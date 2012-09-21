begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PF_MTAG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_PF_MTAG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PF_TAG_GENERATED
value|0x01
end_define

begin_define
define|#
directive|define
name|PF_TAG_FRAGCACHE
value|0x02
end_define

begin_define
define|#
directive|define
name|PF_TAG_TRANSLATE_LOCALHOST
value|0x04
end_define

begin_define
define|#
directive|define
name|PF_PACKET_LOOPED
value|0x08
end_define

begin_define
define|#
directive|define
name|PF_FASTFWD_OURS_PRESENT
value|0x10
end_define

begin_struct
struct|struct
name|pf_mtag
block|{
name|void
modifier|*
name|hdr
decl_stmt|;
comment|/* saved hdr pos in mbuf, for ECN */
name|u_int32_t
name|qid
decl_stmt|;
comment|/* queue id */
name|u_int16_t
name|tag
decl_stmt|;
comment|/* tag id */
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|routed
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|pf_mtag
operator|*
name|pf_find_mtag
argument_list|(
argument|struct mbuf *m
argument_list|)
block|{ 	struct
name|m_tag
operator|*
name|mtag
block|;
if|if
condition|(
operator|(
name|mtag
operator|=
name|m_tag_find
argument_list|(
name|m
argument_list|,
name|PACKET_TAG_PF
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
end_expr_stmt

begin_return
return|return
operator|(
operator|(
expr|struct
name|pf_mtag
operator|*
operator|)
operator|(
name|mtag
operator|+
literal|1
operator|)
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PF_MTAG_H_ */
end_comment

end_unit

