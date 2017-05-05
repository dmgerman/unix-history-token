begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $OpenPAM: openpam_free_envlist.c 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|"openpam_impl.h"
end_include

begin_comment
comment|/*  * OpenPAM extension  *  * Free an environment list  */
end_comment

begin_function
name|void
name|openpam_free_envlist
parameter_list|(
name|char
modifier|*
modifier|*
name|envlist
parameter_list|)
block|{
name|char
modifier|*
modifier|*
name|env
decl_stmt|;
name|ENTER
argument_list|()
expr_stmt|;
if|if
condition|(
name|envlist
operator|==
name|NULL
condition|)
name|RETURNV
argument_list|()
expr_stmt|;
for|for
control|(
name|env
operator|=
name|envlist
init|;
operator|*
name|env
operator|!=
name|NULL
condition|;
operator|++
name|env
control|)
name|FREE
argument_list|(
operator|*
name|env
argument_list|)
expr_stmt|;
name|FREE
argument_list|(
name|envlist
argument_list|)
expr_stmt|;
name|RETURNV
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Error codes:  */
end_comment

begin_comment
comment|/**  * The =openpam_free_envlist function is a convenience function which  * frees all the environment variables in an environment list, and the  * list itself.  * It is suitable for freeing the return value from =pam_getenvlist.  *  * AUTHOR DES  */
end_comment

end_unit

