begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_decluster.h,v 1.3 1999/02/05 00:06:09 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*----------------------------------------------------------------------  *  * decluster.h -- header file for declustered layout code  *  * Adapted from raidSim version July 1994  * Created 10-21-92 (MCH)  *  *--------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DECLUSTER_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DECLUSTER_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_comment
comment|/*  * These structures define the tables used to locate the spare unit  * associated with a particular data or parity unit, and to perform  * the associated inverse mapping.  */
end_comment

begin_struct
struct|struct
name|RF_SpareTableEntry_s
block|{
name|u_int
name|spareDisk
decl_stmt|;
comment|/* disk to which this block is spared */
name|u_int
name|spareBlockOffsetInSUs
decl_stmt|;
comment|/* offset into spare table for that 					 * disk */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_SPAREMAP_NAME_LEN
value|128
end_define

begin_comment
comment|/* this is the layout-specific info structure for the declustered layout.  */
end_comment

begin_struct
struct|struct
name|RF_DeclusteredConfigInfo_s
block|{
name|RF_StripeCount_t
name|groupSize
decl_stmt|;
comment|/* no. of stripe units per parity 					 * stripe */
name|RF_RowCol_t
modifier|*
modifier|*
name|LayoutTable
decl_stmt|;
comment|/* the block design table */
name|RF_RowCol_t
modifier|*
modifier|*
name|OffsetTable
decl_stmt|;
comment|/* the sector offset table */
name|RF_RowCol_t
modifier|*
modifier|*
name|BlockTable
decl_stmt|;
comment|/* the block membership table */
name|RF_StripeCount_t
name|SUsPerFullTable
decl_stmt|;
comment|/* stripe units per full table */
name|RF_StripeCount_t
name|SUsPerTable
decl_stmt|;
comment|/* stripe units per table */
name|RF_StripeCount_t
name|PUsPerBlock
decl_stmt|;
comment|/* parity units per block */
name|RF_StripeCount_t
name|SUsPerBlock
decl_stmt|;
comment|/* stripe units per block */
name|RF_StripeCount_t
name|BlocksPerTable
decl_stmt|;
comment|/* block design tuples per 						 * table */
name|RF_StripeCount_t
name|NumParityReps
decl_stmt|;
comment|/* tables per full table */
name|RF_StripeCount_t
name|TableDepthInPUs
decl_stmt|;
comment|/* PUs on one disk in 1 table */
name|RF_StripeCount_t
name|FullTableDepthInPUs
decl_stmt|;
comment|/* PUs on one disk in 1 						 * fulltable */
name|RF_StripeCount_t
name|FullTableLimitSUID
decl_stmt|;
comment|/* SU where partial fulltables 						 * start */
name|RF_StripeCount_t
name|ExtraTablesPerDisk
decl_stmt|;
comment|/* # of tables in last 						 * fulltable */
name|RF_SectorNum_t
name|DiskOffsetOfLastFullTableInSUs
decl_stmt|;
comment|/* disk offs of partial 							 * ft, if any */
name|RF_StripeCount_t
name|numCompleteFullTablesPerDisk
decl_stmt|;
comment|/* ft identifier of 							 * partial ft, if any */
name|u_int
name|Lambda
decl_stmt|;
comment|/* the pair count in the block design */
comment|/* these are used only in the distributed-sparing case */
name|RF_StripeCount_t
name|FullTablesPerSpareRegion
decl_stmt|;
comment|/* # of ft's comprising 							 * 1 spare region */
name|RF_StripeCount_t
name|TablesPerSpareRegion
decl_stmt|;
comment|/* # of tables */
name|RF_SectorCount_t
name|SpareSpaceDepthPerRegionInSUs
decl_stmt|;
comment|/* spare 							 * space/disk/region */
name|RF_SectorCount_t
name|SpareRegionDepthInSUs
decl_stmt|;
comment|/* # of units/disk/region */
name|RF_SectorNum_t
name|DiskOffsetOfLastSpareSpaceChunkInSUs
decl_stmt|;
comment|/* locates sp space 								 * after partial ft */
name|RF_StripeCount_t
name|TotSparePUsPerDisk
decl_stmt|;
comment|/* total number of spare PUs 						 * per disk */
name|RF_StripeCount_t
name|NumCompleteSRs
decl_stmt|;
name|RF_SpareTableEntry_t
modifier|*
modifier|*
name|SpareTable
decl_stmt|;
comment|/* remap table for spare space */
name|char
name|sparemap_fname
index|[
name|RF_SPAREMAP_NAME_LEN
index|]
decl_stmt|;
comment|/* where to find 							 * sparemap. not used in 							 * kernel */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|rf_ConfigureDeclustered
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
name|int
name|rf_ConfigureDeclusteredDS
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
name|void
name|rf_MapSectorDeclustered
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
name|rf_MapParityDeclustered
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
name|rf_IdentifyStripeDeclustered
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
name|rf_MapSIDToPSIDDeclustered
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

begin_function_decl
name|int
name|rf_InstallSpareTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
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
name|rf_FreeSpareTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_HeadSepLimit_t
name|rf_GetDefaultHeadSepLimitDeclustered
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_GetDefaultNumFloatingReconBuffersDeclustered
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_decluster_adjust_params
parameter_list|(
name|RF_RaidLayout_t
modifier|*
name|layoutPtr
parameter_list|,
name|RF_StripeNum_t
modifier|*
name|SUID
parameter_list|,
name|RF_StripeCount_t
modifier|*
name|sus_per_fulltable
parameter_list|,
name|RF_StripeCount_t
modifier|*
name|fulltable_depth
parameter_list|,
name|RF_StripeNum_t
modifier|*
name|base_suid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_remap_to_spare_space
parameter_list|(
name|RF_RaidLayout_t
modifier|*
name|layoutPtr
parameter_list|,
name|RF_DeclusteredConfigInfo_t
modifier|*
name|info
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_StripeNum_t
name|FullTableID
parameter_list|,
name|RF_StripeNum_t
name|TableID
parameter_list|,
name|RF_SectorNum_t
name|BlockID
parameter_list|,
name|RF_StripeNum_t
name|base_suid
parameter_list|,
name|RF_StripeNum_t
name|SpareRegion
parameter_list|,
name|RF_RowCol_t
modifier|*
name|outCol
parameter_list|,
name|RF_StripeNum_t
modifier|*
name|outSU
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SetSpareTable
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_ReconUnitCount_t
name|rf_GetNumSpareRUsDeclustered
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DECLUSTER_H_ */
end_comment

end_unit

