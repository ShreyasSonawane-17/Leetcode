# Write your MySQL query statement below
select name as Customers 
from Customers 
where id Not in (
    select customerId
    from Orders
);