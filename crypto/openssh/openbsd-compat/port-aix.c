begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 2001 Gert Doering.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_include
include|#
directive|include
file|<uinfo.h>
end_include

begin_include
include|#
directive|include
file|<../xmalloc.h>
end_include

begin_comment
comment|/*  * AIX has a "usrinfo" area where logname and other stuff is stored -   * a few applications actually use this and die if it's not set  *  * NOTE: TTY= should be set, but since no one uses it and it's hard to  * acquire due to privsep code.  We will just drop support.  */
end_comment

begin_function
name|void
name|aix_usrinfo
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
block|{
name|u_int
name|i
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|cp
operator|=
name|xmalloc
argument_list|(
literal|16
operator|+
literal|2
operator|*
name|strlen
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|=
name|sprintf
argument_list|(
name|cp
argument_list|,
literal|"LOGNAME=%s%cNAME=%s%c"
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|,
literal|0
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|usrinfo
argument_list|(
name|SETUINFO
argument_list|,
name|cp
argument_list|,
name|i
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|fatal
argument_list|(
literal|"Couldn't set usrinfo: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|debug3
argument_list|(
literal|"AIX/UsrInfo: set len %d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|xfree
argument_list|(
name|cp
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX */
end_comment

end_unit

