begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_reconmap.h,v 1.3 1999/02/05 00:06:16 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/******************************************************************************  * rf_reconMap.h -- Header file describing reconstruction status data structure  ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_RECONMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_RECONMAP_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_comment
comment|/*  * Main reconstruction status descriptor. size and maxsize are used for  * monitoring only:  they have no function for reconstruction.  */
end_comment

begin_struct
struct|struct
name|RF_ReconMap_s
block|{
name|RF_SectorCount_t
name|sectorsPerReconUnit
decl_stmt|;
comment|/* sectors per reconstruct 						 * unit */
name|RF_SectorCount_t
name|sectorsInDisk
decl_stmt|;
comment|/* total sectors in disk */
name|RF_SectorCount_t
name|unitsLeft
decl_stmt|;
comment|/* recon units left to recon */
name|RF_ReconUnitCount_t
name|totalRUs
decl_stmt|;
comment|/* total recon units on disk */
name|RF_ReconUnitCount_t
name|spareRUs
decl_stmt|;
comment|/* total number of spare RUs on failed 					 * disk */
name|RF_StripeCount_t
name|totalParityStripes
decl_stmt|;
comment|/* total number of parity 						 * stripes in array */
name|u_int
name|size
decl_stmt|;
comment|/* overall size of this structure */
name|u_int
name|maxSize
decl_stmt|;
comment|/* maximum size so far */
name|RF_ReconMapListElem_t
modifier|*
modifier|*
name|status
decl_stmt|;
comment|/* array of ptrs to list elements */
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
block|}
struct|;
end_struct

begin_comment
comment|/* a list element */
end_comment

begin_struct
struct|struct
name|RF_ReconMapListElem_s
block|{
name|RF_SectorNum_t
name|startSector
decl_stmt|;
comment|/* bounding sect nums on this block */
name|RF_SectorNum_t
name|stopSector
decl_stmt|;
name|RF_ReconMapListElem_t
modifier|*
name|next
decl_stmt|;
comment|/* next element in list */
block|}
struct|;
end_struct

begin_function_decl
name|RF_ReconMap_t
modifier|*
name|rf_MakeReconMap
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_SectorCount_t
name|ru_sectors
parameter_list|,
name|RF_SectorCount_t
name|disk_sectors
parameter_list|,
name|RF_ReconUnitCount_t
name|spareUnitsPerDisk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ReconMapUpdate
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_ReconMap_t
modifier|*
name|mapPtr
parameter_list|,
name|RF_SectorNum_t
name|startSector
parameter_list|,
name|RF_SectorNum_t
name|stopSector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeReconMap
parameter_list|(
name|RF_ReconMap_t
modifier|*
name|mapPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_CheckRUReconstructed
parameter_list|(
name|RF_ReconMap_t
modifier|*
name|mapPtr
parameter_list|,
name|RF_SectorNum_t
name|startSector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ReconUnitCount_t
name|rf_UnitsLeftToReconstruct
parameter_list|(
name|RF_ReconMap_t
modifier|*
name|mapPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintReconMap
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_ReconMap_t
modifier|*
name|mapPtr
parameter_list|,
name|RF_RowCol_t
name|frow
parameter_list|,
name|RF_RowCol_t
name|fcol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintReconSchedule
parameter_list|(
name|RF_ReconMap_t
modifier|*
name|mapPtr
parameter_list|,
name|struct
name|timeval
modifier|*
name|starttime
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_RECONMAP_H_ */
end_comment

end_unit

