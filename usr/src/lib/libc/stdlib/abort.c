begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)abort.c	5.6 (Berkeley) %G%"
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
file|<signal.h>
end_include

begin_macro
name|abort
argument_list|()
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|sigblock
argument_list|(
operator|~
literal|0L
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGABRT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigsetmask
argument_list|(
operator|~
name|sigmask
argument_list|(
name|SIGABRT
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGABRT
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

