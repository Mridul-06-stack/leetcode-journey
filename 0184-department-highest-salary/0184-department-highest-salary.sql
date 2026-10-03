SELECT 
    a.deptname AS Department,
    a.name     AS Employee,
    a.salary
FROM (
    SELECT 
        e.name,
        e.salary,
        d.name AS deptname,
        DENSE_RANK() OVER (
            PARTITION BY d.name
            ORDER BY e.salary DESC
        ) AS rnk
    FROM employee e
    JOIN Department d
        ON e.departmentid = d.id
) AS a
WHERE a.rnk = 1;