begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTT_REG_ADDR_H
end_ifndef

begin_define
define|#
directive|define
name|GTT_REG_ADDR_H
end_define

begin_comment
comment|/* Win 2 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_IGU_CMD
value|0x00f000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 3 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_TSDM_RAM
value|0x010000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 4 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_MSDM_RAM
value|0x011000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 5 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_MSDM_RAM_1024
value|0x012000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 6 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_USDM_RAM
value|0x013000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 7 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_USDM_RAM_1024
value|0x014000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 8 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_USDM_RAM_2048
value|0x015000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 9 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_XSDM_RAM
value|0x016000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 10 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_YSDM_RAM
value|0x017000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_comment
comment|/* Win 11 */
end_comment

begin_define
define|#
directive|define
name|GTT_BAR0_MAP_REG_PSDM_RAM
value|0x018000UL
end_define

begin_comment
comment|//Access:RW   DataWidth:0x20   //
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

