begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Module names for debug messages */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|moduleStrings
index|[]
init|=
block|{
literal|"???"
comment|/* MODULE_UNKNOWN */
block|,
literal|"MEM"
comment|/* MODULE_ */
block|,
literal|"MM"
comment|/* MODULE_MM */
block|,
literal|"CORE"
comment|/* MODULE_CORE */
block|,
literal|"P3041"
comment|/* MODULE_P3041 */
block|,
literal|"P3041-Platform"
comment|/* MODULE_P3041_PLTFRM */
block|,
literal|"PM"
comment|/* MODULE_PM */
block|,
literal|"MMU"
comment|/* MODULE_MMU */
block|,
literal|"PIC"
comment|/* MODULE_PIC */
block|,
literal|"L3 cache (CPC)"
comment|/* MODULE_CPC */
block|,
literal|"DUART"
comment|/* MODULE_DUART */
block|,
literal|"SerDes"
comment|/* MODULE_SERDES */
block|,
literal|"PIO"
comment|/* MODULE_PIO */
block|,
literal|"QM"
comment|/* MODULE_QM */
block|,
literal|"BM"
comment|/* MODULE_BM */
block|,
literal|"SEC"
comment|/* MODULE_SEC */
block|,
literal|"LAW"
comment|/* MODULE_LAW */
block|,
literal|"LBC"
comment|/* MODULE_LBC */
block|,
literal|"PAMU"
comment|/* MODULE_PAMU */
block|,
literal|"FM"
comment|/* MODULE_FM */
block|,
literal|"FM-MURAM"
comment|/* MODULE_FM_MURAM */
block|,
literal|"FM-PCD"
comment|/* MODULE_FM_PCD */
block|,
literal|"FM-RTC"
comment|/* MODULE_FM_RTC */
block|,
literal|"FM-MAC"
comment|/* MODULE_FM_MAC */
block|,
literal|"FM-Port"
comment|/* MODULE_FM_PORT */
block|,
literal|"DPA"
comment|/* MODULE_DPA */
block|}
decl_stmt|;
end_decl_stmt

end_unit

