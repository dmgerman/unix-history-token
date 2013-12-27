begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_REMOTE_NODE_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_REMOTE_NODE_TABLE_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures, constants and prototypes used for  *        the remote node table.  */
end_comment

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
include|#
directive|include
file|<dev/isci/scil/sci_controller_constants.h>
comment|/**  * Remote node sets are sets of remote node index in the remtoe node table  * The SCU hardware requires that STP remote node entries take three  * consecutive remote node index so the table is arranged in sets of three.  * The bits are used as 0111 0111 to make a byte and the bits define the set  * of three remote nodes to use as a sequence.  */
define|#
directive|define
name|SCIC_SDS_REMOTE_NODE_SETS_PER_BYTE
value|2
comment|/**  * Since the remote node table is organized as DWORDS take the remote node  * sets in bytes and represent them in DWORDs. The lowest ordered bits are the  * ones used in case full DWORD is not being used.  *  * i.e. 0000 0000 0000 0000 0111 0111 0111 0111 // if only a single WORD is in  * use in the DWORD.  */
define|#
directive|define
name|SCIC_SDS_REMOTE_NODE_SETS_PER_DWORD
define|\
value|(sizeof(U32) * SCIC_SDS_REMOTE_NODE_SETS_PER_BYTE)
comment|/**  * This is a count of the numeber of remote nodes that can be represented in  * a byte  */
define|#
directive|define
name|SCIC_SDS_REMOTE_NODES_PER_BYTE
define|\
value|(SCU_STP_REMOTE_NODE_COUNT * SCIC_SDS_REMOTE_NODE_SETS_PER_BYTE)
comment|/**  * This is a count of the number of remote nodes that can be represented in a  * DWROD  */
define|#
directive|define
name|SCIC_SDS_REMOTE_NODES_PER_DWORD
define|\
value|(sizeof(U32) * SCIC_SDS_REMOTE_NODES_PER_BYTE)
comment|/**  * This is the number of bits in a remote node group  */
define|#
directive|define
name|SCIC_SDS_REMOTE_NODES_BITS_PER_GROUP
value|4
define|#
directive|define
name|SCIC_SDS_REMOTE_NODE_TABLE_INVALID_INDEX
value|(0xFFFFFFFF)
define|#
directive|define
name|SCIC_SDS_REMOTE_NODE_TABLE_FULL_SLOT_VALUE
value|(0x07)
define|#
directive|define
name|SCIC_SDS_REMOTE_NODE_TABLE_EMPTY_SLOT_VALUE
value|(0x00)
comment|/**  * Expander attached sata remote node count  */
define|#
directive|define
name|SCU_STP_REMOTE_NODE_COUNT
value|3
comment|/**  * Expander or direct attached ssp remote node count  */
define|#
directive|define
name|SCU_SSP_REMOTE_NODE_COUNT
value|1
comment|/**  * Direct attached STP remote node count  */
define|#
directive|define
name|SCU_SATA_REMOTE_NODE_COUNT
value|1
comment|/**  * @struct SCIC_REMOTE_NODE_TABLE  */
typedef|typedef
struct|struct
name|SCIC_REMOTE_NODE_TABLE
block|{
comment|/**     * This field contains the array size in dwords     */
name|U16
name|available_nodes_array_size
decl_stmt|;
comment|/**     * This field contains the array size of the     */
name|U16
name|group_array_size
decl_stmt|;
comment|/**     * This field is the array of available remote node entries in bits.     * Because of the way STP remote node data is allocated on the SCU hardware     * the remote nodes must occupy three consecutive remote node context     * entries.  For ease of allocation and de-allocation we have broken the     * sets of three into a single nibble.  When the STP RNi is allocated all     * of the bits in the nibble are cleared.  This math results in a table size     * of MAX_REMOTE_NODES / CONSECUTIVE RNi ENTRIES for STP / 2 entries per byte.     */
name|U32
name|available_remote_nodes
index|[
operator|(
name|SCI_MAX_REMOTE_DEVICES
operator|/
name|SCIC_SDS_REMOTE_NODES_PER_DWORD
operator|)
operator|+
operator|(
operator|(
name|SCI_MAX_REMOTE_DEVICES
operator|%
name|SCIC_SDS_REMOTE_NODES_PER_DWORD
operator|)
operator|!=
literal|0
operator|)
index|]
decl_stmt|;
comment|/**     * This field is the nibble selector for the above table.  There are three     * possible selectors each for fast lookup when trying to find one, two or     * three remote node entries.     */
name|U32
name|remote_node_groups
index|[
name|SCU_STP_REMOTE_NODE_COUNT
index|]
index|[
operator|(
name|SCI_MAX_REMOTE_DEVICES
operator|/
operator|(
literal|32
operator|*
name|SCU_STP_REMOTE_NODE_COUNT
operator|)
operator|)
operator|+
operator|(
operator|(
name|SCI_MAX_REMOTE_DEVICES
operator|%
operator|(
literal|32
operator|*
name|SCU_STP_REMOTE_NODE_COUNT
operator|)
operator|)
operator|!=
literal|0
operator|)
index|]
decl_stmt|;
block|}
name|SCIC_REMOTE_NODE_TABLE_T
typedef|;
comment|// ---------------------------------------------------------------------------
name|void
name|scic_sds_remote_node_table_initialize
parameter_list|(
name|SCIC_REMOTE_NODE_TABLE_T
modifier|*
name|remote_node_table
parameter_list|,
name|U32
name|remote_node_entries
parameter_list|)
function_decl|;
name|U16
name|scic_sds_remote_node_table_allocate_remote_node
parameter_list|(
name|SCIC_REMOTE_NODE_TABLE_T
modifier|*
name|remote_node_table
parameter_list|,
name|U32
name|remote_node_count
parameter_list|)
function_decl|;
name|void
name|scic_sds_remote_node_table_release_remote_node_index
parameter_list|(
name|SCIC_REMOTE_NODE_TABLE_T
modifier|*
name|remote_node_table
parameter_list|,
name|U32
name|remote_node_count
parameter_list|,
name|U16
name|remote_node_index
parameter_list|)
function_decl|;
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
comment|// _SCIC_SDS_REMOTE_NODE_TABLE_H_
end_comment

end_unit

