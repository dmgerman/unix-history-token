begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Roman Divacky  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MISC_H_
end_define

begin_comment
comment|/* defines for prctl */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_SET_PDEATHSIG
value|1
end_define

begin_comment
comment|/* Second arg is a signal. */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_GET_PDEATHSIG
value|2
end_define

begin_comment
comment|/* 					 * Second arg is a ptr to return the 					 * signal. 					 */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_SET_NAME
value|15
end_define

begin_comment
comment|/* Set process name. */
end_comment

begin_define
define|#
directive|define
name|LINUX_PR_GET_NAME
value|16
end_define

begin_comment
comment|/* Get process name. */
end_comment

begin_define
define|#
directive|define
name|LINUX_MAX_COMM_LEN
value|16
end_define

begin_comment
comment|/* Maximum length of the process name. */
end_comment

begin_define
define|#
directive|define
name|LINUX_MREMAP_MAYMOVE
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_MREMAP_FIXED
value|2
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|linux_platform
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Non-standard aux entry types used in Linux ELF binaries.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_PLATFORM
value|15
end_define

begin_comment
comment|/* String identifying CPU */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_HWCAP
value|16
end_define

begin_comment
comment|/* CPU capabilities */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_CLKTCK
value|17
end_define

begin_comment
comment|/* frequency at which times() increments */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_SECURE
value|23
end_define

begin_comment
comment|/* secure mode boolean */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_BASE_PLATFORM
value|24
end_define

begin_comment
comment|/* string identifying real platform, may 					 * differ from AT_PLATFORM. 					 */
end_comment

begin_define
define|#
directive|define
name|LINUX_AT_EXECFN
value|31
end_define

begin_comment
comment|/* filename of program */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MISC_H_ */
end_comment

end_unit

