begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting, Atheros  * Communications, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the following conditions are met:  * 1. The materials contained herein are unmodified and are used  *    unmodified.  * 2. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following NO  *    ''WARRANTY'' disclaimer below (''Disclaimer''), without  *    modification.  * 3. Redistributions in binary form must reproduce at minimum a  *    disclaimer similar to the Disclaimer below and any redistribution  *    must be conditioned upon including a substantially similar  *    Disclaimer requirement for further binary redistribution.  * 4. Neither the names of the above-listed copyright holders nor the  *    names of any contributors may be used to endorse or promote  *    product derived from this software without specific prior written  *    permission.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT,  * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE  * FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGES.  *  * $Id: ah_devid.h,v 1.6 2003/06/25 04:50:22 sam Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_DEVID_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_DEVID_H_
end_define

begin_define
define|#
directive|define
name|ATHEROS_VENDOR_ID
value|0x168c
end_define

begin_comment
comment|/* Atheros PCI vendor ID */
end_comment

begin_comment
comment|/* AR5210 (for reference) */
end_comment

begin_define
define|#
directive|define
name|AR5210_DEFAULT
value|0x1107
end_define

begin_comment
comment|/* No eeprom HW default */
end_comment

begin_define
define|#
directive|define
name|AR5210_PROD
value|0x0007
end_define

begin_comment
comment|/* Final device ID */
end_comment

begin_define
define|#
directive|define
name|AR5210_AP
value|0x0207
end_define

begin_comment
comment|/* Early AP11s */
end_comment

begin_comment
comment|/* AR5211 */
end_comment

begin_define
define|#
directive|define
name|AR5211_DEFAULT
value|0x1112
end_define

begin_comment
comment|/* No eeprom HW default */
end_comment

begin_define
define|#
directive|define
name|AR5311_DEVID
value|0x0011
end_define

begin_comment
comment|/* Final ar5311 devid */
end_comment

begin_define
define|#
directive|define
name|AR5211_DEVID
value|0x0012
end_define

begin_comment
comment|/* Final ar5211 devid */
end_comment

begin_define
define|#
directive|define
name|AR5211_LEGACY
value|0xff12
end_define

begin_comment
comment|/* Original emulation board */
end_comment

begin_define
define|#
directive|define
name|AR5211_FPGA11B
value|0xf11b
end_define

begin_comment
comment|/* 11b emulation board */
end_comment

begin_comment
comment|/* AR5212 */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEFAULT
value|0x1113
end_define

begin_comment
comment|/* No eeprom HW default */
end_comment

begin_define
define|#
directive|define
name|AR5212_DEVID
value|0x0013
end_define

begin_comment
comment|/* Final ar5212 devid */
end_comment

begin_define
define|#
directive|define
name|AR5212_FPGA
value|0xf013
end_define

begin_comment
comment|/* Emulation board */
end_comment

begin_define
define|#
directive|define
name|AR_SUBVENDOR_ID_NOG
value|0x0e11
end_define

begin_comment
comment|/* No 11G subvendor ID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_DEVID_H */
end_comment

end_unit

