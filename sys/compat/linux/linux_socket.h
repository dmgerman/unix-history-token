begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Assar Westerlund  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_SOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_SOCKET_H_
end_define

begin_comment
comment|/* msg flags in recvfrom/recvmsg */
end_comment

begin_define
define|#
directive|define
name|LINUX_MSG_OOB
value|0x01
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_PEEK
value|0x02
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_DONTROUTE
value|0x04
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_CTRUNC
value|0x08
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_PROXY
value|0x10
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_TRUNC
value|0x20
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_DONTWAIT
value|0x40
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_EOR
value|0x80
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_WAITALL
value|0x100
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_FIN
value|0x200
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_SYN
value|0x400
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_CONFIRM
value|0x800
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_RST
value|0x1000
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_ERRQUEUE
value|0x2000
end_define

begin_define
define|#
directive|define
name|LINUX_MSG_NOSIGNAL
value|0x4000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_SOCKET_H_ */
end_comment

end_unit

