begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Error handler for noninteractive utilities    Copyright (C) 1990-1998, 2000 Free Software Foundation, Inc.     This file is part of the GNU C Library.  Its master source is NOT part of    the C library, however.  The master source lives in /gd/gnu/lib.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie<djm@gnu.ai.mit.edu>.  */
end_comment

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

begin_if
if|#
directive|if
name|HAVE_LIBINTL_H
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_VPRINTF
operator|||
name|HAVE_DOPRNT
operator|||
name|_LIBC
end_if

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

begin_else
else|#
directive|else
end_else

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

begin_if
if|#
directive|if
name|STDC_HEADERS
operator|||
name|_LIBC
end_if

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

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_STRERROR_R
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_STRERROR_R
name|char
operator|*
name|strerror_r
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_
end_ifndef

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If NULL, error will flush stdout, then print on stderr the program    name, a colon and a space.  Otherwise, error will call this    function without parameters instead.  */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|error_print_progname
function_decl|)
parameter_list|(
if|#
directive|if
name|__STDC__
operator|-
literal|0
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This variable is incremented each time `error' is called.  */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|error_message_count
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_comment
comment|/* In the GNU C library, there is a predefined variable for this.  */
end_comment

begin_define
define|#
directive|define
name|program_name
value|program_invocation_name
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* In GNU libc we want do not want to use the common name `error' directly.    Instead make it a weak alias.  */
end_comment

begin_define
define|#
directive|define
name|error
value|__error
end_define

begin_define
define|#
directive|define
name|error_at_line
value|__error_at_line
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_IN_LIBIO
end_ifdef

begin_include
include|#
directive|include
file|<libio/iolibio.h>
end_include

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|s
parameter_list|)
value|_IO_fflush (s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _LIBC */
end_comment

begin_comment
comment|/* The calling program should define program_name and set it to the    name of the executing program.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRERROR_R
end_ifdef

begin_define
define|#
directive|define
name|__strerror_r
value|strerror_r
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_STRERROR
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|strerror
end_ifndef

begin_comment
comment|/* On some systems, strerror is a macro */
end_comment

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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
name|_
argument_list|(
name|sys_errlist
index|[
name|errnum
index|]
argument_list|)
return|;
return|return
name|_
argument_list|(
literal|"Unknown system error"
argument_list|)
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
comment|/* HAVE_STRERROR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRERROR_R */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _LIBC */
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
name|VA_START
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
specifier|const
name|char
operator|*
name|message
argument_list|,
operator|...
argument_list|)
else|#
directive|else
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

