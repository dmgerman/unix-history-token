begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NTP_IO_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_IO_H
end_define

begin_include
include|#
directive|include
file|"ntp_workimpl.h"
end_include

begin_comment
comment|/*  * POSIX says use<fnct.h> to get O_* symbols and   * SEEK_SET symbol form<unistd.h>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

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
operator|!
name|defined
argument_list|(
name|SEEK_SET
argument_list|)
operator|&&
name|defined
argument_list|(
name|L_SET
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEEK_SET
value|L_SET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|"win32_io.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_NETINET_IN_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_NETINET_IP_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

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

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"libntp.h"
end_include

begin_comment
comment|/* This needs Something above for GETDTABLESIZE */
end_comment

begin_comment
comment|/*  * Define FNDELAY and FASYNC using O_NONBLOCK and O_ASYNC if we need  * to (and can).  This is here initially for QNX, but may help for  * others as well...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FNDELAY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|O_NONBLOCK
end_ifdef

begin_define
define|#
directive|define
name|FNDELAY
value|O_NONBLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FASYNC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|O_ASYNC
end_ifdef

begin_define
define|#
directive|define
name|FASYNC
value|O_ASYNC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NIC rule match types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MATCH_ALL
block|,
name|MATCH_IPV4
block|,
name|MATCH_IPV6
block|,
name|MATCH_WILDCARD
block|,
name|MATCH_IFNAME
block|,
name|MATCH_IFADDR
block|}
name|nic_rule_match
typedef|;
end_typedef

begin_comment
comment|/*  * NIC rule actions  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACTION_LISTEN
block|,
name|ACTION_IGNORE
block|,
name|ACTION_DROP
block|}
name|nic_rule_action
typedef|;
end_typedef

begin_function_decl
name|SOCKET
name|move_fd
parameter_list|(
name|SOCKET
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|get_broadcastclient_flag
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_ip_address
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sau_from_netaddr
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_nic_rule
parameter_list|(
name|nic_rule_match
name|match_type
parameter_list|,
specifier|const
name|char
modifier|*
name|if_name
parameter_list|,
name|int
name|prefixlen
parameter_list|,
name|nic_rule_action
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_IO_COMPLETION_PORT
end_ifndef

begin_function_decl
specifier|extern
name|void
name|maintain_activefds
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|closing
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
name|maintain_activefds
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_IO_H */
end_comment

end_unit

