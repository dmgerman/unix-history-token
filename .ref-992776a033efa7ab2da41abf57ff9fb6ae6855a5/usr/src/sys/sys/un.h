begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	un.h	5.1	82/08/02	*/
end_comment

begin_comment
comment|/*  * Definitions for UNIX IPC domain.  */
end_comment

begin_struct
struct|struct
name|sockaddr_un
block|{
name|short
name|sun_family
decl_stmt|;
comment|/* AF_UNIX */
name|char
name|sun_path
index|[
literal|14
index|]
decl_stmt|;
comment|/* path name */
block|}
struct|;
end_struct

end_unit

