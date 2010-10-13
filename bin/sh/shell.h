begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)shell.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL_H_
end_ifndef

begin_define
define|#
directive|define
name|SHELL_H_
end_define

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/*  * The follow should be set to reflect the type of system you have:  *	JOBS -> 1 if you have Berkeley job control, 0 otherwise.  *	define DEBUG=1 to compile in debugging (set global "debug" to turn on)  *	define DEBUG=2 to compile in and turn on debugging.  *	define DEBUG=3 to also build all functions as public  *  * When debugging is on, debugging info will be written to ./trace and  * a quit signal will generate a core dump.  */
end_comment

begin_define
define|#
directive|define
name|JOBS
value|1
end_define

begin_comment
comment|/* #define DEBUG 1 */
end_comment

begin_comment
comment|/*  * Type of used arithmetics. SUSv3 requires us to have at least signed long.  */
end_comment

begin_typedef
typedef|typedef
name|intmax_t
name|arith_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ARITH_FORMAT_STR
value|"%" PRIdMAX
end_define

begin_define
define|#
directive|define
name|atoarith_t
parameter_list|(
name|arg
parameter_list|)
value|strtoimax(arg, NULL, 0)
end_define

begin_define
define|#
directive|define
name|strtoarith_t
parameter_list|(
name|nptr
parameter_list|,
name|endptr
parameter_list|,
name|base
parameter_list|)
value|strtoimax(nptr, endptr, base)
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_comment
comment|/* STATIC is only for use with functions, not variables.  */
end_comment

begin_if
if|#
directive|if
name|DEBUG
operator|>=
literal|3
end_if

begin_define
define|#
directive|define
name|STATIC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MKINIT
end_define

begin_comment
comment|/* empty */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|nullstr
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* null string */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|param
parameter_list|)
value|sh_trace param
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|param
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHELL_H_ */
end_comment

end_unit

