begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2010 Marcel Moolenaar  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_H_
end_define

begin_define
define|#
directive|define
name|IA64_NXIVS
value|256
end_define

begin_comment
comment|/* External Interrupt Vectors */
end_comment

begin_define
define|#
directive|define
name|IA64_MIN_XIV
value|16
end_define

begin_define
define|#
directive|define
name|IA64_MAX_HWPRIO
value|14
end_define

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sapic
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Layout of the Processor Interrupt Block.  */
end_comment

begin_struct
struct|struct
name|ia64_pib
block|{
name|uint64_t
name|ib_ipi
index|[
literal|65536
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* 64K-way IPIs (1MB area). */
name|uint8_t
name|_rsvd1
index|[
literal|0xe0000
index|]
decl_stmt|;
name|uint8_t
name|ib_inta
decl_stmt|;
comment|/* Generate INTA cycle. */
name|uint8_t
name|_rsvd2
index|[
literal|7
index|]
decl_stmt|;
name|uint8_t
name|ib_xtp
decl_stmt|;
comment|/* External Task Priority. */
name|uint8_t
name|_rsvd3
index|[
literal|7
index|]
decl_stmt|;
name|uint8_t
name|_rsvd4
index|[
literal|0x1fff0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ia64_xiv_use
block|{
name|IA64_XIV_FREE
block|,
name|IA64_XIV_ARCH
block|,
comment|/* Architecturally defined. */
name|IA64_XIV_PLAT
block|,
comment|/* Platform defined. */
name|IA64_XIV_IPI
block|,
comment|/* Used for IPIs. */
name|IA64_XIV_IRQ
comment|/* Used for external interrupts. */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|u_int
function_decl|(
name|ia64_ihtype
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|ia64_pib
modifier|*
name|ia64_pib
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ia64_bind_intr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_handle_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_setup_intr
parameter_list|(
specifier|const
name|char
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
name|enum
name|intr_type
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_teardown_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_xiv_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|ia64_xiv_alloc
parameter_list|(
name|u_int
parameter_list|,
name|enum
name|ia64_xiv_use
parameter_list|,
name|ia64_ihtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_xiv_free
parameter_list|(
name|u_int
parameter_list|,
name|enum
name|ia64_xiv_use
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_xiv_reserve
parameter_list|(
name|u_int
parameter_list|,
name|enum
name|ia64_xiv_use
parameter_list|,
name|ia64_ihtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sapic_bind_intr
parameter_list|(
name|u_int
parameter_list|,
name|struct
name|pcpu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sapic_config_intr
parameter_list|(
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
name|struct
name|sapic
modifier|*
name|sapic_create
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sapic_enable
parameter_list|(
name|struct
name|sapic
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sapic_eoi
parameter_list|(
name|struct
name|sapic
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sapic
modifier|*
name|sapic_lookup
parameter_list|(
name|u_int
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sapic_mask
parameter_list|(
name|struct
name|sapic
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sapic_unmask
parameter_list|(
name|struct
name|sapic
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|void
name|sapic_print
parameter_list|(
name|struct
name|sapic
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTR_H_ */
end_comment

end_unit

