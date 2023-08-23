# Write your MySQL query statement below
SELECT P.project_id, ROUND(SUM(E.experience_years)/count(P.employee_id),2) as average_years
FROM Project as P
INNER JOIN Employee as E
ON P.employee_id=E.employee_id
GROUP BY P.project_id