begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahaslkey - Table of all known ASL non-operator keywords and  *                         table of iASL Preprocessor directives  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"acpihelp.h"
end_include

begin_comment
comment|/*  * ASL Keyword types and associated actual keywords.  * This table was extracted from the ACPI specification.  */
end_comment

begin_decl_stmt
specifier|const
name|AH_ASL_KEYWORD
name|Gbl_AslKeywordInfo
index|[]
init|=
block|{
block|{
literal|"AccessAttribKeyword"
block|,
literal|"Serial Bus Attributes (with legacy SMBus aliases)"
block|,
literal|":= AttribQuick (SMBusQuick) | AttribSendReceive (SMBusSendReceive) | "
literal|"AttribByte (SMBusByte) | AttribWord (SMBusWord) | "
literal|"AttribBlock (SMBusBlock) | AttribProcessCall (SMBusProcessCall) | "
literal|"AttribBlockProcessCall (SMBusProcessCall)"
block|}
block|,
block|{
literal|"AccessTypeKeyword"
block|,
literal|"Field Access Types"
block|,
literal|":= AnyAcc | ByteAcc | WordAcc | DWordAcc | QWordAcc | BufferAcc"
block|}
block|,
block|{
literal|"AddressingModeKeyword"
block|,
literal|"Mode - Resource Descriptors"
block|,
literal|":= AddressingMode7Bit | AddressingMode10Bit"
block|}
block|,
block|{
literal|"AddressKeyword"
block|,
literal|"ACPI memory range types"
block|,
literal|":= AddressRangeMemory | AddressRangeReserved | "
literal|"AddressRangeNVS | AddressRangeACPI"
block|}
block|,
block|{
literal|"AddressSpaceKeyword"
block|,
literal|"Operation Region Address Space Types"
block|,
literal|":= RegionSpaceKeyword | FFixedHW"
block|}
block|,
block|{
literal|"BusMasterKeyword"
block|,
literal|"DMA Bus Mastering"
block|,
literal|":= BusMaster | NotBusMaster"
block|}
block|,
block|{
literal|"ByteLengthKeyword"
block|,
literal|"Bits per Byte - Resource Descriptors"
block|,
literal|":= DataBitsFive | DataBitsSix | DataBitsSeven | DataBitsEight | DataBitsNine"
block|}
block|,
block|{
literal|"ClockPhaseKeyword"
block|,
literal|"Resource Descriptors"
block|,
literal|":= ClockPhaseFirst | ClockPhaseSecond"
block|}
block|,
block|{
literal|"ClockPolarityKeyword"
block|,
literal|"Resource Descriptors"
block|,
literal|":= ClockPolarityLow | ClockPolarityHigh"
block|}
block|,
block|{
literal|"DecodeKeyword"
block|,
literal|"Type of Memory Decoding - Resource Descriptors"
block|,
literal|":= SubDecode | PosDecode"
block|}
block|,
block|{
literal|"DmaTypeKeyword"
block|,
literal|"DMA Types - DMA Resource Descriptor"
block|,
literal|":= Compatibility | TypeA | TypeB | TypeF"
block|}
block|,
block|{
literal|"EndianKeyword"
block|,
literal|"Endian type - Resource Descriptor"
block|,
literal|":= BigEndian | LittleEndian"
block|}
block|,
block|{
literal|"ExtendedAttribKeyword"
block|,
literal|"Extended Bus Attributes"
block|,
literal|":= AttribBytes (AccessLength) | AttribRawBytes (AccessLength) | "
literal|"AttribRawProcessBytes (AccessLength)"
block|}
block|,
block|{
literal|"FlowControlKeyword"
block|,
literal|"Resource Descriptor"
block|,
literal|":= FlowControlNone | FlowControlXon | FlowControlHardware"
block|}
block|,
block|{
literal|"InterruptLevelKeyword"
block|,
literal|"Interrupt Active Types"
block|,
literal|":= ActiveHigh | ActiveLow | ActiveBoth"
block|}
block|,
block|{
literal|"InterruptTypeKeyword"
block|,
literal|"Interrupt Types"
block|,
literal|":= Edge | Level"
block|}
block|,
block|{
literal|"IoDecodeKeyword"
block|,
literal|"I/O Decoding - IO Resource Descriptor"
block|,
literal|":= Decode16 | Decode10"
block|}
block|,
block|{
literal|"IoRestrictionKeyword"
block|,
literal|"I/O Restriction - GPIO Resource Descriptors"
block|,
literal|":= IoRestrictionNone | IoRestrictionInputOnly | "
literal|"IoRestrictionOutputOnly | IoRestrictionNoneAndPreserve"
block|}
block|,
block|{
literal|"LockRuleKeyword"
block|,
literal|"Global Lock use for Field Operator"
block|,
literal|":= Lock | NoLock"
block|}
block|,
block|{
literal|"MatchOpKeyword"
block|,
literal|"Types for Match Operator"
block|,
literal|":= MTR | MEQ | MLE | MLT | MGE | MGT"
block|}
block|,
block|{
literal|"MaxKeyword"
block|,
literal|"Max Range Type - Resource Descriptors"
block|,
literal|":= MaxFixed | MaxNotFixed"
block|}
block|,
block|{
literal|"MemTypeKeyword"
block|,
literal|"Memory Types - Resource Descriptors"
block|,
literal|":= Cacheable | WriteCombining | Prefetchable | NonCacheable"
block|}
block|,
block|{
literal|"MinKeyword"
block|,
literal|"Min Range Type - Resource Descriptors"
block|,
literal|":= MinFixed | MinNotFixed"
block|}
block|,
block|{
literal|"ObjectTypeKeyword"
block|,
literal|"ACPI Object Types"
block|,
literal|":= UnknownObj | IntObj | StrObj | BuffObj | PkgObj | FieldUnitObj | "
literal|"DeviceObj | EventObj | MethodObj | MutexObj | OpRegionObj | PowerResObj | "
literal|"ProcessorObj | ThermalZoneObj | BuffFieldObj | DDBHandleObj"
block|}
block|,
block|{
literal|"ParityKeyword"
block|,
literal|"Resource Descriptors"
block|,
literal|":= ParityTypeNone | ParityTypeSpace | ParityTypeMark | "
literal|"ParityTypeOdd | ParityTypeEven"
block|}
block|,
block|{
literal|"PinConfigKeyword"
block|,
literal|"Pin Configuration - GPIO Resource Descriptors"
block|,
literal|":= PullDefault | PullUp | PullDown | PullNone"
block|}
block|,
block|{
literal|"PolarityKeyword"
block|,
literal|"Resource Descriptors"
block|,
literal|":= PolarityHigh | PolarityLow"
block|}
block|,
block|{
literal|"RangeTypeKeyword"
block|,
literal|"I/O Range Types - Resource Descriptors"
block|,
literal|":= ISAOnlyRanges | NonISAOnlyRanges | EntireRange"
block|}
block|,
block|{
literal|"ReadWriteKeyword"
block|,
literal|"Memory Access Types - Resource Descriptors"
block|,
literal|":= ReadWrite | ReadOnly"
block|}
block|,
block|{
literal|"RegionSpaceKeyword"
block|,
literal|"Operation Region Address Space Types"
block|,
literal|":= UserDefRegionSpace | SystemIO | SystemMemory | PCI_Config | "
literal|"EmbeddedControl | SMBus | SystemCMOS | PciBarTarget | IPMI | "
literal|"GeneralPurposeIo, GenericSerialBus"
block|}
block|,
block|{
literal|"ResourceTypeKeyword"
block|,
literal|"Resource Usage - Resource Descriptors"
block|,
literal|":= ResourceConsumer | ResourceProducer"
block|}
block|,
block|{
literal|"SerializeRuleKeyword"
block|,
literal|"Control Method Serialization"
block|,
literal|":= Serialized | NotSerialized"
block|}
block|,
block|{
literal|"ShareTypeKeyword"
block|,
literal|"Interrupt Sharing - Resource Descriptors"
block|,
literal|":= Shared | Exclusive | SharedAndWake | ExclusiveAndWake"
block|}
block|,
block|{
literal|"SlaveModeKeyword"
block|,
literal|"Resource Descriptors"
block|,
literal|":= ControllerInitiated | DeviceInitiated"
block|}
block|,
block|{
literal|"StopBitsKeyword"
block|,
literal|"Resource Descriptors"
block|,
literal|":= StopBitsZero | StopBitsOne | StopBitsOnePlusHalf | StopBitsTwo"
block|}
block|,
block|{
literal|"TransferWidthKeyword"
block|,
literal|"DMA Widths - Fixed DMA Resource Descriptor"
block|,
literal|":= Width8bit | Width16bit | Width32bit | Width64bit | "
literal|"Width128bit | Width256bit"
block|}
block|,
block|{
literal|"TranslationKeyword"
block|,
literal|"Translation Density Types - Resource Descriptors"
block|,
literal|":= SparseTranslation | DenseTranslation"
block|}
block|,
block|{
literal|"TypeKeyword"
block|,
literal|"Translation Types - Resource Descriptors"
block|,
literal|":= TypeTranslation | TypeStatic"
block|}
block|,
block|{
literal|"UpdateRuleKeyword"
block|,
literal|"Field Update Rules"
block|,
literal|":= Preserve | WriteAsOnes | WriteAsZeros"
block|}
block|,
block|{
literal|"UserDefRegionSpace"
block|,
literal|"User defined address spaces"
block|,
literal|":= IntegerData => 0x80 - 0xFF"
block|}
block|,
block|{
literal|"WireModeKeyword"
block|,
literal|"SPI Wire Mode - Resource Descriptors"
block|,
literal|":= ThreeWireMode | FourWireMode"
block|}
block|,
block|{
literal|"XferTypeKeyword"
block|,
literal|"DMA Transfer Types"
block|,
literal|":= Transfer8 | Transfer16 | Transfer8_16"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Preprocessor directives */
end_comment

begin_decl_stmt
specifier|const
name|AH_DIRECTIVE_INFO
name|Gbl_PreprocessorDirectives
index|[]
init|=
block|{
block|{
literal|"#include \"Filename\""
block|,
literal|"Standard include of an ASCII ASL source code file"
block|}
block|,
block|{
literal|"#include<Filename>"
block|,
literal|"Alternate syntax for #include, alternate search path"
block|}
block|,
block|{
literal|"#includebuffer \"Filename\"<Name>"
block|,
literal|"Include a binary file to create AML Buffer with ASL namepath"
block|}
block|,
block|{
literal|"#includebuffer<Filename><Name>"
block|,
literal|"Alternate syntax for #includebuffer, alternate search path"
block|}
block|,
block|{
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"#define<Name>,<Defined name>"
block|,
literal|"Simple macro definition (full macros not supported at this time)"
block|}
block|,
block|{
literal|"#define<Expression>,<Defined name>"
block|,
literal|"Simple macro definition (full macros not supported at this time)"
block|}
block|,
block|{
literal|"#undef<Defined name>"
block|,
literal|"Delete a previous #define"
block|}
block|,
block|{
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"#if<Expression>"
block|,
literal|"Evaluate<Expression> and test return value"
block|}
block|,
block|{
literal|"#ifdef<Defined name>"
block|,
literal|"Test existence of the<Defined Name>"
block|}
block|,
block|{
literal|"#ifndef<Defined name>"
block|,
literal|"Test non-existence of the<Defined Name>"
block|}
block|,
block|{
literal|"#elif<Expression>"
block|,
literal|"Else-If contraction - evaluate #if<Expression>, test return value"
block|}
block|,
block|{
literal|"#else"
block|,
literal|"Execute alternate case for a previous #if, #ifdef or #ifndef block"
block|}
block|,
block|{
literal|"#endif"
block|,
literal|"Close a previous #if, #ifdef or #ifndef block"
block|}
block|,
block|{
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"#line<LineNumber> [Filename]"
block|,
literal|"Set the current ASL source code line number, optional filename"
block|}
block|,
block|{
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"#error \"String\""
block|,
literal|"Emit error message and abort compilation"
block|}
block|,
block|{
literal|"#warning \"String\""
block|,
literal|"Emit an iASL warning at this location in the ASL source"
block|}
block|,
block|{
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"#pragma disable (Error number)"
block|,
literal|"Disable an iASL error or warning number"
block|}
block|,
block|{
literal|"#pragma message \"String\""
block|,
literal|"Emit an informational message to the output file(s)"
block|}
block|,
block|{
literal|""
block|,
literal|""
block|}
block|,
block|{
literal|"__FILE__"
block|,
literal|"Return the simple filename of the current ASL file"
block|}
block|,
block|{
literal|"__PATH__"
block|,
literal|"Return the full pathname of the current ASL file"
block|}
block|,
block|{
literal|"__LINE__"
block|,
literal|"Return the current line number within the current ASL file"
block|}
block|,
block|{
literal|"__DATE__"
block|,
literal|"Return the current date"
block|}
block|,
block|{
literal|"__METHOD__"
block|,
literal|"Return the declared name of the current control method"
block|}
block|,
block|{
literal|"__IASL__"
block|,
literal|"Permanently defined for the iASL compiler"
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

