# Write your MySQL query statement below
SELECT E.employee_id,E.name,COUNT(E.employee_id) AS reports_count,ROUND(AVG(f.age)) AS average_age
FROM Employees E INNER JOIN Employees F
ON E.employee_id=F.reports_to
GROUP BY E.employee_id
ORDER BY E.employee_id;