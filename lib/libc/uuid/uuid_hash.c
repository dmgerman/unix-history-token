begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Marcel Moolenaar  * Copyright (c) 2002 Hiten Mahesh Pandya  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_comment
comment|/*  * uuid_hash() - generate a hash value.  * See also:  *	http://www.opengroup.org/onlinepubs/009629399/uuid_hash.htm  */
end_comment

begin_function
name|uint16_t
name|uuid_hash
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
comment|/* 	 * Use the most frequently changing bits in the UUID as the hash 	 * value. This should yield a good enough distribution... 	 */
return|return
operator|(
operator|(
name|u
operator|)
condition|?
name|u
operator|->
name|time_low
operator|&
literal|0xffff
else|:
literal|0
operator|)
return|;
block|}
end_function

end_unit

