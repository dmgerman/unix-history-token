begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acoutput.h -- debug output  *       $Revision: 1.101 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACOUTPUT_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACOUTPUT_H__
end_define

begin_comment
comment|/*  * Debug levels and component IDs.  These are used to control the  * granularity of the output of the DEBUG_PRINT macro -- on a per-  * component basis and a per-exception-type basis.  */
end_comment

begin_comment
comment|/* Component IDs are used in the global "DebugLayer" */
end_comment

begin_define
define|#
directive|define
name|ACPI_UTILITIES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_HARDWARE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACPI_EVENTS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACPI_TABLES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACPI_NAMESPACE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACPI_PARSER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACPI_DISPATCHER
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ACPI_EXECUTER
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ACPI_CA_DEBUGGER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ACPI_OS_SERVICES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ACPI_CA_DISASSEMBLER
value|0x00000800
end_define

begin_comment
comment|/* Component IDs for ACPI tools and utilities */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMPILER
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ACPI_TOOLS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ACPI_ALL_COMPONENTS
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|ACPI_COMPONENT_DEFAULT
value|(ACPI_ALL_COMPONENTS)
end_define

begin_comment
comment|/* Component IDs reserved for ACPI drivers */
end_comment

begin_define
define|#
directive|define
name|ACPI_ALL_DRIVERS
value|0xFFFF0000
end_define

begin_comment
comment|/*  * Raw debug output levels, do not use these in the DEBUG_PRINT macros  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LV_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_LV_WARN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACPI_LV_INIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACPI_LV_DEBUG_OBJECT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACPI_LV_INFO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACPI_LV_ALL_EXCEPTIONS
value|0x0000001F
end_define

begin_comment
comment|/* Trace verbosity level 1 [Standard Trace Level] */
end_comment

begin_define
define|#
directive|define
name|ACPI_LV_INIT_NAMES
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACPI_LV_PARSE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ACPI_LV_LOAD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ACPI_LV_DISPATCH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ACPI_LV_EXEC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ACPI_LV_NAMES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ACPI_LV_OPREGION
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ACPI_LV_BFIELD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_TABLES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_VALUES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_OBJECTS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_RESOURCES
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_USER_REQUESTS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_PACKAGE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_VERBOSITY1
value|0x0007FF40 | ACPI_LV_ALL_EXCEPTIONS
end_define

begin_comment
comment|/* Trace verbosity level 2 [Function tracing and memory allocation] */
end_comment

begin_define
define|#
directive|define
name|ACPI_LV_ALLOCATIONS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_FUNCTIONS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_OPTIMIZATIONS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_VERBOSITY2
value|0x00700000 | ACPI_LV_VERBOSITY1
end_define

begin_define
define|#
directive|define
name|ACPI_LV_ALL
value|ACPI_LV_VERBOSITY2
end_define

begin_comment
comment|/* Trace verbosity level 3 [Threading, I/O, and Interrupts] */
end_comment

begin_define
define|#
directive|define
name|ACPI_LV_MUTEX
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_THREADS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_IO
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_INTERRUPTS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_VERBOSITY3
value|0x0F000000 | ACPI_LV_VERBOSITY2
end_define

begin_comment
comment|/* Exceptionally verbose output -- also used in the global "DebugLevel"  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LV_AML_DISASSEMBLE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_VERBOSE_INFO
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_FULL_TABLES
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_EVENTS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ACPI_LV_VERBOSE
value|0xF0000000
end_define

begin_comment
comment|/*  * Debug level macros that are used in the DEBUG_PRINT macros  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_LEVEL
parameter_list|(
name|dl
parameter_list|)
value|(UINT32) dl,ACPI_DEBUG_PARAMETERS
end_define

begin_comment
comment|/* Exception level -- used in the global "DebugLevel" */
end_comment

