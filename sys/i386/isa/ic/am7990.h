begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	AMD 7990 (LANCE) definitions  *  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|LN_BITFIELD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|b, a
end_define

begin_define
define|#
directive|define
name|LN_BITFIELD3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|c, b, a
end_define

begin_define
define|#
directive|define
name|LN_BITFIELD4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|d, c, b, a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LN_BITFIELD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a, b
end_define

begin_define
define|#
directive|define
name|LN_BITFIELD3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a, b, c
end_define

begin_define
define|#
directive|define
name|LN_BITFIELD4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a, b, c, d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LN_ADDR_LO
parameter_list|(
name|addr
parameter_list|)
value|((addr)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|LN_ADDR_HI
parameter_list|(
name|addr
parameter_list|)
value|(((addr)>> 16)& 0xFF)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|r_addr_lo
decl_stmt|;
name|unsigned
name|int
name|LN_BITFIELD3
decl|(
name|r_addr_hi
decl|: 8
decl_stmt|,
range|:
literal|5
decl_stmt|,
name|r_log2_size
range|:
literal|3
range|)
decl_stmt|;
block|}
name|ln_ring_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LN_MC_MASK
value|0x3F
end_define

begin_comment
comment|/* Only 6 bits of the CRC */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|ln_mode
decl_stmt|;
define|#
directive|define
name|LN_MODE_RXD
value|0x0001
comment|/* ( W)  Receiver Disabled */
define|#
directive|define
name|LN_MODE_TXD
value|0x0002
comment|/* ( W)  Transmitter Disabled */
define|#
directive|define
name|LN_MODE_LOOP
value|0x0004
comment|/* ( W)  Enable Loopback */
define|#
directive|define
name|LN_MODE_NOTXCRC
value|0x0008
comment|/* ( W)  Don't Calculate TX CRCs */
define|#
directive|define
name|LN_MODE_FRCCOLL
value|0x0010
comment|/* ( W)  Force Collision */
define|#
directive|define
name|LN_MODE_NORETRY
value|0x0020
comment|/* ( W)  No Transmit Retries */
define|#
directive|define
name|LN_MODE_INTLOOP
value|0x0040
comment|/* ( W)  Internal Loopback */
define|#
directive|define
name|LN_MODE_PROMISC
value|0x8000
comment|/* ( W)  Promiscious Mode */
name|unsigned
name|short
name|ln_physaddr
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|short
name|ln_multi_mask
index|[
literal|4
index|]
decl_stmt|;
name|ln_ring_t
name|ln_rxring
decl_stmt|;
name|ln_ring_t
name|ln_txring
decl_stmt|;
block|}
name|ln_initb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|d_addr_lo
decl_stmt|;
name|unsigned
name|char
name|d_addr_hi
decl_stmt|;
name|unsigned
name|char
name|d_flag
decl_stmt|;
define|#
directive|define
name|LN_DFLAG_EOP
value|0x0001
comment|/* (RW)  End Of Packet */
define|#
directive|define
name|LN_DFLAG_SOP
value|0x0002
comment|/* (RW)  Start Of Packet */
define|#
directive|define
name|LN_DFLAG_RxBUFERROR
value|0x0004
comment|/* (R )  Receive  - Buffer Error */
define|#
directive|define
name|LN_DFLAG_TxDEFERRED
value|0x0004
comment|/* (R )  Transmit - Initially Deferred */
define|#
directive|define
name|LN_DFLAG_RxBADCRC
value|0x0008
comment|/* (R )  Receive  - Bad Checksum */
define|#
directive|define
name|LN_DFLAG_TxONECOLL
value|0x0008
comment|/* (R )  Transmit - Single Collision */
define|#
directive|define
name|LN_DFLAG_RxOVERFLOW
value|0x0010
comment|/* (R )  Receive  - Overflow Error */
define|#
directive|define
name|LN_DFLAG_TxMULTCOLL
value|0x0010
comment|/* (R )  Transmit - Multiple Collisions */
define|#
directive|define
name|LN_DFLAG_RxFRAMING
value|0x0020
comment|/* (R )  Receive  - Framing Error */
define|#
directive|define
name|LN_DFLAG_RxERRSUM
value|0x0040
comment|/* (R )  Receive  - Error Summary */
define|#
directive|define
name|LN_DFLAG_TxERRSUM
value|0x0040
comment|/* (R )  Transmit - Error Summary */
define|#
directive|define
name|LN_DFLAG_OWNER
value|0x0080
comment|/* (RW)  Owner (1=Am7990, 0=host) */
name|signed
name|short
name|d_buflen
decl_stmt|;
comment|/* ( W)  Two's complement */
name|unsigned
name|short
name|d_status
decl_stmt|;
define|#
directive|define
name|LN_DSTS_RxLENMASK
value|0x0FFF
comment|/* (R )  Recieve Length */
define|#
directive|define
name|LN_DSTS_TxTDRMASK
value|0x03FF
comment|/* (R )  Transmit - Time Domain Reflectometer */
define|#
directive|define
name|LN_DSTS_TxEXCCOLL
value|0x0400
comment|/* (R )  Transmit - Excessive Collisions */
define|#
directive|define
name|LN_DSTS_TxCARRLOSS
value|0x0800
comment|/* (R )  Transmit - Carrier Loss */
define|#
directive|define
name|LN_DSTS_TxLATECOLL
value|0x1000
comment|/* (R )  Transmit - Late Collision */
define|#
directive|define
name|LN_DSTS_TxUNDERFLOW
value|0x4000
comment|/* (R )  Transmit - Underflow */
define|#
directive|define
name|LN_DSTS_TxBUFERROR
value|0x8000
comment|/* (R )  Transmit - Buffer Error */
block|}
name|ln_desc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LN_CSR0
value|0x0000
end_define

