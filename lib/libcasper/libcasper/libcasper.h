begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2013 The FreeBSD Foundation  * Copyright (c) 2015-2017 Mariusz Zaborski<oshogbo@FreeBSD.org>  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCASPER_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBCASPER_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CASPER
end_ifdef

begin_define
define|#
directive|define
name|WITH_CASPER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_NVLIST_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_NVLIST_T_DECLARED
end_define

begin_struct_decl
struct_decl|struct
name|nvlist
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|nvlist
name|nvlist_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CAP_CHANNEL_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_CAP_CHANNEL_T_DECLARED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_struct_decl
struct_decl|struct
name|cap_channel
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|cap_channel
name|cap_channel_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|cap_channel
block|{
name|int
name|cch_fd
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cap_channel
name|cap_channel_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WITH_CASPER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _CAP_CHANNEL_T_DECLARED */
end_comment

begin_comment
comment|/*  * The functions opens unrestricted communication channel to Casper.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|cap_channel_t
modifier|*
name|cap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|cap_channel_t
modifier|*
name|cap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|cap_channel_t
modifier|*
name|chan
decl_stmt|;
name|chan
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|chan
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|chan
operator|!=
name|NULL
condition|)
block|{
name|chan
operator|->
name|cch_fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|chan
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The functions to communicate with service.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|cap_channel_t
modifier|*
name|cap_service_open
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cap_service_limit
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|names
parameter_list|,
name|size_t
name|nnames
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_service_open
parameter_list|(
name|chan
parameter_list|,
name|name
parameter_list|)
value|(cap_init())
end_define

begin_define
define|#
directive|define
name|cap_service_limit
parameter_list|(
name|chan
parameter_list|,
name|names
parameter_list|,
name|nnames
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function creates cap_channel_t based on the given socket.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|cap_channel_t
modifier|*
name|cap_wrap
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|cap_channel_t
modifier|*
name|cap_wrap
parameter_list|(
name|int
name|sock
parameter_list|)
block|{
name|cap_channel_t
modifier|*
name|chan
decl_stmt|;
name|chan
operator|=
name|cap_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|chan
operator|!=
name|NULL
condition|)
block|{
name|chan
operator|->
name|cch_fd
operator|=
name|sock
expr_stmt|;
block|}
return|return
operator|(
name|chan
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function returns communication socket and frees cap_channel_t.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|int
name|cap_unwrap
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_unwrap
parameter_list|(
name|chan
parameter_list|)
value|(chan->cch_fd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function clones the given capability.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|cap_channel_t
modifier|*
name|cap_clone
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|cap_channel_t
modifier|*
name|cap_clone
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
block|{
name|cap_channel_t
modifier|*
name|newchan
decl_stmt|;
name|newchan
operator|=
name|cap_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|newchan
operator|==
name|NULL
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|chan
operator|->
name|cch_fd
operator|==
operator|-
literal|1
condition|)
block|{
name|newchan
operator|->
name|cch_fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
name|newchan
operator|->
name|cch_fd
operator|=
name|dup
argument_list|(
name|chan
operator|->
name|cch_fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|newchan
operator|->
name|cch_fd
operator|<
literal|0
condition|)
block|{
name|free
argument_list|(
name|newchan
argument_list|)
expr_stmt|;
name|newchan
operator|=
name|NULL
expr_stmt|;
block|}
block|}
return|return
operator|(
name|newchan
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function closes the given capability.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|void
name|cap_close
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|void
name|cap_close
parameter_list|(
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
block|{
if|if
condition|(
name|chan
operator|->
name|cch_fd
operator|>=
literal|0
condition|)
block|{
name|close
argument_list|(
name|chan
operator|->
name|cch_fd
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|chan
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function returns socket descriptor associated with the given  * cap_channel_t for use with select(2)/kqueue(2)/etc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|int
name|cap_sock
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_sock
parameter_list|(
name|chan
parameter_list|)
value|(chan->cch_fd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function limits the given capability.  * It always destroys 'limits' on return.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|int
name|cap_limit_set
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|nvlist_t
modifier|*
name|limits
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_limit_set
parameter_list|(
name|chan
parameter_list|,
name|limits
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function returns current limits of the given capability.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|int
name|cap_limit_get
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|nvlist_t
modifier|*
modifier|*
name|limitsp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|int
name|cap_limit_get
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
name|__unused
parameter_list|,
name|nvlist_t
modifier|*
modifier|*
name|limitsp
parameter_list|)
block|{
operator|*
name|limitsp
operator|=
name|nvlist_create
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Function sends nvlist over the given capability.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|int
name|cap_send_nvlist
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
name|nvl
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_send_nvlist
parameter_list|(
name|chan
parameter_list|,
name|nvl
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Function receives nvlist over the given capability.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|nvlist_t
modifier|*
name|cap_recv_nvlist
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cap_recv_nvlist
parameter_list|(
name|chan
parameter_list|,
name|flags
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Function sends the given nvlist, destroys it and receives new nvlist in  * response over the given capability.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_CASPER
end_ifdef

begin_function_decl
name|nvlist_t
modifier|*
name|cap_xfer_nvlist
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
parameter_list|,
name|nvlist_t
modifier|*
name|nvl
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|nvlist_t
modifier|*
name|cap_xfer_nvlist
parameter_list|(
specifier|const
name|cap_channel_t
modifier|*
name|chan
name|__unused
parameter_list|,
name|nvlist_t
modifier|*
name|nvl
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|nvlist_destroy
argument_list|(
name|nvl
argument_list|)
expr_stmt|;
return|return
operator|(
name|nvlist_create
argument_list|(
name|flags
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBCASPER_H_ */
end_comment

end_unit

