begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2002 Marcel Moolenaar  * Copyright (c) 2002 Hiten Mahesh Pandya  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_comment
comment|/*  * uuid_create_nil() - create a nil UUID.  * See also:  *	http://www.opengroup.org/onlinepubs/009629399/uuid_create_nil.htm  */
end_comment

begin_function
name|void
name|uuid_create_nil
parameter_list|(
name|uuid_t
modifier|*
name|u
parameter_list|,
name|uint32_t
modifier|*
name|status
parameter_list|)
block|{
if|if
condition|(
name|status
condition|)
operator|*
name|status
operator|=
name|uuid_s_ok
expr_stmt|;
name|bzero
argument_list|(
name|u
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|u
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

