begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_pcd_ext.h   @Description   FM PCD API definitions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PCD_EXT
end_ifndef

begin_define
define|#
directive|define
name|__FM_PCD_EXT
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"net_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_ext.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman_kg.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_grp Frame Manager API   @Description   Frame Manager Application Programming Interface   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_grp FM PCD   @Description   Frame Manager PCD (Parse-Classify-Distribute) API.                  The FM PCD module is responsible for the initialization of all                 global classifying FM modules. This includes the parser general and                 common registers, the key generator global and common registers,                 and the policer global and common registers.                 In addition, the FM PCD SW module will initialize all required                 key generator schemes, coarse classification flows, and policer                 profiles. When FM module is configured to work with one of these                 entities, it will register to it using the FM PORT API. The PCD                 module will manage the PCD resources - i.e. resource management of                 KeyGen schemes, etc.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    General PCD defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_PRIVATE_HDRS
value|2
end_define

begin_comment
comment|/**< Number of units/headers saved for user */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS_NUM_OF_HDRS
value|16
end_define

begin_comment
comment|/**< Number of headers supported by HW parser */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_DISTINCTION_UNITS
value|(32 - FM_PCD_MAX_NUM_OF_PRIVATE_HDRS)
end_define

begin_comment
comment|/**< Number of distinction units is limited by                                                                              register size (32 bits) minus reserved bits                                                                              for private headers. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_INTERCHANGEABLE_HDRS
value|4
end_define

begin_comment
comment|/**< Maximum number of interchangeable headers                                                                              in a distinction unit */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_NUM_OF_GENERIC_REGS
value|FM_KG_NUM_OF_GENERIC_REGS
end_define

begin_comment
comment|/**< Total number of generic KeyGen registers */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_MAX_NUM_OF_EXTRACTS_PER_KEY
value|35
end_define

begin_comment
comment|/**< Max number allowed on any configuration;                                                                              For HW implementation reasons, in most                                                                              cases less than this will be allowed; The                                                                              driver will return an initialization error                                                                              if resource is unavailable. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_NUM_OF_EXTRACT_MASKS
value|4
end_define

begin_comment
comment|/**< Total number of masks allowed on KeyGen extractions. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_NUM_OF_DEFAULT_GROUPS
value|16
end_define

begin_comment
comment|/**< Number of default value logical groups */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS_NUM_OF_LABELS
value|32
end_define

begin_comment
comment|/**< Maximum number of SW parser labels */
end_comment

begin_define
define|#
directive|define
name|FM_SW_PRS_MAX_IMAGE_SIZE
value|(FM_PCD_SW_PRS_SIZE
comment|/*- FM_PCD_PRS_SW_OFFSET -FM_PCD_PRS_SW_TAIL_SIZE*/
value|-FM_PCD_PRS_SW_PATCHES_SIZE)
end_define

begin_comment
comment|/**< Maximum size of SW parser code */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_MANIP_INSRT_TEMPLATE_SIZE
value|128
end_define

begin_comment
comment|/**< Maximum size of insertion template for                                                                              insert manipulation */
end_comment

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
name|FM_PCD_FRM_REPLIC_MAX_NUM_OF_ENTRIES
value|64
end_define

