begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations specific to this driver */
end_comment

begin_define
define|#
directive|define
name|NTBUF
value|2
end_define

begin_define
define|#
directive|define
name|TLEN
value|1
end_define

begin_define
define|#
directive|define
name|NRBUF
value|8
end_define

begin_define
define|#
directive|define
name|RLEN
value|3
end_define

begin_define
define|#
directive|define
name|BUFSIZE
value|1518
end_define

begin_define
define|#
directive|define
name|RAP
value|0xe
end_define

begin_define
define|#
directive|define
name|RDP
value|0xc
end_define

begin_comment
comment|/* Control and status register 0 flags */
end_comment

begin_define
define|#
directive|define
name|ERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|BABL
value|0x4000
end_define

begin_define
define|#
directive|define
name|CERR
value|0x2000
end_define

begin_define
define|#
directive|define
name|MISS
value|0x1000
end_define

begin_define
define|#
directive|define
name|MERR
value|0x0800
end_define

begin_define
define|#
directive|define
name|RINT
value|0x0400
end_define

begin_define
define|#
directive|define
name|TINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|IDON
value|0x0100
end_define

begin_define
define|#
directive|define
name|INTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|INEA
value|0x0040
end_define

begin_define
define|#
directive|define
name|RXON
value|0x0020
end_define

begin_define
define|#
directive|define
name|TXON
value|0x0010
end_define

begin_define
define|#
directive|define
name|TDMD
value|0x0008
end_define

begin_define
define|#
directive|define
name|STOP
value|0x0004
end_define

begin_define
define|#
directive|define
name|STRT
value|0x0002
end_define

begin_define
define|#
directive|define
name|INIT
value|0x0001
end_define

begin_comment
comment|/* Coontrol and status register 3 flags */
end_comment

begin_define
define|#
directive|define
name|BSWP
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACON
value|0x0002
end_define

begin_define
define|#
directive|define
name|BCON
value|0x0001
end_define

begin_comment
comment|/* Initialisation block (must be on word boundary) */
end_comment

begin_struct
struct|struct
name|init_block
block|{
name|u_short
name|mode
decl_stmt|;
comment|/* Mode register 			*/
name|u_char
name|padr
index|[
literal|6
index|]
decl_stmt|;
comment|/* Ethernet address 			*/
name|u_char
name|ladrf
index|[
literal|8
index|]
decl_stmt|;
comment|/* Logical address filter (multicast) 	*/
name|u_short
name|rdra
decl_stmt|;
comment|/* Low order pointer to receive ring 	*/
name|u_short
name|rlen
decl_stmt|;
comment|/* High order pointer and no. rings 	*/
name|u_short
name|tdra
decl_stmt|;
comment|/* Low order pointer to transmit ring 	*/
name|u_short
name|tlen
decl_stmt|;
comment|/* High order pointer and no rings 	*/
block|}
struct|;
end_struct

begin_comment
comment|/* Mode settings */
end_comment

begin_define
define|#
directive|define
name|PROM
value|0x8000
end_define

begin_comment
comment|/* Promiscuous		*/
end_comment

begin_define
define|#
directive|define
name|INTL
value|0x0040
end_define

begin_comment
comment|/* Internal loopback	*/
end_comment

begin_define
define|#
directive|define
name|DRTY
value|0x0020
end_define

begin_comment
comment|/* Disable retry 	*/
end_comment

begin_define
define|#
directive|define
name|COLL
value|0x0010
end_define

begin_comment
comment|/* Force collision 	*/
end_comment

begin_define
define|#
directive|define
name|DTCR
value|0x0008
end_define

begin_comment
comment|/* Disable transmit crc	*/
end_comment

begin_define
define|#
directive|define
name|LOOP
value|0x0004
end_define

begin_comment
comment|/* Loop back 		*/
end_comment

begin_define
define|#
directive|define
name|DTX
value|0x0002
end_define

begin_comment
comment|/* Disable transmitter 	*/
end_comment

begin_define
define|#
directive|define
name|DRX
value|0x0001
end_define

begin_comment
comment|/* Disable receiver 	*/
end_comment

begin_comment
comment|/* Message descriptor structure */
end_comment

begin_struct
struct|struct
name|mds
block|{
name|u_short
name|addr
decl_stmt|;
name|u_short
name|flags
decl_stmt|;
name|u_short
name|bcnt
decl_stmt|;
name|u_short
name|mcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Receive ring status flags */
end_comment

begin_define
define|#
directive|define
name|OWN
value|0x8000
end_define

begin_comment
comment|/* Owner bit, 0=host, 1=Lance 	*/
end_comment

begin_define
define|#
directive|define
name|MDERR
value|0x4000
end_define

begin_comment
comment|/* Error 			*/
end_comment

begin_define
define|#
directive|define
name|FRAM
value|0x2000
end_define

begin_comment
comment|/* Framing error error 		*/
end_comment

begin_define
define|#
directive|define
name|OFLO
value|0x1000
end_define

begin_comment
comment|/* Silo overflow 		*/
end_comment

begin_define
define|#
directive|define
name|CRC
value|0x0800
end_define

begin_comment
comment|/* CRC error 			*/
end_comment

begin_define
define|#
directive|define
name|RBUFF
value|0x0400
end_define

begin_comment
comment|/* Buffer error 		*/
end_comment

begin_define
define|#
directive|define
name|STP
value|0x0200
end_define

begin_comment
comment|/* Start of packet 		*/
end_comment

begin_define
define|#
directive|define
name|ENP
value|0x0100
end_define

begin_comment
comment|/* End of packet 		*/
end_comment

begin_comment
comment|/* Transmit ring flags */
end_comment

begin_define
define|#
directive|define
name|MORE
value|0x1000
end_define

begin_comment
comment|/* More than 1 retry 	*/
end_comment

begin_define
define|#
directive|define
name|ONE
value|0x0800
end_define

begin_comment
comment|/* One retry 		*/
end_comment

begin_define
define|#
directive|define
name|DEF
value|0x0400
end_define

begin_comment
comment|/* Deferred transmit 	*/
end_comment

begin_comment
comment|/* Transmit errors */
end_comment

begin_define
define|#
directive|define
name|TBUFF
value|0x8000
end_define

begin_comment
comment|/* Buffer error 	*/
end_comment

begin_define
define|#
directive|define
name|UFLO
value|0x4000
end_define

begin_comment
comment|/* Silo underflow	*/
end_comment

begin_define
define|#
directive|define
name|LCOL
value|0x1000
end_define

begin_comment
comment|/* Late collision 	*/
end_comment

begin_define
define|#
directive|define
name|LCAR
value|0x0800
end_define

begin_comment
comment|/* Loss of carrier 	*/
end_comment

begin_define
define|#
directive|define
name|RTRY
value|0x0400
end_define

begin_comment
comment|/* Tried 16 times 	*/
end_comment

end_unit

