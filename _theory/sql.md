---
layout: post
title: "Introduction to SQL"
permalink: /theory/sql_intro
index: true
---
{% include start-row.html %}

### Basic concepts

- **SQL** (Structured Query Language): Programming language designed to manage data held in *relational databases*.
- **Relational Databases**: Database which stores information in one (ore more) tables (aka relations).
- **Table**: Data organized in *columns* (set of elements of same type), and *rows* (each one representing an entry).
- **Types**: `INTEGER`, `REAL`, `TEXT`, `DATE`
- **Primary key**: Uniquely identifies a row. Thus, it must be unique, only one column, not NULL.
- **Foreign key**: Primary key of a table appearing in a different table.

### Table Creation

```sql
CREATE TABLE tbl (
   id INTEGER, 
   name TEXT, 
   age INTEGER
);
```
{% include end-row.html %}
{% include start-row.html %}
To those, you can add constrains after the type such as:
- `PRIMARY KEY`: Uniquely identifies the row (must be **unique**)
- `UNIQUE`: Each row must have a different value.
- `NOT NULL`: Cannot be null.
- `DEFAULT val`: Assigns a default value. 

{% include annotation.html %}
Attempts to add elements which don't satisfy those conditions will result into a *constrain violation*.
{% include end-row.html %}
{% include start-row.html %}

### Content Modification

**Insertion of an element:**

```sql
INSERT INTO tbl (col1, col2, col3)
VALUES (1, 'Justin Bieber', 22);
```



**Add/Remove columns:**

```sql
ALTER TABLE tbl ADD COLUMN col TEXT;
ALTER TABLE tbl DROP COLUMN col;
```

**Edit element in table:**

```sql
UPDATE tbl 
SET col = '@taylorswift13' 
WHERE id = 4; 
```

**Delete elements certifying condition cond**

```sql
DELETE
FROM tbl
WHERE col IS NULL;
```

### Querying

**Query**: Extract information stored in a database.

#### Select

```sql
SELECT * FROM tbl;
SELECT col1, col2 FROM tbl;
SELECT col1 AS 'Alias' FROM tbl; --displays different column name
SELECT DISTINCT col1 FROM tbl; --only display different elements
```

#### Where

Usage:

```sql
SELECT ...
FROM tbl
WHERE ...
```

Examples:

{% include end-row.html %}
{% include start-row.html %}

```sql
WHERE cond;
WHERE col LIKE 'bla_bla'; --'_' can be any character
WHERE col LIKE 'bla%'; --'%' can be any string (also empty)
WHERE col IS (NOT) NULL; 
WHERE col BETWEEN val1 AND val2; --Both inclusive
```

{% include annotation.html %}
Simple conditions use the format:

col `=, !=, >, <` val
{% include end-row.html %}
{% include start-row.html %}


You can combine multiple conditions as:

```sql
WHERE cond1 AND cond2
```

```sql
WHERE cond1 OR cond2
```

Similarly, one can create a new column modifying values as:

```sql
SELECT name,
 CASE
  WHEN col > 8 THEN 'Something'
  ELSE 'Something else'
 END AS 'New col'
FROM tbl;
```


### Aggregates

{% include end-row.html %}
{% include start-row.html %}
Calculations performed on multiple rows of the table, for instance:

```sql
SELECT COUNT(col)
SELECT SUM(col)
SELECT AVG(col)
SELECT MIN(col)
SELECT MAX(col)
SELECT ROUND(col, decimals) --number of decimals as an int
```

{% include annotation.html %}
Basic usage:
```sql
SELECT FUNC(col)
FROM tbl;
```
{% include end-row.html %}
{% include start-row.html %}

{% include end-row.html %}
{% include start-row.html %}
**GROUP BY**: Allows us to perform an operation on some column and give a result wrt groups of identical data in another one

```sql
SELECT col1, AVG(col2)
FROM tbl
GROUP BY col1
```

**HAVING**: Allows to apply a filter on the **groups**. It works exactly the same as **WHERE** but working on the groups instead of the original data.

```sql
SELECT col1, COUNT(*)
FROM tbl
GROUP BY col1
HAVING COUNT(*) > 0 --Only display groups of > 10 elements
``` 

{% include annotation.html %}
Instead of using the column reference in the **GROUP BY**, we could just use the index used in the **SELECT** order.
In this case,
```sql
GROUP BY 1
```
would be the same as
```sql
GROUP BY col1
``` 
{% include end-row.html %}
{% include start-row.html %}

### CASES

```sql
SELECT
   CASE
      WHEN cond1 THEN result1
      WHEN cond2 THEN result2
      ELSE result3
   END AS new_col_name
FROM table
```

### CTE
Store a query output as a temporal table for later usage.

```sql
WITH CTE AS
(
   --Your query
)
```

You can combine multiple helper tables as:

```sql
WITH CTE_1 AS
(
   --Your query using original data
),
CTE_2 AS
(
   --Your query using CTE_1
)

-- Here you can use CTE_2
```


### Multiple Tables

**INNER JOIN**: Only keeps values which are in both matched columns.

```sql
SELECT t1.col1, t2.col2
FROM tbl1 t1
JOIN tbl2 t2 ON t1.col_a = t2.col_b
```

**LEFT JOIN**: Keeps only the exact same values from table 1.

```sql
SELECT t1.col1, t2.col2
FROM tbl1 t1
LEFT JOIN tbl2 t2 ON t1.col_a = t2.col_b
```

**CROSS JOIN**: Combines all rows of table 1 with all rows of table 2.

**UNION**: Appends table2 to table 1.


### PIVOTING

Groups by a column elements and converts each element aggregation into different columns.

```sql
SELECT 
  -- Whatever you want
FROM
(
   -- Insert query that produces pivotable_col
) AS TMP
PIVOT
(
   -- Aggregate function over newly grouped categories
   FOR pivotable_col IN ([category_1], [category_2], ...)
) AS PVT
```

### Window functions

**OVER PARTITION**: Aggregates data same as GROUP BY but without grouping (leaves multiple rows with the repeated information).

{% include end-row.html %}
{% include start-row.html %}

```sql
SELECT 
  -- Whatever columns you want
   FUNC(col1) OVER(PARTITION BY col2) AS new_col_name
FROM tbl
```

{% include annotation.html %}
This will apply the `FUNC` aggregate on elements of `col1` grouping by `col2` but displaying each row.
{% include end-row.html %}
{% include start-row.html %}

{% include end-row.html %}
