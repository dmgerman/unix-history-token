begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)rew.c	5.4 (Berkeley) 6/27/88"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_expr_stmt
name|rewind
argument_list|(
name|iop
argument_list|)
specifier|register
name|FILE
operator|*
name|iop
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|off_t
name|lseek
parameter_list|()
function_decl|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|iop
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|lseek
argument_list|(
name|fileno
argument_list|(
name|iop
argument_list|)
argument_list|,
literal|0L
argument_list|,
name|L_SET
argument_list|)
expr_stmt|;
name|iop
operator|->
name|_cnt
operator|=
literal|0
expr_stmt|;
name|iop
operator|->
name|_ptr
operator|=
name|iop
operator|->
name|_base
expr_stmt|;
name|iop
operator|->
name|_flag
operator|&=
operator|~
operator|(
name|_IOERR
operator||
name|_IOEOF
operator|)
expr_stmt|;
if|if
condition|(
name|iop
operator|->
name|_flag
operator|&
name|_IORW
condition|)
name|iop
operator|->
name|_flag
operator|&=
operator|~
operator|(
name|_IOREAD
operator||
name|_IOWRT
operator|)
expr_stmt|;
block|}
end_block

end_unit

