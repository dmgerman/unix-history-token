begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Steven Wallace  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_POLL_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_POLL_H
value|1
end_define

begin_comment
comment|/* iBCS2 poll commands */
end_comment

begin_define
define|#
directive|define
name|IBCS2_POLLIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLPRI
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLHUP
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLNVAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLRDNORM
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLWRNORM
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLRDBAND
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLWRBAND
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_READPOLL
value|(IBCS2_POLLIN|IBCS2_POLLRDNORM|IBCS2_POLLRDBAND)
end_define

begin_define
define|#
directive|define
name|IBCS2_WRITEPOLL
value|(IBCS2_POLLOUT|IBCS2_POLLWRNORM|IBCS2_POLLWRBAND)
end_define

begin_struct
struct|struct
name|ibcs2_poll
block|{
name|int
name|fd
decl_stmt|;
name|short
name|events
decl_stmt|;
name|short
name|revents
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_POLL_H */
end_comment

end_unit