begin_define
define|#
directive|define
name|ACPI_DB_INIT
value|ACPI_DEBUG_LEVEL (ACPI_LV_INIT)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_DEBUG_OBJECT
value|ACPI_DEBUG_LEVEL (ACPI_LV_DEBUG_OBJECT)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_INFO
value|ACPI_DEBUG_LEVEL (ACPI_LV_INFO)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_ALL_EXCEPTIONS
value|ACPI_DEBUG_LEVEL (ACPI_LV_ALL_EXCEPTIONS)
end_define

begin_comment
comment|/*  * These two levels are essentially obsolete, all instances in the  * ACPICA core code have been replaced by ACPI_ERROR and ACPI_WARNING  * (Kept here because some drivers may still use them)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DB_ERROR
value|ACPI_DEBUG_LEVEL (ACPI_LV_ERROR)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_WARN
value|ACPI_DEBUG_LEVEL (ACPI_LV_WARN)
end_define

begin_comment
comment|/* Trace level -- also used in the global "DebugLevel" */
end_comment

begin_define
define|#
directive|define
name|ACPI_DB_INIT_NAMES
value|ACPI_DEBUG_LEVEL (ACPI_LV_INIT_NAMES)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_THREADS
value|ACPI_DEBUG_LEVEL (ACPI_LV_THREADS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_PARSE
value|ACPI_DEBUG_LEVEL (ACPI_LV_PARSE)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_DISPATCH
value|ACPI_DEBUG_LEVEL (ACPI_LV_DISPATCH)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_LOAD
value|ACPI_DEBUG_LEVEL (ACPI_LV_LOAD)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_EXEC
value|ACPI_DEBUG_LEVEL (ACPI_LV_EXEC)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_NAMES
value|ACPI_DEBUG_LEVEL (ACPI_LV_NAMES)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_OPREGION
value|ACPI_DEBUG_LEVEL (ACPI_LV_OPREGION)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_BFIELD
value|ACPI_DEBUG_LEVEL (ACPI_LV_BFIELD)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_TABLES
value|ACPI_DEBUG_LEVEL (ACPI_LV_TABLES)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_FUNCTIONS
value|ACPI_DEBUG_LEVEL (ACPI_LV_FUNCTIONS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_OPTIMIZATIONS
value|ACPI_DEBUG_LEVEL (ACPI_LV_OPTIMIZATIONS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_VALUES
value|ACPI_DEBUG_LEVEL (ACPI_LV_VALUES)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_OBJECTS
value|ACPI_DEBUG_LEVEL (ACPI_LV_OBJECTS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_ALLOCATIONS
value|ACPI_DEBUG_LEVEL (ACPI_LV_ALLOCATIONS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_RESOURCES
value|ACPI_DEBUG_LEVEL (ACPI_LV_RESOURCES)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_IO
value|ACPI_DEBUG_LEVEL (ACPI_LV_IO)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_INTERRUPTS
value|ACPI_DEBUG_LEVEL (ACPI_LV_INTERRUPTS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_USER_REQUESTS
value|ACPI_DEBUG_LEVEL (ACPI_LV_USER_REQUESTS)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_PACKAGE
value|ACPI_DEBUG_LEVEL (ACPI_LV_PACKAGE)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_MUTEX
value|ACPI_DEBUG_LEVEL (ACPI_LV_MUTEX)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_ALL
value|ACPI_DEBUG_LEVEL (ACPI_LV_ALL)
end_define

begin_comment
comment|/* Defaults for DebugLevel, debug and normal */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_DEFAULT
value|(ACPI_LV_INIT | ACPI_LV_WARN | ACPI_LV_ERROR | ACPI_LV_DEBUG_OBJECT)
end_define

begin_define
define|#
directive|define
name|ACPI_NORMAL_DEFAULT
value|(ACPI_LV_INIT | ACPI_LV_WARN | ACPI_LV_ERROR | ACPI_LV_DEBUG_OBJECT)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_ALL
value|(ACPI_LV_AML_DISASSEMBLE | ACPI_LV_ALL_EXCEPTIONS | ACPI_LV_ALL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACOUTPUT_H__ */
end_comment

end_unit

