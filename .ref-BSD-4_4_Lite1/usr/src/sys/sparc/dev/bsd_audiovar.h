begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)bsd_audiovar.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: bsd_audiovar.h,v 1.6 92/11/21 20:46:49 van Exp $ (LBL)  */
end_comment

begin_define
define|#
directive|define
name|AUCB_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|AUCB_MOD
parameter_list|(
name|k
parameter_list|)
value|((k)& (AUCB_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|AUCB_INIT
parameter_list|(
name|cb
parameter_list|)
value|((cb)->cb_head = (cb)->cb_tail = (cb)->cb_drops = \ 			 (cb)->cb_pdrops = 0)
end_define

begin_define
define|#
directive|define
name|AUCB_EMPTY
parameter_list|(
name|cb
parameter_list|)
value|((cb)->cb_head == (cb)->cb_tail)
end_define

begin_define
define|#
directive|define
name|AUCB_FULL
parameter_list|(
name|cb
parameter_list|)
value|(AUCB_MOD((cb)->cb_tail + 1) == (cb)->cb_head)
end_define

begin_define
define|#
directive|define
name|AUCB_LEN
parameter_list|(
name|cb
parameter_list|)
value|(AUCB_MOD((cb)->cb_tail - (cb)->cb_head))
end_define

begin_define
define|#
directive|define
name|MAXBLKSIZE
value|(AUCB_SIZE / 2)
end_define

begin_define
define|#
directive|define
name|DEFBLKSIZE
value|128
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * aucb's are used for communication between the trap handler and  * the software interrupt.  */
end_comment

begin_struct
struct|struct
name|aucb
block|{
name|int
name|cb_head
decl_stmt|;
comment|/* queue head */
name|int
name|cb_tail
decl_stmt|;
comment|/* queue tail */
name|int
name|cb_thresh
decl_stmt|;
comment|/* threshold for wakeup */
name|u_short
name|cb_waking
decl_stmt|;
comment|/* needs wakeup at softint level */
name|u_short
name|cb_pause
decl_stmt|;
comment|/* io paused */
name|u_long
name|cb_drops
decl_stmt|;
comment|/* missed samples from over/underrun */
name|u_long
name|cb_pdrops
decl_stmt|;
comment|/* sun compat -- paused samples */
name|u_char
name|cb_data
index|[
name|AUCB_SIZE
index|]
decl_stmt|;
comment|/* data buffer */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|volatile
argument_list|)
end_if

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|auio
block|{
specifier|volatile
name|struct
name|amd7930
modifier|*
name|au_amd
decl_stmt|;
comment|/* chip registers */
name|u_long
name|au_stamp
decl_stmt|;
comment|/* time stamp */
name|int
name|au_lowat
decl_stmt|;
comment|/* xmit low water mark (for wakeup) */
name|int
name|au_hiwat
decl_stmt|;
comment|/* xmit high water mark (for wakeup) */
name|int
name|au_blksize
decl_stmt|;
comment|/* recv block (chunk) size */
name|int
name|au_backlog
decl_stmt|;
comment|/* # samples of xmit backlog to gen. */
name|struct
name|aucb
name|au_rb
decl_stmt|;
comment|/* read (recv) buffer */
name|struct
name|aucb
name|au_wb
decl_stmt|;
comment|/* write (xmit) buffer */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

