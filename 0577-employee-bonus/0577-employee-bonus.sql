# Write your MySQL query statement below
SELECT name,bonus 
FROM Employee as E LEFT OUTER JOIN Bonus as B ON E.empId=B.empId
WHERE Bonus <1000 OR Bonus IS NULL;