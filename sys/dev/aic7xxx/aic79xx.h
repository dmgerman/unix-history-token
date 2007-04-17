begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Core definitions and data structures shareable across OS platforms.  *  * Copyright (c) 1994-2002 Justin T. Gibbs.  * Copyright (c) 2000-2002 Adaptec Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/aic7xxx/aic7xxx/aic79xx.h#107 $  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AIC79XX_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIC79XX_H_
end_define

begin_comment
comment|/* Register Definitions */
end_comment

begin_include
include|#
directive|include
file|"aic79xx_reg.h"
end_include

begin_comment
comment|/************************* Forward Declarations *******************************/
end_comment

begin_struct_decl
struct_decl|struct
name|ahd_platform_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scb_platform_data
struct_decl|;
end_struct_decl

begin_comment
comment|/****************************** Useful Macros *********************************/
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

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NUM_ELEMENTS
parameter_list|(
name|array
parameter_list|)
value|(sizeof(array) / sizeof(*array))
end_define

begin_define
define|#
directive|define
name|ALL_CHANNELS
value|'\0'
end_define

begin_define
define|#
directive|define
name|ALL_TARGETS_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|INITIATOR_WILDCARD
value|(~0)
end_define

begin_define
define|#
directive|define
name|SCB_LIST_NULL
value|0xFF00
end_define

begin_define
define|#
directive|define
name|SCB_LIST_NULL_LE
value|(aic_htole16(SCB_LIST_NULL))
end_define

begin_define
define|#
directive|define
name|QOUTFIFO_ENTRY_VALID
value|0x80
end_define

begin_define
define|#
directive|define
name|SCBID_IS_NULL
parameter_list|(
name|scbid
parameter_list|)
value|(((scbid)& 0xFF00 ) == SCB_LIST_NULL)
end_define

begin_define
define|#
directive|define
name|SCSIID_TARGET
parameter_list|(
name|ahd
parameter_list|,
name|scsiid
parameter_list|)
define|\
value|(((scsiid)& TID)>> TID_SHIFT)
end_define

begin_define
define|#
directive|define
name|SCSIID_OUR_ID
parameter_list|(
name|scsiid
parameter_list|)
define|\
value|((scsiid)& OID)
end_define

begin_define
define|#
directive|define
name|SCSIID_CHANNEL
parameter_list|(
name|ahd
parameter_list|,
name|scsiid
parameter_list|)
value|('A')
end_define

begin_define
define|#
directive|define
name|SCB_IS_SCSIBUS_B
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|SCB_GET_OUR_ID
parameter_list|(
name|scb
parameter_list|)
define|\
value|SCSIID_OUR_ID((scb)->hscb->scsiid)
end_define

begin_define
define|#
directive|define
name|SCB_GET_TARGET
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
define|\
value|SCSIID_TARGET((ahd), (scb)->hscb->scsiid)
end_define

begin_define
define|#
directive|define
name|SCB_GET_CHANNEL
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
define|\
value|SCSIID_CHANNEL(ahd, (scb)->hscb->scsiid)
end_define

begin_define
define|#
directive|define
name|SCB_GET_LUN
parameter_list|(
name|scb
parameter_list|)
define|\
value|((scb)->hscb->lun)
end_define

begin_define
define|#
directive|define
name|SCB_GET_TARGET_OFFSET
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
define|\
value|SCB_GET_TARGET(ahd, scb)
end_define

