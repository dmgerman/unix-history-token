begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CKCNET_H
end_ifndef

begin_define
define|#
directive|define
name|CKCNET_H
end_define

begin_comment
comment|/* Network types */
end_comment

begin_define
define|#
directive|define
name|NET_NONE
value|0
end_define

begin_comment
comment|/* None */
end_comment

begin_define
define|#
directive|define
name|NET_TCPB
value|1
end_define

begin_comment
comment|/* TCP/IP Berkeley (socket) */
end_comment

begin_define
define|#
directive|define
name|NET_TCPA
value|2
end_define

begin_comment
comment|/* TCP/IP AT&T (streams) */
end_comment

begin_define
define|#
directive|define
name|NET_SX25
value|3
end_define

begin_comment
comment|/* SUNOS SunLink X.25 */
end_comment

begin_define
define|#
directive|define
name|NET_DEC
value|4
end_define

begin_comment
comment|/* DECnet */
end_comment

begin_define
define|#
directive|define
name|NET_VPSI
value|5
end_define

begin_comment
comment|/* VAX PSI */
end_comment

begin_define
define|#
directive|define
name|NET_PIPE
value|6
end_define

begin_comment
comment|/* LAN Manager Named Pipe */
end_comment

begin_comment
comment|/* Network virtual terminal protocols */
end_comment

begin_define
define|#
directive|define
name|NP_NONE
value|0
end_define

begin_comment
comment|/* None (async) */
end_comment

begin_define
define|#
directive|define
name|NP_TELNET
value|1
end_define

begin_comment
comment|/* TCP/IP telnet */
end_comment

begin_define
define|#
directive|define
name|NP_VTP
value|2
end_define

begin_comment
comment|/* ISO Virtual Terminal Protocol */
end_comment

begin_define
define|#
directive|define
name|NP_X3
value|3
end_define

begin_comment
comment|/* CCITT X.3 */
end_comment

begin_define
define|#
directive|define
name|NP_X28
value|4
end_define

begin_comment
comment|/* CCITT X.28 */
end_comment

begin_define
define|#
directive|define
name|NP_X29
value|5
end_define

begin_comment
comment|/* CCITT X.28 */
end_comment

begin_define
define|#
directive|define
name|NP_CTERM
value|20
end_define

begin_comment
comment|/* DEC CTERM */
end_comment

begin_define
define|#
directive|define
name|NP_LAT
value|21
end_define

begin_comment
comment|/* DEC LAT */
end_comment

begin_comment
comment|/* others here... */
end_comment

