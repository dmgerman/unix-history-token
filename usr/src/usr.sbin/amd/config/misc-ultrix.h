begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: misc-ultrix.h,v 5.2 90/06/23 22:20:56 jsp Rel $  *  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)misc-ultrix.h	5.1 (Berkeley) 6/29/90  */
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

