begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  * From: $NetBSD: diskbuf.h,v 1.1.1.1 1997/03/14 02:40:32 perry Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996  *	Matthias Drochner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* data buffer for BIOS disk / DOS I/O */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|diskbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* client-supplied disk buffer */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|diskbuf_user
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using function sets it to unique value to allow check if overwritten*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|diskbuf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of client-supplied buffer in sectors */
end_comment

end_unit

