begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Capabiltiy comparison functions cap_subset, cap_equal.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* define this to pull in the cap macros the kernel uses */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|_CAPABILITY_NEEDMACROS
end_define

begin_include
include|#
directive|include
file|<sys/capability.h>
end_include

begin_undef
undef|#
directive|undef
name|_CAPABILITY_NEEDMACROS
end_undef

begin_function
name|int
name|cap_subset_np
parameter_list|(
name|cap_t
name|c1
parameter_list|,
name|cap_t
name|c2
parameter_list|)
block|{
return|return
name|CAP_SUBSET
argument_list|(
operator|*
name|c1
argument_list|,
operator|*
name|c2
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|cap_equal_np
parameter_list|(
name|cap_t
name|c1
parameter_list|,
name|cap_t
name|c2
parameter_list|)
block|{
return|return
name|c1
operator|->
name|c_effective
operator|==
name|c2
operator|->
name|c_effective
operator|&&
name|c1
operator|->
name|c_permitted
operator|==
name|c2
operator|->
name|c_permitted
operator|&&
name|c1
operator|->
name|c_inheritable
operator|==
name|c2
operator|->
name|c_inheritable
return|;
block|}
end_function

end_unit

