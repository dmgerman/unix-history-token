begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the generic driver for the aic7xxx based adaptec  * SCSI controllers.  This is used to implement product specific  * probe and attach routines.  *  * Copyright (c) 1994, 1995, 1996, 1997, 1998, 1999, 2000 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AIC7XXX_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIC7XXX_H_
end_define

begin_include
include|#
directive|include
file|"opt_aic7xxx.h"
end_include

begin_comment
comment|/* for config options */
end_comment

begin_include
include|#
directive|include
file|"aic7xxx_reg.h"
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/* For device_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The maximum number of supported targets.  */
end_comment

begin_define
define|#
directive|define
name|AHC_NUM_TARGETS
value|16
end_define

begin_comment
comment|/*  * The maximum number of supported luns.  * The identify message supports up to 64 luns in SPI3.  */
end_comment

begin_define
define|#
directive|define
name|AHC_NUM_LUNS
value|64
end_define

begin_comment
comment|/*  * The maximum transfer per S/G segment.  */
end_comment

begin_define
define|#
directive|define
name|AHC_MAXTRANSFER_SIZE
value|0x00ffffff
end_define

begin_comment
comment|/* limited by 24bit counter */
end_comment

begin_comment
comment|/*  * The number of dma segments supported.  The sequencer can handle any number  * of physically contiguous S/G entrys.  To reduce the driver's memory  * consumption, we limit the number supported to be sufficient to handle  * the largest mapping supported by the kernel, MAXPHYS.  Assuming the  * transfer is as fragmented as possible and unaligned, this turns out to  * be the number of paged sized transfers in MAXPHYS plus an extra element  * to handle any unaligned residual.  The sequencer fetches SG elements  * in 128 byte chucks, so make the number per-transaction a nice multiple  * of 16 (8 byte S/G elements).  */
end_comment

begin_comment
comment|/* XXX Worth the space??? */
end_comment

begin_define
define|#
directive|define
name|AHC_NSEG
value|(roundup(btoc(MAXPHYS) + 1, 16))
end_define

begin_define
define|#
directive|define
name|AHC_SCB_MAX
value|255
end_define

begin_comment
comment|/* 				 * Up to 255 SCBs on some types of aic7xxx 				 * based boards.  The aic7870 have 16 internal 				 * SCBs, but external SRAM bumps this to 255. 				 * The aic7770 family have only 4, and the  				 * aic7850 has only 3. 				 */
end_comment

begin_define
define|#
directive|define
name|AHC_TMODE_CMDS
value|256
end_define

begin_comment
comment|/* 				* Ring Buffer of incoming target commands. 				* We allocate 256 to simplify the logic 				* in the sequencer by using the natural 				* wrap point of an 8bit counter. 				*/
end_comment

begin_comment
comment|/*  * The aic7xxx chips only support a 24bit length.  We use the top  * byte of the length to store additional address bits as well  * as an indicator if this is the last SG segment in a transfer.  * This gives us an addressable range of 512GB on machines with  * 64bit PCI or with chips that can support dual address cycles  * on 32bit PCI busses.  */
end_comment

begin_struct
struct|struct
name|ahc_dma_seg
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
define|#
directive|define
name|AHC_DMA_LAST_SEG
value|0x80000000
define|#
directive|define
name|AHC_SG_HIGH_ADDR_MASK
value|0x7F000000
define|#
directive|define
name|AHC_SG_LEN_MASK
value|0x00FFFFFF
block|}
struct|;
end_struct

