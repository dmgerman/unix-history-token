begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|group
block|{
comment|/* see getgrent(3) */
name|char
modifier|*
name|gr_name
decl_stmt|;
name|char
modifier|*
name|gr_passwd
decl_stmt|;
name|int
name|gr_gid
decl_stmt|;
name|char
modifier|*
modifier|*
name|gr_mem
decl_stmt|;
block|}
struct|;
end_struct

end_unit

