begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* md5.h - Declaration of functions and data types used for MD5 sum    computing library functions.    Copyright 1995, 1996, 2000 Free Software Foundation, Inc.    NOTE: The canonical source of this file is maintained with the GNU C    Library.  Bugs can be reported to bug-glibc@prep.ai.mit.edu.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MD5_H
end_ifndef

begin_define
define|#
directive|define
name|_MD5_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
name|HAVE_LIMITS_H
operator|||
name|_LIBC
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following contortions are an attempt to use the C preprocessor    to determine an unsigned integral type that is 32 bits wide.  An    alternative approach is to use autoconf's AC_CHECK_SIZEOF macro, but    doing that would require that the configure script compile and *run*    the resulting executable.  Locally running cross-compiled executables    is usually not possible.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|u_int32_t
name|md5_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT_MAX_32_BITS
value|2147483647
end_define

begin_comment
comment|/* If UINT_MAX isn't defined, assume it's a 32-bit type.    This should be valid for all systems GNU cares about because    that doesn't include 16-bit systems, and only modern systems    (that certainly have<limits.h>) have 64+-bit integral types.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|INT_MAX_32_BITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|INT_MAX
operator|==
name|INT_MAX_32_BITS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|md5_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|SHRT_MAX
operator|==
name|INT_MAX_32_BITS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|md5_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONG_MAX
operator|==
name|INT_MAX_32_BITS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|md5_uint32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The following line is intended to evoke an error.         Using #error is not portable enough.  */
end_comment

begin_expr_stmt
literal|"Cannot determine unsigned 32-bit data type."
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
undef|#
directive|undef
name|__P
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
else|#
directive|else
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
endif|#
directive|endif
comment|/* Structure to save state of computation between the single steps.  */
expr|struct
name|md5_ctx
block|{
name|md5_uint32
name|A
block|;
name|md5_uint32
name|B
block|;
name|md5_uint32
name|C
block|;
name|md5_uint32
name|D
block|;
name|md5_uint32
name|total
index|[
literal|2
index|]
block|;
name|md5_uint32
name|buflen
block|;
name|char
name|buffer
index|[
literal|128
index|]
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The following three functions are build up the low level used in  * the functions `md5_stream' and `md5_buffer'.  */
end_comment

begin_comment
comment|/* Initialize structure containing state of computation.    (RFC 1321, 3.3: Step 3)  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|md5_init_ctx
name|__P
argument_list|(
operator|(
expr|struct
name|md5_ctx
operator|*
name|ctx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Starting with the result of former calls of this function (or the    initialization function update the context for the next LEN bytes    starting at BUFFER.    It is necessary that LEN is a multiple of 64!!! */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|md5_process_block
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|buffer
operator|,
name|size_t
name|len
operator|,
expr|struct
name|md5_ctx
operator|*
name|ctx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Starting with the result of former calls of this function (or the    initialization function update the context for the next LEN bytes    starting at BUFFER.    It is NOT required that LEN is a multiple of 64.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|md5_process_bytes
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|buffer
operator|,
name|size_t
name|len
operator|,
expr|struct
name|md5_ctx
operator|*
name|ctx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process the remaining bytes in the buffer and put result from CTX    in first 16 bytes following RESBUF.  The result is always in little    endian byte order, so that a byte-wise output yields to the wanted    ASCII representation of the message digest.     IMPORTANT: On some systems it is required that RESBUF is correctly    aligned for a 32 bits value.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|md5_finish_ctx
name|__P
argument_list|(
operator|(
expr|struct
name|md5_ctx
operator|*
name|ctx
operator|,
name|void
operator|*
name|resbuf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Put result from CTX in first 16 bytes following RESBUF.  The result is    always in little endian byte order, so that a byte-wise output yields    to the wanted ASCII representation of the message digest.     IMPORTANT: On some systems it is required that RESBUF is correctly    aligned for a 32 bits value.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|md5_read_ctx
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|md5_ctx
operator|*
name|ctx
operator|,
name|void
operator|*
name|resbuf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compute MD5 message digest for bytes read from STREAM.  The    resulting message digest number will be written into the 16 bytes    beginning at RESBLOCK.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|md5_stream
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|stream
operator|,
name|void
operator|*
name|resblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compute MD5 message digest for LEN bytes beginning at BUFFER.  The    result is always in little endian byte order, so that a byte-wise    output yields to the wanted ASCII representation of the message    digest.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|md5_buffer
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|buffer
operator|,
name|size_t
name|len
operator|,
name|void
operator|*
name|resblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

