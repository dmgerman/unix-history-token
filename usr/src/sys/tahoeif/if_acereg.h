begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)if_acereg.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * VERSAbus ACC ethernet controller definitions  */
end_comment

begin_comment
comment|/*  * Register definitions  */
end_comment

begin_struct
struct|struct
name|acedevice
block|{
name|short
name|station
index|[
literal|6
index|]
decl_stmt|;
comment|/* station address */
name|short
name|bcastena
index|[
literal|2
index|]
decl_stmt|;
comment|/* broadcast enable */
name|short
name|hash
index|[
literal|8
index|]
decl_stmt|;
comment|/* multicast hash codes */
name|short
name|csr
decl_stmt|;
comment|/* control and status register */
name|short
name|tseg
decl_stmt|;
comment|/* current transmit segment # */
name|short
name|rseg
decl_stmt|;
comment|/* current receive  segment # */
name|short
name|segb
decl_stmt|;
comment|/* segment boundary register */
name|short
name|lrf
decl_stmt|;
comment|/* lost receive frame counter */
name|short
name|ivct
decl_stmt|;
comment|/* interrupt vector register */
name|short
name|resv
decl_stmt|;
comment|/* reserved for future use */
name|short
name|fcoll
decl_stmt|;
comment|/* force collision register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit segment in dual ported ram.  */
end_comment

begin_struct
struct|struct
name|tx_segment
block|{
name|short
name|tx_csr
decl_stmt|;
comment|/* packet status */
name|char
name|tx_data
index|[
literal|2014
index|]
decl_stmt|;
name|short
name|tx_backoff
index|[
literal|16
index|]
decl_stmt|;
comment|/* random backoff counters */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receive segment in dual ported ram.  */
end_comment

begin_struct
struct|struct
name|rx_segment
block|{
name|short
name|rx_csr
decl_stmt|;
comment|/* packet status */
name|char
name|rx_data
index|[
literal|2046
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ACC statistics block.  */
end_comment

begin_struct
struct|struct
name|ace_stats
block|{
name|int
name|rx_datagrams
decl_stmt|;
comment|/* valid packets received */
name|int
name|rx_crc_errors
decl_stmt|;
comment|/* CRC errors */
name|int
name|rx_overruns
decl_stmt|;
comment|/* packets too large */
name|int
name|rx_underruns
decl_stmt|;
comment|/* packets too small */
name|int
name|rx_align_errors
decl_stmt|;
comment|/* packets w/ odd byte count */
name|int
name|rx_reserved
decl_stmt|;
name|int
name|rx_busy
decl_stmt|;
comment|/* recv segment filled */
name|int
name|rx_mbuf
decl_stmt|;
comment|/* out of mbufs */
name|int
name|rx_oddoff
decl_stmt|;
comment|/* odd offset in mbuf */
name|int
name|rx_rintcnt
decl_stmt|;
comment|/* recvr interrupt */
name|int
name|tx_datagrams
decl_stmt|;
comment|/* packets xmit'd */
name|int
name|tx_retries
decl_stmt|;
comment|/* collision retries */
name|int
name|tx_discarded
decl_stmt|;
comment|/* packets w/ max retries */
name|int
name|tx_busy
decl_stmt|;
comment|/* xmit segment filled in acestart */
name|int
name|tx_cbusy
decl_stmt|;
comment|/* xmit segment filled in acecint */
name|int
name|tx_mbuf
decl_stmt|;
comment|/* total mbufs */
name|int
name|tx_oddoff
decl_stmt|;
comment|/* odd offset in mbuf */
name|int
name|tx_outcnt
decl_stmt|;
comment|/* calls to aceoutput */
name|int
name|tx_startcnt
decl_stmt|;
comment|/* calls to acestart */
name|int
name|tx_cintcnt
decl_stmt|;
comment|/* xmit's completed */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control status definitions.  */
end_comment

begin_define
define|#
directive|define
name|CSR_OBCENA
value|0x0200
end_define

begin_comment
comment|/* enable xmit of odd byte count */
end_comment

begin_define
define|#
directive|define
name|CSR_ACTIVE
value|0x0080
end_define

begin_comment
comment|/* board active */
end_comment

begin_define
define|#
directive|define
name|CSR_RESET
value|0x0040
end_define

begin_comment
comment|/* reset board */
end_comment

begin_define
define|#
directive|define
name|CSR_PROMISC
value|0x0020
end_define

begin_comment
comment|/* enable promiscous mode */
end_comment

begin_define
define|#
directive|define
name|CSR_CRCDIS
value|0x0010
end_define

begin_comment
comment|/* disable CRC generation */
end_comment

begin_define
define|#
directive|define
name|CSR_LOOP3
value|0x0008
end_define

begin_comment
comment|/* enable loopback mode 3 */
end_comment

begin_define
define|#
directive|define
name|CSR_LOOP2
value|0x0004
end_define

begin_comment
comment|/* enable loopback mode 2 */
end_comment

begin_define
define|#
directive|define
name|CSR_IENA
value|0x0002
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CSR_GO
value|0x0001
end_define

begin_comment
comment|/* enable micro-engine */
end_comment

begin_define
define|#
directive|define
name|ACE_CSRBITS
define|\
value|"\20\12OBCENA\10ACTIVE\7RESET\6PROMISC\5CRCDIS\4LOOP3\3LOOP2\2IENA\1GO"
end_define

begin_comment
comment|/*  * Transmit packet status definitions.  */
end_comment

begin_define
define|#
directive|define
name|TCS_TBFULL
value|(short)0x8000
end_define

begin_comment
comment|/* buffer filled, send it */
end_comment

begin_define
define|#
directive|define
name|TCS_TBC
value|(short)0x07FF
end_define

begin_comment
comment|/* byte count */
end_comment

begin_define
define|#
directive|define
name|TCS_TBMT
value|(short)0x8000
end_define

begin_comment
comment|/* buffer empty */
end_comment

begin_define
define|#
directive|define
name|TCS_RTFAIL
value|(short)0x4000
end_define

begin_comment
comment|/* retries failed */
end_comment

begin_define
define|#
directive|define
name|TCS_RTC
value|(short)0x000F
end_define

begin_comment
comment|/* collision retry mask */
end_comment

begin_comment
comment|/*  * Receive packet status definitions.  */
end_comment

begin_define
define|#
directive|define
name|RCS_RBMT
value|0x8000
end_define

begin_comment
comment|/* buffer ready for recv */
end_comment

begin_define
define|#
directive|define
name|RCS_RBFULL
value|0x8000
end_define

begin_comment
comment|/* buffer full, take data */
end_comment

begin_define
define|#
directive|define
name|RCS_ROVRN
value|0x4000
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|RCS_RCRC
value|0x2000
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RCS_RODD
value|0x1000
end_define

begin_comment
comment|/* odd byte count error */
end_comment

begin_define
define|#
directive|define
name|RCS_RBC
value|0x07FF
end_define

begin_comment
comment|/* byte count mask */
end_comment

begin_define
define|#
directive|define
name|ACE_RCSBITS
value|"\20\20RBFULL\17ROVRN\16RCSR\15RODD"
end_define

begin_define
define|#
directive|define
name|CRC_SIZE
value|4
end_define

begin_comment
comment|/* number of bytes in a rx seg's CRC */
end_comment

begin_define
define|#
directive|define
name|RCW_SIZE
value|2
end_define

begin_comment
comment|/* number of bytes in a rx seg's csr */
end_comment

begin_define
define|#
directive|define
name|SEG_MAX
value|15
end_define

begin_comment
comment|/* largest valid segment number */
end_comment

begin_define
define|#
directive|define
name|ET_MINLEN
value|64
end_define

begin_comment
comment|/* min frame size */
end_comment

begin_define
define|#
directive|define
name|ET_MAXLEN
value|1514
end_define

begin_comment
comment|/* max frame size w/o CRC& RCW */
end_comment

end_unit

