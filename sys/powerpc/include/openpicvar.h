begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_OPENPICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_OPENPICVAR_H_
end_define

begin_define
define|#
directive|define
name|OPENPIC_DEVSTR
value|"OpenPIC Interrupt Controller"
end_define

begin_define
define|#
directive|define
name|OPENPIC_IRQMAX
value|256
end_define

begin_comment
comment|/* h/w allows more */
end_comment

begin_struct
struct|struct
name|openpic_softc
block|{
name|char
modifier|*
name|sc_version
decl_stmt|;
name|u_int
name|sc_ncpu
decl_stmt|;
name|u_int
name|sc_nirq
decl_stmt|;
name|int
name|sc_psim
decl_stmt|;
name|struct
name|rman
name|sc_rman
decl_stmt|;
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
name|u_int
name|sc_hwprobed
decl_stmt|;
name|u_int
name|sc_early_done
decl_stmt|;
name|device_t
name|sc_altdev
decl_stmt|;
name|u_char
name|sc_irqrsv
index|[
name|OPENPIC_IRQMAX
index|]
decl_stmt|;
comment|/* pre-h/w reservation */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bus-independent attach i/f  */
end_comment

begin_function_decl
name|int
name|openpic_early_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpic_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PIC interface.  */
end_comment

begin_function_decl
name|struct
name|resource
modifier|*
name|openpic_allocate_intr
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpic_setup_intr
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|,
name|int
parameter_list|,
name|driver_filter_t
parameter_list|,
name|driver_intr_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpic_teardown_intr
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpic_release_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_OPENPICVAR_H_ */
end_comment

end_unit

