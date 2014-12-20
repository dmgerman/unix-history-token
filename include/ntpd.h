begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpd.h - Prototypes and external variables for ntpd.  *  * Note the first half is primarily function prototypes, type  * declarations, and preprocessor macros, with variables declared  * primarily in the second half.  *  * Each half is further divided into sections for each source file.  */
end_comment

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_debug.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_select.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_intres.h"
end_include

begin_include
include|#
directive|include
file|"recvbuff.h"
end_include

begin_comment
comment|/*  * First half: ntpd types, functions, macros  * -----------------------------------------  */
end_comment

begin_comment
comment|/*  * macro for debugging output - cut down on #ifdef pollution.  *  * DPRINTF() is for use by ntpd only, and compiles away to nothing  * without DEBUG (configure --disable-debugging).  *  * TRACE() is similar for libntp and utilities, which retain full  * debug capability even when compiled without DEBUG.  *  * The calling convention is not attractive:  *     DPRINTF(debuglevel, (fmt, ...));  *     DPRINTF(2, ("shows #ifdef DEBUG and if debug>= %d\n", 2));  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|lvl
parameter_list|,
name|arg
parameter_list|)
define|\
value|do { 						\ 		if (debug>= (lvl))			\ 			mprintf arg;			\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|lvl
parameter_list|,
name|arg
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nt_clockstuff.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|win_time_stepped
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntp_config.c */
end_comment

begin_define
define|#
directive|define
name|TAI_1972
value|10
end_define

begin_comment
comment|/* initial TAI offset (s) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|keysdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* crypto keys and leaptable directory */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|saveconfigdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntpq saveconfig output directory */
end_comment

begin_function_decl
specifier|extern
name|void
name|getconfig
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ctl_clr_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ctlclrtrap
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|ctlpeerstatus
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ctlsettrap
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|ctlsysstatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_control
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_control
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|report_event
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mprintf_event
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* ntp_control.c */
end_comment

begin_comment
comment|/*  * Structure for translation tables between internal system  * variable indices and text format.  */
end_comment

