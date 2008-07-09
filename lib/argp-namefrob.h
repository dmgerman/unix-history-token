begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Name frobnication for compiling argp outside of glibc    Copyright (C) 1997, 2003 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|_LIBC
end_if

begin_comment
comment|/* This code is written for inclusion in gnu-libc, and uses names in the    namespace reserved for libc.  If we're not compiling in libc, define those    names to be the normal ones instead.  */
end_comment

begin_comment
comment|/* argp-parse functions */
end_comment

begin_undef
undef|#
directive|undef
name|__argp_parse
end_undef

begin_define
define|#
directive|define
name|__argp_parse
value|argp_parse
end_define

begin_undef
undef|#
directive|undef
name|__option_is_end
end_undef

begin_define
define|#
directive|define
name|__option_is_end
value|_option_is_end
end_define

begin_undef
undef|#
directive|undef
name|__option_is_short
end_undef

begin_define
define|#
directive|define
name|__option_is_short
value|_option_is_short
end_define

begin_undef
undef|#
directive|undef
name|__argp_input
end_undef

begin_define
define|#
directive|define
name|__argp_input
value|_argp_input
end_define

begin_comment
comment|/* argp-help functions */
end_comment

begin_undef
undef|#
directive|undef
name|__argp_help
end_undef

begin_define
define|#
directive|define
name|__argp_help
value|argp_help
end_define

begin_undef
undef|#
directive|undef
name|__argp_error
end_undef

begin_define
define|#
directive|define
name|__argp_error
value|argp_error
end_define

begin_undef
undef|#
directive|undef
name|__argp_failure
end_undef

begin_define
define|#
directive|define
name|__argp_failure
value|argp_failure
end_define

begin_undef
undef|#
directive|undef
name|__argp_state_help
end_undef

begin_define
define|#
directive|define
name|__argp_state_help
value|argp_state_help
end_define

begin_undef
undef|#
directive|undef
name|__argp_usage
end_undef

begin_define
define|#
directive|define
name|__argp_usage
value|argp_usage
end_define

begin_comment
comment|/* argp-fmtstream functions */
end_comment

begin_undef
undef|#
directive|undef
name|__argp_make_fmtstream
end_undef

begin_define
define|#
directive|define
name|__argp_make_fmtstream
value|argp_make_fmtstream
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_free
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_free
value|argp_fmtstream_free
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_putc
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_putc
value|argp_fmtstream_putc
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_puts
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_puts
value|argp_fmtstream_puts
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_write
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_write
value|argp_fmtstream_write
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_printf
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_printf
value|argp_fmtstream_printf
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_set_lmargin
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_set_lmargin
value|argp_fmtstream_set_lmargin
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_set_rmargin
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_set_rmargin
value|argp_fmtstream_set_rmargin
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_set_wmargin
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_set_wmargin
value|argp_fmtstream_set_wmargin
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_point
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_point
value|argp_fmtstream_point
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_update
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_update
value|_argp_fmtstream_update
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_ensure
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_ensure
value|_argp_fmtstream_ensure
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_lmargin
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_lmargin
value|argp_fmtstream_lmargin
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_rmargin
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_rmargin
value|argp_fmtstream_rmargin
end_define

begin_undef
undef|#
directive|undef
name|__argp_fmtstream_wmargin
end_undef

begin_define
define|#
directive|define
name|__argp_fmtstream_wmargin
value|argp_fmtstream_wmargin
end_define

begin_include
include|#
directive|include
file|"mempcpy.h"
end_include

begin_include
include|#
directive|include
file|"strcase.h"
end_include

begin_include
include|#
directive|include
file|"strchrnul.h"
end_include

begin_include
include|#
directive|include
file|"strndup.h"
end_include

begin_comment
comment|/* normal libc functions we call */
end_comment

begin_undef
undef|#
directive|undef
name|__flockfile
end_undef

