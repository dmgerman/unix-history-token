begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * descriptor flags  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|0x80000000
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|0x40000000
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TRAP
value|0x20000000
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|0x10000000
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_define
define|#
directive|define
name|F_NUM
value|0x08000000
end_define

begin_comment
comment|/* set if numeric value */
end_comment

begin_define
define|#
directive|define
name|F_INT
value|0x04000000
end_define

begin_comment
comment|/* set if integer value */
end_comment

begin_define
define|#
directive|define
name|F_AGGR
value|0x02000000
end_define

begin_comment
comment|/* set if aggregrate */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|F_NQUAL
value|0100000
end_define

begin_comment
comment|/* set if NOT string qualifier */
end_comment

begin_define
define|#
directive|define
name|F_VAR
value|0040000
end_define

begin_comment
comment|/* set if variable */
end_comment

begin_define
define|#
directive|define
name|F_TRAP
value|0020000
end_define

begin_comment
comment|/* set if trapped variable */
end_comment

begin_define
define|#
directive|define
name|F_PTR
value|0010000
end_define

begin_comment
comment|/* set if value field is pointer */
end_comment

begin_define
define|#
directive|define
name|F_NUM
value|0004000
end_define

begin_comment
comment|/* set if numeric value */
end_comment

begin_define
define|#
directive|define
name|F_INT
value|0002000
end_define

begin_comment
comment|/* set if integer value */
end_comment

begin_define
define|#
directive|define
name|F_AGGR
value|0001000
end_define

begin_comment
comment|/* set if aggregrate */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * type codes (descriptors and blocks)  */
end_comment

begin_define
define|#
directive|define
name|T_INTEGER
value|1
end_define

begin_comment
comment|/* short integer (not placed in heap) */
end_comment

begin_define
define|#
directive|define
name|T_LONGINT
value|2
end_define

begin_comment
comment|/* long integer type */
end_comment

begin_define
define|#
directive|define
name|T_REAL
value|3
end_define

begin_comment
comment|/* real number */
end_comment

begin_define
define|#
directive|define
name|T_CSET
value|4
end_define

begin_comment
comment|/* cset */
end_comment

begin_define
define|#
directive|define
name|T_FILE
value|5
end_define

begin_comment
comment|/* file block */
end_comment

begin_define
define|#
directive|define
name|T_PROC
value|6
end_define

begin_comment
comment|/* procedure block */
end_comment

begin_define
define|#
directive|define
name|T_LIST
value|7
end_define

begin_comment
comment|/* list header */
end_comment

begin_define
define|#
directive|define
name|T_STACK
value|8
end_define

begin_comment
comment|/* stack header */
end_comment

begin_define
define|#
directive|define
name|T_TABLE
value|9
end_define

begin_comment
comment|/* table header */
end_comment

begin_define
define|#
directive|define
name|T_RECORD
value|10
end_define

begin_comment
comment|/* record block */
end_comment

begin_define
define|#
directive|define
name|T_TELEM
value|11
end_define

begin_comment
comment|/* table element */
end_comment

begin_define
define|#
directive|define
name|T_LISTB
value|12
end_define

begin_comment
comment|/* list element block */
end_comment

begin_define
define|#
directive|define
name|T_STACKB
value|13
end_define

begin_comment
comment|/* stack element block */
end_comment

begin_define
define|#
directive|define
name|T_TVSUBS
value|14
end_define

begin_comment
comment|/* substring trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVSUBJ
value|15
end_define

begin_comment
comment|/* subject trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVTBL
value|16
end_define

begin_comment
comment|/* table element trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVLIST
value|17
end_define

begin_comment
comment|/* list element trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVPOS
value|18
end_define

begin_comment
comment|/*&pos trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVRAND
value|19
end_define

begin_comment
comment|/*&random trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_TVTRACE
value|20
end_define

begin_comment
comment|/*&trace trapped variable */
end_comment

begin_define
define|#
directive|define
name|T_ESTACK
value|21
end_define

begin_comment
comment|/* expression stack block */
end_comment

begin_comment
comment|/*  * descriptor types and flags  */
end_comment

begin_define
define|#
directive|define
name|D_NULL
value|0
end_define

begin_define
define|#
directive|define
name|D_INTEGER
value|(T_INTEGER | F_NUM | F_INT | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LONGINT
value|(T_LONGINT | F_NUM | F_INT | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_REAL
value|(T_REAL | F_NUM | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_CSET
value|(T_CSET | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_FILE
value|(T_FILE | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_PROC
value|(T_PROC | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LIST
value|(T_LIST | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_STACK
value|(T_STACK | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TABLE
value|(T_TABLE | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_RECORD
value|(T_RECORD | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TELEM
value|(T_TELEM | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_LISTB
value|(T_LISTB | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_STACKB
value|(T_STACKB | F_AGGR | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TVSUBS
value|(T_TVSUBS | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVSUBJ
value|(T_TVSUBJ | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVTBL
value|(T_TVTBL | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVLIST
value|(T_TVLIST | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVPOS
value|(T_TVPOS | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVRAND
value|(T_TVRAND | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_TVTRACE
value|(T_TVTRACE | D_TVAR)
end_define

begin_define
define|#
directive|define
name|D_ESTACK
value|(T_ESTACK | F_PTR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_VAR
value|(F_VAR | F_NQUAL)
end_define

begin_define
define|#
directive|define
name|D_TVAR
value|(F_VAR | F_TVAR | F_NQUAL)
end_define

end_unit

