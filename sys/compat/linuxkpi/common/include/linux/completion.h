begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_COMPLETION_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_COMPLETION_H_
end_define

begin_include
include|#
directive|include
file|<linux/errno.h>
end_include

begin_struct
struct|struct
name|completion
block|{
name|unsigned
name|int
name|done
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INIT_COMPLETION
parameter_list|(
name|c
parameter_list|)
define|\
value|((c).done = 0)
end_define

begin_define
define|#
directive|define
name|init_completion
parameter_list|(
name|c
parameter_list|)
define|\
value|do { (c)->done = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|reinit_completion
parameter_list|(
name|c
parameter_list|)
define|\
value|do { (c)->done = 0; } while (0)
end_define

begin_define
define|#
directive|define
name|complete
parameter_list|(
name|c
parameter_list|)
define|\
value|linux_complete_common((c), 0)
end_define

begin_define
define|#
directive|define
name|complete_all
parameter_list|(
name|c
parameter_list|)
define|\
value|linux_complete_common((c), 1)
end_define

begin_define
define|#
directive|define
name|wait_for_completion
parameter_list|(
name|c
parameter_list|)
define|\
value|linux_wait_for_common((c), 0)
end_define

begin_define
define|#
directive|define
name|wait_for_completion_interuptible
parameter_list|(
name|c
parameter_list|)
define|\
value|linux_wait_for_common((c), 1)
end_define

begin_define
define|#
directive|define
name|wait_for_completion_timeout
parameter_list|(
name|c
parameter_list|,
name|timeout
parameter_list|)
define|\
value|linux_wait_for_timeout_common((c), (timeout), 0)
end_define

begin_define
define|#
directive|define
name|wait_for_completion_interruptible_timeout
parameter_list|(
name|c
parameter_list|,
name|timeout
parameter_list|)
define|\
value|linux_wait_for_timeout_common((c), (timeout), 1)
end_define

begin_define
define|#
directive|define
name|try_wait_for_completion
parameter_list|(
name|c
parameter_list|)
define|\
value|linux_try_wait_for_completion(c)
end_define

begin_define
define|#
directive|define
name|completion_done
parameter_list|(
name|c
parameter_list|)
define|\
value|linux_completion_done(c)
end_define

begin_function_decl
specifier|extern
name|void
name|linux_complete_common
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|linux_wait_for_common
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|linux_wait_for_timeout_common
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_try_wait_for_completion
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|linux_completion_done
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_COMPLETION_H_ */
end_comment

end_unit

