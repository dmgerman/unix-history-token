begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* internet.h - TCP/IP abstractions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/internet.h,v 7.5 91/02/22 09:24:43 mrose Interim $  *  *  * $Log:	internet.h,v $  * Revision 7.5  91/02/22  09:24:43  mrose  * Interim 6.8  *   * Revision 7.4  91/01/07  12:39:26  mrose  * update  *   * Revision 7.3  90/10/15  22:54:08  mrose  * typo  *   * Revision 7.2  90/01/11  18:36:01  mrose  * real-sync  *   * Revision 7.1  89/12/19  16:18:01  mrose  * dgram  *   * Revision 7.0  89/11/23  21:55:45  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTERNET_
end_ifndef

begin_define
define|#
directive|define
name|_INTERNET_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MANIFEST_
end_ifndef

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|SOCKETS */
end_comment

begin_include
include|#
directive|include
file|"sys/socket.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SOMAXCONN
end_ifndef

begin_define
define|#
directive|define
name|SOMAXCONN
value|5
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
name|WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|WINTLI
argument_list|)
end_if

begin_include
include|#
directive|include
file|"sys/in.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"netinet/in.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|start_tcp_client
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_tcp_server
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKETS
end_ifdef

begin_function_decl
name|int
name|join_tcp_client
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|join_tcp_server
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|read_tcp_socket
value|read
end_define

begin_define
define|#
directive|define
name|write_tcp_socket
value|write
end_define

begin_define
define|#
directive|define
name|select_tcp_socket
value|selsocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WINTLI
end_ifdef

begin_function_decl
name|int
name|join_tcp_client
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|join_tcp_server
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|select_tcp_socket
value|selsocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EXOS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_define
define|#
directive|define
name|join_tcp_client
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|(accept ((s), (struct sockaddr *) (f)) != NOTOK ? (s) : NOTOK)
end_define

begin_define
define|#
directive|define
name|join_tcp_server
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|connect ((s), (struct sockaddr *) (t))
end_define

begin_define
define|#
directive|define
name|read_tcp_socket
value|read
end_define

begin_define
define|#
directive|define
name|write_tcp_socket
value|write
end_define

begin_define
define|#
directive|define
name|close_tcp_socket
value|close
end_define

begin_define
define|#
directive|define
name|select_tcp_socket
value|selsocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|read_tcp_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_tcp_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close_tcp_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select_tcp_socket
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|UDP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKETS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_DGRAM_
end_ifndef

begin_include
include|#
directive|include
file|"dgram.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|start_udp_server
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|start_udp_client
value|start_udp_server
end_define

begin_define
define|#
directive|define
name|join_udp_server
parameter_list|(
name|fd
parameter_list|,
name|sock
parameter_list|)
define|\
value|join_dgram_aux ((fd), (struct sockaddr *) (sock), 0)
end_define

begin_define
define|#
directive|define
name|join_udp_client
parameter_list|(
name|fd
parameter_list|,
name|sock
parameter_list|)
define|\
value|join_dgram_aux ((fd), (struct sockaddr *) (sock), 1)
end_define

begin_define
define|#
directive|define
name|read_udp_socket
value|read_dgram_socket
end_define

begin_define
define|#
directive|define
name|write_udp_socket
value|write_dgram_socket
end_define

begin_define
define|#
directive|define
name|close_udp_socket
value|close_dgram_socket
end_define

begin_define
define|#
directive|define
name|select_udp_socket
value|select_dgram_socket
end_define

begin_define
define|#
directive|define
name|check_udp_socket
value|check_dgram_socket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|NETDB */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOCKETS
argument_list|)
operator|||
name|defined
argument_list|(
name|WINTLI
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN
argument_list|)
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
name|defined
argument_list|(
name|BIND
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|h_addr
argument_list|)
end_if

begin_define
define|#
directive|define
name|h_addr
value|h_addr_list[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|inaddr_copy
parameter_list|(
name|hp
parameter_list|,
name|sin
parameter_list|)
define|\
value|bcopy ((hp) -> h_addr, (char *)&((sin) -> sin_addr), (hp) -> h_length)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EXOS
end_ifdef

begin_struct
struct|struct
name|hostent
block|{
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* official name */
name|char
modifier|*
modifier|*
name|h_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|h_addrtype
decl_stmt|;
comment|/* address type: AF_INET */
name|int
name|h_length
decl_stmt|;
comment|/* address length: sizeof (u_long) == 4 */
name|char
modifier|*
name|h_addr
decl_stmt|;
comment|/* address value: (struct in_addr *) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|servent
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* official name */
name|char
modifier|*
modifier|*
name|s_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|s_port
decl_stmt|;
comment|/* port number */
name|char
modifier|*
name|s_proto
decl_stmt|;
comment|/* protocol beneath service */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|hostent
modifier|*
name|gethostbyaddr
argument_list|()
decl_stmt|,
modifier|*
name|gethostbyname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|servent
modifier|*
name|getservbyname
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbystring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|INET */
end_comment

begin_comment
comment|/* under BSD42, we could simply include<arpa/inet.h> instead.  However,    the definition of inet_addr contained therein causes problems with some    compilers. */
end_comment

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DG
end_ifndef

begin_function_decl
name|u_long
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX
end_ifndef

begin_function_decl
name|u_long
name|inet_network
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|inet_network
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|in_addr
name|inet_addr
argument_list|()
decl_stmt|,
name|inet_network
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