begin_comment
comment|/* The chip order is from least sophisticated to most sophisticated */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_NONE
init|=
literal|0x0000
block|,
name|AHC_CHIPID_MASK
init|=
literal|0x00FF
block|,
name|AHC_AIC7770
init|=
literal|0x0001
block|,
name|AHC_AIC7850
init|=
literal|0x0002
block|,
name|AHC_AIC7855
init|=
literal|0x0003
block|,
name|AHC_AIC7859
init|=
literal|0x0004
block|,
name|AHC_AIC7860
init|=
literal|0x0005
block|,
name|AHC_AIC7870
init|=
literal|0x0006
block|,
name|AHC_AIC7880
init|=
literal|0x0007
block|,
name|AHC_AIC7895
init|=
literal|0x0008
block|,
name|AHC_AIC7890
init|=
literal|0x0009
block|,
name|AHC_AIC7896
init|=
literal|0x000a
block|,
name|AHC_AIC7892
init|=
literal|0x000b
block|,
name|AHC_AIC7899
init|=
literal|0x000c
block|,
name|AHC_VL
init|=
literal|0x0100
block|,
comment|/* Bus type VL */
name|AHC_EISA
init|=
literal|0x0200
block|,
comment|/* Bus type EISA */
name|AHC_PCI
init|=
literal|0x0400
block|,
comment|/* Bus type PCI */
name|AHC_BUS_MASK
init|=
literal|0x0F00
block|}
name|ahc_chip
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ahc_chip_names
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_FENONE
init|=
literal|0x0000
block|,
name|AHC_ULTRA
init|=
literal|0x0001
block|,
comment|/* Supports 20MHz Transfers */
name|AHC_ULTRA2
init|=
literal|0x0002
block|,
comment|/* Supports 40MHz Transfers */
name|AHC_WIDE
init|=
literal|0x0004
block|,
comment|/* Wide Channel */
name|AHC_TWIN
init|=
literal|0x0008
block|,
comment|/* Twin Channel */
name|AHC_MORE_SRAM
init|=
literal|0x0010
block|,
comment|/* 80 bytes instead of 64 */
name|AHC_CMD_CHAN
init|=
literal|0x0020
block|,
comment|/* Has a Command DMA Channel */
name|AHC_QUEUE_REGS
init|=
literal|0x0040
block|,
comment|/* Has Queue management registers */
name|AHC_SG_PRELOAD
init|=
literal|0x0080
block|,
comment|/* Can perform auto-SG preload */
name|AHC_SPIOCAP
init|=
literal|0x0100
block|,
comment|/* Has a Serial Port I/O Cap Register */
name|AHC_MULTI_TID
init|=
literal|0x0200
block|,
comment|/* Has bitmask of TIDs for select-in */
name|AHC_HS_MAILBOX
init|=
literal|0x0400
block|,
comment|/* Has HS_MAILBOX register */
name|AHC_DT
init|=
literal|0x0800
block|,
comment|/* Double Transition transfers */
name|AHC_NEW_TERMCTL
init|=
literal|0x1000
block|,
name|AHC_MULTI_FUNC
init|=
literal|0x2000
block|,
comment|/* Multi-Function Twin Channel Device */
name|AHC_LARGE_SCBS
init|=
literal|0x4000
block|,
comment|/* 64byte SCBs */
name|AHC_AIC7770_FE
init|=
name|AHC_FENONE
block|,
name|AHC_AIC7850_FE
init|=
name|AHC_SPIOCAP
block|,
name|AHC_AIC7855_FE
init|=
name|AHC_AIC7850_FE
block|,
name|AHC_AIC7859_FE
init|=
name|AHC_AIC7850_FE
operator||
name|AHC_ULTRA
block|,
name|AHC_AIC7860_FE
init|=
name|AHC_AIC7859_FE
block|,
name|AHC_AIC7870_FE
init|=
name|AHC_FENONE
block|,
name|AHC_AIC7880_FE
init|=
name|AHC_ULTRA
block|,
name|AHC_AIC7890_FE
init|=
name|AHC_MORE_SRAM
operator||
name|AHC_CMD_CHAN
operator||
name|AHC_ULTRA2
operator||
name|AHC_QUEUE_REGS
operator||
name|AHC_SG_PRELOAD
operator||
name|AHC_MULTI_TID
operator||
name|AHC_HS_MAILBOX
operator||
name|AHC_NEW_TERMCTL
operator||
name|AHC_LARGE_SCBS
block|,
name|AHC_AIC7892_FE
init|=
name|AHC_AIC7890_FE
operator||
name|AHC_DT
block|,
name|AHC_AIC7895_FE
init|=
name|AHC_AIC7880_FE
operator||
name|AHC_MORE_SRAM
operator||
name|AHC_CMD_CHAN
operator||
name|AHC_MULTI_FUNC
operator||
name|AHC_LARGE_SCBS
block|,
name|AHC_AIC7895C_FE
init|=
name|AHC_AIC7895_FE
operator||
name|AHC_MULTI_TID
block|,
name|AHC_AIC7896_FE
init|=
name|AHC_AIC7890_FE
operator||
name|AHC_MULTI_FUNC
block|,
name|AHC_AIC7899_FE
init|=
name|AHC_AIC7892_FE
operator||
name|AHC_MULTI_FUNC
block|}
name|ahc_feature
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_BUGNONE
init|=
literal|0x00
block|,
comment|/* 	 * On all chips prior to the U2 product line, 	 * the WIDEODD S/G segment feature does not 	 * work during scsi->HostBus transfers. 	 */
name|AHC_TMODE_WIDEODD_BUG
init|=
literal|0x01
block|,
comment|/* 	 * On the aic7890/91 Rev 0 chips, the autoflush 	 * feature does not work.  A manual flush of 	 * the DMA FIFO is required. 	 */
name|AHC_AUTOFLUSH_BUG
init|=
literal|0x02
block|,
comment|/* 	 * On the aic7890/91 Rev 0 chips, cacheline 	 * streaming does not work. 	 */
name|AHC_CACHETHEN_BUG
init|=
literal|0x04
block|,
comment|/* 	 * On the aic7896/97 chips, cacheline 	 * streaming must be enabled. 	 */
name|AHC_CACHETHEN_DIS_BUG
init|=
literal|0x08
block|}
name|ahc_bug
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_FNONE
init|=
literal|0x000
block|,
name|AHC_PAGESCBS
init|=
literal|0x001
block|,
comment|/* Enable SCB paging */
name|AHC_CHANNEL_B_PRIMARY
init|=
literal|0x002
block|,
comment|/* 					 * On twin channel adapters, probe 					 * channel B first since it is the 					 * primary bus. 					 */
name|AHC_USEDEFAULTS
init|=
literal|0x004
block|,
comment|/* 					 * For cards without an seeprom 					 * or a BIOS to initialize the chip's 					 * SRAM, we use the default target 					 * settings. 					 */
name|AHC_SHARED_SRAM
init|=
literal|0x010
block|,
name|AHC_LARGE_SEEPROM
init|=
literal|0x020
block|,
comment|/* Uses C56_66 not C46 */
name|AHC_RESET_BUS_A
init|=
literal|0x040
block|,
name|AHC_RESET_BUS_B
init|=
literal|0x080
block|,
name|AHC_EXTENDED_TRANS_A
init|=
literal|0x100
block|,
name|AHC_EXTENDED_TRANS_B
init|=
literal|0x200
block|,
name|AHC_TERM_ENB_A
init|=
literal|0x400
block|,
name|AHC_TERM_ENB_B
init|=
literal|0x800
block|,
name|AHC_INITIATORMODE
init|=
literal|0x1000
block|,
comment|/* 					  * Allow initiator operations on 					  * this controller. 					  */
name|AHC_TARGETMODE
init|=
literal|0x2000
block|,
comment|/* 					  * Allow target operations on this 					  * controller. 					  */
name|AHC_NEWEEPROM_FMT
init|=
literal|0x4000
block|,
name|AHC_RESOURCE_SHORTAGE
init|=
literal|0x8000
block|,
name|AHC_TQINFIFO_BLOCKED
init|=
literal|0x10000
block|,
comment|/* Blocked waiting for ATIOs */
name|AHC_INT50_SPEEDFLEX
init|=
literal|0x20000
block|,
comment|/* 					   * Internal 50pin connector 					   * sits behind an aic3860 					   */
name|AHC_SCB_BTT
init|=
literal|0x40000
comment|/* 					   * The busy targets table is 					   * stored in SCB space rather 					   * than SRAM. 					   */
block|}
name|ahc_flag
typedef|;
end_typedef