begin_define
define|#
directive|define
name|__flockfile
value|flockfile
end_define

begin_undef
undef|#
directive|undef
name|__funlockfile
end_undef

begin_define
define|#
directive|define
name|__funlockfile
value|funlockfile
end_define

begin_undef
undef|#
directive|undef
name|__mempcpy
end_undef

begin_define
define|#
directive|define
name|__mempcpy
value|mempcpy
end_define

begin_undef
undef|#
directive|undef
name|__sleep
end_undef

begin_define
define|#
directive|define
name|__sleep
value|sleep
end_define

begin_undef
undef|#
directive|undef
name|__strcasecmp
end_undef

begin_define
define|#
directive|define
name|__strcasecmp
value|strcasecmp
end_define

begin_undef
undef|#
directive|undef
name|__strchrnul
end_undef

begin_define
define|#
directive|define
name|__strchrnul
value|strchrnul
end_define

begin_undef
undef|#
directive|undef
name|__strerror_r
end_undef

begin_define
define|#
directive|define
name|__strerror_r
value|strerror_r
end_define

begin_undef
undef|#
directive|undef
name|__strndup
end_undef

begin_define
define|#
directive|define
name|__strndup
value|strndup
end_define

begin_undef
undef|#
directive|undef
name|__vsnprintf
end_undef

begin_define
define|#
directive|define
name|__vsnprintf
value|vsnprintf
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_CLEARERR_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_CLEARERR_UNLOCKED
end_if

begin_define
define|#
directive|define
name|clearerr_unlocked
parameter_list|(
name|x
parameter_list|)
value|clearerr (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FEOF_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FEOF_UNLOCKED
end_if

begin_define
define|#
directive|define
name|feof_unlocked
parameter_list|(
name|x
parameter_list|)
value|feof (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FERROR_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FERROR_UNLOCKED
end_if

begin_define
define|#
directive|define
name|ferror_unlocked
parameter_list|(
name|x
parameter_list|)
value|ferror (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FFLUSH_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FFLUSH_UNLOCKED
end_if

begin_define
define|#
directive|define
name|fflush_unlocked
parameter_list|(
name|x
parameter_list|)
value|fflush (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FGETS_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FGETS_UNLOCKED
end_if

begin_define
define|#
directive|define
name|fgets_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fgets (x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FPUTC_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FPUTC_UNLOCKED
end_if

begin_define
define|#
directive|define
name|fputc_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fputc (x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FPUTS_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FPUTS_UNLOCKED
end_if

begin_define
define|#
directive|define
name|fputs_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fputs (x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FREAD_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FREAD_UNLOCKED
end_if

begin_define
define|#
directive|define
name|fread_unlocked
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fread (w,x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FWRITE_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FWRITE_UNLOCKED
end_if

begin_define
define|#
directive|define
name|fwrite_unlocked
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fwrite (w,x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_GETC_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETC_UNLOCKED
end_if

begin_define
define|#
directive|define
name|getc_unlocked
parameter_list|(
name|x
parameter_list|)
value|getc (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_GETCHAR_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETCHAR_UNLOCKED
end_if

begin_define
define|#
directive|define
name|getchar_unlocked
parameter_list|()
value|getchar ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_PUTC_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_PUTC_UNLOCKED
end_if

begin_define
define|#
directive|define
name|putc_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|putc (x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_PUTCHAR_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_PUTCHAR_UNLOCKED
end_if

begin_define
define|#
directive|define
name|putchar_unlocked
parameter_list|(
name|x
parameter_list|)
value|putchar (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|__argp_basename
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__set_errno
end_ifndef

begin_define
define|#
directive|define
name|__set_errno
parameter_list|(
name|e
parameter_list|)
value|(errno = (e))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME
end_if

begin_define
define|#
directive|define
name|__argp_short_program_name
parameter_list|()
value|(program_invocation_short_name)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|__argp_short_program_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

