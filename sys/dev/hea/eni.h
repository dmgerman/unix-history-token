begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  *  * Protocol and implementation definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENI_ENI_H
end_ifndef

begin_define
define|#
directive|define
name|_ENI_ENI_H
end_define

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_comment
comment|/*  * Physical device name - used to configure HARP devices  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENI_DEV_NAME
end_ifndef

begin_define
define|#
directive|define
name|ENI_DEV_NAME
value|"hea"
end_define

begin_comment
comment|/* HARP Efficient ATM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENI_MAX_UNITS
value|4
end_define

begin_define
define|#
directive|define
name|ENI_IFF_MTU
value|9188
end_define

begin_define
define|#
directive|define
name|ENI_MAX_VCI
value|1023
end_define

begin_comment
comment|/* 0 - 1023 */
end_comment

begin_define
define|#
directive|define
name|ENI_MAX_VPI
value|0
end_define

begin_define
define|#
directive|define
name|ENI_IFQ_MAXLEN
value|1000
end_define

begin_comment
comment|/* rx/tx queue lengths */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_comment
comment|/*  * Size of small and large receive buffers  */
end_comment

begin_define
define|#
directive|define
name|ENI_SMALL_BSIZE
value|64
end_define

begin_define
define|#
directive|define
name|ENI_LARGE_BSIZE
value|MCLBYTES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_comment
comment|/*  * ENI memory map offsets IN WORDS, not bytes  *  * The Efficient Adapter implements a 4 MB address space. The lower  * 2 MB are used by bootprom (E)EPROM and by chipset registers such  * as the MIDWAY and SUNI chips. The (upto) upper 2 MB is used for  * RAM. Of the RAM, the lower 28 KB is used for fixed tables - the  * VCI table, the RX and TX DMA queues, and the Service List queue.  * Memory above the 28 KB range is available for RX and TX buffers.  *  * NOTE: Access to anything other then the (E)EPROM MUST be as a 32 bit  * access. Also note that Efficient uses both byte addresses and word  * addresses when describing offsets. BE CAREFUL or you'll get confused!  */
end_comment

begin_comment
comment|/*  * Size of memory space reserved for registers and expansion (e)eprom.  */
end_comment

begin_define
define|#
directive|define
name|ENI_REG_SIZE
value|0x200000
end_define

begin_comment
comment|/* Two megabytes */
end_comment

begin_define
define|#
directive|define
name|SUNI_OFFSET
value|0x008000
end_define

begin_comment
comment|/* SUNI chip registers */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_OFFSET
value|0x010000
end_define

begin_comment
comment|/* MIDWAY chip registers */
end_comment

begin_define
define|#
directive|define
name|RAM_OFFSET
value|0x080000
end_define

begin_comment
comment|/* Adapter RAM */
end_comment

begin_define
define|#
directive|define
name|VCITBL_OFFSET
value|0x080000
end_define

begin_comment
comment|/* VCI Table offset */
end_comment

begin_define
define|#
directive|define
name|RXQUEUE_OFFSET
value|0x081000
end_define

begin_comment
comment|/* RX DMA Queue offset */
end_comment

begin_define
define|#
directive|define
name|TXQUEUE_OFFSET
value|0x081400
end_define

begin_comment
comment|/* TX DMA Queue offset */
end_comment

begin_define
define|#
directive|define
name|SVCLIST_OFFSET
value|0x081800
end_define

begin_comment
comment|/* SVC List Queue offset */
end_comment

begin_define
define|#
directive|define
name|SEGBUF_BASE
value|0x007000
end_define

begin_comment
comment|/* Base from start of RAM */
end_comment

begin_define
define|#
directive|define
name|DMA_LIST_SIZE
value|512
end_define

begin_comment
comment|/* 1024 words / 2 words per entry */
end_comment

begin_define
define|#
directive|define
name|SVC_LIST_SIZE
value|1024
end_define

begin_comment
comment|/* 1024 words / 1 word  per entry */
end_comment

