begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Seigo Tanimura  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CSA_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_CSA_VAR_H
end_define

begin_struct
struct|struct
name|csa_card
block|{
name|u_int16_t
name|subvendor
decl_stmt|,
name|subdevice
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|amp
decl_stmt|;
name|void
modifier|*
name|amp_init
decl_stmt|;
name|int
function_decl|(
modifier|*
name|active
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
name|inv_eapd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Resources. */
end_comment

begin_struct
struct|struct
name|csa_res
block|{
name|int
name|io_rid
decl_stmt|;
comment|/* io rid */
name|struct
name|resource
modifier|*
name|io
decl_stmt|;
comment|/* io */
name|int
name|mem_rid
decl_stmt|;
comment|/* memory rid */
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
comment|/* memory */
name|int
name|irq_rid
decl_stmt|;
comment|/* irq rid */
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
comment|/* irq */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|csa_res
name|csa_res
typedef|;
end_typedef

begin_comment
comment|/* State of the bridge. */
end_comment

begin_struct
struct|struct
name|csa_bridgeinfo
block|{
name|u_int32_t
name|hisr
decl_stmt|;
comment|/* The value of HISR on this interrupt. */
name|struct
name|csa_card
modifier|*
name|card
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|csa_clearserialfifos
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Common functions for csa. */
end_comment

begin_function_decl
name|struct
name|csa_card
modifier|*
name|csa_findsubcard
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csa_readcodec
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_int32_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|csa_writecodec
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_int32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|csa_readio
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|csa_writeio
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_int32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|csa_readmem
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|,
name|u_long
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|csa_writemem
parameter_list|(
name|csa_res
modifier|*
name|resp
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_int32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CSA_VAR_H */
end_comment

end_unit

