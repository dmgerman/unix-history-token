begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Shigio Yamaguchi. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Shigio Yamaguchi.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	token.h						14-Aug-98  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TOKEN_H_
end_ifndef

begin_define
define|#
directive|define
name|_TOKEN_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"mgets.h"
end_include

begin_define
define|#
directive|define
name|MAXTOKEN
value|512
end_define

begin_define
define|#
directive|define
name|SYMBOL
value|0
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sp
decl_stmt|,
modifier|*
name|cp
decl_stmt|,
modifier|*
name|lp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|crflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ymode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|token
index|[
name|MAXTOKEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|curfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nextchar
parameter_list|()
define|\
value|(cp == NULL ? \ 		((sp = cp = mgets(ip, NULL, 0)) == NULL ? \ 			EOF : \ 			(lineno++, *cp == 0 ? \ 				lp = cp, cp = NULL, '\n' : \ 				*cp++)) : \ 		(*cp == 0 ? (lp = cp, cp = NULL, '\n') : *cp++))
end_define

begin_define
define|#
directive|define
name|atfirst
value|(sp&& sp == (cp ? cp - 1 : lp))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|opentoken
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
name|closetoken
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nexttoken
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|char
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushbacktoken
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|peekc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|atfirst_exceptspace
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _TOKEN_H_ */
end_comment

end_unit

