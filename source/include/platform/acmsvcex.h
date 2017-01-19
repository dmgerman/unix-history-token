begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmsvcex.h - Extra VC specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACMSVCEX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACMSVCEX_H__
end_define

begin_comment
comment|/* va_arg implementation can be compiler specific */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_STANDARD_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_STANDARD_HEADERS */
end_comment

begin_comment
comment|/* Debug support. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|_CRTDBG_MAP_ALLOC
end_define

begin_comment
comment|/* Enables specific file/lineno for leaks */
end_comment

begin_include
include|#
directive|include
file|<crtdbg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End standard headers */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_SYSTEM_CLIBRARY
end_ifndef

begin_comment
comment|/******************************************************************************  *  * Not using native C library, use local implementations  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|va_arg
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_VALIST
end_ifndef

begin_define
define|#
directive|define
name|_VALIST
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VALIST */
end_comment

begin_comment
comment|/* Storage alignment properties */
end_comment

begin_define
define|#
directive|define
name|_AUPBND
value|(sizeof (ACPI_NATIVE_INT) - 1)
end_define

begin_define
define|#
directive|define
name|_ADNBND
value|(sizeof (ACPI_NATIVE_INT) - 1)
end_define

begin_comment
comment|/* Variable argument list macro definitions */
end_comment

begin_define
define|#
directive|define
name|_Bnd
parameter_list|(
name|X
parameter_list|,
name|bnd
parameter_list|)
value|(((sizeof (X)) + (bnd))& (~(bnd)))
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|T
parameter_list|)
value|(*(T *)(((ap) += (_Bnd (T, _AUPBND))) - (_Bnd (T,_ADNBND))))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|(ap = (va_list) NULL)
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|A
parameter_list|)
value|(void) ((ap) = (((char *)&(A)) + (_Bnd (A,_AUPBND))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* va_arg */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_USE_SYSTEM_CLIBRARY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACMSVCEX_H__ */
end_comment

end_unit

