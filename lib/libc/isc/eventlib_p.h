begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1995-1999 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* eventlib_p.h - private interfaces for eventlib  * vix 09sep95 [initial]  *  * $Id: eventlib_p.h,v 1.3.2.1.4.4 2006/03/10 00:17:21 marka Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVENTLIB_P_H
end_ifndef

begin_define
define|#
directive|define
name|_EVENTLIB_P_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_define
define|#
directive|define
name|EVENTLIB_DEBUG
value|1
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_include
include|#
directive|include
file|<isc/list.h>
end_include

begin_include
include|#
directive|include
file|<isc/heap.h>
end_include

begin_include
include|#
directive|include
file|<isc/memcluster.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EV_MASK_ALL
value|(EV_READ | EV_WRITE | EV_EXCEPT)
end_define

begin_define
define|#
directive|define
name|EV_ERR
parameter_list|(
name|e
parameter_list|)
value|return (errno = (e), -1)
end_define

begin_define
define|#
directive|define
name|OK
parameter_list|(
name|x
parameter_list|)
value|if ((x)< 0) EV_ERR(errno); else (void)NULL
end_define

begin_define
define|#
directive|define
name|OKFREE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if ((x)< 0) { FREE((y)); EV_ERR(errno); } \ 			else (void)NULL
end_define

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|p
parameter_list|)
value|if (((p) = memget(sizeof *(p))) != NULL) \ 				FILL(p); \ 			else \ 				(void)NULL;
end_define

begin_define
define|#
directive|define
name|OKNEW
parameter_list|(
name|p
parameter_list|)
value|if (!((p) = memget(sizeof *(p)))) { \ 				errno = ENOMEM; \ 				return (-1); \ 			} else \ 				FILL(p)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|p
parameter_list|)
value|memput((p), sizeof *(p))
end_define

begin_if
if|#
directive|if
name|EVENTLIB_DEBUG
end_if

