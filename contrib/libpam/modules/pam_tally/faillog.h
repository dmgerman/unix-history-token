begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1989 - 1994, Julianne Frances Haugh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Julianne F. Haugh nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JULIE HAUGH AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JULIE HAUGH OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * faillog.h - login failure logging file format  *  *	$Id: faillog.h,v 1.1.1.1 2000/06/20 22:11:59 agmorgan Exp $  *  * The login failure file is maintained by login(1) and faillog(8)  * Each record in the file represents a separate UID and the file  * is indexed in that fashion.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FAILLOG_H
end_ifndef

begin_define
define|#
directive|define
name|_FAILLOG_H
end_define

begin_struct
struct|struct
name|faillog
block|{
name|short
name|fail_cnt
decl_stmt|;
comment|/* failures since last success */
name|short
name|fail_max
decl_stmt|;
comment|/* failures before turning account off */
name|char
name|fail_line
index|[
literal|12
index|]
decl_stmt|;
comment|/* last failure occured here */
name|time_t
name|fail_time
decl_stmt|;
comment|/* last failure occured then */
comment|/* 	 * If nonzero, the account will be re-enabled if there are no 	 * failures for fail_locktime seconds since last failure. 	 */
name|long
name|fail_locktime
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

