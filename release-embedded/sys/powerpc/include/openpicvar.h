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

begin_comment
comment|/* Names match the macros in openpicreg.h. */
end_comment

begin_struct
struct|struct
name|openpic_timer
block|{
name|uint32_t
name|tcnt
decl_stmt|;
name|uint32_t
name|tbase
decl_stmt|;
name|uint32_t
name|tvec
decl_stmt|;
name|uint32_t
name|tdst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|openpic_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_memr
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_intr
decl_stmt|;
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
name|char
modifier|*
name|sc_version
decl_stmt|;
name|int
name|sc_rid
decl_stmt|;
name|int
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_icookie
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
comment|/* Saved states. */
name|uint32_t
name|sc_saved_config
decl_stmt|;
name|uint32_t
name|sc_saved_ipis
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|sc_saved_prios
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|openpic_timer
name|sc_saved_timers
index|[
name|OPENPIC_TIMERS
index|]
decl_stmt|;
name|uint32_t
name|sc_saved_vectors
index|[
name|OPENPIC_SRC_VECTOR_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|openpic_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bus-independent attach i/f  */
end_comment

begin_function_decl
name|int
name|openpic_common_attach
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PIC interface.  */
end_comment

begin_function_decl
name|void
name|openpic_bind
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|irq
parameter_list|,
name|cpuset_t
name|cpumask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_config
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|intr_trigger
parameter_list|,
name|enum
name|intr_polarity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_dispatch
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_enable
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_eoi
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_ipi
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_mask
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|openpic_unmask
parameter_list|(
name|device_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpic_resume
parameter_list|(
name|device_t
name|dev
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

