CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
       select max(salary)
       from Employee as e1
       where N-1= (select count(distinct salary)
       from Employee as e2
       where e2.salary>e1.salary)
      # Write your MySQL query statement below.

  );
END