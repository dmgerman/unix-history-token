begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          qm_ext.h   @Description   QM& Portal API */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QM_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__QM_EXT_H
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

begin_include
include|#
directive|include
file|"dpaa_ext.h"
end_include

begin_include
include|#
directive|include
file|"part_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_grp Queue Manager API   @Description   QM API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   This callback type is used when receiving frame.                  User provides this function. Driver invokes it.   @Param[in]     h_App       A user argument to the callback  @Param[in]     h_QmFqr     A handle to an QM-FQR Module.  @Param[in]     fqidOffset  fqid offset from the FQR's fqid base.  @Param[in]     p_Frame     The Received Frame   @Retval        e_RX_STORE_RESPONSE_CONTINUE - order the driver to continue Rx                                                operation for all ready data.  @Retval        e_RX_STORE_RESPONSE_PAUSE    - order the driver to stop Rx operation.   @Cautions      p_Frame is local parameter; i.e. users must NOT access or use                 this parameter in any means outside this callback context. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|e_RxStoreResponse
function_decl|(
name|t_QmReceivedFrameCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|,
name|t_DpaaFD
modifier|*
name|p_Frame
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   This callback type is used when the FQR is completely was drained.                  User provides this function. Driver invokes it.   @Param[in]     h_App       A user argument to the callback  @Param[in]     h_QmFqr     A handle to an QM-FQR Module.   @Retval        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|t_Error
function_decl|(
name|t_QmFqrDrainedCompletionCB
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|t_Handle
name|h_QmFqr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   QM Rejection code enum */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_QmRejectionCode
block|{
name|e_QM_RC_NONE
block|,
name|e_QM_RC_CG_TAILDROP
block|,
comment|/**< This frames was rejected due to congestion                                      group taildrop situation */
name|e_QM_RC_CG_WRED
block|,
comment|/**< This frames was rejected due to congestion                                      group WRED situation */
name|e_QM_RC_FQ_TAILDROP
comment|/**< This frames was rejected due to FQID TD                                      situation */
comment|/*  e_QM_RC_ERROR     e_QM_RC_ORPWINDOW_EARLY     e_QM_RC_ORPWINDOW_LATE     e_QM_RC_ORPWINDOW_RETIRED */
block|}
name|e_QmRejectionCode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   QM Rejected frame information */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmRejectedFrameInfo
block|{
name|e_QmRejectionCode
name|rejectionCode
decl_stmt|;
comment|/**< Rejection code */
union|union
block|{
struct|struct
block|{
name|uint8_t
name|cgId
decl_stmt|;
comment|/**< congestion group id*/
block|}
name|cg
struct|;
comment|/**< rejection parameters when rejectionCode =                                              e_QM_RC_CG_TAILDROP or e_QM_RC_CG_WRED. */
block|}
union|;
block|}
name|t_QmRejectedFrameInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   This callback type is used when receiving rejected frames.                  User provides this function. Driver invokes it.   @Param[in]     h_App                   A user argument to the callback  @Param[in]     h_QmFqr                 A handle to an QM-FQR Module.  @Param[in]     fqidOffset              fqid offset from the FQR's fqid base.  @Param[in]     p_Frame                 The Rejected Frame  @Param[in]     p_QmRejectedFrameInfo   Rejected Frame information   @Retval        e_RX_STORE_RESPONSE_CONTINUE - order the driver to continue Rx                                                operation for all ready data.  @Retval        e_RX_STORE_RESPONSE_PAUSE    - order the driver to stop Rx operation.   @Cautions      p_Frame is local parameter; i.e. users must NOT access or use                 this parameter in any means outside this callback context. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|e_RxStoreResponse
function_decl|(
name|t_QmRejectedFrameCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|,
name|t_DpaaFD
modifier|*
name|p_Frame
parameter_list|,
name|t_QmRejectedFrameInfo
modifier|*
name|p_QmRejectedFrameInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_lib_grp QM common API   @Description   QM common API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   QM Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_QmExceptions
block|{
name|e_QM_EX_CORENET_INITIATOR_DATA
init|=
literal|0
block|,
comment|/**< Initiator Data Error */
name|e_QM_EX_CORENET_TARGET_DATA
block|,
comment|/**< CoreNet Target Data Error */
name|e_QM_EX_CORENET_INVALID_TARGET_TRANSACTION
block|,
comment|/**< Invalid Target Transaction */
name|e_QM_EX_PFDR_THRESHOLD
block|,
comment|/**< PFDR Low Watermark Interrupt */
name|e_QM_EX_PFDR_ENQUEUE_BLOCKED
block|,
comment|/**< PFDR Enqueues Blocked Interrupt */
name|e_QM_EX_SINGLE_ECC
block|,
comment|/**< Single Bit ECC Error Interrupt */
name|e_QM_EX_MULTI_ECC
block|,
comment|/**< Multi Bit ECC Error Interrupt */
name|e_QM_EX_INVALID_COMMAND
block|,
comment|/**< Invalid Command Verb Interrupt */
name|e_QM_EX_DEQUEUE_DCP
block|,
comment|/**< Invalid Dequeue Direct Connect Portal Interrupt */
name|e_QM_EX_DEQUEUE_FQ
block|,
comment|/**< Invalid Dequeue FQ Interrupt */
name|e_QM_EX_DEQUEUE_SOURCE
block|,
comment|/**< Invalid Dequeue Source Interrupt */
name|e_QM_EX_DEQUEUE_QUEUE
block|,
comment|/**< Invalid Dequeue Queue Interrupt */
name|e_QM_EX_ENQUEUE_OVERFLOW
block|,
comment|/**< Invalid Enqueue Overflow Interrupt */
name|e_QM_EX_ENQUEUE_STATE
block|,
comment|/**< Invalid Enqueue State Interrupt */
name|e_QM_EX_ENQUEUE_CHANNEL
block|,
comment|/**< Invalid Enqueue Channel Interrupt */
name|e_QM_EX_ENQUEUE_QUEUE
block|,
comment|/**< Invalid Enqueue Queue Interrupt */
name|e_QM_EX_CG_STATE_CHANGE
comment|/**< CG change state notification */
block|}
name|e_QmExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_init_grp QM (common) Initialization Unit   @Description   QM (common) Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_QmExceptionsCallback   @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App      - User's application descriptor.  @Param[in]     exception  - The exception. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_QmExceptionsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_QmExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description    Frame's Type to poll */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_QmPortalPollSource
block|{
name|e_QM_PORTAL_POLL_SOURCE_DATA_FRAMES
init|=
literal|0
block|,
comment|/**< Poll only data frames */
name|e_QM_PORTAL_POLL_SOURCE_CONTROL_FRAMES
block|,
comment|/**< Poll only control frames */
name|e_QM_PORTAL_POLL_SOURCE_BOTH
comment|/**< Poll both */
block|}
name|e_QmPortalPollSource
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM contextA of FQ initialization parameters                 Note that this is only "space-holder" for the Context-A. The "real"                 Context-A is described in each specific driver (E.g. FM driver                 has its own Context-A API). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|res
index|[
literal|2
index|]
decl_stmt|;
comment|/**< reserved size for context-a */
block|}
name|t_QmContextA
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM contextB of FQ initialization parameters                 Note that this is only "space-holder" for the Context-B. The "real"                 Context-B is described in each specific driver (E.g. FM driver                 has its own Context-B API). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_QmContextB
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM initialization parameters */
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
comment|/**< QM Partition Id */
name|uintptr_t
name|baseAddress
decl_stmt|;
comment|/**< Qm base address (virtual)                                                          NOTE: this parameter relevant only for BM in master mode ('guestId'=NCSW_MASTER_ID). */
name|uintptr_t
name|swPortalsBaseAddress
decl_stmt|;
comment|/**< QM Software Portals Base Address (virtual) */
name|uint16_t
name|liodn
decl_stmt|;
comment|/**< This value is attached to every transaction initiated by QMan when accessing its private data structures */
name|uint32_t
name|totalNumOfFqids
decl_stmt|;
comment|/**< Total number of frame-queue-ids in the system */
name|uint32_t
name|fqdMemPartitionId
decl_stmt|;
comment|/**< FQD's mem partition id;                                                          NOTE: The memory partition must be non-cacheable and no-coherent area. */
name|uint32_t
name|pfdrMemPartitionId
decl_stmt|;
comment|/**< PFDR's mem partition id;                                                          NOTE: The memory partition must be non-cacheable and no-coherent area. */
name|t_QmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< An application callback routine to handle exceptions.*/
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                          be passed by the driver upon calling the above callbacks */
name|uintptr_t
name|errIrq
decl_stmt|;
comment|/**< error interrupt line; NO_IRQ if interrupts not used */
name|uint32_t
name|partFqidBase
decl_stmt|;
comment|/**< The first frame-queue-id dedicated to this partition.                                                          NOTE: this parameter relevant only when working with multiple partitions. */
name|uint32_t
name|partNumOfFqids
decl_stmt|;
comment|/**< Number of frame-queue-ids dedicated to this partition.                                                          NOTE: this parameter relevant only when working with multiple partitions. */
name|uint16_t
name|partCgsBase
decl_stmt|;
comment|/**< The first cgr dedicated to this partition.                                                          NOTE: this parameter relevant only when working with multiple partitions. */
name|uint16_t
name|partNumOfCgs
decl_stmt|;
comment|/**< Number of cgr's dedicated to this partition.                                                          NOTE: this parameter relevant only when working with multiple partitions. */
block|}
name|t_QmParam
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_Config   @Description   Creates descriptor for the QM module.                  The routine returns a handle (descriptor) to the QM object.                 This descriptor must be passed as first parameter to all other                 QM function calls.                  No actual initialization or configuration of QM hardware is                 done by this routine.   @Param[in]     p_QmParam   - Pointer to data structure of parameters   @Retval        Handle to the QM object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|QM_Config
parameter_list|(
name|t_QmParam
modifier|*
name|p_QmParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_Init   @Description   Initializes the QM module   @Param[in]     h_Qm - A handle to the QM module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_Init
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_Free   @Description   Frees all resources that were assigned to the QM module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_Qm - A handle to the QM module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_Free
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_advanced_init_grp    QM (common) Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining DC portal ERN destination */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmDcPortalParams
block|{
name|bool
name|sendToSw
decl_stmt|;
name|e_DpaaSwPortal
name|swPortalId
decl_stmt|;
block|}
name|t_QmDcPortalParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_ConfigRTFramesDepth   @Description   Change the run-time frames depth (i.e. the maximum total number                 of frames that may be inside QM at a certain time) from its default                 configuration [30000].   @Param[in]     h_Qm            - A handle to the QM module  @Param[in]     rtFramesDepth   - run-time max num of frames.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Config() and before QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_ConfigRTFramesDepth
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|uint32_t
name|rtFramesDepth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_ConfigPfdrThreshold   @Description   Change the pfdr threshold from its default                 configuration [0].                 An interrupt if enables is asserted when the number of PFDRs is below this threshold.   @Param[in]     h_Qm            - A handle to the QM module  @Param[in]     threshold       - threshold value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Config() and before QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_ConfigPfdrThreshold
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|uint32_t
name|threshold
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_ConfigSfdrReservationThreshold   @Description   Change the sfdr threshold from its default                 configuration [0].   @Param[in]     h_Qm            - A handle to the QM module  @Param[in]     threshold       - threshold value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Config() and before QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_ConfigSfdrReservationThreshold
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|uint32_t
name|threshold
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_ConfigErrorRejectionNotificationDest   @Description   Change the destination of rejected frames for DC portals.                 By default, depending on chip, some DC portals are set to reject                 frames to HW and some to SW.   @Param[in]     h_Qm            - A handle to the QM module  @Param[in]     id              - DC Portal id.  @Param[in]     p_Params        - Destination parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Config() and before QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_ConfigErrorRejectionNotificationDest
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|e_DpaaDcPortal
name|id
parameter_list|,
name|t_QmDcPortalParams
modifier|*
name|p_Params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_runtime_control_grp QM (common) Runtime Control Unit   @Description   QM (common) Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining QM counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_QmCounters
block|{
name|e_QM_COUNTERS_SFDR_IN_USE
init|=
literal|0
block|,
comment|/**< Total Single Frame Descriptor Record (SFDR) currently in use */
name|e_QM_COUNTERS_PFDR_IN_USE
block|,
comment|/**< Total Packed Frame Descriptor Record (PFDR) currently in use */
name|e_QM_COUNTERS_PFDR_FREE_POOL
comment|/**< Total Packed Frame Descriptor Record (PFDR) Free Pool Count in external memory */
block|}
name|e_QmCounters
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
name|t_QmRevisionInfo
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
name|t_QmRevisionInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM FQ-Range reservation parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmRsrvFqrParams
block|{
name|bool
name|useForce
decl_stmt|;
comment|/**< TRUE - force reservation of specific fqids;                                              FALSE - reserve several fqids */
name|uint32_t
name|numOfFqids
decl_stmt|;
comment|/**< number of fqids to be reserved. */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|align
decl_stmt|;
comment|/**< alignment. will be used if useForce=FALSE */
block|}
name|nonFrcQs
struct|;
struct|struct
block|{
name|uint32_t
name|fqid
decl_stmt|;
comment|/**< the fqid base of the forced fqids. will be used if useForce=TRUE */
block|}
name|frcQ
struct|;
block|}
name|qs
union|;
block|}
name|t_QmRsrvFqrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM Error information */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmErrorInfo
block|{
name|bool
name|portalValid
decl_stmt|;
name|bool
name|hwPortal
decl_stmt|;
name|e_DpaaSwPortal
name|swPortalId
decl_stmt|;
comment|/**< Sw Portal id */
name|e_DpaaDcPortal
name|dcpId
decl_stmt|;
comment|/**< Dcp (hw Portal) id */
name|bool
name|fqidValid
decl_stmt|;
name|uint32_t
name|fqid
decl_stmt|;
block|}
name|t_QmErrorInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_ReserveQueues   @Description   Request to Reserved queues for future use.   @Param[in]     h_Qm            - A handle to the QM Module.  @Param[in]     p_QmFqrParams   - A structure of parameters for defining the                                   desired queues parameters.  @Param[out]    p_BaseFqid      - base-fqid on success; '0' code otherwise.   @Return        E_OK on success;   @Cautions      Allowed only after QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_ReserveQueues
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|t_QmRsrvFqrParams
modifier|*
name|p_QmFqrParams
parameter_list|,
name|uint32_t
modifier|*
name|p_BaseFqid
parameter_list|)
function_decl|;
end_function_decl

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
comment|/**  @Function      QM_DumpRegs   @Description   Dumps all QM registers   @Param[in]     h_Qm        - A handle to the QM Module.   @Return        E_OK on success;   @Cautions      Allowed only after QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_DumpRegs
parameter_list|(
name|t_Handle
name|h_Qm
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
comment|/**  @Function      QM_SetException   @Description   Calling this routine enables/disables the specified exception.   @Param[in]     h_Qm        - A handle to the QM Module.  @Param[in]     exception   - The exception to be selected.  @Param[in]     enable      - TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_SetException
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|e_QmExceptions
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
comment|/**  @Function      QM_ErrorIsr   @Description   QM interrupt-service-routine for errors.   @Param[in]     h_Qm            - A handle to the QM module   @Cautions      Allowed only following QM_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|QM_ErrorIsr
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_GetErrorInformation   @Description   Reads the last error information.   @Param[in]     h_Qm        - A handle to the QM Module.  @Param[out]    p_errInfo   - the information will be loaded to this struct.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_GetErrorInformation
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|t_QmErrorInfo
modifier|*
name|p_errInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_GetCounter   @Description   Reads one of the QM counters.   @Param[in]     h_Qm        - A handle to the QM Module.  @Param[in]     counter     - The requested counter.   @Return        Counter's current value.   @Cautions      Allowed only following QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|QM_GetCounter
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|e_QmCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_GetRevision   @Description   Returns the QM revision   @Param[in]     h_Qm                A handle to a QM Module.  @Param[out]    p_QmRevisionInfo    A structure of revision information parameters.   @Return        None.   @Cautions      Allowed only following QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_GetRevision
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|t_QmRevisionInfo
modifier|*
name|p_QmRevisionInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_runtime_control_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_runtime_data_grp QM (common) Runtime Data Unit   @Description   QM (common) Runtime data unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_Poll   @Description   Poll frames from QM.   @Param[in]     h_Qm            - A handle to the QM module  @Param[in]     source          - The selected frames type to poll   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_Poll
parameter_list|(
name|t_Handle
name|h_Qm
parameter_list|,
name|e_QmPortalPollSource
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_runtime_data_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_lib_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_portal_grp QM-Portal API   @Description   QM common API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_portal_init_grp QM-Portal Initialization Unit   @Description   QM-Portal Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM-Portal Stash parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|stashDestQueue
decl_stmt|;
comment|/**< This value is used to direct all stashing transactions initiated on behalf of this software portal                                                                  to the specific Stashing Request Queues (SRQ) */
name|uint8_t
name|eqcr
decl_stmt|;
comment|/**< If 0, disabled. If 1, for every EQCR entry consumed by QMan a new stash transaction is performed.                                                                  If 2-7, after 2-7 EQCR entries being consumed by QMAN a new stash transaction is performed. */
name|bool
name|eqcrHighPri
decl_stmt|;
comment|/**< EQCR entry stash transactions for this software portal will be signaled with higher priority. */
name|bool
name|dqrr
decl_stmt|;
comment|/**< DQRR entry stash enable/disable */
name|uint16_t
name|dqrrLiodn
decl_stmt|;
comment|/**< This value is attached to every transaction initiated by QMan when performing DQRR entry or EQCR_CI stashing                                                                  on behalf of this software portal */
name|bool
name|dqrrHighPri
decl_stmt|;
comment|/**< DQRR entry stash transactions for this software portal will be signaled with higher priority. */
name|bool
name|fdFq
decl_stmt|;
comment|/**< Dequeued Frame Data, Annotation, and FQ Context Stashing enable/disable */
name|uint16_t
name|fdFqLiodn
decl_stmt|;
comment|/**< This value is attached to every transaction initiated by QMan when performing dequeued frame data and                                                                  annotation stashing, or FQ context stashing on behalf of this software portal */
name|bool
name|fdFqHighPri
decl_stmt|;
comment|/**< Dequeued frame data, annotation, and FQ context stash transactions for this software portal will be signaled                                                                  with higher priority. */
name|bool
name|fdFqDrop
decl_stmt|;
comment|/**< If True, Dequeued frame data, annotation, and FQ context stash transactions for this software portal will be dropped                                                                           by QMan if the target SRQ is almost full, to prevent QMan sequencer stalling. Stash transactions that are                                                                           dropped will result in a fetch from main memory when a core reads the addressed coherency granule.                                                                  If FALSE, Dequeued frame data, annotation, and FQ context stash transactions for this software portal will never be                                                                            dropped by QMan. If the target SRQ is full a sequencer will stall until each stash transaction can be completed. */
block|}
name|t_QmPortalStashParam
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM-Portal initialization parameters */
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
name|h_Qm
decl_stmt|;
comment|/**< Qm Handle */
name|e_DpaaSwPortal
name|swPortalId
decl_stmt|;
comment|/**< Portal id */
name|uintptr_t
name|irq
decl_stmt|;
comment|/**< portal interrupt line; used only if useIrq set to TRUE */
name|uint16_t
name|fdLiodnOffset
decl_stmt|;
comment|/**< liodn to be used for all frames enqueued via this software portal */
name|t_QmReceivedFrameCallback
modifier|*
name|f_DfltFrame
decl_stmt|;
comment|/**< this callback will be called unless specific callback assigned to the FQ*/
name|t_QmRejectedFrameCallback
modifier|*
name|f_RejectedFrame
decl_stmt|;
comment|/**< this callback will be called for rejected frames. */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< a handle to the upper layer; It will be passed by the driver upon calling the CB */
block|}
name|t_QmPortalParam
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_Config   @Description   Creates descriptor for a QM-Portal module.                  The routine returns a handle (descriptor) to a QM-Portal object.                 This descriptor must be passed as first parameter to all other                 QM-Portal function calls.                  No actual initialization or configuration of QM-Portal hardware is                 done by this routine.   @Param[in]     p_QmPortalParam   - Pointer to data structure of parameters   @Retval        Handle to a QM-Portal object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|QM_PORTAL_Config
parameter_list|(
name|t_QmPortalParam
modifier|*
name|p_QmPortalParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_Init   @Description   Initializes a QM-Portal module   @Param[in]     h_QmPortal - A handle to a QM-Portal module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_Init
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_Free   @Description   Frees all resources that were assigned to a QM-Portal module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_QmPortal - A handle to a QM-Portal module   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_Free
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_portal_advanced_init_grp    QM-Portal Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_ConfigDcaMode   @Description   Change the Discrate Consumption Acknowledge mode                 from its default configuration [FALSE].   @Param[in]     h_QmPortal  - A handle to a QM-Portal module  @Param[in]     enable      - Enable/Disable DCA mode   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Config() and before QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_ConfigDcaMode
parameter_list|(
name|t_Handle
name|h_QmPortal
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
comment|/**  @Function      QM_PORTAL_ConfigStash   @Description   Config the portal to active stash mode.   @Param[in]     h_QmPortal      - A handle to a QM-Portal module  @Param[in]     p_StashParams   - Pointer to data structure of parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Config() and before QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_ConfigStash
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|,
name|t_QmPortalStashParam
modifier|*
name|p_StashParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_ConfigPullMode   @Description   Change the Pull Mode from its default configuration [FALSE].   @Param[in]     h_QmPortal  - A handle to a QM-Portal module  @Param[in]     pullMode    - When TRUE, the Portal will work in pull mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Config() and before QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_ConfigPullMode
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|,
name|bool
name|pullMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_portal_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_portal_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_portal_runtime_control_grp QM-Portal Runtime Control Unit   @Description   QM-Portal Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_AddPoolChannel   @Description   Adding the pool channel to the SW-Portal's scheduler.                 the sw-portal will get frames that came from the pool channel.   @Param[in]     h_QmPortal      - A handle to a QM-Portal module  @Param[in]     poolChannelId   - Pool channel id. must between '0' to QM_MAX_NUM_OF_POOL_CHANNELS   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_AddPoolChannel
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint8_t
name|poolChannelId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_portal_runtime_control_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_portal_runtime_data_grp QM-Portal Runtime Data Unit   @Description   QM-Portal Runtime data unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description structure representing QM Portal Frame Info */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmPortalFrameInfo
block|{
name|t_Handle
name|h_App
decl_stmt|;
name|t_Handle
name|h_QmFqr
decl_stmt|;
name|uint32_t
name|fqidOffset
decl_stmt|;
name|t_DpaaFD
name|frame
decl_stmt|;
block|}
name|t_QmPortalFrameInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_Poll   @Description   Poll frames from the specified sw-portal.   @Param[in]     h_QmPortal      - A handle to a QM-Portal module  @Param[in]     source          - The selected frames type to poll   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_Poll
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|,
name|e_QmPortalPollSource
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_PORTAL_PollFrame   @Description   Poll frames from the specified sw-portal. will poll only data frames   @Param[in]     h_QmPortal      - A handle to a QM-Portal module  @Param[out]    p_frameInfo     - A structure to hold the dequeued frame information   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_PORTAL_PollFrame
parameter_list|(
name|t_Handle
name|h_QmPortal
parameter_list|,
name|t_QmPortalFrameInfo
modifier|*
name|p_frameInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_portal_runtime_data_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_portal_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_fqr_grp QM Frame-Queue-Range API   @Description   QM-FQR API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_fqr_init_grp QM-FQR Initialization Unit   @Description   QM-FQR Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description structure representing QM FQ-Range congestion group parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_QmCg
decl_stmt|;
comment|/**< A handle to the congestion group. */
name|int8_t
name|overheadAccountingLength
decl_stmt|;
comment|/**< For each frame add this number for CG calculation                                                  (may be negative), if 0 - disable feature */
name|uint32_t
name|fqTailDropThreshold
decl_stmt|;
comment|/**< if not "0" - enable tail drop on this FQR */
block|}
name|t_QmFqrCongestionAvoidanceParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM FQ-Range initialization parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Qm
decl_stmt|;
comment|/**< A handle to a QM module */
name|t_Handle
name|h_QmPortal
decl_stmt|;
comment|/**< A handle to a QM Portal Module;                                              will be used only for Init and Free routines;                                              NOTE : if NULL, assuming affinity */
name|bool
name|initParked
decl_stmt|;
comment|/**< This FQ-Range will be initialize in park state (un-schedule) */
name|bool
name|holdActive
decl_stmt|;
comment|/**< This FQ-Range can be parked (un-schedule);                                              This affects only on queues destined to software portals*/
name|bool
name|preferInCache
decl_stmt|;
comment|/**< Prefer this FQ-Range to be in QMAN's internal cache for all states */
name|bool
name|useContextAForStash
decl_stmt|;
comment|/**< This FQ-Range will use context A for stash */
union|union
block|{
struct|struct
block|{
name|uint8_t
name|frameAnnotationSize
decl_stmt|;
comment|/**< Size of Frame Annotation to be stashed */
name|uint8_t
name|frameDataSize
decl_stmt|;
comment|/**< Size of Frame Data to be stashed. */
name|uint8_t
name|fqContextSize
decl_stmt|;
comment|/**< Size of FQ context to be stashed. */
name|uint64_t
name|fqContextAddr
decl_stmt|;
comment|/**< 40 bit memory address containing the FQ context information to be stashed;                                                  Must be cacheline-aligned */
block|}
name|stashingParams
struct|;
name|t_QmContextA
modifier|*
name|p_ContextA
decl_stmt|;
comment|/**< context-A field to be written in the FQ structure */
block|}
union|;
name|t_QmContextB
modifier|*
name|p_ContextB
decl_stmt|;
comment|/**< context-B field to be written in the FQ structure;                                              Note that this field may be used for Tx queues only! */
name|e_QmFQChannel
name|channel
decl_stmt|;
comment|/**< Qm Channel */
name|uint8_t
name|wq
decl_stmt|;
comment|/**< Work queue within the channel */
name|bool
name|shadowMode
decl_stmt|;
comment|/**< If TRUE, useForce MUST set to TRUE and numOfFqids MUST set to '1' */
name|uint32_t
name|numOfFqids
decl_stmt|;
comment|/**< number of fqids to be allocated*/
name|bool
name|useForce
decl_stmt|;
comment|/**< TRUE - force allocation of specific fqids;                                              FALSE - allocate several fqids */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|align
decl_stmt|;
comment|/**< alignment. will be used if useForce=FALSE */
block|}
name|nonFrcQs
struct|;
struct|struct
block|{
name|uint32_t
name|fqid
decl_stmt|;
comment|/**< the fqid base of the forced fqids. will be used if useForce=TRUE */
block|}
name|frcQ
struct|;
block|}
name|qs
union|;
name|bool
name|congestionAvoidanceEnable
decl_stmt|;
comment|/**< TRUE to enable congestion avoidance mechanism */
name|t_QmFqrCongestionAvoidanceParams
name|congestionAvoidanceParams
decl_stmt|;
comment|/**< Parameters for congestion avoidance */
block|}
name|t_QmFqrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_Create   @Description   Initializing and enabling a Frame-Queue-Range.                 This routine should be called for adding an FQR.   @Param[in]     p_QmFqrParams   - A structure of parameters for defining the                                   desired queues parameters.   @Return        A handle to the initialized FQR on success; NULL code otherwise.   @Cautions      Allowed only following QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|QM_FQR_Create
parameter_list|(
name|t_QmFqrParams
modifier|*
name|p_QmFqrParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_Free   @Description   Deleting and free all resources of an initialized FQR.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init() and QM_FQR_Create() for this FQR. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_Free
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_FreeWDrain   @Description   Deleting and free all resources of an initialized FQR                 with the option of draining.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     f_CompletionCB  - Pointer to a completion callback to be used in non-blocking mode.  @Param[in]     deliverFrame    - TRUE for deliver the drained frames to the user;                                   FALSE for not deliver the frames.  @Param[in]     f_CallBack      - Pointer to a callback to handle the delivered frames.  @Param[in]     h_App           - User's application descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init() and QM_FQR_Create() for this FQR. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_FreeWDrain
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_QmFqrDrainedCompletionCB
modifier|*
name|f_CompletionCB
parameter_list|,
name|bool
name|deliverFrame
parameter_list|,
name|t_QmReceivedFrameCallback
modifier|*
name|f_CallBack
parameter_list|,
name|t_Handle
name|h_App
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_fqr_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_fqr_runtime_control_grp QM-FQR Runtime Control Unit   @Description   QM-FQR Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining QM-FQR counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_QmFqrCounters
block|{
name|e_QM_FQR_COUNTERS_FRAME
init|=
literal|0
block|,
comment|/**< Total number of frames on this frame queue */
name|e_QM_FQR_COUNTERS_BYTE
comment|/**< Total number of bytes in all frames on this frame queue */
block|}
name|e_QmFqrCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_RegisterCB   @Description   Register a callback routine to be called when a frame comes from this FQ-Range   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     f_CallBack      - An application callback  @Param[in]     h_App           - User's application descriptor   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_FQR_Create(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_RegisterCB
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_QmReceivedFrameCallback
modifier|*
name|f_CallBack
parameter_list|,
name|t_Handle
name|h_App
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_Resume   @Description   Request to Re-Schedule this Fqid.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     h_QmPortal      - A handle to a QM Portal Module;                                   NOTE : if NULL, assuming affinity.  @Param[in]     fqidOffset      - Fqid offset within the FQ-Range.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_FQR_Create(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_Resume
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_Suspend   @Description   Request to Un-Schedule this Fqid.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     h_QmPortal      - A handle to a QM Portal Module;                                   NOTE : if NULL, assuming affinity.  @Param[in]     fqidOffset      - Fqid offset within the FQ-Range.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_FQR_Create(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_Suspend
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_GetFqid   @Description   Returned the Fqid base of the FQ-Range   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.   @Return        Fqid base.   @Cautions      Allowed only following QM_FQR_Create(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|QM_FQR_GetFqid
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_GetCounter   @Description   Reads one of the QM-FQR counters.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     h_QmPortal      - A handle to a QM Portal Module;                                   NOTE : if NULL, assuming affinity.  @Param[in]     fqidOffset      - Fqid offset within the FQ-Range.  @Param[in]     counter         - The requested counter.   @Return        Counter's current value.   @Cautions      Allowed only following QM_FQR_Create(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|QM_FQR_GetCounter
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|,
name|e_QmFqrCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_fqr_runtime_control_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_fqr_runtime_data_grp QM-FQR Runtime Data Unit   @Description   QM-FQR Runtime data unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_Enqueue   @Description   Enqueue the frame into the FQ to be transmitted.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     h_QmPortal      - A handle to a QM Portal Module;                                   NOTE : if NULL, assuming affinity.  @Param[in]     fqidOffset      - Fqid offset within the FQ-Range.  @Param[in]     p_Frame         - Pointer to the frame to be enqueued.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_FQR_Create(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_Enqueue
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|,
name|t_DpaaFD
modifier|*
name|p_Frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_FQR_PullFrame   @Description   Perform a Pull command.   @Param[in]     h_QmFqr         - A handle to a QM-FQR Module.  @Param[in]     h_QmPortal      - A handle to a QM Portal Module;                                   NOTE : if NULL, assuming affinity.  @Param[in]     fqidOffset      - Fqid offset within the FQ-Range.  @Param[out]    p_Frame         - The Received Frame   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_PORTAL_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_FQR_PullFrame
parameter_list|(
name|t_Handle
name|h_QmFqr
parameter_list|,
name|t_Handle
name|h_QmPortal
parameter_list|,
name|uint32_t
name|fqidOffset
parameter_list|,
name|t_DpaaFD
modifier|*
name|p_Frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_fqr_runtime_data_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_fqr_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_cg_grp QM Congestion Group API   @Description   QM-CG API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_cg_init_grp QM-Congestion Group Initialization Unit   @Description   QM-CG Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM CG WRED curve */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmCgWredCurve
block|{
name|uint32_t
name|maxTh
decl_stmt|;
comment|/**< minimum threshold - below this level                                              all packets are rejected (approximated                                              to be expressed as x*2^y due to HW                                              implementation)*/
name|uint32_t
name|minTh
decl_stmt|;
comment|/**< minimum threshold - below this level                                              all packets are accepted (approximated                                              due to HW implementation)*/
name|uint8_t
name|probabilityDenominator
decl_stmt|;
comment|/**< 1-64, the fraction of packets dropped                                              when the average queue depth is at the                                              maximum threshold.(approximated due to HW                                              implementation). */
block|}
name|t_QmCgWredCurve
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM CG WRED parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmCgWredParams
block|{
name|bool
name|enableGreen
decl_stmt|;
name|t_QmCgWredCurve
name|greenCurve
decl_stmt|;
name|bool
name|enableYellow
decl_stmt|;
name|t_QmCgWredCurve
name|yellowCurve
decl_stmt|;
name|bool
name|enableRed
decl_stmt|;
name|t_QmCgWredCurve
name|redCurve
decl_stmt|;
block|}
name|t_QmCgWredParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM CG configuration parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmCgParams
block|{
name|t_Handle
name|h_Qm
decl_stmt|;
comment|/**< A handle to a QM module */
name|t_Handle
name|h_QmPortal
decl_stmt|;
comment|/**< A handle to a QM Portal Module;                                                  will be used for Init, Free and as                                                  an interrupt destination for cg state                                                  change (if CgStateChangeEnable = TRUE) */
name|bool
name|frameCount
decl_stmt|;
comment|/**< TRUE for frame count, FALSE - byte count */
name|bool
name|wredEnable
decl_stmt|;
comment|/**< if TRUE - WRED enabled. Each color is enabled independently                                                  so that some colors may use WRED, but others may use                                                  Tail drop - if enabled, or none.  */
name|t_QmCgWredParams
name|wredParams
decl_stmt|;
comment|/**< WRED parameters, relevant if wredEnable = TRUE*/
name|bool
name|tailDropEnable
decl_stmt|;
comment|/**< if TRUE - Tail drop enabled */
name|uint32_t
name|threshold
decl_stmt|;
comment|/**< If Tail drop - used as Tail drop threshold, otherwise                                                  'threshold' may still be used to receive notifications                                                  when threshold is passed. If threshold and f_Exception                                                  are set, interrupts are set defaultly by driver. */
name|bool
name|notifyDcPortal
decl_stmt|;
comment|/**< Relevant if this CG receives enqueues from a direct portal                                                  e_DPAA_DCPORTAL0 or e_DPAA_DCPORTAL1. TRUE to notify                                                  the DC portal, FALSE to notify this SW portal. */
name|e_DpaaDcPortal
name|dcPortalId
decl_stmt|;
comment|/**< relevant if notifyDcPortal=TRUE - DC Portal id */
name|t_QmExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< relevant and mandatory if threshold is configured and                                                  notifyDcPortal = FALSE. If threshold and f_Exception                                                  are set, interrupts are set defaultly by driver */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to the application layer, will be passed as                                                  argument to f_Exception */
block|}
name|t_QmCgParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_CG_Create   @Description   Create and configure a congestion Group.   @Param[in]     p_CgParams      - CG parameters   @Return        A handle to the CG module   @Cautions      Allowed only following QM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|QM_CG_Create
parameter_list|(
name|t_QmCgParams
modifier|*
name|p_CgParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_CG_Free   @Description   Deleting and free all resources of an initialized CG.   @Param[in]     h_QmCg         - A handle to a QM-CG Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init() and QM_CR_Create() for this CG. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_CG_Free
parameter_list|(
name|t_Handle
name|h_QmCg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_cg_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_cg_runtime_control_grp QM-CG Runtime Control Unit   @Description   QM-CG Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM CG WRED colors */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_QmCgColor
block|{
name|e_QM_CG_COLOR_GREEN
block|,
name|e_QM_CG_COLOR_YELLOW
block|,
name|e_QM_CG_COLOR_RED
block|}
name|e_QmCgColor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure representing QM CG modification parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_QmCgModifyWredParams
block|{
name|e_QmCgColor
name|color
decl_stmt|;
name|bool
name|enable
decl_stmt|;
name|t_QmCgWredCurve
name|wredParams
decl_stmt|;
block|}
name|t_QmCgModifyWredParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_CG_SetException   @Description   Set CG exception.   @Param[in]     h_QmCg         - A handle to a QM-CG Module.  @Param[in]     exception      - exception enum  @Param[in]     enable         - TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init() and QM_CG_Create() for this CG. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_CG_SetException
parameter_list|(
name|t_Handle
name|h_QmCg
parameter_list|,
name|e_QmExceptions
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
comment|/**  @Function      QM_CG_ModifyWredCurve   @Description   Change WRED curve parameters for a selected color.                 Note that this routine may be called only for valid CG's that                 already have been configured for WRED, and only need a change                 in the WRED parameters.   @Param[in]     h_QmCg              - A handle to a QM-CG Module.  @Param[in]     p_QmCgModifyParams  - A structure of new WRED parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init() and QM_CG_Create() for this CG. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_CG_ModifyWredCurve
parameter_list|(
name|t_Handle
name|h_QmCg
parameter_list|,
name|t_QmCgModifyWredParams
modifier|*
name|p_QmCgModifyParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      QM_CG_ModifyTailDropThreshold   @Description   Change WRED curve parameters for a selected color.                 Note that this routine may be called only for valid CG's that                 already have been configured for tail drop, and only need a change                 in the threshold value.   @Param[in]     h_QmCg              - A handle to a QM-CG Module.  @Param[in]     threshold           - New threshold.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following QM_Init() and QM_CG_Create() for this CG. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|QM_CG_ModifyTailDropThreshold
parameter_list|(
name|t_Handle
name|h_QmCg
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
comment|/* end of QM_cg_runtime_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_cg_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __QM_EXT_H */
end_comment

end_unit

