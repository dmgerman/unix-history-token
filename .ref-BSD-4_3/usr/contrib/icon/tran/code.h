begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Code generator parameters.  */
end_comment

begin_define
define|#
directive|define
name|LOOPDEPTH
value|20
end_define

begin_comment
comment|/* max. depth of nested loops */
end_comment

begin_define
define|#
directive|define
name|CASEDEPTH
value|10
end_define

begin_comment
comment|/* max. depth of nested case statements */
end_comment

begin_define
define|#
directive|define
name|CREATDEPTH
value|10
end_define

begin_comment
comment|/* max. depth of nested create statements */
end_comment

begin_comment
comment|/*  * loopstk structures hold information about nested loops.  */
end_comment

begin_struct
struct|struct
name|loopstk
block|{
name|int
name|nextlab
decl_stmt|;
comment|/* label for next exit */
name|int
name|breaklab
decl_stmt|;
comment|/* label for break exit */
name|int
name|markcount
decl_stmt|;
comment|/* number of marks */
name|int
name|ltype
decl_stmt|;
comment|/* loop type */
block|}
struct|;
end_struct

begin_comment
comment|/*  * casestk structure hold information about case statements.  */
end_comment

begin_struct
struct|struct
name|casestk
block|{
name|int
name|endlab
decl_stmt|;
comment|/* label for exit from case statement */
name|nodeptr
name|deftree
decl_stmt|;
comment|/* pointer to tree for default clause */
block|}
struct|;
end_struct

begin_comment
comment|/*  * creatstk structures hold information about create statements.  */
end_comment

begin_struct
struct|struct
name|creatstk
block|{
name|int
name|nextlab
decl_stmt|;
comment|/* previous value of nextlab */
name|int
name|breaklab
decl_stmt|;
comment|/* previous value of breaklab */
block|}
struct|;
end_struct

end_unit

