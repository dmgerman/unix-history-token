begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Core definitions and data structures shareable across OS platforms.  *  * Copyright (c) 1994-2001 Justin T. Gibbs.  * Copyright (c) 2000-2001 Adaptec Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/aic7xxx/aic7xxx/aic7xxx.h#85 $  *  * $FreeBSD$  */
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

begin_comment
comment|/* Register Definitions */
end_comment

begin_include
include|#
directive|include
file|"aic7xxx_reg.h"
end_include

begin_comment
comment|/************************* Forward Declarations *******************************/
end_comment

begin_struct_decl
struct_decl|struct
name|ahc_platform_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scb_platform_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|seeprom_descriptor
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
name|SCSIID_TARGET
parameter_list|(
name|ahc
parameter_list|,
name|scsiid
parameter_list|)
define|\
value|(((scsiid)& ((((ahc)->features& AHC_TWIN) != 0) ? TWIN_TID : TID)) \>> TID_SHIFT)
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
name|ahc
parameter_list|,
name|scsiid
parameter_list|)
define|\
value|((((ahc)->features& AHC_TWIN) != 0) \         ? ((((scsiid)& TWIN_CHNLB) != 0) ? 'B' : 'A') \        : 'A')
end_define

begin_define
define|#
directive|define
name|SCB_IS_SCSIBUS_B
parameter_list|(
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|(SCSIID_CHANNEL(ahc, (scb)->hscb->scsiid) == 'B')
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
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|SCSIID_TARGET((ahc), (scb)->hscb->scsiid)
end_define

begin_define
define|#
directive|define
name|SCB_GET_CHANNEL
parameter_list|(
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|SCSIID_CHANNEL(ahc, (scb)->hscb->scsiid)
end_define

begin_define
define|#
directive|define
name|SCB_GET_LUN
parameter_list|(
name|scb
parameter_list|)
define|\
value|((scb)->hscb->lun& LID)
end_define

begin_define
define|#
directive|define
name|SCB_GET_TARGET_OFFSET
parameter_list|(
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|(SCB_GET_TARGET(ahc, scb) + (SCB_IS_SCSIBUS_B(ahc, scb) ? 8 : 0))
end_define

begin_define
define|#
directive|define
name|SCB_GET_TARGET_MASK
parameter_list|(
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|(0x01<< (SCB_GET_TARGET_OFFSET(ahc, scb)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SCB_IS_SILENT
parameter_list|(
name|scb
parameter_list|)
define|\
value|((ahc_debug& AHC_SHOW_MASKED_ERRORS) == 0		\&& (((scb)->flags& SCB_SILENT) != 0))
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
value|(tcl& (AHC_NUM_LUNS - 1))
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

begin_ifndef
ifndef|#
directive|ifndef
name|AHC_TARGET_MODE
end_ifndef

begin_undef
undef|#
directive|undef
name|AHC_TMODE_ENABLE
end_undef

begin_define
define|#
directive|define
name|AHC_TMODE_ENABLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**************************** Driver Constants ********************************/
end_comment

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
comment|/*  * The maximum number of supported luns.  * The identify message only supports 64 luns in SPI3.  * You can have 2^64 luns when information unit transfers are enabled,  * but it is doubtful this driver will ever support IUTs.  */
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
comment|/*  * The maximum amount of SCB storage in hardware on a controller.  * This value represents an upper bound.  Controllers vary in the number  * they actually support.  */
end_comment

begin_define
define|#
directive|define
name|AHC_SCB_MAX
value|255
end_define

begin_comment
comment|/*  * The maximum number of concurrent transactions supported per driver instance.  * Sequencer Control Blocks (SCBs) store per-transaction information.  Although  * the space for SCBs on the host adapter varies by model, the driver will  * page the SCBs between host and controller memory as needed.  We are limited  * to 253 because:  * 	1) The 8bit nature of the RISC engine holds us to an 8bit value.  * 	2) We reserve one value, 255, to represent the invalid element.  *	3) Our input queue scheme requires one SCB to always be reserved  *	   in advance of queuing any SCBs.  This takes us down to 254.  *	4) To handle our output queue correctly on machines that only  * 	   support 32bit stores, we must clear the array 4 bytes at a  *	   time.  To avoid colliding with a DMA write from the sequencer,  *	   we must be sure that 4 slots are empty when we write to clear  *	   the queue.  This reduces us to 253 SCBs: 1 that just completed  *	   and the known three additional empty slots in the queue that  *	   precede it.  */
end_comment

begin_define
define|#
directive|define
name|AHC_MAX_QUEUE
value|253
end_define

begin_comment
comment|/*  * The maximum amount of SCB storage we allocate in host memory.  This  * number should reflect the 1 additional SCB we require to handle our  * qinfifo mechanism.  */
end_comment

begin_define
define|#
directive|define
name|AHC_SCB_MAX_ALLOC
value|(AHC_MAX_QUEUE+1)
end_define

begin_comment
comment|/*  * Ring Buffer of incoming target commands.  * We allocate 256 to simplify the logic in the sequencer  * by using the natural wrap point of an 8bit counter.  */
end_comment

begin_define
define|#
directive|define
name|AHC_TMODE_CMDS
value|256
end_define

begin_comment
comment|/* Reset line assertion time in us */
end_comment

begin_define
define|#
directive|define
name|AHC_BUSRESET_DELAY
value|25
end_define

begin_comment
comment|/* Phase change constants used in target mode. */
end_comment

begin_define
define|#
directive|define
name|AHC_BUSSETTLE_DELAY
value|400
end_define

begin_define
define|#
directive|define
name|AHC_DATARELEASE_DELAY
value|400
end_define

begin_comment
comment|/******************* Chip Characteristics/Operating Settings  *****************/
end_comment

begin_comment
comment|/*  * Chip Type  * The chip order is from least sophisticated to most sophisticated.  */
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
name|AHC_AIC7895C
init|=
literal|0x0009
block|,
name|AHC_AIC7890
init|=
literal|0x000a
block|,
name|AHC_AIC7896
init|=
literal|0x000b
block|,
name|AHC_AIC7892
init|=
literal|0x000c
block|,
name|AHC_AIC7899
init|=
literal|0x000d
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

begin_comment
comment|/*  * Features available in each chip type.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_FENONE
init|=
literal|0x00000
block|,
name|AHC_ULTRA
init|=
literal|0x00001
block|,
comment|/* Supports 20MHz Transfers */
name|AHC_ULTRA2
init|=
literal|0x00002
block|,
comment|/* Supports 40MHz Transfers */
name|AHC_WIDE
init|=
literal|0x00004
block|,
comment|/* Wide Channel */
name|AHC_TWIN
init|=
literal|0x00008
block|,
comment|/* Twin Channel */
name|AHC_MORE_SRAM
init|=
literal|0x00010
block|,
comment|/* 80 bytes instead of 64 */
name|AHC_CMD_CHAN
init|=
literal|0x00020
block|,
comment|/* Has a Command DMA Channel */
name|AHC_QUEUE_REGS
init|=
literal|0x00040
block|,
comment|/* Has Queue management registers */
name|AHC_SG_PRELOAD
init|=
literal|0x00080
block|,
comment|/* Can perform auto-SG preload */
name|AHC_SPIOCAP
init|=
literal|0x00100
block|,
comment|/* Has a Serial Port I/O Cap Register */
name|AHC_MULTI_TID
init|=
literal|0x00200
block|,
comment|/* Has bitmask of TIDs for select-in */
name|AHC_HS_MAILBOX
init|=
literal|0x00400
block|,
comment|/* Has HS_MAILBOX register */
name|AHC_DT
init|=
literal|0x00800
block|,
comment|/* Double Transition transfers */
name|AHC_NEW_TERMCTL
init|=
literal|0x01000
block|,
comment|/* Newer termination scheme */
name|AHC_MULTI_FUNC
init|=
literal|0x02000
block|,
comment|/* Multi-Function Twin Channel Device */
name|AHC_LARGE_SCBS
init|=
literal|0x04000
block|,
comment|/* 64byte SCBs */
name|AHC_AUTORATE
init|=
literal|0x08000
block|,
comment|/* Automatic update of SCSIRATE/OFFSET*/
name|AHC_AUTOPAUSE
init|=
literal|0x10000
block|,
comment|/* Automatic pause on register access */
name|AHC_TARGETMODE
init|=
literal|0x20000
block|,
comment|/* Has tested target mode support */
name|AHC_MULTIROLE
init|=
literal|0x40000
block|,
comment|/* Space for two roles at a time */
name|AHC_REMOVABLE
init|=
literal|0x80000
block|,
comment|/* Hot-Swap supported */
name|AHC_AIC7770_FE
init|=
name|AHC_FENONE
block|,
comment|/* 	 * The real 7850 does not support Ultra modes, but there are 	 * several cards that use the generic 7850 PCI ID even though 	 * they are using an Ultra capable chip (7859/7860).  We start 	 * out with the AHC_ULTRA feature set and then check the DEVSTATUS 	 * register to determine if the capability is really present. 	 */
name|AHC_AIC7850_FE
init|=
name|AHC_SPIOCAP
operator||
name|AHC_AUTOPAUSE
operator||
name|AHC_TARGETMODE
operator||
name|AHC_ULTRA
block|,
name|AHC_AIC7860_FE
init|=
name|AHC_AIC7850_FE
block|,
name|AHC_AIC7870_FE
init|=
name|AHC_TARGETMODE
operator||
name|AHC_AUTOPAUSE
block|,
name|AHC_AIC7880_FE
init|=
name|AHC_AIC7870_FE
operator||
name|AHC_ULTRA
block|,
comment|/* 	 * Although we have space for both the initiator and 	 * target roles on ULTRA2 chips, we currently disable 	 * the initiator role to allow multi-scsi-id target mode 	 * configurations.  We can only respond on the same SCSI 	 * ID as our initiator role if we allow initiator operation. 	 * At some point, we should add a configuration knob to 	 * allow both roles to be loaded. 	 */
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
operator||
name|AHC_TARGETMODE
block|,
name|AHC_AIC7892_FE
init|=
name|AHC_AIC7890_FE
operator||
name|AHC_DT
operator||
name|AHC_AUTORATE
operator||
name|AHC_AUTOPAUSE
block|,
name|AHC_AIC7895_FE
init|=
name|AHC_AIC7880_FE
operator||
name|AHC_MORE_SRAM
operator||
name|AHC_AUTOPAUSE
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

begin_comment
comment|/*  * Bugs in the silicon that we work around in software.  */
end_comment

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
comment|/* 	 * On many chips, cacheline streaming does not work. 	 */
name|AHC_CACHETHEN_BUG
init|=
literal|0x04
block|,
comment|/* 	 * On the aic7896/97 chips, cacheline 	 * streaming must be enabled. 	 */
name|AHC_CACHETHEN_DIS_BUG
init|=
literal|0x08
block|,
comment|/* 	 * PCI 2.1 Retry failure on non-empty data fifo. 	 */
name|AHC_PCI_2_1_RETRY_BUG
init|=
literal|0x10
block|,
comment|/* 	 * Controller does not handle cacheline residuals 	 * properly on S/G segments if PCI MWI instructions 	 * are allowed. 	 */
name|AHC_PCI_MWI_BUG
init|=
literal|0x20
block|,
comment|/* 	 * An SCB upload using the SCB channel's 	 * auto array entry copy feature may  	 * corrupt data.  This appears to only 	 * occur on 66MHz systems. 	 */
name|AHC_SCBCHAN_UPLOAD_BUG
init|=
literal|0x40
block|}
name|ahc_bug
typedef|;
end_typedef

begin_comment
comment|/*  * Configuration specific settings.  * The driver determines these settings by probing the  * chip/controller's configuration.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_FNONE
init|=
literal|0x000
block|,
name|AHC_PRIMARY_CHANNEL
init|=
literal|0x003
block|,
comment|/* 					 * The channel that should 					 * be probed first. 					 */
name|AHC_USEDEFAULTS
init|=
literal|0x004
block|,
comment|/* 					 * For cards without an seeprom 					 * or a BIOS to initialize the chip's 					 * SRAM, we use the default target 					 * settings. 					 */
name|AHC_SEQUENCER_DEBUG
init|=
literal|0x008
block|,
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
name|AHC_INITIATORROLE
init|=
literal|0x1000
block|,
comment|/* 					  * Allow initiator operations on 					  * this controller. 					  */
name|AHC_TARGETROLE
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
block|,
comment|/* 					   * The busy targets table is 					   * stored in SCB space rather 					   * than SRAM. 					   */
name|AHC_BIOS_ENABLED
init|=
literal|0x80000
block|,
name|AHC_ALL_INTERRUPTS
init|=
literal|0x100000
block|,
name|AHC_PAGESCBS
init|=
literal|0x400000
block|,
comment|/* Enable SCB paging */
name|AHC_EDGE_INTERRUPT
init|=
literal|0x800000
block|,
comment|/* Device uses edge triggered ints */
name|AHC_39BIT_ADDRESSING
init|=
literal|0x1000000
block|,
comment|/* Use 39 bit addressing scheme. */
name|AHC_LSCBS_ENABLED
init|=
literal|0x2000000
block|,
comment|/* 64Byte SCBs enabled */
name|AHC_SCB_CONFIG_USED
init|=
literal|0x4000000
block|,
comment|/* No SEEPROM but SCB2 had info. */
name|AHC_NO_BIOS_INIT
init|=
literal|0x8000000
block|,
comment|/* No BIOS left over settings. */
name|AHC_DISABLE_PCI_PERR
init|=
literal|0x10000000
block|,
name|AHC_HAS_TERM_LOGIC
init|=
literal|0x20000000
block|,
name|AHC_SHUTDOWN_RECOVERY
init|=
literal|0x40000000
comment|/* Terminate recovery thread. */
block|}
name|ahc_flag
typedef|;
end_typedef

begin_comment
comment|/************************* Hardware  SCB Definition ***************************/
end_comment

begin_comment
comment|/*  * The driver keeps up to MAX_SCB scb structures per card in memory.  The SCB  * consists of a "hardware SCB" mirroring the fields available on the card  * and additional information the kernel stores for each transaction.  *  * To minimize space utilization, a portion of the hardware scb stores  * different data during different portions of a SCSI transaction.  * As initialized by the host driver for the initiator role, this area  * contains the SCSI cdb (or a pointer to the  cdb) to be executed.  After  * the cdb has been presented to the target, this area serves to store  * residual transfer information and the SCSI status byte.  * For the target role, the contents of this area do not change, but  * still serve a different purpose than for the initiator role.  See  * struct target_data for details.  */
end_comment

begin_comment
comment|/*  * Status information embedded in the shared poriton of  * an SCB after passing the cdb to the target.  The kernel  * driver will only read this data for transactions that  * complete abnormally (non-zero status byte).  */
end_comment

begin_struct
struct|struct
name|status_pkt
block|{
name|uint32_t
name|residual_datacnt
decl_stmt|;
comment|/* Residual in the current S/G seg */
name|uint32_t
name|residual_sg_ptr
decl_stmt|;
comment|/* The next S/G for this transfer */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* Standard SCSI status byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Target mode version of the shared data SCB segment.  */
end_comment

begin_struct
struct|struct
name|target_data
block|{
name|uint32_t
name|residual_datacnt
decl_stmt|;
comment|/* Residual in the current S/G seg */
name|uint32_t
name|residual_sg_ptr
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

begin_define
define|#
directive|define
name|MAX_CDB_LEN
value|16
end_define

begin_struct
struct|struct
name|hardware_scb
block|{
comment|/*0*/
union|union
block|{
comment|/* 		 * If the cdb is 12 bytes or less, we embed it directly 		 * in the SCB.  For longer cdbs, we embed the address 		 * of the cdb payload as seen by the chip and a DMA 		 * is used to pull it in. 		 */
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
comment|/*  * A word about residuals.  * The scb is presented to the sequencer with the dataptr and datacnt  * fields initialized to the contents of the first S/G element to  * transfer.  The sgptr field is initialized to the bus address for  * the S/G element that follows the first in the in core S/G array  * or'ed with the SG_FULL_RESID flag.  Sgptr may point to an invalid  * S/G entry for this transfer (single S/G element transfer with the  * first elements address and length preloaded in the dataptr/datacnt  * fields).  If no transfer is to occur, sgptr is set to SG_LIST_NULL.  * The SG_FULL_RESID flag ensures that the residual will be correctly  * noted even if no data transfers occur.  Once the data phase is entered,  * the residual sgptr and datacnt are loaded from the sgptr and the  * datacnt fields.  After each S/G element's dataptr and length are  * loaded into the hardware, the residual sgptr is advanced.  After  * each S/G element is expired, its datacnt field is checked to see  * if the LAST_SEG flag is set.  If so, SG_LIST_NULL is set in the  * residual sg ptr and the transfer is considered complete.  If the  * sequencer determines that there is a residual in the tranfer, it  * will set the SG_RESID_VALID flag in sgptr and dma the scb back into  * host memory.  To sumarize:  *  * Sequencer:  *	o A residual has occurred if SG_FULL_RESID is set in sgptr,  *	  or residual_sgptr does not have SG_LIST_NULL set.  *  *	o We are transfering the last segment if residual_datacnt has  *	  the SG_LAST_SEG flag set.  *  * Host:  *	o A residual has occurred if a completed scb has the  *	  SG_RESID_VALID flag set.  *  *	o residual_sgptr and sgptr refer to the "next" sg entry  *	  and so may point beyond the last valid sg entry for the  *	  transfer.  */
comment|/*12*/
name|uint32_t
name|dataptr
decl_stmt|;
comment|/*16*/
name|uint32_t
name|datacnt
decl_stmt|;
comment|/* 					 * Byte 3 (numbered from 0) of 					 * the datacnt is really the 					 * 4th byte in that data address. 					 */
comment|/*20*/
name|uint32_t
name|sgptr
decl_stmt|;
define|#
directive|define
name|SG_PTR_MASK
value|0xFFFFFFF8
comment|/*24*/
name|uint8_t
name|control
decl_stmt|;
comment|/* See SCB_CONTROL in aic7xxx.reg for details */
comment|/*25*/
name|uint8_t
name|scsiid
decl_stmt|;
comment|/* what to load in the SCSIID register */
comment|/*26*/
name|uint8_t
name|lun
decl_stmt|;
comment|/*27*/
name|uint8_t
name|tag
decl_stmt|;
comment|/* 					 * Index into our kernel SCB array. 					 * Also used as the tag for tagged I/O 					 */
comment|/*28*/
name|uint8_t
name|cdb_len
decl_stmt|;
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
comment|/* 					 * Used for threading SCBs in the 					 * "Waiting for Selection" and 					 * "Disconnected SCB" lists down 					 * in the sequencer. 					 */
comment|/*32*/
name|uint8_t
name|cdb32
index|[
literal|32
index|]
decl_stmt|;
comment|/* 					 * CDB storage for cdbs of size 					 * 13->32.  We store them here 					 * because hardware scbs are 					 * allocated from DMA safe 					 * memory so we are guaranteed 					 * the controller can access 					 * this data. 					 */
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

begin_comment
comment|/*  * The current state of this SCB.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SCB_FLAG_NONE
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
name|SCB_CDB32_PTR
init|=
literal|0x0010
block|,
name|SCB_RECOVERY_SCB
init|=
literal|0x0020
block|,
name|SCB_AUTO_NEGOTIATE
init|=
literal|0x0040
block|,
comment|/* Negotiate to achieve goal. */
name|SCB_NEGOTIATE
init|=
literal|0x0080
block|,
comment|/* Negotiation forced for command. */
name|SCB_ABORT
init|=
literal|0x0100
block|,
name|SCB_UNTAGGEDQ
init|=
literal|0x0200
block|,
name|SCB_ACTIVE
init|=
literal|0x0400
block|,
name|SCB_TARGET_IMMEDIATE
init|=
literal|0x0800
block|,
name|SCB_TRANSMISSION_ERROR
init|=
literal|0x1000
block|,
comment|/* 					  * We detected a parity or CRC 					  * error that has effected the 					  * payload of the command.  This 					  * flag is checked when normal 					  * status is returned to catch 					  * the case of a target not 					  * responding to our attempt 					  * to report the error. 					  */
name|SCB_TARGET_SCB
init|=
literal|0x2000
block|,
name|SCB_SILENT
init|=
literal|0x4000
block|,
comment|/* 					  * Be quiet about transmission type 					  * errors.  They are expected and we 					  * don't want to upset the user.  This 					  * flag is typically used during DV. 					  */
name|SCB_TIMEDOUT
init|=
literal|0x8000
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
name|TAILQ_ENTRY
argument_list|(
argument|scb
argument_list|)
name|tqe
expr_stmt|;
block|}
name|links
union|;
name|LIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|pending_links
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|timedout_links
expr_stmt|;
name|aic_io_ctx_t
name|io_ctx
decl_stmt|;
name|struct
name|ahc_softc
modifier|*
name|ahc_softc
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
name|sg_map_node
modifier|*
name|sg_map
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
name|aic_timer_t
name|io_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scb_data
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|free_scbs
expr_stmt|;
comment|/* 					 * Pool of SCBs ready to be assigned 					 * commands to execute. 					 */
name|struct
name|scb
modifier|*
name|scbindex
index|[
literal|256
index|]
decl_stmt|;
comment|/* 					 * Mapping from tag to SCB. 					 * As tag identifiers are an 					 * 8bit value, we provide space 					 * for all possible tag values. 					 * Any lookups to entries at or 					 * above AHC_SCB_MAX_ALLOC will 					 * always fail. 					 */
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
name|struct
name|scsi_sense_data
modifier|*
name|sense
decl_stmt|;
comment|/* Per SCB sense data */
name|u_int
name|recovery_scbs
decl_stmt|;
comment|/* Transactions currently in recovery */
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
comment|/*  * Per enabled lun target mode state.  * As this state is directly influenced by the host OS'es target mode  * environment, we let the OS module define it.  Forward declare the  * structure here so we can store arrays of them, etc. in OS neutral  * data structures.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_TARGET_MODE
end_ifdef

begin_struct
struct|struct
name|ahc_tmode_lstate
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

begin_else
else|#
directive|else
end_else

begin_struct_decl
struct_decl|struct
name|ahc_tmode_lstate
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
comment|/* Assume this target is on the bus */
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

begin_define
define|#
directive|define
name|AHC_WIDTH_UNKNOWN
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHC_PERIOD_UNKNOWN
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHC_OFFSET_UNKNOWN
value|0xFF
end_define

begin_define
define|#
directive|define
name|AHC_PPR_OPTS_UNKNOWN
value|0xFF
end_define

begin_comment
comment|/*  * Transfer Negotiation Information.  */
end_comment

begin_struct
struct|struct
name|ahc_transinfo
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
name|ahc_initiator_tinfo
block|{
name|uint8_t
name|scsirate
decl_stmt|;
comment|/* Computed value for SCSIRATE reg */
name|struct
name|ahc_transinfo
name|curr
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
comment|/*  * Per enabled target ID state.  * Pointers to lun target state as well as sync/wide negotiation information  * for each initiator<->target mapping.  For the initiator role we pretend  * that we are the target and the targets are the initiators since the  * negotiation is the same regardless of role.  */
end_comment

begin_struct
struct|struct
name|ahc_tmode_tstate
block|{
name|struct
name|ahc_tmode_lstate
modifier|*
name|enabled_luns
index|[
name|AHC_NUM_LUNS
index|]
decl_stmt|;
name|struct
name|ahc_initiator_tinfo
name|transinfo
index|[
name|AHC_NUM_TARGETS
index|]
decl_stmt|;
comment|/* 	 * Per initiator state bitmasks. 	 */
name|uint16_t
name|auto_negotiate
decl_stmt|;
comment|/* Auto Negotiation Required */
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
comment|/*  * Data structure for our table of allowed synchronous transfer rates.  */
end_comment

begin_struct
struct|struct
name|ahc_syncrate
block|{
name|u_int
name|sxfr_u2
decl_stmt|;
comment|/* Value of the SXFR parameter for Ultra2+ Chips */
name|u_int
name|sxfr
decl_stmt|;
comment|/* Value of the SXFR parameter for<= Ultra Chips */
define|#
directive|define
name|ULTRA_SXFR
value|0x100
comment|/* Rate Requires Ultra Mode set */
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

begin_comment
comment|/* Safe and valid period for async negotiations. */
end_comment

begin_define
define|#
directive|define
name|AHC_ASYNC_XFER_PERIOD
value|0x45
end_define

begin_define
define|#
directive|define
name|AHC_ULTRA2_XFER_PERIOD
value|0x0a
end_define

begin_comment
comment|/*  * Indexes into our table of syncronous transfer rates.  */
end_comment

begin_define
define|#
directive|define
name|AHC_SYNCRATE_DT
value|0
end_define

begin_define
define|#
directive|define
name|AHC_SYNCRATE_ULTRA2
value|1
end_define

begin_define
define|#
directive|define
name|AHC_SYNCRATE_ULTRA
value|3
end_define

begin_define
define|#
directive|define
name|AHC_SYNCRATE_FAST
value|6
end_define

begin_define
define|#
directive|define
name|AHC_SYNCRATE_MAX
value|AHC_SYNCRATE_DT
end_define

begin_define
define|#
directive|define
name|AHC_SYNCRATE_MIN
value|13
end_define

begin_comment
comment|/***************************** Lookup Tables **********************************/
end_comment

begin_comment
comment|/*  * Phase -> name and message out response  * to parity errors in each phase table.   */
end_comment

begin_struct
struct|struct
name|ahc_phase_table_entry
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
define|#
directive|define
name|CFBIOS_BUSSCAN
value|0x0008
comment|/* Have the BIOS Scan the Bus */
define|#
directive|define
name|CFSM2DRV
value|0x0010
comment|/* support more than two drives */
define|#
directive|define
name|CFSTPWLEVEL
value|0x0010
comment|/* Termination level control */
define|#
directive|define
name|CF284XEXTEND
value|0x0020
comment|/* extended translation (284x cards) */
define|#
directive|define
name|CFCTRL_A
value|0x0020
comment|/* BIOS displays Ctrl-A message */
define|#
directive|define
name|CFTERM_MENU
value|0x0040
comment|/* BIOS displays termination menu */
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
name|CFBOOTCD
value|0x0800
comment|/* Support Bootable CD-ROM */
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
name|CFBOOTCHAN
value|0x0300
comment|/* probe this channel first */
define|#
directive|define
name|CFBOOTCHANSHIFT
value|8
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
name|CFENABLEDV
value|0x4000
comment|/* Perform Domain Validation*/
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
define|#
directive|define
name|CFSIGNATURE2
value|0x300
name|uint16_t
name|checksum
decl_stmt|;
comment|/* word 31 */
block|}
struct|;
end_struct

begin_comment
comment|/****************************  Message Buffer *********************************/
end_comment

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
name|ahc_aic7770_softc
block|{
comment|/* 	 * Saved register state used for chip_init(). 	 */
name|uint8_t
name|busspd
decl_stmt|;
name|uint8_t
name|bustime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_pci_softc
block|{
comment|/* 	 * Saved register state used for chip_init(). 	 */
name|uint32_t
name|devconfig
decl_stmt|;
name|uint16_t
name|targcrccnt
decl_stmt|;
name|uint8_t
name|command
decl_stmt|;
name|uint8_t
name|csize_lattime
decl_stmt|;
name|uint8_t
name|optionmode
decl_stmt|;
name|uint8_t
name|crccontrol1
decl_stmt|;
name|uint8_t
name|dscommand0
decl_stmt|;
name|uint8_t
name|dspcistatus
decl_stmt|;
name|uint8_t
name|scbbaddr
decl_stmt|;
name|uint8_t
name|dff_thrsh
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ahc_bus_softc
block|{
name|struct
name|ahc_aic7770_softc
name|aic7770_softc
decl_stmt|;
name|struct
name|ahc_pci_softc
name|pci_softc
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ahc_bus_intr_t
function_decl|)
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ahc_bus_chip_init_t
function_decl|)
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ahc_bus_suspend_t
function_decl|)
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ahc_bus_resume_t
function_decl|)
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|ahc_callback_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|AIC_SCB_DATA
parameter_list|(
name|softc
parameter_list|)
value|((softc)->scb_data)
end_define

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
modifier|*
name|scb_data
decl_stmt|;
name|struct
name|scb
modifier|*
name|next_queued_scb
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
comment|/* 	 * Counting lock for deferring the release of additional 	 * untagged transactions from the untagged_queues.  When 	 * the lock is decremented to 0, all queues in the 	 * untagged_queues array are run. 	 */
name|u_int
name|untagged_queue_lock
decl_stmt|;
comment|/* 	 * Per-target queue of untagged-transactions.  The 	 * transaction at the head of the queue is the 	 * currently pending untagged transaction for the 	 * target.  The driver only allows a single untagged 	 * transaction per target. 	 */
name|struct
name|scb_tailq
name|untagged_queues
index|[
name|AHC_NUM_TARGETS
index|]
decl_stmt|;
comment|/* 	 * Bus attachment specific data. 	 */
name|union
name|ahc_bus_softc
name|bus_softc
decl_stmt|;
comment|/* 	 * Platform specific data. 	 */
name|struct
name|ahc_platform_data
modifier|*
name|platform_data
decl_stmt|;
comment|/* 	 * Platform specific device information. 	 */
name|aic_dev_softc_t
name|dev_softc
decl_stmt|;
comment|/* 	 * Bus specific device information. 	 */
name|ahc_bus_intr_t
name|bus_intr
decl_stmt|;
comment|/* 	 * Bus specific initialization required 	 * after a chip reset. 	 */
name|ahc_bus_chip_init_t
name|bus_chip_init
decl_stmt|;
comment|/* 	 * Bus specific suspend routine. 	 */
name|ahc_bus_suspend_t
name|bus_suspend
decl_stmt|;
comment|/* 	 * Bus specific resume routine. 	 */
name|ahc_bus_resume_t
name|bus_resume
decl_stmt|;
comment|/* 	 * Target mode related state kept on a per enabled lun basis. 	 * Targets that are not enabled will have null entries. 	 * As an initiator, we keep one target entry for our initiator 	 * ID to store our sync/wide transfer settings. 	 */
name|struct
name|ahc_tmode_tstate
modifier|*
name|enabled_targets
index|[
name|AHC_NUM_TARGETS
index|]
decl_stmt|;
comment|/* 	 * The black hole device responsible for handling requests for 	 * disabled luns on enabled targets. 	 */
name|struct
name|ahc_tmode_lstate
modifier|*
name|black_hole
decl_stmt|;
comment|/* 	 * Device instance currently on the bus awaiting a continue TIO 	 * for a command that was not given the disconnect priveledge. 	 */
name|struct
name|ahc_tmode_lstate
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
name|struct
name|seeprom_config
modifier|*
name|seep_config
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
comment|/* Critical Section Data */
name|struct
name|cs
modifier|*
name|critical_sections
decl_stmt|;
name|u_int
name|num_critical_sections
decl_stmt|;
comment|/* Links for chaining softcs */
name|TAILQ_ENTRY
argument_list|(
argument|ahc_softc
argument_list|)
name|links
expr_stmt|;
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
comment|/* 	 * PCI error detection. 	 */
name|int
name|unsolicited_ints
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
comment|/* 	 * Cached copy of the sequencer control register. 	 */
name|uint8_t
name|seqctl
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
name|bus_dmamap_t
name|shared_data_dmamap
decl_stmt|;
name|bus_addr_t
name|shared_data_busaddr
decl_stmt|;
comment|/* 	 * Bus address of the one byte buffer used to 	 * work-around a DMA bug for chips<= aic7880 	 * in target mode. 	 */
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
comment|/* PCI cacheline size. */
name|u_int
name|pci_cachesize
decl_stmt|;
comment|/* 	 * Count of parity errors we have seen as a target. 	 * We auto-disable parity error checking after seeing 	 * AHC_PCI_TARGET_PERR_THRESH number of errors. 	 */
name|u_int
name|pci_target_perr_count
decl_stmt|;
define|#
directive|define
name|AHC_PCI_TARGET_PERR_THRESH
value|10
comment|/* Maximum number of sequencer instructions supported. */
name|u_int
name|instruction_ram_size
decl_stmt|;
comment|/* Per-Unit descriptive information */
specifier|const
name|char
modifier|*
name|description
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
name|int
name|seltime_b
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
name|ahc_softc_tailq
argument_list|,
name|ahc_softc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ahc_softc_tailq
name|ahc_tailq
decl_stmt|;
end_decl_stmt

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
name|ahc_devinfo
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
name|AHC_PCI_IOADDR
value|PCIR_BAR(0)
end_define

begin_comment
comment|/* I/O Address */
end_comment

begin_define
define|#
directive|define
name|AHC_PCI_MEMADDR
value|PCIR_BAR(1)
end_define

begin_comment
comment|/* Mem I/O Address */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ahc_device_setup_t
function_decl|)
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ahc_pci_identity
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
name|ahc_device_setup_t
modifier|*
name|setup
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ahc_pci_identity
name|ahc_pci_ident_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_int
name|ahc_num_pci_devs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************** VL/EISA Declarations ***************************/
end_comment

begin_struct
struct|struct
name|aic7770_identity
block|{
name|uint32_t
name|full_id
decl_stmt|;
name|uint32_t
name|id_mask
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|ahc_device_setup_t
modifier|*
name|setup
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|aic7770_identity
name|aic7770_ident_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|ahc_num_aic7770_devs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AHC_EISA_SLOT_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AHC_EISA_SLOT_OFFSET
value|0xc00
end_define

begin_define
define|#
directive|define
name|AHC_EISA_IOSIZE
value|0x100
end_define

begin_comment
comment|/*************************** Function Declarations ****************************/
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_function_decl
name|u_int
name|ahc_index_busy_tcl
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|tcl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_unbusy_tcl
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|tcl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_busy_tcl
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|tcl
parameter_list|,
name|u_int
name|busyid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************** PCI Front End *********************************/
end_comment

begin_function_decl
name|struct
name|ahc_pci_identity
modifier|*
name|ahc_find_pci_device
parameter_list|(
name|aic_dev_softc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_pci_config
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_pci_identity
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_pci_test_register_access
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************** EISA/VL Front End ********************************/
end_comment

begin_function_decl
name|struct
name|aic7770_identity
modifier|*
name|aic7770_find_device
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aic7770_config
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|aic7770_identity
modifier|*
parameter_list|,
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** SCB and SCB queue management **********************/
end_comment

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
name|void
name|ahc_run_untagged_queues
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
name|ahc_run_untagged_queue
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|scb_tailq
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_qinfifo_requeue_tail
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_match_scb
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_softc
modifier|*
name|ahc_alloc
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
name|ahc_softc_init
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_controller_info
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_chip_init
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_intr_enable
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_pause_and_flushwork
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_suspend
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_resume
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
name|ahc_softc_insert
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_set_unit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_set_name
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_alloc_scbs
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
name|ahc
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
parameter_list|,
name|int
name|reinit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_shutdown
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************** Interrupt Services *******************************/
end_comment

begin_function_decl
name|void
name|ahc_clear_intstat
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
name|ahc_run_qoutfifo
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|AHC_TARGET_MODE
end_ifdef

begin_function_decl
name|void
name|ahc_run_tqinfifo
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_handle_brkadrint
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
name|ahc_handle_seqint
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|intstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_handle_scsiint
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|intstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_clear_critical_section
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
block|}
name|ahc_search_action
typedef|;
end_typedef

begin_function_decl
name|int
name|ahc_search_qinfifo
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_search_action
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_search_untagged_queues
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|aic_io_ctx_t
name|ctx
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
name|uint32_t
name|status
parameter_list|,
name|ahc_search_action
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_search_disc_list
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_freeze_devq
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_reset_channel
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_abort_scbs
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_restart
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
name|ahc_calc_residual
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_timeout
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
name|ahc_recover_commands
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************** Utility Functions ********************************/
end_comment

begin_function_decl
name|struct
name|ahc_phase_table_entry
modifier|*
name|ahc_lookup_phase_entry
parameter_list|(
name|int
name|phase
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_compile_devinfo
parameter_list|(
name|struct
name|ahc_devinfo
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
name|struct
name|ahc_syncrate
modifier|*
name|ahc_find_syncrate
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|u_int
name|ahc_find_period
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|scsirate
parameter_list|,
name|u_int
name|maxsync
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_validate_offset
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|ahc_initiator_tinfo
modifier|*
name|tinfo
parameter_list|,
name|struct
name|ahc_syncrate
modifier|*
name|syncrate
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
name|ahc_validate_width
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|ahc_initiator_tinfo
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
name|AHC_NEG_TO_GOAL
block|,
comment|/* Renegotiate only if goal and curr differ. */
name|AHC_NEG_IF_NON_ASYNC
block|,
comment|/* Renegotiate so long as goal is non-async. */
name|AHC_NEG_ALWAYS
comment|/* Renegotiat even if goal is async. */
block|}
name|ahc_neg_type
typedef|;
end_typedef

begin_function_decl
name|int
name|ahc_update_neg_request
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
parameter_list|,
name|struct
name|ahc_tmode_tstate
modifier|*
parameter_list|,
name|struct
name|ahc_initiator_tinfo
modifier|*
parameter_list|,
name|ahc_neg_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_set_width
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|ahc_devinfo
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
name|ahc_set_syncrate
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
name|devinfo
parameter_list|,
name|struct
name|ahc_syncrate
modifier|*
name|syncrate
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
name|AHC_QUEUE_NONE
block|,
name|AHC_QUEUE_BASIC
block|,
name|AHC_QUEUE_TAGGED
block|}
name|ahc_queue_alg
typedef|;
end_typedef

begin_function_decl
name|void
name|ahc_set_tags
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
name|devinfo
parameter_list|,
name|ahc_queue_alg
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
name|AHC_TARGET_MODE
end_ifdef

begin_function_decl
name|void
name|ahc_send_lstate_events
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_tmode_lstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_handle_en_lun
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_find_tmode_devs
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_tmode_tstate
modifier|*
modifier|*
name|tstate
parameter_list|,
name|struct
name|ahc_tmode_lstate
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
name|AHC_TMODE_ENABLE
end_ifndef

begin_define
define|#
directive|define
name|AHC_TMODE_ENABLE
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
name|AHC_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|uint32_t
name|ahc_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AHC_SHOW_MISC
value|0x0001
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_SENSE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AHC_DUMP_SEEPROM
value|0x0004
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_TERMCTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_MEMORY
value|0x0010
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_MESSAGES
value|0x0020
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_DV
value|0x0040
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_SELTO
value|0x0080
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_QFULL
value|0x0200
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_QUEUE
value|0x0400
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_TQIN
value|0x0800
end_define

begin_define
define|#
directive|define
name|AHC_SHOW_MASKED_ERRORS
value|0x1000
end_define

begin_define
define|#
directive|define
name|AHC_DEBUG_SEQUENCER
value|0x2000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ahc_print_scb
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
name|ahc_print_devinfo
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_dump_card_state
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_print_register
parameter_list|(
name|ahc_reg_parse_entry_t
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

begin_comment
comment|/******************************* SEEPROM *************************************/
end_comment

begin_function_decl
name|int
name|ahc_acquire_seeprom
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|struct
name|seeprom_descriptor
modifier|*
name|sd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_release_seeprom
parameter_list|(
name|struct
name|seeprom_descriptor
modifier|*
name|sd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC7XXX_H_ */
end_comment

end_unit

