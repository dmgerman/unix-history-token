begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Poul-Henning Kamp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PRINTF_H_
end_ifndef

begin_define
define|#
directive|define
name|_PRINTF_H_
end_define

begin_comment
comment|/*  * The API defined by glibc allows a renderer to take multiple arguments  * This is obviously usable for things like (ptr+len) pairs etc.  * But the do not actually provide support for it at the end of the day,  * they offer only one argument to the arginfo function, but do accept  *>1 returns, although the do not check the types of those arguments  * argument  * Be compatible for now.  */
end_comment

begin_define
define|#
directive|define
name|__PRINTFMAXARG
value|2
end_define

begin_struct
struct|struct
name|printf_info
block|{
comment|/* GLIBC compatible */
name|int
name|prec
decl_stmt|;
name|int
name|width
decl_stmt|;
name|wchar_t
name|spec
decl_stmt|;
name|unsigned
name|is_long_double
decl_stmt|;
name|unsigned
name|is_char
decl_stmt|;
name|unsigned
name|is_short
decl_stmt|;
name|unsigned
name|is_long
decl_stmt|;
name|unsigned
name|alt
decl_stmt|;
name|unsigned
name|space
decl_stmt|;
name|unsigned
name|left
decl_stmt|;
name|unsigned
name|showsign
decl_stmt|;
name|unsigned
name|group
decl_stmt|;
name|unsigned
name|extra
decl_stmt|;
name|unsigned
name|wide
decl_stmt|;
name|wchar_t
name|pad
decl_stmt|;
comment|/* FreeBSD extensions */
name|unsigned
name|is_quad
decl_stmt|;
name|unsigned
name|is_intmax
decl_stmt|;
name|unsigned
name|is_ptrdiff
decl_stmt|;
name|unsigned
name|is_size
decl_stmt|;
comment|/* private */
name|int
name|sofar
decl_stmt|;
name|unsigned
name|get_width
decl_stmt|;
name|unsigned
name|get_prec
decl_stmt|;
specifier|const
name|char
modifier|*
name|begin
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
decl_stmt|;
name|void
modifier|*
name|arg
index|[
name|__PRINTFMAXARG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|PA_INT
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/* int */
name|PA_CHAR
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/* int, cast to char */
name|PA_WCHAR
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/* wide char */
name|PA_STRING
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/* const char * (with '\0') */
name|PA_WSTRING
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
comment|/* const wchar_t * */
name|PA_POINTER
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
comment|/* void * */
name|PA_FLOAT
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|/* float */
name|PA_DOUBLE
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
comment|/* double */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PA_FLAG_MASK
value|0xff0000
end_define

begin_define
define|#
directive|define
name|PA_FLAG_LONG_LONG
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_LONG
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_SHORT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_PTR
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_QUAD
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_INTMAX
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_SIZE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_PTRDIFF
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PA_FLAG_LONG_DOUBLE
value|PA_FLAG_LONG_LONG
end_define

begin_typedef
typedef|typedef
name|int
name|printf_arginfo_function
parameter_list|(
specifier|const
name|struct
name|printf_info
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|printf_function
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|struct
name|printf_info
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* FreeBSD extension */
end_comment

begin_struct_decl
struct_decl|struct
name|__printf_io
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|printf_render
parameter_list|(
name|struct
name|__printf_io
modifier|*
parameter_list|,
specifier|const
name|struct
name|printf_info
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* vprintf.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|__lowercase_hex
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|__uppercase_hex
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__printf_flush
parameter_list|(
name|struct
name|__printf_io
modifier|*
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__printf_puts
parameter_list|(
name|struct
name|__printf_io
modifier|*
name|io
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__printf_pad
parameter_list|(
name|struct
name|__printf_io
modifier|*
name|io
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__printf_out
parameter_list|(
name|struct
name|__printf_io
modifier|*
name|io
parameter_list|,
specifier|const
name|struct
name|printf_info
modifier|*
name|pi
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__xvprintf
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt0
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|__use_xprintf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GLIBC compat */
end_comment

begin_function_decl
name|int
name|register_printf_function
parameter_list|(
name|int
name|spec
parameter_list|,
name|printf_function
modifier|*
name|render
parameter_list|,
name|printf_arginfo_function
modifier|*
name|arginfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FreeBSD */
end_comment

begin_function_decl
name|int
name|register_printf_render
parameter_list|(
name|int
name|spec
parameter_list|,
name|printf_render
modifier|*
name|render
parameter_list|,
name|printf_arginfo_function
modifier|*
name|arginfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_printf_render_std
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|specs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vprintf_errno.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_float.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_float
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_hexdump.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_hexdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_hexdump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_int.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_int
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_quoute.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_quote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_quote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_str.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_chr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_chr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_str
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_time.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vprintf_vis.c */
end_comment

begin_decl_stmt
name|printf_arginfo_function
name|__printf_arginfo_vis
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|printf_render
name|__printf_render_vis
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PRINTF_H */
end_comment

end_unit

