begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* error.c -- error handler for noninteractive utilities    Copyright (C) 1990, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* David MacKenzie */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|VPRINTF_MISSING
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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
comment|/* not __STDC__ */
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
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not VPRINTF_MISSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOPRNT_MISSING
end_ifndef

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
comment|/* DOPRNT_MISSING */
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
comment|/* DOPRNT_MISSING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VPRINTF_MISSING */
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
comment|/* not STDC_HEADERS */
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
comment|/* STDC_HEADERS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRERROR_MISSING
end_ifdef

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
operator|<
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
comment|/* STRERROR_MISSING */
end_comment

begin_comment
comment|/* Print the program name and error message MESSAGE, which is a printf-style    format string with optional args.    If ERRNUM is nonzero, print its corresponding system error message.    Exit with status STATUS if it is nonzero. */
end_comment

begin_comment
comment|/* VARARGS */
end_comment

begin_decl_stmt
name|void
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VPRINTF_MISSING
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
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
comment|/* VPRINTF_MISSING or not __STDC__ */
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
comment|/* not VPRINTF_MISSING or __STDC__ */
end_comment

begin_block
block|{
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
ifndef|#
directive|ifndef
name|VPRINTF_MISSING
name|va_list
name|args
decl_stmt|;
endif|#
directive|endif
comment|/* VPRINTF_MISSING */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|VPRINTF_MISSING
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
comment|/* VPRINTF_MISSING */
ifndef|#
directive|ifndef
name|DOPRNT_MISSING
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
comment|/* DOPRNT_MISSING */
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
comment|/* DOPRNT_MISSING */
endif|#
directive|endif
comment|/* VPRINTF_MISSING */
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

