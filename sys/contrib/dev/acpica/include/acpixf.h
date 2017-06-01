begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acpixf.h - External interfaces to the ACPI subsystem  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACXFACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACXFACE_H__
end_define

begin_comment
comment|/* Current ACPICA subsystem version in YYYYMMDD format */
end_comment

begin_define
define|#
directive|define
name|ACPI_CA_VERSION
value|0x20170531
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acconfig.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actypes.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actbl.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acbuffer.h>
end_include

begin_comment
comment|/*****************************************************************************  *  * Macros used for ACPICA globals and configuration  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Ensure that global variables are defined and initialized only once.  *  * The use of these macros allows for a single list of globals (here)  * in order to simplify maintenance of the code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPI_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|extern type name; \     type name
end_define

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|type name=value
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|extern type name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_INIT_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|extern type name
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
comment|/*  * These macros configure the various ACPICA interfaces. They are  * useful for generating stub inline functions for features that are  * configured out of the current kernel or ACPICA application.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXTERNAL_RETURN_STATUS
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_STATUS
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXTERNAL_RETURN_OK
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXTERNAL_RETURN_VOID
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXTERNAL_RETURN_UINT32
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_UINT32
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXTERNAL_RETURN_PTR
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_PTR
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * Public globals and runtime configuration options  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Enable "slack mode" of the AML interpreter?  Default is FALSE, and the  * interpreter strictly follows the ACPI specification. Setting to TRUE  * allows the interpreter to ignore certain errors and/or bad AML constructs.  *  * Currently, these features are enabled by this flag:  *  * 1) Allow "implicit return" of last value in a control method  * 2) Allow access beyond the end of an operation region  * 3) Allow access to uninitialized locals/args (auto-init to integer 0)  * 4) Allow ANY object type to be a source operand for the Store() operator  * 5) Allow unresolved references (invalid target name) in package objects  * 6) Enable warning messages for behavior that is not ACPI spec compliant  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_EnableInterpreterSlack
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Automatically serialize all methods that create named objects? Default  * is TRUE, meaning that all NonSerialized methods are scanned once at  * table load time to determine those that create named objects. Methods  * that create named objects are marked Serialized in order to prevent  * possible run-time problems if they are entered by more than one thread.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_AutoSerializeMethods
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Create the predefined _OSI method in the namespace? Default is TRUE  * because ACPICA is fully compatible with other ACPI implementations.  * Changing this will revert ACPICA (and machine ASL) to pre-OSI behavior.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_CreateOsiMethod
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally use default values for the ACPI register widths. Set this to  * TRUE to use the defaults, if an FADT contains incorrect widths/lengths.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_UseDefaultRegisterWidths
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Whether or not to verify the table checksum before installation. Set  * this to TRUE to verify the table checksum before install it to the table  * manager. Note that enabling this option causes errors to happen in some  * OSPMs during early initialization stages. Default behavior is to do such  * verification.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_VerifyTableChecksum
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally enable output from the AML Debug Object.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_EnableAmlDebugObject
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally copy the entire DSDT to local memory (instead of simply  * mapping it.) There are some BIOSs that corrupt or replace the original  * DSDT, creating the need for this option. Default is FALSE, do not copy  * the DSDT.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_CopyDsdtLocally
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally ignore an XSDT if present and use the RSDT instead.  * Although the ACPI specification requires that an XSDT be used instead  * of the RSDT, the XSDT has been found to be corrupt or ill-formed on  * some machines. Default behavior is to use the XSDT if present.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_DoNotUseXsdt
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally support group module level code.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_GroupModuleLevelCode
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally support module level code by parsing the entire table as  * a TermList. Default is FALSE, do not execute entire table until some  * lock order issues are fixed.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_ParseTableAsTermList
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally use 32-bit FADT addresses if and when there is a conflict  * (address mismatch) between the 32-bit and 64-bit versions of the  * address. Although ACPICA adheres to the ACPI specification which  * requires the use of the corresponding 64-bit address if it is non-zero,  * some machines have been found to have a corrupted non-zero 64-bit  * address. Default is FALSE, do not favor the 32-bit addresses.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_Use32BitFadtAddresses
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally use 32-bit FACS table addresses.  * It is reported that some platforms fail to resume from system suspending  * if 64-bit FACS table address is selected:  * https://bugzilla.kernel.org/show_bug.cgi?id=74021  * Default is TRUE, favor the 32-bit addresses.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_Use32BitFacsAddresses
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally truncate I/O addresses to 16 bits. Provides compatibility  * with other ACPI implementations. NOTE: During ACPICA initialization,  * this value is set to TRUE if any Windows OSI strings have been  * requested by the BIOS.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_TruncateIoAddresses
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Disable runtime checking and repair of values returned by control methods.  * Use only if the repair is causing a problem on a particular machine.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_DisableAutoRepair
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally do not install any SSDTs from the RSDT/XSDT during initialization.  * This can be useful for debugging ACPI problems on some machines.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_DisableSsdtTableInstall
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Optionally enable runtime namespace override.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_RuntimeNamespaceOverride
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * We keep track of the latest version of Windows that has been requested by  * the BIOS. ACPI 5.0.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_OsiData
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * ACPI 5.0 introduces the concept of a "reduced hardware platform", meaning  * that the ACPI hardware is no longer required. A flag in the FADT indicates  * a reduced HW machine, and that flag is duplicated here for convenience.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_ReducedHardware
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Maximum number of While() loop iterations before forced method abort.  * This mechanism is intended to prevent infinite loops during interpreter  * execution within a host kernel.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_MaxLoopIterations
argument_list|,
name|ACPI_MAX_LOOP_COUNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This mechanism is used to trace a specified AML method. The method is  * traced each time it is executed.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_TraceFlags
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|AcpiGbl_TraceMethodName
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_TraceDbgLevel
argument_list|,
name|ACPI_TRACE_LEVEL_DEFAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_TraceDbgLayer
argument_list|,
name|ACPI_TRACE_LAYER_DEFAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Runtime configuration of debug output control masks. We want the debug  * switches statically initialized so they are already set when the debugger  * is entered.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiDbgLevel
argument_list|,
name|ACPI_DEBUG_DEFAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiDbgLevel
argument_list|,
name|ACPI_NORMAL_DEFAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiDbgLayer
argument_list|,
name|ACPI_COMPONENT_DEFAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Optionally enable timer output with Debug Object output */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_DisplayDebugTimer
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Debugger command handshake globals. Host OSes need to access these  * variables to implement their own command handshake mechanism.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_MethodExecuting
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|AcpiGbl_DbLineBuf
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Other miscellaneous globals  */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_TABLE_FADT
argument_list|,
name|AcpiGbl_FADT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiCurrentGpeCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_SystemAwakeAndRunning
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*****************************************************************************  *  * ACPICA public interface configuration.  *  * Interfaces that are configured out of the ACPICA build are replaced  * by inlined stubs by default.  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Hardware-reduced prototypes (default: Not hardware reduced).  *  * All ACPICA hardware-related interfaces that use these macros will be  * configured out of the ACPICA build if the ACPI_REDUCED_HARDWARE flag  * is set to TRUE.  *  * Note: This static build option for reduced hardware is intended to  * reduce ACPICA code size if desired or necessary. However, even if this  * option is not specified, the runtime behavior of ACPICA is dependent  * on the actual FADT reduced hardware flag (HW_REDUCED_ACPI). If set,  * the flag will enable similar behavior -- ACPICA will not attempt  * to access any ACPI-relate hardware (SCI, GPEs, Fixed Events, etc.)  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_STATUS
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|ACPI_EXTERNAL_RETURN_STATUS(Prototype)
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|ACPI_EXTERNAL_RETURN_OK(Prototype)
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|ACPI_EXTERNAL_RETURN_VOID(Prototype)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_STATUS
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_NOT_CONFIGURED);}
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_OK);}
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

