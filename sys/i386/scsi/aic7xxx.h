begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the generic driver for the aic7xxx based adaptec  * SCSI controllers.  This is used to implement product specific  * probe and attach routines.  *  * Copyright (c) 1994, 1995, 1996 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  *	$Id: aic7xxx.h,v 1.23 1996/03/31 03:15:31 gibbs Exp $  */
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

begin_define
define|#
directive|define
name|AHC_NSEG
value|256
end_define

begin_comment
comment|/* number of dma segments supported */
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

begin_comment
comment|/* #define AHCDEBUG */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bootverbose
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|physaddr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|u_long
name|ahc_unit
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ahc_dma_seg
block|{
name|physaddr
name|addr
decl_stmt|;
name|long
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
literal|0x000
block|,
name|AHC_ULTRA
init|=
literal|0x001
block|,
comment|/* Supports 20MHz Transfers */
name|AHC_WIDE
init|=
literal|0x002
block|,
comment|/* Wide Channel */
name|AHC_TWIN
init|=
literal|0x008
block|,
comment|/* Twin Channel */
name|AHC_AIC7770
init|=
literal|0x010
block|,
name|AHC_AIC7850
init|=
literal|0x020
block|,
name|AHC_AIC7870
init|=
literal|0x040
block|,
name|AHC_AIC7880
init|=
literal|0x041
block|,
name|AHC_AIC78X0
init|=
literal|0x060
block|,
comment|/* PCI Based Controller */
name|AHC_274
init|=
literal|0x110
block|,
comment|/* EISA Based Controller */
name|AHC_284
init|=
literal|0x210
block|,
comment|/* VL/ISA Based Controller */
name|AHC_294
init|=
literal|0x440
block|,
comment|/* PCI Based Controller */
name|AHC_294U
init|=
literal|0x441
block|,
comment|/* ULTRA PCI Based Controller */
name|AHC_394
init|=
literal|0x840
block|,
comment|/* Twin Channel PCI Controller */
name|AHC_394U
init|=
literal|0x841
block|,
comment|/* Twin, ULTRA Channel PCI Controller */
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
name|AHC_USEDEFAULTS
init|=
literal|0x04
block|,
comment|/* 					 * For cards without an seeprom 					 * or a BIOS to initialize the chip's 					 * SRAM, we use the default chip and 					 * target settings. 					 */
name|AHC_EXTSCB
init|=
literal|0x10
block|,
comment|/* External SCBs present */
name|AHC_CHNLB
init|=
literal|0x20
block|,
comment|/*  					 * Second controller on 3940  					 * Also encodes the offset in the 					 * SEEPROM for CHNLB info (32) 					 */
block|}
name|ahc_flag
typedef|;
end_typedef

begin_comment
comment|/*  * The driver keeps up to MAX_SCB scb structures per card in memory.  Only the  * first 26 bytes of the structure need to be transfered to the card during  * normal operation.  The remaining fields (next_waiting and host_scb) are  * initialized the first time an SCB is allocated in get_scb().  The fields  * starting at byte 32 are used for kernel level bookkeeping.    */
end_comment

