begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Internal details for libpcap on DOS.  * 32-bit targets: djgpp, Pharlap or DOS4GW.  *  * @(#) $Header: /tcpdump/master/libpcap/pcap-dos.h,v 1.1 2004/12/18 08:52:10 guy Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCAP_DOS_H
end_ifndef

begin_define
define|#
directive|define
name|__PCAP_DOS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__DJGPP__
end_ifdef

begin_include
include|#
directive|include
file|<pc.h>
end_include

begin_comment
comment|/* simple non-conio kbhit */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<conio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|WORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|DWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|BYTE
name|ETHER
index|[
literal|6
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ETH_ALEN
value|sizeof(ETHER)
end_define

begin_comment
comment|/* Ether address length */
end_comment

begin_define
define|#
directive|define
name|ETH_HLEN
value|(2*ETH_ALEN+2)
end_define

begin_comment
comment|/* Ether header length  */
end_comment

begin_define
define|#
directive|define
name|ETH_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|ETH_MIN
value|60
end_define

begin_define
define|#
directive|define
name|ETH_MAX
value|(ETH_MTU+ETH_HLEN)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PHARLAP
value|1
end_define

begin_define
define|#
directive|define
name|DJGPP
value|2
end_define

begin_define
define|#
directive|define
name|DOS4GW
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__DJGPP__
end_ifdef

begin_undef
undef|#
directive|undef
name|DOSX
end_undef

begin_define
define|#
directive|define
name|DOSX
value|DJGPP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__WATCOMC__
end_ifdef

begin_undef
undef|#
directive|undef
name|DOSX
end_undef

begin_define
define|#
directive|define
name|DOSX
value|DOS4GW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__HIGHC__
end_ifdef

begin_include
include|#
directive|include
file|<pharlap.h>
end_include

begin_undef
undef|#
directive|undef
name|DOSX
end_undef

begin_define
define|#
directive|define
name|DOSX
value|PHARLAP
end_define

begin_define
define|#
directive|define
name|inline
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__HIGHC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|QWORD
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__WATCOMC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|QWORD
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARGSUSED
parameter_list|(
name|x
parameter_list|)
value|(void) x
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SMALL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__LARGE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DOSX
value|0
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|DOSX
argument_list|)
end_elif

begin_error
error|#
directive|error
error|DOSX not defined; 1 = PharLap, 2 = djgpp, 4 = DOS4GW
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__HIGHC__
end_ifdef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_min(a,b)
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_max(a,b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
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

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
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
name|_U_
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_U_
value|__attribute__((unused))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_U_
end_ifndef

begin_define
define|#
directive|define
name|_U_
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
name|USE_32BIT_DRIVERS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"msdos/pm_drvr/lock.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RECEIVE_QUEUE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|RECEIVE_QUEUE_SIZE
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RECEIVE_BUF_SIZE
end_ifndef

begin_define
define|#
directive|define
name|RECEIVE_BUF_SIZE
value|(ETH_MAX+20)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|device
name|el2_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3Com EtherLink II */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|device
name|el3_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      EtherLink III */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|device
name|tc59_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3Com Vortex Card (?) */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|device
name|tc515_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|tc90x_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|tc90bcx_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|wd_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|ne_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|acct_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|cs89_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
name|rtl8139_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|rx_ringbuf
block|{
specifier|volatile
name|int
name|in_index
decl_stmt|;
comment|/* queue index head */
name|int
name|out_index
decl_stmt|;
comment|/* queue index tail */
name|int
name|elem_size
decl_stmt|;
comment|/* size of each element */
name|int
name|num_elem
decl_stmt|;
comment|/* number of elements */
name|char
modifier|*
name|buf_start
decl_stmt|;
comment|/* start of buffer pool */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rx_elem
block|{
name|DWORD
name|size
decl_stmt|;
comment|/* size copied to this element */
name|BYTE
name|data
index|[
name|ETH_MAX
operator|+
literal|10
index|]
decl_stmt|;
comment|/* add some margin. data[0] should be */
block|}
struct|;
end_struct

begin_comment
comment|/* dword aligned */
end_comment

begin_decl_stmt
specifier|extern
name|BYTE
modifier|*
name|get_rxbuf
argument_list|(
name|int
name|len
argument_list|)
name|LOCKED_FUNC
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|peek_rxbuf
parameter_list|(
name|BYTE
modifier|*
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|release_rxbuf
parameter_list|(
name|BYTE
modifier|*
name|buf
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
name|LOCKED_VAR
end_define

begin_define
define|#
directive|define
name|LOCKED_FUNC
end_define

begin_struct
struct|struct
name|device
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|long_name
decl_stmt|;
name|DWORD
name|base_addr
decl_stmt|;
comment|/* device I/O address       */
name|int
name|irq
decl_stmt|;
comment|/* device IRQ number        */
name|int
name|dma
decl_stmt|;
comment|/* DMA channel              */
name|DWORD
name|mem_start
decl_stmt|;
comment|/* shared mem start         */
name|DWORD
name|mem_end
decl_stmt|;
comment|/* shared mem end           */
name|DWORD
name|rmem_start
decl_stmt|;
comment|/* shmem "recv" start       */
name|DWORD
name|rmem_end
decl_stmt|;
comment|/* shared "recv" end        */
name|struct
name|device
modifier|*
name|next
decl_stmt|;
comment|/* next device in list      */
comment|/* interface service routines */
name|int
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|xmit
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|get_stats
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_multicast_list
function_decl|)
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
comment|/* driver-to-pcap receive buffer routines */
name|int
function_decl|(
modifier|*
name|copy_rx_buf
function_decl|)
parameter_list|(
name|BYTE
modifier|*
name|buf
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
comment|/* rx-copy (pktdrvr only) */
name|BYTE
modifier|*
function_decl|(
modifier|*
name|get_rx_buf
function_decl|)
parameter_list|(
name|int
name|len
parameter_list|)
function_decl|;
comment|/* rx-buf fetch/enqueue */
name|int
function_decl|(
modifier|*
name|peek_rx_buf
function_decl|)
parameter_list|(
name|BYTE
modifier|*
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* rx-non-copy at queue */
name|int
function_decl|(
modifier|*
name|release_rx_buf
function_decl|)
parameter_list|(
name|BYTE
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/* release after peek */
name|WORD
name|flags
decl_stmt|;
comment|/* Low-level status flags. */
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* private data */
block|}
struct|;
end_struct

begin_comment
comment|/*    * Network device statistics    */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|net_device_stats
block|{
name|DWORD
name|rx_packets
decl_stmt|;
comment|/* total packets received       */
name|DWORD
name|tx_packets
decl_stmt|;
comment|/* total packets transmitted    */
name|DWORD
name|rx_bytes
decl_stmt|;
comment|/* total bytes received         */
name|DWORD
name|tx_bytes
decl_stmt|;
comment|/* total bytes transmitted      */
name|DWORD
name|rx_errors
decl_stmt|;
comment|/* bad packets received         */
name|DWORD
name|tx_errors
decl_stmt|;
comment|/* packet transmit problems     */
name|DWORD
name|rx_dropped
decl_stmt|;
comment|/* no space in Rx buffers       */
name|DWORD
name|tx_dropped
decl_stmt|;
comment|/* no space available for Tx    */
name|DWORD
name|multicast
decl_stmt|;
comment|/* multicast packets received   */
comment|/* detailed rx_errors: */
name|DWORD
name|rx_length_errors
decl_stmt|;
name|DWORD
name|rx_over_errors
decl_stmt|;
comment|/* recv'r overrun error         */
name|DWORD
name|rx_osize_errors
decl_stmt|;
comment|/* recv'r over-size error       */
name|DWORD
name|rx_crc_errors
decl_stmt|;
comment|/* recv'd pkt with crc error    */
name|DWORD
name|rx_frame_errors
decl_stmt|;
comment|/* recv'd frame alignment error */
name|DWORD
name|rx_fifo_errors
decl_stmt|;
comment|/* recv'r fifo overrun          */
name|DWORD
name|rx_missed_errors
decl_stmt|;
comment|/* recv'r missed packet         */
comment|/* detailed tx_errors */
name|DWORD
name|tx_aborted_errors
decl_stmt|;
name|DWORD
name|tx_carrier_errors
decl_stmt|;
name|DWORD
name|tx_fifo_errors
decl_stmt|;
name|DWORD
name|tx_heartbeat_errors
decl_stmt|;
name|DWORD
name|tx_window_errors
decl_stmt|;
name|DWORD
name|tx_collisions
decl_stmt|;
name|DWORD
name|tx_jabbers
decl_stmt|;
block|}
name|NET_STATS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|device
modifier|*
name|active_dev
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|device
modifier|*
name|dev_base
name|LOCKED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device
modifier|*
name|probed_dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pcap_pkt_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|_w32_os_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Watt-32's misc.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|PCAP_ASSERT
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|pcap_assert
parameter_list|(
specifier|const
name|char
modifier|*
name|what
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|unsigned
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PCAP_ASSERT
parameter_list|(
name|x
parameter_list|)
value|do { \                            if (!(x)) \                               pcap_assert (#x, __FILE__, __LINE__); \                          } while (0)
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
comment|/* __PCAP_DOS_H */
end_comment

end_unit

