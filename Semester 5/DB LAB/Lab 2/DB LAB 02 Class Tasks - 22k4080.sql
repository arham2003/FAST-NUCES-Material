-- ID: 22k-4080
-- Class TASKS lab 02

--Q1
select employee_id, first_name||' '||last_name as name, Salary, Salary*1.15 as "Incremented Salary", 
abs(Salary - (Salary*1.15)) as "Incremented Amount" from Employees;

--Q2

select * from Employees
where LAST_NAME Like 'A%';

-- Q3

select department_id, manager_id, round(COMMISSION_PCT,1) as Commission_PCT from employees;

-- Q4

select employee_id as "Employee Number", first_name||' '||last_name as Name,  Department_Id, Salary From Employees
where (department_id = 100 OR DEPARTMENT_ID = 40) AND Salary Between 50000 AND 70000;

-- Q5

select employee_id, first_name from employees
where DEPARTMENT_ID Between 60 AND 100;

-- Q6

select * from employees
where FIRST_NAME Like '%ll%';



