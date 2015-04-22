begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EPOLLTABLE_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EPOLLTABLE_INTERNAL_H_INCLUDED_
end_define

begin_comment
comment|/*   Here are the values we're masking off to decide what operations to do.   Note that since EV_READ|EV_WRITE.    Note also that this table is a little sparse, since ADD+DEL is   nonsensical ("xxx" in the list below.)    Note also also that we are shifting old_events by only 5 bits, since   EV_READ is 2 and EV_WRITE is 4.    The table was auto-generated with a python script, according to this   pseudocode:[*0]        If either the read or the write change is add+del: 	 This is impossible; Set op==-1, events=0.       Else, if either the read or the write change is add: 	 Set events to 0. 	 If the read change is add, or 	    (the read change is not del, and ev_read is in old_events): 	       Add EPOLLIN to events. 	 If the write change is add, or 	    (the write change is not del, and ev_write is in old_events): 	       Add EPOLLOUT to events.  	 If old_events is set: 	       Set op to EPOLL_CTL_MOD [*1,*2] 	Else: 	       Set op to EPOLL_CTL_ADD [*3]        Else, if the read or the write change is del: 	 Set op to EPOLL_CTL_DEL. 	 If the read change is del: 	     If the write change is del: 		 Set events to EPOLLIN|EPOLLOUT 	     Else if ev_write is in old_events: 		 Set events to EPOLLOUT 		Set op to EPOLL_CTL_MOD 	     Else 		 Set events to EPOLLIN 	 Else: 	     {The write change is del.} 	    If ev_read is in old_events: 		 Set events to EPOLLIN 		Set op to EPOLL_CTL_MOD 	    Else: 		Set the events to EPOLLOUT        Else: 	   There is no read or write change; set op to 0 and events to 0.        The logic is a little tricky, since we had no events set on the fd before,       we need to set op="ADD" and set events=the events we want to add.	 If we       had any events set on the fd before, and we want any events to remain on       the fd, we need to say op="MOD" and set events=the events we want to       remain.  But if we want to delete the last event, we say op="DEL" and       set events=(any non-null pointer).    [*0] Actually, the Python script has gotten a bit more complicated, to        support EPOLLRDHUP.    [*1] This MOD is only a guess.  MOD might fail with ENOENT if the file was        closed and a new file was opened with the same fd.  If so, we'll retry        with ADD.    [*2] We can't replace this with a no-op even if old_events is the same as        the new events: if the file was closed and reopened, we need to retry        with an ADD.  (We do a MOD in this case since "no change" is more        common than "close and reopen", so we'll usually wind up doing 1        syscalls instead of 2.)    [*3] This ADD is only a guess.  There is a fun Linux kernel issue where if        you have two fds for the same file (via dup) and you ADD one to an        epfd, then close it, then re-create it with the same fd (via dup2 or an        unlucky dup), then try to ADD it again, you'll get an EEXIST, since the        struct epitem is not actually removed from the struct eventpoll until        the file itself is closed.    EV_CHANGE_ADD==1   EV_CHANGE_DEL==2   EV_READ      ==2   EV_WRITE     ==4   EV_CLOSED    ==0x80    Bit 0: close change is add   Bit 1: close change is del   Bit 2: read change is add   Bit 3: read change is del   Bit 4: write change is add   Bit 5: write change is del   Bit 6: old events had EV_READ   Bit 7: old events had EV_WRITE   Bit 8: old events had EV_CLOSED */
end_comment

begin_define
define|#
directive|define
name|EPOLL_OP_TABLE_INDEX
parameter_list|(
name|c
parameter_list|)
define|\
value|(   (((c)->close_change&(EV_CHANGE_ADD|EV_CHANGE_DEL))) |		\ 	    (((c)->read_change&(EV_CHANGE_ADD|EV_CHANGE_DEL))<< 2) |	\ 	    (((c)->write_change&(EV_CHANGE_ADD|EV_CHANGE_DEL))<< 4) |	\ 	    (((c)->old_events&(EV_READ|EV_WRITE))<< 5) |		\ 	    (((c)->old_events&(EV_CLOSED))<< 1)				\ 	    )
end_define

