begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SRCU_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SRCU_H_
end_define

begin_struct
struct|struct
name|srcu_struct
block|{ }
struct|;
end_struct

begin_define
define|#
directive|define
name|srcu_dereference
parameter_list|(
name|ptr
parameter_list|,
name|srcu
parameter_list|)
value|((__typeof(*(ptr)) *)(ptr))
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
specifier|extern
name|int
name|srcu_read_lock
parameter_list|(
name|struct
name|srcu_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|srcu_read_unlock
parameter_list|(
name|struct
name|srcu_struct
modifier|*
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|synchronize_srcu
parameter_list|(
name|struct
name|srcu_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|srcu_barrier
parameter_list|(
name|struct
name|srcu_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_srcu_struct
parameter_list|(
name|struct
name|srcu_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cleanup_srcu_struct
parameter_list|(
name|struct
name|srcu_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SRCU_H_ */
end_comment

end_unit

