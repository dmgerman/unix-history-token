begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	kernel.h	4.2	82/09/06	*/
end_comment

begin_comment
comment|/*  * Global variables for the kernel  */
end_comment

begin_comment
comment|/* 1.1 */
end_comment

begin_decl_stmt
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hostname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nextpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2 */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tick
decl_stmt|;
end_decl_stmt

end_unit

