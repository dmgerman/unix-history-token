begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpibinh - Include file for AcpiBin utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"accommon.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|DB_CONSOLE_OUTPUT
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_DB_REDIRECTABLE_OUTPUT
value|0x01
end_define

begin_comment
comment|/*  * Global variables. Defined in main.c only, externed in all other files  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_define
define|#
directive|define
name|INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a=b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Globals */
end_comment

begin_function_decl
name|EXTERN
name|BOOLEAN
name|INIT_GLOBAL
parameter_list|(
name|Gbl_TerseMode
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prototypes */
end_comment

begin_function_decl
name|int
name|AbCompareAmlFiles
parameter_list|(
name|char
modifier|*
name|File1Path
parameter_list|,
name|char
modifier|*
name|File2Path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AbDumpAmlFile
parameter_list|(
name|char
modifier|*
name|File1Path
parameter_list|,
name|char
modifier|*
name|File2Path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AbComputeChecksum
parameter_list|(
name|char
modifier|*
name|File1Path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AbDisplayHeader
parameter_list|(
name|char
modifier|*
name|File1Path
parameter_list|)
function_decl|;
end_function_decl

end_unit

