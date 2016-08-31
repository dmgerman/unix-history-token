begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/trap/trap_netbsd.h */
end_comment

begin_if
if|#
directive|if
name|__NetBSD_Version__
operator|>=
literal|499002300
end_if

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
value|mount(type, mnt->mnt_dir, flags, mnt_data, 0)
end_define

begin_else
else|#
directive|else
end_else

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
value|mount(type, mnt->mnt_dir, flags, mnt_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

