begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2015 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_macsec_ext.h   @Description   FM MACSEC ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_MACSEC_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_MACSEC_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_grp Frame Manager API   @Description   FM API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_grp FM MACSEC   @Description   FM MACSEC API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecExceptions
block|{
name|e_FM_MACSEC_EX_SINGLE_BIT_ECC
block|,
comment|/**< Single bit ECC error */
name|e_FM_MACSEC_EX_MULTI_BIT_ECC
comment|/**< Multi bit ECC error */
block|}
name|e_FmMacsecExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_init_grp FM-MACSEC Initialization Unit   @Description   FM MACSEC Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmMacsecExceptionsCallback   @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App       A handle to an application layer object; This handle                             will be passed by the driver upon calling this callback.  @Param[in]     exception   The exception. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmMacsecExceptionsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmMacsecExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM MACSEC config input */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecParams
block|{
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< A handle to the FM object related to */
name|bool
name|guestMode
decl_stmt|;
comment|/**< Partition-id */
union|union
block|{
struct|struct
block|{
name|uint8_t
name|fmMacId
decl_stmt|;
comment|/**< FM MAC id */
block|}
name|guestParams
struct|;
struct|struct
block|{
name|uintptr_t
name|baseAddr
decl_stmt|;
comment|/**< Base of memory mapped FM MACSEC registers */
name|t_Handle
name|h_FmMac
decl_stmt|;
comment|/**< A handle to the FM MAC object  related to */
name|t_FmMacsecExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Exception Callback Routine         */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                                      be passed by the driver upon calling the above callbacks */
block|}
name|nonGuestParams
struct|;
block|}
union|;
block|}
name|t_FmMacsecParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_Config   @Description   Creates descriptor for the FM MACSEC module;                  The routine returns a handle (descriptor) to the FM MACSEC object;                 This descriptor must be passed as first parameter to all other                 FM MACSEC function calls;                  No actual initialization or configuration of FM MACSEC hardware is                 done by this routine.   @Param[in]     p_FmMacsecParam     Pointer to data structure of parameters.   @Retval        Handle to FM MACSEC object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_MACSEC_Config
parameter_list|(
name|t_FmMacsecParams
modifier|*
name|p_FmMacsecParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_Init   @Description   Initializes the FM MACSEC module.   @Param[in]     h_FmMacsec      FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_Init
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_Free   @Description   Frees all resources that were assigned to FM MACSEC module;                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmMacsec      FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_Free
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_advanced_init_grp    FM-MACSEC Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for unknown sci frame treatment */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecUnknownSciFrameTreatment
block|{
name|e_FM_MACSEC_UNKNOWN_SCI_FRAME_TREATMENT_DISCARD_BOTH
init|=
literal|0
block|,
comment|/**< Controlled port - Strict mode */
name|e_FM_MACSEC_UNKNOWN_SCI_FRAME_TREATMENT_DISCARD_UNCONTROLLED_DELIVER_OR_DISCARD_CONTROLLED
block|,
comment|/**< If C bit clear deliver on controlled port, else discard                                                                                                                  Controlled port - Check or Disable mode */
name|e_FM_MACSEC_UNKNOWN_SCI_FRAME_TREATMENT_DELIVER_UNCONTROLLED_DISCARD_CONTROLLED
block|,
comment|/**< Controlled port - Strict mode */
name|e_FM_MACSEC_UNKNOWN_SCI_FRAME_TREATMENT_DELIVER_OR_DISCARD_UNCONTROLLED_DELIVER_OR_DISCARD_CONTROLLED
comment|/**< If C bit set deliver on uncontrolled port and discard on controlled port,                                                                                                                  else discard on uncontrolled port and deliver on controlled port                                                                                                                  Controlled port - Check or Disable mode */
block|}
name|e_FmMacsecUnknownSciFrameTreatment
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for untag frame treatment */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecUntagFrameTreatment
block|{
name|e_FM_MACSEC_UNTAG_FRAME_TREATMENT_DELIVER_UNCONTROLLED_DISCARD_CONTROLLED
init|=
literal|0
block|,
comment|/**< Controlled port - Strict mode */
name|e_FM_MACSEC_UNTAG_FRAME_TREATMENT_DISCARD_BOTH
block|,
comment|/**< Controlled port - Strict mode */
name|e_FM_MACSEC_UNTAG_FRAME_TREATMENT_DISCARD_UNCONTROLLED_DELIVER_CONTROLLED_UNMODIFIED
comment|/**< Controlled port - Strict mode */
block|}
name|e_FmMacsecUntagFrameTreatment
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigUnknownSciFrameTreatment   @Description   Change the treatment for received frames with unknown sci from its default                 configuration [DEFAULT_unknownSciFrameTreatment].   @Param[in]     h_FmMacsec      FM MACSEC module descriptor.  @Param[in]     treatMode       The selected mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigUnknownSciFrameTreatment
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|e_FmMacsecUnknownSciFrameTreatment
name|treatMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigInvalidTagsFrameTreatment   @Description   Change the treatment for received frames with invalid tags or                 a zero value PN or an invalid ICV from its default configuration                 [DEFAULT_invalidTagsFrameTreatment].   @Param[in]     h_FmMacsec              FM MACSEC module descriptor.  @Param[in]     deliverUncontrolled     If True deliver on the uncontrolled port, else discard;                                         In both cases discard on the controlled port;                                         this provide Strict, Check or Disable mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigInvalidTagsFrameTreatment
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|bool
name|deliverUncontrolled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigEncryptWithNoChangedTextFrameTreatment   @Description   Change the treatment for received frames with the Encryption bit                 set and the Changed Text bit clear from its default configuration                 [DEFAULT_encryptWithNoChangedTextFrameTreatment].   @Param[in]     h_FmMacsec              FM MACSEC module descriptor.  @Param[in]     discardUncontrolled     If True discard on the uncontrolled port, else deliver;                                         In both cases discard on the controlled port;                                         this provide Strict, Check or Disable mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigEncryptWithNoChangedTextFrameTreatment
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|bool
name|discardUncontrolled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigChangedTextWithNoEncryptFrameTreatment   @Description   Change the treatment for received frames with the Encryption bit                 clear and the Changed Text bit set from its default configuration                 [DEFAULT_changedTextWithNoEncryptFrameTreatment].   @Param[in]     h_FmMacsec              FM MACSEC module descriptor.  @Param[in]     deliverUncontrolled     If True deliver on the uncontrolled port, else discard;                                         In both cases discard on the controlled port;                                         this provide Strict, Check or Disable mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigChangedTextWithNoEncryptFrameTreatment
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|bool
name|deliverUncontrolled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigUntagFrameTreatment   @Description   Change the treatment for received frames without the MAC security tag (SecTAG)                 from its default configuration [DEFAULT_untagFrameTreatment].   @Param[in]     h_FmMacsec     FM MACSEC module descriptor.  @Param[in]     treatMode      The selected mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigUntagFrameTreatment
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|e_FmMacsecUntagFrameTreatment
name|treatMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigOnlyScbIsSetFrameTreatment   @Description   Change the treatment for received frames with only SCB bit set                 from its default configuration [DEFAULT_onlyScbIsSetFrameTreatment].   @Param[in]     h_FmMacsec              FM MACSEC module descriptor.  @Param[in]     deliverUncontrolled     If True deliver on the uncontrolled port, else discard;                                         In both cases discard on the controlled port;                                         this provide Strict, Check or Disable mode.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigOnlyScbIsSetFrameTreatment
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|bool
name|deliverUncontrolled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigPnExhaustionThreshold   @Description   It's provide the ability to configure a PN exhaustion threshold;                 When the NextPn crosses this value an interrupt event                 is asserted to warn that the active SA should re-key.   @Param[in]     h_FmMacsec     FM MACSEC module descriptor.  @Param[in]     pnExhThr       If the threshold is reached, an interrupt event                                is asserted to re-key.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigPnExhaustionThreshold
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|uint32_t
name|pnExhThr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigKeysUnreadable   @Description   Turn on privacy mode; All the keys and their hash values can't be read any more;                 Can not be cleared unless hard reset.   @Param[in]     h_FmMacsec         FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigKeysUnreadable
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigSectagWithoutSCI   @Description   Promise that all generated Sectag will be without SCI included.   @Param[in]     h_FmMacsec         FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigSectagWithoutSCI
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_ConfigException   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement;                 By default all exceptions are enabled.   @Param[in]     h_FmMacsec      FM MACSEC module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Config() and before FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_ConfigException
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|e_FmMacsecExceptions
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_runtime_control_grp FM-MACSEC Runtime Control Data Unit   @Description   FM MACSEC runtime control data unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_GetRevision   @Description   Return MACSEC HW chip revision   @Param[in]     h_FmMacsec         FM MACSEC module descriptor.  @Param[out]    p_MacsecRevision   MACSEC revision as defined by the chip.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_GetRevision
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|uint32_t
modifier|*
name|p_MacsecRevision
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_Enable   @Description   This routine should be called after MACSEC is initialized for enabling all                 MACSEC engines according to their existing configuration.   @Param[in]     h_FmMacsec         FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Init() and when MACSEC is disabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_Enable
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_Disable   @Description   This routine may be called when MACSEC is enabled in order to                 disable all MACSEC engines; The MACSEC is working in bypass mode.   @Param[in]     h_FmMacsec         FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Init() and when MACSEC is enabled. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_Disable
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SetException   @Description   Calling this routine enables/disables the specified exception.   @Param[in]     h_FmMacsec      FM MACSEC module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SetException
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|e_FmMacsecExceptions
name|exception
parameter_list|,
name|bool
name|enable
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
comment|/**  @Function      FM_MACSEC_DumpRegs   @Description   Dump internal registers.   @Param[in]     h_FmMacsec  - FM MACSEC module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only after FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_DumpRegs
parameter_list|(
name|t_Handle
name|h_FmMacsec
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

begin_ifdef
ifdef|#
directive|ifdef
name|VERIFICATION_SUPPORT
end_ifdef

begin_comment
comment|/********************* VERIFICATION ONLY ********************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_BackdoorSet   @Description   Set register of the MACSEC memory map   @Param[in]     h_FmMacsec          FM MACSEC module descriptor.  @Param[out]    offset              Register offset.  @Param[out]    value               Value to write.    @Return        None   @Cautions      Allowed only following FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_BackdoorSet
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|uint32_t
name|offset
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
comment|/**  @Function      FM_MACSEC_BackdoorGet   @Description   Read from register of the MACSEC memory map.   @Param[in]     h_FmMacsec          FM MACSEC module descriptor.  @Param[out]    offset              Register offset.   @Return        Value read   @Cautions      Allowed only following FM_MACSEC_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_MACSEC_BackdoorGet
parameter_list|(
name|t_Handle
name|h_FmMacsec
parameter_list|,
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERIFICATION_SUPPORT */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_runtime_control_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_SECY_grp FM-MACSEC SecY   @Description   FM-MACSEC SecY API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|macsecSAKey_t
index|[
literal|32
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|macsecSCI_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|macsecAN_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/** @Description   MACSEC SECY Cipher Suite */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecSecYCipherSuite
block|{
name|e_FM_MACSEC_SECY_GCM_AES_128
init|=
literal|0
block|,
comment|/**< GCM-AES-128 */
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|e_FM_MACSEC_SECY_GCM_AES_256
comment|/**< GCM-AES-256 */
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
block|}
name|e_FmMacsecSecYCipherSuite
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SECY Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecSecYExceptions
block|{
name|e_FM_MACSEC_SECY_EX_FRAME_DISCARDED
comment|/**< Frame  Discarded */
block|}
name|e_FmMacsecSecYExceptions
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SECY Events */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecSecYEvents
block|{
name|e_FM_MACSEC_SECY_EV_NEXT_PN
comment|/**< Next Packet Number exhaustion threshold reached */
block|}
name|e_FmMacsecSecYEvents
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   MACSEC SECY Frame Discarded Descriptor error */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|macsecTxScFrameDiscardedErrSelect_t
typedef|;
end_typedef

begin_comment
comment|/**< typedef for defining Frame Discarded Descriptor errors */
end_comment

begin_define
define|#
directive|define
name|FM_MACSEC_SECY_TX_SC_FRM_DISCAR_ERR_NEXT_PN_ZERO
value|0x8000
end_define

begin_comment
comment|/**< NextPn == 0 */
end_comment

begin_define
define|#
directive|define
name|FM_MACSEC_SECY_TX_SC_FRM_DISCAR_ERR_SC_DISBALE
value|0x4000
end_define

begin_comment
comment|/**< SC is disable */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmMacsecSecYExceptionsCallback   @Description   Exceptions user callback routine, will be called upon an                 exception passing the exception identification.   @Param[in]     h_App       A handle to an application layer object; This handle                             will be passed by the driver upon calling this callback.  @Param[in]     exception   The exception. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmMacsecSecYExceptionsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmMacsecSecYExceptions
name|exception
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      t_FmMacsecSecYEventsCallback   @Description   Events user callback routine, will be called upon an                 event passing the event identification.   @Param[in]     h_App       A handle to an application layer object; This handle                             will be passed by the driver upon calling this callback.  @Param[in]     event       The event. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|t_FmMacsecSecYEventsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_App
parameter_list|,
name|e_FmMacsecSecYEvents
name|event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   RFC2863 MIB */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_MIBStatistics
block|{
name|uint64_t
name|ifInOctets
decl_stmt|;
comment|/**< Total number of byte received */
name|uint64_t
name|ifInPkts
decl_stmt|;
comment|/**< Total number of packets received */
name|uint64_t
name|ifInMcastPkts
decl_stmt|;
comment|/**< Total number of multicast frame received */
name|uint64_t
name|ifInBcastPkts
decl_stmt|;
comment|/**< Total number of broadcast frame received */
name|uint64_t
name|ifInDiscards
decl_stmt|;
comment|/**< Frames received, but discarded due to problems within the MAC RX :                                                - InPktsNoTag,                                                - InPktsLate,                                                - InPktsOverrun */
name|uint64_t
name|ifInErrors
decl_stmt|;
comment|/**< Number of frames received with error:                                                - InPktsBadTag,                                                - InPktsNoSCI,                                                - InPktsNotUsingSA                                                - InPktsNotValid */
name|uint64_t
name|ifOutOctets
decl_stmt|;
comment|/**< Total number of byte sent */
name|uint64_t
name|ifOutPkts
decl_stmt|;
comment|/**< Total number of packets sent */
name|uint64_t
name|ifOutMcastPkts
decl_stmt|;
comment|/**< Total number of multicast frame sent */
name|uint64_t
name|ifOutBcastPkts
decl_stmt|;
comment|/**< Total number of multicast frame sent */
name|uint64_t
name|ifOutDiscards
decl_stmt|;
comment|/**< Frames received, but discarded due to problems within the MAC TX N/A! */
name|uint64_t
name|ifOutErrors
decl_stmt|;
comment|/**< Number of frames transmitted with error:                                                - FIFO Overflow Error                                                - FIFO Underflow Error                                                - Other */
block|}
name|t_MIBStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SecY Rx SA Statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYRxSaStatistics
block|{
name|uint32_t
name|inPktsOK
decl_stmt|;
comment|/**< The number of frames with resolved SCI, have passed all                                                      frame validation frame validation with the validateFrame not set to disable */
name|uint32_t
name|inPktsInvalid
decl_stmt|;
comment|/**< The number of frames with resolved SCI, that have failed frame                                                      validation with the validateFrame set to check */
name|uint32_t
name|inPktsNotValid
decl_stmt|;
comment|/**< The number of frames with resolved SCI, discarded on the controlled port,                                                      that have failed frame validation with the validateFrame set to strict or the c bit is set */
name|uint32_t
name|inPktsNotUsingSA
decl_stmt|;
comment|/**< The number of frames received with resolved SCI and discarded on disabled or                                                      not provisioned SA with validateFrame in the strict mode or the C bit is set */
name|uint32_t
name|inPktsUnusedSA
decl_stmt|;
comment|/**< The number of frames received with resolved SCI on disabled or not provisioned SA                                                      with validateFrame not in the strict mode and the C bit is cleared */
block|}
name|t_FmMacsecSecYRxSaStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SecY Tx SA Statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYTxSaStatistics
block|{
name|uint64_t
name|outPktsProtected
decl_stmt|;
comment|/**< The number of frames, that the user of the controlled port requested to                                                      be transmitted, which were integrity protected */
name|uint64_t
name|outPktsEncrypted
decl_stmt|;
comment|/**< The number of frames, that the user of the controlled port requested to                                                      be transmitted, which were confidentiality protected */
block|}
name|t_FmMacsecSecYTxSaStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SecY Rx SC Statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYRxScStatistics
block|{
name|uint64_t
name|inPktsUnchecked
decl_stmt|;
comment|/**< The number of frames with resolved SCI, delivered to the user of a controlled port,                                                      that are not validated with the validateFrame set to disable */
name|uint64_t
name|inPktsDelayed
decl_stmt|;
comment|/**< The number of frames with resolved SCI, delivered to the user of a controlled port,                                                      that have their PN smaller than the lowest_PN with the validateFrame set to                                                      disable or replayProtect disabled */
name|uint64_t
name|inPktsLate
decl_stmt|;
comment|/**< The number of frames with resolved SCI, discarded on the controlled port,                                                      that have their PN smaller than the lowest_PN with the validateFrame set to                                                      Check or Strict and replayProtect enabled */
name|uint64_t
name|inPktsOK
decl_stmt|;
comment|/**< The number of frames with resolved SCI, have passed all                                                      frame validation frame validation with the validateFrame not set to disable */
name|uint64_t
name|inPktsInvalid
decl_stmt|;
comment|/**< The number of frames with resolved SCI, that have failed frame                                                      validation with the validateFrame set to check */
name|uint64_t
name|inPktsNotValid
decl_stmt|;
comment|/**< The number of frames with resolved SCI, discarded on the controlled port,                                                      that have failed frame validation with the validateFrame set to strict or the c bit is set */
name|uint64_t
name|inPktsNotUsingSA
decl_stmt|;
comment|/**< The number of frames received with resolved SCI and discarded on disabled or                                                      not provisioned SA with validateFrame in the strict mode or the C bit is set */
name|uint64_t
name|inPktsUnusedSA
decl_stmt|;
comment|/**< The number of frames received with resolved SCI on disabled or not provisioned SA                                                      with validateFrame not in the strict mode and the C bit is cleared */
block|}
name|t_FmMacsecSecYRxScStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SecY Tx SC Statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYTxScStatistics
block|{
name|uint64_t
name|outPktsProtected
decl_stmt|;
comment|/**< The number of frames, that the user of the controlled port requested to                                                      be transmitted, which were integrity protected */
name|uint64_t
name|outPktsEncrypted
decl_stmt|;
comment|/**< The number of frames, that the user of the controlled port requested to                                                      be transmitted, which were confidentiality protected */
block|}
name|t_FmMacsecSecYTxScStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SecY Statistics */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYStatistics
block|{
name|t_MIBStatistics
name|mibCtrlStatistics
decl_stmt|;
comment|/**< Controlled port MIB statistics */
name|t_MIBStatistics
name|mibNonCtrlStatistics
decl_stmt|;
comment|/**< Uncontrolled port MIB statistics */
comment|/* Frame verification statistics */
name|uint64_t
name|inPktsUntagged
decl_stmt|;
comment|/**< The number of received packets without the MAC security tag                                                      (SecTAG) with validateFrames which is not in the strict mode */
name|uint64_t
name|inPktsNoTag
decl_stmt|;
comment|/**< The number of received packets discarded without the                                                      MAC security tag (SecTAG) with validateFrames which is in the strict mode */
name|uint64_t
name|inPktsBadTag
decl_stmt|;
comment|/**< The number of received packets discarded with an invalid                                                      SecTAG or a zero value PN or an invalid ICV */
name|uint64_t
name|inPktsUnknownSCI
decl_stmt|;
comment|/**< The number of received packets with unknown SCI with the                                                      condition : validateFrames is not in the strict mode and the                                                      C bit in the SecTAG is not set */
name|uint64_t
name|inPktsNoSCI
decl_stmt|;
comment|/**< The number of received packets discarded with unknown SCI                                                      information with the condition : validateFrames is in the strict mode                                                      or the C bit in the SecTAG is set */
name|uint64_t
name|inPktsOverrun
decl_stmt|;
comment|/**< The number of packets discarded because the number of                                                      received packets exceeded the cryptographic performance capabilities */
comment|/* Frame validation statistics */
name|uint64_t
name|inOctetsValidated
decl_stmt|;
comment|/**< The number of octets of plaintext recovered from received frames with                                                      resolved SCI that were integrity protected but not encrypted */
name|uint64_t
name|inOctetsDecrypted
decl_stmt|;
comment|/**< The number of octets of plaintext recovered from received frames with                                                      resolved SCI that were integrity protected and encrypted */
comment|/* Frame generation statistics */
name|uint64_t
name|outPktsUntagged
decl_stmt|;
comment|/**< The number of frames, that the user of the controlled port requested to                                                      be transmitted, with protectFrame false */
name|uint64_t
name|outPktsTooLong
decl_stmt|;
comment|/**< The number of frames, that the user of the controlled port requested to                                                      be transmitted, discarded due to length being larger than Maximum Frame Length (MACSEC_MFL) */
comment|/* Frame protection statistics */
name|uint64_t
name|outOctetsProtected
decl_stmt|;
comment|/**< The number of octets of User Data in transmitted frames that were                                                      integrity protected but not encrypted */
name|uint64_t
name|outOctetsEncrypted
decl_stmt|;
comment|/**< The number of octets of User Data in transmitted frames that were                                                      both integrity protected and encrypted */
block|}
name|t_FmMacsecSecYStatistics
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   MACSEC SecY SC Params */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYSCParams
block|{
name|macsecSCI_t
name|sci
decl_stmt|;
comment|/**< The secure channel identification of the SC */
name|e_FmMacsecSecYCipherSuite
name|cipherSuite
decl_stmt|;
comment|/**< Cipher suite to be used for the SC */
block|}
name|t_FmMacsecSecYSCParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_SECY_init_grp FM-MACSEC SecY Initialization Unit   @Description   FM-MACSEC SecY Initialization Unit   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for validate frames */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecValidFrameBehavior
block|{
name|e_FM_MACSEC_VALID_FRAME_BEHAVIOR_DISABLE
init|=
literal|0
block|,
comment|/**< disable the validation function */
name|e_FM_MACSEC_VALID_FRAME_BEHAVIOR_CHECK
block|,
comment|/**< enable the validation function but only for checking                                                          without filtering out invalid frames */
name|e_FM_MACSEC_VALID_FRAME_BEHAVIOR_STRICT
comment|/**< enable the validation function and also strictly filter                                                          out those invalid frames */
block|}
name|e_FmMacsecValidFrameBehavior
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for sci insertion */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacsecSciInsertionMode
block|{
name|e_FM_MACSEC_SCI_INSERTION_MODE_EXPLICIT_SECTAG
init|=
literal|0
block|,
comment|/**< explicit sci in the sectag */
name|e_FM_MACSEC_SCI_INSERTION_MODE_EXPLICIT_MAC_SA
block|,
comment|/**< mac sa is overwritten with the sci*/
name|e_FM_MACSEC_SCI_INSERTION_MODE_IMPLICT_PTP
comment|/**< implicit point-to-point sci (pre-shared) */
block|}
name|e_FmMacsecSciInsertionMode
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM MACSEC SecY config input */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmMacsecSecYParams
block|{
name|t_Handle
name|h_FmMacsec
decl_stmt|;
comment|/**< A handle to the FM MACSEC object */
name|t_FmMacsecSecYSCParams
name|txScParams
decl_stmt|;
comment|/**< Tx SC Params */
name|uint32_t
name|numReceiveChannels
decl_stmt|;
comment|/**< Number of receive channels dedicated to this SecY */
name|t_FmMacsecSecYExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< Callback routine to be called by the driver upon SecY exception */
name|t_FmMacsecSecYEventsCallback
modifier|*
name|f_Event
decl_stmt|;
comment|/**< Callback routine to be called by the driver upon SecY event */
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< A handle to an application layer object; This handle will                                                                              be passed by the driver upon calling the above callbacks */
block|}
name|t_FmMacsecSecYParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_Config   @Description   Creates descriptor for the FM MACSEC SECY module;                  The routine returns a handle (descriptor) to the FM MACSEC SECY object;                 This descriptor must be passed as first parameter to all other                 FM MACSEC SECY function calls;                 No actual initialization or configuration of FM MACSEC SecY hardware is                 done by this routine.   @Param[in]     p_FmMacsecSecYParam     Pointer to data structure of parameters.   @Return        Handle to FM MACSEC SECY object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_MACSEC_SECY_Config
parameter_list|(
name|t_FmMacsecSecYParams
modifier|*
name|p_FmMacsecSecYParam
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_Init   @Description   Initializes the FM MACSEC SECY module.   @Param[in]     h_FmMacsecSecY  FM MACSEC SECY module descriptor.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_Init
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_Free   @Description   Frees all resources that were assigned to FM MACSEC SECY module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmMacsecSecY  FM MACSEC SECY module descriptor.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_Free
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_SECY_advanced_init_grp  FM-MACSEC SecY Advanced Configuration Unit   @Description   Configuration functions used to change default values.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigSciInsertionMode   @Description   Calling this routine changes the SCI-insertion-mode in the                 internal driver data base from its default configuration                 [DEFAULT_sciInsertionMode]   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     sciInsertionMode    Sci insertion mode   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init();  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigSciInsertionMode
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|e_FmMacsecSciInsertionMode
name|sciInsertionMode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigProtectFrames   @Description   Calling this routine changes the protect-frame mode in the                 internal driver data base from its default configuration                 [DEFAULT_protectFrames]   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     protectFrames       If FALSE, frames are transmitted without modification   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init();  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigProtectFrames
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|bool
name|protectFrames
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigReplayWindow   @Description   Calling this routine changes the replay-window settings in the                 internal driver data base from its default configuration                 [DEFAULT_replayEnable], [DEFAULT_replayWindow]   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     replayProtect;      Replay protection function mode  @Param[in]     replayWindow;       The size of the replay window   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init();  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigReplayWindow
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|bool
name|replayProtect
parameter_list|,
name|uint32_t
name|replayWindow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigValidationMode   @Description   Calling this routine changes the frame-validation-behavior mode                 in the internal driver data base from its default configuration                 [DEFAULT_validateFrames]   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     validateFrames      Validation function mode   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init();  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigValidationMode
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|e_FmMacsecValidFrameBehavior
name|validateFrames
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigConfidentiality   @Description   Calling this routine changes the confidentiality settings in the                 internal driver data base from its default configuration                 [DEFAULT_confidentialityEnable], [DEFAULT_confidentialityOffset]   @Param[in]     h_FmMacsecSecY          FM MACSEC SECY module descriptor.  @Param[in]     confidentialityEnable   TRUE  - confidentiality protection and integrity protection                                         FALSE - no confidentiality protection, only integrity protection  @Param[in]     confidentialityOffset   The number of initial octets of each MSDU without confidentiality protection                                         common values are 0, 30, and 50   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init();  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigConfidentiality
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|bool
name|confidentialityEnable
parameter_list|,
name|uint16_t
name|confidentialityOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigPointToPoint   @Description   configure this SecY to work in point-to-point mode, means that                 it will have only one rx sc;   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init();                 Can be called only once in a system; only the first secY that will call this                 routine will be able to operate in Point-To-Point mode. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigPointToPoint
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_ConfigException   @Description   Calling this routine changes the internal driver data base                 from its default selection of exceptions enablement;                 By default all exceptions are enabled.   @Param[in]     h_FmMacsecSecY  FM MACSEC SECY module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigException
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|e_FmMacsecSecYExceptions
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
comment|/**  @Function      FM_MACSEC_SECY_ConfigEvent   @Description   Calling this routine changes the internal driver data base                 from its default selection of events enablement;                 By default all events are enabled.   @Param[in]     h_FmMacsecSecY  FM MACSEC SECY module descriptor.  @Param[in]     event           The event to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_ConfigEvent
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|e_FmMacsecSecYEvents
name|event
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_SECY_advanced_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_SECY_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_MACSEC_SECY_runtime_control_grp FM-MACSEC SecY Runtime Control Unit   @Description   FM MACSEC SECY Runtime control unit API functions, definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_CreateRxSc   @Description   Create a receive secure channel.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     scParams            secure channel params.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_MACSEC_SECY_CreateRxSc
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_FmMacsecSecYSCParams
modifier|*
name|p_ScParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_DeleteRxSc   @Description   Deleting an initialized secure channel.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSc(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_DeleteRxSc
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_CreateRxSa   @Description   Create a receive secure association for the secure channel;                 the SA cannot be used to receive frames until FM_MACSEC_SECY_RxSaEnableReceive is called.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.  @Param[in]     lowestPn            the lowest acceptable PN value for a received frame.  @Param[in]     key                 the desired key for this SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSc(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_CreateRxSa
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|uint32_t
name|lowestPn
parameter_list|,
name|macsecSAKey_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_DeleteRxSa   @Description   Deleting an initialized secure association.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_DeleteRxSa
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxSaEnableReceive   @Description   Enabling the SA to receive frames.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSa(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxSaEnableReceive
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxSaDisableReceive   @Description   Disabling the SA from receive frames.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSa(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxSaDisableReceive
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxSaUpdateNextPn   @Description   Update the next packet number expected on RX;                 The value of nextPN shall be set to the greater of its existing value and the                 supplied of updtNextPN (802.1AE-2006 10.7.15).   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.  @Param[in]     updtNextPN          the next PN value for a received frame.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSa(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxSaUpdateNextPn
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|uint32_t
name|updtNextPN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxSaUpdateLowestPn   @Description   Update the lowest packet number expected on RX;                 The value of lowestPN shall be set to the greater of its existing value and the                 supplied of updtLowestPN (802.1AE-2006 10.7.15).   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.  @Param[in]     updtLowestPN        the lowest PN acceptable value for a received frame.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSa(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxSaUpdateLowestPn
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|uint32_t
name|updtLowestPN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxSaModifyKey   @Description   Modify the current key of the SA with a new one.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[in]     an                  association number represent the SA.  @Param[in]     key                 new key to replace the current key.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSa(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxSaModifyKey
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|macsecSAKey_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_CreateTxSa   @Description   Create a transmit secure association for the secure channel;                 the SA cannot be used to transmit frames until FM_MACSEC_SECY_TxSaSetActivate is called;                 Only one SA can be active at a time.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     an                  association number represent the SA.  @Param[in]     key                 the desired key for this SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_CreateTxSa
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|macsecSAKey_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_DeleteTxSa   @Description   Deleting an initialized secure association.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     an                  association number represent the SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_DeleteTxSa
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|macsecAN_t
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_TxSaModifyKey   @Description   Modify the key of the inactive SA with a new one.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     nextActiveAn        association number represent the next SA to be activated.  @Param[in]     key                 new key to replace the current key.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_TxSaModifyKey
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|macsecAN_t
name|nextActiveAn
parameter_list|,
name|macsecSAKey_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_TxSaSetActive   @Description   Set this SA to the active SA to be used on TX for SC;                 only one SA can be active at a time.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     an                  association number represent the SA.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_TxSaSetActive
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|macsecAN_t
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_TxSaGetActive   @Description   Get the active SA that being used for TX.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[out]    p_An                the active an.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_TxSaGetActive
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|macsecAN_t
modifier|*
name|p_An
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_GetStatistics   @Description   get all statistics counters.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     p_Statistics        Structure with statistics.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_GetStatistics
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_FmMacsecSecYStatistics
modifier|*
name|p_Statistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxScGetStatistics   @Description   get all statistics counters.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                Rx Sc handle.  @Param[in]     p_Statistics        Structure with statistics.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxScGetStatistics
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|t_FmMacsecSecYRxScStatistics
modifier|*
name|p_Statistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_RxSaGetStatistics   @Description   get all statistics counters   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                Rx Sc handle.  @Param[in]     an                  association number represent the SA.  @Param[in]     p_Statistics        Structure with statistics.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_RxSaGetStatistics
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|t_FmMacsecSecYRxSaStatistics
modifier|*
name|p_Statistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_TxScGetStatistics   @Description   get all statistics counters.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     p_Statistics        Structure with statistics.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_TxScGetStatistics
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_FmMacsecSecYTxScStatistics
modifier|*
name|p_Statistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_TxSaGetStatistics   @Description   get all statistics counters.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     an                  association number represent the SA.  @Param[in]     p_Statistics        Structure with statistics.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_TxSaGetStatistics
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|macsecAN_t
name|an
parameter_list|,
name|t_FmMacsecSecYTxSaStatistics
modifier|*
name|p_Statistics
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_SetException   @Description   Calling this routine enables/disables the specified exception.   @Param[in]     h_FmMacsecSecY  FM MACSEC SECY module descriptor.  @Param[in]     exception       The exception to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_SetException
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|e_FmMacsecExceptions
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
comment|/**  @Function      FM_MACSEC_SECY_SetEvent   @Description   Calling this routine enables/disables the specified event.   @Param[in]     h_FmMacsecSecY  FM MACSEC SECY module descriptor.  @Param[in]     event           The event to be selected.  @Param[in]     enable          TRUE to enable interrupt, FALSE to mask it.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Config() and before FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_SetEvent
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|e_FmMacsecSecYEvents
name|event
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
comment|/**  @Function      FM_MACSEC_SECY_GetRxScPhysId   @Description   return the physical id of the Secure Channel.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[in]     h_Sc                SC handle as returned by FM_MACSEC_SECY_CreateRxSc.  @Param[out]    p_ScPhysId          the SC physical id.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_CreateRxSc(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_GetRxScPhysId
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|t_Handle
name|h_Sc
parameter_list|,
name|uint32_t
modifier|*
name|p_ScPhysId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MACSEC_SECY_GetTxScPhysId   @Description   return the physical id of the Secure Channel.   @Param[in]     h_FmMacsecSecY      FM MACSEC SECY module descriptor.  @Param[out]    p_ScPhysId          the SC physical id.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_MACSEC_SECY_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_MACSEC_SECY_GetTxScPhysId
parameter_list|(
name|t_Handle
name|h_FmMacsecSecY
parameter_list|,
name|uint32_t
modifier|*
name|p_ScPhysId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_SECY_runtime_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_SECY_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_MACSEC_grp group */
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
comment|/* __FM_MACSEC_EXT_H */
end_comment

end_unit

