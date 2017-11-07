begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          bm.h   @Description   BM header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BM_H
end_ifndef

begin_define
define|#
directive|define
name|__BM_H
end_define

begin_include
include|#
directive|include
file|"xx_common.h"
end_include

begin_include
include|#
directive|include
file|"bm_ext.h"
end_include

begin_include
include|#
directive|include
file|"mm_ext.h"
end_include

begin_include
include|#
directive|include
file|"bman_private.h"
end_include

begin_include
include|#
directive|include
file|"bm_ipc.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_BM
end_define

begin_define
define|#
directive|define
name|BM_NUM_OF_POOLS
value|64
end_define

begin_define
define|#
directive|define
name|BM_NUM_OF_PM
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BM_EX_INVALID_COMMAND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BM_EX_FBPR_THRESHOLD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BM_EX_MULTI_ECC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BM_EX_SINGLE_ECC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BM_EX_POOLS_AVAIL_STATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GET_EXCEPTION_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|exception
parameter_list|)
define|\
value|switch(exception){                                                      \     case e_BM_EX_INVALID_COMMAND:                                       \         bitMask = BM_EX_INVALID_COMMAND; break;                         \     case e_BM_EX_FBPR_THRESHOLD:                                        \         bitMask = BM_EX_FBPR_THRESHOLD; break;                          \     case e_BM_EX_SINGLE_ECC:                                            \         bitMask = BM_EX_SINGLE_ECC; break;                              \     case e_BM_EX_MULTI_ECC:                                             \         bitMask = BM_EX_MULTI_ECC; break;                               \     default: bitMask = 0;break;                                         \ }
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* BM defaults */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|(BM_EX_INVALID_COMMAND      |\                                             BM_EX_FBPR_THRESHOLD        |\                                             BM_EX_MULTI_ECC             |\                                             BM_EX_SINGLE_ECC            )
end_define

begin_define
define|#
directive|define
name|DEFAULT_fbprThreshold
value|0
end_define

begin_comment
comment|/* BM-Portal defaults */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_memAttr
value|MEMORY_ATTR_CACHEABLE
end_define

begin_comment
comment|/* BM-Pool defaults */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_dynamicBpid
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_useDepletion
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_useStockpile
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_numOfBufsPerCmd
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Memory Mapped Registers */
end_comment

begin_comment
comment|/***************************************************************************/
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

