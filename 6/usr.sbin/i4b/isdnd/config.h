begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b daemon - compile time configuration header file  *	---------------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Mon May 21 11:21:15 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H_
end_define

begin_comment
comment|/* general values */
end_comment

begin_define
define|#
directive|define
name|UMASK
value|022
end_define

begin_comment
comment|/* file creation perm mask	*/
end_comment

begin_define
define|#
directive|define
name|CFG_ENTRY_MAX
value|60
end_define

begin_comment
comment|/* max no of config entries	*/
end_comment

begin_define
define|#
directive|define
name|ISDN_CTRL_MAX
value|4
end_define

begin_comment
comment|/* max no of controllers	*/
end_comment

begin_define
define|#
directive|define
name|MAX_RE
value|8
end_define

begin_comment
comment|/* max regular expression entries */
end_comment

begin_comment
comment|/* monitor max values */
end_comment

begin_define
define|#
directive|define
name|MAX_MHOSTS
value|8
end_define

begin_comment
comment|/* max allowed monitor hosts 	*/
end_comment

begin_comment
comment|/* timouts */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT_CONNECT_ACTIVE
value|30
end_define

begin_comment
comment|/* seconds to wait for MSG_CONN_ACT */
end_comment

begin_comment
comment|/* utility programs forked */
end_comment

begin_define
define|#
directive|define
name|REGPROG_DEF
value|"program"
end_define

begin_comment
comment|/* default program to use for regexpr */
end_comment

begin_define
define|#
directive|define
name|ANSWERPROG_DEF
value|"answer"
end_define

begin_comment
comment|/* default telephone answer program */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONFIG_H_ */
end_comment

begin_comment
comment|/* EOF */
end_comment

end_unit

