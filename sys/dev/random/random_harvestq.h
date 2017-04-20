begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2015, 2017 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
value|2
end_define

begin_comment
comment|/* Max length in words of each harvested entropy unit */
end_comment

begin_comment
comment|/* These are used to queue harvested packets of entropy. The entropy  * buffer size is pretty arbitrary.  */
end_comment

begin_struct
struct|struct
name|harvest_event
block|{
name|uint32_t
name|he_somecounter
decl_stmt|;
comment|/* fast counter for clock jitter */
name|uint32_t
name|he_entropy
index|[
name|HARVESTSIZE
index|]
decl_stmt|;
comment|/* some harvested entropy */
name|uint8_t
name|he_size
decl_stmt|;
comment|/* harvested entropy byte count */
name|uint8_t
name|he_bits
decl_stmt|;
comment|/* stats about the entropy */
name|uint8_t
name|he_destination
decl_stmt|;
comment|/* destination pool of this entropy */
name|uint8_t
name|he_source
decl_stmt|;
comment|/* origin of the entropy */
block|}
name|__packed
struct|;
end_struct

begin_function_decl
name|void
name|read_rate_increment
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RANDOM_HARVEST_INIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_init(&harvest_context.hc_mtx, "entropy harvest mutex", NULL, MTX_SPIN)
end_define

begin_define
define|#
directive|define
name|RANDOM_HARVEST_LOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_lock_spin(&harvest_context.hc_mtx)
end_define

begin_define
define|#
directive|define
name|RANDOM_HARVEST_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock_spin(&harvest_context.hc_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_RANDOM_RANDOM_HARVESTQ_H_INCLUDED */
end_comment

end_unit

