begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_layout.h,v 1.5 2001/01/26 04:14:14 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* rf_layout.h -- header file defining layout data structures  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_LAYOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_LAYOUT_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_alloclist.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************************  *  * This structure identifies all layout-specific operations and parameters.  *  ****************************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RF_LayoutSW_s
block|{
name|RF_ParityConfig_t
name|parityConfig
decl_stmt|;
specifier|const
name|char
modifier|*
name|configName
decl_stmt|;
ifndef|#
directive|ifndef
name|_KERNEL
comment|/* layout-specific parsing */
name|int
function_decl|(
modifier|*
name|MakeLayoutSpecific
function_decl|)
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|makeLayoutSpecificArg
decl_stmt|;
endif|#
directive|endif
comment|/* !KERNEL */
if|#
directive|if
name|RF_UTILITY
operator|==
literal|0
comment|/* initialization routine */
name|int
function_decl|(
modifier|*
name|Configure
function_decl|)
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|shutdownListp
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
comment|/* routine to map RAID sector address -> physical (row, col, offset) */
name|void
function_decl|(
modifier|*
name|MapSector
function_decl|)
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
comment|/* routine to map RAID sector address -> physical (r,c,o) of parity 	 * unit */
name|void
function_decl|(
modifier|*
name|MapParity
function_decl|)
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
comment|/* routine to map RAID sector address -> physical (r,c,o) of Q unit */
name|void
function_decl|(
modifier|*
name|MapQ
function_decl|)
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
comment|/* routine to identify the disks comprising a stripe */
name|void
function_decl|(
modifier|*
name|IdentifyStripe
function_decl|)
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
comment|/* routine to select a dag */
name|void
function_decl|(
modifier|*
name|SelectionFunc
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_IoType_t
name|type
parameter_list|,
name|RF_AccessStripeMap_t
modifier|*
name|asmap
parameter_list|,
name|RF_VoidFuncPtr
modifier|*
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
block|void    (**createFunc) (RF_Raid_t *, 	            RF_AccessStripeMap_t *, 	            RF_DagHeader_t *, void *, 	            RF_RaidAccessFlags_t, 	            RF_AllocListElem_t *);
endif|#
directive|endif
comment|/* map a stripe ID to a parity stripe ID.  This is typically the 	 * identity mapping */
name|void
function_decl|(
modifier|*
name|MapSIDToPSID
function_decl|)
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
comment|/* get default head separation limit (may be NULL) */
name|RF_HeadSepLimit_t
function_decl|(
modifier|*
name|GetDefaultHeadSepLimit
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
comment|/* get default num recon buffers (may be NULL) */
name|int
function_decl|(
modifier|*
name|GetDefaultNumFloatingReconBuffers
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
comment|/* get number of spare recon units (may be NULL) */
name|RF_ReconUnitCount_t
function_decl|(
modifier|*
name|GetNumSpareRUs
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
comment|/* spare table installation (may be NULL) */
name|int
function_decl|(
modifier|*
name|InstallSpareTable
function_decl|)
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
comment|/* recon buffer submission function */
name|int
function_decl|(
modifier|*
name|SubmitReconBuffer
function_decl|)
parameter_list|(
name|RF_ReconBuffer_t
modifier|*
name|rbuf
parameter_list|,
name|int
name|keep_it
parameter_list|,
name|int
name|use_committed
parameter_list|)
function_decl|;
comment|/*          * verify that parity information for a stripe is correct          * see rf_parityscan.h for return vals          */
name|int
function_decl|(
modifier|*
name|VerifyParity
function_decl|)
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RaidAddr_t
name|raidAddr
parameter_list|,
name|RF_PhysDiskAddr_t
modifier|*
name|parityPDA
parameter_list|,
name|int
name|correct_it
parameter_list|,
name|RF_RaidAccessFlags_t
name|flags
parameter_list|)
function_decl|;
comment|/* number of faults tolerated by this mapping */
name|int
name|faultsTolerated
decl_stmt|;
comment|/* states to step through in an access. Must end with "LastState". The 	 * default is DefaultStates in rf_layout.c */
name|RF_AccessState_t
modifier|*
name|states
decl_stmt|;
name|RF_AccessStripeMapFlags_t
name|flags
decl_stmt|;
endif|#
directive|endif
comment|/* RF_UTILITY == 0 */
block|}
name|RF_LayoutSW_t
typedef|;
end_typedef

begin_comment
comment|/* enables remapping to spare location under dist sparing */
end_comment

begin_define
define|#
directive|define
name|RF_REMAP
value|1
end_define

begin_define
define|#
directive|define
name|RF_DONT_REMAP
value|0
end_define

begin_comment
comment|/*  * Flags values for RF_AccessStripeMapFlags_t  */
end_comment

begin_define
define|#
directive|define
name|RF_NO_STRIPE_LOCKS
value|0x0001
end_define

begin_comment
comment|/* suppress stripe locks */
end_comment

begin_define
define|#
directive|define
name|RF_DISTRIBUTE_SPARE
value|0x0002
end_define

begin_comment
comment|/* distribute spare space in archs 					 * that support it */
end_comment

begin_define
define|#
directive|define
name|RF_BD_DECLUSTERED
value|0x0004
end_define

begin_comment
comment|/* declustering uses block designs */
end_comment

begin_comment
comment|/*************************************************************************  *  * this structure forms the layout component of the main Raid  * structure.  It describes everything needed to define and perform  * the mapping of logical RAID addresses<-> physical disk addresses.  *  *************************************************************************/
end_comment

begin_struct
struct|struct
name|RF_RaidLayout_s
block|{
comment|/* configuration parameters */
name|RF_SectorCount_t
name|sectorsPerStripeUnit
decl_stmt|;
comment|/* number of sectors in one 						 * stripe unit */
name|RF_StripeCount_t
name|SUsPerPU
decl_stmt|;
comment|/* stripe units per parity unit */
name|RF_StripeCount_t
name|SUsPerRU
decl_stmt|;
comment|/* stripe units per reconstruction 					 * unit */
comment|/* redundant-but-useful info computed from the above, used in all 	 * layouts */
name|RF_StripeCount_t
name|numStripe
decl_stmt|;
comment|/* total number of stripes in the 					 * array */
name|RF_SectorCount_t
name|dataSectorsPerStripe
decl_stmt|;
name|RF_StripeCount_t
name|dataStripeUnitsPerDisk
decl_stmt|;
name|u_int
name|bytesPerStripeUnit
decl_stmt|;
name|u_int
name|dataBytesPerStripe
decl_stmt|;
name|RF_StripeCount_t
name|numDataCol
decl_stmt|;
comment|/* number of SUs of data per stripe 					 * (name here is a la RAID4) */
name|RF_StripeCount_t
name|numParityCol
decl_stmt|;
comment|/* number of SUs of parity per stripe. 					 * Always 1 for now */
name|RF_StripeCount_t
name|numParityLogCol
decl_stmt|;
comment|/* number of SUs of parity log 						 * per stripe.  Always 1 for 						 * now */
name|RF_StripeCount_t
name|stripeUnitsPerDisk
decl_stmt|;
name|RF_LayoutSW_t
modifier|*
name|map
decl_stmt|;
comment|/* ptr to struct holding mapping fns and 				 * information */
name|void
modifier|*
name|layoutSpecificInfo
decl_stmt|;
comment|/* ptr to a structure holding 					 * layout-specific params */
block|}
struct|;
end_struct

begin_comment
comment|/*****************************************************************************************  *  * The mapping code returns a pointer to a list of AccessStripeMap structures, which  * describes all the mapping information about an access.  The list contains one  * AccessStripeMap structure per stripe touched by the access.  Each element in the list  * contains a stripe identifier and a pointer to a list of PhysDiskAddr structuress.  Each  * element in this latter list describes the physical location of a stripe unit accessed  * within the corresponding stripe.  *  ****************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|RF_PDA_TYPE_DATA
value|0
end_define

begin_define
define|#
directive|define
name|RF_PDA_TYPE_PARITY
value|1
end_define

begin_define
define|#
directive|define
name|RF_PDA_TYPE_Q
value|2
end_define

begin_struct
struct|struct
name|RF_PhysDiskAddr_s
block|{
name|RF_RowCol_t
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* disk identifier */
name|RF_SectorNum_t
name|startSector
decl_stmt|;
comment|/* sector offset into the disk */
name|RF_SectorCount_t
name|numSector
decl_stmt|;
comment|/* number of sectors accessed */
name|int
name|type
decl_stmt|;
comment|/* used by higher levels: currently, data, 				 * parity, or q */
name|caddr_t
name|bufPtr
decl_stmt|;
comment|/* pointer to buffer supplying/receiving data */
name|RF_RaidAddr_t
name|raidAddress
decl_stmt|;
comment|/* raid address corresponding to this 					 * physical disk address */
name|RF_PhysDiskAddr_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_MAX_FAILED_PDA
value|RF_MAXCOL
end_define

begin_struct
struct|struct
name|RF_AccessStripeMap_s
block|{
name|RF_StripeNum_t
name|stripeID
decl_stmt|;
comment|/* the stripe index */
name|RF_RaidAddr_t
name|raidAddress
decl_stmt|;
comment|/* the starting raid address within 					 * this stripe */
name|RF_RaidAddr_t
name|endRaidAddress
decl_stmt|;
comment|/* raid address one sector past the 					 * end of the access */
name|RF_SectorCount_t
name|totalSectorsAccessed
decl_stmt|;
comment|/* total num sectors 						 * identified in physInfo list */
name|RF_StripeCount_t
name|numStripeUnitsAccessed
decl_stmt|;
comment|/* total num elements in 							 * physInfo list */
name|int
name|numDataFailed
decl_stmt|;
comment|/* number of failed data disks accessed */
name|int
name|numParityFailed
decl_stmt|;
comment|/* number of failed parity disks accessed (0 				 * or 1) */
name|int
name|numQFailed
decl_stmt|;
comment|/* number of failed Q units accessed (0 or 1) */
name|RF_AccessStripeMapFlags_t
name|flags
decl_stmt|;
comment|/* various flags */
if|#
directive|if
literal|0
block|RF_PhysDiskAddr_t *failedPDA;
comment|/* points to the PDA that has failed */
block|RF_PhysDiskAddr_t *failedPDAtwo;
comment|/* points to the second PDA 						 * that has failed, if any */
else|#
directive|else
name|int
name|numFailedPDAs
decl_stmt|;
comment|/* number of failed phys addrs */
name|RF_PhysDiskAddr_t
modifier|*
name|failedPDAs
index|[
name|RF_MAX_FAILED_PDA
index|]
decl_stmt|;
comment|/* array of failed phys 								 * addrs */
endif|#
directive|endif
name|RF_PhysDiskAddr_t
modifier|*
name|physInfo
decl_stmt|;
comment|/* a list of PhysDiskAddr structs */
name|RF_PhysDiskAddr_t
modifier|*
name|parityInfo
decl_stmt|;
comment|/* list of physical addrs for the 					 * parity (P of P + Q ) */
name|RF_PhysDiskAddr_t
modifier|*
name|qInfo
decl_stmt|;
comment|/* list of physical addrs for the Q of 					 * P + Q */
name|RF_LockReqDesc_t
name|lockReqDesc
decl_stmt|;
comment|/* used for stripe locking */
name|RF_RowCol_t
name|origRow
decl_stmt|;
comment|/* the original row:  we may redirect the acc 				 * to a different row */
name|RF_AccessStripeMap_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flag values */
end_comment

begin_define
define|#
directive|define
name|RF_ASM_REDIR_LARGE_WRITE
value|0x00000001
end_define

begin_comment
comment|/* allows large-write creation 						 * code to redirect failed 						 * accs */
end_comment

begin_define
define|#
directive|define
name|RF_ASM_BAILOUT_DAG_USED
value|0x00000002
end_define

begin_comment
comment|/* allows us to detect 						 * recursive calls to the 						 * bailout write dag */
end_comment

begin_define
define|#
directive|define
name|RF_ASM_FLAGS_LOCK_TRIED
value|0x00000004
end_define

begin_comment
comment|/* we've acquired the lock on 						 * the first parity range in 						 * this parity stripe */
end_comment

begin_define
define|#
directive|define
name|RF_ASM_FLAGS_LOCK_TRIED2
value|0x00000008
end_define

begin_comment
comment|/* we've acquired the lock on 						 * the 2nd   parity range in 						 * this parity stripe */
end_comment

begin_define
define|#
directive|define
name|RF_ASM_FLAGS_FORCE_TRIED
value|0x00000010
end_define

begin_comment
comment|/* we've done the force-recon 						 * call on this parity stripe */
end_comment

begin_define
define|#
directive|define
name|RF_ASM_FLAGS_RECON_BLOCKED
value|0x00000020
end_define

begin_comment
comment|/* we blocked recon => we must 						 * unblock it later */
end_comment

begin_struct
struct|struct
name|RF_AccessStripeMapHeader_s
block|{
name|RF_StripeCount_t
name|numStripes
decl_stmt|;
comment|/* total number of stripes touched by 					 * this acc */
name|RF_AccessStripeMap_t
modifier|*
name|stripeMap
decl_stmt|;
comment|/* pointer to the actual map. 						 * Also used for making lists */
name|RF_AccessStripeMapHeader_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*****************************************************************************************  *  * various routines mapping addresses in the RAID address space.  These work across  * all layouts.  DON'T PUT ANY LAYOUT-SPECIFIC CODE HERE.  *  ****************************************************************************************/
end_comment

begin_comment
comment|/* return the identifier of the stripe containing the given address */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressToStripeID
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( ((_addr_) / (_layoutPtr_)->sectorsPerStripeUnit) / (_layoutPtr_)->numDataCol )
end_define

begin_comment
comment|/* return the raid address of the start of the indicates stripe ID */
end_comment

begin_define
define|#
directive|define
name|rf_StripeIDToRaidAddress
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_sid_
parameter_list|)
define|\
value|( ((_sid_) * (_layoutPtr_)->sectorsPerStripeUnit) * (_layoutPtr_)->numDataCol )
end_define

begin_comment
comment|/* return the identifier of the stripe containing the given stripe unit id */
end_comment

begin_define
define|#
directive|define
name|rf_StripeUnitIDToStripeID
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (_addr_) / (_layoutPtr_)->numDataCol )
end_define

begin_comment
comment|/* return the identifier of the stripe unit containing the given address */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressToStripeUnitID
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( ((_addr_) / (_layoutPtr_)->sectorsPerStripeUnit) )
end_define

begin_comment
comment|/* return the RAID address of next stripe boundary beyond the given address */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressOfNextStripeBoundary
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (((_addr_)/(_layoutPtr_)->dataSectorsPerStripe)+1) * (_layoutPtr_)->dataSectorsPerStripe )
end_define

begin_comment
comment|/* return the RAID address of the start of the stripe containing the given address */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressOfPrevStripeBoundary
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (((_addr_)/(_layoutPtr_)->dataSectorsPerStripe)+0) * (_layoutPtr_)->dataSectorsPerStripe )
end_define

begin_comment
comment|/* return the RAID address of next stripe unit boundary beyond the given address */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressOfNextStripeUnitBoundary
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (((_addr_)/(_layoutPtr_)->sectorsPerStripeUnit)+1L)*(_layoutPtr_)->sectorsPerStripeUnit )
end_define