begin_comment
comment|/**< Maximum possible entries for frame replicator group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_init_grp FM PCD Initialization Unit   @Description   Frame Manager PCD Initialization Unit API   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   PCD counters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdCounters
block|{
name|e_FM_PCD_KG_COUNTERS_TOTAL
block|,
comment|/**< KeyGen counter */
name|e_FM_PCD_PLCR_COUNTERS_RED
block|,
comment|/**< Policer counter - counts the total number of RED packets that exit the Policer. */
name|e_FM_PCD_PLCR_COUNTERS_YELLOW
block|,
comment|/**< Policer counter - counts the total number of YELLOW packets that exit the Policer. */
name|e_FM_PCD_PLCR_COUNTERS_RECOLORED_TO_RED
block|,
comment|/**< Policer counter - counts the number of packets that changed color to RED by the Policer;                                                                      This is a subset of e_FM_PCD_PLCR_COUNTERS_RED packet count, indicating active color changes. */
name|e_FM_PCD_PLCR_COUNTERS_RECOLORED_TO_YELLOW
block|,
comment|/**< Policer counter - counts the number of packets that changed color to YELLOW by the Policer;                                                                      This is a subset of e_FM_PCD_PLCR_COUNTERS_YELLOW packet count, indicating active color changes. */
name|e_FM_PCD_PLCR_COUNTERS_TOTAL
block|,
comment|/**< Policer counter - counts the total number of packets passed in the Policer. */
name|e_FM_PCD_PLCR_COUNTERS_LENGTH_MISMATCH
block|,
comment|/**< Policer counter - counts the number of packets with length mismatch. */
name|e_FM_PCD_PRS_COUNTERS_PARSE_DISPATCH
block|,
comment|/**< Parser counter - counts the number of times the parser block is dispatched. */
name|e_FM_PCD_PRS_COUNTERS_L2_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter - counts the number of times L2 parse result is returned (including errors). */
name|e_FM_PCD_PRS_COUNTERS_L3_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter - counts the number of times L3 parse result is returned (including errors). */
name|e_FM_PCD_PRS_COUNTERS_L4_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter - counts the number of times L4 parse result is returned (including errors). */
name|e_FM_PCD_PRS_COUNTERS_SHIM_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter - counts the number of times SHIM parse result is returned (including errors). */
name|e_FM_PCD_PRS_COUNTERS_L2_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter - counts the number of times L2 parse result is returned with errors. */
name|e_FM_PCD_PRS_COUNTERS_L3_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter - counts the number of times L3 parse result is returned with errors. */
name|e_FM_PCD_PRS_COUNTERS_L4_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter - counts the number of times L4 parse result is returned with errors. */
name|e_FM_PCD_PRS_COUNTERS_SHIM_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter - counts the number of times SHIM parse result is returned with errors. */
name|e_FM_PCD_PRS_COUNTERS_SOFT_PRS_CYCLES
block|,
comment|/**< Parser counter - counts the number of cycles spent executing soft parser instruction (including stall cycles). */
name|e_FM_PCD_PRS_COUNTERS_SOFT_PRS_STALL_CYCLES
block|,
comment|/**< Parser counter - counts the number of cycles stalled waiting for parser internal memory reads while executing soft parser instruction. */
name|e_FM_PCD_PRS_COUNTERS_HARD_PRS_CYCLE_INCL_STALL_CYCLES
block|,
comment|/**< Parser counter - counts the number of cycles spent executing hard parser (including stall cycles). */
name|e_FM_PCD_PRS_COUNTERS_MURAM_READ_CYCLES
block|,
comment|/**< MURAM counter - counts the number of cycles while performing FMan Memory read. */
name|e_FM_PCD_PRS_COUNTERS_MURAM_READ_STALL_CYCLES
block|,
comment|/**< MURAM counter - counts the number of cycles stalled while performing FMan Memory read. */
name|e_FM_PCD_PRS_COUNTERS_MURAM_WRITE_CYCLES
block|,
comment|/**< MURAM counter - counts the number of cycles while performing FMan Memory write. */
name|e_FM_PCD_PRS_COUNTERS_MURAM_WRITE_STALL_CYCLES
block|,
comment|/**< MURAM counter - counts the number of cycles stalled while performing FMan Memory write. */
name|e_FM_PCD_PRS_COUNTERS_FPM_COMMAND_STALL_CYCLES
comment|/**< FPM counter - counts the number of cycles stalled while performing a FPM Command. */
block|}
name|e_FmPcdCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   PCD interrupts */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdExceptions
block|{
name|e_FM_PCD_KG_EXCEPTION_DOUBLE_ECC
block|,
comment|/**< KeyGen double-bit ECC error is detected on internal memory read access. */
name|e_FM_PCD_KG_EXCEPTION_KEYSIZE_OVERFLOW
block|,
comment|/**< KeyGen scheme configuration error indicating a key size larger than 56 bytes. */
name|e_FM_PCD_PLCR_EXCEPTION_DOUBLE_ECC
block|,
comment|/**< Policer double-bit ECC error has been detected on PRAM read access. */
name|e_FM_PCD_PLCR_EXCEPTION_INIT_ENTRY_ERROR
block|,
comment|/**< Policer access to a non-initialized profile has been detected. */
name|e_FM_PCD_PLCR_EXCEPTION_PRAM_SELF_INIT_COMPLETE
block|,
comment|/**< Policer RAM self-initialization complete */
name|e_FM_PCD_PLCR_EXCEPTION_ATOMIC_ACTION_COMPLETE
block|,
comment|/**< Policer atomic action complete */
name|e_FM_PCD_PRS_EXCEPTION_DOUBLE_ECC
block|,
comment|/**< Parser double-bit ECC error */
name|e_FM_PCD_PRS_EXCEPTION_SINGLE_ECC
comment|/**< Parser single-bit ECC error */
block|}
name|e_FmPcdExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App      - User's application descriptor.  @Param[in]     exception  - The exception.   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmPcdExceptionCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmPcdExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Exceptions user callback routine, will be called upon an exception                 passing the exception identification.   @Param[in]     h_App           - User's application descriptor.  @Param[in]     exception       - The exception.  @Param[in]     index           - id of the relevant source (may be scheme or profile id).  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmPcdIdExceptionCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmPcdExceptions
name|exception
parameter_list|,
name|uint16_t
name|index
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A callback for enqueuing frame onto a QM queue.   @Param[in]     h_QmArg         - Application's handle passed to QM module on enqueue.  @Param[in]     p_Fd            - Frame descriptor for the frame.   @Return        E_OK on success; Error code otherwise.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|t_Error
function_decl|(
name|t_FmPcdQmEnqueueCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_QmArg
parameter_list|,
name|void
modifier|*
name|p_Fd
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Host-Command parameters structure.                  When using Host command for PCD functionalities, a dedicated port                 must be used. If this routine is called for a PCD in a single partition                 environment, or it is the Master partition in a Multi-partition                 environment, The port will be initialized by the PCD driver                 initialization routine.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdHcParams
block|{
name|uintptr_t
name|portBaseAddr
decl_stmt|;
comment|/**< Virtual Address of Host-Command Port memory mapped registers.*/
name|uint8_t
name|portId
decl_stmt|;
comment|/**< Port Id (0-6 relative to Host-Command/Offline-Parsing ports);                                                          NOTE: When configuring Host Command port for                                                          FMANv3 devices (DPAA_VERSION 11 and higher),                                                          portId=0 MUST be used. */
name|uint16_t
name|liodnBase
decl_stmt|;
comment|/**< LIODN base for this port, to be used together with LIODN offset                                                          (irrelevant for P4080 revision 1.0) */
name|uint32_t
name|errFqid
decl_stmt|;
comment|/**< Host-Command Port error queue Id. */
name|uint32_t
name|confFqid
decl_stmt|;
comment|/**< Host-Command Port confirmation queue Id. */
name|uint32_t
name|qmChannel
decl_stmt|;
comment|/**< QM channel dedicated to this Host-Command port;                                                          will be used by the FM for dequeue. */
name|t_FmPcdQmEnqueueCallback
modifier|*
name|f_QmEnqueue
decl_stmt|;
comment|/**< Callback routine for enqueuing a frame to the QM */
name|t_Handle
name|h_QmArg
decl_stmt|;
comment|/**< Application's handle passed to QM module on enqueue */
block|}
name|t_FmPcdHcParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   The main structure for PCD initialization  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdParams
block|{
name|bool
name|prsSupport
decl_stmt|;
comment|/**< TRUE if Parser will be used for any of the FM ports. */
name|bool
name|ccSupport
decl_stmt|;
comment|/**< TRUE if Coarse Classification will be used for any                                                              of the FM ports. */
name|bool
name|kgSupport
decl_stmt|;
comment|/**< TRUE if KeyGen will be used for any of the FM ports. */
name|bool
name|plcrSupport
decl_stmt|;
comment|/**< TRUE if Policer will be used for any of the FM ports. */
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< A handle to the FM module. */
name|uint8_t
name|numOfSchemes
decl_stmt|;
comment|/**< Number of schemes dedicated to this partition.                                                              this parameter is relevant if 'kgSupport'=TRUE. */
name|bool
name|useHostCommand
decl_stmt|;
comment|/**< Optional for single partition, Mandatory for Multi partition */
name|t_FmPcdHcParams
name|hc
decl_stmt|;
comment|/**< Host Command parameters, relevant only if 'useHostCommand'=TRUE;                                                              Relevant when FM not runs in "guest-mode". */
name|t_FmPcdExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Callback routine for general PCD exceptions;                                                              Relevant when FM not runs in "guest-mode". */
name|t_FmPcdIdExceptionCallback
modifier|*
name|f_ExceptionId
decl_stmt|;
comment|/**< Callback routine for specific KeyGen scheme or                                                              Policer profile exceptions;                                                              Relevant when FM not runs in "guest-mode". */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                              be passed by the driver upon calling the above callbacks;                                                              Relevant when FM not runs in "guest-mode". */
name|uint8_t
name|partPlcrProfilesBase
decl_stmt|;
comment|/**< The first policer-profile-id dedicated to this partition.                                                              this parameter is relevant if 'plcrSupport'=TRUE.                                                              NOTE: this parameter relevant only when working with multiple partitions. */
name|uint16_t
name|partNumOfPlcrProfiles
decl_stmt|;
comment|/**< Number of policer-profiles dedicated to this partition.                                                              this parameter is relevant if 'plcrSupport'=TRUE.                                                              NOTE: this parameter relevant only when working with multiple partitions. */
block|}
name|t_FmPcdParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_Config   @Description   Basic configuration of the PCD module.                 Creates descriptor for the FM PCD module.   @Param[in]     p_FmPcdParams    A structure of parameters for the initialization of PCD.   @Return        A handle to the initialized module. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_Config
parameter_list|(
name|t_FmPcdParams
modifier|*
name|p_FmPcdParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_Init   @Description   Initialization of the PCD module.   @Param[in]     h_FmPcd - FM PCD module descriptor.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_Init
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_Free   @Description   Frees all resources that were assigned to FM module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmPcd - FM PCD module descriptor.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_Free
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_advanced_cfg_grp    FM PCD Advanced Configuration Unit   @Description   Frame Manager PCD Advanced Configuration API.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ConfigException   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enabling.                 [DEFAULT_numOfSharedPlcrProfiles].   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ConfigException
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_FmPcdExceptions
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
comment|/**  @Function      FM_PCD_ConfigHcFramesDataMemory   @Description   Configures memory-partition-id for FMan-Controller Host-Command                 frames. Calling this routine changes the internal driver data                 base from its default configuration [0].   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     memId           Memory partition ID.   @Return        E_OK on success; Error code otherwise.   @Cautions      This routine may be called only if 'useHostCommand' was TRUE                 when FM_PCD_Config() routine was called. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ConfigHcFramesDataMemory
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|memId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ConfigPlcrNumOfSharedProfiles   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement.                 [DEFAULT_numOfSharedPlcrProfiles].   @Param[in]     h_FmPcd                     FM PCD module descriptor.  @Param[in]     numOfSharedPlcrProfiles     Number of profiles to                                             be shared between ports on this partition   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ConfigPlcrNumOfSharedProfiles
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|numOfSharedPlcrProfiles
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ConfigPlcrAutoRefreshMode   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement.                 By default auto-refresh is [DEFAULT_plcrAutoRefresh].   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     enable          TRUE to enable, FALSE to disable   @Return        E_OK on success; Error code otherwise.   @Cautions      This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ConfigPlcrAutoRefreshMode
parameter_list|(
name|t_Handle
name|h_FmPcd
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
comment|/**  @Function      FM_PCD_ConfigPrsMaxCycleLimit   @Description   Calling this routine changes the internal data structure for                 the maximum parsing time from its default value                 [DEFAULT_MAX_PRS_CYC_LIM].   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     value           0 to disable the mechanism, or new                                 maximum parsing time.   @Return        E_OK on success; Error code otherwise.   @Cautions      This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ConfigPrsMaxCycleLimit
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_advanced_cfg_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_Runtime_grp FM PCD Runtime Unit   @Description   Frame Manager PCD Runtime Unit API                  The runtime control allows creation of PCD infrastructure modules                 such as Network Environment Characteristics, Classification Plan                 Groups and Coarse Classification Trees.                 It also allows on-the-fly initialization, modification and removal                 of PCD modules such as KeyGen schemes, coarse classification nodes                 and Policer profiles.                  In order to explain the programming model of the PCD driver interface                 a few terms should be explained, and will be used below.                   - Distinction Header - One of the 16 protocols supported by the FM parser,                     or one of the SHIM headers (1 or 2). May be a header with a special                     option (see below).                   - Interchangeable Headers Group - This is a group of Headers recognized                     by either one of them. For example, if in a specific context the user                     chooses to treat IPv4 and IPV6 in the same way, they may create an                     interchangeable Headers Unit consisting of these 2 headers.                   - A Distinction Unit - a Distinction Header or an Interchangeable Headers                     Group.                   - Header with special option - applies to Ethernet, MPLS, VLAN, IPv4 and                     IPv6, includes multicast, broadcast and other protocol specific options.                     In terms of hardware it relates to the options available in the classification                     plan.                   - Network Environment Characteristics - a set of Distinction Units that define                     the total recognizable header selection for a certain environment. This is                     NOT the list of all headers that will ever appear in a flow, but rather                     everything that needs distinction in a flow, where distinction is made by KeyGen                     schemes and coarse classification action descriptors.                  The PCD runtime modules initialization is done in stages. The first stage after                 initializing the PCD module itself is to establish a Network Flows Environment                 Definition. The application may choose to establish one or more such environments.                 Later, when needed, the application will have to state, for some of its modules,                 to which single environment it belongs.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for SW parser labels  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPrsLabelParams
block|{
name|uint32_t
name|instructionOffset
decl_stmt|;
comment|/**< SW parser label instruction offset (2 bytes                                                                  resolution), relative to Parser RAM. */
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< The existence of this header will invoke                                                                  the SW parser code; Use  HEADER_TYPE_NONE                                                                  to indicate that sw parser is to run                                                                  independent of the existence of any protocol                                                                  (run before HW parser). */
name|uint8_t
name|indexPerHdr
decl_stmt|;
comment|/**< Normally 0, if more than one SW parser                                                                  attachments for the same header, use this                                                                  index to distinguish between them. */
block|}
name|t_FmPcdPrsLabelParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for SW parser  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPrsSwParams
block|{
name|bool
name|override
decl_stmt|;
comment|/**< FALSE to invoke a check that nothing else                                                              was loaded to this address, including                                                              internal patches.                                                              TRUE to override any existing code.*/
name|uint32_t
name|size
decl_stmt|;
comment|/**< SW parser code size */
name|uint16_t
name|base
decl_stmt|;
comment|/**< SW parser base (in instruction counts!                                                              must be larger than 0x20)*/
name|uint8_t
modifier|*
name|p_Code
decl_stmt|;
comment|/**< SW parser code */
name|uint32_t
name|swPrsDataParams
index|[
name|FM_PCD_PRS_NUM_OF_HDRS
index|]
decl_stmt|;
comment|/**< SW parser data (parameters) */
name|uint8_t
name|numOfLabels
decl_stmt|;
comment|/**< Number of labels for SW parser. */
name|t_FmPcdPrsLabelParams
name|labelsTable
index|[
name|FM_PCD_PRS_NUM_OF_LABELS
index|]
decl_stmt|;
comment|/**< SW parser labels table, containing                                                              numOfLabels entries */
block|}
name|t_FmPcdPrsSwParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_Enable   @Description   This routine should be called after PCD is initialized for enabling all                 PCD engines according to their existing configuration.   @Param[in]     h_FmPcd         FM PCD module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_Enable
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_Disable   @Description   This routine may be called when PCD is enabled in order to                 disable all PCD engines. It may be called                 only when none of the ports in the system are using the PCD.   @Param[in]     h_FmPcd         FM PCD module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init() and when PCD is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_Disable
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_GetCounter   @Description   Reads one of the FM PCD counters.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     counter     The requested counter.   @Return        Counter's current value.   @Cautions      Allowed only following FM_PCD_Init().                 Note that it is user's responsibility to call this routine only                 for enabled counters, and there will be no indication if a                 disabled counter is accessed. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_GetCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_FmPcdCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Function       FM_PCD_PrsLoadSw  @Description    This routine may be called in order to load software parsing code.   @Param[in]      h_FmPcd        FM PCD module descriptor. @Param[in]      p_SwPrs        A pointer to a structure of software                                parser parameters, including the software                                parser image.  @Return         E_OK on success; Error code otherwise.  @Cautions       Allowed only following FM_PCD_Init() and when PCD is disabled.                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PrsLoadSw
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdPrsSwParams
modifier|*
name|p_SwPrs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Function      FM_PCD_SetAdvancedOffloadSupport  @Description   This routine must be called in order to support the following features:                IP-fragmentation, IP-reassembly, IPsec, Header-manipulation, frame-replicator.  @Param[in]     h_FmPcd         FM PCD module descriptor.  @Return        E_OK on success; Error code otherwise.  @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled.                This routine should NOT be called from guest-partition                (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_SetAdvancedOffloadSupport
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSetDfltValue   @Description   Calling this routine sets a global default value to be used                 by the KeyGen when parser does not recognize a required                 field/header.                 By default default values are 0.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     valueId         0,1 - one of 2 global default values.  @Param[in]     value           The requested default value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled.                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgSetDfltValue
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|valueId
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSetAdditionalDataAfterParsing   @Description   Calling this routine allows the KeyGen to access data past                 the parser finishing point.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     payloadOffset   the number of bytes beyond the parser location.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled.                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgSetAdditionalDataAfterParsing
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|payloadOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_SetException   @Description   Calling this routine enables/disables PCD interrupts.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_SetException
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_FmPcdExceptions
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
comment|/**  @Function      FM_PCD_ModifyCounter   @Description   Sets a value to an enabled counter. Use "0" to reset the counter.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     counter     The requested counter.  @Param[in]     value       The requested value to be written into the counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ModifyCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_FmPcdCounters
name|counter
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_SetPlcrStatistics   @Description   This routine may be used to enable/disable policer statistics                 counter. By default the statistics is enabled.   @Param[in]     h_FmPcd         FM PCD module descriptor  @Param[in]     enable          TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_SetPlcrStatistics
parameter_list|(
name|t_Handle
name|h_FmPcd
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
comment|/**  @Function      FM_PCD_SetPrsStatistics   @Description   Defines whether to gather parser statistics including all ports.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     enable      TRUE to enable, FALSE to disable.   @Return        None   @Cautions      Allowed only following FM_PCD_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_PCD_SetPrsStatistics
parameter_list|(
name|t_Handle
name|h_FmPcd
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
comment|/**  @Function      FM_PCD_HcTxConf   @Description   This routine should be called to confirm frames that were                  received on the HC confirmation queue.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     p_Fd            Frame descriptor of the received frame.   @Cautions      Allowed only following FM_PCD_Init(). Allowed only if 'useHostCommand'                 option was selected in the initialization. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FM_PCD_HcTxConf
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_DpaaFD
modifier|*
name|p_Fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Function      FM_PCD_ForceIntr   @Description   Causes an interrupt event on the requested source.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     exception       An exception to be forced.   @Return        E_OK on success; Error code if the exception is not enabled,                 or is not able to create interrupt.   @Cautions      Allowed only following FM_PCD_Init().                 This routine should NOT be called from guest-partition                 (i.e. guestId != NCSW_MASTER_ID) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ForceIntr
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_FmPcdExceptions
name|exception
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
comment|/**  @Function      FM_PCD_DumpRegs   @Description   Dumps all PCD registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 NOTE: this routine may be called only for FM in master mode                 (i.e. 'guestId'=NCSW_MASTER_ID) or in a case that the registers                 are mapped. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_DumpRegs
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgDumpRegs   @Description   Dumps all PCD KG registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 NOTE: this routine may be called only for FM in master mode                 (i.e. 'guestId'=NCSW_MASTER_ID) or in a case that the registers                 are mapped. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgDumpRegs
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrDumpRegs   @Description   Dumps all PCD Policer registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 NOTE: this routine may be called only for FM in master mode                 (i.e. 'guestId'=NCSW_MASTER_ID) or in a case that the registers                 are mapped. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrDumpRegs
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrProfileDumpRegs   @Description   Dumps all PCD Policer profile registers   @Param[in]     h_Profile       A handle to a Policer profile.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 NOTE: this routine may be called only for FM in master mode                 (i.e. 'guestId'=NCSW_MASTER_ID) or in a case that the registers                 are mapped. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrProfileDumpRegs
parameter_list|(
name|t_Handle
name|h_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PrsDumpRegs   @Description   Dumps all PCD Parser registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 NOTE: this routine may be called only for FM in master mode                 (i.e. 'guestId'=NCSW_MASTER_ID) or in a case that the registers                 are mapped. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PrsDumpRegs
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HcDumpRegs   @Description   Dumps HC Port registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 NOTE: this routine may be called only for FM in master mode                 (i.e. 'guestId'=NCSW_MASTER_ID). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HcDumpRegs
parameter_list|(
name|t_Handle
name|h_FmPcd
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
comment|/**  KeyGen         FM_PCD_Runtime_build_grp FM PCD Runtime Building Unit   @Description   Frame Manager PCD Runtime Building API                  This group contains routines for setting, deleting and modifying                 PCD resources, for defining the total PCD tree.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Definitions of coarse classification                 parameters as required by KeyGen (when coarse classification                 is the next engine after this scheme). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_TREES
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_GROUPS
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_UNITS
value|4
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_KEYS
value|256
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_FLOWS
value|(4*KILOBYTE)
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_SIZE_OF_KEY
value|56
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_ENTRIES_IN_GRP
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_LAST_KEY_INDEX
value|0xffff
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_NODES
value|255
end_define

begin_comment
comment|/* Obsolete, not used - will be removed in the future */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    A set of definitions to allow protocol                 special option description. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|protocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< A general type to define a protocol option. */
end_comment

begin_typedef
typedef|typedef
name|protocolOpt_t
name|ethProtocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< Ethernet protocol options. */
end_comment

begin_define
define|#
directive|define
name|ETH_BROADCAST
value|0x80000000
end_define

begin_comment
comment|/**< Ethernet Broadcast. */
end_comment

begin_define
define|#
directive|define
name|ETH_MULTICAST
value|0x40000000
end_define

begin_comment
comment|/**< Ethernet Multicast. */
end_comment

begin_typedef
typedef|typedef
name|protocolOpt_t
name|vlanProtocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< VLAN protocol options. */
end_comment

begin_define
define|#
directive|define
name|VLAN_STACKED
value|0x20000000
end_define

begin_comment
comment|/**< Stacked VLAN. */
end_comment

begin_typedef
typedef|typedef
name|protocolOpt_t
name|mplsProtocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< MPLS protocol options. */
end_comment

begin_define
define|#
directive|define
name|MPLS_STACKED
value|0x10000000
end_define

begin_comment
comment|/**< Stacked MPLS. */
end_comment

begin_typedef
typedef|typedef
name|protocolOpt_t
name|ipv4ProtocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< IPv4 protocol options. */
end_comment

begin_define
define|#
directive|define
name|IPV4_BROADCAST_1
value|0x08000000
end_define

begin_comment
comment|/**< IPv4 Broadcast. */
end_comment

begin_define
define|#
directive|define
name|IPV4_MULTICAST_1
value|0x04000000
end_define

begin_comment
comment|/**< IPv4 Multicast. */
end_comment

begin_define
define|#
directive|define
name|IPV4_UNICAST_2
value|0x02000000
end_define

begin_comment
comment|/**< Tunneled IPv4 - Unicast. */
end_comment

begin_define
define|#
directive|define
name|IPV4_MULTICAST_BROADCAST_2
value|0x01000000
end_define

begin_comment
comment|/**< Tunneled IPv4 - Broadcast/Multicast. */
end_comment

begin_define
define|#
directive|define
name|IPV4_FRAG_1
value|0x00000008
end_define

begin_comment
comment|/**< IPV4 reassembly option.                                                      IPV4 Reassembly manipulation requires network                                                      environment with IPV4 header and IPV4_FRAG_1 option  */
end_comment

begin_typedef
typedef|typedef
name|protocolOpt_t
name|ipv6ProtocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< IPv6 protocol options. */
end_comment

begin_define
define|#
directive|define
name|IPV6_MULTICAST_1
value|0x00800000
end_define

begin_comment
comment|/**< IPv6 Multicast. */
end_comment

begin_define
define|#
directive|define
name|IPV6_UNICAST_2
value|0x00400000
end_define

begin_comment
comment|/**< Tunneled IPv6 - Unicast. */
end_comment

begin_define
define|#
directive|define
name|IPV6_MULTICAST_2
value|0x00200000
end_define

begin_comment
comment|/**< Tunneled IPv6 - Multicast. */
end_comment

begin_define
define|#
directive|define
name|IPV6_FRAG_1
value|0x00000004
end_define

begin_comment
comment|/**< IPV6 reassembly option.                                                      IPV6 Reassembly manipulation requires network                                                      environment with IPV6 header and IPV6_FRAG_1 option;                                                      in case where fragment found, the fragment-extension offset                                                      may be found at 'shim2' (in parser-result). */
end_comment

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_typedef
typedef|typedef
name|protocolOpt_t
name|capwapProtocolOpt_t
typedef|;
end_typedef

begin_comment
comment|/**< CAPWAP protocol options. */
end_comment

begin_define
define|#
directive|define
name|CAPWAP_FRAG_1
value|0x00000008
end_define

begin_comment
comment|/**< CAPWAP reassembly option.                                                      CAPWAP Reassembly manipulation requires network                                                      environment with CAPWAP header and CAPWAP_FRAG_1 option;                                                      in case where fragment found, the fragment-extension offset                                                      may be found at 'shim2' (in parser-result). */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MANIP_MAX_HDR_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_DSCP_TO_VLAN_TRANS
value|64
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    A set of definitions to support Header Manipulation selection. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|hdrManipFlags_t
typedef|;
end_typedef

begin_comment
comment|/**< A general type to define a HMan update command flags. */
end_comment

begin_typedef
typedef|typedef
name|hdrManipFlags_t
name|ipv4HdrManipUpdateFlags_t
typedef|;
end_typedef

begin_comment
comment|/**< IPv4 protocol HMan update command flags. */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV4_TOS
value|0x80000000
end_define

begin_comment
comment|/**< update TOS with the given value ('tos' field                                                                  of t_FmPcdManipHdrFieldUpdateIpv4) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV4_ID
value|0x40000000
end_define

begin_comment
comment|/**< update IP ID with the given value ('id' field                                                                  of t_FmPcdManipHdrFieldUpdateIpv4) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV4_TTL
value|0x20000000
end_define

begin_comment
comment|/**< Decrement TTL by 1 */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV4_SRC
value|0x10000000
end_define

begin_comment
comment|/**< update IP source address with the given value                                                                  ('src' field of t_FmPcdManipHdrFieldUpdateIpv4) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV4_DST
value|0x08000000
end_define

begin_comment
comment|/**< update IP destination address with the given value                                                                  ('dst' field of t_FmPcdManipHdrFieldUpdateIpv4) */
end_comment

begin_typedef
typedef|typedef
name|hdrManipFlags_t
name|ipv6HdrManipUpdateFlags_t
typedef|;
end_typedef

begin_comment
comment|/**< IPv6 protocol HMan update command flags. */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV6_TC
value|0x80000000
end_define

begin_comment
comment|/**< update Traffic Class address with the given value                                                                  ('trafficClass' field of t_FmPcdManipHdrFieldUpdateIpv6) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV6_HL
value|0x40000000
end_define

begin_comment
comment|/**< Decrement Hop Limit by 1 */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV6_SRC
value|0x20000000
end_define

begin_comment
comment|/**< update IP source address with the given value                                                                  ('src' field of t_FmPcdManipHdrFieldUpdateIpv6) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_IPV6_DST
value|0x10000000
end_define

begin_comment
comment|/**< update IP destination address with the given value                                                                  ('dst' field of t_FmPcdManipHdrFieldUpdateIpv6) */
end_comment

begin_typedef
typedef|typedef
name|hdrManipFlags_t
name|tcpUdpHdrManipUpdateFlags_t
typedef|;
end_typedef

begin_comment
comment|/**< TCP/UDP protocol HMan update command flags. */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_TCP_UDP_SRC
value|0x80000000
end_define

begin_comment
comment|/**< update TCP/UDP source address with the given value                                                                  ('src' field of t_FmPcdManipHdrFieldUpdateTcpUdp) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_TCP_UDP_DST
value|0x40000000
end_define

begin_comment
comment|/**< update TCP/UDP destination address with the given value                                                                  ('dst' field of t_FmPcdManipHdrFieldUpdateTcpUdp) */
end_comment

begin_define
define|#
directive|define
name|HDR_MANIP_TCP_UDP_CHECKSUM
value|0x20000000
end_define

begin_comment
comment|/**< update TCP/UDP checksum */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A type used for returning the order of the key extraction.                 each value in this array represents the index of the extraction                 command as defined by the user in the initialization extraction array.                 The valid size of this array is the user define number of extractions                 required (also marked by the second '0' in this array). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|t_FmPcdKgKeyOrder
index|[
name|FM_PCD_KG_MAX_NUM_OF_EXTRACTS_PER_KEY
index|]
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   All PCD engines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdEngine
block|{
name|e_FM_PCD_INVALID
init|=
literal|0
block|,
comment|/**< Invalid PCD engine */
name|e_FM_PCD_DONE
block|,
comment|/**< No PCD Engine indicated */
name|e_FM_PCD_KG
block|,
comment|/**< KeyGen */
name|e_FM_PCD_CC
block|,
comment|/**< Coarse classifier */
name|e_FM_PCD_PLCR
block|,
comment|/**< Policer */
name|e_FM_PCD_PRS
block|,
comment|/**< Parser */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|e_FM_PCD_FR
block|,
comment|/**< Frame-Replicator */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|e_FM_PCD_HASH
comment|/**< Hash table */
block|}
name|e_FmPcdEngine
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting extraction by header types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdExtractByHdrType
block|{
name|e_FM_PCD_EXTRACT_FROM_HDR
block|,
comment|/**< Extract bytes from header */
name|e_FM_PCD_EXTRACT_FROM_FIELD
block|,
comment|/**< Extract bytes from header field */
name|e_FM_PCD_EXTRACT_FULL_FIELD
comment|/**< Extract a full field */
block|}
name|e_FmPcdExtractByHdrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting extraction source                 (when it is not the header) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdExtractFrom
block|{
name|e_FM_PCD_EXTRACT_FROM_FRAME_START
block|,
comment|/**< KG& CC: Extract from beginning of frame */
name|e_FM_PCD_EXTRACT_FROM_DFLT_VALUE
block|,
comment|/**< KG only: Extract from a default value */
name|e_FM_PCD_EXTRACT_FROM_CURR_END_OF_PARSE
block|,
comment|/**< KG& CC: Extract from the point where parsing had finished */
name|e_FM_PCD_EXTRACT_FROM_KEY
block|,
comment|/**< CC only: Field where saved KEY */
name|e_FM_PCD_EXTRACT_FROM_HASH
block|,
comment|/**< CC only: Field where saved HASH */
name|e_FM_PCD_EXTRACT_FROM_PARSE_RESULT
block|,
comment|/**< KG only: Extract from the parser result */
name|e_FM_PCD_EXTRACT_FROM_ENQ_FQID
block|,
comment|/**< KG& CC: Extract from enqueue FQID */
name|e_FM_PCD_EXTRACT_FROM_FLOW_ID
comment|/**< CC only: Field where saved Dequeue FQID */
block|}
name|e_FmPcdExtractFrom
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting extraction type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdExtractType
block|{
name|e_FM_PCD_EXTRACT_BY_HDR
block|,
comment|/**< Extract according to header */
name|e_FM_PCD_EXTRACT_NON_HDR
block|,
comment|/**< Extract from data that is not the header */
name|e_FM_PCD_KG_EXTRACT_PORT_PRIVATE_INFO
comment|/**< Extract private info as specified by user */
block|}
name|e_FmPcdExtractType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting default extraction value */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdKgExtractDfltSelect
block|{
name|e_FM_PCD_KG_DFLT_GBL_0
block|,
comment|/**< Default selection is KG register 0 */
name|e_FM_PCD_KG_DFLT_GBL_1
block|,
comment|/**< Default selection is KG register 1 */
name|e_FM_PCD_KG_DFLT_PRIVATE_0
block|,
comment|/**< Default selection is a per scheme register 0 */
name|e_FM_PCD_KG_DFLT_PRIVATE_1
block|,
comment|/**< Default selection is a per scheme register 1 */
name|e_FM_PCD_KG_DFLT_ILLEGAL
comment|/**< Illegal selection */
block|}
name|e_FmPcdKgExtractDfltSelect
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type defining all default groups - each group shares                 a default value, one of four user-initialized values. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdKgKnownFieldsDfltTypes
block|{
name|e_FM_PCD_KG_MAC_ADDR
block|,
comment|/**< MAC Address */
name|e_FM_PCD_KG_TCI
block|,
comment|/**< TCI field */
name|e_FM_PCD_KG_ENET_TYPE
block|,
comment|/**< ENET Type */
name|e_FM_PCD_KG_PPP_SESSION_ID
block|,
comment|/**< PPP Session id */
name|e_FM_PCD_KG_PPP_PROTOCOL_ID
block|,
comment|/**< PPP Protocol id */
name|e_FM_PCD_KG_MPLS_LABEL
block|,
comment|/**< MPLS label */
name|e_FM_PCD_KG_IP_ADDR
block|,
comment|/**< IP address */
name|e_FM_PCD_KG_PROTOCOL_TYPE
block|,
comment|/**< Protocol type */
name|e_FM_PCD_KG_IP_TOS_TC
block|,
comment|/**< TOS or TC */
name|e_FM_PCD_KG_IPV6_FLOW_LABEL
block|,
comment|/**< IPV6 flow label */
name|e_FM_PCD_KG_IPSEC_SPI
block|,
comment|/**< IPSEC SPI */
name|e_FM_PCD_KG_L4_PORT
block|,
comment|/**< L4 Port */
name|e_FM_PCD_KG_TCP_FLAG
block|,
comment|/**< TCP Flag */
name|e_FM_PCD_KG_GENERIC_FROM_DATA
block|,
comment|/**< grouping implemented by SW,                                              any data extraction that is not the full                                              field described above  */
name|e_FM_PCD_KG_GENERIC_FROM_DATA_NO_V
block|,
comment|/**< grouping implemented by SW,                                              any data extraction without validation */
name|e_FM_PCD_KG_GENERIC_NOT_FROM_DATA
comment|/**< grouping implemented by SW,                                              extraction from parser result or                                              direct use of default value  */
block|}
name|e_FmPcdKgKnownFieldsDfltTypes
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for defining header index for scenarios with                 multiple (tunneled) headers */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdHdrIndex
block|{
name|e_FM_PCD_HDR_INDEX_NONE
init|=
literal|0
block|,
comment|/**< used when multiple headers not used, also                                              to specify regular IP (not tunneled). */
name|e_FM_PCD_HDR_INDEX_1
block|,
comment|/**< may be used for VLAN, MPLS, tunneled IP */
name|e_FM_PCD_HDR_INDEX_2
block|,
comment|/**< may be used for MPLS, tunneled IP */
name|e_FM_PCD_HDR_INDEX_3
block|,
comment|/**< may be used for MPLS */
name|e_FM_PCD_HDR_INDEX_LAST
init|=
literal|0xFF
comment|/**< may be used for VLAN, MPLS */
block|}
name|e_FmPcdHdrIndex
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting the policer profile functional type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdProfileTypeSelection
block|{
name|e_FM_PCD_PLCR_PORT_PRIVATE
block|,
comment|/**< Port dedicated profile */
name|e_FM_PCD_PLCR_SHARED
comment|/**< Shared profile (shared within partition) */
block|}
name|e_FmPcdProfileTypeSelection
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting the policer profile algorithm */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrAlgorithmSelection
block|{
name|e_FM_PCD_PLCR_PASS_THROUGH
block|,
comment|/**< Policer pass through */
name|e_FM_PCD_PLCR_RFC_2698
block|,
comment|/**< Policer algorithm RFC 2698 */
name|e_FM_PCD_PLCR_RFC_4115
comment|/**< Policer algorithm RFC 4115 */
block|}
name|e_FmPcdPlcrAlgorithmSelection
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting a policer profile color mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrColorMode
block|{
name|e_FM_PCD_PLCR_COLOR_BLIND
block|,
comment|/**< Color blind */
name|e_FM_PCD_PLCR_COLOR_AWARE
comment|/**< Color aware */
block|}
name|e_FmPcdPlcrColorMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting a policer profile color */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrColor
block|{
name|e_FM_PCD_PLCR_GREEN
block|,
comment|/**< Green color code */
name|e_FM_PCD_PLCR_YELLOW
block|,
comment|/**< Yellow color code */
name|e_FM_PCD_PLCR_RED
block|,
comment|/**< Red color code */
name|e_FM_PCD_PLCR_OVERRIDE
comment|/**< Color override code */
block|}
name|e_FmPcdPlcrColor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting the policer profile packet frame length selector */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrFrameLengthSelect
block|{
name|e_FM_PCD_PLCR_L2_FRM_LEN
block|,
comment|/**< L2 frame length */
name|e_FM_PCD_PLCR_L3_FRM_LEN
block|,
comment|/**< L3 frame length */
name|e_FM_PCD_PLCR_L4_FRM_LEN
block|,
comment|/**< L4 frame length */
name|e_FM_PCD_PLCR_FULL_FRM_LEN
comment|/**< Full frame length */
block|}
name|e_FmPcdPlcrFrameLengthSelect
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting roll-back frame */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrRollBackFrameSelect
block|{
name|e_FM_PCD_PLCR_ROLLBACK_L2_FRM_LEN
block|,
comment|/**< Roll-back L2 frame length */
name|e_FM_PCD_PLCR_ROLLBACK_FULL_FRM_LEN
comment|/**< Roll-back Full frame length */
block|}
name|e_FmPcdPlcrRollBackFrameSelect
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting the policer profile packet or byte mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrRateMode
block|{
name|e_FM_PCD_PLCR_BYTE_MODE
block|,
comment|/**< Byte mode */
name|e_FM_PCD_PLCR_PACKET_MODE
comment|/**< Packet mode */
block|}
name|e_FmPcdPlcrRateMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for defining action of frame */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdDoneAction
block|{
name|e_FM_PCD_ENQ_FRAME
init|=
literal|0
block|,
comment|/**< Enqueue frame */
name|e_FM_PCD_DROP_FRAME
comment|/**< Mark this frame as error frame and continue                                         to error flow; 'FM_PORT_FRM_ERR_CLS_DISCARD'                                         flag will be set for this frame. */
block|}
name|e_FmPcdDoneAction
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting the policer counter */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdPlcrProfileCounters
block|{
name|e_FM_PCD_PLCR_PROFILE_GREEN_PACKET_TOTAL_COUNTER
block|,
comment|/**< Green packets counter */
name|e_FM_PCD_PLCR_PROFILE_YELLOW_PACKET_TOTAL_COUNTER
block|,
comment|/**< Yellow packets counter */
name|e_FM_PCD_PLCR_PROFILE_RED_PACKET_TOTAL_COUNTER
block|,
comment|/**< Red packets counter */
name|e_FM_PCD_PLCR_PROFILE_RECOLOURED_YELLOW_PACKET_TOTAL_COUNTER
block|,
comment|/**< Recolored yellow packets counter */
name|e_FM_PCD_PLCR_PROFILE_RECOLOURED_RED_PACKET_TOTAL_COUNTER
comment|/**< Recolored red packets counter */
block|}
name|e_FmPcdPlcrProfileCounters
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting the PCD action after extraction */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdAction
block|{
name|e_FM_PCD_ACTION_NONE
block|,
comment|/**< NONE  */
name|e_FM_PCD_ACTION_EXACT_MATCH
block|,
comment|/**< Exact match on the selected extraction */
name|e_FM_PCD_ACTION_INDEXED_LOOKUP
comment|/**< Indexed lookup on the selected extraction */
block|}
name|e_FmPcdAction
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of insert manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrInsrtType
block|{
name|e_FM_PCD_MANIP_INSRT_GENERIC
block|,
comment|/**< Insert according to offset& size */
name|e_FM_PCD_MANIP_INSRT_BY_HDR
block|,
comment|/**< Insert according to protocol */
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
name|e_FM_PCD_MANIP_INSRT_BY_TEMPLATE
comment|/**< Insert template to start of frame */
endif|#
directive|endif
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
block|}
name|e_FmPcdManipHdrInsrtType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of remove manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrRmvType
block|{
name|e_FM_PCD_MANIP_RMV_GENERIC
block|,
comment|/**< Remove according to offset& size */
name|e_FM_PCD_MANIP_RMV_BY_HDR
comment|/**< Remove according to offset& size */
block|}
name|e_FmPcdManipHdrRmvType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting specific L2 fields removal */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrRmvSpecificL2
block|{
name|e_FM_PCD_MANIP_HDR_RMV_ETHERNET
block|,
comment|/**< Ethernet/802.3 MAC */
name|e_FM_PCD_MANIP_HDR_RMV_STACKED_QTAGS
block|,
comment|/**< stacked QTags */
name|e_FM_PCD_MANIP_HDR_RMV_ETHERNET_AND_MPLS
block|,
comment|/**< MPLS and Ethernet/802.3 MAC header until                                                          the header which follows the MPLS header */
name|e_FM_PCD_MANIP_HDR_RMV_MPLS
block|,
comment|/**< Remove MPLS header (Unlimited MPLS labels) */
name|e_FM_PCD_MANIP_HDR_RMV_PPPOE
comment|/**< Remove the PPPoE header and PPP protocol field. */
block|}
name|e_FmPcdManipHdrRmvSpecificL2
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting specific fields updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrFieldUpdateType
block|{
name|e_FM_PCD_MANIP_HDR_FIELD_UPDATE_VLAN
block|,
comment|/**< VLAN updates */
name|e_FM_PCD_MANIP_HDR_FIELD_UPDATE_IPV4
block|,
comment|/**< IPV4 updates */
name|e_FM_PCD_MANIP_HDR_FIELD_UPDATE_IPV6
block|,
comment|/**< IPV6 updates */
name|e_FM_PCD_MANIP_HDR_FIELD_UPDATE_TCP_UDP
block|,
comment|/**< TCP_UDP updates */
block|}
name|e_FmPcdManipHdrFieldUpdateType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting VLAN updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrFieldUpdateVlan
block|{
name|e_FM_PCD_MANIP_HDR_FIELD_UPDATE_VLAN_VPRI
block|,
comment|/**< Replace VPri of outer most VLAN tag. */
name|e_FM_PCD_MANIP_HDR_FIELD_UPDATE_DSCP_TO_VLAN
comment|/**< DSCP to VLAN priority bits translation */
block|}
name|e_FmPcdManipHdrFieldUpdateVlan
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting specific L2 header insertion */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrInsrtSpecificL2
block|{
name|e_FM_PCD_MANIP_HDR_INSRT_MPLS
block|,
comment|/**< Insert MPLS header (Unlimited MPLS labels) */
name|e_FM_PCD_MANIP_HDR_INSRT_PPPOE
comment|/**< Insert PPPOE */
block|}
name|e_FmPcdManipHdrInsrtSpecificL2
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting QoS mapping mode                  Note: In all cases except 'e_FM_PCD_MANIP_HDR_QOS_MAPPING_NONE'                 User should instruct the port to read the hash-result */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrQosMappingMode
block|{
name|e_FM_PCD_MANIP_HDR_QOS_MAPPING_NONE
init|=
literal|0
block|,
comment|/**< No mapping, QoS field will not be changed */
name|e_FM_PCD_MANIP_HDR_QOS_MAPPING_AS_IS
block|,
comment|/**< QoS field will be overwritten by the last byte in the hash-result. */
block|}
name|e_FmPcdManipHdrQosMappingMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting QoS source                  Note: In all cases except 'e_FM_PCD_MANIP_HDR_QOS_SRC_NONE'                 User should left room for the hash-result on input/output buffer                 and instruct the port to read/write the hash-result to the buffer (RPD should be set) */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrQosSrc
block|{
name|e_FM_PCD_MANIP_HDR_QOS_SRC_NONE
init|=
literal|0
block|,
comment|/**< TODO */
name|e_FM_PCD_MANIP_HDR_QOS_SRC_USER_DEFINED
block|,
comment|/**< QoS will be taken from the last byte in the hash-result. */
block|}
name|e_FmPcdManipHdrQosSrc
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of header insertion */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrInsrtByHdrType
block|{
name|e_FM_PCD_MANIP_INSRT_BY_HDR_SPECIFIC_L2
block|,
comment|/**< Specific L2 fields insertion */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|e_FM_PCD_MANIP_INSRT_BY_HDR_IP
block|,
comment|/**< IP insertion */
name|e_FM_PCD_MANIP_INSRT_BY_HDR_UDP
block|,
comment|/**< UDP insertion */
name|e_FM_PCD_MANIP_INSRT_BY_HDR_UDP_LITE
block|,
comment|/**< UDP lite insertion */
name|e_FM_PCD_MANIP_INSRT_BY_HDR_CAPWAP
comment|/**< CAPWAP insertion */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|e_FmPcdManipHdrInsrtByHdrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting specific customCommand */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrCustomType
block|{
name|e_FM_PCD_MANIP_HDR_CUSTOM_IP_REPLACE
block|,
comment|/**< Replace IPv4/IPv6 */
name|e_FM_PCD_MANIP_HDR_CUSTOM_GEN_FIELD_REPLACE
block|,
comment|/**< Replace IPv4/IPv6 */
block|}
name|e_FmPcdManipHdrCustomType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting specific customCommand */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrCustomIpReplace
block|{
name|e_FM_PCD_MANIP_HDR_CUSTOM_REPLACE_IPV4_BY_IPV6
block|,
comment|/**< Replace IPv4 by IPv6 */
name|e_FM_PCD_MANIP_HDR_CUSTOM_REPLACE_IPV6_BY_IPV4
comment|/**< Replace IPv6 by IPv4 */
block|}
name|e_FmPcdManipHdrCustomIpReplace
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of header removal */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipHdrRmvByHdrType
block|{
name|e_FM_PCD_MANIP_RMV_BY_HDR_SPECIFIC_L2
init|=
literal|0
block|,
comment|/**< Specific L2 fields removal */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|e_FM_PCD_MANIP_RMV_BY_HDR_CAPWAP
block|,
comment|/**< CAPWAP removal */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
operator|||
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
name|e_FM_PCD_MANIP_RMV_BY_HDR_FROM_START
block|,
comment|/**< Locate from data that is not the header */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) || ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
block|}
name|e_FmPcdManipHdrRmvByHdrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of timeout mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipReassemTimeOutMode
block|{
name|e_FM_PCD_MANIP_TIME_OUT_BETWEEN_FRAMES
block|,
comment|/**< Limits the time of the reassembly process                                                  from the first fragment to the last */
name|e_FM_PCD_MANIP_TIME_OUT_BETWEEN_FRAG
comment|/**< Limits the time of receiving the fragment */
block|}
name|e_FmPcdManipReassemTimeOutMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of WaysNumber mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipReassemWaysNumber
block|{
name|e_FM_PCD_MANIP_ONE_WAY_HASH
init|=
literal|1
block|,
comment|/**< One way hash    */
name|e_FM_PCD_MANIP_TWO_WAYS_HASH
block|,
comment|/**< Two ways hash   */
name|e_FM_PCD_MANIP_THREE_WAYS_HASH
block|,
comment|/**< Three ways hash */
name|e_FM_PCD_MANIP_FOUR_WAYS_HASH
block|,
comment|/**< Four ways hash  */
name|e_FM_PCD_MANIP_FIVE_WAYS_HASH
block|,
comment|/**< Five ways hash  */
name|e_FM_PCD_MANIP_SIX_WAYS_HASH
block|,
comment|/**< Six ways hash   */
name|e_FM_PCD_MANIP_SEVEN_WAYS_HASH
block|,
comment|/**< Seven ways hash */
name|e_FM_PCD_MANIP_EIGHT_WAYS_HASH
comment|/**< Eight ways hash */
block|}
name|e_FmPcdManipReassemWaysNumber
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of statistics mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdStatsType
block|{
name|e_FM_PCD_STATS_PER_FLOWID
init|=
literal|0
comment|/**< Flow ID is used as index for getting statistics */
block|}
name|e_FmPcdStatsType
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting manipulation type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipType
block|{
name|e_FM_PCD_MANIP_HDR
init|=
literal|0
block|,
comment|/**< Header manipulation */
name|e_FM_PCD_MANIP_REASSEM
block|,
comment|/**< Reassembly */
name|e_FM_PCD_MANIP_FRAG
block|,
comment|/**< Fragmentation */
name|e_FM_PCD_MANIP_SPECIAL_OFFLOAD
comment|/**< Special Offloading */
block|}
name|e_FmPcdManipType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of statistics mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdCcStatsMode
block|{
name|e_FM_PCD_CC_STATS_MODE_NONE
init|=
literal|0
block|,
comment|/**< No statistics support */
name|e_FM_PCD_CC_STATS_MODE_FRAME
block|,
comment|/**< Frame count statistics */
name|e_FM_PCD_CC_STATS_MODE_BYTE_AND_FRAME
block|,
comment|/**< Byte and frame count statistics */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|e_FM_PCD_CC_STATS_MODE_RMON
block|,
comment|/**< Byte and frame length range count statistics;                                                  This mode is supported only on B4860 device */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|e_FmPcdCcStatsMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for determining the action in case an IP packet                 is larger than MTU but its DF (Don't Fragment) bit is set. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipDontFragAction
block|{
name|e_FM_PCD_MANIP_DISCARD_PACKET
init|=
literal|0
block|,
comment|/**< Discard packet */
name|e_FM_PCD_MANIP_ENQ_TO_ERR_Q_OR_DISCARD_PACKET
init|=
name|e_FM_PCD_MANIP_DISCARD_PACKET
block|,
comment|/**< Obsolete, cannot enqueue to error queue;                                                              In practice, selects to discard packets;                                                              Will be removed in the future */
name|e_FM_PCD_MANIP_FRAGMENT_PACKET
block|,
comment|/**< Fragment packet and continue normal processing */
name|e_FM_PCD_MANIP_CONTINUE_WITHOUT_FRAG
comment|/**< Continue normal processing without fragmenting the packet */
block|}
name|e_FmPcdManipDontFragAction
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enumeration type for selecting type of special offload manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipSpecialOffloadType
block|{
name|e_FM_PCD_MANIP_SPECIAL_OFFLOAD_IPSEC
block|,
comment|/**< IPSec offload manipulation */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|e_FM_PCD_MANIP_SPECIAL_OFFLOAD_CAPWAP
comment|/**< CAPWAP offload manipulation */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|e_FmPcdManipSpecialOffloadType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A Union of protocol dependent special options */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|u_FmPcdHdrProtocolOpt
block|{
name|ethProtocolOpt_t
name|ethOpt
decl_stmt|;
comment|/**< Ethernet options */
name|vlanProtocolOpt_t
name|vlanOpt
decl_stmt|;
comment|/**< VLAN options */
name|mplsProtocolOpt_t
name|mplsOpt
decl_stmt|;
comment|/**< MPLS options */
name|ipv4ProtocolOpt_t
name|ipv4Opt
decl_stmt|;
comment|/**< IPv4 options */
name|ipv6ProtocolOpt_t
name|ipv6Opt
decl_stmt|;
comment|/**< IPv6 options */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|capwapProtocolOpt_t
name|capwapOpt
decl_stmt|;
comment|/**< CAPWAP options */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|u_FmPcdHdrProtocolOpt
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A union holding protocol fields                   Fields supported as "full fields":                     HEADER_TYPE_ETH:                         NET_HEADER_FIELD_ETH_DA                         NET_HEADER_FIELD_ETH_SA                         NET_HEADER_FIELD_ETH_TYPE                      HEADER_TYPE_LLC_SNAP:                         NET_HEADER_FIELD_LLC_SNAP_TYPE                      HEADER_TYPE_VLAN:                         NET_HEADER_FIELD_VLAN_TCI                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_LAST)                      HEADER_TYPE_MPLS:                         NET_HEADER_FIELD_MPLS_LABEL_STACK                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_2,                                  e_FM_PCD_HDR_INDEX_LAST)                      HEADER_TYPE_IPv4:                         NET_HEADER_FIELD_IPv4_SRC_IP                         NET_HEADER_FIELD_IPv4_DST_IP                         NET_HEADER_FIELD_IPv4_PROTO                         NET_HEADER_FIELD_IPv4_TOS                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_2/e_FM_PCD_HDR_INDEX_LAST)                      HEADER_TYPE_IPv6:                         NET_HEADER_FIELD_IPv6_SRC_IP                         NET_HEADER_FIELD_IPv6_DST_IP                         NET_HEADER_FIELD_IPv6_NEXT_HDR                         NET_HEADER_FIELD_IPv6_VER | NET_HEADER_FIELD_IPv6_FL | NET_HEADER_FIELD_IPv6_TC (must come together!)                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_2/e_FM_PCD_HDR_INDEX_LAST)                                  (Note that starting from DPAA 1-1, NET_HEADER_FIELD_IPv6_NEXT_HDR applies to                                  the last next header indication, meaning the next L4, which may be                                  present at the Ipv6 last extension. On earlier revisions this field                                  applies to the Next-Header field of the main IPv6 header)                      HEADER_TYPE_IP:                         NET_HEADER_FIELD_IP_PROTO                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_LAST)                         NET_HEADER_FIELD_IP_DSCP                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1)                     HEADER_TYPE_GRE:                         NET_HEADER_FIELD_GRE_TYPE                      HEADER_TYPE_MINENCAP                         NET_HEADER_FIELD_MINENCAP_SRC_IP                         NET_HEADER_FIELD_MINENCAP_DST_IP                         NET_HEADER_FIELD_MINENCAP_TYPE                      HEADER_TYPE_TCP:                         NET_HEADER_FIELD_TCP_PORT_SRC                         NET_HEADER_FIELD_TCP_PORT_DST                         NET_HEADER_FIELD_TCP_FLAGS                      HEADER_TYPE_UDP:                         NET_HEADER_FIELD_UDP_PORT_SRC                         NET_HEADER_FIELD_UDP_PORT_DST                      HEADER_TYPE_UDP_LITE:                         NET_HEADER_FIELD_UDP_LITE_PORT_SRC                         NET_HEADER_FIELD_UDP_LITE_PORT_DST                      HEADER_TYPE_IPSEC_AH:                         NET_HEADER_FIELD_IPSEC_AH_SPI                         NET_HEADER_FIELD_IPSEC_AH_NH                      HEADER_TYPE_IPSEC_ESP:                         NET_HEADER_FIELD_IPSEC_ESP_SPI                      HEADER_TYPE_SCTP:                         NET_HEADER_FIELD_SCTP_PORT_SRC                         NET_HEADER_FIELD_SCTP_PORT_DST                      HEADER_TYPE_DCCP:                         NET_HEADER_FIELD_DCCP_PORT_SRC                         NET_HEADER_FIELD_DCCP_PORT_DST                      HEADER_TYPE_PPPoE:                         NET_HEADER_FIELD_PPPoE_PID                         NET_HEADER_FIELD_PPPoE_SID          *****************************************************************                 Fields supported as "from fields":                     HEADER_TYPE_ETH (with or without validation):                         NET_HEADER_FIELD_ETH_TYPE                      HEADER_TYPE_VLAN (with or without validation):                         NET_HEADER_FIELD_VLAN_TCI                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_LAST)                      HEADER_TYPE_IPv4 (without validation):                         NET_HEADER_FIELD_IPv4_PROTO                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_2/e_FM_PCD_HDR_INDEX_LAST)                      HEADER_TYPE_IPv6 (without validation):                         NET_HEADER_FIELD_IPv6_NEXT_HDR                                 (index may apply:                                  e_FM_PCD_HDR_INDEX_NONE/e_FM_PCD_HDR_INDEX_1,                                  e_FM_PCD_HDR_INDEX_2/e_FM_PCD_HDR_INDEX_LAST)  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|t_FmPcdFields
block|{
name|headerFieldEth_t
name|eth
decl_stmt|;
comment|/**< Ethernet               */
name|headerFieldVlan_t
name|vlan
decl_stmt|;
comment|/**< VLAN                   */
name|headerFieldLlcSnap_t
name|llcSnap
decl_stmt|;
comment|/**< LLC SNAP               */
name|headerFieldPppoe_t
name|pppoe
decl_stmt|;
comment|/**< PPPoE                  */
name|headerFieldMpls_t
name|mpls
decl_stmt|;
comment|/**< MPLS                   */
name|headerFieldIp_t
name|ip
decl_stmt|;
comment|/**< IP                     */
name|headerFieldIpv4_t
name|ipv4
decl_stmt|;
comment|/**< IPv4                   */
name|headerFieldIpv6_t
name|ipv6
decl_stmt|;
comment|/**< IPv6                   */
name|headerFieldUdp_t
name|udp
decl_stmt|;
comment|/**< UDP                    */
name|headerFieldUdpLite_t
name|udpLite
decl_stmt|;
comment|/**< UDP Lite               */
name|headerFieldTcp_t
name|tcp
decl_stmt|;
comment|/**< TCP                    */
name|headerFieldSctp_t
name|sctp
decl_stmt|;
comment|/**< SCTP                   */
name|headerFieldDccp_t
name|dccp
decl_stmt|;
comment|/**< DCCP                   */
name|headerFieldGre_t
name|gre
decl_stmt|;
comment|/**< GRE                    */
name|headerFieldMinencap_t
name|minencap
decl_stmt|;
comment|/**< Minimal Encapsulation  */
name|headerFieldIpsecAh_t
name|ipsecAh
decl_stmt|;
comment|/**< IPSec AH               */
name|headerFieldIpsecEsp_t
name|ipsecEsp
decl_stmt|;
comment|/**< IPSec ESP              */
name|headerFieldUdpEncapEsp_t
name|udpEncapEsp
decl_stmt|;
comment|/**< UDP Encapsulation ESP  */
block|}
name|t_FmPcdFields
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header extraction for key generation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdFromHdr
block|{
name|uint8_t
name|size
decl_stmt|;
comment|/**< Size in byte */
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Byte offset */
block|}
name|t_FmPcdFromHdr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining field extraction for key generation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdFromField
block|{
name|t_FmPcdFields
name|field
decl_stmt|;
comment|/**< Field selection */
name|uint8_t
name|size
decl_stmt|;
comment|/**< Size in byte */
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Byte offset */
block|}
name|t_FmPcdFromField
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a single network environment unit                  A distinction unit should be defined if it will later be used                 by one or more PCD engines to distinguish between flows. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdDistinctionUnit
block|{
struct|struct
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< One of the headers supported by the FM */
name|u_FmPcdHdrProtocolOpt
name|opt
decl_stmt|;
comment|/**< Select only one option ! */
block|}
name|hdrs
index|[
name|FM_PCD_MAX_NUM_OF_INTERCHANGEABLE_HDRS
index|]
struct|;
block|}
name|t_FmPcdDistinctionUnit
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining all different distinction units supported                 by a specific PCD Network Environment Characteristics module.                  Each unit represent a protocol or a group of protocols that may                 be used later by the different PCD engines to distinguish                 between flows. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdNetEnvParams
block|{
name|uint8_t
name|numOfDistinctionUnits
decl_stmt|;
comment|/**< Number of different units to be identified */
name|t_FmPcdDistinctionUnit
name|units
index|[
name|FM_PCD_MAX_NUM_OF_DISTINCTION_UNITS
index|]
decl_stmt|;
comment|/**< An array of numOfDistinctionUnits of the                                                                              different units to be identified */
block|}
name|t_FmPcdNetEnvParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a single extraction action when                 creating a key */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdExtractEntry
block|{
name|e_FmPcdExtractType
name|type
decl_stmt|;
comment|/**< Extraction type select */
union|union
block|{
struct|struct
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
name|bool
name|ignoreProtocolValidation
decl_stmt|;
comment|/**< Ignore protocol validation */
name|e_FmPcdHdrIndex
name|hdrIndex
decl_stmt|;
comment|/**< Relevant only for MPLS, VLAN and tunneled                                                              IP. Otherwise should be cleared. */
name|e_FmPcdExtractByHdrType
name|type
decl_stmt|;
comment|/**< Header extraction type select */
union|union
block|{
name|t_FmPcdFromHdr
name|fromHdr
decl_stmt|;
comment|/**< Extract bytes from header parameters */
name|t_FmPcdFromField
name|fromField
decl_stmt|;
comment|/**< Extract bytes from field parameters */
name|t_FmPcdFields
name|fullField
decl_stmt|;
comment|/**< Extract full filed parameters */
block|}
name|extractByHdrType
union|;
block|}
name|extractByHdr
struct|;
comment|/**< used when type = e_FM_PCD_KG_EXTRACT_BY_HDR */
struct|struct
block|{
name|e_FmPcdExtractFrom
name|src
decl_stmt|;
comment|/**< Non-header extraction source */
name|e_FmPcdAction
name|action
decl_stmt|;
comment|/**< Relevant for CC Only */
name|uint16_t
name|icIndxMask
decl_stmt|;
comment|/**< Relevant only for CC when                                                              action = e_FM_PCD_ACTION_INDEXED_LOOKUP;                                                              Note that the number of bits that are set within                                                              this mask must be log2 of the CC-node 'numOfKeys'.                                                              Note that the mask cannot be set on the lower bits. */
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Byte offset */
name|uint8_t
name|size
decl_stmt|;
comment|/**< Size in byte */
block|}
name|extractNonHdr
struct|;
comment|/**< used when type = e_FM_PCD_KG_EXTRACT_NON_HDR */
block|}
union|;
block|}
name|t_FmPcdExtractEntry
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining masks for each extracted field in the key. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgExtractMask
block|{
name|uint8_t
name|extractArrayIndex
decl_stmt|;
comment|/**< Index in the extraction array, as initialized by user */
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Byte offset */
name|uint8_t
name|mask
decl_stmt|;
comment|/**< A byte mask (selected bits will be used) */
block|}
name|t_FmPcdKgExtractMask
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining default selection per groups of fields */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgExtractDflt
block|{
name|e_FmPcdKgKnownFieldsDfltTypes
name|type
decl_stmt|;
comment|/**< Default type select */
name|e_FmPcdKgExtractDfltSelect
name|dfltSelect
decl_stmt|;
comment|/**< Default register select */
block|}
name|t_FmPcdKgExtractDflt
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining key extraction and hashing */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgKeyExtractAndHashParams
block|{
name|uint32_t
name|privateDflt0
decl_stmt|;
comment|/**< Scheme default register 0 */
name|uint32_t
name|privateDflt1
decl_stmt|;
comment|/**< Scheme default register 1 */
name|uint8_t
name|numOfUsedExtracts
decl_stmt|;
comment|/**< defines the valid size of the following array */
name|t_FmPcdExtractEntry
name|extractArray
index|[
name|FM_PCD_KG_MAX_NUM_OF_EXTRACTS_PER_KEY
index|]
decl_stmt|;
comment|/**< An array of extractions definition. */
name|uint8_t
name|numOfUsedDflts
decl_stmt|;
comment|/**< defines the valid size of the following array */
name|t_FmPcdKgExtractDflt
name|dflts
index|[
name|FM_PCD_KG_NUM_OF_DEFAULT_GROUPS
index|]
decl_stmt|;
comment|/**< For each extraction used in this scheme, specify the required                                                                   default register to be used when header is not found.                                                                   types not specified in this array will get undefined value. */
name|uint8_t
name|numOfUsedMasks
decl_stmt|;
comment|/**< defines the valid size of the following array */
name|t_FmPcdKgExtractMask
name|masks
index|[
name|FM_PCD_KG_NUM_OF_EXTRACT_MASKS
index|]
decl_stmt|;
name|uint8_t
name|hashShift
decl_stmt|;
comment|/**< hash result right shift. Select the 24 bits out of the 64 hash                                                                   result. 0 means using the 24 LSB's, otherwise use the                                                                   24 LSB's after shifting right.*/
name|uint32_t
name|hashDistributionNumOfFqids
decl_stmt|;
comment|/**< must be> 1 and a power of 2. Represents the range                                                                   of queues for the key and hash functionality */
name|uint8_t
name|hashDistributionFqidsShift
decl_stmt|;
comment|/**< selects the FQID bits that will be effected by the hash */
name|bool
name|symmetricHash
decl_stmt|;
comment|/**< TRUE to generate the same hash for frames with swapped source and                                                                   destination fields on all layers; If TRUE, driver will check that for                                                                   all layers, if SRC extraction is selected, DST extraction must also be                                                                   selected, and vice versa. */
block|}
name|t_FmPcdKgKeyExtractAndHashParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a single FQID mask (extracted OR). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgExtractedOrParams
block|{
name|e_FmPcdExtractType
name|type
decl_stmt|;
comment|/**< Extraction type select */
union|union
block|{
struct|struct
block|{
comment|/**< used when type = e_FM_PCD_KG_EXTRACT_BY_HDR */
name|e_NetHeaderType
name|hdr
decl_stmt|;
name|e_FmPcdHdrIndex
name|hdrIndex
decl_stmt|;
comment|/**< Relevant only for MPLS, VLAN and tunneled                                                              IP. Otherwise should be cleared.*/
name|bool
name|ignoreProtocolValidation
decl_stmt|;
comment|/**< continue extraction even if protocol is not recognized */
block|}
name|extractByHdr
struct|;
comment|/**< Header to extract by */
name|e_FmPcdExtractFrom
name|src
decl_stmt|;
comment|/**< used when type = e_FM_PCD_KG_EXTRACT_NON_HDR */
block|}
union|;
name|uint8_t
name|extractionOffset
decl_stmt|;
comment|/**< Offset for extraction (in bytes).  */
name|e_FmPcdKgExtractDfltSelect
name|dfltValue
decl_stmt|;
comment|/**< Select register from which extraction is taken if                                                              field not found */
name|uint8_t
name|mask
decl_stmt|;
comment|/**< Extraction mask (specified bits are used) */
name|uint8_t
name|bitOffsetInFqid
decl_stmt|;
comment|/**< 0-31, Selects which bits of the 24 FQID bits to effect using                                                              the extracted byte; Assume byte is placed as the 8 MSB's in                                                              a 32 bit word where the lower bits                                                              are the FQID; i.e if bitOffsetInFqid=1 than its LSB                                                              will effect the FQID MSB, if bitOffsetInFqid=24 than the                                                              extracted byte will effect the 8 LSB's of the FQID,                                                              if bitOffsetInFqid=31 than the byte's MSB will effect                                                              the FQID's LSB; 0 means - no effect on FQID;                                                              Note that one, and only one of                                                              bitOffsetInFqid or bitOffsetInPlcrProfile must be set (i.e,                                                              extracted byte must effect either FQID or Policer profile).*/
name|uint8_t
name|bitOffsetInPlcrProfile
decl_stmt|;
comment|/**< 0-15, Selects which bits of the 8 policer profile id bits to                                                              effect using the extracted byte; Assume byte is placed                                                              as the 8 MSB's in a 16 bit word where the lower bits                                                              are the policer profile id; i.e if bitOffsetInPlcrProfile=1                                                              than its LSB will effect the profile MSB, if bitOffsetInFqid=8                                                              than the extracted byte will effect the whole policer profile id,                                                              if bitOffsetInFqid=15 than the byte's MSB will effect                                                              the Policer Profile id's LSB;                                                              0 means - no effect on policer profile; Note that one, and only one of                                                              bitOffsetInFqid or bitOffsetInPlcrProfile must be set (i.e,                                                              extracted byte must effect either FQID or Policer profile).*/
block|}
name|t_FmPcdKgExtractedOrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring a scheme counter */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgSchemeCounter
block|{
name|bool
name|update
decl_stmt|;
comment|/**< FALSE to keep the current counter state                                  and continue from that point, TRUE to update/reset                                  the counter when the scheme is written. */
name|uint32_t
name|value
decl_stmt|;
comment|/**< If update=TRUE, this value will be written into the                                  counter. clear this field to reset the counter. */
block|}
name|t_FmPcdKgSchemeCounter
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring a policer profile for a KeyGen scheme                 (when policer is the next engine after this scheme). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgPlcrProfile
block|{
name|bool
name|sharedProfile
decl_stmt|;
comment|/**< TRUE if this profile is shared between ports                                                          (managed by master partition); Must not be TRUE                                                          if profile is after Coarse Classification*/
name|bool
name|direct
decl_stmt|;
comment|/**< if TRUE, directRelativeProfileId only selects the profile                                                          id, if FALSE fqidOffsetRelativeProfileIdBase is used                                                          together with fqidOffsetShift and numOfProfiles                                                          parameters, to define a range of profiles from                                                          which the KeyGen result will determine the                                                          destination policer profile.  */
union|union
block|{
name|uint16_t
name|directRelativeProfileId
decl_stmt|;
comment|/**< Used if 'direct' is TRUE, to select policer profile.                                                          should indicate the policer profile offset within the                                                          port's policer profiles or shared window. */
struct|struct
block|{
name|uint8_t
name|fqidOffsetShift
decl_stmt|;
comment|/**< Shift on the KeyGen create FQID offset (i.e. not the                                                          final FQID - without the FQID base). */
name|uint8_t
name|fqidOffsetRelativeProfileIdBase
decl_stmt|;
comment|/**< The base of the FMan Port's relative Storage-Profile ID;                                                          this value will be "OR'ed" with the KeyGen create FQID                                                          offset (i.e. not the final FQID - without the FQID base);                                                          the final result should indicate the Storage-Profile offset                                                          within the FMan Port's relative Storage-Profiles window/                                                          (or the SHARED window depends on 'sharedProfile'). */
name|uint8_t
name|numOfProfiles
decl_stmt|;
comment|/**< Range of profiles starting at base */
block|}
name|indirectProfile
struct|;
comment|/**< Indirect profile parameters */
block|}
name|profileSelect
union|;
comment|/**< Direct/indirect profile selection and parameters */
block|}
name|t_FmPcdKgPlcrProfile
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring a storage profile for a KeyGen scheme. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgStorageProfile
block|{
name|bool
name|direct
decl_stmt|;
comment|/**< If TRUE, directRelativeProfileId only selects the                                                          profile id;                                                          If FALSE, fqidOffsetRelativeProfileIdBase is used                                                          together with fqidOffsetShift and numOfProfiles                                                          parameters to define a range of profiles from which                                                          the KeyGen result will determine the destination                                                          storage profile. */
union|union
block|{
name|uint16_t
name|directRelativeProfileId
decl_stmt|;
comment|/**< Used when 'direct' is TRUE, to select a storage profile;                                                          should indicate the storage profile offset within the                                                          port's storage profiles window. */
struct|struct
block|{
name|uint8_t
name|fqidOffsetShift
decl_stmt|;
comment|/**< Shift on the KeyGen create FQID offset (i.e. not the                                                          final FQID - without the FQID base). */
name|uint8_t
name|fqidOffsetRelativeProfileIdBase
decl_stmt|;
comment|/**< The base of the FMan Port's relative Storage-Profile ID;                                                          this value will be "OR'ed" with the KeyGen create FQID                                                          offset (i.e. not the final FQID - without the FQID base);                                                          the final result should indicate the Storage-Profile offset                                                          within the FMan Port's relative Storage-Profiles window. */
name|uint8_t
name|numOfProfiles
decl_stmt|;
comment|/**< Range of profiles starting at base. */
block|}
name|indirectProfile
struct|;
comment|/**< Indirect profile parameters. */
block|}
name|profileSelect
union|;
comment|/**< Direct/indirect profile selection and parameters. */
block|}
name|t_FmPcdKgStorageProfile
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining CC as the next engine after KeyGen */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgCc
block|{
name|t_Handle
name|h_CcTree
decl_stmt|;
comment|/**< A handle to a CC Tree */
name|uint8_t
name|grpId
decl_stmt|;
comment|/**< CC group id within the CC tree */
name|bool
name|plcrNext
decl_stmt|;
comment|/**< TRUE if after CC, in case of data frame,                                                                  policing is required. */
name|bool
name|bypassPlcrProfileGeneration
decl_stmt|;
comment|/**< TRUE to bypass KeyGen policer profile generation;                                                                  selected profile is the one set at port initialization. */
name|t_FmPcdKgPlcrProfile
name|plcrProfile
decl_stmt|;
comment|/**< Valid only if plcrNext = TRUE and                                                                  bypassPlcrProfileGeneration = FALSE */
block|}
name|t_FmPcdKgCc
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining initializing a KeyGen scheme */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgSchemeParams
block|{
name|bool
name|modify
decl_stmt|;
comment|/**< TRUE to change an existing scheme */
union|union
block|{
name|uint8_t
name|relativeSchemeId
decl_stmt|;
comment|/**< if modify=FALSE:Partition relative scheme id */
name|t_Handle
name|h_Scheme
decl_stmt|;
comment|/**< if modify=TRUE: a handle of the existing scheme */
block|}
name|id
union|;
name|bool
name|alwaysDirect
decl_stmt|;
comment|/**< This scheme is reached only directly, i.e. no need                                                                      for match vector; KeyGen will ignore it when matching */
struct|struct
block|{
comment|/**< HL Relevant only if alwaysDirect = FALSE */
name|t_Handle
name|h_NetEnv
decl_stmt|;
comment|/**< A handle to the Network environment as returned                                                                      by FM_PCD_NetEnvCharacteristicsSet() */
name|uint8_t
name|numOfDistinctionUnits
decl_stmt|;
comment|/**< Number of NetEnv units listed in unitIds array */
name|uint8_t
name|unitIds
index|[
name|FM_PCD_MAX_NUM_OF_DISTINCTION_UNITS
index|]
decl_stmt|;
comment|/**< Indexes as passed to SetNetEnvCharacteristics array*/
block|}
name|netEnvParams
struct|;
name|bool
name|useHash
decl_stmt|;
comment|/**< use the KeyGen Hash functionality  */
name|t_FmPcdKgKeyExtractAndHashParams
name|keyExtractAndHashParams
decl_stmt|;
comment|/**< used only if useHash = TRUE */
name|bool
name|bypassFqidGeneration
decl_stmt|;
comment|/**< Normally - FALSE, TRUE to avoid FQID update in the IC;                                                                      In such a case FQID after KeyGen will be the default FQID                                                                      defined for the relevant port, or the FQID defined by CC                                                                      in cases where CC was the previous engine. */
name|uint32_t
name|baseFqid
decl_stmt|;
comment|/**< Base FQID; Relevant only if bypassFqidGeneration = FALSE;                                                                      If hash is used and an even distribution is expected                                                                      according to hashDistributionNumOfFqids, baseFqid must be aligned to                                                                      hashDistributionNumOfFqids. */
name|uint8_t
name|numOfUsedExtractedOrs
decl_stmt|;
comment|/**< Number of FQID masks listed in extractedOrs array */
name|t_FmPcdKgExtractedOrParams
name|extractedOrs
index|[
name|FM_PCD_KG_NUM_OF_GENERIC_REGS
index|]
decl_stmt|;
comment|/**< FM_PCD_KG_NUM_OF_GENERIC_REGS                                                                      registers are shared between qidMasks                                                                      functionality and some of the extraction                                                                      actions; Normally only some will be used                                                                      for qidMask. Driver will return error if                                                                      resource is full at initialization time. */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|bool
name|overrideStorageProfile
decl_stmt|;
comment|/**< TRUE if KeyGen override previously decided storage profile */
name|t_FmPcdKgStorageProfile
name|storageProfile
decl_stmt|;
comment|/**< Used when overrideStorageProfile TRUE */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|e_FmPcdEngine
name|nextEngine
decl_stmt|;
comment|/**< may be BMI, PLCR or CC */
union|union
block|{
comment|/**< depends on nextEngine */
name|e_FmPcdDoneAction
name|doneAction
decl_stmt|;
comment|/**< Used when next engine is BMI (done) */
name|t_FmPcdKgPlcrProfile
name|plcrProfile
decl_stmt|;
comment|/**< Used when next engine is PLCR */
name|t_FmPcdKgCc
name|cc
decl_stmt|;
comment|/**< Used when next engine is CC */
block|}
name|kgNextEngineParams
union|;
name|t_FmPcdKgSchemeCounter
name|schemeCounter
decl_stmt|;
comment|/**< A structure of parameters for updating                                                                      the scheme counter */
block|}
name|t_FmPcdKgSchemeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Definitions for CC statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

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
name|FM_PCD_CC_STATS_MAX_NUM_OF_FLR
value|10
end_define

