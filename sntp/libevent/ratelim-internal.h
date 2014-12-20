begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RATELIM_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|RATELIM_INTERNAL_H_INCLUDED_
end_define

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
file|"event2/util.h"
comment|/** A token bucket is an internal structure that tracks how many bytes we are  * currently willing to read or write on a given bufferevent or group of  * bufferevents */
struct|struct
name|ev_token_bucket
block|{
comment|/** How many bytes are we willing to read or write right now? These 	 * values are signed so that we can do "defecit spending" */
name|ev_ssize_t
name|read_limit
decl_stmt|,
name|write_limit
decl_stmt|;
comment|/** When was this bucket last updated?  Measured in abstract 'ticks' 	 * relative to the token bucket configuration. */
name|ev_uint32_t
name|last_updated
decl_stmt|;
block|}
struct|;
comment|/** Configuration info for a token bucket or set of token buckets. */
struct|struct
name|ev_token_bucket_cfg
block|{
comment|/** How many bytes are we willing to read on average per tick? */
name|size_t
name|read_rate
decl_stmt|;
comment|/** How many bytes are we willing to read at most in any one tick? */
name|size_t
name|read_maximum
decl_stmt|;
comment|/** How many bytes are we willing to write on average per tick? */
name|size_t
name|write_rate
decl_stmt|;
comment|/** How many bytes are we willing to write at most in any one tick? */
name|size_t
name|write_maximum
decl_stmt|;
comment|/* How long is a tick?  Note that fractions of a millisecond are 	 * ignored. */
name|struct
name|timeval
name|tick_timeout
decl_stmt|;
comment|/* How long is a tick, in milliseconds?  Derived from tick_timeout. */
name|unsigned
name|msec_per_tick
decl_stmt|;
block|}
struct|;
comment|/** The current tick is 'current_tick': add bytes to 'bucket' as specified in  * 'cfg'. */
name|int
name|ev_token_bucket_update_
parameter_list|(
name|struct
name|ev_token_bucket
modifier|*
name|bucket
parameter_list|,
specifier|const
name|struct
name|ev_token_bucket_cfg
modifier|*
name|cfg
parameter_list|,
name|ev_uint32_t
name|current_tick
parameter_list|)
function_decl|;
comment|/** In which tick does 'tv' fall according to 'cfg'?  Note that ticks can  * overflow easily; your code needs to handle this. */
name|ev_uint32_t
name|ev_token_bucket_get_tick_
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
specifier|const
name|struct
name|ev_token_bucket_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
comment|/** Adjust 'bucket' to respect 'cfg', and note that it was last updated in  * 'current_tick'.  If 'reinitialize' is true, we are changing the  * configuration of 'bucket'; otherwise, we are setting it up for the first  * time.  */
name|int
name|ev_token_bucket_init_
parameter_list|(
name|struct
name|ev_token_bucket
modifier|*
name|bucket
parameter_list|,
specifier|const
name|struct
name|ev_token_bucket_cfg
modifier|*
name|cfg
parameter_list|,
name|ev_uint32_t
name|current_tick
parameter_list|,
name|int
name|reinitialize
parameter_list|)
function_decl|;
name|int
name|bufferevent_remove_from_rate_limit_group_internal_
parameter_list|(
name|struct
name|bufferevent
modifier|*
name|bev
parameter_list|,
name|int
name|unsuspend
parameter_list|)
function_decl|;
comment|/** Decrease the read limit of 'b' by 'n' bytes */
define|#
directive|define
name|ev_token_bucket_decrement_read
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
define|\
value|do {					\ 		(b)->read_limit -= (n);		\ 	} while (0)
comment|/** Decrease the write limit of 'b' by 'n' bytes */
define|#
directive|define
name|ev_token_bucket_decrement_write
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
define|\
value|do {					\ 		(b)->write_limit -= (n);	\ 	} while (0)
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

end_unit

