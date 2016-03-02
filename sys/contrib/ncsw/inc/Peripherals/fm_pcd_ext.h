begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_pcd_ext.h   @Description   FM PCD ... */
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Group         FM_grp Frame Manager API   @Description   FM API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_grp FM PCD   @Description   FM PCD API functions, definitions and enums                  The FM PCD module is responsible for the initialization of all                 global classifying FM modules. This includes the parser general and                 common registers, the key generator global and common registers,                 and the Policer global and common registers.                 In addition, the FM PCD SW module will initialize all required                 key generator schemes, coarse classification flows, and Policer                 profiles. When An FM module is configured to work with one of these                 entities, it will register to it using the FM PORT API. The PCD                 module will manage the PCD resources - i.e. resource management of                 Keygen schemes, etc.   @{ */
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

begin_typedef
typedef|typedef
name|uint32_t
name|fmPcdEngines_t
typedef|;
end_typedef

begin_comment
comment|/**< options as defined below: */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_NONE
value|0
end_define

begin_comment
comment|/**< No PCD Engine indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS
value|0x80000000
end_define

begin_comment
comment|/**< Parser indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG
value|0x40000000
end_define

begin_comment
comment|/**< Keygen indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_CC
value|0x20000000
end_define

begin_comment
comment|/**< Coarse classification indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR
value|0x10000000
end_define

begin_comment
comment|/**< Policer indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MANIP
value|0x08000000
end_define

begin_comment
comment|/**< Manipulation indicated */
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
comment|/**< number of distinction units is limited by                                                                              register size (32), - reserved bits for                                                                              private headers. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_INTERCHANGEABLE_HDRS
value|4
end_define

begin_comment
comment|/**< Maximum number of interchangeable headers in a distinction unit */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_NUM_OF_GENERIC_REGS
value|8
end_define

begin_comment
comment|/**< Total number of generic KG registers */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_MAX_NUM_OF_EXTRACTS_PER_KEY
value|35
end_define

begin_comment
comment|/**< Max number allowed on any configuration.                                                                              For reason of HW implementation, in most                                                                              cases less than this will be allowed. The                                                                              driver will return error in initialization                                                                              time if resource is overused. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_NUM_OF_EXTRACT_MASKS
value|4
end_define

begin_comment
comment|/**< Total number of masks allowed on KG extractions. */
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
comment|/**< Max number of SW parser label */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_SW_PRS_SIZE
value|0x00000800
end_define

begin_comment
comment|/**< Total size of sw parser area */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS_SW_OFFSET
value|0x00000040
end_define

begin_comment
comment|/**< Size of illegal addresses at the beginning                                                                              of the SW parser area */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS_SW_PATCHES_SIZE
value|0x00000200
end_define

begin_comment
comment|/**< Number of bytes saved for patches */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS_SW_TAIL_SIZE
value|4
end_define

begin_comment
comment|/**< Number of bytes that must be cleared at                                                                              the end of the SW parser area */
end_comment

begin_define
define|#
directive|define
name|FM_SW_PRS_MAX_IMAGE_SIZE
value|(FM_PCD_SW_PRS_SIZE-FM_PCD_PRS_SW_OFFSET-FM_PCD_PRS_SW_TAIL_SIZE-FM_PCD_PRS_SW_PATCHES_SIZE)
end_define

begin_comment
comment|/**< Max possible size of SW parser code */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_MANIP_INSRT_TEMPLATE_SIZE
value|128
end_define

begin_comment
comment|/**< Max possible size of insertion template for                                                                              insert manipulation*/
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_init_grp FM PCD Initialization Unit   @Description   FM PCD Initialization Unit   @{ */
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
comment|/**< Policer counter */
name|e_FM_PCD_PLCR_COUNTERS_YELLOW
block|,
comment|/**< Policer counter */
name|e_FM_PCD_PLCR_COUNTERS_RED
block|,
comment|/**< Policer counter */
name|e_FM_PCD_PLCR_COUNTERS_RECOLORED_TO_RED
block|,
comment|/**< Policer counter */
name|e_FM_PCD_PLCR_COUNTERS_RECOLORED_TO_YELLOW
block|,
comment|/**< Policer counter */
name|e_FM_PCD_PLCR_COUNTERS_TOTAL
block|,
comment|/**< Policer counter */
name|e_FM_PCD_PLCR_COUNTERS_LENGTH_MISMATCH
block|,
comment|/**< Policer counter */
name|e_FM_PCD_PRS_COUNTERS_PARSE_DISPATCH
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_L2_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_L3_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_L4_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_SHIM_PARSE_RESULT_RETURNED
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_L2_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_L3_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_L4_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_SHIM_PARSE_RESULT_RETURNED_WITH_ERR
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_SOFT_PRS_CYCLES
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_SOFT_PRS_STALL_CYCLES
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_HARD_PRS_CYCLE_INCL_STALL_CYCLES
block|,
comment|/**< Parser counter */
name|e_FM_PCD_PRS_COUNTERS_MURAM_READ_CYCLES
block|,
comment|/**< MURAM counter */
name|e_FM_PCD_PRS_COUNTERS_MURAM_READ_STALL_CYCLES
block|,
comment|/**< MURAM counter */
name|e_FM_PCD_PRS_COUNTERS_MURAM_WRITE_CYCLES
block|,
comment|/**< MURAM counter */
name|e_FM_PCD_PRS_COUNTERS_MURAM_WRITE_STALL_CYCLES
block|,
comment|/**< MURAM counter */
name|e_FM_PCD_PRS_COUNTERS_FPM_COMMAND_STALL_CYCLES
comment|/**< FPM counter */
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
comment|/**< Keygen ECC error */
name|e_FM_PCD_PLCR_EXCEPTION_DOUBLE_ECC
block|,
comment|/**< Read Buffer ECC error */
name|e_FM_PCD_KG_EXCEPTION_KEYSIZE_OVERFLOW
block|,
comment|/**< Write Buffer ECC error on system side */
name|e_FM_PCD_PLCR_EXCEPTION_INIT_ENTRY_ERROR
block|,
comment|/**< Write Buffer ECC error on FM side */
name|e_FM_PCD_PLCR_EXCEPTION_PRAM_SELF_INIT_COMPLETE
block|,
comment|/**< Self init complete */
name|e_FM_PCD_PLCR_EXCEPTION_ATOMIC_ACTION_COMPLETE
block|,
comment|/**< Atomic action complete */
name|e_FM_PCD_PRS_EXCEPTION_DOUBLE_ECC
block|,
comment|/**< Parser ECC error */
name|e_FM_PCD_PRS_EXCEPTION_SINGLE_ECC
comment|/**< Parser single ECC */
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
comment|/**  @Description   A callback for enqueuing frame onto a QM queue.   @Param[in]     h_App           - User's application descriptor.  @Param[in]     p_Fd            - Frame descriptor for the frame.   @Return        E_OK on success; Error code otherwise.  */
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
comment|/**  @Description   A structure for Host-Command                 When using Host command for PCD functionalities, a dedicated port                 must be used. If this routine is called for a PCD in a single partition                 environment, or it is the Master partition in a Multi partition                 environment, The port will be initialized by the PCD driver                 initialization routine.  */
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
comment|/**< Host-Command Port Virtual Address of                                                          memory mapped registers.*/
name|uint8_t
name|portId
decl_stmt|;
comment|/**< Host-Command Port Id (0-6 relative                                                          to Host-Command/Offline parsing ports) */
name|uint16_t
name|liodnBase
decl_stmt|;
comment|/**< Irrelevant for P4080 rev 1. LIODN base for this port, to be                                                          used together with LIODN offset. */
name|uint32_t
name|errFqid
decl_stmt|;
comment|/**< Host-Command Port Error Queue Id. */
name|uint32_t
name|confFqid
decl_stmt|;
comment|/**< Host-Command Port Confirmation queue Id. */
name|uint32_t
name|qmChannel
decl_stmt|;
comment|/**< Host-Command port - QM-channel dedicated to                                                          this port will be used by the FM for dequeue. */
name|t_FmPcdQmEnqueueCallback
modifier|*
name|f_QmEnqueue
decl_stmt|;
comment|/**< Call back routine for enqueuing a frame to the QM */
name|t_Handle
name|h_QmArg
decl_stmt|;
comment|/**< A handle of the QM module */
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
comment|/**< TRUE if Parser will be used for any                                                              of the FM ports */
name|bool
name|ccSupport
decl_stmt|;
comment|/**< TRUE if Coarse Classification will be used for any                                                              of the FM ports */
name|bool
name|kgSupport
decl_stmt|;
comment|/**< TRUE if Keygen will be used for any                                                              of the FM ports */
name|bool
name|plcrSupport
decl_stmt|;
comment|/**< TRUE if Policer will be used for any                                                              of the FM ports */
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< A handle to the FM module */
name|uint8_t
name|numOfSchemes
decl_stmt|;
comment|/**< Number of schemes dedicated to this partition. */
name|bool
name|useHostCommand
decl_stmt|;
comment|/**< Optional for single partition, Mandatory for Multi partition */
name|t_FmPcdHcParams
name|hc
decl_stmt|;
comment|/**< Relevant only if useHostCommand=TRUE.                                                              Host Command parameters. */
name|t_FmPcdExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Relevant for master (or single) partition only: Callback routine                                                              to be called of PCD exception */
name|t_FmPcdIdExceptionCallback
modifier|*
name|f_ExceptionId
decl_stmt|;
comment|/**< Relevant for master (or single) partition only: Callback routine                                                              to be used for a single scheme and                                                              profile exceptions */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< Relevant for master (or single) partition only: A handle to an                                                              application layer object; This handle will                                                              be passed by the driver upon calling the above callbacks */
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
comment|/**  @Group         FM_PCD_advanced_init_grp    FM PCD Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ConfigPlcrNumOfSharedProfiles   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement.                 [4].   @Param[in]     h_FmPcd                     FM PCD module descriptor.  @Param[in]     numOfSharedPlcrProfiles     Number of profiles to                                             be shared between ports on this partition   @Return        E_OK on success; Error code otherwise. */
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
comment|/**  @Function      FM_PCD_ConfigException   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement.                 By default all exceptions are enabled.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_ConfigPlcrAutoRefreshMode   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement.                 By default autorefresh is enabled.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     enable          TRUE to enable, FALSE to disable   @Return        E_OK on success; Error code otherwise.   @Cautions      Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_ConfigPrsMaxCycleLimit   @Description   Calling this routine changes the internal data structure for                 the maximum parsing time from its default value                 [0].   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     value           0 to disable the mechanism, or new                                 maximum parsing time.   @Return        E_OK on success; Error code otherwise.   @Cautions      Not available for guest partition. */
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
comment|/* end of FM_PCD_advanced_init_grp group */
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
comment|/**  @Group         FM_PCD_Runtime_grp FM PCD Runtime Unit   @Description   FM PCD Runtime Unit                  The runtime control allows creation of PCD infrastructure modules                 such as Network Environment Characteristics, Classification Plan                 Groups and Coarse Classification Trees.                 It also allows on-the-fly initialization, modification and removal                 of PCD modules such as Keygen schemes, coarse classification nodes                 and Policer profiles.                   In order to explain the programming model of the PCD driver interface                 a few terms should be explained, and will be used below.                   * Distinction Header - One of the 16 protocols supported by the FM parser,                     or one of the shim headers (1 or 2). May be a header with a special                     option (see below).                   * Interchangeable Headers Group- This is a group of Headers recognized                     by either one of them. For example, if in a specific context the user                     chooses to treat IPv4 and IPV6 in the same way, they may create an                     interchangeable Headers Unit consisting of these 2 headers.                   * A Distinction Unit - a Distinction Header or an Interchangeable Headers                     Group.                   * Header with special option - applies to ethernet, mpls, vlan, ipv4 and                     ipv6, includes multicast, broadcast and other protocol specific options.                     In terms of hardware it relates to the options available in the classification                     plan.                   * Network Environment Characteristics - a set of Distinction Units that define                     the total recognizable header selection for a certain environment. This is                     NOT the list of all headers that will ever appear in a flow, but rather                     everything that needs distinction in a flow, where distinction is made by keygen                     schemes and coarse classification action descriptors.                  The PCD runtime modules initialization is done in stages. The first stage after                 initializing the PCD module itself is to establish a Network Flows Environment                 Definition. The application may choose to establish one or more such environments.                 Later, when needed, the application will have to state, for some of its modules,                 to which single environment it belongs.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for sw parser labels  */
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
comment|/**< The existance of this header will envoke                                                                  the sw parser code. */
name|uint8_t
name|indexPerHdr
decl_stmt|;
comment|/**< Normally 0, if more than one sw parser                                                                  attachments for the same header, use this                                                                  index to distinguish between them. */
block|}
name|t_FmPcdPrsLabelParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for sw parser  */
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
comment|/** @Function      FM_PCD_PrsLoadSw  @Description   This routine may be called in order to load software parsing code.   @Param[in]     h_FmPcd         FM PCD module descriptor. @Param[in]     p_SwPrs         A pointer to a structure of software                                parser parameters, including the software                                parser image.  @Return        E_OK on success; Error code otherwise.  @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled.                Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_KgSetDfltValue   @Description   Calling this routine sets a global default value to be used                 by the keygen when parser does not recognize a required                 field/header.                 By default default values are 0.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     valueId         0,1 - one of 2 global default values.  @Param[in]     value           The requested default value.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled.                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_KgSetAdditionalDataAfterParsing   @Description   Calling this routine allows the keygen to access data past                 the parser finishing point.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     payloadOffset   the number of bytes beyond the parser location.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init() and when PCD is disabled.                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_SetException   @Description   Calling this routine enables/disables PCD interrupts.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_ModifyCounter   @Description   Sets a value to an enabled counter. Use "0" to reset the counter.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     counter     The requested counter.  @Param[in]     value       The requested value to be written into the counter.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_SetPlcrStatistics   @Description   This routine may be used to enable/disable policer statistics                 counter. By default the statistics is enabled.   @Param[in]     h_FmPcd         FM PCD module descriptor  @Param[in]     enable          TRUE to enable, FALSE to disable.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init().                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_SetPrsStatistics   @Description   Defines whether to gather parser statistics including all ports.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     enable      TRUE to enable, FALSE to disable.   @Return        None   @Cautions      Allowed only following FM_PCD_Init().                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_ForceIntr   @Description   Causes an interrupt event on the requested source.   @Param[in]     h_FmPcd     FM PCD module descriptor.  @Param[in]     exception       An exception to be forced.   @Return        E_OK on success; Error code if the exception is not enabled,                 or is not able to create interrupt.   @Cautions      Allowed only following FM_PCD_Init().                 Not available for guest partition. */
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
comment|/**  @Function      FM_PCD_DumpRegs   @Description   Dumps all PCD registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
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
comment|/**  @Function      FM_PCD_KgDumpRegs   @Description   Dumps all PCD KG registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
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
comment|/**  @Function      FM_PCD_PlcrDumpRegs   @Description   Dumps all PCD Plcr registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
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
comment|/**  @Function      FM_PCD_PlcrProfileDumpRegs   @Description   Dumps all PCD Plcr registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_Profile       A handle to a profile.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrProfileDumpRegs
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PrsDumpRegs   @Description   Dumps all PCD Prs registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
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
comment|/**  @Function      FM_PCD_HcDumpRegs   @Description   Dumps HC Port registers   @Param[in]     h_FmPcd         A handle to an FM PCD Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
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
comment|/**  @Group         FM_PCD_Runtime_tree_buildgrp FM PCD Tree building Unit   @Description   FM PCD Runtime Unit                  This group contains routines for setting, deleting and modifying                 PCD resources, for defining the total PCD tree.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    Definitions of coarse classification                 parameters as required by keygen (when coarse classification                 is the next engine after this scheme). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_NODES
value|255
end_define

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
name|FM_PCD_MAX_SIZE_OF_KEY
value|56
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_CC_ENTRIES_IN_GRP
value|16
end_define

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
comment|/**< Vlan protocol options. */
end_comment

begin_define
define|#
directive|define
name|VLAN_STACKED
value|0x20000000
end_define

begin_comment
comment|/**< Vlan Stacked. */
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
comment|/**< MPLS Stacked. */
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
comment|/**< Invalid PCD engine indicated*/
name|e_FM_PCD_DONE
block|,
comment|/**< No PCD Engine indicated */
name|e_FM_PCD_KG
block|,
comment|/**< Keygen indicated */
name|e_FM_PCD_CC
block|,
comment|/**< Coarse classification indicated */
name|e_FM_PCD_PLCR
block|,
comment|/**< Policer indicated */
name|e_FM_PCD_PRS
comment|/**< Parser indicated */
block|}
name|e_FmPcdEngine
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting extraction by header types */
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
comment|/**  @Description   An enum for selecting extraction source                 (when it is not the header) */
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
comment|/**< KG only: Extract from the point where parsing had finished */
name|e_FM_PCD_EXTRACT_FROM_KEY
block|,
comment|/**< CC only: Field where saved KEY */
name|e_FM_PCD_EXTRACT_FROM_HASH
block|,
comment|/**< CC only: Field where saved HASH */
name|e_FM_PCD_EXTRACT_FROM_PARSE_RESULT
block|,
comment|/**< KG& CC: Extract from the parser result */
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
comment|/**  @Description   An enum for selecting extraction type */
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
comment|/**  @Description   An enum for selecting a default */
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
comment|/**  @Description   An enum defining all default groups -                 each group shares a default value, one of 4 user                 initialized values. */
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
comment|/**< IP addr */
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
comment|/**< grouping implemented by sw,                                              any data extraction that is not the full                                              field described above  */
name|e_FM_PCD_KG_GENERIC_FROM_DATA_NO_V
block|,
comment|/**< grouping implemented by sw,                                              any data extraction without validation */
name|e_FM_PCD_KG_GENERIC_NOT_FROM_DATA
comment|/**< grouping implemented by sw,                                              extraction from parser result or                                              direct use of default value  */
block|}
name|e_FmPcdKgKnownFieldsDfltTypes
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining header index when headers may repeat */
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
comment|/**  @Description   A structure for selcting the policer profile functional type */
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
comment|/**  @Description   A structure for selcting the policer profile algorithem */
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
comment|/**< Policer algorythm RFC 2698 */
name|e_FM_PCD_PLCR_RFC_4115
comment|/**< Policer algorythm RFC 4115 */
block|}
name|e_FmPcdPlcrAlgorithmSelection
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for selcting the policer profile color mode */
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
comment|/**  @Description   A structure for selcting the policer profile color functional mode */
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
comment|/**< Green */
name|e_FM_PCD_PLCR_YELLOW
block|,
comment|/**< Yellow */
name|e_FM_PCD_PLCR_RED
block|,
comment|/**< Red */
name|e_FM_PCD_PLCR_OVERRIDE
comment|/**< Color override */
block|}
name|e_FmPcdPlcrColor
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for selcting the policer profile packet frame length selector */
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
comment|/**  @Description   An enum for selecting rollback frame */
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
comment|/**< Rollback L2 frame length */
name|e_FM_PCD_PLCR_ROLLBACK_FULL_FRM_LEN
comment|/**< Rollback Full frame length */
block|}
name|e_FmPcdPlcrRollBackFrameSelect
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for selcting the policer profile packet or byte mode */
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
comment|/**  @Description   An enum for defining action of frame */
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
comment|/**< Drop frame */
block|}
name|e_FmPcdDoneAction
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for selecting the policer counter */
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
comment|/**  @Description   A structure for selecting action */
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
comment|/**< Exact match on the selected extraction*/
name|e_FM_PCD_ACTION_INDEXED_LOOKUP
comment|/**< Indexed lookup on the selected extraction*/
block|}
name|e_FmPcdAction
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting type of insert manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipInsrtType
block|{
name|e_FM_PCD_MANIP_INSRT_NONE
init|=
literal|0
block|,
comment|/**< No insertion */
name|e_FM_PCD_MANIP_INSRT_TO_START_OF_FRAME_INT_FRAME_HDR
block|,
comment|/**< Insert internal frame header to start of frame */
name|e_FM_PCD_MANIP_INSRT_TO_START_OF_FRAME_TEMPLATE
comment|/**< Insert template to start of frame*/
block|}
name|e_FmPcdManipInsrtType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting type of remove manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipRmvParamsType
block|{
name|e_FM_PCD_MANIP_RMV_NONE
init|=
literal|0
block|,
comment|/**< No remove */
name|e_FM_PCD_MANIP_RMV_FROM_START_OF_FRAME_TILL_SPECIFIC_LOCATION
block|,
comment|/**< Remove from start of frame till (excluding) specified indication */
name|e_FM_PCD_MANIP_RMV_FROM_START_OF_FRAME_INCLUDE_SPECIFIC_LOCATION
block|,
comment|/**< Remove from start of frame till (including) specified indication */
name|e_FM_PCD_MANIP_RMV_INT_FRAME_HDR
comment|/**< Remove internal frame header to start of frame */
block|}
name|e_FmPcdManipRmvParamsType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting type of location */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmPcdManipLocateType
block|{
name|e_FM_PCD_MANIP_LOC_BY_HDR
init|=
literal|0
block|,
comment|/**< Locate according to header */
name|e_FM_PCD_MANIP_LOC_NON_HDR
comment|/**< Locate from data that is not the header */
block|}
name|e_FmPcdManipLocateType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting type of Timeout mode */
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
comment|/**< limits the time of the reassm process from the first frag to the last */
name|e_FM_PCD_MANIP_TIME_OUT_BETWEEN_FRAG
comment|/**< limits the time of receiving the fragment */
block|}
name|e_FmPcdManipReassemTimeOutMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting type of WaysNumber mode */
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
comment|/**< -------------- */
name|e_FM_PCD_MANIP_TWO_WAYS_HASH
block|,
comment|/**< -------------- */
name|e_FM_PCD_MANIP_THREE_WAYS_HASH
block|,
comment|/**< -------------- */
name|e_FM_PCD_MANIP_FOUR_WAYS_HASH
block|,
comment|/**< four ways hash */
name|e_FM_PCD_MANIP_FIVE_WAYS_HASH
block|,
comment|/**< -------------- */
name|e_FM_PCD_MANIP_SIX_WAYS_HASH
block|,
comment|/**< -------------- */
name|e_FM_PCD_MANIP_SEVEN_WAYS_HASH
block|,
comment|/**< -------------- */
name|e_FM_PCD_MANIP_EIGHT_WAYS_HASH
comment|/**< eight ways hash*/
block|}
name|e_FmPcdManipReassemWaysNumber
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   An enum for selecting type of statistics mode */
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
comment|/**< type where flowId used as index for getting statistics */
block|}
name|e_FmPcdStatsType
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_CAPWAP_SUPPORT */
end_comment

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
comment|/**< Vlan options */
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
block|}
name|u_FmPcdHdrProtocolOpt
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A union holding all known protocol fields */
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
comment|/**< eth      */
name|headerFieldVlan_t
name|vlan
decl_stmt|;
comment|/**< vlan     */
name|headerFieldLlcSnap_t
name|llcSnap
decl_stmt|;
comment|/**< llcSnap  */
name|headerFieldPppoe_t
name|pppoe
decl_stmt|;
comment|/**< pppoe    */
name|headerFieldMpls_t
name|mpls
decl_stmt|;
comment|/**< mpls     */
name|headerFieldIpv4_t
name|ipv4
decl_stmt|;
comment|/**< ipv4     */
name|headerFieldIpv6_t
name|ipv6
decl_stmt|;
comment|/**< ipv6     */
name|headerFieldUdp_t
name|udp
decl_stmt|;
comment|/**< udp      */
name|headerFieldTcp_t
name|tcp
decl_stmt|;
comment|/**< tcp      */
name|headerFieldSctp_t
name|sctp
decl_stmt|;
comment|/**< sctp     */
name|headerFieldDccp_t
name|dccp
decl_stmt|;
comment|/**< dccp     */
name|headerFieldGre_t
name|gre
decl_stmt|;
comment|/**< gre      */
name|headerFieldMinencap_t
name|minencap
decl_stmt|;
comment|/**< minencap */
name|headerFieldIpsecAh_t
name|ipsecAh
decl_stmt|;
comment|/**< ipsecAh  */
name|headerFieldIpsecEsp_t
name|ipsecEsp
decl_stmt|;
comment|/**< ipsecEsp */
name|headerFieldUdpEncapEsp_t
name|udpEncapEsp
decl_stmt|;
comment|/**< udpEncapEsp */
block|}
name|t_FmPcdFields
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining header extraction for key generation */
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
comment|/**  @Description   structure for defining field extraction for key generation */
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
comment|/**  @Description   A structure of parameters used to define a single network                 environment unit.                 A unit should be defined if it will later be used by one or                 more PCD engines to distinguich between flows. */
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
comment|/**< only one option !! */
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
comment|/**  @Description   A structure of parameters used to define the different                 units supported by a specific PCD Network Environment                 Characteristics module. Each unit represent                 a protocol or a group of protocols that may be used later                 by the different PCD engined to distinguich between flows. */
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
comment|/**  @Description   structure for defining a single extraction action                 when creating a key */
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
comment|/**< Relevant only for MPLS, VLAN and tunneled                                                              IP. Otherwise should be cleared.*/
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
comment|/**< Extract bytes from field parameters*/
name|t_FmPcdFields
name|fullField
decl_stmt|;
comment|/**< Extract full filed parameters*/
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
comment|/**< Relevant only for CC where                                                              action=e_FM_PCD_ACTION_INDEXED_LOOKUP */
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
comment|/**  @Description   A structure for defining masks for each extracted                 field in the key. */
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
comment|/**  @Description   A structure for defining default selection per groups                 of fields */
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
comment|/**< Default type select*/
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
comment|/**  @Description   A structure for defining all parameters needed for                 generation a key and using a hash function */
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
comment|/**  @Description   A structure of parameters for defining a single                 Fqid mask (extracted OR). */
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
comment|/**  @Description   A structure for configuring scheme counter */
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
comment|/**  @Description   A structure for defining policer profile                 parameters as required by keygen (when policer                 is the next engine after this scheme). */
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
comment|/**< TRUE if this profile is shared between ports                                                          (i.e. managed by master partition) May not be TRUE                                                          if profile is after Coarse Classification*/
name|bool
name|direct
decl_stmt|;
comment|/**< if TRUE, directRelativeProfileId only selects the profile                                                          id, if FALSE fqidOffsetRelativeProfileIdBase is used                                                          together with fqidOffsetShift and numOfProfiles                                                          parameters, to define a range of profiles from                                                          which the keygen result will determine the                                                          destination policer profile.  */
union|union
block|{
name|uint16_t
name|directRelativeProfileId
decl_stmt|;
comment|/**< Used if 'direct' is TRUE, to select policer profile.                                                          This parameter should                                                          indicate the policer profile offset within the port's                                                          policer profiles or SHARED window. */
struct|struct
block|{
name|uint8_t
name|fqidOffsetShift
decl_stmt|;
comment|/**< shift of KG results without the qid base */
name|uint8_t
name|fqidOffsetRelativeProfileIdBase
decl_stmt|;
comment|/**< OR of KG results without the qid base                                                          This parameter should indicate the policer profile                                                          offset within the port's policer profiles window or                                                          SHARED window depends on sharedProfile */
name|uint8_t
name|numOfProfiles
decl_stmt|;
comment|/**< Range of profiles starting at base */
block|}
name|indirectProfile
struct|;
block|}
name|profileSelect
union|;
block|}
name|t_FmPcdKgPlcrProfile
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for CC parameters if CC is the next engine after KG */
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
comment|/**< TRUE if after CC, in case of data frame,                                                      policing is required. */
name|bool
name|bypassPlcrProfileGeneration
decl_stmt|;
comment|/**< TRUE to bypass keygen policer profile                                                      generation (profile selected is the one selected at                                                      port initialization). */
name|t_FmPcdKgPlcrProfile
name|plcrProfile
decl_stmt|;
comment|/**< only if plcrNext=TRUE and bypassPlcrProfileGeneration=FALSE */
block|}
name|t_FmPcdKgCc
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for initializing a keygen single scheme */
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
comment|/**< This scheme is reached only directly, i.e.                                                              no need for match vector. Keygen will ignore                                                                      it when matching   */
struct|struct
block|{
comment|/**< HL Relevant only if alwaysDirect = FALSE */
name|t_Handle
name|h_NetEnv
decl_stmt|;
comment|/**< A handle to the Network environment as returned                                                                      by FM_PCD_SetNetEnvCharacteristics() */
name|uint8_t
name|numOfDistinctionUnits
decl_stmt|;
comment|/**< Number of netenv units listed in unitIds array */
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
comment|/**< use the KG Hash functionality  */
name|t_FmPcdKgKeyExtractAndHashParams
name|keyExtractAndHashParams
decl_stmt|;
comment|/**< used only if useHash = TRUE */
name|bool
name|bypassFqidGeneration
decl_stmt|;
comment|/**< Normally - FALSE, TRUE to avoid FQID update in the IC;                                                                      In such a case FQID after KG will be the default FQID                                                                      defined for the relevant port, or the FQID defined by CC                                                                      in cases where CC was the previous engine. */
name|uint32_t
name|baseFqid
decl_stmt|;
comment|/**< Base FQID; Relevant only if bypassFqidGeneration = FALSE;                                                                      If hash is used and an even distribution is expected                                                                      according to hashDistributionNumOfFqids, baseFqid must be aligned to                                                                      hashDistributionNumOfFqids.  */
name|uint8_t
name|numOfUsedExtractedOrs
decl_stmt|;
comment|/**< Number of Fqid masks listed in extractedOrs array*/
name|t_FmPcdKgExtractedOrParams
name|extractedOrs
index|[
name|FM_PCD_KG_NUM_OF_GENERIC_REGS
index|]
decl_stmt|;
comment|/**< IN: FM_PCD_KG_NUM_OF_GENERIC_REGS                                                                      registers are shared between qidMasks                                                                      functionality and some of the extraction                                                                      actions; Normally only some will be used                                                                      for qidMask. Driver will return error if                                                                      resource is full at initialization time. */
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
comment|/**  @Description   A structure for defining CC params when CC is the                 next engine after a CC node. */
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining PLCR params when PLCR is the                 next engine after a CC node. */
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
comment|/**< Relevant only if overrideParams=TRUE:                                              (otherwise profile id is taken from keygen);                                              This parameter should indicate the policer                                              profile offset within the port's                                              policer profiles or from SHARED window.*/
name|uint32_t
name|newFqid
decl_stmt|;
comment|/**< Relevant only if overrideParams=TRUE:                                              FQID for enqueuing the frame;                                              In earlier chips  if policer next engine is KEYGEN,                                              this parameter can be 0, because the KEYGEN                                              always decides the enqueue FQID.*/
name|bool
name|statisticsEn
decl_stmt|;
comment|/**< In the case of TRUE Statistic counter is                                              incremented for each received frame passed through                                              this Coarse Classification entry.*/
block|}
name|t_FmPcdCcNextPlcrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining enqueue params when BMI is the                 next engine after a CC node. */
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
comment|/**< TRUE if CC override previously decided Fqid(by Keygen),                                              relevant if action = e_FM_PCD_ENQ_FRAME */
name|uint32_t
name|newFqid
decl_stmt|;
comment|/**< Valid if overrideFqid=TRUE, FQID for enqueuing the frame                                              (otherwise FQID is taken from keygen),                                              relevant if action = e_FM_PCD_ENQ_FRAME*/
name|bool
name|statisticsEn
decl_stmt|;
comment|/**< In the case of TRUE Statistic counter is                                              incremented for each received frame passed through                                              this Coarse Classification entry.*/
block|}
name|t_FmPcdCcNextEnqueueParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining KG params when KG is the                 next engine after a CC node. */
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
comment|/**< TRUE if CC override previously decided Fqid (by keygen),                                              Note - this parameters irrelevant for earlier chips*/
name|uint32_t
name|newFqid
decl_stmt|;
comment|/**< Valid if overrideFqid=TRUE, FQID for enqueuing the frame                                              (otherwise FQID is taken from keygen),                                              Note - this parameters irrelevant for earlier chips*/
name|t_Handle
name|h_DirectScheme
decl_stmt|;
comment|/**< Direct scheme handle to go to. */
name|bool
name|statisticsEn
decl_stmt|;
comment|/**< In the case of TRUE Statistic counter is                                              incremented for each received frame passed through                                              this Coarse Classification entry.*/
block|}
name|t_FmPcdCcNextKgParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining next engine params after a CC node. */
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
comment|/**< User has to initialize parameters                                                             according to nextEngine definition */
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
block|}
name|params
union|;
if|#
directive|if
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
name|t_Handle
name|h_Manip
decl_stmt|;
comment|/**< Handler to headerManip.                                                             Relevant if next engine of the type result                                                             (e_FM_PCD_PLCR, e_FM_PCD_KG, e_FM_PCD_DONE) */
endif|#
directive|endif
comment|/* defined(FM_CAPWAP_SUPPORT) || ... */
block|}
name|t_FmPcdCcNextEngineParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining a single CC Key parameters */
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
comment|/**< pointer to the key of the size defined in keySize*/
name|uint8_t
modifier|*
name|p_Mask
decl_stmt|;
comment|/**< pointer to the Mask per key  of the size defined                                                  in keySize. p_Key and p_Mask (if defined) has to be                                                  of the same size defined in the keySize */
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
comment|/**  @Description   A structure for defining CC Keys parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_KeysParams
block|{
name|uint8_t
name|numOfKeys
decl_stmt|;
comment|/**< Number Of relevant Keys  */
name|uint8_t
name|keySize
decl_stmt|;
comment|/**< size of the key - in the case of the extraction of                                                      the type FULL_FIELD keySize has to be as standard size of the relevant                                                      key. In the another type of extraction keySize has to be as size of extraction.                                                      In the case of action = e_FM_PCD_ACTION_INDEXED_LOOKUP the size of keySize has to be 2*/
name|t_FmPcdCcKeyParams
name|keyParams
index|[
name|FM_PCD_MAX_NUM_OF_KEYS
index|]
decl_stmt|;
comment|/**< it's array with numOfKeys entries each entry in                                                      the array of the type t_FmPcdCcKeyParams */
name|t_FmPcdCcNextEngineParams
name|ccNextEngineParamsForMiss
decl_stmt|;
comment|/**< parameters for the next step of                                                      unfound (or undefined) key . Not relevant in the case                                                      of action = e_FM_PCD_ACTION_INDEXED_LOOKUP*/
block|}
name|t_KeysParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining the CC node params */
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
comment|/**< params which defines extraction parameters */
name|t_KeysParams
name|keysParams
decl_stmt|;
comment|/**< params which defines Keys parameters of the                                                          extraction defined in extractCcParams */
block|}
name|t_FmPcdCcNodeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining each CC tree group in term of                 NetEnv units and the action to be taken in each case.                 the unitIds list must be in order from lower to higher indexes.                  t_FmPcdCcNextEngineParams is a list of 2^numOfDistinctionUnits                 structures where each defines the next action to be taken for                 each units combination. for example:                 numOfDistinctionUnits = 2                 unitIds = {1,3}                 p_NextEnginePerEntriesInGrp[0] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - not found; unit 3 - not found;                 p_NextEnginePerEntriesInGrp[1] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - not found; unit 3 - found;                 p_NextEnginePerEntriesInGrp[2] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - found; unit 3 - not found;                 p_NextEnginePerEntriesInGrp[3] = t_FmPcdCcNextEngineParams for the case that                                                         unit 1 - found; unit 3 - found; */
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
comment|/**< up to 4 */
name|uint8_t
name|unitIds
index|[
name|FM_PCD_MAX_NUM_OF_CC_UNITS
index|]
decl_stmt|;
comment|/**< Indexes of the units as defined in                                                                      FM_PCD_SetNetEnvCharacteristics() */
name|t_FmPcdCcNextEngineParams
name|nextEnginePerEntriesInGrp
index|[
name|FM_PCD_MAX_NUM_OF_CC_ENTRIES_IN_GRP
index|]
decl_stmt|;
comment|/**< Max size is 16 - if only one group used */
block|}
name|t_FmPcdCcGrpParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining the CC tree groups */
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
comment|/**< A handle to the Network environment as returned                                                                              by FM_PCD_SetNetEnvCharacteristics() */
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
comment|/**  @Description   A structure for defining parameters for byte rate */
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
comment|/**  @Description   A structure for selcting the policer profile RFC-2698 or                 RFC-4115 parameters */
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
comment|/**< Byte / Packet */
name|t_FmPcdPlcrByteRateModeParams
name|byteModeParams
decl_stmt|;
comment|/**< Valid for Byte NULL for Packet */
name|uint32_t
name|comittedInfoRate
decl_stmt|;
comment|/**< KBits/Sec or Packets/Sec */
name|uint32_t
name|comittedBurstSize
decl_stmt|;
comment|/**< Bytes/Packets */
name|uint32_t
name|peakOrAccessiveInfoRate
decl_stmt|;
comment|/**< KBits/Sec or Packets/Sec */
name|uint32_t
name|peakOrAccessiveBurstSize
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
comment|/**  @Description   A union for defining Policer next engine parameters */
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
comment|/**< Policer profile handle -  used when next engine                                                                  is PLCR, must be a SHARED profile */
name|t_Handle
name|h_DirectScheme
decl_stmt|;
comment|/**< Direct scheme select - when next engine is Keygen */
block|}
name|u_FmPcdPlcrNextEngineParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for selecting the policer profile entry parameters */
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
comment|/**< use it when modify=FALSE */
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
comment|/**< For Color-Blind Pass-Through mode. the policer will re-color                                                                          any incoming packet with the default value. */
name|e_FmPcdPlcrColor
name|override
decl_stmt|;
comment|/**< For Color-Aware modes. The profile response to a                                                                          pre-color value of 2'b11. */
block|}
name|color
union|;
name|t_FmPcdPlcrNonPassthroughAlgParams
name|nonPassthroughAlgParams
decl_stmt|;
comment|/**< RFC2698 or RFC4115 params */
name|e_FmPcdEngine
name|nextEngineOnGreen
decl_stmt|;
comment|/**< Green next engine type */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnGreen
decl_stmt|;
comment|/**< Green next engine params */
name|e_FmPcdEngine
name|nextEngineOnYellow
decl_stmt|;
comment|/**< Yellow next engine type */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnYellow
decl_stmt|;
comment|/**< Yellow next engine params */
name|e_FmPcdEngine
name|nextEngineOnRed
decl_stmt|;
comment|/**< Red next engine type */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnRed
decl_stmt|;
comment|/**< Red next engine params */
name|bool
name|trapProfileOnFlowA
decl_stmt|;
comment|/**< Trap on flow A */
name|bool
name|trapProfileOnFlowB
decl_stmt|;
comment|/**< Trap on flow B */
name|bool
name|trapProfileOnFlowC
decl_stmt|;
comment|/**< Trap on flow C */
block|}
name|t_FmPcdPlcrProfileParams
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for selecting the location of manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipLocationParams
block|{
name|e_FmPcdManipLocateType
name|type
decl_stmt|;
comment|/**< location of manipulation type select */
struct|struct
block|{
comment|/**< used when type = e_FM_PCD_MANIP_BY_HDR */
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
name|e_FmPcdHdrIndex
name|hdrIndex
decl_stmt|;
comment|/**< Relevant only for MPLS, VLAN and tunneled                                                              IP. Otherwise should be cleared. */
name|bool
name|byField
decl_stmt|;
comment|/**< TRUE if the location of manipulation is according to some field in the specific header*/
name|t_FmPcdFields
name|fullField
decl_stmt|;
comment|/**< Relevant only when byField = TRUE: Extract field */
block|}
name|manipByHdr
struct|;
block|}
name|t_FmPcdManipLocationParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining insert manipulation                 of the type e_FM_PCD_MANIP_INSRT_TO_START_OF_FRAME_TEMPLATE */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipInsrtByTemplateParams
block|{
name|uint8_t
name|size
decl_stmt|;
comment|/**< size of insert template to the start of the frame. */
name|uint8_t
name|hdrTemplate
index|[
name|FM_PCD_MAX_MANIP_INSRT_TEMPLATE_SIZE
index|]
decl_stmt|;
comment|/**< array of the insertion template. */
name|bool
name|modifyOuterIp
decl_stmt|;
comment|/**< TRUE if user want to modify some fields in outer IP. */
struct|struct
block|{
name|uint16_t
name|ipOuterOffset
decl_stmt|;
comment|/**< offset of outer IP in the insert template, relevant if modifyOuterIp = TRUE.*/
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
comment|/**< offset in the insert template of UDP, relevant if modifyOuterIp = TRUE and udpPresent=TRUE.*/
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
comment|/**< The CAAM block-size; Used by FMan-CTRL to calculate the IP-total-len field.*/
name|uint8_t
name|extraBytesAddedAlignedToBlockSize
decl_stmt|;
comment|/**< Used by FMan-CTRL to calculate the IP-total-len field and UDP length*/
name|uint8_t
name|extraBytesAddedNotAlignedToBlockSize
decl_stmt|;
comment|/**< Used by FMan-CTRL to calculate the IP-total-len field and UDP length.*/
block|}
name|recalculateLengthParams
struct|;
comment|/**< recalculate length parameters - relevant if modifyOuterIp = TRUE and recalculateLength = TRUE */
block|}
name|modifyOuterIpParams
struct|;
comment|/**< Outer IP modification parameters - ignored if modifyOuterIp is FALSE */
name|bool
name|modifyOuterVlan
decl_stmt|;
comment|/**< TRUE if user wants to modify vpri field in the outer VLAN header*/
struct|struct
block|{
name|uint8_t
name|vpri
decl_stmt|;
comment|/**< value of vpri, relevant if modifyOuterVlan = TRUE                                                              vpri only 3 bits, it has to be adjusted to the right*/
block|}
name|modifyOuterVlanParams
struct|;
block|}
name|t_FmPcdManipInsrtByTemplateParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FM_CAPWAP_SUPPORT) || ... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FM_CAPWAP_SUPPORT
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining CAPWAP fragmentation */
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
comment|/**  @Description   structure for defining CAPWAP Re-assembly */
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
comment|/**< Number of frames which can be processed by Reassembly in the same time.                                                                  It has to be power of 2.                                                                  In the case numOfFramesPerHashEntry == e_FM_PCD_MANIP_FOUR_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 4 - 512,                                                                  In the case numOfFramesPerHashEntry == e_FM_PCD_MANIP_EIGHT_WAYS_HASH,                                                                  maxNumFramesInProcess has to be in the range of 8 - 2048 */
name|bool
name|haltOnDuplicationFrag
decl_stmt|;
comment|/**< In the case of TRUE, Reassembly process halted due to duplicated fragment,                                                                  and all processed fragments passed for enqueue with error indication.                                                                  In the case of FALSE, only duplicated fragment passed for enqueue with error indication */
name|e_FmPcdManipReassemTimeOutMode
name|timeOutMode
decl_stmt|;
comment|/**< Expiration delay initialized by Reassembly process */
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
comment|/**< Fqid in which time out frames will enqueue during Time Out Process  */
name|uint32_t
name|timeoutRoutineRequestTime
decl_stmt|;
comment|/**< Represents the time interval in microseconds between consecutive                                                                  timeout routine requests It has to be power of 2. */
name|uint32_t
name|timeoutThresholdForReassmProcess
decl_stmt|;
comment|/**< Represents the time interval in microseconds which defines                                                                  if opened frame (at least one fragment was processed but not all the fragments)is found as too old*/
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
decl_stmt|;
comment|/**< Number of frames per hash entry needed for reassembly process */
block|}
name|t_CapwapReassemblyParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_CAPWAP_SUPPORT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining fragmentation/reassembly */
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
name|extBufPoolIndx
decl_stmt|;
comment|/**< Index of the buffer pool ID which was configured for port                                                                  and can be used for manipulation;                                                                  NOTE: This field is relevant only for CAPWAP fragmentation                                                                  and reassembly */
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
union|union
block|{
ifdef|#
directive|ifdef
name|FM_CAPWAP_SUPPORT
name|t_CapwapFragmentationParams
name|capwapFragParams
decl_stmt|;
comment|/**< Structure for CAPWAP fragmentation, relevant if frag = TRUE, hdr = HEADER_TYPE_CAPWAP */
name|t_CapwapReassemblyParams
name|capwapReasmParams
decl_stmt|;
comment|/**< Structure for CAPWAP reassembly, relevant if frag = FALSE, hdr = HEADER_TYPE_CAPWAP */
endif|#
directive|endif
comment|/* FM_CAPWAP_SUPPORT */
block|}
union|;
block|}
name|t_FmPcdManipFragOrReasmParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining insert manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipInsrtParams
block|{
name|e_FmPcdManipInsrtType
name|type
decl_stmt|;
comment|/**< Type of insert manipulation */
union|union
block|{
name|t_FmPcdManipInsrtByTemplateParams
name|insrtByTemplateParams
decl_stmt|;
comment|/**< parameters for insert manipulation, relevant if                                                                  type = e_FM_PCD_MANIP_INSRT_TO_START_OF_FRAME_TEMPLATE */
block|}
union|;
block|}
name|t_FmPcdManipInsrtParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining remove manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipRmvParams
block|{
name|e_FmPcdManipRmvParamsType
name|type
decl_stmt|;
comment|/**< Type of remove manipulation */
name|t_FmPcdManipLocationParams
name|rmvSpecificLocationParams
decl_stmt|;
comment|/**< Specified location of remove manipulation;                                                               This params should be initialized in cases:                                                               - e_FM_PCD_MANIP_RMV_FROM_START_OF_FRAME_TILL_SPECIFIC_LOCATION                                                               - e_FM_PCD_MANIP_RMV_FROM_START_OF_FRAME_INCLUDE_SPECIFIC_LOCATION */
block|}
name|t_FmPcdManipRmvParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for defining manipulation */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdManipParams
block|{
name|bool
name|rmv
decl_stmt|;
comment|/**< TRUE, if defined remove manipulation */
name|t_FmPcdManipRmvParams
name|rmvParams
decl_stmt|;
comment|/**< Parameters for remove manipulation, relevant if rmv = TRUE */
name|bool
name|insrt
decl_stmt|;
comment|/**< TRUE, if defined insert manipulation */
name|t_FmPcdManipInsrtParams
name|insrtParams
decl_stmt|;
comment|/**< Parameters for insert manipulation, relevant if insrt = TRUE */
name|bool
name|fragOrReasm
decl_stmt|;
comment|/**< TRUE, if defined fragmentation/reassembly manipulation */
name|t_FmPcdManipFragOrReasmParams
name|fragOrReasmParams
decl_stmt|;
comment|/**< Parameters for fragmentation/reassembly manipulation, relevant if fragOrReasm = TRUE */
comment|/**< General parameters */
name|bool
name|treatFdStatusFieldsAsErrors
decl_stmt|;
comment|/**< Set to TRUE when the port that is using this manip is chained                                                                          to SEC (i.e. the traffic was forwarded from SEC) */
block|}
name|t_FmPcdManipParams
typedef|;
end_typedef

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
comment|/* defined(FM_CAPWAP_SUPPORT) || ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_SetNetEnvCharacteristics   @Description   Define a set of Network Environment Characteristics.                 When setting an environment it is important to understand its                 application. It is not meant to describe the flows that will run                 on the ports using this environment, but what the user means TO DO                 with the PCD mechanisms in order to parse-classify-distribute those                 frames.                 By specifying a distinction unit, the user means it would use that option                 for distinction between frames at either a keygen scheme keygen or a coarse                 classification action descriptor. Using interchangeable headers to define a                 unit means that the user is indifferent to which of the interchangeable                 headers is present in the frame, and they want the distinction to be based                 on the presence of either one of them.                 Depending on context, there are limitations to the use of environments. A                 port using the PCD functionality is bound to an environment. Some or even                 all ports may share an environment but also an environment per port is                 possible. When initializing a scheme, a classification plan group (see below),                 or a coarse classification tree, one of the initialized environments must be                 stated and related to. When a port is bound to a scheme, a classification                 plan group, or a coarse classification tree, it MUST be bound to the same                 environment.                 The different PCD modules, may relate (for flows definition) ONLY on                 distinction units as defined by their environment. When initializing a                 scheme for example, it may not choose to select IPV4 as a match for                 recognizing flows unless it was defined in the relating environment. In                 fact, to guide the user through the configuration of the PCD, each module's                 characterization in terms of flows is not done using protocol names, but using                 environment indexes.                 In terms of HW implementation, the list of distinction units sets the LCV vectors                 and later used for match vector, classification plan vectors and coarse classification                 indexing.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     p_NetEnvParams  A structure of parameters for the initialization of                                 the network environment.   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_SetNetEnvCharacteristics
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
comment|/**  @Function      FM_PCD_DeleteNetEnvCharacteristics   @Description   Deletes a set of Network Environment Characteristics.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     h_NetEnv        A handle to the Network environment.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_DeleteNetEnvCharacteristics
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_NetEnv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSetScheme   @Description   Initializing or modifying and enabling a scheme for the keygen.                 This routine should be called for adding or modifying a scheme.                 When a scheme needs modifying, the API requires that it will be                 rewritten. In such a case 'modify' should be TRUE. If the                 routine is called for a valid scheme and 'modify' is FALSE,                 it will return error.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in,out] p_Scheme        A structure of parameters for defining the scheme   @Return        A handle to the initialized scheme on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_KgSetScheme
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgSchemeParams
modifier|*
name|p_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgDeleteScheme   @Description   Deleting an initialized scheme.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_Scheme        scheme handle as returned by FM_PCD_KgSetScheme   @Return        E_OK on success; Error code otherwise.  @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgDeleteScheme
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgGetSchemeCounter   @Description   Reads scheme packet counter.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     h_Scheme        scheme handle as returned by FM_PCD_KgSetScheme.   @Return        Counter's current value.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_KgGetSchemeCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_KgSetSchemeCounter   @Description   Writes scheme packet counter.   @Param[in]     h_FmPcd         FM PCD module descriptor.  @Param[in]     h_Scheme        scheme handle as returned by FM_PCD_KgSetScheme.  @Param[in]     value           New scheme counter value - typically '0' for                                 resetting the counter.  @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_KgSetSchemeCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
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
comment|/**  @Function      FM_PCD_CcBuildTree   @Description   This routine must be called to define a complete coarse                 classification tree. This is the way to define coarse                 classification to a certain flow - the keygen schemes                 may point only to trees defined in this way.   @Param[in]     h_FmPcd                 FM PCD module descriptor.  @Param[in]     p_FmPcdCcTreeParams     A structure of parameters to define the tree.   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_CcBuildTree
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdCcTreeParams
modifier|*
name|p_FmPcdCcTreeParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcDeleteTree   @Description   Deleting an built tree.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_CcTree        A handle to a CC tree.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcDeleteTree
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcTree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcSetNode   @Description   This routine should be called for each CC (coarse classification)                 node. The whole CC tree should be built bottom up so that each                 node points to already defined nodes.   @Param[in]     h_FmPcd             FM PCD module descriptor.  @Param[in]     p_CcNodeParam       A structure of parameters defining the CC node   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_CcSetNode
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdCcNodeParams
modifier|*
name|p_CcNodeParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcDeleteNode   @Description   Deleting an built node.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_CcNode        A handle to a CC node.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcDeleteNode
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcTreeModifyNextEngine   @Description   Modify the Next Engine Parameters in the entry of the tree.   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcTree                    A handle to the tree  @Param[in]     grpId                       A Group index in the tree  @Param[in]     index                       Entry index in the group defined by grpId  @Param[in]     p_FmPcdCcNextEngineParams   A structure for defining new next engine params   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcBuildTree(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcTreeModifyNextEngine
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
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
comment|/**  @Function      FM_PCD_CcNodeModifyNextEngine   @Description   Modify the Next Engine Parameters in the relevant key entry of the node.   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for Next Engine Params modifications  @Param[in]     p_FmPcdCcNextEngineParams   A structure for defining new next engine params   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcSetNode(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcNodeModifyNextEngine
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
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
comment|/**  @Function      FM_PCD_CcNodeModifyMissNextEngine   @Description   Modify the Next Engine Parameters of the Miss key case of the node.   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     p_FmPcdCcNextEngineParams   A structure for defining new next engine params   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcSetNode(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcNodeModifyMissNextEngine
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
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
comment|/**  @Function      FM_PCD_CcNodeRemoveKey   @Description   Remove the key (include Next Engine Parameters of this key) defined by the index of the relevant node .   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for removing   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcSetNode() not only of the relevant node but also                 the node that points to this node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcNodeRemoveKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CcNodeAddKey   @Description   Add the key(include Next Engine Parameters of this key)in the index defined by the keyIndex .   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for adding  @Param[in]     keySize                     Key size of added key  @Param[in]     p_KeyParams                 A pointer to the parameters includes new key with Next Engine Parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcSetNode() not only of the relevant node but also                 the node that points to this node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcNodeAddKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
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
comment|/**  @Function      FM_PCD_CcNodeModifyKeyAndNextEngine   @Description   Modify the key and Next Engine Parameters of this key in the index defined by the keyIndex .   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for adding  @Param[in]     keySize                     Key size of added key  @Param[in]     p_KeyParams                 A pointer to the parameters includes modified key and modified Next Engine Parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcSetNode() not only of the relevant node but also                 the node that points to this node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcNodeModifyKeyAndNextEngine
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
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
comment|/**  @Function      FM_PCD_CcNodeModifyKey   @Description   Modify the key  in the index defined by the keyIndex .   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for adding  @Param[in]     keySize                     Key size of added key  @Param[in]     p_Key                       A pointer to the new key  @Param[in]     p_Mask                      A pointer to the new mask if relevant, otherwise pointer to NULL   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_CcSetNode() not only of the relevant node but also                 the node that points to this node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_CcNodeModifyKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
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
comment|/**  @Function      FM_PCD_CcNodeGetKeyCounter   @Description   This routine may be used to get a counter of specific key in a CC                 Node; This counter reflects how many frames passed that were matched                 this key.   @Param[in]     h_FmPcd                     A handle to an FM PCD Module.  @Param[in]     h_CcNode                    A handle to the node  @Param[in]     keyIndex                    Key index for adding   @Return        The specific key counter.   @Cautions      Allowed only following FM_PCD_CcSetNode() not only of the relevant node but also                 the node that points to this node */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_CcNodeGetKeyCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrSetProfile   @Description   Sets a profile entry in the policer profile table.                 The routine overrides any existing value.   @Param[in]     h_FmPcd           A handle to an FM PCD Module.  @Param[in]     p_Profile         A structure of parameters for defining a                                   policer profile entry.   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_PlcrSetProfile
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
comment|/**  @Function      FM_PCD_PlcrDeleteProfile   @Description   Delete a profile entry in the policer profile table.                 The routine set entry to invalid.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_Profile       A handle to the profile.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrDeleteProfile
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PlcrGetProfileCounter   @Description   Sets an entry in the classification plan.                 The routine overrides any existing value.   @Param[in]     h_FmPcd             A handle to an FM PCD Module.  @Param[in]     h_Profile       A handle to the profile.  @Param[in]     counter             Counter selector.   @Return        specific counter value.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_PCD_PlcrGetProfileCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
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
comment|/**  @Function      FM_PCD_PlcrSetProfileCounter   @Description   Sets an entry in the classification plan.                 The routine overrides any existing value.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_Profile       A handle to the profile.  @Param[in]     counter         Counter selector.  @Param[in]     value           value to set counter with.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_PlcrSetProfileCounter
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ManipSetNode   @Description   This routine should be called for defining a manipulation                 node. A manipulation node must be defined before the CC node                 that precedes it.   @Param[in]     h_FmPcd             FM PCD module descriptor.  @Param[in]     p_FmPcdManipParams  A structure of parameters defining the manipulation   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_PCD_ManipSetNode
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
comment|/**  @Function      FM_PCD_ManipDeleteNode   @Description   Delete an existing manip node.   @Param[in]     h_FmPcd         A handle to an FM PCD Module.  @Param[in]     h_HdrManipNode  A handle to a Manip node.   @Cautions      Allowed only following FM_PCD_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_PCD_ManipDeleteNode
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_HdrManipNode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FM_CAPWAP_SUPPORT) || ... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FM_CAPWAP_SUPPORT
end_ifdef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_StatisticsSetNode   @Description   This routine should be called for defining a statistics                 node.   @Param[in]     h_FmPcd             FM PCD module descriptor.  @Param[in]     p_FmPcdstatsParams  A structure of parameters defining the statistics   @Return        A handle to the initialized object on success; NULL code otherwise.   @Cautions      Allowed only following FM_PCD_Init(). */
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
comment|/* FM_CAPWAP_SUPPORT */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_Runtime_tree_buildgrp group */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_PCD_EXT */
end_comment

end_unit

