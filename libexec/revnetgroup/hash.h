begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Groupname entry hung off a member_entry node. */
end_comment

begin_struct
struct|struct
name|grouplist
block|{
name|char
modifier|*
name|groupname
decl_stmt|;
name|struct
name|grouplist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Entry in the cooked member list hash table. */
end_comment

begin_struct
struct|struct
name|member_entry
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|domain
decl_stmt|;
name|struct
name|grouplist
modifier|*
name|groups
decl_stmt|;
name|struct
name|member_entry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Entry in the raw netgroup table. */
end_comment

begin_struct
struct|struct
name|group_entry
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|struct
name|group_entry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Table size (chosen arbitrarily). Not too big, not too small. */
end_comment

begin_define
define|#
directive|define
name|TABLESIZE
value|256
end_define

begin_define
define|#
directive|define
name|HASH_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|LINSIZ
value|1024 * 10
end_define

begin_decl_stmt
specifier|extern
name|void
name|store
name|__P
argument_list|(
operator|(
expr|struct
name|group_entry
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mstore
name|__P
argument_list|(
operator|(
expr|struct
name|member_entry
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lookup
name|__P
argument_list|(
operator|(
expr|struct
name|group_entry
operator|*
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__endnetgrent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__setnetgrent
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
specifier|extern
name|int
name|__getnetgrent
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

