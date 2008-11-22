begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Word-wrapping and line-truncating streams.    Copyright (C) 1997 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This package emulates glibc `line_wrap_stream' semantics for systems that    don't have that.  If the system does have it, it is just a wrapper for    that.  This header file is only used internally while compiling argp, and    shouldn't be installed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARGP_FMTSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|_ARGP_FMTSTREAM_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_comment
comment|/* This feature is available in gcc versions 2.5 and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The __-protected variants of `format' and `printf' attributes    are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__format__
value|format
end_define

begin_define
define|#
directive|define
name|__printf__
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|_LIBC
operator|-
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|USE_IN_LIBIO
argument_list|)
operator|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LINEWRAP_H
argument_list|)
operator|)
end_if

begin_comment
comment|/* line_wrap_stream is available, so use that.  */
end_comment

begin_define
define|#
directive|define
name|ARGP_FMTSTREAM_USE_LINEWRAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARGP_FMTSTREAM_USE_LINEWRAP
end_ifdef

begin_comment
comment|/* Just be a simple wrapper for line_wrap_stream; the semantics are    *slightly* different, as line_wrap_stream doesn't actually make a new    object, it just modifies the given stream (reversibly) to do    line-wrapping.  Since we control who uses this code, it doesn't matter.  */
end_comment

begin_include
include|#
directive|include
file|<linewrap.h>
end_include

begin_typedef
typedef|typedef
name|FILE
modifier|*
name|argp_fmtstream_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|argp_make_fmtstream
value|line_wrap_stream
end_define

begin_define
define|#
directive|define
name|__argp_make_fmtstream
value|line_wrap_stream
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_free
value|line_unwrap_stream
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_free
value|line_unwrap_stream
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_putc
parameter_list|(
name|fs
parameter_list|,
name|ch
parameter_list|)
value|putc(ch,fs)
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_putc
parameter_list|(
name|fs
parameter_list|,
name|ch
parameter_list|)
value|putc(ch,fs)
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_puts
parameter_list|(
name|fs
parameter_list|,
name|str
parameter_list|)
value|fputs(str,fs)
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_puts
parameter_list|(
name|fs
parameter_list|,
name|str
parameter_list|)
value|fputs(str,fs)
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_write
parameter_list|(
name|fs
parameter_list|,
name|str
parameter_list|,
name|len
parameter_list|)
value|fwrite(str,1,len,fs)
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_write
parameter_list|(
name|fs
parameter_list|,
name|str
parameter_list|,
name|len
parameter_list|)
value|fwrite(str,1,len,fs)
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_printf
value|fprintf
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_printf
value|fprintf
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_lmargin
value|line_wrap_lmargin
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_lmargin
value|line_wrap_lmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_set_lmargin
value|line_wrap_set_lmargin
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_set_lmargin
value|line_wrap_set_lmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_rmargin
value|line_wrap_rmargin
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_rmargin
value|line_wrap_rmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_set_rmargin
value|line_wrap_set_rmargin
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_set_rmargin
value|line_wrap_set_rmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_wmargin
value|line_wrap_wmargin
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_wmargin
value|line_wrap_wmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_set_wmargin
value|line_wrap_set_wmargin
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_set_wmargin
value|line_wrap_set_wmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_point
value|line_wrap_point
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_point
value|line_wrap_point
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ARGP_FMTSTREAM_USE_LINEWRAP */
end_comment

begin_comment
comment|/* Guess we have to define our own version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__const
end_ifndef

begin_define
define|#
directive|define
name|__const
value|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_struct
struct|struct
name|argp_fmtstream
block|{
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/* The stream we're outputting to.  */
name|size_t
name|lmargin
decl_stmt|,
name|rmargin
decl_stmt|;
comment|/* Left and right margins.  */
name|ssize_t
name|wmargin
decl_stmt|;
comment|/* Margin to wrap to, or -1 to truncate.  */
comment|/* Point in buffer to which we've processed for wrapping, but not output.  */
name|size_t
name|point_offs
decl_stmt|;
comment|/* Output column at POINT_OFFS, or -1 meaning 0 but don't add lmargin.  */
name|ssize_t
name|point_col
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* Output buffer.  */
name|char
modifier|*
name|p
decl_stmt|;
comment|/* Current end of text in BUF. */
name|char
modifier|*
name|end
decl_stmt|;
comment|/* Absolute end of BUF.  */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|argp_fmtstream
modifier|*
name|argp_fmtstream_t
typedef|;
end_typedef

begin_comment
comment|/* Return an argp_fmtstream that outputs to STREAM, and which prefixes lines    written on it with LMARGIN spaces and limits them to RMARGIN columns    total.  If WMARGIN>= 0, words that extend past RMARGIN are wrapped by    replacing the whitespace before them with a newline and WMARGIN spaces.    Otherwise, chars beyond RMARGIN are simply dropped until a newline.    Returns NULL if there was an error.  */
end_comment

