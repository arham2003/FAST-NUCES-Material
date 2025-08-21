SET SERVEROUTPUT ON;
-- Lab 8 pl/Sql 22k4080


-- Task 1
accept x number prompt 'Please enter your Employee Number: ';
DECLARE
emp_num EMPLOYEES.EMPLOYEE_ID%type := &x;
e_sal employees.Salary%type;
bonus float;
Begin
Select Salary Into e_sal From Employees Where Employee_Id = emp_num;
If (e_sal < 1000) Then
bonus := (e_sal*0.1);
dbms_output.put_line ('Employee Bonus is: ' || bonus);
ElsIF (e_sal >= 1000 AND e_sal <=1500) THEN
bonus := (e_sal*0.15);
DBMS_OUTPUT.PUT_LINE('Employee Bonus is: ' || bonus);
ElsIF (e_sal > 1500) THEN
bonus := (e_sal*0.2);
DBMS_OUTPUT.PUT_LINE('Employee Bonus is: ' || bonus);
Else
bonus := 0;
DBMS_OUTPUT.PUT_LINE('No bonus.');
END IF;
end;
/

-- Task 2

accept emp_id_new NUMBER PROMPT 'Please enter the Employee ID: ';

DECLARE
emp_id_new EMPLOYEES.EMPLOYEE_ID%TYPE := &emp_id_new;
commission_check EMPLOYEES.COMMISSION_PCT%TYPE;
emp_sal EMPLOYEES.SALARY%TYPE;
BEGIN
SELECT COMMISSION_PCT, SALARY INTO commission_check, emp_sal FROM EMPLOYEES WHERE EMPLOYEE_ID = emp_id_new;
IF commission_check IS NULL THEN

emp_sal := emp_sal + NVL(commission_check, 0);
UPDATE EMPLOYEES SET SALARY = emp_sal WHERE EMPLOYEE_ID = emp_id_new;

DBMS_OUTPUT.PUT_LINE('Salary updated successfully. New Salary: ' || emp_sal);
ELSE
DBMS_OUTPUT.PUT_LINE('No update required as commission is not NULL.');
End IF;
END;
/

-- Task 3

Declare
dept_no Employees.Department_id%type := 30;
dept_name Departments.Department_name%type;
Begin
SELECT D.DEPARTMENT_NAME INTO dept_name FROM EMPLOYEES E
JOIN DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
WHERE E.DEPARTMENT_ID = dept_no AND ROWNUM = 1;

DBMS_OUTPUT.PUT_LINE('The department name for department number ' || dept_no || ' is: ' || dept_name);
End;
/

-- Task 4

Declare
dept_no Employees.Department_id%type := 20;
job_titl Departments.Department_name%type;
PROCEDURE get_job_by_dept(p_dept_no IN NUMBER) IS

Begin
SELECT JOB_ID INTO job_titl FROM EMPLOYEES WHERE DEPARTMENT_ID = p_dept_no
AND ROWNUM = 1;
DBMS_OUTPUT.PUT_LINE('The Nature of the job for an employee in department ' || p_dept_no || ' is: ' || job_titl);
END get_job_by_dept;

BEGIN
get_job_by_dept(dept_no);
End;
/

-- Task 6
DECLARE
PROCEDURE update_salary(empno IN NUMBER) IS
BEGIN
UPDATE EMPLOYEES SET SALARY = SALARY * 1.1 WHERE EMPLOYEE_ID = empno;
DBMS_OUTPUT.PUT_LINE('Salary updated successfully for employee ' || empno);
END;
BEGIN
update_salary(104);
END;
/

-- Task 7
accept deptno number prompt 'Enter Department Number:';
DECLARE
PROCEDURE add_bonus(deptno IN NUMBER) IS
BEGIN
UPDATE EMPLOYEES SET SALARY = SALARY + 1000 WHERE SALARY > 5000 AND DEPARTMENT_ID = deptno;
DBMS_OUTPUT.PUT_LINE('Salaries updated for department ' || deptno);
END;
BEGIN
add_bonus(&deptno);
END;
/

-- Task 8 (a)

CREATE or Replace VIEW emp_designation_count AS SELECT JOB_ID, COUNT(*) AS emp_count FROM EMPLOYEES
GROUP BY JOB_ID;
--Select * from Emp_designation_count;

-- Task 8 (b)

CREATE or Replace VIEW emp_details_exc_king AS
SELECT E.EMPLOYEE_ID, E.FIRST_NAME, E.LAST_NAME, E.DEPARTMENT_ID, D.DEPARTMENT_NAME FROM EMPLOYEES E 
JOIN DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
WHERE Last_name != 'King';

--select * from emp_details_exc_king;

-- Task 8 (c)

