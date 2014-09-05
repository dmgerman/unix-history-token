begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_ERR_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_ERR_H_
end_define

begin_define
define|#
directive|define
name|MAX_ERRNO
value|4095
end_define

begin_define
define|#
directive|define
name|IS_ERR_VALUE
parameter_list|(
name|x
parameter_list|)
value|((x)>= (unsigned long)-MAX_ERRNO)
end_define

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|ERR_PTR
parameter_list|(
name|long
name|error
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|error
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|PTR_ERR
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
name|long
operator|)
name|ptr
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|IS_ERR
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|IS_ERR_VALUE
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|ERR_CAST
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|ptr
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|PTR_ERR_OR_ZERO
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|IS_ERR
argument_list|(
name|ptr
argument_list|)
condition|)
return|return
name|PTR_ERR
argument_list|(
name|ptr
argument_list|)
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|PTR_RET
parameter_list|(
name|p
parameter_list|)
value|PTR_ERR_OR_ZERO(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_ERR_H_ */
end_comment

end_unit

