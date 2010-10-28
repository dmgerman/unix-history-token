begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__PKTDRVR_H
end_ifndef

begin_define
define|#
directive|define
name|__PKTDRVR_H
end_define

begin_define
define|#
directive|define
name|PUBLIC
end_define

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_define
define|#
directive|define
name|RX_BUF_SIZE
value|ETH_MTU
end_define

begin_comment
comment|/* buffer size variables. NB !! */
end_comment

begin_define
define|#
directive|define
name|TX_BUF_SIZE
value|ETH_MTU
end_define

begin_comment
comment|/* must be same as in pkt_rx*.* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__HIGHC__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|Off
name|(
name|Align_members
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Packet-driver classes */
name|PD_ETHER
init|=
literal|1
block|,
name|PD_PRONET10
init|=
literal|2
block|,
name|PD_IEEE8025
init|=
literal|3
block|,
name|PD_OMNINET
init|=
literal|4
block|,
name|PD_APPLETALK
init|=
literal|5
block|,
name|PD_SLIP
init|=
literal|6
block|,
name|PD_STARTLAN
init|=
literal|7
block|,
name|PD_ARCNET
init|=
literal|8
block|,
name|PD_AX25
init|=
literal|9
block|,
name|PD_KISS
init|=
literal|10
block|,
name|PD_IEEE8023_2
init|=
literal|11
block|,
name|PD_FDDI8022
init|=
literal|12
block|,
name|PD_X25
init|=
literal|13
block|,
name|PD_LANstar
init|=
literal|14
block|,
name|PD_PPP
init|=
literal|18
block|}
name|PKT_CLASS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Packet-driver receive modes    */
name|PDRX_OFF
init|=
literal|1
block|,
comment|/* turn off receiver              */
name|PDRX_DIRECT
block|,
comment|/* receive only to this interface */
name|PDRX_BROADCAST
block|,
comment|/* DIRECT + broadcast packets     */
name|PDRX_MULTICAST1
block|,
comment|/* BROADCAST + limited multicast  */
name|PDRX_MULTICAST2
block|,
comment|/* BROADCAST + all multicast      */
name|PDRX_ALL_PACKETS
block|,
comment|/* receive all packets on network */
block|}
name|PKT_RX_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
index|[
literal|8
index|]
decl_stmt|;
name|char
name|len
decl_stmt|;
block|}
name|PKT_FRAME
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|class
decl_stmt|;
comment|/* = 1 for DEC/Interl/Xerox Ethernet */
name|BYTE
name|number
decl_stmt|;
comment|/* = 0 for single LAN adapter        */
name|WORD
name|type
decl_stmt|;
comment|/* = 13 for 3C523                    */
name|BYTE
name|funcs
decl_stmt|;
comment|/* Basic/Extended/HiPerf functions   */
name|WORD
name|intr
decl_stmt|;
comment|/* user interrupt vector number      */
name|WORD
name|handle
decl_stmt|;
comment|/* Handle associated with session    */
name|BYTE
name|name
index|[
literal|15
index|]
decl_stmt|;
comment|/* Name of adapter interface,ie.3C523*/
name|BOOL
name|quiet
decl_stmt|;
comment|/* (don't) print errors to stdout    */
specifier|const
name|char
modifier|*
name|error
decl_stmt|;
comment|/* address of error string           */
name|BYTE
name|majVer
decl_stmt|;
comment|/* Major driver implementation ver.  */
name|BYTE
name|minVer
decl_stmt|;
comment|/* Minor driver implementation ver.  */
name|BYTE
name|dummyLen
decl_stmt|;
comment|/* length of following data          */
name|WORD
name|MAClength
decl_stmt|;
comment|/* HiPerformance data, N/A           */
name|WORD
name|MTU
decl_stmt|;
comment|/* HiPerformance data, N/A           */
name|WORD
name|multicast
decl_stmt|;
comment|/* HiPerformance data, N/A           */
name|WORD
name|rcvrBuffers
decl_stmt|;
comment|/* valid for                         */
name|WORD
name|UMTbufs
decl_stmt|;
comment|/*   High Performance drivers only   */
name|WORD
name|postEOIintr
decl_stmt|;
comment|/*                  Usage ??         */
block|}
name|PKT_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PKT_PARAM_SIZE
value|14
end_define

