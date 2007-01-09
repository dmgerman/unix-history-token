begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: iodesc.h,v 1.4 1995/09/23 03:31:50 gwr Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 Adam Glass   * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_LIBNETBOOT_IODESC_H
end_ifndef

begin_define
define|#
directive|define
name|__SYS_LIBNETBOOT_IODESC_H
end_define

begin_struct
struct|struct
name|iodesc
block|{
name|struct
name|in_addr
name|destip
decl_stmt|;
comment|/* dest. ip addr, net order */
name|struct
name|in_addr
name|myip
decl_stmt|;
comment|/* local ip addr, net order */
name|u_short
name|destport
decl_stmt|;
comment|/* dest. port, net order */
name|u_short
name|myport
decl_stmt|;
comment|/* local port, net order */
name|u_long
name|xid
decl_stmt|;
comment|/* transaction identification */
name|u_char
name|myea
index|[
literal|6
index|]
decl_stmt|;
comment|/* my ethernet address */
name|struct
name|netif
modifier|*
name|io_netif
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_LIBNETBOOT_IODESC_H */
end_comment

end_unit

