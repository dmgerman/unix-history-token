begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_cc.h   @Description   FM PCD CC ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_CC_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_CC_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_pcd.h"
end_include

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Coarse classification defines                              */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|CC_MAX_NUM_OF_KEYS
value|(FM_PCD_MAX_NUM_OF_KEYS + 1)
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MACDST
value|0x00
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MACSRC
value|0x01
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_ETYPE
value|0x02
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_TCI1
value|0x03
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_TCI2
value|0x04
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MPLS1
value|0x06
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MPLS_LAST
value|0x07
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4DST1
value|0x08
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4DST2
value|0x16
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4IPTOS_TC1
value|0x09
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4IPTOS_TC2
value|0x17
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4PTYPE1
value|0x0A
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4PTYPE2
value|0x18
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4SRC1
value|0x0b
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4SRC2
value|0x19
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4SRC1_IPV4DST1
value|0x0c
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4SRC2_IPV4DST2
value|0x1a
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV4TTL
value|0x29
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPTOS_IPV6TC1_IPV6FLOW1
value|0x0d
end_define

begin_comment
comment|/*TODO - CLASS - what is it? TOS*/
end_comment

begin_define
define|#
directive|define
name|CC_PC_FF_IPTOS_IPV6TC2_IPV6FLOW2
value|0x1b
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6PTYPE1
value|0x0e
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6PTYPE2
value|0x1c
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6DST1
value|0x0f
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6DST2
value|0x1d
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6SRC1
value|0x10
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6SRC2
value|0x1e
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPV6HOP_LIMIT
value|0x2a
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPPID
value|0x24
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_IPDSCP
value|0x76
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_GREPTYPE
value|0x11
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MINENCAP_PTYPE
value|0x12
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MINENCAP_IPDST
value|0x13
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MINENCAP_IPSRC
value|0x14
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_MINENCAP_IPSRC_IPDST
value|0x15
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_L4PSRC
value|0x1f
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_L4PDST
value|0x20
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_L4PSRC_L4PDST
value|0x21
end_define

begin_define
define|#
directive|define
name|CC_PC_FF_PPPPID
value|0x05
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_SHIM1
value|0x22
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_SHIM2
value|0x23
end_define

begin_define
define|#
directive|define
name|CC_PC_GENERIC_WITHOUT_MASK
value|0x27
end_define

begin_define
define|#
directive|define
name|CC_PC_GENERIC_WITH_MASK
value|0x28
end_define

begin_define
define|#
directive|define
name|CC_PC_GENERIC_IC_GMASK
value|0x2B
end_define

begin_define
define|#
directive|define
name|CC_PC_GENERIC_IC_HASH_INDEXED
value|0x2C
end_define

begin_define
define|#
directive|define
name|CC_PC_GENERIC_IC_AGING_MASK
value|0x2D
end_define

begin_define
define|#
directive|define
name|CC_PR_OFFSET
value|0x25
end_define

begin_define
define|#
directive|define
name|CC_PR_WITHOUT_OFFSET
value|0x26
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_ETH_OFFSET
value|19
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_USER_DEFINED_SHIM1_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_USER_DEFINED_SHIM2_OFFSET
value|17
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_USER_LLC_SNAP_OFFSET
value|20
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_VLAN1_OFFSET
value|21
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_VLAN2_OFFSET
value|22
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_PPPOE_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_MPLS1_OFFSET
value|25
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_MPLS_LAST_OFFSET
value|26
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_IP1_OFFSET
value|27
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_IP_LAST_OFFSET
value|28
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_MINENC_OFFSET
value|28
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_L4_OFFSET
value|30
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_GRE_OFFSET
value|29
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_ETYPE_LAST_OFFSET
value|23
end_define

begin_define
define|#
directive|define
name|CC_PC_PR_NEXT_HEADER_OFFSET
value|31
end_define

begin_define
define|#
directive|define
name|CC_PC_ILLEGAL
value|0xff
end_define

