begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)options.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
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
value|optlist[0].val
end_define

begin_define
define|#
directive|define
name|fflag
value|optlist[1].val
end_define

begin_define
define|#
directive|define
name|Iflag
value|optlist[2].val
end_define

begin_define
define|#
directive|define
name|iflag
value|optlist[3].val
end_define

begin_define
define|#
directive|define
name|mflag
value|optlist[4].val
end_define

begin_define
define|#
directive|define
name|nflag
value|optlist[5].val
end_define

begin_define
define|#
directive|define
name|sflag
value|optlist[6].val
end_define

begin_define
define|#
directive|define
name|xflag
value|optlist[7].val
end_define

begin_define
define|#
directive|define
name|vflag
value|optlist[8].val
end_define

begin_define
define|#
directive|define
name|Vflag
value|optlist[9].val
end_define

begin_define
define|#
directive|define
name|Eflag
value|optlist[10].val
end_define

begin_define
define|#
directive|define
name|Cflag
value|optlist[11].val
end_define

begin_define
define|#
directive|define
name|aflag
value|optlist[12].val
end_define

begin_define
define|#
directive|define
name|bflag
value|optlist[13].val
end_define

begin_define
define|#
directive|define
name|uflag
value|optlist[14].val
end_define

begin_define
define|#
directive|define
name|privileged
value|optlist[15].val
end_define

begin_define
define|#
directive|define
name|Tflag
value|optlist[16].val
end_define

begin_define
define|#
directive|define
name|NOPTS
value|17
end_define

begin_struct
struct|struct
name|optent
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
name|letter
decl_stmt|;
name|char
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_OPTIONS
end_ifdef

begin_decl_stmt
name|struct
name|optent
name|optlist
index|[
name|NOPTS
index|]
init|=
block|{
block|{
literal|"errexit"
block|,
literal|'e'
block|,
literal|0
block|}
block|,
block|{
literal|"noglob"
block|,
literal|'f'
block|,
literal|0
block|}
block|,
block|{
literal|"ignoreeof"
block|,
literal|'I'
block|,
literal|0
block|}
block|,
block|{
literal|"interactive"
block|,
literal|'i'
block|,
literal|0
block|}
block|,
block|{
literal|"monitor"
block|,
literal|'m'
block|,
literal|0
block|}
block|,
block|{
literal|"noexec"
block|,
literal|'n'
block|,
literal|0
block|}
block|,
block|{
literal|"stdin"
block|,
literal|'s'
block|,
literal|0
block|}
block|,
block|{
literal|"xtrace"
block|,
literal|'x'
block|,
literal|0
block|}
block|,
block|{
literal|"verbose"
block|,
literal|'v'
block|,
literal|0
block|}
block|,
block|{
literal|"vi"
block|,
literal|'V'
block|,
literal|0
block|}
block|,
block|{
literal|"emacs"
block|,
literal|'E'
block|,
literal|0
block|}
block|,
block|{
literal|"noclobber"
block|,
literal|'C'
block|,
literal|0
block|}
block|,
block|{
literal|"allexport"
block|,
literal|'a'
block|,
literal|0
block|}
block|,
block|{
literal|"notify"
block|,
literal|'b'
block|,
literal|0
block|}
block|,
block|{
literal|"nounset"
block|,
literal|'u'
block|,
literal|0
block|}
block|,
block|{
literal|"privileged"
block|,
literal|'p'
block|,
literal|0
block|}
block|,
block|{
literal|"trapsasync"
block|,
literal|'T'
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|optent
name|optlist
index|[
name|NOPTS
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
name|optptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by nextopt */
end_comment

begin_decl_stmt
name|void
name|procargs
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|optschanged
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setparam
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|freeparam
name|__P
argument_list|(
operator|(
expr|struct
name|shparam
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shiftcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getoptscmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nextopt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getoptsreset
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

