begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2000 by Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * BASED ON:  * -------------------------------------------------------------------------  *  * Copyright (c) 1988, Julian Onions<jpo@cs.nott.ac.uk>  * Nottingham University 1987.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Id: if_tap.h,v 0.7 2000/07/12 04:12:51 max Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_TAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_TAP_H_
end_define

begin_comment
comment|/* refer to if_tapvar.h for the softc stuff */
end_comment

begin_comment
comment|/* maximum receive packet size (hard limit) */
end_comment

begin_define
define|#
directive|define
name|TAPMRU
value|16384
end_define

begin_struct
struct|struct
name|tapinfo
block|{
name|int
name|baudrate
decl_stmt|;
comment|/* linespeed                 */
name|short
name|mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|u_char
name|type
decl_stmt|;
comment|/* ethernet, tokenring, etc. */
name|u_char
name|dummy
decl_stmt|;
comment|/* place holder              */
block|}
struct|;
end_struct

begin_comment
comment|/* ioctl's for get/set debug */
end_comment

begin_define
define|#
directive|define
name|TAPSDEBUG
value|_IOW('t', 90, int)
end_define

begin_define
define|#
directive|define
name|TAPGDEBUG
value|_IOR('t', 89, int)
end_define

begin_define
define|#
directive|define
name|TAPSIFINFO
value|_IOW('t', 91, struct tapinfo)
end_define

begin_define
define|#
directive|define
name|TAPGIFINFO
value|_IOR('t', 92, struct tapinfo)
end_define

begin_comment
comment|/* VMware ioctl's */
end_comment

begin_define
define|#
directive|define
name|VMIO_SIOCSIFFLAGS
value|_IO('V', 0)
end_define

begin_define
define|#
directive|define
name|VMIO_SIOCSKEEP
value|_IO('V', 1)
end_define

begin_define
define|#
directive|define
name|VMIO_SIOCSIFBR
value|_IO('V', 2)
end_define

begin_define
define|#
directive|define
name|VMIO_SIOCSLADRF
value|_IO('V', 3)
end_define

begin_comment
comment|/* XXX -- unimplemented */
end_comment

begin_define
define|#
directive|define
name|VMIO_SIOCSETMACADDR
value|_IO('V', 4)
end_define

begin_comment
comment|/* XXX -- not used? */
end_comment

begin_define
define|#
directive|define
name|VMIO_SIOCPORT
value|_IO('V', 5)
end_define

begin_define
define|#
directive|define
name|VMIO_SIOCBRIDGE
value|_IO('V', 6)
end_define

begin_define
define|#
directive|define
name|VMIO_SIOCNETIF
value|_IO('V', 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TAP_H_ */
end_comment

end_unit

