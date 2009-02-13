begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acenv.h - Generation environment specific items  *       $Revision: 1.131 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACENV_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACENV_H__
end_define

begin_comment
comment|/*  * Configuration for ACPI tools and utilities  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_LIBRARY
end_ifdef

begin_comment
comment|/*  * Note: The non-debug version of the AcpiLibrary does not contain any  * debug support, for minimimal size. The debug version uses ACPI_FULL_DEBUG  */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ASL_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_define
define|#
directive|define
name|ACPI_APPLICATION
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
end_define

begin_define
define|#
directive|define
name|ACPI_CONSTANT_EVAL_ONLY
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_NAMESPACE_NODE
end_define

begin_define
define|#
directive|define
name|ACPI_DATA_TABLE_DISASSEMBLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_EXEC_APP
end_ifdef

begin_undef
undef|#
directive|undef
name|DEBUGGER_THREADING
end_undef

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_SINGLE_THREADED
end_define

begin_define
define|#
directive|define
name|ACPI_FULL_DEBUG
end_define

begin_define
define|#
directive|define
name|ACPI_APPLICATION
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUGGER
end_define

begin_define
define|#
directive|define
name|ACPI_MUTEX_DEBUG
end_define

begin_define
define|#
directive|define
name|ACPI_DBG_TRACK_ALLOCATIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DASM_APP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ACPI_APPLICATION
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
end_define

begin_define
define|#
directive|define
name|ACPI_NO_METHOD_EXECUTION
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_NAMESPACE_NODE
end_define

begin_define
define|#
directive|define
name|ACPI_DATA_TABLE_DISASSEMBLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
end_define

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_FULL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUGGER
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Environment configuration.  The purpose of this file is to interface to the  * local generation environment.  *  * 1) ACPI_USE_SYSTEM_CLIBRARY - Define this if linking to an actual C library.  *      Otherwise, local versions of string/memory functions will be used.  * 2) ACPI_USE_STANDARD_HEADERS - Define this if linking to a C library and  *      the standard header files may be used.  *  * The ACPI subsystem only uses low level C library functions that do not call  * operating system services and may therefore be inlined in the code.  *  * It may be necessary to tailor these include files to the target  * generation environment.  *  *  * Functions and constants used from each header:  *  * string.h:    memcpy  *              memset  *              strcat  *              strcmp  *              strcpy  *              strlen  *              strncmp  *              strncat  *              strncpy  *  * stdlib.h:    strtoul  *  * stdarg.h:    va_list  *              va_arg  *              va_start  *              va_end  *  */
end_comment

begin_comment
comment|/*! [Begin] no source code translation */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"aclinux.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AED_EFI
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acefi.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acwin.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WIN64
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acwin64.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_elif

begin_comment
comment|/* Must appear after WIN32 and WIN64 check */
end_comment

begin_include
include|#
directive|include
file|"acdos16.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acfreebsd.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acnetbsd.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MODESTO
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acmodesto.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NETWARE
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acnetware.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acsolaris.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* All other environments */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|long long
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_comment
comment|/*  * Debugger threading model  * Use single threaded if the entire subsystem is contained in an application  * Use multiple threaded when the subsystem is running in the kernel.  *  * By default the model is single threaded if ACPI_APPLICATION is set,  * multi-threaded if ACPI_APPLICATION is not set.  */
end_comment

begin_define
define|#
directive|define
name|DEBUGGER_SINGLE_THREADED
value|0
end_define

begin_define
define|#
directive|define
name|DEBUGGER_MULTI_THREADED
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGGER_THREADING
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_SINGLE_THREADED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_MULTI_THREADED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DEBUGGER_THREADING */
end_comment

begin_comment
comment|/******************************************************************************  *  * C library configuration  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACPI_IS_ASCII
parameter_list|(
name|c
parameter_list|)
value|((c)< 0x80)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_SYSTEM_CLIBRARY
end_ifdef

begin_comment
comment|/*  * Use the standard C library headers.  * We want to keep these to a minimum.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_STANDARD_HEADERS
end_ifdef

begin_comment
comment|/*  * Use the standard headers from the standard locations  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
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
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_STANDARD_HEADERS */
end_comment

