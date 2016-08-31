begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/trap/trap_ultrix.h */
end_comment

begin_comment
comment|/* arg 3 to mount(2) is rwflag */
end_comment

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
value|mount(mnt->mnt_fsname, mnt->mnt_dir, flags& MNT2_GEN_OPT_RONLY, type, mnt_data)
end_define

end_unit

