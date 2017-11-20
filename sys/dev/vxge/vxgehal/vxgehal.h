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
name|VXGE_HAL_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_H
end_define

begin_include
include|#
directive|include
file|<dev/vxge/include/vxgehal-ll.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-regdefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-legacy-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-toc-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-common-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-memrepair-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-pcicfgmgmt-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-mrpcim-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-srpcim-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-vpmgmt-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-vpath-reg.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-regs.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-config-priv.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-swapper.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-mm.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-blockpool.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-doorbells.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-virtualpath.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-device.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-channel.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-srpcim.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-mrpcim.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-driver.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-ring.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-fifo.h>
end_include

begin_include
include|#
directive|include
file|<dev/vxge/vxgehal/vxgehal-ifmsg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_H */
end_comment

end_unit

