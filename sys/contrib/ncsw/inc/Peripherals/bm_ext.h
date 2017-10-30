begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          bm_ext.h   @Description   BM API */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BM_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__BM_EXT_H
end_define

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_grp Buffer Manager API   @Description   BM API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   This callback type is used when handling pool depletion entry/exit.                  User provides this function. Driver invokes it.   @Param[in]     h_App       - User's application descriptor.  @Param[in]     in          - TRUE when entered depletion state                               FALSE when exit the depletion state.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_BmDepletionCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|bool
name|in
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_lib_grp BM common API   @Description   BM common API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   BM Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_BmExceptions
block|{
name|e_BM_EX_INVALID_COMMAND
init|=
literal|0
block|,
comment|/**< Invalid Command Verb Interrupt */
name|e_BM_EX_FBPR_THRESHOLD
block|,
comment|/**< FBPR Low Watermark Interrupt. */
name|e_BM_EX_SINGLE_ECC
block|,
comment|/**< Single Bit ECC Error Interrupt. */
name|e_BM_EX_MULTI_ECC
comment|/**< Multi Bit ECC Error Interrupt */
block|}
name|e_BmExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_init_grp BM (common) Initialization Unit   @Description   BM (common) Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_BmExceptionsCallback   @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App      - User's application descriptor.  @Param[in]     exception  - The exception. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_BmExceptionsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_BmExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing BM initialization parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|guestId
decl_stmt|;
comment|/**< BM Partition Id */
name|uintptr_t
name|baseAddress
decl_stmt|;
comment|/**< Bm base address (virtual).                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|uint16_t
name|liodn
decl_stmt|;
comment|/**< This value is attached to every transaction initiated by                                                          BMan when accessing its private data structures                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|uint32_t
name|totalNumOfBuffers
decl_stmt|;
comment|/**< Total number of buffers                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|uint32_t
name|fbprMemPartitionId
decl_stmt|;
comment|/**< FBPR's mem partition id;                                                          NOTE: The memory partition must be non-cacheable and no-coherent area.                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|t_BmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< An application callback routine to handle exceptions.                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                          be passed by the driver upon calling the above callbacks.                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|uintptr_t
name|errIrq
decl_stmt|;
comment|/**< BM error interrupt line; NO_IRQ if interrupts not used.                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|uint8_t
name|partBpidBase
decl_stmt|;
comment|/**< The first buffer-pool-id dedicated to this partition.                                                          NOTE: this parameter relevant only when working with multiple partitions. */
name|uint8_t
name|partNumOfPools
decl_stmt|;
comment|/**< Number of Pools dedicated to this partition.                                                          NOTE: this parameter relevant only when working with multiple partitions. */
block|}
name|t_BmParam
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_Config   @Description   Creates descriptor for the BM module and initializes the BM module.                  The routine returns a handle (descriptor) to the BM object.                 This descriptor must be passed as first parameter to all other                 BM function calls.   @Param[in]     p_BmParam   - A pointer to data structure of parameters   @Return        Handle to BM object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|BM_Config
parameter_list|(
name|t_BmParam
modifier|*
name|p_BmParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_Init   @Description   Initializes the BM module   @Param[in]     h_Bm            - A handle to the BM module   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_Config(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_Init
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_Free   @Description   Frees all resources that were assigned to BM module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_Bm            - A handle to the BM module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_Free
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_advanced_init_grp    BM (common) Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_ConfigFbprThreshold   @Description   Change the fbpr threshold from its default                 configuration [0].                 An interrupt if enables is asserted when the number of FBPRs is below this threshold.                 NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID).   @Param[in]     h_Bm            - A handle to the BM module  @Param[in]     threshold       - threshold value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_Config() and before BM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_ConfigFbprThreshold
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|uint32_t
name|threshold
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_runtime_control_grp BM (common) Runtime Control Unit   @Description   BM (common) Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining BM counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_BmCounters
block|{
name|e_BM_COUNTERS_FBPR
init|=
literal|0
comment|/**< Total Free Buffer Proxy Record (FBPR) Free Pool Count in external memory */
block|}
name|e_BmCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for returning revision information */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_BmRevisionInfo
block|{
name|uint8_t
name|majorRev
decl_stmt|;
comment|/**< Major revision */
name|uint8_t
name|minorRev
decl_stmt|;
comment|/**< Minor revision */
block|}
name|t_BmRevisionInfo
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|&&
operator|(
name|DEBUG_ERRORS
operator|>
literal|0
operator|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_DumpRegs   @Description   Dumps all BM registers                 NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID).   @Param[in]     h_Bm      A handle to an BM Module.   @Return        E_OK on success;   @Cautions      Allowed only after BM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_DumpRegs
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_SetException   @Description   Calling this routine enables/disables the specified exception.                 NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID).   @Param[in]     h_Bm        - A handle to the BM Module.  @Param[in]     exception   - The exception to be selected.  @Param[in]     enable      - TRUE to enable interrupt, FALSE to mask it.   @Cautions      Allowed only following BM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_SetException
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|e_BmExceptions
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_ErrorIsr   @Description   BM interrupt-service-routine for errors.                 NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID).   @Param[in]     h_Bm        - A handle to the BM Module.   @Cautions      Allowed only following BM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|BM_ErrorIsr
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_GetCounter   @Description   Reads one of the BM counters.   @Param[in]     h_Bm        - A handle to the BM Module.  @Param[in]     counter     - The requested counter.   @Return        Counter's current value. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|BM_GetCounter
parameter_list|(
name|t_Handle
name|h_Bm
parameter_list|,
name|e_BmCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_GetRevision   @Description   Returns the BM revision   @Param[in]     h_Bm                A handle to a BM Module.  @Param[out]    p_BmRevisionInfo    A structure of revision information parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_GetRevision
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

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_runtime_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_lib_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_portal_grp BM-Portal API   @Description   BM-Portal API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_portal_init_grp BM-Portal Initialization Unit   @Description   BM-Portal Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing BM Portal initialization parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uintptr_t
name|ceBaseAddress
decl_stmt|;
comment|/**< Cache-enabled base address (virtual) */
name|uintptr_t
name|ciBaseAddress
decl_stmt|;
comment|/**< Cache-inhibited base address (virtual) */
name|t_Handle
name|h_Bm
decl_stmt|;
comment|/**< Bm Handle */
name|e_DpaaSwPortal
name|swPortalId
decl_stmt|;
comment|/**< Portal id */
name|uintptr_t
name|irq
decl_stmt|;
comment|/**< portal interrupt line; NO_IRQ if interrupts not used */
block|}
name|t_BmPortalParam
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_PORTAL_Config   @Description   Creates descriptor for the BM Portal;                  The routine returns a handle (descriptor) to a BM-Portal object;                 This descriptor must be passed as first parameter to all other                 BM-Portal function calls.                  No actual initialization or configuration of QM-Portal hardware is                 done by this routine.   @Param[in]     p_BmPortalParam   - Pointer to data structure of parameters   @Retval        Handle to a BM-Portal object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|BM_PORTAL_Config
parameter_list|(
name|t_BmPortalParam
modifier|*
name|p_BmPortalParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_PORTAL_Init   @Description   Initializes a BM-Portal module   @Param[in]     h_BmPortal - A handle to a BM-Portal module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_PORTAL_Init
parameter_list|(
name|t_Handle
name|h_BmPortal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_PortalFree   @Description   Frees all resources that were assigned to BM Portal module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_BmPortal  - BM Portal module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_PORTAL_Free
parameter_list|(
name|t_Handle
name|h_BmPortal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_PORTAL_ConfigMemAttr   @Description   Change the memory attributes                 from its default configuration [MEMORY_ATTR_CACHEABLE].   @Param[in]     h_BmPortal          - A handle to a BM-Portal module  @Param[in]     hwExtStructsMemAttr - memory attributes (cache/non-cache, etc.)   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_PORTAL_Config() and before BM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_PORTAL_ConfigMemAttr
parameter_list|(
name|t_Handle
name|h_BmPortal
parameter_list|,
name|uint32_t
name|hwExtStructsMemAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_portal_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_portal_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_pool_grp BM-Pool API   @Description   BM-Pool API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_pool_init_grp BM-Pool Initialization Unit   @Description   BM-Pool Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    BM Pool Depletion Thresholds macros                 The thresholds are represent by an array of size MAX_DEPLETION_THRESHOLDS                 Use the following macros to access the appropriate location in the array. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BM_POOL_DEP_THRESH_SW_ENTRY
value|0
end_define

begin_define
define|#
directive|define
name|BM_POOL_DEP_THRESH_SW_EXIT
value|1
end_define

begin_define
define|#
directive|define
name|BM_POOL_DEP_THRESH_HW_ENTRY
value|2
end_define

begin_define
define|#
directive|define
name|BM_POOL_DEP_THRESH_HW_EXIT
value|3
end_define

begin_define
define|#
directive|define
name|MAX_DEPLETION_THRESHOLDS
value|4
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing BM Pool initialization parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Bm
decl_stmt|;
comment|/**< A handle to a BM Module. */
name|t_Handle
name|h_BmPortal
decl_stmt|;
comment|/**< A handle to a BM Portal Module.                                                          will be used only for Init and Free routines.                                                          NOTE: if NULL, assuming affinity */
name|uint32_t
name|numOfBuffers
decl_stmt|;
comment|/**< Number of buffers use by this pool                                                          NOTE: If zero, empty pool buffer is created. */
name|t_BufferPoolInfo
name|bufferPoolInfo
decl_stmt|;
comment|/**< Data buffers pool information */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< opaque user value passed as a parameter to callbacks */
name|bool
name|shadowMode
decl_stmt|;
comment|/**< If TRUE, numOfBuffers will be set to '0'. */
name|uint8_t
name|bpid
decl_stmt|;
comment|/**< index of the shadow buffer pool (0-BM_MAX_NUM_OF_POOLS).                                                          valid only if shadowMode='TRUE'. */
block|}
name|t_BmPoolParam
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_Config   @Description   Creates descriptor for the BM Pool;                  The routine returns a handle (descriptor) to the BM Pool object.   @Param[in]     p_BmPoolParam   - A pointer to data structure of parameters   @Return        Handle to BM Portal object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|BM_POOL_Config
parameter_list|(
name|t_BmPoolParam
modifier|*
name|p_BmPoolParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_Init   @Description   Initializes a BM-Pool module   @Param[in]     h_BmPool - A handle to a BM-Pool module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_Init
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_PoolFree   @Description   Frees all resources that were assigned to BM Pool module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_BmPool    - BM Pool module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_Free
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_ConfigBpid   @Description   Config a specific pool id rather than dynamic pool id.   @Param[in]     h_BmPool    - A handle to a BM-Pool module  @Param[in]     bpid        - index of the buffer pool (0-BM_MAX_NUM_OF_POOLS).   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_POOL_Config() and before BM_POOL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_ConfigBpid
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_ConfigDepletion   @Description   Config depletion-entry/exit thresholds and callback.   @Param[in]     h_BmPool        - A handle to a BM-Pool module  @Param[in]     f_Depletion     - depletion-entry/exit callback.  @Param[in]     thresholds      - depletion-entry/exit thresholds.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_POOL_Config() and before BM_POOL_Init();                 Allowed only if shadowMode='FALSE'.                 Allowed only if BM in master mode ('guestId'=NCSW_MASTER_ID), or                 the BM is in guest mode BUT than this routine will invoke IPC                 call to the master. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_ConfigDepletion
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|t_BmDepletionCallback
modifier|*
name|f_Depletion
parameter_list|,
name|uint32_t
name|thresholds
index|[
name|MAX_DEPLETION_THRESHOLDS
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_ConfigStockpile   @Description   Config software stockpile.   @Param[in]     h_BmPool     - A handle to a BM-Pool module  @Param[in]     maxBuffers   - the software data structure size saved for stockpile;                                when reached this value, release to hw command performed.  @Param[in]     minBuffers   - if current capacity is equal or lower then this value,                                acquire from hw command performed.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_POOL_Config() and before BM_POOL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_ConfigStockpile
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|uint16_t
name|maxBuffers
parameter_list|,
name|uint16_t
name|minBuffers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_ConfigBuffContextMode   @Description   Config the BM pool to set/unset buffer-context   @Param[in]     h_BmPool     - A handle to a BM-Pool module  @Param[in]     en           - enable/disable buffer context mode   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following BM_POOL_Config() and before BM_POOL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_ConfigBuffContextMode
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_pool_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_pool_runtime_control_grp BM-Pool Runtime Control Unit   @Description   BM-Pool Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining BM Pool counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_BmPoolCounters
block|{
name|e_BM_POOL_COUNTERS_CONTENT
init|=
literal|0
block|,
comment|/**< number of free buffers for a particular pool */
name|e_BM_POOL_COUNTERS_SW_DEPLETION
block|,
comment|/**< number of times pool entered sw depletion */
name|e_BM_POOL_COUNTERS_HW_DEPLETION
comment|/**< number of times pool entered hw depletion */
block|}
name|e_BmPoolCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_GetId   @Description   return a buffer pool id.   @Param[in]     h_BmPool    - A handle to a BM-pool   @Return        Pool ID. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
name|BM_POOL_GetId
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_GetBufferSize   @Description   returns the pool's buffer size.   @Param[in]     h_BmPool    - A handle to a BM-pool   @Return        pool's buffer size. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint16_t
name|BM_POOL_GetBufferSize
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_GetBufferContext   @Description   Returns the user's private context that                 should be associated with the buffer.   @Param[in]     h_BmPool    - A handle to a BM-pool  @Param[in]     p_Buff      - A Pointer to the buffer   @Return        user's private context. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|BM_POOL_GetBufferContext
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|void
modifier|*
name|p_Buff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_GetCounter   @Description   Reads one of the BM Pool counters.   @Param[in]     h_BmPool    - A handle to a BM-pool  @Param[in]     counter     - The requested counter.   @Return        Counter's current value. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|BM_POOL_GetCounter
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|e_BmPoolCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_pool_runtime_control_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         BM_pool_runtime_data_grp BM-Pool Runtime Data Unit   @Description   BM-Pool Runtime data unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_GetBuf   @Description   Allocate buffer from a buffer pool.   @Param[in]     h_BmPool    - A handle to a BM-pool  @Param[in]     h_BmPortal  - A handle to a BM Portal Module;                               NOTE : if NULL, assuming affinity.   @Return        A Pointer to the allocated buffer. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
modifier|*
name|BM_POOL_GetBuf
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|t_Handle
name|h_BmPortal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_PutBuf   @Description   Deallocate buffer to a buffer pool.   @Param[in]     h_BmPool    - A handle to a BM-pool  @Param[in]     h_BmPortal  - A handle to a BM Portal Module;                               NOTE : if NULL, assuming affinity.  @Param[in]     p_Buff      - A Pointer to the buffer.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_PutBuf
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|t_Handle
name|h_BmPortal
parameter_list|,
name|void
modifier|*
name|p_Buff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      BM_POOL_FillBufs   @Description   Fill a BM pool with new buffers.   @Param[in]     h_BmPool    - A handle to a BM-pool  @Param[in]     h_BmPortal  - A handle to a BM Portal Module;                               NOTE : if NULL, assuming affinity.  @Param[in]     numBufs     - How many buffers to fill into the pool.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|BM_POOL_FillBufs
parameter_list|(
name|t_Handle
name|h_BmPool
parameter_list|,
name|t_Handle
name|h_BmPortal
parameter_list|,
name|uint32_t
name|numBufs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_pool_runtime_data_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_pool_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of BM_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BM_EXT_H */
end_comment

end_unit