begin_define
define|#
directive|define
name|MEM_MAP_START
end_define

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
comment|/* BMan Buffer Pool Configuration& Status Registers */
specifier|volatile
name|uint32_t
name|swdet
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< S/W Portal depletion entry threshold */
specifier|volatile
name|uint32_t
name|hwdet
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< H/W Portal depletion entry threshold */
specifier|volatile
name|uint32_t
name|swdxt
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< S/W Portal depletion exit threshold */
specifier|volatile
name|uint32_t
name|hwdxt
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< H/W Portal depletion exit threshold */
specifier|volatile
name|uint32_t
name|sdcnt
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< S/W Portal depletion count */
specifier|volatile
name|uint32_t
name|hdcnt
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< H/W Portal depletion count */
specifier|volatile
name|uint32_t
name|content
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< Snapshot of buffer count in Pool */
specifier|volatile
name|uint32_t
name|hdptr
index|[
name|BM_NUM_OF_POOLS
index|]
decl_stmt|;
comment|/**< Head Pointer for Pool's FBPR list. */
comment|/* Free Buffer Proxy Record (FBPR) Manager Query Registers */
specifier|volatile
name|uint32_t
name|fbpr_fpc
decl_stmt|;
comment|/**< FBPR Free Pool Count */
specifier|volatile
name|uint32_t
name|fbpr_fp_lwit
decl_stmt|;
comment|/**< FBPR Free Pool Low Watermark Interrupt Threshold  */
specifier|volatile
name|uint8_t
name|res1
index|[
literal|248
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* Performance Monitor (PM) Configuration Register */
specifier|volatile
name|uint32_t
name|cmd_pm_cfg
index|[
name|BM_NUM_OF_PM
index|]
decl_stmt|;
comment|/**< BMan Command Performance Monitor configuration registers. */
specifier|volatile
name|uint32_t
name|fl_pm_cfg
index|[
name|BM_NUM_OF_PM
index|]
decl_stmt|;
comment|/**< BMan Free List Performance Monitor configuration registers */
specifier|volatile
name|uint8_t
name|res2
index|[
literal|192
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* BMan Error Capture Registers */
specifier|volatile
name|uint32_t
name|ecsr
decl_stmt|;
comment|/**< BMan Error Capture Status Register */
specifier|volatile
name|uint32_t
name|ecir
decl_stmt|;
comment|/**< BMan Error Capture Information Register */
specifier|volatile
name|uint32_t
name|eadr
decl_stmt|;
comment|/**< BMan Error Capture Address Register */
specifier|volatile
name|uint8_t
name|res3
index|[
literal|4
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|edata
index|[
literal|8
index|]
decl_stmt|;
comment|/**< BMan ECC Error Data Register */
specifier|volatile
name|uint32_t
name|sbet
decl_stmt|;
comment|/**< BMan Single Bit ECC Error Threshold Register */
specifier|volatile
name|uint32_t
name|efcr
decl_stmt|;
comment|/**< BMan Error Fetch Capture Register */
specifier|volatile
name|uint32_t
name|efar
decl_stmt|;
comment|/**< BMan Error Fetch Address Register */
specifier|volatile
name|uint8_t
name|res4
index|[
literal|68
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|sbec0
decl_stmt|;
comment|/**< BMan Single Bit ECC Error Count 0 Register */
specifier|volatile
name|uint32_t
name|sbec1
decl_stmt|;
comment|/**< BMan Single Bit ECC Error Count 1 Register */
specifier|volatile
name|uint8_t
name|res5
index|[
literal|368
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* BMan ID/Revision Registers */
specifier|volatile
name|uint32_t
name|ip_rev_1
decl_stmt|;
comment|/**< BMan IP Block Revision 1 register */
specifier|volatile
name|uint32_t
name|ip_rev_2
decl_stmt|;
comment|/**< BMan IP Block Revision 2 register */
comment|/* CoreNet Initiator Interface Memory Window Configuration Registers */
specifier|volatile
name|uint32_t
name|fbpr_bare
decl_stmt|;
comment|/**< Data Structure Extended Base Address Register */
specifier|volatile
name|uint32_t
name|fbpr_bar
decl_stmt|;
comment|/**< Data Structure Base Address Register */
specifier|volatile
name|uint8_t
name|res6
index|[
literal|8
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|fbpr_ar
decl_stmt|;
comment|/**< Data Structure Attributes Register */
specifier|volatile
name|uint8_t
name|res7
index|[
literal|240
index|]
decl_stmt|;
comment|/**< reserved */
specifier|volatile
name|uint32_t
name|srcidr
decl_stmt|;
comment|/**< BMan Source ID Register */
specifier|volatile
name|uint32_t
name|liodnr
decl_stmt|;
comment|/**< BMan Logical I/O Device Number Register */
specifier|volatile
name|uint8_t
name|res8
index|[
literal|244
index|]
decl_stmt|;
comment|/**< reserved */
comment|/* BMan Interrupt and Error Registers */
specifier|volatile
name|uint32_t
name|err_isr
decl_stmt|;
comment|/**< BMan Error Interrupt Status Register */
specifier|volatile
name|uint32_t
name|err_ier
decl_stmt|;
comment|/**< BMan Error Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|err_isdr
decl_stmt|;
comment|/**< BMan Error Interrupt Status Disable Register */
specifier|volatile
name|uint32_t
name|err_iir
decl_stmt|;
comment|/**< BMan Error Interrupt Inhibit Register */
specifier|volatile
name|uint32_t
name|err_ifr
decl_stmt|;
comment|/**< BMan Error Interrupt Force Register */
block|}
name|_PackedType
name|t_BmRegs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEM_MAP_END
end_define

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
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       General defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MODULE_NAME_SIZE
value|30
end_define

begin_define
define|#
directive|define
name|FBPR_ENTRY_SIZE
value|64
end_define

begin_comment
comment|/* 64 bytes */
end_comment

begin_comment
comment|/* Compilation constants */
end_comment

begin_define
define|#
directive|define
name|RCR_THRESH
value|2
end_define

begin_comment
comment|/* reread h/w CI when running out of space */
end_comment

begin_define
define|#
directive|define
name|RCR_ITHRESH
value|4
end_define

begin_comment
comment|/* if RCR congests, interrupt threshold */
end_comment

begin_comment
comment|/* Lock/unlock portals, subject to "UNLOCKED" flag */
end_comment

begin_define
define|#
directive|define
name|NCSW_PLOCK
parameter_list|(
name|p
parameter_list|)
value|((t_BmPortal*)(p))->irq_flags = XX_DisableAllIntr()
end_define

begin_define
define|#
directive|define
name|PUNLOCK
parameter_list|(
name|p
parameter_list|)
value|XX_RestoreAllIntr(((t_BmPortal*)(p))->irq_flags)
end_define

begin_define
define|#
directive|define
name|BM_RCR_RING
value|0
end_define

begin_define
define|#
directive|define
name|BM_NUM_OF_RINGS
value|1
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Register defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|REV1_MAJOR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|REV1_MINOR_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|REV2_INTEG_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|REV2_ERR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|REV2_CFG_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_PRIORITY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_SIZE_MASK
value|0x0000003f
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|REV1_MAJOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|REV1_MINOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|REV2_INTEG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|REV2_ERR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|REV2_CFG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR_SIZE_SHIFT
value|0
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|bmRingType_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|t_BmUpdateCb
function_decl|)
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|p_BmPortalLow
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_BmPrefetchCb
function_decl|)
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|p_BmPortalLow
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_BmCommitCb
function_decl|)
parameter_list|(
name|struct
name|bm_portal
modifier|*
name|p_BmPortalLow
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|useStockpile
decl_stmt|;
comment|/**<  */
name|bool
name|dynamicBpid
decl_stmt|;
comment|/**< boolean indicates use of dynamic Bpid */
name|bool
name|useDepletion
decl_stmt|;
comment|/**< boolean indicates use of depletion */
name|uint32_t
name|depletionThresholds
index|[
name|MAX_DEPLETION_THRESHOLDS
index|]
decl_stmt|;
comment|/**< depletion-entry/exit thresholds, if useThresholds is set. NB:                                                          this is only allowed if useThresholds is used and                                                          when run in the control plane (which controls Bman CCSR) */
block|}
name|t_BmPoolDriverParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|BmPool
block|{
name|uint8_t
name|bpid
decl_stmt|;
comment|/**< index of the buffer pool to encapsulate (0-63) */
name|t_Handle
name|h_Bm
decl_stmt|;
name|t_Handle
name|h_BmPortal
decl_stmt|;
name|bool
name|shadowMode
decl_stmt|;
name|uint32_t
name|numOfBuffers
decl_stmt|;
comment|/**< Number of buffers use by this pool */
name|t_BufferPoolInfo
name|bufferPoolInfo
decl_stmt|;
comment|/**< Data buffers pool information */
name|uint32_t
name|flags
decl_stmt|;
comment|/**< bit-mask of BMAN_POOL_FLAG_*** options */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< opaque user value passed as a parameter to 'cb' */
name|t_BmDepletionCallback
modifier|*
name|f_Depletion
decl_stmt|;
comment|/**< depletion-entry/exit callback, if BMAN_POOL_FLAG_DEPLETION is set */
name|uint32_t
name|swDepletionCount
decl_stmt|;
name|uint32_t
name|hwDepletionCount
decl_stmt|;
comment|/* stockpile state - NULL unless BMAN_POOL_FLAG_STOCKPILE is set */
name|struct
name|bm_buffer
modifier|*
name|sp
decl_stmt|;
name|uint16_t
name|spFill
decl_stmt|;
name|uint8_t
name|spBufsCmd
decl_stmt|;
name|uint16_t
name|spMaxBufs
decl_stmt|;
name|uint16_t
name|spMinBufs
decl_stmt|;
name|bool
name|noBuffCtxt
decl_stmt|;
name|t_BmPoolDriverParams
modifier|*
name|p_BmPoolDriverParams
decl_stmt|;
block|}
name|t_BmPool
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_BmUpdateCb
modifier|*
name|f_BmUpdateCb
decl_stmt|;
name|t_BmPrefetchCb
modifier|*
name|f_BmPrefetchCb
decl_stmt|;
name|t_BmCommitCb
modifier|*
name|f_BmCommitCb
decl_stmt|;
block|}
name|t_BmPortalCallbacks
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|hwExtStructsMemAttr
decl_stmt|;
name|struct
name|bman_depletion
name|mask
decl_stmt|;
block|}
name|t_BmPortalDriverParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Bm
decl_stmt|;
name|struct
name|bm_portal
modifier|*
name|p_BmPortalLow
decl_stmt|;
name|t_BmPortalCallbacks
name|cbs
index|[
name|BM_NUM_OF_RINGS
index|]
decl_stmt|;
name|uintptr_t
name|irq
decl_stmt|;
name|int
name|cpu
decl_stmt|;
comment|/* This is used for any "core-affine" portals, ie. default portals                                   * associated to the corresponding cpu. -1 implies that there is no core                                   * affinity configured. */
name|struct
name|bman_depletion
name|pools
index|[
literal|2
index|]
decl_stmt|;
comment|/**< 2-element array. pools[0] is mask, pools[1] is snapshot. */
name|uint32_t
name|flags
decl_stmt|;
comment|/**< BMAN_PORTAL_FLAG_*** - static, caller-provided */
name|uint32_t
name|irq_flags
decl_stmt|;
name|int
name|thresh_set
decl_stmt|;
name|uint32_t
name|slowpoll
decl_stmt|;
name|uint32_t
name|rcrProd
decl_stmt|;
comment|/**< The wrap-around rcr_[prod|cons] counters are used to support BMAN_RELEASE_FLAG_WAIT_SYNC. */
name|uint32_t
name|rcrCons
decl_stmt|;
comment|/**< 64-entry hash-table of pool objects that are tracking depletion      * entry/exit (ie. BMAN_POOL_FLAG_DEPLETION). This isn't fast-path, so      * we're not fussy about cache-misses and so forth - whereas the above      * members should all fit in one cacheline.      * BTW, with BM_MAX_NUM_OF_POOLS entries in the hash table and BM_MAX_NUM_OF_POOLS buffer pools to track,      * you'll never guess the hash-function ... */
name|t_BmPool
modifier|*
name|depletionPoolsTable
index|[
name|BM_MAX_NUM_OF_POOLS
index|]
decl_stmt|;
name|t_BmPortalDriverParams
modifier|*
name|p_BmPortalDriverParams
decl_stmt|;
block|}
name|t_BmPortal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|partBpidBase
decl_stmt|;
name|uint8_t
name|partNumOfPools
decl_stmt|;
name|uint32_t
name|totalNumOfBuffers
decl_stmt|;
comment|/**< total number of buffers */
name|uint32_t
name|fbprMemPartitionId
decl_stmt|;
name|uint32_t
name|fbprThreshold
decl_stmt|;
name|uint16_t
name|liodn
decl_stmt|;
block|}
name|t_BmDriverParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|guestId
decl_stmt|;
name|t_Handle
name|h_BpidMm
decl_stmt|;
name|t_Handle
name|h_SpinLock
decl_stmt|;
name|t_Handle
name|h_Portals
index|[
name|DPAA_MAX_NUM_OF_SW_PORTALS
index|]
decl_stmt|;
name|t_Handle
name|h_Session
decl_stmt|;
name|char
name|moduleName
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|t_BmRegs
modifier|*
name|p_BmRegs
decl_stmt|;
name|void
modifier|*
name|p_FbprBase
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|t_BmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|uintptr_t
name|errIrq
decl_stmt|;
comment|/**< error interrupt line; NO_IRQ if interrupts not used */
name|t_BmDriverParams
modifier|*
name|p_BmDriverParams
decl_stmt|;
block|}
name|t_Bm
typedef|;
end_typedef

