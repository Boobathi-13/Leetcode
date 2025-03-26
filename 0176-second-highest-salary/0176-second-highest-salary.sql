-- SELECT salary AS SecondHighestSalary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1

-- Error REASON:
-- Why does this return nothing when the table has only one or no rows?
-- If there are fewer than 2 distinct salaries, OFFSET 1 tries to skip the first row and fetch the second one.

-- Since there is no second row, the query returns an empty result set (i.e., no rows).

-- SQL does not return NULL automatically when a query has no results—it just returns an empty set.


SELECT (
    SELECT DISTINCT salary AS SecondHighestSalary 
    FROM Employee 
    ORDER BY salary DESC 
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary 