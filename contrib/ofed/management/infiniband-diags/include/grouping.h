begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2007 Voltaire Inc.  All rights reserved.  * Copyright (c) 2007 Xsigo Systems Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GROUPING_H_
end_ifndef

begin_define
define|#
directive|define
name|_GROUPING_H_
end_define

begin_comment
comment|/*========================================================*/
end_comment

begin_comment
comment|/*               FABRIC SCANNER SPECIFIC DATA             */
end_comment

begin_comment
comment|/*========================================================*/
end_comment

begin_define
define|#
directive|define
name|SPINES_MAX_NUM
value|12
end_define

begin_define
define|#
directive|define
name|LINES_MAX_NUM
value|36
end_define

begin_typedef
typedef|typedef
name|struct
name|ChassisList
name|ChassisList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|AllChassisList
name|AllChassisList
typedef|;
end_typedef

begin_struct
struct|struct
name|ChassisList
block|{
name|ChassisList
modifier|*
name|next
decl_stmt|;
name|uint64_t
name|chassisguid
decl_stmt|;
name|int
name|chassisnum
decl_stmt|;
name|int
name|chassistype
decl_stmt|;
name|int
name|nodecount
decl_stmt|;
comment|/* used for grouping by SystemImageGUID */
name|Node
modifier|*
name|spinenode
index|[
name|SPINES_MAX_NUM
operator|+
literal|1
index|]
decl_stmt|;
name|Node
modifier|*
name|linenode
index|[
name|LINES_MAX_NUM
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|AllChassisList
block|{
name|ChassisList
modifier|*
name|first
decl_stmt|;
name|ChassisList
modifier|*
name|current
decl_stmt|;
name|ChassisList
modifier|*
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*========================================================*/
end_comment

begin_comment
comment|/*                CHASSIS RECOGNITION SPECIFIC DATA       */
end_comment

begin_comment
comment|/*========================================================*/
end_comment

begin_comment
comment|/* Device IDs */
end_comment

begin_define
define|#
directive|define
name|VTR_DEVID_IB_FC_ROUTER
value|0x5a00
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_IB_IP_ROUTER
value|0x5a01
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR9600_SPINE
value|0x5a02
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR9600_LEAF
value|0x5a03
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_HCA1
value|0x5a04
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_HCA2
value|0x5a44
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_HCA3
value|0x6278
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SW_6IB4
value|0x5a05
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR9024
value|0x5a06
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR9288
value|0x5a07
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SLB24
value|0x5a09
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB12
value|0x5a08
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB4
value|0x5a0b
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR9024_12
value|0x5a0c
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SLB8
value|0x5a0d
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_RLX_SWITCH_BLADE
value|0x5a20
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR9024_DDR
value|0x5a31
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB12_DDR
value|0x5a32
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB4_DDR
value|0x5a33
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SLB24_DDR
value|0x5a34
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB2012
value|0x5a37
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SLB2024
value|0x5a38
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR2012
value|0x5a39
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB2004
value|0x5a40
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_ISR2004
value|0x5a41
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SRB2004
value|0x5a42
end_define

begin_enum
enum|enum
name|ChassisType
block|{
name|UNRESOLVED_CT
block|,
name|ISR9288_CT
block|,
name|ISR9096_CT
block|,
name|ISR2012_CT
block|,
name|ISR2004_CT
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ChassisSlot
block|{
name|UNRESOLVED_CS
block|,
name|LINE_CS
block|,
name|SPINE_CS
block|,
name|SRBD_CS
block|}
enum|;
end_enum

begin_comment
comment|/*========================================================*/
end_comment

begin_comment
comment|/*                External interface                      */
end_comment

begin_comment
comment|/*========================================================*/
end_comment

begin_function_decl
name|ChassisList
modifier|*
name|group_nodes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|portmapstring
parameter_list|(
name|Port
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_chassis_type
parameter_list|(
name|unsigned
name|char
name|chassistype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_chassis_slot
parameter_list|(
name|unsigned
name|char
name|chassisslot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|get_chassis_guid
parameter_list|(
name|unsigned
name|char
name|chassisnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_xsigo_guid
parameter_list|(
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_xsigo_tca
parameter_list|(
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_xsigo_hca
parameter_list|(
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GROUPING_H_ */
end_comment

end_unit

