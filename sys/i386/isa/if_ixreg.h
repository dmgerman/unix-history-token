begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995  *	Rodney W. Grimes, Milwaukie, Oregon  97222.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Rodney W. Grimes.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RODNEY W. GRIMES ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL RODNEY W. GRIMES BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * These really belong some place else, but I can't find them right  * now.  I'll look again latter  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ADDRESS_LENGTH
value|6
end_define

begin_comment
comment|/* Length of an ethernet address */
end_comment

begin_define
define|#
directive|define
name|ETHER_HEADER_LENGTH
value|14
end_define

begin_comment
comment|/* Length of an ethernet header */
end_comment

begin_define
define|#
directive|define
name|ETHER_DATA_LENGTH
value|ETHERMTU
end_define

begin_define
define|#
directive|define
name|ETHER_CRC_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|ETHER_MIN_LENGTH
value|64
end_define

begin_comment
comment|/* Minimum length of an ethernet packet */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAX_LENGTH
value|(ETHER_HEADER_LENGTH + \ 				 ETHERMTU + \ 				 ETHER_CRC_LENGTH)
end_define

begin_define
define|#
directive|define
name|IX_IO_PORTS
value|16
end_define

begin_comment
comment|/* Number of I/O ports used, note 				 * this is not true, due to shadow 				 * ports at 400X,800X and C00X 				 */
end_comment

begin_define
define|#
directive|define
name|dxreg
value|0x00
end_define

begin_comment
comment|/* Data transfer register	Word R/W */
end_comment

begin_define
define|#
directive|define
name|wrptr
value|0x02
end_define

begin_comment
comment|/* Write address pointer	Word R/W */
end_comment

begin_define
define|#
directive|define
name|rdptr
value|0x04
end_define

begin_comment
comment|/* Read address pointer		Word R/W */
end_comment

begin_define
define|#
directive|define
name|ca_ctrl
value|0x06
end_define

begin_comment
comment|/* Channel attention control	Byte R/W */
end_comment

begin_define
define|#
directive|define
name|sel_irq
value|0x07
end_define

begin_comment
comment|/* IRQ select			Byte R/W */
end_comment

begin_define
define|#
directive|define
name|IRQ_ENABLE
value|0x08
end_define

begin_comment
comment|/* Enable board interrupts */
end_comment

begin_define
define|#
directive|define
name|smb_ptr
value|0x08
end_define

begin_comment
comment|/* Shadow memory bank pointer	Word R/W */
end_comment

begin_define
define|#
directive|define
name|memdec
value|0x0A
end_define

begin_comment
comment|/* Memory address decode	Byte   W */
end_comment

begin_define
define|#
directive|define
name|memctrl
value|0x0B
end_define

begin_comment
comment|/* Memory mapped control	Byte R/W */
end_comment

begin_define
define|#
directive|define
name|MEMCTRL_UNUSED
value|0x83
end_define

begin_comment
comment|/* Unused bits */
end_comment

begin_define
define|#
directive|define
name|MEMCTRL_MEMMEG
value|0x60
end_define

begin_comment
comment|/* Which megabyte of memory, 0, E or F */
end_comment

begin_define
define|#
directive|define
name|MEMCTRL_FMCS16
value|0x10
end_define

begin_comment
comment|/* MEMCS16- for F000 */
end_comment

begin_define
define|#
directive|define
name|MEMCTRL_MEMADJ
value|0xC0
end_define

begin_comment
comment|/* memory adjust value */
end_comment

begin_define
define|#
directive|define
name|mempc
value|0x0C
end_define

begin_comment
comment|/* MEMCS16- page control	Byte R/W */
end_comment

begin_define
define|#
directive|define
name|config
value|0x0D
end_define

begin_comment
comment|/* Configuration, test		Byte R/W */
end_comment

begin_define
define|#
directive|define
name|BART_LINK
value|0x01
end_define

begin_comment
comment|/* link integrity active, TPE */
end_comment

begin_define
define|#
directive|define
name|BART_LOOPBACK
value|0x02
end_define

