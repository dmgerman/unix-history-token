begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the generic driver for the aic7xxx based adaptec  * SCSI controllers.  This is used to implement product specific  * probe and attach routines.  *  * Copyright (c) 1994, 1995, 1996, 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_comment
comment|/*  * convert FreeBSD's<sys/queue.h> symbols to NetBSD's  */
end_comment

begin_define
define|#
directive|define
name|STAILQ_ENTRY
value|SIMPLEQ_ENTRY
end_define

begin_define
define|#
directive|define
name|STAILQ_HEAD
value|SIMPLEQ_HEAD
end_define

begin_define
define|#
directive|define
name|STAILQ_INIT
value|SIMPLEQ_INIT
end_define

begin_define
define|#
directive|define
name|STAILQ_INSERT_HEAD
value|SIMPLEQ_INSERT_HEAD
end_define

begin_define
define|#
directive|define
name|STAILQ_INSERT_TAIL
value|SIMPLEQ_INSERT_TAIL
end_define

begin_define
define|#
directive|define
name|STAILQ_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|SIMPLEQ_REMOVE_HEAD(head, (head)->sqh_first, field)
end_define

begin_define
define|#
directive|define
name|stqh_first
value|sqh_first
end_define

begin_define
define|#
directive|define
name|stqe_next
value|sqe_next
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AHC_NSEG
value|32
end_define

begin_comment
comment|/* The number of dma segments supported. 				 * AHC_NSEG can be maxed out at 256 entries, 				 * but the kernel will never need to transfer 				 * such a large (1MB) request.  To reduce the 				 * driver's memory consumption, we reduce the 				 * max to 32.  16 would work if all transfers 				 * are paged alined since the kernel will only 				 * generate at most a 64k transfer, but to 				 * handle non-page aligned transfers, you need 				 * 17, so we round to the next power of two 				 * to make allocating SG space easy and 				 * efficient. 				 */
end_comment

begin_define
define|#
directive|define
name|AHC_SCB_MAX
value|255
end_define

