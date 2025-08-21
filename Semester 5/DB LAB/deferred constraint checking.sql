Create Table dup_Departments (
Department_id Int Primary Key,
Manager_id INT
);

Create Table Professors(
Professor_id Int Primary Key,
Department_id int
);

Alter Table Professors Add Constraint fk_department Foreign Key (Department_id) 
References dup_Departments(Department_id) Deferrable Initially Deferred;

Alter Table dup_Departments Add Constraint fk_manager Foreign Key (Manager_id) 
References Professors(Professor_id) Deferrable Initially Deferred;

Insert Into Professors Values(1,Null);

Insert Into DUP_DEPARTMENTS Values(101,Null);

Update DUP_DEPARTMENTS Set MANAGER_ID = 1 Where DEPARTMENT_ID = 101;

Update Professors Set DEPARTMENT_ID = 101 Where PROFESSOR_ID = 1; 
