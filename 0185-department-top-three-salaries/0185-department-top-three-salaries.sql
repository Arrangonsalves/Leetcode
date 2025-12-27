# Write your MySQL query statement below
SELECT Department,Employee,Salary FROM(
SELECT 
d.name AS Department, 
e.name AS Employee,
salary AS Salary,
DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rank_dept
FROM Employee e LEFT JOIN Department d ON e.departmentId = d.id
) t
WHERE rank_dept<4

