begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aecommon - common include for the AcpiExec utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AECOMMON
end_ifndef

begin_define
define|#
directive|define
name|_AECOMMON
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|/* disable some level-4 warnings */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
end_pragma

begin_comment
comment|/* warning C4100: unreferenced formal parameter */
end_comment

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
file|"acparser.h"
end_include

begin_include
include|#
directive|include
file|"amlcode.h"
end_include

begin_include
include|#
directive|include
file|"acnamesp.h"
end_include

begin_include
include|#
directive|include
file|"acdebug.h"
end_include

begin_include
include|#
directive|include
file|"actables.h"
end_include

begin_include
include|#
directive|include
file|"acinterp.h"
end_include

begin_include
include|#
directive|include
file|"amlresrc.h"
end_include

begin_include
include|#
directive|include
file|"acapps.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_IgnoreErrors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_RegionFillValue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_UseHwReducedFadt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_DisplayRegionAccess
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_DoInterfaceTests
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_LoadTestTables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_CONNECTION_INFO
name|AeMyContext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check for unexpected exceptions */
end_comment

begin_define
define|#
directive|define
name|AE_CHECK_STATUS
parameter_list|(
name|Name
parameter_list|,
name|Status
parameter_list|,
name|Expected
parameter_list|)
define|\
value|if (Status != Expected) \     { \         AcpiOsPrintf ("Unexpected %s from %s (%s-%d)\n", \             AcpiFormatException (Status), #Name, _AcpiModuleName, __LINE__); \     }
end_define

begin_comment
comment|/* Check for unexpected non-AE_OK errors */
end_comment

begin_define
define|#
directive|define
name|AE_CHECK_OK
parameter_list|(
name|Name
parameter_list|,
name|Status
parameter_list|)
value|AE_CHECK_STATUS (Name, Status, AE_OK);
end_define

begin_typedef
typedef|typedef
struct|struct
name|ae_table_desc
block|{
name|ACPI_TABLE_HEADER
modifier|*
name|Table
decl_stmt|;
name|struct
name|ae_table_desc
modifier|*
name|Next
decl_stmt|;
block|}
name|AE_TABLE_DESC
typedef|;
end_typedef

begin_comment
comment|/*  * Debug Regions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ae_region
block|{
name|ACPI_PHYSICAL_ADDRESS
name|Address
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|void
modifier|*
name|Buffer
decl_stmt|;
name|void
modifier|*
name|NextRegion
decl_stmt|;
name|UINT8
name|SpaceId
decl_stmt|;
block|}
name|AE_REGION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ae_debug_regions
block|{
name|UINT32
name|NumberOfRegions
decl_stmt|;
name|AE_REGION
modifier|*
name|RegionList
decl_stmt|;
block|}
name|AE_DEBUG_REGIONS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TEST_OUTPUT_LEVEL
parameter_list|(
name|lvl
parameter_list|)
value|if ((lvl)& OutputLevel)
end_define

begin_define
define|#
directive|define
name|OSD_PRINT
parameter_list|(
name|lvl
parameter_list|,
name|fp
parameter_list|)
value|TEST_OUTPUT_LEVEL(lvl) {\                                             AcpiOsPrintf PARAM_LIST(fp);}
end_define

begin_function_decl
name|void
name|ACPI_SYSTEM_XFACE
name|AeCtrlCHandler
parameter_list|(
name|int
name|Sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AeBuildLocalTables
parameter_list|(
name|UINT32
name|TableCount
parameter_list|,
name|AE_TABLE_DESC
modifier|*
name|TableList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AeInstallTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeDumpNamespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeDumpObject
parameter_list|(
name|char
modifier|*
name|MethodName
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|ReturnObj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeDumpBuffer
parameter_list|(
name|UINT32
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeExecute
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeSetScope
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeCloseDebugFile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeOpenDebugFile
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AeDisplayAllMethods
parameter_list|(
name|UINT32
name|DisplayCount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AeInstallEarlyHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AeInstallLateHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeMiscellaneousTests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AeRegionHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AeGpeHandler
parameter_list|(
name|ACPI_HANDLE
name|GpeDevice
parameter_list|,
name|UINT32
name|GpeNumber
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeGlobalEventHandler
parameter_list|(
name|UINT32
name|Type
parameter_list|,
name|ACPI_HANDLE
name|GpeDevice
parameter_list|,
name|UINT32
name|EventNumber
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* aeregion */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AeInstallDeviceHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeInstallRegionHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AeOverrideRegionHandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AECOMMON */
end_comment

end_unit

