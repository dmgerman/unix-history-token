begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: lukemftpd.h,v 1.18 2002/03/14 06:02:24 lukem Exp $ */
end_comment

begin_define
define|#
directive|define
name|FTPD_VERSION
value|"lukemftpd 1.2 beta 1"
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_SYSMACROS_H
end_if

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_if
if|#
directive|if
name|HAVE_FTP_NAMES
end_if

begin_include
include|#
directive|include
file|<arpa/ftp.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"arpaftp.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<fnmatch.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_if
if|#
directive|if
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_if
if|#
directive|if
name|HAVE_SYS_NDIR_H
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_DIR_H
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_NDIR_H
end_if

begin_include
include|#
directive|include
file|<ndir.h>
end_include

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
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

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
name|HAVE_ERR_H
end_if

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_WORKING_GLOB
end_if

begin_include
include|#
directive|include
file|<glob.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ftpglob.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_PATHS_H
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_CSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_CSHELL
value|"/bin/csh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SHELLS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SHELLS
value|"/etc/shells"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NOLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NOLOGIN
value|"/etc/nologin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FTPD_LOGTYPE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LOG_FTP
end_ifdef

begin_define
define|#
directive|define
name|FTPD_LOGTYPE
value|LOG_FTP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FTPD_LOGTYPE
value|LOG_DAEMON
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
name|LOG_AUTHPRIV
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LOG_AUTH
end_ifdef

begin_define
define|#
directive|define
name|LOG_AUTHPRIV
value|LOG_AUTH
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOG_AUTHPRIV
value|LOG_DAEMON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_stringlist
block|{
name|char
modifier|*
modifier|*
name|sl_str
decl_stmt|;
name|size_t
name|sl_max
decl_stmt|;
name|size_t
name|sl_cur
decl_stmt|;
block|}
name|StringList
typedef|;
end_typedef

