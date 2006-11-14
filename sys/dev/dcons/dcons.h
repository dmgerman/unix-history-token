begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002-2004  * 	Hidetoshi Shimokawa. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  *	This product includes software developed by Hidetoshi Shimokawa.  *  * 4. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $Id: dcons.h,v 1.15 2003/10/23 15:05:31 simokawa Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_BOOT
argument_list|)
end_if

begin_define
define|#
directive|define
name|V
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|V
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DCONS_NPORT
value|2
end_define

begin_define
define|#
directive|define
name|DCONS_CON
value|0
end_define

begin_define
define|#
directive|define
name|DCONS_GDB
value|1
end_define

begin_struct
struct|struct
name|dcons_buf
block|{
define|#
directive|define
name|DCONS_VERSION
value|2
name|V
name|u_int32_t
name|version
decl_stmt|;
name|V
name|u_int32_t
name|ooffset
index|[
name|DCONS_NPORT
index|]
decl_stmt|;
name|V
name|u_int32_t
name|ioffset
index|[
name|DCONS_NPORT
index|]
decl_stmt|;
name|V
name|u_int32_t
name|osize
index|[
name|DCONS_NPORT
index|]
decl_stmt|;
name|V
name|u_int32_t
name|isize
index|[
name|DCONS_NPORT
index|]
decl_stmt|;
define|#
directive|define
name|DCONS_MAGIC
value|0x64636f6e
comment|/* "dcon" */
name|V
name|u_int32_t
name|magic
decl_stmt|;
define|#
directive|define
name|DCONS_GEN_SHIFT
value|(24)
define|#
directive|define
name|DCONS_GEN_MASK
value|(0xff)
define|#
directive|define
name|DCONS_POS_MASK
value|((1<< DCONS_GEN_SHIFT) - 1)
name|V
name|u_int32_t
name|optr
index|[
name|DCONS_NPORT
index|]
decl_stmt|;
name|V
name|u_int32_t
name|iptr
index|[
name|DCONS_NPORT
index|]
decl_stmt|;
name|V
name|char
name|buf
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DCONS_CSR_VAL_VER
value|0x64636f
end_define

begin_comment
comment|/* "dco" */
end_comment

begin_define
define|#
directive|define
name|DCONS_CSR_KEY_HI
value|0x3a
end_define

begin_define
define|#
directive|define
name|DCONS_CSR_KEY_LO
value|0x3b
end_define

begin_define
define|#
directive|define
name|DCONS_HEADER_SIZE
value|sizeof(struct dcons_buf)
end_define

begin_define
define|#
directive|define
name|DCONS_MAKE_PTR
parameter_list|(
name|x
parameter_list|)
value|htonl(((x)->gen<< DCONS_GEN_SHIFT) | (x)->pos)
end_define

begin_define
define|#
directive|define
name|DCONS_NEXT_GEN
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)& DCONS_GEN_MASK)
end_define

begin_struct
struct|struct
name|dcons_ch
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_int32_t
name|gen
decl_stmt|;
name|u_int32_t
name|pos
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_BOOT
argument_list|)
name|V
name|u_int32_t
modifier|*
name|ptr
decl_stmt|;
name|V
name|char
modifier|*
name|buf
decl_stmt|;
else|#
directive|else
name|off_t
name|buf
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KEY_CTRLB
value|2
end_define

begin_comment
comment|/* ^B */
end_comment

begin_define
define|#
directive|define
name|KEY_CR
value|13
end_define

begin_comment
comment|/* CR '\r' */
end_comment

begin_define
define|#
directive|define
name|KEY_TILDE
value|126
end_define

begin_comment
comment|/* ~ */
end_comment

begin_define
define|#
directive|define
name|STATE0
value|0
end_define

begin_define
define|#
directive|define
name|STATE1
value|1
end_define

begin_define
define|#
directive|define
name|STATE2
value|2
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_BOOT
argument_list|)
end_if

begin_struct
struct|struct
name|dcons_softc
block|{
name|struct
name|dcons_ch
name|o
decl_stmt|,
name|i
decl_stmt|;
name|int
name|brk_state
decl_stmt|;
define|#
directive|define
name|DC_GDB
value|1
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|dcons_checkc
parameter_list|(
name|struct
name|dcons_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dcons_ischar
parameter_list|(
name|struct
name|dcons_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dcons_putc
parameter_list|(
name|struct
name|dcons_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dcons_load_buffer
parameter_list|(
name|struct
name|dcons_buf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|dcons_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dcons_init
parameter_list|(
name|struct
name|dcons_buf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|dcons_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

