begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonBaseInfo.h - Top level definitions for Hexagon --*- C++ -*--===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the Hexagon target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core
end_comment

begin_comment
comment|// code gen types, passes, etc..
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEXAGONBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONBASEINFO_H
end_define

begin_include
include|#
directive|include
file|"HexagonMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// HexagonII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|HexagonII
block|{
comment|// *** The code below must match HexagonInstrFormat*.td *** //
comment|// Insn types.
comment|// *** Must match HexagonInstrFormat*.td ***
enum|enum
name|Type
block|{
name|TypePSEUDO
init|=
literal|0
block|,
name|TypeALU32
init|=
literal|1
block|,
name|TypeCR
init|=
literal|2
block|,
name|TypeJR
init|=
literal|3
block|,
name|TypeJ
init|=
literal|4
block|,
name|TypeLD
init|=
literal|5
block|,
name|TypeST
init|=
literal|6
block|,
name|TypeSYSTEM
init|=
literal|7
block|,
name|TypeXTYPE
init|=
literal|8
block|,
name|TypeMEMOP
init|=
literal|9
block|,
name|TypeNV
init|=
literal|10
block|,
name|TypePREFIX
init|=
literal|30
block|,
comment|// Such as extenders.
name|TypeENDLOOP
init|=
literal|31
comment|// Such as end of a HW loop.
block|}
enum|;
enum|enum
name|SubTarget
block|{
name|HasV2SubT
init|=
literal|0xf
block|,
name|HasV2SubTOnly
init|=
literal|0x1
block|,
name|NoV2SubT
init|=
literal|0x0
block|,
name|HasV3SubT
init|=
literal|0xe
block|,
name|HasV3SubTOnly
init|=
literal|0x2
block|,
name|NoV3SubT
init|=
literal|0x1
block|,
name|HasV4SubT
init|=
literal|0xc
block|,
name|NoV4SubT
init|=
literal|0x3
block|,
name|HasV5SubT
init|=
literal|0x8
block|,
name|NoV5SubT
init|=
literal|0x7
block|}
enum|;
enum|enum
name|AddrMode
block|{
name|NoAddrMode
init|=
literal|0
block|,
comment|// No addressing mode
name|Absolute
init|=
literal|1
block|,
comment|// Absolute addressing mode
name|AbsoluteSet
init|=
literal|2
block|,
comment|// Absolute set addressing mode
name|BaseImmOffset
init|=
literal|3
block|,
comment|// Indirect with offset
name|BaseLongOffset
init|=
literal|4
block|,
comment|// Indirect with long offset
name|BaseRegOffset
init|=
literal|5
block|,
comment|// Indirect with register offset
name|PostInc
init|=
literal|6
comment|// Post increment addressing mode
block|}
enum|;
enum|enum
name|MemAccessSize
block|{
name|NoMemAccess
init|=
literal|0
block|,
comment|// Not a memory acces instruction.
name|ByteAccess
init|=
literal|1
block|,
comment|// Byte access instruction (memb).
name|HalfWordAccess
init|=
literal|2
block|,
comment|// Half word access instruction (memh).
name|WordAccess
init|=
literal|3
block|,
comment|// Word access instruction (memw).
name|DoubleWordAccess
init|=
literal|4
comment|// Double word access instruction (memd)
block|}
enum|;
comment|// MCInstrDesc TSFlags
comment|// *** Must match HexagonInstrFormat*.td ***
enum|enum
block|{
comment|// This 5-bit field describes the insn type.
name|TypePos
init|=
literal|0
block|,
name|TypeMask
init|=
literal|0x1f
block|,
comment|// Solo instructions.
name|SoloPos
init|=
literal|5
block|,
name|SoloMask
init|=
literal|0x1
block|,
comment|// Predicated instructions.
name|PredicatedPos
init|=
literal|6
block|,
name|PredicatedMask
init|=
literal|0x1
block|,
name|PredicatedFalsePos
init|=
literal|7
block|,
name|PredicatedFalseMask
init|=
literal|0x1
block|,
name|PredicatedNewPos
init|=
literal|8
block|,
name|PredicatedNewMask
init|=
literal|0x1
block|,
comment|// New-Value consumer instructions.
name|NewValuePos
init|=
literal|9
block|,
name|NewValueMask
init|=
literal|0x1
block|,
comment|// New-Value producer instructions.
name|hasNewValuePos
init|=
literal|10
block|,
name|hasNewValueMask
init|=
literal|0x1
block|,
comment|// Which operand consumes or produces a new value.
name|NewValueOpPos
init|=
literal|11
block|,
name|NewValueOpMask
init|=
literal|0x7
block|,
comment|// Which bits encode the new value.
name|NewValueBitsPos
init|=
literal|14
block|,
name|NewValueBitsMask
init|=
literal|0x3
block|,
comment|// Stores that can become new-value stores.
name|mayNVStorePos
init|=
literal|16
block|,
name|mayNVStoreMask
init|=
literal|0x1
block|,
comment|// New-value store instructions.
name|NVStorePos
init|=
literal|17
block|,
name|NVStoreMask
init|=
literal|0x1
block|,
comment|// Extendable insns.
name|ExtendablePos
init|=
literal|18
block|,
name|ExtendableMask
init|=
literal|0x1
block|,
comment|// Insns must be extended.
name|ExtendedPos
init|=
literal|19
block|,
name|ExtendedMask
init|=
literal|0x1
block|,
comment|// Which operand may be extended.
name|ExtendableOpPos
init|=
literal|20
block|,
name|ExtendableOpMask
init|=
literal|0x7
block|,
comment|// Signed or unsigned range.
name|ExtentSignedPos
init|=
literal|23
block|,
name|ExtentSignedMask
init|=
literal|0x1
block|,
comment|// Number of bits of range before extending operand.
name|ExtentBitsPos
init|=
literal|24
block|,
name|ExtentBitsMask
init|=
literal|0x1f
block|,
comment|// Valid subtargets
name|validSubTargetPos
init|=
literal|29
block|,
name|validSubTargetMask
init|=
literal|0xf
block|,
comment|// Addressing mode for load/store instructions.
name|AddrModePos
init|=
literal|33
block|,
name|AddrModeMask
init|=
literal|0x7
block|,
comment|// Access size of memory access instructions (load/store).
name|MemAccessSizePos
init|=
literal|36
block|,
name|MemAccesSizeMask
init|=
literal|0x7
block|}
enum|;
comment|// *** The code above must match HexagonInstrFormat*.td *** //
comment|// Hexagon specific MO operand flag mask.
enum|enum
name|HexagonMOTargetFlagVal
block|{
comment|//===------------------------------------------------------------------===//
comment|// Hexagon Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
name|HMOTF_ConstExtended
init|=
literal|1
block|,
comment|/// MO_PCREL - On a symbol operand, indicates a PC-relative relocation
comment|/// Used for computing a global address for PIC compilations
name|MO_PCREL
block|,
comment|/// MO_GOT - Indicates a GOT-relative relocation
name|MO_GOT
block|,
comment|// Low or high part of a symbol.
name|MO_LO16
block|,
name|MO_HI16
block|,
comment|// Offset from the base of the SDA.
name|MO_GPREL
block|}
enum|;
block|}
comment|// End namespace HexagonII.
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

