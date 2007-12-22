begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IICBUS_H
end_ifndef

begin_define
define|#
directive|define
name|__IICBUS_H
end_define

begin_define
define|#
directive|define
name|IICBUS_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct iicbus_ivar *) device_get_ivars(d)
end_define

begin_define
define|#
directive|define
name|IICBUS_SOFTC
parameter_list|(
name|d
parameter_list|)
value|(struct iicbus_softc *) device_get_softc(d)
end_define

begin_struct
struct|struct
name|iicbus_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Myself */
name|device_t
name|owner
decl_stmt|;
comment|/* iicbus owner device structure */
name|u_char
name|started
decl_stmt|;
comment|/* address of the 'started' slave 				 * 0 if no start condition succeeded */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iicbus_ivar
block|{
name|uint32_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|IICBUS_IVAR_ADDR
comment|/* Address or base address */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IICBUS_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\
value|__inline static int							\ iicbus_get_ ## A(device_t dev, T *t)					\ {									\ 	return BUS_READ_IVAR(device_get_parent(dev), dev,		\ 	    IICBUS_IVAR_ ## B, (uintptr_t *) t);			\ }
end_define

begin_macro
name|IICBUS_ACCESSOR
argument_list|(
argument|addr
argument_list|,
argument|ADDR
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_function_decl
specifier|extern
name|int
name|iicbus_generic_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|event
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|driver_t
name|iicbus_driver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|iicbus_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

