begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id:$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_TUNVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_TUNVAR_H_
end_define

begin_struct
struct|struct
name|tun_softc
block|{
name|u_short
name|tun_flags
decl_stmt|;
comment|/* misc flags */
define|#
directive|define
name|TUN_OPEN
value|0x0001
define|#
directive|define
name|TUN_INITED
value|0x0002
define|#
directive|define
name|TUN_RCOLL
value|0x0004
define|#
directive|define
name|TUN_IASET
value|0x0008
define|#
directive|define
name|TUN_DSTADDR
value|0x0010
define|#
directive|define
name|TUN_RWAIT
value|0x0040
define|#
directive|define
name|TUN_ASYNC
value|0x0080
define|#
directive|define
name|TUN_READY
value|(TUN_OPEN | TUN_INITED)
name|struct
name|ifnet
name|tun_if
decl_stmt|;
comment|/* the interface */
name|int
name|tun_pgrp
decl_stmt|;
comment|/* the process group - if any */
name|struct
name|selinfo
name|tun_rsel
decl_stmt|;
comment|/* read select */
name|struct
name|selinfo
name|tun_wsel
decl_stmt|;
comment|/* write select (not used) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TUNVAR_H_ */
end_comment

end_unit

