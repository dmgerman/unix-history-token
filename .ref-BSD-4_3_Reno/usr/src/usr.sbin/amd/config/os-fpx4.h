begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: os-fpx4.h,v 5.2 90/06/23 22:20:45 jsp Rel $ */
end_comment

begin_comment
comment|/*  * Celerity FPX 4.1/2 definitions for Amd (automounter)  *      from Stephen Pope<scp@grizzly.acl.lanl.gov>  *  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)os-fpx4.h	5.1 (Berkeley) 6/29/90  */
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

