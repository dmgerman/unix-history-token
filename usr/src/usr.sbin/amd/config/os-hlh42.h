begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: os-hlh42.h,v 5.2 90/06/23 22:20:46 jsp Rel $ */
end_comment

begin_comment
comment|/*  * HLH OTS definitions for Amd (automounter)  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-hlh42.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_undef
undef|#
directive|undef
name|VOIDP
end_undef

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
comment|/*  * Byte ordering  */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hlh
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Miscellaneous HLH 4.2 incantations  */
end_comment

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|x
parameter_list|)
value|(1<< ((x)-1))
end_define

begin_comment
comment|/*  * HLH's 4.2 needs the extra RPC definitions.  */
end_comment

begin_define
define|#
directive|define
name|MISC_RPC
end_define

end_unit

