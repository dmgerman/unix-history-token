begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acoutput.h -- debug output  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * Debug levels and component IDs. These are used to control the  * granularity of the output of the ACPI_DEBUG_PRINT macro -- on a  * per-component basis and a per-exception-type basis.  */
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
name|ACPI_EXAMPLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ACPI_DRIVER
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DT_COMPILER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACPI_ALL_COMPONENTS
value|0x0001FFFF
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
comment|/*  * Raw debug output levels, do not use these in the ACPI_DEBUG_PRINT macros  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LV_INIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_LV_DEBUG_OBJECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACPI_LV_INFO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACPI_LV_REPAIR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACPI_LV_ALL_EXCEPTIONS
value|0x0000000F
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
comment|/*  * Exception level -- used in the global "DebugLevel"  *  * Note: For errors, use the ACPI_ERROR or ACPI_EXCEPTION interfaces.  * For warnings, use ACPI_WARNING.  */
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
name|ACPI_DB_REPAIR
value|ACPI_DEBUG_LEVEL (ACPI_LV_REPAIR)
end_define

begin_define
define|#
directive|define
name|ACPI_DB_ALL_EXCEPTIONS
value|ACPI_DEBUG_LEVEL (ACPI_LV_ALL_EXCEPTIONS)
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
name|ACPI_DB_EVENTS
value|ACPI_DEBUG_LEVEL (ACPI_LV_EVENTS)
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
value|(ACPI_LV_INIT | ACPI_LV_DEBUG_OBJECT | ACPI_LV_REPAIR)
end_define

begin_define
define|#
directive|define
name|ACPI_NORMAL_DEFAULT
value|(ACPI_LV_INIT | ACPI_LV_DEBUG_OBJECT | ACPI_LV_REPAIR)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_ALL
value|(ACPI_LV_AML_DISASSEMBLE | ACPI_LV_ALL_EXCEPTIONS | ACPI_LV_ALL)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|ACPI_NO_ERROR_MESSAGES
argument_list|)
end_if

begin_comment
comment|/*  * Module name is included in both debug and non-debug versions primarily for  * error messages. The __FILE__ macro is not very useful for this, because it  * often includes the entire pathname to the module  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MODULE_NAME
parameter_list|(
name|Name
parameter_list|)
value|static const char ACPI_UNUSED_VAR _AcpiModuleName[] = Name;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_MODULE_NAME
parameter_list|(
name|Name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ascii error messages can be configured out  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_NO_ERROR_MESSAGES
end_ifndef

begin_define
define|#
directive|define
name|AE_INFO
value|_AcpiModuleName, __LINE__
end_define

begin_comment
comment|/*  * Error reporting. Callers module and line number are inserted by AE_INFO,  * the plist contains a set of parens to allow variable-length lists.  * These macros are used for both the debug and non-debug versions of the code.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_INFO
parameter_list|(
name|plist
parameter_list|)
value|AcpiInfo plist
end_define

begin_define
define|#
directive|define
name|ACPI_WARNING
parameter_list|(
name|plist
parameter_list|)
value|AcpiWarning plist
end_define

begin_define
define|#
directive|define
name|ACPI_EXCEPTION
parameter_list|(
name|plist
parameter_list|)
value|AcpiException plist
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR
parameter_list|(
name|plist
parameter_list|)
value|AcpiError plist
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_OBJECT
parameter_list|(
name|obj
parameter_list|,
name|l
parameter_list|,
name|i
parameter_list|)
value|AcpiExDoDebugObject(obj,l,i)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No error messages */
end_comment

begin_define
define|#
directive|define
name|ACPI_INFO
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_WARNING
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_EXCEPTION
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_ERROR
parameter_list|(
name|plist
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_OBJECT
parameter_list|(
name|obj
parameter_list|,
name|l
parameter_list|,
name|i
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_NO_ERROR_MESSAGES */
end_comment

begin_comment
comment|/*  * Debug macros that are conditionally compiled  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_comment
comment|/*  * If ACPI_GET_FUNCTION_NAME was not defined in the compiler-dependent header,  * define it now. This is the case where there the compiler does not support  * a __FUNCTION__ macro or equivalent.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_GET_FUNCTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|ACPI_GET_FUNCTION_NAME
value|_AcpiFunctionName
end_define

begin_comment
comment|/*  * The Name parameter should be the procedure name as a quoted string.  * The function name is also used by the function exit macros below.  * Note: (const char) is used to be compatible with the debug interfaces  * and macros such as __FUNCTION__.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_NAME
parameter_list|(
name|Name
parameter_list|)
value|static const char _AcpiFunctionName[] = #Name;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Compiler supports __FUNCTION__ (or equivalent) -- Ignore this macro */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_NAME
parameter_list|(
name|Name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_GET_FUNCTION_NAME */
end_comment

begin_comment
comment|/*  * Common parameters used for debug output functions:  * line number, function name, module(file) name, component ID  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_PARAMETERS
value|__LINE__, ACPI_GET_FUNCTION_NAME, _AcpiModuleName, _COMPONENT
end_define

begin_comment
comment|/*  * Master debug print macros  * Print message if and only if:  *    1) Debug print for the current component is enabled  *    2) Debug error level or trace level for the print statement is enabled  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT
parameter_list|(
name|plist
parameter_list|)
value|AcpiDebugPrint plist
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT_RAW
parameter_list|(
name|plist
parameter_list|)
value|AcpiDebugPrintRaw plist
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * This is the non-debug case -- make everything go away,  * leaving no executable debug code!  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FUNCTION_NAME
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT
parameter_list|(
name|pl
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_PRINT_RAW
parameter_list|(
name|pl
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUG_OUTPUT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACOUTPUT_H__ */
end_comment

end_unit

