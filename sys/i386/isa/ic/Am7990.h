begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Am7990, Local Area Network Controller for Ethernet (LANCE)  *  * Copyright (c) 1994, Paul Richards. This software may be used,  * modified, copied, distributed, and sold, in both source and binary  * form provided that the above copyright and these terms are retained.  * Under no circumstances is the author responsible for the proper  * functioning of this software, nor does the author assume any  * responsibility for damages incurred with its use.  *  */
end_comment

begin_comment
comment|/*  * The LANCE has four Control and Status Registers(CSRs) which are accessed  * through two bus addressable ports, the address port (RAP) and the data  * port (RDP).  *  */
end_comment

begin_define
define|#
directive|define
name|CSR0
value|0
end_define

begin_define
define|#
directive|define
name|CSR1
value|1
end_define

begin_define
define|#
directive|define
name|CSR2
value|2
end_define

begin_define
define|#
directive|define
name|CSR3
value|3
end_define

begin_define
define|#
directive|define
name|CSR88
value|88
end_define

begin_define
define|#
directive|define
name|CSR89
value|89
end_define

begin_define
define|#
directive|define
name|BCR49
value|49
end_define

begin_define
define|#
directive|define
name|BCR32
value|32
end_define

begin_define
define|#
directive|define
name|BCR33
value|33
end_define

begin_define
define|#
directive|define
name|BCR34
value|34
end_define

begin_comment
comment|/* Control and Status Register Masks */
end_comment

begin_comment
comment|/* CSR0 */
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
comment|/*  * CSR3  *  * Bits 3-15 are reserved.  *  */
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
comment|/* Initialisation block */
end_comment

begin_struct
struct|struct
name|init_block
block|{
name|u_short
name|mode
decl_stmt|;
comment|/* Mode register			*/
name|u_char
name|padr
index|[
literal|6
index|]
decl_stmt|;
comment|/* Ethernet address			*/
name|u_char
name|ladrf
index|[
literal|8
index|]
decl_stmt|;
comment|/* Logical address filter (multicast)	*/
name|u_short
name|rdra
decl_stmt|;
comment|/* Low order pointer to receive ring	*/
name|u_short
name|rlen
decl_stmt|;
comment|/* High order pointer and no. rings	*/
name|u_short
name|tdra
decl_stmt|;
comment|/* Low order pointer to transmit ring	*/
name|u_short
name|tlen
decl_stmt|;
comment|/* High order pointer and no rings	*/
block|}
struct|;
end_struct

begin_comment
comment|/* Initialisation Block Mode Register Masks */
end_comment

begin_define
define|#
directive|define
name|PROM
value|0x8000
end_define

begin_comment
comment|/* Promiscuous Mode */
end_comment

begin_define
define|#
directive|define
name|DRCVBC
value|0x4000
end_define

begin_comment
comment|/* Disable Receive Broadcast */
end_comment

begin_define
define|#
directive|define
name|DRCVPA
value|0x2000
end_define

begin_comment
comment|/* Disable Receive Physical Address */
end_comment

begin_define
define|#
directive|define
name|DLNKTST
value|0x1000
end_define

begin_comment
comment|/* Disable Link Status */
end_comment

begin_define
define|#
directive|define
name|DAPC
value|0x0800
end_define

begin_comment
comment|/* Disable Automatic Polarity Correction */
end_comment

begin_define
define|#
directive|define
name|MENDECL
value|0x0400
end_define

begin_comment
comment|/* MENDEC Loopback Mode */
end_comment

begin_define
define|#
directive|define
name|LRT
value|0x0200
end_define

begin_comment
comment|/* Low Receive Threshold (T-MAU mode only) */
end_comment

begin_define
define|#
directive|define
name|TSEL
value|0x0200
end_define

begin_comment
comment|/* Transmit Mode Select  (AUI mode only) */
end_comment

begin_define
define|#
directive|define
name|PORTSEL
value|0x0180
end_define

begin_comment
comment|/* Port Select bits */
end_comment

begin_define
define|#
directive|define
name|INTL
value|0x0040
end_define

begin_comment
comment|/* Internal Loopback */
end_comment

begin_define
define|#
directive|define
name|DRTY
value|0x0020
end_define

begin_comment
comment|/* Disable Retry */
end_comment

begin_define
define|#
directive|define
name|FCOLL
value|0x0010
end_define

begin_comment
comment|/* Force Collision */
end_comment

begin_define
define|#
directive|define
name|DXMTFCS
value|0x0008
end_define

begin_comment
comment|/* Disable transmit CRC (FCS) */
end_comment

begin_define
define|#
directive|define
name|LOOP
value|0x0004
end_define

begin_comment
comment|/* Loopback Enabl */
end_comment

begin_define
define|#
directive|define
name|DTX
value|0x0002
end_define

begin_comment
comment|/* Disable the transmitter */
end_comment

begin_define
define|#
directive|define
name|DRX
value|0x0001
end_define

begin_comment
comment|/* Disable the receiver */
end_comment