begin_comment
comment|/* Maximal supported number of frame length ranges */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_CC_STATS_FLR_SIZE
value|2
end_define

begin_comment
comment|/* Size in bytes of a frame length range limit */
end_comment

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
name|FM_PCD_CC_STATS_COUNTER_SIZE
value|4
end_define

begin_comment
comment|/* Size in bytes of a frame length range counter */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining CC as the next engine after a CC node. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNextCcParams
block|{
name|t_Handle
name|h_CcNode
decl_stmt|;
comment|/**< A handle of the next CC node */
block|}
name|t_FmPcdCcNextCcParams
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining Frame replicator as the next engine after a CC node. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNextFrParams
block|{
name|t_Handle
name|h_FrmReplic
decl_stmt|;
comment|/**< A handle of the next frame replicator group */
block|}
name|t_FmPcdCcNextFrParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining Policer as the next engine after a CC node. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNextPlcrParams
block|{
name|bool
name|overrideParams
decl_stmt|;
comment|/**< TRUE if CC override previously decided parameters*/
name|bool
name|sharedProfile
decl_stmt|;
comment|/**< Relevant only if overrideParams=TRUE:                                              TRUE if this profile is shared between ports */
name|uint16_t
name|newRelativeProfileId
decl_stmt|;
comment|/**< Relevant only if overrideParams=TRUE:                                              (otherwise profile id is taken from KeyGen);                                              This parameter should indicate the policer                                              profile offset within the port's                                              policer profiles or from SHARED window.*/
name|uint32_t
name|newFqid
decl_stmt|;
comment|/**< Relevant only if overrideParams=TRUE:                                              FQID for enqueuing the frame;                                              In earlier chips  if policer next engine is KEYGEN,                                              this parameter can be 0, because the KEYGEN                                              always decides the enqueue FQID.*/
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint8_t
name|newRelativeStorageProfileId
decl_stmt|;
comment|/**< Indicates the relative storage profile offset within                                              the port's storage profiles window;                                              Relevant only if the port was configured with VSP. */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|t_FmPcdCcNextPlcrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining enqueue as the next action after a CC node. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNextEnqueueParams
block|{
name|e_FmPcdDoneAction
name|action
decl_stmt|;
comment|/**< Action - when next engine is BMI (done) */
name|bool
name|overrideFqid
decl_stmt|;
comment|/**< TRUE if CC override previously decided fqid and vspid,                                              relevant if action = e_FM_PCD_ENQ_FRAME */
name|uint32_t
name|newFqid
decl_stmt|;
comment|/**< Valid if overrideFqid=TRUE, FQID for enqueuing the frame                                              (otherwise FQID is taken from KeyGen),                                              relevant if action = e_FM_PCD_ENQ_FRAME */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint8_t
name|newRelativeStorageProfileId
decl_stmt|;
comment|/**< Valid if overrideFqid=TRUE, Indicates the relative virtual                                              storage profile offset within the port's storage profiles                                              window; Relevant only if the port was configured with VSP. */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|t_FmPcdCcNextEnqueueParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining KeyGen as the next engine after a CC node. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNextKgParams
block|{
name|bool
name|overrideFqid
decl_stmt|;
comment|/**< TRUE if CC override previously decided fqid and vspid,                                              Note - this parameters irrelevant for earlier chips */
name|uint32_t
name|newFqid
decl_stmt|;
comment|/**< Valid if overrideFqid=TRUE, FQID for enqueuing the frame                                              (otherwise FQID is taken from KeyGen),                                              Note - this parameters irrelevant for earlier chips */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint8_t
name|newRelativeStorageProfileId
decl_stmt|;
comment|/**< Valid if overrideFqid=TRUE, Indicates the relative virtual                                              storage profile offset within the port's storage profiles                                              window; Relevant only if the port was configured with VSP. */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|t_Handle
name|h_DirectScheme
decl_stmt|;
comment|/**< Direct scheme handle to go to. */
block|}
name|t_FmPcdCcNextKgParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining the next engine after a CC node. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNextEngineParams
block|{
name|e_FmPcdEngine
name|nextEngine
decl_stmt|;
comment|/**< User has to initialize parameters                                                              according to nextEngine definition */
union|union
block|{
name|t_FmPcdCcNextCcParams
name|ccParams
decl_stmt|;
comment|/**< Parameters in case next engine is CC */
name|t_FmPcdCcNextPlcrParams
name|plcrParams
decl_stmt|;
comment|/**< Parameters in case next engine is PLCR */
name|t_FmPcdCcNextEnqueueParams
name|enqueueParams
decl_stmt|;
comment|/**< Parameters in case next engine is BMI */
name|t_FmPcdCcNextKgParams
name|kgParams
decl_stmt|;
comment|/**< Parameters in case next engine is KG */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdCcNextFrParams
name|frParams
decl_stmt|;
comment|/**< Parameters in case next engine is FR */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|params
union|;
comment|/**< union used for all the next-engine parameters options */
name|t_Handle
name|h_Manip
decl_stmt|;
comment|/**< Handle to Manipulation object.                                                              Relevant if next engine is of type result                                                              (e_FM_PCD_PLCR, e_FM_PCD_KG, e_FM_PCD_DONE) */
name|bool
name|statisticsEn
decl_stmt|;
comment|/**< If TRUE, statistics counters are incremented                                                              for each frame passing through this                                                              Coarse Classification entry. */
block|}
name|t_FmPcdCcNextEngineParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a single CC key */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcKeyParams
block|{
name|uint8_t
modifier|*
name|p_Key
decl_stmt|;
comment|/**< Relevant only if 'action' = e_FM_PCD_ACTION_EXACT_MATCH;                                                  pointer to the key of the size defined in keySize */
name|uint8_t
modifier|*
name|p_Mask
decl_stmt|;
comment|/**< Relevant only if 'action' = e_FM_PCD_ACTION_EXACT_MATCH;                                                  pointer to the Mask per key  of the size defined                                                  in keySize. p_Key and p_Mask (if defined) has to be                                                  of the same size defined in the keySize;                                                  NOTE that if this value is equal for all entries whithin                                                  this table, the driver will automatically use global-mask                                                  (i.e. one common mask for all entries) instead of private                                                  one; that is done in order to spare some memory and for                                                  better performance. */
name|t_FmPcdCcNextEngineParams
name|ccNextEngineParams
decl_stmt|;
comment|/**< parameters for the next for the defined Key in                                                  the p_Key */
block|}
name|t_FmPcdCcKeyParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining CC keys parameters                 The driver supports two methods for CC node allocation: dynamic and static.                 Static mode was created in order to prevent runtime alloc/free                 of FMan memory (MURAM), which may cause fragmentation; in this mode,                 the driver automatically allocates the memory according to                 'maxNumOfKeys' parameter. The driver calculates the maximal memory                 size that may be used for this CC-Node taking into consideration                 'maskSupport' and 'statisticsMode' parameters.                 When 'action' = e_FM_PCD_ACTION_INDEXED_LOOKUP in the extraction                 parameters of this node, 'maxNumOfKeys' must be equal to 'numOfKeys'.                 In dynamic mode, 'maxNumOfKeys' must be zero. At initialization,                 all required structures are allocated according to 'numOfKeys'                 parameter. During runtime modification, these structures are                 re-allocated according to the updated number of keys.                  Please note that 'action' and 'icIndxMask' mentioned in the                 specific parameter explanations are passed in the extraction                 parameters of the node (fields of extractCcParams.extractNonHdr). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_KeysParams
block|{
name|uint16_t
name|maxNumOfKeys
decl_stmt|;
comment|/**< Maximum number of keys that will (ever) be used in this CC-Node;                                                      A value of zero may be used for dynamic memory allocation. */
name|bool
name|maskSupport
decl_stmt|;
comment|/**< This parameter is relevant only if a node is initialized with                                                      'action' = e_FM_PCD_ACTION_EXACT_MATCH and maxNumOfKeys> 0;                                                      Should be TRUE to reserve table memory for key masks, even if                                                      initial keys do not contain masks, or if the node was initialized                                                      as 'empty' (without keys); this will allow user to add keys with                                                      masks at runtime.                                                      NOTE that if user want to use only global-masks (i.e. one common mask                                                      for all the entries within this table, this parameter should set to 'FALSE'. */
name|e_FmPcdCcStatsMode
name|statisticsMode
decl_stmt|;
comment|/**< Determines the supported statistics mode for all node's keys.                                                      To enable statistics gathering, statistics should be enabled per                                                      every key, using 'statisticsEn' in next engine parameters structure                                                      of that key;                                                      If 'maxNumOfKeys' is set, all required structures will be                                                      preallocated for all keys. */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint16_t
name|frameLengthRanges
index|[
name|FM_PCD_CC_STATS_MAX_NUM_OF_FLR
index|]
decl_stmt|;
comment|/**< Relevant only for 'RMON' statistics mode                                                      (this feature is supported only on B4860 device);                                                      Holds a list of programmable thresholds - for each received frame,                                                      its length in bytes is examined against these range thresholds and                                                      the appropriate counter is incremented by 1 - for example, to belong                                                      to range i, the following should hold:                                                      range i-1 threshold< frame length<= range i threshold                                                      Each range threshold must be larger then its preceding range                                                      threshold, and last range threshold must be 0xFFFF. */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|uint16_t
name|numOfKeys
decl_stmt|;
comment|/**< Number of initial keys;                                                      Note that in case of 'action' = e_FM_PCD_ACTION_INDEXED_LOOKUP,                                                      this field should be power-of-2 of the number of bits that are                                                      set in 'icIndxMask'. */
name|uint8_t
name|keySize
decl_stmt|;
comment|/**< Size of key - for extraction of type FULL_FIELD, 'keySize' has                                                      to be the standard size of the selected key; For other extraction                                                      types, 'keySize' has to be as size of extraction; When 'action' =                                                      e_FM_PCD_ACTION_INDEXED_LOOKUP, 'keySize' must be 2. */
name|t_FmPcdCcKeyParams
name|keyParams
index|[
name|FM_PCD_MAX_NUM_OF_KEYS
index|]
decl_stmt|;
comment|/**< An array with 'numOfKeys' entries, each entry specifies the                                                      corresponding key parameters;                                                      When 'action' = e_FM_PCD_ACTION_EXACT_MATCH, this value must not                                                      exceed 255 (FM_PCD_MAX_NUM_OF_KEYS-1) as the last entry is saved                                                      for the 'miss' entry. */
name|t_FmPcdCcNextEngineParams
name|ccNextEngineParamsForMiss
decl_stmt|;
comment|/**< Parameters for defining the next engine when a key is not matched;                                                      Not relevant if action = e_FM_PCD_ACTION_INDEXED_LOOKUP. */
block|}
name|t_KeysParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a CC node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcNodeParams
block|{
name|t_FmPcdExtractEntry
name|extractCcParams
decl_stmt|;
comment|/**< Extraction parameters */
name|t_KeysParams
name|keysParams
decl_stmt|;
comment|/**< Keys definition matching the selected extraction */
block|}
name|t_FmPcdCcNodeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a hash table */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdHashTableParams
block|{
name|uint16_t
name|maxNumOfKeys
decl_stmt|;
comment|/**< Maximum Number Of Keys that will (ever) be used in this Hash-table */
name|e_FmPcdCcStatsMode
name|statisticsMode
decl_stmt|;
comment|/**< If not e_FM_PCD_CC_STATS_MODE_NONE, the required structures for the                                                                  requested statistics mode will be allocated according to maxNumOfKeys. */
name|uint8_t
name|kgHashShift
decl_stmt|;
comment|/**< KG-Hash-shift as it was configured in the KG-scheme                                                                  that leads to this hash-table. */
name|uint16_t
name|hashResMask
decl_stmt|;
comment|/**< Mask that will be used on the hash-result;                                                                  The number-of-sets for this hash will be calculated                                                                  as (2^(number of bits set in 'hashResMask'));                                                                  The 4 lower bits must be cleared. */
name|uint8_t
name|hashShift
decl_stmt|;
comment|/**< Byte offset from the beginning of the KeyGen hash result to the                                                                  2-bytes to be used as hash index. */
name|uint8_t
name|matchKeySize
decl_stmt|;
comment|/**< Size of the exact match keys held by the hash buckets */
name|t_FmPcdCcNextEngineParams
name|ccNextEngineParamsForMiss
decl_stmt|;
comment|/**< Parameters for defining the next engine when a key is not matched */
block|}
name|t_FmPcdHashTableParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a CC tree group.                  This structure defines a CC group in terms of NetEnv units                 and the action to be taken in each case. The unitIds list must                 be given in order from low to high indices.                  t_FmPcdCcNextEngineParams is a list of 2^numOfDistinctionUnits                 structures where each defines the next action to be taken for                 each units combination. for example:                 numOfDistinctionUnits = 2                 unitIds = {1,3}                 p_NextEnginePerEntriesInGrp[0] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - not found; unit 3 - not found;                 p_NextEnginePerEntriesInGrp[1] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - not found; unit 3 - found;                 p_NextEnginePerEntriesInGrp[2] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - found; unit 3 - not found;                 p_NextEnginePerEntriesInGrp[3] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - found; unit 3 - found; */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcGrpParams
block|{
name|uint8_t
name|numOfDistinctionUnits
decl_stmt|;
comment|/**< Up to 4 */
name|uint8_t
name|unitIds
index|[
name|FM_PCD_MAX_NUM_OF_CC_UNITS
index|]
decl_stmt|;
comment|/**< Indices of the units as defined in                                                                      FM_PCD_NetEnvCharacteristicsSet() */
name|t_FmPcdCcNextEngineParams
name|nextEnginePerEntriesInGrp
index|[
name|FM_PCD_MAX_NUM_OF_CC_ENTRIES_IN_GRP
index|]
decl_stmt|;
comment|/**< Maximum entries per group is 16 */
block|}
name|t_FmPcdCcGrpParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining CC tree groups */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcTreeParams
block|{
name|t_Handle
name|h_NetEnv
decl_stmt|;
comment|/**< A handle to the Network environment as returned                                                              by FM_PCD_NetEnvCharacteristicsSet() */
name|uint8_t
name|numOfGrps
decl_stmt|;
comment|/**< Number of CC groups within the CC tree */
name|t_FmPcdCcGrpParams
name|ccGrpParams
index|[
name|FM_PCD_MAX_NUM_OF_CC_GROUPS
index|]
decl_stmt|;
comment|/**< Parameters for each group. */
block|}
name|t_FmPcdCcTreeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   CC key statistics structure */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcKeyStatistics
block|{
name|uint32_t
name|byteCount
decl_stmt|;
comment|/**< This counter reflects byte count of frames that                                      were matched by this key. */
name|uint32_t
name|frameCount
decl_stmt|;
comment|/**< This counter reflects count of frames that                                      were matched by this key. */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint32_t
name|frameLengthRangeCount
index|[
name|FM_PCD_CC_STATS_MAX_NUM_OF_FLR
index|]
decl_stmt|;
comment|/**< These counters reflect how many frames matched                                      this key in 'RMON' statistics mode:                                      Each counter holds the number of frames of a                                      specific frames length range, according to the                                      ranges provided at initialization. */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|t_FmPcdCcKeyStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining policer byte rate */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPlcrByteRateModeParams
block|{
name|e_FmPcdPlcrFrameLengthSelect
name|frameLengthSelection
decl_stmt|;
comment|/**< Frame length selection */
name|e_FmPcdPlcrRollBackFrameSelect
name|rollBackFrameSelection
decl_stmt|;
comment|/**< relevant option only e_FM_PCD_PLCR_L2_FRM_LEN,                                                                  e_FM_PCD_PLCR_FULL_FRM_LEN */
block|}
name|t_FmPcdPlcrByteRateModeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining the policer profile (based on                 RFC-2698 or RFC-4115 attributes). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPlcrNonPassthroughAlgParams
block|{
name|e_FmPcdPlcrRateMode
name|rateMode
decl_stmt|;
comment|/**< Byte mode or Packet mode */
name|t_FmPcdPlcrByteRateModeParams
name|byteModeParams
decl_stmt|;
comment|/**< Valid for Byte NULL for Packet */
name|uint32_t
name|committedInfoRate
decl_stmt|;
comment|/**< KBits/Second or Packets/Second */
name|uint32_t
name|committedBurstSize
decl_stmt|;
comment|/**< Bytes/Packets */
name|uint32_t
name|peakOrExcessInfoRate
decl_stmt|;
comment|/**< KBits/Second or Packets/Second */
name|uint32_t
name|peakOrExcessBurstSize
decl_stmt|;
comment|/**< Bytes/Packets */
block|}
name|t_FmPcdPlcrNonPassthroughAlgParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining the next engine after policer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|u_FmPcdPlcrNextEngineParams
block|{
name|e_FmPcdDoneAction
name|action
decl_stmt|;
comment|/**< Action - when next engine is BMI (done) */
name|t_Handle
name|h_Profile
decl_stmt|;
comment|/**< Policer profile handle -  used when next engine                                                              is Policer, must be a SHARED profile */
name|t_Handle
name|h_DirectScheme
decl_stmt|;
comment|/**< Direct scheme select - when next engine is KeyGen */
block|}
name|u_FmPcdPlcrNextEngineParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining the policer profile entry */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdPlcrProfileParams
block|{
name|bool
name|modify
decl_stmt|;
comment|/**< TRUE to change an existing profile */
union|union
block|{
struct|struct
block|{
name|e_FmPcdProfileTypeSelection
name|profileType
decl_stmt|;
comment|/**< Type of policer profile */
name|t_Handle
name|h_FmPort
decl_stmt|;
comment|/**< Relevant for per-port profiles only */
name|uint16_t
name|relativeProfileId
decl_stmt|;
comment|/**< Profile id - relative to shared group or to port */
block|}
name|newParams
struct|;
comment|/**< use it when modify = FALSE */
name|t_Handle
name|h_Profile
decl_stmt|;
comment|/**< A handle to a profile - use it when modify=TRUE */
block|}
name|id
union|;
name|e_FmPcdPlcrAlgorithmSelection
name|algSelection
decl_stmt|;
comment|/**< Profile Algorithm PASS_THROUGH, RFC_2698, RFC_4115 */
name|e_FmPcdPlcrColorMode
name|colorMode
decl_stmt|;
comment|/**< COLOR_BLIND, COLOR_AWARE */
union|union
block|{
name|e_FmPcdPlcrColor
name|dfltColor
decl_stmt|;
comment|/**< For Color-Blind Pass-Through mode; the policer will re-color                                                                          any incoming packet with the default value. */
name|e_FmPcdPlcrColor
name|override
decl_stmt|;
comment|/**< For Color-Aware modes; the profile response to a                                                                          pre-color value of 2'b11. */
block|}
name|color
union|;
name|t_FmPcdPlcrNonPassthroughAlgParams
name|nonPassthroughAlgParams
decl_stmt|;
comment|/**< RFC2698 or RFC4115 parameters */
name|e_FmPcdEngine
name|nextEngineOnGreen
decl_stmt|;
comment|/**< Next engine for green-colored frames */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnGreen
decl_stmt|;
comment|/**< Next engine parameters for green-colored frames  */
name|e_FmPcdEngine
name|nextEngineOnYellow
decl_stmt|;
comment|/**< Next engine for yellow-colored frames */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnYellow
decl_stmt|;
comment|/**< Next engine parameters for yellow-colored frames  */
name|e_FmPcdEngine
name|nextEngineOnRed
decl_stmt|;
comment|/**< Next engine for red-colored frames */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnRed
decl_stmt|;
comment|/**< Next engine parameters for red-colored frames  */
name|bool
name|trapProfileOnFlowA
decl_stmt|;
comment|/**< Obsolete - do not use */
name|bool
name|trapProfileOnFlowB
decl_stmt|;
comment|/**< Obsolete - do not use */
name|bool
name|trapProfileOnFlowC
decl_stmt|;
comment|/**< Obsolete - do not use */
block|}
name|t_FmPcdPlcrProfileParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for selecting a location for requested manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmManipHdrInfo
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
name|e_FmPcdHdrIndex
name|hdrIndex
decl_stmt|;
comment|/**< Relevant only for MPLS, VLAN and tunneled IP. Otherwise should be cleared. */
name|bool
name|byField
decl_stmt|;
comment|/**< TRUE if the location of manipulation is according to some field in the specific header*/
name|t_FmPcdFields
name|fullField
decl_stmt|;
comment|/**< Relevant only when byField = TRUE: Extract field */
block|}
name|t_FmManipHdrInfo
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining an insertion manipulation                 of type e_FM_PCD_MANIP_INSRT_TO_START_OF_FRAME_TEMPLATE */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrtByTemplateParams
block|{
name|uint8_t
name|size
decl_stmt|;
comment|/**< Size of insert template to the start of the frame. */
name|uint8_t
name|hdrTemplate
index|[
name|FM_PCD_MAX_MANIP_INSRT_TEMPLATE_SIZE
index|]
decl_stmt|;
comment|/**< Array of the insertion template. */
name|bool
name|modifyOuterIp
decl_stmt|;
comment|/**< TRUE if user want to modify some fields in outer IP. */
struct|struct
block|{
name|uint16_t
name|ipOuterOffset
decl_stmt|;
comment|/**< Offset of outer IP in the insert template, relevant if modifyOuterIp = TRUE.*/
name|uint16_t
name|dscpEcn
decl_stmt|;
comment|/**< value of dscpEcn in IP outer, relevant if modifyOuterIp = TRUE.                                                              in IPV4 dscpEcn only byte - it has to be adjusted to the right*/
name|bool
name|udpPresent
decl_stmt|;
comment|/**< TRUE if UDP is present in the insert template, relevant if modifyOuterIp = TRUE.*/
name|uint8_t
name|udpOffset
decl_stmt|;
comment|/**< Offset in the insert template of UDP, relevant if modifyOuterIp = TRUE and udpPresent=TRUE.*/
name|uint8_t
name|ipIdentGenId
decl_stmt|;
comment|/**< Used by FMan-CTRL to calculate IP-identification field,relevant if modifyOuterIp = TRUE.*/
name|bool
name|recalculateLength
decl_stmt|;
comment|/**< TRUE if recalculate length has to be performed due to the engines in the path which can change the frame later, relevant if modifyOuterIp = TRUE.*/
struct|struct
block|{
name|uint8_t
name|blockSize
decl_stmt|;
comment|/**< The CAAM block-size; Used by FMan-CTRL to calculate the IP Total Length field.*/
name|uint8_t
name|extraBytesAddedAlignedToBlockSize
decl_stmt|;
comment|/**< Used by FMan-CTRL to calculate the IP Total Length field and UDP length*/
name|uint8_t
name|extraBytesAddedNotAlignedToBlockSize
decl_stmt|;
comment|/**< Used by FMan-CTRL to calculate the IP Total Length field and UDP length.*/
block|}
name|recalculateLengthParams
struct|;
comment|/**< Recalculate length parameters - relevant if modifyOuterIp = TRUE and recalculateLength = TRUE */
block|}
name|modifyOuterIpParams
struct|;
comment|/**< Outer IP modification parameters - ignored if modifyOuterIp is FALSE */
name|bool
name|modifyOuterVlan
decl_stmt|;
comment|/**< TRUE if user wants to modify VPri field in the outer VLAN header*/
struct|struct
block|{
name|uint8_t
name|vpri
decl_stmt|;
comment|/**< Value of VPri, relevant if modifyOuterVlan = TRUE                                                              VPri only 3 bits, it has to be adjusted to the right*/
block|}
name|modifyOuterVlanParams
struct|;
block|}
name|t_FmPcdManipHdrInsrtByTemplateParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining CAPWAP fragmentation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_CapwapFragmentationParams
block|{
name|uint16_t
name|sizeForFragmentation
decl_stmt|;
comment|/**< if length of the frame is greater than this value, CAPWAP fragmentation will be executed.*/
name|bool
name|headerOptionsCompr
decl_stmt|;
comment|/**< TRUE - first fragment include the CAPWAP header options field,                                                              and all other fragments exclude the CAPWAP options field,                                                              FALSE - all fragments include CAPWAP header options field. */
block|}
name|t_CapwapFragmentationParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining CAPWAP reassembly */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_CapwapReassemblyParams
block|{
name|uint16_t
name|maxNumFramesInProcess
decl_stmt|;
comment|/**< Number of frames which can be reassembled concurrently; must be power of 2.                                                                  In case numOfFramesPerHashEntry == e_FM_PCD_MANIP_FOUR_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 4 - 512,                                                                  In case numOfFramesPerHashEntry == e_FM_PCD_MANIP_EIGHT_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 8 - 2048 */
name|bool
name|haltOnDuplicationFrag
decl_stmt|;
comment|/**< If TRUE, reassembly process will be halted due to duplicated fragment,                                                                  and all processed fragments will be enqueued with error indication;                                                                  If FALSE, only duplicated fragments will be enqueued with error indication. */
name|e_FmPcdManipReassemTimeOutMode
name|timeOutMode
decl_stmt|;
comment|/**< Expiration delay initialized by the reassembly process */
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
comment|/**< FQID in which time out frames will enqueue during Time Out Process  */
name|uint32_t
name|timeoutRoutineRequestTime
decl_stmt|;
comment|/**< Represents the time interval in microseconds between consecutive                                                                  timeout routine requests It has to be power of 2. */
name|uint32_t
name|timeoutThresholdForReassmProcess
decl_stmt|;
comment|/**< Time interval (microseconds) for marking frames in process as too old;                                                                  Frames in process are those for which at least one fragment was received                                                                  but not all fragments. */
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
decl_stmt|;
comment|/**< Number of frames per hash entry (needed for the reassembly process) */
block|}
name|t_CapwapReassemblyParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining fragmentation/reassembly manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragOrReasmParams
block|{
name|bool
name|frag
decl_stmt|;
comment|/**< TRUE if using the structure for fragmentation,                                                                  otherwise this structure is used for reassembly */
name|uint8_t
name|sgBpid
decl_stmt|;
comment|/**< Scatter/Gather buffer pool id;                                                                  Same LIODN number is used for these buffers as for                                                                  the received frames buffers, so buffers of this pool                                                                  need to be allocated in the same memory area as the                                                                  received buffers. If the received buffers arrive                                                                  from different sources, the Scatter/Gather BP id                                                                  should be mutual to all these sources. */
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
union|union
block|{
name|t_CapwapFragmentationParams
name|capwapFragParams
decl_stmt|;
comment|/**< Structure for CAPWAP fragmentation,                                                                  relevant if 'frag' = TRUE, 'hdr' = HEADER_TYPE_CAPWAP */
name|t_CapwapReassemblyParams
name|capwapReasmParams
decl_stmt|;
comment|/**< Structure for CAPWAP reassembly,                                                                  relevant if 'frag' = FALSE, 'hdr' = HEADER_TYPE_CAPWAP */
block|}
name|u
union|;
block|}
name|t_FmPcdManipFragOrReasmParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header removal by header type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrRmvByHdrParams
block|{
name|e_FmPcdManipHdrRmvByHdrType
name|type
decl_stmt|;
comment|/**< Selection of header removal location */
union|union
block|{
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
struct|struct
block|{
name|bool
name|include
decl_stmt|;
comment|/**< If FALSE, remove until the specified header (not including the header);                                                              If TRUE, remove also the specified header. */
name|t_FmManipHdrInfo
name|hdrInfo
decl_stmt|;
block|}
name|fromStartByHdr
struct|;
comment|/**< Relevant when type = e_FM_PCD_MANIP_RMV_BY_HDR_FROM_START */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) || ... */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmManipHdrInfo
name|hdrInfo
decl_stmt|;
comment|/**< Relevant when type = e_FM_PCD_MANIP_RMV_BY_HDR_FROM_START */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|e_FmPcdManipHdrRmvSpecificL2
name|specificL2
decl_stmt|;
comment|/**< Relevant when type = e_FM_PCD_MANIP_BY_HDR_SPECIFIC_L2;                                                              Defines which L2 headers to remove. */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrRmvByHdrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring IP fragmentation manipulation   Restrictions:      - IP Fragmentation output fragments must not be forwarded to application directly.      - Maximum number of fragments per frame is 16.      - Fragmentation of IP fragments is not supported.      - IPv4 packets containing header Option fields are fragmented by copying all option        fields to each fragment, regardless of the copy bit value.      - Transmit confirmation is not supported.      - Fragmentation after SEC can't handle S/G frames.      - Fragmentation nodes must be set as the last PCD action (i.e. the        corresponding CC node key must have next engine set to e_FM_PCD_DONE).      - Only BMan buffers shall be used for frames to be fragmented.      - IPF does not support VSP. Therefore, on the same port where we have IPF        we cannot support VSP.      - NOTE: The following comment is relevant only for FMAN v3 devices: IPF        does not support VSP. Therefore, on the same port where we have IPF we        cannot support VSP. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragIpParams
block|{
name|uint16_t
name|sizeForFragmentation
decl_stmt|;
comment|/**< If length of the frame is greater than this value,                                                              IP fragmentation will be executed.*/
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
name|uint8_t
name|scratchBpid
decl_stmt|;
comment|/**< Absolute buffer pool id according to BM configuration.*/
endif|#
directive|endif
comment|/* (DPAA_VERSION == 10) */
name|bool
name|sgBpidEn
decl_stmt|;
comment|/**< Enable a dedicated buffer pool id for the Scatter/Gather buffer allocation;                                                              If disabled, the Scatter/Gather buffer will be allocated from the same pool as the                                                              received frame's buffer. */
name|uint8_t
name|sgBpid
decl_stmt|;
comment|/**< Scatter/Gather buffer pool id;                                                              This parameters is relevant when 'sgBpidEn=TRUE';                                                              Same LIODN number is used for these buffers as for the received frames buffers, so buffers                                                              of this pool need to be allocated in the same memory area as the received buffers.                                                              If the received buffers arrive from different sources, the Scatter/Gather BP id should be                                                              mutual to all these sources. */
name|e_FmPcdManipDontFragAction
name|dontFragAction
decl_stmt|;
comment|/**< Don't Fragment Action - If an IP packet is larger                                                              than MTU and its DF bit is set, then this field will                                                              determine the action to be taken.*/
block|}
name|t_FmPcdManipFragIpParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring IP reassembly manipulation.                  This is a common structure for both IPv4 and IPv6 reassembly                 manipulation. For reassembly of both IPv4 and IPv6, make sure to                 set the 'hdr' field in t_FmPcdManipReassemParams to HEADER_TYPE_IPv6.   Restrictions:     - Application must define at least one scheme to catch the reassembled frames.     - Maximum number of fragments per frame is 16.     - Reassembly of IPv4 fragments containing Option fields is supported.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipReassemIpParams
block|{
name|uint8_t
name|relativeSchemeId
index|[
literal|2
index|]
decl_stmt|;
comment|/**< Partition relative scheme id:                                                                  relativeSchemeId[0] -  Relative scheme ID for IPV4 Reassembly manipulation;                                                                  relativeSchemeId[1] -  Relative scheme ID for IPV6 Reassembly manipulation;                                                                  NOTE: The following comment is relevant only for FMAN v2 devices:                                                                  Relative scheme ID for IPv4/IPv6 Reassembly manipulation must be smaller than                                                                  the user schemes id to ensure that the reassembly schemes will be first match;                                                                  Rest schemes, if defined, should have higher relative scheme ID. */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint32_t
name|nonConsistentSpFqid
decl_stmt|;
comment|/**< In case that other fragments of the frame corresponds to different storage                                                                  profile than the opening fragment (Non-Consistent-SP state)                                                                  then one of two possible scenarios occurs:                                                                  if 'nonConsistentSpFqid != 0', the reassembled frame will be enqueued to                                                                  this fqid, otherwise a 'Non Consistent SP' bit will be set in the FD[status].*/
else|#
directive|else
name|uint8_t
name|sgBpid
decl_stmt|;
comment|/**< Buffer pool id for the S/G frame created by the reassembly process */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|uint8_t
name|dataMemId
decl_stmt|;
comment|/**< Memory partition ID for the IPR's external tables structure */
name|uint16_t
name|dataLiodnOffset
decl_stmt|;
comment|/**< LIODN offset for access the IPR's external tables structure. */
name|uint16_t
name|minFragSize
index|[
literal|2
index|]
decl_stmt|;
comment|/**< Minimum fragment size:                                                                  minFragSize[0] - for ipv4, minFragSize[1] - for ipv6 */
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
index|[
literal|2
index|]
decl_stmt|;
comment|/**< Number of frames per hash entry needed for reassembly process:                                                                  numOfFramesPerHashEntry[0] - for ipv4 (max value is e_FM_PCD_MANIP_EIGHT_WAYS_HASH);                                                                  numOfFramesPerHashEntry[1] - for ipv6 (max value is e_FM_PCD_MANIP_SIX_WAYS_HASH). */
name|uint16_t
name|maxNumFramesInProcess
decl_stmt|;
comment|/**< Number of frames which can be processed by Reassembly in the same time;                                                                  Must be power of 2;                                                                  In the case numOfFramesPerHashEntry == e_FM_PCD_MANIP_FOUR_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 4 - 512;                                                                  In the case numOfFramesPerHashEntry == e_FM_PCD_MANIP_EIGHT_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 8 - 2048. */
name|e_FmPcdManipReassemTimeOutMode
name|timeOutMode
decl_stmt|;
comment|/**< Expiration delay initialized by Reassembly process */
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
comment|/**< FQID in which time out frames will enqueue during Time Out Process;                                                                  Recommended value for this field is 0; in this way timed-out frames will be discarded */
name|uint32_t
name|timeoutThresholdForReassmProcess
decl_stmt|;
comment|/**< Represents the time interval in microseconds which defines                                                                  if opened frame (at least one fragment was processed but not all the fragments)is found as too old*/
block|}
name|t_FmPcdManipReassemIpParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining IPSEC manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipSpecialOffloadIPSecParams
block|{
name|bool
name|decryption
decl_stmt|;
comment|/**< TRUE if being used in decryption direction;                                                      FALSE if being used in encryption direction. */
name|bool
name|ecnCopy
decl_stmt|;
comment|/**< TRUE to copy the ECN bits from inner/outer to outer/inner                                                      (direction depends on the 'decryption' field). */
name|bool
name|dscpCopy
decl_stmt|;
comment|/**< TRUE to copy the DSCP bits from inner/outer to outer/inner                                                      (direction depends on the 'decryption' field). */
name|bool
name|variableIpHdrLen
decl_stmt|;
comment|/**< TRUE for supporting variable IP header length in decryption. */
name|bool
name|variableIpVersion
decl_stmt|;
comment|/**< TRUE for supporting both IP version on the same SA in encryption */
name|uint8_t
name|outerIPHdrLen
decl_stmt|;
comment|/**< if 'variableIpVersion == TRUE' then this field must be set to non-zero value;                                                      It is specifies the length of the outer IP header that was configured in the                                                      corresponding SA. */
name|uint16_t
name|arwSize
decl_stmt|;
comment|/**< if<> '0' then will perform ARW check for this SA;                                                      The value must be a multiplication of 16 */
name|uintptr_t
name|arwAddr
decl_stmt|;
comment|/**< if arwSize<> '0' then this field must be set to non-zero value;                                                      MUST be allocated from FMAN's MURAM that the post-sec op-port belongs to;                                                      Must be 4B aligned. Required MURAM size is 'NEXT_POWER_OF_2(arwSize+32))/8+4' Bytes */
block|}
name|t_FmPcdManipSpecialOffloadIPSecParams
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring CAPWAP fragmentation manipulation   Restrictions:      - Maximum number of fragments per frame is 16.      - Transmit confirmation is not supported.      - Fragmentation nodes must be set as the last PCD action (i.e. the        corresponding CC node key must have next engine set to e_FM_PCD_DONE).      - Only BMan buffers shall be used for frames to be fragmented.      - NOTE: The following comment is relevant only for FMAN v3 devices: IPF        does not support VSP. Therefore, on the same port where we have IPF we        cannot support VSP. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragCapwapParams
block|{
name|uint16_t
name|sizeForFragmentation
decl_stmt|;
comment|/**< If length of the frame is greater than this value,                                                              CAPWAP fragmentation will be executed.*/
name|bool
name|sgBpidEn
decl_stmt|;
comment|/**< Enable a dedicated buffer pool id for the Scatter/Gather buffer allocation;                                                              If disabled, the Scatter/Gather buffer will be allocated from the same pool as the                                                              received frame's buffer. */
name|uint8_t
name|sgBpid
decl_stmt|;
comment|/**< Scatter/Gather buffer pool id;                                                              This parameters is relevant when 'sgBpidEn=TRUE';                                                              Same LIODN number is used for these buffers as for the received frames buffers, so buffers                                                              of this pool need to be allocated in the same memory area as the received buffers.                                                              If the received buffers arrive from different sources, the Scatter/Gather BP id should be                                                              mutual to all these sources. */
name|bool
name|compressModeEn
decl_stmt|;
comment|/**< CAPWAP Header Options Compress Enable mode;                                                              When this mode is enabled then only the first fragment include the CAPWAP header options                                                              field (if user provides it in the input frame) and all other fragments exclude the CAPWAP                                                              options field (CAPWAP header is updated accordingly).*/
block|}
name|t_FmPcdManipFragCapwapParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for configuring CAPWAP reassembly manipulation.   Restrictions:     - Application must define one scheme to catch the reassembled frames.     - Maximum number of fragments per frame is 16.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipReassemCapwapParams
block|{
name|uint8_t
name|relativeSchemeId
decl_stmt|;
comment|/**< Partition relative scheme id;                                                                  NOTE: this id must be smaller than the user schemes id to ensure that the reassembly scheme will be first match;                                                                  Rest schemes, if defined, should have higher relative scheme ID. */
name|uint8_t
name|dataMemId
decl_stmt|;
comment|/**< Memory partition ID for the IPR's external tables structure */
name|uint16_t
name|dataLiodnOffset
decl_stmt|;
comment|/**< LIODN offset for access the IPR's external tables structure. */
name|uint16_t
name|maxReassembledFrameLength
decl_stmt|;
comment|/**< The maximum CAPWAP reassembled frame length in bytes;                                                                    If maxReassembledFrameLength == 0, any successful reassembled frame length is                                                                    considered as a valid length;                                                                    if maxReassembledFrameLength> 0, a successful reassembled frame which its length                                                                    exceeds this value is considered as an error frame (FD status[CRE] bit is set). */
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
decl_stmt|;
comment|/**< Number of frames per hash entry needed for reassembly process */
name|uint16_t
name|maxNumFramesInProcess
decl_stmt|;
comment|/**< Number of frames which can be processed by reassembly in the same time;                                                                  Must be power of 2;                                                                  In the case numOfFramesPerHashEntry == e_FM_PCD_MANIP_FOUR_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 4 - 512;                                                                  In the case numOfFramesPerHashEntry == e_FM_PCD_MANIP_EIGHT_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 8 - 2048. */
name|e_FmPcdManipReassemTimeOutMode
name|timeOutMode
decl_stmt|;
comment|/**< Expiration delay initialized by Reassembly process */
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
comment|/**< FQID in which time out frames will enqueue during Time Out Process;                                                                  Recommended value for this field is 0; in this way timed-out frames will be discarded */
name|uint32_t
name|timeoutThresholdForReassmProcess
decl_stmt|;
comment|/**< Represents the time interval in microseconds which defines                                                                  if opened frame (at least one fragment was processed but not all the fragments)is found as too old*/
block|}
name|t_FmPcdManipReassemCapwapParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining CAPWAP manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipSpecialOffloadCapwapParams
block|{
name|bool
name|dtls
decl_stmt|;
comment|/**< TRUE if continue to SEC DTLS encryption */
name|e_FmPcdManipHdrQosSrc
name|qosSrc
decl_stmt|;
comment|/**< TODO */
block|}
name|t_FmPcdManipSpecialOffloadCapwapParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining special offload manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipSpecialOffloadParams
block|{
name|e_FmPcdManipSpecialOffloadType
name|type
decl_stmt|;
comment|/**< Type of special offload manipulation */
union|union
block|{
name|t_FmPcdManipSpecialOffloadIPSecParams
name|ipsec
decl_stmt|;
comment|/**< Parameters for IPSec; Relevant when                                                                  type = e_FM_PCD_MANIP_SPECIAL_OFFLOAD_IPSEC */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdManipSpecialOffloadCapwapParams
name|capwap
decl_stmt|;
comment|/**< Parameters for CAPWAP; Relevant when                                                                  type = e_FM_PCD_MANIP_SPECIAL_OFFLOAD_CAPWAP */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|u
union|;
block|}
name|t_FmPcdManipSpecialOffloadParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining insertion manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrt
block|{
name|uint8_t
name|size
decl_stmt|;
comment|/**< size of inserted section */
name|uint8_t
modifier|*
name|p_Data
decl_stmt|;
comment|/**< data to be inserted */
block|}
name|t_FmPcdManipHdrInsrt
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining generic removal manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrRmvGenericParams
block|{
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Offset from beginning of header to the start                                                          location of the removal */
name|uint8_t
name|size
decl_stmt|;
comment|/**< Size of removed section */
block|}
name|t_FmPcdManipHdrRmvGenericParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining generic insertion manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrtGenericParams
block|{
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Offset from beginning of header to the start                                                          location of the insertion */
name|uint8_t
name|size
decl_stmt|;
comment|/**< Size of inserted section */
name|bool
name|replace
decl_stmt|;
comment|/**< TRUE to override (replace) existing data at                                                          'offset', FALSE to insert */
name|uint8_t
modifier|*
name|p_Data
decl_stmt|;
comment|/**< Pointer to data to be inserted */
block|}
name|t_FmPcdManipHdrInsrtGenericParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation VLAN DSCP To Vpri translation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrFieldUpdateVlanDscpToVpri
block|{
name|uint8_t
name|dscpToVpriTable
index|[
name|FM_PCD_MANIP_DSCP_TO_VLAN_TRANS
index|]
decl_stmt|;
comment|/**< A table of VPri values for each DSCP value;                                                              The index is the DSCP value (0-0x3F) and the                                                              value is the corresponding VPRI (0-15). */
name|uint8_t
name|vpriDefVal
decl_stmt|;
comment|/**< 0-7, Relevant only if if updateType =                                                              e_FM_PCD_MANIP_HDR_FIELD_UPDATE_DSCP_TO_VLAN,                                                              this field is the Q Tag default value if the                                                              IP header is not found. */
block|}
name|t_FmPcdManipHdrFieldUpdateVlanDscpToVpri
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation VLAN fields updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrFieldUpdateVlan
block|{
name|e_FmPcdManipHdrFieldUpdateVlan
name|updateType
decl_stmt|;
comment|/**< Selects VLAN update type */
union|union
block|{
name|uint8_t
name|vpri
decl_stmt|;
comment|/**< 0-7, Relevant only if If updateType =                                                                      e_FM_PCD_MANIP_HDR_FIELD_UPDATE_VLAN_PRI, this                                                                      is the new VLAN pri. */
name|t_FmPcdManipHdrFieldUpdateVlanDscpToVpri
name|dscpToVpri
decl_stmt|;
comment|/**< Parameters structure, Relevant only if updateType                                                                      = e_FM_PCD_MANIP_HDR_FIELD_UPDATE_DSCP_TO_VLAN. */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrFieldUpdateVlan
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation IPV4 fields updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrFieldUpdateIpv4
block|{
name|ipv4HdrManipUpdateFlags_t
name|validUpdates
decl_stmt|;
comment|/**< ORed flag, selecting the required updates */
name|uint8_t
name|tos
decl_stmt|;
comment|/**< 8 bit New TOS; Relevant if validUpdates contains                                                              HDR_MANIP_IPV4_TOS */
name|uint16_t
name|id
decl_stmt|;
comment|/**< 16 bit New IP ID; Relevant only if validUpdates                                                              contains HDR_MANIP_IPV4_ID */
name|uint32_t
name|src
decl_stmt|;
comment|/**< 32 bit New IP SRC; Relevant only if validUpdates                                                              contains HDR_MANIP_IPV4_SRC */
name|uint32_t
name|dst
decl_stmt|;
comment|/**< 32 bit New IP DST; Relevant only if validUpdates                                                              contains HDR_MANIP_IPV4_DST */
block|}
name|t_FmPcdManipHdrFieldUpdateIpv4
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation IPV6 fields updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrFieldUpdateIpv6
block|{
name|ipv6HdrManipUpdateFlags_t
name|validUpdates
decl_stmt|;
comment|/**< ORed flag, selecting the required updates */
name|uint8_t
name|trafficClass
decl_stmt|;
comment|/**< 8 bit New Traffic Class; Relevant if validUpdates contains                                                              HDR_MANIP_IPV6_TC */
name|uint8_t
name|src
index|[
name|NET_HEADER_FIELD_IPv6_ADDR_SIZE
index|]
decl_stmt|;
comment|/**< 16 byte new IP SRC; Relevant only if validUpdates                                                              contains HDR_MANIP_IPV6_SRC */
name|uint8_t
name|dst
index|[
name|NET_HEADER_FIELD_IPv6_ADDR_SIZE
index|]
decl_stmt|;
comment|/**< 16 byte new IP DST; Relevant only if validUpdates                                                              contains HDR_MANIP_IPV6_DST */
block|}
name|t_FmPcdManipHdrFieldUpdateIpv6
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation TCP/UDP fields updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrFieldUpdateTcpUdp
block|{
name|tcpUdpHdrManipUpdateFlags_t
name|validUpdates
decl_stmt|;
comment|/**< ORed flag, selecting the required updates */
name|uint16_t
name|src
decl_stmt|;
comment|/**< 16 bit New TCP/UDP SRC; Relevant only if validUpdates                                                              contains HDR_MANIP_TCP_UDP_SRC */
name|uint16_t
name|dst
decl_stmt|;
comment|/**< 16 bit New TCP/UDP DST; Relevant only if validUpdates                                                              contains HDR_MANIP_TCP_UDP_DST */
block|}
name|t_FmPcdManipHdrFieldUpdateTcpUdp
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation fields updates */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrFieldUpdateParams
block|{
name|e_FmPcdManipHdrFieldUpdateType
name|type
decl_stmt|;
comment|/**< Type of header field update manipulation */
union|union
block|{
name|t_FmPcdManipHdrFieldUpdateVlan
name|vlan
decl_stmt|;
comment|/**< Parameters for VLAN update. Relevant when                                                                          type = e_FM_PCD_MANIP_HDR_FIELD_UPDATE_VLAN */
name|t_FmPcdManipHdrFieldUpdateIpv4
name|ipv4
decl_stmt|;
comment|/**< Parameters for IPv4 update. Relevant when                                                                          type = e_FM_PCD_MANIP_HDR_FIELD_UPDATE_IPV4 */
name|t_FmPcdManipHdrFieldUpdateIpv6
name|ipv6
decl_stmt|;
comment|/**< Parameters for IPv6 update. Relevant when                                                                          type = e_FM_PCD_MANIP_HDR_FIELD_UPDATE_IPV6 */
name|t_FmPcdManipHdrFieldUpdateTcpUdp
name|tcpUdp
decl_stmt|;
comment|/**< Parameters for TCP/UDP update. Relevant when                                                                          type = e_FM_PCD_MANIP_HDR_FIELD_UPDATE_TCP_UDP */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrFieldUpdateParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining custom header manipulation for generic field replacement */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrCustomGenFieldReplace
block|{
name|uint8_t
name|srcOffset
decl_stmt|;
comment|/**< Location of new data - Offset from                                                              Parse Result  (>= 16, srcOffset+size<= 32, ) */
name|uint8_t
name|dstOffset
decl_stmt|;
comment|/**< Location of data to be overwritten - Offset from                                                              start of frame (dstOffset + size<= 256). */
name|uint8_t
name|size
decl_stmt|;
comment|/**< The number of bytes (<=16) to be replaced */
name|uint8_t
name|mask
decl_stmt|;
comment|/**< Optional 1 byte mask. Set to select bits for                                                              replacement (1 - bit will be replaced);                                                              Clear to use field as is. */
name|uint8_t
name|maskOffset
decl_stmt|;
comment|/**< Relevant if mask != 0;                                                              Mask offset within the replaces "size" */
block|}
name|t_FmPcdManipHdrCustomGenFieldReplace
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining custom header manipulation for IP replacement */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrCustomIpHdrReplace
block|{
name|e_FmPcdManipHdrCustomIpReplace
name|replaceType
decl_stmt|;
comment|/**< Selects replace update type */
name|bool
name|decTtlHl
decl_stmt|;
comment|/**< Decrement TTL (IPV4) or Hop limit (IPV6) by 1  */
name|bool
name|updateIpv4Id
decl_stmt|;
comment|/**< Relevant when replaceType =                                                              e_FM_PCD_MANIP_HDR_CUSTOM_REPLACE_IPV6_BY_IPV4 */
name|uint16_t
name|id
decl_stmt|;
comment|/**< 16 bit New IP ID; Relevant only if                                                              updateIpv4Id = TRUE */
name|uint8_t
name|hdrSize
decl_stmt|;
comment|/**< The size of the new IP header */
name|uint8_t
name|hdr
index|[
name|FM_PCD_MANIP_MAX_HDR_SIZE
index|]
decl_stmt|;
comment|/**< The new IP header */
block|}
name|t_FmPcdManipHdrCustomIpHdrReplace
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining custom header manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrCustomParams
block|{
name|e_FmPcdManipHdrCustomType
name|type
decl_stmt|;
comment|/**< Type of header field update manipulation */
union|union
block|{
name|t_FmPcdManipHdrCustomIpHdrReplace
name|ipHdrReplace
decl_stmt|;
comment|/**< Parameters IP header replacement */
name|t_FmPcdManipHdrCustomGenFieldReplace
name|genFieldReplace
decl_stmt|;
comment|/**< Parameters IP header replacement */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrCustomParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining specific L2 insertion manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrtSpecificL2Params
block|{
name|e_FmPcdManipHdrInsrtSpecificL2
name|specificL2
decl_stmt|;
comment|/**< Selects which L2 headers to insert */
name|bool
name|update
decl_stmt|;
comment|/**< TRUE to update MPLS header */
name|uint8_t
name|size
decl_stmt|;
comment|/**< size of inserted section */
name|uint8_t
modifier|*
name|p_Data
decl_stmt|;
comment|/**< data to be inserted */
block|}
name|t_FmPcdManipHdrInsrtSpecificL2Params
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining IP insertion manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrtIpParams
block|{
name|bool
name|calcL4Checksum
decl_stmt|;
comment|/**< Calculate L4 checksum. */
name|e_FmPcdManipHdrQosMappingMode
name|mappingMode
decl_stmt|;
comment|/**< TODO */
name|uint8_t
name|lastPidOffset
decl_stmt|;
comment|/**< the offset of the last Protocol within                                                          the inserted header */
name|uint16_t
name|id
decl_stmt|;
comment|/**< 16 bit New IP ID */
name|bool
name|dontFragOverwrite
decl_stmt|;
comment|/**< IPv4 only. DF is overwritten with the hash-result next-to-last byte.      * This byte is configured to be overwritten when RPD is set. */
name|uint8_t
name|lastDstOffset
decl_stmt|;
comment|/**< IPv6 only. if routing extension exist, user should set the offset of the destination address      * in order to calculate UDP checksum pseudo header;      * Otherwise set it to '0'. */
name|t_FmPcdManipHdrInsrt
name|insrt
decl_stmt|;
comment|/**< size and data to be inserted. */
block|}
name|t_FmPcdManipHdrInsrtIpParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header insertion manipulation by header type */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrtByHdrParams
block|{
name|e_FmPcdManipHdrInsrtByHdrType
name|type
decl_stmt|;
comment|/**< Selects manipulation type */
union|union
block|{
name|t_FmPcdManipHdrInsrtSpecificL2Params
name|specificL2Params
decl_stmt|;
comment|/**< Used when type = e_FM_PCD_MANIP_INSRT_BY_HDR_SPECIFIC_L2:                                                               Selects which L2 headers to insert */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdManipHdrInsrtIpParams
name|ipParams
decl_stmt|;
comment|/**< Used when type = e_FM_PCD_MANIP_INSRT_BY_HDR_IP */
name|t_FmPcdManipHdrInsrt
name|insrt
decl_stmt|;
comment|/**< Used when type is one of e_FM_PCD_MANIP_INSRT_BY_HDR_UDP,                                                                 e_FM_PCD_MANIP_INSRT_BY_HDR_UDP_LITE, or                                                                 e_FM_PCD_MANIP_INSRT_BY_HDR_CAPWAP */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrInsrtByHdrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header insertion manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrInsrtParams
block|{
name|e_FmPcdManipHdrInsrtType
name|type
decl_stmt|;
comment|/**< Type of insertion manipulation */
union|union
block|{
name|t_FmPcdManipHdrInsrtByHdrParams
name|byHdr
decl_stmt|;
comment|/**< Parameters for defining header insertion manipulation by header type,                                                                  relevant if 'type' = e_FM_PCD_MANIP_INSRT_BY_HDR */
name|t_FmPcdManipHdrInsrtGenericParams
name|generic
decl_stmt|;
comment|/**< Parameters for defining generic header insertion manipulation,                                                                  relevant if 'type' = e_FM_PCD_MANIP_INSRT_GENERIC */
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
name|t_FmPcdManipHdrInsrtByTemplateParams
name|byTemplate
decl_stmt|;
comment|/**< Parameters for defining header insertion manipulation by template,                                                                  relevant if 'type' = e_FM_PCD_MANIP_INSRT_BY_TEMPLATE */
endif|#
directive|endif
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrInsrtParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header removal manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrRmvParams
block|{
name|e_FmPcdManipHdrRmvType
name|type
decl_stmt|;
comment|/**< Type of header removal manipulation */
union|union
block|{
name|t_FmPcdManipHdrRmvByHdrParams
name|byHdr
decl_stmt|;
comment|/**< Parameters for defining header removal manipulation by header type,                                                              relevant if type = e_FM_PCD_MANIP_RMV_BY_HDR */
name|t_FmPcdManipHdrRmvGenericParams
name|generic
decl_stmt|;
comment|/**< Parameters for defining generic header removal manipulation,                                                              relevant if type = e_FM_PCD_MANIP_RMV_GENERIC */
block|}
name|u
union|;
block|}
name|t_FmPcdManipHdrRmvParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining header manipulation node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipHdrParams
block|{
name|bool
name|rmv
decl_stmt|;
comment|/**< TRUE, to define removal manipulation */
name|t_FmPcdManipHdrRmvParams
name|rmvParams
decl_stmt|;
comment|/**< Parameters for removal manipulation, relevant if 'rmv' = TRUE */
name|bool
name|insrt
decl_stmt|;
comment|/**< TRUE, to define insertion manipulation */
name|t_FmPcdManipHdrInsrtParams
name|insrtParams
decl_stmt|;
comment|/**< Parameters for insertion manipulation, relevant if 'insrt' = TRUE */
name|bool
name|fieldUpdate
decl_stmt|;
comment|/**< TRUE, to define field update manipulation */
name|t_FmPcdManipHdrFieldUpdateParams
name|fieldUpdateParams
decl_stmt|;
comment|/**< Parameters for field update manipulation, relevant if 'fieldUpdate' = TRUE */
name|bool
name|custom
decl_stmt|;
comment|/**< TRUE, to define custom manipulation */
name|t_FmPcdManipHdrCustomParams
name|customParams
decl_stmt|;
comment|/**< Parameters for custom manipulation, relevant if 'custom' = TRUE */
name|bool
name|dontParseAfterManip
decl_stmt|;
comment|/**< TRUE to de-activate the parser after the manipulation defined in this node.                                                                                           Restrictions:                                                                                           1. MUST be set if the next engine after the CC is not another CC node                                                                                           (but rather Policer or Keygen), and this is the last (no h_NextManip) in a chain                                                                                           of manipulation nodes. This includes single nodes (i.e. no h_NextManip and                                                                                           also never pointed as h_NextManip of other manipulation nodes)                                                                                           2. MUST be set if the next engine after the CC is another CC node, and                                                                                           this is NOT the last manipulation node (i.e. it has h_NextManip).*/
block|}
name|t_FmPcdManipHdrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining fragmentation manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragParams
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
union|union
block|{
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdManipFragCapwapParams
name|capwapFrag
decl_stmt|;
comment|/**< Parameters for defining CAPWAP fragmentation,                                                            relevant if 'hdr' = HEADER_TYPE_CAPWAP */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|t_FmPcdManipFragIpParams
name|ipFrag
decl_stmt|;
comment|/**< Parameters for defining IP fragmentation,                                                            relevant if 'hdr' = HEADER_TYPE_Ipv4 or HEADER_TYPE_Ipv6 */
block|}
name|u
union|;
block|}
name|t_FmPcdManipFragParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining reassembly manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipReassemParams
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
union|union
block|{
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdManipReassemCapwapParams
name|capwapReassem
decl_stmt|;
comment|/**< Parameters for defining CAPWAP reassembly,                                                            relevant if 'hdr' = HEADER_TYPE_CAPWAP */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|t_FmPcdManipReassemIpParams
name|ipReassem
decl_stmt|;
comment|/**< Parameters for defining IP reassembly,                                                            relevant if 'hdr' = HEADER_TYPE_Ipv4 or HEADER_TYPE_Ipv6 */
block|}
name|u
union|;
block|}
name|t_FmPcdManipReassemParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining a manipulation node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipParams
block|{
name|e_FmPcdManipType
name|type
decl_stmt|;
comment|/**< Selects type of manipulation node */
union|union
block|{
name|t_FmPcdManipHdrParams
name|hdr
decl_stmt|;
comment|/**< Parameters for defining header manipulation node */
name|t_FmPcdManipReassemParams
name|reassem
decl_stmt|;
comment|/**< Parameters for defining reassembly manipulation node */
name|t_FmPcdManipFragParams
name|frag
decl_stmt|;
comment|/**< Parameters for defining fragmentation manipulation node */
name|t_FmPcdManipSpecialOffloadParams
name|specialOffload
decl_stmt|;
comment|/**< Parameters for defining special offload manipulation node */
block|}
name|u
union|;
name|t_Handle
name|h_NextManip
decl_stmt|;
comment|/**< Supported for Header Manipulation only;                                                                      Handle to another (previously defined) manipulation node;                                                                      Allows concatenation of manipulation actions;                                                                      This parameter is optional and may be NULL. */
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
name|bool
name|fragOrReasm
decl_stmt|;
comment|/**< TRUE, if defined fragmentation/reassembly manipulation */
name|t_FmPcdManipFragOrReasmParams
name|fragOrReasmParams
decl_stmt|;
comment|/**< Parameters for fragmentation/reassembly manipulation,                                                                      relevant if fragOrReasm = TRUE */
endif|#
directive|endif
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
block|}
name|t_FmPcdManipParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for retrieving IP reassembly statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipReassemIpStats
block|{
comment|/* common counters for both IPv4 and IPv6 */
name|uint32_t
name|timeout
decl_stmt|;
comment|/**< Counts the number of timeout occurrences */
name|uint32_t
name|rfdPoolBusy
decl_stmt|;
comment|/**< Counts the number of failed attempts to allocate                                                      a Reassembly Frame Descriptor */
name|uint32_t
name|internalBufferBusy
decl_stmt|;
comment|/**< Counts the number of times an internal buffer busy occurred */
name|uint32_t
name|externalBufferBusy
decl_stmt|;
comment|/**< Counts the number of times external buffer busy occurred */
name|uint32_t
name|sgFragments
decl_stmt|;
comment|/**< Counts the number of Scatter/Gather fragments */
name|uint32_t
name|dmaSemaphoreDepletion
decl_stmt|;
comment|/**< Counts the number of failed attempts to allocate a DMA semaphore */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|uint32_t
name|nonConsistentSp
decl_stmt|;
comment|/**< Counts the number of Non Consistent Storage Profile events for                                                      successfully reassembled frames */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
struct|struct
block|{
name|uint32_t
name|successfullyReassembled
decl_stmt|;
comment|/**< Counts the number of successfully reassembled frames */
name|uint32_t
name|validFragments
decl_stmt|;
comment|/**< Counts the total number of valid fragments that                                                      have been processed for all frames */
name|uint32_t
name|processedFragments
decl_stmt|;
comment|/**< Counts the number of processed fragments                                                      (valid and error fragments) for all frames */
name|uint32_t
name|malformedFragments
decl_stmt|;
comment|/**< Counts the number of malformed fragments processed for all frames */
name|uint32_t
name|discardedFragments
decl_stmt|;
comment|/**< Counts the number of fragments discarded by the reassembly process */
name|uint32_t
name|autoLearnBusy
decl_stmt|;
comment|/**< Counts the number of times a busy condition occurs when attempting                                                      to access an IP-Reassembly Automatic Learning Hash set */
name|uint32_t
name|moreThan16Fragments
decl_stmt|;
comment|/**< Counts the fragment occurrences in which the number of fragments-per-frame                                                      exceeds 16 */
block|}
name|specificHdrStatistics
index|[
literal|2
index|]
struct|;
comment|/**< slot '0' is for IPv4, slot '1' is for IPv6 */
block|}
name|t_FmPcdManipReassemIpStats
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for retrieving IP fragmentation statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragIpStats
block|{
name|uint32_t
name|totalFrames
decl_stmt|;
comment|/**< Number of frames that passed through the manipulation node */
name|uint32_t
name|fragmentedFrames
decl_stmt|;
comment|/**< Number of frames that were fragmented */
name|uint32_t
name|generatedFragments
decl_stmt|;
comment|/**< Number of fragments that were generated */
block|}
name|t_FmPcdManipFragIpStats
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for retrieving CAPWAP reassembly statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipReassemCapwapStats
block|{
name|uint32_t
name|timeout
decl_stmt|;
comment|/**< Counts the number of timeout occurrences */
name|uint32_t
name|rfdPoolBusy
decl_stmt|;
comment|/**< Counts the number of failed attempts to allocate                                                  a Reassembly Frame Descriptor */
name|uint32_t
name|internalBufferBusy
decl_stmt|;
comment|/**< Counts the number of times an internal buffer busy occurred */
name|uint32_t
name|externalBufferBusy
decl_stmt|;
comment|/**< Counts the number of times external buffer busy occurred */
name|uint32_t
name|sgFragments
decl_stmt|;
comment|/**< Counts the number of Scatter/Gather fragments */
name|uint32_t
name|dmaSemaphoreDepletion
decl_stmt|;
comment|/**< Counts the number of failed attempts to allocate a DMA semaphore */
name|uint32_t
name|successfullyReassembled
decl_stmt|;
comment|/**< Counts the number of successfully reassembled frames */
name|uint32_t
name|validFragments
decl_stmt|;
comment|/**< Counts the total number of valid fragments that                                                  have been processed for all frames */
name|uint32_t
name|processedFragments
decl_stmt|;
comment|/**< Counts the number of processed fragments                                                  (valid and error fragments) for all frames */
name|uint32_t
name|malformedFragments
decl_stmt|;
comment|/**< Counts the number of malformed fragments processed for all frames */
name|uint32_t
name|autoLearnBusy
decl_stmt|;
comment|/**< Counts the number of times a busy condition occurs when attempting                                                  to access an Reassembly Automatic Learning Hash set */
name|uint32_t
name|discardedFragments
decl_stmt|;
comment|/**< Counts the number of fragments discarded by the reassembly process */
name|uint32_t
name|moreThan16Fragments
decl_stmt|;
comment|/**< Counts the fragment occurrences in which the number of fragments-per-frame                                                  exceeds 16 */
name|uint32_t
name|exceedMaxReassemblyFrameLen
decl_stmt|;
comment|/**< ounts the number of times that a successful reassembled frame                                                  length exceeds MaxReassembledFrameLength value */
block|}
name|t_FmPcdManipReassemCapwapStats
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for retrieving CAPWAP fragmentation statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragCapwapStats
block|{
name|uint32_t
name|totalFrames
decl_stmt|;
comment|/**< Number of frames that passed through the manipulation node */
name|uint32_t
name|fragmentedFrames
decl_stmt|;
comment|/**< Number of frames that were fragmented */
name|uint32_t
name|generatedFragments
decl_stmt|;
comment|/**< Number of fragments that were generated */
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
name|uint8_t
name|sgAllocationFailure
decl_stmt|;
comment|/**< Number of allocation failure of s/g buffers */
endif|#
directive|endif
comment|/* (defined(DEBUG_ERRORS)&& (DEBUG_ERRORS> 0)) */
block|}
name|t_FmPcdManipFragCapwapStats
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for retrieving reassembly statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipReassemStats
block|{
union|union
block|{
name|t_FmPcdManipReassemIpStats
name|ipReassem
decl_stmt|;
comment|/**< Structure for IP reassembly statistics */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdManipReassemCapwapStats
name|capwapReassem
decl_stmt|;
comment|/**< Structure for CAPWAP reassembly statistics */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|u
union|;
block|}
name|t_FmPcdManipReassemStats
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for retrieving fragmentation statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipFragStats
block|{
union|union
block|{
name|t_FmPcdManipFragIpStats
name|ipFrag
decl_stmt|;
comment|/**< Structure for IP fragmentation statistics */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|t_FmPcdManipFragCapwapStats
name|capwapFrag
decl_stmt|;
comment|/**< Structure for CAPWAP fragmentation statistics */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|u
union|;
block|}
name|t_FmPcdManipFragStats
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for selecting manipulation statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipStats
block|{
union|union
block|{
name|t_FmPcdManipReassemStats
name|reassem
decl_stmt|;
comment|/**< Structure for reassembly statistics */
name|t_FmPcdManipFragStats
name|frag
decl_stmt|;
comment|/**< Structure for fragmentation statistics */
block|}
name|u
union|;
block|}
name|t_FmPcdManipStats
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Parameters for defining frame replicator group and its members */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdFrmReplicGroupParams
block|{
name|uint8_t
name|maxNumOfEntries
decl_stmt|;
comment|/**< Maximal number of members in the group;                                                          Must be at least 2. */
name|uint8_t
name|numOfEntries
decl_stmt|;
comment|/**< Number of members in the group;                                                          Must be at least 1. */
name|t_FmPcdCcNextEngineParams
name|nextEngineParams
index|[
name|FM_PCD_FRM_REPLIC_MAX_NUM_OF_ENTRIES
index|]
decl_stmt|;
comment|/**< Array of members' parameters */
block|}
name|t_FmPcdFrmReplicGroupParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining statistics node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdStatsParams
block|{
name|e_FmPcdStatsType
name|type
decl_stmt|;
comment|/**< type of statistics node */
block|}
name|t_FmPcdStatsParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_NetEnvCharacteristicsSet   @Description   Define a set of Network Environment Characteristics.                  When setting an environment it is important to understand its                 application. It is not meant to describe the flows that will run                 on the ports using this environment, but what the user means TO DO                 with the PCD mechanisms in order to parse-classify-distribute those                 frames.                 By specifying a distinction unit, the user means it would use that option                 for distinction between frames at either a KeyGen scheme or a coarse                 classification action descriptor. Using interchangeable headers to define a                 unit means that the user is indifferent to which of the interchangeable                 headers is present in the frame, and wants the distinction to be based                 on the presence of either one of them.                  Depending on context, there are limitations to the use of environments. A                 port using the PCD functionality is bound to an environment. Some or even                 all ports may share an environment but also an environment per port is                 possible. When initializing a scheme, a classification plan group (see below),                 or a coarse classification tree, one of the initialized environments must be                 stated and related to. When a port is bound to a scheme, a classification                 plan group, or a coarse classification tree, it MUST be bound to the same                 environment.                  The different PCD modules, may relate (for flows definition) ONLY on                 distinction units as defined by their environment. When initializing a                 scheme for example, it may not choose to select IPV4 as a match for                 recognizing flows unless it was defined in the relating environment. In                 fact, to guide the user through the configuration of the PCD, each module's                 characterization in terms of flows is not done using protocol names, but using                 environment indexes.                  In terms of HW implementation, the list of distinction units sets the LCV vectors                 and later used for match vector, classification plan vectors and coarse classification                 indexing.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     p_NetEnvParams  A structure of parameters for the initialization of                                 the network environment.   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_NetEnvCharacteristicsSet
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdNetEnvParams
modifier|*
name|p_NetEnvParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_NetEnvCharacteristicsDelete   @Description   Deletes a set of Network Environment Characteristics.   @Param[in]     h_NetEnv        A handle to the Network environment.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_NetEnvCharacteristicsDelete
parameter_list|(
name|t_Handle
name|h_NetEnv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSchemeSet   @Description   Initializing or modifying and enabling a scheme for the KeyGen.                 This routine should be called for adding or modifying a scheme.                 When a scheme needs modifying, the API requires that it will be                 rewritten. In such a case 'modify' should be TRUE. If the                 routine is called for a valid scheme and 'modify' is FALSE,                 it will return error.   @Param[in]     h_FmPcd         If this is a new scheme - A handle to an FM PCD Module.                                 Otherwise NULL (ignored by driver).  @Param[in,out] p_SchemeParams  A structure of parameters for defining the scheme   @Return        A handle to the initialized scheme on success; NULL code otherwise.                 When used as "modify" (rather than for setting a new scheme),                 p_SchemeParams->id.h_Scheme will return NULL if action fails due to scheme                 BUSY state.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_KgSchemeSet
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgSchemeParams
modifier|*
name|p_SchemeParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSchemeDelete   @Description   Deleting an initialized scheme.   @Param[in]     h_Scheme        scheme handle as returned by FM_PCD_KgSchemeSet()   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init()& FM_PCD_KgSchemeSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgSchemeDelete
parameter_list|(
name|t_Handle
name|h_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSchemeGetCounter   @Description   Reads scheme packet counter.   @Param[in]     h_Scheme        scheme handle as returned by FM_PCD_KgSchemeSet().   @Return        Counter's current value.   @Cautions      Allowed only following FM_PCD_Init()& FM_PCD_KgSchemeSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_KgSchemeGetCounter
parameter_list|(
name|t_Handle
name|h_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSchemeSetCounter   @Description   Writes scheme packet counter.   @Param[in]     h_Scheme        scheme handle as returned by FM_PCD_KgSchemeSet().  @Param[in]     value           New scheme counter value - typically '0' for                                 resetting the counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init()& FM_PCD_KgSchemeSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgSchemeSetCounter
parameter_list|(
name|t_Handle
name|h_Scheme
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrProfileSet   @Description   Sets a profile entry in the policer profile table.                 The routine overrides any existing value.   @Param[in]     h_FmPcd           A handle to an FM PCD Module.  @Param[in]     p_Profile         A structure of parameters for defining a                                   policer profile entry.   @Return        A handle to the initialized object on success; NULL code otherwise.                 When used as "modify" (rather than for setting a new profile),                 p_Profile->id.h_Profile will return NULL if action fails due to profile                 BUSY state.  @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_PlcrProfileSet
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdPlcrProfileParams
modifier|*
name|p_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrProfileDelete   @Description   Delete a profile entry in the policer profile table.                 The routine set entry to invalid.   @Param[in]     h_Profile       A handle to the profile.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrProfileDelete
parameter_list|(
name|t_Handle
name|h_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrProfileGetCounter   @Description   Sets an entry in the classification plan.                 The routine overrides any existing value.   @Param[in]     h_Profile       A handle to the profile.  @Param[in]     counter         Counter selector.   @Return        specific counter value.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_PlcrProfileGetCounter
parameter_list|(
name|t_Handle
name|h_Profile
parameter_list|,
name|e_FmPcdPlcrProfileCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrProfileSetCounter   @Description   Sets an entry in the classification plan.                 The routine overrides any existing value.   @Param[in]     h_Profile       A handle to the profile.  @Param[in]     counter         Counter selector.  @Param[in]     value           value to set counter with.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrProfileSetCounter
parameter_list|(
name|t_Handle
name|h_Profile
parameter_list|,
name|e_FmPcdPlcrProfileCounters
name|counter
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcRootBuild   @Description   This routine must be called to define a complete coarse                 classification tree. This is the way to define coarse                 classification to a certain flow - the KeyGen schemes                 may point only to trees defined in this way.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     p_Params        A structure of parameters to define the tree.   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_CcRootBuild
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdCcTreeParams
modifier|*
name|p_Params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcRootDelete   @Description   Deleting an built tree.   @Param[in]     h_CcTree        A handle to a CC tree.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcRootDelete
parameter_list|(
name|t_Handle
name|h_CcTree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcRootModifyNextEngine   @Description   Modify the Next Engine Parameters in the entry of the tree.   @Param[in]     h_CcTree                    A handle to the tree  @Param[in]     grpId                       A Group index in the tree  @Param[in]     index                       Entry index in the group defined by grpId  @Param[in]     p_FmPcdCcNextEngineParams   Pointer to new next engine parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcBuildTree(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcRootModifyNextEngine
parameter_list|(
name|t_Handle
name|h_CcTree
parameter_list|,
name|uint8_t
name|grpId
parameter_list|,
name|uint8_t
name|index
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableSet   @Description   This routine should be called for each CC (coarse classification)                 node. The whole CC tree should be built bottom up so that each                 node points to already defined nodes.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     p_Param         A structure of parameters defining the CC node   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_MatchTableSet
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdCcNodeParams
modifier|*
name|p_Param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableDelete   @Description   Deleting an built node.   @Param[in]     h_CcNode        A handle to a CC node.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableDelete
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableModifyMissNextEngine   @Description   Modify the Next Engine Parameters of the Miss key case of the node.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     p_FmPcdCcNextEngineParams   Parameters for defining next engine   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet();                 Not relevant in the case the node is of type 'INDEXED_LOOKUP'.                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableModifyMissNextEngine
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableRemoveKey   @Description   Remove the key (including next engine parameters of this key)                 defined by the index of the relevant node.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for removing   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableRemoveKey
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableAddKey   @Description   Add the key (including next engine parameters of this key in the                 index defined by the keyIndex. Note that 'FM_PCD_LAST_KEY_INDEX'                 may be used by user that don't care about the position of the                 key in the table - in that case, the key will be automatically                 added by the driver in the last available entry.   @Param[in]     h_CcNode     A handle to the node  @Param[in]     keyIndex     Key index for adding.  @Param[in]     keySize      Key size of added key  @Param[in]     p_KeyParams  A pointer to the parameters includes                              new key with Next Engine Parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableAddKey
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_KeyParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableModifyNextEngine   @Description   Modify the Next Engine Parameters in the relevant key entry of the node.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for Next Engine modifications  @Param[in]     p_FmPcdCcNextEngineParams   Parameters for defining next engine   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet().                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableModifyNextEngine
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableModifyKeyAndNextEngine   @Description   Modify the key and Next Engine Parameters of this key in the                 index defined by the keyIndex.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for adding  @Param[in]     keySize                     Key size of added key  @Param[in]     p_KeyParams                 A pointer to the parameters includes                                             modified key and modified Next Engine Parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it.                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableModifyKeyAndNextEngine
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_KeyParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableModifyKey   @Description   Modify the key in the index defined by the keyIndex.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for adding  @Param[in]     keySize                     Key size of added key  @Param[in]     p_Key                       A pointer to the new key  @Param[in]     p_Mask                      A pointer to the new mask if relevant,                                             otherwise pointer to NULL   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableModifyKey
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableFindNRemoveKey   @Description   Remove the key (including next engine parameters of this key)                 defined by the key and mask. Note that this routine will search                 the node to locate the index of the required key (& mask) to remove.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keySize                     Key size of the one to remove.  @Param[in]     p_Key                       A pointer to the requested key to remove.  @Param[in]     p_Mask                      A pointer to the mask if relevant,                                             otherwise pointer to NULL   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableFindNRemoveKey
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableFindNModifyNextEngine   @Description   Modify the Next Engine Parameters in the relevant key entry of                 the node. Note that this routine will search the node to locate                 the index of the required key (& mask) to modify.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keySize                     Key size of the one to modify.  @Param[in]     p_Key                       A pointer to the requested key to modify.  @Param[in]     p_Mask                      A pointer to the mask if relevant,                                             otherwise pointer to NULL  @Param[in]     p_FmPcdCcNextEngineParams   Parameters for defining next engine   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet().                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableFindNModifyNextEngine
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableFindNModifyKeyAndNextEngine   @Description   Modify the key and Next Engine Parameters of this key in the                 index defined by the keyIndex. Note that this routine will search                 the node to locate the index of the required key (& mask) to modify.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keySize                     Key size of the one to modify.  @Param[in]     p_Key                       A pointer to the requested key to modify.  @Param[in]     p_Mask                      A pointer to the mask if relevant,                                             otherwise pointer to NULL  @Param[in]     p_KeyParams                 A pointer to the parameters includes                                             modified key and modified Next Engine Parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it.                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableFindNModifyKeyAndNextEngine
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_KeyParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableFindNModifyKey   @Description   Modify the key  in the index defined by the keyIndex. Note that                 this routine will search the node to locate the index of the                 required key (& mask) to modify.   @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keySize                     Key size of the one to modify.  @Param[in]     p_Key                       A pointer to the requested key to modify.  @Param[in]     p_Mask                      A pointer to the mask if relevant,                                             otherwise pointer to NULL  @Param[in]     p_NewKey                    A pointer to the new key  @Param[in]     p_NewMask                   A pointer to the new mask if relevant,                                             otherwise pointer to NULL   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_MatchTableSet() was called for this                 node and the nodes that lead to it. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableFindNModifyKey
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|,
name|uint8_t
modifier|*
name|p_NewKey
parameter_list|,
name|uint8_t
modifier|*
name|p_NewMask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableGetKeyCounter   @Description   This routine may be used to get a counter of specific key in a CC                 Node; This counter reflects how many frames passed that were matched                 this key.   @Param[in]     h_CcNode        A handle to the node  @Param[in]     keyIndex        Key index for adding   @Return        The specific key counter.   @Cautions      Allowed only following FM_PCD_MatchTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_MatchTableGetKeyCounter
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableGetKeyStatistics   @Description   This routine may be used to get statistics counters of specific key                 in a CC Node.                  If 'e_FM_PCD_CC_STATS_MODE_FRAME' and                 'e_FM_PCD_CC_STATS_MODE_BYTE_AND_FRAME' were set for this node,                 these counters reflect how many frames passed that were matched                 this key; The total frames count will be returned in the counter                 of the first range (as only one frame length range was defined).                 If 'e_FM_PCD_CC_STATS_MODE_RMON' was set for this node, the total                 frame count will be separated to frame length counters, based on                 provided frame length ranges.   @Param[in]     h_CcNode        A handle to the node  @Param[in]     keyIndex        Key index for adding  @Param[out]    p_KeyStatistics Key statistics counters   @Return        The specific key statistics.   @Cautions      Allowed only following FM_PCD_MatchTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableGetKeyStatistics
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|,
name|t_FmPcdCcKeyStatistics
modifier|*
name|p_KeyStatistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableGetMissStatistics   @Description   This routine may be used to get statistics counters of miss entry                 in a CC Node.                  If 'e_FM_PCD_CC_STATS_MODE_FRAME' and                 'e_FM_PCD_CC_STATS_MODE_BYTE_AND_FRAME' were set for this node,                 these counters reflect how many frames were not matched to any                 existing key and therefore passed through the miss entry; The                 total frames count will be returned in the counter of the                 first range (as only one frame length range was defined).   @Param[in]     h_CcNode            A handle to the node  @Param[out]    p_MissStatistics    Statistics counters for 'miss'   @Return        The statistics for 'miss'.   @Cautions      Allowed only following FM_PCD_MatchTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableGetMissStatistics
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|t_FmPcdCcKeyStatistics
modifier|*
name|p_MissStatistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MatchTableFindNGetKeyStatistics   @Description   This routine may be used to get statistics counters of specific key                 in a CC Node.                  If 'e_FM_PCD_CC_STATS_MODE_FRAME' and                 'e_FM_PCD_CC_STATS_MODE_BYTE_AND_FRAME' were set for this node,                 these counters reflect how many frames passed that were matched                 this key; The total frames count will be returned in the counter                 of the first range (as only one frame length range was defined).                 If 'e_FM_PCD_CC_STATS_MODE_RMON' was set for this node, the total                 frame count will be separated to frame length counters, based on                 provided frame length ranges.                 Note that this routine will search the node to locate the index                 of the required key based on received key parameters.   @Param[in]     h_CcNode        A handle to the node  @Param[in]     keySize         Size of the requested key  @Param[in]     p_Key           A pointer to the requested key  @Param[in]     p_Mask          A pointer to the mask if relevant,                                 otherwise pointer to NULL  @Param[out]    p_KeyStatistics Key statistics counters   @Return        The specific key statistics.   @Cautions      Allowed only following FM_PCD_MatchTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableFindNGetKeyStatistics
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|,
name|t_FmPcdCcKeyStatistics
modifier|*
name|p_KeyStatistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Function      FM_PCD_MatchTableGetNextEngine   @Description   Gets NextEngine of the relevant keyIndex.   @Param[in]     h_CcNode                    A handle to the node.  @Param[in]     keyIndex                    keyIndex in the relevant node.  @Param[out]    p_FmPcdCcNextEngineParams   here updated nextEngine parameters for                                             the relevant keyIndex of the CC Node                                             received as parameter to this function   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableGetNextEngine
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint16_t
name|keyIndex
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Function      FM_PCD_MatchTableGetIndexedHashBucket   @Description   This routine simulates KeyGen operation on the provided key and                 calculates to which hash bucket it will be mapped.   @Param[in]     h_CcNode                A handle to the node.  @Param[in]     kgKeySize               Key size as it was configured in the KG                                         scheme that leads to this hash.  @Param[in]     p_KgKey                 Pointer to the key; must be like the key                                         that the KG is generated, i.e. the same                                         extraction and with mask if exist.  @Param[in]     kgHashShift             Hash-shift as it was configured in the KG                                         scheme that leads to this hash.  @Param[out]    p_CcNodeBucketHandle    Pointer to the bucket of the provided key.  @Param[out]    p_BucketIndex           Index to the bucket of the provided key  @Param[out]    p_LastIndex             Pointer to last index in the bucket of the                                         provided key.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet() */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_MatchTableGetIndexedHashBucket
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|kgKeySize
parameter_list|,
name|uint8_t
modifier|*
name|p_KgKey
parameter_list|,
name|uint8_t
name|kgHashShift
parameter_list|,
name|t_Handle
modifier|*
name|p_CcNodeBucketHandle
parameter_list|,
name|uint8_t
modifier|*
name|p_BucketIndex
parameter_list|,
name|uint16_t
modifier|*
name|p_LastIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableSet   @Description   This routine initializes a hash table structure.                 KeyGen hash result determines the hash bucket.                 Next, KeyGen key is compared against all keys of this                 bucket (exact match).                 Number of sets (number of buckets) of the hash equals to the                 number of 1-s in 'hashResMask' in the provided parameters.                 Number of hash table ways is then calculated by dividing                 'maxNumOfKeys' equally between the hash sets. This is the maximal                 number of keys that a hash bucket may hold.                 The hash table is initialized empty and keys may be                 added to it following the initialization. Keys masks are not                 supported in current hash table implementation.                 The initialized hash table can be integrated as a node in a                 CC tree.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     p_Param     A structure of parameters defining the hash table   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_HashTableSet
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdHashTableParams
modifier|*
name|p_Param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableDelete   @Description   This routine deletes the provided hash table and released all                 its allocated resources.   @Param[in]     h_HashTbl       A handle to a hash table   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableDelete
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableAddKey   @Description   This routine adds the provided key (including next engine                 parameters of this key) to the hash table.                 The key is added as the last key of the bucket that it is                 mapped to.   @Param[in]     h_HashTbl    A handle to a hash table  @Param[in]     keySize      Key size of added key  @Param[in]     p_KeyParams  A pointer to the parameters includes                              new key with next engine parameters; The pointer                              to the key mask must be NULL, as masks are not                              supported in hash table implementation.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableAddKey
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_KeyParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableRemoveKey   @Description   This routine removes the requested key (including next engine                 parameters of this key) from the hash table.   @Param[in]     h_HashTbl    A handle to a hash table  @Param[in]     keySize      Key size of the one to remove.  @Param[in]     p_Key        A pointer to the requested key to remove.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableRemoveKey
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableModifyNextEngine   @Description   This routine modifies the next engine for the provided key. The                 key should be previously added to the hash table.   @Param[in]     h_HashTbl                   A handle to a hash table  @Param[in]     keySize                     Key size of the key to modify.  @Param[in]     p_Key                       A pointer to the requested key to modify.  @Param[in]     p_FmPcdCcNextEngineParams   A structure for defining new next engine                                             parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet().                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableModifyNextEngine
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableModifyMissNextEngine   @Description   This routine modifies the next engine on key match miss.   @Param[in]     h_HashTbl                   A handle to a hash table  @Param[in]     p_FmPcdCcNextEngineParams   A structure for defining new next engine                                             parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet().                 When configuring nextEngine = e_FM_PCD_CC, note that                 p_FmPcdCcNextEngineParams->ccParams.h_CcNode must be different                 from the currently changed table. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableModifyMissNextEngine
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Function      FM_PCD_HashTableGetMissNextEngine   @Description   Gets NextEngine in case of key match miss.   @Param[in]     h_HashTbl                   A handle to a hash table  @Param[out]    p_FmPcdCcNextEngineParams   Next engine parameters for the specified                                             hash table.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_HashTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableGetMissNextEngine
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableFindNGetKeyStatistics   @Description   This routine may be used to get statistics counters of specific key                 in a hash table.                  If 'e_FM_PCD_CC_STATS_MODE_FRAME' and                 'e_FM_PCD_CC_STATS_MODE_BYTE_AND_FRAME' were set for this node,                 these counters reflect how many frames passed that were matched                 this key; The total frames count will be returned in the counter                 of the first range (as only one frame length range was defined).                 If 'e_FM_PCD_CC_STATS_MODE_RMON' was set for this node, the total                 frame count will be separated to frame length counters, based on                 provided frame length ranges.                 Note that this routine will identify the bucket of this key in                 the hash table and will search the bucket to locate the index                 of the required key based on received key parameters.   @Param[in]     h_HashTbl       A handle to a hash table  @Param[in]     keySize         Size of the requested key  @Param[in]     p_Key           A pointer to the requested key  @Param[out]    p_KeyStatistics Key statistics counters   @Return        The specific key statistics.   @Cautions      Allowed only following FM_PCD_HashTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableFindNGetKeyStatistics
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|t_FmPcdCcKeyStatistics
modifier|*
name|p_KeyStatistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_HashTableGetMissStatistics   @Description   This routine may be used to get statistics counters of 'miss'                 entry of the a hash table.                  If 'e_FM_PCD_CC_STATS_MODE_FRAME' and                 'e_FM_PCD_CC_STATS_MODE_BYTE_AND_FRAME' were set for this node,                 these counters reflect how many frames were not matched to any                 existing key and therefore passed through the miss entry;   @Param[in]     h_HashTbl           A handle to a hash table  @Param[out]    p_MissStatistics    Statistics counters for 'miss'   @Return        The statistics for 'miss'.   @Cautions      Allowed only following FM_PCD_HashTableSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_HashTableGetMissStatistics
parameter_list|(
name|t_Handle
name|h_HashTbl
parameter_list|,
name|t_FmPcdCcKeyStatistics
modifier|*
name|p_MissStatistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ManipNodeSet   @Description   This routine should be called for defining a manipulation                 node. A manipulation node must be defined before the CC node                 that precedes it.   @Param[in]     h_FmPcd             FM PCD module descriptor.  @Param[in]     p_FmPcdManipParams  A structure of parameters defining the manipulation   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_ManipNodeSet
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdManipParams
modifier|*
name|p_FmPcdManipParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ManipNodeDelete   @Description   Delete an existing manipulation node.   @Param[in]     h_ManipNode     A handle to a manipulation node.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_ManipNodeSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ManipNodeDelete
parameter_list|(
name|t_Handle
name|h_ManipNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ManipGetStatistics   @Description   Retrieve the manipulation statistics.   @Param[in]     h_ManipNode         A handle to a manipulation node.  @Param[out]    p_FmPcdManipStats   A structure for retrieving the manipulation statistics   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_ManipNodeSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ManipGetStatistics
parameter_list|(
name|t_Handle
name|h_ManipNode
parameter_list|,
name|t_FmPcdManipStats
modifier|*
name|p_FmPcdManipStats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ManipNodeReplace   @Description   Change existing manipulation node to be according to new requirement.   @Param[in]     h_ManipNode         A handle to a manipulation node.  @Param[out]    p_ManipParams       A structure of parameters defining the change requirement   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_ManipNodeSet(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ManipNodeReplace
parameter_list|(
name|t_Handle
name|h_ManipNode
parameter_list|,
name|t_FmPcdManipParams
modifier|*
name|p_ManipParams
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FrmReplicSetGroup   @Description   Initialize a Frame Replicator group.   @Param[in]     h_FmPcd                FM PCD module descriptor.  @Param[in]     p_FrmReplicGroupParam  A structure of parameters for the initialization of                                        the frame replicator group.   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_FrmReplicSetGroup
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdFrmReplicGroupParams
modifier|*
name|p_FrmReplicGroupParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FrmReplicDeleteGroup   @Description   Delete a Frame Replicator group.   @Param[in]     h_FrmReplicGroup  A handle to the frame replicator group.   @Return        E_OK on success;  Error code otherwise.   @Cautions      Allowed only following FM_PCD_FrmReplicSetGroup(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_FrmReplicDeleteGroup
parameter_list|(
name|t_Handle
name|h_FrmReplicGroup
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FrmReplicAddMember   @Description   Add the member in the index defined by the memberIndex.   @Param[in]     h_FrmReplicGroup   A handle to the frame replicator group.  @Param[in]     memberIndex        member index for adding.  @Param[in]     p_MemberParams     A pointer to the new member parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_FrmReplicSetGroup() of this group. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_FrmReplicAddMember
parameter_list|(
name|t_Handle
name|h_FrmReplicGroup
parameter_list|,
name|uint16_t
name|memberIndex
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_MemberParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FrmReplicRemoveMember   @Description   Remove the member defined by the index from the relevant group.   @Param[in]     h_FrmReplicGroup   A handle to the frame replicator group.  @Param[in]     memberIndex        member index for removing.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_FrmReplicSetGroup() of this group. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_FrmReplicRemoveMember
parameter_list|(
name|t_Handle
name|h_FrmReplicGroup
parameter_list|,
name|uint16_t
name|memberIndex
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_StatisticsSetNode   @Description   This routine should be called for defining a statistics node.   @Param[in]     h_FmPcd             FM PCD module descriptor.  @Param[in]     p_FmPcdstatsParams  A structure of parameters defining the statistics   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_StatisticsSetNode
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdStatsParams
modifier|*
name|p_FmPcdstatsParams
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_Runtime_build_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_Runtime_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_grp group */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCSW_BACKWARD_COMPATIBLE_API
end_ifdef

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_INTERCHANGABLE_HDRS
value|FM_PCD_MAX_NUM_OF_INTERCHANGEABLE_HDRS
end_define

begin_define
define|#
directive|define
name|e_FM_PCD_MANIP_ONE_WAYS_HASH
value|e_FM_PCD_MANIP_ONE_WAY_HASH
end_define

begin_define
define|#
directive|define
name|e_FM_PCD_MANIP_TOW_WAYS_HASH
value|e_FM_PCD_MANIP_TWO_WAYS_HASH
end_define

begin_define
define|#
directive|define
name|e_FM_PCD_MANIP_FRAGMENT_PACKECT
value|e_FM_PCD_MANIP_FRAGMENT_PACKET
end_define

begin_comment
comment|/* Feb13 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_SetNetEnvCharacteristics
parameter_list|(
name|_pcd
parameter_list|,
name|_params
parameter_list|)
define|\
value|FM_PCD_NetEnvCharacteristicsSet(_pcd, _params)
end_define

begin_define
define|#
directive|define
name|FM_PCD_KgSetScheme
parameter_list|(
name|_pcd
parameter_list|,
name|_params
parameter_list|)
value|FM_PCD_KgSchemeSet(_pcd, _params)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcBuildTree
parameter_list|(
name|_pcd
parameter_list|,
name|_params
parameter_list|)
value|FM_PCD_CcRootBuild(_pcd, _params)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcSetNode
parameter_list|(
name|_pcd
parameter_list|,
name|_params
parameter_list|)
value|FM_PCD_MatchTableSet(_pcd, _params)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PlcrSetProfile
parameter_list|(
name|_pcd
parameter_list|,
name|_params
parameter_list|)
value|FM_PCD_PlcrProfileSet(_pcd, _params)
end_define

begin_define
define|#
directive|define
name|FM_PCD_ManipSetNode
parameter_list|(
name|_pcd
parameter_list|,
name|_params
parameter_list|)
value|FM_PCD_ManipNodeSet(_pcd, _params)
end_define

begin_define
define|#
directive|define
name|FM_PCD_DeleteNetEnvCharacteristics
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_NetEnvCharacteristicsDelete(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_KgDeleteScheme
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_KgSchemeDelete(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_KgGetSchemeCounter
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_KgSchemeGetCounter(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_KgSetSchemeCounter
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_KgSchemeSetCounter(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PlcrDeleteProfile
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_PlcrProfileDelete(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PlcrGetProfileCounter
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_PlcrProfileGetCounter(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PlcrSetProfileCounter
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_PlcrProfileSetCounter(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcDeleteTree
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_CcRootDelete(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcTreeModifyNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_CcRootModifyNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcDeleteNode
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableDelete(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeModifyMissNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableModifyMissNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeRemoveKey
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableRemoveKey(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeAddKey
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableAddKey(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeModifyNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableModifyNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeModifyKeyAndNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableModifyKeyAndNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeModifyKey
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableModifyKey(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeFindNRemoveKey
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableFindNRemoveKey(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeFindNModifyNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableFindNModifyNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeFindNModifyKeyAndNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableFindNModifyKeyAndNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeFindNModifyKey
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableFindNModifyKey(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcIndexedHashNodeGetBucket
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableGetIndexedHashBucket(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeGetNextEngine
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableGetNextEngine(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_CcNodeGetKeyCounter
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_MatchTableGetKeyCounter(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FM_PCD_ManipDeleteNode
parameter_list|(
name|_pcd
parameter_list|,
modifier|...
parameter_list|)
define|\
value|FM_PCD_ManipNodeDelete(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCSW_BACKWARD_COMPATIBLE_API */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_PCD_EXT */
end_comment

end_unit

