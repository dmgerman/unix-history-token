begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ARCH_POLL_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ARCH_POLL_PRIVATE_H
end_define

begin_if
if|#
directive|if
name|HAVE_POLL_H
end_if

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_POLL_H
end_if

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PORT_CREATE
end_ifdef

begin_include
include|#
directive|include
file|<port.h>
end_include

begin_include
include|#
directive|include
file|<sys/port_impl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_KQUEUE
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_EPOLL
end_ifdef

begin_include
include|#
directive|include
file|<sys/epoll.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NETWARE
end_ifdef

begin_define
define|#
directive|define
name|HAS_SOCKETS
parameter_list|(
name|dt
parameter_list|)
value|(dt == APR_POLL_SOCKET) ? 1 : 0
end_define

begin_define
define|#
directive|define
name|HAS_PIPES
parameter_list|(
name|dt
parameter_list|)
value|(dt == APR_POLL_FILE) ? 1 : 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_AIO_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_AIO_MSGQ
argument_list|)
end_if

begin_define
define|#
directive|define
name|_AIO_OS390
end_define

begin_comment
comment|/* enable a bunch of z/OS aio.h definitions */
end_comment

begin_include
include|#
directive|include
file|<aio.h>
end_include

begin_comment
comment|/* aiocb	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Choose the best method platform specific to use in apr_pollset */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_KQUEUE
end_ifdef

begin_define
define|#
directive|define
name|POLLSET_USES_KQUEUE
end_define

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_KQUEUE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_PORT_CREATE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|POLLSET_USES_PORT
end_define

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_PORT
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_EPOLL
argument_list|)
end_elif

begin_define
define|#
directive|define
name|POLLSET_USES_EPOLL
end_define

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_EPOLL
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_AIO_MSGQ
argument_list|)
end_elif

begin_define
define|#
directive|define
name|POLLSET_USES_AIO_MSGQ
end_define

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_AIO_MSGQ
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_POLL
argument_list|)
end_elif

begin_define
define|#
directive|define
name|POLLSET_USES_POLL
end_define

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_POLL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POLLSET_USES_SELECT
end_define

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_SELECT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|POLL_USES_SELECT
end_define

begin_undef
undef|#
directive|undef
name|POLLSET_DEFAULT_METHOD
end_undef

begin_define
define|#
directive|define
name|POLLSET_DEFAULT_METHOD
value|APR_POLLSET_SELECT
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_POLL
end_ifdef

begin_define
define|#
directive|define
name|POLL_USES_POLL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POLL_USES_SELECT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|POLLSET_USES_KQUEUE
argument_list|)
operator|||
name|defined
argument_list|(
name|POLLSET_USES_EPOLL
argument_list|)
operator|||
name|defined
argument_list|(
name|POLLSET_USES_PORT
argument_list|)
operator|||
name|defined
argument_list|(
name|POLLSET_USES_AIO_MSGQ
argument_list|)
end_if

begin_include
include|#
directive|include
file|"apr_ring.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_define
define|#
directive|define
name|pollset_lock_rings
parameter_list|()
define|\
value|if (pollset->flags& APR_POLLSET_THREADSAFE) \         apr_thread_mutex_lock(pollset->p->ring_lock);
end_define

begin_define
define|#
directive|define
name|pollset_unlock_rings
parameter_list|()
define|\
value|if (pollset->flags& APR_POLLSET_THREADSAFE) \         apr_thread_mutex_unlock(pollset->p->ring_lock);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pollset_lock_rings
parameter_list|()
end_define

begin_define
define|#
directive|define
name|pollset_unlock_rings
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|pfd_elem_t
name|pfd_elem_t
typedef|;
end_typedef

begin_struct
struct|struct
name|pfd_elem_t
block|{
name|APR_RING_ENTRY
argument_list|(
argument|pfd_elem_t
argument_list|)
name|link
expr_stmt|;
name|apr_pollfd_t
name|pfd
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_PORT_CREATE
name|int
name|on_query_ring
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|apr_pollset_private_t
name|apr_pollset_private_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|apr_pollset_provider_t
name|apr_pollset_provider_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|apr_pollcb_provider_t
name|apr_pollcb_provider_t
typedef|;
end_typedef

begin_struct
struct|struct
name|apr_pollset_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_uint32_t
name|nelts
decl_stmt|;
name|apr_uint32_t
name|nalloc
decl_stmt|;
name|apr_uint32_t
name|flags
decl_stmt|;
comment|/* Pipe descriptors used for wakeup */
name|apr_file_t
modifier|*
name|wakeup_pipe
index|[
literal|2
index|]
decl_stmt|;
name|apr_pollfd_t
name|wakeup_pfd
decl_stmt|;
name|apr_pollset_private_t
modifier|*
name|p
decl_stmt|;
name|apr_pollset_provider_t
modifier|*
name|provider
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_EPOLL
argument_list|)
name|struct
name|epoll_event
modifier|*
name|epoll
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PORT_CREATE
argument_list|)
name|port_event_t
modifier|*
name|port
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_KQUEUE
argument_list|)
name|struct
name|kevent
modifier|*
name|ke
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POLL
argument_list|)
name|struct
name|pollfd
modifier|*
name|ps
decl_stmt|;
endif|#
directive|endif
name|void
modifier|*
name|undef
decl_stmt|;
block|}
name|apr_pollcb_pset
typedef|;
end_typedef

begin_struct
struct|struct
name|apr_pollcb_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_uint32_t
name|nelts
decl_stmt|;
name|apr_uint32_t
name|nalloc
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|apr_pollcb_pset
name|pollset
decl_stmt|;
name|apr_pollfd_t
modifier|*
modifier|*
name|copyset
decl_stmt|;
name|apr_pollcb_provider_t
modifier|*
name|provider
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apr_pollset_provider_t
block|{
name|apr_status_t
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|apr_pollset_t
modifier|*
parameter_list|,
name|apr_uint32_t
parameter_list|,
name|apr_pool_t
modifier|*
parameter_list|,
name|apr_uint32_t
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|add
function_decl|)
parameter_list|(
name|apr_pollset_t
modifier|*
parameter_list|,
specifier|const
name|apr_pollfd_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|remove
function_decl|)
parameter_list|(
name|apr_pollset_t
modifier|*
parameter_list|,
specifier|const
name|apr_pollfd_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|poll
function_decl|)
parameter_list|(
name|apr_pollset_t
modifier|*
parameter_list|,
name|apr_interval_time_t
parameter_list|,
name|apr_int32_t
modifier|*
parameter_list|,
specifier|const
name|apr_pollfd_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|apr_pollset_t
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apr_pollcb_provider_t
block|{
name|apr_status_t
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|apr_pollcb_t
modifier|*
parameter_list|,
name|apr_uint32_t
parameter_list|,
name|apr_pool_t
modifier|*
parameter_list|,
name|apr_uint32_t
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|add
function_decl|)
parameter_list|(
name|apr_pollcb_t
modifier|*
parameter_list|,
name|apr_pollfd_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|remove
function_decl|)
parameter_list|(
name|apr_pollcb_t
modifier|*
parameter_list|,
name|apr_pollfd_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|poll
function_decl|)
parameter_list|(
name|apr_pollcb_t
modifier|*
parameter_list|,
name|apr_interval_time_t
parameter_list|,
name|apr_pollcb_cb_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Private functions */
end_comment

begin_function_decl
name|void
name|apr_pollset_drain_wakeup_pipe
parameter_list|(
name|apr_pollset_t
modifier|*
name|pollset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_ARCH_POLL_PRIVATE_H */
end_comment

end_unit

