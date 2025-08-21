-- lab 09 22k-4080
SET Serveroutput on;

-- DML Trigger Tasks:

-- 1)

Create table employee_bonus (
    employee_id integer PRIMARY KEY,
    bonus DECIMAL(10, 2)
);

CREATE OR REPLACE TRIGGER trg_employee_bonus_insert AFTER INSERT ON employees
FOR EACH ROW
DECLARE
bonus_amount DECIMAL(10, 2);
BEGIN
bonus_amount := :NEW.salary * 0.10;
INSERT INTO employee_bonus (employee_id, bonus)
VALUES (:NEW.employee_id, bonus_amount);
END;
/

-- 2):

CREATE OR REPLACE TRIGGER trg_salary_threshold_check BEFORE UPDATE OF salary ON employees
FOR EACH ROW
BEGIN
IF :NEW.salary > 10000 THEN
RAISE_APPLICATION_ERROR(-20001, 'Error: Salary exceeds the threshold of 10,000.');
END IF;
END;
/

-- 3):

CREATE TABLE Deleted_Employees_Log(
    employee_id Integer,
    name VARCHAR2(50),
    position VARCHAR2(50),
    salary DECIMAL(10, 2),
    deleted_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_employee_delete_log AFTER DELETE ON employees
FOR EACH ROW
BEGIN
INSERT INTO Deleted_Employees_Log (employee_id, name, position, salary, deleted_at)
VALUES (:OLD.employee_id, :OLD.first_name, :OLD.job_id, :OLD.salary, SYSTIMESTAMP);
END;
/


-- 4):

Create TABLE Salary_Log (
    employee_id INT,
    old_salary DECIMAL(10, 2),
    new_salary DECIMAL(10, 2),
    changed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_salary_update_log AFTER UPDATE OF salary ON employees
FOR EACH ROW
BEGIN
INSERT INTO Salary_Log (employee_id, old_salary, new_salary, changed_at)
VALUES (:OLD.employee_id, :OLD.salary, :NEW.salary, SYSTIMESTAMP);
END;
/

-- -- DDL Trigger Tasks

-- 1):
-- audit_log table aready created above ^
CREATE OR REPLACE TRIGGER trg_table_creation_log AFTER CREATE ON SCHEMA
DECLARE
BEGIN
INSERT INTO Audit_Log (table_name, created_by, created_at)
VALUES (ora_dict_obj_name, SYS_CONTEXT('USERENV', 'SESSION_USER'), SYSTIMESTAMP);
END;
/

-- 2):

CREATE OR REPLACE TRIGGER trg_restrict_alter_schema BEFORE ALTER ON SCHEMA
DECLARE
work_hours NUMBER;
BEGIN
-- Checking if the statement affects the 'employees' table, oracle not allowing system triggers based on all tables
IF ora_dict_obj_name = 'EMPLOYEES' THEN

work_hours := TO_NUMBER(TO_CHAR(SYSDATE, 'HH24'));
IF work_hours >= 18 OR work_hours < 8 THEN
    RAISE_APPLICATION_ERROR(-20002, 'Error: Cannot alter the employees table outside business hours.');
END IF;

END IF;
END;
/

-- 3):

CREATE TABLE Drop_Log (
    table_name VARCHAR2(25),
    dropped_by VARCHAR2(50),
    dropped_at TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_drop_log AFTER DROP ON SCHEMA
DECLARE
BEGIN
INSERT INTO Drop_Log (table_name, dropped_by, dropped_at)
VALUES (ora_dict_obj_name, SYS_CONTEXT('USERENV', 'SESSION_USER'), SYSTIMESTAMP);
END;
/

-- 4):

CREATE OR REPLACE TRIGGER trg_protect_audit_log_drop BEFORE DROP ON SCHEMA
DECLARE
BEGIN
IF ora_dict_obj_name = 'AUDIT_LOG' THEN -- getting table name
    RAISE_APPLICATION_ERROR(-20003, 'Dropping the Audit_Log table is not allowed.');
END IF;
END;
/

--- Database Trigger Task:

-- Q1:

CREATE TABLE System_Logs (
    event_type VARCHAR2(50),
    event_time TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_database_start_log AFTER STARTUP 
ON DATABASE
BEGIN
INSERT INTO System_Logs (event_type, event_time)
VALUES ('Database Start', SYSTIMESTAMP);
END;
/

-- Q2:

CREATE TABLE Failed_Logins (
    username VARCHAR2(50),
    attempt_time TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_failed_login_log AFTER SERVERERROR ON DATABASE
DECLARE
BEGIN
IF (IS_SERVERERROR(1017)) THEN  -- 1017 is the error code for invalid login
    INSERT INTO Failed_Logins (username, attempt_time)
    VALUES (SYS_CONTEXT('USERENV', 'SESSION_USER'), SYSTIMESTAMP);
END IF;
END;
/

-- Q3:

CREATE TABLE User_Activity_Log (
    username VARCHAR2(50),
    login_time TIMESTAMP,
    logout_time TIMESTAMP,
    session_duration INTERVAL DAY TO SECOND
);

CREATE OR REPLACE TRIGGER trg_successful_logout_log AFTER LOGOFF ON SCHEMA
DECLARE
v_login_time TIMESTAMP;
BEGIN
v_login_time := SYS_CONTEXT('USERENV', 'SESSION_START_TIME');
INSERT INTO User_Activity_Log (username, login_time, logout_time, session_duration)
VALUES (SYS_CONTEXT('USERENV', 'SESSION_USER'), v_login_time, SYSTIMESTAMP, SYSTIMESTAMP - v_login_time);
END;
/

--- Instead of Trigger Tasks:
-- Q1

CREATE or Replace VIEW emp_dept_view AS
SELECT e.employee_id, e.first_name, e.salary, d.department_id, d.department_name FROM employees e 
JOIN departments d ON e.department_id = d.department_id;


CREATE OR REPLACE TRIGGER trg_instead_of_insert_emp_dept INSTEAD OF INSERT ON emp_dept_view
FOR EACH ROW
BEGIN

INSERT INTO departments (department_id, department_name)
VALUES (:NEW.department_id, :NEW.department_name);

INSERT INTO employees (employee_id, first_name, salary, department_id)
VALUES (:NEW.employee_id, :NEW.first_name, :NEW.salary, :NEW.department_id);
END;
/


-- Q2

CREATE or Replace VIEW emp_salary_view AS
Select employee_id, first_name, salary FROM employees;


CREATE OR REPLACE TRIGGER trg_instead_of_update_emp_sal INSTEAD OF UPDATE ON emp_salary_view
FOR EACH ROW
BEGIN
IF (:OLD.salary - :NEW.salary) / :OLD.salary > 0.20 THEN
    RAISE_APPLICATION_ERROR(-20004, 'Error: Salary reduction exceeds 20% limit.');
ELSE
    UPDATE employees SET salary = :NEW.salary WHERE employee_id = :OLD.employee_id;
END IF;
END;
/




















-- 2):

CREATE TABLE Audit_Log (
    table_name VARCHAR2(50),
    created_by VARCHAR2(50),
    created_at TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_table_creation_log
AFTER CREATE ON SCHEMA
DECLARE
BEGIN
INSERT INTO Audit_Log (table_name, created_by, created_at)
VALUES (ora_dict_obj_name, SYS_CONTEXT('USERENV', 'SESSION_USER'), SYSTIMESTAMP);
END;
/

