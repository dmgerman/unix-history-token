begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* error.c -- error handler for noninteractive utilities    Copyright (C) 1990-1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* David MacKenzie */
end_comment

begin_comment
comment|/* Brian Berliner added support for CVS */
end_comment

begin_include
include|#
directive|include
file|"cvs.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$CVSid: @(#)error.c 1.13 94/09/30 $"
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|USE
argument_list|(
name|rcsid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* If non-zero, error will use the CVS protocol to stdout to report error    messages.  This will only be set in the CVS server parent process;    most other code is run via do_cvs_command, which forks off a child    process and packages up its stderr in the protocol.  */
end_comment

begin_decl_stmt
name|int
name|error_use_protocol
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STDC_HEADERS
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

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|void
name|exit
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|fn_returning_void
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* Function to call before exiting.  */
end_comment

begin_decl_stmt
specifier|static
name|fn_returning_void
name|cleanup_fn
decl_stmt|;
end_decl_stmt

begin_function
name|fn_returning_void
name|error_set_cleanup
parameter_list|(
name|arg
parameter_list|)
name|fn_returning_void
name|arg
decl_stmt|;
block|{
name|fn_returning_void
name|retval
init|=
name|cleanup_fn
decl_stmt|;
name|cleanup_fn
operator|=
name|arg
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

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
specifier|const
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
name|FILE
modifier|*
name|out
init|=
name|stderr
decl_stmt|;
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
specifier|extern
name|char
modifier|*
name|command_name
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_VPRINTF
name|va_list
name|args
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error_use_protocol
condition|)
block|{
name|out
operator|=
name|stdout
expr_stmt|;
name|printf
argument_list|(
literal|"E "
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|command_name
operator|&&
operator|*
name|command_name
condition|)
if|if
condition|(
name|status
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"%s [%s aborted]: "
argument_list|,
name|program_name
argument_list|,
name|command_name
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"%s %s: "
argument_list|,
name|program_name
argument_list|,
name|command_name
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|out
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
name|out
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
name|out
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|out
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
endif|#
directive|endif
if|if
condition|(
name|errnum
condition|)
name|fprintf
argument_list|(
name|out
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
name|out
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|out
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
block|{
if|if
condition|(
name|cleanup_fn
condition|)
call|(
modifier|*
name|cleanup_fn
call|)
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* Print the program name and error message MESSAGE, which is a printf-style    format string with optional args to the file specified by FP.    If ERRNUM is nonzero, print its corresponding system error message.    Exit with status STATUS if it is nonzero. */
end_comment

begin_comment
comment|/* VARARGS */
end_comment

begin_function
name|void
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VPRINTF
argument_list|)
operator|&&
name|__STDC__
name|fperror
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
name|status
parameter_list|,
name|int
name|errnum
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|fperror
parameter_list|(
name|fp
parameter_list|,
name|status
parameter_list|,
name|errnum
parameter_list|,
name|message
parameter_list|,
name|va_alist
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|status
decl_stmt|;
name|int
name|errnum
decl_stmt|;
name|char
modifier|*
name|message
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_VPRINTF
name|va_list
name|args
decl_stmt|;
endif|#
directive|endif
name|fprintf
argument_list|(
name|fp
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
name|fp
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
name|fp
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|fp
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
endif|#
directive|endif
if|if
condition|(
name|errnum
condition|)
name|fprintf
argument_list|(
name|fp
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
name|fp
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
block|{
if|if
condition|(
name|cleanup_fn
condition|)
call|(
modifier|*
name|cleanup_fn
call|)
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

