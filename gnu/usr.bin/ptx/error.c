begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* error.c -- error handler for noninteractive utilities    Copyright (C) 1990, 1991, 1992, 1993 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONFIG_BROKETS
argument_list|)
end_if

begin_comment
comment|/* We use<config.h> instead of "config.h" so that a compilation    using -I. -I$srcdir will use ./config.h rather than $srcdir/config.h    (which it would do because it found this file in $srcdir).  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_VPRINTF
end_ifdef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|args
parameter_list|,
name|lastarg
parameter_list|)
value|va_start(args, lastarg)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__STDC__ */
end_comment

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|args
parameter_list|,
name|lastarg
parameter_list|)
value|va_start(args)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_VPRINTF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DOPRNT
end_ifdef

begin_define
define|#
directive|define
name|va_alist
value|args
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int args;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_DOPRNT */
end_comment

begin_define
define|#
directive|define
name|va_alist
value|a1, a2, a3, a4, a5, a6, a7, a8
end_define

begin_define
define|#
directive|define
name|va_dcl
value|char *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_DOPRNT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_VPRINTF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !STDC_HEADERS */
end_comment

begin_function_decl
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !STDC_HEADERS */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_function
specifier|static
name|char
modifier|*
name|private_strerror
parameter_list|(
name|errnum
parameter_list|)
name|int
name|errnum
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
if|if
condition|(
name|errnum
operator|>
literal|0
operator|&&
name|errnum
operator|<=
name|sys_nerr
condition|)
return|return
name|sys_errlist
index|[
name|errnum
index|]
return|;
return|return
literal|"Unknown system error"
return|;
block|}
end_function

begin_define
define|#
directive|define
name|strerror
value|private_strerror
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRERROR */
end_comment

begin_comment
comment|/* Print the program name and error message MESSAGE, which is a printf-style    format string with optional args.    If ERRNUM is nonzero, print its corresponding system error message.    Exit with status STATUS if it is nonzero.  */
end_comment

begin_comment
comment|/* VARARGS */
end_comment

begin_decl_stmt
name|void
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VPRINTF
argument_list|)
operator|&&
name|__STDC__
name|error
argument_list|(
name|int
name|status
argument_list|,
name|int
name|errnum
argument_list|,
name|char
operator|*
name|message
argument_list|,
operator|...
argument_list|)
else|#
directive|else
comment|/* !HAVE_VPRINTF or !__STDC__ */
name|error
argument_list|(
name|status
argument_list|,
name|errnum
argument_list|,
name|message
argument_list|,
name|va_alist
argument_list|)
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|message
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_VPRINTF or !__STDC__ */
end_comment

begin_block
block|{
ifdef|#
directive|ifdef
name|HAVE_VPRINTF
name|va_list
name|args
decl_stmt|;
endif|#
directive|endif
comment|/* HAVE_VPRINTF */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_VPRINTF
name|VA_START
argument_list|(
name|args
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HAVE_VPRINTF */
ifdef|#
directive|ifdef
name|HAVE_DOPRNT
name|_doprnt
argument_list|(
name|message
argument_list|,
operator|&
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HAVE_DOPRNT */
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|message
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HAVE_DOPRNT */
endif|#
directive|endif
comment|/* !HAVE_VPRINTF */
if|if
condition|(
name|errnum
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|": %s"
argument_list|,
name|strerror
argument_list|(
name|errnum
argument_list|)
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

