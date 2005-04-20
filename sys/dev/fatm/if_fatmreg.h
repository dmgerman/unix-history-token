begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Fore PCA200E hardware definitions.  */
end_comment

begin_comment
comment|/*  * Fore implements some additional PCI registers. One of them is the  * master control register. One of the bits allow to automatically byte  * swap accesses to the on-board RAM.  */
end_comment

begin_define
define|#
directive|define
name|FATM_PCIR_MCTL
value|0x41
end_define

begin_define
define|#
directive|define
name|FATM_PCIM_SWAB
value|0x100
end_define

begin_comment
comment|/*  * Operations codes for commands.  */
end_comment

begin_enum
enum|enum
block|{
name|FATM_OP_INITIALIZE
init|=
literal|0x01
block|,
comment|/* Initialize the card */
name|FATM_OP_ACTIVATE_VCIN
init|=
literal|0x02
block|,
comment|/* Start reassembly on a channel */
name|FATM_OP_ACTIVATE_VCOUT
init|=
literal|0x03
block|,
comment|/* (not used) */
name|FATM_OP_DEACTIVATE_VCIN
init|=
literal|0x04
block|,
comment|/* Stop reassembly on a channel */
name|FATM_OP_DEACTIVATE_VCOUT
init|=
literal|0x05
block|,
comment|/* (not used) */
name|FATM_OP_REQUEST_STATS
init|=
literal|0x06
block|,
comment|/* Get statistics */
name|FATM_OP_OC3_SET_REG
init|=
literal|0x07
block|,
comment|/* Set OC3 chip register */
name|FATM_OP_OC3_GET_REG
init|=
literal|0x08
block|,
comment|/* Get OC3 chip registers */
name|FATM_OP_ZERO_STATS
init|=
literal|0x09
block|,
comment|/* Zero out statistics */
name|FATM_OP_GET_PROM_DATA
init|=
literal|0x0a
block|,
comment|/* Return expansion ROM data */
name|FATM_OP_SETVPI_BITS
init|=
literal|0x0b
block|,
comment|/* (not used, not implemented) */
name|FATM_OP_INTERRUPT_SEL
init|=
literal|0x80
block|,
comment|/* Request interrupt on completion */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Status word definitions. Before initiating an operation the host sets the  * status word to PENDING. The card sets it to COMPLETE upon completion of  * the transmit/receive or command. An unused queue entry contains FREE.  * The ERROR can be ored into the COMPLETE. Note, that there are circumstances  * when ERROR is set without COMPLETE beeing set (when you try to activate  * a bad VCI like, for example, VCI 0).  */
end_comment

begin_enum
enum|enum
block|{
name|FATM_STAT_PENDING
init|=
literal|0x01
block|,
name|FATM_STAT_COMPLETE
init|=
literal|0x02
block|,
name|FATM_STAT_FREE
init|=
literal|0x04
block|,
name|FATM_STAT_ERROR
init|=
literal|0x08
block|, }
enum|;
end_enum

begin_comment
comment|/*  * On board queue offsets. There are two fundamentally different queue types:  * the command queue and all other queues. The command queue has 32 byte  * entries on the card which contain the operation code, parameters and the  * DMA pointer to the status word. All other queues have 8 byte entries, which  * contain a DMA pointer to the i/o block, that contains the parameters, and  * a DMA pointer to the status word.  */
end_comment

begin_define
define|#
directive|define
name|FATMOC_OP
value|0
end_define

begin_comment
comment|/* cmd queue: offset to op code */
end_comment

begin_define
define|#
directive|define
name|FATMOC_PARAM
value|4
end_define

begin_comment
comment|/* cmd queue: offset to parameters */
end_comment

begin_define
define|#
directive|define
name|FATMOC_STATP
value|16
end_define

begin_comment
comment|/* cmd queue: offset to status ptr */
end_comment

begin_define
define|#
directive|define
name|FATMOC_END
value|32
end_define

begin_comment
comment|/* cmd queue: element size */
end_comment

begin_define
define|#
directive|define
name|FATMOC_ACTIN_VPVC
value|(FATMOC_PARAM + 0)
end_define

begin_define
define|#
directive|define
name|FATMOC_ACTIN_MTU
value|(FATMOC_PARAM + 4)
end_define

begin_define
define|#
directive|define
name|FATMOC_DEACTIN_VPVC
value|(FATMOC_PARAM + 0)
end_define

begin_define
define|#
directive|define
name|FATMOC_GETOC3_BUF
value|(FATMOC_PARAM + 0)
end_define

begin_define
define|#
directive|define
name|FATMOC_GSTAT_BUF
value|(FATMOC_PARAM + 0)
end_define

begin_define
define|#
directive|define
name|FATMOC_GPROM_BUF
value|(FATMOC_PARAM + 0)
end_define

begin_define
define|#
directive|define
name|FATMOS_IOBLK
value|0
end_define

begin_comment
comment|/* other queues: offset to ioblk ptr */
end_comment

begin_define
define|#
directive|define
name|FATMOS_STATP
value|4
end_define

begin_comment
comment|/* other queues: offset to status ptr */
end_comment

begin_define
define|#
directive|define
name|FATM_MAKE_SETOC3
parameter_list|(
name|REG
parameter_list|,
name|VAL
parameter_list|,
name|MASK
parameter_list|)
define|\
value|(FATM_OP_OC3_SET_REG | (((REG)& 0xff)<< 8) | 			\      (((VAL)& 0xff)<< 16) | (((MASK)& 0xff)<< 24))
end_define

begin_define
define|#
directive|define
name|FATM_NREGS
value|128
end_define

begin_comment
comment|/*  * On board memory layout.  *  * The card contains up to 2MByte memory that is mapped at virtual offset 0.  * It is followed by three registers. The memory contains two areas at  * fixed addresses: the mon960 area that is used for communication with  * the card's operating system and the common block that is used by the  * firmware to communicate with the driver.  */
end_comment

begin_define
define|#
directive|define
name|FATM_RAM_SIZE
value|(256 * 1024)
end_define

begin_comment
comment|/* normal RAM size */
end_comment

begin_define
define|#
directive|define
name|FATMO_RAM
value|(0x0)
end_define

begin_comment
comment|/* virtual RAM start */
end_comment

begin_define
define|#
directive|define
name|FATMO_MON960
value|(0x400)
end_define

begin_comment
comment|/* mon960 communication area */
end_comment

begin_define
define|#
directive|define
name|FATMO_COMMON_ORIGIN
value|(0x4d40)
end_define

begin_comment
comment|/* firmware comm. area */
end_comment

begin_define
define|#
directive|define
name|FATMO_HCR
value|(0x100000)
end_define

begin_comment
comment|/* host control registers */
end_comment

begin_define
define|#
directive|define
name|FATMO_HIMR
value|(0x100004)
end_define

begin_comment
comment|/* host interrupt mask */
end_comment

begin_define
define|#
directive|define
name|FATMO_PSR
value|(0x100008)
end_define

begin_comment
comment|/* PCI control register */
end_comment

begin_define
define|#
directive|define
name|FATMO_END
value|(0x200000)
end_define

begin_comment
comment|/* end of mapped area */
end_comment

begin_comment
comment|/*  * The mon960 area contains two cells that are used as a virtual serial  * interface, a status word, the base for loading the application (i.e.  * firmware) and a version number.  */
end_comment

begin_define
define|#
directive|define
name|FATMO_UART_TO_960
value|(FATMO_MON960 + 0)
end_define

begin_define
define|#
directive|define
name|FATMO_UART_TO_HOST
value|(FATMO_MON960 + 4)
end_define

begin_define
define|#
directive|define
name|FATMO_BOOT_STATUS
value|(FATMO_MON960 + 8)
end_define

begin_define
define|#
directive|define
name|FATMO_APP_BASE
value|(FATMO_MON960 + 12)
end_define

begin_define
define|#
directive|define
name|FATMO_VERSION
value|(FATMO_MON960 + 16)
end_define

begin_comment
comment|/*  * The host control register allows to hold the i960 or send it interrupts.  * The bits have different meaning on read and write.  */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_RESET
value|0x01
end_define

begin_comment
comment|/* (W) reset the card */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_LOCK_HOLD
value|0x02
end_define

begin_comment
comment|/* (W) hold the i960 */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_I960FAIL
value|0x04
end_define

begin_comment
comment|/* (R) internal self-test failed */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_INTR2
value|0x04
end_define

begin_comment
comment|/* (W) assert i960 interrupt 2 */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_HOLDA
value|0x08
end_define

begin_comment
comment|/* (R) hold ack from i960 */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_INTR1
value|0x08
end_define

begin_comment
comment|/* (W) assert i960 interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_OFIFO
value|0x10
end_define

begin_comment
comment|/* (R) DMA request FIFO full */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_CLRIRQ
value|0x10
end_define

begin_comment
comment|/* (W) clear interrupt request */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_ESP_HOLD
value|0x20
end_define

begin_comment
comment|/* (R) SAR chip holds i960 */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_IFIFO
value|0x40
end_define

begin_comment
comment|/* (R) input FIFO full */
end_comment

begin_define
define|#
directive|define
name|FATM_HCR_TESTMODE
value|0x80
end_define

begin_comment
comment|/* (R) board is in test mode */
end_comment

begin_comment
comment|/*  * The mon960 area contains a virtual UART and a status word.  * The UART uses a simple protocol: a zero means, that there is no  * character available from the i960 or that one can write the next  * character to the i960. This character has to be ored with 0x1000000  * to signal to the i960 that there is a new character.  * The cold_start values must be written to the status word, the others  * denote certain stages of initializing.  */
end_comment

begin_define
define|#
directive|define
name|XMIT_READY
value|0
end_define

begin_define
define|#
directive|define
name|CHAR_AVAIL
value|0x1000000
end_define

begin_define
define|#
directive|define
name|COLD_START
value|0xc01dc01d
end_define

begin_define
define|#
directive|define
name|SELF_TEST_OK
value|0x02201958
end_define

begin_define
define|#
directive|define
name|SELF_TEST_FAIL
value|0xadbadbad
end_define

begin_define
define|#
directive|define
name|CP_RUNNING
value|0xce11feed
end_define

begin_define
define|#
directive|define
name|MON906_TOO_BIG
value|0x10aded00
end_define

begin_comment
comment|/*  * The firmware communication area contains a big structure most of which  * is used only during initialisation.  */
end_comment

begin_comment
comment|/*  * These are the offsets to the onboard queues that are valid after the  * initialisation command has completed.  */
end_comment

begin_define
define|#
directive|define
name|FATMO_COMMAND_QUEUE
value|(FATMO_COMMON_ORIGIN + 0)
end_define

begin_define
define|#
directive|define
name|FATMO_TRANSMIT_QUEUE
value|(FATMO_COMMON_ORIGIN + 4)
end_define

begin_define
define|#
directive|define
name|FATMO_RECEIVE_QUEUE
value|(FATMO_COMMON_ORIGIN + 8)
end_define

begin_define
define|#
directive|define
name|FATMO_SMALL_B1_QUEUE
value|(FATMO_COMMON_ORIGIN + 12)
end_define

begin_define
define|#
directive|define
name|FATMO_LARGE_B1_QUEUE
value|(FATMO_COMMON_ORIGIN + 16)
end_define

begin_define
define|#
directive|define
name|FATMO_SMALL_B2_QUEUE
value|(FATMO_COMMON_ORIGIN + 20)
end_define

begin_define
define|#
directive|define
name|FATMO_LARGE_B2_QUEUE
value|(FATMO_COMMON_ORIGIN + 24)
end_define

begin_comment
comment|/*  * If the interrupt mask is set to 1, interrupts to the host are queued, but  * inhbited. The istat variable is set, when this card has posted an interrupt.  */
end_comment

begin_define
define|#
directive|define
name|FATMO_IMASK
value|(FATMO_COMMON_ORIGIN + 28)
end_define

begin_define
define|#
directive|define
name|FATMO_ISTAT
value|(FATMO_COMMON_ORIGIN + 32)
end_define

begin_comment
comment|/*  * This is the offset and the size of the queue area. Could be used to  * dynamically compute queue sizes.  */
end_comment

begin_define
define|#
directive|define
name|FATMO_HEAP_BASE
value|(FATMO_COMMON_ORIGIN + 36)
end_define

begin_define
define|#
directive|define
name|FATMO_HEAP_SIZE
value|(FATMO_COMMON_ORIGIN + 40)
end_define

begin_define
define|#
directive|define
name|FATMO_HLOGGER
value|(FATMO_COMMON_ORIGIN + 44)
end_define

begin_comment
comment|/*  * The heartbeat variable is incremented in each loop of the normal processing.  * If it is stuck this means, that the card had a fatal error. In this case  * it may set the word to a number of values of the form 0xdeadXXXX where  * XXXX is an error code.  */
end_comment

begin_define
define|#
directive|define
name|FATMO_HEARTBEAT
value|(FATMO_COMMON_ORIGIN + 48)
end_define

begin_define
define|#
directive|define
name|FATMO_FIRMWARE_RELEASE
value|(FATMO_COMMON_ORIGIN + 52)
end_define

begin_define
define|#
directive|define
name|FATMO_MON960_RELEASE
value|(FATMO_COMMON_ORIGIN + 56)
end_define

begin_define
define|#
directive|define
name|FATMO_TQ_PLEN
value|(FATMO_COMMON_ORIGIN + 60)
end_define

begin_comment
comment|/*  * At this offset the init command block is located. The init command cannot  * use the normal queue mechanism because it is used to initialize the  * queues. For this reason it is located at this fixed offset.  */
end_comment

begin_define
define|#
directive|define
name|FATMO_INIT
value|(FATMO_COMMON_ORIGIN + 64)
end_define

begin_comment
comment|/*  * physical media type  */
end_comment

begin_define
define|#
directive|define
name|FATMO_MEDIA_TYPE
value|(FATMO_COMMON_ORIGIN + 176)
end_define

begin_define
define|#
directive|define
name|FATMO_OC3_REVISION
value|(FATMO_COMMON_ORIGIN + 180)
end_define

begin_comment
comment|/*  * End of the common block  */
end_comment

begin_define
define|#
directive|define
name|FATMO_COMMON_END
value|(FATMO_COMMON_ORIGIN + 184)
end_define

begin_comment
comment|/*  * The INITIALIZE command block. This is embedded into the above common  * block. The offsets are from the beginning of the command block.  */
end_comment

begin_define
define|#
directive|define
name|FATMOI_OP
value|0
end_define

begin_comment
comment|/* operation code */
end_comment

begin_define
define|#
directive|define
name|FATMOI_STATUS
value|4
end_define

begin_comment
comment|/* status word */
end_comment

begin_define
define|#
directive|define
name|FATMOI_RECEIVE_TRESHOLD
value|8
end_define

begin_comment
comment|/* when to start interrupting */
end_comment

begin_define
define|#
directive|define
name|FATMOI_NUM_CONNECT
value|12
end_define

begin_comment
comment|/* max number of VCIs */
end_comment

begin_define
define|#
directive|define
name|FATMOI_CQUEUE_LEN
value|16
end_define

begin_comment
comment|/* length of command queue */
end_comment

begin_define
define|#
directive|define
name|FATMOI_TQUEUE_LEN
value|20
end_define

begin_comment
comment|/* length of transmit queue */
end_comment

begin_define
define|#
directive|define
name|FATMOI_RQUEUE_LEN
value|24
end_define

begin_comment
comment|/* length of receive queue */
end_comment

begin_define
define|#
directive|define
name|FATMOI_RPD_EXTENSION
value|28
end_define

begin_comment
comment|/* additional 32 byte blocks */
end_comment

begin_define
define|#
directive|define
name|FATMOI_TPD_EXTENSION
value|32
end_define

begin_comment
comment|/* additional 32 byte blocks */
end_comment

begin_define
define|#
directive|define
name|FATMOI_CONLESS_VPVC
value|36
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|FATMOI_SMALL_B1
value|48
end_define

begin_comment
comment|/* small buffer 1 pool */
end_comment

begin_define
define|#
directive|define
name|FATMOI_LARGE_B1
value|64
end_define

begin_comment
comment|/* small buffer 2 pool */
end_comment

begin_define
define|#
directive|define
name|FATMOI_SMALL_B2
value|80
end_define

begin_comment
comment|/* large buffer 1 pool */
end_comment

begin_define
define|#
directive|define
name|FATMOI_LARGE_B2
value|96
end_define

begin_comment
comment|/* large buffer 2 pool */
end_comment

begin_define
define|#
directive|define
name|FATMOI_END
value|112
end_define

begin_comment
comment|/* size of init block */
end_comment

begin_comment
comment|/*  * Each of the four buffer schemes is initialized with a block that  * contains four words:  */
end_comment

begin_define
define|#
directive|define
name|FATMOB_QUEUE_LENGTH
value|0
end_define

begin_comment
comment|/* supply queue length */
end_comment

begin_define
define|#
directive|define
name|FATMOB_BUFFER_SIZE
value|4
end_define

begin_comment
comment|/* size of each buffer */
end_comment

begin_define
define|#
directive|define
name|FATMOB_POOL_SIZE
value|8
end_define

begin_comment
comment|/* size of on-board pool */
end_comment

begin_define
define|#
directive|define
name|FATMOB_SUPPLY_BLKSIZE
value|12
end_define

begin_comment
comment|/* number of buffers/supply */
end_comment

begin_comment
comment|/*  * The fore firmware is a binary file, that starts with a header. The  * header contains the offset to where the file must be loaded and the  * entry for execution. The header must also be loaded onto the card!  */
end_comment

begin_struct
struct|struct
name|firmware
block|{
name|uint32_t
name|id
decl_stmt|;
comment|/* "FORE" */
name|uint32_t
name|version
decl_stmt|;
comment|/* firmware version */
name|uint32_t
name|offset
decl_stmt|;
comment|/* load offset */
name|uint32_t
name|entry
decl_stmt|;
comment|/* entry point */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FATM_FWID
value|0x65726f66
end_define

begin_comment
comment|/* "FORE" */
end_comment

begin_define
define|#
directive|define
name|FATM_FWVERSION
value|0x100
end_define

begin_comment
comment|/* supported version */
end_comment

begin_comment
comment|/*  * PDUs to be transmitted are described by Transmit PDU Descriptors.  * These descriptors are held in host memory, but referenced from the ioblk  * member of the queue structure on the card. The card DMAs the descriptor  * and than gather-DMAs the PDU transmitting it on-the-fly. Tpds are variable  * length in blocks of 32 byte (8 words). The minimum length is one block,  * maximum 15. The number of blocks beyond 1 is configured during the  * initialisation command (tpd_extension).  * Each gather-DMA segment is described by a segment descriptor. The buffer  * address and the length must be a multiple of four.  * Tpd must also be 4 byte aligned.  * Because of the minimum length of 32 byte, the first blocks contains already  * 2 segement descriptors. Each extension block holds four descriptors.  */
end_comment

begin_define
define|#
directive|define
name|TXD_FIXED
value|2
end_define

begin_define
define|#
directive|define
name|SEGS_PER_BLOCK
value|4
end_define

begin_comment
comment|/* segment descriptors per extension block */
end_comment

begin_struct
struct|struct
name|txseg
block|{
name|uint32_t
name|buffer
decl_stmt|;
comment|/* DMA buffer address */
name|uint32_t
name|length
decl_stmt|;
comment|/* and length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tpd
block|{
name|uint32_t
name|atm_header
decl_stmt|;
comment|/* header for the transmitted cells */
name|uint32_t
name|spec
decl_stmt|;
comment|/* PDU description */
name|uint32_t
name|stream
decl_stmt|;
comment|/* traffic shaping word */
name|uint32_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|txseg
name|segment
index|[
name|TXD_FIXED
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TDX_MKSPEC
parameter_list|(
name|INTR
parameter_list|,
name|AAL
parameter_list|,
name|NSEG
parameter_list|,
name|LEN
parameter_list|)
define|\
value|(((INTR)<< 28) | ((AAL)<< 24) | ((NSEG)<< 16) | (LEN))
end_define

begin_define
define|#
directive|define
name|TDX_MKSTR
parameter_list|(
name|DATA
parameter_list|,
name|IDLE
parameter_list|)
define|\
value|(((DATA)<< 16) | (IDLE))
end_define

begin_define
define|#
directive|define
name|TDX_MKHDR
parameter_list|(
name|VPI
parameter_list|,
name|VCI
parameter_list|,
name|PT
parameter_list|,
name|CLP
parameter_list|)
define|\
value|(((VPI)<< 20) | ((VCI)<< 4) | ((PT)<< 1) | (CLP))
end_define

begin_define
define|#
directive|define
name|TDX_SEGS2BLKS
parameter_list|(
name|SEGS
parameter_list|)
define|\
value|(1 + ((SEGS)-TXD_FIXED+SEGS_PER_BLOCK-1)/SEGS_PER_BLOCK)
end_define

begin_comment
comment|/*  * We want probably support scatter transmission, so we use the maximum  * transmit descriptor extension that is possible. Because the size of the  * Tpd is encoded in 32-byte blocks in a 4-bit field, the maximum extension  * is 14 such blocks. The value for the init command is the number of   * additional descriptor entries NOT the number of 32 byte blocks.  */
end_comment

begin_define
define|#
directive|define
name|TPD_EXTENSION_BLOCKS
value|14
end_define

begin_define
define|#
directive|define
name|TPD_EXTENSIONS
value|(TPD_EXTENSION_BLOCKS * 4)
end_define

begin_define
define|#
directive|define
name|TPD_SIZE
value|((size_t)((TPD_EXTENSION_BLOCKS+1) * 32))
end_define

begin_comment
comment|/*  * Received PDUs are handed from the card to the host by means of Receive  * PDU descriptors. Each segment describes on part of the PDU. The buffer  * handle is a 32 bit value that is supplied by the host and passed  * transparently back to the host by the card. It is used to locate the buffer.  * The length field is the number of actual bytes in that buffer.  */
end_comment

begin_define
define|#
directive|define
name|RXD_FIXED
value|3
end_define

begin_struct
struct|struct
name|rxseg
block|{
name|uint32_t
name|handle
decl_stmt|;
comment|/* buffer handle */
name|uint32_t
name|length
decl_stmt|;
comment|/* number of bytes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rpd
block|{
name|uint32_t
name|atm_header
decl_stmt|;
name|uint32_t
name|nseg
decl_stmt|;
name|struct
name|rxseg
name|segment
index|[
name|RXD_FIXED
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDUs received are stored in buffers supplied to the card. We use only  * buffer scheme 1: small buffers are normal mbuf's which can hold three  * cells in their default size (256 byte) and mbuf clusters which can  * hold 42 cells (2 kbyte).  * The number of receive segments can be computed from these sizes:  */
end_comment

begin_define
define|#
directive|define
name|FATM_MAXPDU
value|65535
end_define

begin_define
define|#
directive|define
name|MAXPDU_CELLS
value|((FATM_MAXPDU+47)/48)
end_define

begin_define
define|#
directive|define
name|SMALL_BUFFER_CELLS
value|(MHLEN/48)
end_define

begin_define
define|#
directive|define
name|LARGE_BUFFER_CELLS
value|(MCLBYTES/48)
end_define

begin_define
define|#
directive|define
name|SMALL_BUFFER_LEN
value|(SMALL_BUFFER_CELLS * 48)
end_define

begin_define
define|#
directive|define
name|LARGE_BUFFER_LEN
value|(LARGE_BUFFER_CELLS * 48)
end_define

begin_comment
comment|/*  * The card first alloctes a small buffer and the switches to large  * buffers. So the number of large buffers needed to store the maximum  * PDU is:  */
end_comment

begin_define
define|#
directive|define
name|MAX_LARGE_BUFFERS
value|((MAXPDU_CELLS - SMALL_BUFFER_CELLS	\ 				  + LARGE_BUFFER_CELLS - 1)		\ 				 / LARGE_BUFFER_CELLS)
end_define

begin_comment
unit|\
comment|/*  * From this we get the number of extension blocks for the Rpds as:  */
end_comment

begin_define
define|#
directive|define
name|RPD_EXTENSION_BLOCKS
value|((MAX_LARGE_BUFFERS + 1 - RXD_FIXED	\ 				  + SEGS_PER_BLOCK - 1)			\ 				 / SEGS_PER_BLOCK)
end_define

begin_define
define|#
directive|define
name|RPD_EXTENSIONS
value|(RPD_EXTENSION_BLOCKS * 4)
end_define

begin_define
define|#
directive|define
name|RPD_SIZE
value|((size_t)((RPD_EXTENSION_BLOCKS+1) * 32))
end_define

begin_comment
comment|/*  * Buffers are supplied to the card prior receiving by the supply queues.  * We use two queues: scheme 1 small buffers and scheme 1 large buffers.  * The queues and on-card pools are initialized by the initialize command.  * Buffers are supplied in chunks. Each chunk can contain from 4 to 124  * buffers in multiples of four. The chunk sizes are configured by the  * initialize command. Each buffer in a chunk is described by a Receive  * Buffer Descriptor that is held in host memory and given as the ioblk  * to the card.  */
end_comment

begin_define
define|#
directive|define
name|BSUP_BLK2SIZE
parameter_list|(
name|CHUNK
parameter_list|)
value|(8 * (CHUNK))
end_define

begin_struct
struct|struct
name|rbd
block|{
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|buffer
decl_stmt|;
comment|/* DMA address for card */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The PCA200E has an expansion ROM that contains version information and  * the FORE-assigned MAC address. It can be read via the get_prom_data  * operation.  */
end_comment

begin_struct
struct|struct
name|prom
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|serial
decl_stmt|;
name|uint8_t
name|mac
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The media type member of the firmware communication block contains a   * code that describes the physical medium and physical protocol.  */
end_comment

begin_define
define|#
directive|define
name|FORE_MT_TAXI_100
value|0x04
end_define

begin_define
define|#
directive|define
name|FORE_MT_TAXI_140
value|0x05
end_define

begin_define
define|#
directive|define
name|FORE_MT_UTP_SONET
value|0x06
end_define

begin_define
define|#
directive|define
name|FORE_MT_MM_OC3_ST
value|0x16
end_define

begin_define
define|#
directive|define
name|FORE_MT_MM_OC3_SC
value|0x26
end_define

begin_define
define|#
directive|define
name|FORE_MT_SM_OC3_ST
value|0x36
end_define

begin_define
define|#
directive|define
name|FORE_MT_SM_OC3_SC
value|0x46
end_define

begin_comment
comment|/*  * Assorted constants  */
end_comment

begin_define
define|#
directive|define
name|FORE_MAX_VCC
value|1024
end_define

begin_comment
comment|/* max. number of VCIs supported */
end_comment

begin_define
define|#
directive|define
name|FORE_VCIBITS
value|10
end_define

begin_define
define|#
directive|define
name|FATM_STATE_TIMEOUT
value|500
end_define

begin_comment
comment|/* msec */
end_comment

begin_comment
comment|/*  * Statistics as delivered by the FORE cards  */
end_comment

begin_struct
struct|struct
name|fatm_stats
block|{
struct|struct
block|{
name|uint32_t
name|crc_header_errors
decl_stmt|;
name|uint32_t
name|framing_errors
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|phy_4b5b
struct|;
struct|struct
block|{
name|uint32_t
name|section_bip8_errors
decl_stmt|;
name|uint32_t
name|path_bip8_errors
decl_stmt|;
name|uint32_t
name|line_bip24_errors
decl_stmt|;
name|uint32_t
name|line_febe_errors
decl_stmt|;
name|uint32_t
name|path_febe_errors
decl_stmt|;
name|uint32_t
name|corr_hcs_errors
decl_stmt|;
name|uint32_t
name|ucorr_hcs_errors
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
block|}
name|phy_oc3
struct|;
struct|struct
block|{
name|uint32_t
name|cells_transmitted
decl_stmt|;
name|uint32_t
name|cells_received
decl_stmt|;
name|uint32_t
name|vpi_bad_range
decl_stmt|;
name|uint32_t
name|vpi_no_conn
decl_stmt|;
name|uint32_t
name|vci_bad_range
decl_stmt|;
name|uint32_t
name|vci_no_conn
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|atm
struct|;
struct|struct
block|{
name|uint32_t
name|cells_transmitted
decl_stmt|;
name|uint32_t
name|cells_received
decl_stmt|;
name|uint32_t
name|cells_dropped
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|1
index|]
decl_stmt|;
block|}
name|aal0
struct|;
struct|struct
block|{
name|uint32_t
name|cells_transmitted
decl_stmt|;
name|uint32_t
name|cells_received
decl_stmt|;
name|uint32_t
name|cells_crc_errors
decl_stmt|;
name|uint32_t
name|cels_protocol_errors
decl_stmt|;
name|uint32_t
name|cells_dropped
decl_stmt|;
name|uint32_t
name|cspdus_transmitted
decl_stmt|;
name|uint32_t
name|cspdus_received
decl_stmt|;
name|uint32_t
name|cspdus_protocol_errors
decl_stmt|;
name|uint32_t
name|cspdus_dropped
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|aal4
struct|;
struct|struct
block|{
name|uint32_t
name|cells_transmitted
decl_stmt|;
name|uint32_t
name|cells_received
decl_stmt|;
name|uint32_t
name|congestion_experienced
decl_stmt|;
name|uint32_t
name|cells_dropped
decl_stmt|;
name|uint32_t
name|cspdus_transmitted
decl_stmt|;
name|uint32_t
name|cspdus_received
decl_stmt|;
name|uint32_t
name|cspdus_crc_errors
decl_stmt|;
name|uint32_t
name|cspdus_protocol_errors
decl_stmt|;
name|uint32_t
name|cspdus_dropped
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|aal5
struct|;
struct|struct
block|{
name|uint32_t
name|small_b1_failed
decl_stmt|;
name|uint32_t
name|large_b1_failed
decl_stmt|;
name|uint32_t
name|small_b2_failed
decl_stmt|;
name|uint32_t
name|large_b2_failed
decl_stmt|;
name|uint32_t
name|rpd_alloc_failed
decl_stmt|;
name|uint32_t
name|receive_carrier
decl_stmt|;
name|uint32_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|aux
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FATM_NSTATS
value|42
end_define

end_unit