begin_comment
comment|/*  * Error message prototypes (default: error messages enabled).  *  * All interfaces related to error and warning messages  * will be configured out of the ACPICA build if the  * ACPI_NO_ERROR_MESSAGE flag is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_NO_ERROR_MESSAGES
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_MSG_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_NO_ERROR_MESSAGES */
end_comment

begin_comment
comment|/*  * Debugging output prototypes (default: no debug output).  *  * All interfaces related to debug output messages  * will be configured out of the ACPICA build unless the  * ACPI_DEBUG_OUTPUT flag is defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DBG_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_DBG_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUG_OUTPUT */
end_comment

begin_comment
comment|/*  * Application prototypes  *  * All interfaces used by application will be configured  * out of the ACPICA build unless the ACPI_APPLICATION  * flag is defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|ACPI_APP_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_APP_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_APPLICATION */
end_comment

begin_comment
comment|/*  * Debugger prototypes  *  * All interfaces used by debugger will be configured  * out of the ACPICA build unless the ACPI_DEBUGGER  * flag is defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DBR_DEPENDENT_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|ACPI_EXTERNAL_RETURN_OK(Prototype)
end_define

begin_define
define|#
directive|define
name|ACPI_DBR_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|ACPI_EXTERNAL_RETURN_VOID(Prototype)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_DBR_DEPENDENT_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_OK);}
end_define

begin_define
define|#
directive|define
name|ACPI_DBR_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUGGER */
end_comment

