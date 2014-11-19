begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: accommon.h - Common include files for generation of ACPICA source  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACCOMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACCOMMON_H__
end_define

begin_comment
comment|/*  * Common set of includes for all ACPICA source files.  * We put them here because we don't want to duplicate them  * in the the source code again and again.  *  * Note: The order of these include files is important.  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acconfig.h>
end_include

begin_comment
comment|/* Global configuration constants */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acmacros.h>
end_include

begin_comment
comment|/* C macros */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/aclocal.h>
end_include

begin_comment
comment|/* Internal data types */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acobject.h>
end_include

begin_comment
comment|/* ACPI internal object */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acstruct.h>
end_include

begin_comment
comment|/* Common structures */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acglobal.h>
end_include

begin_comment
comment|/* All global variables */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/achware.h>
end_include

begin_comment
comment|/* Hardware defines and interfaces */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acutils.h>
end_include

begin_comment
comment|/* Utility interfaces */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACCOMMON_H__ */
end_comment

end_unit

