begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dmalloc - debugging layer on top of malloc  * vix 22mar92 [written]  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++  * -  * Copyright (c)  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|s
parameter_list|)
value|dmalloc(__FILE__, __LINE__, s)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|p
parameter_list|)
value|dfree(__FILE__, __LINE__, p)
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|dcalloc(__FILE__, __LINE__, n, s)
end_define

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|drealloc(__FILE__, __LINE__, p, s)
end_define

begin_decl_stmt
name|char
modifier|*
name|dmalloc
argument_list|()
decl_stmt|,
modifier|*
name|dcalloc
argument_list|()
decl_stmt|,
modifier|*
name|drealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dfree
argument_list|()
decl_stmt|,
name|dmallocstats
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

