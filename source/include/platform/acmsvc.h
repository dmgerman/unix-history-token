begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmsvc.h - VC specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACMSVC_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACMSVC_H__
end_define

begin_comment
comment|/* Note: do not include any C library headers here */
end_comment

begin_comment
comment|/*  * Note: MSVC project files should define ACPI_DEBUGGER and ACPI_DISASSEMBLER  * as appropriate to enable editor functions like "Find all references".  * The editor isn't smart enough to dig through the include files to find  * out if these are actually defined.  */
end_comment

begin_comment
comment|/* Eliminate warnings for "old" (non-secure) versions of clib functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRT_SECURE_NO_WARNINGS
end_ifndef

begin_define
define|#
directive|define
name|_CRT_SECURE_NO_WARNINGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Eliminate warnings for POSIX clib function names (open, write, etc.) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRT_NONSTDC_NO_DEPRECATE
end_ifndef

begin_define
define|#
directive|define
name|_CRT_NONSTDC_NO_DEPRECATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|__int64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned __int64
end_define

begin_define
define|#
directive|define
name|ACPI_INLINE
value|__inline
end_define

begin_comment
comment|/*  * Calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces  * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
value|__cdecl
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
value|__cdecl
end_define

begin_comment
comment|/* Do not maintain the architecture specific stuffs for the EFI ports */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_EDK2_EFI
argument_list|)
end_if

begin_comment
comment|/*  * Math helper functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_DIV_64_BY_32
end_ifndef

begin_define
define|#
directive|define
name|ACPI_DIV_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|d32
parameter_list|,
name|q32
parameter_list|,
name|r32
parameter_list|)
define|\
value|{                           \     __asm mov    edx, n_hi  \     __asm mov    eax, n_lo  \     __asm div    d32        \     __asm mov    q32, eax   \     __asm mov    r32, edx   \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MUL_64_BY_32
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MUL_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|m32
parameter_list|,
name|p32
parameter_list|,
name|c32
parameter_list|)
define|\
value|{                           \     __asm mov    edx, n_hi  \     __asm mov    eax, n_lo  \     __asm mul    m32        \     __asm mov    p32, eax   \     __asm mov    c32, edx   \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SHIFT_LEFT_64_BY_32
end_ifndef

begin_define
define|#
directive|define
name|ACPI_SHIFT_LEFT_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|s32
parameter_list|)
define|\
value|{                               \     __asm mov    edx, n_hi      \     __asm mov    eax, n_lo      \     __asm mov    ecx, s32       \     __asm and    ecx, 31        \     __asm shld   edx, eax, cl   \     __asm shl    eax, cl        \     __asm mov    n_hi, edx      \     __asm mov    n_lo, eax      \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SHIFT_RIGHT_64_BY_32
end_ifndef

begin_define
define|#
directive|define
name|ACPI_SHIFT_RIGHT_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|s32
parameter_list|)
define|\
value|{                               \     __asm mov    edx, n_hi      \     __asm mov    eax, n_lo      \     __asm mov    ecx, s32       \     __asm and    ecx, 31        \     __asm shrd   eax, edx, cl   \     __asm shr    edx, cl        \     __asm mov    n_hi, edx      \     __asm mov    n_lo, eax      \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SHIFT_RIGHT_64
end_ifndef

begin_define
define|#
directive|define
name|ACPI_SHIFT_RIGHT_64
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|)
define|\
value|{                           \     __asm shr    n_hi, 1    \     __asm rcr    n_lo, 1    \ }
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
comment|/* warn C4100: unreferenced formal parameter */
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
comment|/* warn C4127: conditional expression is constant */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
end_pragma

begin_comment
comment|/* warn C4706: assignment within conditional expression */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4706
name|)
end_pragma

begin_comment
comment|/* warn C4131: uses old-style declarator (iASL compiler only) */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4131
name|)
end_pragma

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1200
end_if

begin_comment
comment|/* Versions above VC++ 6 */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4295
name|)
end_pragma

begin_comment
comment|/* needed for acpredef.h array */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Debug support. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef

begin_comment
comment|/*  * Debugging memory corruption issues with windows:  * Add #include<crtdbg.h> to accommon.h if necessary.  * Add _ASSERTE(_CrtCheckMemory()); where needed to test memory integrity.  * This can quickly localize the memory corruption.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUG_INITIALIZE
parameter_list|()
define|\
value|_CrtSetDbgFlag (\         _CRTDBG_CHECK_ALWAYS_DF | \         _CRTDBG_ALLOC_MEM_DF | \         _CRTDBG_DELAY_FREE_MEM_DF | \         _CRTDBG_LEAK_CHECK_DF | \         _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * _CrtSetBreakAlloc can be used to set a breakpoint at a particular  * memory leak, add to the macro above.  */
end_comment

begin_endif
unit|Detected memory leaks! Dumping objects -> ..\..\source\os_specific\service_layers\oswinxf.c(701) : {937} normal block at 0x002E9190, 40 bytes long.  Data:<> 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  _CrtSetBreakAlloc (937);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1200
end_if

begin_comment
comment|/* Versions above VC++ 6 */
end_comment

begin_define
define|#
directive|define
name|COMPILER_VA_MACRO
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Begin standard headers */
end_comment

begin_comment
comment|/*  * warn C4001: nonstandard extension 'single line comment' was used  *  * We need to enable this for ACPICA internal files, but disable it for  * buggy MS runtime headers.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4001
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACMSVC_H__ */
end_comment

end_unit

