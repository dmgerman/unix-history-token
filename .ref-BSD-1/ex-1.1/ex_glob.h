begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB  * Version 1.0 September, 1977  */
end_comment

begin_struct
struct|struct
name|Glob
block|{
name|char
name|Ab
index|[
literal|522
index|]
decl_stmt|;
name|char
modifier|*
name|Ava
index|[
literal|200
index|]
decl_stmt|;
block|}
modifier|*
name|G
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xargv0
decl_stmt|,
modifier|*
modifier|*
name|xargv
decl_stmt|,
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xargc0
decl_stmt|,
name|xargc
decl_stmt|,
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gargc
decl_stmt|;
end_decl_stmt

end_unit