begin_define
define|#
directive|define
name|LN_CSR0_INIT
value|0x0001
end_define

begin_comment
comment|/* (RS)  Initialize Am 7990 */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_START
value|0x0002
end_define

begin_comment
comment|/* (RS)  Start Am7990 */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_STOP
value|0x0004
end_define

begin_comment
comment|/* (RS)  Reset Am7990 */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_TXDEMAND
value|0x0008
end_define

begin_comment
comment|/* (RS)  Transmit On Demand */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_TXON
value|0x0010
end_define

begin_comment
comment|/* (R )  Transmitter Enabled */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_RXON
value|0x0020
end_define

begin_comment
comment|/* (R )  Receiver Enabled */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_ENABINTR
value|0x0040
end_define

begin_comment
comment|/* (RW)  Interrupt Enabled */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_PENDINTR
value|0x0080
end_define

begin_comment
comment|/* (R )  Interrupt Pending */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_INITDONE
value|0x0100
end_define

begin_comment
comment|/* (RC)  Initialization Done */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_TXINT
value|0x0200
end_define

begin_comment
comment|/* (RC)  Transmit Interrupt */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_RXINT
value|0x0400
end_define

begin_comment
comment|/* (RC)  Receive Interrupt */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_MEMERROR
value|0x0800
end_define

begin_comment
comment|/* (RC)  Memory Error */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_MISS
value|0x1000
end_define

begin_comment
comment|/* (RC)  No Available Receive Buffers */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_CERR
value|0x2000
end_define

begin_comment
comment|/* (RC)  SQE failed */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_BABL
value|0x4000
end_define

begin_comment
comment|/* (RC)  Transmit Babble */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_ERRSUM
value|0x8000
end_define

begin_comment
comment|/* (R )  Error Summary (last 4) */
end_comment

begin_define
define|#
directive|define
name|LN_CSR0_CLEAR
value|0x7F00
end_define

begin_comment
comment|/*       Clear Status Bit */
end_comment

begin_comment
comment|/*  * CSR1 -- Init Block Address (Low 16 Bits -- Must be Word Aligned)  * CSR2 -- Init Block Address (High 8 Bits)  */
end_comment

begin_define
define|#
directive|define
name|LN_CSR1
value|0x0001
end_define

begin_define
define|#
directive|define
name|LN_CSR2
value|0x0002
end_define

begin_comment
comment|/*  * CSR3 -- Hardware Control  */
end_comment

begin_define
define|#
directive|define
name|LN_CSR3
value|0x0003
end_define

begin_define
define|#
directive|define
name|LN_CSR3_BCON
value|0x0001
end_define

begin_comment
comment|/* (RW)  BM/HOLD Control */
end_comment

begin_define
define|#
directive|define
name|LN_CSR3_ALE
value|0x0002
end_define

begin_comment
comment|/* (RW)  ALE Control */
end_comment

begin_define
define|#
directive|define
name|LN_CSR3_BSWP
value|0x0004
end_define

begin_comment
comment|/* (RW)  Byte Swap */
end_comment

end_unit

