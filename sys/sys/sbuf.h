begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2008 Poul-Henning Kamp  * Copyright (c) 2000-2008 Dag-Erling CoÃ¯dan SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SBUF_H_
end_define

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
name|sbuf_drain_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Structure definition  */
end_comment

begin_struct
struct|struct
name|sbuf
block|{
name|char
modifier|*
name|s_buf
decl_stmt|;
comment|/* storage buffer */
name|sbuf_drain_func
modifier|*
name|s_drain_func
decl_stmt|;
comment|/* drain function */
name|void
modifier|*
name|s_drain_arg
decl_stmt|;
comment|/* user-supplied drain argument */
name|int
name|s_error
decl_stmt|;
comment|/* current error code */
name|ssize_t
name|s_size
decl_stmt|;
comment|/* size of storage buffer */
name|ssize_t
name|s_len
decl_stmt|;
comment|/* current length of string */
define|#
directive|define
name|SBUF_FIXEDLEN
value|0x00000000
comment|/* fixed length buffer (default) */
define|#
directive|define
name|SBUF_AUTOEXTEND
value|0x00000001
comment|/* automatically extend buffer */
define|#
directive|define
name|SBUF_USRFLAGMSK
value|0x0000ffff
comment|/* mask of flags the user may specify */
define|#
directive|define
name|SBUF_DYNAMIC
value|0x00010000
comment|/* s_buf must be freed */
define|#
directive|define
name|SBUF_FINISHED
value|0x00020000
comment|/* set by sbuf_finish() */
define|#
directive|define
name|SBUF_DYNSTRUCT
value|0x00080000
comment|/* sbuf must be freed */
define|#
directive|define
name|SBUF_INSECTION
value|0x00100000
comment|/* set by sbuf_start_section() */
name|int
name|s_flags
decl_stmt|;
comment|/* flags */
name|ssize_t
name|s_sect_len
decl_stmt|;
comment|/* current length of section */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|HD_COLUMN_MASK
end_ifndef

begin_define
define|#
directive|define
name|HD_COLUMN_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|HD_DELIM_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|HD_OMIT_COUNT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|HD_OMIT_HEX
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|HD_OMIT_CHARS
value|(1<< 18)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HD_COLUMN_MASK */
end_comment

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * API functions  */
name|struct
name|sbuf
modifier|*
name|sbuf_new
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sbuf_new_auto
parameter_list|()
define|\
value|sbuf_new(NULL, NULL, 0, SBUF_AUTOEXTEND)
end_define

begin_function_decl
name|void
name|sbuf_clear
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_setpos
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|ssize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_bcat
parameter_list|(
name|struct
name|sbuf
modifier|*
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
name|int
name|sbuf_bcpy
parameter_list|(
name|struct
name|sbuf
modifier|*
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
name|int
name|sbuf_cat
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_cpy
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_printf
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|sbuf_vprintf
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|sbuf_putc
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_set_drain
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|sbuf_drain_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_trim
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_error
parameter_list|(
specifier|const
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_finish
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sbuf_data
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|sbuf_len
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_done
parameter_list|(
specifier|const
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_delete
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_start_section
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|ssize_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|sbuf_end_section
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|ssize_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_hexdump
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbuf_putbuf
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|sbuf
modifier|*
name|sbuf_uionew
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_bcopyin
parameter_list|(
name|struct
name|sbuf
modifier|*
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
name|int
name|sbuf_copyin
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

