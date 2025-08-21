Set SERVEROUTPUT ON;
Create Table customer (
    customer_id NUMBER PRIMARY KEY,
    customer_name varchar2(50),
    balance Number
);

Create Table orders (
    order_id NUMBER primary key,
    customer_id Number References customer(customer_id),
    order_amount Number,
    order_status Varchar2(20)
); 

Set Transaction Name 'customer order transaction';

Insert into customer (customer_id, customer_name, balance) Values (101, 'Arham Khan', 10000);

savepoint customer_added;


Insert into orders (order_id, customer_id, order_amount, order_status) Values (1001, 101, 150, 'Pending');

Update Customer  set balance = balance - 8500 where customer_id =101;

SAVEPOINT order_added;


select * from customer;

Declare

insufficient_balance EXCEPTION;
customer_balance Number;

Begin

Select balance into customer_balance From Customer where customer_id = 101;

If customer_balance < 0 Then
    Raise insufficient_balance;
END IF;


COMMIT;

EXCEPTION

    When insufficient_balance Then
        Rollback to Savepoint customer_added;
        DBMS_OUTPUT.PUT_LINE('Transaction Rolled back due to insufficient balance.');
    When OTHERS Then
    
        Rollback;
        DBMS_OUTPUT.PUT_LINE('Transaction failed and was rolled back.');
END;
/

--- Class Task

Create Table product (
    product_id NUMBER PRIMARY KEY,
    product_name VARCHAR2(50),
    price NUMBER
);

Create Table inventory (
    inventory_id NUMBER PRIMARY KEY,
    product_id NUMBER REFERENCES product(product_id),
    quantity NUMBER
);


Set Transaction Name 'inventory transaction';

Insert into product (product_id, product_name, price)  Values (201, 'Laptop', 1500);

SAVEPOINT product_added;

Insert into inventory (inventory_id, product_id, quantity) Values (3001, 201, 50);

SAVEPOINT inventory_added;


Insert into orders (order_id, customer_id, order_amount, order_status)
Values (5001, 101, 9000, 'Pending');

-- Deducting inventory for the ordered product

DECLARE
    insufficient_inventory EXCEPTION;
    inventory_quantity NUMBER;
    order_quantity NUMBER := &x;

BEGIN

Update inventory Set quantity = quantity - order_quantity Where product_id = 201;


SAVEPOINT order_placed;


Select quantity into inventory_quantity  From inventory Where product_id = 201;

IF inventory_quantity < 0 THEN
    RAISE insufficient_inventory;
END IF;

COMMIT;

EXCEPTION
    WHEN insufficient_inventory THEN
      
        ROLLBACK TO SAVEPOINT inventory_added;
        DBMS_OUTPUT.PUT_LINE('Transaction rolled back: Insufficient inventory.');

    WHEN OTHERS THEN
    
        ROLLBACK;
        DBMS_OUTPUT.PUT_LINE('Transaction failed and was rolled back.');
END;
/


--- TASK 1

CREATE TABLE product_inventory (
    product_id NUMBER PRIMARY KEY,
    product_name VARCHAR2(50),
    stock NUMBER,
    price NUMBER
);

CREATE TABLE returns (
    return_id NUMBER PRIMARY KEY,
    product_id NUMBER REFERENCES product_inventory(product_id),
    return_date DATE,
    reason VARCHAR2(100),
    quantity NUMBER
);

INSERT INTO product_inventory (product_id, product_name, stock, price) 
VALUES (101, 'Laptop', 100, 1500);

INSERT INTO product_inventory (product_id, product_name, stock, price) 
VALUES (102, 'Mouse', 200, 50);

INSERT INTO product_inventory (product_id, product_name, stock, price) 
VALUES (103, 'Keyboard', 150, 100);

COMMIT;

-- query
SELECT  r.product_id,  p.product_name, SUM(r.quantity) AS total_returned, SUM(r.quantity) * 0.95 AS restocked_quantity
FROM returns r
JOIN product_inventory p ON r.product_id = p.product_id
GROUP BY r.product_id, p.product_name;

-- transaction

DECLARE
    restocking_fee NUMBER := 0.05;
    adjusted_quantity NUMBER;
BEGIN

INSERT INTO returns (return_id, product_id, return_date, reason, quantity)
VALUES (1, 101, SYSDATE, 'Defective item', 10);


SAVEPOINT stock_update;


SELECT quantity * (1 - restocking_fee) INTO adjusted_quantity FROM returns WHERE return_id = 1;