begin_define
define|#
directive|define
name|FILL
parameter_list|(
name|p
parameter_list|)
value|memset((p), 0xF5, sizeof *(p))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FILL
parameter_list|(
name|p
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_POLL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STROPTS_H
end_ifdef

begin_include
include|#
directive|include
file|<stropts.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_POLL */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|evConn
block|{
name|evConnFunc
name|func
decl_stmt|;
name|void
modifier|*
name|uap
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|EV_CONN_LISTEN
value|0x0001
comment|/* Connection is a listener. */
define|#
directive|define
name|EV_CONN_SELECTED
value|0x0002
comment|/* evSelectFD(conn->file). */
define|#
directive|define
name|EV_CONN_BLOCK
value|0x0004
comment|/* Listener fd was blocking. */
name|evFileID
name|file
decl_stmt|;
name|struct
name|evConn
modifier|*
name|prev
decl_stmt|;
name|struct
name|evConn
modifier|*
name|next
decl_stmt|;
block|}
name|evConn
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|evAccept
block|{
name|int
name|fd
decl_stmt|;
union|union
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|in
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_SOCKADDR_UN
name|struct
name|sockaddr_un
name|un
decl_stmt|;
endif|#
directive|endif
block|}
name|la
union|;
name|ISC_SOCKLEN_T
name|lalen
decl_stmt|;
union|union
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|in
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_SOCKADDR_UN
name|struct
name|sockaddr_un
name|un
decl_stmt|;
endif|#
directive|endif
block|}
name|ra
union|;
name|ISC_SOCKLEN_T
name|ralen
decl_stmt|;
name|int
name|ioErrno
decl_stmt|;
name|evConn
modifier|*
name|conn
decl_stmt|;
name|LINK
argument_list|(
argument|struct evAccept
argument_list|)
name|link
expr_stmt|;
block|}
name|evAccept
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|evFile
block|{
name|evFileFunc
name|func
decl_stmt|;
name|void
modifier|*
name|uap
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int
name|eventmask
decl_stmt|;
name|int
name|preemptive
decl_stmt|;
name|struct
name|evFile
modifier|*
name|prev
decl_stmt|;
name|struct
name|evFile
modifier|*
name|next
decl_stmt|;
name|struct
name|evFile
modifier|*
name|fdprev
decl_stmt|;
name|struct
name|evFile
modifier|*
name|fdnext
decl_stmt|;
block|}
name|evFile
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|evStream
block|{
name|evStreamFunc
name|func
decl_stmt|;
name|void
modifier|*
name|uap
decl_stmt|;
name|evFileID
name|file
decl_stmt|;
name|evTimerID
name|timer
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|EV_STR_TIMEROK
value|0x0001
comment|/* IFF timer valid. */
name|int
name|fd
decl_stmt|;
name|struct
name|iovec
modifier|*
name|iovOrig
decl_stmt|;
name|int
name|iovOrigCount
decl_stmt|;
name|struct
name|iovec
modifier|*
name|iovCur
decl_stmt|;
name|int
name|iovCurCount
decl_stmt|;
name|int
name|ioTotal
decl_stmt|;
name|int
name|ioDone
decl_stmt|;
name|int
name|ioErrno
decl_stmt|;
name|struct
name|evStream
modifier|*
name|prevDone
decl_stmt|,
modifier|*
name|nextDone
decl_stmt|;
name|struct
name|evStream
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
block|}
name|evStream
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|evTimer
block|{
name|evTimerFunc
name|func
decl_stmt|;
name|void
modifier|*
name|uap
decl_stmt|;
name|struct
name|timespec
name|due
decl_stmt|,
name|inter
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|mode
decl_stmt|;
define|#
directive|define
name|EV_TMR_RATE
value|1
block|}
name|evTimer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|evWait
block|{
name|evWaitFunc
name|func
decl_stmt|;
name|void
modifier|*
name|uap
decl_stmt|;
specifier|const
name|void
modifier|*
name|tag
decl_stmt|;
name|struct
name|evWait
modifier|*
name|next
decl_stmt|;
block|}
name|evWait
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|evWaitList
block|{
name|evWait
modifier|*
name|first
decl_stmt|;
name|evWait
modifier|*
name|last
decl_stmt|;
name|struct
name|evWaitList
modifier|*
name|prev
decl_stmt|;
name|struct
name|evWaitList
modifier|*
name|next
decl_stmt|;
block|}
name|evWaitList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|evEvent_p
block|{
enum|enum
block|{
name|Accept
block|,
name|File
block|,
name|Stream
block|,
name|Timer
block|,
name|Wait
block|,
name|Free
block|,
name|Null
block|}
name|type
enum|;
union|union
block|{
struct|struct
block|{
name|evAccept
modifier|*
name|this
decl_stmt|;
block|}
name|accept
struct|;
struct|struct
block|{
name|evFile
modifier|*
name|this
decl_stmt|;
name|int
name|eventmask
decl_stmt|;
block|}
name|file
struct|;
struct|struct
block|{
name|evStream
modifier|*
name|this
decl_stmt|;
block|}
name|stream
struct|;
struct|struct
block|{
name|evTimer
modifier|*
name|this
decl_stmt|;
block|}
name|timer
struct|;
struct|struct
block|{
name|evWait
modifier|*
name|this
decl_stmt|;
block|}
name|wait
struct|;
struct|struct
block|{
name|struct
name|evEvent_p
modifier|*
name|next
decl_stmt|;
block|}
name|free
struct|;
struct|struct
block|{
specifier|const
name|void
modifier|*
name|placeholder
decl_stmt|;
block|}
name|null
struct|;
block|}
name|u
union|;
block|}
name|evEvent_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_POLL
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
comment|/* pointer to the evContext_p   */
name|uint32_t
name|type
decl_stmt|;
comment|/* READ, WRITE, EXCEPT, nonblk  */
name|uint32_t
name|result
decl_stmt|;
comment|/* 1 => revents, 0 => events    */
block|}
name|__evEmulMask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|emulMaskInit
parameter_list|(
name|ctx
parameter_list|,
name|field
parameter_list|,
name|ev
parameter_list|,
name|lastnext
parameter_list|)
define|\
value|ctx->field.ctx = ctx; \ 	ctx->field.type = ev; \ 	ctx->field.result = lastnext;
end_define

