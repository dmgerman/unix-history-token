begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)seq.h	8.7 (Berkeley) 12/2/93  */
end_comment

begin_comment
comment|/*  * Map and abbreviation structures.  *  * The map structure is doubly linked list, sorted by input string and by  * input length within the string.  (The latter is necessary so that short  * matches will happen before long matches when the list is searched.)  * Additionally, there is a bitmap which has bits set if there are entries  * starting with the corresponding character.  This keeps us from walking  * the list unless it's necessary.  *  * XXX  * The fast-lookup bits are never turned off -- users don't usually unmap  * things, though, so it's probably not a big deal.  */
end_comment

begin_comment
comment|/* Sequence type. */
end_comment

begin_enum
enum|enum
name|seqtype
block|{
name|SEQ_ABBREV
block|,
name|SEQ_COMMAND
block|,
name|SEQ_INPUT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|_seq
block|{
name|LIST_ENTRY
argument_list|(
argument|_seq
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of all sequences. */
name|enum
name|seqtype
name|stype
decl_stmt|;
comment|/* Sequence type. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Sequence name (if any). */
name|size_t
name|nlen
decl_stmt|;
comment|/* Name length. */
name|char
modifier|*
name|input
decl_stmt|;
comment|/* Sequence input keys. */
name|size_t
name|ilen
decl_stmt|;
comment|/* Input keys length. */
name|char
modifier|*
name|output
decl_stmt|;
comment|/* Sequence output keys. */
name|size_t
name|olen
decl_stmt|;
comment|/* Output keys length. */
define|#
directive|define
name|S_USERDEF
value|0x01
comment|/* If sequence user defined. */
name|u_char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|abbr_save
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|map_save
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seq_delete
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
expr|enum
name|seqtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seq_dump
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
expr|enum
name|seqtype
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SEQ
modifier|*
name|seq_find
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SEQ
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
expr|enum
name|seqtype
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seq_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seq_save
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
expr|enum
name|seqtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seq_set
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
expr|enum
name|seqtype
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

