begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_raid5_rotatedspare.h,v 1.3 1999/02/05 00:06:16 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Khalil Amiri  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* rf_raid5_rotatedspare.h - header file for RAID Level 5 with rotated sparing */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_RAID5_ROTATEDSPARE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_RAID5_ROTATEDSPARE_H_
end_define

begin_function_decl
name|int
name|rf_ConfigureRAID5_RS
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ReconUnitCount_t
name|rf_GetNumSpareRUsRAID5_RS
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_MapSectorRAID5_RS
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|raidSector
parameter_list|,
name|RF_RowCol_t
modifier|*
name|row
parameter_list|,
name|RF_RowCol_t
modifier|*
name|col
parameter_list|,
name|RF_SectorNum_t
modifier|*
name|diskSector
parameter_list|,
name|int
name|remap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_MapParityRAID5_RS
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|raidSector
parameter_list|,
name|RF_RowCol_t
modifier|*
name|row
parameter_list|,
name|RF_RowCol_t
modifier|*
name|col
parameter_list|,
name|RF_SectorNum_t
modifier|*
name|diskSector
parameter_list|,
name|int
name|remap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_IdentifyStripeRAID5_RS
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|addr
parameter_list|,
name|RF_RowCol_t
modifier|*
modifier|*
name|diskids
parameter_list|,
name|RF_RowCol_t
modifier|*
name|outRow
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_MapSIDToPSIDRAID5_RS
parameter_list|(
name|RF_RaidLayout_t
modifier|*
name|layoutPtr
parameter_list|,
name|RF_StripeNum_t
name|stripeID
parameter_list|,
name|RF_StripeNum_t
modifier|*
name|psID
parameter_list|,
name|RF_ReconUnitNum_t
modifier|*
name|which_ru
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_RAID5_ROTATEDSPARE_H_ */
end_comment

end_unit

