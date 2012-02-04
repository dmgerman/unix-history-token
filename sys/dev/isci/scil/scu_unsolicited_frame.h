begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  *  * @brief This field defines the SCU format of an unsolicited frame (UF).  A  *        UF is a frame received by the SCU for which there is no known  *        corresponding task context (TC).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCU_UNSOLICITED_FRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCU_UNSOLICITED_FRAME_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
comment|/**  * This constant defines the number of DWORDS found the unsolicited frame  * header data member.  */
define|#
directive|define
name|SCU_UNSOLICITED_FRAME_HEADER_DATA_DWORDS
value|15
comment|/**  * @struct SCU_UNSOLICITED_FRAME_HEADER  *  * This structure delineates the format of an unsolicited frame header.  * The first DWORD are UF attributes defined by the silicon architecture.  * The data depicts actual header information received on the link.  */
typedef|typedef
struct|struct
name|SCU_UNSOLICITED_FRAME_HEADER
block|{
comment|/**     * This field indicates if there is an Initiator Index Table entry with     * which this header is associated.     */
name|U32
name|iit_exists
range|:
literal|1
decl_stmt|;
comment|/**     * This field simply indicates the protocol type (i.e. SSP, STP, SMP).     */
name|U32
name|protocol_type
range|:
literal|3
decl_stmt|;
comment|/**     * This field indicates if the frame is an address frame (IAF or OAF)     * or if it is a information unit frame.     */
name|U32
name|is_address_frame
range|:
literal|1
decl_stmt|;
comment|/**     * This field simply indicates the connection rate at which the frame     * was received.     */
name|U32
name|connection_rate
range|:
literal|4
decl_stmt|;
name|U32
name|reserved
range|:
literal|23
decl_stmt|;
comment|/**     * This field represents the actual header data received on the link.     */
name|U32
name|data
index|[
name|SCU_UNSOLICITED_FRAME_HEADER_DATA_DWORDS
index|]
decl_stmt|;
block|}
name|SCU_UNSOLICITED_FRAME_HEADER_T
typedef|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCU_UNSOLICITED_FRAME_H_
end_comment

end_unit

