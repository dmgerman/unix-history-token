begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ccitt_proto.c	7.5 (Berkeley) 8/30/90  *	$Id: ccitt_proto.c,v 1.2 1993/10/16 19:46:33 rgrimes Exp $  */
end_comment

begin_define
define|#
directive|define
name|HDLC
end_define

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"x25.h"
end_include

begin_comment
comment|/*  *	Definitions of protocols supported in the CCITT domain.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_3
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|ccittdomain
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DOMAIN
value|&ccittdomain
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DOMAIN
value|PF_CCITT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XE
end_ifdef

begin_function_decl
name|int
name|xe_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xe_ctlinput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xe_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xe_timer
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HDLC
end_ifdef

begin_function_decl
name|int
name|hd_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hd_ctlinput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hd_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hd_timer
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pk_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pk_timer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pk_ctloutput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pk_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|protosw
name|ccittsw
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|XE
block|{
literal|0
block|,
name|DOMAIN
block|,
name|IEEEPROTO_802LLC
block|,
literal|0
block|,
literal|0
block|,
name|xe_output
block|,
name|xe_ctlinput
block|,
literal|0
block|,
literal|0
block|,
name|xe_init
block|,
literal|0
block|,
name|xe_timer
block|,
literal|0
block|,  }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HDLC
block|{
literal|0
block|,
name|DOMAIN
block|,
name|CCITTPROTO_HDLC
block|,
literal|0
block|,
literal|0
block|,
name|hd_output
block|,
name|hd_ctlinput
block|,
literal|0
block|,
literal|0
block|,
name|hd_init
block|,
literal|0
block|,
name|hd_timer
block|,
literal|0
block|,  }
block|,
endif|#
directive|endif
block|{
name|SOCK_STREAM
block|,
name|DOMAIN
block|,
name|CCITTPROTO_X25
block|,
name|PR_CONNREQUIRED
operator||
name|PR_ATOMIC
operator||
name|PR_WANTRCVD
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|pk_ctloutput
block|,
name|pk_usrreq
block|,
name|pk_init
block|,
literal|0
block|,
name|pk_timer
block|,
literal|0
block|,  }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|ccittdomain
init|=
ifdef|#
directive|ifdef
name|BSD4_3
block|{
name|AF_CCITT
block|,
literal|"ccitt"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ccittsw
block|,
operator|&
name|ccittsw
index|[
sizeof|sizeof
argument_list|(
name|ccittsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ccittsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_block
block|{
name|AF_CCITT
operator|,
literal|"ccitt"
operator|,
name|ccittsw
operator|,
operator|&
name|ccittsw
index|[
sizeof|sizeof
argument_list|(
name|ccittsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ccittsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

