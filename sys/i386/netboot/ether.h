begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** NETBOOT -  BOOTP/TFTP Bootstrap Program  Author: Martin Renters   Date: Jun/94  **************************************************************************/
end_comment

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

begin_define
define|#
directive|define
name|ETH_MIN_PACKET
value|64
end_define

begin_define
define|#
directive|define
name|ETH_MAX_PACKET
value|1518
end_define

begin_define
define|#
directive|define
name|VENDOR_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VENDOR_WD
value|1
end_define

begin_define
define|#
directive|define
name|VENDOR_NOVELL
value|2
end_define

begin_define
define|#
directive|define
name|FLAG_PIO
value|0x01
end_define

begin_define
define|#
directive|define
name|FLAG_16BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|FLAG_790
value|0x04
end_define

begin_define
define|#
directive|define
name|MEM_8192
value|32
end_define

begin_define
define|#
directive|define
name|MEM_16384
value|64
end_define

begin_define
define|#
directive|define
name|MEM_32768
value|128
end_define

begin_comment
comment|/************************************************************************** Western Digital/SMC Board Definitions **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|WD_LOW_BASE
value|0x200
end_define

begin_define
define|#
directive|define
name|WD_HIGH_BASE
value|0x3e0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WD_DEFAULT_MEM
end_ifndef

begin_define
define|#
directive|define
name|WD_DEFAULT_MEM
value|0xD0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WD_NIC_ADDR
value|0x10
end_define

begin_comment
comment|/************************************************************************** Western Digital/SMC ASIC Addresses **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|WD_MSR
value|0x00
end_define

begin_define
define|#
directive|define
name|WD_ICR
value|0x01
end_define

begin_define
define|#
directive|define
name|WD_IAR
value|0x02
end_define

begin_define
define|#
directive|define
name|WD_BIO
value|0x03
end_define

begin_define
define|#
directive|define
name|WD_IRR
value|0x04
end_define

begin_define
define|#
directive|define
name|WD_LAAR
value|0x05
end_define

begin_define
define|#
directive|define
name|WD_IJR
value|0x06
end_define

begin_define
define|#
directive|define
name|WD_GP2
value|0x07
end_define

begin_define
define|#
directive|define
name|WD_LAR
value|0x08
end_define

begin_define
define|#
directive|define
name|WD_BID
value|0x0E
end_define

begin_define
define|#
directive|define
name|WD_ICR_16BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|WD_MSR_MENB
value|0x40
end_define

begin_define
define|#
directive|define
name|WD_LAAR_L16EN
value|0x40
end_define

begin_define
define|#
directive|define
name|WD_LAAR_M16EN
value|0x80
end_define

begin_define
define|#
directive|define
name|WD_SOFTCONFIG
value|0x20
end_define

begin_comment
comment|/************************************************************************** Western Digital/SMC Board Types **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TYPE_WD8003S
value|0x02
end_define

begin_define
define|#
directive|define
name|TYPE_WD8003E
value|0x03
end_define

begin_define
define|#
directive|define
name|TYPE_WD8013EBT
value|0x05
end_define

begin_define
define|#
directive|define
name|TYPE_WD8003W
value|0x24
end_define

begin_define
define|#
directive|define
name|TYPE_WD8003EB
value|0x25
end_define

begin_define
define|#
directive|define
name|TYPE_WD8013W
value|0x26
end_define

begin_define
define|#
directive|define
name|TYPE_WD8013EP
value|0x27
end_define

begin_define
define|#
directive|define
name|TYPE_WD8013WC
value|0x28
end_define

begin_define
define|#
directive|define
name|TYPE_WD8013EPC
value|0x29
end_define

begin_define
define|#
directive|define
name|TYPE_SMC8216T
value|0x2a
end_define

begin_define
define|#
directive|define
name|TYPE_SMC8216C
value|0x2b
end_define

begin_define
define|#
directive|define
name|TYPE_SMC8013EBP
value|0x2c
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INCLUDE_WD
end_ifdef

begin_struct
struct|struct
name|wd_board
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|id
decl_stmt|;
name|char
name|flags
decl_stmt|;
name|char
name|memsize
decl_stmt|;
block|}
name|wd_boards
index|[]
init|=
block|{
block|{
literal|"WD8003S"
block|,
name|TYPE_WD8003S
block|,
literal|0
block|,
name|MEM_8192
block|}
block|,
block|{
literal|"WD8003E"
block|,
name|TYPE_WD8003E
block|,
literal|0
block|,
name|MEM_8192
block|}
block|,
block|{
literal|"WD8013EBT"
block|,
name|TYPE_WD8013EBT
block|,
name|FLAG_16BIT
block|,
name|MEM_16384
block|}
block|,
block|{
literal|"WD8003W"
block|,
name|TYPE_WD8003W
block|,
literal|0
block|,
name|MEM_8192
block|}
block|,
block|{
literal|"WD8003EB"
block|,
name|TYPE_WD8003EB
block|,
literal|0
block|,
name|MEM_8192
block|}
block|,
block|{
literal|"WD8013W"
block|,
name|TYPE_WD8013W
block|,
name|FLAG_16BIT
block|,
name|MEM_16384
block|}
block|,
block|{
literal|"WD8003EP/WD8013EP"
block|,
name|TYPE_WD8013EP
block|,
literal|0
block|,
name|MEM_8192
block|}
block|,
block|{
literal|"WD8013WC"
block|,
name|TYPE_WD8013WC
block|,
name|FLAG_16BIT
block|,
name|MEM_16384
block|}
block|,
block|{
literal|"WD8013EPC"
block|,
name|TYPE_WD8013EPC
block|,
name|FLAG_16BIT
block|,
name|MEM_16384
block|}
block|,
block|{
literal|"SMC8216T"
block|,
name|TYPE_SMC8216T
block|,
name|FLAG_16BIT
operator||
name|FLAG_790
block|,
name|MEM_16384
block|}
block|,
block|{
literal|"SMC8216C"
block|,
name|TYPE_SMC8216C
block|,
name|FLAG_16BIT
operator||
name|FLAG_790
block|,
name|MEM_16384
block|}
block|,
block|{
literal|"SMC8013EBP"
block|,
name|TYPE_SMC8013EBP
block|,
name|FLAG_16BIT
block|,
name|MEM_16384
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************** NE1000/2000 definitions **************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NE_BASE
end_ifndef

begin_define
define|#
directive|define
name|NE_BASE
value|0x320
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NE_ASIC_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|NE_RESET
value|0x0F
end_define

begin_comment
comment|/* Used to reset card */
end_comment

