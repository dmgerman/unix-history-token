begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)READ4.c	1.10 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|READ4
parameter_list|(
name|curfile
parameter_list|)
specifier|register
name|struct
name|iorec
modifier|*
name|curfile
decl_stmt|;
block|{
name|long
name|data
decl_stmt|;
name|int
name|retval
decl_stmt|;
if|if
condition|(
name|curfile
operator|->
name|funit
operator|&
name|FWRITE
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Attempt to read, but open for writing\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
block|}
name|UNSYNC
argument_list|(
name|curfile
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|retval
operator|=
name|fscanf
argument_list|(
name|curfile
operator|->
name|fbuf
argument_list|,
literal|"%ld"
argument_list|,
operator|&
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|==
name|EOF
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Tried to read past end of file\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|retval
operator|==
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Bad data found on integer read\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errno
operator|==
name|ERANGE
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: Overflow on integer read\n"
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
name|PERROR
argument_list|(
literal|"Error encountered on integer read "
argument_list|,
name|curfile
operator|->
name|pfname
argument_list|)
expr_stmt|;
block|}
return|return
name|data
return|;
block|}
end_function

end_unit

