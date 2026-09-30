# Write your MySQL query statement below
SELECT  max(salary) as SecondHighestSalary
FROM employee
WHERE salary < (SELECT MAX(salary) FROM employee)
