begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)isatty_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * determine if stream is associated with a tty (async port)  *  * calling sequence:  *	logical	isatty, val  *	val = isatty (lunit)  * where:  *	val will be .TRUE. if lunit is associated with a 'tty'  */
end_comment

begin_include
include|#
directive|include
file|"../libI77/fiodefs.h"
end_include

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical units table from iolib */
end_comment

begin_function
name|long
name|isatty_
parameter_list|(
name|u
parameter_list|)
name|long
modifier|*
name|u
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|unit
modifier|*
name|lu
decl_stmt|;
if|if
condition|(
operator|*
name|u
operator|<
literal|0
operator|||
operator|*
name|u
operator|>=
name|MXUNIT
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|lu
operator|=
operator|&
name|units
index|[
operator|*
name|u
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|lu
operator|->
name|ufd
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
call|(
name|long
call|)
argument_list|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|lu
operator|->
name|ufd
argument_list|)
argument_list|)
operator|!=
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