begin_define
define|#
directive|define
name|NE_DATA
value|0x00
end_define

begin_comment
comment|/* Used to read/write NIC mem */
end_comment

begin_comment
comment|/************************************************************************** 8390 Register Definitions **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|D8390_P0_COMMAND
value|0x00
end_define

begin_define
define|#
directive|define
name|D8390_P0_PSTART
value|0x01
end_define

begin_define
define|#
directive|define
name|D8390_P0_PSTOP
value|0x02
end_define

begin_define
define|#
directive|define
name|D8390_P0_BOUND
value|0x03
end_define

begin_define
define|#
directive|define
name|D8390_P0_TSR
value|0x04
end_define

begin_define
define|#
directive|define
name|D8390_P0_TPSR
value|0x04
end_define

begin_define
define|#
directive|define
name|D8390_P0_TBCR0
value|0x05
end_define

begin_define
define|#
directive|define
name|D8390_P0_TBCR1
value|0x06
end_define

begin_define
define|#
directive|define
name|D8390_P0_ISR
value|0x07
end_define

begin_define
define|#
directive|define
name|D8390_P0_RSAR0
value|0x08
end_define

begin_define
define|#
directive|define
name|D8390_P0_RSAR1
value|0x09
end_define

begin_define
define|#
directive|define
name|D8390_P0_RBCR0
value|0x0A
end_define

begin_define
define|#
directive|define
name|D8390_P0_RBCR1
value|0x0B
end_define

begin_define
define|#
directive|define
name|D8390_P0_RSR
value|0x0C
end_define

begin_define
define|#
directive|define
name|D8390_P0_RCR
value|0x0C
end_define

begin_define
define|#
directive|define
name|D8390_P0_TCR
value|0x0D
end_define

begin_define
define|#
directive|define
name|D8390_P0_DCR
value|0x0E
end_define

begin_define
define|#
directive|define
name|D8390_P0_IMR
value|0x0F
end_define

begin_define
define|#
directive|define
name|D8390_P1_COMMAND
value|0x00
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR0
value|0x01
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR1
value|0x02
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR2
value|0x03
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR3
value|0x04
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR4
value|0x05
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR5
value|0x06
end_define

begin_define
define|#
directive|define
name|D8390_P1_CURR
value|0x07
end_define

begin_define
define|#
directive|define
name|D8390_P1_MAR0
value|0x08
end_define

begin_define
define|#
directive|define
name|D8390_COMMAND_PS0
value|0x0
end_define

begin_comment
comment|/* Page 0 select */
end_comment