begin_block
block|{
ifdef|#
directive|ifdef
name|VA_START
name|va_list
name|args
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error_print_progname
condition|)
call|(
modifier|*
name|error_print_progname
call|)
argument_list|()
expr_stmt|;
else|else
block|{
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|VA_START
name|VA_START
argument_list|(
name|args
argument_list|,
name|message
argument_list|)
expr_stmt|;
if|#
directive|if
name|HAVE_VPRINTF
operator|||
name|_LIBC
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
else|#
directive|else
name|_doprnt
argument_list|(
name|message
argument_list|,
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
else|#
directive|else
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
operator|++
name|error_message_count
expr_stmt|;
if|if
condition|(
name|errnum
condition|)
block|{
if|#
directive|if
name|defined
name|HAVE_STRERROR_R
operator|||
name|_LIBC
name|char
name|errbuf
index|[
literal|1024
index|]
decl_stmt|;
if|#
directive|if
name|HAVE_WORKING_STRERROR_R
operator|||
name|_LIBC
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|": %s"
argument_list|,
name|__strerror_r
argument_list|(
name|errnum
argument_list|,
name|errbuf
argument_list|,
sizeof|sizeof
name|errbuf
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Don't use __strerror_r's return value because on some systems 	 (at least DEC UNIX 4.0[A-D]) strerror_r returns `int'.  */
name|__strerror_r
argument_list|(
name|errnum
argument_list|,
name|errbuf
argument_list|,
sizeof|sizeof
name|errbuf
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|": %s"
argument_list|,
name|errbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
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
endif|#
directive|endif
block|}
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

begin_escape
end_escape

begin_comment
comment|/* Sometimes we want to have at most one error per line.  This    variable controls whether this mode is selected or not.  */
end_comment

begin_decl_stmt
name|int
name|error_one_per_line
decl_stmt|;
end_decl_stmt

begin_function
name|void
if|#
directive|if
name|defined
name|VA_START
operator|&&
name|__STDC__
name|error_at_line
parameter_list|(
name|int
name|status
parameter_list|,
name|int
name|errnum
parameter_list|,
specifier|const
name|char
modifier|*
name|file_name
parameter_list|,
name|unsigned
name|int
name|line_number
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|error_at_line
parameter_list|(
name|status
parameter_list|,
name|errnum
parameter_list|,
name|file_name
parameter_list|,
name|line_number
parameter_list|,
name|message
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|status
decl_stmt|;
name|int
name|errnum
decl_stmt|;
specifier|const
name|char
modifier|*
name|file_name
decl_stmt|;
name|unsigned
name|int
name|line_number
decl_stmt|;
name|char
modifier|*
name|message
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|VA_START
name|va_list
name|args
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error_one_per_line
condition|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|old_file_name
decl_stmt|;
specifier|static
name|unsigned
name|int
name|old_line_number
decl_stmt|;
if|if
condition|(
name|old_line_number
operator|==
name|line_number
operator|&&
operator|(
name|file_name
operator|==
name|old_file_name
operator|||
operator|!
name|strcmp
argument_list|(
name|old_file_name
argument_list|,
name|file_name
argument_list|)
operator|)
condition|)
comment|/* Simply return and print nothing.  */
return|return;
name|old_file_name
operator|=
name|file_name
expr_stmt|;
name|old_line_number
operator|=
name|line_number
expr_stmt|;
block|}
if|if
condition|(
name|error_print_progname
condition|)
call|(
modifier|*
name|error_print_progname
call|)
argument_list|()
expr_stmt|;
else|else
block|{
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:"
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|file_name
operator|!=
name|NULL
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:%d: "
argument_list|,
name|file_name
argument_list|,
name|line_number
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VA_START
name|VA_START
argument_list|(
name|args
argument_list|,
name|message
argument_list|)
expr_stmt|;
if|#
directive|if
name|HAVE_VPRINTF
operator|||
name|_LIBC
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
else|#
directive|else
name|_doprnt
argument_list|(
name|message
argument_list|,
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
else|#
directive|else
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
operator|++
name|error_message_count
expr_stmt|;
if|if
condition|(
name|errnum
condition|)
block|{
if|#
directive|if
name|defined
name|HAVE_STRERROR_R
operator|||
name|_LIBC
name|char
name|errbuf
index|[
literal|1024
index|]
decl_stmt|;
if|#
directive|if
name|HAVE_WORKING_STRERROR_R
operator|||
name|_LIBC
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|": %s"
argument_list|,
name|__strerror_r
argument_list|(
name|errnum
argument_list|,
name|errbuf
argument_list|,
sizeof|sizeof
name|errbuf
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Don't use __strerror_r's return value because on some systems 	 (at least DEC UNIX 4.0[A-D]) strerror_r returns `int'.  */
name|__strerror_r
argument_list|(
name|errnum
argument_list|,
name|errbuf
argument_list|,
sizeof|sizeof
name|errbuf
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|": %s"
argument_list|,
name|errbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
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
endif|#
directive|endif
block|}
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
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_comment
comment|/* Make the weak alias.  */
end_comment

begin_undef
undef|#
directive|undef
name|error
end_undef

begin_undef
undef|#
directive|undef
name|error_at_line
end_undef

begin_macro
name|weak_alias
argument_list|(
argument|__error
argument_list|,
argument|error
argument_list|)
end_macro

begin_macro
name|weak_alias
argument_list|(
argument|__error_at_line
argument_list|,
argument|error_at_line
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

