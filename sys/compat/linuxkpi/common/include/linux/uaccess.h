begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.  * Copyright (c) 2015 FranÃ§ois Tigeot  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_UACCESS_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_UACCESS_H_
end_define

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_define
define|#
directive|define
name|__get_user
parameter_list|(
name|_x
parameter_list|,
name|_p
parameter_list|)
value|({					\ 	int __err;						\ 	__typeof(*(_p)) __x;					\ 	__err = linux_copyin((_p),&(__x), sizeof(*(_p)));	\ 	(_x) = __x;						\ 	__err;							\ })
end_define

begin_define
define|#
directive|define
name|__put_user
parameter_list|(
name|_x
parameter_list|,
name|_p
parameter_list|)
value|({				\ 	__typeof(*(_p)) __x = (_x);			\ 	linux_copyout(&(__x), (_p), sizeof(*(_p)));	\ })
end_define

begin_define
define|#
directive|define
name|get_user
parameter_list|(
name|_x
parameter_list|,
name|_p
parameter_list|)
value|linux_copyin((_p),&(_x), sizeof(*(_p)))
end_define

begin_define
define|#
directive|define
name|put_user
parameter_list|(
name|_x
parameter_list|,
name|_p
parameter_list|)
value|linux_copyout(&(_x), (_p), sizeof(*(_p)))
end_define

begin_function_decl
specifier|extern
name|int
name|linux_copyin
parameter_list|(
specifier|const
name|void
modifier|*
name|uaddr
parameter_list|,
name|void
modifier|*
name|kaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_copyout
parameter_list|(
specifier|const
name|void
modifier|*
name|kaddr
parameter_list|,
name|void
modifier|*
name|uaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * NOTE: The returned value from pagefault_disable() must be stored  * and passed to pagefault_enable(). Else possible recursion on the  * state can be lost.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|__must_check
name|pagefault_disable
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|vm_fault_disable_pagefaults
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|pagefault_enable
parameter_list|(
name|int
name|save
parameter_list|)
block|{
name|vm_fault_enable_pagefaults
argument_list|(
name|save
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_UACCESS_H_ */
end_comment

end_unit

