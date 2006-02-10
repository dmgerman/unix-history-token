begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Rink Springer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_XBOX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_XBOX_H_
end_define

begin_define
define|#
directive|define
name|XBOX_LED_GREEN
value|0x0f
end_define

begin_define
define|#
directive|define
name|XBOX_LED_RED
value|0xf0
end_define

begin_define
define|#
directive|define
name|XBOX_LED_FLASHRED
value|0xa0
end_define

begin_define
define|#
directive|define
name|XBOX_LED_FLASHGREEN
value|0x03
end_define

begin_define
define|#
directive|define
name|XBOX_RAM_SIZE
value|(arch_i386_xbox_memsize * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|XBOX_FB_SIZE
value|(0x400000)
end_define

begin_define
define|#
directive|define
name|XBOX_FB_START
value|(0xf0000000 | (XBOX_RAM_SIZE - XBOX_FB_SIZE))
end_define

begin_define
define|#
directive|define
name|XBOX_FB_START_PTR
value|(0xFD600800)
end_define

begin_decl_stmt
specifier|extern
name|int
name|arch_i386_is_xbox
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|arch_i386_xbox_memsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Megabytes */
end_comment

begin_function_decl
name|void
name|pic16l_setbyte
parameter_list|(
name|int
name|addr
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pic16l_setled
parameter_list|(
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pic16l_reboot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pic16l_poweroff
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_XBOX_H_ */
end_comment

end_unit

