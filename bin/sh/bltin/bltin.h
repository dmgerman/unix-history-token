begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)bltin.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file is included by programs which are optionally built into the  * shell.  If SHELL is defined, we try to map the standard UNIX library  * routines to ash routines using defines.  */
end_comment

begin_include
include|#
directive|include
file|"../shell.h"
end_include

begin_include
include|#
directive|include
file|"../mystring.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SHELL
end_ifdef

begin_include
include|#
directive|include
file|"../output.h"
end_include

begin_undef
undef|#
directive|undef
name|stdout
end_undef

begin_define
define|#
directive|define
name|stdout
value|out1
end_define

begin_undef
undef|#
directive|undef
name|stderr
end_undef

begin_define
define|#
directive|define
name|stderr
value|out2
end_define

begin_define
define|#
directive|define
name|printf
value|out1fmt
end_define

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|c
parameter_list|,
name|file
parameter_list|)
value|outc(c, file)
end_define

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|c
parameter_list|)
value|out1c(c)
end_define

begin_define
define|#
directive|define
name|fprintf
value|outfmt
end_define

begin_define
define|#
directive|define
name|fputs
value|outstr
end_define

begin_define
define|#
directive|define
name|fflush
value|flushout
end_define

begin_define
define|#
directive|define
name|INITARGS
parameter_list|(
name|argv
parameter_list|)
end_define

begin_define
define|#
directive|define
name|warnx1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{				\ 	char buf[64];					\ 	(void)snprintf(buf, sizeof(buf), a);		\ 	error("%s", buf);				\ }
end_define

begin_define
define|#
directive|define
name|warnx2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{				\ 	char buf[64];					\ 	(void)snprintf(buf, sizeof(buf), a, b);		\ 	error("%s", buf);				\ }
end_define

begin_define
define|#
directive|define
name|warnx3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{				\ 	char buf[64];					\ 	(void)snprintf(buf, sizeof(buf), a, b, c);	\ 	error("%s", buf);				\ }
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|main
end_undef

begin_define
define|#
directive|define
name|INITARGS
parameter_list|(
name|argv
parameter_list|)
value|if ((commandname = argv[0]) == NULL) {fputs("Argc is zero\n", stderr); exit(2);} else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|pointer
name|stalloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printf0like
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|pointer
name|stalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|commandname
decl_stmt|;
end_decl_stmt

end_unit