begin_comment
comment|/* return the RAID address of the start of the stripe unit containing RAID address _addr_ */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressOfPrevStripeUnitBoundary
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (((_addr_)/(_layoutPtr_)->sectorsPerStripeUnit)+0)*(_layoutPtr_)->sectorsPerStripeUnit )
end_define

begin_comment
comment|/* returns the offset into the stripe.  used by RaidAddressStripeAligned */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressStripeOffset
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (_addr_) % ((_layoutPtr_)->dataSectorsPerStripe) )
end_define

begin_comment
comment|/* returns the offset into the stripe unit.  */
end_comment

begin_define
define|#
directive|define
name|rf_StripeUnitOffset
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (_addr_) % ((_layoutPtr_)->sectorsPerStripeUnit) )
end_define

begin_comment
comment|/* returns nonzero if the given RAID address is stripe-aligned */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressStripeAligned
parameter_list|(
name|__layoutPtr__
parameter_list|,
name|__addr__
parameter_list|)
define|\
value|( rf_RaidAddressStripeOffset(__layoutPtr__, __addr__) == 0 )
end_define

begin_comment
comment|/* returns nonzero if the given address is stripe-unit aligned */
end_comment

begin_define
define|#
directive|define
name|rf_StripeUnitAligned
parameter_list|(
name|__layoutPtr__
parameter_list|,
name|__addr__
parameter_list|)
define|\
value|( rf_StripeUnitOffset(__layoutPtr__, __addr__) == 0 )
end_define

