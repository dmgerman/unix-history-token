begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: rmp_proto.c 1.3 89/06/07$  *  *	From: @(#)rmp_proto.c	7.1 (Berkeley) 5/8/90  *	$Id: rmp_proto.c,v 1.1 1993/11/07 22:55:11 wollman Exp $  */
end_comment

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
file|"rmp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RMP
end_ifdef

begin_comment
comment|/*  * HP Remote Maintenance Protocol (RMP) family: BOOT  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|rmpdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|raw_usrreq
argument_list|()
decl_stmt|,
name|rmp_output
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protosw
name|rmpsw
index|[]
init|=
block|{
block|{
name|SOCK_RAW
block|,
operator|&
name|rmpdomain
block|,
name|RMPPROTO_BOOT
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
literal|0
block|,
name|rmp_output
block|,
literal|0
block|,
literal|0
block|,
name|raw_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,   }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|rmpdomain
init|=
block|{
name|AF_RMP
block|,
literal|"RMP"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|rmpsw
block|,
operator|&
name|rmpsw
index|[
sizeof|sizeof
argument_list|(
name|rmpsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rmpsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

