begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)signal.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * Almost backwards compatible signal.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
name|sigset_t
name|_sigintr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shared with siginterrupt */
end_comment

begin_function
name|sig_t
name|signal
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
name|int
name|s
decl_stmt|;
name|sig_t
name|a
decl_stmt|;
block|{
name|struct
name|sigaction
name|sa
decl_stmt|,
name|osa
decl_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|a
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sa
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|sigismember
argument_list|(
operator|&
name|_sigintr
argument_list|,
name|s
argument_list|)
condition|)
name|sa
operator|.
name|sa_flags
operator||=
name|SA_RESTART
expr_stmt|;
if|if
condition|(
name|sigaction
argument_list|(
name|s
argument_list|,
operator|&
name|sa
argument_list|,
operator|&
name|osa
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
name|BADSIG
operator|)
return|;
return|return
operator|(
name|osa
operator|.
name|sa_handler
operator|)
return|;
block|}
end_function

end_unit

