begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)msg.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/*  * M_BERR	-- Error: ring a bell if O_VERBOSE not set, else  *		   display in inverse video.  * M_ERR	-- Error: display in inverse video.  * M_INFO	-- Info: display in normal video.  * M_VINFO	-- Info: display only if O_VERBOSE set.  *  * In historical vi, O_VERBOSE didn't exist, and O_TERSE made the  * error messages shorter.  In this version, O_TERSE has no effect  * and O_VERBOSE results in informational displays about common  * errors.  */
end_comment

begin_enum
enum|enum
name|msgtype
block|{
name|M_BERR
block|,
name|M_ERR
block|,
name|M_INFO
block|,
name|M_VINFO
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|_msg
block|{
name|struct
name|_msg
modifier|*
name|next
decl_stmt|;
comment|/* Linked list of messages. */
name|char
modifier|*
name|mbuf
decl_stmt|;
comment|/* Message. */
name|size_t
name|blen
decl_stmt|;
comment|/* Message buffer length. */
name|size_t
name|len
decl_stmt|;
comment|/* Message length. */
define|#
directive|define
name|M_EMPTY
value|0x01
comment|/* No message. */
define|#
directive|define
name|M_INV_VIDEO
value|0x02
comment|/* Inverse video. */
name|u_int
name|flags
decl_stmt|;
comment|/* Flags. */
block|}
name|MSG
typedef|;
end_typedef

begin_comment
comment|/* Messages. */
end_comment

begin_decl_stmt
name|void
name|bell
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|msg_app
name|__P
argument_list|(
operator|(
expr|struct
name|_gs
operator|*
operator|,
expr|struct
name|_scr
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msg_rpt
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|msgq
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|enum
name|msgtype
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