begin_comment
comment|/* Basic network function prototypes, common to all. */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int netopen
argument_list|,
argument|(char *, int *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int netclos
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int netflui
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int nettchk
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int netbreak
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int netinc
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int nettol
argument_list|,
argument|(char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int nettoc
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*   SunLink X.25 support by Marcello Frutig, Catholic University,   Rio de Janeiro, Brazil, 1990.    Maybe this can be adapted to VAX PSI and other X.25 products too. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUNOS4
end_ifndef

begin_comment
comment|/* Only valid for SUNOS4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_undef
undef|#
directive|undef
name|SUNX25
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NETCONN
end_ifndef

begin_comment
comment|/* SUNX25 implies NETCONN */
end_comment

begin_define
define|#
directive|define
name|NETCONN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

begin_define
define|#
directive|define
name|MAXPADPARMS
value|18
end_define

begin_comment
comment|/* Number of PAD parameters */
end_comment

begin_define
define|#
directive|define
name|MAXCUDATA
value|12
end_define

begin_comment
comment|/* Max length of X.25 call user data */
end_comment

begin_define
define|#
directive|define
name|X29PID
value|1
end_define

begin_comment
comment|/* X.29 protocol ID */
end_comment

begin_define
define|#
directive|define
name|X29PIDLEN
value|4
end_define

begin_comment
comment|/* X.29 protocol ID length */
end_comment

begin_define
define|#
directive|define
name|X29_SET_PARMS
value|2
end_define

begin_define
define|#
directive|define
name|X29_READ_PARMS
value|4
end_define

begin_define
define|#
directive|define
name|X29_SET_AND_READ_PARMS
value|6
end_define

begin_define
define|#
directive|define
name|X29_INVITATION_TO_CLEAR
value|1
end_define

begin_define
define|#
directive|define
name|X29_PARAMETER_INDICATION
value|0
end_define

begin_define
define|#
directive|define
name|X29_INDICATION_OF_BREAK
value|3
end_define

begin_define
define|#
directive|define
name|X29_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|INVALID_PAD_PARM
value|1
end_define

begin_define
define|#
directive|define
name|PAD_BREAK_CHARACTER
value|0
end_define

begin_define
define|#
directive|define
name|PAD_ESCAPE
value|1
end_define

begin_define
define|#
directive|define
name|PAD_ECHO
value|2
end_define

begin_define
define|#
directive|define
name|PAD_DATA_FORWARD_CHAR
value|3
end_define

begin_define
define|#
directive|define
name|PAD_DATA_FORWARD_TIMEOUT
value|4
end_define

begin_define
define|#
directive|define
name|PAD_FLOW_CONTROL_BY_PAD
value|5
end_define

begin_define
define|#
directive|define
name|PAD_SUPPRESSION_OF_SIGNALS
value|6
end_define

begin_define
define|#
directive|define
name|PAD_BREAK_ACTION
value|7
end_define

begin_define
define|#
directive|define
name|PAD_SUPPRESSION_OF_DATA
value|8
end_define

begin_define
define|#
directive|define
name|PAD_PADDING_AFTER_CR
value|9
end_define

begin_define
define|#
directive|define
name|PAD_LINE_FOLDING
value|10
end_define

begin_define
define|#
directive|define
name|PAD_LINE_SPEED
value|11
end_define

begin_define
define|#
directive|define
name|PAD_FLOW_CONTROL_BY_USER
value|12
end_define

begin_define
define|#
directive|define
name|PAD_LF_AFTER_CR
value|13
end_define

begin_define
define|#
directive|define
name|PAD_PADDING_AFTER_LF
value|14
end_define

begin_define
define|#
directive|define
name|PAD_EDITING
value|15
end_define

begin_define
define|#
directive|define
name|PAD_CHAR_DELETE_CHAR
value|16
end_define

begin_define
define|#
directive|define
name|PAD_BUFFER_DELETE_CHAR
value|17
end_define

begin_define
define|#
directive|define
name|PAD_BUFFER_DISPLAY_CHAR
value|18
end_define

begin_define
define|#
directive|define
name|MAXIX25
value|MAX_USER_DATA*7
end_define

begin_define
define|#
directive|define
name|MAXOX25
value|MAX_USER_DATA
end_define

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* X.25 includes */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<sundev/syncstat.h>
end_include

begin_include
include|#
directive|include
file|<netx25/x25_pk.h>
end_include

begin_include
include|#
directive|include
file|<netx25/x25_ctl.h>
end_include

begin_include
include|#
directive|include
file|<netx25/x25_ioctl.h>
end_include

begin_comment
comment|/* C-Kermit X.3 / X.25 / X.29 / X.121 support functions */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID shopad
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID initpad
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID setpad
argument_list|,
argument|(CHAR *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID readpad
argument_list|,
argument|(CHAR *, int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int qbitpkt
argument_list|,
argument|(CHAR *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID setqbit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID resetqbit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID breakact
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int pkx121
argument_list|,
argument|(char *, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID x25oobh
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25diag
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25intr
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25reset
argument_list|,
argument|(char, char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25clear
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25stat
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25in
argument_list|,
argument|(int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int x25inl
argument_list|,
argument|(CHAR *, int, int, CHAR)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_comment
comment|/* DEC TCP/IP for (Open)VMS, previously known as UCX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_TCPIP
end_ifdef

begin_comment
comment|/* DEC_TCPIP implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMSTCPIP
end_ifndef

begin_define
define|#
directive|define
name|VMSTCPIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMSTCPIP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEC_TCPIP */
end_comment

begin_comment
comment|/* TGV/SRI MultiNet, TCP/IP for VAX/VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_comment
comment|/* MULTINET implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMSTCPIP
end_ifndef

begin_define
define|#
directive|define
name|VMSTCPIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMSTCPIP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TGVORWIN
end_ifndef

begin_comment
comment|/* MULTINET and WINTCP */
end_comment

begin_define
define|#
directive|define
name|TGVORWIN
end_define

begin_comment
comment|/* share a lot of code... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TGVORWIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTINET */
end_comment

begin_comment
comment|/* Wollongong TCP/IP for VAX/VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WINTCP
end_ifdef

begin_comment
comment|/* WINTCP implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMSTCPIP
end_ifndef

begin_define
define|#
directive|define
name|VMSTCPIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMSTCPIP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TGVORWIN
end_ifndef

begin_comment
comment|/* WINTCP and MULTINET */
end_comment

begin_define
define|#
directive|define
name|TGVORWIN
end_define

begin_comment
comment|/* share a lot of code... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TGVORWIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINTCP */
end_comment

begin_comment
comment|/* Wollongong TCP/IP for AT&T Sys V */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WOLLONGONG
end_ifdef

begin_comment
comment|/* WOLLONGONG implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_comment
comment|/* Don't confuse WOLLONGONG */
end_comment

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_comment
comment|/* (which is for UNIX) with */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_comment
comment|/* WINTCP, which is for VMS! */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WOLLONGONG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXCELAN
end_ifdef

begin_comment
comment|/* EXCELAN implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXCELAN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INTERLAN
end_ifdef

begin_comment
comment|/* INTERLAN implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTERLAN */
end_comment

begin_comment
comment|/* Telnet protocol */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPSOCKET
end_ifdef

begin_comment
comment|/* TCPSOCKET implies TNCODE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TNCODE
end_ifndef

begin_comment
comment|/* Which means... */
end_comment

begin_define
define|#
directive|define
name|TNCODE
end_define

begin_comment
comment|/* Compile in telnet code */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TNCODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_comment
comment|/* SUNX25 implies TCPSOCKET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPSOCKET
end_ifndef

begin_comment
comment|/* But doesn't imply TNCODE */
end_comment

begin_define
define|#
directive|define
name|TCPSOCKET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_comment
comment|/* This is the TCPSOCKET section... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPSOCKET
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NETCONN
end_ifndef

begin_comment
comment|/* TCPSOCKET implies NETCONN */
end_comment

begin_define
define|#
directive|define
name|NETCONN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

begin_comment
comment|/* BSD sockets library header files */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_comment
comment|/* UNIX section */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INTERLAN
end_ifdef

begin_comment
comment|/* Racal-Interlan TCP/IP */
end_comment

begin_include
include|#
directive|include
file|<interlan/socket.h>
end_include

begin_include
include|#
directive|include
file|<interlan/il_types.h>
end_include

begin_include
include|#
directive|include
file|<interlan/telnet.h>
end_include

begin_include
include|#
directive|include
file|<interlan/il_errno.h>
end_include

begin_include
include|#
directive|include
file|<interlan/in.h>
end_include

begin_include
include|#
directive|include
file|<interlan/telnet.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Normal BSD TCP/IP library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX
end_ifndef

begin_include
include|#
directive|include
file|<arpa/telnet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WOLLONGONG
end_ifdef

begin_include
include|#
directive|include
file|<sys/in.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WOLLONGONG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTERLAN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXCELAN
end_ifndef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|INTERLAN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|WOLLONGONG
end_ifdef

begin_define
define|#
directive|define
name|minor
end_define

begin_comment
comment|/* Do not include<sys/macros.h> */
end_comment

begin_include
include|#
directive|include
file|<sys/inet.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|OXOS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX
end_ifndef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OXOS */
end_comment

begin_comment
comment|/* In too many releases of X/OS,<arpa/inet.h> declares inet_addr() as  * ``struct in_addr''.  This is definitively wrong, and could cause  * core dumps.  Instead of including that bad file, inet_addr() is  * correctly declared here.  Of course, all the declarations done there  * has been copied here.  */
end_comment

begin_function_decl
name|unsigned
name|long
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|inet_network
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OXOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WOLLONGONG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTERLAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXCELAN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXCELAN
end_ifdef

begin_comment
comment|/* Excelan TCP/IP */
end_comment

begin_include
include|#
directive|include
file|<ex_errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXCELAN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I386IX
end_ifdef

begin_comment
comment|/* Interactive Sys V R3 network. */
end_comment

begin_comment
comment|/* #define TELOPTS */
end_comment

begin_comment
comment|/* This might need defining. */
end_comment

begin_define
define|#
directive|define
name|ORG_NLONG
value|ENAMETOOLONG
end_define

begin_comment
comment|/* Resolve conflicting symbols */
end_comment

begin_undef
undef|#
directive|undef
name|ENAMETOOLONG
end_undef

begin_comment
comment|/* in<errno.h> and<net/errno.h> */
end_comment

begin_define
define|#
directive|define
name|ORG_NEMPTY
value|ENOTEMPTY
end_define

begin_undef
undef|#
directive|undef
name|ENOTEMPTY
end_undef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_undef
undef|#
directive|undef
name|ENAMETOOLONG
end_undef

begin_define
define|#
directive|define
name|ENAMETOOLONG
value|ORG_NLONG
end_define

begin_undef
undef|#
directive|undef
name|ENOTEMPTY
end_undef

begin_define
define|#
directive|define
name|ENOTEMPTY
value|ORG_NEMPTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I386IX */
end_comment

begin_comment
comment|/*   Data type of the inet_addr() function...   We define INADDRX if it is of type struct inaddr.   If it is undefined, unsigned long is assumed.   Look at<arpa/inet.h> to find out.  The following known cases are   handled here.  Other systems that need it can be added here, or else   -DINADDRX can be included in the CFLAGS on the cc command line. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX540
end_ifdef

begin_comment
comment|/* Data General UX 5.40 */
end_comment

begin_define
define|#
directive|define
name|INADDRX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX540 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DU2
end_ifdef

begin_comment
comment|/* DEC Ultrix 2.0 */
end_comment

begin_define
define|#
directive|define
name|INADDRX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DU2 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not UNIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* VAX/VMS section */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WINTCP
end_ifdef

begin_comment
comment|/* TWG WIN/TCP for VMS */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include.sys]types.h"
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include.sys]socket.h"
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include]netdb.h"
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include.sys]domain.h"
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include.sys]protosw.h"
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include.netinet]in.h"
end_include

begin_include
include|#
directive|include
file|"twg$tcp:[netdist.include.sys]ioctl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINTCP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_comment
comment|/* TGV MultiNet */
end_comment

begin_include
include|#
directive|include
file|"multinet_root:[multinet.include]errno.h"
end_include

begin_include
include|#
directive|include
file|"multinet_root:[multinet.include.sys]types.h"
end_include

begin_include
include|#
directive|include
file|"multinet_root:[multinet.include.sys]socket.h"
end_include

begin_include
include|#
directive|include
file|"multinet_root:[multinet.include]netdb.h"
end_include

begin_include
include|#
directive|include
file|"multinet_root:[multinet.include.netinet]in.h"
end_include

begin_include
include|#
directive|include
file|"multinet_root:[multinet.include.sys]ioctl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTINET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEC_TCPIP
end_ifdef

begin_include
include|#
directive|include
file|<in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<socket.h>
end_include

begin_include
include|#
directive|include
file|"ckvioc.h"
end_include

begin_define
define|#
directive|define
name|socket_errno
value|errno
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s,0,n)
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|h
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|memmove(a,h,l)
end_define

begin_define
define|#
directive|define
name|socket_read
value|read
end_define

begin_define
define|#
directive|define
name|socket_write
value|write
end_define

begin_define
define|#
directive|define
name|socket_ioctl
value|ioctl
end_define

begin_define
define|#
directive|define
name|socket_close
value|close
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEC_TCPIP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPSOCKET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TNCODE
end_ifdef

begin_comment
comment|/* If we're compiling telnet code... */
end_comment

begin_comment
comment|/*   Make sure telnet symbols are defined; can't rely on library header files   for any of them. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IAC
end_ifndef

begin_comment
comment|/* First the telnet commands */
end_comment

begin_define
define|#
directive|define
name|IAC
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IAC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DONT
end_ifndef

begin_define
define|#
directive|define
name|DONT
value|254
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DONT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DO
end_ifndef

begin_define
define|#
directive|define
name|DO
value|253
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WONT
end_ifndef

begin_define
define|#
directive|define
name|WONT
value|252
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WONT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WILL
end_ifndef

begin_define
define|#
directive|define
name|WILL
value|251
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WILL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SB
end_ifndef

begin_define
define|#
directive|define
name|SB
value|250
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SB */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BREAK
end_ifndef

begin_define
define|#
directive|define
name|BREAK
value|243
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BREAK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SE
end_ifndef

begin_define
define|#
directive|define
name|SE
value|240
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TELOPT_ECHO
end_ifndef

begin_comment
comment|/* Then the options */
end_comment

begin_define
define|#
directive|define
name|TELOPT_ECHO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TELOPT_ECHO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TELOPT_SGA
end_ifndef

begin_define
define|#
directive|define
name|TELOPT_SGA
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TELOPT_SGA */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TELOPT_STATUS
end_ifndef

begin_define
define|#
directive|define
name|TELOPT_STATUS
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TELOPT_STATUS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TELOPT_TTYPE
end_ifndef

begin_define
define|#
directive|define
name|TELOPT_TTYPE
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TELOPT_TTYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTELOPTS
end_ifndef

begin_define
define|#
directive|define
name|NTELOPTS
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTELOPTS */
end_comment

begin_comment
comment|/* Telnet protocol functions defined in C-Kermit */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tn_ini
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Telnet protocol support */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tn_sopt
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tn_doop
argument_list|,
argument|(CHAR, int, int (*)(int) )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tn_sttyp
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tnsndbrk
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TNCODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCNET_H */
end_comment

end_unit

