begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/compat/closefrom.h#1 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOSEFROM_H_
end_ifndef

begin_define
define|#
directive|define
name|_CLOSEFROM_H_
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
specifier|static
name|void
name|closefrom
parameter_list|(
name|int
name|lowfd
parameter_list|)
block|{
name|int
name|error
decl_stmt|,
name|fd
decl_stmt|,
name|maxfd
decl_stmt|;
name|error
operator|=
name|errno
expr_stmt|;
name|maxfd
operator|=
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|maxfd
operator|<
literal|0
condition|)
name|maxfd
operator|=
literal|16384
expr_stmt|;
for|for
control|(
name|fd
operator|=
name|lowfd
init|;
name|fd
operator|<=
name|maxfd
condition|;
name|fd
operator|++
control|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|error
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CLOSEFROM_H_ */
end_comment

end_unit

