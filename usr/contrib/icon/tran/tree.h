begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure of a tree node.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|node
modifier|*
name|nodeptr
typedef|;
end_typedef

begin_struct
struct|struct
name|node
block|{
name|int
name|n_type
decl_stmt|;
comment|/* node type */
name|int
name|n_line
decl_stmt|;
comment|/* line number in source program */
name|int
name|n_col
decl_stmt|;
comment|/* column number in source program */
union|union
block|{
name|int
name|n_val
decl_stmt|;
comment|/* integer-valued fields */
name|char
modifier|*
name|n_str
decl_stmt|;
comment|/* string-valued fields */
name|nodeptr
name|n_ptr
decl_stmt|;
comment|/* subtree pointers */
block|}
name|n_field
index|[
literal|4
index|]
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros to access fields of parse tree nodes.  */
end_comment

begin_define
define|#
directive|define
name|TYPE
parameter_list|(
name|t
parameter_list|)
value|t->n_type
end_define

begin_define
define|#
directive|define
name|LINE
parameter_list|(
name|t
parameter_list|)
value|t->n_line
end_define

begin_define
define|#
directive|define
name|COL
parameter_list|(
name|t
parameter_list|)
value|t->n_col
end_define

begin_define
define|#
directive|define
name|TREE0
parameter_list|(
name|t
parameter_list|)
value|t->n_field[0].n_ptr
end_define

begin_define
define|#
directive|define
name|TREE1
parameter_list|(
name|t
parameter_list|)
value|t->n_field[1].n_ptr
end_define

begin_define
define|#
directive|define
name|TREE2
parameter_list|(
name|t
parameter_list|)
value|t->n_field[2].n_ptr
end_define

begin_define
define|#
directive|define
name|TREE3
parameter_list|(
name|t
parameter_list|)
value|t->n_field[3].n_ptr
end_define

begin_define
define|#
directive|define
name|VAL0
parameter_list|(
name|t
parameter_list|)
value|t->n_field[0].n_val
end_define

begin_define
define|#
directive|define
name|VAL1
parameter_list|(
name|t
parameter_list|)
value|t->n_field[1].n_val
end_define

begin_define
define|#
directive|define
name|VAL2
parameter_list|(
name|t
parameter_list|)
value|t->n_field[2].n_val
end_define

begin_define
define|#
directive|define
name|VAL3
parameter_list|(
name|t
parameter_list|)
value|t->n_field[3].n_val
end_define

begin_define
define|#
directive|define
name|STR0
parameter_list|(
name|t
parameter_list|)
value|t->n_field[0].n_str
end_define

begin_define
define|#
directive|define
name|STR1
parameter_list|(
name|t
parameter_list|)
value|t->n_field[1].n_str
end_define

begin_define
define|#
directive|define
name|STR2
parameter_list|(
name|t
parameter_list|)
value|t->n_field[2].n_str
end_define

begin_define
define|#
directive|define
name|STR3
parameter_list|(
name|t
parameter_list|)
value|t->n_field[3].n_str
end_define

begin_comment
comment|/*  * External declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|nodeptr
name|tree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parse tree space */
end_comment

begin_decl_stmt
specifier|extern
name|nodeptr
name|tfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for tree space */
end_comment

begin_decl_stmt
specifier|extern
name|nodeptr
name|tend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of tree space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parse tree size (integers) */
end_comment

begin_function_decl
specifier|extern
name|nodeptr
name|tree1
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tree node allocator routines */
end_comment

begin_function_decl
specifier|extern
name|nodeptr
name|tree3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nodeptr
name|tree4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nodeptr
name|tree5
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|nodeptr
name|tree6
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|nodeptr
name|yylval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parser's current token value */
end_comment

begin_comment
comment|/*  * Node types.  */
end_comment

begin_define
define|#
directive|define
name|N_ACTIVAT
value|1
end_define

begin_comment
comment|/* activation control structure */
end_comment

begin_define
define|#
directive|define
name|N_ALT
value|2
end_define

begin_comment
comment|/* alternation operator */
end_comment

begin_define
define|#
directive|define
name|N_AUGOP
value|3
end_define

begin_comment
comment|/* augmented operator */
end_comment

begin_define
define|#
directive|define
name|N_BAR
value|4
end_define

begin_comment
comment|/* generator control structure */
end_comment

begin_define
define|#
directive|define
name|N_BINOP
value|5
end_define

begin_comment
comment|/* other binary operator */
end_comment

begin_define
define|#
directive|define
name|N_BREAK
value|6
end_define

begin_comment
comment|/* break statement */
end_comment

begin_define
define|#
directive|define
name|N_CASE
value|7
end_define

begin_comment
comment|/* case statement */
end_comment

begin_define
define|#
directive|define
name|N_CCLS
value|8
end_define

begin_comment
comment|/* case clause */
end_comment

begin_define
define|#
directive|define
name|N_CLIST
value|9
end_define

begin_comment
comment|/* list of case clauses */
end_comment

begin_define
define|#
directive|define
name|N_CONJ
value|10
end_define

begin_comment
comment|/* conjunction operator */
end_comment

begin_define
define|#
directive|define
name|N_CREATE
value|11
end_define

begin_comment
comment|/* create control structure */
end_comment

begin_define
define|#
directive|define
name|N_CSET
value|12
end_define

begin_comment
comment|/* cset literal */
end_comment

begin_define
define|#
directive|define
name|N_ELIST
value|14
end_define

begin_comment
comment|/* list of expressions */
end_comment

begin_define
define|#
directive|define
name|N_EMPTY
value|15
end_define

begin_comment
comment|/* empty expression or statement */
end_comment

begin_define
define|#
directive|define
name|N_FIELD
value|16
end_define

begin_comment
comment|/* record field reference */
end_comment

begin_define
define|#
directive|define
name|N_ID
value|17
end_define

begin_comment
comment|/* identifier token */
end_comment

begin_define
define|#
directive|define
name|N_IF
value|18
end_define

begin_comment
comment|/* if-then-else statement */
end_comment

begin_define
define|#
directive|define
name|N_INT
value|19
end_define

begin_comment
comment|/* integer literal */
end_comment

begin_define
define|#
directive|define
name|N_INVOK
value|20
end_define

begin_comment
comment|/* procedure call */
end_comment

begin_define
define|#
directive|define
name|N_KEY
value|21
end_define

begin_comment
comment|/* keyword */
end_comment

begin_define
define|#
directive|define
name|N_LIMIT
value|22
end_define

begin_comment
comment|/* LIMIT control structure */
end_comment

begin_define
define|#
directive|define
name|N_LIST
value|23
end_define

begin_comment
comment|/* [ ... ] style list */
end_comment

begin_define
define|#
directive|define
name|N_LOOP
value|24
end_define

begin_comment
comment|/* while, until, every, or repeat */
end_comment

begin_define
define|#
directive|define
name|N_NOT
value|25
end_define

begin_comment
comment|/* not prefix control structure */
end_comment

begin_define
define|#
directive|define
name|N_NEXT
value|26
end_define

begin_comment
comment|/* next statement */
end_comment

begin_define
define|#
directive|define
name|N_OP
value|27
end_define

begin_comment
comment|/* operator token */
end_comment

begin_define
define|#
directive|define
name|N_PROC
value|28
end_define

begin_comment
comment|/* procedure */
end_comment

begin_define
define|#
directive|define
name|N_REAL
value|29
end_define

begin_comment
comment|/* real literal */
end_comment

begin_define
define|#
directive|define
name|N_RES
value|30
end_define

begin_comment
comment|/* reserved word token */
end_comment

begin_define
define|#
directive|define
name|N_RET
value|31
end_define

begin_comment
comment|/* fail, return, or succeed */
end_comment

begin_define
define|#
directive|define
name|N_SCAN
value|32
end_define

begin_comment
comment|/* scan-using statement */
end_comment

begin_define
define|#
directive|define
name|N_SECT
value|33
end_define

begin_comment
comment|/* s[i:j] (section) */
end_comment

begin_define
define|#
directive|define
name|N_SLIST
value|34
end_define

begin_comment
comment|/* list of statements */
end_comment

begin_define
define|#
directive|define
name|N_STR
value|35
end_define

begin_comment
comment|/* string literal */
end_comment

begin_define
define|#
directive|define
name|N_SUSP
value|36
end_define

begin_comment
comment|/* suspend statement */
end_comment

begin_define
define|#
directive|define
name|N_TO
value|37
end_define

begin_comment
comment|/* TO operator */
end_comment

begin_define
define|#
directive|define
name|N_TOBY
value|38
end_define

begin_comment
comment|/* TO-BY operator */
end_comment

begin_define
define|#
directive|define
name|N_UNOP
value|39
end_define

begin_comment
comment|/* unary operator */
end_comment

begin_comment
comment|/*  * Node constructor macros.  */
end_comment

begin_define
define|#
directive|define
name|ACTIVNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree6(N_ACTIVAT,LINE(a),COL(a),a,b,c)
end_define

begin_define
define|#
directive|define
name|ALTNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_ALT,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|AUGOPNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree6(N_AUGOP,LINE(a),COL(a),a,b,c)
end_define

begin_define
define|#
directive|define
name|BARNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_BAR,LINE(a),COL(a),a)
end_define

