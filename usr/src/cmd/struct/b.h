begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|int
name|xxindent
decl_stmt|,
name|xxval
decl_stmt|,
name|newflag
decl_stmt|,
name|xxmaxchars
decl_stmt|,
name|xxbpertab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xxlineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of lines already output */
end_comment

begin_define
define|#
directive|define
name|xxtop
value|100
end_define

begin_comment
comment|/* max size of xxstack */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xxstind
decl_stmt|,
name|xxstack
index|[
name|xxtop
index|]
decl_stmt|,
name|xxlablast
decl_stmt|,
name|xxt
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|node
block|{
name|int
name|op
decl_stmt|;
name|char
modifier|*
name|lit
decl_stmt|;
name|struct
name|node
modifier|*
name|left
decl_stmt|;
name|struct
name|node
modifier|*
name|right
decl_stmt|;
block|}
struct|;
end_struct

end_unit

