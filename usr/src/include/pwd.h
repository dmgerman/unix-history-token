begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pwd.h	4.1	83/05/03	*/
end_comment

begin_struct
struct|struct
name|passwd
block|{
comment|/* see getpwent(3) */
name|char
modifier|*
name|pw_name
decl_stmt|;
name|char
modifier|*
name|pw_passwd
decl_stmt|;
name|int
name|pw_uid
decl_stmt|;
name|int
name|pw_gid
decl_stmt|;
name|int
name|pw_quota
decl_stmt|;
name|char
modifier|*
name|pw_comment
decl_stmt|;
name|char
modifier|*
name|pw_gecos
decl_stmt|;
name|char
modifier|*
name|pw_dir
decl_stmt|;
name|char
modifier|*
name|pw_shell
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwent
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|,
modifier|*
name|getpwnam
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