begin_comment
comment|/* Loopback, 0=none, 1=loopback */
end_comment

begin_define
define|#
directive|define
name|SLOT_WIDTH
value|0x04
end_define

begin_comment
comment|/* 0 = 8bit, 1 = 16bit */
end_comment

begin_define
define|#
directive|define
name|BART_USEWIDTH
value|0x08
end_define

begin_comment
comment|/* use SLOT_WIDTH for bus size */
end_comment

begin_define
define|#
directive|define
name|BART_IOCHRDY_LATE
value|0x10
end_define

begin_comment
comment|/* iochrdy late control bit */
end_comment

begin_define
define|#
directive|define
name|BART_IO_TEST_EN
value|0x20
end_define

begin_comment
comment|/* enable iochrdy timing test */
end_comment

begin_define
define|#
directive|define
name|BART_IO_RESULT
value|0x40
end_define

begin_comment
comment|/* result of the iochrdy test */
end_comment

begin_define
define|#
directive|define
name|BART_MCS16_TEST
value|0x80
end_define

begin_comment
comment|/* enable memcs16 select test */
end_comment

begin_define
define|#
directive|define
name|ee_ctrl
value|0x0E
end_define

begin_comment
comment|/* EEPROM control, reset	Byte R/W */
end_comment

begin_define
define|#
directive|define
name|EENORMAL
value|0x00
end_define

begin_comment
comment|/* normal state of ee_ctrl */
end_comment

begin_define
define|#
directive|define
name|EESK
value|0x01
end_define

begin_comment
comment|/* EEPROM clock bit */
end_comment

begin_define
define|#
directive|define
name|EECS
value|0x02
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|EEDI
value|0x04
end_define

begin_comment
comment|/* EEPROM data in bit (write EEPROM) */
end_comment

begin_define
define|#
directive|define
name|EEDO
value|0x08
end_define

begin_comment
comment|/* EEPROM data out bit (read EEPROM) */
end_comment

begin_define
define|#
directive|define
name|EEUNUSED
value|0x30
end_define

begin_comment
comment|/* unused bits in ee_ctrl */
end_comment

begin_define
define|#
directive|define
name|GA_RESET
value|0x40
end_define

begin_comment
comment|/* BART ASIC chip reset pin */
end_comment

begin_define
define|#
directive|define
name|I586_RESET
value|0x80
end_define

begin_comment
comment|/* 82586 chip reset pin */
end_comment

begin_define
define|#
directive|define
name|memectrl
value|0x0F
end_define

begin_comment
comment|/* Memory control, E000h seg	Byte   W */
end_comment

begin_define
define|#
directive|define
name|autoid
value|0x0F
end_define

begin_comment
comment|/* Auto ID register		Byte R   */
end_comment

begin_define
define|#
directive|define
name|BOARDID
value|0xBABA
end_define

begin_comment
comment|/* Intel PCED board ID for EtherExpress */
end_comment

begin_define
define|#
directive|define
name|eeprom_opsize1
value|0x03
end_define

begin_comment
comment|/* Size of opcodes for r/w/e */
end_comment

begin_define
define|#
directive|define
name|eeprom_read_op
value|0x06
end_define

begin_comment
comment|/* EEPROM read op code */
end_comment

begin_define
define|#
directive|define
name|eeprom_write_op
value|0x05
end_define

begin_comment
comment|/* EEPROM write op code */
end_comment

begin_define
define|#
directive|define
name|eeprom_erase_op
value|0x07
end_define

begin_comment
comment|/* EEPROM erase op code */
end_comment

begin_define
define|#
directive|define
name|eeprom_opsize2
value|0x05
end_define

begin_comment
comment|/* Size of opcodes for we/wdr */
end_comment

begin_define
define|#
directive|define
name|eeprom_wenable_op
value|0x13
end_define

begin_comment
comment|/* EEPROM write enable op code */
end_comment

begin_define
define|#
directive|define
name|eeprom_wdisable_op
value|0x10
end_define

begin_comment
comment|/* EEPROM write disable op code */
end_comment

