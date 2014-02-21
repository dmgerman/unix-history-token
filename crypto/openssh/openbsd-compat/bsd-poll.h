begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: poll.h,v 1.11 2003/12/10 23:10:08 millert Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Theo de Raadt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: sys/sys/poll.h */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_POLL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_POLL_H
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_POLL_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_POLL_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|pollfd
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
name|pollfd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|nfds_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|POLLIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|POLLOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|POLLERR
value|0x0008
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* the following are currently not implemented */
end_comment

begin_define
define|#
directive|define
name|POLLPRI
value|0x0002
end_define

begin_define
define|#
directive|define
name|POLLHUP
value|0x0010
end_define

begin_define
define|#
directive|define
name|POLLNVAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|POLLRDNORM
value|0x0040
end_define

begin_define
define|#
directive|define
name|POLLNORM
value|POLLRDNORM
end_define

begin_define
define|#
directive|define
name|POLLWRNORM
value|POLLOUT
end_define

begin_define
define|#
directive|define
name|POLLRDBAND
value|0x0080
end_define

begin_define
define|#
directive|define
name|POLLWRBAND
value|0x0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INFTIM
value|(-1)
end_define

begin_comment
comment|/* not standard */
end_comment

begin_function_decl
name|int
name|poll
parameter_list|(
name|struct
name|pollfd
modifier|*
parameter_list|,
name|nfds_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_POLL_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_POLL_H */
end_comment

end_unit