begin_struct
struct|struct
name|ahc_probe_config
block|{
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
name|char
name|channel
decl_stmt|;
name|char
name|channel_b
decl_stmt|;
name|ahc_chip
name|chip
decl_stmt|;
name|ahc_feature
name|features
decl_stmt|;
name|ahc_bug
name|bugs
decl_stmt|;
name|ahc_flag
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|SCB_FREE
init|=
literal|0x0000
block|,
name|SCB_OTHERTCL_TIMEOUT
init|=
literal|0x0002
block|,
comment|/* 					  * Another device was active 					  * during the first timeout for 					  * this SCB so we gave ourselves 					  * an additional timeout period 					  * in case it was hogging the 					  * bus. 				          */
name|SCB_DEVICE_RESET
init|=
literal|0x0004
block|,
name|SCB_SENSE
init|=
literal|0x0008
block|,
name|SCB_RECOVERY_SCB
init|=
literal|0x0040
block|,
name|SCB_NEGOTIATE
init|=
literal|0x0080
block|,
name|SCB_ABORT
init|=
literal|0x1000
block|,
name|SCB_QUEUED_MSG
init|=
literal|0x2000
block|,
name|SCB_ACTIVE
init|=
literal|0x4000
block|,
name|SCB_TARGET_IMMEDIATE
init|=
literal|0x8000
block|}
name|scb_flag
typedef|;
end_typedef

begin_comment
comment|/*  * The driver keeps up to MAX_SCB scb structures per card in memory.  The SCB  * consists of a "hardware SCB" mirroring the fields availible on the card  * and additional information the kernel stores for each transaction.  *  * To minimize space utilization, a portion of the hardware scb stores  * different data during different portions of a SCSI transaction.  * As initialized by the host driver for the initiator role, this area  * contains the SCSI cdb (or pointer to the  cdb) to be executed.  After  * the cdb has been presented to the target, this area serves to store  * residual transfer information and the SCSI status byte.  * For the target role, the contents of this area do not change, but  * still serve a different purpose than for the initiator role.  See  * struct target_data for details.  */
end_comment

