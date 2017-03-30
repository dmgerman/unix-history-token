begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Roman Divacky  * Copyright (c) 2014 Dmitry Chagin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EVENT_H_
end_define

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
name|LINUX_EPOLL_EVRD
value|(LINUX_EPOLLIN|LINUX_EPOLLRDNORM	\ 		|LINUX_EPOLLHUP|LINUX_EPOLLERR|LINUX_EPOLLPRI)
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_EVWR
value|(LINUX_EPOLLOUT|LINUX_EPOLLWRNORM)
end_define

begin_define
define|#
directive|define
name|LINUX_EPOLL_EVSUP
value|(LINUX_EPOLLET|LINUX_EPOLLONESHOT	\ 		|LINUX_EPOLL_EVRD|LINUX_EPOLL_EVWR|LINUX_EPOLLRDHUP)
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
name|LINUX_EFD_SEMAPHORE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_TIMER_ABSTIME
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_TIMER_CANCEL_ON_SET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_CLOEXEC
value|LINUX_O_CLOEXEC
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_NONBLOCK
value|LINUX_O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_SHARED_FCNTL_FLAGS
value|(LINUX_TFD_CLOEXEC		\ 		|LINUX_TFD_NONBLOCK)
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_CREATE_FLAGS
value|LINUX_TFD_SHARED_FCNTL_FLAGS
end_define

begin_define
define|#
directive|define
name|LINUX_TFD_SETTIME_FLAGS
value|(LINUX_TFD_TIMER_ABSTIME		\ 		|LINUX_TFD_TIMER_CANCEL_ON_SET)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_EVENT_H_ */
end_comment

end_unit

