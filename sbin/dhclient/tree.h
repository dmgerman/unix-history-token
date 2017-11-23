begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: tree.h,v 1.5 2004/05/06 22:29:15 deraadt Exp $	*/
end_comment

begin_comment
comment|/* Definitions for address trees... */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1995 The Internet Software Consortium.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon<mellon@fugue.com> in cooperation with Vixie  * Enterprises.  To learn more about the Internet Software Consortium,  * see ``http://www.vix.com/isc''.  To learn more about Vixie  * Enterprises, see ``http://www.vix.com''.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* A pair of pointers, suitable for making a linked list. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pair
block|{
name|caddr_t
name|car
decl_stmt|;
name|struct
name|_pair
modifier|*
name|cdr
decl_stmt|;
block|}
typedef|*
name|pair
typedef|;
end_typedef

begin_struct
struct|struct
name|tree_cache
block|{
name|unsigned
name|char
modifier|*
name|value
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
name|buf_size
decl_stmt|;
name|time_t
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|universe
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|hash_table
modifier|*
name|hash
decl_stmt|;
name|struct
name|option
modifier|*
name|options
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|option
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|format
decl_stmt|;
name|struct
name|universe
modifier|*
name|universe
decl_stmt|;
name|unsigned
name|char
name|code
decl_stmt|;
block|}
struct|;
end_struct

end_unit

