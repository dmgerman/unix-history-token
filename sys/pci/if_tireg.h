begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Tigon register offsets. These are memory mapped registers  * which can be accessed with the CSR_READ_4()/CSR_WRITE_4() macros.  * Each register must be accessed using 32 bit operations.  *  * All reegisters are accessed through a 16K shared memory block.  * The first group of registers are actually copies of the PCI  * configuration space registers.  */
end_comment

begin_define
define|#
directive|define
name|TI_PCI_ID
value|0x000
end_define

begin_comment
comment|/* PCI device/vendor ID */
end_comment

begin_define
define|#
directive|define
name|TI_PCI_CMDSTAT
value|0x004
end_define

begin_define
define|#
directive|define
name|TI_PCI_CLASSCODE
value|0x008
end_define

begin_define
define|#
directive|define
name|TI_PCI_BIST
value|0x00C
end_define

begin_define
define|#
directive|define
name|TI_PCI_LOMEM
value|0x010
end_define

begin_comment
comment|/* Shared memory base address */
end_comment

begin_define
define|#
directive|define
name|TI_PCI_SUBSYS
value|0x02C
end_define

begin_define
define|#
directive|define
name|TI_PCI_ROMBASE
value|0x030
end_define

begin_define
define|#
directive|define
name|TI_PCI_INT
value|0x03C
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCIM_CMD_MWIEN
end_ifndef

begin_define
define|#
directive|define
name|PCIM_CMD_MWIEN
value|0x0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Alteon AceNIC PCI vendor/device ID.  */
end_comment

begin_define
define|#
directive|define
name|ALT_VENDORID
value|0x12AE
end_define

begin_define
define|#
directive|define
name|ALT_DEVICEID_ACENIC
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALT_DEVICEID_ACENIC_COPPER
value|0x0002
end_define

begin_comment
comment|/*  * 3Com 3c985 PCI vendor/device ID.  */
end_comment

begin_define
define|#
directive|define
name|TC_VENDORID
value|0x10B7
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_3C985
value|0x0001
end_define

begin_comment
comment|/*  * Netgear GA620 PCI vendor/device ID.  */
end_comment

begin_define
define|#
directive|define
name|NG_VENDORID
value|0x1385
end_define

begin_define
define|#
directive|define
name|NG_DEVICEID_GA620
value|0x620A
end_define

begin_define
define|#
directive|define
name|NG_DEVICEID_GA620T
value|0x630A
end_define

begin_comment
comment|/*  * SGI device/vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|SGI_VENDORID
value|0x10A9
end_define

begin_define
define|#
directive|define
name|SGI_DEVICEID_TIGON
value|0x0009
end_define

begin_comment
comment|/*  * DEC vendor ID, Farallon device ID. Apparently, Farallon used  * the DEC vendor ID in their cards by mistake.  */
end_comment

begin_define
define|#
directive|define
name|DEC_VENDORID
value|0x1011
end_define

begin_define
define|#
directive|define
name|DEC_DEVICEID_FARALLON_PN9000SX
value|0x001a
end_define

begin_comment
comment|/*  * Tigon configuration and control registers.  */
end_comment

begin_define
define|#
directive|define
name|TI_MISC_HOST_CTL
value|0x040
end_define

begin_define
define|#
directive|define
name|TI_MISC_LOCAL_CTL
value|0x044
end_define

begin_define
define|#
directive|define
name|TI_SEM_AB
value|0x048
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MISC_CONF
value|0x050
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_TIMER_BITS
value|0x054
end_define

begin_define
define|#
directive|define
name|TI_TIMERREF
value|0x058
end_define

begin_define
define|#
directive|define
name|TI_PCI_STATE
value|0x05C
end_define

begin_define
define|#
directive|define
name|TI_MAIN_EVENT_A
value|0x060
end_define

begin_define
define|#
directive|define
name|TI_MAILBOX_EVENT_A
value|0x064
end_define

begin_define
define|#
directive|define
name|TI_WINBASE
value|0x068
end_define

begin_define
define|#
directive|define
name|TI_WINDATA
value|0x06C
end_define

begin_define
define|#
directive|define
name|TI_MAIN_EVENT_B
value|0x070
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MAILBOX_EVENT_B
value|0x074
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_TIMERREF_B
value|0x078
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_SERIAL
value|0x07C
end_define

begin_comment
comment|/*  * Misc host control bits.  */
end_comment

begin_define
define|#
directive|define
name|TI_MHC_INTSTATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_MHC_CLEARINT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_MHC_RESET
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TI_MHC_BYTE_SWAP_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TI_MHC_WORD_SWAP_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TI_MHC_MASK_INTS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TI_MHC_CHIP_REV_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|TI_MHC_BIGENDIAN_INIT
define|\
value|(TI_MHC_BYTE_SWAP_ENB|TI_MHC_WORD_SWAP_ENB|TI_MHC_CLEARINT)
end_define

begin_define
define|#
directive|define
name|TI_MHC_LITTLEENDIAN_INIT
define|\
value|(TI_MHC_WORD_SWAP_ENB|TI_MHC_CLEARINT)
end_define

begin_comment
comment|/*  * Tigon chip rev values. Rev 4 is the Tigon 1. Rev 6 is the Tigon 2.  * Rev 5 is also the Tigon 2, but is a broken version which was never  * used in any actual hardware, so we ignore it.  */
end_comment

begin_define
define|#
directive|define
name|TI_REV_TIGON_I
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TI_REV_TIGON_II
value|0x60000000
end_define

begin_comment
comment|/*  * Firmware revision that we want.  */
end_comment

begin_define
define|#
directive|define
name|TI_FIRMWARE_MAJOR
value|0xc
end_define

begin_define
define|#
directive|define
name|TI_FIRMWARE_MINOR
value|0x4
end_define

begin_define
define|#
directive|define
name|TI_FIRMWARE_FIX
value|0xd
end_define

begin_comment
comment|/*  * Miscelaneous Local Control register.  */
end_comment

begin_define
define|#
directive|define
name|TI_MLC_EE_WRITE_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TI_MLC_SRAM_BANK_SIZE
value|0x00000300
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MLC_LOCALADDR_21
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TI_MLC_LOCALADDR_22
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TI_MLC_SBUS_WRITEERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TI_MLC_EE_CLK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TI_MLC_EE_TXEN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|TI_MLC_EE_DOUT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TI_MLC_EE_DIN
value|0x00800000
end_define

begin_comment
comment|/* Possible memory sizes. */
end_comment

begin_define
define|#
directive|define
name|TI_MLC_SRAM_BANK_DISA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TI_MLC_SRAM_BANK_1024K
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TI_MLC_SRAM_BANK_512K
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TI_MLC_SRAM_BANK_256K
value|0x00000300
end_define

begin_comment
comment|/*  * Offset of MAC address inside EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|TI_EE_MAC_OFFSET
value|0x8c
end_define

begin_define
define|#
directive|define
name|TI_DMA_ASSIST
value|0x11C
end_define

begin_define
define|#
directive|define
name|TI_CPU_STATE
value|0x140
end_define

begin_define
define|#
directive|define
name|TI_CPU_PROGRAM_COUNTER
value|0x144
end_define

begin_define
define|#
directive|define
name|TI_SRAM_ADDR
value|0x154
end_define

begin_define
define|#
directive|define
name|TI_SRAM_DATA
value|0x158
end_define

begin_define
define|#
directive|define
name|TI_GEN_0
value|0x180
end_define

begin_define
define|#
directive|define
name|TI_GEN_X
value|0x1FC
end_define

begin_define
define|#
directive|define
name|TI_MAC_TX_STATE
value|0x200
end_define

begin_define
define|#
directive|define
name|TI_MAC_RX_STATE
value|0x220
end_define

begin_define
define|#
directive|define
name|TI_CPU_CTL_B
value|0x240
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_CPU_PROGRAM_COUNTER_B
value|0x244
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_SRAM_ADDR_B
value|0x254
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_SRAM_DATA_B
value|0x258
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_GEN_B_0
value|0x280
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_GEN_B_X
value|0x2FC
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_comment
comment|/*  * Misc config register.  */
end_comment

