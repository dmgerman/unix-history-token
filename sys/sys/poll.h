begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Peter Wemm<peter@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: poll.h,v 1.3 1997/12/15 03:09:48 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_POLL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_POLL_H_
end_define

begin_comment
comment|/*  * This file is intended to be compatable with the traditional poll.h.  */
end_comment

begin_comment
comment|/*  * This structure is passed as an array to poll(2).  */
end_comment

begin_struct
struct|struct
name|pollfd
block|{
name|int
name|fd
decl_stmt|;
comment|/* which file descriptor to poll */
name|short
name|events
decl_stmt|;
comment|/* events we are interested in */
name|short
name|revents
decl_stmt|;
comment|/* events found on return */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Requestable events.  If poll(2) finds any of these set, they are  * copied to revents on return.  * XXX Note that FreeBSD doesn't make much distinction between POLLPRI  * and POLLRDBAND since none of the file types have distinct priority  * bands - and only some have an urgent "mode".  * XXX Note POLLIN isn't really supported in true SVSV terms.  Under SYSV  * POLLIN includes all of normal, band and urgent data.  Most poll handlers  * on FreeBSD only treat it as "normal" data.  */
end_comment

begin_define
define|#
directive|define
name|POLLIN
value|0x0001
end_define

begin_comment
comment|/* any readable data available */
end_comment

begin_define
define|#
directive|define
name|POLLPRI
value|0x0002
end_define

begin_comment
comment|/* OOB/Urgent readable data */
end_comment

begin_define
define|#
directive|define
name|POLLOUT
value|0x0004
end_define

begin_comment
comment|/* file descriptor is writeable */
end_comment

begin_define
define|#
directive|define
name|POLLRDNORM
value|0x0040
end_define

begin_comment
comment|/* non-OOB/URG data available */
end_comment

begin_define
define|#
directive|define
name|POLLWRNORM
value|POLLOUT
end_define

begin_comment
comment|/* no write type differentiation */
end_comment

begin_define
define|#
directive|define
name|POLLRDBAND
value|0x0080
end_define

begin_comment
comment|/* OOB/Urgent readable data */
end_comment

begin_define
define|#
directive|define
name|POLLWRBAND
value|0x0100
end_define

begin_comment
comment|/* OOB/Urgent data can be written */
end_comment

begin_comment
comment|/*  * FreeBSD extensions: polling on a regular file might return one  * of these events (currently only supported on UFS).  */
end_comment

begin_define
define|#
directive|define
name|POLLEXTEND
value|0x0200
end_define

begin_comment
comment|/* file may have been extended */
end_comment

begin_define
define|#
directive|define
name|POLLATTRIB
value|0x0400
end_define

begin_comment
comment|/* file attributes may have changed */
end_comment

begin_define
define|#
directive|define
name|POLLNLINK
value|0x0800
end_define

begin_comment
comment|/* (un)link/rename may have happened */
end_comment

begin_define
define|#
directive|define
name|POLLWRITE
value|0x1000
end_define

begin_comment
comment|/* file's contents may have changed */
end_comment

begin_comment
comment|/*  * These events are set if they occur regardless of whether they were  * requested.  */
end_comment

begin_define
define|#
directive|define
name|POLLERR
value|0x0008
end_define

begin_comment
comment|/* some poll error occurred */
end_comment

begin_define
define|#
directive|define
name|POLLHUP
value|0x0010
end_define

begin_comment
comment|/* file descriptor was "hung up" */
end_comment

begin_define
define|#
directive|define
name|POLLNVAL
value|0x0020
end_define

begin_comment
comment|/* requested events "invalid" */
end_comment

begin_define
define|#
directive|define
name|POLLSTANDARD
value|(POLLIN|POLLPRI|POLLOUT|POLLRDNORM|POLLRDBAND|\ 			 POLLWRBAND|POLLERR|POLLHUP|POLLNVAL)
end_define

begin_comment
comment|/*  * Request that poll() wait forever.  * XXX in SYSV, this is defined in stropts.h, which is not included  * by poll.h.  */
end_comment

begin_define
define|#
directive|define
name|INFTIM
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
comment|/*  * XXX logically, poll() should be declared in<poll.h>, but SVR4 at  * least has it here in<sys/poll.h>.  * XXX poll() has "unsigned long" nfds on SVR4, not unsigned as on the  * other BSDs.  */
name|int
name|poll
name|__P
argument_list|(
operator|(
expr|struct
name|pollfd
operator|*
name|_pfd
operator|,
name|unsigned
name|_nfds
operator|,
name|int
name|_timeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_POLL_H_ */
end_comment

end_unit

