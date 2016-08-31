begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/trap/trap_aix3.h */
end_comment

begin_function_decl
specifier|extern
name|int
name|mount_aix3
parameter_list|(
name|char
modifier|*
name|fsname
parameter_list|,
name|char
modifier|*
name|dir
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|mnt_opts
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNT_TRAP
parameter_list|(
name|type
parameter_list|,
name|mnt
parameter_list|,
name|flags
parameter_list|,
name|mnt_data
parameter_list|)
value|mount_aix3(mnt->mnt_fsname, mnt->mnt_dir, flags, type, mnt_data, mnt->mnt_opts)
end_define

begin_comment
comment|/* there is no other better place for this missing external definition */
end_comment

begin_function_decl
specifier|extern
name|int
name|uvmount
parameter_list|(
name|int
name|VirtualFileSystemID
parameter_list|,
name|int
name|Flag
parameter_list|)
function_decl|;
end_function_decl

end_unit

