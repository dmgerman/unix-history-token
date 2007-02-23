begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Layout of the Processor Interrupt Block.  */
end_comment

begin_struct
struct|struct
name|ia64_interrupt_block
block|{
name|u_int64_t
name|ib_ipi
index|[
literal|0x20000
index|]
decl_stmt|;
comment|/* 1Mb of IPI interrupts */
name|u_int8_t
name|ib_reserved1
index|[
literal|0xe0000
index|]
decl_stmt|;
name|u_int8_t
name|ib_inta
decl_stmt|;
comment|/* Generate INTA cycle */
name|u_int8_t
name|ib_reserved2
index|[
literal|7
index|]
decl_stmt|;
name|u_int8_t
name|ib_xtp
decl_stmt|;
comment|/* XTP cycle */
name|u_int8_t
name|ib_reserved3
index|[
literal|7
index|]
decl_stmt|;
name|u_int8_t
name|ib_reserved4
index|[
literal|0x1fff0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|u_int64_t
name|ia64_lapic_address
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IA64_INTERRUPT_BLOCK
define|\
value|(struct ia64_interrupt_block *)IA64_PHYS_TO_RR6(ia64_lapic_address)
end_define

begin_struct_decl
struct_decl|struct
name|sapic
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ia64_add_sapic
parameter_list|(
name|struct
name|sapic
modifier|*
name|sa
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
name|name
parameter_list|,
name|int
name|irq
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|,
specifier|volatile
name|long
modifier|*
name|cntp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ia64_teardown_intr
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia64_dispatch_intr
parameter_list|(
name|void
modifier|*
name|frame
parameter_list|,
name|unsigned
name|long
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTR_H_ */
end_comment

end_unit

