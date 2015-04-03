begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_BUFFEREVENT_STRUCT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_BUFFEREVENT_STRUCT_H_INCLUDED_
end_define

begin_comment
comment|/** @file event2/bufferevent_struct.h    Data structures for bufferevents.  Using these structures may hurt forward   compatibility with later versions of Libevent: be careful!    @deprecated Use of bufferevent_struct.h is completely deprecated; these     structures are only exposed for backward compatibility with programs     written before Libevent 2.0 that used them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<event2/event-config.h>
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TYPES_H
include|#
directive|include
file|<sys/types.h>
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TIME_H
include|#
directive|include
file|<sys/time.h>
endif|#
directive|endif
comment|/* For int types. */
include|#
directive|include
file|<event2/util.h>
comment|/* For struct event */
include|#
directive|include
file|<event2/event_struct.h>
struct|struct
name|event_watermark
block|{
name|size_t
name|low
decl_stmt|;
name|size_t
name|high
decl_stmt|;
block|}
struct|;
comment|/**   Shared implementation of a bufferevent.    This type is exposed only because it was exposed in previous versions,   and some people's code may rely on manipulating it.  Otherwise, you   should really not rely on the layout, size, or contents of this structure:   it is fairly volatile, and WILL change in future versions of the code. **/
struct|struct
name|bufferevent
block|{
comment|/** Event base for which this bufferevent was created. */
name|struct
name|event_base
modifier|*
name|ev_base
decl_stmt|;
comment|/** Pointer to a table of function pointers to set up how this 	    bufferevent behaves. */
specifier|const
name|struct
name|bufferevent_ops
modifier|*
name|be_ops
decl_stmt|;
comment|/** A read event that triggers when a timeout has happened or a socket 	    is ready to read data.  Only used by some subtypes of 	    bufferevent. */
name|struct
name|event
name|ev_read
decl_stmt|;
comment|/** A write event that triggers when a timeout has happened or a socket 	    is ready to write data.  Only used by some subtypes of 	    bufferevent. */
name|struct
name|event
name|ev_write
decl_stmt|;
comment|/** An input buffer. Only the bufferevent is allowed to add data to 	    this buffer, though the user is allowed to drain it. */
name|struct
name|evbuffer
modifier|*
name|input
decl_stmt|;
comment|/** An input buffer. Only the bufferevent is allowed to drain data 	    from this buffer, though the user is allowed to add it. */
name|struct
name|evbuffer
modifier|*
name|output
decl_stmt|;
name|struct
name|event_watermark
name|wm_read
decl_stmt|;
name|struct
name|event_watermark
name|wm_write
decl_stmt|;
name|bufferevent_data_cb
name|readcb
decl_stmt|;
name|bufferevent_data_cb
name|writecb
decl_stmt|;
comment|/* This should be called 'eventcb', but renaming it would break 	 * backward compatibility */
name|bufferevent_event_cb
name|errorcb
decl_stmt|;
name|void
modifier|*
name|cbarg
decl_stmt|;
name|struct
name|timeval
name|timeout_read
decl_stmt|;
name|struct
name|timeval
name|timeout_write
decl_stmt|;
comment|/** Events that are currently enabled: currently EV_READ and EV_WRITE 	    are supported. */
name|short
name|enabled
decl_stmt|;
block|}
struct|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT2_BUFFEREVENT_STRUCT_H_INCLUDED_ */
end_comment

end_unit

