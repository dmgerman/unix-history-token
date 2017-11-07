begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FMAN_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|__FMAN_COMMON_H
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Description       NIA Description */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NIA_ORDER_RESTOR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_FM_CTL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_PRS
value|0x00440000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_KG
value|0x00480000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_PLCR
value|0x004C0000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_BMI
value|0x00500000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_QMI_ENQ
value|0x00540000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_QMI_DEQ
value|0x00580000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_MASK
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_CC
value|0x00000006
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_HC
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_IND_MODE_TX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_IND_MODE_RX
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_FRAG
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_FETCH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_FETCH_PCD
value|0x00000012
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_FETCH_PCD_UDP_LEN
value|0x00000018
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_FETCH_NO_PCD
value|0x00000012
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_FRAG_CHECK
value|0x00000014
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_CC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_ENQ_FRAME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_TX_RELEASE
value|0x000002C0
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_RELEASE
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_DISCARD
value|0x000000C1
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_TX
value|0x00000274
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_FETCH
value|0x00000208
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|NIA_KG_DIRECT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NIA_KG_CC_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NIA_PLCR_ABSOLUTE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_ENQ_FRAME_WITHOUT_DMA
value|0x00000202
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_FETCH_ALL_FRAME
value|0x0000020c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FMAN_COMMON_H */
end_comment

end_unit