begin_define
define|#
directive|define
name|D8390_COMMAND_PS1
value|0x40
end_define

begin_comment
comment|/* Page 1 select */
end_comment

begin_define
define|#
directive|define
name|D8390_COMMAND_PS2
value|0x80
end_define

begin_comment
comment|/* Page 2 select */
end_comment

begin_define
define|#
directive|define
name|D8390_COMMAND_RD2
value|0x20
end_define

begin_comment
comment|/* Remote DMA control */
end_comment

begin_define
define|#
directive|define
name|D8390_COMMAND_RD1
value|0x10
end_define

begin_define
define|#
directive|define
name|D8390_COMMAND_RD0
value|0x08
end_define

begin_define
define|#
directive|define
name|D8390_COMMAND_TXP
value|0x04
end_define

begin_comment
comment|/* transmit packet */
end_comment

begin_define
define|#
directive|define
name|D8390_COMMAND_STA
value|0x02
end_define

begin_comment
comment|/* start */
end_comment

begin_define
define|#
directive|define
name|D8390_COMMAND_STP
value|0x01
end_define

begin_comment
comment|/* stop */
end_comment

begin_define
define|#
directive|define
name|D8390_RCR_MON
value|0x20
end_define

begin_comment
comment|/* monitor mode */
end_comment

begin_define
define|#
directive|define
name|D8390_DCR_FT1
value|0x40
end_define

begin_define
define|#
directive|define
name|D8390_DCR_LS
value|0x08
end_define

begin_comment
comment|/* Loopback select */
end_comment

begin_define
define|#
directive|define
name|D8390_DCR_WTS
value|0x01
end_define

begin_comment
comment|/* Word transfer select */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_PRX
value|0x01
end_define

begin_comment
comment|/* successful recv */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_PTX
value|0x02
end_define

begin_comment
comment|/* successful xmit */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_RXE
value|0x04
end_define

begin_comment
comment|/* receive error */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_TXE
value|0x08
end_define

begin_comment
comment|/* transmit error */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_OVW
value|0x10
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_CNT
value|0x20
end_define

begin_comment
comment|/* Counter overflow */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_RDC
value|0x40
end_define

begin_comment
comment|/* Remote DMA complete */
end_comment

begin_define
define|#
directive|define
name|D8390_ISR_RST
value|0x80
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|D8390_RSTAT_PRX
value|0x01
end_define

begin_comment
comment|/* successful recv */
end_comment

begin_define
define|#
directive|define
name|D8390_RSTAT_CRC
value|0x02
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|D8390_RSTAT_FAE
value|0x04
end_define

begin_comment
comment|/* Frame alignment error */
end_comment

begin_define
define|#
directive|define
name|D8390_RSTAT_OVER
value|0x08
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|D8390_TXBUF_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|D8390_RXBUF_END
value|32
end_define

begin_struct
struct|struct
name|ringbuffer
block|{
name|unsigned
name|char
name|status
decl_stmt|;
name|unsigned
name|char
name|bound
decl_stmt|;
name|unsigned
name|short
name|len
decl_stmt|;
block|}
struct|;
end_struct

end_unit

