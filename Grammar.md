# Relational Algebra Grammar

## Features
- SELECTION COND FROM R
- PROJECT list_of_columns FROM R
- CROSS R S if common name renamed to R_name and S_name
- RENAME column_name TO column_name FROM R
- DISTINCT R
- SORT R BY 
- CLEAR R
- LOAD R 

## Grammar

```
Statement -> relation_name <- assignment_statement
           | load_statement
           | clear_statement

assignment_statement -> selection_statement
           | projection_statement
           | cross_product_statement
           | rename_statement
           | distinct_statement
           | sort_statement
           

selection_statement -> SELECT condition FROM relation_name

condition -> column_name binop column_name 
           | column_name binop int_literal

binop -> > | < | == | !=

projection_statement -> PROJECT projection_list FROM relation_name

projection_list -> projection_list, column_name 
                 | column_name

cross_product_statement -> CROSS relation_name relation_name

rename_statement -> RENAME column_name TO column_name FROM relation_name

distinct_statement -> DISTINCT relation_name

sort_statement -> SORT relation_name BY column_name

clear_statement -> CLEAR relation_name

load_statement -> LOAD relation_name

```