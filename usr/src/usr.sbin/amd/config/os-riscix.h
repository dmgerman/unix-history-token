begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: os-riscix.h,v 5.2.1.1 90/10/21 22:31:03 jsp Exp $ */
end_comment

begin_comment
comment|/*  * Acorn Archimedes RISC iX definitions for Amd (automounter)  * Contributed by Piete Brooks.  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-riscix.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_define
define|#
directive|define
name|VOIDP
end_define

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
comment|/*  * Does this OS have NDBM support?  */
end_comment

begin_define
define|#
directive|define
name|OS_HAS_NDBM
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_comment
comment|/*  * Is the mount table mirrored in software  */
end_comment

begin_define
define|#
directive|define
name|UPDATE_MTAB
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

begin_undef
undef|#
directive|undef
name|MTAB_TYPE_UFS
end_undef

begin_define
define|#
directive|define
name|MTAB_TYPE_UFS
value|MNTTYPE_43
end_define

end_unit

