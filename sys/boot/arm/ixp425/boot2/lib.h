begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_function_decl
name|int
name|main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DELAY
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xputchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|puthex8
parameter_list|(
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|puthexlist
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
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

begin_function_decl
name|void
name|bzero
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
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

begin_function_decl
name|int
name|p_strlen
parameter_list|(
specifier|const
name|char
modifier|*
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
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memchr
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
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
name|void
modifier|*
name|memmem
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
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

begin_define
define|#
directive|define
name|strlen
value|p_strlen
end_define

begin_define
define|#
directive|define
name|memcmp
value|p_memcmp
end_define

begin_define
define|#
directive|define
name|memset
value|p_memset
end_define

begin_function_decl
name|u_int16_t
name|swap16
parameter_list|(
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|swap32
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|board_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clr_board
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|avila_read
parameter_list|(
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpu_id
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
comment|/* !ARM_BOOT_LIB_H */
end_comment

end_unit

