begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acenvex.h - Extra host and compiler configuration  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACENVEX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACENVEX_H__
end_define

begin_comment
comment|/*! [Begin] no source code translation */
end_comment

begin_comment
comment|/******************************************************************************  *  * Extra host configuration files. All ACPICA headers are included before  * including these files.  *  *****************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"aclinuxex.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acdragonflyex.h"
end_include

begin_comment
comment|/*  * EFI applications can be built with -nostdlib, in this case, it must be  * included after including all other host environmental definitions, in  * order to override the definitions.  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AED_EFI
argument_list|)
operator|||
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
operator|||
name|defined
argument_list|(
name|_EDK2_EFI
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acefiex.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_include
include|#
directive|include
file|"acgccex.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acmsvcex.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACENVEX_H__ */
end_comment

end_unit

