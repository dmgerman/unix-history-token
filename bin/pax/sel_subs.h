begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sel_subs.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * data structure for storing uid/grp selects (-U, -G non standard options)  */
end_comment

begin_define
define|#
directive|define
name|USR_TB_SZ
value|317
end_define

begin_comment
comment|/* user selection table size */
end_comment

begin_define
define|#
directive|define
name|GRP_TB_SZ
value|317
end_define

begin_comment
comment|/* user selection table size */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|usrt
block|{
name|uid_t
name|uid
decl_stmt|;
name|struct
name|usrt
modifier|*
name|fow
decl_stmt|;
comment|/* next uid */
block|}
name|USRT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|grpt
block|{
name|gid_t
name|gid
decl_stmt|;
name|struct
name|grpt
modifier|*
name|fow
decl_stmt|;
comment|/* next gid */
block|}
name|GRPT
typedef|;
end_typedef

begin_comment
comment|/*  * data structure for storing user supplied time ranges (-T option)  */
end_comment

begin_define
define|#
directive|define
name|ATOI2
parameter_list|(
name|s
parameter_list|)
value|((((s)[0] - '0') * 10) + ((s)[1] - '0'))
end_define

begin_typedef
typedef|typedef
struct|struct
name|time_rng
block|{
name|time_t
name|low_time
decl_stmt|;
comment|/* lower inclusive time limit */
name|time_t
name|high_time
decl_stmt|;
comment|/* higher inclusive time limit */
name|int
name|flgs
decl_stmt|;
comment|/* option flags */
define|#
directive|define
name|HASLOW
value|0x01
comment|/* has lower time limit */
define|#
directive|define
name|HASHIGH
value|0x02
comment|/* has higher time limit */
define|#
directive|define
name|CMPMTME
value|0x04
comment|/* compare file modification time */
define|#
directive|define
name|CMPCTME
value|0x08
comment|/* compare inode change time */
define|#
directive|define
name|CMPBOTH
value|(CMPMTME|CMPCTME)
comment|/* compare inode and mod time */
name|struct
name|time_rng
modifier|*
name|fow
decl_stmt|;
comment|/* next pattern */
block|}
name|TIME_RNG
typedef|;
end_typedef

end_unit

