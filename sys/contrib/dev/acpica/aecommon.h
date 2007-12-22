begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aecommon - common include for the AcpiExec utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acparser.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/amlcode.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acnamesp.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acdebug.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/actables.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acinterp.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acapps.h>
end_include

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|AcpiGbl_DebugFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_IgnoreErrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Debug Regions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Region
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
name|REGION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|DebugRegions
block|{
name|UINT32
name|NumberOfRegions
decl_stmt|;
name|REGION
modifier|*
name|RegionList
decl_stmt|;
block|}
name|DEBUG_REGIONS
typedef|;
end_typedef

begin_comment
comment|/*  * Pointer overlay for 16-bit code  */
end_comment

begin_typedef
typedef|typedef
union|union
name|ptr_ovl
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|UINT32
name|dword
decl_stmt|;
struct|struct
block|{
name|UINT16
name|offset
decl_stmt|;
name|UINT16
name|base
decl_stmt|;
block|}
name|ovl
struct|;
block|}
name|PTR_OVL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GET_SEGMENT
parameter_list|(
name|ptr
parameter_list|)
value|((UINT16)(_segment)(ptr))
end_define

begin_define
define|#
directive|define
name|GET_OFFSET
parameter_list|(
name|ptr
parameter_list|)
value|((UINT16)(UINT32) (ptr))
end_define

begin_define
define|#
directive|define
name|GET_PHYSICAL_ADDRESS
parameter_list|(
name|ptr
parameter_list|)
value|(((((UINT32)GET_SEGMENT(ptr))<< 4)) + GET_OFFSET(ptr))
end_define

begin_define
define|#
directive|define
name|PTR_OVL_BUILD_PTR
parameter_list|(
name|p
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|)
value|{p.ovl.base=b;p.ovl.offset=o;}
end_define

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
name|__cdecl
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
name|ACPI_TABLE_HEADER
modifier|*
name|UserTable
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
name|AeInstallHandlers
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AECOMMON */
end_comment

end_unit