begin_comment
comment|/*  * Message Descriptor Structure  *  * Each transmit or receive descriptor ring entry (RDRE's and TDRE's)  * is composed of 4, 16-bit, message descriptors. They contain the following  * information.  *  * 1. The address of the actual message data buffer in user (host) memory.  * 2. The length of that message buffer.  * 3. The status information for that particular buffer. The eight most  *    significant bits of md1 are collectively termed the STATUS of the  *    descriptor.  *  * Descriptor md0 contains LADR 0-15, the low order 16 bits of the 24-bit  * address of the actual data buffer.  Bits 0-7 of descriptor md1 contain  * HADR, the high order 8-bits of the 24-bit data buffer address. Bits 8-15  * of md1 contain the status flags of the buffer. Descriptor md2 contains the  * buffer byte count in bits 0-11 as a two's complement number and must have  * 1's written to bits 12-15. For the receive entry md3 has the Message Byte  * Count in bits 0-11, this is the length of the received message and is valid  * only when ERR is cleared and ENP is set. For the transmit entry it contains  * more status information.  *  */
end_comment

begin_struct
struct|struct
name|mds
block|{
name|u_short
name|md0
decl_stmt|;
name|u_short
name|md1
decl_stmt|;
name|short
name|md2
decl_stmt|;
name|u_short
name|md3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Receive STATUS flags for md1 */
end_comment

begin_define
define|#
directive|define
name|OWN
value|0x8000
end_define

begin_comment
comment|/* Owner bit, 0=host, 1=Lance   */
end_comment

begin_define
define|#
directive|define
name|MDERR
value|0x4000
end_define

begin_comment
comment|/* Error                        */
end_comment

begin_define
define|#
directive|define
name|FRAM
value|0x2000
end_define

begin_comment
comment|/* Framing error error          */
end_comment

begin_define
define|#
directive|define
name|OFLO
value|0x1000
end_define

begin_comment
comment|/* Silo overflow                */
end_comment

begin_define
define|#
directive|define
name|CRC
value|0x0800
end_define

begin_comment
comment|/* CRC error                    */
end_comment

begin_define
define|#
directive|define
name|RBUFF
value|0x0400
end_define

begin_comment
comment|/* Buffer error                 */
end_comment

begin_define
define|#
directive|define
name|STP
value|0x0200
end_define

begin_comment
comment|/* Start of packet              */
end_comment

begin_define
define|#
directive|define
name|ENP
value|0x0100
end_define

begin_comment
comment|/* End of packet                */
end_comment

begin_define
define|#
directive|define
name|HADR
value|0x00FF
end_define

begin_comment
comment|/* High order address bits	*/
end_comment

begin_comment
comment|/* Receive STATUS flags for md2 */
end_comment

begin_define
define|#
directive|define
name|BCNT
value|0x0FFF
end_define

begin_comment
comment|/* Size of data buffer as 2's comp. no. */
end_comment

begin_comment
comment|/* Receive STATUS flags for md3 */
end_comment

begin_define
define|#
directive|define
name|MCNT
value|0x0FFF
end_define

begin_comment
comment|/* Total size of data for received packet */
end_comment

begin_comment
comment|/* Transmit STATUS flags for md1 */
end_comment

begin_define
define|#
directive|define
name|ADD_FCS
value|0x2000
end_define

begin_comment
comment|/* Controls generation of FCS	*/
end_comment

begin_define
define|#
directive|define
name|MORE
value|0x1000
end_define

begin_comment
comment|/* Indicates more than one retry was needed */
end_comment

begin_define
define|#
directive|define
name|ONE
value|0x0800
end_define

begin_comment
comment|/* Exactly one retry was needed */
end_comment

begin_define
define|#
directive|define
name|DEF
value|0x0400
end_define

begin_comment
comment|/* Packet transmit deferred -- channel busy */
end_comment

begin_comment
comment|/*  * Transmit status flags for md2  *  * Same as for receive descriptor.  *  * BCNT   0x0FFF         Size of data buffer as 2's complement number.  *  */
end_comment

begin_comment
comment|/* Transmit status flags for md3 */
end_comment

begin_define
define|#
directive|define
name|TBUFF
value|0x8000
end_define

begin_comment
comment|/* Buffer error         */
end_comment

begin_define
define|#
directive|define
name|UFLO
value|0x4000
end_define

begin_comment
comment|/* Silo underflow       */
end_comment

begin_define
define|#
directive|define
name|LCOL
value|0x1000
end_define

begin_comment
comment|/* Late collision       */
end_comment

begin_define
define|#
directive|define
name|LCAR
value|0x0800
end_define

begin_comment
comment|/* Loss of carrier      */
end_comment

begin_define
define|#
directive|define
name|RTRY
value|0x0400
end_define

begin_comment
comment|/* Tried 16 times       */
end_comment

begin_define
define|#
directive|define
name|TDR
value|0x03FF
end_define

begin_comment
comment|/* Time domain reflectometry */
end_comment

end_unit

