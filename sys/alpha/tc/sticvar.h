begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: sticvar.h,v 1.1 1997/11/08 07:27:51 jonathan Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Jonathan Stone  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jonathan Stone for  *      the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TC_STICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_TC_STICVAR_H_
end_define

begin_include
include|#
directive|include
file|<dev/tc/sticreg.h>
end_include

begin_comment
comment|/*  * A "softc" used to communicate address info to functions  * that need to deal with all of the STAMP, the STIC, and the VDAC,  * on eihter 2-d or 3-d boards.  */
end_comment

begin_struct
struct|struct
name|stic_softc
block|{
name|struct
name|stic_reg
modifier|*
name|stic_addr
decl_stmt|;
name|void
modifier|*
name|stamp_addr
decl_stmt|;
name|void
modifier|*
name|vdac_addr
decl_stmt|;
name|void
modifier|*
name|stic_pktbuf
decl_stmt|;
comment|/* kva of packet/polling area. */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|stic_init
name|__P
argument_list|(
operator|(
expr|struct
name|stic_softc
operator|*
name|stic_sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TC_STICVAR_H_ */
end_comment

end_unit

