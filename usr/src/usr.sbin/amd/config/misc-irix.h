begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)misc-irix.h	5.4 (Berkeley) %G%  *  * $Id: misc-irix.h,v 5.2.2.1 1992/02/09 15:10:30 jsp beta $  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/fs/nfs_clnt.h>
end_include

begin_include
include|#
directive|include
file|<sys/fsid.h>
end_include

begin_include
include|#
directive|include
file|<sys/fstyp.h>
end_include

begin_struct
struct|struct
name|ufs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
block|}
struct|;
end_struct

end_unit

