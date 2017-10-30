begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_pcd_ipc.h   @Description   FM PCD Inter-Partition prototypes, structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PCD_IPC_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_PCD_IPC_H
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for getting a sw parser address according to a label                 Fields commented 'IN' are passed by the port module to be used                 by the FM module.                 Fields commented 'OUT' will be filled by FM before returning to port. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdIpcSwPrsLable
block|{
name|uint32_t
name|enumHdr
decl_stmt|;
comment|/**< IN. The existence of this header will invoke                                                      the sw parser code. */
name|uint8_t
name|indexPerHdr
decl_stmt|;
comment|/**< IN. Normally 0, if more than one sw parser                                                      attachments for the same header, use this                                                     index to distinguish between them. */
block|}
name|_PackedType
name|t_FmPcdIpcSwPrsLable
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for port-PCD communication.                 Fields commented 'IN' are passed by the port module to be used                 by the FM module.                 Fields commented 'OUT' will be filled by FM before returning to port.                 Some fields are optional (depending on configuration) and                 will be analized by the port and FM modules accordingly. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdIpcKgSchemesParams
block|{
name|uint8_t
name|guestId
decl_stmt|;
name|uint8_t
name|numOfSchemes
decl_stmt|;
name|uint8_t
name|schemesIds
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdIpcKgSchemesParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdIpcKgClsPlanParams
block|{
name|uint8_t
name|guestId
decl_stmt|;
name|uint16_t
name|numOfClsPlanEntries
decl_stmt|;
name|uint8_t
name|clsPlanBase
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdIpcKgClsPlanParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdIpcPrsIncludePort
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
name|bool
name|include
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdIpcPrsIncludePort
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FM_PCD_MAX_REPLY_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_MSG_SIZE
value|36
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_REPLY_BODY_SIZE
value|36
end_define

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint32_t
name|msgId
decl_stmt|;
name|uint8_t
name|msgBody
index|[
name|FM_PCD_MAX_MSG_SIZE
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdIpcMsg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdIpcReply
block|{
name|uint32_t
name|error
decl_stmt|;
name|uint8_t
name|replyBody
index|[
name|FM_PCD_MAX_REPLY_BODY_SIZE
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdIpcReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcResourceAllocParams
block|{
name|uint8_t
name|guestId
decl_stmt|;
name|uint16_t
name|base
decl_stmt|;
name|uint16_t
name|num
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcResourceAllocParams
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
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ALLOC_KG_SCHEMES   @Description   Used by FM PCD front-end in order to allocate KG resources   @Param[in/out] t_FmPcdIpcKgAllocParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_ALLOC_KG_SCHEMES
value|3
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FREE_KG_SCHEMES   @Description   Used by FM PCD front-end in order to Free KG resources   @Param[in/out] t_FmPcdIpcKgSchemesParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_FREE_KG_SCHEMES
value|4
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ALLOC_PROFILES   @Description   Used by FM PCD front-end in order to allocate Policer profiles   @Param[in/out] t_FmIpcResourceAllocParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_ALLOC_PROFILES
value|5
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FREE_PROFILES   @Description   Used by FM PCD front-end in order to Free Policer profiles   @Param[in/out] t_FmIpcResourceAllocParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_FREE_PROFILES
value|6
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_SET_PORT_PROFILES   @Description   Used by FM PCD front-end in order to allocate Policer profiles                 for specific port   @Param[in/out] t_FmIpcResourceAllocParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_SET_PORT_PROFILES
value|7
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_CLEAR_PORT_PROFILES   @Description   Used by FM PCD front-end in order to allocate Policer profiles                 for specific port   @Param[in/out] t_FmIpcResourceAllocParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_CLEAR_PORT_PROFILES
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_GET_PHYS_MURAM_BASE   @Description   Used by FM PCD front-end in order to get MURAM base address   @Param[in/out] t_FmPcdIcPhysAddr Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_GET_PHYS_MURAM_BASE
value|9
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_GET_SW_PRS_OFFSET   @Description   Used by FM front-end to get the SW parser offset of the start of                 code relevant to a given label.   @Param[in/out] t_FmPcdIpcSwPrsLable Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_GET_SW_PRS_OFFSET
value|10
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MASTER_IS_ENABLED   @Description   Used by FM front-end in order to verify                 PCD enablement.   @Param[in]     bool Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MASTER_IS_ENABLED
value|15
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_GUEST_DISABLE   @Description   Used by FM front-end to inform back-end when                 front-end PCD is disabled   @Param[in]     None */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_GUEST_DISABLE
value|16
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_FREE_KG_CLSPLAN   @Description   Used by FM PCD front-end in order to Free KG classification plan entries   @Param[in/out] t_FmPcdIpcKgClsPlanParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_FREE_KG_CLSPLAN
value|22
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_ALLOC_KG_CLSPLAN   @Description   Used by FM PCD front-end in order to allocate KG classification plan entries   @Param[in/out] t_FmPcdIpcKgClsPlanParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_ALLOC_KG_CLSPLAN
value|23
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_MASTER_IS_ALIVE   @Description   Used by FM front-end to check that back-end exists   @Param[in]     None */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MASTER_IS_ALIVE
value|24
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_GET_COUNTER   @Description   Used by FM front-end to read PCD counters   @Param[in/out] t_FmPcdIpcGetCounter Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_GET_COUNTER
value|25
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_PCD_PRS_INC_PORT_STATS   @Description   Used by FM front-end to set/clear statistics for port   @Param[in/out] t_FmPcdIpcPrsIncludePort Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS_INC_PORT_STATS
value|26
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

begin_comment
comment|/* TODO - doc */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_ALLOC_SP
value|27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_PCD_IPC_grp group */
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
comment|/* __FM_PCD_IPC_H */
end_comment

end_unit

