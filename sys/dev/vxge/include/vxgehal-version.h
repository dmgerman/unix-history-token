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
name|VXGE_HAL_VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_VERSION_H
end_define

begin_include
include|#
directive|include
file|<dev/vxge/include/build-version.h>
end_include

begin_comment
comment|/*  * VXGE_HAL_VERSION_MAJOR - HAL major version  */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_VERSION_MAJOR
value|0
end_define

begin_comment
comment|/*  * VXGE_HAL_VERSION_MINOR - HAL minor version  */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_VERSION_MINOR
value|0
end_define

begin_comment
comment|/*  * VXGE_HAL_VERSION_FIX - HAL version fix  */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_VERSION_FIX
value|0
end_define

begin_comment
comment|/*  * VXGE_HAL_VERSION_BUILD - HAL build version  */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_VERSION_BUILD
value|GENERATED_BUILD_VERSION
end_define

begin_comment
comment|/*  * VXGE_HAL_VERSION - HAL version  */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_VERSION
value|"VXGE_HAL_VERSION_MAJOR.VXGE_HAL_VERSION_MINOR.\ 			VXGE_HAL_VERSION_FIX.VXGE_HAL_VERSION_BUILD"
end_define

begin_comment
comment|/*  * VXGE_HAL_DESC - HAL Description  */
end_comment

begin_define
define|#
directive|define
name|VXGE_HAL_DESC
value|VXGE_DRIVER_NAME" v."VXGE_HAL_VERSION
end_define

begin_comment
comment|/* Link Layer versioning */
end_comment

begin_include
include|#
directive|include
file|<dev/vxge/vxgell-version.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_VERSION_H */
end_comment

end_unit

