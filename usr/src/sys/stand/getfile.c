begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)getfile.c	7.5 (Berkeley) 6/28/90  */
end_comment

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"sys/time.h"
end_include

begin_include
include|#
directive|include
file|"saio.h"
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

