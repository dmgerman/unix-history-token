begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          QM_ipc.h   @Description   QM Inter-Partition prototypes, structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QM_IPC_H
end_ifndef

begin_define
define|#
directive|define
name|__QM_IPC_H
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
comment|/**  @Group         QM_grp Frame Manager API   @Description   QM API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         QM_IPC_grp Qm Inter-Partition messaging Unit   @Description   QM Inter-Partition messaging unit API definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|QM_FORCE_FQID
value|1
end_define

begin_define
define|#
directive|define
name|QM_PUT_FQID
value|2
end_define

begin_define
define|#
directive|define
name|QM_GET_COUNTER
value|3
end_define

begin_define
define|#
directive|define
name|QM_GET_SET_PORTAL_PARAMS
value|4
end_define

begin_define
define|#
directive|define
name|QM_GET_REVISION
value|5
end_define

begin_define
define|#
directive|define
name|QM_MASTER_IS_ALIVE
value|6
end_define

begin_define
define|#
directive|define
name|QM_IPC_MAX_REPLY_BODY_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_IPC_MAX_REPLY_SIZE
value|(QM_IPC_MAX_REPLY_BODY_SIZE + sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|QM_IPC_MAX_MSG_SIZE
value|30
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
name|t_QmIpcMsg
block|{
name|uint32_t
name|msgId
decl_stmt|;
name|uint8_t
name|msgBody
index|[
name|QM_IPC_MAX_MSG_SIZE
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_QmIpcMsg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_QmIpcReply
block|{
name|uint32_t
name|error
decl_stmt|;
name|uint8_t
name|replyBody
index|[
name|QM_IPC_MAX_REPLY_BODY_SIZE
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_QmIpcReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_QmIpcGetCounter
block|{
name|uint32_t
name|enumId
decl_stmt|;
comment|/**< IN */
block|}
name|_PackedType
name|t_QmIpcGetCounter
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_QmIpcFqidParams
block|{
name|uint32_t
name|fqid
decl_stmt|;
comment|/**< IN */
name|uint32_t
name|size
decl_stmt|;
comment|/**< IN */
block|}
name|_PackedType
name|t_QmIpcFqidParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_QmIpcPortalInitParams
block|{
name|uint8_t
name|portalId
decl_stmt|;
comment|/**< IN */
name|uint8_t
name|stashDestQueue
decl_stmt|;
comment|/**< IN */
name|uint16_t
name|liodn
decl_stmt|;
comment|/**< IN */
name|uint16_t
name|dqrrLiodn
decl_stmt|;
comment|/**< IN */
name|uint16_t
name|fdFqLiodn
decl_stmt|;
comment|/**< IN */
block|}
name|_PackedType
name|t_QmIpcPortalInitParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_QmIpcRevisionInfo
block|{
name|uint8_t
name|majorRev
decl_stmt|;
comment|/**< OUT: Major revision */
name|uint8_t
name|minorRev
decl_stmt|;
comment|/**< OUT: Minor revision */
block|}
name|_PackedType
name|t_QmIpcRevisionInfo
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
comment|/** @} */
end_comment

begin_comment
comment|/* end of QM_IPC_grp group */
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
comment|/* __QM_IPC_H */
end_comment

end_unit

