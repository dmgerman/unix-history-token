begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_KEYVALQ_STRUCT_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_KEYVALQ_STRUCT_H_INCLUDED_
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
comment|/* Fix so that people don't have to run with<sys/queue.h> */
comment|/* XXXX This code is duplicated with event_struct.h */
ifndef|#
directive|ifndef
name|TAILQ_ENTRY
define|#
directive|define
name|EVENT_DEFINED_TQENTRY_
define|#
directive|define
name|TAILQ_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *tqe_next;
comment|/* next element */
value|\ 	struct type **tqe_prev;
comment|/* address of previous next element */
value|\ }
endif|#
directive|endif
comment|/* !TAILQ_ENTRY */
ifndef|#
directive|ifndef
name|TAILQ_HEAD
define|#
directive|define
name|EVENT_DEFINED_TQHEAD_
define|#
directive|define
name|TAILQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {					\ 	struct type *tqh_first;			\ 	struct type **tqh_last;			\ }
endif|#
directive|endif
comment|/*  * Key-Value pairs.  Can be used for HTTP headers but also for  * query argument parsing.  */
struct|struct
name|evkeyval
block|{
name|TAILQ_ENTRY
argument_list|(
argument|evkeyval
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
name|TAILQ_HEAD
argument_list|(
name|evkeyvalq
argument_list|,
name|evkeyval
argument_list|)
expr_stmt|;
comment|/* XXXX This code is duplicated with event_struct.h */
ifdef|#
directive|ifdef
name|EVENT_DEFINED_TQENTRY_
undef|#
directive|undef
name|TAILQ_ENTRY
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EVENT_DEFINED_TQHEAD_
undef|#
directive|undef
name|TAILQ_HEAD
endif|#
directive|endif
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

