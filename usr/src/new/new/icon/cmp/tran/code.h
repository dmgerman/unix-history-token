begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * code generator parameters  */
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
comment|/*  * code generator structures  */
end_comment

begin_struct
struct|struct
name|loopstk
block|{
name|int
name|nextlab
decl_stmt|;
name|int
name|breaklab
decl_stmt|;
name|int
name|markcount
decl_stmt|;
name|int
name|ltype
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|casestk
block|{
name|int
name|endlab
decl_stmt|;
name|nodeptr
name|deftree
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|creatstk
block|{
name|int
name|nextlab
decl_stmt|;
name|int
name|breaklab
decl_stmt|;
block|}
struct|;
end_struct

end_unit

