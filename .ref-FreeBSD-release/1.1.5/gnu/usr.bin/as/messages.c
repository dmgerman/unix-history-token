begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* messages.c - error reporter -    Copyright (C) 1987, 1991, 1992 Free Software Foundation, Inc.        This file is part of GAS, the GNU Assembler.        GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.        GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: messages.c,v 1.3 1993/10/02 20:57:45 pk Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* define stderr */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDARG
end_ifndef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VARARGS
end_ifndef

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_VARARGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_STDARG */
end_comment

begin_comment
comment|/*  * Despite the rest of the comments in this file, (FIXME-SOON),  * here is the current scheme for error messages etc:  *  * as_fatal() is used when gas is quite confused and  * continuing the assembly is pointless.  In this case we  * exit immediately with error status.  *  * as_bad() is used to mark errors that result in what we  * presume to be a useless object file.  Say, we ignored  * something that might have been vital.  If we see any of  * these, assembly will continue to the end of the source,  * no object file will be produced, and we will terminate  * with error status.  The new option, -Z, tells us to  * produce an object file anyway but we still exit with  * error status.  The assumption here is that you don't want  * this object file but we could be wrong.  *  * as_warn() is used when we have an error from which we  * have a plausible error recovery.  eg, masking the top  * bits of a constant that is longer than will fit in the  * destination.  In this case we will continue to assemble  * the source, although we may have made a bad assumption,  * and we will produce an object file and return normal exit  * status (ie, no error).  The new option -X tells us to  * treat all as_warn() errors as as_bad() errors.  That is,  * no object file will be produced and we will exit with  * error status.  The idea here is that we don't kill an  * entire make because of an error that we knew how to  * correct.  On the other hand, sometimes you might want to  * stop the make at these points.  *  * as_tsktsk() is used when we see a minor error for which  * our error recovery action is almost certainly correct.  * In this case, we print a message and then assembly  * continues as though no error occurred.  */
end_comment

begin_comment
comment|/*   ERRORS      JF: this is now bogus.  We now print more standard error messages   that try to look like everyone else's.      We print the error message 1st, beginning in column 1.   All ancillary info starts in column 2 on lines after the   key error text.   We try to print a location in logical and physical file   just after the main error text.   Caller then prints any appendices after that, begining all   lines with at least 1 space.      Optionally, we may die.   There is no need for a trailing '\n' in your error text format   because we supply one.      as_warn(fmt,args)  Like fprintf(stderr,fmt,args) but also call errwhere().      as_fatal(fmt,args) Like as_warn() but exit with a fatal status.      */
end_comment

begin_decl_stmt
specifier|static
name|int
name|warning_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of number of warnings issued */
end_comment

begin_function
name|int
name|had_warnings
parameter_list|()
block|{
return|return
operator|(
name|warning_count
operator|)
return|;
block|}
end_function

begin_comment
comment|/* had_err() */
end_comment

begin_comment
comment|/* Nonzero if we've hit a 'bad error', and should not write an obj file,    and exit with a nonzero error code */
end_comment

begin_decl_stmt
specifier|static
name|int
name|error_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|had_errors
parameter_list|()
block|{
return|return
operator|(
name|error_count
operator|)
return|;
block|}
end_function

begin_comment
comment|/* had_errors() */
end_comment

begin_comment
comment|/*  *			a s _ p e r r o r  *  * Like perror(3), but with more info.  */
end_comment

begin_function
name|void
name|as_perror
parameter_list|(
name|gripe
parameter_list|,
name|filename
parameter_list|)
name|char
modifier|*
name|gripe
decl_stmt|;
comment|/* Unpunctuated error theme. */
name|char
modifier|*
name|filename
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|HAVE_STRERROR
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* HAVE_STRERROR */
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|gripe
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s.\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* After reporting, clear it. */
block|}
end_function

begin_comment
comment|/* as_perror() */
end_comment

begin_comment
comment|/*  *			a s _ t s k t s k ()  *  * Send to stderr a string (with bell) (JF: Bell is obnoxious!) as a warning, and locate warning  * in input file(s).  * Please only use this for when we have some recovery action.  * Please explain in string (which may have '\n's) what recovery was done.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDARG
end_ifndef

begin_function
name|void
name|as_tsktsk
parameter_list|(
name|Format
parameter_list|)
specifier|const
name|char
modifier|*
name|Format
decl_stmt|;
block|{
name|va_list
name|args
decl_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|Format
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_tsktsk() */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VARARGS
end_ifndef

