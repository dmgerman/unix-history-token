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
literal|"@(#)opendir.c	5.3 (Berkeley) 6/18/88"
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
comment|/*  * open a directory.  */
end_comment

begin_function
name|DIR
modifier|*
name|opendir
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
specifier|register
name|int
name|fd
decl_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|name
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|(
name|dirp
operator|=
operator|(
name|DIR
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|DIR
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|dirp
operator|->
name|dd_fd
operator|=
name|fd
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
literal|0
expr_stmt|;
return|return
name|dirp
return|;
block|}
end_function

end_unit

