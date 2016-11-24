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
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONBASEINFO_H
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

begin_include
include|#
directive|include
file|<stdint.h>
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
name|TypeDUPLEX
init|=
literal|11
block|,
name|TypeCOMPOUND
init|=
literal|12
block|,
name|TypeCVI_FIRST
init|=
literal|13
block|,
name|TypeCVI_VA
init|=
name|TypeCVI_FIRST
block|,
name|TypeCVI_VA_DV
init|=
literal|14
block|,
name|TypeCVI_VX
init|=
literal|15
block|,
name|TypeCVI_VX_DV
init|=
literal|16
block|,
name|TypeCVI_VP
init|=
literal|17
block|,
name|TypeCVI_VP_VS
init|=
literal|18
block|,
name|TypeCVI_VS
init|=
literal|19
block|,
name|TypeCVI_VINLANESAT
init|=
literal|20
block|,
name|TypeCVI_VM_LD
init|=
literal|21
block|,
name|TypeCVI_VM_TMP_LD
init|=
literal|22
block|,
name|TypeCVI_VM_CUR_LD
init|=
literal|23
block|,
name|TypeCVI_VM_VP_LDU
init|=
literal|24
block|,
name|TypeCVI_VM_ST
init|=
literal|25
block|,
name|TypeCVI_VM_NEW_ST
init|=
literal|26
block|,
name|TypeCVI_VM_STU
init|=
literal|27
block|,
name|TypeCVI_HIST
init|=
literal|28
block|,
name|TypeCVI_LAST
init|=
name|TypeCVI_HIST
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
comment|// MemAccessSize is represented as 1+log2(N) where N is size in bits.
name|enum
name|class
name|MemAccessSize
block|{
name|NoMemAccess
operator|=
literal|0
operator|,
comment|// Not a memory acces instruction.
name|ByteAccess
operator|=
literal|1
operator|,
comment|// Byte access instruction (memb).
name|HalfWordAccess
operator|=
literal|2
operator|,
comment|// Half word access instruction (memh).
name|WordAccess
operator|=
literal|3
operator|,
comment|// Word access instruction (memw).
name|DoubleWordAccess
operator|=
literal|4
operator|,
comment|// Double word access instruction (memd)
comment|// 5,       // We do not have a 16 byte vector access.
name|Vector64Access
operator|=
literal|7
operator|,
comment|// 64 Byte vector access instruction (vmem).
name|Vector128Access
operator|=
literal|8
comment|// 128 Byte vector access instruction (vmem).
block|}
empty_stmt|;
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
comment|// Packed only with A or X-type instructions.
name|SoloAXPos
init|=
literal|6
block|,
name|SoloAXMask
init|=
literal|0x1
block|,
comment|// Only A-type instruction in first slot or nothing.
name|SoloAin1Pos
init|=
literal|7
block|,
name|SoloAin1Mask
init|=
literal|0x1
block|,
comment|// Predicated instructions.
name|PredicatedPos
init|=
literal|8
block|,
name|PredicatedMask
init|=
literal|0x1
block|,
name|PredicatedFalsePos
init|=
literal|9
block|,
name|PredicatedFalseMask
init|=
literal|0x1
block|,
name|PredicatedNewPos
init|=
literal|10
block|,
name|PredicatedNewMask
init|=
literal|0x1
block|,
name|PredicateLatePos
init|=
literal|11
block|,
name|PredicateLateMask
init|=
literal|0x1
block|,
comment|// New-Value consumer instructions.
name|NewValuePos
init|=
literal|12
block|,
name|NewValueMask
init|=
literal|0x1
block|,
comment|// New-Value producer instructions.
name|hasNewValuePos
init|=
literal|13
block|,
name|hasNewValueMask
init|=
literal|0x1
block|,
comment|// Which operand consumes or produces a new value.
name|NewValueOpPos
init|=
literal|14
block|,
name|NewValueOpMask
init|=
literal|0x7
block|,
comment|// Stores that can become new-value stores.
name|mayNVStorePos
init|=
literal|17
block|,
name|mayNVStoreMask
init|=
literal|0x1
block|,
comment|// New-value store instructions.
name|NVStorePos
init|=
literal|18
block|,
name|NVStoreMask
init|=
literal|0x1
block|,
comment|// Loads that can become current-value loads.
name|mayCVLoadPos
init|=
literal|19
block|,
name|mayCVLoadMask
init|=
literal|0x1
block|,
comment|// Current-value load instructions.
name|CVLoadPos
init|=
literal|20
block|,
name|CVLoadMask
init|=
literal|0x1
block|,
comment|// Extendable insns.
name|ExtendablePos
init|=
literal|21
block|,
name|ExtendableMask
init|=
literal|0x1
block|,
comment|// Insns must be extended.
name|ExtendedPos
init|=
literal|22
block|,
name|ExtendedMask
init|=
literal|0x1
block|,
comment|// Which operand may be extended.
name|ExtendableOpPos
init|=
literal|23
block|,
name|ExtendableOpMask
init|=
literal|0x7
block|,
comment|// Signed or unsigned range.
name|ExtentSignedPos
init|=
literal|26
block|,
name|ExtentSignedMask
init|=
literal|0x1
block|,
comment|// Number of bits of range before extending operand.
name|ExtentBitsPos
init|=
literal|27
block|,
name|ExtentBitsMask
init|=
literal|0x1f
block|,
comment|// Alignment power-of-two before extending operand.
name|ExtentAlignPos
init|=
literal|32
block|,
name|ExtentAlignMask
init|=
literal|0x3
block|,
comment|// Valid subtargets
name|validSubTargetPos
init|=
literal|34
block|,
name|validSubTargetMask
init|=
literal|0xf
block|,
comment|// Addressing mode for load/store instructions.
name|AddrModePos
init|=
literal|40
block|,
name|AddrModeMask
init|=
literal|0x7
block|,
comment|// Access size for load/store instructions.
name|MemAccessSizePos
init|=
literal|43
block|,
name|MemAccesSizeMask
init|=
literal|0xf
block|,
comment|// Branch predicted taken.
name|TakenPos
init|=
literal|47
block|,
name|TakenMask
init|=
literal|0x1
block|,
comment|// Floating-point instructions.
name|FPPos
init|=
literal|48
block|,
name|FPMask
init|=
literal|0x1
block|,
comment|// New-Value producer-2 instructions.
name|hasNewValuePos2
init|=
literal|50
block|,
name|hasNewValueMask2
init|=
literal|0x1
block|,
comment|// Which operand consumes or produces a new value.
name|NewValueOpPos2
init|=
literal|51
block|,
name|NewValueOpMask2
init|=
literal|0x7
block|,
comment|// Accumulator instructions.
name|AccumulatorPos
init|=
literal|54
block|,
name|AccumulatorMask
init|=
literal|0x1
block|,
comment|// Complex XU, prevent xu competition by prefering slot3
name|PrefersSlot3Pos
init|=
literal|55
block|,
name|PrefersSlot3Mask
init|=
literal|0x1
block|,   }
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
block|,
comment|// MO_GDGOT - indicates GOT relative relocation for TLS
comment|// GeneralDynamic method
name|MO_GDGOT
block|,
comment|// MO_GDPLT - indicates PLT relative relocation for TLS
comment|// GeneralDynamic method
name|MO_GDPLT
block|,
comment|// MO_IE - indicates non PIC relocation for TLS
comment|// Initial Executable method
name|MO_IE
block|,
comment|// MO_IEGOT - indicates PIC relocation for TLS
comment|// Initial Executable method
name|MO_IEGOT
block|,
comment|// MO_TPREL - indicates relocation for TLS
comment|// local Executable method
name|MO_TPREL
block|}
enum|;
comment|// Hexagon Sub-instruction classes.
enum|enum
name|SubInstructionGroup
block|{
name|HSIG_None
init|=
literal|0
block|,
name|HSIG_L1
block|,
name|HSIG_L2
block|,
name|HSIG_S1
block|,
name|HSIG_S2
block|,
name|HSIG_A
block|,
name|HSIG_Compound
block|}
enum|;
comment|// Hexagon Compound classes.
enum|enum
name|CompoundGroup
block|{
name|HCG_None
init|=
literal|0
block|,
name|HCG_A
block|,
name|HCG_B
block|,
name|HCG_C
block|}
enum|;
enum|enum
name|InstParseBits
block|{
name|INST_PARSE_MASK
init|=
literal|0x0000c000
block|,
name|INST_PARSE_PACKET_END
init|=
literal|0x0000c000
block|,
name|INST_PARSE_LOOP_END
init|=
literal|0x00008000
block|,
name|INST_PARSE_NOT_END
init|=
literal|0x00004000
block|,
name|INST_PARSE_DUPLEX
init|=
literal|0x00000000
block|,
name|INST_PARSE_EXTENDER
init|=
literal|0x00000000
block|}
enum|;
enum|enum
name|InstIClassBits
enum|:
name|unsigned
block|{
name|INST_ICLASS_MASK
init|=
literal|0xf0000000
block|,
name|INST_ICLASS_EXTENDER
init|=
literal|0x00000000
block|,
name|INST_ICLASS_J_1
init|=
literal|0x10000000
block|,
name|INST_ICLASS_J_2
init|=
literal|0x20000000
block|,
name|INST_ICLASS_LD_ST_1
init|=
literal|0x30000000
block|,
name|INST_ICLASS_LD_ST_2
init|=
literal|0x40000000
block|,
name|INST_ICLASS_J_3
init|=
literal|0x50000000
block|,
name|INST_ICLASS_CR
init|=
literal|0x60000000
block|,
name|INST_ICLASS_ALU32_1
init|=
literal|0x70000000
block|,
name|INST_ICLASS_XTYPE_1
init|=
literal|0x80000000
block|,
name|INST_ICLASS_LD
init|=
literal|0x90000000
block|,
name|INST_ICLASS_ST
init|=
literal|0xa0000000
block|,
name|INST_ICLASS_ALU32_2
init|=
literal|0xb0000000
block|,
name|INST_ICLASS_XTYPE_2
init|=
literal|0xc0000000
block|,
name|INST_ICLASS_XTYPE_3
init|=
literal|0xd0000000
block|,
name|INST_ICLASS_XTYPE_4
init|=
literal|0xe0000000
block|,
name|INST_ICLASS_ALU32_3
init|=
literal|0xf0000000
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

