begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpidump.h - Include file for AcpiDump utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

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

begin_define
define|#
directive|define
name|DEFINE_ACPI_GLOBALS
value|1
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
file|"actables.h"
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

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* Globals */
end_comment

begin_function_decl
name|EXTERN
name|BOOLEAN
name|INIT_GLOBAL
parameter_list|(
name|Gbl_SummaryMode
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|BOOLEAN
name|INIT_GLOBAL
parameter_list|(
name|Gbl_VerboseMode
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|BOOLEAN
name|INIT_GLOBAL
parameter_list|(
name|Gbl_BinaryMode
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|BOOLEAN
name|INIT_GLOBAL
parameter_list|(
name|Gbl_DumpCustomizedTables
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|BOOLEAN
name|INIT_GLOBAL
parameter_list|(
name|Gbl_DoNotDumpXsdt
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
name|FILE
name|INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_OutputFile
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
name|INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_OutputFilename
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|UINT64
name|INIT_GLOBAL
argument_list|(
name|Gbl_RsdpBase
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Globals required for use with ACPICA modules */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_GLOBALS
end_ifdef

begin_decl_stmt
name|UINT8
name|AcpiGbl_IntegerByteWidth
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Action table used to defer requested options */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ap_dump_action
block|{
name|char
modifier|*
name|Argument
decl_stmt|;
name|UINT32
name|ToBeDone
decl_stmt|;
block|}
name|AP_DUMP_ACTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AP_MAX_ACTIONS
value|32
end_define

begin_define
define|#
directive|define
name|AP_DUMP_ALL_TABLES
value|0
end_define

begin_define
define|#
directive|define
name|AP_DUMP_TABLE_BY_ADDRESS
value|1
end_define

begin_define
define|#
directive|define
name|AP_DUMP_TABLE_BY_NAME
value|2
end_define

begin_define
define|#
directive|define
name|AP_DUMP_TABLE_BY_FILE
value|3
end_define

begin_define
define|#
directive|define
name|AP_MAX_ACPI_FILES
value|256
end_define

begin_comment
comment|/* Prevent infinite loops */
end_comment

begin_comment
comment|/* Minimum FADT sizes for various table addresses */
end_comment

begin_define
define|#
directive|define
name|MIN_FADT_FOR_DSDT
value|(ACPI_FADT_OFFSET (Dsdt) + sizeof (UINT32))
end_define

begin_define
define|#
directive|define
name|MIN_FADT_FOR_FACS
value|(ACPI_FADT_OFFSET (Facs) + sizeof (UINT32))
end_define

begin_define
define|#
directive|define
name|MIN_FADT_FOR_XDSDT
value|(ACPI_FADT_OFFSET (XDsdt) + sizeof (UINT64))
end_define

begin_define
define|#
directive|define
name|MIN_FADT_FOR_XFACS
value|(ACPI_FADT_OFFSET (XFacs) + sizeof (UINT64))
end_define

begin_comment
comment|/*  * apdump - Table get/dump routines  */
end_comment

begin_function_decl
name|int
name|ApDumpTableFromFile
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ApDumpTableByName
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ApDumpTableByAddress
parameter_list|(
name|char
modifier|*
name|AsciiAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ApDumpAllTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|ApIsValidHeader
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|ApIsValidChecksum
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|ApGetTableLength
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * apfiles - File I/O utilities  */
end_comment

begin_function_decl
name|int
name|ApOpenOutputFile
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ApWriteToBinaryFile
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT32
name|Instance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_TABLE_HEADER
modifier|*
name|ApGetTableFromFile
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|,
name|UINT32
modifier|*
name|FileSize
parameter_list|)
function_decl|;
end_function_decl

end_unit

