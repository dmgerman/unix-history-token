begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)misc-ultrix.h	5.4 (Berkeley) %G%  *  * $Id: misc-ultrix.h,v 5.2.2.1 1992/02/09 15:10:49 jsp beta $  *  */
end_comment

begin_include
include|#
directive|include
file|<nfs/nfs_gfs.h>
end_include

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_include
include|#
directive|include
file|<sys/fs_types.h>
end_include

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTNAMESZ
end_ifndef

begin_include
include|#
directive|include
file|<nfs/nfs_clnt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ufs/ufs_mount.h>
end_include

begin_define
define|#
directive|define
name|ufs_args
value|ufs_specific
end_define

end_unit

