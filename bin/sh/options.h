begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)options.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|shparam
block|{
name|int
name|nparam
decl_stmt|;
comment|/* # of positional parameters (without $0) */
name|unsigned
name|char
name|malloc
decl_stmt|;
comment|/* if parameter list dynamically allocated */
name|unsigned
name|char
name|reset
decl_stmt|;
comment|/* if getopts has been reset */
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
comment|/* parameter list */
name|char
modifier|*
modifier|*
name|optp
decl_stmt|;
comment|/* parameter list for getopts */
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
name|mflag
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
name|vflag
value|optval[8]
end_define

begin_define
define|#
directive|define
name|Vflag
value|optval[9]
end_define

begin_define
define|#
directive|define
name|Eflag
value|optval[10]
end_define

begin_define
define|#
directive|define
name|Cflag
value|optval[11]
end_define

begin_define
define|#
directive|define
name|aflag
value|optval[12]
end_define

begin_define
define|#
directive|define
name|bflag
value|optval[13]
end_define

begin_define
define|#
directive|define
name|uflag
value|optval[14]
end_define

begin_define
define|#
directive|define
name|privileged
value|optval[15]
end_define

begin_define
define|#
directive|define
name|Tflag
value|optval[16]
end_define

begin_define
define|#
directive|define
name|Pflag
value|optval[17]
end_define

begin_define
define|#
directive|define
name|hflag
value|optval[18]
end_define

begin_define
define|#
directive|define
name|nologflag
value|optval[19]
end_define

begin_define
define|#
directive|define
name|NSHORTOPTS
value|19
end_define

begin_define
define|#
directive|define
name|NOPTS
value|20
end_define

begin_decl_stmt
specifier|extern
name|char
name|optval
index|[
name|NOPTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|optletter
index|[
name|NSHORTOPTS
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_OPTIONS
end_ifdef

begin_decl_stmt
name|char
name|optval
index|[
name|NOPTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|optletter
index|[
name|NSHORTOPTS
index|]
init|=
literal|"efIimnsxvVECabupTPh"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|optname
index|[]
init|=
literal|"\007errexit"
literal|"\006noglob"
literal|"\011ignoreeof"
literal|"\013interactive"
literal|"\007monitor"
literal|"\006noexec"
literal|"\005stdin"
literal|"\006xtrace"
literal|"\007verbose"
literal|"\002vi"
literal|"\005emacs"
literal|"\011noclobber"
literal|"\011allexport"
literal|"\006notify"
literal|"\007nounset"
literal|"\012privileged"
literal|"\012trapsasync"
literal|"\010physical"
literal|"\010trackall"
literal|"\005nolog"
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
name|shoptarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by nextopt */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nextopt_optptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by nextopt */
end_comment

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
name|optschanged
parameter_list|(
name|void
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
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getoptsreset
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