begin_comment
comment|/*  * We will be linking to the standard Clib functions  */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRSTR
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strstr((s1), (s2))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCHR
parameter_list|(
name|s1
parameter_list|,
name|c
parameter_list|)
value|strchr((s1), (c))
end_define

begin_define
define|#
directive|define
name|ACPI_STRLEN
parameter_list|(
name|s
parameter_list|)
value|(ACPI_SIZE) strlen((s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) strcpy((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) strncpy((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncmp((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|strcmp((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) strcat((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncat((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRTOUL
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strtoul((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp((const char *)(s1), (const char *)(s2), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) memcpy((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMSET
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) memset((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_TOUPPER
parameter_list|(
name|i
parameter_list|)
value|toupper((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_TOLOWER
parameter_list|(
name|i
parameter_list|)
value|tolower((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_XDIGIT
parameter_list|(
name|i
parameter_list|)
value|isxdigit((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_DIGIT
parameter_list|(
name|i
parameter_list|)
value|isdigit((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_SPACE
parameter_list|(
name|i
parameter_list|)
value|isspace((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_UPPER
parameter_list|(
name|i
parameter_list|)
value|isupper((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_PRINT
parameter_list|(
name|i
parameter_list|)
value|isprint((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_ALPHA
parameter_list|(
name|i
parameter_list|)
value|isalpha((int) (i))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/******************************************************************************  *  * Not using native C library, use local implementations  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Use local definitions of C library macros and functions  * NOTE: The function implementations may not be as efficient  * as an inline or assembly code implementation provided by a  * native C library.  */
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
comment|/*  * Storage alignment properties  */
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
comment|/*  * Variable argument list macro definitions  */
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
value|(void) 0
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

begin_define
define|#
directive|define
name|ACPI_STRSTR
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|AcpiUtStrstr ((s1), (s2))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCHR
parameter_list|(
name|s1
parameter_list|,
name|c
parameter_list|)
value|AcpiUtStrchr ((s1), (c))
end_define

begin_define
define|#
directive|define
name|ACPI_STRLEN
parameter_list|(
name|s
parameter_list|)
value|(ACPI_SIZE) AcpiUtStrlen ((s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) AcpiUtStrcpy ((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) AcpiUtStrncpy ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|AcpiUtStrncmp ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|AcpiUtStrcmp ((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) AcpiUtStrcat ((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|AcpiUtStrncat ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRTOUL
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|AcpiUtStrtoul ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|AcpiUtMemcmp((const char *)(s1), (const char *)(s2), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) AcpiUtMemcpy ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMSET
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|)
value|(void) AcpiUtMemset ((d), (v), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_TOUPPER
value|AcpiUtToUpper
end_define

begin_define
define|#
directive|define
name|ACPI_TOLOWER
value|AcpiUtToLower
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_CLIBRARY */
end_comment

begin_comment
comment|/******************************************************************************  *  * Assembly code macros  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Handle platform- and compiler-specific assembly language differences.  * These should already have been defined by the platform includes above.  *  * Notes:  * 1) Interrupt 3 is used to break into a debugger  * 2) Interrupts are turned off during ACPI register setup  */
end_comment

begin_comment
comment|/* Unrecognized compiler, use defaults */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_ASM_MACROS
end_ifndef

begin_comment
comment|/*  * Calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces  * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_VAR_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_ASM_MACROS
end_define

begin_define
define|#
directive|define
name|BREAKPOINT3
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_IRQS
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_IRQS
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ACPI_ACQUIRE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acq
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_RELEASE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acq
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_ASM_MACROS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_comment
comment|/* Don't want software interrupts within a ring3 application */
end_comment

begin_undef
undef|#
directive|undef
name|BREAKPOINT3
end_undef

begin_define
define|#
directive|define
name|BREAKPOINT3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************************************************************  *  * Compiler-specific information is contained in the compiler-specific  * headers.  *  *****************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACENV_H__ */
end_comment

end_unit

