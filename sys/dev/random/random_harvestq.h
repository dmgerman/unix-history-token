begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Mark R V Murray  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_RANDOM_HARVESTQ_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_RANDOM_HARVESTQ_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|HARVESTSIZE
value|16
end_define

begin_comment
comment|/* max size of each harvested entropy unit */
end_comment

begin_comment
comment|/* These are used to queue harvested packets of entropy. The entropy  * buffer size is pretty arbitrary.  */
end_comment

begin_struct
struct|struct
name|harvest_event
block|{
name|uintmax_t
name|he_somecounter
decl_stmt|;
comment|/* fast counter for clock jitter */
name|uint8_t
name|he_entropy
index|[
name|HARVESTSIZE
index|]
decl_stmt|;
comment|/* some harvested entropy */
name|u_int
name|he_size
decl_stmt|;
comment|/* harvested entropy byte count */
name|u_int
name|he_bits
decl_stmt|;
comment|/* stats about the entropy */
name|u_int
name|he_destination
decl_stmt|;
comment|/* destination pool of this entropy */
name|enum
name|random_entropy_source
name|he_source
decl_stmt|;
comment|/* origin of the entropy */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|random_harvestq_init
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|harvest_event
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_harvestq_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_harvestq_internal
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|random_entropy_source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pool count is used by anything needing to know how many entropy  * pools are currently being maintained.  * This is of use to (e.g.) the live source feed where we need to give  * all the pools a top-up.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|harvest_pool_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is in randomdev.c as it needs to be permanently in the kernel */
end_comment

begin_function_decl
name|void
name|randomdev_set_wakeup_exit
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Force all currently pending queue contents to clear, and kick the software processor */
end_comment

begin_function_decl
name|void
name|random_harvestq_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Function called to process one harvested stochastic event */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|harvest_process_event
function_decl|)
parameter_list|(
name|struct
name|harvest_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Round-robin destination cache. */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|harvest_destination
index|[
name|ENTROPYSOURCE
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_RANDOM_RANDOM_HARVESTQ_H_INCLUDED */
end_comment

end_unit