begin_define
define|#
directive|define
name|eeprom_addr_size
value|0x06
end_define

begin_comment
comment|/* Size of EEPROM address */
end_comment

begin_comment
comment|/* These are the locations in the EEPROM */
end_comment

begin_define
define|#
directive|define
name|eeprom_config1
value|0x00
end_define

begin_comment
comment|/* Configuration register 1 */
end_comment

begin_define
define|#
directive|define
name|CONNECT_BNCTPE
value|0x1000
end_define

begin_comment
comment|/* 0 = AUI, 1 = BNC/TPE */
end_comment

begin_define
define|#
directive|define
name|IRQ
value|0xE000
end_define

begin_comment
comment|/* Encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|IRQ_SHIFT
value|13
end_define

begin_comment
comment|/* To shift IRQ to lower bits */
end_comment

begin_define
define|#
directive|define
name|eeprom_lock_address
value|0x01
end_define

begin_comment
comment|/* contains the lock bit */
end_comment

begin_define
define|#
directive|define
name|EEPROM_LOCKED
value|0x01
end_define

begin_comment
comment|/* means that it is locked */
end_comment

begin_define
define|#
directive|define
name|eeprom_enetaddr_low
value|0x02
end_define

begin_comment
comment|/* Ethernet address, low word */
end_comment

begin_define
define|#
directive|define
name|eeprom_enetaddr_mid
value|0x03
end_define

begin_comment
comment|/* Ethernet address, middle word */
end_comment

begin_define
define|#
directive|define
name|eeprom_enetaddr_high
value|0x04
end_define

begin_comment
comment|/* Ethernet address, high word */
end_comment

begin_define
define|#
directive|define
name|eeprom_config2
value|0x05
end_define

begin_comment
comment|/* Configureation register 2 */
end_comment

begin_define
define|#
directive|define
name|CONNECT_TPE
value|0x0001
end_define

begin_comment
comment|/* 0 = BNC, 1 = TPE */
end_comment

begin_comment
comment|/* this converts a kernal virtual address to a board offset */
end_comment

begin_define
define|#
directive|define
name|KVTOBOARD
parameter_list|(
name|addr
parameter_list|)
value|((int)addr - (int)sc->maddr)
end_define

begin_define
define|#
directive|define
name|BOARDTOKV
parameter_list|(
name|addr
parameter_list|)
value|((int)addr + (int)sc->maddr)
end_define

begin_comment
comment|/* XXX This belongs is ic/i825x6.h, but is here for editing for now */
end_comment

begin_define
define|#
directive|define
name|INTEL586NULL
value|0xFFFF
end_define

begin_comment
comment|/* NULL pointer for 82586 */
end_comment

begin_define
define|#
directive|define
name|INTEL596NULL
value|0xFFFFFFFF
end_define

begin_comment
comment|/* NULL pointer for 82596 */
end_comment

begin_comment
comment|/*  * Layout of memory for the 825x6 chip:  * Low:		Control Blocks  *		Transmit Frame Descriptor(s)  *		Transmit Frame Buffer(s)  *		Receive Frame Descriptors  *		Receive Frames  *		SCB_ADDR	System Control Block  *		ISCP_ADDR	Intermediate System Configuration Pointer  * High:	SCP_ADDR	System Configuration Pointer  */
end_comment

begin_define
define|#
directive|define
name|SCP_ADDR
value|(sc->msize - sizeof(scp_t))
end_define

begin_define
define|#
directive|define
name|ISCP_ADDR
value|(SCP_ADDR - sizeof(iscp_t))
end_define

begin_define
define|#
directive|define
name|SCB_ADDR
value|(ISCP_ADDR - sizeof(scb_t))
end_define

begin_define
define|#
directive|define
name|TB_COUNT
value|3
end_define

begin_comment
comment|/* How many transfer buffers in the TFA */
end_comment

begin_define
define|#
directive|define
name|TB_SIZE
value|(ETHER_MAX_LENGTH)
end_define

begin_comment
comment|/* size of transmit buffer */
end_comment

begin_define
define|#
directive|define
name|TFA_START
value|0x0000
end_define

