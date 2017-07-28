begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahtable - Table of known ACPI tables with descriptions  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|const
name|AH_TABLE
modifier|*
name|AcpiAhGetTableInfo
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|AH_TABLE
name|Gbl_AcpiSupportedTables
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiAhGetTableInfo  *  * PARAMETERS:  Signature           - ACPI signature (4 chars) to match  *  * RETURN:      Pointer to a valid AH_TABLE. Null if no match found.  *  * DESCRIPTION: Find a match in the "help" table of supported ACPI tables  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|AH_TABLE
modifier|*
name|AcpiAhGetTableInfo
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
block|{
specifier|const
name|AH_TABLE
modifier|*
name|Info
decl_stmt|;
for|for
control|(
name|Info
operator|=
name|Gbl_AcpiSupportedTables
init|;
name|Info
operator|->
name|Signature
condition|;
name|Info
operator|++
control|)
block|{
if|if
condition|(
name|ACPI_COMPARE_NAME
argument_list|(
name|Signature
argument_list|,
name|Info
operator|->
name|Signature
argument_list|)
condition|)
block|{
return|return
operator|(
name|Info
operator|)
return|;
block|}
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Note: Any tables added here should be duplicated within AcpiDmTableData  * in the file common/dmtable.c  */
end_comment

begin_decl_stmt
specifier|const
name|AH_TABLE
name|Gbl_AcpiSupportedTables
index|[]
init|=
block|{
block|{
name|ACPI_SIG_ASF
block|,
literal|"Alert Standard Format table"
block|}
block|,
block|{
name|ACPI_SIG_BERT
block|,
literal|"Boot Error Record Table"
block|}
block|,
block|{
name|ACPI_SIG_BGRT
block|,
literal|"Boot Graphics Resource Table"
block|}
block|,
block|{
name|ACPI_SIG_BOOT
block|,
literal|"Simple Boot Flag Table"
block|}
block|,
block|{
name|ACPI_SIG_CPEP
block|,
literal|"Corrected Platform Error Polling table"
block|}
block|,
block|{
name|ACPI_SIG_CSRT
block|,
literal|"Core System Resource Table"
block|}
block|,
block|{
name|ACPI_SIG_DBG2
block|,
literal|"Debug Port table type 2"
block|}
block|,
block|{
name|ACPI_SIG_DBGP
block|,
literal|"Debug Port table"
block|}
block|,
block|{
name|ACPI_SIG_DMAR
block|,
literal|"DMA Remapping table"
block|}
block|,
block|{
name|ACPI_SIG_DRTM
block|,
literal|"Dynamic Root of Trust for Measurement table"
block|}
block|,
block|{
name|ACPI_SIG_DSDT
block|,
literal|"Differentiated System Description Table (AML table)"
block|}
block|,
block|{
name|ACPI_SIG_ECDT
block|,
literal|"Embedded Controller Boot Resources Table"
block|}
block|,
block|{
name|ACPI_SIG_EINJ
block|,
literal|"Error Injection table"
block|}
block|,
block|{
name|ACPI_SIG_ERST
block|,
literal|"Error Record Serialization Table"
block|}
block|,
block|{
name|ACPI_SIG_FACS
block|,
literal|"Firmware ACPI Control Structure"
block|}
block|,
block|{
name|ACPI_SIG_FADT
block|,
literal|"Fixed ACPI Description Table (FADT)"
block|}
block|,
block|{
name|ACPI_SIG_FPDT
block|,
literal|"Firmware Performance Data Table"
block|}
block|,
block|{
name|ACPI_SIG_GTDT
block|,
literal|"Generic Timer Description Table"
block|}
block|,
block|{
name|ACPI_SIG_HEST
block|,
literal|"Hardware Error Source Table"
block|}
block|,
block|{
name|ACPI_SIG_HMAT
block|,
literal|"Heterogeneous Memory Attributes Table"
block|}
block|,
block|{
name|ACPI_SIG_HPET
block|,
literal|"High Precision Event Timer table"
block|}
block|,
block|{
name|ACPI_SIG_IORT
block|,
literal|"IO Remapping Table"
block|}
block|,
block|{
name|ACPI_SIG_IVRS
block|,
literal|"I/O Virtualization Reporting Structure"
block|}
block|,
block|{
name|ACPI_SIG_LPIT
block|,
literal|"Low Power Idle Table"
block|}
block|,
block|{
name|ACPI_SIG_MADT
block|,
literal|"Multiple APIC Description Table (MADT)"
block|}
block|,
block|{
name|ACPI_SIG_MCFG
block|,
literal|"Memory Mapped Configuration table"
block|}
block|,
block|{
name|ACPI_SIG_MCHI
block|,
literal|"Management Controller Host Interface table"
block|}
block|,
block|{
name|ACPI_SIG_MPST
block|,
literal|"Memory Power State Table"
block|}
block|,
block|{
name|ACPI_SIG_MSCT
block|,
literal|"Maximum System Characteristics Table"
block|}
block|,
block|{
name|ACPI_SIG_MSDM
block|,
literal|"Microsoft Data Management table"
block|}
block|,
block|{
name|ACPI_SIG_MTMR
block|,
literal|"MID Timer Table"
block|}
block|,
block|{
name|ACPI_SIG_NFIT
block|,
literal|"NVDIMM Firmware Interface Table"
block|}
block|,
block|{
name|ACPI_SIG_PCCT
block|,
literal|"Platform Communications Channel Table"
block|}
block|,
block|{
name|ACPI_SIG_PMTT
block|,
literal|"Platform Memory Topology Table"
block|}
block|,
block|{
name|ACPI_SIG_PPTT
block|,
literal|"Processor Properties Topology Table"
block|}
block|,
block|{
name|ACPI_SIG_RASF
block|,
literal|"RAS Features Table"
block|}
block|,
block|{
name|ACPI_RSDP_NAME
block|,
literal|"Root System Description Pointer"
block|}
block|,
block|{
name|ACPI_SIG_RSDT
block|,
literal|"Root System Description Table"
block|}
block|,
block|{
name|ACPI_SIG_S3PT
block|,
literal|"S3 Performance Table"
block|}
block|,
block|{
name|ACPI_SIG_SBST
block|,
literal|"Smart Battery Specification Table"
block|}
block|,
block|{
name|ACPI_SIG_SDEI
block|,
literal|"Software Delegated Exception Interface Table"
block|}
block|,
block|{
name|ACPI_SIG_SLIC
block|,
literal|"Software Licensing Description Table"
block|}
block|,
block|{
name|ACPI_SIG_SLIT
block|,
literal|"System Locality Information Table"
block|}
block|,
block|{
name|ACPI_SIG_SPCR
block|,
literal|"Serial Port Console Redirection table"
block|}
block|,
block|{
name|ACPI_SIG_SPMI
block|,
literal|"Server Platform Management Interface table"
block|}
block|,
block|{
name|ACPI_SIG_SRAT
block|,
literal|"System Resource Affinity Table"
block|}
block|,
block|{
name|ACPI_SIG_SSDT
block|,
literal|"Secondary System Description Table (AML table)"
block|}
block|,
block|{
name|ACPI_SIG_STAO
block|,
literal|"Status Override table"
block|}
block|,
block|{
name|ACPI_SIG_TCPA
block|,
literal|"Trusted Computing Platform Alliance table"
block|}
block|,
block|{
name|ACPI_SIG_TPM2
block|,
literal|"Trusted Platform Module hardware interface table"
block|}
block|,
block|{
name|ACPI_SIG_UEFI
block|,
literal|"UEFI Boot Optimization Table"
block|}
block|,
block|{
name|ACPI_SIG_VRTC
block|,
literal|"Virtual Real-Time Clock Table"
block|}
block|,
block|{
name|ACPI_SIG_WAET
block|,
literal|"Windows ACPI Emulated Devices Table"
block|}
block|,
block|{
name|ACPI_SIG_WDAT
block|,
literal|"Watchdog Action Table"
block|}
block|,
block|{
name|ACPI_SIG_WDDT
block|,
literal|"Watchdog Description Table"
block|}
block|,
block|{
name|ACPI_SIG_WDRT
block|,
literal|"Watchdog Resource Table"
block|}
block|,
block|{
name|ACPI_SIG_WPBT
block|,
literal|"Windows Platform Binary Table"
block|}
block|,
block|{
name|ACPI_SIG_WSMT
block|,
literal|"Windows SMM Security Migrations Table"
block|}
block|,
block|{
name|ACPI_SIG_XENV
block|,
literal|"Xen Environment table"
block|}
block|,
block|{
name|ACPI_SIG_XSDT
block|,
literal|"Extended System Description Table"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