begin_if
if|#
directive|if
name|EV_READ
operator|!=
literal|2
operator|||
name|EV_WRITE
operator|!=
literal|4
operator|||
name|EV_CLOSED
operator|!=
literal|0x80
operator|||
name|EV_CHANGE_ADD
operator|!=
literal|1
operator|||
name|EV_CHANGE_DEL
operator|!=
literal|2
end_if

begin_error
error|#
directive|error
literal|"Libevent's internals changed!  Regenerate the op_table in epolltable-internal.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct
specifier|static
specifier|const
struct|struct
name|operation
block|{
name|int
name|events
decl_stmt|;
name|int
name|op
decl_stmt|;
block|}
name|epoll_op_table
index|[]
init|=
block|{
comment|/* old=  0, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old=  0, write:  0, read:  0, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:  0, read:  0, close:del */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:  0, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:  0, read:del, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:  0, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:  0, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:  0, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:  0, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:  0, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:  0, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:del, read:  0, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:del, read:  0, close:del */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:del, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_ADD
block|}
block|,
comment|/* old=  0, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  0, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  0, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old=  r, write:  0, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:  0, read:  0, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:  0, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:del, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  r, write:  0, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:  0, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  r, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:  0, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:  0, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:  0, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:  0, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:del, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  r, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  r, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  r, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  r, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old=  w, write:  0, read:  0, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:  0, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:del, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:  0, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:  0, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:  0, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:  0, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  w, write:del, read:  0, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:del, read:  0, close:del */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  w, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:del, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  w, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  w, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  w, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  w, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old= rw, write:  0, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:  0, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:del, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:  0, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:  0, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:  0, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:  0, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:del, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old= rw, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= rw, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old= rw, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= rw, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old=  c, write:  0, read:  0, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:  0, read:  0, close:del */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  c, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:  0, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:del, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:  0, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:  0, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  c, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:  0, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:  0, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:  0, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:  0, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:  0, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:  0, close:del */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  c, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:del, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=  c, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=  c, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=  c, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old= cr, write:  0, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:  0, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:del, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:  0, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old= cr, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:  0, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:  0, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:  0, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:  0, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:del, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cr, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old= cr, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cr, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old= cw, write:  0, read:  0, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:  0, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:del, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:  0, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:  0, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:  0, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:  0, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:  0, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:  0, close:del */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old= cw, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:del, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old= cw, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old= cw, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old= cw, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:  0, close:  0 */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* old=crw, write:  0, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:  0, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:del, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:  0, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:  0, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:  0, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:  0, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:add, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:del, close:  0 */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:del, close:add */
block|{
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:del, close:del */
block|{
name|EPOLLOUT
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:add, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:add, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:  0, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:  0, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:  0, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:add, close:  0 */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:add, close:add */
block|{
name|EPOLLIN
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:add, close:del */
block|{
name|EPOLLIN
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:del, close:  0 */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:del, close:add */
block|{
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_MOD
block|}
block|,
comment|/* old=crw, write:del, read:del, close:del */
block|{
name|EPOLLIN
operator||
name|EPOLLOUT
operator||
name|EPOLLRDHUP
block|,
name|EPOLL_CTL_DEL
block|}
block|,
comment|/* old=crw, write:del, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:del, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:  0, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:  0, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:  0, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:  0, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:add, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:add, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:add, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:add, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:del, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:del, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:del, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:del, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:xxx, close:  0 */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:xxx, close:add */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:xxx, close:del */
block|{
literal|0
block|,
literal|255
block|}
block|,
comment|/* old=crw, write:xxx, read:xxx, close:xxx */
block|{
literal|0
block|,
literal|255
block|}
block|, }
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

