begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Derived from:  *	$NetBSD: svr4_resource.h,v 1.1 1998/11/28 21:53:02 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Original copyright:  *  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Portions of this code derived from software contributed to the  * FreeBSD Project by Mark Newton.  *   * Copyright (c) 1999 Mark Newton  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_RESOURCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_RESOURCE_H_
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_CPU
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_FSIZE
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_DATA
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_STACK
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_CORE
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_NOFILE
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_VMEM
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_RLIMIT_AS
value|SVR4_RLIMIT_VMEM
end_define

begin_define
define|#
directive|define
name|SVR4_RLIM_NLIMITS
value|7
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|svr4_rlim_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SVR4_RLIM_SAVED_CUR
value|0x7ffffffd
end_define

begin_define
define|#
directive|define
name|SVR4_RLIM_SAVED_MAX
value|0x7ffffffe
end_define

begin_define
define|#
directive|define
name|SVR4_RLIM_INFINITY
value|0x7fffffff
end_define

begin_struct
struct|struct
name|svr4_rlimit
block|{
name|svr4_rlim_t
name|rlim_cur
decl_stmt|;
name|svr4_rlim_t
name|rlim_max
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|u_int64_t
name|svr4_rlim64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SVR4_RLIM64_SAVED_CUR
value|((svr4_rlim64_t) -1)
end_define

begin_define
define|#
directive|define
name|SVR4_RLIM64_SAVED_MAX
value|((svr4_rlim64_t) -2)
end_define

begin_define
define|#
directive|define
name|SVR4_RLIM64_INFINITY
value|((svr4_rlim64_t) -3)
end_define

begin_struct
struct|struct
name|svr4_rlimit64
block|{
name|svr4_rlim64_t
name|rlim_cur
decl_stmt|;
name|svr4_rlim64_t
name|rlim_max
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_RESOURCE_H_ */
end_comment

end_unit