Create or Replace VIEW emp_department_details AS
SELECT E.EMPLOYEE_ID, E.First_name || E.Last_name AS "EMP_NAME", E.DEPARTMENT_ID, D.DEPARTMENT_NAME FROM EMPLOYEES E 
JOIN DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID;


-- Task 9

DECLARE
num1 NUMBER;
num2 NUMBER;
sum_result NUMBER;
BEGIN
num1 := &num1;
num2 := &num2;
sum_result := num1 + num2;

DBMS_OUTPUT.PUT_LINE('The sum of ' || num1 || ' + ' || num2 || ' is: ' || sum_result);
END;
/

-- Task 10

Declare
l_b NUMBER := &l_b;
u_b NUMBER := &u_b;
total_sum NUMBER := 0;
BEGIN
FOR i IN l_b..u_b LOOP
total_sum := total_sum + i;
END LOOP;

DBMS_OUTPUT.PUT_LINE('The sum of numbers from ' || l_b || ' to ' || u_b || ' is: ' || total_sum);
END;
/

-- Task 11

DECLARE
emp_id EMPLOYEES.EMPLOYEE_ID%type := &emp_id;
emp_name EMPLOYEES.First_name%TYPE;
hire_date EMPLOYEES.HIRE_DATE%TYPE;
dept_name DEPARTMENTS.DEPARTMENT_NAME%TYPE;
BEGIN
SELECT E.First_name, E.HIRE_DATE, D.DEPARTMENT_NAME INTO emp_name, hire_date, dept_name FROM EMPLOYEES E
JOIN DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
WHERE E.EMPLOYEE_ID = emp_id;

DBMS_OUTPUT.PUT_LINE('Employee Name: ' || emp_name);
DBMS_OUTPUT.PUT_LINE('Hire Date: ' || hire_date);
DBMS_OUTPUT.PUT_LINE('Department Name: ' || dept_name);
END;
/

-- Task 12

DECLARE
num NUMBER := &numb;
reversed_num NUMBER := 0;
temp NUMBER := num;
BEGIN
WHILE temp > 0 LOOP
reversed_num := reversed_num * 10 + MOD(temp, 10);
temp := floor(temp / 10);
END LOOP;

IF num = reversed_num THEN
DBMS_OUTPUT.PUT_LINE(num || ' is a palindrome.');
ELSE
DBMS_OUTPUT.PUT_LINE(num || ' is not a palindrome.');
END IF;
END;
/

-- TAsk 13

DECLARE
emp_id_2 EMPLOYEE_BACKUP.EMPLOYEE_ID%type := &emp_id_2;
emp_name VARCHAR2(50) := '&emp_name';
dept_id EMPLOYEE_BACKUP.DEPARTMENT_ID%type := &dept_id;
dept_name VARCHAR2(50) := '&dept_name';
l_name EMPLOYEE_BACKUP.LAST_NAME%type := '&l_name';
emp_email EMPLOYEE_BACKUP.EMAIL%type := '&emp_email';
emp_hdate EMPLOYEE_BACKUP.HIRE_DATE%type := '&emp_hdate';
emp_jobid EMPLOYEE_BACKUP.JOB_ID%type := '&emp_jobid';
BEGIN
INSERT INTO EMPLOYEE_Backup (EMPLOYEE_ID, First_name,Last_name, Email,Hire_date, JOB_ID , DEPARTMENT_ID) 
VALUES (emp_id_new, emp_name,l_name, emp_email, emp_hdate, emp_jobid, dept_id);

INSERT INTO DEPARTMENTS (DEPARTMENT_ID, DEPARTMENT_NAME) 
VALUES (dept_id, dept_name);

DBMS_OUTPUT.PUT_LINE('Employee and Department inserted successfully.');
END;
/


-- Task 14

DECLARE
emp_id_3 NUMBER := 105;
current_id NUMBER;
emp_name EMPLOYEES.First_name%TYPE;
emp_salary EMPLOYEES.SALARY%TYPE;
BEGIN
current_id := emp_id_3;

LOOP
SELECT MANAGER_ID INTO current_id FROM EMPLOYEES WHERE EMPLOYEE_ID = current_id;

SELECT First_Name, SALARY INTO emp_name, emp_salary FROM EMPLOYEES
WHERE EMPLOYEE_ID = current_id AND SALARY > 2500;

IF emp_salary > 2500 THEN
DBMS_OUTPUT.PUT_LINE('Employee ' || '"'||emp_name|| '"' || ' has a salary over 2500 and is higher in the chain.');
EXIT;
END IF;
END LOOP;

END;
/


-- TASK 15

DECLARE
sum_100 NUMBER := 0;
BEGIN
FOR i IN 1..100 LOOP
sum_100 := sum_100 + i;
END LOOP;

DBMS_OUTPUT.PUT_LINE('sum of the first 100 numbers is: ' || sum_100);
END;
/
