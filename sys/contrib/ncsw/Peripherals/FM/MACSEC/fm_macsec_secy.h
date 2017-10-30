begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2015 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_macsec_secy.h   @Description   FM MACSEC SecY internal structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_MACSEC_SECY_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_MACSEC_SECY_H
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
file|"fm_macsec.h"
end_include

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
name|FM_MACSEC_SECY_EX_FRAME_DISCARDED
value|0x80000000
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
value|switch (exception){     \     case e_FM_MACSEC_SECY_EX_FRAME_DISCARDED:                           \         bitMask = FM_MACSEC_SECY_EX_FRAME_DISCARDED; break;             \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Events */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MACSEC_SECY_EV_NEXT_PN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|GET_EVENT_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|event
parameter_list|)
value|switch (event){     \     case e_FM_MACSEC_SECY_EV_NEXT_PN:                               \         bitMask = FM_MACSEC_SECY_EV_NEXT_PN; break;                 \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_exceptions
value|(FM_MACSEC_SECY_EX_FRAME_DISCARDED)
end_define

begin_define
define|#
directive|define
name|DEFAULT_events
value|(FM_MACSEC_SECY_EV_NEXT_PN)
end_define

begin_define
define|#
directive|define
name|DEFAULT_numOfTxSc
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_confidentialityEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_confidentialityOffset
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_sciInsertionMode
value|e_FM_MACSEC_SCI_INSERTION_MODE_EXPLICIT_SECTAG
end_define

begin_define
define|#
directive|define
name|DEFAULT_validateFrames
value|e_FM_MACSEC_VALID_FRAME_BEHAVIOR_STRICT
end_define

begin_define
define|#
directive|define
name|DEFAULT_replayEnable
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_replayWindow
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_protectFrames
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_ptp
value|FALSE
end_define

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
name|SECY_AN_FREE_VALUE
value|MAX_NUM_OF_SA_PER_SC
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|e_ScSaId
name|saId
decl_stmt|;
name|bool
name|active
decl_stmt|;
union|union
block|{
name|t_FmMacsecSecYRxSaStatistics
name|rxSaStatistics
decl_stmt|;
name|t_FmMacsecSecYTxSaStatistics
name|txSaStatistics
decl_stmt|;
block|}
union|;
block|}
name|t_SecYSa
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|inUse
decl_stmt|;
name|uint32_t
name|scId
decl_stmt|;
name|e_ScType
name|type
decl_stmt|;
name|uint8_t
name|numOfSa
decl_stmt|;
name|t_SecYSa
name|sa
index|[
name|MAX_NUM_OF_SA_PER_SC
index|]
decl_stmt|;
union|union
block|{
name|t_FmMacsecSecYRxScStatistics
name|rxScStatistics
decl_stmt|;
name|t_FmMacsecSecYTxScStatistics
name|txScStatistics
decl_stmt|;
block|}
union|;
block|}
name|t_SecYSc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmMacsecSecYSCParams
name|txScParams
decl_stmt|;
comment|/**< Tx SC Params */
block|}
name|t_FmMacsecSecYDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_FmMacsec
decl_stmt|;
name|bool
name|confidentialityEnable
decl_stmt|;
comment|/**< TRUE  - confidentiality protection and integrity protection                                                                      FALSE - no confidentiality protection, only integrity protection*/
name|uint16_t
name|confidentialityOffset
decl_stmt|;
comment|/**< The number of initial octets of each MSDU without confidentiality protection                                                                      common values are 0, 30, and 50 */
name|bool
name|replayProtect
decl_stmt|;
comment|/**< replay protection function mode */
name|uint32_t
name|replayWindow
decl_stmt|;
comment|/**< the size of the replay window */
name|e_FmMacsecValidFrameBehavior
name|validateFrames
decl_stmt|;
comment|/**< validation function mode */
name|e_FmMacsecSciInsertionMode
name|sciInsertionMode
decl_stmt|;
name|bool
name|protectFrames
decl_stmt|;
name|bool
name|isPointToPoint
decl_stmt|;
name|e_FmMacsecSecYCipherSuite
name|cipherSuite
decl_stmt|;
comment|/**< Cipher suite to be used for this SecY */
name|uint32_t
name|numOfRxSc
decl_stmt|;
comment|/**< Number of receive channels */
name|uint32_t
name|numOfTxSc
decl_stmt|;
comment|/**< Number of transmit channels */
name|t_SecYSc
modifier|*
name|p_RxSc
decl_stmt|;
name|t_SecYSc
modifier|*
name|p_TxSc
decl_stmt|;
name|uint32_t
name|events
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|t_FmMacsecSecYExceptionsCallback
modifier|*
name|f_Exception
decl_stmt|;
comment|/**< TODO */
name|t_FmMacsecSecYEventsCallback
modifier|*
name|f_Event
decl_stmt|;
comment|/**< TODO */
name|t_Handle
name|h_App
decl_stmt|;
name|t_FmMacsecSecYStatistics
name|statistics
decl_stmt|;
name|t_FmMacsecSecYDriverParam
modifier|*
name|p_FmMacsecSecYDriverParam
decl_stmt|;
block|}
name|t_FmMacsecSecY
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_MACSEC_SECY_H */
end_comment

end_unit

