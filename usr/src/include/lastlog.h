begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	lastlog.h	4.2	83/05/22	*/
end_comment

begin_struct
struct|struct
name|lastlog
block|{
name|time_t
name|ll_time
decl_stmt|;
name|char
name|ll_line
index|[
literal|8
index|]
decl_stmt|;
name|char
name|ll_host
index|[
literal|16
index|]
decl_stmt|;
comment|/* same as in utmp */
block|}
struct|;
end_struct

end_unit

