begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_EXTRES_REGULATOR_FIXED_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_EXTRES_REGULATOR_FIXED_H_
end_define

begin_include
include|#
directive|include
file|<dev/gpio/gpiobusvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/regulator/regulator.h>
end_include

begin_struct
struct|struct
name|regnode_fixed_init_def
block|{
name|struct
name|regnode_init_def
name|reg_init_def
decl_stmt|;
name|bool
name|gpio_open_drain
decl_stmt|;
name|struct
name|gpiobus_pin
modifier|*
name|gpio_pin
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|regnode_fixed_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|regnode_fixed_init_def
modifier|*
name|init_def
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_DEV_EXTRES_REGULATOR_FIXED_H_*/
end_comment

end_unit

