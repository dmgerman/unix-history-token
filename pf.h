begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.   *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.   *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * @(#) $Header: /tcpdump/master/tcpdump/pf.h,v 1.2 2004/04/02 06:36:25 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*	from $OpenBSD: pfvar.h,v 1.170 2003/08/22 21:50:34 david Exp $ */
end_comment

begin_enum
enum|enum
block|{
name|PF_INOUT
init|=
literal|0
block|,
name|PF_IN
init|=
literal|1
block|,
name|PF_OUT
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_PASS
init|=
literal|0
block|,
name|PF_DROP
init|=
literal|1
block|,
name|PF_SCRUB
init|=
literal|2
block|,
name|PF_NAT
init|=
literal|3
block|,
name|PF_NONAT
init|=
literal|4
block|,
name|PF_BINAT
init|=
literal|5
block|,
name|PF_NOBINAT
init|=
literal|6
block|,
name|PF_RDR
init|=
literal|7
block|,
name|PF_NORDR
init|=
literal|8
block|,
name|PF_SYNPROXY_DROP
init|=
literal|9
block|}
enum|;
end_enum

begin_comment
comment|/* Reasons code for passing/dropping a packet */
end_comment

begin_define
define|#
directive|define
name|PFRES_MATCH
value|0
end_define

begin_comment
comment|/* Explicit match of a rule */
end_comment

begin_define
define|#
directive|define
name|PFRES_BADOFF
value|1
end_define

begin_comment
comment|/* Bad offset for pull_hdr */
end_comment

begin_define
define|#
directive|define
name|PFRES_FRAG
value|2
end_define

begin_comment
comment|/* Dropping following fragment */
end_comment

begin_define
define|#
directive|define
name|PFRES_SHORT
value|3
end_define

begin_comment
comment|/* Dropping short packet */
end_comment

begin_define
define|#
directive|define
name|PFRES_NORM
value|4
end_define

begin_comment
comment|/* Dropping by normalizer */
end_comment

begin_define
define|#
directive|define
name|PFRES_MEMORY
value|5
end_define

begin_comment
comment|/* Dropped due to lacking mem */
end_comment

begin_define
define|#
directive|define
name|PFRES_MAX
value|6
end_define

begin_comment
comment|/* total+1 */
end_comment

begin_define
define|#
directive|define
name|PFRES_NAMES
value|{ \ 	"match", \ 	"bad-offset", \ 	"fragment", \ 	"short", \ 	"normalize", \ 	"memory", \ 	NULL \ }
end_define

begin_define
define|#
directive|define
name|PF_RULESET_NAME_SIZE
value|16
end_define

begin_comment
comment|/*	from $OpenBSD: if_pflog.h,v 1.9 2003/07/15 20:27:27 dhartmei Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IFNAMSIZ
end_ifndef

begin_define
define|#
directive|define
name|IFNAMSIZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pfloghdr
block|{
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|af
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
name|u_int8_t
name|reason
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|char
name|ruleset
index|[
name|PF_RULESET_NAME_SIZE
index|]
decl_stmt|;
name|u_int32_t
name|rulenr
decl_stmt|;
name|u_int32_t
name|subrulenr
decl_stmt|;
name|u_int8_t
name|dir
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFLOG_HDRLEN
value|sizeof(struct pfloghdr)
end_define

end_unit

