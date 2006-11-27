begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003, Trent Nelson,<trent@arpa.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONVTBL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONVTBL_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|BITS
value|(1)
end_define

begin_define
define|#
directive|define
name|BYTES
value|(1)
end_define

begin_define
define|#
directive|define
name|KILO
value|(1024)
end_define

begin_define
define|#
directive|define
name|MEGA
value|(KILO * 1024)
end_define

begin_define
define|#
directive|define
name|GIGA
value|(MEGA * 1024)
end_define

begin_enum
enum|enum
name|scale
block|{
name|SC_BYTE
block|,
name|SC_KILOBYTE
block|,
name|SC_MEGABYTE
block|,
name|SC_GIGABYTE
block|,
name|SC_BIT
block|,
name|SC_KILOBIT
block|,
name|SC_MEGABIT
block|,
name|SC_GIGABIT
block|,
name|SC_AUTO
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|BIT
value|(8)
end_define

begin_define
define|#
directive|define
name|BYTE
value|(1)
end_define

begin_struct
struct|struct
name|convtbl
block|{
name|u_int
name|mul
decl_stmt|;
name|u_int
name|scale
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|convtbl
name|convtbl
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|double
name|convert
parameter_list|(
specifier|const
name|u_long
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|get_string
parameter_list|(
specifier|const
name|u_long
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _CONVTBL_H_ */
end_comment

end_unit

