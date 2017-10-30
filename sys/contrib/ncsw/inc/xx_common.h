begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          debug_ext.h   @Description   Debug mode definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XX_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|__XX_COMMON_H
end_define

begin_comment
comment|/*****************************************************************************  *  UNIFIED MODULE CODES  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MODULE_UNKNOWN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MODULE_FM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_MURAM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_PCD
value|0x00030000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_RTC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_MAC
value|0x00050000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_PORT
value|0x00060000
end_define

begin_define
define|#
directive|define
name|MODULE_MM
value|0x00070000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_SP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_MACSEC
value|0x00090000
end_define

begin_define
define|#
directive|define
name|MODULE_QM
value|0x000a0000
end_define

begin_define
define|#
directive|define
name|MODULE_BM
value|0x000b0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XX_COMMON_H */
end_comment

end_unit

