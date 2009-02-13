begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/o_dir.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* Copied from Richard Levitte's (richard@levitte.org) LP library.  All  * symbol names have been changed, with permission from the author.  */
end_comment

begin_comment
comment|/* $LP: LPlib/test/test_dir.c,v 1.1 2004/06/16 22:59:47 _cvs_levitte Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, Richard Levitte<richard@levitte.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"e_os2.h"
end_include

begin_include
include|#
directive|include
file|"o_dir.h"
end_include

begin_if
if|#
directive|if
name|defined
name|OPENSSL_SYS_UNIX
operator|||
name|defined
name|OPENSSL_SYS_WIN32
operator|||
name|defined
name|OPENSSL_SYS_WINCE
end_if

begin_define
define|#
directive|define
name|CURRDIR
value|"."
end_define

begin_elif
elif|#
directive|elif
name|defined
name|OPENSSL_SYS_VMS
end_elif

begin_define
define|#
directive|define
name|CURRDIR
value|"SYS$DISK:[]"
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"No supported platform defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|()
block|{
name|OPENSSL_DIR_CTX
modifier|*
name|ctx
init|=
name|NULL
decl_stmt|;
specifier|const
name|char
modifier|*
name|result
decl_stmt|;
while|while
condition|(
operator|(
name|result
operator|=
name|OPENSSL_DIR_read
argument_list|(
operator|&
name|ctx
argument_list|,
name|CURRDIR
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errno
condition|)
block|{
name|perror
argument_list|(
literal|"test_dir"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|OPENSSL_DIR_end
argument_list|(
operator|&
name|ctx
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"test_dir"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

