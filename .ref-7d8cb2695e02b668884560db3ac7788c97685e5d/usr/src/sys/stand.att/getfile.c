begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)getfile.c	7.8 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stand.att/saio.h>
end_include

begin_macro
name|getfile
argument_list|(
argument|prompt
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|fd
decl_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
do|do
block|{
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|prompt
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|buf
argument_list|,
name|mode
argument_list|)
operator|)
operator|<=
literal|0
condition|)
do|;
return|return
operator|(
name|fd
operator|)
return|;
block|}
end_block

end_unit

