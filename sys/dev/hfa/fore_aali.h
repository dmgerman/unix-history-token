begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * ATM Adaptation Layer Interface (AALI) definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FORE_AALI_H
end_ifndef

begin_define
define|#
directive|define
name|_FORE_AALI_H
end_define

begin_comment
comment|/*  * This file contains the definitions required by the FORE ATM Adaptation  * Layer Interface (AALI) specification.  */
end_comment

begin_comment
comment|/*  * Addressing/Pointer definitions  *  * The CP memory only supports 32-bit word accesses (read and write) - thus,  * all memory must be defined and accessed as 32-bit words.  Also, since the  * data transfers are word-sized, we must take care of byte-swapping issues  * from/to little-endian hosts (the CP is an i960 processor, ie big-endian).  *  * All pointers to CP memory areas are actually offsets from the start of   * the adapter RAM address space.  *  * All CP-resident data structures are declared volatile.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|H_addr
typedef|;
end_typedef

begin_comment
comment|/* Host-resident address */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|H_dma
typedef|;
end_typedef

begin_comment
comment|/* Host-resident DMA address */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|CP_word
typedef|;
end_typedef

begin_comment
comment|/* CP-resident word */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|CP_addr
typedef|;
end_typedef

begin_comment
comment|/* CP-resident CP memory offset */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|CP_dma
typedef|;
end_typedef

begin_comment
comment|/* CP-resident DMA address */
end_comment

begin_comment
comment|/*  * Structure defining the CP's shared memory interface to the mon960 program  */
end_comment

