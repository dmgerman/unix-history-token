begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)wwrint.c	3.8 (Berkeley) %G%"
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
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/*  * Tty input interrupt handler.  * (1) Read input into buffer (wwib*).  * (2) Set the interrupt flag if anything is read.  * Currently, the last is used to get out of the blocking  * select() in wwiomux().  * To avoid race conditions, we only modify wwibq in here, except  * when the buffer is empty; and everywhere else, we only change wwibp.  * It should be completely safe.  */
end_comment

begin_macro
name|wwrint
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|n
expr_stmt|;
if|if
condition|(
name|wwibp
operator|==
name|wwibq
condition|)
name|wwibp
operator|=
name|wwibq
operator|=
name|wwib
expr_stmt|;
name|wwnread
operator|++
expr_stmt|;
operator|(
name|void
operator|)
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETFL
argument_list|,
name|FNDELAY
operator||
name|wwnewtty
operator|.
name|ww_fflags
argument_list|)
expr_stmt|;
name|n
operator|=
name|read
argument_list|(
literal|0
argument_list|,
name|wwibq
argument_list|,
name|wwibe
operator|-
name|wwibq
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETFL
argument_list|,
name|wwnewtty
operator|.
name|ww_fflags
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|wwibq
operator|+=
name|n
expr_stmt|;
name|wwnreadc
operator|+=
name|n
expr_stmt|;
name|wwsetintr
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|wwnreadz
operator|++
expr_stmt|;
else|else
name|wwnreade
operator|++
expr_stmt|;
block|}
end_block

end_unit

