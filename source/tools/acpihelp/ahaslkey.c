begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahaslkey - Table of all known ASL non-operator keywords  *  *****************************************************************************/
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
comment|/*  * ASL Keyword types and associated actual keywords.  * This table was extracted from the ACPI specification.  */
end_comment

begin_decl_stmt
specifier|const
name|AH_ASL_KEYWORD
name|AslKeywordInfo
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

end_unit

