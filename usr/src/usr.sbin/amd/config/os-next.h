begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-next.h	5.5 (Berkeley) %G%  *  * $Id: os-next.h,v 5.2.2.1 1992/02/09 15:10:33 jsp beta $  *  * NeXT OS definitions for Amd (automounter)  * By Bill Trost, Reed College  * trost%reed@cse.ogi.edu,  *  * Derived from the Sun 3.2 definitions for Amd (os-sos3.h).  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *	(NeXT uses gcc)  */
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
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|MOUNT_UFS
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|MOUNT_NFS
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
value|"4.3"
end_define

begin_comment
comment|/*  * Where to get NFS definitions  */
end_comment

begin_define
define|#
directive|define
name|NFS_HDR
value|"misc-next.h"
end_define

end_unit

