begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure for stty and gtty system calls.  */
end_comment

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|sg_ospeed
decl_stmt|;
comment|/* output speed */
name|char
name|sg_erase
decl_stmt|;
comment|/* erase character */
name|char
name|sg_kill
decl_stmt|;
comment|/* kill character */
name|int
name|sg_flags
decl_stmt|;
comment|/* mode flags */
block|}
struct|;
end_struct

end_unit

