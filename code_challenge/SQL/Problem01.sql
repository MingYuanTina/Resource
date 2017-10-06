-- //  595. Big Countries
-- // There is a table World

-- // +-----------------+------------+------------+--------------+---------------+
-- // | name            | continent  | area       | population   | gdp           |
-- // +-----------------+------------+------------+--------------+---------------+
-- // | Afghanistan     | Asia       | 652230     | 25500100     | 20343000      |
-- // | Albania         | Europe     | 28748      | 2831741      | 12960000      |
-- // | Algeria         | Africa     | 2381741    | 37100000     | 188681000     |
-- // | Andorra         | Europe     | 468        | 78115        | 3712000       |
-- // | Angola          | Africa     | 1246700    | 20609294     | 100990000     |
-- // +-----------------+------------+------------+--------------+---------------+
-- // A country is big if it has an area of bigger than 3 million square km or a population of more than 25 million.

-- // Write a SQL solution to output big countries' name, population and area.

-- // For example, according to the above table, we should output:

-- // +--------------+-------------+--------------+
-- // | name         | population  | area         |
-- // +--------------+-------------+--------------+
-- // | Afghanistan  | 25500100    | 652230       |
-- // | Algeria      | 37100000    | 2381741      |
-- // +--------------+-------------+--------------+

-- // Implementation
SELECT NAME, POPULATION, AREA FROM WORLD WHERE POPULATION > 25000000 OR AREA > 3000000;

# Equivalent code transformation
# vector<vector<string> >list
# for (int i = 0 ; i < World.size(); i++){                                              FROM (LOOP)
#     if (World[i].population > 25000000 or World[i].area > 3000000){                   WHERE (Condition)
#         vector<int> temp = { World[i].name, World[i].population, World[i].area }      SELECT (RETURN STATEMENT)
#         return temp;
#     }
# }

# Different approach

