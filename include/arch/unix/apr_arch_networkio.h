begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETWORK_IO_H
end_ifndef

begin_define
define|#
directive|define
name|NETWORK_IO_H
end_define

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_private.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_lib.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WAITIO_USES_POLL
end_ifndef

begin_include
include|#
directive|include
file|"apr_poll.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System headers the network I/O library needs */
end_comment

begin_if
if|#
directive|if
name|APR_HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_UIO_H
end_if

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_ERRNO_H
end_if

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_TCP_H
end_if

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_SCTP_UIO_H
end_if

begin_include
include|#
directive|include
file|<netinet/sctp_uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_SCTP_H
end_if

begin_include
include|#
directive|include
file|<netinet/sctp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_IN_H
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_ARPA_INET_H
end_if

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_SOCKET_H
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_SOCKIO_H
end_if

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_NETDB_H
end_if

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_SENDFILE_H
end_if

begin_include
include|#
directive|include
file|<sys/sendfile.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_IOCTL_H
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End System Headers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_POLLIN
end_ifndef

begin_define
define|#
directive|define
name|POLLIN
value|1
end_define

begin_define
define|#
directive|define
name|POLLPRI
value|2
end_define

begin_define
define|#
directive|define
name|POLLOUT
value|4
end_define

begin_define
define|#
directive|define
name|POLLERR
value|8
end_define

begin_define
define|#
directive|define
name|POLLHUP
value|16
end_define

begin_define
define|#
directive|define
name|POLLNVAL
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|sock_userdata_t
name|sock_userdata_t
typedef|;
end_typedef

begin_struct
struct|struct
name|sock_userdata_t
block|{
name|sock_userdata_t
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apr_socket_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|int
name|socketdes
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|protocol
decl_stmt|;
name|apr_sockaddr_t
modifier|*
name|local_addr
decl_stmt|;
name|apr_sockaddr_t
modifier|*
name|remote_addr
decl_stmt|;
name|apr_interval_time_t
name|timeout
decl_stmt|;
ifndef|#
directive|ifndef
name|HAVE_POLL
name|int
name|connected
decl_stmt|;
endif|#
directive|endif
name|int
name|local_port_unknown
decl_stmt|;
name|int
name|local_interface_unknown
decl_stmt|;
name|int
name|remote_addr_unknown
decl_stmt|;
name|apr_int32_t
name|options
decl_stmt|;
name|apr_int32_t
name|inherit
decl_stmt|;
name|sock_userdata_t
modifier|*
name|userdata
decl_stmt|;
ifndef|#
directive|ifndef
name|WAITIO_USES_POLL
comment|/* if there is a timeout set, then this pollset is used */
name|apr_pollset_t
modifier|*
name|pollset
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|apr_inet_ntop
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|apr_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apr_inet_pton
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apr_sockaddr_vars_set
parameter_list|(
name|apr_sockaddr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|apr_port_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|apr_is_option_set
parameter_list|(
name|skt
parameter_list|,
name|option
parameter_list|)
define|\
value|(((skt)->options& (option)) == (option))
end_define

begin_define
define|#
directive|define
name|apr_set_option
parameter_list|(
name|skt
parameter_list|,
name|option
parameter_list|,
name|on
parameter_list|)
define|\
value|do {                                 \         if (on)                          \             (skt)->options |= (option);         \         else                             \             (skt)->options&= ~(option);        \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NETWORK_IO_H */
end_comment

end_unit

