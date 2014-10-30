begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_COMPILER_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_COMPILER_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|__user
end_define

begin_define
define|#
directive|define
name|__kernel
end_define

begin_define
define|#
directive|define
name|__safe
end_define

begin_define
define|#
directive|define
name|__force
end_define

begin_define
define|#
directive|define
name|__nocast
end_define

begin_define
define|#
directive|define
name|__iomem
end_define

begin_define
define|#
directive|define
name|__chk_user_ptr
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|__chk_io_ptr
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|__builtin_warning
parameter_list|(
name|x
parameter_list|,
name|y
modifier|...
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|__acquires
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__releases
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__acquire
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|__release
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|__cond_lock
parameter_list|(
name|x
parameter_list|,
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|__bitwise
end_define

begin_define
define|#
directive|define
name|__devinitdata
end_define

begin_define
define|#
directive|define
name|__init
end_define

begin_define
define|#
directive|define
name|__devinit
end_define

begin_define
define|#
directive|define
name|__devexit
end_define

begin_define
define|#
directive|define
name|__exit
end_define

begin_define
define|#
directive|define
name|__stringify
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|__attribute_const__
value|__attribute__((__const__))
end_define

begin_undef
undef|#
directive|undef
name|__always_inline
end_undef

begin_define
define|#
directive|define
name|__always_inline
value|inline
end_define

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_define
define|#
directive|define
name|typeof
parameter_list|(
name|x
parameter_list|)
value|__typeof(x)
end_define

begin_define
define|#
directive|define
name|uninitialized_var
parameter_list|(
name|x
parameter_list|)
value|x = x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_COMPILER_H_ */
end_comment

end_unit

