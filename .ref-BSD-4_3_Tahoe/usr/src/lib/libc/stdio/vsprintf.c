begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)vsprintf.c	5.2 (Berkeley) 6/27/88"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_function
name|int
name|vsprintf
parameter_list|(
name|str
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|,
decl|*
name|fmt
decl_stmt|;
end_function

begin_decl_stmt
name|va_list
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
name|f
decl_stmt|;
name|int
name|len
decl_stmt|;
name|f
operator|.
name|_flag
operator|=
name|_IOWRT
operator|+
name|_IOSTRG
expr_stmt|;
name|f
operator|.
name|_ptr
operator|=
name|str
expr_stmt|;
name|f
operator|.
name|_cnt
operator|=
literal|32767
expr_stmt|;
name|len
operator|=
name|_doprnt
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|,
operator|&
name|f
argument_list|)
expr_stmt|;
operator|*
name|f
operator|.
name|_ptr
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|len
operator|)
return|;
block|}
end_block

end_unit

