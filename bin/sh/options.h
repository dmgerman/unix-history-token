begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)options.h	5.1 (Berkeley) 3/7/91  *	options.h,v 1.4 1993/08/01 18:58:39 mycroft Exp  */
end_comment

begin_struct
struct|struct
name|shparam
block|{
name|int
name|nparam
decl_stmt|;
comment|/* number of positional parameters (without $0) */
name|char
name|malloc
decl_stmt|;
comment|/* true if parameter list dynamicly allocated */
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
comment|/* parameter list */
name|char
modifier|*
modifier|*
name|optnext
decl_stmt|;
comment|/* next parameter to be processed by getopts */
name|char
modifier|*
name|optptr
decl_stmt|;
comment|/* used by getopts */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|eflag
value|optval[0]
end_define

begin_define
define|#
directive|define
name|fflag
value|optval[1]
end_define

begin_define
define|#
directive|define
name|Iflag
value|optval[2]
end_define

begin_define
define|#
directive|define
name|iflag
value|optval[3]
end_define

begin_define
define|#
directive|define
name|jflag
value|optval[4]
end_define

begin_define
define|#
directive|define
name|nflag
value|optval[5]
end_define

begin_define
define|#
directive|define
name|sflag
value|optval[6]
end_define

begin_define
define|#
directive|define
name|xflag
value|optval[7]
end_define

begin_define
define|#
directive|define
name|zflag
value|optval[8]
end_define

begin_define
define|#
directive|define
name|vflag
value|optval[9]
end_define

begin_define
define|#
directive|define
name|NOPTS
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_OPTIONS
end_ifdef

begin_decl_stmt
specifier|const
name|char
name|optchar
index|[
name|NOPTS
operator|+
literal|1
index|]
init|=
literal|"efIijnsxzv"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell flags */
end_comment

begin_decl_stmt
name|char
name|optval
index|[
name|NOPTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values of option flags */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|optchar
index|[
name|NOPTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|optval
index|[
name|NOPTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|minusc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argument to -c option */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|arg0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $0 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|shparam
name|shellparam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $@ */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|argptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argument list for builtin commands */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by nextopt */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by nextopt */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|procargs
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setparam
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeparam
parameter_list|(
name|struct
name|shparam
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nextopt
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|procargs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setparam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeparam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nextopt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

