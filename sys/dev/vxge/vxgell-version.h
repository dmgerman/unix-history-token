begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VXGELL_VERSION_H_
end_ifndef

begin_define
define|#
directive|define
name|_VXGELL_VERSION_H_
end_define

begin_define
define|#
directive|define
name|XGELL_VERSION_MAJOR
value|2
end_define

begin_define
define|#
directive|define
name|XGELL_VERSION_MINOR
value|5
end_define

begin_define
define|#
directive|define
name|XGELL_VERSION_FIX
value|1
end_define

begin_define
define|#
directive|define
name|XGELL_VERSION_BUILD
value|GENERATED_BUILD_VERSION
end_define

begin_define
define|#
directive|define
name|VXGE_FW_VERSION
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|build
parameter_list|)
define|\
value|((major<< 16) + (minor<< 8) + build)
end_define

begin_define
define|#
directive|define
name|VXGE_FW_MAJ_MIN_VERSION
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|((major<< 16) + (minor<< 8))
end_define

begin_comment
comment|/* Adapter should be running with this fw version for using FW_UPGRADE API's */
end_comment

begin_define
define|#
directive|define
name|VXGE_BASE_FW_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_BASE_FW_MINOR_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|VXGE_BASE_FW_BUILD_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|VXGE_BASE_FW_VERSION
define|\
value|VXGE_FW_VERSION(VXGE_BASE_FW_MAJOR_VERSION,		\ 			VXGE_BASE_FW_MINOR_VERSION,		\ 			VXGE_BASE_FW_BUILD_VERSION)
end_define

begin_define
define|#
directive|define
name|VXGE_DRV_FW_VERSION
define|\
value|VXGE_FW_VERSION(VXGE_MIN_FW_MAJOR_VERSION,		\ 			VXGE_MIN_FW_MINOR_VERSION,		\ 			VXGE_MIN_FW_BUILD_NUMBER)
end_define

begin_define
define|#
directive|define
name|VXGE_DRV_FW_MAJ_MIN_VERSION
define|\
value|VXGE_FW_MAJ_MIN_VERSION(VXGE_MIN_FW_MAJOR_VERSION,	\ 				VXGE_MIN_FW_MINOR_VERSION)
end_define

begin_define
define|#
directive|define
name|VXGE_FW_ARRAY_NAME
value|X3fw_ncf
end_define

begin_define
define|#
directive|define
name|VXGE_COPYRIGHT
value|"Copyright(c) 2002-2011 Exar Corp.\n"
end_define

begin_define
define|#
directive|define
name|VXGE_ADAPTER_NAME
value|"Neterion x3100 10GbE PCIe Server Adapter " \ 				"(Rev %d)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VXGELL_VERSION_H_ */
end_comment

end_unit

