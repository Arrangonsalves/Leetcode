# Write your MySQL query statement below
SELECT employee_id,if(employee_id%2 and name NOT LIKE 'M%',salary,0) as bonus from Employees order by employee_id