begin_comment
comment|/*  * Values for testing size of RAM on adapter  *  * Efficient has (at least) two different memory sizes available. One  * is a client card which has either 128 KB or 512 KB RAM, the other  * is a server card which has 2 MB RAM. The driver will size and test  * the memory to correctly determine what's available.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ENI_MEM
value|0x200000
end_define

begin_comment
comment|/* 2 MB - max. mem supported */
end_comment

begin_define
define|#
directive|define
name|TEST_STEP
value|0x000400
end_define

begin_comment
comment|/* Look at 1 KB steps */
end_comment

begin_define
define|#
directive|define
name|TEST_PAT
value|0xA5A5A5A5
end_define

begin_comment
comment|/* Test pattern */
end_comment

begin_comment
comment|/*  * Values for memory allocator  */
end_comment

begin_define
define|#
directive|define
name|ENI_BUF_PGSZ
value|1024
end_define

begin_comment
comment|/* Allocation unit of buffers */
end_comment

begin_define
define|#
directive|define
name|ENI_BUF_NBIT
value|8
end_define

begin_comment
comment|/* Number of bits to get from */
end_comment

begin_comment
comment|/* min buffer (1KB) to max (128KB) */
end_comment

begin_comment
comment|/*  * Values for allocating TX buffers  */
end_comment

begin_define
define|#
directive|define
name|MAX_CLIENT_RAM
value|512
end_define

begin_comment
comment|/* Most RAM a client card will have */
end_comment

begin_define
define|#
directive|define
name|TX_SMALL_BSIZE
value|32
end_define

begin_comment
comment|/* Small buffer - 32KB */
end_comment

begin_define
define|#
directive|define
name|TX_LARGE_BSIZE
value|128
end_define

begin_comment
comment|/* Large buffer - 128KB */
end_comment

begin_comment
comment|/*  * Values for allocating RX buffers  */
end_comment

begin_define
define|#
directive|define
name|RX_SIG_BSIZE
value|4
end_define

begin_comment
comment|/* Signalling buffer - 4KB */
end_comment

begin_define
define|#
directive|define
name|RX_CLIENT_BSIZE
value|16
end_define

begin_comment
comment|/* Client buffer - 16KB */
end_comment

begin_define
define|#
directive|define
name|RX_SERVER_BSIZE
value|32
end_define

begin_comment
comment|/* Server buffer - 32KB */
end_comment

begin_comment
comment|/*  * Adapter bases all addresses off of some power from 1KB. Thus, it  * only needs to store the most sigificant bits and can drop the lower  * 10 bits.  */
end_comment

begin_define
define|#
directive|define
name|ENI_LOC_PREDIV
value|10
end_define

begin_comment
comment|/* Bits location is shifted */
end_comment

begin_comment
comment|/* Location is prescaled by 1KB */
end_comment

begin_comment
comment|/* before use in various places */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_DELAY
value|10
end_define

begin_comment
comment|/* Time to wait for Midway finish */
end_comment

begin_comment
comment|/*  * Define the MIDWAY register offsets and any interesting bits within  * the register  */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_ID
value|0x00
end_define

begin_comment
comment|/* ID/Reset register */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_RESET
value|0
end_define

begin_comment
comment|/* iWrite of any value */
end_comment

begin_define
define|#
directive|define
name|ID_SHIFT
value|27
end_define

begin_comment
comment|/* Midway ID version */
end_comment

begin_define
define|#
directive|define
name|ID_MASK
value|0x1F
end_define

begin_comment
comment|/* ID mask */
end_comment

begin_define
define|#
directive|define
name|MID_SHIFT
value|7
end_define

begin_comment
comment|/* Mother board ID */
end_comment

begin_define
define|#
directive|define
name|MID_MASK
value|0x7
end_define

begin_comment
comment|/* MID mask */
end_comment

begin_define
define|#
directive|define
name|DID_SHIFT
value|0
end_define

