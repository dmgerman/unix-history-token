begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2004 Niels Provos<provos@citi.umich.edu>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVENT_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_EVENT_INTERNAL_H_
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
struct|struct
name|event_base
block|{
specifier|const
name|struct
name|eventop
modifier|*
name|evsel
decl_stmt|;
name|void
modifier|*
name|evbase
decl_stmt|;
name|int
name|event_count
decl_stmt|;
comment|/* counts number of total events */
name|int
name|event_count_active
decl_stmt|;
comment|/* counts number of active events */
name|int
name|event_gotterm
decl_stmt|;
comment|/* Set to terminate loop */
comment|/* active event management */
name|struct
name|event_list
modifier|*
modifier|*
name|activequeues
decl_stmt|;
name|int
name|nactivequeues
decl_stmt|;
name|struct
name|event_list
name|eventqueue
decl_stmt|;
name|struct
name|timeval
name|event_tv
decl_stmt|;
name|RB_HEAD
argument_list|(
argument|event_tree
argument_list|,
argument|event
argument_list|)
name|timetree
expr_stmt|;
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
comment|/* _EVENT_INTERNAL_H_ */
end_comment

end_unit