begin_function_decl
specifier|extern
name|argp_fmtstream_t
name|__argp_make_fmtstream
parameter_list|(
name|FILE
modifier|*
name|__stream
parameter_list|,
name|size_t
name|__lmargin
parameter_list|,
name|size_t
name|__rmargin
parameter_list|,
name|ssize_t
name|__wmargin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|argp_fmtstream_t
name|argp_make_fmtstream
parameter_list|(
name|FILE
modifier|*
name|__stream
parameter_list|,
name|size_t
name|__lmargin
parameter_list|,
name|size_t
name|__rmargin
parameter_list|,
name|ssize_t
name|__wmargin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flush __FS to its stream, and free it (but don't close the stream).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__argp_fmtstream_free
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|argp_fmtstream_free
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|__argp_fmtstream_printf
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|ssize_t
name|argp_fmtstream_printf
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|__argp_fmtstream_putc
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|int
name|__ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|argp_fmtstream_putc
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|int
name|__ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__argp_fmtstream_puts
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|argp_fmtstream_puts
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__argp_fmtstream_write
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__str
parameter_list|,
name|size_t
name|__len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|argp_fmtstream_write
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__str
parameter_list|,
name|size_t
name|__len
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Access macros for various bits of state.  */
end_comment

begin_define
define|#
directive|define
name|argp_fmtstream_lmargin
parameter_list|(
name|__fs
parameter_list|)
value|((__fs)->lmargin)
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_rmargin
parameter_list|(
name|__fs
parameter_list|)
value|((__fs)->rmargin)
end_define

begin_define
define|#
directive|define
name|argp_fmtstream_wmargin
parameter_list|(
name|__fs
parameter_list|)
value|((__fs)->wmargin)
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_lmargin
value|argp_fmtstream_lmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_rmargin
value|argp_fmtstream_rmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_wmargin
value|argp_fmtstream_wmargin
end_define

begin_comment
comment|/* Set __FS's left margin to LMARGIN and return the old value.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|argp_fmtstream_set_lmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__lmargin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__argp_fmtstream_set_lmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__lmargin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set __FS's right margin to __RMARGIN and return the old value.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|argp_fmtstream_set_rmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__rmargin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__argp_fmtstream_set_rmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__rmargin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set __FS's wrap margin to __WMARGIN and return the old value.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|argp_fmtstream_set_wmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__wmargin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__argp_fmtstream_set_wmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__wmargin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the column number of the current output point in __FS.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|argp_fmtstream_point
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__argp_fmtstream_point
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Internal routines.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_argp_fmtstream_update
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__argp_fmtstream_update
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_argp_fmtstream_ensure
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__argp_fmtstream_ensure
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__amount
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_comment
comment|/* Inline versions of above routines.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|_LIBC
end_if

begin_define
define|#
directive|define
name|__argp_fmtstream_putc
value|argp_fmtstream_putc
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_puts
value|argp_fmtstream_puts
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_write
value|argp_fmtstream_write
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_set_lmargin
value|argp_fmtstream_set_lmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_set_rmargin
value|argp_fmtstream_set_rmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_set_wmargin
value|argp_fmtstream_set_wmargin
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_point
value|argp_fmtstream_point
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_update
value|_argp_fmtstream_update
end_define

begin_define
define|#
directive|define
name|__argp_fmtstream_ensure
value|_argp_fmtstream_ensure
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARGP_FS_EI
end_ifndef

begin_define
define|#
directive|define
name|ARGP_FS_EI
value|extern inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|ARGP_FS_EI
name|size_t
name|__argp_fmtstream_write
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__str
parameter_list|,
name|size_t
name|__len
parameter_list|)
block|{
if|if
condition|(
name|__fs
operator|->
name|p
operator|+
name|__len
operator|<=
name|__fs
operator|->
name|end
operator|||
name|__argp_fmtstream_ensure
argument_list|(
name|__fs
argument_list|,
name|__len
argument_list|)
condition|)
block|{
name|memcpy
argument_list|(
name|__fs
operator|->
name|p
argument_list|,
name|__str
argument_list|,
name|__len
argument_list|)
expr_stmt|;
name|__fs
operator|->
name|p
operator|+=
name|__len
expr_stmt|;
return|return
name|__len
return|;
block|}
else|else
return|return
literal|0
return|;
block|}
end_function

begin_function
name|ARGP_FS_EI
name|int
name|__argp_fmtstream_puts
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|__const
name|char
modifier|*
name|__str
parameter_list|)
block|{
name|size_t
name|__len
init|=
name|strlen
argument_list|(
name|__str
argument_list|)
decl_stmt|;
if|if
condition|(
name|__len
condition|)
block|{
name|size_t
name|__wrote
init|=
name|__argp_fmtstream_write
argument_list|(
name|__fs
argument_list|,
name|__str
argument_list|,
name|__len
argument_list|)
decl_stmt|;
return|return
name|__wrote
operator|==
name|__len
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
else|else
return|return
literal|0
return|;
block|}
end_function

begin_function
name|ARGP_FS_EI
name|int
name|__argp_fmtstream_putc
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|int
name|__ch
parameter_list|)
block|{
if|if
condition|(
name|__fs
operator|->
name|p
operator|<
name|__fs
operator|->
name|end
operator|||
name|__argp_fmtstream_ensure
argument_list|(
name|__fs
argument_list|,
literal|1
argument_list|)
condition|)
return|return
operator|*
name|__fs
operator|->
name|p
operator|++
operator|=
name|__ch
return|;
else|else
return|return
name|EOF
return|;
block|}
end_function

begin_comment
comment|/* Set __FS's left margin to __LMARGIN and return the old value.  */
end_comment

begin_function
name|ARGP_FS_EI
name|size_t
name|__argp_fmtstream_set_lmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__lmargin
parameter_list|)
block|{
name|size_t
name|__old
decl_stmt|;
if|if
condition|(
call|(
name|size_t
call|)
argument_list|(
name|__fs
operator|->
name|p
operator|-
name|__fs
operator|->
name|buf
argument_list|)
operator|>
name|__fs
operator|->
name|point_offs
condition|)
name|__argp_fmtstream_update
argument_list|(
name|__fs
argument_list|)
expr_stmt|;
name|__old
operator|=
name|__fs
operator|->
name|lmargin
expr_stmt|;
name|__fs
operator|->
name|lmargin
operator|=
name|__lmargin
expr_stmt|;
return|return
name|__old
return|;
block|}
end_function

begin_comment
comment|/* Set __FS's right margin to __RMARGIN and return the old value.  */
end_comment

begin_function
name|ARGP_FS_EI
name|size_t
name|__argp_fmtstream_set_rmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__rmargin
parameter_list|)
block|{
name|size_t
name|__old
decl_stmt|;
if|if
condition|(
call|(
name|size_t
call|)
argument_list|(
name|__fs
operator|->
name|p
operator|-
name|__fs
operator|->
name|buf
argument_list|)
operator|>
name|__fs
operator|->
name|point_offs
condition|)
name|__argp_fmtstream_update
argument_list|(
name|__fs
argument_list|)
expr_stmt|;
name|__old
operator|=
name|__fs
operator|->
name|rmargin
expr_stmt|;
name|__fs
operator|->
name|rmargin
operator|=
name|__rmargin
expr_stmt|;
return|return
name|__old
return|;
block|}
end_function

begin_comment
comment|/* Set FS's wrap margin to __WMARGIN and return the old value.  */
end_comment

begin_function
name|ARGP_FS_EI
name|size_t
name|__argp_fmtstream_set_wmargin
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|,
name|size_t
name|__wmargin
parameter_list|)
block|{
name|size_t
name|__old
decl_stmt|;
if|if
condition|(
call|(
name|size_t
call|)
argument_list|(
name|__fs
operator|->
name|p
operator|-
name|__fs
operator|->
name|buf
argument_list|)
operator|>
name|__fs
operator|->
name|point_offs
condition|)
name|__argp_fmtstream_update
argument_list|(
name|__fs
argument_list|)
expr_stmt|;
name|__old
operator|=
name|__fs
operator|->
name|wmargin
expr_stmt|;
name|__fs
operator|->
name|wmargin
operator|=
name|__wmargin
expr_stmt|;
return|return
name|__old
return|;
block|}
end_function

begin_comment
comment|/* Return the column number of the current output point in __FS.  */
end_comment

begin_function
name|ARGP_FS_EI
name|size_t
name|__argp_fmtstream_point
parameter_list|(
name|argp_fmtstream_t
name|__fs
parameter_list|)
block|{
if|if
condition|(
call|(
name|size_t
call|)
argument_list|(
name|__fs
operator|->
name|p
operator|-
name|__fs
operator|->
name|buf
argument_list|)
operator|>
name|__fs
operator|->
name|point_offs
condition|)
name|__argp_fmtstream_update
argument_list|(
name|__fs
argument_list|)
expr_stmt|;
return|return
name|__fs
operator|->
name|point_col
operator|>=
literal|0
condition|?
name|__fs
operator|->
name|point_col
else|:
literal|0
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|_LIBC
end_if

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_putc
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_puts
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_write
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_set_lmargin
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_set_rmargin
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_set_wmargin
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_point
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_update
end_undef

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_ensure
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OPTIMIZE__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGP_FMTSTREAM_USE_LINEWRAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* argp-fmtstream.h */
end_comment

end_unit