begin_comment
comment|/* Daughter board ID */
end_comment

begin_define
define|#
directive|define
name|DID_MASK
value|0x1F
end_define

begin_comment
comment|/* DID mask */
end_comment

begin_comment
comment|/* 	 * Efficient defines the following IDs for their adapters: 	 * 0x420/0x620 - SONET MMF, client memory size 	 * 0x430/0x630 - SONET MMF, server memory size 	 * 0x424/0x624 - UTP-5, client memory size 	 * 0x434/0x634 - UTP-5, server memory size 	 */
end_comment

begin_define
define|#
directive|define
name|MEDIA_MASK
value|0x04
end_define

begin_comment
comment|/* Mask off UTP-5/MMF media */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_ISA
value|0x01
end_define

begin_comment
comment|/* Interrupt Status Ack. */
end_comment

begin_comment
comment|/* Reading this register */
end_comment

begin_comment
comment|/* also acknowledges the */
end_comment

begin_comment
comment|/* posted interrupt(s) */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_IS
value|0x02
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_comment
comment|/* Reading this register */
end_comment

begin_comment
comment|/* does NOT acknowledge the */
end_comment

begin_comment
comment|/* posted interrupt(s) */
end_comment

begin_comment
comment|/* Interrupt names */
end_comment

begin_define
define|#
directive|define
name|ENI_INT_STAT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ENI_INT_SUNI
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ENI_INT_SERVICE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ENI_INT_TX_DMA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ENI_INT_RX_DMA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ENI_INT_DMA_ERR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ENI_INT_DMA_LERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ENI_INT_IDEN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ENI_INT_DMA_OVFL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ENI_INT_TX_MASK
value|0x0001FE00
end_define

begin_define
define|#
directive|define
name|MIDWAY_IE
value|0x03
end_define

begin_comment
comment|/* Interrupt Enable register */
end_comment

begin_comment
comment|/* Interrupt enable bits are the same as the Interrupt names */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_MASTER
value|0x04
end_define

begin_comment
comment|/* Master Control */
end_comment

begin_comment
comment|/* Master control bits */
end_comment

begin_define
define|#
directive|define
name|ENI_M_WAIT500
value|0x00000001
end_define

begin_comment
comment|/* Disable interrupts .5 ms */
end_comment

begin_define
define|#
directive|define
name|ENI_M_WAIT1
value|0x00000002
end_define

begin_comment
comment|/* Disable interrupts 1 ms */
end_comment

begin_define
define|#
directive|define
name|ENI_M_RXENABLE
value|0x00000004
end_define

begin_comment
comment|/* Enable RX engine */
end_comment

begin_define
define|#
directive|define
name|ENI_M_TXENABLE
value|0x00000008
end_define

begin_comment
comment|/* Enable TX engine */
end_comment

begin_define
define|#
directive|define
name|ENI_M_DMAENABLE
value|0x00000010
end_define

begin_comment
comment|/* Enable DMA */
end_comment

begin_define
define|#
directive|define
name|ENI_M_TXLOCK
value|0x00000020
end_define

begin_comment
comment|/* 0: Streaming, 1: Lock */
end_comment

begin_define
define|#
directive|define
name|ENI_M_INTSEL
value|0x000001C0
end_define

begin_comment
comment|/* Int Select mask */
end_comment

begin_define
define|#
directive|define
name|ENI_ISEL_SHIFT
value|6
end_define

begin_comment
comment|/* Bits to shift ISEL value */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_STAT
value|0x05
end_define

begin_comment
comment|/* Statistics register */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_SVCWR
value|0x06
end_define

begin_comment
comment|/* Svc List write pointer */
end_comment

begin_define
define|#
directive|define
name|SVC_SIZE_MASK
value|0x3FF
end_define

begin_comment
comment|/* Valid bits in svc pointer */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_DMAADDR
value|0x07
end_define

begin_comment
comment|/* Current virtual DMA addr */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_RX_WR
value|0x08
end_define

