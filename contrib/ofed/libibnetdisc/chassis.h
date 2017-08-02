begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2007 Voltaire Inc.  All rights reserved.  * Copyright (c) 2007 Xsigo Systems Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHASSIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CHASSIS_H_
end_define

begin_include
include|#
directive|include
file|<infiniband/ibnetdisc.h>
end_include

begin_include
include|#
directive|include
file|"internal.h"
end_include

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

begin_define
define|#
directive|define
name|VTR_DEVID_SLB4018
value|0x5a5b
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB4700
value|0x5a5c
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB4700X2
value|0x5a5d
end_define

begin_define
define|#
directive|define
name|VTR_DEVID_SFB4200
value|0x5a60
end_define

begin_define
define|#
directive|define
name|MLX_DEVID_IS4
value|0xbd36
end_define

begin_comment
comment|/* Vendor IDs (for chassis based systems) */
end_comment

begin_define
define|#
directive|define
name|VTR_VENDOR_ID
value|0x8f1
end_define

begin_comment
comment|/* Voltaire */
end_comment

begin_define
define|#
directive|define
name|MLX_VENDOR_ID
value|0x2c9
end_define

begin_comment
comment|/* Mellanox */
end_comment

begin_define
define|#
directive|define
name|TS_VENDOR_ID
value|0x5ad
end_define

begin_comment
comment|/* Cisco */
end_comment

begin_define
define|#
directive|define
name|SS_VENDOR_ID
value|0x66a
end_define

begin_comment
comment|/* InfiniCon */
end_comment

begin_define
define|#
directive|define
name|XS_VENDOR_ID
value|0x1397
end_define

begin_comment
comment|/* Xsigo */
end_comment

begin_enum
enum|enum
name|ibnd_chassis_type
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
block|,
name|ISR4700_CT
block|,
name|ISR4200_CT
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ibnd_chassis_slot_type
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

begin_function_decl
name|int
name|group_nodes
parameter_list|(
name|struct
name|ibnd_fabric
modifier|*
name|fabric
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CHASSIS_H_ */
end_comment

end_unit