begin_comment
comment|/* Start of the TFA */
end_comment

begin_define
define|#
directive|define
name|TFA_SIZE
value|(TB_COUNT * \ 			(sizeof(cb_transmit_t) + sizeof(tbd_t) + TB_SIZE))
end_define

begin_define
define|#
directive|define
name|RFA_START
value|(TFA_SIZE)
end_define

begin_define
define|#
directive|define
name|RFA_SIZE
value|(SCP_ADDR - RFA_START)
end_define

begin_define
define|#
directive|define
name|RB_SIZE
value|(ETHER_MAX_LENGTH)
end_define

begin_comment
comment|/* size of receive buffer */
end_comment

begin_typedef
typedef|typedef
struct|struct
comment|/* System Configuration Pointer */
block|{
name|u_short
name|unused1
decl_stmt|;
comment|/* should be zeros for 82596 compatibility */
name|u_short
name|sysbus
decl_stmt|;
comment|/* width of the 82586 data bus 0=16, 1=8 */
name|u_short
name|unused2
decl_stmt|;
comment|/* should be zeros for 82596 compatibility */
name|u_short
name|unused3
decl_stmt|;
comment|/* should be zeros for 82596 compatibility */
name|u_long
name|iscp
decl_stmt|;
comment|/* iscp address (24bit 586, 32bit 596) */
block|}
name|scp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* Intermediate System Configuration Pointer */
block|{
specifier|volatile
name|u_short
name|busy
decl_stmt|;
comment|/* Set to 1 by host before its first CA, 				   cleared by 82586 after reading */
define|#
directive|define
name|ISCP_BUSY
value|0x01
comment|/* 82586 is busy reading the iscp */
name|u_short
name|scb_offset
decl_stmt|;
comment|/* Address of System Control Block */
name|u_long
name|scb_base
decl_stmt|;
comment|/* scb base address (24bit 586, 32bit 596) */
block|}
name|iscp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* System Control Block */
block|{
specifier|volatile
name|u_short
name|status
decl_stmt|;
comment|/* status bits */
define|#
directive|define
name|SCB_RUS_MASK
value|0x0070
comment|/* receive unit status mask */
define|#
directive|define
name|SCB_RUS_IDLE
value|0x0000
comment|/* receive unit status idle */
define|#
directive|define
name|SCB_RUS_SUSP
value|0x0010
comment|/* receive unit status suspended */
define|#
directive|define
name|SCB_RUS_NRSC
value|0x0020
comment|/* receive unit status no resources */
define|#
directive|define
name|SCB_RUS_READY
value|0x0040
comment|/* receive unit status ready */
define|#
directive|define
name|SCB_CUS_MASK
value|0x0700
comment|/* command unit status mask */
define|#
directive|define
name|SCB_CUS_IDLE
value|0x0000
comment|/* command unit status idle */
define|#
directive|define
name|SCB_CUS_SUSP
value|0x0100
comment|/* command unit status suspended */
define|#
directive|define
name|SCB_CUS_ACT
value|0x0200
comment|/* command unit status active */
define|#
directive|define
name|SCB_STAT_MASK
value|0xF000
comment|/* command unit status mask */
define|#
directive|define
name|SCB_STAT_RNR
value|0x1000
comment|/* receive unit left the ready state */
define|#
directive|define
name|SCB_STAT_CNA
value|0x2000
comment|/* command unit left the active state */
define|#
directive|define
name|SCB_STAT_FR
value|0x4000
comment|/* the ru finished receiving a frame */
define|#
directive|define
name|SCB_STAT_CX
value|0x8000
comment|/* the cu finished executing a command 				   with its I (interrupt) bit set */
define|#
directive|define
name|SCB_STAT_NULL
value|0x0000
comment|/* used to clear the status work */
name|u_short
name|command
decl_stmt|;
comment|/* command bits */
define|#
directive|define
name|SCB_RUC_MASK
value|0x0070
comment|/* receive unit command mask */
define|#
directive|define
name|SCB_RUC_NOP
value|0x0000
comment|/* receive unit command nop */
define|#
directive|define
name|SCB_RUC_START
value|0x0010
comment|/* receive unit command start */
define|#
directive|define
name|SCB_RUC_RESUME
value|0x0020
comment|/* receive unit command resume */
define|#
directive|define
name|SCB_RUC_SUSP
value|0x0030
comment|/* receive unit command suspend */
define|#
directive|define
name|SCB_RUC_ABORT
value|0x0040
comment|/* receive unit command abort */
define|#
directive|define
name|SCB_RESET
value|0x0080
comment|/* reset the chip, same as hardware reset */
define|#
directive|define
name|SCB_CUC_MASK
value|0x0700
comment|/* command unit command mask */
define|#
directive|define
name|SCB_CUC_NOP
value|0x0000
comment|/* command unit command nop */
define|#
directive|define
name|SCB_CUC_START
value|0x0100
comment|/* start execution of the first command */
define|#
directive|define
name|SCB_CUC_RESUME
value|0x0200
comment|/* resume execution of the next command */
define|#
directive|define
name|SCB_CUC_SUSP
value|0x0300
comment|/* suspend execution after the current command */
define|#
directive|define
name|SCB_CUC_ABORT
value|0x0400
comment|/* abort execution of the current command */
define|#
directive|define
name|SCB_ACK_MASK
value|0xF000
comment|/* command unit acknowledge mask */
define|#
directive|define
name|SCB_ACK_RNR
value|0x1000
comment|/* ack receive unit left the ready state */
define|#
directive|define
name|SCB_ACK_CNA
value|0x2000
comment|/* ack command unit left the active state */
define|#
directive|define
name|SCB_ACK_FR
value|0x4000
comment|/* ack the ru finished receiving a frame */
define|#
directive|define
name|SCB_ACK_CX
value|0x8000
comment|/* ack the cu finished executing a command 				   with its I (interrupt) bit set */
name|u_short
name|cbl_offset
decl_stmt|;
comment|/* first command block on the cbl */
name|u_short
name|rfa_offset
decl_stmt|;
comment|/* receive frame area */
specifier|volatile
name|u_short
name|crc_errors
decl_stmt|;
comment|/* frame was aligned, but bad crc */
specifier|volatile
name|u_short
name|aln_errors
decl_stmt|;
comment|/* frame was not aligned, and had bad crc */
specifier|volatile
name|u_short
name|rsc_errors
decl_stmt|;
comment|/* did not have resources to receive */
specifier|volatile
name|u_short
name|ovr_errors
decl_stmt|;
comment|/* system bus was not availiable to receive */
block|}
name|scb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - nop (also the common part of cb's */
block|{
specifier|volatile
name|u_short
name|status
decl_stmt|;
comment|/* status bits */
define|#
directive|define
name|CB_COLLISIONS
value|0x000F
comment|/* the number of collisions that occured */
define|#
directive|define
name|CB_BIT4
value|0x0010
comment|/* reserved by intel */
define|#
directive|define
name|CB_EXCESSCOLL
value|0x0020
comment|/* the number of collisions> MAX allowed */
define|#
directive|define
name|CB_HEARTBEAT
value|0x0040
comment|/* */
define|#
directive|define
name|CB_DEFER
value|0x0080
comment|/* had to defer due to trafic */
define|#
directive|define
name|CB_DMAUNDER
value|0x0100
comment|/* dma underrun */
define|#
directive|define
name|CB_NOCTS
value|0x0200
comment|/* lost clear to send */
define|#
directive|define
name|CB_NOCS
value|0x0400
comment|/* lost carrier sense */
define|#
directive|define
name|CB_LATECOLL
value|0x0800
comment|/* late collision occured (82596 only) */
define|#
directive|define
name|CB_ABORT
value|0x1000
comment|/* command was aborted by CUC abort command */
define|#
directive|define
name|CB_OK
value|0x2000
comment|/* command executed without error */
define|#
directive|define
name|CB_BUSY
value|0x4000
comment|/* command is being executed */
define|#
directive|define
name|CB_COMPLETE
value|0x8000
comment|/* command completed */
name|u_short
name|command
decl_stmt|;
comment|/* command bits */
define|#
directive|define
name|CB_CMD_MASK
value|0x0007
comment|/* command mask */
define|#
directive|define
name|CB_CMD_NOP
value|0x0000
comment|/* nop command */
define|#
directive|define
name|CB_CMD_IAS
value|0x0001
comment|/* individual address setup command */
define|#
directive|define
name|CB_CMD_CONF
value|0x0002
comment|/* configure command */
define|#
directive|define
name|CB_CMD_MCAS
value|0x0003
comment|/* multicast address setup command */
define|#
directive|define
name|CB_CMD_TRANSMIT
value|0x0004
comment|/* transmit command */
define|#
directive|define
name|CB_CMD_TDR
value|0x0005
comment|/* time domain reflectometry command */
define|#
directive|define
name|CB_CMD_DUMP
value|0x0006
comment|/* dump command */
define|#
directive|define
name|CB_CMD_DIAGNOSE
value|0x0007
comment|/* diagnose command */
define|#
directive|define
name|CB_CMD_INT
value|0x2000
comment|/* interrupt when command completed */
define|#
directive|define
name|CB_CMD_SUSP
value|0x4000
comment|/* suspend CU when command completed */
define|#
directive|define
name|CB_CMD_EL
value|0x8000
comment|/* end of the command block list */
name|u_short
name|next
decl_stmt|;
comment|/* pointer to the next cb */
block|}
name|cb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - individual address setup command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
name|u_char
name|source
index|[
name|ETHER_ADDRESS_LENGTH
index|]
decl_stmt|;
comment|/* ethernet hardware address */
block|}
name|cb_ias_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - configure command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
name|u_char
name|byte
index|[
literal|12
index|]
decl_stmt|;
comment|/* ZZZ this is ugly, but it works */
block|}
name|cb_configure_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - multicast address setup command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
block|}
name|cb_mcas_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - transmit command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
name|u_short
name|tbd_offset
decl_stmt|;
comment|/* transmit buffer descriptor offset */
name|u_char
name|destination
index|[
name|ETHER_ADDRESS_LENGTH
index|]
decl_stmt|;
comment|/* ethernet destination address field */
name|u_short
name|length
decl_stmt|;
comment|/* ethernet length field */
name|u_char
name|byte
index|[
literal|16
index|]
decl_stmt|;
comment|/* XXX stupid fill tell I fix the ixinit 				 * code for the special cb's */
block|}
name|cb_transmit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - tdr command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
block|}
name|cb_tdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - dump command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
block|}
name|cb_dump_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* command block - diagnose command */
block|{
name|cb_t
name|common
decl_stmt|;
comment|/* common part of all command blocks */
block|}
name|cb_diagnose_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* Transmit Buffer Descriptor */
block|{
specifier|volatile
name|u_short
name|act_count
decl_stmt|;
comment|/* size of buffer actual count of valid bytes */
define|#
directive|define
name|TBD_STAT_EOF
value|0x8000
comment|/* end of frame */
name|u_short
name|next
decl_stmt|;
comment|/* pointer to the next tbd */
name|u_long
name|buffer
decl_stmt|;
comment|/* transmit buffer address (24bit 586, 32bit 596) */
block|}
name|tbd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* Receive Frame Descriptor */
block|{
specifier|volatile
name|u_short
name|status
decl_stmt|;
comment|/* status bits */
define|#
directive|define
name|RFD_BUSY
value|0x4000
comment|/* frame is being received */
define|#
directive|define
name|RFD_COMPLETE
value|0x8000
comment|/* this frame is complete */
name|u_short
name|command
decl_stmt|;
comment|/* command bits */
define|#
directive|define
name|RFD_CMD_SUSP
value|0x4000
comment|/* suspend the ru after this rfd is used */
define|#
directive|define
name|RFD_CMD_EL
value|0x8000
comment|/* end of the rfd list */
name|u_short
name|next
decl_stmt|;
comment|/* pointer to the next rfd */
name|u_short
name|rbd_offset
decl_stmt|;
comment|/* pointer to the first rbd for this frame */
name|u_char
name|destination
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet destination address */
name|u_char
name|source
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet source address */
name|u_short
name|length
decl_stmt|;
comment|/* ethernet length field */
block|}
name|rfd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
comment|/* Receive Buffer Descriptor */
block|{
specifier|volatile
name|u_short
name|act_count
decl_stmt|;
comment|/* Actual Count (size) and status bits */
define|#
directive|define
name|RBD_STAT_SIZE
value|0x3FFF
comment|/* size mask */
define|#
directive|define
name|RBD_STAT_VALID
value|0x4000
comment|/* act_count field is valid */
define|#
directive|define
name|RBD_STAT_EOF
value|0x8000
comment|/* end of frame */
name|u_short
name|next
decl_stmt|;
comment|/* pointer to the next rbd */
name|u_long
name|buffer
decl_stmt|;
comment|/* receive buffer address */
name|u_short
name|size
decl_stmt|;
comment|/* size of buffer in bytes, must be even */
define|#
directive|define
name|RBD_SIZE_EL
value|0x8000
comment|/* end of rbd list */
block|}
name|rbd_t
typedef|;
end_typedef

