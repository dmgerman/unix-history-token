begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_BOOT_LIB_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_BOOT_LIB_H
end_define

begin_function_decl
name|int
name|getc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xputchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following function write eeprom at ee_addr using data 	*/
end_comment

begin_comment
comment|/*  from data_add for size bytes.				*/
end_comment

begin_function_decl
name|int
name|ReadEEPROM
parameter_list|(
name|unsigned
name|eeoff
parameter_list|,
name|char
modifier|*
name|data_addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WriteEEPROM
parameter_list|(
name|unsigned
name|eeoff
parameter_list|,
name|char
modifier|*
name|data_addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InitEEPROM
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XMODEM protocol */
end_comment

begin_function_decl
name|int
name|xmodem_rx
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  */
end_comment

begin_function_decl
name|void
name|start_wdog
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delay us */
end_comment

begin_function_decl
name|void
name|Delay
parameter_list|(
name|int
name|us
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ToASCII
parameter_list|(
name|x
parameter_list|)
value|((x> 9) ? (x + 'A' - 0xa) : (x + '0'))
end_define

begin_function_decl
name|int
name|p_IsWhiteSpace
parameter_list|(
name|char
name|cValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|p_HexCharValue
parameter_list|(
name|char
name|cValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|p_ASCIIToHex
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|p_ASCIIToDec
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p_memset
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|char
name|value
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memcpy
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_memcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