begin_comment
comment|/* convert an address expressed in RAID blocks to/from an addr expressed in bytes */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressToByte
parameter_list|(
name|_raidPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (_addr_)<< ( (_raidPtr_)->logBytesPerSector ) )
end_define

begin_define
define|#
directive|define
name|rf_ByteToRaidAddress
parameter_list|(
name|_raidPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (_addr_)>> ( (_raidPtr_)->logBytesPerSector ) )
end_define

begin_comment
comment|/* convert a raid address to/from a parity stripe ID.  Conversion to raid address is easy,  * since we're asking for the address of the first sector in the parity stripe.  Conversion to a  * parity stripe ID is more complex, since stripes are not contiguously allocated in  * parity stripes.  */
end_comment

begin_define
define|#
directive|define
name|rf_RaidAddressToParityStripeID
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|,
name|_ru_num_
parameter_list|)
define|\
value|rf_MapStripeIDToParityStripeID( (_layoutPtr_), rf_RaidAddressToStripeID( (_layoutPtr_), (_addr_) ), (_ru_num_) )
end_define

begin_define
define|#
directive|define
name|rf_ParityStripeIDToRaidAddress
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_psid_
parameter_list|)
define|\
value|( (_psid_) * (_layoutPtr_)->SUsPerPU * (_layoutPtr_)->numDataCol * (_layoutPtr_)->sectorsPerStripeUnit )
end_define

begin_function_decl
name|RF_LayoutSW_t
modifier|*
name|rf_GetLayout
parameter_list|(
name|RF_ParityConfig_t
name|parityConfig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureLayout
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
name|RF_StripeNum_t
name|rf_MapStripeIDToParityStripeID
parameter_list|(
name|RF_RaidLayout_t
modifier|*
name|layoutPtr
parameter_list|,
name|RF_StripeNum_t
name|stripeID
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
comment|/* !_RF__RF_LAYOUT_H_ */
end_comment

end_unit

