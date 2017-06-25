begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_LOCKDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_LOCKDEP_H_
end_define

begin_struct
struct|struct
name|lock_class_key
block|{ }
struct|;
end_struct

begin_define
define|#
directive|define
name|lockdep_set_class
parameter_list|(
name|lock
parameter_list|,
name|key
parameter_list|)
end_define

begin_define
define|#
directive|define
name|lockdep_set_class_and_name
parameter_list|(
name|lock
parameter_list|,
name|key
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|lockdep_assert_held
parameter_list|(
name|m
parameter_list|)
define|\
value|sx_assert(&(m)->sx, SA_XLOCKED)
end_define

begin_define
define|#
directive|define
name|lockdep_assert_held_once
parameter_list|(
name|m
parameter_list|)
define|\
value|sx_assert(&(m)->sx, SA_XLOCKED | SA_NOTRECURSED)
end_define

begin_define
define|#
directive|define
name|lockdep_is_held
parameter_list|(
name|m
parameter_list|)
value|(sx_xholder(&(m)->sx) == curthread)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_LOCKDEP_H_ */
end_comment

end_unit