begin_comment
comment|/* 				 * Up to 255 SCBs on some types of aic7xxx 				 * based boards.  The aic7870 have 16 internal 				 * SCBs, but external SRAM bumps this to 255. 				 * The aic7770 family have only 4, and the  				 * aic7850 has only 3. 				 */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|physaddr
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|u_long
name|ahc_unit
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ahc_dma_seg
block|{
name|physaddr
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
name|AHC_ULTRA
init|=
literal|0x0001
block|,
comment|/* Supports 20MHz Transfers */
name|AHC_WIDE
init|=
literal|0x0002
block|,
comment|/* Wide Channel */
name|AHC_TWIN
init|=
literal|0x0008
block|,
comment|/* Twin Channel */
name|AHC_AIC7770
init|=
literal|0x0010
block|,
name|AHC_AIC7850
init|=
literal|0x0020
block|,
name|AHC_AIC7860
init|=
literal|0x0021
block|,
comment|/* ULTRA version of the aic7850 */
name|AHC_AIC7870
init|=
literal|0x0040
block|,
name|AHC_AIC7880
init|=
literal|0x0041
block|,
name|AHC_AIC78X0
init|=
literal|0x0060
block|,
comment|/* PCI Based Controller */
name|AHC_274
init|=
literal|0x0110
block|,
comment|/* EISA Based Controller */
name|AHC_284
init|=
literal|0x0210
block|,
comment|/* VL/ISA Based Controller */
name|AHC_294AU
init|=
literal|0x0421
block|,
comment|/* aic7860 based '2940' */
name|AHC_294
init|=
literal|0x0440
block|,
comment|/* PCI Based Controller */
name|AHC_294U
init|=
literal|0x0441
block|,
comment|/* ULTRA PCI Based Controller */
name|AHC_394
init|=
literal|0x0840
block|,
comment|/* Twin Channel PCI Controller */
name|AHC_394U
init|=
literal|0x0841
block|,
comment|/* ULTRA, Twin Channel PCI Controller */
name|AHC_398
init|=
literal|0x1040
block|,
comment|/* Multi Channel PCI RAID Controller */
name|AHC_398U
init|=
literal|0x1041
block|,
comment|/* ULTRA, Multi Channel PCI 					 * RAID Controller 					 */
name|AHC_39X
init|=
literal|0x1800
comment|/* Multi Channel PCI Adapter */
block|}
name|ahc_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AHC_FNONE
init|=
literal|0x00
block|,
name|AHC_INIT
init|=
literal|0x01
block|,
name|AHC_RUNNING
init|=
literal|0x02
block|,
name|AHC_PAGESCBS
init|=
literal|0x04
block|,
comment|/* Enable SCB paging */
name|AHC_CHANNEL_B_PRIMARY
init|=
literal|0x08
block|,
comment|/* 					 * On twin channel adapters, probe 					 * channel B first since it is the 					 * primary bus. 					 */
name|AHC_USEDEFAULTS
init|=
literal|0x10
block|,
comment|/* 					 * For cards without an seeprom 					 * or a BIOS to initialize the chip's 					 * SRAM, we use the default target 					 * settings. 					 */
name|AHC_CHNLB
init|=
literal|0x20
block|,
comment|/*  					 * Second controller on 3940/398X  					 * Also encodes the offset in the 					 * SEEPROM for CHNLB info (32) 					 */
name|AHC_CHNLC
init|=
literal|0x40
comment|/* 					 * Third controller on 3985 					 * Also encodes the offset in the 					 * SEEPROM for CHNLC info (64) 					 */
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
name|SCB_ACTIVE
init|=
literal|0x0001
block|,
name|SCB_ABORTED
init|=
literal|0x0002
block|,
name|SCB_DEVICE_RESET
init|=
literal|0x0004
block|,
name|SCB_SENSE
init|=
literal|0x0008
block|,
name|SCB_TIMEDOUT
init|=
literal|0x0010
block|,
name|SCB_QUEUED_FOR_DONE
init|=
literal|0x0020
block|,
name|SCB_RECOVERY_SCB
init|=
literal|0x0040
block|,
name|SCB_WAITINGQ
init|=
literal|0x0080
block|,
name|SCB_ASSIGNEDQ
init|=
literal|0x0100
block|,
name|SCB_SENTORDEREDTAG
init|=
literal|0x0200
block|,
name|SCB_MSGOUT_SDTR
init|=
literal|0x0400
block|,
name|SCB_MSGOUT_WDTR
init|=
literal|0x0800
block|,
name|SCB_ABORT
init|=
literal|0x1000
block|,
name|SCB_QUEUED_ABORT
init|=
literal|0x2000
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
name|SG_segment_count
decl_stmt|;
comment|/*4*/
name|physaddr
name|SG_list_pointer
decl_stmt|;
comment|/*8*/
name|u_int8_t
name|residual_SG_segment_count
decl_stmt|;
comment|/*9*/
name|u_int8_t
name|residual_data_count
index|[
literal|3
index|]
decl_stmt|;
comment|/*12*/
name|physaddr
name|data
decl_stmt|;
comment|/*16*/
name|u_int32_t
name|datalen
decl_stmt|;
comment|/* Really only three bits, but its 					 * faster to treat it as a long on 					 * a quad boundary. 					 */
comment|/*20*/
name|physaddr
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
define|#
directive|define
name|SCB_PIO_TRANSFER_SIZE
value|26
comment|/* amount we need to upload/download 					 * via PIO to initialize a transaction. 					 */
comment|/*26*/
name|u_int8_t
name|next
decl_stmt|;
comment|/* Used for threading SCBs in the 					 * "Waiting for Selection" and 					 * "Disconnected SCB" lists down 					 * in the sequencer. 					 */
comment|/*27*/
name|u_int8_t
name|prev
decl_stmt|;
comment|/*28*/
name|u_int32_t
name|pad
decl_stmt|;
comment|/* 					 * Unused by the kernel, but we require 					 * the padding so that the array of 					 * hardware SCBs is alligned on 32 byte 					 * boundaries so the sequencer can 					 * index them easily. 					 */
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
name|STAILQ_ENTRY
argument_list|(
argument|scb
argument_list|)
name|links
expr_stmt|;
comment|/* for chaining */
name|struct
name|scsi_xfer
modifier|*
name|xs
decl_stmt|;
comment|/* the scsi_xfer for this cmd */
name|scb_flag
name|flags
decl_stmt|;
name|struct
name|ahc_dma_seg
modifier|*
name|ahc_dma
decl_stmt|;
comment|/* Pointer to SG segments */
name|struct
name|scsi_sense
name|sense_cmd
decl_stmt|;
name|u_int8_t
name|sg_count
decl_stmt|;
comment|/* How full ahc_dma_seg is */
name|u_int8_t
name|position
decl_stmt|;
comment|/* Position in card's scbarray */
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
index|[
name|AHC_SCB_MAX
index|]
decl_stmt|;
comment|/* Array of kernel SCBs */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|free_scbs
expr_stmt|;
comment|/* 					 * Pool of SCBs ready to be assigned 					 * commands to execute. 					 */
name|u_int8_t
name|numscbs
decl_stmt|;
name|u_int8_t
name|maxhscbs
decl_stmt|;
comment|/* Number of SCBs on the card */
name|u_int8_t
name|maxscbs
decl_stmt|;
comment|/* 					 * Max SCBs we allocate total including 					 * any that will force us to page SCBs 					 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_busreset_args
block|{
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|char
name|bus
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_softc
block|{
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|int
name|unit
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|struct
name|device
name|sc_dev
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|bus_chipset_tag_t
name|sc_bc
decl_stmt|;
name|bus_io_handle_t
name|sc_ioh
decl_stmt|;
endif|#
directive|endif
name|ahc_type
name|type
decl_stmt|;
name|ahc_flag
name|flags
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|u_int32_t
name|baseport
decl_stmt|;
endif|#
directive|endif
specifier|volatile
name|u_int8_t
modifier|*
name|maddr
decl_stmt|;
name|struct
name|scb_data
modifier|*
name|scb_data
decl_stmt|;
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
name|struct
name|scsi_link
name|sc_link_b
decl_stmt|;
comment|/* Second bus for Twin channel cards */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|waiting_scbs
expr_stmt|;
comment|/* 					 * SCBs waiting ready to go but 					 * waiting for space in the QINFIFO. 					 */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|cmplete_scbs
expr_stmt|;
comment|/* 					 * SCBs out of the QOUTFIFO, waiting 					 * to be ahc_done'd. 					 */
name|u_int8_t
name|activescbs
decl_stmt|;
name|u_int8_t
name|cmdoutcnt
decl_stmt|;
name|u_int16_t
name|needsdtr_orig
decl_stmt|;
comment|/* Targets we initiate sync neg with */
name|u_int16_t
name|needwdtr_orig
decl_stmt|;
comment|/* Targets we initiate wide neg with */
name|u_int16_t
name|needsdtr
decl_stmt|;
comment|/* Current list of negotiated targets */
name|u_int16_t
name|needwdtr
decl_stmt|;
comment|/* Current list of negotiated targets */
name|u_int16_t
name|sdtrpending
decl_stmt|;
comment|/* Pending SDTR to these targets */
name|u_int16_t
name|wdtrpending
decl_stmt|;
comment|/* Pending WDTR to these targets */
name|u_int16_t
name|tagenable
decl_stmt|;
comment|/* Targets that can handle tags */
name|u_int16_t
name|orderedtag
decl_stmt|;
comment|/* Targets to use ordered tag on */
name|u_int16_t
name|discenable
decl_stmt|;
comment|/* Targets allowed to disconnect */
name|u_int8_t
name|our_id
decl_stmt|;
comment|/* our scsi id */
name|u_int8_t
name|our_id_b
decl_stmt|;
comment|/* B channel scsi id */
name|u_int8_t
name|qcntmask
decl_stmt|;
comment|/* 					 * Mask of valid registers in the 					 * Q*CNT registers. 					 */
name|u_int8_t
name|qfullcount
decl_stmt|;
comment|/* 					 * The maximum number of entries 					 * storable in the Q*FIFOs. 					 */
name|u_int8_t
name|curqincnt
decl_stmt|;
comment|/* 					 * The current value we "think" the 					 * QINCNT has.  The reason it is 					 * "think" is that this is a cached 					 * value that is only updated when 					 * curqincount == qfullcount to reduce 					 * the amount of accesses made to the 					 * card. 					 */
name|u_int8_t
name|unpause
decl_stmt|;
name|u_int8_t
name|pause
decl_stmt|;
name|u_int8_t
name|in_timeout
decl_stmt|;
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|ahc_name
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ahc_softc
modifier|*
name|ahc_alloc
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|u_int32_t
name|io_base
operator|,
name|vm_offset_t
name|maddr
operator|,
name|ahc_type
name|type
operator|,
name|ahc_flag
name|flags
operator|,
expr|struct
name|scb_data
operator|*
name|scb_data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ahc_name
parameter_list|(
name|ahc
parameter_list|)
value|(ahc)->sc_dev.dv_xname
end_define