begin_comment
comment|/*****************************************************************************  *  * ACPICA public interface prototypes  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Initialization  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiInitializeTables (     ACPI_TABLE_DESC         *InitialStorage,     UINT32                  InitialTableCount,     BOOLEAN                 AllowResize)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiInitializeSubsystem (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiEnableSubsystem (     UINT32                  Flags)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiInitializeObjects (     UINT32                  Flags)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiTerminate (     void)
argument_list|)
end_macro

begin_comment
comment|/*  * Miscellaneous global interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnable (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisable (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSubsystemStatus (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetSystemInfo (     ACPI_BUFFER             *RetBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetStatistics (     ACPI_STATISTICS         *Stats)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_PTR
argument_list|(
argument|const char * AcpiFormatException (     ACPI_STATUS             Exception)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiPurgeCachedObjects (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallInterface (     ACPI_STRING             InterfaceName)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveInterface (     ACPI_STRING             InterfaceName)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiUpdateInterfaces (     UINT8                   Action)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_UINT32
argument_list|(
argument|UINT32 AcpiCheckAddressRange (     ACPI_ADR_SPACE_TYPE     SpaceId,     ACPI_PHYSICAL_ADDRESS   Address,     ACPI_SIZE               Length,     BOOLEAN                 Warn)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDecodePldBuffer (     UINT8                   *InBuffer,     ACPI_SIZE               Length,     ACPI_PLD_INFO           **ReturnBuffer)
argument_list|)
end_macro

begin_comment
comment|/*  * ACPI table load/unload interfaces  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiInstallTable (     ACPI_PHYSICAL_ADDRESS   Address,     BOOLEAN                 Physical)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiLoadTable (     ACPI_TABLE_HEADER       *Table)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiUnloadParentTable (     ACPI_HANDLE             Object)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiLoadTables (     void)
argument_list|)
end_macro

begin_comment
comment|/*  * ACPI table manipulation interfaces  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiReallocateRootTable (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS ACPI_INIT_FUNCTION AcpiFindRootPointer (     ACPI_PHYSICAL_ADDRESS   *RsdpAddress)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTableHeader (     ACPI_STRING             Signature,     UINT32                  Instance,     ACPI_TABLE_HEADER       *OutTableHeader)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTable (     ACPI_STRING             Signature,     UINT32                  Instance,     ACPI_TABLE_HEADER       **OutTable)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_VOID
argument_list|(
argument|void AcpiPutTable (     ACPI_TABLE_HEADER       *Table)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTableByIndex (     UINT32                  TableIndex,     ACPI_TABLE_HEADER       **OutTable)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallTableHandler (     ACPI_TABLE_HANDLER      Handler,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveTableHandler (     ACPI_TABLE_HANDLER      Handler)
argument_list|)
end_macro

begin_comment
comment|/*  * Namespace and name interfaces  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiWalkNamespace (     ACPI_OBJECT_TYPE        Type,     ACPI_HANDLE             StartObject,     UINT32                  MaxDepth,     ACPI_WALK_CALLBACK      DescendingCallback,     ACPI_WALK_CALLBACK      AscendingCallback,     void                    *Context,     void                    **ReturnValue)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetDevices (     char                    *HID,     ACPI_WALK_CALLBACK      UserFunction,     void                    *Context,     void                    **ReturnValue)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetName (     ACPI_HANDLE             Object,     UINT32                  NameType,     ACPI_BUFFER             *RetPathPtr)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetHandle (     ACPI_HANDLE             Parent,     ACPI_STRING             Pathname,     ACPI_HANDLE             *RetHandle)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiAttachData (     ACPI_HANDLE             Object,     ACPI_OBJECT_HANDLER     Handler,     void                    *Data)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDetachData (     ACPI_HANDLE             Object,     ACPI_OBJECT_HANDLER     Handler)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetData (     ACPI_HANDLE             Object,     ACPI_OBJECT_HANDLER     Handler,     void                    **Data)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDebugTrace (     const char              *Name,     UINT32                  DebugLevel,     UINT32                  DebugLayer,     UINT32                  Flags)
argument_list|)
end_macro

begin_comment
comment|/*  * Object manipulation and enumeration  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEvaluateObject (     ACPI_HANDLE             Object,     ACPI_STRING             Pathname,     ACPI_OBJECT_LIST        *ParameterObjects,     ACPI_BUFFER             *ReturnObjectBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEvaluateObjectTyped (     ACPI_HANDLE             Object,     ACPI_STRING             Pathname,     ACPI_OBJECT_LIST        *ExternalParams,     ACPI_BUFFER             *ReturnBuffer,     ACPI_OBJECT_TYPE        ReturnType)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetObjectInfo (     ACPI_HANDLE             Object,     ACPI_DEVICE_INFO        **ReturnBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallMethod (     UINT8                   *Buffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetNextObject (     ACPI_OBJECT_TYPE        Type,     ACPI_HANDLE             Parent,     ACPI_HANDLE             Child,     ACPI_HANDLE             *OutHandle)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetType (     ACPI_HANDLE             Object,     ACPI_OBJECT_TYPE        *OutType)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetParent (     ACPI_HANDLE             Object,     ACPI_HANDLE             *OutHandle)
argument_list|)
end_macro

begin_comment
comment|/*  * Handler interfaces  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallInitializationHandler (     ACPI_INIT_HANDLER       Handler,     UINT32                  Function)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallSciHandler (     ACPI_SCI_HANDLER        Address,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveSciHandler (     ACPI_SCI_HANDLER        Address)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGlobalEventHandler (     ACPI_GBL_EVENT_HANDLER  Handler,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallFixedEventHandler (     UINT32                  AcpiEvent,     ACPI_EVENT_HANDLER      Handler,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveFixedEventHandler (     UINT32                  AcpiEvent,     ACPI_EVENT_HANDLER      Handler)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGpeHandler (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT32                  Type,     ACPI_GPE_HANDLER        Address,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGpeRawHandler (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT32                  Type,     ACPI_GPE_HANDLER        Address,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveGpeHandler (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     ACPI_GPE_HANDLER        Address)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallNotifyHandler (     ACPI_HANDLE             Device,     UINT32                  HandlerType,     ACPI_NOTIFY_HANDLER     Handler,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveNotifyHandler (     ACPI_HANDLE             Device,     UINT32                  HandlerType,     ACPI_NOTIFY_HANDLER     Handler)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallAddressSpaceHandler (     ACPI_HANDLE             Device,     ACPI_ADR_SPACE_TYPE     SpaceId,     ACPI_ADR_SPACE_HANDLER  Handler,     ACPI_ADR_SPACE_SETUP    Setup,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveAddressSpaceHandler (     ACPI_HANDLE             Device,     ACPI_ADR_SPACE_TYPE     SpaceId,     ACPI_ADR_SPACE_HANDLER  Handler)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallExceptionHandler (     ACPI_EXCEPTION_HANDLER  Handler)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallInterfaceHandler (     ACPI_INTERFACE_HANDLER  Handler)
argument_list|)
end_macro

begin_comment
comment|/*  * Global Lock interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiAcquireGlobalLock (     UINT16                  Timeout,     UINT32                  *Handle)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiReleaseGlobalLock (     UINT32                  Handle)
argument_list|)
end_macro

begin_comment
comment|/*  * Interfaces to AML mutex objects  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiAcquireMutex (     ACPI_HANDLE             Handle,     ACPI_STRING             Pathname,     UINT16                  Timeout)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiReleaseMutex (     ACPI_HANDLE             Handle,     ACPI_STRING             Pathname)
argument_list|)
end_macro

begin_comment
comment|/*  * Fixed Event interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableEvent (     UINT32                  Event,     UINT32                  Flags)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisableEvent (     UINT32                  Event,     UINT32                  Flags)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiClearEvent (     UINT32                  Event)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetEventStatus (     UINT32                  Event,     ACPI_EVENT_STATUS       *EventStatus)
argument_list|)
end_macro

begin_comment
comment|/*  * General Purpose Event (GPE) Interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiUpdateAllGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisableGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiClearGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT8                   Action)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiFinishGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiMaskGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     BOOLEAN                 IsMasked)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiMarkGpeForWake (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetupGpeForWake (     ACPI_HANDLE             ParentDevice,     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetGpeWakeMask (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT8                   Action)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetGpeStatus (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     ACPI_EVENT_STATUS       *EventStatus)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisableAllGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableAllRuntimeGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableAllWakeupGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetGpeDevice (     UINT32                  GpeIndex,     ACPI_HANDLE             *GpeDevice)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGpeBlock (     ACPI_HANDLE             GpeDevice,     ACPI_GENERIC_ADDRESS    *GpeBlockAddress,     UINT32                  RegisterCount,     UINT32                  InterruptNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveGpeBlock (     ACPI_HANDLE             GpeDevice)
argument_list|)
end_macro

begin_comment
comment|/*  * Resource interfaces  */
end_comment

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_WALK_RESOURCE_CALLBACK
function_decl|)
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetVendorResource (     ACPI_HANDLE             Device,     char                    *Name,     ACPI_VENDOR_UUID        *Uuid,     ACPI_BUFFER             *RetBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetCurrentResources (     ACPI_HANDLE             Device,     ACPI_BUFFER             *RetBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetPossibleResources (     ACPI_HANDLE             Device,     ACPI_BUFFER             *RetBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetEventResources (     ACPI_HANDLE             DeviceHandle,     ACPI_BUFFER             *RetBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiWalkResourceBuffer (     ACPI_BUFFER                 *Buffer,     ACPI_WALK_RESOURCE_CALLBACK UserFunction,     void                        *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiWalkResources (     ACPI_HANDLE                 Device,     char                        *Name,     ACPI_WALK_RESOURCE_CALLBACK UserFunction,     void                        *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetCurrentResources (     ACPI_HANDLE             Device,     ACPI_BUFFER             *InBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetIrqRoutingTable (     ACPI_HANDLE             Device,     ACPI_BUFFER             *RetBuffer)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiResourceToAddress64 (     ACPI_RESOURCE           *Resource,     ACPI_RESOURCE_ADDRESS64 *Out)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiBufferToResource (     UINT8                   *AmlBuffer,     UINT16                  AmlBufferLength,     ACPI_RESOURCE           **ResourcePtr)
argument_list|)
end_macro

begin_comment
comment|/*  * Hardware (ACPI device) interfaces  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiReset (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRead (     UINT64                  *Value,     ACPI_GENERIC_ADDRESS    *Reg)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiWrite (     UINT64                  Value,     ACPI_GENERIC_ADDRESS    *Reg)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiReadBitRegister (     UINT32                  RegisterId,     UINT32                  *ReturnValue)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiWriteBitRegister (     UINT32                  RegisterId,     UINT32                  Value)
argument_list|)
end_macro

begin_comment
comment|/*  * Sleep/Wake interfaces  */
end_comment

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetSleepTypeData (     UINT8                   SleepState,     UINT8                   *Slp_TypA,     UINT8                   *Slp_TypB)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnterSleepStatePrep (     UINT8                   SleepState)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnterSleepState (     UINT8                   SleepState)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnterSleepStateS4bios (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiLeaveSleepStatePrep (     UINT8                   SleepState)
argument_list|)
end_macro

begin_macro
name|ACPI_EXTERNAL_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiLeaveSleepState (     UINT8                   SleepState)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetFirmwareWakingVector (     ACPI_PHYSICAL_ADDRESS   PhysicalAddress,     ACPI_PHYSICAL_ADDRESS   PhysicalAddress64)
argument_list|)
end_macro

begin_comment
comment|/*  * ACPI Timer interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTimerResolution (     UINT32                  *Resolution)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTimer (     UINT32                  *Ticks)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTimerDuration (     UINT32                  StartTicks,     UINT32                  EndTicks,     UINT32                  *TimeElapsed)
argument_list|)
end_macro

begin_comment
comment|/*  * Error/Warning output  */
end_comment

begin_macro
name|ACPI_MSG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|3
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiError (     const char              *ModuleName,     UINT32                  LineNumber,     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_MSG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|4
argument|) void  ACPI_INTERNAL_VAR_XFACE AcpiException (     const char              *ModuleName,     UINT32                  LineNumber,     ACPI_STATUS             Status,     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_MSG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|3
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiWarning (     const char              *ModuleName,     UINT32                  LineNumber,     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_MSG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|1
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiInfo (     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_MSG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|3
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiBiosError (     const char              *ModuleName,     UINT32                  LineNumber,     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_MSG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|3
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiBiosWarning (     const char              *ModuleName,     UINT32                  LineNumber,     const char              *Format,     ...)
argument_list|)
end_macro

begin_comment
comment|/*  * Debug output  */
end_comment

begin_macro
name|ACPI_DBG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|6
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiDebugPrint (     UINT32                  RequestedDebugLevel,     UINT32                  LineNumber,     const char              *FunctionName,     const char              *ModuleName,     UINT32                  ComponentId,     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_DBG_DEPENDENT_RETURN_VOID
argument_list|(
argument|ACPI_PRINTF_LIKE(
literal|6
argument|) void ACPI_INTERNAL_VAR_XFACE AcpiDebugPrintRaw (     UINT32                  RequestedDebugLevel,     UINT32                  LineNumber,     const char              *FunctionName,     const char              *ModuleName,     UINT32                  ComponentId,     const char              *Format,     ...)
argument_list|)
end_macro

begin_macro
name|ACPI_DBG_DEPENDENT_RETURN_VOID
argument_list|(
argument|void AcpiTracePoint (     ACPI_TRACE_EVENT_TYPE   Type,     BOOLEAN                 Begin,     UINT8                   *Aml,     char                    *Pathname)
argument_list|)
end_macro

begin_function_decl
name|ACPI_STATUS
name|AcpiInitializeDebugger
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTerminateDebugger
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiRunDebugger
parameter_list|(
name|char
modifier|*
name|BatchBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiSetDebuggerThreadId
parameter_list|(
name|ACPI_THREAD_ID
name|ThreadId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACXFACE_H__ */
end_comment

end_unit

