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
literal|"@(#)abort.c	5.9 (Berkeley) %G%"
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
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|void
name|abort
parameter_list|()
block|{
name|sigset_t
name|mask
decl_stmt|;
name|sigfillset
argument_list|(
operator|&
name|mask
argument_list|)
expr_stmt|;
comment|/* 	 * don't block SIGABRT to give any handler a chance; we ignore 	 * any errors -- X311J doesn't allow abort to return anyway. 	 */
name|sigdelset
argument_list|(
operator|&
name|mask
argument_list|,
name|SIGABRT
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|mask
argument_list|,
operator|(
name|sigset_t
operator|*
operator|)
name|NULL
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
comment|/* 	 * if SIGABRT ignored, or caught and the handler returns, do 	 * it again, only harder. 	 */
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
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|mask
argument_list|,
operator|(
name|sigset_t
operator|*
operator|)
name|NULL
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
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

