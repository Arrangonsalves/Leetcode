# Write your MySQL query statement below
SELECT score, (SELECT count(distinct score) FROM Scores WHERE score>=s.score) AS "rank"
FROM Scores s
ORDER BY score desc