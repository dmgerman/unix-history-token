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
literal|"@(#)wwsuspend.c	3.9 (Berkeley) 6/29/88"
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
file|"tt.h"
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_macro
name|wwsuspend
argument_list|()
end_macro

begin_block
block|{
name|int
function_decl|(
modifier|*
name|oldsig
function_decl|)
parameter_list|()
function_decl|;
name|oldsig
operator|=
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|wwend
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|wwsettty
argument_list|(
literal|0
argument_list|,
operator|&
name|wwnewtty
argument_list|,
operator|&
name|wwoldtty
argument_list|)
expr_stmt|;
call|(
modifier|*
name|tt
operator|.
name|tt_init
call|)
argument_list|()
expr_stmt|;
name|wwredraw
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|oldsig
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

