begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)sigsetjmp.c	5.1 (Berkeley) 5/27/90"
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
file|<setjmp.h>
end_include

begin_macro
name|sigsetjmp
argument_list|(
argument|env
argument_list|,
argument|savemask
argument_list|)
end_macro

begin_decl_stmt
name|sigjmp_buf
name|env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|savemask
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|env
index|[
literal|0
index|]
operator|=
name|savemask
operator|)
condition|?
name|setjmp
argument_list|(
name|env
operator|+
literal|1
argument_list|)
else|:
name|_setjmp
argument_list|(
name|env
operator|+
literal|1
argument_list|)
operator|)
return|;
block|}
end_block

begin_function
name|void
name|siglongjmp
parameter_list|(
name|env
parameter_list|,
name|val
parameter_list|)
name|sigjmp_buf
name|env
decl_stmt|;
name|int
name|val
decl_stmt|;
block|{
if|if
condition|(
name|env
index|[
literal|0
index|]
condition|)
name|longjmp
argument_list|(
name|env
operator|+
literal|1
argument_list|,
name|val
argument_list|)
expr_stmt|;
else|else
name|_longjmp
argument_list|(
name|env
operator|+
literal|1
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