begin_define
define|#
directive|define
name|BINOPNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree6(N_BINOP,LINE(a),COL(a),a,b,c)
end_define

begin_define
define|#
directive|define
name|BREAKNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree4(N_BREAK,LINE(a),COL(a),b)
end_define

begin_define
define|#
directive|define
name|CASENODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_CASE,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|CCLSNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_CCLS,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|CLISTNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_CLIST,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|CONJNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree6(N_CONJ,LINE(a),COL(a),a,b,c)
end_define

begin_define
define|#
directive|define
name|CREATENODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree4(N_CREATE,LINE(a),COL(a),b)
end_define

begin_define
define|#
directive|define
name|CSETNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree5(N_CSET,tline,tcol,a,b)
end_define

begin_define
define|#
directive|define
name|ELISTNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_ELIST,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|EMPTYNODE
value|tree1(N_EMPTY)
end_define

begin_define
define|#
directive|define
name|FIELDNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_FIELD,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|IDNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_ID,tline,tcol,a)
end_define

begin_define
define|#
directive|define
name|IFNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|tree6(N_IF,LINE(a),COL(a),b,c,d)
end_define

begin_define
define|#
directive|define
name|INTNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_INT,tline,tcol,a)
end_define

begin_define
define|#
directive|define
name|INVOKNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_INVOK,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|KEYNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree4(N_KEY,LINE(a),COL(a),b)
end_define