begin_function_decl
name|StringList
modifier|*
name|sl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sl_add
parameter_list|(
name|StringList
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sl_free
parameter_list|(
name|StringList
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sl_find
parameter_list|(
name|StringList
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|HAVE_FTS_H
end_if

begin_include
include|#
directive|include
file|<fts.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ftpfts.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UTIL_H
end_if

begin_include
include|#
directive|include
file|<util.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIBUTIL_H
end_if

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_IN_PORT_T
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|in_port_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_SOCKLEN_T
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|socklen_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_AF_INET6
operator|&&
name|HAVE_SOCKADDR_IN6
end_if

begin_define
define|#
directive|define
name|INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_RFC2553_NETDB
end_if

begin_comment
comment|/* RFC 2553 */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_ADDRFAMILY
end_undef

begin_define
define|#
directive|define
name|EAI_ADDRFAMILY
value|1
end_define

begin_comment
comment|/* address family for hostname not supported */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_AGAIN
end_undef

begin_define
define|#
directive|define
name|EAI_AGAIN
value|2
end_define

begin_comment
comment|/* temporary failure in name resolution */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_BADFLAGS
end_undef

begin_define
define|#
directive|define
name|EAI_BADFLAGS
value|3
end_define

begin_comment
comment|/* invalid value for ai_flags */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_FAIL
end_undef

begin_define
define|#
directive|define
name|EAI_FAIL
value|4
end_define

begin_comment
comment|/* non-recoverable failure in name resolution */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_FAMILY
end_undef

begin_define
define|#
directive|define
name|EAI_FAMILY
value|5
end_define

begin_comment
comment|/* ai_family not supported */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_MEMORY
end_undef

begin_define
define|#
directive|define
name|EAI_MEMORY
value|6
end_define

begin_comment
comment|/* memory allocation failure */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_NODATA
end_undef

begin_define
define|#
directive|define
name|EAI_NODATA
value|7
end_define

begin_comment
comment|/* no address associated with hostname */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_NONAME
end_undef

begin_define
define|#
directive|define
name|EAI_NONAME
value|8
end_define

begin_comment
comment|/* hostname nor servname provided, or not known */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_SERVICE
end_undef

begin_define
define|#
directive|define
name|EAI_SERVICE
value|9
end_define

begin_comment
comment|/* servname not supported for ai_socktype */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_SOCKTYPE
end_undef

begin_define
define|#
directive|define
name|EAI_SOCKTYPE
value|10
end_define

begin_comment
comment|/* ai_socktype not supported */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_SYSTEM
end_undef

begin_define
define|#
directive|define
name|EAI_SYSTEM
value|11
end_define

begin_comment
comment|/* system error returned in errno */
end_comment

begin_comment
comment|/* KAME extensions? */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_BADHINTS
end_undef

begin_define
define|#
directive|define
name|EAI_BADHINTS
value|12
end_define

begin_undef
undef|#
directive|undef
name|EAI_PROTOCOL
end_undef

begin_define
define|#
directive|define
name|EAI_PROTOCOL
value|13
end_define

begin_undef
undef|#
directive|undef
name|EAI_MAX
end_undef

begin_define
define|#
directive|define
name|EAI_MAX
value|14
end_define

begin_comment
comment|/* RFC 2553 */
end_comment

begin_undef
undef|#
directive|undef
name|NI_MAXHOST
end_undef

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_undef
undef|#
directive|undef
name|NI_MAXSERV
end_undef

begin_define
define|#
directive|define
name|NI_MAXSERV
value|32
end_define

begin_undef
undef|#
directive|undef
name|NI_NOFQDN
end_undef

begin_define
define|#
directive|define
name|NI_NOFQDN
value|0x00000001
end_define

begin_undef
undef|#
directive|undef
name|NI_NUMERICHOST
end_undef

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|0x00000002
end_define

begin_undef
undef|#
directive|undef
name|NI_NAMEREQD
end_undef

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|0x00000004
end_define

begin_undef
undef|#
directive|undef
name|NI_NUMERICSERV
end_undef

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|0x00000008
end_define

begin_undef
undef|#
directive|undef
name|NI_DGRAM
end_undef

begin_define
define|#
directive|define
name|NI_DGRAM
value|0x00000010
end_define

begin_comment
comment|/* RFC 2553 */
end_comment

begin_undef
undef|#
directive|undef
name|AI_PASSIVE
end_undef

begin_define
define|#
directive|define
name|AI_PASSIVE
value|0x00000001
end_define

begin_comment
comment|/* get address to use bind() */
end_comment

begin_undef
undef|#
directive|undef
name|AI_CANONNAME
end_undef

begin_define
define|#
directive|define
name|AI_CANONNAME
value|0x00000002
end_define

begin_comment
comment|/* fill ai_canonname */
end_comment

begin_comment
comment|/* KAME extensions ? */
end_comment

begin_undef
undef|#
directive|undef
name|AI_NUMERICHOST
end_undef

begin_define
define|#
directive|define
name|AI_NUMERICHOST
value|0x00000004
end_define

begin_comment
comment|/* prevent name resolution */
end_comment

begin_undef
undef|#
directive|undef
name|AI_MASK
end_undef

begin_define
define|#
directive|define
name|AI_MASK
value|(AI_PASSIVE | AI_CANONNAME | AI_NUMERICHOST)
end_define

begin_comment
comment|/* RFC 2553 */
end_comment

begin_undef
undef|#
directive|undef
name|AI_ALL
end_undef

begin_define
define|#
directive|define
name|AI_ALL
value|0x00000100
end_define

begin_comment
comment|/* IPv6 and IPv4-mapped (with AI_V4MAPPED) */
end_comment

begin_undef
undef|#
directive|undef
name|AI_V4MAPPED_CFG
end_undef

begin_define
define|#
directive|define
name|AI_V4MAPPED_CFG
value|0x00000200
end_define

begin_comment
comment|/* accept IPv4-mapped if kernel supports */
end_comment

begin_undef
undef|#
directive|undef
name|AI_ADDRCONFIG
end_undef

begin_define
define|#
directive|define
name|AI_ADDRCONFIG
value|0x00000400
end_define

begin_comment
comment|/* only if any address is assigned */
end_comment

begin_undef
undef|#
directive|undef
name|AI_V4MAPPED
end_undef

begin_define
define|#
directive|define
name|AI_V4MAPPED
value|0x00000800
end_define

begin_comment
comment|/* accept IPv4-mapped IPv6 address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_RFC2553_NETDB */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_RFC2553_NETDB
operator|&&
operator|!
name|HAVE_ADDRINFO
end_if

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
name|int
name|ai_family
decl_stmt|;
comment|/* PF_xxx */
name|int
name|ai_socktype
decl_stmt|;
comment|/* SOCK_xxx */
name|int
name|ai_protocol
decl_stmt|;
comment|/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
name|size_t
name|ai_addrlen
decl_stmt|;
comment|/* length of ai_addr */
name|char
modifier|*
name|ai_canonname
decl_stmt|;
comment|/* canonical name for hostname */
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
comment|/* binary address */
name|struct
name|addrinfo
modifier|*
name|ai_next
decl_stmt|;
comment|/* next structure in linked list */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|,
name|struct
name|addrinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeaddrinfo
parameter_list|(
name|struct
name|addrinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_RFC2553_NETDB&& ! HAVE_ADDRINFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_D_NAMLEN
end_if

begin_define
define|#
directive|define
name|DIRENT_MISSING_D_NAMLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_CRYPT_D
end_if

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FCLOSE_D
end_if

begin_function_decl
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_OPTARG_D
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_OPTIND_D
end_if

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_PCLOSE_D
end_if

begin_function_decl
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_ERR
end_if

begin_function_decl
name|void
name|err
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|errx
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warnx
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FGETLN
end_if

begin_function_decl
name|char
modifier|*
name|fgetln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FPARSELN
end_if

begin_define
define|#
directive|define
name|FPARSELN_UNESCESC
value|0x01
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCONT
value|0x02
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCOMM
value|0x04
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCREST
value|0x08
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCALL
value|0x0f
end_define

begin_function_decl
name|char
modifier|*
name|fparseln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
index|[
literal|3
index|]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_GETUSERSHELL
operator|||
operator|!
name|HAVE_GETUSERSHELL_D
end_if

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_INET_NTOP
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|inet_ntop
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_INET_PTON
end_if

begin_function_decl
name|int
name|inet_pton
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_MKSTEMP
end_if

begin_function_decl
name|int
name|mkstemp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_SNPRINTF
end_if

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRDUP
end_if

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRERROR
end_if

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_QUAD_SUPPORT
end_if

begin_if
if|#
directive|if
operator|!
name|HAVE_STRTOLL
operator|&&
name|HAVE_LONG_LONG
end_if

begin_function_decl
name|long
name|long
name|strtoll
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QUAD_MIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|QUAD_MIN
value|(-0x7fffffffffffffffL-1)
end_define

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
name|QUAD_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|QUAD_MAX
value|(0x7fffffffffffffffL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_QUAD_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|NO_LONG_LONG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_QUAD_SUPPORT */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRLCAT
end_if

begin_function_decl
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRLCPY
end_if

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRMODE
end_if

begin_function_decl
name|void
name|strmode
parameter_list|(
name|mode_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRSEP
end_if

begin_function_decl
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_USER_FROM_UID
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|user_from_uid
parameter_list|(
name|uid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|group_from_gid
parameter_list|(
name|gid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_VSYSLOG
end_if

begin_function_decl
name|void
name|vsyslog
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

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
name|MIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

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
name|MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

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
name|timersub
argument_list|)
end_if

begin_define
define|#
directive|define
name|timersub
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|vvp
parameter_list|)
define|\
value|do {								\ 		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\ 		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\ 		if ((vvp)->tv_usec< 0) {				\ 			(vvp)->tv_sec--;				\ 			(vvp)->tv_usec += 1000000;			\ 		}							\ 	} while (0)
end_define

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
name|S_ISLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DAYSPERNYEAR
value|365
end_define

begin_define
define|#
directive|define
name|SECSPERDAY
value|86400
end_define

begin_define
define|#
directive|define
name|TM_YEAR_BASE
value|1900
end_define

end_unit

