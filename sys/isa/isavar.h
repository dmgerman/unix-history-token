begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ISA_NPORT_IVARS
value|2
end_define

begin_define
define|#
directive|define
name|ISA_NMEM_IVARS
value|2
end_define

begin_define
define|#
directive|define
name|ISA_NIRQ_IVARS
value|2
end_define

begin_define
define|#
directive|define
name|ISA_NDRQ_IVARS
value|2
end_define

begin_enum
enum|enum
name|isa_device_ivars
block|{
name|ISA_IVAR_PORT
block|,
name|ISA_IVAR_PORT_0
init|=
name|ISA_IVAR_PORT
block|,
name|ISA_IVAR_PORT_1
block|,
name|ISA_IVAR_PORTSIZE
block|,
name|ISA_IVAR_PORTSIZE_0
init|=
name|ISA_IVAR_PORTSIZE
block|,
name|ISA_IVAR_PORTSIZE_1
block|,
name|ISA_IVAR_MADDR
block|,
name|ISA_IVAR_MADDR_0
init|=
name|ISA_IVAR_MADDR
block|,
name|ISA_IVAR_MADDR_1
block|,
name|ISA_IVAR_MSIZE
block|,
name|ISA_IVAR_MSIZE_0
init|=
name|ISA_IVAR_MSIZE
block|,
name|ISA_IVAR_MSIZE_1
block|,
name|ISA_IVAR_FLAGS
block|,
name|ISA_IVAR_IRQ
block|,
name|ISA_IVAR_IRQ_0
init|=
name|ISA_IVAR_IRQ
block|,
name|ISA_IVAR_IRQ_1
block|,
name|ISA_IVAR_DRQ
block|,
name|ISA_IVAR_DRQ_0
init|=
name|ISA_IVAR_DRQ
block|,
name|ISA_IVAR_DRQ_1
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|int
name|isa_irq_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isa_irq_mask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Simplified accessors for isa devices  */
end_comment

begin_define
define|#
directive|define
name|ISA_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									\
value|static __inline T isa_get_ ## A(device_t dev)				\ {									\ 	u_long v;							\ 	BUS_READ_IVAR(device_get_parent(dev), dev, ISA_IVAR_ ## B,&v);	\ 	return (T) v;							\ }									\ 									\ static __inline void isa_set_ ## A(device_t dev, T t)			\ {									\ 	u_long v = (u_long) t;						\ 	BUS_WRITE_IVAR(device_get_parent(dev), dev, ISA_IVAR_ ## B, v);	\ }
end_define

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|port
argument_list|,
argument|PORT
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|portsize
argument_list|,
argument|PORTSIZE
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|flags
argument_list|,
argument|FLAGS
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|ISA_ACCESSOR
argument_list|(
argument|irq
argument_list|,
argument|IRQ
argument_list|,
argument|int
argument_list|)
end_macro

end_unit