begin_function
specifier|static
name|__inline__
name|void
name|BmSetPortalHandle
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|t_Handle
name|h_Portal
parameter_list|,
name|e_DpaaSwPortal
name|portalId
parameter_list|)
block|{
name|ASSERT_COND
argument_list|(
operator|!
operator|(
operator|(
name|t_Bm
operator|*
operator|)
name|h_Bm
operator|)
operator|->
name|h_Portals
index|[
name|portalId
index|]
operator|||
operator|!
name|h_Portal
argument_list|)
expr_stmt|;
operator|(
operator|(
name|t_Bm
operator|*
operator|)
name|h_Bm
operator|)
operator|->
name|h_Portals
index|[
name|portalId
index|]
operator|=
name|h_Portal
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|t_Handle
name|BmGetPortalHandle
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|)
block|{
name|t_Bm
modifier|*
name|p_Bm
init|=
operator|(
name|t_Bm
operator|*
operator|)
name|h_Bm
decl_stmt|;
name|ASSERT_COND
argument_list|(
name|p_Bm
argument_list|)
expr_stmt|;
return|return
name|p_Bm
operator|->
name|h_Portals
index|[
name|CORE_GetId
argument_list|()
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint8_t
name|BmUpdate
parameter_list|(
name|t_BmPortal
modifier|*
name|p_BmPortal
parameter_list|,
name|bmRingType_t
name|type
parameter_list|)
block|{
return|return
name|p_BmPortal
operator|->
name|cbs
index|[
name|type
index|]
operator|.
name|f_BmUpdateCb
argument_list|(
name|p_BmPortal
operator|->
name|p_BmPortalLow
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|BmPrefetch
parameter_list|(
name|t_BmPortal
modifier|*
name|p_BmPortal
parameter_list|,
name|bmRingType_t
name|type
parameter_list|)
block|{
if|if
condition|(
name|p_BmPortal
operator|->
name|cbs
index|[
name|type
index|]
operator|.
name|f_BmPrefetchCb
condition|)
name|p_BmPortal
operator|->
name|cbs
index|[
name|type
index|]
operator|.
name|f_BmPrefetchCb
argument_list|(
name|p_BmPortal
operator|->
name|p_BmPortalLow
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|BmCommit
parameter_list|(
name|t_BmPortal
modifier|*
name|p_BmPortal
parameter_list|,
name|bmRingType_t
name|type
parameter_list|,
name|uint8_t
name|myverb
parameter_list|)
block|{
name|p_BmPortal
operator|->
name|cbs
index|[
name|type
index|]
operator|.
name|f_BmCommitCb
argument_list|(
name|p_BmPortal
operator|->
name|p_BmPortalLow
argument_list|,
name|myverb
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|BmBpidGet
parameter_list|(
name|t_Bm
modifier|*
name|p_Bm
parameter_list|,
name|bool
name|force
parameter_list|,
name|uint32_t
name|base
parameter_list|)
block|{
name|uint64_t
name|ans
decl_stmt|,
name|size
init|=
literal|1
decl_stmt|;
name|uint64_t
name|alignment
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|force
condition|)
block|{
if|if
condition|(
name|MM_InRange
argument_list|(
name|p_Bm
operator|->
name|h_BpidMm
argument_list|,
operator|(
name|uint64_t
operator|)
name|base
argument_list|)
condition|)
block|{
name|ans
operator|=
name|MM_GetForce
argument_list|(
name|p_Bm
operator|->
name|h_BpidMm
argument_list|,
name|base
argument_list|,
name|size
argument_list|,
literal|"BM BPID MEM"
argument_list|)
expr_stmt|;
name|ans
operator|=
name|base
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|p_Bm
operator|->
name|h_Session
condition|)
block|{
name|t_BmIpcMsg
name|msg
decl_stmt|;
name|t_BmIpcReply
name|reply
decl_stmt|;
name|uint32_t
name|replyLength
decl_stmt|;
name|t_BmIpcBpidParams
name|ipcBpid
decl_stmt|;
name|t_Error
name|errCode
init|=
name|E_OK
decl_stmt|;
name|memset
argument_list|(
operator|&
name|msg
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|t_BmIpcMsg
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|reply
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|t_BmIpcReply
argument_list|)
argument_list|)
expr_stmt|;
name|ipcBpid
operator|.
name|bpid
operator|=
operator|(
name|uint8_t
operator|)
name|base
expr_stmt|;
name|msg
operator|.
name|msgId
operator|=
name|BM_FORCE_BPID
expr_stmt|;
name|memcpy
argument_list|(
name|msg
operator|.
name|msgBody
argument_list|,
operator|&
name|ipcBpid
argument_list|,
sizeof|sizeof
argument_list|(
name|t_BmIpcBpidParams
argument_list|)
argument_list|)
expr_stmt|;
name|replyLength
operator|=
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|errCode
operator|=
name|XX_IpcSendMessage
argument_list|(
name|p_Bm
operator|->
name|h_Session
argument_list|,
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
operator|.
name|msgId
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|t_BmIpcBpidParams
argument_list|)
argument_list|,
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|reply
argument_list|,
operator|&
name|replyLength
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
name|E_OK
condition|)
block|{
name|REPORT_ERROR
argument_list|(
name|MAJOR
argument_list|,
name|errCode
argument_list|,
name|NO_MSG
argument_list|)
expr_stmt|;
return|return
operator|(
name|uint32_t
operator|)
name|ILLEGAL_BASE
return|;
block|}
if|if
condition|(
name|replyLength
operator|!=
operator|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|)
condition|)
block|{
name|REPORT_ERROR
argument_list|(
name|MAJOR
argument_list|,
name|E_INVALID_VALUE
argument_list|,
operator|(
literal|"IPC reply length mismatch"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|uint32_t
operator|)
name|ILLEGAL_BASE
return|;
block|}
name|memcpy
argument_list|(
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|ans
argument_list|,
name|reply
operator|.
name|replyBody
argument_list|,
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DBG
argument_list|(
name|WARNING
argument_list|,
operator|(
literal|"No Ipc - can't validate bpid."
operator|)
argument_list|)
expr_stmt|;
name|ans
operator|=
name|base
expr_stmt|;
block|}
block|}
else|else
name|ans
operator|=
name|MM_Get
argument_list|(
name|p_Bm
operator|->
name|h_BpidMm
argument_list|,
name|size
argument_list|,
name|alignment
argument_list|,
literal|"BM BPID MEM"
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|ans
operator|<
name|UINT32_MAX
argument_list|,
operator|(
literal|"Oops, %lx> UINT32_MAX!\n"
operator|,
name|ans
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|uint32_t
operator|)
name|ans
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|t_Error
name|BmBpidPut
parameter_list|(
name|t_Bm
modifier|*
name|p_Bm
parameter_list|,
name|uint32_t
name|base
parameter_list|)
block|{
if|if
condition|(
name|MM_InRange
argument_list|(
name|p_Bm
operator|->
name|h_BpidMm
argument_list|,
operator|(
name|uint64_t
operator|)
name|base
argument_list|)
condition|)
block|{
if|if
condition|(
name|MM_Put
argument_list|(
name|p_Bm
operator|->
name|h_BpidMm
argument_list|,
operator|(
name|uint64_t
operator|)
name|base
argument_list|)
operator|!=
name|base
condition|)
return|return
name|E_OK
return|;
else|else
return|return
name|ERROR_CODE
argument_list|(
name|E_NOT_FOUND
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|p_Bm
operator|->
name|h_Session
condition|)
block|{
name|t_BmIpcMsg
name|msg
decl_stmt|;
name|t_BmIpcBpidParams
name|ipcBpid
decl_stmt|;
name|t_Error
name|errCode
init|=
name|E_OK
decl_stmt|;
name|memset
argument_list|(
operator|&
name|msg
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|t_BmIpcMsg
argument_list|)
argument_list|)
expr_stmt|;
name|ipcBpid
operator|.
name|bpid
operator|=
operator|(
name|uint8_t
operator|)
name|base
expr_stmt|;
name|msg
operator|.
name|msgId
operator|=
name|BM_PUT_BPID
expr_stmt|;
name|memcpy
argument_list|(
name|msg
operator|.
name|msgBody
argument_list|,
operator|&
name|ipcBpid
argument_list|,
sizeof|sizeof
argument_list|(
name|t_BmIpcBpidParams
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|errCode
operator|=
name|XX_IpcSendMessage
argument_list|(
name|p_Bm
operator|->
name|h_Session
argument_list|,
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
operator|.
name|msgId
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|t_BmIpcBpidParams
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|!=
name|E_OK
condition|)
name|RETURN_ERROR
argument_list|(
name|MAJOR
argument_list|,
name|errCode
argument_list|,
name|NO_MSG
argument_list|)
expr_stmt|;
block|}
else|else
name|DBG
argument_list|(
name|WARNING
argument_list|,
operator|(
literal|"No Ipc - can't validate bpid."
operator|)
argument_list|)
expr_stmt|;
return|return
name|E_OK
return|;
block|}
end_function

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/*       Inter-Module functions        */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_BmInterModuleCounters
block|{
name|e_BM_IM_COUNTERS_FBPR
init|=
literal|0
block|,
name|e_BM_IM_COUNTERS_POOL_CONTENT
block|,
name|e_BM_IM_COUNTERS_POOL_SW_DEPLETION
block|,
name|e_BM_IM_COUNTERS_POOL_HW_DEPLETION
block|}
name|e_BmInterModuleCounters
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|BmSetPoolThresholds
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|uint8_t
name|bpid
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|thresholds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|BmUnSetPoolThresholds
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|BmPortalAcquire
parameter_list|(
name|t_Handle
name|h_BmPortal
parameter_list|,
name|uint8_t
name|bpid
parameter_list|,
name|struct
name|bm_buffer
modifier|*
name|bufs
parameter_list|,
name|uint8_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|BmPortalRelease
parameter_list|(
name|t_Handle
name|h_BmPortal
parameter_list|,
name|uint8_t
name|bpid
parameter_list|,
name|struct
name|bm_buffer
modifier|*
name|bufs
parameter_list|,
name|uint8_t
name|num
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|BmPortalQuery
parameter_list|(
name|t_Handle
name|h_BmPortal
parameter_list|,
name|struct
name|bman_depletion
modifier|*
name|p_Pools
parameter_list|,
name|bool
name|depletion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|BmGetCounter
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|e_BmInterModuleCounters
name|counter
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|BmGetRevision
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|t_BmRevisionInfo
modifier|*
name|p_BmRevisionInfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BM_H */
end_comment

end_unit

