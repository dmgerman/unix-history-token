begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Jan-Simon Pendry  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)misc-bsd44l.h	8.1 (Berkeley) %G%  *  */
end_comment

begin_define
define|#
directive|define
name|M_NEWTYPE
value|0
end_define

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_define
define|#
directive|define
name|NFS_NPROCS
value|26
end_define

begin_comment
comment|/* from<nfs/nfsproto.h> */
end_comment

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

end_unit

