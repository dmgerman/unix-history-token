begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: os-xinu43.h,v 5.2 90/06/23 22:21:01 jsp Rel $ */
end_comment

begin_comment
comment|/*  * mt Xinu 4.3 (MORE/bsd) definitions for Amd (automounter)  * Should work on both Vax and HP ...  *  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-xinu43.h	5.1 (Berkeley) %G%  */
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
name|RPC_4
end_define

begin_comment
comment|/*  * mt Xinu have a compatibility problem  * with getreq vs. getreqset.  On SunOS  * getreqset takes a pointer to an fd_set,  * whereas on MORE/bsd, getreq takes a  * fd_set directly (cf. an integer on SunOS).  */
end_comment

begin_define
define|#
directive|define
name|svc_getreqset
parameter_list|(
name|p
parameter_list|)
value|svc_getreq(*p)
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
value|"ufs"
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
value|"ufs"
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"little"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

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
name|Probably
name|no
name|hope
name|of
name|running
name|Amd
name|on
name|this
name|machine
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LITTLE */
end_comment

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

end_unit