begin_decl_stmt
name|void
name|ahc_construct
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|bus_chipset_tag_t
name|bc
operator|,
name|bus_io_handle_t
name|ioh
operator|,
name|ahc_type
name|type
operator|,
name|ahc_flag
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|ahc_reset
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ahc_free
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ahc_init
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ahc_attach
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
name|void
name|ahc_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|ahc_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|__inline
name|u_int8_t
name|ahc_inb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int32_t
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|ahc_outb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int32_t
name|port
operator|,
name|u_int8_t
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|ahc_outsb
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_softc
operator|*
name|ahc
operator|,
name|u_int32_t
name|port
operator|,
name|u_int8_t
operator|*
name|valp
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|u_int8_t
name|ahc_inb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|u_int32_t
name|port
decl_stmt|;
block|{
if|if
condition|(
name|ahc
operator|->
name|maddr
operator|!=
name|NULL
condition|)
return|return
name|ahc
operator|->
name|maddr
index|[
name|port
index|]
return|;
else|else
return|return
name|inb
argument_list|(
name|ahc
operator|->
name|baseport
operator|+
name|port
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_outb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|val
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|u_int32_t
name|port
decl_stmt|;
name|u_int8_t
name|val
decl_stmt|;
block|{
if|if
condition|(
name|ahc
operator|->
name|maddr
operator|!=
name|NULL
condition|)
name|ahc
operator|->
name|maddr
index|[
name|port
index|]
operator|=
name|val
expr_stmt|;
else|else
name|outb
argument_list|(
name|ahc
operator|->
name|baseport
operator|+
name|port
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahc_outsb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|size
parameter_list|)
name|struct
name|ahc_softc
modifier|*
name|ahc
decl_stmt|;
name|u_int32_t
name|port
decl_stmt|;
name|u_int8_t
modifier|*
name|valp
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|{
if|if
condition|(
name|ahc
operator|->
name|maddr
operator|!=
name|NULL
condition|)
block|{
asm|__asm __volatile(" 			cld; 		1:	lodsb; 			movb %%al,(%0); 			loop 1b"			:
block|:
literal|"r"
operator|(
operator|(
name|ahc
operator|)
operator|->
name|maddr
operator|+
operator|(
name|port
operator|)
operator|)
operator|,
literal|"S"
operator|(
operator|(
name|valp
operator|)
operator|)
operator|,
literal|"c"
operator|(
operator|(
name|size
operator|)
operator|)
operator|:
literal|"%esi"
operator|,
literal|"%ecx"
operator|,
literal|"%eax"
block|)
empty_stmt|;
block|}
end_function

begin_else
else|else
name|outsb
argument_list|(
name|ahc
operator|->
name|baseport
operator|+
name|port
argument_list|,
name|valp
argument_list|,
name|size
argument_list|)
expr_stmt|;
end_else

begin_elif
unit|}
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

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
value|bus_io_read_1((ahc)->sc_bc, (ahc)->sc_ioh, port)
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
name|val
parameter_list|)
define|\
value|bus_io_write_1((ahc)->sc_bc, (ahc)->sc_ioh, port, val)
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
name|size
parameter_list|)
define|\
value|bus_io_write_multi_1((ahc)->sc_bc, (ahc)->sc_ioh, port, valp, size)
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
comment|/* _AIC7XXX_H_ */
end_comment

end_unit

