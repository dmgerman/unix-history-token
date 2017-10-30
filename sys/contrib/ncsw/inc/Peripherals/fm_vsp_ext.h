begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_vsp_ext.h   @Description   FM Virtual Storage-Profile ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_VSP_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_VSP_EXT_H
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
file|"string_ext.h"
end_include

begin_include
include|#
directive|include
file|"debug_ext.h"
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
comment|/**  @Group         FM_VSP_grp FM Virtual-Storage-Profile   @Description   FM Virtual-Storage-Profile API   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_VSP_init_grp FM VSP Initialization Unit   @Description   FM VSP initialization API.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Virtual Storage Profile */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmVspParams
block|{
name|t_Handle
name|h_Fm
decl_stmt|;
comment|/**< A handle to the FM object this VSP related to */
name|t_FmExtPools
name|extBufPools
decl_stmt|;
comment|/**< Which external buffer pools are used                                                  (up to FM_PORT_MAX_NUM_OF_EXT_POOLS), and their sizes.                                                  parameter associated with Rx / OP port */
name|uint16_t
name|liodnOffset
decl_stmt|;
comment|/**< VSP's LIODN offset */
struct|struct
block|{
name|e_FmPortType
name|portType
decl_stmt|;
comment|/**< Port type */
name|uint8_t
name|portId
decl_stmt|;
comment|/**< Port Id - relative to type */
block|}
name|portParams
struct|;
name|uint8_t
name|relativeProfileId
decl_stmt|;
comment|/**< VSP Id - relative to VSP's range                                                  defined in relevant FM object */
block|}
name|t_FmVspParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_Config   @Description   Creates descriptor for the FM VSP module.                  The routine returns a handle (descriptor) to the FM VSP object.                 This descriptor must be passed as first parameter to all other                 FM VSP function calls.                  No actual initialization or configuration of FM hardware is                 done by this routine.  @Param[in]      p_FmVspParams   Pointer to data structure of parameters   @Retval        Handle to FM VSP object, or NULL for Failure. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FM_VSP_Config
parameter_list|(
name|t_FmVspParams
modifier|*
name|p_FmVspParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_Init   @Description   Initializes the FM VSP module   @Param[in]     h_FmVsp - FM VSP module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_Init
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_Free   @Description   Frees all resources that were assigned to FM VSP module.                  Calling this routine invalidates the descriptor.   @Param[in]     h_FmVsp - FM VSP module descriptor   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_Free
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_VSP_adv_config_grp  FM VSP Advanced Configuration Unit   @Description   FM VSP advanced configuration functions.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigBufferPrefixContent   @Description   Defines the structure, size and content of the application buffer.                  The prefix will                 In VSPs defined for Tx ports, if 'passPrsResult', the application                 should set a value to their offsets in the prefix of                 the FM will save the first 'privDataSize', than,                 depending on 'passPrsResult' and 'passTimeStamp', copy parse result                 and timeStamp, and the packet itself (in this order), to the                 application buffer, and to offset.                  Calling this routine changes the buffer margins definitions                 in the internal driver data base from its default                 configuration: Data size:  [DEFAULT_FM_SP_bufferPrefixContent_privDataSize]                                Pass Parser result: [DEFAULT_FM_SP_bufferPrefixContent_passPrsResult].                                Pass timestamp: [DEFAULT_FM_SP_bufferPrefixContent_passTimeStamp].   @Param[in]     h_FmVsp                         A handle to a FM VSP module.  @Param[in,out] p_FmBufferPrefixContent         A structure of parameters describing the                                                 structure of the buffer.                                                 Out parameter: Start margin - offset                                                 of data from start of external buffer.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigBufferPrefixContent
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|t_FmBufferPrefixContent
modifier|*
name|p_FmBufferPrefixContent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigDmaSwapData   @Description   Calling this routine changes the DMA swap data parameter                 in the internal driver data base from its default                 configuration  [DEFAULT_FM_SP_dmaSwapData]   @Param[in]     h_FmVsp     A handle to a FM VSP module.  @Param[in]     swapData    New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigDmaSwapData
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|e_FmDmaSwapOption
name|swapData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigDmaIcCacheAttr   @Description   Calling this routine changes the internal context cache                 attribute parameter in the internal driver data base                 from its default configuration  [DEFAULT_FM_SP_dmaIntContextCacheAttr]   @Param[in]     h_FmVsp                 A handle to a FM VSP module.  @Param[in]     intContextCacheAttr     New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigDmaIcCacheAttr
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|e_FmDmaCacheOption
name|intContextCacheAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigDmaHdrAttr   @Description   Calling this routine changes the header cache                 attribute parameter in the internal driver data base                 from its default configuration  [DEFAULT_FM_SP_dmaHeaderCacheAttr]   @Param[in]     h_FmVsp                     A handle to a FM VSP module.  @Param[in]     headerCacheAttr             New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigDmaHdrAttr
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|e_FmDmaCacheOption
name|headerCacheAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigDmaScatterGatherAttr   @Description   Calling this routine changes the scatter gather cache                 attribute parameter in the internal driver data base                 from its default configuration [DEFAULT_FM_SP_dmaScatterGatherCacheAttr]   @Param[in]     h_FmVsp                     A handle to a FM VSP module.  @Param[in]     scatterGatherCacheAttr      New selection   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigDmaScatterGatherAttr
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|e_FmDmaCacheOption
name|scatterGatherCacheAttr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigDmaWriteOptimize   @Description   Calling this routine changes the write optimization                 parameter in the internal driver data base                 from its default configuration: optimize = [DEFAULT_FM_SP_dmaWriteOptimize]   @Param[in]     h_FmVsp     A handle to a FM VSP module.  @Param[in]     optimize    TRUE to enable optimization, FALSE for normal operation   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigDmaWriteOptimize
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|bool
name|optimize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigNoScatherGather   @Description   Calling this routine changes the possibility to receive S/G frame                 in the internal driver data base                 from its default configuration: optimize = [DEFAULT_FM_SP_noScatherGather]   @Param[in]     h_FmVsp             A handle to a FM VSP module.  @Param[in]     noScatherGather     TRUE to operate without scatter/gather capability.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigNoScatherGather
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|bool
name|noScatherGather
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigPoolDepletion   @Description   Calling this routine enables pause frame generation depending on the                 depletion status of BM pools. It also defines the conditions to activate                 this functionality. By default, this functionality is disabled.   @Param[in]     h_FmVsp                 A handle to a FM VSP module.  @Param[in]     p_BufPoolDepletion      A structure of pool depletion parameters   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigPoolDepletion
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|t_FmBufPoolDepletion
modifier|*
name|p_BufPoolDepletion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_ConfigBackupPools   @Description   Calling this routine allows the configuration of some of the BM pools                 defined for this port as backup pools.                 A pool configured to be a backup pool will be used only if all other                 enabled non-backup pools are depleted.   @Param[in]     h_FmVsp                 A handle to a FM VSP module.  @Param[in]     p_BackupBmPools         An array of pool id's. All pools specified here will                                         be defined as backup pools.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_VSP_Config() and before FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FM_VSP_ConfigBackupPools
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|t_FmBackupBmPools
modifier|*
name|p_BackupBmPools
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_VSP_adv_config_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_VSP_init_grp group */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_VSP_control_grp FM VSP Control Unit   @Description   FM VSP runtime control API.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_GetBufferDataOffset   @Description   Relevant for Rx ports.                 Returns the data offset from the beginning of the data buffer   @Param[in]     h_FmVsp - FM PORT module descriptor   @Return        data offset.   @Cautions      Allowed only following FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FM_VSP_GetBufferDataOffset
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_GetBufferICInfo   @Description   Returns the Internal Context offset from the beginning of the data buffer   @Param[in]     h_FmVsp - FM PORT module descriptor  @Param[in]     p_Data   - A pointer to the data buffer.   @Return        Internal context info pointer on success, NULL if 'allOtherInfo' was not                 configured for this port.   @Cautions      Allowed only following FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|FM_VSP_GetBufferICInfo
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_GetBufferPrsResult   @Description   Returns the pointer to the parse result in the data buffer.                 In Rx ports this is relevant after reception, if parse                 result is configured to be part of the data passed to the                 application. For non Rx ports it may be used to get the pointer                 of the area in the buffer where parse result should be                 initialized - if so configured.                 See FM_VSP_ConfigBufferPrefixContent for data buffer prefix                 configuration.   @Param[in]     h_FmVsp    - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        Parse result pointer on success, NULL if parse result was not                 configured for this port.   @Cautions      Allowed only following FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_FmPrsResult
modifier|*
name|FM_VSP_GetBufferPrsResult
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_GetBufferTimeStamp   @Description   Returns the time stamp in the data buffer.                 Relevant for Rx ports for getting the buffer time stamp.                 See FM_VSP_ConfigBufferPrefixContent for data buffer prefix                 configuration.   @Param[in]     h_FmVsp    - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        A pointer to the hash result on success, NULL otherwise.   @Cautions      Allowed only following FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint64_t
modifier|*
name|FM_VSP_GetBufferTimeStamp
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_VSP_GetBufferHashResult   @Description   Given a data buffer, on the condition that hash result was defined                 as a part of the buffer content (see FM_VSP_ConfigBufferPrefixContent)                 this routine will return the pointer to the hash result location in the                 buffer prefix.   @Param[in]     h_FmVsp    - FM PORT module descriptor  @Param[in]     p_Data      - A pointer to the data buffer.   @Return        A pointer to the hash result on success, NULL otherwise.   @Cautions      Allowed only following FM_VSP_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|FM_VSP_GetBufferHashResult
parameter_list|(
name|t_Handle
name|h_FmVsp
parameter_list|,
name|char
modifier|*
name|p_Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_VSP_control_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_VSP_grp group */
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
comment|/* __FM_VSP_EXT_H */
end_comment

end_unit