begin_comment
comment|/* Write ptr to RX DMA queue */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_RX_RD
value|0x09
end_define

begin_comment
comment|/* Read ptr to RX DMA queue */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_TX_WR
value|0x0A
end_define

begin_comment
comment|/* Write ptr to TX DMA queue */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_TX_RD
value|0x0B
end_define

begin_comment
comment|/* Read ptr to TX DMA queue */
end_comment

begin_comment
comment|/*  * Registers 0x0C - 0x0F are unused  */
end_comment

begin_comment
comment|/*  * MIDWAY supports 8 transmit channels. Each channel has 3 registers  * to control operation. Each new channel starts on N * 4 set. Thus,  * channel 0 uses register 0x10 - 0x13, channel 1 uses 0x14 - 0x17, etc.  * Register 0x13 + N * 4 is unused.  */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_TXPLACE
value|0x10
end_define

begin_comment
comment|/* Channel N TX location */
end_comment

begin_define
define|#
directive|define
name|TXSIZE_SHIFT
value|11
end_define

begin_comment
comment|/* Bits to shift size by */
end_comment

begin_define
define|#
directive|define
name|TX_PLACE_MASK
value|0x7FF
end_define

begin_comment
comment|/* Valid bits in TXPLACE */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_RDPTR
value|0x11
end_define

begin_comment
comment|/* Channel N Read ptr */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_DESCR
value|0x12
end_define

begin_comment
comment|/* Channel N Descr ptr */
end_comment

begin_comment
comment|/*  * Register 0x30 on up are unused  */
end_comment

begin_comment
comment|/*  * Part of PCI configuration registers but not defined in<pci/pcireg.h>  */
end_comment

begin_define
define|#
directive|define
name|PCI_CONTROL_REG
value|0x60
end_define

begin_define
define|#
directive|define
name|ENDIAN_SWAP_DMA
value|0x80
end_define

begin_comment
comment|/* Enable endian swaps on DMA */
end_comment

begin_comment
comment|/*  * The Efficient adapter references adapter RAM through the use of  * location and size values. Eight sizes are defined. When allocating  * buffers, there size must be rounded up to the next size which will  * hold the requested size. Buffers are allocated on 'SIZE' boundaries.  * See eni_buffer.c for more info.  */
end_comment

begin_comment
comment|/*  * Buffer SIZE definitions - in words, so from 1 KB to 128 KB  */
end_comment

begin_define
define|#
directive|define
name|SIZE_256
value|0x00
end_define

begin_define
define|#
directive|define
name|SIZE_512
value|0x01
end_define

begin_define
define|#
directive|define
name|SIZE_1K
value|0x02
end_define

begin_define
define|#
directive|define
name|SIZE_2K
value|0x03
end_define

begin_define
define|#
directive|define
name|SIZE_4K
value|0x04
end_define

begin_define
define|#
directive|define
name|SIZE_8K
value|0x05
end_define

begin_define
define|#
directive|define
name|SIZE_16K
value|0x06
end_define

begin_define
define|#
directive|define
name|SIZE_32K
value|0x07
end_define

begin_comment
comment|/*  * Define values for DMA type - DMA descriptors include a type field and a  * count field except in the special case of JK (just-kidding). With type JK,  * the count field should be set to the address which will be loaded  * into the pointer, ie. where the pointer should next point to, since  * JK doesn't have a "size" associated with it. JK DMA is used to skip  * over descriptor words, and to strip off padding of AAL5 PDUs. The   * DMA_nWORDM types will do a n word DMA burst, but the count field  * does not have to equal n. Any difference results in garbage filling  * the remaining words of the DMA. These types could be used where a  * particular burst size yields better DMA performance.  */
end_comment

begin_define
define|#
directive|define
name|DMA_WORD
value|0x00
end_define

begin_define
define|#
directive|define
name|DMA_BYTE
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_HWORD
value|0x02
end_define

begin_define
define|#
directive|define
name|DMA_JK
value|0x03
end_define

