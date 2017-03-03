begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahaslops - Table of all known ASL operators  *  *****************************************************************************/
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
comment|/*  * ASL operators with syntax (directly from ACPI specification).  * Note: All tokens require a space separator.  * Long lines are automatically split during output.  */
end_comment

begin_decl_stmt
specifier|const
name|AH_ASL_OPERATOR
name|Gbl_AslOperatorInfo
index|[]
init|=
block|{
block|{
literal|"AccessAs"
block|,
literal|"(AccessType, AccessAttribKeyword | "
literal|"ExtendedAttribKeyword (AccessLength))"
block|,
literal|"ChangeFieldUnitAccess"
block|}
block|,
block|{
literal|"Acquire"
block|,
literal|"(SyncObject, TimeoutValue) => Boolean"
block|,
literal|"Acquire a mutex"
block|}
block|,
block|{
literal|"Add"
block|,
literal|"(Addend1, Addend2, Result) => Integer"
block|,
literal|"Integer Add"
block|}
block|,
block|{
literal|"Alias"
block|,
literal|"(SourceObject, AliasObject)"
block|,
literal|"Define a name alias"
block|}
block|,
block|{
literal|"And"
block|,
literal|"(Source1, Source2, Result) => Integer"
block|,
literal|"Integer Bitwise And"
block|}
block|,
block|{
literal|"Arg"
block|,
literal|"Arg0 - Arg6"
block|,
literal|"Method argument data objects"
block|}
block|,
block|{
literal|"BankField"
block|,
literal|"(RegionName, BankName, BankValue, "
literal|"AccessTypeKeyword, LockRuleKeyword, "
literal|"UpdateRuleKeyword) {FieldUnitList}"
block|,
literal|"Declare fields in a banked configuration object"
block|}
block|,
block|{
literal|"Break"
block|,
literal|"No parameters"
block|,
literal|"Continue following the innermost enclosing While"
block|}
block|,
block|{
literal|"BreakPoint"
block|,
literal|"No parameters"
block|,
literal|"Used for debugging, stops execution in the debugger"
block|}
block|,
block|{
literal|"Buffer"
block|,
literal|"(BufferSize) {String or ByteList} => Buffer"
block|,
literal|"Declare Buffer object"
block|}
block|,
block|{
literal|"Case"
block|,
literal|"(Value) {TermList}"
block|,
literal|"Expression for conditional execution"
block|}
block|,
block|{
literal|"Concatenate"
block|,
literal|"(Source1, Source2, Result) => ComputationalData"
block|,
literal|"Concatenate two strings, integers or buffers"
block|}
block|,
block|{
literal|"ConcatenateResTemplate"
block|,
literal|"(Source1, Source2, Result) => Buffer"
block|,
literal|"Concatenate two resource templates"
block|}
block|,
block|{
literal|"CondRefOf"
block|,
literal|"(Source, Result) => Boolean"
block|,
literal|"Conditional reference to an object"
block|}
block|,
block|{
literal|"Connection"
block|,
literal|"(ResourceMacro)"
block|,
literal|"Associate connection with FieldUnits within a Field object"
block|}
block|,
block|{
literal|"Continue"
block|,
literal|"No parameters"
block|,
literal|"Continue innermost enclosing While loop"
block|}
block|,
block|{
literal|"CopyObject"
block|,
literal|"(Source, Destination) => DataRefObject"
block|,
literal|"Copy and existing object"
block|}
block|,
block|{
literal|"CreateBitField"
block|,
literal|"(SourceBuffer, BitIndex, BitFieldName)"
block|,
literal|"Declare a bit field object of a buffer object"
block|}
block|,
block|{
literal|"CreateByteField"
block|,
literal|"(SourceBuffer, ByteIndex, ByteFieldName)"
block|,
literal|"Declare a byte field object of a buffer object"
block|}
block|,
block|{
literal|"CreateDWordField"
block|,
literal|"(SourceBuffer, ByteIndex, DWordFieldName)"
block|,
literal|"Declare a DWord field object of a buffer object"
block|}
block|,
block|{
literal|"CreateField"
block|,
literal|"(SourceBuffer, BitIndex, NumBits, FieldName)"
block|,
literal|"Declare an arbitrary length bit field of a buffer object"
block|}
block|,
block|{
literal|"CreateQWordField"
block|,
literal|"(SourceBuffer, ByteIndex, QWordFieldName)"
block|,
literal|"Declare a QWord field object of a buffer object"
block|}
block|,
block|{
literal|"CreateWordField"
block|,
literal|"(SourceBuffer, ByteIndex, WordFieldName)"
block|,
literal|"Declare a Word field object of a buffer object"
block|}
block|,
block|{
literal|"DataTableRegion"
block|,
literal|"(RegionName, SignatureString, OemIDString, OemTableIDString)"
block|,
literal|"Declare a Data Table Region"
block|}
block|,
block|{
literal|"Debug"
block|,
literal|"No parameters"
block|,
literal|"Debugger output"
block|}
block|,
block|{
literal|"Decrement"
block|,
literal|"(Minuend) => Integer"
block|,
literal|"Decrement an Integer"
block|}
block|,
block|{
literal|"Default"
block|,
literal|"{TermList}"
block|,
literal|"Default execution path in Switch()"
block|}
block|,
block|{
literal|"DefinitionBlock"
block|,
literal|"(AmlFileName, TableSignature, ComplianceRevision, "
literal|"OemId, TableId, OemRevision) {TermList}"
block|,
literal|"Declare a Definition Block"
block|}
block|,
block|{
literal|"DerefOf"
block|,
literal|"(Source) => Object"
block|,
literal|"Dereference an object reference"
block|}
block|,
block|{
literal|"Device"
block|,
literal|"(DeviceName) {TermList}"
block|,
literal|"Declare a bus/device object"
block|}
block|,
block|{
literal|"Divide"
block|,
literal|"(Dividend, Divisor, Remainder, Result) => Integer"
block|,
literal|"Integer Divide"
block|}
block|,
block|{
literal|"Dma"
block|,
literal|"(DmaTypeKeyword, BusMasterKeyword, XferTypeKeyword, "
literal|"DescriptorName) {DmaChannelList} => Buffer"
block|,
literal|"DMA Resource Descriptor macro"
block|}
block|,
block|{
literal|"DWordIo"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, "
literal|"DecodeKeyword, RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, ResourceSourceIndex, "
literal|"ResourceSource, DescriptorName, TypeKeyword, TranslationKeyword)"
block|,
literal|"DWord I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"DWordMemory"
block|,
literal|"(ResourceTypeKeyword, DecodeKeyword, MinKeyword, "
literal|"MaxKeyword, MemTypeKeyword, ReadWriteKeyword, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, ResourceSourceIndex, ResourceSource, DescriptorName, AddressKeyword, "
literal|"TypeKeyword)"
block|,
literal|"DWord Memory Resource Descriptor macro"
block|}
block|,
block|{
literal|"DWordSpace"
block|,
literal|"(ResourceType, ResourceTypeKeyword, DecodeKeyword, "
literal|"MinKeyword, MaxKeyword, TypeSpecificFlags, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, "
literal|"AddressTranslation, RangeLength, "
literal|"ResourceSourceIndex, ResourceSource, DescriptorName)"
block|,
literal|"DWord Space Resource Descriptor macro"
block|}
block|,
block|{
literal|"EisaId"
block|,
literal|"(EisaIdString) => DWordConst"
block|,
literal|"EISA ID String to Integer conversion macro"
block|}
block|,
block|{
literal|"Else"
block|,
literal|"{TermList}"
block|,
literal|"Alternate conditional execution"
block|}
block|,
block|{
literal|"ElseIf"
block|,
literal|"(Predicate)"
block|,
literal|"Conditional execution"
block|}
block|,
block|{
literal|"EndDependentFn"
block|,
literal|"() => Buffer"
block|,
literal|"End Dependent Function Resource Descriptor macro"
block|}
block|,
block|{
literal|"Event"
block|,
literal|"(EventName)"
block|,
literal|"Declare an event synchronization object"
block|}
block|,
block|{
literal|"ExtendedIo"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, "
literal|"DecodeKeyword, RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, RangeLength, "
literal|"TypeSpecificAttributes, DescriptorName, TypeKeyword, TranslationKeyword)"
block|,
literal|"Extended I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"ExtendedMemory"
block|,
literal|"(ResourceTypeKeyword, DecodeKeyword, MinKeyword, "
literal|"MaxKeyword, MemTypeKeyword, ReadWriteKeyword, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, TypeSpecificAttributes, DescriptorName, "
literal|"AddressKeyword, TypeKeyword)"
block|,
literal|"Extended Memory Resource Descriptor macro"
block|}
block|,
block|{
literal|"ExtendedSpace"
block|,
literal|"(ResourceType, ResourceTypeKeyword, DecodeKeyword, "
literal|"MinKeyword, MaxKeyword, TypeSpecificFlags, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, TypeSpecificAttributes, DescriptorName)"
block|,
literal|"Extended Space Resource Descriptor macro"
block|}
block|,
block|{
literal|"External"
block|,
literal|"(ObjectName, ObjectTypeKeyword, ReturnType, ParameterTypes)"
block|,
literal|"Declare external objects"
block|}
block|,
block|{
literal|"Fatal"
block|,
literal|"(Type, Code, Arg)"
block|,
literal|"Fatal error check"
block|}
block|,
block|{
literal|"Field"
block|,
literal|"(RegionName, AccessTypeKeyword, LockRuleKeyword, "
literal|"UpdateRuleKeyword) {FieldUnitList}"
block|,
literal|"Declare fields of an operation region object"
block|}
block|,
block|{
literal|"FindSetLeftBit"
block|,
literal|"(Source, Result) => Integer"
block|,
literal|"Index of first least significant bit set"
block|}
block|,
block|{
literal|"FindSetRightBit"
block|,
literal|"(Source, Result) => Integer"
block|,
literal|"Index of first most significant bit set"
block|}
block|,
block|{
literal|"FixedDma"
block|,
literal|"(DmaRequestLine, Channel, TransferWidthKeyword, DescriptorName) => Buffer"
block|,
literal|"Fixed DMA Resource Descriptor macro"
block|}
block|,
block|{
literal|"FixedIo"
block|,
literal|"(AddressBase, RangeLength, DescriptorName) => Buffer"
block|,
literal|"Fixed I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"FromBcd"
block|,
literal|"(BcdValue, Result) => Integer"
block|,
literal|"Convert from BCD to numeric"
block|}
block|,
block|{
literal|"Function"
block|,
literal|"(FunctionName, ReturnType, ParameterTypes) {TermList}"
block|,
literal|"Declare control method"
block|}
block|,
block|{
literal|"GpioInt"
block|,
literal|"(InterruptTypeKeyword, InterruptLevelKeyword, "
literal|"ShareTypeKeyword, PinConfigKeyword, "
literal|"DebounceTimeout, ResourceSource, "
literal|"ResourceSourceIndex, ResourceTypeKeyword, DescriptorName, "
literal|"RawDataBuffer() {VendorData}) {Pin}"
block|,
literal|"GPIO Interrupt Connection Resource Descriptor Macro"
block|}
block|,
block|{
literal|"GpioIo"
block|,
literal|"(ShareTypeKeyword, PinConfigKeyword, DebounceTimeout, DriveStrength, "
literal|"IoRestrictionKeyword, ResourceSource, "
literal|"ResourceSourceIndex, ResourceTypeKeyword, DescriptorName, "
literal|"RawDataBuffer() {VendorData}) {PinList}"
block|,
literal|"GPIO I/O Connection Resource Descriptor Macro"
block|}
block|,
block|{
literal|"I2cSerialBusV2"
block|,
literal|"(SlaveAddress, SlaveModeKeyword, ConnectionSpeed, "
literal|"AddressingModeKeyword, ResourceSource, "
literal|"ResourceSourceIndex, ResourceTypeKeyword, DescriptorName, Shared, "
literal|"RawDataBuffer() {VendorData})"
block|,
literal|"I2C Serial Bus Connection Resource Descriptor Macro"
block|}
block|,
block|{
literal|"If"
block|,
literal|"(Predicate) {TermList}"
block|,
literal|"Conditional execution"
block|}
block|,
block|{
literal|"Include"
block|,
literal|"(FilePathName)"
block|,
literal|"Include another ASL file"
block|}
block|,
block|{
literal|"Increment"
block|,
literal|"(Addend) => Integer"
block|,
literal|"Increment a Integer"
block|}
block|,
block|{
literal|"Index"
block|,
literal|"(Source, Index, Destination) => ObjectReference"
block|,
literal|"Indexed Reference to member object"
block|}
block|,
block|{
literal|"IndexField"
block|,
literal|"(IndexName, DataName, AccessTypeKeyword, LockRuleKeyword, "
literal|"UpdateRuleKeyword) {FieldUnitList}"
block|,
literal|"Declare Index/Data Fields"
block|}
block|,
block|{
literal|"Interrupt"
block|,
literal|"(ResourceTypeKeyword, InterruptTypeKeyword, InterruptLevelKeyword, "
literal|"ShareTypeKeyword, ResourceSourceIndex, "
literal|"ResourceSource, DescriptorName) {InterruptList} => Buffer"
block|,
literal|"Interrupt Resource Descriptor macro"
block|}
block|,
block|{
literal|"Io"
block|,
literal|"(IoDecodeKeyword, AddressMin, AddressMax, AddressAlignment, "
literal|"RangeLength, DescriptorName) => Buffer"
block|,
literal|"I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"Irq"
block|,
literal|"(InterruptTypeKeyword, InterruptLevelKeyword, ShareTypeKeyword, "
literal|"DescriptorName) {InterruptList} => Buffer"
block|,
literal|"Interrupt Resource Descriptor macro"
block|}
block|,
block|{
literal|"IrqNoFlags"
block|,
literal|"(DescriptorName) {InterruptList} => Buffer"
block|,
literal|"Short Interrupt Resource Descriptor macro"
block|}
block|,
block|{
literal|"LAnd"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical And"
block|}
block|,
block|{
literal|"LEqual"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Equal"
block|}
block|,
block|{
literal|"LGreater"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Greater"
block|}
block|,
block|{
literal|"LGreaterEqual"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Not less"
block|}
block|,
block|{
literal|"LLess"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Less"
block|}
block|,
block|{
literal|"LLessEqual"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Not greater"
block|}
block|,
block|{
literal|"LNot"
block|,
literal|"(Source) => Boolean"
block|,
literal|"Logical Not"
block|}
block|,
block|{
literal|"LNotEqual"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Not equal"
block|}
block|,
block|{
literal|"Load"
block|,
literal|"(Object, DDBHandle)"
block|,
literal|"Load differentiating definition block"
block|}
block|,
block|{
literal|"LoadTable"
block|,
literal|"(SignatureString, OemIdString, OemTableIdString, RootPathString, "
literal|"ParameterPathString, ParameterData) => DDBHandle"
block|,
literal|"Load Table from RSDT/XSDT"
block|}
block|,
block|{
literal|"Local"
block|,
literal|"Local0 - Local7"
block|,
literal|"Method local data objects"
block|}
block|,
block|{
literal|"LOr"
block|,
literal|"(Source1, Source2) => Boolean"
block|,
literal|"Logical Or"
block|}
block|,
block|{
literal|"Match"
block|,
literal|"(SearchPackage, MatchOpKeyword, MatchObject1, MatchOpKeyword, "
literal|"MatchObject2, StartIndex) => Ones | Integer"
block|,
literal|"Search for match in package array"
block|}
block|,
block|{
literal|"Memory24"
block|,
literal|"(ReadWriteKeyword, AddressMinimum, AddressMaximum, AddressAlignment, "
literal|"RangeLength, DescriptorName)"
block|,
literal|"Memory Resource Descriptor macro"
block|}
block|,
block|{
literal|"Memory32"
block|,
literal|"(ReadWriteKeyword, AddressMinimum, AddressMaximum, AddressAlignment, "
literal|"RangeLength, DescriptorName)"
block|,
literal|"Memory Resource Descriptor macro"
block|}
block|,
block|{
literal|"Memory32Fixed"
block|,
literal|"(ReadWriteKeyword, AddressBase, RangeLength, DescriptorName)"
block|,
literal|"Memory Resource Descriptor macro"
block|}
block|,
block|{
literal|"Method"
block|,
literal|"(MethodName, NumArgs, SerializeRuleKeyword, "
literal|"SyncLevel, ReturnType, ParameterTypes) "
literal|"{TermList}"
block|,
literal|"Declare a control method"
block|}
block|,
block|{
literal|"Mid"
block|,
literal|"(Source, Index, Length, Result) => Buffer or String"
block|,
literal|"Return a portion of buffer or string"
block|}
block|,
block|{
literal|"Mod"
block|,
literal|"(Dividend, Divisor, Result) => Integer"
block|,
literal|"Integer Modulo"
block|}
block|,
block|{
literal|"Multiply"
block|,
literal|"(Multiplicand, Multiplier, Result) => Integer"
block|,
literal|"Integer Multiply"
block|}
block|,
block|{
literal|"Mutex"
block|,
literal|"(MutexName, SyncLevel)"
block|,
literal|"Declare a mutex synchronization object"
block|}
block|,
block|{
literal|"Name"
block|,
literal|"(ObjectName, Object)"
block|,
literal|"Declare a Named object"
block|}
block|,
block|{
literal|"NAnd"
block|,
literal|"(Source1, Source2, Result) => Integer"
block|,
literal|"Integer Bitwise Nand"
block|}
block|,
block|{
literal|"NoOp"
block|,
literal|"No parameters"
block|,
literal|"No operation"
block|}
block|,
block|{
literal|"NOr"
block|,
literal|"(Source1, Source2, Result) => Integer"
block|,
literal|"Integer Bitwise Nor"
block|}
block|,
block|{
literal|"Not"
block|,
literal|"(Source, Result) => Integer"
block|,
literal|"Integer Bitwise Not"
block|}
block|,
block|{
literal|"Notify"
block|,
literal|"(Object, NotificationValue)"
block|,
literal|"Notify Object of event"
block|}
block|,
block|{
literal|"ObjectType"
block|,
literal|"(Object) => Integer"
block|,
literal|"Type of object"
block|}
block|,
block|{
literal|"Offset"
block|,
literal|"(ByteOffset)"
block|,
literal|"Change Current Field Unit Offset"
block|}
block|,
block|{
literal|"One"
block|,
literal|"=> Integer"
block|,
literal|"Constant One Object (1)"
block|}
block|,
block|{
literal|"Ones"
block|,
literal|"=> Integer"
block|,
literal|"Constant Ones Object (0xFFFFFFFF or 0xFFFFFFFFFFFFFFFF)"
block|}
block|,
block|{
literal|"OperationRegion"
block|,
literal|"(RegionName, RegionSpaceKeyword, Offset, Length)"
block|,
literal|"Declare an operational region"
block|}
block|,
block|{
literal|"Or"
block|,
literal|"(Source1, Source2, Result) => Integer"
block|,
literal|"Integer Bitwise Or"
block|}
block|,
block|{
literal|"Package"
block|,
literal|"(NumElements) {PackageList} => Package"
block|,
literal|"Declare a package object"
block|}
block|,
block|{
literal|"PowerResource"
block|,
literal|"(ResourceName, SystemLevel, ResourceOrder) {TermList}"
block|,
literal|"Declare a power resource object"
block|}
block|,
block|{
literal|"Processor"
block|,
literal|"(ProcessorName, ProcessorID, PBlockAddress, PblockLength) {TermList}"
block|,
literal|"Declare a processor package"
block|}
block|,
block|{
literal|"QWordIo"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, DecodeKeyword, "
literal|"RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, RangeLength, "
literal|"ResourceSourceIndex, ResourceSource, DescriptorName, TypeKeyword, "
literal|"TranslationKeyword)"
block|,
literal|"QWord I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"QWordMemory"
block|,
literal|"(ResourceTypeKeyword, DecodeKeyword, MinKeyword, MaxKeyword, "
literal|"MemTypeKeyword, ReadWriteKeyword, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, ResourceSourceIndex, ResourceSource, "
literal|"DescriptorName, AddressKeyword, "
literal|"TypeKeyword)"
block|,
literal|"QWord Memory Resource Descriptor macro"
block|}
block|,
block|{
literal|"QWordSpace"
block|,
literal|"(ResourceType, ResourceTypeKeyword, DecodeKeyword, "
literal|"MinKeyword, MaxKeyword, TypeSpecificFlags, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, ResourceSourceIndex, ResourceSource, DescriptorName)"
block|,
literal|"Qword Space Resource Descriptor macro"
block|}
block|,
block|{
literal|"RawDataBuffer"
block|,
literal|"(BufferSize) {ByteList} => RawDataBuffer"
block|,
literal|"Create a raw data buffer (does not use Buffer AML opcode)"
block|}
block|,
block|{
literal|"RefOf"
block|,
literal|"(Object) => ObjectReference"
block|,
literal|"Create Reference to an object"
block|}
block|,
block|{
literal|"Register"
block|,
literal|"(AddressSpaceKeyword, RegisterBitWidth, "
literal|"RegisterBitOffset, RegisterAddress, "
literal|"AccessSize, DescriptorName)"
block|,
literal|"Generic register Resource Descriptor macro"
block|}
block|,
block|{
literal|"Release"
block|,
literal|"(SyncObject)"
block|,
literal|"Release a synchronization object"
block|}
block|,
block|{
literal|"Reset"
block|,
literal|"(SyncObject)"
block|,
literal|"Reset a synchronization object"
block|}
block|,
block|{
literal|"ResourceTemplate"
block|,
literal|"() {ResourceMacroList} => Buffer"
block|,
literal|"Resource to buffer conversion macro"
block|}
block|,
block|{
literal|"Return"
block|,
literal|"None | () | (ReturnArg)"
block|,
literal|"Return from method execution"
block|}
block|,
block|{
literal|"Revision"
block|,
literal|"=> Integer"
block|,
literal|"Constant revision object"
block|}
block|,
block|{
literal|"Scope"
block|,
literal|"(Location) {TermList}"
block|,
literal|"Open named scope "
block|}
block|,
block|{
literal|"ShiftLeft"
block|,
literal|"(Source, ShiftCount, Result) => Integer"
block|,
literal|"Integer shift value left"
block|}
block|,
block|{
literal|"ShiftRight"
block|,
literal|"(Source, ShiftCount, Result) => Integer"
block|,
literal|"Integer shift value right"
block|}
block|,
block|{
literal|"Signal"
block|,
literal|"(SyncObject)"
block|,
literal|"Signal a synchronization object"
block|}
block|,
block|{
literal|"SizeOf"
block|,
literal|"(ObjectName) => Integer"
block|,
literal|"Get the size of a buffer}, string}, or package"
block|}
block|,
block|{
literal|"Sleep"
block|,
literal|"(Milliseconds)"
block|,
literal|"Sleep n milliseconds (yields the processor)"
block|}
block|,
block|{
literal|"SpiSerialBusV2"
block|,
literal|"(DeviceSelection, PolarityKeyword, WireModeKeyword, "
literal|"DataBitLength, SlaveModeKeyword, "
literal|"ConnectionSpeed, ClockPolarityKeyword, ClockPhaseKeyword, "
literal|"ResourceSource, ResourceSourceIndex, "
literal|"ResourceTypeKeyword, DescriptorName, Shared, RawDataBuffer() {VendorData})"
block|,
literal|"SPI Serial Bus Connection Resource Descriptor Macro"
block|}
block|,
block|{
literal|"Stall"
block|,
literal|"(Microseconds)"
block|,
literal|"Delay n microseconds (does not yield the processor)"
block|}
block|,
block|{
literal|"StartDependentFn"
block|,
literal|"(CompatibilityPriority, PerformancePriority) {ResourceList}"
block|,
literal|"Start Dependent Function Resource Descriptor macro"
block|}
block|,
block|{
literal|"StartDependentFnNoPri"
block|,
literal|"() {ResourceList}"
block|,
literal|"Start Dependent Function Resource Descriptor macro"
block|}
block|,
block|{
literal|"Store"
block|,
literal|"(Source, Destination) => DataRefObject"
block|,
literal|"Store object"
block|}
block|,
block|{
literal|"Subtract"
block|,
literal|"(Minuend, Subtrahend, Result) => Integer"
block|,
literal|"Integer Subtract"
block|}
block|,
block|{
literal|"Switch"
block|,
literal|"(Expression) {CaseTermList}"
block|,
literal|"Select code to execute based on expression value"
block|}
block|,
block|{
literal|"ThermalZone"
block|,
literal|"(ThermalZoneName) {TermList}"
block|,
literal|"Declare a thermal zone package"
block|}
block|,
block|{
literal|"Timer"
block|,
literal|"=> Integer"
block|,
literal|"Get 64-bit timer value"
block|}
block|,
block|{
literal|"ToBcd"
block|,
literal|"(Value, Result) => Integer"
block|,
literal|"Convert Integer to BCD"
block|}
block|,
block|{
literal|"ToBuffer"
block|,
literal|"(Data, Result) => Buffer"
block|,
literal|"Convert data type to buffer"
block|}
block|,
block|{
literal|"ToDecimalString"
block|,
literal|"(Data, Result) => String"
block|,
literal|"Convert data type to decimal string"
block|}
block|,
block|{
literal|"ToHexString"
block|,
literal|"(Data, Result) => String"
block|,
literal|"Convert data type to hexadecimal string"
block|}
block|,
block|{
literal|"ToInteger"
block|,
literal|"(Data, Result) => Integer"
block|,
literal|"Convert data type to integer"
block|}
block|,
block|{
literal|"ToString"
block|,
literal|"(Source, Length, Result) => String"
block|,
literal|"Copy ASCII string from buffer"
block|}
block|,
block|{
literal|"ToUuid"
block|,
literal|"(AsciiString) => Buffer"
block|,
literal|"Convert Ascii string to UUID"
block|}
block|,
block|{
literal|"UartSerialBusV2"
block|,
literal|"(ConnectionSpeed, ByteLengthKeyword, StopBitsKeyword, "
literal|"LinesInUse, EndianKeyword, ParityKeyword, "
literal|"FlowControlKeyword, ReceiveBufferSize, TransmitBufferSize, ResourceSource, "
literal|"ResourceSourceIndex, ResourceTypeKeyword, DescriptorName, Shared, "
literal|"RawDataBuffer() {VendorData})"
block|,
literal|"UART Serial Bus Connection Resource Descriptor Macro"
block|}
block|,
block|{
literal|"Unicode"
block|,
literal|"(String) => Buffer"
block|,
literal|"String to Unicode conversion macro"
block|}
block|,
block|{
literal|"Unload"
block|,
literal|"(Handle)"
block|,
literal|"Unload definition block"
block|}
block|,
block|{
literal|"VendorLong"
block|,
literal|"(DescriptorName) {VendorByteList}"
block|,
literal|"Vendor Resource Descriptor"
block|}
block|,
block|{
literal|"VendorShort"
block|,
literal|"(DescriptorName) {VendorByteList}"
block|,
literal|"Vendor Resource Descriptor"
block|}
block|,
block|{
literal|"Wait"
block|,
literal|"(SyncObject, TimeoutValue) => Boolean"
block|,
literal|"Wait on an Event"
block|}
block|,
block|{
literal|"While"
block|,
literal|"(Predicate) {TermList}"
block|,
literal|"Conditional loop"
block|}
block|,
block|{
literal|"WordBusNumber"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, DecodeKeyword, "
literal|"AddressGranularity, AddressMinimum, "
literal|"AddressMaximum, AddressTranslation, RangeLength, ResourceSourceIndex, "
literal|"ResourceSource, DescriptorName)"
block|,
literal|"Word Bus number Resource Descriptor macro"
block|}
block|,
block|{
literal|"WordIo"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, DecodeKeyword, "
literal|"RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, RangeLength, "
literal|"ResourceSourceIndex, ResourceSource, DescriptorName, TypeKeyword, "
literal|"TranslationKeyword)"
block|,
literal|"Word I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"WordSpace"
block|,
literal|"(ResourceType, ResourceTypeKeyword, DecodeKeyword, MinKeyword, "
literal|"MaxKeyword, TypeSpecificFlags, "
literal|"AddressGranularity, AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, ResourceSourceIndex, ResourceSource, DescriptorName)"
block|,
literal|"Word Space Resource Descriptor macro"
block|}
block|,
block|{
literal|"Xor"
block|,
literal|"(Source1, Source2, Result) => Integer"
block|,
literal|"Integer Bitwise Xor"
block|}
block|,
block|{
literal|"Zero"
block|,
literal|"=> Integer"
block|,
literal|"Constant Zero object (0)"
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

end_unit

