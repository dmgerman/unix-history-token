begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  *	Derived from:  *	$NetBSD: svr4_fuser.h,v 1.4 1998/09/04 19:54:38 christos Exp $	 */
end_comment

begin_comment
comment|/*-  * Original Copyright:  *  * Copyright (c) 1994 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions of this code have been derived from code contributed to the  * FreeBSD Project by Mark Newton.  *  * Copyright (c) 1999 Mark Newton  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_FUSER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_FUSER_H_
end_define

begin_include
include|#
directive|include
file|<svr4/svr4_types.h>
end_include

begin_struct
struct|struct
name|svr4_f_user
block|{
name|svr4_pid_t
name|fu_pid
decl_stmt|;
name|int
name|fu_flags
decl_stmt|;
name|uid_t
name|fu_uid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SVR4_F_FILE_ONLY
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_F_CONTAINED
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_F_CDIR
value|0x01
end_define

begin_define
define|#
directive|define
name|SVR4_F_RDIR
value|0x02
end_define

begin_define
define|#
directive|define
name|SVR4_F_TEXT
value|0x04
end_define

begin_define
define|#
directive|define
name|SVR4_F_MAP
value|0x08
end_define

begin_define
define|#
directive|define
name|SVR4_F_OPEN
value|0x10
end_define

begin_define
define|#
directive|define
name|SVR4_F_TRACE
value|0x20
end_define

begin_define
define|#
directive|define
name|SVR4_F_TTY
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_FUSER_H_ */
end_comment

end_unit

