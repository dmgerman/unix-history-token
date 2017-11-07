begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  BSD LICENSE  *  *  Copyright(c) 2017 Broadcom Corporation.  All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *    * Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    * Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in  *      the documentation and/or other materials provided with the  *      distribution.  *    * Neither the name of Broadcom Corporation nor the names of its  *      contributors may be used to endorse or promote products derived  *      from this software without specific prior written permission.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_PINCTRL_BRCM_STINGRAY_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_PINCTRL_BRCM_STINGRAY_H__
end_define

begin_comment
comment|/* Alternate functions available in MUX controller */
end_comment

begin_define
define|#
directive|define
name|MODE_NITRO
value|0
end_define

begin_define
define|#
directive|define
name|MODE_NAND
value|1
end_define

begin_define
define|#
directive|define
name|MODE_PNOR
value|2
end_define

begin_define
define|#
directive|define
name|MODE_GPIO
value|3
end_define

begin_comment
comment|/* Pad configuration attribute */
end_comment

begin_define
define|#
directive|define
name|PAD_SLEW_RATE_ENA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PAD_SLEW_RATE_ENA_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_2_MA
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_4_MA
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_6_MA
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_8_MA
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_10_MA
value|(4<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_12_MA
value|(5<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_14_MA
value|(6<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_16_MA
value|(7<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_DRIVE_STRENGTH_MASK
value|(7<< 1)
end_define

begin_define
define|#
directive|define
name|PAD_PULL_UP_ENA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PAD_PULL_UP_ENA_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PAD_PULL_DOWN_ENA
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PAD_PULL_DOWN_ENA_MASK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PAD_INPUT_PATH_DIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PAD_INPUT_PATH_DIS_MASK
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PAD_HYSTERESIS_ENA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PAD_HYSTERESIS_ENA_MASK
value|(1<< 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

