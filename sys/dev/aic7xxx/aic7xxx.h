begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the generic driver for the aic7xxx based adaptec  * SCSI controllers.  This is used to implement product specific  * probe and attach routines.  *  * Copyright (c) 1994, 1995, 1996, 1997, 1998, 1999 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Where this Software is combined with software released under the terms of   * the GNU Public License ("GPL") and the terms of the GPL would require the   * combined work to also be released under the terms of the GPL, the terms  * and conditions of this License will apply in addition to those of the  * GPL with the exception of any terms or conditions of this License that  * conflict with, or are expressly prohibited by, the GPL.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: aic7xxx.h,v 1.10 1999/05/22 22:04:10 gibbs Exp $  */
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
file|"ahc.h"
end_include

begin_comment
comment|/* for NAHC from config */
end_comment

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
comment|/*  * The number of dma segments supported.  The current implementation limits  * us to 255 S/G entries (this may change to be unlimited at some point).  * To reduce the driver's memory consumption, we further limit the number  * supported to be sufficient to handle the largest mapping supported by  * the kernel, MAXPHYS.  Assuming the transfer is as fragmented as possible  * and unaligned, this turns out to be the number of paged sized transfers  * in MAXPHYS plus an extra element to handle any unaligned residual.  */
end_comment

begin_define
define|#
directive|define
name|AHC_NSEG
value|(MIN(btoc(MAXPHYS) + 1, 255))
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

begin_struct
struct|struct
name|ahc_dma_seg
block|{
name|u_int32_t
name|addr
decl_stmt|;
name|u_int32_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

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
name|AHC_AIC7860
init|=
literal|0x0003
block|,
name|AHC_AIC7870
init|=
literal|0x0004
block|,
name|AHC_AIC7880
init|=
literal|0x0005
block|,
name|AHC_AIC7890
init|=
literal|0x0006
block|,
name|AHC_AIC7895
init|=
literal|0x0007
block|,
name|AHC_AIC7896
init|=
literal|0x0008
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
block|}
name|ahc_chip
typedef|;
end_typedef

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
name|AHC_AIC7770_FE
init|=
name|AHC_FENONE
block|,
name|AHC_AIC7850_FE
init|=
name|AHC_FENONE
operator||
name|AHC_SPIOCAP
block|,
name|AHC_AIC7860_FE
init|=
name|AHC_ULTRA
operator||
name|AHC_SPIOCAP
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
block|,
name|AHC_AIC7895_FE
init|=
name|AHC_MORE_SRAM
operator||
name|AHC_CMD_CHAN
operator||
name|AHC_ULTRA
block|,
name|AHC_AIC7895C_FE
init|=
name|AHC_MORE_SRAM
operator||
name|AHC_CMD_CHAN
operator||
name|AHC_ULTRA
operator||
name|AHC_MULTI_TID
block|,
name|AHC_AIC7896_FE
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
block|}
name|ahc_feature
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
block|}
name|ahc_flag
typedef|;
end_typedef

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
comment|/*  * The driver keeps up to MAX_SCB scb structures per card in memory.  The SCB  * consists of a "hardware SCB" mirroring the fields availible on the card  * and additional information the kernel stores for each transaction.  */
end_comment

