begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/openpam/lib/openpam_static.c#4 $  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|OPENPAM_STATIC_MODULES
end_ifdef

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|_openpam_static_modules
argument_list|,
name|pam_module_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * OpenPAM internal  *  * Locate a statically linked module  */
end_comment

begin_function
name|pam_module_t
modifier|*
name|openpam_static
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|pam_module_t
modifier|*
modifier|*
name|module
decl_stmt|;
name|SET_FOREACH
argument_list|(
argument|module
argument_list|,
argument|_openpam_static_modules
argument_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
operator|(
operator|*
name|module
operator|)
operator|->
name|path
argument_list|,
name|path
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
operator|*
name|module
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NOPARSE  */
end_comment

end_unit

