begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/trap/trap_mach3.h */
end_comment

begin_function_decl
specifier|extern
name|int
name|mount_mach3
parameter_list|(
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|mnt
parameter_list|,
name|int
name|flags
parameter_list|,
name|caddr_t
name|mnt_data
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
value|mount_mach(type, mnt, flags, mnt_data)
end_define

end_unit

