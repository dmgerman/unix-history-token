begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_DEVIDS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_DEVIDS_H_
end_define

begin_comment
comment|/* Vendor ID */
end_comment

begin_define
define|#
directive|define
name|I40E_INTEL_VENDOR_ID
value|0x8086
end_define

begin_comment
comment|/* Device IDs */
end_comment

begin_define
define|#
directive|define
name|I40E_DEV_ID_SFP_XL710
value|0x1572
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_QEMU
value|0x1574
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_KX_B
value|0x1580
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_KX_C
value|0x1581
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_QSFP_A
value|0x1583
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_QSFP_B
value|0x1584
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_QSFP_C
value|0x1585
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_10G_BASE_T
value|0x1586
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_20G_KR2
value|0x1587
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_20G_KR2_A
value|0x1588
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_10G_BASE_T4
value|0x1589
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_25G_B
value|0x158A
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_25G_SFP28
value|0x158B
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_VF
value|0x154C
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_VF_HV
value|0x1571
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_X722_A0
value|0x374C
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_X722_A0_VF
value|0x374D
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_KX_X722
value|0x37CE
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_QSFP_X722
value|0x37CF
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_SFP_X722
value|0x37D0
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_1G_BASE_T_X722
value|0x37D1
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_10G_BASE_T_X722
value|0x37D2
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_SFP_I_X722
value|0x37D3
end_define

begin_define
define|#
directive|define
name|I40E_DEV_ID_X722_VF
value|0x37CD
end_define

begin_define
define|#
directive|define
name|i40e_is_40G_device
parameter_list|(
name|d
parameter_list|)
value|((d) == I40E_DEV_ID_QSFP_A  || \ 					 (d) == I40E_DEV_ID_QSFP_B  || \ 					 (d) == I40E_DEV_ID_QSFP_C)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_DEVIDS_H_ */
end_comment

end_unit

