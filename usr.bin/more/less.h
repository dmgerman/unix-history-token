begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)less.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|MAXVARLENGTH
value|(20)
end_define

begin_define
define|#
directive|define
name|NULL_POSITION
value|((off_t)(-1))
end_define

begin_define
define|#
directive|define
name|EOI
value|(0)
end_define

begin_define
define|#
directive|define
name|READ_INTR
value|(-2)
end_define

begin_define
define|#
directive|define
name|NO_HORIZ_OFF
value|(-1)
end_define

begin_comment
comment|/* Wrap lines like normal */
end_comment

begin_comment
comment|/* Special chars used to tell put_line() to do something special */
end_comment

begin_define
define|#
directive|define
name|UL_CHAR
value|'\201'
end_define

begin_comment
comment|/* Enter underline mode */
end_comment

begin_define
define|#
directive|define
name|UE_CHAR
value|'\202'
end_define

begin_comment
comment|/* Exit underline mode */
end_comment

begin_define
define|#
directive|define
name|BO_CHAR
value|'\203'
end_define

begin_comment
comment|/* Enter boldface mode */
end_comment

begin_define
define|#
directive|define
name|BE_CHAR
value|'\204'
end_define

begin_comment
comment|/* Exit boldface mode */
end_comment

begin_define
define|#
directive|define
name|CONTROL_CHAR
parameter_list|(
name|c
parameter_list|)
value|(!isprint(c))
end_define

begin_define
define|#
directive|define
name|CARAT_CHAR
parameter_list|(
name|c
parameter_list|)
value|((c == '\177') ? '?' : (c | 0100))
end_define

begin_define
define|#
directive|define
name|TOP
value|(0)
end_define

begin_define
define|#
directive|define
name|TOP_PLUS_ONE
value|(1)
end_define

begin_define
define|#
directive|define
name|BOTTOM
value|(-1)
end_define

begin_define
define|#
directive|define
name|BOTTOM_PLUS_ONE
value|(-2)
end_define

begin_define
define|#
directive|define
name|MIDDLE
value|(-3)
end_define

begin_comment
comment|/* The return type of runmacro() */
end_comment

begin_enum
enum|enum
name|runmacro
block|{
name|OK
init|=
literal|0
block|,
name|TOOMACRO
block|,
name|BADMACRO
block|,
name|NOMACRO
block|,
name|BADCOMMAND
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINEGLOBALS
end_ifdef

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|var
parameter_list|,
name|val
parameter_list|)
value|var = val
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|var
parameter_list|,
name|val
parameter_list|)
value|extern var
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This style of error-reporting (see also command.c) is only used by some  * code.  Eventually most of the code should use it, since it is becoming  * inconvenient to have John Q. random function() calling error().  *  * This style of error-reporting still leaves somewhat to be desired....  *  * Note that more(1) needs to potentially work under low-memory conditions  * (such as may occur when all available memory has been sucked-up by  * the file buffer in ch.c).  */
end_comment

begin_comment
comment|/* Be careful about ordering correctly!!  (must match deferrinit_) */
end_comment

begin_enum
enum|enum
name|error
block|{
name|E_OK
init|=
literal|0
block|,
name|E_AMBIG
block|,
name|E_BADMATH
block|,
name|E_BADVAR
block|,
name|E_BOGCOM
block|,
name|E_CANTPARSE
block|,
name|E_CANTXPND
block|,
name|E_COMPLIM
block|,
name|E_EXTERN
block|,
name|E_NOMAC
block|,
name|E_MALLOC
block|,
name|E_NONUM
block|,
name|E_NOSTR
block|,
name|E_NOTOG
block|,
name|E_NULL
block|}
enum|;
end_enum

begin_comment
comment|/* Listed here for reference only.  Be careful about ordering correctly!! */
end_comment

begin_define
define|#
directive|define
name|deferrinit_
value|{ \ 	"",
comment|/* E_OK */
value|\ 	"ambigious macro",
comment|/* E_AMBIG */
value|\ 	"invalid arithmetic expression",
comment|/* E_BADMATH */
value|\ 	"bad variable",
comment|/* E_BADVAR */
value|\ 	"bogus command",
comment|/* E_BOGCOM */
value|\ 	"could not parse command string",
comment|/* E_CANTPARSE */
value|\ 	"could not expand macro",
comment|/* E_CANTXPND */
value|\ 	"compile time limit",
comment|/* E_COMPLIM */
value|\ 	"external dependency error",
comment|/* E_EXTERN */
value|\ 	"could not find match for macro",
comment|/* E_NOMAC */
value|\ 	"malloc() failed",
comment|/* E_MALLOC */
value|\ 	"missing numeric argument to command",
comment|/* E_NONUM */
value|\ 	"missing string argument to command",
comment|/* E_NOSTR */
value|\ 	"bad n-toggle argument to command",
comment|/* E_NOTOG */
value|\ 	"to the unknown error",
comment|/* E_NULL */
value|\ }
end_define

begin_expr_stmt
name|GLOBAL
argument_list|(
specifier|const
name|char
operator|*
name|deferr
index|[]
argument_list|,
name|deferrinit_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * It is possible for erreur to become dis-synchronized from errstr if  * its users aren't careful.  Access through the macros is considered  * careful.  */
end_comment

begin_macro
name|GLOBAL
argument_list|(
argument|enum error erreur
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|GLOBAL
argument_list|(
name|char
operator|*
name|errstr
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* must point be null or free()'ble */
end_comment

begin_define
define|#
directive|define
name|SETERR
parameter_list|(
name|e
parameter_list|)
value|do { \ 		erreur = (e); \ 		if (errstr) free(errstr); \ 		errstr = NULL; \ 	} while (0)
end_define

begin_comment
comment|/* SETERRSTR() also exists.  It is in command.c */
end_comment

begin_comment
comment|/*  * An emalloc() traditionally never fails, but fmalloc() may fail, hence  * the non-standard name.  The fmalloc() is just syntactic sugar that sets  * erreur for the user.  *  * fmalloc(size, pointer-to-new-memory);  *  * Don't compile this puppy with -Wall...  */
end_comment

begin_define
define|#
directive|define
name|FMALLOC
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((((v) = malloc(s)) ? 0 : \ 	((errstr ? free(errstr), errstr=NULL : 0), erreur = E_MALLOC)), (v))
end_define

end_unit

