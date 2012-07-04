begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_UDP_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PCAP_H
end_ifdef

begin_include
include|#
directive|include
file|<pcap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_SYSTM_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IP_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NET_IF_H
end_ifdef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IF_ETHER_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WINSOCK2_H
end_ifdef

begin_define
define|#
directive|define
name|USE_WINSOCK
value|1
end_define

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WS2TCPIP_H
end_ifdef

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETADDRINFO
end_ifndef

begin_include
include|#
directive|include
file|<fake-rfc2553.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RANDOM
end_ifndef

begin_comment
comment|/* random can be replaced by rand for ldnsexamples */
end_comment

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SRANDOM
end_ifndef

begin_comment
comment|/* srandom can be replaced by srand for ldnsexamples */
end_comment

begin_define
define|#
directive|define
name|srandom
value|srand
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|,
name|opterr
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|S_SPLINT_S
end_ifdef

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|a
parameter_list|)
end_define

begin_comment
comment|/* a */
end_comment

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_comment
comment|/* a, b */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

