begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_map.h,v 1.3 1999/02/05 00:06:12 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* rf_map.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_MAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_MAP_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_raid.h>
end_include

begin_comment
comment|/* mapping structure allocation and free routines */
end_comment

begin_function_decl
name|RF_AccessStripeMapHeader_t
modifier|*
name|rf_MapAccess
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|raidAddress
parameter_list|,
name|RF_SectorCount_t
name|numBlocks
parameter_list|,
name|caddr_t
name|buffer
parameter_list|,
name|int
name|remap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_MarkFailuresInASMList
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMapHeader_t
modifier|*
name|asm_h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_AccessStripeMap_t
modifier|*
name|rf_DuplicateASM
parameter_list|(
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_PhysDiskAddr_t
modifier|*
name|rf_DuplicatePDA
parameter_list|(
name|RF_PhysDiskAddr_t
modifier|*
name|pda
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureMapModule
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_AccessStripeMapHeader_t
modifier|*
name|rf_AllocAccessStripeMapHeader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeAccessStripeMapHeader
parameter_list|(
name|RF_AccessStripeMapHeader_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_PhysDiskAddr_t
modifier|*
name|rf_AllocPhysDiskAddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_PhysDiskAddr_t
modifier|*
name|rf_AllocPDAList
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreePhysDiskAddr
parameter_list|(
name|RF_PhysDiskAddr_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_AccessStripeMap_t
modifier|*
name|rf_AllocAccessStripeMapComponent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_AccessStripeMap_t
modifier|*
name|rf_AllocASMList
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeAccessStripeMapComponent
parameter_list|(
name|RF_AccessStripeMap_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeAccessStripeMap
parameter_list|(
name|RF_AccessStripeMapHeader_t
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_CheckStripeForFailures
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_NumFailedDataUnitsInStripe
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintAccessStripeMap
parameter_list|(
name|RF_AccessStripeMapHeader_t
modifier|*
name|asm_h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintFullAccessStripeMap
parameter_list|(
name|RF_AccessStripeMapHeader_t
modifier|*
name|asm_h
parameter_list|,
name|int
name|prbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_PrintRaidAddressInfo
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|raidAddr
parameter_list|,
name|RF_SectorCount_t
name|numBlocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ASMParityAdjust
parameter_list|(
name|RF_PhysDiskAddr_t
modifier|*
name|toAdjust
parameter_list|,
name|RF_StripeNum_t
name|startAddrWithinStripe
parameter_list|,
name|RF_SectorNum_t
name|endAddress
parameter_list|,
name|RF_RaidLayout_t
modifier|*
name|layoutPtr
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asm_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ASMCheckStatus
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_PhysDiskAddr_t
modifier|*
name|pda_p
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asm_p
parameter_list|,
name|RF_RaidDisk_t
modifier|*
modifier|*
name|disks
parameter_list|,
name|int
name|parity
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_MAP_H_ */
end_comment

end_unit

