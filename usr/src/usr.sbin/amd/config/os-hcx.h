begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-hcx.h	5.4 (Berkeley) %G%  *  * $Id: os-hcx.h,v 5.2.2.1 1992/02/09 15:10:20 jsp beta $  *  * Harris HCX/UX Release 3.0 definitions for Amd (automounter)  */
end_comment

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_3
end_define

begin_comment
comment|/*  * Which version of the NFS interface are we using.  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|NFS_3
end_define

begin_comment
comment|/*  * Deviant call necessary.  The mount() routine in libc only works for UFS  * (it's a backward-compatible piece of C code which traps to mountsyscall).  */
end_comment

begin_undef
undef|#
directive|undef
name|MOUNT_TRAP
end_undef

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
define|\
value|mountsyscall(type, mnt->mnt_dir, flags, mnt_data)
end_define

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|MOUNT_NFS
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|MOUNT_UFS
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_hcx
end_ifdef

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XXX
operator|-
name|bizarre
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

