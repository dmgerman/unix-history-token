begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: os-sos4.h,v 5.2 90/06/23 22:20:52 jsp Rel $ */
end_comment

begin_comment
comment|/*  * SunOS 4.0 definitions for Amd (automounter)  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-sos4.h	5.1 (Berkeley) %G%  */
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
comment|/*  * What type is free(void*) returning?  */
end_comment

begin_undef
undef|#
directive|undef
name|FREE_RETURN_TYPE
end_undef

begin_define
define|#
directive|define
name|FREE_RETURN_TYPE
value|int
end_define

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_4
end_define

begin_comment
comment|/*  * Which version of the NFS interface are we using.  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|NFS_4
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mc68010
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68020
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|i386
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
value|"nfs"
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|"4.2"
end_define

begin_comment
comment|/*  * Type of a file handle  */
end_comment

begin_undef
undef|#
directive|undef
name|NFS_FH_TYPE
end_undef

begin_define
define|#
directive|define
name|NFS_FH_TYPE
value|caddr_t
end_define

begin_comment
comment|/*  * Type of filesystem type  */
end_comment

begin_undef
undef|#
directive|undef
name|MTYPE_TYPE
end_undef

begin_define
define|#
directive|define
name|MTYPE_TYPE
value|char *
end_define

begin_comment
comment|/*  * Add support for SunOS 4 automounter files  */
end_comment

begin_define
define|#
directive|define
name|SUNOS4_COMPAT
end_define

end_unit

