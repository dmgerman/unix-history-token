begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahtable - Table of known ACPI tables with descriptions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
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
name|AcpiSupportedTables
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
name|AcpiSupportedTables
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
name|AcpiSupportedTables
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

