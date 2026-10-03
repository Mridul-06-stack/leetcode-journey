SELECT w1.id
FROM Weather AS w1
WHERE w1.temperature > (
    SELECT w2.temperature
    FROM Weather AS w2
    WHERE w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
);