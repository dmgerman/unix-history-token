begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahaslops - Table of all known ASL operators  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2015, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
name|AslOperatorInfo
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
literal|"(DeviceName) {ObjectList}"
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
literal|"DMA"
block|,
literal|"(DmaTypeKeyword, BusMasterKeyword, XferTypeKeyword, "
literal|"DescriptorName) {DmaChannelList} => Buffer"
block|,
literal|"DMA Resource Descriptor macro"
block|}
block|,
block|{
literal|"DWordIO"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, "
literal|"DecodeKeyword, RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, "
literal|"RangeLength, ResourceSourceIndex, "
literal|"ResourceSource, DescriptorName, TypeKeyword, TranslationKeyword)"
block|,
literal|"DWord IO Resource Descriptor macro"
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
literal|"EISAID"
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
literal|"ExtendedIO"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, "
literal|"DecodeKeyword, RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, RangeLength, "
literal|"TypeSpecificAttributes, DescriptorName, TypeKeyword, TranslationKeyword)"
block|,
literal|"Extended IO Resource Descriptor macro"
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
literal|"FixedDMA"
block|,
literal|"(DmaRequestLine, Channel, TransferWidthKeyword, DescriptorName) => Buffer"
block|,
literal|"Fixed DMA Resource Descriptor macro"
block|}
block|,
block|{
literal|"FixedIO"
block|,
literal|"(AddressBase, RangeLength, DescriptorName) => Buffer"
block|,
literal|"Fixed I/O Resource Descriptor macro"
block|}
block|,
block|{
literal|"FromBCD"
block|,
literal|"(BCDValue, Result) => Integer"
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
literal|"I2cSerialBus"
block|,
literal|"(SlaveAddress, SlaveModeKeyword, ConnectionSpeed, "
literal|"AddressingModeKeyword, ResourceSource, "
literal|"ResourceSourceIndex, ResourceTypeKeyword, DescriptorName, "
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
literal|"IO"
block|,
literal|"(IoDecodeKeyword, AddressMin, AddressMax, AddressAlignment, "
literal|"RangeLength, DescriptorName) => Buffer"
block|,
literal|"IO Resource Descriptor macro"
block|}
block|,
block|{
literal|"IRQ"
block|,
literal|"(InterruptTypeKeyword, InterruptLevelKeyword, ShareTypeKeyword, "
literal|"DescriptorName) {InterruptList} => Buffer"
block|,
literal|"Interrupt Resource Descriptor macro"
block|}
block|,
block|{
literal|"IRQNoFlags"
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
literal|"(ResourceName, SystemLevel, ResourceOrder) {ObjectList}"
block|,
literal|"Declare a power resource object"
block|}
block|,
block|{
literal|"Processor"
block|,
literal|"(ProcessorName, ProcessorID, PBlockAddress, PblockLength) {ObjectList}"
block|,
literal|"Declare a processor package"
block|}
block|,
block|{
literal|"QWordIO"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, DecodeKeyword, "
literal|"RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, RangeLength, "
literal|"ResourceSourceIndex, ResourceSource, DescriptorName, TypeKeyword, "
literal|"TranslationKeyword)"
block|,
literal|"QWord IO Resource Descriptor macro"
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
literal|"(Location) {ObjectList}"
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
literal|"SpiSerialBus"
block|,
literal|"(DeviceSelection, PolarityKeyword, WireModeKeyword, "
literal|"DataBitLength, SlaveModeKeyword, "
literal|"ConnectionSpeed, ClockPolarityKeyword, ClockPhaseKeyword, "
literal|"ResourceSource, ResourceSourceIndex, "
literal|"ResourceTypeKeyword, DescriptorName, RawDataBuffer() {VendorData})"
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
literal|"(ThermalZoneName) {ObjectList}"
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
literal|"ToBCD"
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
literal|"ToUUID"
block|,
literal|"(AsciiString) => Buffer"
block|,
literal|"Convert Ascii string to UUID"
block|}
block|,
block|{
literal|"UartSerialBus"
block|,
literal|"(ConnectionSpeed, ByteLengthKeyword, StopBitsKeyword, "
literal|"LinesInUse, EndianKeyword, ParityKeyword, "
literal|"FlowControlKeyword, ReceiveBufferSize, TransmitBufferSize, ResourceSource, "
literal|"ResourceSourceIndex, ResourceTypeKeyword, DescriptorName, "
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
literal|"WordIO"
block|,
literal|"(ResourceTypeKeyword, MinKeyword, MaxKeyword, DecodeKeyword, "
literal|"RangeTypeKeyword, AddressGranularity, "
literal|"AddressMinimum, AddressMaximum, AddressTranslation, RangeLength, "
literal|"ResourceSourceIndex, ResourceSource, DescriptorName, TypeKeyword, "
literal|"TranslationKeyword)"
block|,
literal|"Word IO Resource Descriptor macro"
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
literal|"XOr"
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