begin_define
define|#
directive|define
name|DMA_4WORD
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_8WORD
value|0x05
end_define

begin_define
define|#
directive|define
name|DMA_16WORD
value|0x06
end_define

begin_define
define|#
directive|define
name|DMA_2WORD
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_4WORDM
value|0x0C
end_define

begin_define
define|#
directive|define
name|DMA_8WORDM
value|0x0D
end_define

begin_define
define|#
directive|define
name|DMA_16WORDM
value|0x0E
end_define

begin_define
define|#
directive|define
name|DMA_2WORDM
value|0x0F
end_define

begin_comment
comment|/*  * Define the size of the local DMA list we'll build before  * giving up on the PDU.  */
end_comment

begin_define
define|#
directive|define
name|TEMP_DMA_SIZE
value|120
end_define

begin_comment
comment|/* Enough for 58/59 buffers */
end_comment

begin_define
define|#
directive|define
name|DMA_COUNT_SHIFT
value|16
end_define

begin_comment
comment|/* Number of bits to shift count */
end_comment

begin_comment
comment|/* in DMA descriptor word */
end_comment

begin_define
define|#
directive|define
name|DMA_VCC_SHIFT
value|6
end_define

begin_comment
comment|/* Number of bits to shift RX VCC or */
end_comment

begin_comment
comment|/* TX channel in DMA descriptor word */
end_comment

begin_define
define|#
directive|define
name|DMA_END_BIT
value|0x20
end_define

begin_comment
comment|/* Signal end of DMA list */
end_comment

begin_comment
comment|/*  * Defines for VCI table  *  * The VCI table is a 1K by 4 word table allowing up to 1024 (0-1023)  * VCIs. Entries into the table use the VCI number as the index.  */
end_comment

