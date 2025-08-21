-- Lab 03 Home Tasks (22k-4080)

--Q1

-- Created new user using sql command line (picture attached).

-- Q2
Create Table Products (
Product_ID INT NOT NULL,
Product_name VARCHAR(25) NOT NULL,
Supplier_ID VARCHAR(10),
Category_ID VARCHAR(10) --considering Category Id as : C-1543
);

-- Q3

Insert INTO Products Values(
1001, 'Potatoes', 'SP-101', 'C-95'
);

Insert INTO Products Values(
1002, 'French Fries', 'SP-101', 'C-95'
);

Insert INTO Products Values(
1003, 'Strawberries', 'SP-102', 'C-97'
);

Insert INTO Products Values(
1004, 'Blue Berries', 'SP-102', 'C-97'
);

Insert INTO Products Values(
1005, 'Sweet Corns', 'SP-101', 'C-80'
);

-- Q4

Alter Table Products ADD (Product_Origin varchar(20) DEFAULT 'Pakistan');

-- Q5

Create Table Departments(
DEPARTMENT_ID NUMBER(4,0) Primary Key,
DEPARTMENT_NAME	VARCHAR(30) Not Null,
MANAGER_ID	NUMBER(6,0),
LOCATION_ID	NUMBER(4,0)
);

Create Table Employees(
EMPLOYEE_ID	NUMBER(6,0) Primary Key,
FIRST_NAME VARCHAR(20),
LAST_NAME VARCHAR(25) NOT NULL,
EMAIL VARCHAR(25) NOT NULL,
PHONE_NUMBER VARCHAR(20),
HIRE_DATE DATE NOT NULL,
JOB_ID VARCHAR(10) NOT NULL,
SALARY NUMBER(8,2),
COMMISSION_PCT NUMBER(2,2),
MANAGER_ID NUMBER(6,0),
DEPARTMENT_ID NUMBER(4,0)
);


-- Q6

Alter Table Employees ADD Foreign KEY (DEPARTMENT_ID) REFERENCES Departments (DEPARTMENT_ID);

-- Q7

Alter Table Employees Drop Column Email;
Alter Table Employees Drop Column Manager_ID;

Alter Table Departments Drop Column Manager_ID;

-- Q8

Alter Table Departments ADD Constraint chk_lower CHECK(location_id = LOWER(location_id));

-- Q9

Alter Table Employees ADD Unique(Salary);

-- Q10

Alter Table Employees ADD constraint no_future_date check (hire_date <= '08-Sep-2024'); -- Sysdate is not working

-- Q11

Insert INTO Departments Values(
10, 'Accounts', 0464
);

Insert INTO Employees Values(
1001, 'Dave', 'Smith', 02143-3222445, '01-Jan-2012', 'J-435', 40000, 0.2, 10
);

-- Q12

Alter Table Employees ADD Constraint add_primary_key PRIMARY KEY (Employee_Id, Job_ID);

-- We can only have one primary key, but we can have multiple columns in our primary key.
-- primary key is primary way of identifying a row. Primary means 'first'. There can't be two firsts.
-- we can make a composite primary key while creating table but not after that.

-- Q13

Alter Table Products Rename To Store_Products;


-- Q14

-- checked dependencies in dependencies section of table.

Drop Table Store_Products;

-- Q15

DELETE FROM EMPLOYEES WHERE department_id = 10;

Delete From DEPARTMENTS;

-- now dropping the constraints

SELECT constraint_name, CONSTRAINT_TYPE
FROM user_constraints -- oracle table for constraints name as I have not named the constraint above.
WHERE table_name = 'EMPLOYEES';

Alter Table Employees Drop constraint SYS_C007046;

Drop Table Departments;

