begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_RANDOM_ADAPTORS_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_RANDOM_ADAPTORS_H_INCLUDED
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ENTROPY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
name|random_adaptor_init_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_adaptor_deinit_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_adaptor_read_func_t
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_adaptor_write_func_t
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|random_adaptor_seeded_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_adaptor_reseed_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|random_adaptor
block|{
specifier|const
name|char
modifier|*
name|ra_ident
decl_stmt|;
name|int
name|ra_priority
decl_stmt|;
name|random_adaptor_init_func_t
modifier|*
name|ra_init
decl_stmt|;
name|random_adaptor_deinit_func_t
modifier|*
name|ra_deinit
decl_stmt|;
name|random_adaptor_read_func_t
modifier|*
name|ra_read
decl_stmt|;
name|random_adaptor_write_func_t
modifier|*
name|ra_write
decl_stmt|;
name|random_adaptor_reseed_func_t
modifier|*
name|ra_reseed
decl_stmt|;
name|random_adaptor_seeded_func_t
modifier|*
name|ra_seeded
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|random_adaptors
block|{
name|LIST_ENTRY
argument_list|(
argument|random_adaptors
argument_list|)
name|rra_entries
expr_stmt|;
comment|/* list of providers */
specifier|const
name|char
modifier|*
name|rra_name
decl_stmt|;
comment|/* name of random adaptor */
name|struct
name|random_adaptor
modifier|*
name|rra_ra
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Dummy "always-block" pseudo-device */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|random_adaptor
name|randomdev_dummy
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|random_adaptors_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_adaptors_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_adaptor_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|random_adaptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_adaptor_deregister
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_adaptor_read
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_adaptor_write
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_adaptor_poll
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_adaptor_read_rate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_adaptor_unblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_RANDOM_RANDOM_ADAPTORS_H_INCLUDED */
end_comment

end_unit