begin_define
define|#
directive|define
name|CC_SIZE_ILLEGAL
value|0
end_define

begin_define
define|#
directive|define
name|FM_PCD_CC_KEYS_MATCH_TABLE_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_CC_AD_TABLE_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_CC_AD_ENTRY_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_CC_NUM_OF_KEYS
value|255
end_define

begin_define
define|#
directive|define
name|FM_PCD_CC_TREE_ADDR_ALIGN
value|256
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_CONTRL_FLOW_TYPE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_DATA_FLOW_TYPE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_PLCR_DIS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_EXTENDED_MODE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_NADEN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_STATISTICS_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_CONT_LOOKUP_TYPE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_CONT_LOOKUP_LCL_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_TYPE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_FLR_ADDR_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_COUNTERS_ADDR_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_NEXT_ACTION_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_NEXT_ACTION_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_NAD_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_OP_CODE
value|0x00000036
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_FLR_EN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_STATS_COND_EN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_BYPASS_TYPE
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_TYPE_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_OPCODE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_PROFILEID_FOR_CNTRL_SHIFT
value|16
end_define

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_VSP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_NO_OM_VSPE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_RESULT_VSP_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|FM_PCD_AD_NCSPFQIDM_MASK
value|0x80000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_define
define|#
directive|define
name|GLBL_MASK_FOR_HASH_INDEXED
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|CC_GLBL_MASK_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|CC_AGING_MASK_SIZE
value|4
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|ccPrivateInfo_t
typedef|;
end_typedef

begin_comment
comment|/**< private info of CC: */
end_comment

