begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the generic driver for the aic7xxx based adaptec  * SCSI controllers.  This is used to implement product specific  * probe and attach routines.  *  * Copyright (c) 1994, 1995 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  *	$Id: aic7xxx.h,v 1.12 1995/08/05 17:32:55 gibbs Exp $  */
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
comment|/* 				 * Up to 255 SCBs on some types of aic7xxx 				 * based boards.  The aic7870 have 16 internal 				 * SCBs, but external SRAM bumps this to 255. 				 * The aic7770 family have only 4, and the  				 * aic7850 have only 3. 				 */
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
name|int
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
name|AHC_394
init|=
literal|0x840
comment|/* Twin Channel PCI Controller */
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
comment|/*  * The driver keeps up to MAX_SCB scb structures per card in memory.  Only the  * first 26 bytes of the structure are valid for the hardware, the rest used  * for driver level bookeeping.  The "__attribute ((packed))" tags ensure that  * gcc does not attempt to pad the long ints in the structure to word  * boundaries since the first 26 bytes of this structure must have the correct  * offsets for the hardware to find them.  The driver is further optimized  * so that we only have to download the first 19 bytes since as long  * as we always use S/G, the last fields should be zero anyway.  */
end_comment

begin_struct
struct|struct
name|scb
block|{
comment|/* ------------    Begin hardware supported fields    ---------------- */
comment|/*1*/
name|u_char
name|control
decl_stmt|;
define|#
directive|define
name|SCB_NEEDWDTR
value|0x80
comment|/* Initiate Wide Negotiation */
define|#
directive|define
name|SCB_DISCENB
value|0x40
comment|/* Disconnection Enable */
define|#
directive|define
name|SCB_TE
value|0x20
comment|/* Tag enable */
define|#
directive|define
name|SCB_NEEDSDTR
value|0x10
comment|/* Initiate Sync Negotiation */
define|#
directive|define
name|SCB_NEEDDMA
value|0x08
comment|/* Refresh SCB from host ram */
define|#
directive|define
name|SCB_DIS
value|0x04
define|#
directive|define
name|SCB_TAG_TYPE
value|0x03
define|#
directive|define
name|SIMPLE_QUEUE
value|0x00
define|#
directive|define
name|HEAD_QUEUE
value|0x01
define|#
directive|define
name|OR_QUEUE
value|0x02
comment|/*2*/
name|u_char
name|target_channel_lun
decl_stmt|;
comment|/* 4/1/3 bits */
comment|/*3*/
name|u_char
name|SG_segment_count
decl_stmt|;
comment|/*7*/
name|physaddr
name|SG_list_pointer
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/*11*/
name|physaddr
name|cmdpointer
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/*12*/
name|u_char
name|cmdlen
decl_stmt|;
comment|/*14*/
name|u_char
name|RESERVED
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be zero */
comment|/*15*/
name|u_char
name|target_status
decl_stmt|;
comment|/*18*/
name|u_char
name|residual_data_count
index|[
literal|3
index|]
decl_stmt|;
comment|/*19*/
name|u_char
name|residual_SG_segment_count
decl_stmt|;
comment|/*23*/
name|physaddr
name|data
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/*26*/
name|u_char
name|datalen
index|[
literal|3
index|]
decl_stmt|;
define|#
directive|define
name|SCB_DOWN_SIZE
value|26
comment|/* amount to actually download */
define|#
directive|define
name|SCB_UP_SIZE
value|26
comment|/* 					 * amount we need to upload to perform 					 * a request sense. 					 */
comment|/*30*/
name|physaddr
name|host_scb
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/*31*/
name|u_char
name|next_waiting
decl_stmt|;
comment|/* Used to thread SCBs awaiting 					 * selection 					 */
define|#
directive|define
name|SCB_LIST_NULL
value|0xff
comment|/* SCB list equivelent to NULL */
if|#
directive|if
literal|0
comment|/* 	 *  No real point in transferring this to the 	 *  SCB registers. 	*/
block|unsigned char RESERVED[1];
endif|#
directive|endif
comment|/*-----------------end of hardware supported fields----------------*/
name|struct
name|scb
modifier|*
name|next
decl_stmt|;
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
name|struct
name|scb
modifier|*
name|free_scb
decl_stmt|;
name|struct
name|scb
modifier|*
name|timedout_scb
decl_stmt|;
name|int
name|in_timeout
decl_stmt|;
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
comment|/* an outstanding immediete command */
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
name|unpause
decl_stmt|;
name|u_char
name|pause
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ahc_data
modifier|*
name|ahcdata
index|[
name|NAHC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ahcprobe
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
name|int
name|ahc_attach
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ahcintr
parameter_list|()
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

