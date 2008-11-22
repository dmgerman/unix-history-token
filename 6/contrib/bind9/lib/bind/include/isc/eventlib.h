begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1995-1999 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* eventlib.h - exported interfaces for eventlib  * vix 09sep95 [initial]  *  * $Id: eventlib.h,v 1.1.2.1.4.3 2008/01/23 02:08:48 marka Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVENTLIB_H
end_ifndef

begin_define
define|#
directive|define
name|_EVENTLIB_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__EVENTLIB_P_DEFINED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In the absence of branded types... */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evConnID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evFileID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evStreamID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evTimerID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evWaitID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evContext
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|evEvent
typedef|;
end_typedef

begin_define
define|#
directive|define
name|evInitID
parameter_list|(
name|id
parameter_list|)
value|((id)->opaque = NULL)
end_define

begin_define
define|#
directive|define
name|evTestID
parameter_list|(
name|id
parameter_list|)
value|((id).opaque != NULL)
end_define

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*evConnFunc
argument_list|)
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*evFileFunc
argument_list|)
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*evStreamFunc
argument_list|)
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|void
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*evTimerFunc
argument_list|)
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|void
operator|*
operator|,
expr|struct
name|timespec
operator|,
expr|struct
name|timespec
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*evWaitFunc
argument_list|)
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|mask
index|[
literal|256
operator|/
literal|8
index|]
decl_stmt|;
block|}
name|evByteMask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EV_BYTEMASK_BYTE
parameter_list|(
name|b
parameter_list|)
value|((b) / 8)
end_define

begin_define
define|#
directive|define
name|EV_BYTEMASK_MASK
parameter_list|(
name|b
parameter_list|)
value|(1<< ((b) % 8))
end_define

begin_define
define|#
directive|define
name|EV_BYTEMASK_SET
parameter_list|(
name|bm
parameter_list|,
name|b
parameter_list|)
define|\
value|((bm).mask[EV_BYTEMASK_BYTE(b)] |= EV_BYTEMASK_MASK(b))
end_define

begin_define
define|#
directive|define
name|EV_BYTEMASK_CLR
parameter_list|(
name|bm
parameter_list|,
name|b
parameter_list|)
define|\
value|((bm).mask[EV_BYTEMASK_BYTE(b)]&= ~EV_BYTEMASK_MASK(b))
end_define

begin_define
define|#
directive|define
name|EV_BYTEMASK_TST
parameter_list|(
name|bm
parameter_list|,
name|b
parameter_list|)
define|\
value|((bm).mask[EV_BYTEMASK_BYTE(b)]& EV_BYTEMASK_MASK(b))
end_define

begin_define
define|#
directive|define
name|EV_POLL
value|1
end_define

begin_define
define|#
directive|define
name|EV_WAIT
value|2
end_define

begin_define
define|#
directive|define
name|EV_NULL
value|4
end_define

begin_define
define|#
directive|define
name|EV_READ
value|1
end_define

begin_define
define|#
directive|define
name|EV_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|EV_EXCEPT
value|4
end_define

begin_define
define|#
directive|define
name|EV_WASNONBLOCKING
value|8
end_define

begin_comment
comment|/* Internal library use. */
end_comment

begin_comment
comment|/* eventlib.c */
end_comment

begin_define
define|#
directive|define
name|evCreate
value|__evCreate
end_define

begin_define
define|#
directive|define
name|evSetDebug
value|__evSetDebug
end_define

begin_define
define|#
directive|define
name|evDestroy
value|__evDestroy
end_define

begin_define
define|#
directive|define
name|evGetNext
value|__evGetNext
end_define

begin_define
define|#
directive|define
name|evDispatch
value|__evDispatch
end_define

begin_define
define|#
directive|define
name|evDrop
value|__evDrop
end_define

begin_define
define|#
directive|define
name|evMainLoop
value|__evMainLoop
end_define

begin_define
define|#
directive|define
name|evHighestFD
value|__evHighestFD
end_define

begin_define
define|#
directive|define
name|evGetOption
value|__evGetOption
end_define

begin_define
define|#
directive|define
name|evSetOption
value|__evSetOption
end_define