begin_define
define|#
directive|define
name|TI_MCR_SRAM_SYNCHRONOUS
value|0x00100000
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_comment
comment|/*  * PCI state register.  */
end_comment

begin_define
define|#
directive|define
name|TI_PCISTATE_FORCE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_PROVIDE_LEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_READ_MAXDMA
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_WRITE_MAXDMA
value|0x000000E0
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_MINDMA
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_FIFO_RETRY_ENB
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_USE_MEM_RD_MULT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_NO_SWAP_READ_DMA
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_NO_SWAP_WRITE_DMA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_66MHZ_BUS
value|0x00080000
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_PCISTATE_32BIT_BUS
value|0x00100000
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_PCISTATE_ENB_BYTE_ENABLES
value|0x00800000
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_PCISTATE_READ_CMD
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|TI_PCISTATE_WRITE_CMD
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_4
value|0x04
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_16
value|0x08
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_32
value|0x0C
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_64
value|0x10
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_128
value|0x14
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_256
value|0x18
end_define

begin_define
define|#
directive|define
name|TI_PCI_READMAX_1024
value|0x1C
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_4
value|0x20
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_16
value|0x40
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_32
value|0x60
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_64
value|0x80
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_128
value|0xA0
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_256
value|0xC0
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITEMAX_1024
value|0xE0
end_define

begin_define
define|#
directive|define
name|TI_PCI_READ_CMD
value|0x06000000
end_define

begin_define
define|#
directive|define
name|TI_PCI_WRITE_CMD
value|0x70000000
end_define

begin_comment
comment|/*  * DMA state register.  */
end_comment

begin_define
define|#
directive|define
name|TI_DMASTATE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_DMASTATE_PAUSE
value|0x00000002
end_define

begin_comment
comment|/*  * CPU state register.  */
end_comment

begin_define
define|#
directive|define
name|TI_CPUSTATE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_CPUSTATE_STEP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_CPUSTATE_ROMFAIL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TI_CPUSTATE_HALT
value|0x00010000
end_define

begin_comment
comment|/*  * MAC TX state register  */
end_comment

begin_define
define|#
directive|define
name|TI_TXSTATE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_TXSTATE_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_TXSTATE_STOP
value|0x00000004
end_define

begin_comment
comment|/*  * MAC RX state register  */
end_comment

begin_define
define|#
directive|define
name|TI_RXSTATE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_RXSTATE_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_RXSTATE_STOP
value|0x00000004
end_define

begin_comment
comment|/*  * Tigon 2 mailbox registers. The mailbox area consists of 256 bytes  * split into 64 bit registers. Only the lower 32 bits of each mailbox  * are used.  */
end_comment

begin_define
define|#
directive|define
name|TI_MB_HOSTINTR_HI
value|0x500
end_define

begin_define
define|#
directive|define
name|TI_MB_HOSTINTR_LO
value|0x504
end_define

begin_define
define|#
directive|define
name|TI_MB_HOSTINTR
value|TI_MB_HOSTINTR_LO
end_define

begin_define
define|#
directive|define
name|TI_MB_CMDPROD_IDX_HI
value|0x508
end_define

begin_define
define|#
directive|define
name|TI_MB_CMDPROD_IDX_LO
value|0x50C
end_define

begin_define
define|#
directive|define
name|TI_MB_CMDPROD_IDX
value|TI_MB_CMDPROD_IDX_LO
end_define

begin_define
define|#
directive|define
name|TI_MB_SENDPROD_IDX_HI
value|0x510
end_define

begin_define
define|#
directive|define
name|TI_MB_SENDPROD_IDX_LO
value|0x514
end_define

begin_define
define|#
directive|define
name|TI_MB_SENDPROD_IDX
value|TI_MB_SENDPROD_IDX_LO
end_define

begin_define
define|#
directive|define
name|TI_MB_STDRXPROD_IDX_HI
value|0x518
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MB_STDRXPROD_IDX_LO
value|0x51C
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MB_STDRXPROD_IDX
value|TI_MB_STDRXPROD_IDX_LO
end_define

begin_define
define|#
directive|define
name|TI_MB_JUMBORXPROD_IDX_HI
value|0x520
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MB_JUMBORXPROD_IDX_LO
value|0x524
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MB_JUMBORXPROD_IDX
value|TI_MB_JUMBORXPROD_IDX_LO
end_define

begin_define
define|#
directive|define
name|TI_MB_MINIRXPROD_IDX_HI
value|0x528
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MB_MINIRXPROD_IDX_LO
value|0x52C
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_MB_MINIRXPROD_IDX
value|TI_MB_MINIRXPROD_IDX_LO
end_define

begin_define
define|#
directive|define
name|TI_MB_RSVD
value|0x530
end_define

begin_comment
comment|/*  * Tigon 2 general communication registers. These are 64 and 32 bit  * registers which are only valid after the firmware has been  * loaded and started. They actually exist in NIC memory but are  * mapped into the host memory via the shared memory region.  *  * The NIC internally maps these registers starting at address 0,  * so to determine the NIC address of any of these registers, we  * subtract 0x600 (the address of the first register).  */
end_comment

begin_define
define|#
directive|define
name|TI_GCR_BASE
value|0x600
end_define

begin_define
define|#
directive|define
name|TI_GCR_MACADDR
value|0x600
end_define

begin_define
define|#
directive|define
name|TI_GCR_PAR0
value|0x600
end_define

begin_define
define|#
directive|define
name|TI_GCR_PAR1
value|0x604
end_define

begin_define
define|#
directive|define
name|TI_GCR_GENINFO_HI
value|0x608
end_define

begin_define
define|#
directive|define
name|TI_GCR_GENINFO_LO
value|0x60C
end_define

begin_define
define|#
directive|define
name|TI_GCR_MCASTADDR
value|0x610
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_GCR_MAR0
value|0x610
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_GCR_MAR1
value|0x614
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_GCR_OPMODE
value|0x618
end_define

begin_define
define|#
directive|define
name|TI_GCR_DMA_READCFG
value|0x61C
end_define

begin_define
define|#
directive|define
name|TI_GCR_DMA_WRITECFG
value|0x620
end_define

begin_define
define|#
directive|define
name|TI_GCR_TX_BUFFER_RATIO
value|0x624
end_define

begin_define
define|#
directive|define
name|TI_GCR_EVENTCONS_IDX
value|0x628
end_define

begin_define
define|#
directive|define
name|TI_GCR_CMDCONS_IDX
value|0x62C
end_define

begin_define
define|#
directive|define
name|TI_GCR_TUNEPARMS
value|0x630
end_define

begin_define
define|#
directive|define
name|TI_GCR_RX_COAL_TICKS
value|0x630
end_define

begin_define
define|#
directive|define
name|TI_GCR_TX_COAL_TICKS
value|0x634
end_define

begin_define
define|#
directive|define
name|TI_GCR_STAT_TICKS
value|0x638
end_define

begin_define
define|#
directive|define
name|TI_GCR_TX_MAX_COAL_BD
value|0x63C
end_define

begin_define
define|#
directive|define
name|TI_GCR_RX_MAX_COAL_BD
value|0x640
end_define

begin_define
define|#
directive|define
name|TI_GCR_NIC_TRACING
value|0x644
end_define

begin_define
define|#
directive|define
name|TI_GCR_GLINK
value|0x648
end_define

begin_define
define|#
directive|define
name|TI_GCR_LINK
value|0x64C
end_define

begin_define
define|#
directive|define
name|TI_GCR_NICTRACE_PTR
value|0x650
end_define

begin_define
define|#
directive|define
name|TI_GCR_NICTRACE_START
value|0x654
end_define

begin_define
define|#
directive|define
name|TI_GCR_NICTRACE_LEN
value|0x658
end_define

begin_define
define|#
directive|define
name|TI_GCR_IFINDEX
value|0x65C
end_define

begin_define
define|#
directive|define
name|TI_GCR_IFMTU
value|0x660
end_define

