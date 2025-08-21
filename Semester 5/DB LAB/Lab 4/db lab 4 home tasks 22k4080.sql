-- db lab 04 Home Tasks 22k4080

-- Q1

Select Sum(e.Salary) AS "Tot Salary", d.department_name AS "Departments"
From Employees e, departments d
Where d.DEPARTMENT_ID = e.DEPARTMENT_ID
Group By d.department_name;

-- Q5

Select * from Employees
Where Salary = (Select Max(salary) from Employees);

-- Q6

Select * from Employees
Where Salary > (Select Avg(salary) from Employees);


-- Q8

Select First_name, Last_name, Job_Id from employees
where job_id = (select job_id from employees where employee_id =200);

-- Q9

select * from employees
where department_id = 
(select department_id from employees
where salary = (select max(salary) from employees));

-- Q10
select * from employees
where salary > 
(select min(salary) from employees
where department_id = 50);

-- Q11

select * from employees
where salary <
(select min(salary) from employees
where department_id = 90);

-- Q12

Select * from employees
where job_id = 'Sales';

-- Q13

Select * from employees e
where Salary > (select avg(salary) from employees where department_id = e.DEPARTMENT_ID);

-- Q15

SELECT first_name, last_name, department_id, hire_date, 
FLOOR(months_between(SYSDATE, hire_date) / 12) AS "tenure (Years)" --flooring because we cannot have more years than the employee has worked for
FROM employees e
WHERE FLOOR(months_between(SYSDATE, hire_date) / 12) > 
(SELECT AVG(FLOOR(months_between(SYSDATE, hire_date) / 12)) FROM employees
WHERE department_id = e.department_id);

-- Q17

Update Employees Set Salary = Salary*1.05
Where Salary < (select Avg(Salary) from employees where department_id = 20); -- 84 rows updated

-- Q18

Delete From EMPLOYEE_BACKUP
where employee_id NOT IN (Select employee_id from employees);

-- Q19

Create Table Employee_Bonus AS
(select employee_id, salary AS "Bonus Amount" from employees where 1=0);

Insert into employee_bonus
(select employee_id, Salary * 0.2 AS "Bonus Amount" from employees where Salary > (select Avg(salary) from employees) );


-- Q20

-- Select * from Jobs;

Update Jobs Set job_title = 'Senior'
Where Job_Id IN
(select job_id from employees where Floor(Months_between(SYSDATE, hire_date)/12) > 10);

