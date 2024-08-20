# Write your MySQL query statement below
SELECT name AS Employee
FROM Employee E
WHERE E.salary>(SELECT salary FROM Employee AS s WHERE E.managerId=s.id )