begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008 by Nathan Whitehorn. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACIO_MACGPIOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACIO_MACGPIOVAR_H_
end_define

begin_comment
comment|/* relative offsets into gpio space */
end_comment

begin_define
define|#
directive|define
name|GPIO_EXTINT_BASE
value|0x08
end_define

begin_define
define|#
directive|define
name|GPIO_BASE
value|0x1a
end_define

begin_define
define|#
directive|define
name|GPIO_EXTINT_COUNT
value|0x12
end_define

begin_define
define|#
directive|define
name|GPIO_COUNT
value|0x11
end_define

begin_define
define|#
directive|define
name|GPIO_LEVELS_0
value|0x50
end_define

begin_define
define|#
directive|define
name|GPIO_LEVELS_1
value|0x54
end_define

begin_comment
comment|/* gpio bit definitions */
end_comment

begin_define
define|#
directive|define
name|GPIO_DATA
value|0x01
end_define

begin_comment
comment|/* GPIO data */
end_comment

begin_define
define|#
directive|define
name|GPIO_LEVEL_RO
value|0x02
end_define

begin_comment
comment|/* read-only level on pin */
end_comment

begin_define
define|#
directive|define
name|GPIO_DDR_INPUT
value|0x00
end_define

begin_comment
comment|/* use for input */
end_comment

begin_define
define|#
directive|define
name|GPIO_DDR_OUTPUT
value|0x04
end_define

begin_comment
comment|/* use for output */
end_comment

begin_function_decl
name|uint8_t
name|macgpio_read
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|macgpio_write
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACIO_MACGPIOVAR_H_ */
end_comment

end_unit

