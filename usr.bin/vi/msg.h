begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)msg.h	8.8 (Berkeley) 11/18/93  */
end_comment

begin_comment
comment|/*  * M_BERR	-- Error: ring a bell if O_VERBOSE not set, else  *		   display in inverse video.  * M_ERR	-- Error: display in inverse video.  * M_INFO	-- Info: display in normal video.  * M_SYSERR	-- M_ERR, but use standard error message.  * M_VINFO	-- Info: display only if O_VERBOSE set.  *  * In historical vi, O_VERBOSE didn't exist, and O_TERSE made the  * error messages shorter.  In this version, O_TERSE has no effect  * and O_VERBOSE results in informational displays about common  * errors.  */
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
name|M_SYSERR
block|,
name|M_VINFO
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|struct
name|_msgh
name|MSGH
typedef|;
end_typedef

begin_comment
comment|/* MESG list head structure. */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|_msgh
argument_list|,
name|_msg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|_msg
block|{
name|LIST_ENTRY
argument_list|(
argument|_msg
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of messages. */
name|char
modifier|*
name|mbuf
decl_stmt|;
comment|/* Message buffer. */
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
struct|;
end_struct

begin_comment
comment|/* Messages. */
end_comment

begin_decl_stmt
name|void
name|msg_app
name|__P
argument_list|(
operator|(
name|GS
operator|*
operator|,
name|SCR
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
name|SCR
operator|*
operator|,
name|int
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
name|SCR
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

