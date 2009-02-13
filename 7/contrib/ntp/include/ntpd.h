begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpd.h - Prototypes for ntpd.  */
end_comment

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_debug.h"
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
file|"recvbuff.h"
end_include

begin_comment
comment|/* ntp_config.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|getconfig
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_config.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ctl_clr_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ctlclrtrap
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|ctlpeerstatus
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ctlsettrap
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|ctlsysstatus
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_control
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process_control
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|report_event
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|fabs
name|P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sqrt
name|P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|add_var
name|P
argument_list|(
operator|(
expr|struct
name|ctl_var
operator|*
operator|*
operator|,
name|u_long
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_varlist
name|P
argument_list|(
operator|(
expr|struct
name|ctl_var
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_var
name|P
argument_list|(
operator|(
expr|struct
name|ctl_var
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_sys_var
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_intres.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ntp_res_name
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|,
name|u_short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ntp_res_recv
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ntp_intres
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_io.c */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|interface_info
block|{
name|struct
name|interface
modifier|*
name|interface
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

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|disable_dynamic_updates
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|interface_enumerate
name|P
argument_list|(
operator|(
name|interface_receiver_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|findinterface
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|findbcastinter
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|enable_broadcast
name|P
argument_list|(
operator|(
expr|struct
name|interface
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|enable_multicast_if
name|P
argument_list|(
operator|(
expr|struct
name|interface
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|interface_dump
name|P
argument_list|(
operator|(
expr|struct
name|interface
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|interface_update
name|P
argument_list|(
operator|(
name|interface_receiver_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_io
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|input_handler
name|P
argument_list|(
operator|(
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|io_clr_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|io_setbclient
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|io_unsetbclient
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|io_multicast_add
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|io_multicast_del
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kill_asyncio
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sendpkt
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|,
expr|struct
name|pkt
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|collect_timing
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGNALED_IO
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|wait_for_signal
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unblock_io_and_alarm
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|block_io_and_alarm
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
end_define

begin_define
define|#
directive|define
name|BLOCK_IO_AND_ALARM
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntp_leap.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_leap
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|leap_process
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|leap_setleap
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * there seems to be a bug in the IRIX 4 compiler which prevents  * u_char from beeing used in prototyped functions.  * This is also true AIX compiler.  * So give up and define it to be int. WLJ  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|leap_actual
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_loopfilter.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_loopfilter
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|local_clock
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|adj_host_clock
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|loop_config
name|P
argument_list|(
operator|(
name|int
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|huffpuff
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|sys_clocktime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|sys_tai
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_monitor.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_mon
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mon_start
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mon_stop
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntp_monitor
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ntp_monclearinterface
name|P
argument_list|(
operator|(
expr|struct
name|interface
operator|*
name|interface
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_peer.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_peer
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|findexistingpeer
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|peer
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|findpeer
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|findpeerbyassoc
name|P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_peerdstadr
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
name|peer
operator|,
expr|struct
name|interface
operator|*
name|interface
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|newpeer
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|u_int
operator|,
name|u_char
operator|,
name|int
operator|,
name|keyid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|peer_all_reset
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|peer_clr_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|peer_config
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|u_int
operator|,
name|int
operator|,
name|keyid_t
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|peer_reset
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|peer_unconfig
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refresh_all_peerinterfaces
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unpeer
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_all
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|expire_all
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|findmanycastpeer
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_crypto.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|crypto_recv
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|crypto_xmit
name|P
argument_list|(
operator|(
expr|struct
name|pkt
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|,
name|int
operator|,
expr|struct
name|exten
operator|*
operator|,
name|keyid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|keyid_t
name|session_key
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|,
name|keyid_t
operator|,
name|keyid_t
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|make_keylist
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
expr|struct
name|interface
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_expire
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|crypto_update
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|crypto_config
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|crypto_setup
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|crypto_ident
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|exten
modifier|*
name|crypto_args
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|u_int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|crypto_public
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|value_free
name|P
argument_list|(
operator|(
expr|struct
name|value
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* OPENSSL */
end_comment

begin_comment
comment|/* ntp_proto.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|transmit
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|receive
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|peer_crypto_clear
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
name|peer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|peer_clear
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process_packet
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
expr|struct
name|pkt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clock_select
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|kod_proto
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * there seems to be a bug in the IRIX 4 compiler which prevents  * u_char from beeing used in prototyped functions.  * This is also true AIX compiler.  * So give up and define it to be int. WLJ  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|poll_update
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clock_filter
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|double
operator|,
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_proto
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|proto_config
name|P
argument_list|(
operator|(
name|int
operator|,
name|u_long
operator|,
name|double
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|proto_clr_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_comment
comment|/* ntp_refclock.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|refclock_newpeer
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refclock_unpeer
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refclock_receive
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refclock_transmit
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_refclock
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|init_request
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process_private
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_restrict.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_restrict
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|restrictions
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hack_restrict
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_timer.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_timer
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reinit_timer
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timer
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timer_clr_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timer_interfacetimeout
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|interface_interval
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_hostname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|l_fp
name|sys_revoketime
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_comment
comment|/* ntp_util.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_util
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stats_config
name|P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_peer_stats
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
name|int
operator|,
name|double
operator|,
name|double
operator|,
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_loop_stats
name|P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|,
name|double
operator|,
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_clock_stats
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_raw_stats
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
expr|struct
name|sockaddr_storage
operator|*
operator|,
name|l_fp
operator|*
operator|,
name|l_fp
operator|*
operator|,
name|l_fp
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_sys_stats
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_crypto_stats
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|record_timing_stats
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|sock_hash
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_storage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|old_drift
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variable declarations for ntpd.  */
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
comment|/* ntp_intres.c */
end_comment

begin_decl_stmt
specifier|extern
name|keyid_t
name|req_keyid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* request keyid */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|req_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the file with configuration info */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_decl_stmt
specifier|extern
name|HANDLE
name|ResolverEventHandle
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|resolver_pipe_fd
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to let the resolver process alert the parent process */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
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
comment|/*  * Interface stuff  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|any_interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default ipv4 interface */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|any6_interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default ipv6 interface */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|interface
modifier|*
name|loopback_interface
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* loopback interface */
end_comment

begin_comment
comment|/*  * File descriptor masks etc. for call to select  */
end_comment

begin_decl_stmt
specifier|extern
name|fd_set
name|activefds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxactivefd
decl_stmt|;
end_decl_stmt

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
name|u_long
name|pps_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last pps sample time */
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
name|pps_enable
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
name|double
name|allan_xpt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allan intercept (s) */
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
name|struct
name|mon_data
name|mon_mru_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mon_data
name|mon_fifo_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mon_enabled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ntp_peer.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|peer_hash
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* peer hash table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_hash_count
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of peers in each bucket */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|assoc_hash
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* association ID hash table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|assoc_hash_count
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|peer_free_count
decl_stmt|;
end_decl_stmt

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
comment|/* stratum of system */
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
comment|/* distance to current sync source */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_rootdispersion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dispersion of system clock */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32
name|sys_refid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reference source for local clock */
end_comment

begin_decl_stmt
specifier|extern
name|l_fp
name|sys_reftime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time we were last updated */
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
comment|/* our current peer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|sys_pps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our current PPS peer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|peer
modifier|*
name|sys_prefer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our cherished peer */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_automax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum session key lifetime */
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
index|[]
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

begin_decl_stmt
specifier|extern
name|int
name|leap_next
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leap consensus */
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
comment|/* time when we started recording */
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
name|sys_oldversionpkt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old version packets */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_newversionpkt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new version packets  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|sys_unknownversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't know version packets */
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
name|sys_processed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* packets processed */
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
name|sys_limitrejected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rate limit exceeded */
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

begin_comment
comment|/* ntp_refclock.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PPS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|fdpps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pps file descriptor */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* ntp_restrict.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|restrictlist
modifier|*
name|restrictlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the ipv4 restriction list */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|restrictlist6
modifier|*
name|restrictlist6
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the ipv6 restriction list */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|res_min_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|res_avg_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|mon_age
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* monitor preempt age */
end_comment

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
name|u_char
name|sys_revoke
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keys revoke timeout (log2 s) */
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
comment|/* current time (s) */
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

begin_comment
comment|/* ntp_util.c */
end_comment

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

begin_comment
comment|/* ntpd.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging flag */
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
name|char
modifier|*
name|chrootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory to chroot to */
end_comment

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

begin_decl_stmt
specifier|extern
name|struct
name|refclock
modifier|*
name|refclock_conf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* refclock configuration table */
end_comment

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

