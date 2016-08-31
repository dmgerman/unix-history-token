begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $srcdir/conf/trap/trap_hpux.h */
end_comment

begin_function_decl
specifier|extern
name|int
name|mount_hpux
parameter_list|(
name|MTYPE_TYPE
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
name|int
name|flags
parameter_list|,
name|caddr_t
name|data
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
value|mount_hpux(type, mnt->mnt_dir, flags, mnt_data)
end_define

begin_comment
comment|/*  * HPUX 9.x does is not even consistently inconsistent with itself.  * It defines an integer mount type for PCFS, but not a string type as  * with all other mount types.  *  * XXX: remove this ugly hack when HPUX 9.0 is defunct.  */
end_comment

begin_if
if|#
directive|if
name|MOUNT_TYPE_PCFS
operator|==
name|MOUNT_PC
end_if

begin_undef
undef|#
directive|undef
name|MOUNT_TYPE_PCFS
end_undef

begin_define
define|#
directive|define
name|MOUNT_TYPE_PCFS
value|"pcfs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOUNT_TYPE_PCFS == MOUNT_PC */
end_comment

end_unit