begin_struct
struct|struct
name|hardware_scb
block|{
comment|/*0*/
name|u_int8_t
name|control
decl_stmt|;
comment|/*1*/
name|u_int8_t
name|tcl
decl_stmt|;
comment|/* 4/1/3 bits */
comment|/*2*/
name|u_int8_t
name|status
decl_stmt|;
comment|/*3*/
name|u_int8_t
name|SG_count
decl_stmt|;
comment|/*4*/
name|u_int32_t
name|SG_pointer
decl_stmt|;
comment|/*8*/
name|u_int8_t
name|residual_SG_count
decl_stmt|;
comment|/*9*/
name|u_int8_t
name|residual_data_count
index|[
literal|3
index|]
decl_stmt|;
comment|/*12*/
name|u_int32_t
name|data
decl_stmt|;
comment|/*16*/
name|u_int32_t
name|datalen
decl_stmt|;
comment|/* Really only three bytes, but its 					 * faster to treat it as a long on 					 * a quad boundary. 					 */
comment|/*20*/
name|u_int32_t
name|cmdpointer
decl_stmt|;
comment|/*24*/
name|u_int8_t
name|cmdlen
decl_stmt|;
comment|/*25*/
name|u_int8_t
name|tag
decl_stmt|;
comment|/* Index into our kernel SCB array. 					 * Also used as the tag for tagged I/O 					 */
comment|/*26*/
name|u_int8_t
name|next
decl_stmt|;
comment|/* Used for threading SCBs in the 					 * "Waiting for Selection" and 					 * "Disconnected SCB" lists down 					 * in the sequencer. 					 */
comment|/*27*/
name|u_int8_t
name|scsirate
decl_stmt|;
comment|/* Value for SCSIRATE register */
comment|/*28*/
name|u_int8_t
name|scsioffset
decl_stmt|;
comment|/* Value for SCSIOFFSET register */
comment|/*29*/
name|u_int8_t
name|spare
index|[
literal|3
index|]
decl_stmt|;
comment|/* 					 * Spare space available on 					 * all controller types. 					 */
comment|/*32*/
name|u_int8_t
name|cmdstore
index|[
literal|16
index|]
decl_stmt|;
comment|/* 					 * CDB storage for controllers 					 * supporting 64 byte SCBs. 					 */
comment|/*48*/
name|u_int32_t
name|cmdstore_busaddr
decl_stmt|;
comment|/* 					 * Address of command store for 					 * 32byte SCB adapters 					 */
comment|/*48*/
name|u_int8_t
name|spare_64
index|[
literal|12
index|]
decl_stmt|;
comment|/* 					 * Pad to 64 bytes. 					 */
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
name|SLIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|links
expr_stmt|;
comment|/* for chaining */
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
name|u_int8_t
name|initiator_channel
decl_stmt|;
name|u_int8_t
name|targ_id
decl_stmt|;
comment|/* Target ID we were selected at */
name|u_int8_t
name|identify
decl_stmt|;
comment|/* Identify message */
name|u_int8_t
name|bytes
index|[
literal|21
index|]
decl_stmt|;
name|u_int8_t
name|cmd_valid
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|initiator_id
decl_stmt|;
name|u_int8_t
name|event_type
decl_stmt|;
comment|/* MSG type or EVENT_TYPE_BUS_RESET */
define|#
directive|define
name|EVENT_TYPE_BUS_RESET
value|0xFF
name|u_int8_t
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
name|u_int8_t
name|event_r_idx
decl_stmt|;
name|u_int8_t
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
name|u_int8_t
name|width
decl_stmt|;
name|u_int8_t
name|period
decl_stmt|;
name|u_int8_t
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_initiator_tinfo
block|{
name|u_int8_t
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
literal|8
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
name|u_int16_t
name|ultraenb
decl_stmt|;
comment|/* Using ultra sync rate  */
name|u_int16_t
name|discenable
decl_stmt|;
comment|/* Disconnection allowed  */
name|u_int16_t
name|tagenable
decl_stmt|;
comment|/* Tagged Queuing allowed */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Define the format of the aic7XX0 SEEPROM registers (16 bits).  */
end_comment

begin_struct
struct|struct
name|seeprom_config
block|{
comment|/*  * SCSI ID Configuration Flags  */
name|u_int16_t
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
comment|/*		UNUSED		0x0080	*/
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
name|CFMULTILUN
value|0x0800
comment|/* Probe multiple luns in BIOS scan */
comment|/*		UNUSED		0xf000	*/
comment|/*  * BIOS Control Bits  */
name|u_int16_t
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
comment|/* support removeable drives for boot only */
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
comment|/*		UNUSED		0x0060	*/
define|#
directive|define
name|CFEXTEND
value|0x0080
comment|/* extended translation enabled */
comment|/*		UNUSED		0xff00	*/
comment|/*  * Host Adapter Control Bits  */
name|u_int16_t
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
name|CFRESETB
value|0x0040
comment|/* reset SCSI bus at boot */
define|#
directive|define
name|CFCHNLBPRIMARY
value|0x0100
comment|/* aic7895 probe B channel first */
define|#
directive|define
name|CFSEAUTOTERM
value|0x0400
comment|/* aic7890 Perform SE Auto Termination*/
define|#
directive|define
name|CFLVDSTERM
value|0x0800
comment|/* aic7890 LVD Termination */
comment|/*		UNUSED		0xf080	*/
comment|/*  * Bus Release, Host Adapter ID  */
name|u_int16_t
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
name|u_int16_t
name|max_targets
decl_stmt|;
comment|/* word 19 */
define|#
directive|define
name|CFMAXTARG
value|0x00ff
comment|/* maximum targets */
comment|/*		UNUSED		0xff00	*/
name|u_int16_t
name|res_1
index|[
literal|11
index|]
decl_stmt|;
comment|/* words 20-30 */
name|u_int16_t
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
name|int
name|sxfr_ultra2
decl_stmt|;
name|int
name|sxfr
decl_stmt|;
comment|/* Rates in Ultra mode have bit 8 of sxfr set */
define|#
directive|define
name|ULTRA_SXFR
value|0x100
name|u_int8_t
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
name|u_int8_t
name|numscbs
decl_stmt|;
name|u_int8_t
name|maxhscbs
decl_stmt|;
comment|/* Number of SCBs on the card */
name|u_int8_t
name|init_level
decl_stmt|;
comment|/* 					 * How far we've initialized 					 * this structure. 					 */
block|}
struct|;
end_struct

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
comment|/* 	 * CCBs that have been send to the controller 	 */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|pending_ccbs
expr_stmt|;
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
name|ahc_flag
name|flags
decl_stmt|;
comment|/* Values to store in the SEQCTL register for pause and unpause */
name|u_int8_t
name|unpause
decl_stmt|;
name|u_int8_t
name|pause
decl_stmt|;
comment|/* Command Queues */
name|u_int8_t
name|qoutfifonext
decl_stmt|;
name|u_int8_t
name|qinfifonext
decl_stmt|;
name|u_int8_t
modifier|*
name|qoutfifo
decl_stmt|;
name|u_int8_t
modifier|*
name|qinfifo
decl_stmt|;
comment|/* 	 * 256 byte array storing the SCBID of outstanding 	 * untagged SCBs indexed by TCL. 	 */
name|u_int8_t
modifier|*
name|untagged_scbs
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
name|u_int8_t
name|our_id
decl_stmt|;
name|u_int8_t
name|our_id_b
decl_stmt|;
comment|/* Targets that need negotiation messages */
name|u_int16_t
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
name|u_int8_t
name|tqinfifonext
decl_stmt|;
comment|/* 	 * Incoming and outgoing message handling. 	 */
name|u_int8_t
name|send_msg_perror
decl_stmt|;
name|ahc_msg_type
name|msg_type
decl_stmt|;
name|u_int8_t
name|msgout_buf
index|[
literal|8
index|]
decl_stmt|;
comment|/* Message we are sending */
name|u_int8_t
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
comment|/* Number of enabled target mode device on this card */
name|u_int
name|enabled_luns
decl_stmt|;
comment|/* Initialization level of this data structure */
name|u_int
name|init_level
decl_stmt|;
name|u_int16_t
name|user_discenable
decl_stmt|;
comment|/* Disconnection allowed  */
name|u_int16_t
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
name|ahc_chip
name|chip
parameter_list|,
name|ahc_feature
name|features
parameter_list|,
name|ahc_flag
name|flags
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC7XXX_H_ */
end_comment

end_unit

