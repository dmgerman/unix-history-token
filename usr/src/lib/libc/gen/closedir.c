begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)closedir.c	5.3 (Berkeley) 6/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_comment
comment|/*  * close a directory.  */
end_comment

begin_function
name|void
name|closedir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
block|{
name|close
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|)
expr_stmt|;
name|dirp
operator|->
name|dd_fd
operator|=
operator|-
literal|1
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

