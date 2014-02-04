begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_RANDOMDEV_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_RANDOMDEV_H_INCLUDED
end_define

begin_comment
comment|/* This header contains only those definitions that are global  * and non algorithm-specific for the entropy processor  */
end_comment

begin_typedef
typedef|typedef
name|void
name|random_init_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_deinit_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|random_block_func_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|random_read_func_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|random_poll_func_t
parameter_list|(
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_reseed_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|random_adaptor
block|{
name|struct
name|selinfo
name|rsel
decl_stmt|;
specifier|const
name|char
modifier|*
name|ident
decl_stmt|;
name|int
name|seeded
decl_stmt|;
name|unsigned
name|priority
decl_stmt|;
name|random_init_func_t
modifier|*
name|init
decl_stmt|;
name|random_deinit_func_t
modifier|*
name|deinit
decl_stmt|;
name|random_block_func_t
modifier|*
name|block
decl_stmt|;
name|random_read_func_t
modifier|*
name|read
decl_stmt|;
name|random_poll_func_t
modifier|*
name|poll
decl_stmt|;
name|random_reseed_func_t
modifier|*
name|reseed
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|random_hardware_source
block|{
specifier|const
name|char
modifier|*
name|ident
decl_stmt|;
name|enum
name|esource
name|source
decl_stmt|;
name|random_read_func_t
modifier|*
name|read
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

