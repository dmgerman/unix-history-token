begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** NETBOOT -  BOOTP/TFTP Bootstrap Program  Author: Martin Renters   Date: Jun/94  **************************************************************************/
end_comment

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
name|TYPE_SMC8416T
value|0x00
end_define

begin_comment
comment|/* Bogus entries: the 8416 generates the */
end_comment

begin_define
define|#
directive|define
name|TYPE_SMC8416C
value|0x00
end_define

begin_comment
comment|/* the same codes as the 8216. */
end_comment

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
literal|"SMC8416T"
block|,
name|TYPE_SMC8416T
block|,
name|FLAG_16BIT
operator||
name|FLAG_790
block|,
name|MEM_8192
block|}
block|,
block|{
literal|"SMC8416C/BT"
block|,
name|TYPE_SMC8416C
block|,
name|FLAG_16BIT
operator||
name|FLAG_790
block|,
name|MEM_8192
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
comment|/************************************************************************** 3com 3c503 definitions **************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_3COM_BASE
end_ifndef

begin_define
define|#
directive|define
name|_3COM_BASE
value|0x300
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_3COM_TX_PAGE_OFFSET_8BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|_3COM_TX_PAGE_OFFSET_16BIT
value|0x0
end_define

begin_define
define|#
directive|define
name|_3COM_RX_PAGE_OFFSET_16BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|_3COM_ASIC_OFFSET
value|0x400
end_define

begin_define
define|#
directive|define
name|_3COM_NIC_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|_3COM_PSTR
value|0
end_define

begin_define
define|#
directive|define
name|_3COM_PSPR
value|1
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR
value|3
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_2E0
value|0x01
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_2A0
value|0x02
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_280
value|0x04
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_250
value|0x08
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_350
value|0x10
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_330
value|0x20
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_310
value|0x40
end_define

begin_define
define|#
directive|define
name|_3COM_BCFR_300
value|0x80
end_define

begin_define
define|#
directive|define
name|_3COM_PCFR
value|4
end_define

begin_define
define|#
directive|define
name|_3COM_PCFR_C8000
value|0x10
end_define

begin_define
define|#
directive|define
name|_3COM_PCFR_CC000
value|0x20
end_define

begin_define
define|#
directive|define
name|_3COM_PCFR_D8000
value|0x40
end_define

begin_define
define|#
directive|define
name|_3COM_PCFR_DC000
value|0x80
end_define

begin_define
define|#
directive|define
name|_3COM_CR
value|6
end_define

begin_define
define|#
directive|define
name|_3COM_CR_RST
value|0x01
end_define

begin_comment
comment|/* Reset GA and NIC */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_XSEL
value|0x02
end_define

begin_comment
comment|/* Transceiver select. BNC=1(def) AUI=0 */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_EALO
value|0x04
end_define

begin_comment
comment|/* window EA PROM 0-15 to I/O base */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_EAHI
value|0x08
end_define

begin_comment
comment|/* window EA PROM 16-31 to I/O base */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_SHARE
value|0x10
end_define

begin_comment
comment|/* select interrupt sharing option */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_DBSEL
value|0x20
end_define

begin_comment
comment|/* Double buffer select */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_DDIR
value|0x40
end_define

begin_comment
comment|/* DMA direction select */
end_comment

begin_define
define|#
directive|define
name|_3COM_CR_START
value|0x80
end_define

begin_comment
comment|/* Start DMA controller */
end_comment

begin_define
define|#
directive|define
name|_3COM_GACFR
value|5
end_define

begin_define
define|#
directive|define
name|_3COM_GACFR_MBS0
value|0x01
end_define

begin_define
define|#
directive|define
name|_3COM_GACFR_MBS1
value|0x02
end_define

begin_define
define|#
directive|define
name|_3COM_GACFR_MBS2
value|0x04
end_define

begin_define
define|#
directive|define
name|_3COM_GACFR_RSEL
value|0x08
end_define

begin_comment
comment|/* enable shared memory */
end_comment

begin_define
define|#
directive|define
name|_3COM_GACFR_TEST
value|0x10
end_define

begin_comment
comment|/* for GA testing */
end_comment

begin_define
define|#
directive|define
name|_3COM_GACFR_OWS
value|0x20
end_define

begin_comment
comment|/* select 0WS access to GA */
end_comment

begin_define
define|#
directive|define
name|_3COM_GACFR_TCM
value|0x40
end_define

begin_comment
comment|/* Mask DMA interrupts */
end_comment

begin_define
define|#
directive|define
name|_3COM_GACFR_NIM
value|0x80
end_define

begin_comment
comment|/* Mask NIC interrupts */
end_comment

begin_define
define|#
directive|define
name|_3COM_STREG
value|7
end_define

begin_define
define|#
directive|define
name|_3COM_STREG_REV
value|0x07
end_define

begin_comment
comment|/* GA revision */
end_comment

begin_define
define|#
directive|define
name|_3COM_STREG_DIP
value|0x08
end_define

begin_comment
comment|/* DMA in progress */
end_comment

begin_define
define|#
directive|define
name|_3COM_STREG_DTC
value|0x10
end_define

begin_comment
comment|/* DMA terminal count */
end_comment

begin_define
define|#
directive|define
name|_3COM_STREG_OFLW
value|0x20
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|_3COM_STREG_UFLW
value|0x40
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|_3COM_STREG_DPRDY
value|0x80
end_define

begin_comment
comment|/* Data port ready */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR
value|8
end_define

begin_define
define|#
directive|define
name|_3COM_IDCFR_DRQ0
value|0x01
end_define

begin_comment
comment|/* DMA request 1 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_DRQ1
value|0x02
end_define

begin_comment
comment|/* DMA request 2 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_DRQ2
value|0x04
end_define

begin_comment
comment|/* DMA request 3 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_UNUSED
value|0x08
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_IRQ2
value|0x10
end_define

begin_comment
comment|/* Interrupt request 2 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_IRQ3
value|0x20
end_define

begin_comment
comment|/* Interrupt request 3 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_IRQ4
value|0x40
end_define

begin_comment
comment|/* Interrupt request 4 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IDCFR_IRQ5
value|0x80
end_define

begin_comment
comment|/* Interrupt request 5 select */
end_comment

begin_define
define|#
directive|define
name|_3COM_IRQ2
value|2
end_define

begin_define
define|#
directive|define
name|_3COM_IRQ3
value|3
end_define

begin_define
define|#
directive|define
name|_3COM_IRQ4
value|4
end_define

begin_define
define|#
directive|define
name|_3COM_IRQ5
value|5
end_define

begin_define
define|#
directive|define
name|_3COM_DAMSB
value|9
end_define

begin_define
define|#
directive|define
name|_3COM_DALSB
value|0x0a
end_define

begin_define
define|#
directive|define
name|_3COM_VPTR2
value|0x0b
end_define

begin_define
define|#
directive|define
name|_3COM_VPTR1
value|0x0c
end_define

begin_define
define|#
directive|define
name|_3COM_VPTR0
value|0x0d
end_define

begin_define
define|#
directive|define
name|_3COM_RFMSB
value|0x0e
end_define

begin_define
define|#
directive|define
name|_3COM_RFLSB
value|0x0f
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|NE_ASIC_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|NE_RESET
value|0x300
end_define

begin_comment
comment|/* Used to reset card */
end_comment

begin_define
define|#
directive|define
name|NE_DATA
value|0x200
end_define

begin_comment
comment|/* Used to read/write NIC mem */
end_comment

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************** 8390 Register Definitions **************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC98
argument_list|)
operator|||
name|defined
argument_list|(
name|INCLUDE_LGY
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|TYPE98_LGY
value|0x10
end_define

begin_define
define|#
directive|define
name|TYPE98_EGY
value|0x11
end_define

begin_define
define|#
directive|define
name|TYPE98_ICM
value|0x12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INCLUDE_EGY
end_ifdef

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
value|0x02
end_define

begin_define
define|#
directive|define
name|D8390_P0_PSTOP
value|0x04
end_define

begin_define
define|#
directive|define
name|D8390_P0_BOUND
value|0x06
end_define

begin_define
define|#
directive|define
name|D8390_P0_TSR
value|0x08
end_define

begin_define
define|#
directive|define
name|D8390_P0_TPSR
value|0x08
end_define

begin_define
define|#
directive|define
name|D8390_P0_TBCR0
value|0x0a
end_define

begin_define
define|#
directive|define
name|D8390_P0_TBCR1
value|0x0c
end_define

begin_define
define|#
directive|define
name|D8390_P0_ISR
value|0x0e
end_define

begin_define
define|#
directive|define
name|D8390_P0_RSAR0
value|0x100
end_define

begin_define
define|#
directive|define
name|D8390_P0_RSAR1
value|0x102
end_define

begin_define
define|#
directive|define
name|D8390_P0_RBCR0
value|0x104
end_define

begin_define
define|#
directive|define
name|D8390_P0_RBCR1
value|0x106
end_define

begin_define
define|#
directive|define
name|D8390_P0_RSR
value|0x108
end_define

begin_define
define|#
directive|define
name|D8390_P0_RCR
value|0x108
end_define

begin_define
define|#
directive|define
name|D8390_P0_TCR
value|0x10a
end_define

begin_define
define|#
directive|define
name|D8390_P0_DCR
value|0x10c
end_define

begin_define
define|#
directive|define
name|D8390_P0_IMR
value|0x10e
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
value|0x02
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR1
value|0x04
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR2
value|0x06
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR3
value|0x08
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR4
value|0x0a
end_define

begin_define
define|#
directive|define
name|D8390_P1_PAR5
value|0x0c
end_define

begin_define
define|#
directive|define
name|D8390_P1_CURR
value|0x0e
end_define

begin_define
define|#
directive|define
name|D8390_P1_MAR0
value|0x100
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|D8390_PAGE_SIZE
value|256
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