begin_define
define|#
directive|define
name|SCB_GET_TARGET_MASK
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
define|\
value|(0x01<< (SCB_GET_TARGET_OFFSET(ahd, scb)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AHD_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SCB_IS_SILENT
parameter_list|(
name|scb
parameter_list|)
define|\
value|((ahd_debug& AHD_SHOW_MASKED_ERRORS) == 0		\&& (((scb)->flags& SCB_SILENT) != 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCB_IS_SILENT
parameter_list|(
name|scb
parameter_list|)
define|\
value|(((scb)->flags& SCB_SILENT) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * TCLs have the following format: TTTTLLLLLLLL  */
end_comment

begin_define
define|#
directive|define
name|TCL_TARGET_OFFSET
parameter_list|(
name|tcl
parameter_list|)
define|\
value|((((tcl)>> 4)& TID)>> 4)
end_define

begin_define
define|#
directive|define
name|TCL_LUN
parameter_list|(
name|tcl
parameter_list|)
define|\
value|(tcl& (AHD_NUM_LUNS - 1))
end_define

begin_define
define|#
directive|define
name|BUILD_TCL
parameter_list|(
name|scsiid
parameter_list|,
name|lun
parameter_list|)
define|\
value|((lun) | (((scsiid)& TID)<< 4))
end_define

begin_define
define|#
directive|define
name|BUILD_TCL_RAW
parameter_list|(
name|target
parameter_list|,
name|channel
parameter_list|,
name|lun
parameter_list|)
define|\
value|((lun) | ((target)<< 8))
end_define

begin_define
define|#
directive|define
name|SCB_GET_TAG
parameter_list|(
name|scb
parameter_list|)
define|\
value|aic_le16toh(scb->hscb->tag)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|AHD_TARGET_MODE
end_ifndef

begin_undef
undef|#
directive|undef
name|AHD_TMODE_ENABLE
end_undef

begin_define
define|#
directive|define
name|AHD_TMODE_ENABLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AHD_BUILD_COL_IDX
parameter_list|(
name|target
parameter_list|,
name|lun
parameter_list|)
define|\
value|(((lun)<< 4) | target)
end_define

begin_define
define|#
directive|define
name|AHD_GET_SCB_COL_IDX
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
define|\
value|((SCB_GET_LUN(scb)<< 4) | SCB_GET_TARGET(ahd, scb))
end_define

begin_define
define|#
directive|define
name|AHD_SET_SCB_COL_IDX
parameter_list|(
name|scb
parameter_list|,
name|col_idx
parameter_list|)
define|\
value|do {									\ 	(scb)->hscb->scsiid = ((col_idx)<< TID_SHIFT)& TID;		\ 	(scb)->hscb->lun = ((col_idx)>> 4)& (AHD_NUM_LUNS_NONPKT-1);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|AHD_COPY_SCB_COL_IDX
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|do {								\ 	dst->hscb->scsiid = src->hscb->scsiid;			\ 	dst->hscb->lun = src->hscb->lun;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AHD_NEVER_COL_IDX
value|0xFFFF
end_define

begin_comment
comment|/**************************** Driver Constants ********************************/
end_comment

begin_comment
comment|/*  * The maximum number of supported targets.  */
end_comment

begin_define
define|#
directive|define
name|AHD_NUM_TARGETS
value|16
end_define

begin_comment
comment|/*  * The maximum number of supported luns.  * The identify message only supports 64 luns in non-packetized transfers.  * You can have 2^64 luns when information unit transfers are enabled,  * but until we see a need to support that many, we support 256.  */
end_comment

begin_define
define|#
directive|define
name|AHD_NUM_LUNS_NONPKT
value|64
end_define

begin_define
define|#
directive|define
name|AHD_NUM_LUNS
value|256
end_define

begin_comment
comment|/*  * The maximum transfer per S/G segment.  */
end_comment

begin_define
define|#
directive|define
name|AHD_MAXTRANSFER_SIZE
value|0x00ffffff
end_define

begin_comment
comment|/* limited by 24bit counter */
end_comment

begin_comment
comment|/*  * The maximum amount of SCB storage in hardware on a controller.  * This value represents an upper bound.  Due to software design,  * we may not be able to use this number.  */
end_comment

begin_define
define|#
directive|define
name|AHD_SCB_MAX
value|512
end_define

begin_comment
comment|/*  * The maximum number of concurrent transactions supported per driver instance.  * Sequencer Control Blocks (SCBs) store per-transaction information.  */
end_comment

begin_define
define|#
directive|define
name|AHD_MAX_QUEUE
value|AHD_SCB_MAX
end_define

begin_comment
comment|/*  * Define the size of our QIN and QOUT FIFOs.  They must be a power of 2  * in size and accommodate as many transactions as can be queued concurrently.  */
end_comment

begin_define
define|#
directive|define
name|AHD_QIN_SIZE
value|AHD_MAX_QUEUE
end_define

begin_define
define|#
directive|define
name|AHD_QOUT_SIZE
value|AHD_MAX_QUEUE
end_define

begin_define
define|#
directive|define
name|AHD_QIN_WRAP
parameter_list|(
name|x
parameter_list|)
value|((x)& (AHD_QIN_SIZE-1))
end_define

begin_comment
comment|/*  * The maximum amount of SCB storage we allocate in host memory.  */
end_comment

begin_define
define|#
directive|define
name|AHD_SCB_MAX_ALLOC
value|AHD_MAX_QUEUE
end_define

begin_comment
comment|/*  * Ring Buffer of incoming target commands.  * We allocate 256 to simplify the logic in the sequencer  * by using the natural wrap point of an 8bit counter.  */
end_comment

begin_define
define|#
directive|define
name|AHD_TMODE_CMDS
value|256
end_define

begin_comment
comment|/* Reset line assertion time in us */
end_comment

begin_define
define|#
directive|define
name|AHD_BUSRESET_DELAY
value|25
end_define

begin_comment
comment|/******************* Chip Characteristics/Operating Settings  *****************/
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|ahd_attach_to_HostRAID_controllers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Chip Type  * The chip order is from least sophisticated to most sophisticated.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_NONE
init|=
literal|0x0000
block|,
name|AHD_CHIPID_MASK
init|=
literal|0x00FF
block|,
name|AHD_AIC7901
init|=
literal|0x0001
block|,
name|AHD_AIC7902
init|=
literal|0x0002
block|,
name|AHD_AIC7901A
init|=
literal|0x0003
block|,
name|AHD_PCI
init|=
literal|0x0100
block|,
comment|/* Bus type PCI */
name|AHD_PCIX
init|=
literal|0x0200
block|,
comment|/* Bus type PCIX */
name|AHD_BUS_MASK
init|=
literal|0x0F00
block|}
name|ahd_chip
typedef|;
end_typedef

begin_comment
comment|/*  * Features available in each chip type.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_FENONE
init|=
literal|0x00000
block|,
name|AHD_WIDE
init|=
literal|0x00001
block|,
comment|/* Wide Channel */
name|AHD_MULTI_FUNC
init|=
literal|0x00100
block|,
comment|/* Multi-Function/Channel Device */
name|AHD_TARGETMODE
init|=
literal|0x01000
block|,
comment|/* Has tested target mode support */
name|AHD_MULTIROLE
init|=
literal|0x02000
block|,
comment|/* Space for two roles at a time */
name|AHD_RTI
init|=
literal|0x04000
block|,
comment|/* Retained Training Support */
name|AHD_NEW_IOCELL_OPTS
init|=
literal|0x08000
block|,
comment|/* More Signal knobs in the IOCELL */
name|AHD_NEW_DFCNTRL_OPTS
init|=
literal|0x10000
block|,
comment|/* SCSIENWRDIS bit */
name|AHD_FAST_CDB_DELIVERY
init|=
literal|0x20000
block|,
comment|/* CDB acks released to Output Sync */
name|AHD_REMOVABLE
init|=
literal|0x00000
block|,
comment|/* Hot-Swap supported - None so far*/
name|AHD_AIC7901_FE
init|=
name|AHD_FENONE
block|,
name|AHD_AIC7901A_FE
init|=
name|AHD_FENONE
block|,
name|AHD_AIC7902_FE
init|=
name|AHD_MULTI_FUNC
block|}
name|ahd_feature
typedef|;
end_typedef

begin_comment
comment|/*  * Bugs in the silicon that we work around in software.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_BUGNONE
init|=
literal|0x0000
block|,
comment|/* 	 * Rev A hardware fails to update LAST/CURR/NEXTSCB 	 * correctly in certain packetized selection cases. 	 */
name|AHD_SENT_SCB_UPDATE_BUG
init|=
literal|0x0001
block|,
comment|/* The wrong SCB is accessed to check the abort pending bit. */
name|AHD_ABORT_LQI_BUG
init|=
literal|0x0002
block|,
comment|/* Packetized bitbucket crosses packet boundaries. */
name|AHD_PKT_BITBUCKET_BUG
init|=
literal|0x0004
block|,
comment|/* The selection timer runs twice as long as its setting. */
name|AHD_LONG_SETIMO_BUG
init|=
literal|0x0008
block|,
comment|/* The Non-LQ CRC error status is delayed until phase change. */
name|AHD_NLQICRC_DELAYED_BUG
init|=
literal|0x0010
block|,
comment|/* The chip must be reset for all outgoing bus resets.  */
name|AHD_SCSIRST_BUG
init|=
literal|0x0020
block|,
comment|/* Some PCIX fields must be saved and restored across chip reset. */
name|AHD_PCIX_CHIPRST_BUG
init|=
literal|0x0040
block|,
comment|/* MMAPIO is not functional in PCI-X mode.  */
name|AHD_PCIX_MMAPIO_BUG
init|=
literal|0x0080
block|,
comment|/* Reads to SCBRAM fail to reset the discard timer. */
name|AHD_PCIX_SCBRAM_RD_BUG
init|=
literal|0x0100
block|,
comment|/* Bug workarounds that can be disabled on non-PCIX busses. */
name|AHD_PCIX_BUG_MASK
init|=
name|AHD_PCIX_CHIPRST_BUG
operator||
name|AHD_PCIX_MMAPIO_BUG
operator||
name|AHD_PCIX_SCBRAM_RD_BUG
block|,
comment|/* 	 * LQOSTOP0 status set even for forced selections with ATN 	 * to perform non-packetized message delivery. 	 */
name|AHD_LQO_ATNO_BUG
init|=
literal|0x0200
block|,
comment|/* FIFO auto-flush does not always trigger.  */
name|AHD_AUTOFLUSH_BUG
init|=
literal|0x0400
block|,
comment|/* The CLRLQO registers are not self-clearing. */
name|AHD_CLRLQO_AUTOCLR_BUG
init|=
literal|0x0800
block|,
comment|/* The PACKETIZED status bit refers to the previous connection. */
name|AHD_PKTIZED_STATUS_BUG
init|=
literal|0x1000
block|,
comment|/* "Short Luns" are not placed into outgoing LQ packets correctly. */
name|AHD_PKT_LUN_BUG
init|=
literal|0x2000
block|,
comment|/* 	 * Only the FIFO allocated to the non-packetized connection may 	 * be in use during a non-packetzied connection. 	 */
name|AHD_NONPACKFIFO_BUG
init|=
literal|0x4000
block|,
comment|/* 	 * Writing to a DFF SCBPTR register may fail if concurent with 	 * a hardware write to the other DFF SCBPTR register.  This is 	 * not currently a concern in our sequencer since all chips with 	 * this bug have the AHD_NONPACKFIFO_BUG and all writes of concern 	 * occur in non-packetized connections. 	 */
name|AHD_MDFF_WSCBPTR_BUG
init|=
literal|0x8000
block|,
comment|/* SGHADDR updates are slow. */
name|AHD_REG_SLOW_SETTLE_BUG
init|=
literal|0x10000
block|,
comment|/* 	 * Changing the MODE_PTR coincident with an interrupt that 	 * switches to a different mode will cause the interrupt to 	 * be in the mode written outside of interrupt context. 	 */
name|AHD_SET_MODE_BUG
init|=
literal|0x20000
block|,
comment|/* Non-packetized busfree revision does not work. */
name|AHD_BUSFREEREV_BUG
init|=
literal|0x40000
block|,
comment|/* 	 * Paced transfers are indicated with a non-standard PPR 	 * option bit in the neg table, 160MHz is indicated by 	 * sync factor 0x7, and the offset if off by a factor of 2. 	 */
name|AHD_PACED_NEGTABLE_BUG
init|=
literal|0x80000
block|,
comment|/* LQOOVERRUN false positives. */
name|AHD_LQOOVERRUN_BUG
init|=
literal|0x100000
block|,
comment|/* 	 * Controller write to INTSTAT will lose to a host 	 * write to CLRINT. 	 */
name|AHD_INTCOLLISION_BUG
init|=
literal|0x200000
block|,
comment|/* 	 * The GEM318 violates the SCSI spec by not waiting 	 * the mandated bus settle delay between phase changes 	 * in some situations.  Some aic79xx chip revs. are more 	 * strict in this regard and will treat REQ assertions 	 * that fall within the bus settle delay window as 	 * glitches.  This flag tells the firmware to tolerate 	 * early REQ assertions. 	 */
name|AHD_EARLY_REQ_BUG
init|=
literal|0x400000
block|,
comment|/* 	 * The LED does not stay on long enough in packetized modes. 	 */
name|AHD_FAINT_LED_BUG
init|=
literal|0x800000
block|}
name|ahd_bug
typedef|;
end_typedef

begin_comment
comment|/*  * Configuration specific settings.  * The driver determines these settings by probing the  * chip/controller's configuration.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_FNONE
init|=
literal|0x00000
block|,
name|AHD_BOOT_CHANNEL
init|=
literal|0x00001
block|,
comment|/* We were set as the boot channel. */
name|AHD_USEDEFAULTS
init|=
literal|0x00004
block|,
comment|/* 					 * For cards without an seeprom 					 * or a BIOS to initialize the chip's 					 * SRAM, we use the default target 					 * settings. 					 */
name|AHD_SEQUENCER_DEBUG
init|=
literal|0x00008
block|,
name|AHD_RESET_BUS_A
init|=
literal|0x00010
block|,
name|AHD_EXTENDED_TRANS_A
init|=
literal|0x00020
block|,
name|AHD_TERM_ENB_A
init|=
literal|0x00040
block|,
name|AHD_SPCHK_ENB_A
init|=
literal|0x00080
block|,
name|AHD_STPWLEVEL_A
init|=
literal|0x00100
block|,
name|AHD_INITIATORROLE
init|=
literal|0x00200
block|,
comment|/* 					 * Allow initiator operations on 					 * this controller. 					 */
name|AHD_TARGETROLE
init|=
literal|0x00400
block|,
comment|/* 					 * Allow target operations on this 					 * controller. 					 */
name|AHD_RESOURCE_SHORTAGE
init|=
literal|0x00800
block|,
name|AHD_TQINFIFO_BLOCKED
init|=
literal|0x01000
block|,
comment|/* Blocked waiting for ATIOs */
name|AHD_INT50_SPEEDFLEX
init|=
literal|0x02000
block|,
comment|/* 					 * Internal 50pin connector 					 * sits behind an aic3860 					 */
name|AHD_BIOS_ENABLED
init|=
literal|0x04000
block|,
name|AHD_ALL_INTERRUPTS
init|=
literal|0x08000
block|,
name|AHD_39BIT_ADDRESSING
init|=
literal|0x10000
block|,
comment|/* Use 39 bit addressing scheme. */
name|AHD_64BIT_ADDRESSING
init|=
literal|0x20000
block|,
comment|/* Use 64 bit addressing scheme. */
name|AHD_CURRENT_SENSING
init|=
literal|0x40000
block|,
name|AHD_SCB_CONFIG_USED
init|=
literal|0x80000
block|,
comment|/* No SEEPROM but SCB had info. */
name|AHD_HP_BOARD
init|=
literal|0x100000
block|,
name|AHD_RESET_POLL_ACTIVE
init|=
literal|0x200000
block|,
name|AHD_UPDATE_PEND_CMDS
init|=
literal|0x400000
block|,
name|AHD_RUNNING_QOUTFIFO
init|=
literal|0x800000
block|,
name|AHD_HAD_FIRST_SEL
init|=
literal|0x1000000
block|,
name|AHD_SHUTDOWN_RECOVERY
init|=
literal|0x2000000
block|,
comment|/* Terminate recovery thread. */
name|AHD_HOSTRAID_BOARD
init|=
literal|0x4000000
block|}
name|ahd_flag
typedef|;
end_typedef

begin_comment
comment|/************************* Hardware  SCB Definition ***************************/
end_comment

begin_comment
comment|/*  * The driver keeps up to MAX_SCB scb structures per card in memory.  The SCB  * consists of a "hardware SCB" mirroring the fields available on the card  * and additional information the kernel stores for each transaction.  *  * To minimize space utilization, a portion of the hardware scb stores  * different data during different portions of a SCSI transaction.  * As initialized by the host driver for the initiator role, this area  * contains the SCSI cdb (or a pointer to the  cdb) to be executed.  After  * the cdb has been presented to the target, this area serves to store  * residual transfer information and the SCSI status byte.  * For the target role, the contents of this area do not change, but  * still serve a different purpose than for the initiator role.  See  * struct target_data for details.  */
end_comment

begin_comment
comment|/*  * Status information embedded in the shared poriton of  * an SCB after passing the cdb to the target.  The kernel  * driver will only read this data for transactions that  * complete abnormally.  */
end_comment

begin_struct
struct|struct
name|initiator_status
block|{
name|uint32_t
name|residual_datacnt
decl_stmt|;
comment|/* Residual in the current S/G seg */
name|uint32_t
name|residual_sgptr
decl_stmt|;
comment|/* The next S/G for this transfer */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* Standard SCSI status byte */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|target_status
block|{
name|uint32_t
name|residual_datacnt
decl_stmt|;
comment|/* Residual in the current S/G seg */
name|uint32_t
name|residual_sgptr
decl_stmt|;
comment|/* The next S/G for this transfer */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* SCSI status to give to initiator */
name|uint8_t
name|target_phases
decl_stmt|;
comment|/* Bitmap of phases to execute */
name|uint8_t
name|data_phase
decl_stmt|;
comment|/* Data-In or Data-Out */
name|uint8_t
name|initiator_tag
decl_stmt|;
comment|/* Initiator's transaction tag */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initiator mode SCB shared data area.  * If the embedded CDB is 12 bytes or less, we embed  * the sense buffer address in the SCB.  This allows  * us to retrieve sense information without interrupting  * the host in packetized mode.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|sense_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_CDB_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MAX_CDB_LEN_WITH_SENSE_ADDR
value|(MAX_CDB_LEN - sizeof(sense_addr_t))
end_define

begin_union
union|union
name|initiator_data
block|{
struct|struct
block|{
name|uint64_t
name|cdbptr
decl_stmt|;
name|uint8_t
name|cdblen
decl_stmt|;
block|}
name|cdb_from_host
struct|;
name|uint8_t
name|cdb
index|[
name|MAX_CDB_LEN
index|]
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|cdb
index|[
name|MAX_CDB_LEN_WITH_SENSE_ADDR
index|]
decl_stmt|;
name|sense_addr_t
name|sense_addr
decl_stmt|;
block|}
name|cdb_plus_saddr
struct|;
block|}
union|;
end_union

begin_comment
comment|/*  * Target mode version of the shared data SCB segment.  */
end_comment

begin_struct
struct|struct
name|target_data
block|{
name|uint32_t
name|spare
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* SCSI status to give to initiator */
name|uint8_t
name|target_phases
decl_stmt|;
comment|/* Bitmap of phases to execute */
name|uint8_t
name|data_phase
decl_stmt|;
comment|/* Data-In or Data-Out */
name|uint8_t
name|initiator_tag
decl_stmt|;
comment|/* Initiator's transaction tag */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hardware_scb
block|{
comment|/*0*/
union|union
block|{
name|union
name|initiator_data
name|idata
decl_stmt|;
name|struct
name|target_data
name|tdata
decl_stmt|;
name|struct
name|initiator_status
name|istatus
decl_stmt|;
name|struct
name|target_status
name|tstatus
decl_stmt|;
block|}
name|shared_data
union|;
comment|/*  * A word about residuals.  * The scb is presented to the sequencer with the dataptr and datacnt  * fields initialized to the contents of the first S/G element to  * transfer.  The sgptr field is initialized to the bus address for  * the S/G element that follows the first in the in core S/G array  * or'ed with the SG_FULL_RESID flag.  Sgptr may point to an invalid  * S/G entry for this transfer (single S/G element transfer with the  * first elements address and length preloaded in the dataptr/datacnt  * fields).  If no transfer is to occur, sgptr is set to SG_LIST_NULL.  * The SG_FULL_RESID flag ensures that the residual will be correctly  * noted even if no data transfers occur.  Once the data phase is entered,  * the residual sgptr and datacnt are loaded from the sgptr and the  * datacnt fields.  After each S/G element's dataptr and length are  * loaded into the hardware, the residual sgptr is advanced.  After  * each S/G element is expired, its datacnt field is checked to see  * if the LAST_SEG flag is set.  If so, SG_LIST_NULL is set in the  * residual sg ptr and the transfer is considered complete.  If the  * sequencer determines that there is a residual in the tranfer, or  * there is non-zero status, it will set the SG_STATUS_VALID flag in  * sgptr and dma the scb back into host memory.  To sumarize:  *  * Sequencer:  *	o A residual has occurred if SG_FULL_RESID is set in sgptr,  *	  or residual_sgptr does not have SG_LIST_NULL set.  *  *	o We are transfering the last segment if residual_datacnt has  *	  the SG_LAST_SEG flag set.  *  * Host:  *	o A residual can only have occurred if a completed scb has the  *	  SG_STATUS_VALID flag set.  Inspection of the SCSI status field,  *	  the residual_datacnt, and the residual_sgptr field will tell  *	  for sure.  *  *	o residual_sgptr and sgptr refer to the "next" sg entry  *	  and so may point beyond the last valid sg entry for the  *	  transfer.  */
define|#
directive|define
name|SG_PTR_MASK
value|0xFFFFFFF8
comment|/*16*/
name|uint16_t
name|tag
decl_stmt|;
comment|/* Reused by Sequencer. */
comment|/*18*/
name|uint8_t
name|control
decl_stmt|;
comment|/* See SCB_CONTROL in aic79xx.reg for details */
comment|/*19*/
name|uint8_t
name|scsiid
decl_stmt|;
comment|/* 				 * Selection out Id 				 * Our Id (bits 0-3) Their ID (bits 4-7) 				 */
comment|/*20*/
name|uint8_t
name|lun
decl_stmt|;
comment|/*21*/
name|uint8_t
name|task_attribute
decl_stmt|;
comment|/*22*/
name|uint8_t
name|cdb_len
decl_stmt|;
comment|/*23*/
name|uint8_t
name|task_management
decl_stmt|;
comment|/*24*/
name|uint64_t
name|dataptr
decl_stmt|;
comment|/*32*/
name|uint32_t
name|datacnt
decl_stmt|;
comment|/* Byte 3 is spare. */
comment|/*36*/
name|uint32_t
name|sgptr
decl_stmt|;
comment|/*40*/
name|uint32_t
name|hscb_busaddr
decl_stmt|;
comment|/*44*/
name|uint32_t
name|next_hscb_busaddr
decl_stmt|;
comment|/********** Long lun field only downloaded for full 8 byte lun support ********/
comment|/*48*/
name|uint8_t
name|pkt_long_lun
index|[
literal|8
index|]
decl_stmt|;
comment|/******* Fields below are not Downloaded (Sequencer may use for scratch) ******/
comment|/*56*/
name|uint8_t
name|spare
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/************************ Kernel SCB Definitions ******************************/
end_comment

begin_comment
comment|/*  * Some fields of the SCB are OS dependent.  Here we collect the  * definitions for elements that all OS platforms need to include  * in there SCB definition.  */
end_comment

begin_comment
comment|/*  * Definition of a scatter/gather element as transfered to the controller.  * The aic7xxx chips only support a 24bit length.  We use the top byte of  * the length to store additional address bits and a flag to indicate  * that a given segment terminates the transfer.  This gives us an  * addressable range of 512GB on machines with 64bit PCI or with chips  * that can support dual address cycles on 32bit PCI busses.  */
end_comment

begin_struct
struct|struct
name|ahd_dma_seg
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
define|#
directive|define
name|AHD_DMA_LAST_SEG
value|0x80000000
define|#
directive|define
name|AHD_SG_HIGH_ADDR_MASK
value|0x7F000000
define|#
directive|define
name|AHD_SG_LEN_MASK
value|0x00FFFFFF
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahd_dma64_seg
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|map_node
block|{
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|bus_addr_t
name|busaddr
decl_stmt|;
name|uint8_t
modifier|*
name|vaddr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|map_node
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The current state of this SCB.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SCB_FLAG_NONE
init|=
literal|0x00000
block|,
name|SCB_TRANSMISSION_ERROR
init|=
literal|0x00001
block|,
comment|/* 					   * We detected a parity or CRC 					   * error that has effected the 					   * payload of the command.  This 					   * flag is checked when normal 					   * status is returned to catch 					   * the case of a target not 					   * responding to our attempt 					   * to report the error. 					   */
name|SCB_OTHERTCL_TIMEOUT
init|=
literal|0x00002
block|,
comment|/* 					   * Another device was active 					   * during the first timeout for 					   * this SCB so we gave ourselves 					   * an additional timeout period 					   * in case it was hogging the 					   * bus. 				           */
name|SCB_DEVICE_RESET
init|=
literal|0x00004
block|,
name|SCB_SENSE
init|=
literal|0x00008
block|,
name|SCB_CDB32_PTR
init|=
literal|0x00010
block|,
name|SCB_RECOVERY_SCB
init|=
literal|0x00020
block|,
name|SCB_AUTO_NEGOTIATE
init|=
literal|0x00040
block|,
comment|/* Negotiate to achieve goal. */
name|SCB_NEGOTIATE
init|=
literal|0x00080
block|,
comment|/* Negotiation forced for command. */
name|SCB_ABORT
init|=
literal|0x00100
block|,
name|SCB_ACTIVE
init|=
literal|0x00200
block|,
name|SCB_TARGET_IMMEDIATE
init|=
literal|0x00400
block|,
name|SCB_PACKETIZED
init|=
literal|0x00800
block|,
name|SCB_EXPECT_PPR_BUSFREE
init|=
literal|0x01000
block|,
name|SCB_PKT_SENSE
init|=
literal|0x02000
block|,
name|SCB_CMDPHASE_ABORT
init|=
literal|0x04000
block|,
name|SCB_ON_COL_LIST
init|=
literal|0x08000
block|,
name|SCB_SILENT
init|=
literal|0x10000
block|,
comment|/* 					   * Be quiet about transmission type 					   * errors.  They are expected and we 					   * don't want to upset the user.  This 					   * flag is typically used during DV. 					   */
name|SCB_TIMEDOUT
init|=
literal|0x20000
comment|/* 					  * SCB has timed out and is on the 					  * timedout list. 					  */
block|}
name|scb_flag
typedef|;
end_typedef

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
name|LIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|le
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
union|union
block|{
name|SLIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|sle
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|le
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|scb
argument_list|)
name|tqe
expr_stmt|;
block|}
name|links2
union|;
define|#
directive|define
name|pending_links
value|links2.le
define|#
directive|define
name|collision_links
value|links2.le
name|LIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|timedout_links
expr_stmt|;
name|struct
name|scb
modifier|*
name|col_scb
decl_stmt|;
name|aic_io_ctx_t
name|io_ctx
decl_stmt|;
name|struct
name|ahd_softc
modifier|*
name|ahd_softc
decl_stmt|;
name|scb_flag
name|flags
decl_stmt|;
ifndef|#
directive|ifndef
name|__linux__
name|bus_dmamap_t
name|dmamap
decl_stmt|;
endif|#
directive|endif
name|struct
name|scb_platform_data
modifier|*
name|platform_data
decl_stmt|;
name|struct
name|map_node
modifier|*
name|hscb_map
decl_stmt|;
name|struct
name|map_node
modifier|*
name|sg_map
decl_stmt|;
name|struct
name|map_node
modifier|*
name|sense_map
decl_stmt|;
name|void
modifier|*
name|sg_list
decl_stmt|;
name|uint8_t
modifier|*
name|sense_data
decl_stmt|;
name|bus_addr_t
name|sg_list_busaddr
decl_stmt|;
name|bus_addr_t
name|sense_busaddr
decl_stmt|;
name|u_int
name|sg_count
decl_stmt|;
comment|/* How full ahd_dma_seg is */
define|#
directive|define
name|AHD_MAX_LQ_CRC_ERRORS
value|5
name|u_int
name|crc_retry_count
decl_stmt|;
name|aic_timer_t
name|io_timer
decl_stmt|;
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

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|scb_list
argument_list|,
name|scb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|scb_data
block|{
comment|/* 	 * TAILQ of lists of free SCBs grouped by device 	 * collision domains. 	 */
name|struct
name|scb_tailq
name|free_scbs
decl_stmt|;
comment|/* 	 * Per-device lists of SCBs whose tag ID would collide 	 * with an already active tag on the device. 	 */
name|struct
name|scb_list
name|free_scb_lists
index|[
name|AHD_NUM_TARGETS
operator|*
name|AHD_NUM_LUNS_NONPKT
index|]
decl_stmt|;
comment|/* 	 * SCBs that will not collide with any active device. 	 */
name|struct
name|scb_list
name|any_dev_free_scb_list
decl_stmt|;
comment|/* 	 * Mapping from tag to SCB. 	 */
name|struct
name|scb
modifier|*
name|scbindex
index|[
name|AHD_SCB_MAX
index|]
decl_stmt|;
name|u_int
name|recovery_scbs
decl_stmt|;
comment|/* Transactions currently in recovery */
comment|/* 	 * "Bus" addresses of our data structures. 	 */
name|bus_dma_tag_t
name|hscb_dmat
decl_stmt|;
comment|/* dmat for our hardware SCB array */
name|bus_dma_tag_t
name|sg_dmat
decl_stmt|;
comment|/* dmat for our sg segments */
name|bus_dma_tag_t
name|sense_dmat
decl_stmt|;
comment|/* dmat for our sense buffers */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|map_node
argument_list|)
name|hscb_maps
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|map_node
argument_list|)
name|sg_maps
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|map_node
argument_list|)
name|sense_maps
expr_stmt|;
name|int
name|scbs_left
decl_stmt|;
comment|/* unallocated scbs in head map_node */
name|int
name|sgs_left
decl_stmt|;
comment|/* unallocated sgs in head map_node */
name|int
name|sense_left
decl_stmt|;
comment|/* unallocated sense in head map_node */
name|uint16_t
name|numscbs
decl_stmt|;
name|uint16_t
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

begin_comment
comment|/************************ Target Mode Definitions *****************************/
end_comment

begin_comment
comment|/*  * Connection desciptor for select-in requests in target mode.  */
end_comment

begin_struct
struct|struct
name|target_cmd
block|{
name|uint8_t
name|scsiid
decl_stmt|;
comment|/* Our ID and the initiator's ID */
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
comment|/*  				 * Bytes contains any additional message 				 * bytes terminated by 0xFF.  The remainder 				 * is the cdb to execute. 				 */
name|uint8_t
name|cmd_valid
decl_stmt|;
comment|/* 				 * When a command is complete, the firmware 				 * will set cmd_valid to all bits set. 				 * After the host has seen the command, 				 * the bits are cleared.  This allows us 				 * to just peek at host memory to determine 				 * if more work is complete. cmd_valid is on 				 * an 8 byte boundary to simplify setting 				 * it on aic7880 hardware which only has 				 * limited direct access to the DMA FIFO. 				 */
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
name|AHD_TMODE_EVENT_BUFFER_SIZE
value|8
end_define

begin_struct
struct|struct
name|ahd_tmode_event
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
comment|/*  * Per enabled lun target mode state.  * As this state is directly influenced by the host OS'es target mode  * environment, we let the OS module define it.  Forward declare the  * structure here so we can store arrays of them, etc. in OS neutral  * data structures.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHD_TARGET_MODE
end_ifdef

begin_struct
struct|struct
name|ahd_tmode_lstate
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
name|ahd_tmode_event
name|event_buffer
index|[
name|AHD_TMODE_EVENT_BUFFER_SIZE
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

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|ahd_tmode_lstate
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************** Transfer Negotiation Datastructures *********************/
end_comment

begin_define
define|#
directive|define
name|AHD_TRANS_CUR
value|0x01
end_define

begin_comment
comment|/* Modify current neogtiation status */
end_comment

begin_define
define|#
directive|define
name|AHD_TRANS_ACTIVE
value|0x03
end_define

begin_comment
comment|/* Assume this target is on the bus */
end_comment

begin_define
define|#
directive|define
name|AHD_TRANS_GOAL
value|0x04
end_define

begin_comment
comment|/* Modify negotiation goal */
end_comment

begin_define
define|#
directive|define
name|AHD_TRANS_USER
value|0x08
end_define

begin_comment
comment|/* Modify user negotiation settings */
end_comment

begin_define
define|#
directive|define
name|AHD_PERIOD_10MHz
value|0x19
end_define

begin_define
define|#
directive|define
name|AHD_WIDTH_UNKNOWN
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHD_PERIOD_UNKNOWN
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHD_OFFSET_UNKNOWN
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHD_PPR_OPTS_UNKNOWN
value|0xFF
end_define

begin_comment
comment|/*  * Transfer Negotiation Information.  */
end_comment

begin_struct
struct|struct
name|ahd_transinfo
block|{
name|uint8_t
name|protocol_version
decl_stmt|;
comment|/* SCSI Revision level */
name|uint8_t
name|transport_version
decl_stmt|;
comment|/* SPI Revision level */
name|uint8_t
name|width
decl_stmt|;
comment|/* Bus width */
name|uint8_t
name|period
decl_stmt|;
comment|/* Sync rate factor */
name|uint8_t
name|offset
decl_stmt|;
comment|/* Sync offset */
name|uint8_t
name|ppr_options
decl_stmt|;
comment|/* Parallel Protocol Request options */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-initiator current, goal and user transfer negotiation information. */
end_comment

begin_struct
struct|struct
name|ahd_initiator_tinfo
block|{
name|struct
name|ahd_transinfo
name|curr
decl_stmt|;
name|struct
name|ahd_transinfo
name|goal
decl_stmt|;
name|struct
name|ahd_transinfo
name|user
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per enabled target ID state.  * Pointers to lun target state as well as sync/wide negotiation information  * for each initiator<->target mapping.  For the initiator role we pretend  * that we are the target and the targets are the initiators since the  * negotiation is the same regardless of role.  */
end_comment

begin_struct
struct|struct
name|ahd_tmode_tstate
block|{
name|struct
name|ahd_tmode_lstate
modifier|*
name|enabled_luns
index|[
name|AHD_NUM_LUNS
index|]
decl_stmt|;
name|struct
name|ahd_initiator_tinfo
name|transinfo
index|[
name|AHD_NUM_TARGETS
index|]
decl_stmt|;
comment|/* 	 * Per initiator state bitmasks. 	 */
name|uint16_t
name|auto_negotiate
decl_stmt|;
comment|/* Auto Negotiation Required */
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
comment|/*  * Points of interest along the negotiated transfer scale.  */
end_comment

begin_define
define|#
directive|define
name|AHD_SYNCRATE_160
value|0x8
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_PACED
value|0x8
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_DT
value|0x9
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_ULTRA2
value|0xa
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_ULTRA
value|0xc
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_FAST
value|0x19
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_MIN_DT
value|AHD_SYNCRATE_FAST
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_SYNC
value|0x32
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_MIN
value|0x60
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_ASYNC
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_MAX
value|AHD_SYNCRATE_160
end_define

begin_comment
comment|/* Safe and valid period for async negotiations. */
end_comment

begin_define
define|#
directive|define
name|AHD_ASYNC_XFER_PERIOD
value|0x44
end_define

begin_comment
comment|/*  * In RevA, the synctable uses a 120MHz rate for the period  * factor 8 and 160MHz for the period factor 7.  The 120MHz  * rate never made it into the official SCSI spec, so we must  * compensate when setting the negotiation table for Rev A  * parts.  */
end_comment

begin_define
define|#
directive|define
name|AHD_SYNCRATE_REVA_120
value|0x8
end_define

begin_define
define|#
directive|define
name|AHD_SYNCRATE_REVA_160
value|0x7
end_define

begin_comment
comment|/***************************** Lookup Tables **********************************/
end_comment

begin_comment
comment|/*  * Phase -> name and message out response  * to parity errors in each phase table.   */
end_comment

begin_struct
struct|struct
name|ahd_phase_table_entry
block|{
name|uint8_t
name|phase
decl_stmt|;
name|uint8_t
name|mesg_out
decl_stmt|;
comment|/* Message response to parity errors */
name|char
modifier|*
name|phasemsg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/************************** Serial EEPROM Format ******************************/
end_comment

begin_struct
struct|struct
name|seeprom_config
block|{
comment|/*  * Per SCSI ID Configuration Flags  */
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
value|0x003F
comment|/* synchronous transfer rate */
define|#
directive|define
name|CFXFER_ASYNC
value|0x3F
define|#
directive|define
name|CFQAS
value|0x0040
comment|/* Negotiate QAS */
define|#
directive|define
name|CFPACKETIZED
value|0x0080
comment|/* Negotiate Packetized Transfers */
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
name|CFDISC
value|0x0400
comment|/* enable disconnection */
define|#
directive|define
name|CFMULTILUNDEV
value|0x0800
comment|/* Probe multiple luns in BIOS scan */
define|#
directive|define
name|CFWIDEB
value|0x1000
comment|/* wide bus device */
define|#
directive|define
name|CFHOSTMANAGED
value|0x8000
comment|/* Managed by a RAID controller */
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
name|CFBIOSSTATE
value|0x000C
comment|/* BIOS Action State */
define|#
directive|define
name|CFBS_DISABLED
value|0x00
define|#
directive|define
name|CFBS_ENABLED
value|0x04
define|#
directive|define
name|CFBS_DISABLED_SCAN
value|0x08
define|#
directive|define
name|CFENABLEDV
value|0x0010
comment|/* Perform Domain Validation */
define|#
directive|define
name|CFCTRL_A
value|0x0020
comment|/* BIOS displays Ctrl-A message */
define|#
directive|define
name|CFSPARITY
value|0x0040
comment|/* SCSI parity */
define|#
directive|define
name|CFEXTEND
value|0x0080
comment|/* extended translation enabled */
define|#
directive|define
name|CFBOOTCD
value|0x0100
comment|/* Support Bootable CD-ROM */
define|#
directive|define
name|CFMSG_LEVEL
value|0x0600
comment|/* BIOS Message Level */
define|#
directive|define
name|CFMSG_VERBOSE
value|0x0000
define|#
directive|define
name|CFMSG_SILENT
value|0x0200
define|#
directive|define
name|CFMSG_DIAG
value|0x0400
define|#
directive|define
name|CFRESETB
value|0x0800
comment|/* reset SCSI bus at boot */
comment|/*		UNUSED		0xf000	*/
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
name|CFSTERM
value|0x0002
comment|/* SCSI low byte termination */
define|#
directive|define
name|CFWSTERM
value|0x0004
comment|/* SCSI high byte termination */
define|#
directive|define
name|CFSEAUTOTERM
value|0x0008
comment|/* Ultra2 Perform secondary Auto Term*/
define|#
directive|define
name|CFSELOWTERM
value|0x0010
comment|/* Ultra2 secondary low term */
define|#
directive|define
name|CFSEHIGHTERM
value|0x0020
comment|/* Ultra2 secondary high term */
define|#
directive|define
name|CFSTPWLEVEL
value|0x0040
comment|/* Termination level control */
define|#
directive|define
name|CFBIOSAUTOTERM
value|0x0080
comment|/* Perform Auto termination */
define|#
directive|define
name|CFTERM_MENU
value|0x0100
comment|/* BIOS displays termination menu */
define|#
directive|define
name|CFCLUSTERENB
value|0x8000
comment|/* Cluster Enable */
comment|/*  * Bus Release Time, Host Adapter ID  */
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
comment|/* bus release time/PCI Latency Time */
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
comment|/* BIOS Signature */
define|#
directive|define
name|CFSIGNATURE
value|0x400
name|uint16_t
name|checksum
decl_stmt|;
comment|/* word 31 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Vital Product Data used during POST and by the BIOS.  */
end_comment

begin_struct
struct|struct
name|vpd_config
block|{
name|uint8_t
name|bios_flags
decl_stmt|;
define|#
directive|define
name|VPDMASTERBIOS
value|0x0001
define|#
directive|define
name|VPDBOOTHOST
value|0x0002
name|uint8_t
name|reserved_1
index|[
literal|21
index|]
decl_stmt|;
name|uint8_t
name|resource_type
decl_stmt|;
name|uint8_t
name|resource_len
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|resource_data
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|vpd_tag
decl_stmt|;
name|uint16_t
name|vpd_len
decl_stmt|;
name|uint8_t
name|vpd_keyword
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|revision
decl_stmt|;
name|uint8_t
name|device_flags
decl_stmt|;
name|uint8_t
name|termnation_menus
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|fifo_threshold
decl_stmt|;
name|uint8_t
name|end_tag
decl_stmt|;
name|uint8_t
name|vpd_checksum
decl_stmt|;
name|uint16_t
name|default_target_flags
decl_stmt|;
name|uint16_t
name|default_bios_flags
decl_stmt|;
name|uint16_t
name|default_ctrl_flags
decl_stmt|;
name|uint8_t
name|default_irq
decl_stmt|;
name|uint8_t
name|pci_lattime
decl_stmt|;
name|uint8_t
name|max_target
decl_stmt|;
name|uint8_t
name|boot_lun
decl_stmt|;
name|uint16_t
name|signature
decl_stmt|;
name|uint8_t
name|reserved_2
decl_stmt|;
name|uint8_t
name|checksum
decl_stmt|;
name|uint8_t
name|reserved_3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************** Flexport Logic ********************************/
end_comment

begin_define
define|#
directive|define
name|FLXADDR_TERMCTL
value|0x0
end_define

begin_define
define|#
directive|define
name|FLX_TERMCTL_ENSECHIGH
value|0x8
end_define

begin_define
define|#
directive|define
name|FLX_TERMCTL_ENSECLOW
value|0x4
end_define

begin_define
define|#
directive|define
name|FLX_TERMCTL_ENPRIHIGH
value|0x2
end_define

begin_define
define|#
directive|define
name|FLX_TERMCTL_ENPRILOW
value|0x1
end_define

begin_define
define|#
directive|define
name|FLXADDR_ROMSTAT_CURSENSECTL
value|0x1
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_SEECFG
value|0xF0
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_EECFG
value|0x0F
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_SEE_93C66
value|0x00
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_SEE_NONE
value|0xF0
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_EE_512x8
value|0x0
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_EE_1MBx8
value|0x1
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_EE_2MBx8
value|0x2
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_EE_4MBx8
value|0x3
end_define

begin_define
define|#
directive|define
name|FLX_ROMSTAT_EE_16MBx8
value|0x4
end_define

begin_define
define|#
directive|define
name|CURSENSE_ENB
value|0x1
end_define

begin_define
define|#
directive|define
name|FLXADDR_FLEXSTAT
value|0x2
end_define

begin_define
define|#
directive|define
name|FLX_FSTAT_BUSY
value|0x1
end_define

begin_define
define|#
directive|define
name|FLXADDR_CURRENT_STAT
value|0x4
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_SEC_HIGH
value|0xC0
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_SEC_LOW
value|0x30
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_PRI_HIGH
value|0x0C
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_PRI_LOW
value|0x03
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_OKAY
value|0x0
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_OVER
value|0x1
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_UNDER
value|0x2
end_define

begin_define
define|#
directive|define
name|FLX_CSTAT_INVALID
value|0x3
end_define

begin_function_decl
name|int
name|ahd_read_seeprom
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|uint16_t
modifier|*
name|buf
parameter_list|,
name|u_int
name|start_addr
parameter_list|,
name|u_int
name|count
parameter_list|,
name|int
name|bstream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_write_seeprom
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|uint16_t
modifier|*
name|buf
parameter_list|,
name|u_int
name|start_addr
parameter_list|,
name|u_int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_wait_seeprom
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_verify_vpd_cksum
parameter_list|(
name|struct
name|vpd_config
modifier|*
name|vpd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_verify_cksum
parameter_list|(
name|struct
name|seeprom_config
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_acquire_seeprom
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_release_seeprom
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************  Message Buffer *********************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MSG_FLAG_NONE
init|=
literal|0x00
block|,
name|MSG_FLAG_EXPECT_PPR_BUSFREE
init|=
literal|0x01
block|,
name|MSG_FLAG_IU_REQ_CHANGED
init|=
literal|0x02
block|,
name|MSG_FLAG_EXPECT_IDE_BUSFREE
init|=
literal|0x04
block|,
name|MSG_FLAG_EXPECT_QASREJ_BUSFREE
init|=
literal|0x08
block|,
name|MSG_FLAG_PACKETIZED
init|=
literal|0x10
block|}
name|ahd_msg_flags
typedef|;
end_typedef

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
name|ahd_msg_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MSGLOOP_IN_PROG
block|,
name|MSGLOOP_MSGCOMPLETE
block|,
name|MSGLOOP_TERMINATED
block|}
name|msg_loop_stat
typedef|;
end_typedef

begin_comment
comment|/*********************** Software Configuration Structure *********************/
end_comment

begin_struct
struct|struct
name|ahd_suspend_channel_state
block|{
name|uint8_t
name|scsiseq
decl_stmt|;
name|uint8_t
name|sxfrctl0
decl_stmt|;
name|uint8_t
name|sxfrctl1
decl_stmt|;
name|uint8_t
name|simode0
decl_stmt|;
name|uint8_t
name|simode1
decl_stmt|;
name|uint8_t
name|seltimer
decl_stmt|;
name|uint8_t
name|seqctl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahd_suspend_state
block|{
name|struct
name|ahd_suspend_channel_state
name|channel
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|optionmode
decl_stmt|;
name|uint8_t
name|dscommand0
decl_stmt|;
name|uint8_t
name|dspcistatus
decl_stmt|;
comment|/* hsmailbox */
name|uint8_t
name|crccontrol1
decl_stmt|;
name|uint8_t
name|scbbaddr
decl_stmt|;
comment|/* Host and sequencer SCB counts */
name|uint8_t
name|dff_thrsh
decl_stmt|;
name|uint8_t
modifier|*
name|scratch_ram
decl_stmt|;
name|uint8_t
modifier|*
name|btt
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ahd_bus_intr_t
function_decl|)
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_MODE_DFF0
block|,
name|AHD_MODE_DFF1
block|,
name|AHD_MODE_CCHAN
block|,
name|AHD_MODE_SCSI
block|,
name|AHD_MODE_CFG
block|,
name|AHD_MODE_UNKNOWN
block|}
name|ahd_mode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AHD_MK_MSK
parameter_list|(
name|x
parameter_list|)
value|(0x01<< (x))
end_define

begin_define
define|#
directive|define
name|AHD_MODE_DFF0_MSK
value|AHD_MK_MSK(AHD_MODE_DFF0)
end_define

begin_define
define|#
directive|define
name|AHD_MODE_DFF1_MSK
value|AHD_MK_MSK(AHD_MODE_DFF1)
end_define

begin_define
define|#
directive|define
name|AHD_MODE_CCHAN_MSK
value|AHD_MK_MSK(AHD_MODE_CCHAN)
end_define

begin_define
define|#
directive|define
name|AHD_MODE_SCSI_MSK
value|AHD_MK_MSK(AHD_MODE_SCSI)
end_define

begin_define
define|#
directive|define
name|AHD_MODE_CFG_MSK
value|AHD_MK_MSK(AHD_MODE_CFG)
end_define

begin_define
define|#
directive|define
name|AHD_MODE_UNKNOWN_MSK
value|AHD_MK_MSK(AHD_MODE_UNKNOWN)
end_define

begin_define
define|#
directive|define
name|AHD_MODE_ANY_MSK
value|(~0)
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|ahd_mode_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|ahd_callback_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ahd_completion
block|{
name|uint16_t
name|tag
decl_stmt|;
name|uint8_t
name|sg_status
decl_stmt|;
name|uint8_t
name|valid_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AIC_SCB_DATA
parameter_list|(
name|softc
parameter_list|)
value|(&(softc)->scb_data)
end_define

begin_struct
struct|struct
name|ahd_softc
block|{
name|bus_space_tag_t
name|tags
index|[
literal|2
index|]
decl_stmt|;
name|bus_space_handle_t
name|bshs
index|[
literal|2
index|]
decl_stmt|;
ifndef|#
directive|ifndef
name|__linux__
name|bus_dma_tag_t
name|buffer_dmat
decl_stmt|;
comment|/* dmat for buffer I/O */
endif|#
directive|endif
name|struct
name|scb_data
name|scb_data
decl_stmt|;
name|struct
name|hardware_scb
modifier|*
name|next_queued_hscb
decl_stmt|;
name|struct
name|map_node
modifier|*
name|next_queued_hscb_map
decl_stmt|;
comment|/* 	 * SCBs that have been sent to the controller 	 */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|pending_scbs
expr_stmt|;
comment|/* 	 * SCBs whose timeout routine has been called. 	 */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|timedout_scbs
expr_stmt|;
comment|/* 	 * Current register window mode information. 	 */
name|ahd_mode
name|dst_mode
decl_stmt|;
name|ahd_mode
name|src_mode
decl_stmt|;
comment|/* 	 * Saved register window mode information 	 * used for restore on next unpause. 	 */
name|ahd_mode
name|saved_dst_mode
decl_stmt|;
name|ahd_mode
name|saved_src_mode
decl_stmt|;
comment|/* 	 * Platform specific data. 	 */
name|struct
name|ahd_platform_data
modifier|*
name|platform_data
decl_stmt|;
comment|/* 	 * Platform specific device information. 	 */
name|aic_dev_softc_t
name|dev_softc
decl_stmt|;
comment|/* 	 * Bus specific device information. 	 */
name|ahd_bus_intr_t
name|bus_intr
decl_stmt|;
comment|/* 	 * Target mode related state kept on a per enabled lun basis. 	 * Targets that are not enabled will have null entries. 	 * As an initiator, we keep one target entry for our initiator 	 * ID to store our sync/wide transfer settings. 	 */
name|struct
name|ahd_tmode_tstate
modifier|*
name|enabled_targets
index|[
name|AHD_NUM_TARGETS
index|]
decl_stmt|;
comment|/* 	 * The black hole device responsible for handling requests for 	 * disabled luns on enabled targets. 	 */
name|struct
name|ahd_tmode_lstate
modifier|*
name|black_hole
decl_stmt|;
comment|/* 	 * Device instance currently on the bus awaiting a continue TIO 	 * for a command that was not given the disconnect priveledge. 	 */
name|struct
name|ahd_tmode_lstate
modifier|*
name|pending_device
decl_stmt|;
comment|/* 	 * Timer handles for timer driven callbacks. 	 */
name|aic_timer_t
name|reset_timer
decl_stmt|;
name|aic_timer_t
name|stat_timer
decl_stmt|;
comment|/* 	 * Statistics. 	 */
define|#
directive|define
name|AHD_STAT_UPDATE_MS
value|250
define|#
directive|define
name|AHD_STAT_BUCKETS
value|4
name|u_int
name|cmdcmplt_bucket
decl_stmt|;
name|uint32_t
name|cmdcmplt_counts
index|[
name|AHD_STAT_BUCKETS
index|]
decl_stmt|;
name|uint32_t
name|cmdcmplt_total
decl_stmt|;
comment|/* 	 * Card characteristics 	 */
name|ahd_chip
name|chip
decl_stmt|;
name|ahd_feature
name|features
decl_stmt|;
name|ahd_bug
name|bugs
decl_stmt|;
name|ahd_flag
name|flags
decl_stmt|;
name|struct
name|seeprom_config
modifier|*
name|seep_config
decl_stmt|;
comment|/* Command Queues */
name|struct
name|ahd_completion
modifier|*
name|qoutfifo
decl_stmt|;
name|uint16_t
name|qoutfifonext
decl_stmt|;
name|uint16_t
name|qoutfifonext_valid_tag
decl_stmt|;
name|uint16_t
name|qinfifonext
decl_stmt|;
name|uint16_t
name|qinfifo
index|[
name|AHD_SCB_MAX
index|]
decl_stmt|;
comment|/* 	 * Our qfreeze count.  The sequencer compares 	 * this value with its own counter to determine 	 * whether to allow selections to occur. 	 */
name|uint16_t
name|qfreeze_cnt
decl_stmt|;
comment|/* Values to store in the SEQCTL register for pause and unpause */
name|uint8_t
name|unpause
decl_stmt|;
name|uint8_t
name|pause
decl_stmt|;
comment|/* Critical Section Data */
name|struct
name|cs
modifier|*
name|critical_sections
decl_stmt|;
name|u_int
name|num_critical_sections
decl_stmt|;
comment|/* Buffer for handling packetized bitbucket. */
name|uint8_t
modifier|*
name|overrun_buf
decl_stmt|;
comment|/* Links for chaining softcs */
name|TAILQ_ENTRY
argument_list|(
argument|ahd_softc
argument_list|)
name|links
expr_stmt|;
comment|/* Channel Names ('A', 'B', etc.) */
name|char
name|channel
decl_stmt|;
comment|/* Initiator Bus ID */
name|uint8_t
name|our_id
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
comment|/* 	 * Cached verson of the hs_mailbox so we can avoid 	 * pausing the sequencer during mailbox updates. 	 */
name|uint8_t
name|hs_mailbox
decl_stmt|;
comment|/* 	 * Incoming and outgoing message handling. 	 */
name|uint8_t
name|send_msg_perror
decl_stmt|;
name|ahd_msg_flags
name|msg_flags
decl_stmt|;
name|ahd_msg_type
name|msg_type
decl_stmt|;
name|uint8_t
name|msgout_buf
index|[
literal|12
index|]
decl_stmt|;
comment|/* Message we are sending */
name|uint8_t
name|msgin_buf
index|[
literal|12
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
comment|/* 	 * Mapping information for data structures shared 	 * between the sequencer and kernel. 	 */
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|shared_data_dmat
decl_stmt|;
name|struct
name|map_node
name|shared_data_map
decl_stmt|;
comment|/* Information saved through suspend/resume cycles */
name|struct
name|ahd_suspend_state
name|suspend_state
decl_stmt|;
comment|/* Number of enabled target mode device on this card */
name|u_int
name|enabled_luns
decl_stmt|;
comment|/* Initialization level of this data structure */
name|u_int
name|init_level
decl_stmt|;
comment|/* PCI cacheline size. */
name|u_int
name|pci_cachesize
decl_stmt|;
comment|/* PCI-X capability offset. */
name|int
name|pcix_ptr
decl_stmt|;
comment|/* IO Cell Parameters */
name|uint8_t
name|iocell_opts
index|[
name|AHD_NUM_PER_DEV_ANNEXCOLS
index|]
decl_stmt|;
name|u_int
name|stack_size
decl_stmt|;
name|uint16_t
modifier|*
name|saved_stack
decl_stmt|;
comment|/* Per-Unit descriptive information */
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
specifier|const
name|char
modifier|*
name|bus_description
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|unit
decl_stmt|;
comment|/* Selection Timer settings */
name|int
name|seltime
decl_stmt|;
comment|/* 	 * Interrupt coalescing settings. 	 */
define|#
directive|define
name|AHD_INT_COALESCING_TIMER_DEFAULT
value|250
comment|/*us*/
define|#
directive|define
name|AHD_INT_COALESCING_MAXCMDS_DEFAULT
value|10
define|#
directive|define
name|AHD_INT_COALESCING_MAXCMDS_MAX
value|127
define|#
directive|define
name|AHD_INT_COALESCING_MINCMDS_DEFAULT
value|5
define|#
directive|define
name|AHD_INT_COALESCING_MINCMDS_MAX
value|127
define|#
directive|define
name|AHD_INT_COALESCING_THRESHOLD_DEFAULT
value|2000
define|#
directive|define
name|AHD_INT_COALESCING_STOP_THRESHOLD_DEFAULT
value|1000
name|u_int
name|int_coalescing_timer
decl_stmt|;
name|u_int
name|int_coalescing_maxcmds
decl_stmt|;
name|u_int
name|int_coalescing_mincmds
decl_stmt|;
name|u_int
name|int_coalescing_threshold
decl_stmt|;
name|u_int
name|int_coalescing_stop_threshold
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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|ahd_softc_tailq
argument_list|,
name|ahd_softc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ahd_softc_tailq
name|ahd_tailq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************** IO Cell Configuration ****************************/
end_comment

begin_define
define|#
directive|define
name|AHD_PRECOMP_SLEW_INDEX
define|\
value|(AHD_ANNEXCOL_PRECOMP_SLEW - AHD_ANNEXCOL_PER_DEV0)
end_define

begin_define
define|#
directive|define
name|AHD_AMPLITUDE_INDEX
define|\
value|(AHD_ANNEXCOL_AMPLITUDE - AHD_ANNEXCOL_PER_DEV0)
end_define

begin_define
define|#
directive|define
name|AHD_SET_SLEWRATE
parameter_list|(
name|ahd
parameter_list|,
name|new_slew
parameter_list|)
define|\
value|do {									\     (ahd)->iocell_opts[AHD_PRECOMP_SLEW_INDEX]&= ~AHD_SLEWRATE_MASK;	\     (ahd)->iocell_opts[AHD_PRECOMP_SLEW_INDEX] |=			\ 	(((new_slew)<< AHD_SLEWRATE_SHIFT)& AHD_SLEWRATE_MASK);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|AHD_SET_PRECOMP
parameter_list|(
name|ahd
parameter_list|,
name|new_pcomp
parameter_list|)
define|\
value|do {									\     (ahd)->iocell_opts[AHD_PRECOMP_SLEW_INDEX]&= ~AHD_PRECOMP_MASK;	\     (ahd)->iocell_opts[AHD_PRECOMP_SLEW_INDEX] |=			\ 	(((new_pcomp)<< AHD_PRECOMP_SHIFT)& AHD_PRECOMP_MASK);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|AHD_SET_AMPLITUDE
parameter_list|(
name|ahd
parameter_list|,
name|new_amp
parameter_list|)
define|\
value|do {									\     (ahd)->iocell_opts[AHD_AMPLITUDE_INDEX]&= ~AHD_AMPLITUDE_MASK;	\     (ahd)->iocell_opts[AHD_AMPLITUDE_INDEX] |=				\ 	(((new_amp)<< AHD_AMPLITUDE_SHIFT)& AHD_AMPLITUDE_MASK);	\ } while (0)
end_define

begin_comment
comment|/************************ Active Device Information ***************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ROLE_UNKNOWN
block|,
name|ROLE_INITIATOR
block|,
name|ROLE_TARGET
block|}
name|role_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ahd_devinfo
block|{
name|int
name|our_scsiid
decl_stmt|;
name|int
name|target_offset
decl_stmt|;
name|uint16_t
name|target_mask
decl_stmt|;
name|u_int
name|target
decl_stmt|;
name|u_int
name|lun
decl_stmt|;
name|char
name|channel
decl_stmt|;
name|role_t
name|role
decl_stmt|;
comment|/* 				 * Only guaranteed to be correct if not 				 * in the busfree state. 				 */
block|}
struct|;
end_struct

begin_comment
comment|/****************************** PCI Structures ********************************/
end_comment

begin_define
define|#
directive|define
name|AHD_PCI_IOADDR0
value|PCIR_BAR(0)
end_define

begin_comment
comment|/* I/O BAR*/
end_comment

begin_define
define|#
directive|define
name|AHD_PCI_MEMADDR
value|PCIR_BAR(1)
end_define

begin_comment
comment|/* Memory BAR */
end_comment

begin_define
define|#
directive|define
name|AHD_PCI_IOADDR1
value|PCIR_BAR(3)
end_define

begin_comment
comment|/* Second I/O BAR */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ahd_device_setup_t
function_decl|)
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ahd_pci_identity
block|{
name|uint64_t
name|full_id
decl_stmt|;
name|uint64_t
name|id_mask
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|ahd_device_setup_t
modifier|*
name|setup
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ahd_pci_identity
name|ahd_pci_ident_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_int
name|ahd_num_pci_devs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************** Function Declarations ****************************/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_function_decl
name|void
name|ahd_reset_cmds_pending
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|ahd_find_busy_tcl
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|tcl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_busy_tcl
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|tcl
parameter_list|,
name|u_int
name|busyid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_unbusy_tcl
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|tcl
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahd_unbusy_tcl
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|tcl
parameter_list|)
block|{
name|ahd_busy_tcl
argument_list|(
name|ahd
argument_list|,
name|tcl
argument_list|,
name|SCB_LIST_NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/***************************** PCI Front End *********************************/
end_comment

begin_function_decl
name|struct
name|ahd_pci_identity
modifier|*
name|ahd_find_pci_device
parameter_list|(
name|aic_dev_softc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_pci_config
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|struct
name|ahd_pci_identity
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_pci_test_register_access
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** SCB and SCB queue management **********************/
end_comment

begin_function_decl
name|int
name|ahd_probe_scbs
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_qinfifo_requeue_tail
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_match_scb
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|int
name|target
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|lun
parameter_list|,
name|u_int
name|tag
parameter_list|,
name|role_t
name|role
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Initialization ********************************/
end_comment

begin_function_decl
name|struct
name|ahd_softc
modifier|*
name|ahd_alloc
parameter_list|(
name|void
modifier|*
name|platform_arg
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_softc_init
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_controller_info
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_init
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_default_config
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_parse_vpddata
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|vpd_config
modifier|*
name|vpd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_parse_cfgdata
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|seeprom_config
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_intr_enable
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_update_coalescing_values
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|timer
parameter_list|,
name|u_int
name|maxcmds
parameter_list|,
name|u_int
name|mincmds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_enable_coalescing
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_pause_and_flushwork
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_suspend
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_resume
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_softc_insert
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_set_unit
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_set_name
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|scb
modifier|*
name|ahd_get_scb
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|col_idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_free_scb
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_alloc_scbs
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_free
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_reset
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|reinit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_shutdown
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_write_flexport
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_read_flexport
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|uint8_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_wait_flexport
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************** Interrupt Services *******************************/
end_comment

begin_function_decl
name|void
name|ahd_pci_intr
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_clear_intstat
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_flush_qoutfifo
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_run_qoutfifo
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|AHD_TARGET_MODE
end_ifdef

begin_function_decl
name|void
name|ahd_run_tqinfifo
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|paused
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ahd_handle_hwerrint
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_handle_seqint
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|intstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_handle_scsiint
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|intstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_clear_critical_section
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************** Error Recovery *********************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SEARCH_COMPLETE
block|,
name|SEARCH_COUNT
block|,
name|SEARCH_REMOVE
block|,
name|SEARCH_PRINT
block|}
name|ahd_search_action
typedef|;
end_typedef

begin_function_decl
name|void
name|ahd_done_with_status
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|,
name|uint32_t
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_search_qinfifo
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|target
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|lun
parameter_list|,
name|u_int
name|tag
parameter_list|,
name|role_t
name|role
parameter_list|,
name|uint32_t
name|status
parameter_list|,
name|ahd_search_action
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_search_disc_list
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|target
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|lun
parameter_list|,
name|u_int
name|tag
parameter_list|,
name|int
name|stop_on_first
parameter_list|,
name|int
name|remove
parameter_list|,
name|int
name|save_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_freeze_devq
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_reset_channel
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|initiate_reset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_abort_scbs
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|int
name|target
parameter_list|,
name|char
name|channel
parameter_list|,
name|int
name|lun
parameter_list|,
name|u_int
name|tag
parameter_list|,
name|role_t
name|role
parameter_list|,
name|uint32_t
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_restart
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_clear_fifo
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_handle_scb_status
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_handle_scsi_status
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_calc_residual
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_timeout
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_recover_commands
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************** Utility Functions ********************************/
end_comment

begin_function_decl
name|struct
name|ahd_phase_table_entry
modifier|*
name|ahd_lookup_phase_entry
parameter_list|(
name|int
name|phase
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_compile_devinfo
parameter_list|(
name|struct
name|ahd_devinfo
modifier|*
name|devinfo
parameter_list|,
name|u_int
name|our_id
parameter_list|,
name|u_int
name|target
parameter_list|,
name|u_int
name|lun
parameter_list|,
name|char
name|channel
parameter_list|,
name|role_t
name|role
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** Transfer Negotiation ******************************/
end_comment

begin_function_decl
name|void
name|ahd_find_syncrate
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|u_int
modifier|*
name|period
parameter_list|,
name|u_int
modifier|*
name|ppr_options
parameter_list|,
name|u_int
name|maxsync
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_validate_offset
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|ahd_initiator_tinfo
modifier|*
name|tinfo
parameter_list|,
name|u_int
name|period
parameter_list|,
name|u_int
modifier|*
name|offset
parameter_list|,
name|int
name|wide
parameter_list|,
name|role_t
name|role
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_validate_width
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|ahd_initiator_tinfo
modifier|*
name|tinfo
parameter_list|,
name|u_int
modifier|*
name|bus_width
parameter_list|,
name|role_t
name|role
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Negotiation types.  These are used to qualify if we should renegotiate  * even if our goal and current transport parameters are identical.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_NEG_TO_GOAL
block|,
comment|/* Renegotiate only if goal and curr differ. */
name|AHD_NEG_IF_NON_ASYNC
block|,
comment|/* Renegotiate so long as goal is non-async. */
name|AHD_NEG_ALWAYS
comment|/* Renegotiat even if goal is async. */
block|}
name|ahd_neg_type
typedef|;
end_typedef

begin_function_decl
name|int
name|ahd_update_neg_request
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
parameter_list|,
name|struct
name|ahd_tmode_tstate
modifier|*
parameter_list|,
name|struct
name|ahd_initiator_tinfo
modifier|*
parameter_list|,
name|ahd_neg_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_set_width
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
name|devinfo
parameter_list|,
name|u_int
name|width
parameter_list|,
name|u_int
name|type
parameter_list|,
name|int
name|paused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_set_syncrate
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
name|devinfo
parameter_list|,
name|u_int
name|period
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|u_int
name|ppr_options
parameter_list|,
name|u_int
name|type
parameter_list|,
name|int
name|paused
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHD_QUEUE_NONE
block|,
name|AHD_QUEUE_BASIC
block|,
name|AHD_QUEUE_TAGGED
block|}
name|ahd_queue_alg
typedef|;
end_typedef

begin_function_decl
name|void
name|ahd_set_tags
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
name|devinfo
parameter_list|,
name|ahd_queue_alg
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************** Target Mode *************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHD_TARGET_MODE
end_ifdef

begin_function_decl
name|void
name|ahd_send_lstate_events
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|struct
name|ahd_tmode_lstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_handle_en_lun
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cam_status
name|ahd_find_tmode_devs
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|cam_sim
modifier|*
name|sim
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|struct
name|ahd_tmode_tstate
modifier|*
modifier|*
name|tstate
parameter_list|,
name|struct
name|ahd_tmode_lstate
modifier|*
modifier|*
name|lstate
parameter_list|,
name|int
name|notfound_failure
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|AHD_TMODE_ENABLE
end_ifndef

begin_define
define|#
directive|define
name|AHD_TMODE_ENABLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************* Debug ***************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHD_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|uint32_t
name|ahd_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AHD_SHOW_MISC
value|0x00001
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_SENSE
value|0x00002
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_RECOVERY
value|0x00004
end_define

begin_define
define|#
directive|define
name|AHD_DUMP_SEEPROM
value|0x00008
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_TERMCTL
value|0x00010
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_MEMORY
value|0x00020
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_MESSAGES
value|0x00040
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_MODEPTR
value|0x00080
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_SELTO
value|0x00100
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_FIFOS
value|0x00200
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_QFULL
value|0x00400
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_DV
value|0x00800
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_MASKED_ERRORS
value|0x01000
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_QUEUE
value|0x02000
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_TQIN
value|0x04000
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_SG
value|0x08000
end_define

begin_define
define|#
directive|define
name|AHD_SHOW_INT_COALESCING
value|0x10000
end_define

begin_define
define|#
directive|define
name|AHD_DEBUG_SEQUENCER
value|0x20000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ahd_print_scb
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_print_devinfo
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_dump_sglist
parameter_list|(
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_dump_all_cards_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_dump_card_state
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_print_register
parameter_list|(
name|ahd_reg_parse_entry_t
modifier|*
name|table
parameter_list|,
name|u_int
name|num_entries
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_int
name|address
parameter_list|,
name|u_int
name|value
parameter_list|,
name|u_int
modifier|*
name|cur_column
parameter_list|,
name|u_int
name|wrap_point
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_dump_scbs
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC79XX_H_ */
end_comment

end_unit

