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

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

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
name|u_int
name|owncount
decl_stmt|;
comment|/* iicbus ownership nesting count */
name|u_char
name|started
decl_stmt|;
comment|/* address of the 'started' slave 				 * 0 if no start condition succeeded */
name|u_char
name|strict
decl_stmt|;
comment|/* deny operations that violate the 				 * I2C protocol */
name|struct
name|mtx
name|lock
decl_stmt|;
name|u_int
name|bus_freq
decl_stmt|;
comment|/* Configured bus Hz. */
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
name|struct
name|resource_list
name|rl
decl_stmt|;
name|bool
name|nostop
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|IICBUS_IVAR_ADDR
block|,
comment|/* Address or base address */
name|IICBUS_IVAR_NOSTOP
block|,
comment|/* nostop defaults */
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
value|__BUS_ACCESSOR(iicbus, A, IICBUS, B, T)
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

begin_macro
name|IICBUS_ACCESSOR
argument_list|(
argument|nostop
argument_list|,
argument|NOSTOP
argument_list|,
argument|bool
argument_list|)
end_macro

begin_define
define|#
directive|define
name|IICBUS_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->lock)
end_define

begin_define
define|#
directive|define
name|IICBUS_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->lock)
end_define

begin_define
define|#
directive|define
name|IICBUS_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->lock, MA_OWNED)
end_define

begin_function_decl
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

begin_function_decl
name|void
name|iicbus_init_frequency
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|bus_freq
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

