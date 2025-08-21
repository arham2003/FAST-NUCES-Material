-- LAB 2 Home Tasks 22k4080

-- COMMENTS ARE ADDED FOR EASINESS

--Q1

Select First_name||' '||Last_name as "Emp Name", hire_date, to_char(hire_date,'Day') as "DAY" from Employees
ORDER BY mod(to_char(hire_date,'D') + 5, 7) ASC; -- +5 is added because in numbers Sunday is 1 and Monday is 2...

-- Q2

Select * from Employees
Where COMMISSION_PCT > 0.0 AND NOT (DEPARTMENT_ID = 90 OR DEPARTMENT_ID = 100);

-- Q3

Select * from Employees
Where to_char(hire_date, 'YYYY') = 2010;

-- Q4
--Select Job_ID, NVL(Commission_pct,0) From EMployees
--where NVL(Commission_pct, 0) = 0;

--Select Distinct Job_ID from Employees
--Where ROWNUM <= 72;  (Found all the job ids where commission = 0)

Select * From JOBS
Where MIN_SALARY > 8000 AND  MIN_SALARY < 15000 AND NOT (JOB_ID = 'ST_MAN' and JOB_ID = 'ST_CLERK');

-- Q5

Select first_name, last_name, job_id from employees
where job_id > 100 AND JOB_ID < 150 AND (Department_ID > 90 AND Department_ID < 100);

-- Q6

SELECT first_name||' '||Last_name AS "NAME",Commission_pct,Salary, (NVL(commission_pct,0)*Salary)+Salary AS "Total Salary" From Employees;
-- NVL will place value 0 whereever the record is null ( means no commission)

-- Q7
-- This question can be done using join which is not taught till now
SELECT 
(SELECT LOWER(First_name) FROM Employees WHERE Job_ID = 'AD_PRES') AS "First_Name", 
(SELECT UPPER(Job_title) FROM Jobs WHERE Job_ID = 'AD_PRES') AS "Job Title"
FROM dual;
-- chose job_id as "AD_PRES" because it is the one with only 1 record as Dual shows only 1 record.

-- Q8

Select e.First_Name||' '||e.Last_name||' - '||j.Job_title AS "Name with Job", LENGTH(e.First_Name||' '||e.Last_name) AS "Length of Name", INSTR(e.First_Name||' '||e.Last_name,'a') AS "Numeric Position of A"
From EMPLOYEES e, Jobs j
Where e.job_id = j.Job_ID AND j.JOB_ID LIKE 'SA%';


-- Q9

Select Employee_ID, start_date AS "Hire Date", 
Round(Months_between(END_DATE, START_DATE), 0) AS "No. of Months Employed",
Next_day(start_date, 'Friday') AS "Next Friday after Hire Date",last_day(start_date) AS "Last day of month hired"  From Job_History
Where Months_between(end_date,Start_date) > 100;

-- Q10

Select Employee_ID AS "Employee Number", hire_date, to_char(hire_date, 'Month') AS "Month Started" From Employees
Where to_char(hire_date, 'YYYY') >= 2003;

-- Q11

Select Employee_Id AS "Employee Number", to_char(hire_date, 'MM') AS "Month Number", 
to_char(hire_date, 'YYYY') AS "Year of Hiring" From Employees;

-- Q12

Select First_Name||' '||Last_Name AS "Employee Name", to_char(hire_date, 'DD Month,YYYY') AS "Hire Date" From Employees;

-- Q13

Select First_Name||' '||Last_Name AS "Employee Name", to_char(Salary, '$99999') AS "Employee Salary" From Employees
Where First_Name LIKE 'Steven%';

-- Q14

Select Next_Day(SYSDATE, 'Monday') AS "Next Monday from Current Date" From Dual;

-- Q15

Select First_Name||' '||Last_Name AS "Employee Name", SUBSTR(First_Name, (Length(First_name) - 2), 3) AS "Last 3 Characters" From Employees;



