# Write your MySQL query statement below
SELECT 
    a.name AS Department,
    b.name AS Employee,
    b.salary AS Salary
FROM Department a
JOIN Employee b
ON a.id = b.departmentId
WHERE b.salary = (
    SELECT MAX(b2.salary)
    FROM Employee b2
    WHERE b2.departmentId = b.departmentId
);