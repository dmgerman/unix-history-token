begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: mount_irix.c,v 5.2.1.1 90/10/21 22:30:59 jsp Exp $  *  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)mount_irix.c	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * IRIX Mount helper  */
end_comment

begin_include
include|#
directive|include
file|"misc-irix.h"
end_include

begin_comment
comment|/*  * Map from conventional mount arguments  * to IRIX style arguments.  */
end_comment

begin_macro
name|irix_mount
argument_list|(
argument|fsname
argument_list|,
argument|dir
argument_list|,
argument|flags
argument_list|,
argument|type
argument_list|,
argument|data
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fsname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|data
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|size
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|dlog
argument_list|(
literal|"irix_mount: fsname %s, dir %s, type %d"
argument_list|,
name|fsname
argument_list|,
name|dir
argument_list|,
name|type
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
if|if
condition|(
name|type
operator|==
name|MOUNT_TYPE_NFS
condition|)
block|{
name|size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|nfs_args
argument_list|)
expr_stmt|;
return|return
name|mount
argument_list|(
name|dir
argument_list|,
name|dir
argument_list|,
operator|(
name|MS_FSS
operator||
name|MS_DATA
operator||
name|flags
operator|)
argument_list|,
name|type
argument_list|,
operator|(
expr|struct
name|nfs_args
operator|*
operator|)
name|data
argument_list|,
name|size
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|MOUNT_TYPE_UFS
condition|)
block|{
return|return
name|mount
argument_list|(
name|fsname
argument_list|,
name|dir
argument_list|,
operator|(
name|MS_FSS
operator||
name|flags
operator|)
argument_list|,
name|type
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|EINVAL
return|;
block|}
block|}
end_block

end_unit

