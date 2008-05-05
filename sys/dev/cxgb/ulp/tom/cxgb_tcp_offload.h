begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CXGB_TCP_OFFLOAD_H_
end_ifndef

begin_define
define|#
directive|define
name|CXGB_TCP_OFFLOAD_H_
end_define

begin_struct_decl
struct_decl|struct
name|tcpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockbuf
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|tcp_offload_twstart
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_offload_twstart_disconnect
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|tcp_offload_close
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|tcp_offload_drop
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_apply_all
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|socket
modifier|*
name|inp_inpcbtosocket
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|inp_inpcbtotcpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inp_ip_tos_get
parameter_list|(
specifier|const
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_ip_tos_set
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_4tuple_get
parameter_list|(
specifier|const
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|so_sototcpcb
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inpcb
modifier|*
name|so_sotoinpcb
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sockbuf
modifier|*
name|so_sockbuf_snd
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sockbuf
modifier|*
name|so_sockbuf_rcv
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|so_state_get
parameter_list|(
specifier|const
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_state_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|so_options_get
parameter_list|(
specifier|const
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_options_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|so_error_get
parameter_list|(
specifier|const
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_error_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|so_linger_get
parameter_list|(
specifier|const
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_linger_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protosw
modifier|*
name|so_protosw_get
parameter_list|(
specifier|const
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_protosw_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|protosw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_sorwakeup_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_sowwakeup_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_sorwakeup
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_sowwakeup
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_lock
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_unlock
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|so_listeners_apply_all
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sockbuf_lock
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sockbuf_lock_assert
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sockbuf_unlock
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sockbuf_sbspace
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|tcphdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tcpopt
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|syncache_offload_expand
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKETVAR_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_comment
comment|/*  * Constants for sb_flags field of struct sockbuf.  */
end_comment

begin_define
define|#
directive|define
name|SB_MAX
value|(256*1024)
end_define

begin_comment
comment|/* default for max chars in sockbuf */
end_comment

begin_comment
comment|/*  * Constants for sb_flags field of struct sockbuf.  */
end_comment

begin_define
define|#
directive|define
name|SB_WAIT
value|0x04
end_define

begin_comment
comment|/* someone is waiting for data/space */
end_comment

begin_define
define|#
directive|define
name|SB_SEL
value|0x08
end_define

begin_comment
comment|/* someone is selecting */
end_comment

begin_define
define|#
directive|define
name|SB_ASYNC
value|0x10
end_define

begin_comment
comment|/* ASYNC I/O, need signals */
end_comment

begin_define
define|#
directive|define
name|SB_UPCALL
value|0x20
end_define

begin_comment
comment|/* someone wants an upcall */
end_comment

begin_define
define|#
directive|define
name|SB_NOINTR
value|0x40
end_define

begin_comment
comment|/* operations not interruptible */
end_comment

begin_define
define|#
directive|define
name|SB_AIO
value|0x80
end_define

begin_comment
comment|/* AIO operations queued */
end_comment

begin_define
define|#
directive|define
name|SB_KNOTE
value|0x100
end_define

begin_comment
comment|/* kernel note attached */
end_comment

begin_define
define|#
directive|define
name|SB_NOCOALESCE
value|0x200
end_define

begin_comment
comment|/* don't coalesce new data into existing mbufs */
end_comment

begin_define
define|#
directive|define
name|SB_IN_TOE
value|0x400
end_define

begin_comment
comment|/* socket buffer is in the middle of an operation */
end_comment

begin_define
define|#
directive|define
name|SB_AUTOSIZE
value|0x800
end_define

begin_comment
comment|/* automatically size socket buffer */
end_comment

begin_struct
struct|struct
name|sockbuf
block|{
name|struct
name|selinfo
name|sb_sel
decl_stmt|;
comment|/* process selecting read/write */
name|struct
name|mtx
name|sb_mtx
decl_stmt|;
comment|/* sockbuf lock */
name|struct
name|sx
name|sb_sx
decl_stmt|;
comment|/* prevent I/O interlacing */
name|short
name|sb_state
decl_stmt|;
comment|/* (c/d) socket state on sockbuf */
define|#
directive|define
name|sb_startzero
value|sb_mb
name|struct
name|mbuf
modifier|*
name|sb_mb
decl_stmt|;
comment|/* (c/d) the mbuf chain */
name|struct
name|mbuf
modifier|*
name|sb_mbtail
decl_stmt|;
comment|/* (c/d) the last mbuf in the chain */
name|struct
name|mbuf
modifier|*
name|sb_lastrecord
decl_stmt|;
comment|/* (c/d) first mbuf of last 						 * record in socket buffer */
name|struct
name|mbuf
modifier|*
name|sb_sndptr
decl_stmt|;
comment|/* (c/d) pointer into mbuf chain */
name|u_int
name|sb_sndptroff
decl_stmt|;
comment|/* (c/d) byte offset of ptr into chain */
name|u_int
name|sb_cc
decl_stmt|;
comment|/* (c/d) actual chars in buffer */
name|u_int
name|sb_hiwat
decl_stmt|;
comment|/* (c/d) max actual char count */
name|u_int
name|sb_mbcnt
decl_stmt|;
comment|/* (c/d) chars of mbufs used */
name|u_int
name|sb_mbmax
decl_stmt|;
comment|/* (c/d) max chars of mbufs to use */
name|u_int
name|sb_ctl
decl_stmt|;
comment|/* (c/d) non-data chars in buffer */
name|int
name|sb_lowat
decl_stmt|;
comment|/* (c/d) low water mark */
name|int
name|sb_timeo
decl_stmt|;
comment|/* (c/d) timeout for read/write */
name|short
name|sb_flags
decl_stmt|;
comment|/* (c/d) flags, see below */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|sbappend
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappend_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendstream
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendstream_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdrop
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdrop_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdroprecord
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdroprecord_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbflush
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbflush_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbwait
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sblock
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbunlock
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* adjust counters in sb reflecting allocation of m */
end_comment

begin_define
define|#
directive|define
name|sballoc
parameter_list|(
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(sb)->sb_cc += (m)->m_len; \ 	if ((m)->m_type != MT_DATA&& (m)->m_type != MT_OOBDATA) \ 		(sb)->sb_ctl += (m)->m_len; \ 	(sb)->sb_mbcnt += MSIZE; \ 	if ((m)->m_flags& M_EXT) \ 		(sb)->sb_mbcnt += (m)->m_ext.ext_size; \ }
end_define

begin_comment
comment|/* adjust counters in sb reflecting freeing of m */
end_comment

begin_define
define|#
directive|define
name|sbfree
parameter_list|(
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(sb)->sb_cc -= (m)->m_len; \ 	if ((m)->m_type != MT_DATA&& (m)->m_type != MT_OOBDATA) \ 		(sb)->sb_ctl -= (m)->m_len; \ 	(sb)->sb_mbcnt -= MSIZE; \ 	if ((m)->m_flags& M_EXT) \ 		(sb)->sb_mbcnt -= (m)->m_ext.ext_size; \ 	if ((sb)->sb_sndptr == (m)) { \ 		(sb)->sb_sndptr = NULL; \ 		(sb)->sb_sndptroff = 0; \ 	} \ 	if ((sb)->sb_sndptroff != 0) \ 		(sb)->sb_sndptroff -= (m)->m_len; \ }
end_define

begin_define
define|#
directive|define
name|SS_NOFDREF
value|0x0001
end_define

begin_comment
comment|/* no file table ref any more */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTED
value|0x0002
end_define

begin_comment
comment|/* socket connected to a peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTING
value|0x0004
end_define

begin_comment
comment|/* in process of connecting to peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTING
value|0x0008
end_define

begin_comment
comment|/* in process of disconnecting */
end_comment

begin_define
define|#
directive|define
name|SS_NBIO
value|0x0100
end_define

begin_comment
comment|/* non-blocking ops */
end_comment

begin_define
define|#
directive|define
name|SS_ASYNC
value|0x0200
end_define

begin_comment
comment|/* async i/o notify */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONFIRMING
value|0x0400
end_define

begin_comment
comment|/* deciding to accept connection req */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTED
value|0x2000
end_define

begin_comment
comment|/* socket disconnected from peer */
end_comment

begin_comment
comment|/*  * Protocols can mark a socket as SS_PROTOREF to indicate that, following  * pru_detach, they still want the socket to persist, and will free it  * themselves when they are done.  Protocols should only ever call sofree()  * following setting this flag in pru_detach(), and never otherwise, as  * sofree() bypasses socket reference counting.  */
end_comment

begin_define
define|#
directive|define
name|SS_PROTOREF
value|0x4000
end_define

begin_comment
comment|/* strong protocol reference */
end_comment

begin_comment
comment|/*  * Socket state bits now stored in the socket buffer state field.  */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTSENDMORE
value|0x0010
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTRCVMORE
value|0x0020
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SBS_RCVATMARK
value|0x0040
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_enum
enum|enum
name|sopt_dir
block|{
name|SOPT_GET
block|,
name|SOPT_SET
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sockopt
block|{
name|enum
name|sopt_dir
name|sopt_dir
decl_stmt|;
comment|/* is this a get or a set? */
name|int
name|sopt_level
decl_stmt|;
comment|/* second arg of [gs]etsockopt */
name|int
name|sopt_name
decl_stmt|;
comment|/* third arg of [gs]etsockopt */
name|void
modifier|*
name|sopt_val
decl_stmt|;
comment|/* fourth arg of [gs]etsockopt */
name|size_t
name|sopt_valsize
decl_stmt|;
comment|/* (almost) fifth arg of [gs]etsockopt */
name|struct
name|thread
modifier|*
name|sopt_td
decl_stmt|;
comment|/* calling thread or null if kernel */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sooptcopyin
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
name|minlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sooptcopyout
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisconnected
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisconnecting
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisdisconnected
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisdisconnecting
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantrcvmore
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantrcvmore_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantsendmore
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantsendmore_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NET_CORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CXGB_TCP_OFFLOAD_H_ */
end_comment

end_unit

