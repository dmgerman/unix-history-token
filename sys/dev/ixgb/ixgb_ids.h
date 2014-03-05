begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2004, Intel Corporation   All rights reserved.      Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGB_IDS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGB_IDS_H_
end_define

begin_comment
comment|/********************************************************************** ** The Device IDs for 10 Gigabit MACs **********************************************************************/
end_comment

begin_define
define|#
directive|define
name|IXGB_DEVICE_ID_82597EX
value|0x1048
end_define

begin_comment
comment|/* Cibolo A1, -LR (1310nm) */
end_comment

begin_define
define|#
directive|define
name|IXGB_DEVICE_ID_82597EX_SR
value|0x1A48
end_define

begin_comment
comment|/* Cibolo B0, -SR (850nm)  */
end_comment

begin_define
define|#
directive|define
name|IXGB_SUBDEVICE_ID_A11F
value|0xA11F
end_define

begin_comment
comment|/* Adapter-OEM-1310nm-Fiber */
end_comment

begin_define
define|#
directive|define
name|IXGB_SUBDEVICE_ID_A01F
value|0xA01F
end_define

begin_comment
comment|/* Adapter-Retail-1310nm-Fiber */
end_comment

begin_define
define|#
directive|define
name|IXGB_SUBDEVICE_ID_A15F
value|0xA15F
end_define

begin_comment
comment|/* Adapter-OEM-850nm-Fiber */
end_comment

begin_define
define|#
directive|define
name|IXGB_SUBDEVICE_ID_A05F
value|0xA05F
end_define

begin_comment
comment|/* Adapter-Retail-850nm-Fiber */
end_comment

begin_define
define|#
directive|define
name|IXGB_SUBDEVICE_ID_A12F
value|0xA12F
end_define

begin_comment
comment|/* Adapter-OEM-1310nm-Fiber */
end_comment

begin_define
define|#
directive|define
name|IXGB_SUBDEVICE_ID_A02F
value|0xA02F
end_define

begin_comment
comment|/* Adapter-Retail-1310nm-Fiber */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _IXGB_IDS_H_ */
end_comment

begin_comment
comment|/* End of File */
end_comment

end_unit