begin_define
define|#
directive|define
name|LIMITNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree5(N_LIMIT,LINE(a),COL(a),a,b)
end_define

begin_define
define|#
directive|define
name|LISTNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree4(N_LIST,LINE(a),COL(a),b)
end_define

begin_define
define|#
directive|define
name|LOOPNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree6(N_LOOP,LINE(a),COL(a),a,b,c)
end_define

begin_define
define|#
directive|define
name|NOTNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_NOT,LINE(a),COL(a),a)
end_define

begin_define
define|#
directive|define
name|NEXTNODE
parameter_list|(
name|a
parameter_list|)
value|tree3(N_NEXT,LINE(a),COL(a))
end_define

begin_define
define|#
directive|define
name|OPNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_OP,tline,tcol,a)
end_define

begin_define
define|#
directive|define
name|PROCNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|tree7(N_PROC,LINE(a),COL(a),a,b,c,d)
end_define

begin_define
define|#
directive|define
name|REALNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_REAL,tline,tcol,a)
end_define

begin_define
define|#
directive|define
name|RESNODE
parameter_list|(
name|a
parameter_list|)
value|tree4(N_RES,tline,tcol,a)
end_define

begin_define
define|#
directive|define
name|RETNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree5(N_RET,LINE(a),COL(a),a,b)
end_define

begin_define
define|#
directive|define
name|SCANNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree6(N_SCAN,LINE(a),COL(a),a,b,c)
end_define

begin_define
define|#
directive|define
name|SECTNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|tree7(N_SECT,LINE(a),COL(a),a,b,c,d)
end_define

begin_define
define|#
directive|define
name|SLISTNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_SLIST,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|STRNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree5(N_STR,tline,tcol,a,b)
end_define

begin_define
define|#
directive|define
name|SUSPNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree4(N_SUSP,LINE(a),COL(a),b)
end_define

begin_define
define|#
directive|define
name|TOBYNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|tree6(N_TOBY,LINE(a),COL(a),b,c,d)
end_define

begin_define
define|#
directive|define
name|TONODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|tree5(N_TO,LINE(a),COL(a),b,c)
end_define

begin_define
define|#
directive|define
name|UNOPNODE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tree5(N_UNOP,LINE(a),COL(a),a,b)
end_define

end_unit

