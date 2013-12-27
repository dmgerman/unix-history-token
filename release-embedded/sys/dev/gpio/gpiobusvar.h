begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Oleksandr Tymoshenko<gonzo@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GPIOBUS_H__
end_ifndef

begin_define
define|#
directive|define
name|__GPIOBUS_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_define
define|#
directive|define
name|GPIOBUS_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct gpiobus_ivar *) device_get_ivars(d)
end_define

begin_define
define|#
directive|define
name|GPIOBUS_SOFTC
parameter_list|(
name|d
parameter_list|)
value|(struct gpiobus_softc *) device_get_softc(d)
end_define

begin_struct
struct|struct
name|gpiobus_softc
block|{
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* bus mutex */
name|device_t
name|sc_busdev
decl_stmt|;
comment|/* bus device */
name|device_t
name|sc_owner
decl_stmt|;
comment|/* bus owner */
name|device_t
name|sc_dev
decl_stmt|;
comment|/* driver device */
name|int
name|sc_npins
decl_stmt|;
comment|/* total pins on bus */
name|int
modifier|*
name|sc_pins_mapped
decl_stmt|;
comment|/* mark mapped pins */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gpiobus_ivar
block|{
name|uint32_t
name|npins
decl_stmt|;
comment|/* pins total */
name|uint32_t
modifier|*
name|pins
decl_stmt|;
comment|/* pins map */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GPIOBUS_H__ */
end_comment

end_unit

