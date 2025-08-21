SET SERVEROUTPUT ON
Create or Replace Trigger check_insert_emp
BEFORE Insert ON EMPLOYEE_BACKUP
For Each ROW
Begin
DBMS_Output.put_line('New Employee Inserted');
END;

INSERT INTO EMPLoyee_Backup Values(290,'MAC', 'Khan', 'mackhan@gmail.com', '555-111-444', '24-OCT-03', 'AD_VP', 50000, NULL, 100, 90);


--Create or Replace Trigger emp_audit
--BEFORE Insert OR UPDATE OR Delete ON EMPLOYEE_BACKUP
--For each row
--Begin
--IF Inserting THEN




Create Table EMP_AUDIT(
NEW_EMP_ID INT,
OLd_EMP_ID INT,
EMP_NAME VARCHAR(255),
HIRE_DATE DATE,
EMP_CITY VARCHAR(255)
);