begin_struct
struct|struct
name|vci_table
block|{
name|u_long
name|vci_control
decl_stmt|;
comment|/* Control word */
name|u_long
name|vci_descr
decl_stmt|;
comment|/* Descr/ReadPtr */
name|u_long
name|vci_write
decl_stmt|;
comment|/* WritePtr/State/Cell count */
name|u_long
name|vci_crc
decl_stmt|;
comment|/* ongoing CRC calculation */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|vci_table
name|VCI_Table
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VCI_MODE_SHIFT
value|30
end_define

begin_comment
comment|/* Shift to get MODE field */
end_comment

begin_define
define|#
directive|define
name|VCI_MODE_MASK
value|0x3FFFFFFF
end_define

begin_comment
comment|/* Bits to strip MODE off */
end_comment

begin_define
define|#
directive|define
name|VCI_PTI_SHIFT
value|29
end_define

begin_comment
comment|/* Shift to get PTI mode field */
end_comment

begin_define
define|#
directive|define
name|VCI_LOC_SHIFT
value|18
end_define

begin_comment
comment|/* Shift to get location field */
end_comment

begin_define
define|#
directive|define
name|VCI_LOC_MASK
value|0x7FF
end_define

begin_comment
comment|/* Valid bits in location field */
end_comment

begin_define
define|#
directive|define
name|VCI_SIZE_SHIFT
value|15
end_define

begin_comment
comment|/* Shift to get size field */
end_comment

begin_define
define|#
directive|define
name|VCI_SIZE_MASK
value|7
end_define

begin_comment
comment|/* Valid bits in size field */
end_comment

begin_define
define|#
directive|define
name|VCI_IN_SERVICE
value|1
end_define

begin_comment
comment|/* Mask for IN_SERVICE field */
end_comment

begin_comment
comment|/*  * Defines for VC mode  */
end_comment

begin_define
define|#
directive|define
name|VCI_MODE_TRASH
value|0x00
end_define

begin_comment
comment|/* Trash all cells for this VC */
end_comment

begin_define
define|#
directive|define
name|VCI_MODE_AAL0
value|0x01
end_define

begin_comment
comment|/* Reassemble as AAL_0 PDU */
end_comment

begin_define
define|#
directive|define
name|VCI_MODE_AAL5
value|0x02
end_define

begin_comment
comment|/* Reassemble as AAL_5 PDU */
end_comment

begin_comment
comment|/*  * Defines for handling cells with PTI(2) set to 1.  */
end_comment

begin_define
define|#
directive|define
name|PTI_MODE_TRASH
value|0x00
end_define

begin_comment
comment|/* Trash cell */
end_comment

begin_define
define|#
directive|define
name|PTI_MODE_PRESV
value|0x01
end_define

begin_comment
comment|/* Send cell to OAM channel */
end_comment

begin_comment
comment|/*  * Current state of VC  */
end_comment

begin_define
define|#
directive|define
name|VCI_STATE_IDLE
value|0x00
end_define

begin_comment
comment|/* VC is idle */
end_comment

begin_define
define|#
directive|define
name|VCI_STATE_REASM
value|0x01
end_define

begin_comment
comment|/* VC is reassembling PDU */
end_comment

begin_define
define|#
directive|define
name|VCI_STATE_TRASH
value|0x03
end_define

begin_comment
comment|/* VC is trashing cells */
end_comment

begin_comment
comment|/*  * RX Descriptor word values  */
end_comment

begin_define
define|#
directive|define
name|DESCR_TRASH_BIT
value|0x1000
end_define

begin_comment
comment|/* VCI was trashing cells */
end_comment

begin_define
define|#
directive|define
name|DESCR_CRC_ERR
value|0x0800
end_define

begin_comment
comment|/* PDU has CRC error */
end_comment

begin_define
define|#
directive|define
name|DESCR_CELL_COUNT
value|0x07FF
end_define

begin_comment
comment|/* Mask to get cell count */
end_comment

begin_comment
comment|/*  * TX Descriptor word values  */
end_comment

begin_define
define|#
directive|define
name|TX_IDEN_SHIFT
value|28
end_define

begin_comment
comment|/* Unique identifier location */
end_comment

begin_define
define|#
directive|define
name|TX_MODE_SHIFT
value|27
end_define

begin_comment
comment|/* AAL5 or AAL0 */
end_comment

begin_define
define|#
directive|define
name|TX_VCI_SHIFT
value|4
end_define

begin_comment
comment|/* Bits to shift VCI value */
end_comment

begin_comment
comment|/*  * When setting up descriptor words (at head of segmentation queues), there  * is a unique identifier used to help detect sync problems.  */
end_comment

begin_define
define|#
directive|define
name|MIDWAY_UNQ_ID
value|0x0B
end_define

begin_comment
comment|/*  * Defines for cell sizes  */
end_comment

begin_define
define|#
directive|define
name|BYTES_PER_CELL
value|48
end_define

begin_comment
comment|/* Number of data bytes per cell */
end_comment

begin_define
define|#
directive|define
name|WORDS_PER_CELL
value|12
end_define

begin_comment
comment|/* Number of data words per cell */
end_comment

begin_comment
comment|/*  * Access to Serial EEPROM [as opposed to expansion (E)PROM].  *  * This is a ATMEL AT24C01 serial EEPROM part.  * See http://www.atmel.com/atmel/products/prod162.htm for timimg diagrams  * for START/STOP/ACK/READ cycles.  */
end_comment

begin_define
define|#
directive|define
name|SEEPROM
value|PCI_CONTROL_REG
end_define

begin_comment
comment|/* Serial EEPROM is accessed thru */
end_comment

begin_comment
comment|/* PCI control register 	  */
end_comment

begin_define
define|#
directive|define
name|SEPROM_DATA
value|0x02
end_define

begin_comment
comment|/* SEEPROM DATA line */
end_comment

begin_define
define|#
directive|define
name|SEPROM_CLK
value|0x01
end_define

begin_comment
comment|/* SEEPROM CLK line */
end_comment

begin_define
define|#
directive|define
name|SEPROM_SIZE
value|128
end_define

begin_comment
comment|/* Size of Serial EEPROM */
end_comment

begin_define
define|#
directive|define
name|SEPROM_MAC_OFF
value|64
end_define

begin_comment
comment|/* Offset to MAC address */
end_comment

begin_define
define|#
directive|define
name|SEPROM_SN_OFF
value|112
end_define

begin_comment
comment|/* Offset to serial number */
end_comment

begin_define
define|#
directive|define
name|SEPROM_DELAY
value|10
end_define

begin_comment
comment|/* Delay when strobing CLK/DATA lines */
end_comment

begin_comment
comment|/*  * Host protocol control blocks  *  */
end_comment

begin_comment
comment|/*  * Device VCC Entry  *  * Contains the common and ENI-specific information for each VCC  * which is opened through a ENI device.  */
end_comment

begin_struct
struct|struct
name|eni_vcc
block|{
name|struct
name|cmn_vcc
name|ev_cmn
decl_stmt|;
comment|/* Common VCC stuff */
name|caddr_t
name|ev_rxbuf
decl_stmt|;
comment|/* Receive buffer */
name|u_long
name|ev_rxpos
decl_stmt|;
comment|/* Adapter buffer read pointer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_vcc
name|Eni_vcc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ev_next
value|ev_cmn.cv_next
end_define

begin_define
define|#
directive|define
name|ev_toku
value|ev_cmn.cv_toku
end_define

begin_define
define|#
directive|define
name|ev_upper
value|ev_cmn.cv_upper
end_define

begin_define
define|#
directive|define
name|ev_connvc
value|ev_cmn.cv_connvc
end_define

begin_define
define|#
directive|define
name|ev_state
value|ev_cmn.cv_state
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|long
modifier|*
name|Eni_mem
typedef|;
end_typedef

begin_comment
comment|/*  * Define the ID's we'll look for in the PCI config  * register when deciding if we'll support this device.  * The DEV_ID will need to be turned into an array of  * ID's in order to support multiple adapters with  * the same driver.  */
end_comment

begin_define
define|#
directive|define
name|EFF_VENDOR_ID
value|0x111A
end_define

begin_define
define|#
directive|define
name|EFF_DEV_ID
value|0x0002
end_define

begin_comment
comment|/*  * Memory allocator defines and buffer descriptors  */
end_comment

begin_define
define|#
directive|define
name|MEM_FREE
value|0
end_define

begin_define
define|#
directive|define
name|MEM_INUSE
value|1
end_define

begin_typedef
typedef|typedef
name|struct
name|mbd
name|Mbd
typedef|;
end_typedef

begin_struct
struct|struct
name|mbd
block|{
name|Mbd
modifier|*
name|prev
decl_stmt|;
name|Mbd
modifier|*
name|next
decl_stmt|;
name|caddr_t
name|base
decl_stmt|;
comment|/* Adapter base address */
name|int
name|size
decl_stmt|;
comment|/* Size of buffer */
name|int
name|state
decl_stmt|;
comment|/* INUSE or FREE */
block|}
struct|;
end_struct

begin_comment
comment|/*  * We use a hack to allocate a smaller RX buffer for signalling  * channels as they tend to have small MTU lengths.  */
end_comment

begin_define
define|#
directive|define
name|UNI_SIG_VCI
value|5
end_define

begin_comment
comment|/*  * Device Unit Structure  *  * Contains all the information for a single device (adapter).  */
end_comment

begin_struct
struct|struct
name|eni_unit
block|{
name|Cmn_unit
name|eu_cmn
decl_stmt|;
comment|/* Common unit stuff */
name|pcici_t
name|eu_pcitag
decl_stmt|;
comment|/* PCI tag */
name|Eni_mem
name|eu_base
decl_stmt|;
comment|/* Adapter memory base */
name|Eni_mem
name|eu_ram
decl_stmt|;
comment|/* Adapter RAM */
name|u_long
name|eu_ramsize
decl_stmt|;
name|Eni_mem
name|eu_suni
decl_stmt|;
comment|/* SUNI registers */
name|Eni_mem
name|eu_midway
decl_stmt|;
comment|/* MIDWAY registers */
name|VCI_Table
modifier|*
name|eu_vcitbl
decl_stmt|;
comment|/* VCI Table */
name|Eni_mem
name|eu_rxdma
decl_stmt|;
comment|/* Receive DMA queue */
name|Eni_mem
name|eu_txdma
decl_stmt|;
comment|/* Transmit DMA queue */
name|Eni_mem
name|eu_svclist
decl_stmt|;
comment|/* Service list */
name|u_long
name|eu_servread
decl_stmt|;
comment|/* Read pointer into Service list */
name|caddr_t
name|eu_txbuf
decl_stmt|;
comment|/* One large TX buff for everything */
name|u_long
name|eu_txsize
decl_stmt|;
comment|/* Size of TX buffer */
name|u_long
name|eu_txpos
decl_stmt|;
comment|/* Current word being stored in RAM */
name|u_long
name|eu_txfirst
decl_stmt|;
comment|/* First word of unack'ed data */
name|u_long
name|eu_trash
decl_stmt|;
name|u_long
name|eu_ovfl
decl_stmt|;
name|struct
name|ifqueue
name|eu_txqueue
decl_stmt|;
name|u_long
name|eu_txdmawr
decl_stmt|;
name|struct
name|ifqueue
name|eu_rxqueue
decl_stmt|;
name|u_long
name|eu_rxdmawr
decl_stmt|;
comment|/* DMA list write pointer */
name|u_char
name|eu_seeprom
index|[
name|SEPROM_SIZE
index|]
decl_stmt|;
comment|/* Serial EEPROM contents */
name|u_int
name|eu_sevar
decl_stmt|;
comment|/* Unique (per unit) seeprom var. */
name|Mbd
modifier|*
name|eu_memmap
decl_stmt|;
comment|/* Adapter RAM memory allocator map */
name|int
name|eu_memclicks
index|[
name|ENI_BUF_NBIT
index|]
decl_stmt|;
comment|/* Count of INUSE buffers */
name|Eni_stats
name|eu_stats
decl_stmt|;
comment|/* Statistics */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eni_unit
name|Eni_unit
typedef|;
end_typedef

begin_define
define|#
directive|define
name|eu_pif
value|eu_cmn.cu_pif
end_define

begin_define
define|#
directive|define
name|eu_unit
value|eu_cmn.cu_unit
end_define

begin_define
define|#
directive|define
name|eu_flags
value|eu_cmn.cu_flags
end_define

begin_define
define|#
directive|define
name|eu_mtu
value|eu_cmn.cu_mtu
end_define

begin_define
define|#
directive|define
name|eu_open_vcc
value|eu_cmn.cu_open_vcc
end_define

begin_define
define|#
directive|define
name|eu_vcc
value|eu_cmn.cu_vcc
end_define

begin_define
define|#
directive|define
name|eu_vcc_pool
value|eu_cmn.cu_vcc_pool
end_define

begin_define
define|#
directive|define
name|eu_nif_pool
value|eu_cmn.cu_nif_pool
end_define

begin_define
define|#
directive|define
name|eu_ioctl
value|eu_cmn.cu_ioctl
end_define

begin_define
define|#
directive|define
name|eu_instvcc
value|eu_cmn.cu_instvcc
end_define

begin_define
define|#
directive|define
name|eu_openvcc
value|eu_cmn.cu_openvcc
end_define

begin_define
define|#
directive|define
name|eu_closevcc
value|eu_cmn.cu_closevcc
end_define

begin_define
define|#
directive|define
name|eu_output
value|eu_cmn.cu_output
end_define

begin_define
define|#
directive|define
name|eu_config
value|eu_cmn.cu_config
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ENI_ENI_H */
end_comment

end_unit