begin_function_decl
specifier|extern
name|short
modifier|*
name|__fd_eventfield
parameter_list|(
name|int
name|fd
parameter_list|,
name|__evEmulMask
modifier|*
name|maskp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|__poll_event
parameter_list|(
name|__evEmulMask
modifier|*
name|maskp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__fd_clr
parameter_list|(
name|int
name|fd
parameter_list|,
name|__evEmulMask
modifier|*
name|maskp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__fd_set
parameter_list|(
name|int
name|fd
parameter_list|,
name|__evEmulMask
modifier|*
name|maskp
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|FD_ZERO
end_undef

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|maskp
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|FD_SET
end_undef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|fd
parameter_list|,
name|maskp
parameter_list|)
define|\
value|__fd_set(fd, maskp)
end_define

begin_undef
undef|#
directive|undef
name|FD_CLR
end_undef

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|fd
parameter_list|,
name|maskp
parameter_list|)
define|\
value|__fd_clr(fd, maskp)
end_define

begin_undef
undef|#
directive|undef
name|FD_ISSET
end_undef

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|fd
parameter_list|,
name|maskp
parameter_list|)
define|\
value|((*__fd_eventfield(fd, maskp)& __poll_event(maskp)) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_POLL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Global. */
specifier|const
name|evEvent_p
modifier|*
name|cur
decl_stmt|;
comment|/* Debugging. */
name|int
name|debug
decl_stmt|;
name|FILE
modifier|*
name|output
decl_stmt|;
comment|/* Connections. */
name|evConn
modifier|*
name|conns
decl_stmt|;
name|LIST
argument_list|(
argument|evAccept
argument_list|)
name|accepts
expr_stmt|;
comment|/* Files. */
name|evFile
modifier|*
name|files
decl_stmt|,
modifier|*
name|fdNext
decl_stmt|;
ifndef|#
directive|ifndef
name|USE_POLL
name|fd_set
name|rdLast
decl_stmt|,
name|rdNext
decl_stmt|;
name|fd_set
name|wrLast
decl_stmt|,
name|wrNext
decl_stmt|;
name|fd_set
name|exLast
decl_stmt|,
name|exNext
decl_stmt|;
name|fd_set
name|nonblockBefore
decl_stmt|;
name|int
name|fdMax
decl_stmt|,
name|fdCount
decl_stmt|,
name|highestFD
decl_stmt|;
name|evFile
modifier|*
name|fdTable
index|[
name|FD_SETSIZE
index|]
decl_stmt|;
else|#
directive|else
name|struct
name|pollfd
modifier|*
name|pollfds
decl_stmt|;
comment|/* Allocated as needed  */
name|evFile
modifier|*
modifier|*
name|fdTable
decl_stmt|;
comment|/* Ditto                */
name|int
name|maxnfds
decl_stmt|;
comment|/* # elements in above  */
name|int
name|firstfd
decl_stmt|;
comment|/* First active fd      */
name|int
name|fdMax
decl_stmt|;
comment|/* Last active fd       */
name|int
name|fdCount
decl_stmt|;
comment|/* # fd:s with I/O      */
name|int
name|highestFD
decl_stmt|;
comment|/* max fd allowed by OS */
name|__evEmulMask
name|rdLast
decl_stmt|,
name|rdNext
decl_stmt|;
name|__evEmulMask
name|wrLast
decl_stmt|,
name|wrNext
decl_stmt|;
name|__evEmulMask
name|exLast
decl_stmt|,
name|exNext
decl_stmt|;
name|__evEmulMask
name|nonblockBefore
decl_stmt|;
endif|#
directive|endif
comment|/* USE_POLL */
ifdef|#
directive|ifdef
name|EVENTLIB_TIME_CHECKS
name|struct
name|timespec
name|lastSelectTime
decl_stmt|;
name|int
name|lastFdCount
decl_stmt|;
endif|#
directive|endif
comment|/* Streams. */
name|evStream
modifier|*
name|streams
decl_stmt|;
name|evStream
modifier|*
name|strDone
decl_stmt|,
modifier|*
name|strLast
decl_stmt|;
comment|/* Timers. */
name|struct
name|timespec
name|lastEventTime
decl_stmt|;
name|heap_context
name|timers
decl_stmt|;
comment|/* Waits. */
name|evWaitList
modifier|*
name|waitLists
decl_stmt|;
name|evWaitList
name|waitDone
decl_stmt|;
block|}
name|evContext_p
typedef|;
end_typedef

begin_comment
comment|/* eventlib.c */
end_comment

begin_define
define|#
directive|define
name|evPrintf
value|__evPrintf
end_define

begin_function_decl
name|void
name|evPrintf
parameter_list|(
specifier|const
name|evContext_p
modifier|*
name|ctx
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_POLL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|evPollfdRealloc
parameter_list|(
name|evContext_p
modifier|*
name|ctx
parameter_list|,
name|int
name|pollfd_chunk_size
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_POLL */
end_comment

begin_comment
comment|/* ev_timers.c */
end_comment

begin_define
define|#
directive|define
name|evCreateTimers
value|__evCreateTimers
end_define

begin_function_decl
name|heap_context
name|evCreateTimers
parameter_list|(
specifier|const
name|evContext_p
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|evDestroyTimers
value|__evDestroyTimers
end_define

begin_function_decl
name|void
name|evDestroyTimers
parameter_list|(
specifier|const
name|evContext_p
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ev_waits.c */
end_comment

begin_define
define|#
directive|define
name|evFreeWait
value|__evFreeWait
end_define

begin_function_decl
name|evWait
modifier|*
name|evFreeWait
parameter_list|(
name|evContext_p
modifier|*
name|ctx
parameter_list|,
name|evWait
modifier|*
name|old
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Global options */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|__evOptMonoTime
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_EVENTLIB_P_H*/
end_comment

end_unit

