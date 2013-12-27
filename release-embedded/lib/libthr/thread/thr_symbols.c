begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 David Xu<davidxu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<rtld.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_comment
comment|/* A collection of symbols needed by debugger */
end_comment

begin_comment
comment|/* int _libthr_debug */
end_comment

begin_decl_stmt
name|int
name|_thread_off_tcb
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|tcb
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_tid
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|tid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_next
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|tle
operator|.
name|tqe_next
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_attr_flags
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|attr
operator|.
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_linkmap
init|=
name|offsetof
argument_list|(
name|Obj_Entry
argument_list|,
name|linkmap
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_tlsindex
init|=
name|offsetof
argument_list|(
name|Obj_Entry
argument_list|,
name|tlsindex
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_report_events
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|report_events
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_event_mask
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|event_mask
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_event_buf
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|event_buf
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_size_key
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|pthread_key
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_key_allocated
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread_key
argument_list|,
name|allocated
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_key_destructor
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread_key
argument_list|,
name|destructor
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_max_keys
init|=
name|PTHREAD_KEYS_MAX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_dtv
init|=
name|DTV_OFFSET
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_off_state
init|=
name|offsetof
argument_list|(
expr|struct
name|pthread
argument_list|,
name|state
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_state_running
init|=
name|PS_RUNNING
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_thread_state_zoombie
init|=
name|PS_DEAD
decl_stmt|;
end_decl_stmt

end_unit

