begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: utresdecode - Resource descriptor keyword strings  *  ******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acresrc.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"utresdecode"
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ACPI_DISASSEMBLER
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ACPI_DEBUGGER
argument_list|)
end_if

begin_comment
comment|/*  * Strings used to decode resource descriptors.  * Used by both the disassembler and the debugger resource dump routines  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_BmDecode
index|[]
init|=
block|{
literal|"NotBusMaster"
block|,
literal|"BusMaster"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_ConfigDecode
index|[]
init|=
block|{
literal|"0 - Good Configuration"
block|,
literal|"1 - Acceptable Configuration"
block|,
literal|"2 - Suboptimal Configuration"
block|,
literal|"3 - ***Invalid Configuration***"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_ConsumeDecode
index|[]
init|=
block|{
literal|"ResourceProducer"
block|,
literal|"ResourceConsumer"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_DecDecode
index|[]
init|=
block|{
literal|"PosDecode"
block|,
literal|"SubDecode"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_HeDecode
index|[]
init|=
block|{
literal|"Level"
block|,
literal|"Edge"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_IoDecode
index|[]
init|=
block|{
literal|"Decode10"
block|,
literal|"Decode16"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_LlDecode
index|[]
init|=
block|{
literal|"ActiveHigh"
block|,
literal|"ActiveLow"
block|,
literal|"ActiveBoth"
block|,
literal|"Reserved"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_MaxDecode
index|[]
init|=
block|{
literal|"MaxNotFixed"
block|,
literal|"MaxFixed"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_MemDecode
index|[]
init|=
block|{
literal|"NonCacheable"
block|,
literal|"Cacheable"
block|,
literal|"WriteCombining"
block|,
literal|"Prefetchable"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_MinDecode
index|[]
init|=
block|{
literal|"MinNotFixed"
block|,
literal|"MinFixed"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_MtpDecode
index|[]
init|=
block|{
literal|"AddressRangeMemory"
block|,
literal|"AddressRangeReserved"
block|,
literal|"AddressRangeACPI"
block|,
literal|"AddressRangeNVS"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_RngDecode
index|[]
init|=
block|{
literal|"InvalidRanges"
block|,
literal|"NonISAOnlyRanges"
block|,
literal|"ISAOnlyRanges"
block|,
literal|"EntireRange"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_RwDecode
index|[]
init|=
block|{
literal|"ReadOnly"
block|,
literal|"ReadWrite"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_ShrDecode
index|[]
init|=
block|{
literal|"Exclusive"
block|,
literal|"Shared"
block|,
literal|"ExclusiveAndWake"
block|,
comment|/* ACPI 5.0 */
literal|"SharedAndWake"
comment|/* ACPI 5.0 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_SizDecode
index|[]
init|=
block|{
literal|"Transfer8"
block|,
literal|"Transfer8_16"
block|,
literal|"Transfer16"
block|,
literal|"InvalidSize"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_TrsDecode
index|[]
init|=
block|{
literal|"DenseTranslation"
block|,
literal|"SparseTranslation"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_TtpDecode
index|[]
init|=
block|{
literal|"TypeStatic"
block|,
literal|"TypeTranslation"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_TypDecode
index|[]
init|=
block|{
literal|"Compatibility"
block|,
literal|"TypeA"
block|,
literal|"TypeB"
block|,
literal|"TypeF"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_PpcDecode
index|[]
init|=
block|{
literal|"PullDefault"
block|,
literal|"PullUp"
block|,
literal|"PullDown"
block|,
literal|"PullNone"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_IorDecode
index|[]
init|=
block|{
literal|"IoRestrictionNone"
block|,
literal|"IoRestrictionInputOnly"
block|,
literal|"IoRestrictionOutputOnly"
block|,
literal|"IoRestrictionNoneAndPreserve"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_DtsDecode
index|[]
init|=
block|{
literal|"Width8bit"
block|,
literal|"Width16bit"
block|,
literal|"Width32bit"
block|,
literal|"Width64bit"
block|,
literal|"Width128bit"
block|,
literal|"Width256bit"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GPIO connection type */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_CtDecode
index|[]
init|=
block|{
literal|"Interrupt"
block|,
literal|"I/O"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Serial bus type */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_SbtDecode
index|[]
init|=
block|{
literal|"/* UNKNOWN serial bus type */"
block|,
literal|"I2C"
block|,
literal|"SPI"
block|,
literal|"UART"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* I2C serial bus access mode */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_AmDecode
index|[]
init|=
block|{
literal|"AddressingMode7Bit"
block|,
literal|"AddressingMode10Bit"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* I2C serial bus slave mode */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_SmDecode
index|[]
init|=
block|{
literal|"ControllerInitiated"
block|,
literal|"DeviceInitiated"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SPI serial bus wire mode */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_WmDecode
index|[]
init|=
block|{
literal|"FourWireMode"
block|,
literal|"ThreeWireMode"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SPI serial clock phase */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_CphDecode
index|[]
init|=
block|{
literal|"ClockPhaseFirst"
block|,
literal|"ClockPhaseSecond"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SPI serial bus clock polarity */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_CpoDecode
index|[]
init|=
block|{
literal|"ClockPolarityLow"
block|,
literal|"ClockPolarityHigh"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SPI serial bus device polarity */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_DpDecode
index|[]
init|=
block|{
literal|"PolarityLow"
block|,
literal|"PolarityHigh"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UART serial bus endian */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_EdDecode
index|[]
init|=
block|{
literal|"LittleEndian"
block|,
literal|"BigEndian"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UART serial bus bits per byte */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_BpbDecode
index|[]
init|=
block|{
literal|"DataBitsFive"
block|,
literal|"DataBitsSix"
block|,
literal|"DataBitsSeven"
block|,
literal|"DataBitsEight"
block|,
literal|"DataBitsNine"
block|,
literal|"/* UNKNOWN Bits per byte */"
block|,
literal|"/* UNKNOWN Bits per byte */"
block|,
literal|"/* UNKNOWN Bits per byte */"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UART serial bus stop bits */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_SbDecode
index|[]
init|=
block|{
literal|"StopBitsZero"
block|,
literal|"StopBitsOne"
block|,
literal|"StopBitsOnePlusHalf"
block|,
literal|"StopBitsTwo"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UART serial bus flow control */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_FcDecode
index|[]
init|=
block|{
literal|"FlowControlNone"
block|,
literal|"FlowControlHardware"
block|,
literal|"FlowControlXON"
block|,
literal|"/* UNKNOWN flow control keyword */"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UART serial bus parity type */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_PtDecode
index|[]
init|=
block|{
literal|"ParityTypeNone"
block|,
literal|"ParityTypeEven"
block|,
literal|"ParityTypeOdd"
block|,
literal|"ParityTypeMark"
block|,
literal|"ParityTypeSpace"
block|,
literal|"/* UNKNOWN parity keyword */"
block|,
literal|"/* UNKNOWN parity keyword */"
block|,
literal|"/* UNKNOWN parity keyword */"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PinConfig type */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_PtypDecode
index|[]
init|=
block|{
literal|"Default"
block|,
literal|"Bias Pull-up"
block|,
literal|"Bias Pull-down"
block|,
literal|"Bias Default"
block|,
literal|"Bias Disable"
block|,
literal|"Bias High Impedance"
block|,
literal|"Bias Bus Hold"
block|,
literal|"Drive Open Drain"
block|,
literal|"Drive Open Source"
block|,
literal|"Drive Push Pull"
block|,
literal|"Drive Strength"
block|,
literal|"Slew Rate"
block|,
literal|"Input Debounce"
block|,
literal|"Input Schmitt Trigger"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

