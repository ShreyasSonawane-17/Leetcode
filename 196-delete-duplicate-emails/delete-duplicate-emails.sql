# Write your MySQL query statement below
Delete a
from Person a
join Person b
on a.email = b.email
AND a.id > b.id;