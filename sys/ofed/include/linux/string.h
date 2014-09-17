begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_STRING_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_STRING_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/gfp.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_define
define|#
directive|define
name|strnicmp
value|strncasecmp
end_define

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|kmemdup
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|gfp_t
name|gfp
parameter_list|)
block|{
name|void
modifier|*
name|dst
decl_stmt|;
name|dst
operator|=
name|kmalloc
argument_list|(
name|len
argument_list|,
name|gfp
argument_list|)
expr_stmt|;
if|if
condition|(
name|dst
condition|)
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_STRING_H_ */
end_comment

end_unit