begin_struct
struct|struct
name|mon960
block|{
name|CP_word
name|mon_xmitmon
decl_stmt|;
comment|/* Uart - host to mon960 (see below) */
name|CP_word
name|mon_xmithost
decl_stmt|;
comment|/* Uart - mon960 to host (see below) */
name|CP_word
name|mon_bstat
decl_stmt|;
comment|/* Boot status word (see below) */
name|CP_addr
name|mon_appl
decl_stmt|;
comment|/* Pointer to application memory area */
name|CP_word
name|mon_ver
decl_stmt|;
comment|/* Mon960 firmware version */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|mon960
name|Mon960
typedef|;
end_typedef

begin_comment
comment|/*  * Pseudo-UART usage  */
end_comment

begin_define
define|#
directive|define
name|UART_READY
value|0x00000000
end_define

begin_comment
comment|/* UART is ready for more data */
end_comment

begin_define
define|#
directive|define
name|UART_VALID
value|0x01000000
end_define

begin_comment
comment|/* UART character is valid */
end_comment

begin_define
define|#
directive|define
name|UART_DATAMASK
value|0x000000ff
end_define

begin_comment
comment|/* UART character data mask */
end_comment

begin_comment
comment|/*  * Boot Status Word  */
end_comment

begin_define
define|#
directive|define
name|BOOT_COLDSTART
value|0xc01dc01d
end_define

begin_comment
comment|/* CP is performing cold start */
end_comment

begin_define
define|#
directive|define
name|BOOT_MONREADY
value|0x02201958
end_define

begin_comment
comment|/* Monitor is waiting for commands */
end_comment

begin_define
define|#
directive|define
name|BOOT_FAILTEST
value|0xadbadbad
end_define

begin_comment
comment|/* Monitor failed self-test */
end_comment

begin_define
define|#
directive|define
name|BOOT_RUNNING
value|0xce11feed
end_define

begin_comment
comment|/* Microcode downloaded and running */
end_comment

begin_define
define|#
directive|define
name|BOOT_LOOPS
value|20
end_define

begin_comment
comment|/* Loops to wait for CP to boot */
end_comment

begin_define
define|#
directive|define
name|BOOT_DELAY
value|100000
end_define

begin_comment
comment|/* Delay (us) for each boot loop */
end_comment

begin_comment
comment|/*  * Supported AALs  */
end_comment

begin_enum
enum|enum
name|fore_aal
block|{
name|FORE_AAL_0
init|=
literal|0
block|,
comment|/* Cell Service */
name|FORE_AAL_4
init|=
literal|4
block|,
comment|/* AAL 3/4 */
name|FORE_AAL_5
init|=
literal|5
comment|/* AAL 5 */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|fore_aal
name|Fore_aal
typedef|;
end_typedef

begin_comment
comment|/*  * Buffer strategy definition  */
end_comment

begin_struct
struct|struct
name|buf_strategy
block|{
name|CP_word
name|bfs_quelen
decl_stmt|;
comment|/* Buffer supply queue entries */
name|CP_word
name|bfs_bufsize
decl_stmt|;
comment|/* Buffer size */
name|CP_word
name|bfs_cppool
decl_stmt|;
comment|/* Buffers in CP-resident pool */
name|CP_word
name|bfs_entsize
decl_stmt|;
comment|/* Buffers in each supply queue entry */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|buf_strategy
name|Buf_strategy
typedef|;
end_typedef

begin_comment
comment|/*  * Buffer strategy id  */
end_comment

begin_define
define|#
directive|define
name|BUF_STRAT_1
value|0
end_define

begin_comment
comment|/* Buffer strategy one */
end_comment

begin_define
define|#
directive|define
name|BUF_STRAT_2
value|1
end_define

begin_comment
comment|/* Buffer strategy two */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Common Queue Element  *  * Used for Transmit, Receive and Buffer Supply Queues  */
end_comment

begin_struct
struct|struct
name|com_queue
block|{
name|CP_dma
name|cq_descr
decl_stmt|;
comment|/* Pointer to element descriptor */
name|CP_dma
name|cq_status
decl_stmt|;
comment|/* Pointer to element status word */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|com_queue
name|Com_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Queue element status word  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|long
name|Q_status
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QSTAT_PENDING
value|0x01
end_define

begin_comment
comment|/* Operation is pending */
end_comment

begin_define
define|#
directive|define
name|QSTAT_COMPLETED
value|0x02
end_define

begin_comment
comment|/* Operation successfully completed */
end_comment

begin_define
define|#
directive|define
name|QSTAT_FREE
value|0x04
end_define

begin_comment
comment|/* Queue element is free/unused */
end_comment

begin_define
define|#
directive|define
name|QSTAT_ERROR
value|0x08
end_define

begin_comment
comment|/* Operation encountered an error */
end_comment

begin_define
define|#
directive|define
name|QSTAT_ALIGN
value|4
end_define

begin_comment
comment|/*  * PDU Transmit Queue  */
end_comment

begin_comment
comment|/*  * PDU Transmit Queue Element  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|com_queue
name|Xmit_queue
typedef|;
end_typedef

begin_comment
comment|/*  * PDU Transmit buffer segment descriptor  */
end_comment

begin_struct
struct|struct
name|xmit_seg_descr
block|{
name|H_dma
name|xsd_buffer
decl_stmt|;
comment|/* Buffer's DMA address */
name|u_int
name|xsd_len
decl_stmt|;
comment|/* Data length in buffer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xmit_seg_descr
name|Xmit_seg_descr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XMIT_SEG_ALIGN
value|4
end_define

begin_comment
comment|/*  * PDU Transmit descriptor header  */
end_comment

begin_struct
struct|struct
name|xmit_descr_hdr
block|{
name|u_long
name|xdh_cell_hdr
decl_stmt|;
comment|/* Cell header (minus HEC) */
name|u_long
name|xdh_spec
decl_stmt|;
comment|/* Transmit specification (see below) */
name|u_long
name|xdh_rate
decl_stmt|;
comment|/* Rate control (data/idle cell ratio)*/
name|u_long
name|xdh_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xmit_descr_hdr
name|Xmit_descr_hdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XMIT_BLK_BITS
value|5
end_define

begin_comment
comment|/* Bits to encode block size */
end_comment

begin_define
define|#
directive|define
name|XMIT_MAX_BLK_BITS
value|4
end_define

begin_comment
comment|/* Max bits we can use */
end_comment

begin_define
define|#
directive|define
name|XMIT_BLK_SIZE
value|(1<< XMIT_BLK_BITS)
end_define

begin_define
define|#
directive|define
name|XMIT_SEGS_TO_BLKS
parameter_list|(
name|nseg
parameter_list|)
define|\
value|((((nseg) * sizeof(Xmit_seg_descr)) \ 		+ sizeof(Xmit_descr_hdr) + (XMIT_BLK_SIZE - 1)) \>> XMIT_BLK_BITS)
end_define

begin_define
define|#
directive|define
name|XMIT_MAX_BLKS
value|((1<< XMIT_MAX_BLK_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|XMIT_HDR_SEGS
value|((XMIT_BLK_SIZE - sizeof(Xmit_descr_hdr)) \ 					/ sizeof(Xmit_seg_descr))
end_define

begin_define
define|#
directive|define
name|XMIT_BLK_SEGS
value|(XMIT_BLK_SIZE / sizeof(Xmit_seg_descr))
end_define

begin_define
define|#
directive|define
name|XMIT_EXTRA_SEGS
value|((XMIT_MAX_BLKS - 1) * XMIT_BLK_SEGS)
end_define

begin_define
define|#
directive|define
name|XMIT_MAX_SEGS
value|(XMIT_EXTRA_SEGS + XMIT_HDR_SEGS)
end_define

begin_comment
comment|/*  * PDU Transmit descriptor  */
end_comment

begin_struct
struct|struct
name|xmit_descr
block|{
name|Xmit_descr_hdr
name|xd_hdr
decl_stmt|;
comment|/* Descriptor header */
name|Xmit_seg_descr
name|xd_seg
index|[
name|XMIT_MAX_SEGS
index|]
decl_stmt|;
comment|/* PDU segments */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xmit_descr
name|Xmit_descr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|xd_cell_hdr
value|xd_hdr.xdh_cell_hdr
end_define

begin_define
define|#
directive|define
name|xd_spec
value|xd_hdr.xdh_spec
end_define

begin_define
define|#
directive|define
name|xd_rate
value|xd_hdr.xdh_rate
end_define

begin_comment
comment|/*  * Transmit specification  *  *	Bits  0-15 - Total PDU length  *	Bits 16-23 - Number of transmit segments  *	Bits 24-27 - AAL type  *	Bits 28-31 - Interrupt flag  */
end_comment

begin_define
define|#
directive|define
name|XDS_SET_SPEC
parameter_list|(
name|i
parameter_list|,
name|a
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
value|(((i)<< 28) | ((a)<< 24) | ((n)<< 16) | (l))
end_define

begin_define
define|#
directive|define
name|XDS_GET_LEN
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xffff)
end_define

begin_define
define|#
directive|define
name|XDS_GET_SEGS
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|XDS_GET_AAL
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 24)& 0xf)
end_define

begin_define
define|#
directive|define
name|XDS_GET_INTR
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 28)& 0xf)
end_define

begin_define
define|#
directive|define
name|XMIT_MAX_PDULEN
value|65535
end_define

begin_define
define|#
directive|define
name|XMIT_DESCR_ALIGN
value|32
end_define

begin_comment
comment|/*  * PDU Receive Queue  */
end_comment

begin_comment
comment|/*  * PDU Receive Queue Element  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|com_queue
name|Recv_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Receive PDU buffer segment description  */
end_comment

begin_struct
struct|struct
name|recv_seg_descr
block|{
name|H_addr
name|rsd_handle
decl_stmt|;
comment|/* Buffer handle (from supply) */
name|u_int
name|rsd_len
decl_stmt|;
comment|/* Data length in buffer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|recv_seg_descr
name|Recv_seg_descr
typedef|;
end_typedef

begin_comment
comment|/*  * PDU Receive descriptor header  */
end_comment

begin_struct
struct|struct
name|recv_descr_hdr
block|{
name|u_long
name|rdh_cell_hdr
decl_stmt|;
comment|/* Cell header (minus HEC) */
name|u_long
name|rdh_nsegs
decl_stmt|;
comment|/* Number of receive segments */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|recv_descr_hdr
name|Recv_descr_hdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RECV_BLK_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|RECV_HDR_SEGS
value|((RECV_BLK_SIZE - sizeof(Recv_descr_hdr)) \ 					/ sizeof(Recv_seg_descr))
end_define

begin_define
define|#
directive|define
name|RECV_BLK_SEGS
value|(RECV_BLK_SIZE / sizeof(Recv_seg_descr))
end_define

begin_define
define|#
directive|define
name|RECV_MAX_LG_SEGS
value|((FORE_IFF_MTU - BUF1_SM_SIZE \ 					+ (BUF1_LG_SIZE - 1)) / BUF1_LG_SIZE)
end_define

begin_define
define|#
directive|define
name|RECV_EXTRA_BLKS
value|(((RECV_MAX_LG_SEGS + 1 - RECV_HDR_SEGS) \ 					+ (RECV_BLK_SEGS - 1)) / RECV_BLK_SEGS)
end_define

begin_define
define|#
directive|define
name|RECV_EXTRA_SEGS
value|(RECV_EXTRA_BLKS * RECV_BLK_SEGS)
end_define

begin_define
define|#
directive|define
name|RECV_MAX_SEGS
value|(RECV_EXTRA_SEGS + RECV_HDR_SEGS)
end_define

begin_comment
comment|/*  * PDU Receive descriptor  */
end_comment

begin_struct
struct|struct
name|recv_descr
block|{
name|Recv_descr_hdr
name|rd_hdr
decl_stmt|;
comment|/* Descriptor header */
name|Recv_seg_descr
name|rd_seg
index|[
name|RECV_MAX_SEGS
index|]
decl_stmt|;
comment|/* PDU segments */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|recv_descr
name|Recv_descr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rd_cell_hdr
value|rd_hdr.rdh_cell_hdr
end_define

begin_define
define|#
directive|define
name|rd_nsegs
value|rd_hdr.rdh_nsegs
end_define

begin_define
define|#
directive|define
name|RECV_DESCR_ALIGN
value|32
end_define

begin_comment
comment|/*  * Buffer Supply Queue  */
end_comment

begin_comment
comment|/*  * Buffer Supply Queue Element  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|com_queue
name|Buf_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Buffer supply descriptor for supplying receive buffers  */
end_comment

begin_struct
struct|struct
name|buf_descr
block|{
name|H_addr
name|bsd_handle
decl_stmt|;
comment|/* Host-specific buffer handle */
name|H_dma
name|bsd_buffer
decl_stmt|;
comment|/* Buffer DMA address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|buf_descr
name|Buf_descr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUF_DESCR_ALIGN
value|32
end_define

begin_comment
comment|/*  * Command Queue  */
end_comment

begin_comment
comment|/*  * Command Codes  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|long
name|Cmd_code
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CMD_INIT
value|0x01
end_define

begin_comment
comment|/* Initialize microcode */
end_comment

begin_define
define|#
directive|define
name|CMD_ACT_VCCIN
value|0x02
end_define

begin_comment
comment|/* Activate incoming VCC */
end_comment

begin_define
define|#
directive|define
name|CMD_ACT_VCCOUT
value|0x03
end_define

begin_comment
comment|/* Activate outgoing VCC */
end_comment

begin_define
define|#
directive|define
name|CMD_DACT_VCCIN
value|0x04
end_define

begin_comment
comment|/* Deactivate incoming VCC */
end_comment

begin_define
define|#
directive|define
name|CMD_DACT_VCCOUT
value|0x05
end_define

begin_comment
comment|/* Deactivate outgoing VCC */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_STATS
value|0x06
end_define

begin_comment
comment|/* Get adapter statistics */
end_comment

begin_define
define|#
directive|define
name|CMD_SET_OC3_REG
value|0x07
end_define

begin_comment
comment|/* Set SUNI OC3 registers */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_OC3_REG
value|0x08
end_define

begin_comment
comment|/* Get SUNI OC3 registers */
end_comment

begin_define
define|#
directive|define
name|CMD_GET_PROM
value|0x09
end_define

begin_comment
comment|/* Get PROM data */
end_comment

begin_define
define|#
directive|define
name|CMD_INTR_REQ
value|0x80
end_define

begin_comment
comment|/* Request host interrupt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * Structure defining the parameters for the Initialize command  */
end_comment

begin_struct
struct|struct
name|init_parms
block|{
name|CP_word
name|init_cmd
decl_stmt|;
comment|/* Command code */
name|CP_word
name|init_status
decl_stmt|;
comment|/* Completion status */
name|CP_word
name|init_indisc
decl_stmt|;
comment|/* Not used */
name|CP_word
name|init_numvcc
decl_stmt|;
comment|/* Number of VCC's supported */
name|CP_word
name|init_cmd_elem
decl_stmt|;
comment|/* # of command queue elements */
name|CP_word
name|init_xmit_elem
decl_stmt|;
comment|/* # of transmit queue elements */
name|CP_word
name|init_recv_elem
decl_stmt|;
comment|/* # of receive queue elements */
name|CP_word
name|init_recv_ext
decl_stmt|;
comment|/* # of extra receive descr SEGMENTS */
name|CP_word
name|init_xmit_ext
decl_stmt|;
comment|/* # of extra transmit descr SEGMENTS */
name|CP_word
name|init_cls_vcc
decl_stmt|;
comment|/* Not used */
name|CP_word
name|init_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
name|Buf_strategy
name|init_buf1s
decl_stmt|;
comment|/* Buffer strategy - 1 small */
name|Buf_strategy
name|init_buf1l
decl_stmt|;
comment|/* Buffer strategy - 1 large */
name|Buf_strategy
name|init_buf2s
decl_stmt|;
comment|/* Buffer strategy - 2 small */
name|Buf_strategy
name|init_buf2l
decl_stmt|;
comment|/* Buffer strategy - 2 large */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|init_parms
name|Init_parms
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure defining the parameters for the Activate commands  */
end_comment

begin_struct
struct|struct
name|activate_parms
block|{
name|CP_word
name|act_spec
decl_stmt|;
comment|/* Command specification (see below) */
name|CP_word
name|act_vccid
decl_stmt|;
comment|/* VCC id (VPI=0,VCI=id) */
name|CP_word
name|act_batch
decl_stmt|;
comment|/* # cells in batch (AAL=NULL) */
name|CP_word
name|act_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|activate_parms
name|Activate_parms
typedef|;
end_typedef

begin_comment
comment|/*  * Activate command specification  *  *	Bits  0-7  - command code  *	Bits  8-15 - AAL type  *	Bits 16-23 - buffer strategy  *	Bits 24-31 - reserved  */
end_comment

begin_define
define|#
directive|define
name|ACT_SET_SPEC
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
value|(((b)<< 16) | ((a)<< 8) | (c))
end_define

begin_define
define|#
directive|define
name|ACT_GET_CMD
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xff)
end_define

begin_define
define|#
directive|define
name|ACT_GET_AAL
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|ACT_GET_STRAT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 16)& 0xff)
end_define

begin_comment
comment|/*  * Structure defining the parameters for the Deactivate commands  */
end_comment

begin_struct
struct|struct
name|dactivate_parms
block|{
name|CP_word
name|dact_cmd
decl_stmt|;
comment|/* Command code */
name|CP_word
name|dact_vccid
decl_stmt|;
comment|/* VCC id (VPI=0,VCI=id) */
name|CP_word
name|dact_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|dactivate_parms
name|Dactivate_parms
typedef|;
end_typedef

begin_comment
comment|/*  * Structure defining the parameters for the Get Statistics command  */
end_comment

begin_struct
struct|struct
name|stats_parms
block|{
name|CP_word
name|stats_cmd
decl_stmt|;
comment|/* Command code */
name|CP_dma
name|stats_buffer
decl_stmt|;
comment|/* DMA address of host stats buffer */
name|CP_word
name|stats_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|stats_parms
name|Stats_parms
typedef|;
end_typedef

begin_comment
comment|/*  * Structure defining the parameters for the SUNI OC3 commands  */
end_comment

begin_struct
struct|struct
name|suni_parms
block|{
name|CP_word
name|suni_spec
decl_stmt|;
comment|/* Command specification (see below) */
name|CP_dma
name|suni_buffer
decl_stmt|;
comment|/* DMA address of host SUNI buffer */
name|CP_word
name|suni_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|suni_parms
name|Suni_parms
typedef|;
end_typedef

begin_comment
comment|/*  * SUNI OC3 command specification  *  *	Bits  0-7  - command code  *	Bits  8-15 - SUNI register number  *	Bits 16-23 - Value(s) to set in register  *	Bits 24-31 - Mask selecting value bits  */
end_comment

begin_define
define|#
directive|define
name|SUNI_SET_SPEC
parameter_list|(
name|m
parameter_list|,
name|v
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
value|(((m)<< 24) | ((v)<< 16) | ((r)<< 8) | (c))
end_define

begin_define
define|#
directive|define
name|SUNI_GET_CMD
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xff)
end_define

begin_define
define|#
directive|define
name|SUNI_GET_REG
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|SUNI_GET_VALUE
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|SUNI_GET_MASK
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 24)& 0xff)
end_define

begin_comment
comment|/*  * Structure defining the parameters for the Get Prom command  */
end_comment

begin_struct
struct|struct
name|prom_parms
block|{
name|CP_word
name|prom_cmd
decl_stmt|;
comment|/* Command code */
name|CP_dma
name|prom_buffer
decl_stmt|;
comment|/* DMA address of host prom buffer */
name|CP_word
name|prom_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|prom_parms
name|Prom_parms
typedef|;
end_typedef

begin_comment
comment|/*  * Command Queue Element  */
end_comment

begin_struct
struct|struct
name|cmd_queue
block|{
union|union
block|{
comment|/* Command-specific parameters */
name|Activate_parms
name|cmdqu_act
decl_stmt|;
name|Dactivate_parms
name|cmdqu_dact
decl_stmt|;
name|Stats_parms
name|cmdqu_stats
decl_stmt|;
name|Suni_parms
name|cmdqu_suni
decl_stmt|;
name|Prom_parms
name|cmdqu_prom
decl_stmt|;
block|}
name|cmdq_u
union|;
name|CP_dma
name|cmdq_status
decl_stmt|;
comment|/* Pointer to element status word */
name|CP_word
name|cmdq_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cmdq_act
value|cmdq_u.cmdqu_act
end_define

begin_define
define|#
directive|define
name|cmdq_dact
value|cmdq_u.cmdqu_dact
end_define

begin_define
define|#
directive|define
name|cmdq_stats
value|cmdq_u.cmdqu_stats
end_define

begin_define
define|#
directive|define
name|cmdq_suni
value|cmdq_u.cmdqu_suni
end_define

begin_define
define|#
directive|define
name|cmdq_prom
value|cmdq_u.cmdqu_prom
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|cmd_queue
name|Cmd_queue
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * Structure defining the CP's shared memory interface to the   * AALI firmware program (downloaded microcode)  */
end_comment

begin_struct
struct|struct
name|aali
block|{
name|CP_addr
name|aali_cmd_q
decl_stmt|;
comment|/* Pointer to command queue */
name|CP_addr
name|aali_xmit_q
decl_stmt|;
comment|/* Pointer to transmit queue */
name|CP_addr
name|aali_recv_q
decl_stmt|;
comment|/* Pointer to receive queue */
name|CP_addr
name|aali_buf1s_q
decl_stmt|;
comment|/* Pointer to strategy-1 small queue */
name|CP_addr
name|aali_buf1l_q
decl_stmt|;
comment|/* Pointer to strategy-1 large queue */
name|CP_addr
name|aali_buf2s_q
decl_stmt|;
comment|/* Pointer to strategy-2 small queue */
name|CP_addr
name|aali_buf2l_q
decl_stmt|;
comment|/* Pointer to strategy-2 large queue */
name|CP_word
name|aali_intr_ena
decl_stmt|;
comment|/* Enables interrupts if non-zero */
name|CP_word
name|aali_intr_sent
decl_stmt|;
comment|/* Interrupt issued if non-zero */
name|CP_addr
name|aali_heap
decl_stmt|;
comment|/* Pointer to application heap */
name|CP_word
name|aali_heaplen
decl_stmt|;
comment|/* Length of application heap */
name|CP_word
name|aali_hostlog
decl_stmt|;
comment|/* FORE internal use */
name|CP_word
name|aali_heartbeat
decl_stmt|;
comment|/* Monitor microcode health */
name|CP_word
name|aali_ucode_ver
decl_stmt|;
comment|/* Microcode firmware version */
name|CP_word
name|aali_mon_ver
decl_stmt|;
comment|/* Mon960 version */
name|CP_word
name|aali_xmit_tput
decl_stmt|;
comment|/* FORE internal use */
comment|/* This must be on a quad-word boundary */
name|Init_parms
name|aali_init
decl_stmt|;
comment|/* Initialize command parameters */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|volatile
name|struct
name|aali
name|Aali
typedef|;
end_typedef

begin_comment
comment|/*  * CP maintained statistics - DMA'd to host with CMD_GET_STATS command  */
end_comment

begin_struct
struct|struct
name|stats_taxi
block|{
name|u_long
name|taxi_bad_crc
decl_stmt|;
comment|/* Bad header CRC errors */
name|u_long
name|taxi_framing
decl_stmt|;
comment|/* Framing errors */
name|u_long
name|taxi_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_taxi
name|Stats_taxi
typedef|;
end_typedef

begin_struct
struct|struct
name|stats_oc3
block|{
name|u_long
name|oc3_sect_bip8
decl_stmt|;
comment|/* Section 8-bit intrlv parity errors */
name|u_long
name|oc3_path_bip8
decl_stmt|;
comment|/* Path 8-bit intrlv parity errors */
name|u_long
name|oc3_line_bip24
decl_stmt|;
comment|/* Line 24-bit intrlv parity errors */
name|u_long
name|oc3_line_febe
decl_stmt|;
comment|/* Line far-end block errors */
name|u_long
name|oc3_path_febe
decl_stmt|;
comment|/* Path far-end block errors */
name|u_long
name|oc3_hec_corr
decl_stmt|;
comment|/* Correctible HEC errors */
name|u_long
name|oc3_hec_uncorr
decl_stmt|;
comment|/* Uncorrectible HEC errors */
name|u_long
name|oc3_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_oc3
name|Stats_oc3
typedef|;
end_typedef

begin_struct
struct|struct
name|stats_atm
block|{
name|u_long
name|atm_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|atm_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|atm_vpi_range
decl_stmt|;
comment|/* Cell drops - VPI out of range */
name|u_long
name|atm_vpi_noconn
decl_stmt|;
comment|/* Cell drops - no connect for VPI */
name|u_long
name|atm_vci_range
decl_stmt|;
comment|/* Cell drops - VCI out of range */
name|u_long
name|atm_vci_noconn
decl_stmt|;
comment|/* Cell drops - no connect for VCI */
name|u_long
name|atm_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_atm
name|Stats_atm
typedef|;
end_typedef

begin_struct
struct|struct
name|stats_aal0
block|{
name|u_long
name|aal0_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|aal0_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|aal0_drops
decl_stmt|;
comment|/* Cell drops */
name|u_long
name|aal0_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_aal0
name|Stats_aal0
typedef|;
end_typedef

begin_struct
struct|struct
name|stats_aal4
block|{
name|u_long
name|aal4_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|aal4_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|aal4_crc
decl_stmt|;
comment|/* Cells with payload CRC errors */
name|u_long
name|aal4_sar_cs
decl_stmt|;
comment|/* Cells with SAR/CS errors */
name|u_long
name|aal4_drops
decl_stmt|;
comment|/* Cell drops */
name|u_long
name|aal4_pdu_xmit
decl_stmt|;
comment|/* CS PDUs transmitted */
name|u_long
name|aal4_pdu_rcvd
decl_stmt|;
comment|/* CS PDUs received */
name|u_long
name|aal4_pdu_errs
decl_stmt|;
comment|/* CS layer protocol errors */
name|u_long
name|aal4_pdu_drops
decl_stmt|;
comment|/* CS PDUs dropped */
name|u_long
name|aal4_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_aal4
name|Stats_aal4
typedef|;
end_typedef

begin_struct
struct|struct
name|stats_aal5
block|{
name|u_long
name|aal5_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_long
name|aal5_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_long
name|aal5_crc_len
decl_stmt|;
comment|/* Cells with CRC/length errors */
name|u_long
name|aal5_drops
decl_stmt|;
comment|/* Cell drops */
name|u_long
name|aal5_pdu_xmit
decl_stmt|;
comment|/* CS PDUs transmitted */
name|u_long
name|aal5_pdu_rcvd
decl_stmt|;
comment|/* CS PDUs received */
name|u_long
name|aal5_pdu_crc
decl_stmt|;
comment|/* CS PDUs with CRC errors */
name|u_long
name|aal5_pdu_errs
decl_stmt|;
comment|/* CS layer protocol errors */
name|u_long
name|aal5_pdu_drops
decl_stmt|;
comment|/* CS PDUs dropped */
name|u_long
name|aal5_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_aal5
name|Stats_aal5
typedef|;
end_typedef

begin_struct
struct|struct
name|stats_misc
block|{
name|u_long
name|buf1_sm_fail
decl_stmt|;
comment|/* Alloc fail: buffer strat 1 small */
name|u_long
name|buf1_lg_fail
decl_stmt|;
comment|/* Alloc fail: buffer strat 1 large */
name|u_long
name|buf2_sm_fail
decl_stmt|;
comment|/* Alloc fail: buffer strat 2 small */
name|u_long
name|buf2_lg_fail
decl_stmt|;
comment|/* Alloc fail: buffer strat 2 large */
name|u_long
name|rcvd_pdu_fail
decl_stmt|;
comment|/* Received PDU allocation failure */
name|u_long
name|carrier_status
decl_stmt|;
comment|/* Carrier status */
name|u_long
name|misc_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stats_misc
name|Stats_misc
typedef|;
end_typedef

begin_struct
struct|struct
name|fore_cp_stats
block|{
name|Stats_taxi
name|st_cp_taxi
decl_stmt|;
comment|/* TAXI layer statistics */
name|Stats_oc3
name|st_cp_oc3
decl_stmt|;
comment|/* OC3 layer statistics */
name|Stats_atm
name|st_cp_atm
decl_stmt|;
comment|/* ATM layer statistics */
name|Stats_aal0
name|st_cp_aal0
decl_stmt|;
comment|/* AAL0 layer statistics */
name|Stats_aal4
name|st_cp_aal4
decl_stmt|;
comment|/* AAL3/4 layer statistics */
name|Stats_aal5
name|st_cp_aal5
decl_stmt|;
comment|/* AAL5 layer statistics */
name|Stats_misc
name|st_cp_misc
decl_stmt|;
comment|/* Miscellaneous statistics */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fore_cp_stats
name|Fore_cp_stats
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FORE_STATS_ALIGN
value|32
end_define

begin_comment
comment|/*  * CP PROM data - DMA'd to host with CMD_GET_PROM command  */
end_comment

begin_struct
struct|struct
name|fore_prom
block|{
name|u_long
name|pr_hwver
decl_stmt|;
comment|/* Hardware version number */
name|u_long
name|pr_serno
decl_stmt|;
comment|/* Serial number */
name|u_char
name|pr_mac
index|[
literal|8
index|]
decl_stmt|;
comment|/* MAC address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fore_prom
name|Fore_prom
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FORE_PROM_ALIGN
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FORE_AALI_H */
end_comment

end_unit

