begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)slip.h	8.1 (Berkeley) 2/12/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_SLIP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_SLIP_H_
end_define

begin_comment
comment|/* Ioctls operating on SLIP ttys. */
end_comment

begin_define
define|#
directive|define
name|SLIOCGUNIT
value|_IOR('t', 88, int)
end_define

begin_comment
comment|/* get slip unit number */
end_comment

begin_define
define|#
directive|define
name|SLIOCSKEEPAL
value|_IOW('t', 84, int)
end_define

begin_comment
comment|/* set keepalive */
end_comment

begin_define
define|#
directive|define
name|SLIOCSOUTFILL
value|_IOW('t', 83, int)
end_define

begin_comment
comment|/* set out fill time */
end_comment

begin_define
define|#
directive|define
name|SLIOCGKEEPAL
value|_IOR('t', 82, int)
end_define

begin_comment
comment|/* get keepalive time */
end_comment

begin_define
define|#
directive|define
name|SLIOCGOUTFILL
value|_IOR('t', 81, int)
end_define

begin_comment
comment|/* get out fill time */
end_comment

begin_define
define|#
directive|define
name|SLIOCSUNIT
value|_IOW('t', 80, int)
end_define

begin_comment
comment|/* set slip unit number */
end_comment

begin_comment
comment|/*  * Definitions of the pseudo-link-level header attached to slip  * packets grabbed by the packet filter (bpf) traffic monitor.  */
end_comment

begin_define
define|#
directive|define
name|SLIP_HDRLEN
value|16
end_define

begin_comment
comment|/* BPF SLIP header length */
end_comment

begin_comment
comment|/* Offsets into BPF SLIP header. */
end_comment

begin_define
define|#
directive|define
name|SLX_DIR
value|0
end_define

begin_comment
comment|/* direction; see below */
end_comment

begin_define
define|#
directive|define
name|SLX_CHDR
value|1
end_define

begin_comment
comment|/* compressed header data */
end_comment

begin_define
define|#
directive|define
name|CHDR_LEN
value|15
end_define

begin_comment
comment|/* length of compressed header data */
end_comment

begin_define
define|#
directive|define
name|SLIPDIR_IN
value|0
end_define

begin_comment
comment|/* incoming */
end_comment

begin_define
define|#
directive|define
name|SLIPDIR_OUT
value|1
end_define

begin_comment
comment|/* outgoing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_SLIP_H */
end_comment

end_unit