begin_struct
struct|struct
name|status_pkt
block|{
name|uint32_t
name|residual_datacnt
decl_stmt|;
name|uint32_t
name|residual_sg_ptr
decl_stmt|;
name|uint8_t
name|scsi_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|target_data
block|{
name|uint8_t
name|target_phases
decl_stmt|;
name|uint8_t
name|data_phase
decl_stmt|;
name|uint8_t
name|scsi_status
decl_stmt|;
name|uint8_t
name|initiator_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hardware_scb
block|{
comment|/*0*/
name|uint8_t
name|control
decl_stmt|;
comment|/*1*/
name|uint8_t
name|scsiid
decl_stmt|;
comment|/* what to load in the SCSIID register */
comment|/*2*/
name|uint8_t
name|lun
decl_stmt|;
comment|/*3*/
name|uint8_t
name|cdb_len
decl_stmt|;
comment|/*4*/
union|union
block|{
comment|/* 		 * 12 bytes of cdb information only 		 * used on chips with 32byte SCBs. 		 */
name|uint8_t
name|cdb
index|[
literal|12
index|]
decl_stmt|;
name|uint32_t
name|cdb_ptr
decl_stmt|;
name|struct
name|status_pkt
name|status
decl_stmt|;
name|struct
name|target_data
name|tdata
decl_stmt|;
block|}
name|shared_data
union|;
comment|/*  * A word about residuals.  The scb is presented to the sequencer with  * the dataptr and datacnt fields initialized to the contents of the  * first S/G element to transfer.  The sgptr field is initialized to  * the bus address for the S/G element that follows the first in the  * in core S/G array or'ed with the SG_FULL_RESID flag.  Sgptr may point  * to an invalid S/G entry for this transfer.  If no transfer is to occur,  * sgptr is set to SG_LIST_NULL.  The SG_FULL_RESID flag insures that  * the residual will be correctly noted even if no data transfers occur.  * Once the data phase is entered, the residual sgptr and datacnt are  * loaded from the sgptr and the datacnt fields.  After each S/G element's  * dataptr and length are loaded into the hardware, the residual sgptr  * is advanced.  After each S/G element is expired, its datacnt field  * is checked to see if the LAST_SEG flag is set.  If so, SG_LIST_NULL  * is set in the residual sg ptr and the transfer is considered complete.  * If the sequencer determines that three is a residual in the tranfer,  * it will set the SG_RESID_VALID flag in sgptr and dma the scb back into  * host memory.  To sumarize:  *  * Sequencer:  *	o A residual has occurred if SG_FULL_RESID is set in sgptr,  *	  or residual_sgptr does not have SG_LIST_NULL set.  *  *	o We are transfering the last segment if residual_datacnt has  *	  the SG_LAST_SEG flag set.  *  * Host:  *	o A residual has occurred if a completed scb has the  *	  SG_RESID_VALID flag set.  *  *	o residual_sgptr and sgptr refer to the "next" sg entry  *	  and so may point beyond the last valid sg entry for the  *	  transfer.  */
comment|/*16*/
name|uint32_t
name|dataptr
decl_stmt|;
comment|/*20*/
name|uint32_t
name|datacnt
decl_stmt|;
comment|/* 					 * The highest address byte is 					 * really the 5th. byte in the 					 * dataptr. 					 */
comment|/*24*/
name|uint32_t
name|sgptr
decl_stmt|;
define|#
directive|define
name|SG_PTR_MASK
value|0xFFFFFFF8
comment|/*28*/
name|uint8_t
name|tag
decl_stmt|;
comment|/* Index into our kernel SCB array. 					 * Also used as the tag for tagged I/O 					 */
comment|/*29*/
name|uint8_t
name|scsirate
decl_stmt|;
comment|/* Value for SCSIRATE register */
comment|/*30*/
name|uint8_t
name|scsioffset
decl_stmt|;
comment|/* Value for SCSIOFFSET register */
comment|/*31*/
name|uint8_t
name|next
decl_stmt|;
comment|/* Used for threading SCBs in the 					 * "Waiting for Selection" and 					 * "Disconnected SCB" lists down 					 * in the sequencer. 					 */
comment|/*32*/
name|uint8_t
name|cdb32
index|[
literal|32
index|]
decl_stmt|;
comment|/* 					 * CDB storage for controllers 					 * supporting 64 byte SCBs. 					 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scb
block|{
name|struct
name|hardware_scb
modifier|*
name|hscb
decl_stmt|;
union|union
block|{
name|SLIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|sle
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|scb
argument_list|)
name|tqe
expr_stmt|;
block|}
name|links
union|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
comment|/* the ccb for this cmd */
name|scb_flag
name|flags
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|struct
name|ahc_dma_seg
modifier|*
name|sg_list
decl_stmt|;
name|bus_addr_t
name|sg_list_phys
decl_stmt|;
name|bus_addr_t
name|cdb32_busaddr
decl_stmt|;
name|u_int
name|sg_count
decl_stmt|;
comment|/* How full ahc_dma_seg is */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Connection desciptor for select-in requests in target mode.  * The first byte is the connecting target, followed by identify  * message and optional tag information, terminated by 0xFF.  The  * remainder is the command to execute.  The cmd_valid byte is on  * an 8 byte boundary to simplify setting it on aic7880 hardware  * which only has limited direct access to the DMA FIFO.  */
end_comment

begin_struct
struct|struct
name|target_cmd
block|{
name|uint8_t
name|scsiid
decl_stmt|;
name|uint8_t
name|identify
decl_stmt|;
comment|/* Identify message */
name|uint8_t
name|bytes
index|[
literal|22
index|]
decl_stmt|;
name|uint8_t
name|cmd_valid
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Number of events we can buffer up if we run out  * of immediate notify ccbs.  */
end_comment

begin_define
define|#
directive|define
name|AHC_TMODE_EVENT_BUFFER_SIZE
value|8
end_define

begin_struct
struct|struct
name|ahc_tmode_event
block|{
name|uint8_t
name|initiator_id
decl_stmt|;
name|uint8_t
name|event_type
decl_stmt|;
comment|/* MSG type or EVENT_TYPE_BUS_RESET */
define|#
directive|define
name|EVENT_TYPE_BUS_RESET
value|0xFF
name|uint8_t
name|event_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per lun target mode state including accept TIO CCB  * and immediate notify CCB pools.  */
end_comment

begin_struct
struct|struct
name|tmode_lstate
block|{
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|ccb_hdr_slist
name|accept_tios
decl_stmt|;
name|struct
name|ccb_hdr_slist
name|immed_notifies
decl_stmt|;
name|struct
name|ahc_tmode_event
name|event_buffer
index|[
name|AHC_TMODE_EVENT_BUFFER_SIZE
index|]
decl_stmt|;
name|uint8_t
name|event_r_idx
decl_stmt|;
name|uint8_t
name|event_w_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AHC_TRANS_CUR
value|0x01
end_define

begin_comment
comment|/* Modify current neogtiation status */
end_comment

begin_define
define|#
directive|define
name|AHC_TRANS_ACTIVE
value|0x03
end_define

begin_comment
comment|/* Assume this is the active target */
end_comment

begin_define
define|#
directive|define
name|AHC_TRANS_GOAL
value|0x04
end_define

begin_comment
comment|/* Modify negotiation goal */
end_comment

begin_define
define|#
directive|define
name|AHC_TRANS_USER
value|0x08
end_define

begin_comment
comment|/* Modify user negotiation settings */
end_comment

begin_struct
struct|struct
name|ahc_transinfo
block|{
name|uint8_t
name|protocol_version
decl_stmt|;
name|uint8_t
name|transport_version
decl_stmt|;
name|uint8_t
name|width
decl_stmt|;
name|uint8_t
name|period
decl_stmt|;
name|uint8_t
name|offset
decl_stmt|;
name|uint8_t
name|ppr_options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_initiator_tinfo
block|{
name|uint8_t
name|scsirate
decl_stmt|;
name|struct
name|ahc_transinfo
name|current
decl_stmt|;
name|struct
name|ahc_transinfo
name|goal
decl_stmt|;
name|struct
name|ahc_transinfo
name|user
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per target mode enabled target state.  Esentially just an array of  * pointers to lun target state as well as sync/wide negotiation information  * for each initiator<->target mapping (including the mapping for when we  * are the initiator).  */
end_comment

begin_struct
struct|struct
name|tmode_tstate
block|{
name|struct
name|tmode_lstate
modifier|*
name|enabled_luns
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|ahc_initiator_tinfo
name|transinfo
index|[
literal|16
index|]
decl_stmt|;
comment|/* 	 * Per initiator state bitmasks. 	 */
name|uint16_t
name|ultraenb
decl_stmt|;
comment|/* Using ultra sync rate  */
name|uint16_t
name|discenable
decl_stmt|;
comment|/* Disconnection allowed  */
name|uint16_t
name|tagenable
decl_stmt|;
comment|/* Tagged Queuing allowed */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Define the format of the aic7XXX SEEPROM registers (16 bits).  */
end_comment

begin_struct
struct|struct
name|seeprom_config
block|{
comment|/*  * SCSI ID Configuration Flags  */
name|uint16_t
name|device_flags
index|[
literal|16
index|]
decl_stmt|;
comment|/* words 0-15 */
define|#
directive|define
name|CFXFER
value|0x0007
comment|/* synchronous transfer rate */
define|#
directive|define
name|CFSYNCH
value|0x0008
comment|/* enable synchronous transfer */
define|#
directive|define
name|CFDISC
value|0x0010
comment|/* enable disconnection */
define|#
directive|define
name|CFWIDEB
value|0x0020
comment|/* wide bus device */
define|#
directive|define
name|CFSYNCHISULTRA
value|0x0040
comment|/* CFSYNCH is an ultra offset (2940AU)*/
define|#
directive|define
name|CFSYNCSINGLE
value|0x0080
comment|/* Single-Transition signalling */
define|#
directive|define
name|CFSTART
value|0x0100
comment|/* send start unit SCSI command */
define|#
directive|define
name|CFINCBIOS
value|0x0200
comment|/* include in BIOS scan */
define|#
directive|define
name|CFRNFOUND
value|0x0400
comment|/* report even if not found */
define|#
directive|define
name|CFMULTILUNDEV
value|0x0800
comment|/* Probe multiple luns in BIOS scan */
define|#
directive|define
name|CFWBCACHEENB
value|0x4000
comment|/* Enable W-Behind Cache on disks */
define|#
directive|define
name|CFWBCACHENOP
value|0xc000
comment|/* Don't touch W-Behind Cache */
comment|/*  * BIOS Control Bits  */
name|uint16_t
name|bios_control
decl_stmt|;
comment|/* word 16 */
define|#
directive|define
name|CFSUPREM
value|0x0001
comment|/* support all removeable drives */
define|#
directive|define
name|CFSUPREMB
value|0x0002
comment|/* support removeable boot drives */
define|#
directive|define
name|CFBIOSEN
value|0x0004
comment|/* BIOS enabled */
comment|/*		UNUSED		0x0008	*/
define|#
directive|define
name|CFSM2DRV
value|0x0010
comment|/* support more than two drives */
define|#
directive|define
name|CF284XEXTEND
value|0x0020
comment|/* extended translation (284x cards) */
define|#
directive|define
name|CFSTPWLEVEL
value|0x0010
comment|/* Termination level control */
define|#
directive|define
name|CFEXTEND
value|0x0080
comment|/* extended translation enabled */
define|#
directive|define
name|CFSCAMEN
value|0x0100
comment|/* SCAM enable */
comment|/*		UNUSED		0xff00	*/
comment|/*  * Host Adapter Control Bits  */
name|uint16_t
name|adapter_control
decl_stmt|;
comment|/* word 17 */
define|#
directive|define
name|CFAUTOTERM
value|0x0001
comment|/* Perform Auto termination */
define|#
directive|define
name|CFULTRAEN
value|0x0002
comment|/* Ultra SCSI speed enable */
define|#
directive|define
name|CF284XSELTO
value|0x0003
comment|/* Selection timeout (284x cards) */
define|#
directive|define
name|CF284XFIFO
value|0x000C
comment|/* FIFO Threshold (284x cards) */
define|#
directive|define
name|CFSTERM
value|0x0004
comment|/* SCSI low byte termination */
define|#
directive|define
name|CFWSTERM
value|0x0008
comment|/* SCSI high byte termination */
define|#
directive|define
name|CFSPARITY
value|0x0010
comment|/* SCSI parity */
define|#
directive|define
name|CF284XSTERM
value|0x0020
comment|/* SCSI low byte term (284x cards) */
define|#
directive|define
name|CFMULTILUN
value|0x0020
comment|/* SCSI low byte term (284x cards) */
define|#
directive|define
name|CFRESETB
value|0x0040
comment|/* reset SCSI bus at boot */
define|#
directive|define
name|CFCLUSTERENB
value|0x0080
comment|/* Cluster Enable */
define|#
directive|define
name|CFCHNLBPRIMARY
value|0x0100
comment|/* aic7895 probe B channel first */
define|#
directive|define
name|CFSEAUTOTERM
value|0x0400
comment|/* Ultra2 Perform secondary Auto Term*/
define|#
directive|define
name|CFSELOWTERM
value|0x0800
comment|/* Ultra2 secondary low term */
define|#
directive|define
name|CFSEHIGHTERM
value|0x1000
comment|/* Ultra2 secondary high term */
define|#
directive|define
name|CFDOMAINVAL
value|0x4000
comment|/* Perform Domain Validation*/
comment|/*  * Bus Release, Host Adapter ID  */
name|uint16_t
name|brtime_id
decl_stmt|;
comment|/* word 18 */
define|#
directive|define
name|CFSCSIID
value|0x000f
comment|/* host adapter SCSI ID */
comment|/*		UNUSED		0x00f0	*/
define|#
directive|define
name|CFBRTIME
value|0xff00
comment|/* bus release time */
comment|/*  * Maximum targets  */
name|uint16_t
name|max_targets
decl_stmt|;
comment|/* word 19 */
define|#
directive|define
name|CFMAXTARG
value|0x00ff
comment|/* maximum targets */
define|#
directive|define
name|CFBOOTLUN
value|0x0f00
comment|/* Lun to boot from */
define|#
directive|define
name|CFBOOTID
value|0xf000
comment|/* Target to boot from */
name|uint16_t
name|res_1
index|[
literal|10
index|]
decl_stmt|;
comment|/* words 20-29 */
name|uint16_t
name|signature
decl_stmt|;
comment|/* Signature == 0x250 */
define|#
directive|define
name|CFSIGNATURE
value|0x250
name|uint16_t
name|checksum
decl_stmt|;
comment|/* word 31 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_syncrate
block|{
name|u_int
name|sxfr_u2
decl_stmt|;
name|u_int
name|sxfr
decl_stmt|;
comment|/* Rates in Ultra mode have bit 8 of sxfr set */
define|#
directive|define
name|ULTRA_SXFR
value|0x100
define|#
directive|define
name|ST_SXFR
value|0x010
comment|/* Rate Single Transition Only */
define|#
directive|define
name|DT_SXFR
value|0x040
comment|/* Rate Double Transition Only */
name|uint8_t
name|period
decl_stmt|;
comment|/* Period to send to SCSI target */
name|char
modifier|*
name|rate
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|MSG_TYPE_NONE
init|=
literal|0x00
block|,
name|MSG_TYPE_INITIATOR_MSGOUT
init|=
literal|0x01
block|,
name|MSG_TYPE_INITIATOR_MSGIN
init|=
literal|0x02
block|,
name|MSG_TYPE_TARGET_MSGOUT
init|=
literal|0x03
block|,
name|MSG_TYPE_TARGET_MSGIN
init|=
literal|0x04
block|}
name|ahc_msg_type
typedef|;
end_typedef

begin_struct
struct|struct
name|sg_map_node
block|{
name|bus_dmamap_t
name|sg_dmamap
decl_stmt|;
name|bus_addr_t
name|sg_physaddr
decl_stmt|;
name|struct
name|ahc_dma_seg
modifier|*
name|sg_vaddr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|sg_map_node
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scb_data
block|{
name|struct
name|hardware_scb
modifier|*
name|hscbs
decl_stmt|;
comment|/* Array of hardware SCBs */
name|struct
name|scb
modifier|*
name|scbarray
decl_stmt|;
comment|/* Array of kernel SCBs */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|free_scbs
expr_stmt|;
comment|/* 					 * Pool of SCBs ready to be assigned 					 * commands to execute. 					 */
name|struct
name|scsi_sense_data
modifier|*
name|sense
decl_stmt|;
comment|/* Per SCB sense data */
comment|/* 	 * "Bus" addresses of our data structures. 	 */
name|bus_dma_tag_t
name|hscb_dmat
decl_stmt|;
comment|/* dmat for our hardware SCB array */
name|bus_dmamap_t
name|hscb_dmamap
decl_stmt|;
name|bus_addr_t
name|hscb_busaddr
decl_stmt|;
name|bus_dma_tag_t
name|sense_dmat
decl_stmt|;
name|bus_dmamap_t
name|sense_dmamap
decl_stmt|;
name|bus_addr_t
name|sense_busaddr
decl_stmt|;
name|bus_dma_tag_t
name|sg_dmat
decl_stmt|;
comment|/* dmat for our sg segments */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|sg_map_node
argument_list|)
name|sg_maps
expr_stmt|;
name|uint8_t
name|numscbs
decl_stmt|;
name|uint8_t
name|maxhscbs
decl_stmt|;
comment|/* Number of SCBs on the card */
name|uint8_t
name|init_level
decl_stmt|;
comment|/* 					 * How far we've initialized 					 * this structure. 					 */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|scb_tailq
argument_list|,
name|scb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ahc_softc
block|{
name|bus_space_tag_t
name|tag
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* dmat for buffer I/O */
name|struct
name|scb_data
modifier|*
name|scb_data
decl_stmt|;
comment|/* 	 * CCBs that have been sent to the controller 	 */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
expr_stmt|;
comment|/* 	 * Counting lock for deferring the release of additional 	 * untagged transactions from the untagged_queues.  When 	 * the lock is decremented to 0, all queues in the 	 * untagged_queues array are run. 	 */
name|u_int
name|untagged_queue_lock
decl_stmt|;
comment|/* 	 * Per-target queue of untagged-transactions.  The 	 * transaction at the head of the queue is the 	 * currently pending untagged transaction for the 	 * target.  The driver only allows a single untagged 	 * transaction per target. 	 */
name|struct
name|scb_tailq
name|untagged_queues
index|[
literal|16
index|]
decl_stmt|;
comment|/* 	 * Target mode related state kept on a per enabled lun basis. 	 * Targets that are not enabled will have null entries. 	 * As an initiator, we keep one target entry for our initiator 	 * ID to store our sync/wide transfer settings. 	 */
name|struct
name|tmode_tstate
modifier|*
name|enabled_targets
index|[
literal|16
index|]
decl_stmt|;
comment|/* 	 * The black hole device responsible for handling requests for 	 * disabled luns on enabled targets. 	 */
name|struct
name|tmode_lstate
modifier|*
name|black_hole
decl_stmt|;
comment|/* 	 * Device instance currently on the bus awaiting a continue TIO 	 * for a command that was not given the disconnect priveledge. 	 */
name|struct
name|tmode_lstate
modifier|*
name|pending_device
decl_stmt|;
comment|/* 	 * Card characteristics 	 */
name|ahc_chip
name|chip
decl_stmt|;
name|ahc_feature
name|features
decl_stmt|;
name|ahc_bug
name|bugs
decl_stmt|;
name|ahc_flag
name|flags
decl_stmt|;
comment|/* Values to store in the SEQCTL register for pause and unpause */
name|uint8_t
name|unpause
decl_stmt|;
name|uint8_t
name|pause
decl_stmt|;
comment|/* Command Queues */
name|uint8_t
name|qoutfifonext
decl_stmt|;
name|uint8_t
name|qinfifonext
decl_stmt|;
name|uint8_t
modifier|*
name|qoutfifo
decl_stmt|;
name|uint8_t
modifier|*
name|qinfifo
decl_stmt|;
comment|/* 	 * Hooks into the XPT. 	 */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim_b
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path_b
decl_stmt|;
name|int
name|unit
decl_stmt|;
comment|/* Channel Names ('A', 'B', etc.) */
name|char
name|channel
decl_stmt|;
name|char
name|channel_b
decl_stmt|;
comment|/* Initiator Bus ID */
name|uint8_t
name|our_id
decl_stmt|;
name|uint8_t
name|our_id_b
decl_stmt|;
comment|/* Targets that need negotiation messages */
name|uint16_t
name|targ_msg_req
decl_stmt|;
comment|/* 	 * PCI error detection and data for running the 	 * PCI error interrupt handler. 	 */
name|int
name|unsolicited_ints
decl_stmt|;
name|device_t
name|device
decl_stmt|;
comment|/* 	 * Target incoming command FIFO. 	 */
name|struct
name|target_cmd
modifier|*
name|targetcmds
decl_stmt|;
name|uint8_t
name|tqinfifonext
decl_stmt|;
comment|/* 	 * Incoming and outgoing message handling. 	 */
name|uint8_t
name|send_msg_perror
decl_stmt|;
name|ahc_msg_type
name|msg_type
decl_stmt|;
name|uint8_t
name|msgout_buf
index|[
literal|8
index|]
decl_stmt|;
comment|/* Message we are sending */
name|uint8_t
name|msgin_buf
index|[
literal|8
index|]
decl_stmt|;
comment|/* Message we are receiving */
name|u_int
name|msgout_len
decl_stmt|;
comment|/* Length of message to send */
name|u_int
name|msgout_index
decl_stmt|;
comment|/* Current index in msgout */
name|u_int
name|msgin_index
decl_stmt|;
comment|/* Current index in msgin */
name|int
name|regs_res_type
decl_stmt|;
name|int
name|regs_res_id
decl_stmt|;
name|int
name|irq_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|shared_data_dmat
decl_stmt|;
name|bus_dmamap_t
name|shared_data_dmamap
decl_stmt|;
name|bus_addr_t
name|shared_data_busaddr
decl_stmt|;
name|bus_addr_t
name|dma_bug_buf
decl_stmt|;
comment|/* Number of enabled target mode device on this card */
name|u_int
name|enabled_luns
decl_stmt|;
comment|/* Initialization level of this data structure */
name|u_int
name|init_level
decl_stmt|;
name|uint16_t
name|user_discenable
decl_stmt|;
comment|/* Disconnection allowed  */
name|uint16_t
name|user_tagenable
decl_stmt|;
comment|/* Tagged Queuing allowed */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|full_ahc_softc
block|{
name|struct
name|ahc_softc
name|softc
decl_stmt|;
name|struct
name|scb_data
name|scb_data_storage
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* #define AHC_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_DEBUG
end_ifdef

begin_comment
comment|/* Different debugging levels used when AHC_DEBUG is defined */
end_comment

begin_define
define|#
directive|define
name|AHC_SHOWMISC
value|0x0001
end_define

begin_define
define|#
directive|define
name|AHC_SHOWCMDS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AHC_SHOWSCBS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AHC_SHOWABORTS
value|0x0008
end_define

begin_define
define|#
directive|define
name|AHC_SHOWSENSE
value|0x0010
end_define

begin_define
define|#
directive|define
name|AHC_SHOWSCBCNT
value|0x0020
end_define

begin_decl_stmt
specifier|extern
name|int
name|ahc_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialized in i386/scsi/aic7xxx.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ahc_inb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((ahc)->tag, (ahc)->bsh, port)
end_define

begin_define
define|#
directive|define
name|ahc_outb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((ahc)->tag, (ahc)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|ahc_outsb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1((ahc)->tag, (ahc)->bsh, port, valp, count)
end_define

begin_define
define|#
directive|define
name|ahc_insb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((ahc)->tag, (ahc)->bsh, port, valp, count)
end_define

begin_function_decl
name|char
modifier|*
name|ahc_name
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_init_probe_config
parameter_list|(
name|struct
name|ahc_probe_config
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ahc_softc
modifier|*
name|ahc_alloc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|regs
parameter_list|,
name|int
name|regs_type
parameter_list|,
name|int
name|regs_id
parameter_list|,
name|bus_dma_tag_t
name|parent_dmat
parameter_list|,
name|struct
name|ahc_probe_config
modifier|*
name|config
parameter_list|,
name|struct
name|scb_data
modifier|*
name|scb_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_reset
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_free
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_probe_scbs
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_init
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_attach
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|sequencer_paused
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_pause_bug_fix
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|pause_sequencer
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|unpause_sequencer
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_pause_bug_fix
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
comment|/* 	 * Clear the CIOBUS stretch signal by reading a register that will 	 * set this signal and deassert it.  Without this workaround, if 	 * the chip is paused, by an interrupt or manual pause, while 	 * accessing scb ram, then accesses to certain registers will hang 	 * the system (infinite pci retries). 	 */
if|if
condition|(
operator|(
name|ahc
operator|->
name|features
operator|&
name|AHC_ULTRA2
operator|)
operator|!=
literal|0
condition|)
operator|(
name|void
operator|)
name|ahc_inb
argument_list|(
name|ahc
argument_list|,
name|CCSCBCTL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|sequencer_paused
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ahc_inb
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|)
operator|&
name|PAUSE
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pause_sequencer
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
name|ahc_outb
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|,
name|ahc
operator|->
name|pause
argument_list|)
expr_stmt|;
comment|/* 	 * Since the sequencer can disable pausing in a critical section, we 	 * must loop until it actually stops. 	 */
while|while
condition|(
name|sequencer_paused
argument_list|(
name|ahc
argument_list|)
operator|==
literal|0
condition|)
empty_stmt|;
name|ahc_pause_bug_fix
argument_list|(
name|ahc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|unpause_sequencer
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
if|if
condition|(
operator|(
name|ahc_inb
argument_list|(
name|ahc
argument_list|,
name|INTSTAT
argument_list|)
operator|&
operator|(
name|SCSIINT
operator||
name|SEQINT
operator||
name|BRKADRINT
operator|)
operator|)
operator|==
literal|0
condition|)
name|ahc_outb
argument_list|(
name|ahc
argument_list|,
name|HCNTRL
argument_list|,
name|ahc
operator|->
name|unpause
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC7XXX_H_ */
end_comment

end_unit