begin_function
name|void
name|as_tsktsk
parameter_list|(
name|Format
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|Format
decl_stmt|;
function|va_dcl
block|{
name|va_list
name|args
decl_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_tsktsk() */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS1 */
end_comment

begin_macro
name|as_tsktsk
argument_list|(
argument|Format
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|Format
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|as_where
argument_list|()
expr_stmt|;
name|_doprnt
argument_list|(
name|Format
argument_list|,
operator|&
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
comment|/* as_where(); */
block|}
end_block

begin_comment
comment|/* as_tsktsk */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_VARARGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_STDARG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DONTDEF
end_ifdef

begin_function
name|void
name|as_tsktsk
parameter_list|(
name|Format
parameter_list|,
name|aa
parameter_list|,
name|ab
parameter_list|,
name|ac
parameter_list|,
name|ad
parameter_list|,
name|ae
parameter_list|,
name|af
parameter_list|,
name|ag
parameter_list|,
name|ah
parameter_list|,
name|ai
parameter_list|,
name|aj
parameter_list|,
name|ak
parameter_list|,
name|al
parameter_list|,
name|am
parameter_list|,
name|an
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|;
block|{
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|aa
argument_list|,
name|ab
argument_list|,
name|ac
argument_list|,
name|ad
argument_list|,
name|ae
argument_list|,
name|af
argument_list|,
name|ag
argument_list|,
name|ah
argument_list|,
name|ai
argument_list|,
name|aj
argument_list|,
name|ak
argument_list|,
name|al
argument_list|,
name|am
argument_list|,
name|an
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_tsktsk() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *			a s _ w a r n ()  *  * Send to stderr a string (with bell) (JF: Bell is obnoxious!) as a warning, and locate warning  * in input file(s).  * Please only use this for when we have some recovery action.  * Please explain in string (which may have '\n's) what recovery was done.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDARG
end_ifndef

begin_function
name|void
name|as_warn
parameter_list|(
name|Format
parameter_list|)
specifier|const
name|char
modifier|*
name|Format
decl_stmt|;
block|{
name|va_list
name|args
decl_stmt|;
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|flagseen
index|[
literal|'W'
index|]
condition|)
block|{
operator|++
name|warning_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|Format
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning: "
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buffer
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
name|listing_warning
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* as_warn() */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VARARGS
end_ifndef

begin_function
name|void
name|as_warn
parameter_list|(
name|Format
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|Format
decl_stmt|;
function|va_dcl
block|{
name|va_list
name|args
decl_stmt|;
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|flagseen
index|[
literal|'W'
index|]
condition|)
block|{
operator|++
name|warning_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning: "
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buffer
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
name|listing_warning
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* as_warn() */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS1 */
end_comment

begin_macro
name|as_warn
argument_list|(
argument|Format
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|Format
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* -W supresses warning messages. */
if|if
condition|(
operator|!
name|flagseen
index|[
literal|'W'
index|]
condition|)
block|{
operator|++
name|warning_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|_doprnt
argument_list|(
name|Format
argument_list|,
operator|&
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
comment|/* as_where(); */
block|}
block|}
end_block

begin_comment
comment|/* as_warn() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_VARARGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_STDARG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DONTDEF
end_ifdef

begin_function
name|void
name|as_warn
parameter_list|(
name|Format
parameter_list|,
name|aa
parameter_list|,
name|ab
parameter_list|,
name|ac
parameter_list|,
name|ad
parameter_list|,
name|ae
parameter_list|,
name|af
parameter_list|,
name|ag
parameter_list|,
name|ah
parameter_list|,
name|ai
parameter_list|,
name|aj
parameter_list|,
name|ak
parameter_list|,
name|al
parameter_list|,
name|am
parameter_list|,
name|an
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|flagseen
index|[
literal|'W'
index|]
condition|)
block|{
operator|++
name|warning_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|aa
argument_list|,
name|ab
argument_list|,
name|ac
argument_list|,
name|ad
argument_list|,
name|ae
argument_list|,
name|af
argument_list|,
name|ag
argument_list|,
name|ah
argument_list|,
name|ai
argument_list|,
name|aj
argument_list|,
name|ak
argument_list|,
name|al
argument_list|,
name|am
argument_list|,
name|an
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* as_warn() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *			a s _ b a d ()  *  * Send to stderr a string (with bell) (JF: Bell is obnoxious!) as a warning,  * and locate warning in input file(s).  * Please us when there is no recovery, but we want to continue processing  * but not produce an object file.  * Please explain in string (which may have '\n's) what recovery was done.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDARG
end_ifndef

begin_function
name|void
name|as_bad
parameter_list|(
name|Format
parameter_list|)
specifier|const
name|char
modifier|*
name|Format
decl_stmt|;
block|{
name|va_list
name|args
decl_stmt|;
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
operator|++
name|error_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|Format
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: "
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buffer
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
name|listing_error
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_bad() */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VARARGS
end_ifndef

begin_function
name|void
name|as_bad
parameter_list|(
name|Format
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|Format
decl_stmt|;
function|va_dcl
block|{
name|va_list
name|args
decl_stmt|;
name|char
name|buffer
index|[
literal|200
index|]
decl_stmt|;
operator|++
name|error_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buffer
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
name|listing_error
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_bad() */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS1 */
end_comment

begin_macro
name|as_bad
argument_list|(
argument|Format
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|Format
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|++
name|error_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: "
argument_list|)
expr_stmt|;
name|_doprnt
argument_list|(
name|Format
argument_list|,
operator|&
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
comment|/* as_where(); */
block|}
end_block

begin_comment
comment|/* as_bad() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_VARARGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_STDARG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DONTDEF
end_ifdef

begin_function
name|void
name|as_bad
parameter_list|(
name|Format
parameter_list|,
name|aa
parameter_list|,
name|ab
parameter_list|,
name|ac
parameter_list|,
name|ad
parameter_list|,
name|ae
parameter_list|,
name|af
parameter_list|,
name|ag
parameter_list|,
name|ah
parameter_list|,
name|ai
parameter_list|,
name|aj
parameter_list|,
name|ak
parameter_list|,
name|al
parameter_list|,
name|am
parameter_list|,
name|an
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|;
block|{
operator|++
name|error_count
expr_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|aa
argument_list|,
name|ab
argument_list|,
name|ac
argument_list|,
name|ad
argument_list|,
name|ae
argument_list|,
name|af
argument_list|,
name|ag
argument_list|,
name|ah
argument_list|,
name|ai
argument_list|,
name|aj
argument_list|,
name|ak
argument_list|,
name|al
argument_list|,
name|am
argument_list|,
name|an
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_bad() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *			a s _ f a t a l ()  *  * Send to stderr a string (with bell) (JF: Bell is obnoxious!) as a fatal  * message, and locate stdsource in input file(s).  * Please only use this for when we DON'T have some recovery action.  * It exit()s with a warning status.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDARG
end_ifndef

begin_function
name|void
name|as_fatal
parameter_list|(
name|Format
parameter_list|)
specifier|const
name|char
modifier|*
name|Format
decl_stmt|;
block|{
name|va_list
name|args
decl_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|Format
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FATAL:"
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|33
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_fatal() */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VARARGS
end_ifndef

begin_function
name|void
name|as_fatal
parameter_list|(
name|Format
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
name|Format
decl_stmt|;
function|va_dcl
block|{
name|va_list
name|args
decl_stmt|;
name|as_where
argument_list|()
expr_stmt|;
name|va_start
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FATAL:"
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|args
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|33
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_fatal() */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS1 */
end_comment

begin_macro
name|as_fatal
argument_list|(
argument|Format
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|Format
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FATAL:"
argument_list|)
expr_stmt|;
name|_doprnt
argument_list|(
name|Format
argument_list|,
operator|&
name|args
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
comment|/* as_where(); */
name|exit
argument_list|(
literal|33
argument_list|)
expr_stmt|;
comment|/* What is a good exit status? */
block|}
end_block

begin_comment
comment|/* as_fatal() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_VARARGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NO_STDARG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DONTDEF
end_ifdef

begin_function
name|void
name|as_fatal
parameter_list|(
name|Format
parameter_list|,
name|aa
parameter_list|,
name|ab
parameter_list|,
name|ac
parameter_list|,
name|ad
parameter_list|,
name|ae
parameter_list|,
name|af
parameter_list|,
name|ag
parameter_list|,
name|ah
parameter_list|,
name|ai
parameter_list|,
name|aj
parameter_list|,
name|ak
parameter_list|,
name|al
parameter_list|,
name|am
parameter_list|,
name|an
parameter_list|)
name|char
modifier|*
name|Format
decl_stmt|;
block|{
name|as_where
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FATAL:"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|Format
argument_list|,
name|aa
argument_list|,
name|ab
argument_list|,
name|ac
argument_list|,
name|ad
argument_list|,
name|ae
argument_list|,
name|af
argument_list|,
name|ag
argument_list|,
name|ah
argument_list|,
name|ai
argument_list|,
name|aj
argument_list|,
name|ak
argument_list|,
name|al
argument_list|,
name|am
argument_list|,
name|an
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|33
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* as_fatal() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of messages.c */
end_comment

end_unit