begin_struct
struct|struct
name|scb
block|{
comment|/* ------------    Begin hardware supported fields    ---------------- */
comment|/*0*/
name|u_char
name|control
decl_stmt|;
comment|/*1*/
name|u_char
name|target_channel_lun
decl_stmt|;
comment|/* 4/1/3 bits */
comment|/*2*/
name|u_char
name|target_status
decl_stmt|;
comment|/*3*/
name|u_char
name|SG_segment_count
decl_stmt|;
comment|/*4*/
name|physaddr
name|SG_list_pointer
decl_stmt|;
comment|/*8*/
name|u_char
name|residual_SG_segment_count
decl_stmt|;
comment|/*9*/
name|u_char
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
name|u_long
name|datalen
decl_stmt|;
comment|/* Really only three bits, but its 					 * faster to treat it as a long on 					 * a quad boundary. 					 */
comment|/*20*/
name|physaddr
name|cmdpointer
decl_stmt|;
comment|/*24*/
name|u_char
name|cmdlen
decl_stmt|;
define|#
directive|define
name|SCB_PIO_TRANSFER_SIZE
value|25
comment|/* amount we need to upload/download 					 * via PIO to initialize a transaction. 					 */
comment|/*25*/
name|u_char
name|next_waiting
decl_stmt|;
comment|/* Used to thread SCBs awaiting 					 * selection 					 */
comment|/*-----------------end of hardware supported fields----------------*/
name|SLIST_ENTRY
argument_list|(
argument|scb
argument_list|)
name|next
expr_stmt|;
comment|/* in free list */
name|struct
name|scsi_xfer
modifier|*
name|xs
decl_stmt|;
comment|/* the scsi_xfer for this cmd */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|SCB_FREE
value|0x00
define|#
directive|define
name|SCB_ACTIVE
value|0x01
define|#
directive|define
name|SCB_ABORTED
value|0x02
define|#
directive|define
name|SCB_DEVICE_RESET
value|0x04
define|#
directive|define
name|SCB_IMMED
value|0x08
define|#
directive|define
name|SCB_SENSE
value|0x10
define|#
directive|define
name|SCB_TIMEDOUT
value|0x20
define|#
directive|define
name|SCB_QUEUED_FOR_DONE
value|0x40
name|int
name|position
decl_stmt|;
comment|/* Position in scbarray */
name|struct
name|ahc_dma_seg
name|ahc_dma
index|[
name|AHC_NSEG
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
name|struct
name|scsi_sense
name|sense_cmd
decl_stmt|;
comment|/* SCSI command block */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ahc_data
block|{
name|int
name|unit
decl_stmt|;
name|ahc_type
name|type
decl_stmt|;
name|ahc_flag
name|flags
decl_stmt|;
name|u_long
name|baseport
decl_stmt|;
name|struct
name|scb
modifier|*
name|scbarray
index|[
name|AHC_SCB_MAX
index|]
decl_stmt|;
comment|/* Mirror boards scbarray */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|scb
argument_list|)
name|free_scb
expr_stmt|;
name|int
name|our_id
decl_stmt|;
comment|/* our scsi id */
name|int
name|our_id_b
decl_stmt|;
comment|/* B channel scsi id */
name|int
name|vect
decl_stmt|;
name|struct
name|scb
modifier|*
name|immed_ecb
decl_stmt|;
comment|/* an outstanding immediate command */
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
name|struct
name|scsi_link
name|sc_link_b
decl_stmt|;
comment|/* Second bus for Twin channel cards */
name|u_short
name|needsdtr_orig
decl_stmt|;
comment|/* Targets we initiate sync neg with */
name|u_short
name|needwdtr_orig
decl_stmt|;
comment|/* Targets we initiate wide neg with */
name|u_short
name|needsdtr
decl_stmt|;
comment|/* Current list of negotiated targets */
name|u_short
name|needwdtr
decl_stmt|;
comment|/* Current list of negotiated targets */
name|u_short
name|sdtrpending
decl_stmt|;
comment|/* Pending SDTR to these targets */
name|u_short
name|wdtrpending
decl_stmt|;
comment|/* Pending WDTR to these targets */
name|u_short
name|tagenable
decl_stmt|;
comment|/* Targets that can handle tagqueing */
name|u_short
name|discenable
decl_stmt|;
comment|/* Targets allowed to disconnect */
name|int
name|numscbs
decl_stmt|;
name|int
name|activescbs
decl_stmt|;
name|u_char
name|maxscbs
decl_stmt|;
name|u_char
name|qcntmask
decl_stmt|;
name|u_char
name|unpause
decl_stmt|;
name|u_char
name|pause
decl_stmt|;
name|u_char
name|in_timeout
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/* #define AHC_DEBUG */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ahc_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialized in i386/scsi/aic7xxx.c */
end_comment

begin_decl_stmt
name|void
name|ahc_reset
name|__P
argument_list|(
operator|(
name|u_long
name|iobase
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ahc_data
modifier|*
name|ahc_alloc
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|u_long
name|io_base
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

begin_decl_stmt
name|void
name|ahc_free
name|__P
argument_list|(
operator|(
expr|struct
name|ahc_data
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
name|ahc_data
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
name|ahc_data
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC7XXX_H_ */
end_comment

end_unit

