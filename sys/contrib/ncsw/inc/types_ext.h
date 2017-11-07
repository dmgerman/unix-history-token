begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2012 Freescale Semiconductor, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          types_ext.h   @Description   General types Standard Definitions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPES_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__TYPES_EXT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCSW_LINUX
argument_list|)
end_if

begin_include
include|#
directive|include
file|"types_linux.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NCSW_VXWORKS
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"types_vxworks.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"types_bb_gpp.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"types_freebsd.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"types_bb_gcc.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ghs__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"types_ghs.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"types_dflt.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (__ROCOO__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TYPES_EXT_H */
end_comment

end_unit

