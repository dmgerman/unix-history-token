begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-fpx4.h	5.5 (Berkeley) %G%  *  * $Id: os-fpx4.h,v 5.2.2.2 1992/05/31 16:39:34 jsp Exp $  *  * Celerity FPX 4.1/2 definitions for Amd (automounter)  *      from Stephen Pope<scp@grizzly.acl.lanl.gov>  */
end_comment

begin_comment
comment|/*  * FPX wants to include sys headers multiple times  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_HEADERS
end_define

begin_comment
comment|/*  * FPX sys/mount.h includes sys/nfs.h; prevent this  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_nfs
end_define

begin_comment
comment|/*  * FPX doesn't define NMOUNT anywhere  */
end_comment

begin_define
define|#
directive|define
name|NMOUNT
value|40
end_define

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_comment
comment|/* #define VOIDP */
end_comment

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_4
end_define

begin_define
define|#
directive|define
name|svc_fdset
value|svc_fds
end_define

begin_define
define|#
directive|define
name|svc_getreqset
parameter_list|(
name|p
parameter_list|)
value|svc_getreq((*p).fds_bits[0])
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

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
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

end_unit

