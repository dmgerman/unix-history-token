begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_iwm.c,v 1.39 2015/03/23 00:35:19 jsg Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2014 genua mbh<info@genua.de>  * Copyright (c) 2014 Fixup Software Ltd.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  * Driver version we are currently based off of is  * Linux 3.14.3 (tag id a2df521e42b1d9a23f620ac79dbfe8655a8391dd)  *  ***********************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2007 - 2013 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<ilw@linux.intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  *  * BSD LICENSE  *  * Copyright(c) 2005 - 2013 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007-2010 Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWM_PHY_DB_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWM_PHY_DB_H__
end_define

begin_enum
enum|enum
name|iwm_phy_db_section_type
block|{
name|IWM_PHY_DB_CFG
init|=
literal|1
block|,
name|IWM_PHY_DB_CALIB_NCH
block|,
name|IWM_PHY_DB_UNUSED
block|,
name|IWM_PHY_DB_CALIB_CHG_PAPD
block|,
name|IWM_PHY_DB_CALIB_CHG_TXP
block|,
name|IWM_PHY_DB_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_PHY_DB_CMD
value|0x6c
end_define

begin_comment
comment|/* TEMP API - The actual is 0x8c */
end_comment

begin_comment
comment|/*  * phy db - configure operational ucode  */
end_comment

begin_struct
struct|struct
name|iwm_phy_db_cmd
block|{
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* for parsing of tx power channel group data that comes from the firmware*/
end_comment

begin_struct
struct|struct
name|iwm_phy_db_chg_txp
block|{
name|uint32_t
name|space
decl_stmt|;
name|uint16_t
name|max_channel_idx
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * phy db - Receive phy db chunk after calibrations  */
end_comment

begin_struct
struct|struct
name|iwm_calib_res_notif_phy_db
block|{
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|iwm_phy_db_set_section
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|iwm_calib_res_notif_phy_db
modifier|*
name|phy_db_notif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iwm_send_phy_db_data
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWM_PHY_DB_H__ */
end_comment

end_unit

