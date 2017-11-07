begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_replic.h   @Description   FM frame replicator */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_REPLIC_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_REPLIC_H
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

begin_define
define|#
directive|define
name|FRM_REPLIC_SOURCE_TD_OPCODE
value|0x75
end_define

begin_define
define|#
directive|define
name|NEXT_FRM_REPLIC_ADDR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|NEXT_FRM_REPLIC_MEMBER_INDEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FRM_REPLIC_FR_BIT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FRM_REPLIC_NL_BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FRM_REPLIC_INVALID_MEMBER_INDEX
value|0xffff
end_define

begin_define
define|#
directive|define
name|FRM_REPLIC_FIRST_MEMBER_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|FRM_REPLIC_MIDDLE_MEMBER_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|FRM_REPLIC_LAST_MEMBER_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|SOURCE_TD_ITSELF_OPTION
value|0x01
end_define

begin_define
define|#
directive|define
name|SOURCE_TD_COPY_OPTION
value|0x02
end_define

begin_define
define|#
directive|define
name|SOURCE_TD_ITSELF_AND_COPY_OPTION
value|SOURCE_TD_ITSELF_OPTION | SOURCE_TD_COPY_OPTION
end_define

begin_define
define|#
directive|define
name|SOURCE_TD_NONE
value|0x04
end_define

begin_comment
comment|/*typedef enum e_SourceTdOption {     e_SOURCE_TD_NONE = 0,     e_SOURCE_TD_ITSELF_OPTION = 1,     e_SOURCE_TD_COPY_OPTION = 2,     e_SOURCE_TD_ITSELF_AND_COPY_OPTION = e_SOURCE_TD_ITSELF_OPTION | e_SOURCE_TD_COPY_OPTION } e_SourceTdOption; */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|type
decl_stmt|;
specifier|volatile
name|uint32_t
name|frGroupPointer
decl_stmt|;
specifier|volatile
name|uint32_t
name|operationCode
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|t_FrmReplicGroupSourceAd
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdFrmReplicMember
block|{
name|void
modifier|*
name|p_MemberAd
decl_stmt|;
comment|/**< pointer to the member AD */
name|void
modifier|*
name|p_StatisticsAd
decl_stmt|;
comment|/**< pointer to the statistics AD of the member */
name|t_Handle
name|h_Manip
decl_stmt|;
comment|/**< manip handle - need for free routines */
name|t_List
name|node
decl_stmt|;
block|}
name|t_FmPcdFrmReplicMember
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdFrmReplicGroup
block|{
name|t_Handle
name|h_FmPcd
decl_stmt|;
name|uint8_t
name|maxNumOfEntries
decl_stmt|;
comment|/**< maximal number of members in the group */
name|uint8_t
name|numOfEntries
decl_stmt|;
comment|/**< actual number of members in the group */
name|uint16_t
name|owners
decl_stmt|;
comment|/**< how many keys share this frame replicator group */
name|void
modifier|*
name|p_SourceTd
decl_stmt|;
comment|/**< pointer to the frame replicator source table descriptor */
name|t_List
name|membersList
decl_stmt|;
comment|/**< the members list - should reflect the order of the members as in the hw linked list*/
name|t_List
name|availableMembersList
decl_stmt|;
comment|/**< list of all the available members in the group */
name|t_FmPcdLock
modifier|*
name|p_Lock
decl_stmt|;
block|}
name|t_FmPcdFrmReplicGroup
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_REPLIC_H */
end_comment

end_unit

