begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * @file  * @brief This file contains the mode page constants and data for the mode  *        pages supported by this translation implementation.  */
end_comment

begin_comment
comment|// DO NOT MOVE THIS INCLUDE STATEMENT! This include must occur before
end_comment

begin_comment
comment|// the below check for ENABLE_SATI_MODE_PAGES.
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_SATI_MODE_PAGES
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_mode_pages.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/intel_scsi.h>
end_include

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* C O N S T A N T S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE19_SAS_ID
value|0x6
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE19_SUB1_PAGE_NUM
value|0x1
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE19_SUB1_PC
value|0x59
end_define

begin_comment
comment|//******************************************************************************
end_comment

begin_comment
comment|//* M O D E   P A G E S
end_comment

begin_comment
comment|//******************************************************************************
end_comment

begin_decl_stmt
name|U8
name|sat_default_mode_page_01
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_READ_WRITE_ERROR
block|,
comment|// Byte 0 - Page Code, SPF(0), PS(0)
name|SCSI_MODE_PAGE_01_LENGTH
operator|-
literal|2
block|,
comment|// Byte 1 - Page Length
literal|0x80
block|,
comment|// Byte 2 - AWRE, ARRE, TB, RC, EER, PER, DTE, DCR
literal|0x00
block|,
comment|// Byte 3 - Read Retry Count
literal|0x00
block|,
comment|// Byte 4 - Obsolete
literal|0x00
block|,
comment|// Byte 5 - Obsolete
literal|0x00
block|,
comment|// Byte 6 - Obsolete
literal|0x00
block|,
comment|// Byte 7 - Restricted for MMC-4
literal|0x00
block|,
comment|// Byte 8 - Write Retry Count
literal|0x00
block|,
comment|// Byte 9 - Reserved
literal|0x00
block|,
comment|// Byte 10 - Recovery Time Limit
literal|0x00
block|,
comment|// Byte 11
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_changeable_mode_page_01
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_READ_WRITE_ERROR
block|,
name|SCSI_MODE_PAGE_01_LENGTH
operator|-
literal|2
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_default_mode_page_02
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_DISCONNECT_RECONNECT
block|,
comment|// Byte 0 - Page Code, SPF(0), PS(0)
name|SCSI_MODE_PAGE_02_LENGTH
operator|-
literal|2
block|,
comment|// Byte 1 - Page Length
literal|0x00
block|,
comment|// Byte 2 - Buffer Full Ratio
literal|0x00
block|,
comment|// Byte 3 - Buffer Empty Ratio
literal|0x00
block|,
comment|// Byte 4 - Bus Inactivity Limit
literal|0x00
block|,
comment|// Byte 5
literal|0x00
block|,
comment|// Byte 6 - Disconnect Time Limit
literal|0x00
block|,
comment|// Byte 7
literal|0x00
block|,
comment|// Byte 8 - Connect Time Limit
literal|0x00
block|,
comment|// Byte 9
literal|0x00
block|,
comment|// Byte 10 - Maximum Burst Size
literal|0x00
block|,
comment|// Byte 11
literal|0x00
block|,
comment|// Byte 12 - EMDP, FAIR_ARB, DIMM, DTDC
literal|0x00
block|,
comment|// Byte 13
literal|0x00
block|,
comment|// Byte 14 - First Burst Size
literal|0x00
block|,
comment|// Byte 15
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_changeable_mode_page_02
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_DISCONNECT_RECONNECT
block|,
name|SCSI_MODE_PAGE_02_LENGTH
operator|-
literal|2
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_default_mode_page_08
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_CACHING
block|,
comment|// Byte 0 - Page Code, SPF(0), PS(0)
name|SCSI_MODE_PAGE_08_LENGTH
operator|-
literal|2
block|,
comment|// Byte 1 - Page Length
literal|0x00
block|,
comment|// Byte 2 - IC, ABPF, CAP, DISC, SIZE, WCE(1), MF, RCD
literal|0x00
block|,
comment|// Byte 3 - Demand Read Retention Priority, Write Retention Priority
literal|0x00
block|,
comment|// Byte 4 - Disable Pre-Fetch Transfer Length
literal|0x00
block|,
comment|// Byte 5
literal|0x00
block|,
comment|// Byte 6 - Minimum Pre-Fetch
literal|0x00
block|,
comment|// Byte 7
literal|0x00
block|,
comment|// Byte 8 - Maximum Pre-Fetch
literal|0x00
block|,
comment|// Byte 9
literal|0x00
block|,
comment|// Byte 10 - Maximum Pre-Fetch Ceiling
literal|0x00
block|,
comment|// Byte 11
literal|0x00
block|,
comment|// Byte 12 - FSW, LBCSS, DRA(0), Vendor Specific, NV_DIS
literal|0x00
block|,
comment|// Byte 13 - Number of Cache Segments
literal|0x00
block|,
comment|// Byte 14 - Cache Segment Size
literal|0x00
block|,
comment|// Byte 15
literal|0x00
block|,
comment|// Byte 16 - Reserved
literal|0x00
block|,
comment|// Byte 17 - Non-Cache Segment Size
literal|0x00
block|,
comment|// Byte 18
literal|0x00
block|,
comment|// PAD
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_changeable_mode_page_08
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_CACHING
block|,
name|SCSI_MODE_PAGE_08_LENGTH
operator|-
literal|2
block|,
name|SCSI_MODE_PAGE_CACHE_PAGE_WCE_BIT
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
name|SCSI_MODE_PAGE_CACHE_PAGE_DRA_BIT
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|// PAD
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_default_mode_page_0A
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_CONTROL
block|,
comment|// Byte 0 - Page Code, SPF(0), PS(0)
name|SCSI_MODE_PAGE_0A_LENGTH
operator|-
literal|2
block|,
comment|// Byte 1 - Page Length
literal|0x00
block|,
comment|// Byte 2 - TST(0), TMF_ONLY(0), D_SENSE(0), GLTSD(0), RLEC(0)
literal|0x10
block|,
comment|// Byte 3 - Queue Algorithm(0), QErr(0)
literal|0x00
block|,
comment|// Byte 4 - TAS(0), RAC(0), UA_(0), SWP(0)
literal|0x00
block|,
comment|// Byte 5 - ATO(0), AUTOLOAD(0)
literal|0x00
block|,
comment|// Byte 6
literal|0x00
block|,
comment|// Byte 7
literal|0xFF
block|,
comment|// Byte 8 - Unlimited Busy timeout
literal|0xFF
block|,
comment|// Byte 9
literal|0x00
block|,
comment|// Byte 10 - do not support self time compl time xlation
literal|0x00
block|,
comment|// Byte 11
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_changeable_mode_page_0A
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_CONTROL
block|,
name|SCSI_MODE_PAGE_0A_LENGTH
operator|-
literal|2
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_default_mode_page_19
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_PROTOCOL_SPECIFIC_PORT
block|,
comment|// Byte 0 - PS, SPF, Page Code
name|SCSI_MODE_PAGE_19_LENGTH
operator|-
literal|2
block|,
comment|// Byte 1 - Page Length
name|SCSI_MODE_PAGE19_SAS_ID
block|,
comment|// Byte 2 - Rsvd, READY_LED,  ProtoID
literal|0x00
block|,
comment|// PAD
literal|0xFF
block|,
comment|// Byte 4 - IT NLT MSB, 0xFF retry forever
literal|0xFF
block|,
comment|// Byte 5 - IT NLT LSB, 0xFF retry forever
literal|0x00
block|,
comment|// Byte 6 - IRT MSB, 0x0 disable init resp timer
literal|0x00
block|,
comment|// Byte 7 - IRT LSB, 0x0 disable init resp timer
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_changeable_mode_page_19
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_PROTOCOL_SPECIFIC_PORT
block|,
name|SCSI_MODE_PAGE_19_LENGTH
operator|-
literal|2
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_default_mode_page_1C
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_INFORMATIONAL_EXCP_CONTROL
block|,
comment|// Byte 0 - Page Code,
comment|// SPF(0), PS(0)
name|SCSI_MODE_PAGE_1C_LENGTH
operator|-
literal|2
block|,
comment|// Byte 1 - Page Length
name|SCSI_MODE_PAGE_DEXCPT_ENABLE
block|,
comment|// Byte 2 - Perf, EBF, EWasc,
comment|// DExcpt(1), Test, LogErr
literal|0x06
block|,
comment|// Byte 3 -- MRIE (6 == values only available upon request)
literal|0x00
block|,
comment|// Byte 4 -- Interval Timer
literal|0x00
block|,
comment|// Byte 5
literal|0x00
block|,
comment|// Byte 6
literal|0x00
block|,
comment|// Byte 7
literal|0x00
block|,
comment|// Byte 8 -- Report Count
literal|0x00
block|,
comment|// Byte 9
literal|0x00
block|,
comment|// Byte 10
literal|0x00
block|,
comment|// Byte 11
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_changeable_mode_page_1C
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_INFORMATIONAL_EXCP_CONTROL
block|,
name|SCSI_MODE_PAGE_1C_LENGTH
operator|-
literal|2
block|,
name|SCSI_MODE_PAGE_DEXCPT_ENABLE
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
name|sat_supported_mode_pages
index|[]
init|=
block|{
name|SCSI_MODE_PAGE_READ_WRITE_ERROR
block|,
name|SCSI_MODE_PAGE_DISCONNECT_RECONNECT
block|,
name|SCSI_MODE_PAGE_CACHING
block|,
name|SCSI_MODE_PAGE_CONTROL
block|,
name|SCSI_MODE_PAGE_INFORMATIONAL_EXCP_CONTROL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
modifier|*
name|sat_changeable_mode_pages
index|[]
init|=
block|{
name|sat_changeable_mode_page_01
block|,
name|sat_changeable_mode_page_02
block|,
name|sat_changeable_mode_page_08
block|,
name|sat_changeable_mode_page_0A
block|,
name|sat_changeable_mode_page_1C
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U8
modifier|*
name|sat_default_mode_pages
index|[]
init|=
block|{
name|sat_default_mode_page_01
block|,
name|sat_default_mode_page_02
block|,
name|sat_default_mode_page_08
block|,
name|sat_default_mode_page_0A
block|,
name|sat_default_mode_page_1C
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|U16
name|sat_mode_page_sizes
index|[]
init|=
block|{
sizeof|sizeof
argument_list|(
name|sat_default_mode_page_01
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|sat_default_mode_page_02
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|sat_default_mode_page_08
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|sat_default_mode_page_0A
argument_list|)
block|,
expr|sizeof
operator|(
name|sat_default_mode_page_1C
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|U16
name|sati_mode_page_get_page_index
parameter_list|(
name|U8
name|page_code
parameter_list|)
block|{
name|U16
name|index
decl_stmt|;
for|for
control|(
name|index
operator|=
literal|0
init|;
name|index
operator|<
name|SAT_SUPPORTED_MODE_PAGES_LENGTH
condition|;
name|index
operator|++
control|)
block|{
if|if
condition|(
name|sat_supported_mode_pages
index|[
name|index
index|]
operator|==
name|page_code
condition|)
return|return
name|index
return|;
block|}
return|return
name|SATI_MODE_PAGE_UNSUPPORTED_INDEX
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(ENABLE_SATI_MODE_PAGES)
end_comment

end_unit