begin_define
define|#
directive|define
name|TI_GCR_MASK_INTRS
value|0x664
end_define

begin_define
define|#
directive|define
name|TI_GCR_GLINK_STAT
value|0x668
end_define

begin_define
define|#
directive|define
name|TI_GCR_LINK_STAT
value|0x66C
end_define

begin_define
define|#
directive|define
name|TI_GCR_RXRETURNCONS_IDX
value|0x680
end_define

begin_define
define|#
directive|define
name|TI_GCR_CMDRING
value|0x700
end_define

begin_define
define|#
directive|define
name|TI_GCR_NIC_ADDR
parameter_list|(
name|x
parameter_list|)
value|(x - TI_GCR_BASE);
end_define

begin_comment
comment|/*  * Local memory window. The local memory window is a 2K shared  * memory region which can be used to access the NIC's internal  * SRAM. The window can be mapped to a given 2K region using  * the TI_WINDOW_BASE register.  */
end_comment

begin_define
define|#
directive|define
name|TI_WINDOW
value|0x800
end_define

begin_define
define|#
directive|define
name|TI_WINLEN
value|0x800
end_define

begin_define
define|#
directive|define
name|TI_TICKS_PER_SEC
value|1000000
end_define

begin_comment
comment|/*  * Operation mode register.  */
end_comment

begin_define
define|#
directive|define
name|TI_OPMODE_BYTESWAP_BD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_WORDSWAP_BD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_WARN_ENB
value|0x00000008
end_define

begin_comment
comment|/* not yet implimented */
end_comment

begin_define
define|#
directive|define
name|TI_OPMODE_BYTESWAP_DATA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_1_DMA_ACTIVE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_SBUS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_DONT_FRAG_JUMBO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_INCLUDE_CRC
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_RX_BADFRAMES
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_NO_EVENT_INTRS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_NO_TX_INTRS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_NO_RX_INTRS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TI_OPMODE_FATAL_ENB
value|0x40000000
end_define

begin_comment
comment|/* not yet implimented */
end_comment

begin_comment
comment|/*  * DMA configuration thresholds.  */
end_comment

begin_define
define|#
directive|define
name|TI_DMA_STATE_THRESH_16W
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TI_DMA_STATE_THRESH_8W
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TI_DMA_STATE_THRESH_4W
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TI_DMA_STATE_THRESH_2W
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TI_DMA_STATE_THRESH_1W
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TI_DMA_STATE_FORCE_32_BIT
value|0x00000008
end_define

begin_comment
comment|/*  * Gigabit link status bits.  */
end_comment

begin_define
define|#
directive|define
name|TI_GLNK_SENSE_NO_BEG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_LOOPBACK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_PREF
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_1000MB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_FULL_DUPLEX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_TX_FLOWCTL_Y
value|0x00200000
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_GLNK_RX_FLOWCTL_Y
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_AUTONEGENB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TI_GLNK_ENB
value|0x40000000
end_define

begin_comment
comment|/*  * Link status bits.  */
end_comment

begin_define
define|#
directive|define
name|TI_LNK_LOOPBACK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TI_LNK_PREF
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TI_LNK_10MB
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TI_LNK_100MB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|TI_LNK_1000MB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|TI_LNK_FULL_DUPLEX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TI_LNK_HALF_DUPLEX
value|0x00100000
end_define

begin_define
define|#
directive|define
name|TI_LNK_TX_FLOWCTL_Y
value|0x00200000
end_define

begin_comment
comment|/* Tigon 2 only */
end_comment

begin_define
define|#
directive|define
name|TI_LNK_RX_FLOWCTL_Y
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TI_LNK_AUTONEGENB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TI_LNK_ENB
value|0x40000000
end_define

begin_comment
comment|/*  * Ring size constants.  */
end_comment

begin_define
define|#
directive|define
name|TI_EVENT_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|TI_CMD_RING_CNT
value|64
end_define

begin_define
define|#
directive|define
name|TI_STD_RX_RING_CNT
value|512
end_define

begin_define
define|#
directive|define
name|TI_JUMBO_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|TI_MINI_RX_RING_CNT
value|1024
end_define

begin_define
define|#
directive|define
name|TI_RETURN_RING_CNT
value|2048
end_define

begin_comment
comment|/*  * Possible TX ring sizes.  */
end_comment

begin_define
define|#
directive|define
name|TI_TX_RING_CNT_128
value|128
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_BASE_128
value|0x3800
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_CNT_256
value|256
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_BASE_256
value|0x3000
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_CNT_512
value|512
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_BASE_512
value|0x2000
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_CNT
value|TI_TX_RING_CNT_512
end_define

begin_define
define|#
directive|define
name|TI_TX_RING_BASE
value|TI_TX_RING_BASE_512
end_define

begin_comment
comment|/*  * The Tigon can have up to 8MB of external SRAM, however the Tigon 1  * is limited to 2MB total, and in general I think most adapters have  * around 1MB. We use this value for zeroing the NIC's SRAM, so to  * be safe we use the largest possible value (zeroing memory that  * isn't there doesn't hurt anything).  */
end_comment

begin_define
define|#
directive|define
name|TI_MEM_MAX
value|0x7FFFFF
end_define

begin_comment
comment|/*  * Even on the alpha, pci addresses are 32-bit quantities  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__64_bit_pci_addressing__
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int64_t
name|ti_addr
decl_stmt|;
block|}
name|ti_hostaddr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TI_HOSTADDR
parameter_list|(
name|x
parameter_list|)
value|x.ti_addr
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|ti_addr_hi
decl_stmt|;
name|u_int32_t
name|ti_addr_lo
decl_stmt|;
block|}
name|ti_hostaddr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TI_HOSTADDR
parameter_list|(
name|x
parameter_list|)
value|x.ti_addr_lo
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ring control block structure. The rules for the max_len field  * are as follows:  *   * For the send ring, max_len indicates the number of entries in the  * ring (128, 256 or 512).  *  * For the standard receive ring, max_len indicates the threshold  * used to decide when a frame should be put in the jumbo receive ring  * instead of the standard one.  *  * For the mini ring, max_len indicates the size of the buffers in the  * ring. This is the value used to decide when a frame is small enough  * to be placed in the mini ring.  *  * For the return receive ring, max_len indicates the number of entries  * in the ring. It can be one of 2048, 1024 or 0 (which is the same as  * 2048 for backwards compatibility). The value 1024 can only be used  * if the mini ring is disabled.  */
end_comment

