begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Development sponsored by Microsemi, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Helper code to recover a hung i2c bus by bit-banging a recovery sequence.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IICBUS_IIC_RECOVER_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IICBUS_IIC_RECOVER_BUS_H_
end_define

begin_struct
struct|struct
name|iicrb_pin_access
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
name|int
function_decl|(
modifier|*
name|getsda
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setsda
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|getscl
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setscl
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Drive the bus-recovery logic by manipulating the line states using the  * caller-provided functions.  This does not block or sleep or acquire any locks  * (unless the provided pin access functions do so).  It uses DELAY() to pace  * bits on the bus.  *  * Returns 0 if the bus is functioning properly or IIC_EBUSERR if the recovery  * attempt failed and some slave device is still driving the bus.  */
end_comment

begin_function_decl
name|int
name|iic_recover_bus
parameter_list|(
name|struct
name|iicrb_pin_access
modifier|*
name|pins
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

