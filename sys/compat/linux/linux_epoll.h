begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Roman Divacky  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EPOLL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EPOLL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|EPOLL_PACKED
value|__packed
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EPOLL_PACKED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|linux_epoll_event
block|{
name|uint32_t
name|events
decl_stmt|;
name|uint64_t
name|data
decl_stmt|;
block|}
name|EPOLL_PACKED
struct|;
end_struct

begin_define
define|#
directive|define
name|LINUX_EPOLLIN
value|0x001
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLPRI
value|0x002
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLOUT
value|0x004
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLRDNORM
value|0x040
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLRDBAND
value|0x080
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLWRNORM
value|0x100
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLWRBAND
value|0x200
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLMSG
value|0x400
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLERR
value|0x008
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLHUP
value|0x010
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLRDHUP
value|0x2000
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLWAKEUP
value|1u<<29
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLONESHOT
value|1u<<30
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLLET
value|1u<<31
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_CTL_ADD
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_CTL_DEL
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_CTL_MOD
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_CLOEXEC
value|02000000
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_NONBLOCK
value|00004000
end_define

begin_define
define|#
directive|define
name|LINUX_MAX_EVENTS
value|(INT_MAX / sizeof(struct linux_epoll_event))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_EPOLL_H_ */
end_comment

end_unit