begin_struct
struct|struct
name|ti_rcb
block|{
name|ti_hostaddr
name|ti_hostaddr
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_max_len
decl_stmt|;
name|u_int16_t
name|ti_flags
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_flags
decl_stmt|;
name|u_int16_t
name|ti_max_len
decl_stmt|;
endif|#
directive|endif
name|u_int32_t
name|ti_unused
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TI_RCB_FLAG_TCP_UDP_CKSUM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_IP_CKSUM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_NO_PHDR_CKSUM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_VLAN_ASSIST
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_COAL_UPD_ONLY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_HOST_RING
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_IEEE_SNAP_CKSUM
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_USE_EXT_RX_BD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TI_RCB_FLAG_RING_DISABLED
value|0x00000200
end_define

begin_struct
struct|struct
name|ti_producer
block|{
name|u_int32_t
name|ti_idx
decl_stmt|;
name|u_int32_t
name|ti_unused
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tigon statistics counters.  */
end_comment

begin_struct
struct|struct
name|ti_stats
block|{
comment|/* 	 * MAC stats, taken from RFC 1643, ethernet-like MIB 	 */
specifier|volatile
name|u_int32_t
name|dot3StatsAlignmentErrors
decl_stmt|;
comment|/* 0 */
specifier|volatile
name|u_int32_t
name|dot3StatsFCSErrors
decl_stmt|;
comment|/* 1 */
specifier|volatile
name|u_int32_t
name|dot3StatsSingleCollisionFrames
decl_stmt|;
comment|/* 2 */
specifier|volatile
name|u_int32_t
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
comment|/* 3 */
specifier|volatile
name|u_int32_t
name|dot3StatsSQETestErrors
decl_stmt|;
comment|/* 4 */
specifier|volatile
name|u_int32_t
name|dot3StatsDeferredTransmissions
decl_stmt|;
comment|/* 5 */
specifier|volatile
name|u_int32_t
name|dot3StatsLateCollisions
decl_stmt|;
comment|/* 6 */
specifier|volatile
name|u_int32_t
name|dot3StatsExcessiveCollisions
decl_stmt|;
comment|/* 7 */
specifier|volatile
name|u_int32_t
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
comment|/* 8 */
specifier|volatile
name|u_int32_t
name|dot3StatsCarrierSenseErrors
decl_stmt|;
comment|/* 9 */
specifier|volatile
name|u_int32_t
name|dot3StatsFrameTooLongs
decl_stmt|;
comment|/* 10 */
specifier|volatile
name|u_int32_t
name|dot3StatsInternalMacReceiveErrors
decl_stmt|;
comment|/* 11 */
comment|/* 	 * interface stats, taken from RFC 1213, MIB-II, interfaces group 	 */
specifier|volatile
name|u_int32_t
name|ifIndex
decl_stmt|;
comment|/* 12 */
specifier|volatile
name|u_int32_t
name|ifType
decl_stmt|;
comment|/* 13 */
specifier|volatile
name|u_int32_t
name|ifMtu
decl_stmt|;
comment|/* 14 */
specifier|volatile
name|u_int32_t
name|ifSpeed
decl_stmt|;
comment|/* 15 */
specifier|volatile
name|u_int32_t
name|ifAdminStatus
decl_stmt|;
comment|/* 16 */
define|#
directive|define
name|IF_ADMIN_STATUS_UP
value|1
define|#
directive|define
name|IF_ADMIN_STATUS_DOWN
value|2
define|#
directive|define
name|IF_ADMIN_STATUS_TESTING
value|3
specifier|volatile
name|u_int32_t
name|ifOperStatus
decl_stmt|;
comment|/* 17 */
define|#
directive|define
name|IF_OPER_STATUS_UP
value|1
define|#
directive|define
name|IF_OPER_STATUS_DOWN
value|2
define|#
directive|define
name|IF_OPER_STATUS_TESTING
value|3
define|#
directive|define
name|IF_OPER_STATUS_UNKNOWN
value|4
define|#
directive|define
name|IF_OPER_STATUS_DORMANT
value|5
specifier|volatile
name|u_int32_t
name|ifLastChange
decl_stmt|;
comment|/* 18 */
specifier|volatile
name|u_int32_t
name|ifInDiscards
decl_stmt|;
comment|/* 19 */
specifier|volatile
name|u_int32_t
name|ifInErrors
decl_stmt|;
comment|/* 20 */
specifier|volatile
name|u_int32_t
name|ifInUnknownProtos
decl_stmt|;
comment|/* 21 */
specifier|volatile
name|u_int32_t
name|ifOutDiscards
decl_stmt|;
comment|/* 22 */
specifier|volatile
name|u_int32_t
name|ifOutErrors
decl_stmt|;
comment|/* 23 */
specifier|volatile
name|u_int32_t
name|ifOutQLen
decl_stmt|;
comment|/* deprecated */
comment|/* 24 */
specifier|volatile
name|u_int8_t
name|ifPhysAddress
index|[
literal|8
index|]
decl_stmt|;
comment|/* 8 bytes */
comment|/* 25 - 26 */
specifier|volatile
name|u_int8_t
name|ifDescr
index|[
literal|32
index|]
decl_stmt|;
comment|/* 27 - 34 */
name|u_int32_t
name|alignIt
decl_stmt|;
comment|/* align to 64 bit for u_int64_ts following */
comment|/* 	 * more interface stats, taken from RFC 1573, MIB-IIupdate, 	 * interfaces group 	 */
specifier|volatile
name|u_int64_t
name|ifHCInOctets
decl_stmt|;
comment|/* 36 - 37 */
specifier|volatile
name|u_int64_t
name|ifHCInUcastPkts
decl_stmt|;
comment|/* 38 - 39 */
specifier|volatile
name|u_int64_t
name|ifHCInMulticastPkts
decl_stmt|;
comment|/* 40 - 41 */
specifier|volatile
name|u_int64_t
name|ifHCInBroadcastPkts
decl_stmt|;
comment|/* 42 - 43 */
specifier|volatile
name|u_int64_t
name|ifHCOutOctets
decl_stmt|;
comment|/* 44 - 45 */
specifier|volatile
name|u_int64_t
name|ifHCOutUcastPkts
decl_stmt|;
comment|/* 46 - 47 */
specifier|volatile
name|u_int64_t
name|ifHCOutMulticastPkts
decl_stmt|;
comment|/* 48 - 49 */
specifier|volatile
name|u_int64_t
name|ifHCOutBroadcastPkts
decl_stmt|;
comment|/* 50 - 51 */
specifier|volatile
name|u_int32_t
name|ifLinkUpDownTrapEnable
decl_stmt|;
comment|/* 52 */
specifier|volatile
name|u_int32_t
name|ifHighSpeed
decl_stmt|;
comment|/* 53 */
specifier|volatile
name|u_int32_t
name|ifPromiscuousMode
decl_stmt|;
comment|/* 54 */
specifier|volatile
name|u_int32_t
name|ifConnectorPresent
decl_stmt|;
comment|/* follow link state 55 */
comment|/* 	 * Host Commands 	 */
specifier|volatile
name|u_int32_t
name|nicCmdsHostState
decl_stmt|;
comment|/* 56 */
specifier|volatile
name|u_int32_t
name|nicCmdsFDRFiltering
decl_stmt|;
comment|/* 57 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetRecvProdIndex
decl_stmt|;
comment|/* 58 */
specifier|volatile
name|u_int32_t
name|nicCmdsUpdateGencommStats
decl_stmt|;
comment|/* 59 */
specifier|volatile
name|u_int32_t
name|nicCmdsResetJumboRing
decl_stmt|;
comment|/* 60 */
specifier|volatile
name|u_int32_t
name|nicCmdsAddMCastAddr
decl_stmt|;
comment|/* 61 */
specifier|volatile
name|u_int32_t
name|nicCmdsDelMCastAddr
decl_stmt|;
comment|/* 62 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetPromiscMode
decl_stmt|;
comment|/* 63 */
specifier|volatile
name|u_int32_t
name|nicCmdsLinkNegotiate
decl_stmt|;
comment|/* 64 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetMACAddr
decl_stmt|;
comment|/* 65 */
specifier|volatile
name|u_int32_t
name|nicCmdsClearProfile
decl_stmt|;
comment|/* 66 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetMulticastMode
decl_stmt|;
comment|/* 67 */
specifier|volatile
name|u_int32_t
name|nicCmdsClearStats
decl_stmt|;
comment|/* 68 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetRecvJumboProdIndex
decl_stmt|;
comment|/* 69 */
specifier|volatile
name|u_int32_t
name|nicCmdsSetRecvMiniProdIndex
decl_stmt|;
comment|/* 70 */
specifier|volatile
name|u_int32_t
name|nicCmdsRefreshStats
decl_stmt|;
comment|/* 71 */
specifier|volatile
name|u_int32_t
name|nicCmdsUnknown
decl_stmt|;
comment|/* 72 */
comment|/* 	 * NIC Events 	 */
specifier|volatile
name|u_int32_t
name|nicEventsNICFirmwareOperational
decl_stmt|;
comment|/* 73 */
specifier|volatile
name|u_int32_t
name|nicEventsStatsUpdated
decl_stmt|;
comment|/* 74 */
specifier|volatile
name|u_int32_t
name|nicEventsLinkStateChanged
decl_stmt|;
comment|/* 75 */
specifier|volatile
name|u_int32_t
name|nicEventsError
decl_stmt|;
comment|/* 76 */
specifier|volatile
name|u_int32_t
name|nicEventsMCastListUpdated
decl_stmt|;
comment|/* 77 */
specifier|volatile
name|u_int32_t
name|nicEventsResetJumboRing
decl_stmt|;
comment|/* 78 */
comment|/* 	 * Ring manipulation 	 */
specifier|volatile
name|u_int32_t
name|nicRingSetSendProdIndex
decl_stmt|;
comment|/* 79 */
specifier|volatile
name|u_int32_t
name|nicRingSetSendConsIndex
decl_stmt|;
comment|/* 80 */
specifier|volatile
name|u_int32_t
name|nicRingSetRecvReturnProdIndex
decl_stmt|;
comment|/* 81 */
comment|/* 	 * Interrupts 	 */
specifier|volatile
name|u_int32_t
name|nicInterrupts
decl_stmt|;
comment|/* 82 */
specifier|volatile
name|u_int32_t
name|nicAvoidedInterrupts
decl_stmt|;
comment|/* 83 */
comment|/* 	 * BD Coalessing Thresholds 	 */
specifier|volatile
name|u_int32_t
name|nicEventThresholdHit
decl_stmt|;
comment|/* 84 */
specifier|volatile
name|u_int32_t
name|nicSendThresholdHit
decl_stmt|;
comment|/* 85 */
specifier|volatile
name|u_int32_t
name|nicRecvThresholdHit
decl_stmt|;
comment|/* 86 */
comment|/* 	 * DMA Attentions 	 */
specifier|volatile
name|u_int32_t
name|nicDmaRdOverrun
decl_stmt|;
comment|/* 87 */
specifier|volatile
name|u_int32_t
name|nicDmaRdUnderrun
decl_stmt|;
comment|/* 88 */
specifier|volatile
name|u_int32_t
name|nicDmaWrOverrun
decl_stmt|;
comment|/* 89 */
specifier|volatile
name|u_int32_t
name|nicDmaWrUnderrun
decl_stmt|;
comment|/* 90 */
specifier|volatile
name|u_int32_t
name|nicDmaWrMasterAborts
decl_stmt|;
comment|/* 91 */
specifier|volatile
name|u_int32_t
name|nicDmaRdMasterAborts
decl_stmt|;
comment|/* 92 */
comment|/* 	 * NIC Resources 	 */
specifier|volatile
name|u_int32_t
name|nicDmaWriteRingFull
decl_stmt|;
comment|/* 93 */
specifier|volatile
name|u_int32_t
name|nicDmaReadRingFull
decl_stmt|;
comment|/* 94 */
specifier|volatile
name|u_int32_t
name|nicEventRingFull
decl_stmt|;
comment|/* 95 */
specifier|volatile
name|u_int32_t
name|nicEventProducerRingFull
decl_stmt|;
comment|/* 96 */
specifier|volatile
name|u_int32_t
name|nicTxMacDescrRingFull
decl_stmt|;
comment|/* 97 */
specifier|volatile
name|u_int32_t
name|nicOutOfTxBufSpaceFrameRetry
decl_stmt|;
comment|/* 98 */
specifier|volatile
name|u_int32_t
name|nicNoMoreWrDMADescriptors
decl_stmt|;
comment|/* 99 */
specifier|volatile
name|u_int32_t
name|nicNoMoreRxBDs
decl_stmt|;
comment|/* 100 */
specifier|volatile
name|u_int32_t
name|nicNoSpaceInReturnRing
decl_stmt|;
comment|/* 101 */
specifier|volatile
name|u_int32_t
name|nicSendBDs
decl_stmt|;
comment|/* current count 102 */
specifier|volatile
name|u_int32_t
name|nicRecvBDs
decl_stmt|;
comment|/* current count 103 */
specifier|volatile
name|u_int32_t
name|nicJumboRecvBDs
decl_stmt|;
comment|/* current count 104 */
specifier|volatile
name|u_int32_t
name|nicMiniRecvBDs
decl_stmt|;
comment|/* current count 105 */
specifier|volatile
name|u_int32_t
name|nicTotalRecvBDs
decl_stmt|;
comment|/* current count 106 */
specifier|volatile
name|u_int32_t
name|nicTotalSendBDs
decl_stmt|;
comment|/* current count 107 */
specifier|volatile
name|u_int32_t
name|nicJumboSpillOver
decl_stmt|;
comment|/* 108 */
specifier|volatile
name|u_int32_t
name|nicSbusHangCleared
decl_stmt|;
comment|/* 109 */
specifier|volatile
name|u_int32_t
name|nicEnqEventDelayed
decl_stmt|;
comment|/* 110 */
comment|/* 	 * Stats from MAC rx completion 	 */
specifier|volatile
name|u_int32_t
name|nicMacRxLateColls
decl_stmt|;
comment|/* 111 */
specifier|volatile
name|u_int32_t
name|nicMacRxLinkLostDuringPkt
decl_stmt|;
comment|/* 112 */
specifier|volatile
name|u_int32_t
name|nicMacRxPhyDecodeErr
decl_stmt|;
comment|/* 113 */
specifier|volatile
name|u_int32_t
name|nicMacRxMacAbort
decl_stmt|;
comment|/* 114 */
specifier|volatile
name|u_int32_t
name|nicMacRxTruncNoResources
decl_stmt|;
comment|/* 115 */
comment|/* 	 * Stats from the mac_stats area 	 */
specifier|volatile
name|u_int32_t
name|nicMacRxDropUla
decl_stmt|;
comment|/* 116 */
specifier|volatile
name|u_int32_t
name|nicMacRxDropMcast
decl_stmt|;
comment|/* 117 */
specifier|volatile
name|u_int32_t
name|nicMacRxFlowControl
decl_stmt|;
comment|/* 118 */
specifier|volatile
name|u_int32_t
name|nicMacRxDropSpace
decl_stmt|;
comment|/* 119 */
specifier|volatile
name|u_int32_t
name|nicMacRxColls
decl_stmt|;
comment|/* 120 */
comment|/*  	 * MAC RX Attentions 	 */
specifier|volatile
name|u_int32_t
name|nicMacRxTotalAttns
decl_stmt|;
comment|/* 121 */
specifier|volatile
name|u_int32_t
name|nicMacRxLinkAttns
decl_stmt|;
comment|/* 122 */
specifier|volatile
name|u_int32_t
name|nicMacRxSyncAttns
decl_stmt|;
comment|/* 123 */
specifier|volatile
name|u_int32_t
name|nicMacRxConfigAttns
decl_stmt|;
comment|/* 124 */
specifier|volatile
name|u_int32_t
name|nicMacReset
decl_stmt|;
comment|/* 125 */
specifier|volatile
name|u_int32_t
name|nicMacRxBufDescrAttns
decl_stmt|;
comment|/* 126 */
specifier|volatile
name|u_int32_t
name|nicMacRxBufAttns
decl_stmt|;
comment|/* 127 */
specifier|volatile
name|u_int32_t
name|nicMacRxZeroFrameCleanup
decl_stmt|;
comment|/* 128 */
specifier|volatile
name|u_int32_t
name|nicMacRxOneFrameCleanup
decl_stmt|;
comment|/* 129 */
specifier|volatile
name|u_int32_t
name|nicMacRxMultipleFrameCleanup
decl_stmt|;
comment|/* 130 */
specifier|volatile
name|u_int32_t
name|nicMacRxTimerCleanup
decl_stmt|;
comment|/* 131 */
specifier|volatile
name|u_int32_t
name|nicMacRxDmaCleanup
decl_stmt|;
comment|/* 132 */
comment|/* 	 * Stats from the mac_stats area 	 */
specifier|volatile
name|u_int32_t
name|nicMacTxCollisionHistogram
index|[
literal|15
index|]
decl_stmt|;
comment|/* 133 */
comment|/* 	 * MAC TX Attentions 	 */
specifier|volatile
name|u_int32_t
name|nicMacTxTotalAttns
decl_stmt|;
comment|/* 134 */
comment|/* 	 * NIC Profile 	 */
specifier|volatile
name|u_int32_t
name|nicProfile
index|[
literal|32
index|]
decl_stmt|;
comment|/* 135 */
comment|/* 	 * Pat to 1024 bytes. 	 */
name|u_int32_t
name|pad
index|[
literal|75
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tigon general information block. This resides in host memory  * and contains the status counters, ring control blocks and  * producer pointers.  */
end_comment

begin_struct
struct|struct
name|ti_gib
block|{
name|struct
name|ti_stats
name|ti_stats
decl_stmt|;
name|struct
name|ti_rcb
name|ti_ev_rcb
decl_stmt|;
name|struct
name|ti_rcb
name|ti_cmd_rcb
decl_stmt|;
name|struct
name|ti_rcb
name|ti_tx_rcb
decl_stmt|;
name|struct
name|ti_rcb
name|ti_std_rx_rcb
decl_stmt|;
name|struct
name|ti_rcb
name|ti_jumbo_rx_rcb
decl_stmt|;
name|struct
name|ti_rcb
name|ti_mini_rx_rcb
decl_stmt|;
name|struct
name|ti_rcb
name|ti_return_rcb
decl_stmt|;
name|ti_hostaddr
name|ti_ev_prodidx_ptr
decl_stmt|;
name|ti_hostaddr
name|ti_return_prodidx_ptr
decl_stmt|;
name|ti_hostaddr
name|ti_tx_considx_ptr
decl_stmt|;
name|ti_hostaddr
name|ti_refresh_stats_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Buffer descriptor structures. There are basically three types  * of structures: normal receive descriptors, extended receive  * descriptors and transmit descriptors. The extended receive  * descriptors are optionally used only for the jumbo receive ring.  */
end_comment

begin_struct
struct|struct
name|ti_rx_desc
block|{
name|ti_hostaddr
name|ti_addr
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_idx
decl_stmt|;
name|u_int16_t
name|ti_len
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_len
decl_stmt|;
name|u_int16_t
name|ti_idx
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_type
decl_stmt|;
name|u_int16_t
name|ti_flags
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_flags
decl_stmt|;
name|u_int16_t
name|ti_type
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_ip_cksum
decl_stmt|;
name|u_int16_t
name|ti_tcp_udp_cksum
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_tcp_udp_cksum
decl_stmt|;
name|u_int16_t
name|ti_ip_cksum
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_error_flags
decl_stmt|;
name|u_int16_t
name|ti_vlan_tag
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_vlan_tag
decl_stmt|;
name|u_int16_t
name|ti_error_flags
decl_stmt|;
endif|#
directive|endif
name|u_int32_t
name|ti_rsvd
decl_stmt|;
name|u_int32_t
name|ti_opaque
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ti_rx_desc_ext
block|{
name|ti_hostaddr
name|ti_addr1
decl_stmt|;
name|ti_hostaddr
name|ti_addr2
decl_stmt|;
name|ti_hostaddr
name|ti_addr3
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_len1
decl_stmt|;
name|u_int16_t
name|ti_len2
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_len2
decl_stmt|;
name|u_int16_t
name|ti_len1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_len3
decl_stmt|;
name|u_int16_t
name|ti_rsvd0
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_rsvd0
decl_stmt|;
name|u_int16_t
name|ti_len3
decl_stmt|;
endif|#
directive|endif
name|ti_hostaddr
name|ti_addr0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_idx
decl_stmt|;
name|u_int16_t
name|ti_len0
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_len0
decl_stmt|;
name|u_int16_t
name|ti_idx
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_type
decl_stmt|;
name|u_int16_t
name|ti_flags
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_flags
decl_stmt|;
name|u_int16_t
name|ti_type
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_ip_cksum
decl_stmt|;
name|u_int16_t
name|ti_tcp_udp_cksum
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_tcp_udp_cksum
decl_stmt|;
name|u_int16_t
name|ti_ip_cksum
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_error_flags
decl_stmt|;
name|u_int16_t
name|ti_vlan_tag
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_vlan_tag
decl_stmt|;
name|u_int16_t
name|ti_error_flags
decl_stmt|;
endif|#
directive|endif
name|u_int32_t
name|ti_rsvd1
decl_stmt|;
name|u_int32_t
name|ti_opaque
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit descriptors are, mercifully, very small.  */
end_comment

begin_struct
struct|struct
name|ti_tx_desc
block|{
name|ti_hostaddr
name|ti_addr
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_len
decl_stmt|;
name|u_int16_t
name|ti_flags
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_flags
decl_stmt|;
name|u_int16_t
name|ti_len
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int16_t
name|ti_rsvd
decl_stmt|;
name|u_int16_t
name|ti_vlan_tag
decl_stmt|;
else|#
directive|else
name|u_int16_t
name|ti_vlan_tag
decl_stmt|;
name|u_int16_t
name|ti_rsvd
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE!  On the Alpha, we have an alignment constraint.  * The first thing in the packet is a 14-byte Ethernet header.  * This means that the packet is misaligned.  To compensate,  * we actually offset the data 2 bytes into the cluster.  This  * alignes the packet after the Ethernet header at a 32-bit  * boundary.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|TI_FRAMELEN
value|1518
end_define

begin_define
define|#
directive|define
name|TI_JUMBO_FRAMELEN
value|9018
end_define

begin_define
define|#
directive|define
name|TI_JUMBO_MTU
value|(TI_JUMBO_FRAMELEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|TI_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|TI_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * Buffer descriptor error flags.  */
end_comment

begin_define
define|#
directive|define
name|TI_BDERR_CRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|TI_BDERR_COLLDETECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|TI_BDERR_LINKLOST
value|0x0004
end_define

begin_define
define|#
directive|define
name|TI_BDERR_DECODE
value|0x0008
end_define

begin_define
define|#
directive|define
name|TI_BDERR_ODD_NIBBLES
value|0x0010
end_define

begin_define
define|#
directive|define
name|TI_BDERR_MAC_ABRT
value|0x0020
end_define

begin_define
define|#
directive|define
name|TI_BDERR_RUNT
value|0x0040
end_define

begin_define
define|#
directive|define
name|TI_BDERR_TRUNC
value|0x0080
end_define

begin_define
define|#
directive|define
name|TI_BDERR_GIANT
value|0x0100
end_define

begin_comment
comment|/*  * Buffer descriptor flags.  */
end_comment

begin_define
define|#
directive|define
name|TI_BDFLAG_TCP_UDP_CKSUM
value|0x0001
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_IP_CKSUM
value|0x0002
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_END
value|0x0004
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_MORE
value|0x0008
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_JUMBO_RING
value|0x0010
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_UCAST_PKT
value|0x0020
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_MCAST_PKT
value|0x0040
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_BCAST_PKT
value|0x0060
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_IP_FRAG
value|0x0080
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_IP_FRAG_END
value|0x0100
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_VLAN_TAG
value|0x0200
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_ERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_COAL_NOW
value|0x0800
end_define

begin_define
define|#
directive|define
name|TI_BDFLAG_MINI_RING
value|0x1000
end_define

begin_comment
comment|/*  * Descriptor type flags. I think these only have meaning for  * the Tigon 1. I had to extract them from the sample driver source  * since they aren't in the manual.  */
end_comment

begin_define
define|#
directive|define
name|TI_BDTYPE_TYPE_NULL
value|0x0000
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_BD
value|0x0001
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_RECV_BD
value|0x0002
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_RECV_JUMBO_BD
value|0x0003
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_RECV_BD_LAST
value|0x0004
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DATA
value|0x0005
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DATA_LAST
value|0x0006
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_RECV_DATA
value|0x0007
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_RECV_DATA_LAST
value|0x000b
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_EVENT_RUPT
value|0x000c
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_EVENT_NO_RUPT
value|0x000d
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_ODD_START
value|0x000e
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_UPDATE_STATS
value|0x000f
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DUMMY_DMA
value|0x0010
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_EVENT_PROD
value|0x0011
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_TX_CONS
value|0x0012
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_RX_PROD
value|0x0013
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_REFRESH_STATS
value|0x0014
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DATA_LAST_VLAN
value|0x0015
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DATA_COAL
value|0x0016
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DATA_LAST_COAL
value|0x0017
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_SEND_DATA_LAST_VLAN_COAL
value|0x0018
end_define

begin_define
define|#
directive|define
name|TI_BDTYPE_TX_CONS_NO_INTR
value|0x0019
end_define

begin_comment
comment|/*  * Tigon command structure.  */
end_comment

begin_struct
struct|struct
name|ti_cmd_desc
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int32_t
name|ti_cmd
range|:
literal|8
decl_stmt|;
name|u_int32_t
name|ti_code
range|:
literal|12
decl_stmt|;
name|u_int32_t
name|ti_idx
range|:
literal|12
decl_stmt|;
else|#
directive|else
name|u_int32_t
name|ti_idx
range|:
literal|12
decl_stmt|;
name|u_int32_t
name|ti_code
range|:
literal|12
decl_stmt|;
name|u_int32_t
name|ti_cmd
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TI_CMD_HOST_STATE
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_STACK_UP
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_STACK_DOWN
value|0x02
end_define

begin_comment
comment|/*  * This command enables software address filtering. It's a workaround  * for a bug in the Tigon 1 and not implemented for the Tigon 2.  */
end_comment

begin_define
define|#
directive|define
name|TI_CMD_FDR_FILTERING
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_FILT_ENB
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_FILT_DIS
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_CMD_SET_RX_PROD_IDX
value|0x03
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_CMD_UPDATE_GENCOM
value|0x04
end_define

begin_define
define|#
directive|define
name|TI_CMD_RESET_JUMBO_RING
value|0x05
end_define

begin_define
define|#
directive|define
name|TI_CMD_SET_PARTIAL_RX_CNT
value|0x06
end_define

begin_define
define|#
directive|define
name|TI_CMD_ADD_MCAST_ADDR
value|0x08
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_CMD_DEL_MCAST_ADDR
value|0x09
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_CMD_SET_PROMISC_MODE
value|0x0A
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_PROMISC_ENB
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_PROMISC_DIS
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_CMD_LINK_NEGOTIATION
value|0x0B
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_NEGOTIATE_BOTH
value|0x00
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_NEGOTIATE_GIGABIT
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_NEGOTIATE_10_100
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_CMD_SET_MAC_ADDR
value|0x0C
end_define

begin_define
define|#
directive|define
name|TI_CMD_CLR_PROFILE
value|0x0D
end_define

begin_define
define|#
directive|define
name|TI_CMD_SET_ALLMULTI
value|0x0E
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_ALLMULTI_ENB
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_CMD_CODE_ALLMULTI_DIS
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_CMD_CLR_STATS
value|0x0F
end_define

begin_define
define|#
directive|define
name|TI_CMD_SET_RX_JUMBO_PROD_IDX
value|0x10
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|TI_CMD_RFRSH_STATS
value|0x11
end_define

begin_define
define|#
directive|define
name|TI_CMD_EXT_ADD_MCAST
value|0x12
end_define

begin_define
define|#
directive|define
name|TI_CMD_EXT_DEL_MCAST
value|0x13
end_define

begin_comment
comment|/*  * Utility macros to make issuing commands a little simpler. Assumes  * that 'sc' and 'cmd' are in local scope.  */
end_comment

begin_define
define|#
directive|define
name|TI_DO_CMD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|cmd.ti_cmd = x;			\ 	cmd.ti_code = y;		\ 	cmd.ti_idx = z;			\ 	ti_cmd(sc,&cmd);
end_define

begin_define
define|#
directive|define
name|TI_DO_CMD_EXT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|cmd.ti_cmd = x;			\ 	cmd.ti_code = y;		\ 	cmd.ti_idx = z;			\ 	ti_cmd_ext(sc,&cmd, v, w);
end_define

begin_comment
comment|/*  * Other utility macros.  */
end_comment

begin_define
define|#
directive|define
name|TI_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_define
define|#
directive|define
name|TI_UPDATE_JUMBOPROD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|if (x->ti_hwrev == TI_HWREV_TIGON) {				\ 		TI_DO_CMD(TI_CMD_SET_RX_JUMBO_PROD_IDX, 0, y);	\ 	} else {							\ 		CSR_WRITE_4(x, TI_MB_JUMBORXPROD_IDX, y);		\ 	}
end_define

begin_define
define|#
directive|define
name|TI_UPDATE_MINIPROD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|CSR_WRITE_4(x, TI_MB_MINIRXPROD_IDX, y);
end_define

begin_define
define|#
directive|define
name|TI_UPDATE_STDPROD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|if (x->ti_hwrev == TI_HWREV_TIGON) {				\ 		TI_DO_CMD(TI_CMD_SET_RX_PROD_IDX, 0, y);		\ 	} else {							\ 		CSR_WRITE_4(x, TI_MB_STDRXPROD_IDX, y);			\ 	}
end_define

begin_comment
comment|/*  * Tigon event structure.  */
end_comment

begin_struct
struct|struct
name|ti_event_desc
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int32_t
name|ti_event
range|:
literal|8
decl_stmt|;
name|u_int32_t
name|ti_code
range|:
literal|12
decl_stmt|;
name|u_int32_t
name|ti_idx
range|:
literal|12
decl_stmt|;
else|#
directive|else
name|u_int32_t
name|ti_idx
range|:
literal|12
decl_stmt|;
name|u_int32_t
name|ti_code
range|:
literal|12
decl_stmt|;
name|u_int32_t
name|ti_event
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
name|u_int32_t
name|ti_rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tigon events.  */
end_comment

begin_define
define|#
directive|define
name|TI_EV_FIRMWARE_UP
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_EV_STATS_UPDATED
value|0x04
end_define

begin_define
define|#
directive|define
name|TI_EV_LINKSTAT_CHANGED
value|0x06
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_GIG_LINK_UP
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_LINK_DOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_LINK_UP
value|0x03
end_define

begin_define
define|#
directive|define
name|TI_EV_ERROR
value|0x07
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_ERR_INVAL_CMD
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_ERR_UNIMP_CMD
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_ERR_BADCFG
value|0x03
end_define

begin_define
define|#
directive|define
name|TI_EV_MCAST_UPDATED
value|0x08
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_MCAST_ADD
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_EV_CODE_MCAST_DEL
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_EV_RESET_JUMBO_RING
value|0x09
end_define

begin_comment
comment|/*  * Register access macros. The Tigon always uses memory mapped register  * accesses and all registers must be accessed with 32 bit operations.  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->ti_btag, sc->ti_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->ti_btag, sc->ti_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|TI_SETBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, (CSR_READ_4(sc, reg) | x))
end_define

begin_define
define|#
directive|define
name|TI_CLRBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, (CSR_READ_4(sc, reg)& ~x))
end_define

begin_comment
comment|/*  * Memory management stuff. Note: the SSLOTS, MSLOTS and JSLOTS  * values are tuneable. They control the actual amount of buffers  * allocated for the standard, mini and jumbo receive rings.  */
end_comment

begin_define
define|#
directive|define
name|TI_SSLOTS
value|256
end_define

begin_define
define|#
directive|define
name|TI_MSLOTS
value|256
end_define

begin_define
define|#
directive|define
name|TI_JSLOTS
value|384
end_define

begin_define
define|#
directive|define
name|TI_JRAWLEN
value|(TI_JUMBO_FRAMELEN + ETHER_ALIGN + sizeof(u_int64_t))
end_define

begin_define
define|#
directive|define
name|TI_JLEN
value|(TI_JRAWLEN + (sizeof(u_int64_t) - \ 	(TI_JRAWLEN % sizeof(u_int64_t))))
end_define

begin_define
define|#
directive|define
name|TI_JPAGESZ
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|TI_RESID
value|(TI_JPAGESZ - (TI_JLEN * TI_JSLOTS) % TI_JPAGESZ)
end_define

begin_define
define|#
directive|define
name|TI_JMEM
value|((TI_JLEN * TI_JSLOTS) + TI_RESID)
end_define

begin_struct
struct|struct
name|ti_jslot
block|{
name|caddr_t
name|ti_buf
decl_stmt|;
name|int
name|ti_inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ring structures. Most of these reside in host memory and we tell  * the NIC where they are via the ring control blocks. The exceptions  * are the tx and command rings, which live in NIC memory and which  * we access via the shared memory window.  */
end_comment

begin_struct
struct|struct
name|ti_ring_data
block|{
name|struct
name|ti_rx_desc
name|ti_rx_std_ring
index|[
name|TI_STD_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|ti_rx_desc
name|ti_rx_jumbo_ring
index|[
name|TI_JUMBO_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|ti_rx_desc
name|ti_rx_mini_ring
index|[
name|TI_MINI_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|ti_rx_desc
name|ti_rx_return_ring
index|[
name|TI_RETURN_RING_CNT
index|]
decl_stmt|;
name|struct
name|ti_event_desc
name|ti_event_ring
index|[
name|TI_EVENT_RING_CNT
index|]
decl_stmt|;
name|struct
name|ti_tx_desc
name|ti_tx_ring
index|[
name|TI_TX_RING_CNT
index|]
decl_stmt|;
comment|/* 	 * Make sure producer structures are aligned on 32-byte cache 	 * line boundaries. 	 */
name|struct
name|ti_producer
name|ti_ev_prodidx_r
decl_stmt|;
name|u_int32_t
name|ti_pad0
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|ti_producer
name|ti_return_prodidx_r
decl_stmt|;
name|u_int32_t
name|ti_pad1
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|ti_producer
name|ti_tx_considx_r
decl_stmt|;
name|u_int32_t
name|ti_pad2
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|ti_tx_desc
modifier|*
name|ti_tx_ring_nic
decl_stmt|;
comment|/* pointer to shared mem */
name|struct
name|ti_cmd_desc
modifier|*
name|ti_cmd_ring
decl_stmt|;
comment|/* pointer to shared mem */
name|struct
name|ti_gib
name|ti_info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mbuf pointers. We need these to keep track of the virtual addresses  * of our mbuf chains since we can only convert from physical to virtual,  * not the other way around.  */
end_comment

begin_struct
struct|struct
name|ti_chain_data
block|{
name|struct
name|mbuf
modifier|*
name|ti_tx_chain
index|[
name|TI_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ti_rx_std_chain
index|[
name|TI_STD_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ti_rx_jumbo_chain
index|[
name|TI_JUMBO_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ti_rx_mini_chain
index|[
name|TI_MINI_RX_RING_CNT
index|]
decl_stmt|;
comment|/* Stick the jumbo mem management stuff here too. */
name|struct
name|ti_jslot
name|ti_jslots
index|[
name|TI_JSLOTS
index|]
decl_stmt|;
name|void
modifier|*
name|ti_jumbo_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ti_type
block|{
name|u_int16_t
name|ti_vid
decl_stmt|;
name|u_int16_t
name|ti_did
decl_stmt|;
name|char
modifier|*
name|ti_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TI_HWREV_TIGON
value|0x01
end_define

begin_define
define|#
directive|define
name|TI_HWREV_TIGON_II
value|0x02
end_define

begin_define
define|#
directive|define
name|TI_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|TI_TXCONS_UNSET
value|0xFFFF
end_define

begin_comment
comment|/* impossible value */
end_comment

begin_struct
struct|struct
name|ti_mc_entry
block|{
name|struct
name|ether_addr
name|mc_addr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ti_mc_entry
argument_list|)
name|mc_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ti_jpool_entry
block|{
name|int
name|slot
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ti_jpool_entry
argument_list|)
name|jpool_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ti_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|bus_space_handle_t
name|ti_bhandle
decl_stmt|;
name|vm_offset_t
name|ti_vhandle
decl_stmt|;
name|bus_space_tag_t
name|ti_btag
decl_stmt|;
name|void
modifier|*
name|ti_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|ti_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|ti_res
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* media info */
name|u_int8_t
name|ti_unit
decl_stmt|;
comment|/* interface number */
name|u_int8_t
name|ti_hwrev
decl_stmt|;
comment|/* Tigon rev (1 or 2) */
name|u_int8_t
name|ti_copper
decl_stmt|;
comment|/* 1000baseTX card */
name|u_int8_t
name|ti_linkstat
decl_stmt|;
comment|/* Link state */
name|struct
name|ti_ring_data
modifier|*
name|ti_rdata
decl_stmt|;
comment|/* rings */
name|struct
name|ti_chain_data
name|ti_cdata
decl_stmt|;
comment|/* mbufs */
define|#
directive|define
name|ti_ev_prodidx
value|ti_rdata->ti_ev_prodidx_r
define|#
directive|define
name|ti_return_prodidx
value|ti_rdata->ti_return_prodidx_r
define|#
directive|define
name|ti_tx_considx
value|ti_rdata->ti_tx_considx_r
name|u_int16_t
name|ti_tx_saved_considx
decl_stmt|;
name|u_int16_t
name|ti_rx_saved_considx
decl_stmt|;
name|u_int16_t
name|ti_ev_saved_considx
decl_stmt|;
name|u_int16_t
name|ti_cmd_saved_prodidx
decl_stmt|;
name|u_int16_t
name|ti_std
decl_stmt|;
comment|/* current std ring head */
name|u_int16_t
name|ti_mini
decl_stmt|;
comment|/* current mini ring head */
name|u_int16_t
name|ti_jumbo
decl_stmt|;
comment|/* current jumo ring head */
name|SLIST_HEAD
argument_list|(
argument|__ti_mchead
argument_list|,
argument|ti_mc_entry
argument_list|)
name|ti_mc_listhead
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__ti_jfreehead
argument_list|,
argument|ti_jpool_entry
argument_list|)
name|ti_jfree_listhead
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__ti_jinusehead
argument_list|,
argument|ti_jpool_entry
argument_list|)
name|ti_jinuse_listhead
expr_stmt|;
name|u_int32_t
name|ti_stat_ticks
decl_stmt|;
name|u_int32_t
name|ti_rx_coal_ticks
decl_stmt|;
name|u_int32_t
name|ti_tx_coal_ticks
decl_stmt|;
name|u_int32_t
name|ti_rx_max_coal_bds
decl_stmt|;
name|u_int32_t
name|ti_tx_max_coal_bds
decl_stmt|;
name|u_int32_t
name|ti_tx_buf_ratio
decl_stmt|;
name|int
name|ti_if_flags
decl_stmt|;
name|int
name|ti_txcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Microchip Technology 24Cxx EEPROM control bytes  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CTL_READ
value|0xA1
end_define

begin_comment
comment|/* 0101 0001 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_CTL_WRITE
value|0xA0
end_define

begin_comment
comment|/* 0101 0000 */
end_comment

begin_comment
comment|/*  * Note that EEPROM_START leaves transmission enabled.  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_START
define|\
value|TI_SETBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_CLK);
comment|/* Pull clock pin high */
value|\ 	TI_SETBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_DOUT);
comment|/* Set DATA bit to 1 */
value|\ 	TI_SETBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_TXEN);
comment|/* Enable xmit to write bit */
value|\ 	TI_CLRBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_DOUT);
comment|/* Pull DATA bit to 0 again */
value|\ 	TI_CLRBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_CLK);
end_define

begin_comment
comment|/* Pull clock low again */
end_comment

begin_comment
comment|/*  * EEPROM_STOP ends access to the EEPROM and clears the ETXEN bit so  * that no further data can be written to the EEPROM I/O pin.  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_STOP
define|\
value|TI_CLRBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_TXEN);
comment|/* Disable xmit */
value|\ 	TI_CLRBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_DOUT);
comment|/* Pull DATA to 0 */
value|\ 	TI_SETBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_CLK);
comment|/* Pull clock high */
value|\ 	TI_SETBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_TXEN);
comment|/* Enable xmit */
value|\ 	TI_SETBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_DOUT);
comment|/* Toggle DATA to 1 */
value|\ 	TI_CLRBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_TXEN);
comment|/* Disable xmit. */
value|\ 	TI_CLRBIT(sc, TI_MISC_LOCAL_CTL, TI_MLC_EE_CLK);
end_define

begin_comment
comment|/* Pull clock low again */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)va)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