begin_comment
comment|/*  * Ethernet software status per interface.  *  * Each interface is referenced by a network interface structure,  * arpcom.ac_if, which the routing code uses to locate the interface.  * This structure contains the output queue for the interface, its address, ...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* Ethernet common part see net/if.h */
name|int
name|iobase
decl_stmt|;
comment|/* I/O base address for this interface */
name|caddr_t
name|maddr
decl_stmt|;
comment|/* Memory base address for this interface */
name|int
name|msize
decl_stmt|;
comment|/* Size of memory */
name|int
name|flags
decl_stmt|;
comment|/* Software state */
define|#
directive|define
name|IXF_NONE
value|0x00000000
comment|/* Clear all flags */
define|#
directive|define
name|IXF_INITED
value|0x00000001
comment|/* Device has been inited */
define|#
directive|define
name|IXF_BPFATTACHED
value|0x80000000
comment|/* BPF has been attached */
name|int
name|connector
decl_stmt|;
comment|/* Type of connector used on board */
define|#
directive|define
name|AUI
value|0x00
comment|/* Using AUI connector */
define|#
directive|define
name|BNC
value|0x01
comment|/* Using BNC connector */
define|#
directive|define
name|TPE
value|0x02
comment|/* Using TPE connector */
name|u_short
name|irq_encoded
decl_stmt|;
comment|/* Encoded interrupt for use on bart */
name|int
name|width
decl_stmt|;
comment|/* Width of slot the board is in, these 					 * constants are defined to match what 					 * the 82586/596 wants in scp->sysbus */
define|#
directive|define
name|WIDTH_8
value|0x01
comment|/* 8-bit slot */
define|#
directive|define
name|WIDTH_16
value|0x00
comment|/* 16-bit slot */
name|cb_t
modifier|*
name|cb_head
decl_stmt|;
comment|/* head of cb list */
name|cb_t
modifier|*
name|cb_tail
decl_stmt|;
comment|/* tail of cb list */
name|tbd_t
modifier|*
name|tbd_head
decl_stmt|;
comment|/* head of the tbd list */
name|tbd_t
modifier|*
name|tbd_tail
decl_stmt|;
comment|/* tail of the tbd list */
name|rfd_t
modifier|*
name|rfd_head
decl_stmt|;
comment|/* head of the rfd list */
name|rfd_t
modifier|*
name|rfd_tail
decl_stmt|;
comment|/* tail of the rfd list */
name|rbd_t
modifier|*
name|rbd_head
decl_stmt|;
comment|/* head of the rbd list */
name|rbd_t
modifier|*
name|rbd_tail
decl_stmt|;
comment|/* tail of the rbd list */
name|struct
name|kern_devconf
name|kdc
decl_stmt|;
block|}
name|ix_softc_t
typedef|;
end_typedef

end_unit