UPDATE product_inventory SET stock = stock + adjusted_quantity WHERE product_id = 101;

COMMIT;

DBMS_OUTPUT.PUT_LINE('Transaction successful. Stock updated with restocking fee deducted.');

EXCEPTION
    WHEN OTHERS THEN

        ROLLBACK TO stock_update;
        DBMS_OUTPUT.PUT_LINE('Transaction failed. Rolled back to stock_update savepoint.');
END;
/

--- TASK 2

CREATE TABLE bank_accounts (
    account_id NUMBER PRIMARY KEY,
    balance NUMBER,
    account_type VARCHAR2(20)
);

CREATE TABLE transactions (
    transaction_id NUMBER PRIMARY KEY,
    account_id NUMBER REFERENCES bank_accounts(account_id),
    type VARCHAR2(20), -- 'debit' or 'credit'
    amount NUMBER,
    transaction_date DATE
);

INSERT INTO bank_accounts (account_id, balance, account_type) 
VALUES (1, 10000, 'Savings');

INSERT INTO bank_accounts (account_id, balance, account_type) 
VALUES (2, 5000, 'Savings');

COMMIT;



DECLARE
    sender_id NUMBER := 1; 
    receiver_id NUMBER := 2;
    transfer_amount NUMBER := 2000;
    transaction_fee NUMBER; 
    adjusted_amount NUMBER; 
    sender_balance NUMBER;
    insufficient_balance_sender Exception;
BEGIN

transaction_fee := transfer_amount * 0.02;
adjusted_amount := transfer_amount - transaction_fee;

SELECT balance INTO sender_balance 
FROM bank_accounts 
WHERE account_id = sender_id;

IF sender_balance < transfer_amount THEN
    RAISE insufficient_balance_sender;
END IF;

UPDATE bank_accounts SET balance = balance - transfer_amount WHERE account_id = sender_id;

SAVEPOINT balance_updated;

UPDATE bank_accounts SET balance = balance + adjusted_amount WHERE account_id = receiver_id;
-- Inserting a debit transaction for the sender
INSERT INTO transactions (transaction_id, account_id, type, amount, transaction_date)
VALUES (1, sender_id, 'debit', transfer_amount, SYSDATE);

-- Inserting  a credit transaction for the receiver
INSERT INTO transactions (transaction_id, account_id, type, amount, transaction_date)
VALUES (2, receiver_id, 'credit', adjusted_amount, SYSDATE);

COMMIT;
DBMS_OUTPUT.PUT_LINE('Transaction successful. Money transferred with a 2% fee deducted.');

EXCEPTION
    When insufficient_balance_sender Then
    
        ROLLBACK TO balance_updated;
        DBMS_OUTPUT.PUT_LINE('Transaction failed. Rolled back to the balance_updated.');
    WHEN OTHERS THEN
    
        ROLLBACK;
        DBMS_OUTPUT.PUT_LINE('Transaction failed. Rolled back the entire transaction.');
END;
/

--SELECT * FROM bank_accounts;

--SELECT * FROM transactions;

--- TASK 3

Create Table Customers(
    Customer_ID NUMBER Primary key,
    name varchar2(20)
);

Create Table  loyalty_program(
Customer_id Number REFERENCES Customers(customer_id),
points_Earned Number,
points_redeemed Number
);

INSERT INTO customers (customer_id, name) VALUES (1, 'Arham Khan');
INSERT INTO customers (customer_id, name) VALUES (2, 'Yoyo Khan');

INSERT INTO loyalty_program (customer_id, points_earned, points_redeemed) VALUES (1, 100, 20);

INSERT INTO loyalty_program (customer_id, points_earned, points_redeemed) VALUES (2, 200, 50);

COMMIT;

DECLARE
    custom_id NUMBER := 1;
    purchase_amount NUMBER := 600; 
    loyalty_points NUMBER; 

BEGIN

If purchase_Amount > 500 THEN
    loyalty_points := purchase_amount *1.5;
ELSE
    loyalty_points := purchase_amount;
END IF;
    
UPDATE loyalty_program Set points_earned = points_earned + loyalty_points where customer_id = custom_id;

Savepoint points_updated;

Commit;
DBMS_OUTPUT.PUT_LINE('Transaction successful. Loyalty points updated.');

EXCEPTION
    When OTHERS THEN
        Rollback to points_updated;
        dbms_output.put_line('Transaction failed, Rolled back to points_updated savepoint.');
END;
/

Select * from LOYALTY_PROGRAM;