begin_struct
struct|struct
name|ctl_var
block|{
name|u_short
name|code
decl_stmt|;
name|u_short
name|flags
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flag values  */
end_comment

begin_define
define|#
directive|define
name|CAN_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|CAN_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|DEF
value|0x20
end_define

begin_define
define|#
directive|define
name|PADDING
value|0x40
end_define

begin_define
define|#
directive|define
name|EOV
value|0x80
end_define

begin_define
define|#
directive|define
name|RO
value|(CAN_READ)
end_define

begin_define
define|#
directive|define
name|WO
value|(CAN_WRITE)
end_define

begin_define
define|#
directive|define
name|RW
value|(CAN_READ|CAN_WRITE)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|add_var
parameter_list|(
name|struct
name|ctl_var
modifier|*
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_varlist
parameter_list|(
name|struct
name|ctl_var
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_var
parameter_list|(
name|struct
name|ctl_var
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_sys_var
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|get_ext_sys_var
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_io.c */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|interface_info
block|{
name|endpt
modifier|*
name|ep
decl_stmt|;
name|u_char
name|action
decl_stmt|;
block|}
name|interface_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|interface_receiver_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|interface_info_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|interface_enumerate
parameter_list|(
name|interface_receiver_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|endpt
modifier|*
name|getinterface
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|endpt
modifier|*
name|select_peerinterface
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|,
name|endpt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|endpt
modifier|*
name|findinterface
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|endpt
modifier|*
name|findbcastinter
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_broadcast
parameter_list|(
name|endpt
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_multicast_if
parameter_list|(
name|endpt
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|interface_update
parameter_list|(
name|interface_receiver_t
parameter_list|,
name|void
modifier|*
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
name|io_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|init_io
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_open_sockets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_clr_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_setbclient
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_unsetbclient
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_multicast_add
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_multicast_del
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sendpkt
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pkt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|collect_timing
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGNALED_IO
end_ifdef

begin_function_decl
specifier|extern
name|void
name|wait_for_signal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unblock_io_and_alarm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|block_io_and_alarm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNBLOCK_IO_AND_ALARM
parameter_list|()
value|unblock_io_and_alarm()
end_define

begin_define
define|#
directive|define
name|BLOCK_IO_AND_ALARM
parameter_list|()
value|block_io_and_alarm()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNBLOCK_IO_AND_ALARM
parameter_list|()
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|BLOCK_IO_AND_ALARM
parameter_list|()
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|latoa
parameter_list|(
name|pif
parameter_list|)
value|localaddrtoa(pif)
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|localaddrtoa
parameter_list|(
name|endpt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_loopfilter.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_loopfilter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|local_clock
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|adj_host_clock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|loop_config
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|select_loop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|huffpuff
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_long
name|sys_clocktime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|sys_tai
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|freq_cnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_monitor.c */
end_comment

begin_define
define|#
directive|define
name|MON_HASH_SIZE
value|(1U<< mon_hash_bits)
end_define

begin_define
define|#
directive|define
name|MON_HASH_MASK
value|(MON_HASH_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|MON_HASH
parameter_list|(
name|addr
parameter_list|)
value|(sock_hash(addr)& MON_HASH_MASK)
end_define

begin_function_decl
specifier|extern
name|void
name|init_mon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mon_start
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mon_stop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|ntp_monitor
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mon_clearinterface
parameter_list|(
name|endpt
modifier|*
name|interface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_peer.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_peer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|peer
modifier|*
name|findexistingpeer
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|peer
modifier|*
name|findpeer
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|peer
modifier|*
name|findpeerbyassoc
parameter_list|(
name|associd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_peerdstadr
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|endpt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|peer
modifier|*
name|newpeer
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|endpt
modifier|*
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_int
parameter_list|,
name|u_char
parameter_list|,
name|u_int32
parameter_list|,
name|keyid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|peer_all_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|peer_clr_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|peer
modifier|*
name|peer_config
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|endpt
modifier|*
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_int
parameter_list|,
name|u_int32
parameter_list|,
name|keyid_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|peer_reset
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refresh_all_peerinterfaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unpeer
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|score_all
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|peer
modifier|*
name|findmanycastpeer
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_crypto.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOKEY
end_ifdef

begin_function_decl
specifier|extern
name|int
name|crypto_recv
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_xmit
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|struct
name|pkt
modifier|*
parameter_list|,
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|exten
modifier|*
parameter_list|,
name|keyid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|keyid_t
name|session_key
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|,
name|keyid_t
parameter_list|,
name|keyid_t
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|make_keylist
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|struct
name|interface
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|key_expire
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_update
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_config
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|crypto_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int
name|crypto_ident
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|exten
modifier|*
name|crypto_args
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|associd_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|crypto_public
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|value_free
parameter_list|(
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|iffpar_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EVP_PKEY
modifier|*
name|iffpar_pkey
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gqpar_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EVP_PKEY
modifier|*
name|gqpar_pkey
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mvpar_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EVP_PKEY
modifier|*
name|mvpar_pkey
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|value
name|tai_leap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOKEY */
end_comment

begin_comment
comment|/* ntp_proto.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|transmit
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|receive
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|peer_clear
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_packet
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|struct
name|pkt
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clock_select
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_long
name|leapsec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds to next leap (proximity class) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|leapdif
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TAI difference step at next leap second*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_orphan
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sys_mindisp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sys_maxdist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* identity scheme */
end_comment

begin_function_decl
specifier|extern
name|void
name|poll_update
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clock_filter
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_proto
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_sys_tick_precision
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proto_config
parameter_list|(
name|int
parameter_list|,
name|u_long
parameter_list|,
name|double
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proto_clr_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_refclock.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_function_decl
specifier|extern
name|int
name|refclock_newpeer
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_unpeer
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_receive
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_transmit
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_refclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

begin_comment
comment|/* ntp_request.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_request
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_private
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reset_auth_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_restrict.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_restrict
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|restrictions
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hack_restrict
parameter_list|(
name|int
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restrict_source
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntp_timer.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reinit_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_clr_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timer_interfacetimeout
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|interface_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|orphwait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* orphan wait time */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOKEY
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_hostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_groupname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|group_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group name */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_revoke
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keys revoke timeout */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_automax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* session key timeout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOKEY */
end_comment

begin_comment
comment|/* ntp_util.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_util
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_stats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|stats_config
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_peer_stats
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|int
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_proto_stats
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_loop_stats
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_clock_stats
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mprintf_clock_stats
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|record_raw_stats
parameter_list|(
name|sockaddr_u
modifier|*
name|srcadr
parameter_list|,
name|sockaddr_u
modifier|*
name|dstadr
parameter_list|,
name|l_fp
modifier|*
name|t1
parameter_list|,
name|l_fp
modifier|*
name|t2
parameter_list|,
name|l_fp
modifier|*
name|t3
parameter_list|,
name|l_fp
modifier|*
name|t4
parameter_list|,
name|int
name|leap
parameter_list|,
name|int
name|version
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|stratum
parameter_list|,
name|int
name|poll
parameter_list|,
name|int
name|precision
parameter_list|,
name|double
name|root_delay
parameter_list|,
name|double
name|root_dispersion
parameter_list|,
name|u_int32
name|refid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_leap_file
parameter_list|(
name|int
name|is_daily_check
parameter_list|,
name|u_int32
name|ntptime
parameter_list|,
specifier|const
name|time_t
modifier|*
name|systime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_crypto_stats
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|record_timing_stats
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|fstostr
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NTP timescale seconds */
end_comment

begin_comment
comment|/* ntpd.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|parse_cmdline_opts
parameter_list|(
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Signals we catch for debugging.  */
end_comment

begin_define
define|#
directive|define
name|MOREDEBUGSIG
value|SIGUSR1
end_define

begin_define
define|#
directive|define
name|LESSDEBUGSIG
value|SIGUSR2
end_define

begin_comment
comment|/*  * Signals which terminate us gracefully.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_define
define|#
directive|define
name|SIGDIE1
value|SIGHUP
end_define

begin_define
define|#
directive|define
name|SIGDIE2
value|SIGINT
end_define

begin_define
define|#
directive|define
name|SIGDIE3
value|SIGQUIT
end_define

begin_define
define|#
directive|define
name|SIGDIE4
value|SIGTERM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_comment
comment|/*  * Last half: ntpd variables  * -------------------------  */
end_comment

begin_comment
comment|/* ntp_config.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_phone
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ACTS phone numbers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SCHED_SETSCHEDULER
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|config_priority_override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|config_priority
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ntp_signd_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|config_tree_tag
modifier|*
name|cfg_tree_history
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BC_LIST_FRAMEWORK_NOT_YET_USED
end_ifdef

begin_comment
comment|/*  * backwards compatibility flags  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bc_entry_tag
block|{
name|int
name|token
decl_stmt|;
name|int
name|enabled
decl_stmt|;
block|}
name|bc_entry
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bc_entry
name|bc_list
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntp_control.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_ctl_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|keyid_t
name|ctl_auth_keyid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyid used for authenticating write requests */
end_comment

begin_comment
comment|/*  * Statistic counters to keep track of requests and responses.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|ctltimereset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time stats reset */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlreq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of requests we've received */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlbadpkts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bad control packets */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlresponses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of resp packets sent with data */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlfrags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of fragments sent */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlerrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of error responses sent */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctltooshort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of too short input packets */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlinputresp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of responses on input */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlinputfrag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of fragments on input */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlinputerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of input pkts with err bit set */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlbadoffset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of input pkts with nonzero offset */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlbadversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of input pkts with unknown version */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctldatatooshort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data too short for count */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numctlbadop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad op code found in packet */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|numasyncmsgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of async messages we've sent */
end_comment

begin_comment
comment|/*  * Other statistics of possible interest  */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_long
name|packets_dropped
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of packets dropped on reception */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_long
name|packets_ignored
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* packets received on wild card interface */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_long
name|packets_received
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of packets received */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|packets_sent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of packets sent */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|packets_notsent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of packets which couldn't be sent */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_long
name|handler_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of calls to interrupt handler */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_long
name|handler_pkts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of pkts received by handler */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|io_timereset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time counters were reset */
end_comment

begin_comment
comment|/* ntp_io.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|disable_dynamic_updates
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|sys_ifnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next .ifnum to assign */
end_comment

begin_decl_stmt
specifier|extern
name|endpt
modifier|*
name|any_interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPv4 wildcard */
end_comment

begin_decl_stmt
specifier|extern
name|endpt
modifier|*
name|any6_interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPv6 wildcard */
end_comment

begin_decl_stmt
specifier|extern
name|endpt
modifier|*
name|loopback_interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPv4 loopback for refclocks */
end_comment

begin_decl_stmt
specifier|extern
name|endpt
modifier|*
name|ep_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* linked list */
end_comment

begin_comment
comment|/* ntp_loopfilter.c */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|drift_comp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock frequency (s/s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_stability
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock stability (s/s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max offset before step (s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_panic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max offset before panic (s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_phi
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dispersion rate (s/s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_minstep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* step timeout (s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_codec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* codec frequency */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|pll_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status bits for kernel pll */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_PLL */
end_comment

begin_comment
comment|/*  * Clock state machine control flags  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ntp_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock discipline enabled */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pll_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel support available */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|kern_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel support enabled */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hardpps_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel PPS discipline enabled */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ext_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* external clock enabled */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cal_enable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* refclock calibrate enable */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|allow_panic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow panic correction */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mode_ntpdate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit on first clock set */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_ntpdate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of ntpdate peers */
end_comment

begin_comment
comment|/*  * Clock state machine variables  */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|sys_poll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system poll interval (log2 s) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock discipline state */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tc_counter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poll-adjust counter */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|last_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of last clock update (s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|last_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last clock offset (s) */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|allan_xpt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allan intercept (log2 s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|clock_jitter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clock jitter (s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system offset (s) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_jitter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system jitter (s) */
end_comment

begin_comment
comment|/* ntp_monitor.c */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|mon_hash_bits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log2 size of hash table */
end_comment

begin_decl_stmt
specifier|extern
name|mon_entry
modifier|*
modifier|*
name|mon_hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MRU hash table */
end_comment

begin_decl_stmt
specifier|extern
name|mon_entry
name|mon_mru_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mru listhead */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mon_enabled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MON_OFF (0) or other MON_* */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_alloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mru list + free list count */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_entries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mru list count */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_peakentries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* highest mru_entries */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_initalloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* entries to preallocate */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_incalloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allocation batch factor */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_mindepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preempt above this */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mru_maxage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for entries older than */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mru_maxdepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MRU size hard limit */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mon_age
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preemption limit */
end_comment

begin_comment
comment|/* ntp_peer.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|peer_hash
index|[
name|NTP_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* peer hash table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_hash_count
index|[
name|NTP_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of in each bucket */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|assoc_hash
index|[
name|NTP_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* association ID hash table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|assoc_hash_count
index|[
name|NTP_HASH_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of in each bucket */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|peer_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* peer structures list */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count in peer_list */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_free_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count in peer_free */
end_comment

begin_comment
comment|/*  * Miscellaneous statistic counters which may be queried.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|peer_timereset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time stat counters were zeroed */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|findpeer_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of calls to findpeer */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|assocpeer_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of calls to findpeerbyassoc */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|peer_allocations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of allocations from the free list */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|peer_demobilizations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of structs freed to free list */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|total_peer_structs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of peer structs in circulation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_associations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mobilized associations */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_preempt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preemptable associations */
end_comment

begin_comment
comment|/* ntp_proto.c */
end_comment

begin_comment
comment|/*  * System variables are declared here.	See Section 3.2 of the  * specification.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|sys_leap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system leap indicator */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|sys_stratum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system stratum */
end_comment

begin_decl_stmt
specifier|extern
name|s_char
name|sys_precision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local clock precision */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_rootdelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* roundtrip delay to primary source */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_rootdisp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dispersion to primary source */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32
name|sys_refid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reference id */
end_comment

begin_decl_stmt
specifier|extern
name|l_fp
name|sys_reftime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last update time */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|sys_peer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current peer */
end_comment

begin_comment
comment|/*  * Nonspecified system state variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_bclient
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we set our time to broadcasts */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_bdelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* broadcast client default delay */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_authenticate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* requre authentication for config */
end_comment

begin_decl_stmt
specifier|extern
name|l_fp
name|sys_authdelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* authentication delay */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_epoch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last clock update time */
end_comment

begin_decl_stmt
specifier|extern
name|keyid_t
name|sys_private
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* private value for session seed */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_manycastserver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* respond to manycast client pkts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_minclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum survivors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_minsane
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum candidates */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_floor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cluster stratum floor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_ceiling
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cluster stratum ceiling */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|sys_ttl
index|[
name|MAX_TTL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ttl mapping vector */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_ttlmax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max ttl mapping vector index */
end_comment

begin_comment
comment|/*  * Statistics counters  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_stattime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time since reset */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_received
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* packets received */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_processed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* packets for this host */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_restricted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restricted packets */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_newversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current version  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_oldversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old version */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_restricted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* access denied */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_badlength
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad length or format */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_badauth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bad authentication */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_declined
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* declined */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_limitrejected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rate exceeded */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_kodsent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* KoD sent */
end_comment

begin_comment
comment|/* ntp_request.c */
end_comment

begin_decl_stmt
specifier|extern
name|keyid_t
name|info_auth_keyid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyid used to authenticate requests */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|auth_timereset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_restrict.c */
end_comment

begin_decl_stmt
specifier|extern
name|restrict_u
modifier|*
name|restrictlist4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPv4 restriction list */
end_comment

begin_decl_stmt
specifier|extern
name|restrict_u
modifier|*
name|restrictlist6
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPv6 restriction list */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ntp_minpkt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|ntp_minpoll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_scanner.c */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32
name|conf_file_sum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Simple sum of characters */
end_comment

begin_comment
comment|/* ntp_signd.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NTP_SIGND
end_ifdef

begin_function_decl
specifier|extern
name|void
name|send_via_ntp_signd
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|keyid_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|pkt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntp_timer.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|alarm_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alarm flag */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_long
name|alarm_overflow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|current_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds since startup */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|timer_timereset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|timer_overflows
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|timer_xmtcalls
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_decl_stmt
name|HANDLE
name|WaitableTimerHandle
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntp_util.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|statsdir
index|[
name|MAXFILENAME
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stats_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write stats to fileset? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stats_write_period
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of seconds between writes. */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|stats_write_tolerance
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|wander_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntpd.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nofork
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no-fork flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|initializing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initializing flag */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DROPROOT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|droproot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag: try to drop root privileges after startup */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|root_dropped
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root has been dropped */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|user
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user to switch to */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|group
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group to switch to */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|chrootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory to chroot() to */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|waitsync_fd_to_close
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -w/--wait-sync */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntservice.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|accept_wildcard_if_for_winnt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* refclock_conf.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_comment
comment|/* refclock configuration table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|refclock
modifier|*
specifier|const
name|refclock_conf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|num_refclock_conf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