begin_define
define|#
directive|define
name|CC_PRIVATE_INFO_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CC_PRIVATE_INFO_IC_HASH_INDEX_LOOKUP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CC_PRIVATE_INFO_IC_HASH_EXACT_MATCH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CC_PRIVATE_INFO_IC_KEY_EXACT_MATCH
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CC_PRIVATE_INFO_IC_DEQ_FQID_INDEX_LOOKUP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CC_BUILD_AGING_MASK
parameter_list|(
name|numOfKeys
parameter_list|)
value|((((1LL<< ((numOfKeys) + 1)) - 1))<< (31 - (numOfKeys)))
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Memory map                                                 */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fqid
decl_stmt|;
specifier|volatile
name|uint32_t
name|plcrProfile
decl_stmt|;
specifier|volatile
name|uint32_t
name|nia
decl_stmt|;
specifier|volatile
name|uint32_t
name|res
decl_stmt|;
block|}
name|t_AdOfTypeResult
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|ccAdBase
decl_stmt|;
specifier|volatile
name|uint32_t
name|matchTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|pcAndOffsets
decl_stmt|;
specifier|volatile
name|uint32_t
name|gmask
decl_stmt|;
block|}
name|t_AdOfTypeContLookup
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|profileTableAddr
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
specifier|volatile
name|uint32_t
name|nextActionIndx
decl_stmt|;
specifier|volatile
name|uint32_t
name|statsTableAddr
decl_stmt|;
block|}
name|t_AdOfTypeStats
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
specifier|volatile
name|t_AdOfTypeResult
name|adResult
decl_stmt|;
specifier|volatile
name|t_AdOfTypeContLookup
name|adContLookup
decl_stmt|;
block|}
name|t_Ad
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*  Driver's internal structures                                       */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdStatsObj
block|{
name|t_Handle
name|h_StatsAd
decl_stmt|;
name|t_Handle
name|h_StatsCounters
decl_stmt|;
name|t_List
name|node
decl_stmt|;
block|}
name|t_FmPcdStatsObj
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|key
index|[
name|FM_PCD_MAX_SIZE_OF_KEY
index|]
decl_stmt|;
name|uint8_t
name|mask
index|[
name|FM_PCD_MAX_SIZE_OF_KEY
index|]
decl_stmt|;
name|t_FmPcdCcNextEngineParams
name|nextEngineParams
decl_stmt|;
name|uint32_t
name|requiredAction
decl_stmt|;
name|uint32_t
name|shadowAction
decl_stmt|;
name|t_FmPcdStatsObj
modifier|*
name|p_StatsObj
decl_stmt|;
block|}
name|t_FmPcdCcKeyAndNextEngineParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|p_Ad
decl_stmt|;
name|e_FmPcdEngine
name|fmPcdEngine
decl_stmt|;
name|bool
name|adAllocated
decl_stmt|;
name|bool
name|isTree
decl_stmt|;
name|uint32_t
name|myInfo
decl_stmt|;
name|t_List
modifier|*
name|h_CcNextNodesLst
decl_stmt|;
name|t_Handle
name|h_AdditionalInfo
decl_stmt|;
name|t_Handle
name|h_Node
decl_stmt|;
block|}
name|t_FmPcdModifyCcAdditionalParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|p_AdTableNew
decl_stmt|;
name|t_Handle
name|p_KeysMatchTableNew
decl_stmt|;
name|t_Handle
name|p_AdTableOld
decl_stmt|;
name|t_Handle
name|p_KeysMatchTableOld
decl_stmt|;
name|uint16_t
name|numOfKeys
decl_stmt|;
name|t_Handle
name|h_CurrentNode
decl_stmt|;
name|uint16_t
name|savedKeyIndex
decl_stmt|;
name|t_Handle
name|h_NodeForAdd
decl_stmt|;
name|t_Handle
name|h_NodeForRmv
decl_stmt|;
name|t_Handle
name|h_ManipForRmv
decl_stmt|;
name|t_Handle
name|h_ManipForAdd
decl_stmt|;
name|t_FmPcdStatsObj
modifier|*
name|p_StatsObjForRmv
decl_stmt|;
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_Handle
name|h_FrmReplicForAdd
decl_stmt|;
name|t_Handle
name|h_FrmReplicForRmv
decl_stmt|;
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|bool
name|tree
decl_stmt|;
name|t_FmPcdCcKeyAndNextEngineParams
name|keyAndNextEngineParams
index|[
name|CC_MAX_NUM_OF_KEYS
index|]
decl_stmt|;
block|}
name|t_FmPcdModifyCcKeyAdditionalParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Manip
decl_stmt|;
name|t_Handle
name|h_CcNode
decl_stmt|;
block|}
name|t_CcNextEngineInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|numOfKeys
decl_stmt|;
name|uint16_t
name|maxNumOfKeys
decl_stmt|;
name|bool
name|maskSupport
decl_stmt|;
name|uint32_t
name|keysMatchTableMaxSize
decl_stmt|;
name|e_FmPcdCcStatsMode
name|statisticsMode
decl_stmt|;
name|uint32_t
name|numOfStatsFLRs
decl_stmt|;
name|uint32_t
name|countersArraySize
decl_stmt|;
name|bool
name|isHashBucket
decl_stmt|;
comment|/**< Valid for match table node that is a bucket of a hash table only */
name|t_Handle
name|h_MissStatsCounters
decl_stmt|;
comment|/**< Valid for hash table node and match table that is a bucket;                                                          Holds the statistics counters allocated by the hash table and                                                          are shared by all hash table buckets; */
name|t_Handle
name|h_PrivMissStatsCounters
decl_stmt|;
comment|/**< Valid for match table node that is a bucket of a hash table only;                                                          Holds the statistics counters that were allocated for this node                                                          and replaced by the shared counters (allocated by the hash table); */
name|bool
name|statsEnForMiss
decl_stmt|;
comment|/**< Valid for hash table node only; TRUE is statistics are currently                                                          enabled for hash 'miss', FALSE otherwise; This parameter effects the                                                          returned statistics count to user, statistics AD always present for 'miss'                                                          for all hash buckets; */
name|bool
name|glblMaskUpdated
decl_stmt|;
name|t_Handle
name|p_GlblMask
decl_stmt|;
name|bool
name|lclMask
decl_stmt|;
name|uint8_t
name|parseCode
decl_stmt|;
name|uint8_t
name|offset
decl_stmt|;
name|uint8_t
name|prsArrayOffset
decl_stmt|;
name|bool
name|ctrlFlow
decl_stmt|;
name|uint16_t
name|owners
decl_stmt|;
name|uint8_t
name|ccKeySizeAccExtraction
decl_stmt|;
name|uint8_t
name|sizeOfExtraction
decl_stmt|;
name|uint8_t
name|glblMaskSize
decl_stmt|;
name|t_Handle
name|h_KeysMatchTable
decl_stmt|;
name|t_Handle
name|h_AdTable
decl_stmt|;
name|t_Handle
name|h_StatsAds
decl_stmt|;
name|t_Handle
name|h_TmpAd
decl_stmt|;
name|t_Handle
name|h_Ad
decl_stmt|;
name|t_Handle
name|h_StatsFLRs
decl_stmt|;
name|t_List
name|availableStatsLst
decl_stmt|;
name|t_List
name|ccPrevNodesLst
decl_stmt|;
name|t_List
name|ccTreeIdLst
decl_stmt|;
name|t_List
name|ccTreesLst
decl_stmt|;
name|t_Handle
name|h_FmPcd
decl_stmt|;
name|uint32_t
name|shadowAction
decl_stmt|;
name|uint8_t
name|userSizeOfExtraction
decl_stmt|;
name|uint8_t
name|userOffset
decl_stmt|;
name|uint8_t
name|kgHashShift
decl_stmt|;
comment|/* used in hash-table */
name|t_Handle
name|h_Spinlock
decl_stmt|;
name|t_FmPcdCcKeyAndNextEngineParams
name|keyAndNextEngineParams
index|[
name|CC_MAX_NUM_OF_KEYS
index|]
decl_stmt|;
block|}
name|t_FmPcdCcNode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmPcdCcNode
modifier|*
name|p_FmPcdCcNode
decl_stmt|;
name|bool
name|occupied
decl_stmt|;
name|uint16_t
name|owners
decl_stmt|;
specifier|volatile
name|bool
name|lock
decl_stmt|;
block|}
name|t_FmPcdCcNodeArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|numOfEntriesInGroup
decl_stmt|;
name|uint32_t
name|totalBitsMask
decl_stmt|;
name|uint8_t
name|baseGroupEntry
decl_stmt|;
block|}
name|t_FmPcdCcGroupParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_FmPcd
decl_stmt|;
name|uint8_t
name|netEnvId
decl_stmt|;
name|uintptr_t
name|ccTreeBaseAddr
decl_stmt|;
name|uint8_t
name|numOfGrps
decl_stmt|;
name|t_FmPcdCcGroupParam
name|fmPcdGroupParam
index|[
name|FM_PCD_MAX_NUM_OF_CC_GROUPS
index|]
decl_stmt|;
name|t_List
name|fmPortsLst
decl_stmt|;
name|t_FmPcdLock
modifier|*
name|p_Lock
decl_stmt|;
name|uint8_t
name|numOfEntries
decl_stmt|;
name|uint16_t
name|owners
decl_stmt|;
name|t_Handle
name|h_FmPcdCcSavedManipParams
decl_stmt|;
name|bool
name|modifiedState
decl_stmt|;
name|uint32_t
name|requiredAction
decl_stmt|;
name|t_Handle
name|h_IpReassemblyManip
decl_stmt|;
name|t_Handle
name|h_CapwapReassemblyManip
decl_stmt|;
name|t_FmPcdCcKeyAndNextEngineParams
name|keyAndNextEngineParams
index|[
name|FM_PCD_MAX_NUM_OF_CC_GROUPS
index|]
decl_stmt|;
block|}
name|t_FmPcdCcTree
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|FmPcdCcNodeTreeTryLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|t_List
modifier|*
name|p_List
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdCcNodeTreeReleaseLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_List
modifier|*
name|p_List
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdUpdateCcShadow
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint32_t
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_CC_H */
end_comment

end_unit