begin_decl_stmt
name|int
name|evCreate
name|__P
argument_list|(
operator|(
name|evContext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|evSetDebug
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evDestroy
name|__P
argument_list|(
operator|(
name|evContext
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evGetNext
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evEvent
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evDispatch
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evEvent
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|evDrop
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evEvent
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evMainLoop
name|__P
argument_list|(
operator|(
name|evContext
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evHighestFD
name|__P
argument_list|(
operator|(
name|evContext
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evGetOption
name|__P
argument_list|(
operator|(
name|evContext
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evSetOption
name|__P
argument_list|(
operator|(
name|evContext
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ev_connects.c */
end_comment

begin_define
define|#
directive|define
name|evListen
value|__evListen
end_define

begin_define
define|#
directive|define
name|evConnect
value|__evConnect
end_define

begin_define
define|#
directive|define
name|evCancelConn
value|__evCancelConn
end_define

begin_define
define|#
directive|define
name|evHold
value|__evHold
end_define

begin_define
define|#
directive|define
name|evUnhold
value|__evUnhold
end_define

begin_define
define|#
directive|define
name|evTryAccept
value|__evTryAccept
end_define

begin_decl_stmt
name|int
name|evListen
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|int
operator|,
name|int
operator|,
name|evConnFunc
operator|,
name|void
operator|*
operator|,
name|evConnID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evConnect
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
name|evConnFunc
operator|,
name|void
operator|*
operator|,
name|evConnID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evCancelConn
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evConnID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evHold
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evConnID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evUnhold
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evConnID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evTryAccept
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evConnID
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ev_files.c */
end_comment

begin_define
define|#
directive|define
name|evSelectFD
value|__evSelectFD
end_define

begin_define
define|#
directive|define
name|evDeselectFD
value|__evDeselectFD
end_define

begin_decl_stmt
name|int
name|evSelectFD
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|int
operator|,
name|int
operator|,
name|evFileFunc
operator|,
name|void
operator|*
operator|,
name|evFileID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evDeselectFD
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evFileID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ev_streams.c */
end_comment

begin_define
define|#
directive|define
name|evConsIovec
value|__evConsIovec
end_define

begin_define
define|#
directive|define
name|evWrite
value|__evWrite
end_define

begin_define
define|#
directive|define
name|evRead
value|__evRead
end_define

begin_define
define|#
directive|define
name|evTimeRW
value|__evTimeRW
end_define

begin_define
define|#
directive|define
name|evUntimeRW
value|__evUntimeRW
end_define

begin_define
define|#
directive|define
name|evCancelRW
value|__evCancelRW
end_define

begin_decl_stmt
name|struct
name|iovec
name|evConsIovec
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evWrite
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|int
operator|,
specifier|const
expr|struct
name|iovec
operator|*
operator|,
name|int
operator|,
name|evStreamFunc
name|func
operator|,
name|void
operator|*
operator|,
name|evStreamID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evRead
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|int
operator|,
specifier|const
expr|struct
name|iovec
operator|*
operator|,
name|int
operator|,
name|evStreamFunc
name|func
operator|,
name|void
operator|*
operator|,
name|evStreamID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evTimeRW
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evStreamID
operator|,
name|evTimerID
name|timer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evUntimeRW
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evStreamID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evCancelRW
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evStreamID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ev_timers.c */
end_comment

begin_define
define|#
directive|define
name|evConsTime
value|__evConsTime
end_define

begin_define
define|#
directive|define
name|evAddTime
value|__evAddTime
end_define

begin_define
define|#
directive|define
name|evSubTime
value|__evSubTime
end_define

begin_define
define|#
directive|define
name|evCmpTime
value|__evCmpTime
end_define

begin_define
define|#
directive|define
name|evTimeSpec
value|__evTimeSpec
end_define

begin_define
define|#
directive|define
name|evTimeVal
value|__evTimeVal
end_define

begin_define
define|#
directive|define
name|evNowTime
value|__evNowTime
end_define

begin_define
define|#
directive|define
name|evUTCTime
value|__evUTCTime
end_define

begin_define
define|#
directive|define
name|evLastEventTime
value|__evLastEventTime
end_define

begin_define
define|#
directive|define
name|evSetTimer
value|__evSetTimer
end_define

begin_define
define|#
directive|define
name|evClearTimer
value|__evClearTimer
end_define

begin_define
define|#
directive|define
name|evConfigTimer
value|__evConfigTimer
end_define

begin_define
define|#
directive|define
name|evResetTimer
value|__evResetTimer
end_define

begin_define
define|#
directive|define
name|evSetIdleTimer
value|__evSetIdleTimer
end_define

begin_define
define|#
directive|define
name|evClearIdleTimer
value|__evClearIdleTimer
end_define

begin_define
define|#
directive|define
name|evResetIdleTimer
value|__evResetIdleTimer
end_define

begin_define
define|#
directive|define
name|evTouchIdleTimer
value|__evTouchIdleTimer
end_define

begin_decl_stmt
name|struct
name|timespec
name|evConsTime
name|__P
argument_list|(
operator|(
name|time_t
name|sec
operator|,
name|long
name|nsec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|evAddTime
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|,
expr|struct
name|timespec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|evSubTime
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|,
expr|struct
name|timespec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|evNowTime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|evUTCTime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|evLastEventTime
name|__P
argument_list|(
operator|(
name|evContext
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timespec
name|evTimeSpec
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|evTimeVal
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evCmpTime
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|,
expr|struct
name|timespec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evSetTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerFunc
operator|,
name|void
operator|*
operator|,
expr|struct
name|timespec
operator|,
expr|struct
name|timespec
operator|,
name|evTimerID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evClearTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evConfigTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerID
operator|,
specifier|const
name|char
operator|*
name|param
operator|,
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evResetTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerID
operator|,
name|evTimerFunc
operator|,
name|void
operator|*
operator|,
expr|struct
name|timespec
operator|,
expr|struct
name|timespec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evSetIdleTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerFunc
operator|,
name|void
operator|*
operator|,
expr|struct
name|timespec
operator|,
name|evTimerID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evClearIdleTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evResetIdleTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerID
operator|,
name|evTimerFunc
operator|,
name|void
operator|*
operator|,
expr|struct
name|timespec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evTouchIdleTimer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evTimerID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ev_waits.c */
end_comment

begin_define
define|#
directive|define
name|evWaitFor
value|__evWaitFor
end_define

begin_define
define|#
directive|define
name|evDo
value|__evDo
end_define

begin_define
define|#
directive|define
name|evUnwait
value|__evUnwait
end_define

begin_define
define|#
directive|define
name|evDefer
value|__evDefer
end_define

begin_decl_stmt
name|int
name|evWaitFor
name|__P
argument_list|(
operator|(
name|evContext
operator|,
specifier|const
name|void
operator|*
operator|,
name|evWaitFunc
operator|,
name|void
operator|*
operator|,
name|evWaitID
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evDo
name|__P
argument_list|(
operator|(
name|evContext
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evUnwait
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evWaitID
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|evDefer
name|__P
argument_list|(
operator|(
name|evContext
operator|,
name|evWaitFunc
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__EVENTLIB_P_DEFINED
end_ifdef

begin_undef
undef|#
directive|undef
name|__P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_EVENTLIB_H*/
end_comment

end_unit

