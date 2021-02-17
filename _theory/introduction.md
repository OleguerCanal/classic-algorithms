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
- **Table**: Stores data organized in *columns* (set of elements of same type), and *rows* (each record of the table).
- **Types**: `INTEGER`, `REAL`, `TEXT`, `DATE`
- **Statement**: Text recognized as a valid command (always ends in `;`)


### Table Creation

```sql
CREATE TABLE tbl (
   id INTEGER, 
   name TEXT, 
   age INTEGER
);
```

To those, you can add constrains after the type such as:
- `PRIMARY KEY`: Uniquely identifies the row (must be **unique**)
- `UNIQUE`: Each row must have a different value.
- `NOT NULL`: Cannot be null.
- `DEFAULT val`: Assigns a default value. 

Attempts to add elements which don't satisfy those conditions will result into a *constrain violation*.

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
DELETE FROM tbl
WHERE col IS NULL;
```

### Querying

**Query**: Extract information stored in a database.

#### Select

```sql
SELECT * FROM tbl;
SELECT col1, col2 FROM tbl;
SELECT col1 AS 'Col display name' FROM tbl; --displays different column name
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
WHERE cond1
   AND cond2
```

```sql
WHERE cond1
   OR cond2
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

**Aggregates**: Are calculations performed on multiple rows of the table.

Usage:
```sql
SELECT FUNC(col)
FROM tbl;
```

Examples:

```sql
SELECT COUNT(col)
SELECT SUM(col)
SELECT AVG(col)
SELECT MIN(col)
SELECT MAX(col)
SELECT ROUND(col, decimals) --number of decimals as an int
```

**GROUP BY**: Allows us to perform an operation on some column and give a result wrt groups of identical data in another one

{% include end-row.html %}
{% include start-row.html %}

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

{% include end-row.html %}