begin_comment
comment|/* members majVer - postEOIintr */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|DWORD
name|inPackets
decl_stmt|;
comment|/* # of packets received    */
name|DWORD
name|outPackets
decl_stmt|;
comment|/* # of packets transmitted */
name|DWORD
name|inBytes
decl_stmt|;
comment|/* # of bytes received      */
name|DWORD
name|outBytes
decl_stmt|;
comment|/* # of bytes transmitted   */
name|DWORD
name|inErrors
decl_stmt|;
comment|/* # of reception errors    */
name|DWORD
name|outErrors
decl_stmt|;
comment|/* # of transmission errors */
name|DWORD
name|lost
decl_stmt|;
comment|/* # of packets lost (RX)   */
block|}
name|PKT_STAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ETHER
name|destin
decl_stmt|;
name|ETHER
name|source
decl_stmt|;
name|WORD
name|proto
decl_stmt|;
name|BYTE
name|data
index|[
name|TX_BUF_SIZE
index|]
decl_stmt|;
block|}
name|TX_ELEMENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|WORD
name|firstCount
decl_stmt|;
comment|/* # of bytes on 1st         */
name|WORD
name|secondCount
decl_stmt|;
comment|/* and 2nd upcall            */
name|WORD
name|handle
decl_stmt|;
comment|/* instance that upcalled    */
name|ETHER
name|destin
decl_stmt|;
comment|/* E-net destination address */
name|ETHER
name|source
decl_stmt|;
comment|/* E-net source address      */
name|WORD
name|proto
decl_stmt|;
comment|/* protocol number           */
name|BYTE
name|data
index|[
name|RX_BUF_SIZE
index|]
decl_stmt|;
block|}
name|RX_ELEMENT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__HIGHC__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pop
name|(
name|Align_members
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Prototypes for publics  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|PKT_STAT
name|pktStat
decl_stmt|;
comment|/* statistics for packets */
specifier|extern
name|PKT_INFO
name|pktInfo
decl_stmt|;
comment|/* packet-driver information */
specifier|extern
name|PKT_RX_MODE
name|receiveMode
decl_stmt|;
specifier|extern
name|ETHER
name|myAddress
decl_stmt|,
name|ethBroadcast
decl_stmt|;
specifier|extern
name|BOOL
name|PktInitDriver
parameter_list|(
name|PKT_RX_MODE
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktExitDriver
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|PktGetErrorStr
parameter_list|(
name|int
name|errNum
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|PktGetClassName
parameter_list|(
name|WORD
name|class
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|PktRXmodeStr
parameter_list|(
name|PKT_RX_MODE
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktSearchDriver
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PktReceive
parameter_list|(
name|BYTE
modifier|*
name|buf
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktTransmit
parameter_list|(
specifier|const
name|void
modifier|*
name|eth
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
specifier|extern
name|DWORD
name|PktRxDropped
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktReleaseHandle
parameter_list|(
name|WORD
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktTerminHandle
parameter_list|(
name|WORD
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktResetInterface
parameter_list|(
name|WORD
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktSetReceiverMode
parameter_list|(
name|PKT_RX_MODE
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktGetReceiverMode
parameter_list|(
name|PKT_RX_MODE
modifier|*
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktGetStatistics
parameter_list|(
name|WORD
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktSessStatistics
parameter_list|(
name|WORD
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktResetStatistics
parameter_list|(
name|WORD
name|handle
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktGetAddress
parameter_list|(
name|ETHER
modifier|*
name|addr
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktSetAddress
parameter_list|(
specifier|const
name|ETHER
modifier|*
name|addr
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktGetDriverInfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|BOOL
name|PktGetDriverParam
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PktQueueBusy
parameter_list|(
name|BOOL
name|busy
parameter_list|)
function_decl|;
specifier|extern
name|WORD
name|PktBuffersUsed
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PKTDRVR_H */
end_comment

end_unit

