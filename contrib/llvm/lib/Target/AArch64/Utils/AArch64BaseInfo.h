begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AArch64BaseInfo.h - Top level definitions for AArch64- --*- C++ -*-===//
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
comment|// the AArch64 target useful for the compiler back-end and the MC libraries.
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
name|LLVM_AARCH64_BASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64_BASEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
comment|// // Enums corresponding to AArch64 condition codes
name|namespace
name|A64CC
block|{
comment|// The CondCodes constants map directly to the 4-bit encoding of the
comment|// condition field for predicated instructions.
enum|enum
name|CondCodes
block|{
comment|// Meaning (integer)          Meaning (floating-point)
name|EQ
init|=
literal|0
block|,
comment|// Equal                      Equal
name|NE
block|,
comment|// Not equal                  Not equal, or unordered
name|HS
block|,
comment|// Unsigned higher or same>, ==, or unordered
name|LO
block|,
comment|// Unsigned lower or same     Less than
name|MI
block|,
comment|// Minus, negative            Less than
name|PL
block|,
comment|// Plus, positive or zero>, ==, or unordered
name|VS
block|,
comment|// Overflow                   Unordered
name|VC
block|,
comment|// No overflow                Ordered
name|HI
block|,
comment|// Unsigned higher            Greater than, or unordered
name|LS
block|,
comment|// Unsigned lower or same     Less than or equal
name|GE
block|,
comment|// Greater than or equal      Greater than or equal
name|LT
block|,
comment|// Less than                  Less than, or unordered
name|GT
block|,
comment|// Signed greater than        Greater than
name|LE
block|,
comment|// Signed less than or equal<, ==, or unordered
name|AL
block|,
comment|// Always (unconditional)     Always (unconditional)
name|NV
block|,
comment|// Always (unconditional)     Always (unconditional)
comment|// Note the NV exists purely to disassemble 0b1111. Execution
comment|// is "always".
name|Invalid
block|}
enum|;
block|}
comment|// namespace A64CC
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|A64CondCodeToString
argument_list|(
name|A64CC
operator|::
name|CondCodes
name|CC
argument_list|)
block|{
switch|switch
condition|(
name|CC
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown condition code"
argument_list|)
expr_stmt|;
case|case
name|A64CC
operator|::
name|EQ
case|:
return|return
literal|"eq"
return|;
case|case
name|A64CC
operator|::
name|NE
case|:
return|return
literal|"ne"
return|;
case|case
name|A64CC
operator|::
name|HS
case|:
return|return
literal|"hs"
return|;
case|case
name|A64CC
operator|::
name|LO
case|:
return|return
literal|"lo"
return|;
case|case
name|A64CC
operator|::
name|MI
case|:
return|return
literal|"mi"
return|;
case|case
name|A64CC
operator|::
name|PL
case|:
return|return
literal|"pl"
return|;
case|case
name|A64CC
operator|::
name|VS
case|:
return|return
literal|"vs"
return|;
case|case
name|A64CC
operator|::
name|VC
case|:
return|return
literal|"vc"
return|;
case|case
name|A64CC
operator|::
name|HI
case|:
return|return
literal|"hi"
return|;
case|case
name|A64CC
operator|::
name|LS
case|:
return|return
literal|"ls"
return|;
case|case
name|A64CC
operator|::
name|GE
case|:
return|return
literal|"ge"
return|;
case|case
name|A64CC
operator|::
name|LT
case|:
return|return
literal|"lt"
return|;
case|case
name|A64CC
operator|::
name|GT
case|:
return|return
literal|"gt"
return|;
case|case
name|A64CC
operator|::
name|LE
case|:
return|return
literal|"le"
return|;
case|case
name|A64CC
operator|::
name|AL
case|:
return|return
literal|"al"
return|;
case|case
name|A64CC
operator|::
name|NV
case|:
return|return
literal|"nv"
return|;
block|}
block|}
specifier|inline
specifier|static
name|A64CC
operator|::
name|CondCodes
name|A64StringToCondCode
argument_list|(
argument|StringRef CondStr
argument_list|)
block|{
return|return
name|StringSwitch
operator|<
name|A64CC
operator|::
name|CondCodes
operator|>
operator|(
name|CondStr
operator|.
name|lower
argument_list|()
operator|)
operator|.
name|Case
argument_list|(
literal|"eq"
argument_list|,
name|A64CC
operator|::
name|EQ
argument_list|)
operator|.
name|Case
argument_list|(
literal|"ne"
argument_list|,
name|A64CC
operator|::
name|NE
argument_list|)
operator|.
name|Case
argument_list|(
literal|"ne"
argument_list|,
name|A64CC
operator|::
name|NE
argument_list|)
operator|.
name|Case
argument_list|(
literal|"hs"
argument_list|,
name|A64CC
operator|::
name|HS
argument_list|)
operator|.
name|Case
argument_list|(
literal|"cs"
argument_list|,
name|A64CC
operator|::
name|HS
argument_list|)
operator|.
name|Case
argument_list|(
literal|"lo"
argument_list|,
name|A64CC
operator|::
name|LO
argument_list|)
operator|.
name|Case
argument_list|(
literal|"cc"
argument_list|,
name|A64CC
operator|::
name|LO
argument_list|)
operator|.
name|Case
argument_list|(
literal|"mi"
argument_list|,
name|A64CC
operator|::
name|MI
argument_list|)
operator|.
name|Case
argument_list|(
literal|"pl"
argument_list|,
name|A64CC
operator|::
name|PL
argument_list|)
operator|.
name|Case
argument_list|(
literal|"vs"
argument_list|,
name|A64CC
operator|::
name|VS
argument_list|)
operator|.
name|Case
argument_list|(
literal|"vc"
argument_list|,
name|A64CC
operator|::
name|VC
argument_list|)
operator|.
name|Case
argument_list|(
literal|"hi"
argument_list|,
name|A64CC
operator|::
name|HI
argument_list|)
operator|.
name|Case
argument_list|(
literal|"ls"
argument_list|,
name|A64CC
operator|::
name|LS
argument_list|)
operator|.
name|Case
argument_list|(
literal|"ge"
argument_list|,
name|A64CC
operator|::
name|GE
argument_list|)
operator|.
name|Case
argument_list|(
literal|"lt"
argument_list|,
name|A64CC
operator|::
name|LT
argument_list|)
operator|.
name|Case
argument_list|(
literal|"gt"
argument_list|,
name|A64CC
operator|::
name|GT
argument_list|)
operator|.
name|Case
argument_list|(
literal|"le"
argument_list|,
name|A64CC
operator|::
name|LE
argument_list|)
operator|.
name|Case
argument_list|(
literal|"al"
argument_list|,
name|A64CC
operator|::
name|AL
argument_list|)
operator|.
name|Case
argument_list|(
literal|"nv"
argument_list|,
name|A64CC
operator|::
name|NV
argument_list|)
operator|.
name|Default
argument_list|(
name|A64CC
operator|::
name|Invalid
argument_list|)
return|;
block|}
specifier|inline
specifier|static
name|A64CC
operator|::
name|CondCodes
name|A64InvertCondCode
argument_list|(
argument|A64CC::CondCodes CC
argument_list|)
block|{
comment|// It turns out that the condition codes have been designed so that in order
comment|// to reverse the intent of the condition you only have to invert the low bit:
return|return
name|static_cast
operator|<
name|A64CC
operator|::
name|CondCodes
operator|>
operator|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|CC
operator|)
operator|^
literal|0x1
operator|)
return|;
block|}
comment|/// Instances of this class can perform bidirectional mapping from random
comment|/// identifier strings to operand encodings. For example "MSR" takes a named
comment|/// system-register which must be encoded somehow and decoded for printing. This
comment|/// central location means that the information for those transformations is not
comment|/// duplicated and remains in sync.
comment|///
comment|/// FIXME: currently the algorithm is a completely unoptimised linear
comment|/// search. Obviously this could be improved, but we would probably want to work
comment|/// out just how often these instructions are emitted before working on it. It
comment|/// might even be optimal to just reorder the tables for the common instructions
comment|/// rather than changing the algorithm.
struct|struct
name|NamedImmMapper
block|{
struct|struct
name|Mapping
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
name|uint32_t
name|Value
decl_stmt|;
block|}
struct|;
name|template
operator|<
name|int
name|N
operator|>
name|NamedImmMapper
argument_list|(
argument|const Mapping (&Pairs)[N]
argument_list|,
argument|uint32_t TooBigImm
argument_list|)
operator|:
name|Pairs
argument_list|(
operator|&
name|Pairs
index|[
literal|0
index|]
argument_list|)
operator|,
name|NumPairs
argument_list|(
name|N
argument_list|)
operator|,
name|TooBigImm
argument_list|(
argument|TooBigImm
argument_list|)
block|{}
name|StringRef
name|toString
argument_list|(
argument|uint32_t Value
argument_list|,
argument|bool&Valid
argument_list|)
specifier|const
expr_stmt|;
name|uint32_t
name|fromString
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
operator|&
name|Valid
argument_list|)
decl|const
decl_stmt|;
comment|/// Many of the instructions allow an alternative assembly form consisting of
comment|/// a simple immediate. Currently the only valid forms are ranges [0, N) where
comment|/// N being 0 indicates no immediate syntax-form is allowed.
name|bool
name|validImm
argument_list|(
name|uint32_t
name|Value
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
specifier|const
name|Mapping
modifier|*
name|Pairs
decl_stmt|;
name|size_t
name|NumPairs
decl_stmt|;
name|uint32_t
name|TooBigImm
decl_stmt|;
block|}
struct|;
name|namespace
name|A64AT
block|{
enum|enum
name|ATValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
comment|// Op0 Op1  CRn   CRm   Op2
name|S1E1R
init|=
literal|0x43c0
block|,
comment|// 01  000  0111  1000  000
name|S1E2R
init|=
literal|0x63c0
block|,
comment|// 01  100  0111  1000  000
name|S1E3R
init|=
literal|0x73c0
block|,
comment|// 01  110  0111  1000  000
name|S1E1W
init|=
literal|0x43c1
block|,
comment|// 01  000  0111  1000  001
name|S1E2W
init|=
literal|0x63c1
block|,
comment|// 01  100  0111  1000  001
name|S1E3W
init|=
literal|0x73c1
block|,
comment|// 01  110  0111  1000  001
name|S1E0R
init|=
literal|0x43c2
block|,
comment|// 01  000  0111  1000  010
name|S1E0W
init|=
literal|0x43c3
block|,
comment|// 01  000  0111  1000  011
name|S12E1R
init|=
literal|0x63c4
block|,
comment|// 01  100  0111  1000  100
name|S12E1W
init|=
literal|0x63c5
block|,
comment|// 01  100  0111  1000  101
name|S12E0R
init|=
literal|0x63c6
block|,
comment|// 01  100  0111  1000  110
name|S12E0W
init|=
literal|0x63c7
comment|// 01  100  0111  1000  111
block|}
enum|;
name|struct
name|ATMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|ATPairs
index|[]
block|;
name|ATMapper
argument_list|()
block|;   }
decl_stmt|;
block|}
name|namespace
name|A64DB
block|{
enum|enum
name|DBValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
name|OSHLD
init|=
literal|0x1
block|,
name|OSHST
init|=
literal|0x2
block|,
name|OSH
init|=
literal|0x3
block|,
name|NSHLD
init|=
literal|0x5
block|,
name|NSHST
init|=
literal|0x6
block|,
name|NSH
init|=
literal|0x7
block|,
name|ISHLD
init|=
literal|0x9
block|,
name|ISHST
init|=
literal|0xa
block|,
name|ISH
init|=
literal|0xb
block|,
name|LD
init|=
literal|0xd
block|,
name|ST
init|=
literal|0xe
block|,
name|SY
init|=
literal|0xf
block|}
enum|;
name|struct
name|DBarrierMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|DBarrierPairs
index|[]
block|;
name|DBarrierMapper
argument_list|()
block|;   }
decl_stmt|;
block|}
name|namespace
name|A64DC
block|{
enum|enum
name|DCValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
comment|// Op1  CRn   CRm   Op2
name|ZVA
init|=
literal|0x5ba1
block|,
comment|// 01  011  0111  0100  001
name|IVAC
init|=
literal|0x43b1
block|,
comment|// 01  000  0111  0110  001
name|ISW
init|=
literal|0x43b2
block|,
comment|// 01  000  0111  0110  010
name|CVAC
init|=
literal|0x5bd1
block|,
comment|// 01  011  0111  1010  001
name|CSW
init|=
literal|0x43d2
block|,
comment|// 01  000  0111  1010  010
name|CVAU
init|=
literal|0x5bd9
block|,
comment|// 01  011  0111  1011  001
name|CIVAC
init|=
literal|0x5bf1
block|,
comment|// 01  011  0111  1110  001
name|CISW
init|=
literal|0x43f2
comment|// 01  000  0111  1110  010
block|}
enum|;
name|struct
name|DCMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|DCPairs
index|[]
block|;
name|DCMapper
argument_list|()
block|;   }
decl_stmt|;
block|}
name|namespace
name|A64IC
block|{
enum|enum
name|ICValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
comment|// Op1  CRn   CRm   Op2
name|IALLUIS
init|=
literal|0x0388
block|,
comment|// 000  0111  0001  000
name|IALLU
init|=
literal|0x03a8
block|,
comment|// 000  0111  0101  000
name|IVAU
init|=
literal|0x1ba9
comment|// 011  0111  0101  001
block|}
enum|;
name|struct
name|ICMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|ICPairs
index|[]
block|;
name|ICMapper
argument_list|()
block|;   }
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|NeedsRegister
parameter_list|(
name|ICValues
name|Val
parameter_list|)
block|{
return|return
name|Val
operator|==
name|IVAU
return|;
block|}
block|}
name|namespace
name|A64ISB
block|{
enum|enum
name|ISBValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
name|SY
init|=
literal|0xf
block|}
enum|;
name|struct
name|ISBMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|ISBPairs
index|[]
block|;
name|ISBMapper
argument_list|()
block|;   }
decl_stmt|;
block|}
name|namespace
name|A64PRFM
block|{
enum|enum
name|PRFMValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
name|PLDL1KEEP
init|=
literal|0x00
block|,
name|PLDL1STRM
init|=
literal|0x01
block|,
name|PLDL2KEEP
init|=
literal|0x02
block|,
name|PLDL2STRM
init|=
literal|0x03
block|,
name|PLDL3KEEP
init|=
literal|0x04
block|,
name|PLDL3STRM
init|=
literal|0x05
block|,
name|PLIL1KEEP
init|=
literal|0x08
block|,
name|PLIL1STRM
init|=
literal|0x09
block|,
name|PLIL2KEEP
init|=
literal|0x0a
block|,
name|PLIL2STRM
init|=
literal|0x0b
block|,
name|PLIL3KEEP
init|=
literal|0x0c
block|,
name|PLIL3STRM
init|=
literal|0x0d
block|,
name|PSTL1KEEP
init|=
literal|0x10
block|,
name|PSTL1STRM
init|=
literal|0x11
block|,
name|PSTL2KEEP
init|=
literal|0x12
block|,
name|PSTL2STRM
init|=
literal|0x13
block|,
name|PSTL3KEEP
init|=
literal|0x14
block|,
name|PSTL3STRM
init|=
literal|0x15
block|}
enum|;
name|struct
name|PRFMMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|PRFMPairs
index|[]
block|;
name|PRFMMapper
argument_list|()
block|;   }
decl_stmt|;
block|}
name|namespace
name|A64PState
block|{
enum|enum
name|PStateValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
name|SPSel
init|=
literal|0x05
block|,
name|DAIFSet
init|=
literal|0x1e
block|,
name|DAIFClr
init|=
literal|0x1f
block|}
enum|;
name|struct
name|PStateMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|PStatePairs
index|[]
block|;
name|PStateMapper
argument_list|()
block|;   }
decl_stmt|;
block|}
name|namespace
name|A64SE
block|{
enum|enum
name|ShiftExtSpecifiers
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
name|LSL
block|,
name|MSL
block|,
name|LSR
block|,
name|ASR
block|,
name|ROR
block|,
name|UXTB
block|,
name|UXTH
block|,
name|UXTW
block|,
name|UXTX
block|,
name|SXTB
block|,
name|SXTH
block|,
name|SXTW
block|,
name|SXTX
block|}
enum|;
block|}
name|namespace
name|A64Layout
block|{
enum|enum
name|VectorLayout
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
name|VL_8B
block|,
name|VL_4H
block|,
name|VL_2S
block|,
name|VL_1D
block|,
name|VL_16B
block|,
name|VL_8H
block|,
name|VL_4S
block|,
name|VL_2D
block|,
comment|// Bare layout for the 128-bit vector
comment|// (only show ".b", ".h", ".s", ".d" without vector number)
name|VL_B
block|,
name|VL_H
block|,
name|VL_S
block|,
name|VL_D
block|}
enum|;
block|}
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|A64VectorLayoutToString
argument_list|(
name|A64Layout
operator|::
name|VectorLayout
name|Layout
argument_list|)
block|{
switch|switch
condition|(
name|Layout
condition|)
block|{
case|case
name|A64Layout
operator|::
name|VL_8B
case|:
return|return
literal|".8b"
return|;
case|case
name|A64Layout
operator|::
name|VL_4H
case|:
return|return
literal|".4h"
return|;
case|case
name|A64Layout
operator|::
name|VL_2S
case|:
return|return
literal|".2s"
return|;
case|case
name|A64Layout
operator|::
name|VL_1D
case|:
return|return
literal|".1d"
return|;
case|case
name|A64Layout
operator|::
name|VL_16B
case|:
return|return
literal|".16b"
return|;
case|case
name|A64Layout
operator|::
name|VL_8H
case|:
return|return
literal|".8h"
return|;
case|case
name|A64Layout
operator|::
name|VL_4S
case|:
return|return
literal|".4s"
return|;
case|case
name|A64Layout
operator|::
name|VL_2D
case|:
return|return
literal|".2d"
return|;
case|case
name|A64Layout
operator|::
name|VL_B
case|:
return|return
literal|".b"
return|;
case|case
name|A64Layout
operator|::
name|VL_H
case|:
return|return
literal|".h"
return|;
case|case
name|A64Layout
operator|::
name|VL_S
case|:
return|return
literal|".s"
return|;
case|case
name|A64Layout
operator|::
name|VL_D
case|:
return|return
literal|".d"
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown Vector Layout"
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
specifier|static
name|A64Layout
operator|::
name|VectorLayout
name|A64StringToVectorLayout
argument_list|(
argument|StringRef LayoutStr
argument_list|)
block|{
return|return
name|StringSwitch
operator|<
name|A64Layout
operator|::
name|VectorLayout
operator|>
operator|(
name|LayoutStr
operator|)
operator|.
name|Case
argument_list|(
literal|".8b"
argument_list|,
name|A64Layout
operator|::
name|VL_8B
argument_list|)
operator|.
name|Case
argument_list|(
literal|".4h"
argument_list|,
name|A64Layout
operator|::
name|VL_4H
argument_list|)
operator|.
name|Case
argument_list|(
literal|".2s"
argument_list|,
name|A64Layout
operator|::
name|VL_2S
argument_list|)
operator|.
name|Case
argument_list|(
literal|".1d"
argument_list|,
name|A64Layout
operator|::
name|VL_1D
argument_list|)
operator|.
name|Case
argument_list|(
literal|".16b"
argument_list|,
name|A64Layout
operator|::
name|VL_16B
argument_list|)
operator|.
name|Case
argument_list|(
literal|".8h"
argument_list|,
name|A64Layout
operator|::
name|VL_8H
argument_list|)
operator|.
name|Case
argument_list|(
literal|".4s"
argument_list|,
name|A64Layout
operator|::
name|VL_4S
argument_list|)
operator|.
name|Case
argument_list|(
literal|".2d"
argument_list|,
name|A64Layout
operator|::
name|VL_2D
argument_list|)
operator|.
name|Case
argument_list|(
literal|".b"
argument_list|,
name|A64Layout
operator|::
name|VL_B
argument_list|)
operator|.
name|Case
argument_list|(
literal|".h"
argument_list|,
name|A64Layout
operator|::
name|VL_H
argument_list|)
operator|.
name|Case
argument_list|(
literal|".s"
argument_list|,
name|A64Layout
operator|::
name|VL_S
argument_list|)
operator|.
name|Case
argument_list|(
literal|".d"
argument_list|,
name|A64Layout
operator|::
name|VL_D
argument_list|)
operator|.
name|Default
argument_list|(
name|A64Layout
operator|::
name|Invalid
argument_list|)
return|;
block|}
name|namespace
name|A64SysReg
block|{
enum|enum
name|SysRegROValues
block|{
name|MDCCSR_EL0
init|=
literal|0x9808
block|,
comment|// 10  011  0000  0001  000
name|DBGDTRRX_EL0
init|=
literal|0x9828
block|,
comment|// 10  011  0000  0101  000
name|MDRAR_EL1
init|=
literal|0x8080
block|,
comment|// 10  000  0001  0000  000
name|OSLSR_EL1
init|=
literal|0x808c
block|,
comment|// 10  000  0001  0001  100
name|DBGAUTHSTATUS_EL1
init|=
literal|0x83f6
block|,
comment|// 10  000  0111  1110  110
name|PMCEID0_EL0
init|=
literal|0xdce6
block|,
comment|// 11  011  1001  1100  110
name|PMCEID1_EL0
init|=
literal|0xdce7
block|,
comment|// 11  011  1001  1100  111
name|MIDR_EL1
init|=
literal|0xc000
block|,
comment|// 11  000  0000  0000  000
name|CCSIDR_EL1
init|=
literal|0xc800
block|,
comment|// 11  001  0000  0000  000
name|CLIDR_EL1
init|=
literal|0xc801
block|,
comment|// 11  001  0000  0000  001
name|CTR_EL0
init|=
literal|0xd801
block|,
comment|// 11  011  0000  0000  001
name|MPIDR_EL1
init|=
literal|0xc005
block|,
comment|// 11  000  0000  0000  101
name|REVIDR_EL1
init|=
literal|0xc006
block|,
comment|// 11  000  0000  0000  110
name|AIDR_EL1
init|=
literal|0xc807
block|,
comment|// 11  001  0000  0000  111
name|DCZID_EL0
init|=
literal|0xd807
block|,
comment|// 11  011  0000  0000  111
name|ID_PFR0_EL1
init|=
literal|0xc008
block|,
comment|// 11  000  0000  0001  000
name|ID_PFR1_EL1
init|=
literal|0xc009
block|,
comment|// 11  000  0000  0001  001
name|ID_DFR0_EL1
init|=
literal|0xc00a
block|,
comment|// 11  000  0000  0001  010
name|ID_AFR0_EL1
init|=
literal|0xc00b
block|,
comment|// 11  000  0000  0001  011
name|ID_MMFR0_EL1
init|=
literal|0xc00c
block|,
comment|// 11  000  0000  0001  100
name|ID_MMFR1_EL1
init|=
literal|0xc00d
block|,
comment|// 11  000  0000  0001  101
name|ID_MMFR2_EL1
init|=
literal|0xc00e
block|,
comment|// 11  000  0000  0001  110
name|ID_MMFR3_EL1
init|=
literal|0xc00f
block|,
comment|// 11  000  0000  0001  111
name|ID_ISAR0_EL1
init|=
literal|0xc010
block|,
comment|// 11  000  0000  0010  000
name|ID_ISAR1_EL1
init|=
literal|0xc011
block|,
comment|// 11  000  0000  0010  001
name|ID_ISAR2_EL1
init|=
literal|0xc012
block|,
comment|// 11  000  0000  0010  010
name|ID_ISAR3_EL1
init|=
literal|0xc013
block|,
comment|// 11  000  0000  0010  011
name|ID_ISAR4_EL1
init|=
literal|0xc014
block|,
comment|// 11  000  0000  0010  100
name|ID_ISAR5_EL1
init|=
literal|0xc015
block|,
comment|// 11  000  0000  0010  101
name|ID_AA64PFR0_EL1
init|=
literal|0xc020
block|,
comment|// 11  000  0000  0100  000
name|ID_AA64PFR1_EL1
init|=
literal|0xc021
block|,
comment|// 11  000  0000  0100  001
name|ID_AA64DFR0_EL1
init|=
literal|0xc028
block|,
comment|// 11  000  0000  0101  000
name|ID_AA64DFR1_EL1
init|=
literal|0xc029
block|,
comment|// 11  000  0000  0101  001
name|ID_AA64AFR0_EL1
init|=
literal|0xc02c
block|,
comment|// 11  000  0000  0101  100
name|ID_AA64AFR1_EL1
init|=
literal|0xc02d
block|,
comment|// 11  000  0000  0101  101
name|ID_AA64ISAR0_EL1
init|=
literal|0xc030
block|,
comment|// 11  000  0000  0110  000
name|ID_AA64ISAR1_EL1
init|=
literal|0xc031
block|,
comment|// 11  000  0000  0110  001
name|ID_AA64MMFR0_EL1
init|=
literal|0xc038
block|,
comment|// 11  000  0000  0111  000
name|ID_AA64MMFR1_EL1
init|=
literal|0xc039
block|,
comment|// 11  000  0000  0111  001
name|MVFR0_EL1
init|=
literal|0xc018
block|,
comment|// 11  000  0000  0011  000
name|MVFR1_EL1
init|=
literal|0xc019
block|,
comment|// 11  000  0000  0011  001
name|MVFR2_EL1
init|=
literal|0xc01a
block|,
comment|// 11  000  0000  0011  010
name|RVBAR_EL1
init|=
literal|0xc601
block|,
comment|// 11  000  1100  0000  001
name|RVBAR_EL2
init|=
literal|0xe601
block|,
comment|// 11  100  1100  0000  001
name|RVBAR_EL3
init|=
literal|0xf601
block|,
comment|// 11  110  1100  0000  001
name|ISR_EL1
init|=
literal|0xc608
block|,
comment|// 11  000  1100  0001  000
name|CNTPCT_EL0
init|=
literal|0xdf01
block|,
comment|// 11  011  1110  0000  001
name|CNTVCT_EL0
init|=
literal|0xdf02
block|,
comment|// 11  011  1110  0000  010
comment|// Trace registers
name|TRCSTATR
init|=
literal|0x8818
block|,
comment|// 10  001  0000  0011  000
name|TRCIDR8
init|=
literal|0x8806
block|,
comment|// 10  001  0000  0000  110
name|TRCIDR9
init|=
literal|0x880e
block|,
comment|// 10  001  0000  0001  110
name|TRCIDR10
init|=
literal|0x8816
block|,
comment|// 10  001  0000  0010  110
name|TRCIDR11
init|=
literal|0x881e
block|,
comment|// 10  001  0000  0011  110
name|TRCIDR12
init|=
literal|0x8826
block|,
comment|// 10  001  0000  0100  110
name|TRCIDR13
init|=
literal|0x882e
block|,
comment|// 10  001  0000  0101  110
name|TRCIDR0
init|=
literal|0x8847
block|,
comment|// 10  001  0000  1000  111
name|TRCIDR1
init|=
literal|0x884f
block|,
comment|// 10  001  0000  1001  111
name|TRCIDR2
init|=
literal|0x8857
block|,
comment|// 10  001  0000  1010  111
name|TRCIDR3
init|=
literal|0x885f
block|,
comment|// 10  001  0000  1011  111
name|TRCIDR4
init|=
literal|0x8867
block|,
comment|// 10  001  0000  1100  111
name|TRCIDR5
init|=
literal|0x886f
block|,
comment|// 10  001  0000  1101  111
name|TRCIDR6
init|=
literal|0x8877
block|,
comment|// 10  001  0000  1110  111
name|TRCIDR7
init|=
literal|0x887f
block|,
comment|// 10  001  0000  1111  111
name|TRCOSLSR
init|=
literal|0x888c
block|,
comment|// 10  001  0001  0001  100
name|TRCPDSR
init|=
literal|0x88ac
block|,
comment|// 10  001  0001  0101  100
name|TRCDEVAFF0
init|=
literal|0x8bd6
block|,
comment|// 10  001  0111  1010  110
name|TRCDEVAFF1
init|=
literal|0x8bde
block|,
comment|// 10  001  0111  1011  110
name|TRCLSR
init|=
literal|0x8bee
block|,
comment|// 10  001  0111  1101  110
name|TRCAUTHSTATUS
init|=
literal|0x8bf6
block|,
comment|// 10  001  0111  1110  110
name|TRCDEVARCH
init|=
literal|0x8bfe
block|,
comment|// 10  001  0111  1111  110
name|TRCDEVID
init|=
literal|0x8b97
block|,
comment|// 10  001  0111  0010  111
name|TRCDEVTYPE
init|=
literal|0x8b9f
block|,
comment|// 10  001  0111  0011  111
name|TRCPIDR4
init|=
literal|0x8ba7
block|,
comment|// 10  001  0111  0100  111
name|TRCPIDR5
init|=
literal|0x8baf
block|,
comment|// 10  001  0111  0101  111
name|TRCPIDR6
init|=
literal|0x8bb7
block|,
comment|// 10  001  0111  0110  111
name|TRCPIDR7
init|=
literal|0x8bbf
block|,
comment|// 10  001  0111  0111  111
name|TRCPIDR0
init|=
literal|0x8bc7
block|,
comment|// 10  001  0111  1000  111
name|TRCPIDR1
init|=
literal|0x8bcf
block|,
comment|// 10  001  0111  1001  111
name|TRCPIDR2
init|=
literal|0x8bd7
block|,
comment|// 10  001  0111  1010  111
name|TRCPIDR3
init|=
literal|0x8bdf
block|,
comment|// 10  001  0111  1011  111
name|TRCCIDR0
init|=
literal|0x8be7
block|,
comment|// 10  001  0111  1100  111
name|TRCCIDR1
init|=
literal|0x8bef
block|,
comment|// 10  001  0111  1101  111
name|TRCCIDR2
init|=
literal|0x8bf7
block|,
comment|// 10  001  0111  1110  111
name|TRCCIDR3
init|=
literal|0x8bff
block|,
comment|// 10  001  0111  1111  111
comment|// GICv3 registers
name|ICC_IAR1_EL1
init|=
literal|0xc660
block|,
comment|// 11  000  1100  1100  000
name|ICC_IAR0_EL1
init|=
literal|0xc640
block|,
comment|// 11  000  1100  1000  000
name|ICC_HPPIR1_EL1
init|=
literal|0xc662
block|,
comment|// 11  000  1100  1100  010
name|ICC_HPPIR0_EL1
init|=
literal|0xc642
block|,
comment|// 11  000  1100  1000  010
name|ICC_RPR_EL1
init|=
literal|0xc65b
block|,
comment|// 11  000  1100  1011  011
name|ICH_VTR_EL2
init|=
literal|0xe659
block|,
comment|// 11  100  1100  1011  001
name|ICH_EISR_EL2
init|=
literal|0xe65b
block|,
comment|// 11  100  1100  1011  011
name|ICH_ELSR_EL2
init|=
literal|0xe65d
comment|// 11  100  1100  1011  101
block|}
enum|;
enum|enum
name|SysRegWOValues
block|{
name|DBGDTRTX_EL0
init|=
literal|0x9828
block|,
comment|// 10  011  0000  0101  000
name|OSLAR_EL1
init|=
literal|0x8084
block|,
comment|// 10  000  0001  0000  100
name|PMSWINC_EL0
init|=
literal|0xdce4
block|,
comment|// 11  011  1001  1100  100
comment|// Trace Registers
name|TRCOSLAR
init|=
literal|0x8884
block|,
comment|// 10  001  0001  0000  100
name|TRCLAR
init|=
literal|0x8be6
block|,
comment|// 10  001  0111  1100  110
comment|// GICv3 registers
name|ICC_EOIR1_EL1
init|=
literal|0xc661
block|,
comment|// 11  000  1100  1100  001
name|ICC_EOIR0_EL1
init|=
literal|0xc641
block|,
comment|// 11  000  1100  1000  001
name|ICC_DIR_EL1
init|=
literal|0xc659
block|,
comment|// 11  000  1100  1011  001
name|ICC_SGI1R_EL1
init|=
literal|0xc65d
block|,
comment|// 11  000  1100  1011  101
name|ICC_ASGI1R_EL1
init|=
literal|0xc65e
block|,
comment|// 11  000  1100  1011  110
name|ICC_SGI0R_EL1
init|=
literal|0xc65f
comment|// 11  000  1100  1011  111
block|}
enum|;
enum|enum
name|SysRegValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
comment|// Op0 Op1  CRn   CRm   Op2
name|OSDTRRX_EL1
init|=
literal|0x8002
block|,
comment|// 10  000  0000  0000  010
name|OSDTRTX_EL1
init|=
literal|0x801a
block|,
comment|// 10  000  0000  0011  010
name|TEECR32_EL1
init|=
literal|0x9000
block|,
comment|// 10  010  0000  0000  000
name|MDCCINT_EL1
init|=
literal|0x8010
block|,
comment|// 10  000  0000  0010  000
name|MDSCR_EL1
init|=
literal|0x8012
block|,
comment|// 10  000  0000  0010  010
name|DBGDTR_EL0
init|=
literal|0x9820
block|,
comment|// 10  011  0000  0100  000
name|OSECCR_EL1
init|=
literal|0x8032
block|,
comment|// 10  000  0000  0110  010
name|DBGVCR32_EL2
init|=
literal|0xa038
block|,
comment|// 10  100  0000  0111  000
name|DBGBVR0_EL1
init|=
literal|0x8004
block|,
comment|// 10  000  0000  0000  100
name|DBGBVR1_EL1
init|=
literal|0x800c
block|,
comment|// 10  000  0000  0001  100
name|DBGBVR2_EL1
init|=
literal|0x8014
block|,
comment|// 10  000  0000  0010  100
name|DBGBVR3_EL1
init|=
literal|0x801c
block|,
comment|// 10  000  0000  0011  100
name|DBGBVR4_EL1
init|=
literal|0x8024
block|,
comment|// 10  000  0000  0100  100
name|DBGBVR5_EL1
init|=
literal|0x802c
block|,
comment|// 10  000  0000  0101  100
name|DBGBVR6_EL1
init|=
literal|0x8034
block|,
comment|// 10  000  0000  0110  100
name|DBGBVR7_EL1
init|=
literal|0x803c
block|,
comment|// 10  000  0000  0111  100
name|DBGBVR8_EL1
init|=
literal|0x8044
block|,
comment|// 10  000  0000  1000  100
name|DBGBVR9_EL1
init|=
literal|0x804c
block|,
comment|// 10  000  0000  1001  100
name|DBGBVR10_EL1
init|=
literal|0x8054
block|,
comment|// 10  000  0000  1010  100
name|DBGBVR11_EL1
init|=
literal|0x805c
block|,
comment|// 10  000  0000  1011  100
name|DBGBVR12_EL1
init|=
literal|0x8064
block|,
comment|// 10  000  0000  1100  100
name|DBGBVR13_EL1
init|=
literal|0x806c
block|,
comment|// 10  000  0000  1101  100
name|DBGBVR14_EL1
init|=
literal|0x8074
block|,
comment|// 10  000  0000  1110  100
name|DBGBVR15_EL1
init|=
literal|0x807c
block|,
comment|// 10  000  0000  1111  100
name|DBGBCR0_EL1
init|=
literal|0x8005
block|,
comment|// 10  000  0000  0000  101
name|DBGBCR1_EL1
init|=
literal|0x800d
block|,
comment|// 10  000  0000  0001  101
name|DBGBCR2_EL1
init|=
literal|0x8015
block|,
comment|// 10  000  0000  0010  101
name|DBGBCR3_EL1
init|=
literal|0x801d
block|,
comment|// 10  000  0000  0011  101
name|DBGBCR4_EL1
init|=
literal|0x8025
block|,
comment|// 10  000  0000  0100  101
name|DBGBCR5_EL1
init|=
literal|0x802d
block|,
comment|// 10  000  0000  0101  101
name|DBGBCR6_EL1
init|=
literal|0x8035
block|,
comment|// 10  000  0000  0110  101
name|DBGBCR7_EL1
init|=
literal|0x803d
block|,
comment|// 10  000  0000  0111  101
name|DBGBCR8_EL1
init|=
literal|0x8045
block|,
comment|// 10  000  0000  1000  101
name|DBGBCR9_EL1
init|=
literal|0x804d
block|,
comment|// 10  000  0000  1001  101
name|DBGBCR10_EL1
init|=
literal|0x8055
block|,
comment|// 10  000  0000  1010  101
name|DBGBCR11_EL1
init|=
literal|0x805d
block|,
comment|// 10  000  0000  1011  101
name|DBGBCR12_EL1
init|=
literal|0x8065
block|,
comment|// 10  000  0000  1100  101
name|DBGBCR13_EL1
init|=
literal|0x806d
block|,
comment|// 10  000  0000  1101  101
name|DBGBCR14_EL1
init|=
literal|0x8075
block|,
comment|// 10  000  0000  1110  101
name|DBGBCR15_EL1
init|=
literal|0x807d
block|,
comment|// 10  000  0000  1111  101
name|DBGWVR0_EL1
init|=
literal|0x8006
block|,
comment|// 10  000  0000  0000  110
name|DBGWVR1_EL1
init|=
literal|0x800e
block|,
comment|// 10  000  0000  0001  110
name|DBGWVR2_EL1
init|=
literal|0x8016
block|,
comment|// 10  000  0000  0010  110
name|DBGWVR3_EL1
init|=
literal|0x801e
block|,
comment|// 10  000  0000  0011  110
name|DBGWVR4_EL1
init|=
literal|0x8026
block|,
comment|// 10  000  0000  0100  110
name|DBGWVR5_EL1
init|=
literal|0x802e
block|,
comment|// 10  000  0000  0101  110
name|DBGWVR6_EL1
init|=
literal|0x8036
block|,
comment|// 10  000  0000  0110  110
name|DBGWVR7_EL1
init|=
literal|0x803e
block|,
comment|// 10  000  0000  0111  110
name|DBGWVR8_EL1
init|=
literal|0x8046
block|,
comment|// 10  000  0000  1000  110
name|DBGWVR9_EL1
init|=
literal|0x804e
block|,
comment|// 10  000  0000  1001  110
name|DBGWVR10_EL1
init|=
literal|0x8056
block|,
comment|// 10  000  0000  1010  110
name|DBGWVR11_EL1
init|=
literal|0x805e
block|,
comment|// 10  000  0000  1011  110
name|DBGWVR12_EL1
init|=
literal|0x8066
block|,
comment|// 10  000  0000  1100  110
name|DBGWVR13_EL1
init|=
literal|0x806e
block|,
comment|// 10  000  0000  1101  110
name|DBGWVR14_EL1
init|=
literal|0x8076
block|,
comment|// 10  000  0000  1110  110
name|DBGWVR15_EL1
init|=
literal|0x807e
block|,
comment|// 10  000  0000  1111  110
name|DBGWCR0_EL1
init|=
literal|0x8007
block|,
comment|// 10  000  0000  0000  111
name|DBGWCR1_EL1
init|=
literal|0x800f
block|,
comment|// 10  000  0000  0001  111
name|DBGWCR2_EL1
init|=
literal|0x8017
block|,
comment|// 10  000  0000  0010  111
name|DBGWCR3_EL1
init|=
literal|0x801f
block|,
comment|// 10  000  0000  0011  111
name|DBGWCR4_EL1
init|=
literal|0x8027
block|,
comment|// 10  000  0000  0100  111
name|DBGWCR5_EL1
init|=
literal|0x802f
block|,
comment|// 10  000  0000  0101  111
name|DBGWCR6_EL1
init|=
literal|0x8037
block|,
comment|// 10  000  0000  0110  111
name|DBGWCR7_EL1
init|=
literal|0x803f
block|,
comment|// 10  000  0000  0111  111
name|DBGWCR8_EL1
init|=
literal|0x8047
block|,
comment|// 10  000  0000  1000  111
name|DBGWCR9_EL1
init|=
literal|0x804f
block|,
comment|// 10  000  0000  1001  111
name|DBGWCR10_EL1
init|=
literal|0x8057
block|,
comment|// 10  000  0000  1010  111
name|DBGWCR11_EL1
init|=
literal|0x805f
block|,
comment|// 10  000  0000  1011  111
name|DBGWCR12_EL1
init|=
literal|0x8067
block|,
comment|// 10  000  0000  1100  111
name|DBGWCR13_EL1
init|=
literal|0x806f
block|,
comment|// 10  000  0000  1101  111
name|DBGWCR14_EL1
init|=
literal|0x8077
block|,
comment|// 10  000  0000  1110  111
name|DBGWCR15_EL1
init|=
literal|0x807f
block|,
comment|// 10  000  0000  1111  111
name|TEEHBR32_EL1
init|=
literal|0x9080
block|,
comment|// 10  010  0001  0000  000
name|OSDLR_EL1
init|=
literal|0x809c
block|,
comment|// 10  000  0001  0011  100
name|DBGPRCR_EL1
init|=
literal|0x80a4
block|,
comment|// 10  000  0001  0100  100
name|DBGCLAIMSET_EL1
init|=
literal|0x83c6
block|,
comment|// 10  000  0111  1000  110
name|DBGCLAIMCLR_EL1
init|=
literal|0x83ce
block|,
comment|// 10  000  0111  1001  110
name|CSSELR_EL1
init|=
literal|0xd000
block|,
comment|// 11  010  0000  0000  000
name|VPIDR_EL2
init|=
literal|0xe000
block|,
comment|// 11  100  0000  0000  000
name|VMPIDR_EL2
init|=
literal|0xe005
block|,
comment|// 11  100  0000  0000  101
name|CPACR_EL1
init|=
literal|0xc082
block|,
comment|// 11  000  0001  0000  010
name|SCTLR_EL1
init|=
literal|0xc080
block|,
comment|// 11  000  0001  0000  000
name|SCTLR_EL2
init|=
literal|0xe080
block|,
comment|// 11  100  0001  0000  000
name|SCTLR_EL3
init|=
literal|0xf080
block|,
comment|// 11  110  0001  0000  000
name|ACTLR_EL1
init|=
literal|0xc081
block|,
comment|// 11  000  0001  0000  001
name|ACTLR_EL2
init|=
literal|0xe081
block|,
comment|// 11  100  0001  0000  001
name|ACTLR_EL3
init|=
literal|0xf081
block|,
comment|// 11  110  0001  0000  001
name|HCR_EL2
init|=
literal|0xe088
block|,
comment|// 11  100  0001  0001  000
name|SCR_EL3
init|=
literal|0xf088
block|,
comment|// 11  110  0001  0001  000
name|MDCR_EL2
init|=
literal|0xe089
block|,
comment|// 11  100  0001  0001  001
name|SDER32_EL3
init|=
literal|0xf089
block|,
comment|// 11  110  0001  0001  001
name|CPTR_EL2
init|=
literal|0xe08a
block|,
comment|// 11  100  0001  0001  010
name|CPTR_EL3
init|=
literal|0xf08a
block|,
comment|// 11  110  0001  0001  010
name|HSTR_EL2
init|=
literal|0xe08b
block|,
comment|// 11  100  0001  0001  011
name|HACR_EL2
init|=
literal|0xe08f
block|,
comment|// 11  100  0001  0001  111
name|MDCR_EL3
init|=
literal|0xf099
block|,
comment|// 11  110  0001  0011  001
name|TTBR0_EL1
init|=
literal|0xc100
block|,
comment|// 11  000  0010  0000  000
name|TTBR0_EL2
init|=
literal|0xe100
block|,
comment|// 11  100  0010  0000  000
name|TTBR0_EL3
init|=
literal|0xf100
block|,
comment|// 11  110  0010  0000  000
name|TTBR1_EL1
init|=
literal|0xc101
block|,
comment|// 11  000  0010  0000  001
name|TCR_EL1
init|=
literal|0xc102
block|,
comment|// 11  000  0010  0000  010
name|TCR_EL2
init|=
literal|0xe102
block|,
comment|// 11  100  0010  0000  010
name|TCR_EL3
init|=
literal|0xf102
block|,
comment|// 11  110  0010  0000  010
name|VTTBR_EL2
init|=
literal|0xe108
block|,
comment|// 11  100  0010  0001  000
name|VTCR_EL2
init|=
literal|0xe10a
block|,
comment|// 11  100  0010  0001  010
name|DACR32_EL2
init|=
literal|0xe180
block|,
comment|// 11  100  0011  0000  000
name|SPSR_EL1
init|=
literal|0xc200
block|,
comment|// 11  000  0100  0000  000
name|SPSR_EL2
init|=
literal|0xe200
block|,
comment|// 11  100  0100  0000  000
name|SPSR_EL3
init|=
literal|0xf200
block|,
comment|// 11  110  0100  0000  000
name|ELR_EL1
init|=
literal|0xc201
block|,
comment|// 11  000  0100  0000  001
name|ELR_EL2
init|=
literal|0xe201
block|,
comment|// 11  100  0100  0000  001
name|ELR_EL3
init|=
literal|0xf201
block|,
comment|// 11  110  0100  0000  001
name|SP_EL0
init|=
literal|0xc208
block|,
comment|// 11  000  0100  0001  000
name|SP_EL1
init|=
literal|0xe208
block|,
comment|// 11  100  0100  0001  000
name|SP_EL2
init|=
literal|0xf208
block|,
comment|// 11  110  0100  0001  000
name|SPSel
init|=
literal|0xc210
block|,
comment|// 11  000  0100  0010  000
name|NZCV
init|=
literal|0xda10
block|,
comment|// 11  011  0100  0010  000
name|DAIF
init|=
literal|0xda11
block|,
comment|// 11  011  0100  0010  001
name|CurrentEL
init|=
literal|0xc212
block|,
comment|// 11  000  0100  0010  010
name|SPSR_irq
init|=
literal|0xe218
block|,
comment|// 11  100  0100  0011  000
name|SPSR_abt
init|=
literal|0xe219
block|,
comment|// 11  100  0100  0011  001
name|SPSR_und
init|=
literal|0xe21a
block|,
comment|// 11  100  0100  0011  010
name|SPSR_fiq
init|=
literal|0xe21b
block|,
comment|// 11  100  0100  0011  011
name|FPCR
init|=
literal|0xda20
block|,
comment|// 11  011  0100  0100  000
name|FPSR
init|=
literal|0xda21
block|,
comment|// 11  011  0100  0100  001
name|DSPSR_EL0
init|=
literal|0xda28
block|,
comment|// 11  011  0100  0101  000
name|DLR_EL0
init|=
literal|0xda29
block|,
comment|// 11  011  0100  0101  001
name|IFSR32_EL2
init|=
literal|0xe281
block|,
comment|// 11  100  0101  0000  001
name|AFSR0_EL1
init|=
literal|0xc288
block|,
comment|// 11  000  0101  0001  000
name|AFSR0_EL2
init|=
literal|0xe288
block|,
comment|// 11  100  0101  0001  000
name|AFSR0_EL3
init|=
literal|0xf288
block|,
comment|// 11  110  0101  0001  000
name|AFSR1_EL1
init|=
literal|0xc289
block|,
comment|// 11  000  0101  0001  001
name|AFSR1_EL2
init|=
literal|0xe289
block|,
comment|// 11  100  0101  0001  001
name|AFSR1_EL3
init|=
literal|0xf289
block|,
comment|// 11  110  0101  0001  001
name|ESR_EL1
init|=
literal|0xc290
block|,
comment|// 11  000  0101  0010  000
name|ESR_EL2
init|=
literal|0xe290
block|,
comment|// 11  100  0101  0010  000
name|ESR_EL3
init|=
literal|0xf290
block|,
comment|// 11  110  0101  0010  000
name|FPEXC32_EL2
init|=
literal|0xe298
block|,
comment|// 11  100  0101  0011  000
name|FAR_EL1
init|=
literal|0xc300
block|,
comment|// 11  000  0110  0000  000
name|FAR_EL2
init|=
literal|0xe300
block|,
comment|// 11  100  0110  0000  000
name|FAR_EL3
init|=
literal|0xf300
block|,
comment|// 11  110  0110  0000  000
name|HPFAR_EL2
init|=
literal|0xe304
block|,
comment|// 11  100  0110  0000  100
name|PAR_EL1
init|=
literal|0xc3a0
block|,
comment|// 11  000  0111  0100  000
name|PMCR_EL0
init|=
literal|0xdce0
block|,
comment|// 11  011  1001  1100  000
name|PMCNTENSET_EL0
init|=
literal|0xdce1
block|,
comment|// 11  011  1001  1100  001
name|PMCNTENCLR_EL0
init|=
literal|0xdce2
block|,
comment|// 11  011  1001  1100  010
name|PMOVSCLR_EL0
init|=
literal|0xdce3
block|,
comment|// 11  011  1001  1100  011
name|PMSELR_EL0
init|=
literal|0xdce5
block|,
comment|// 11  011  1001  1100  101
name|PMCCNTR_EL0
init|=
literal|0xdce8
block|,
comment|// 11  011  1001  1101  000
name|PMXEVTYPER_EL0
init|=
literal|0xdce9
block|,
comment|// 11  011  1001  1101  001
name|PMXEVCNTR_EL0
init|=
literal|0xdcea
block|,
comment|// 11  011  1001  1101  010
name|PMUSERENR_EL0
init|=
literal|0xdcf0
block|,
comment|// 11  011  1001  1110  000
name|PMINTENSET_EL1
init|=
literal|0xc4f1
block|,
comment|// 11  000  1001  1110  001
name|PMINTENCLR_EL1
init|=
literal|0xc4f2
block|,
comment|// 11  000  1001  1110  010
name|PMOVSSET_EL0
init|=
literal|0xdcf3
block|,
comment|// 11  011  1001  1110  011
name|MAIR_EL1
init|=
literal|0xc510
block|,
comment|// 11  000  1010  0010  000
name|MAIR_EL2
init|=
literal|0xe510
block|,
comment|// 11  100  1010  0010  000
name|MAIR_EL3
init|=
literal|0xf510
block|,
comment|// 11  110  1010  0010  000
name|AMAIR_EL1
init|=
literal|0xc518
block|,
comment|// 11  000  1010  0011  000
name|AMAIR_EL2
init|=
literal|0xe518
block|,
comment|// 11  100  1010  0011  000
name|AMAIR_EL3
init|=
literal|0xf518
block|,
comment|// 11  110  1010  0011  000
name|VBAR_EL1
init|=
literal|0xc600
block|,
comment|// 11  000  1100  0000  000
name|VBAR_EL2
init|=
literal|0xe600
block|,
comment|// 11  100  1100  0000  000
name|VBAR_EL3
init|=
literal|0xf600
block|,
comment|// 11  110  1100  0000  000
name|RMR_EL1
init|=
literal|0xc602
block|,
comment|// 11  000  1100  0000  010
name|RMR_EL2
init|=
literal|0xe602
block|,
comment|// 11  100  1100  0000  010
name|RMR_EL3
init|=
literal|0xf602
block|,
comment|// 11  110  1100  0000  010
name|CONTEXTIDR_EL1
init|=
literal|0xc681
block|,
comment|// 11  000  1101  0000  001
name|TPIDR_EL0
init|=
literal|0xde82
block|,
comment|// 11  011  1101  0000  010
name|TPIDR_EL2
init|=
literal|0xe682
block|,
comment|// 11  100  1101  0000  010
name|TPIDR_EL3
init|=
literal|0xf682
block|,
comment|// 11  110  1101  0000  010
name|TPIDRRO_EL0
init|=
literal|0xde83
block|,
comment|// 11  011  1101  0000  011
name|TPIDR_EL1
init|=
literal|0xc684
block|,
comment|// 11  000  1101  0000  100
name|CNTFRQ_EL0
init|=
literal|0xdf00
block|,
comment|// 11  011  1110  0000  000
name|CNTVOFF_EL2
init|=
literal|0xe703
block|,
comment|// 11  100  1110  0000  011
name|CNTKCTL_EL1
init|=
literal|0xc708
block|,
comment|// 11  000  1110  0001  000
name|CNTHCTL_EL2
init|=
literal|0xe708
block|,
comment|// 11  100  1110  0001  000
name|CNTP_TVAL_EL0
init|=
literal|0xdf10
block|,
comment|// 11  011  1110  0010  000
name|CNTHP_TVAL_EL2
init|=
literal|0xe710
block|,
comment|// 11  100  1110  0010  000
name|CNTPS_TVAL_EL1
init|=
literal|0xff10
block|,
comment|// 11  111  1110  0010  000
name|CNTP_CTL_EL0
init|=
literal|0xdf11
block|,
comment|// 11  011  1110  0010  001
name|CNTHP_CTL_EL2
init|=
literal|0xe711
block|,
comment|// 11  100  1110  0010  001
name|CNTPS_CTL_EL1
init|=
literal|0xff11
block|,
comment|// 11  111  1110  0010  001
name|CNTP_CVAL_EL0
init|=
literal|0xdf12
block|,
comment|// 11  011  1110  0010  010
name|CNTHP_CVAL_EL2
init|=
literal|0xe712
block|,
comment|// 11  100  1110  0010  010
name|CNTPS_CVAL_EL1
init|=
literal|0xff12
block|,
comment|// 11  111  1110  0010  010
name|CNTV_TVAL_EL0
init|=
literal|0xdf18
block|,
comment|// 11  011  1110  0011  000
name|CNTV_CTL_EL0
init|=
literal|0xdf19
block|,
comment|// 11  011  1110  0011  001
name|CNTV_CVAL_EL0
init|=
literal|0xdf1a
block|,
comment|// 11  011  1110  0011  010
name|PMEVCNTR0_EL0
init|=
literal|0xdf40
block|,
comment|// 11  011  1110  1000  000
name|PMEVCNTR1_EL0
init|=
literal|0xdf41
block|,
comment|// 11  011  1110  1000  001
name|PMEVCNTR2_EL0
init|=
literal|0xdf42
block|,
comment|// 11  011  1110  1000  010
name|PMEVCNTR3_EL0
init|=
literal|0xdf43
block|,
comment|// 11  011  1110  1000  011
name|PMEVCNTR4_EL0
init|=
literal|0xdf44
block|,
comment|// 11  011  1110  1000  100
name|PMEVCNTR5_EL0
init|=
literal|0xdf45
block|,
comment|// 11  011  1110  1000  101
name|PMEVCNTR6_EL0
init|=
literal|0xdf46
block|,
comment|// 11  011  1110  1000  110
name|PMEVCNTR7_EL0
init|=
literal|0xdf47
block|,
comment|// 11  011  1110  1000  111
name|PMEVCNTR8_EL0
init|=
literal|0xdf48
block|,
comment|// 11  011  1110  1001  000
name|PMEVCNTR9_EL0
init|=
literal|0xdf49
block|,
comment|// 11  011  1110  1001  001
name|PMEVCNTR10_EL0
init|=
literal|0xdf4a
block|,
comment|// 11  011  1110  1001  010
name|PMEVCNTR11_EL0
init|=
literal|0xdf4b
block|,
comment|// 11  011  1110  1001  011
name|PMEVCNTR12_EL0
init|=
literal|0xdf4c
block|,
comment|// 11  011  1110  1001  100
name|PMEVCNTR13_EL0
init|=
literal|0xdf4d
block|,
comment|// 11  011  1110  1001  101
name|PMEVCNTR14_EL0
init|=
literal|0xdf4e
block|,
comment|// 11  011  1110  1001  110
name|PMEVCNTR15_EL0
init|=
literal|0xdf4f
block|,
comment|// 11  011  1110  1001  111
name|PMEVCNTR16_EL0
init|=
literal|0xdf50
block|,
comment|// 11  011  1110  1010  000
name|PMEVCNTR17_EL0
init|=
literal|0xdf51
block|,
comment|// 11  011  1110  1010  001
name|PMEVCNTR18_EL0
init|=
literal|0xdf52
block|,
comment|// 11  011  1110  1010  010
name|PMEVCNTR19_EL0
init|=
literal|0xdf53
block|,
comment|// 11  011  1110  1010  011
name|PMEVCNTR20_EL0
init|=
literal|0xdf54
block|,
comment|// 11  011  1110  1010  100
name|PMEVCNTR21_EL0
init|=
literal|0xdf55
block|,
comment|// 11  011  1110  1010  101
name|PMEVCNTR22_EL0
init|=
literal|0xdf56
block|,
comment|// 11  011  1110  1010  110
name|PMEVCNTR23_EL0
init|=
literal|0xdf57
block|,
comment|// 11  011  1110  1010  111
name|PMEVCNTR24_EL0
init|=
literal|0xdf58
block|,
comment|// 11  011  1110  1011  000
name|PMEVCNTR25_EL0
init|=
literal|0xdf59
block|,
comment|// 11  011  1110  1011  001
name|PMEVCNTR26_EL0
init|=
literal|0xdf5a
block|,
comment|// 11  011  1110  1011  010
name|PMEVCNTR27_EL0
init|=
literal|0xdf5b
block|,
comment|// 11  011  1110  1011  011
name|PMEVCNTR28_EL0
init|=
literal|0xdf5c
block|,
comment|// 11  011  1110  1011  100
name|PMEVCNTR29_EL0
init|=
literal|0xdf5d
block|,
comment|// 11  011  1110  1011  101
name|PMEVCNTR30_EL0
init|=
literal|0xdf5e
block|,
comment|// 11  011  1110  1011  110
name|PMCCFILTR_EL0
init|=
literal|0xdf7f
block|,
comment|// 11  011  1110  1111  111
name|PMEVTYPER0_EL0
init|=
literal|0xdf60
block|,
comment|// 11  011  1110  1100  000
name|PMEVTYPER1_EL0
init|=
literal|0xdf61
block|,
comment|// 11  011  1110  1100  001
name|PMEVTYPER2_EL0
init|=
literal|0xdf62
block|,
comment|// 11  011  1110  1100  010
name|PMEVTYPER3_EL0
init|=
literal|0xdf63
block|,
comment|// 11  011  1110  1100  011
name|PMEVTYPER4_EL0
init|=
literal|0xdf64
block|,
comment|// 11  011  1110  1100  100
name|PMEVTYPER5_EL0
init|=
literal|0xdf65
block|,
comment|// 11  011  1110  1100  101
name|PMEVTYPER6_EL0
init|=
literal|0xdf66
block|,
comment|// 11  011  1110  1100  110
name|PMEVTYPER7_EL0
init|=
literal|0xdf67
block|,
comment|// 11  011  1110  1100  111
name|PMEVTYPER8_EL0
init|=
literal|0xdf68
block|,
comment|// 11  011  1110  1101  000
name|PMEVTYPER9_EL0
init|=
literal|0xdf69
block|,
comment|// 11  011  1110  1101  001
name|PMEVTYPER10_EL0
init|=
literal|0xdf6a
block|,
comment|// 11  011  1110  1101  010
name|PMEVTYPER11_EL0
init|=
literal|0xdf6b
block|,
comment|// 11  011  1110  1101  011
name|PMEVTYPER12_EL0
init|=
literal|0xdf6c
block|,
comment|// 11  011  1110  1101  100
name|PMEVTYPER13_EL0
init|=
literal|0xdf6d
block|,
comment|// 11  011  1110  1101  101
name|PMEVTYPER14_EL0
init|=
literal|0xdf6e
block|,
comment|// 11  011  1110  1101  110
name|PMEVTYPER15_EL0
init|=
literal|0xdf6f
block|,
comment|// 11  011  1110  1101  111
name|PMEVTYPER16_EL0
init|=
literal|0xdf70
block|,
comment|// 11  011  1110  1110  000
name|PMEVTYPER17_EL0
init|=
literal|0xdf71
block|,
comment|// 11  011  1110  1110  001
name|PMEVTYPER18_EL0
init|=
literal|0xdf72
block|,
comment|// 11  011  1110  1110  010
name|PMEVTYPER19_EL0
init|=
literal|0xdf73
block|,
comment|// 11  011  1110  1110  011
name|PMEVTYPER20_EL0
init|=
literal|0xdf74
block|,
comment|// 11  011  1110  1110  100
name|PMEVTYPER21_EL0
init|=
literal|0xdf75
block|,
comment|// 11  011  1110  1110  101
name|PMEVTYPER22_EL0
init|=
literal|0xdf76
block|,
comment|// 11  011  1110  1110  110
name|PMEVTYPER23_EL0
init|=
literal|0xdf77
block|,
comment|// 11  011  1110  1110  111
name|PMEVTYPER24_EL0
init|=
literal|0xdf78
block|,
comment|// 11  011  1110  1111  000
name|PMEVTYPER25_EL0
init|=
literal|0xdf79
block|,
comment|// 11  011  1110  1111  001
name|PMEVTYPER26_EL0
init|=
literal|0xdf7a
block|,
comment|// 11  011  1110  1111  010
name|PMEVTYPER27_EL0
init|=
literal|0xdf7b
block|,
comment|// 11  011  1110  1111  011
name|PMEVTYPER28_EL0
init|=
literal|0xdf7c
block|,
comment|// 11  011  1110  1111  100
name|PMEVTYPER29_EL0
init|=
literal|0xdf7d
block|,
comment|// 11  011  1110  1111  101
name|PMEVTYPER30_EL0
init|=
literal|0xdf7e
block|,
comment|// 11  011  1110  1111  110
comment|// Trace registers
name|TRCPRGCTLR
init|=
literal|0x8808
block|,
comment|// 10  001  0000  0001  000
name|TRCPROCSELR
init|=
literal|0x8810
block|,
comment|// 10  001  0000  0010  000
name|TRCCONFIGR
init|=
literal|0x8820
block|,
comment|// 10  001  0000  0100  000
name|TRCAUXCTLR
init|=
literal|0x8830
block|,
comment|// 10  001  0000  0110  000
name|TRCEVENTCTL0R
init|=
literal|0x8840
block|,
comment|// 10  001  0000  1000  000
name|TRCEVENTCTL1R
init|=
literal|0x8848
block|,
comment|// 10  001  0000  1001  000
name|TRCSTALLCTLR
init|=
literal|0x8858
block|,
comment|// 10  001  0000  1011  000
name|TRCTSCTLR
init|=
literal|0x8860
block|,
comment|// 10  001  0000  1100  000
name|TRCSYNCPR
init|=
literal|0x8868
block|,
comment|// 10  001  0000  1101  000
name|TRCCCCTLR
init|=
literal|0x8870
block|,
comment|// 10  001  0000  1110  000
name|TRCBBCTLR
init|=
literal|0x8878
block|,
comment|// 10  001  0000  1111  000
name|TRCTRACEIDR
init|=
literal|0x8801
block|,
comment|// 10  001  0000  0000  001
name|TRCQCTLR
init|=
literal|0x8809
block|,
comment|// 10  001  0000  0001  001
name|TRCVICTLR
init|=
literal|0x8802
block|,
comment|// 10  001  0000  0000  010
name|TRCVIIECTLR
init|=
literal|0x880a
block|,
comment|// 10  001  0000  0001  010
name|TRCVISSCTLR
init|=
literal|0x8812
block|,
comment|// 10  001  0000  0010  010
name|TRCVIPCSSCTLR
init|=
literal|0x881a
block|,
comment|// 10  001  0000  0011  010
name|TRCVDCTLR
init|=
literal|0x8842
block|,
comment|// 10  001  0000  1000  010
name|TRCVDSACCTLR
init|=
literal|0x884a
block|,
comment|// 10  001  0000  1001  010
name|TRCVDARCCTLR
init|=
literal|0x8852
block|,
comment|// 10  001  0000  1010  010
name|TRCSEQEVR0
init|=
literal|0x8804
block|,
comment|// 10  001  0000  0000  100
name|TRCSEQEVR1
init|=
literal|0x880c
block|,
comment|// 10  001  0000  0001  100
name|TRCSEQEVR2
init|=
literal|0x8814
block|,
comment|// 10  001  0000  0010  100
name|TRCSEQRSTEVR
init|=
literal|0x8834
block|,
comment|// 10  001  0000  0110  100
name|TRCSEQSTR
init|=
literal|0x883c
block|,
comment|// 10  001  0000  0111  100
name|TRCEXTINSELR
init|=
literal|0x8844
block|,
comment|// 10  001  0000  1000  100
name|TRCCNTRLDVR0
init|=
literal|0x8805
block|,
comment|// 10  001  0000  0000  101
name|TRCCNTRLDVR1
init|=
literal|0x880d
block|,
comment|// 10  001  0000  0001  101
name|TRCCNTRLDVR2
init|=
literal|0x8815
block|,
comment|// 10  001  0000  0010  101
name|TRCCNTRLDVR3
init|=
literal|0x881d
block|,
comment|// 10  001  0000  0011  101
name|TRCCNTCTLR0
init|=
literal|0x8825
block|,
comment|// 10  001  0000  0100  101
name|TRCCNTCTLR1
init|=
literal|0x882d
block|,
comment|// 10  001  0000  0101  101
name|TRCCNTCTLR2
init|=
literal|0x8835
block|,
comment|// 10  001  0000  0110  101
name|TRCCNTCTLR3
init|=
literal|0x883d
block|,
comment|// 10  001  0000  0111  101
name|TRCCNTVR0
init|=
literal|0x8845
block|,
comment|// 10  001  0000  1000  101
name|TRCCNTVR1
init|=
literal|0x884d
block|,
comment|// 10  001  0000  1001  101
name|TRCCNTVR2
init|=
literal|0x8855
block|,
comment|// 10  001  0000  1010  101
name|TRCCNTVR3
init|=
literal|0x885d
block|,
comment|// 10  001  0000  1011  101
name|TRCIMSPEC0
init|=
literal|0x8807
block|,
comment|// 10  001  0000  0000  111
name|TRCIMSPEC1
init|=
literal|0x880f
block|,
comment|// 10  001  0000  0001  111
name|TRCIMSPEC2
init|=
literal|0x8817
block|,
comment|// 10  001  0000  0010  111
name|TRCIMSPEC3
init|=
literal|0x881f
block|,
comment|// 10  001  0000  0011  111
name|TRCIMSPEC4
init|=
literal|0x8827
block|,
comment|// 10  001  0000  0100  111
name|TRCIMSPEC5
init|=
literal|0x882f
block|,
comment|// 10  001  0000  0101  111
name|TRCIMSPEC6
init|=
literal|0x8837
block|,
comment|// 10  001  0000  0110  111
name|TRCIMSPEC7
init|=
literal|0x883f
block|,
comment|// 10  001  0000  0111  111
name|TRCRSCTLR2
init|=
literal|0x8890
block|,
comment|// 10  001  0001  0010  000
name|TRCRSCTLR3
init|=
literal|0x8898
block|,
comment|// 10  001  0001  0011  000
name|TRCRSCTLR4
init|=
literal|0x88a0
block|,
comment|// 10  001  0001  0100  000
name|TRCRSCTLR5
init|=
literal|0x88a8
block|,
comment|// 10  001  0001  0101  000
name|TRCRSCTLR6
init|=
literal|0x88b0
block|,
comment|// 10  001  0001  0110  000
name|TRCRSCTLR7
init|=
literal|0x88b8
block|,
comment|// 10  001  0001  0111  000
name|TRCRSCTLR8
init|=
literal|0x88c0
block|,
comment|// 10  001  0001  1000  000
name|TRCRSCTLR9
init|=
literal|0x88c8
block|,
comment|// 10  001  0001  1001  000
name|TRCRSCTLR10
init|=
literal|0x88d0
block|,
comment|// 10  001  0001  1010  000
name|TRCRSCTLR11
init|=
literal|0x88d8
block|,
comment|// 10  001  0001  1011  000
name|TRCRSCTLR12
init|=
literal|0x88e0
block|,
comment|// 10  001  0001  1100  000
name|TRCRSCTLR13
init|=
literal|0x88e8
block|,
comment|// 10  001  0001  1101  000
name|TRCRSCTLR14
init|=
literal|0x88f0
block|,
comment|// 10  001  0001  1110  000
name|TRCRSCTLR15
init|=
literal|0x88f8
block|,
comment|// 10  001  0001  1111  000
name|TRCRSCTLR16
init|=
literal|0x8881
block|,
comment|// 10  001  0001  0000  001
name|TRCRSCTLR17
init|=
literal|0x8889
block|,
comment|// 10  001  0001  0001  001
name|TRCRSCTLR18
init|=
literal|0x8891
block|,
comment|// 10  001  0001  0010  001
name|TRCRSCTLR19
init|=
literal|0x8899
block|,
comment|// 10  001  0001  0011  001
name|TRCRSCTLR20
init|=
literal|0x88a1
block|,
comment|// 10  001  0001  0100  001
name|TRCRSCTLR21
init|=
literal|0x88a9
block|,
comment|// 10  001  0001  0101  001
name|TRCRSCTLR22
init|=
literal|0x88b1
block|,
comment|// 10  001  0001  0110  001
name|TRCRSCTLR23
init|=
literal|0x88b9
block|,
comment|// 10  001  0001  0111  001
name|TRCRSCTLR24
init|=
literal|0x88c1
block|,
comment|// 10  001  0001  1000  001
name|TRCRSCTLR25
init|=
literal|0x88c9
block|,
comment|// 10  001  0001  1001  001
name|TRCRSCTLR26
init|=
literal|0x88d1
block|,
comment|// 10  001  0001  1010  001
name|TRCRSCTLR27
init|=
literal|0x88d9
block|,
comment|// 10  001  0001  1011  001
name|TRCRSCTLR28
init|=
literal|0x88e1
block|,
comment|// 10  001  0001  1100  001
name|TRCRSCTLR29
init|=
literal|0x88e9
block|,
comment|// 10  001  0001  1101  001
name|TRCRSCTLR30
init|=
literal|0x88f1
block|,
comment|// 10  001  0001  1110  001
name|TRCRSCTLR31
init|=
literal|0x88f9
block|,
comment|// 10  001  0001  1111  001
name|TRCSSCCR0
init|=
literal|0x8882
block|,
comment|// 10  001  0001  0000  010
name|TRCSSCCR1
init|=
literal|0x888a
block|,
comment|// 10  001  0001  0001  010
name|TRCSSCCR2
init|=
literal|0x8892
block|,
comment|// 10  001  0001  0010  010
name|TRCSSCCR3
init|=
literal|0x889a
block|,
comment|// 10  001  0001  0011  010
name|TRCSSCCR4
init|=
literal|0x88a2
block|,
comment|// 10  001  0001  0100  010
name|TRCSSCCR5
init|=
literal|0x88aa
block|,
comment|// 10  001  0001  0101  010
name|TRCSSCCR6
init|=
literal|0x88b2
block|,
comment|// 10  001  0001  0110  010
name|TRCSSCCR7
init|=
literal|0x88ba
block|,
comment|// 10  001  0001  0111  010
name|TRCSSCSR0
init|=
literal|0x88c2
block|,
comment|// 10  001  0001  1000  010
name|TRCSSCSR1
init|=
literal|0x88ca
block|,
comment|// 10  001  0001  1001  010
name|TRCSSCSR2
init|=
literal|0x88d2
block|,
comment|// 10  001  0001  1010  010
name|TRCSSCSR3
init|=
literal|0x88da
block|,
comment|// 10  001  0001  1011  010
name|TRCSSCSR4
init|=
literal|0x88e2
block|,
comment|// 10  001  0001  1100  010
name|TRCSSCSR5
init|=
literal|0x88ea
block|,
comment|// 10  001  0001  1101  010
name|TRCSSCSR6
init|=
literal|0x88f2
block|,
comment|// 10  001  0001  1110  010
name|TRCSSCSR7
init|=
literal|0x88fa
block|,
comment|// 10  001  0001  1111  010
name|TRCSSPCICR0
init|=
literal|0x8883
block|,
comment|// 10  001  0001  0000  011
name|TRCSSPCICR1
init|=
literal|0x888b
block|,
comment|// 10  001  0001  0001  011
name|TRCSSPCICR2
init|=
literal|0x8893
block|,
comment|// 10  001  0001  0010  011
name|TRCSSPCICR3
init|=
literal|0x889b
block|,
comment|// 10  001  0001  0011  011
name|TRCSSPCICR4
init|=
literal|0x88a3
block|,
comment|// 10  001  0001  0100  011
name|TRCSSPCICR5
init|=
literal|0x88ab
block|,
comment|// 10  001  0001  0101  011
name|TRCSSPCICR6
init|=
literal|0x88b3
block|,
comment|// 10  001  0001  0110  011
name|TRCSSPCICR7
init|=
literal|0x88bb
block|,
comment|// 10  001  0001  0111  011
name|TRCPDCR
init|=
literal|0x88a4
block|,
comment|// 10  001  0001  0100  100
name|TRCACVR0
init|=
literal|0x8900
block|,
comment|// 10  001  0010  0000  000
name|TRCACVR1
init|=
literal|0x8910
block|,
comment|// 10  001  0010  0010  000
name|TRCACVR2
init|=
literal|0x8920
block|,
comment|// 10  001  0010  0100  000
name|TRCACVR3
init|=
literal|0x8930
block|,
comment|// 10  001  0010  0110  000
name|TRCACVR4
init|=
literal|0x8940
block|,
comment|// 10  001  0010  1000  000
name|TRCACVR5
init|=
literal|0x8950
block|,
comment|// 10  001  0010  1010  000
name|TRCACVR6
init|=
literal|0x8960
block|,
comment|// 10  001  0010  1100  000
name|TRCACVR7
init|=
literal|0x8970
block|,
comment|// 10  001  0010  1110  000
name|TRCACVR8
init|=
literal|0x8901
block|,
comment|// 10  001  0010  0000  001
name|TRCACVR9
init|=
literal|0x8911
block|,
comment|// 10  001  0010  0010  001
name|TRCACVR10
init|=
literal|0x8921
block|,
comment|// 10  001  0010  0100  001
name|TRCACVR11
init|=
literal|0x8931
block|,
comment|// 10  001  0010  0110  001
name|TRCACVR12
init|=
literal|0x8941
block|,
comment|// 10  001  0010  1000  001
name|TRCACVR13
init|=
literal|0x8951
block|,
comment|// 10  001  0010  1010  001
name|TRCACVR14
init|=
literal|0x8961
block|,
comment|// 10  001  0010  1100  001
name|TRCACVR15
init|=
literal|0x8971
block|,
comment|// 10  001  0010  1110  001
name|TRCACATR0
init|=
literal|0x8902
block|,
comment|// 10  001  0010  0000  010
name|TRCACATR1
init|=
literal|0x8912
block|,
comment|// 10  001  0010  0010  010
name|TRCACATR2
init|=
literal|0x8922
block|,
comment|// 10  001  0010  0100  010
name|TRCACATR3
init|=
literal|0x8932
block|,
comment|// 10  001  0010  0110  010
name|TRCACATR4
init|=
literal|0x8942
block|,
comment|// 10  001  0010  1000  010
name|TRCACATR5
init|=
literal|0x8952
block|,
comment|// 10  001  0010  1010  010
name|TRCACATR6
init|=
literal|0x8962
block|,
comment|// 10  001  0010  1100  010
name|TRCACATR7
init|=
literal|0x8972
block|,
comment|// 10  001  0010  1110  010
name|TRCACATR8
init|=
literal|0x8903
block|,
comment|// 10  001  0010  0000  011
name|TRCACATR9
init|=
literal|0x8913
block|,
comment|// 10  001  0010  0010  011
name|TRCACATR10
init|=
literal|0x8923
block|,
comment|// 10  001  0010  0100  011
name|TRCACATR11
init|=
literal|0x8933
block|,
comment|// 10  001  0010  0110  011
name|TRCACATR12
init|=
literal|0x8943
block|,
comment|// 10  001  0010  1000  011
name|TRCACATR13
init|=
literal|0x8953
block|,
comment|// 10  001  0010  1010  011
name|TRCACATR14
init|=
literal|0x8963
block|,
comment|// 10  001  0010  1100  011
name|TRCACATR15
init|=
literal|0x8973
block|,
comment|// 10  001  0010  1110  011
name|TRCDVCVR0
init|=
literal|0x8904
block|,
comment|// 10  001  0010  0000  100
name|TRCDVCVR1
init|=
literal|0x8924
block|,
comment|// 10  001  0010  0100  100
name|TRCDVCVR2
init|=
literal|0x8944
block|,
comment|// 10  001  0010  1000  100
name|TRCDVCVR3
init|=
literal|0x8964
block|,
comment|// 10  001  0010  1100  100
name|TRCDVCVR4
init|=
literal|0x8905
block|,
comment|// 10  001  0010  0000  101
name|TRCDVCVR5
init|=
literal|0x8925
block|,
comment|// 10  001  0010  0100  101
name|TRCDVCVR6
init|=
literal|0x8945
block|,
comment|// 10  001  0010  1000  101
name|TRCDVCVR7
init|=
literal|0x8965
block|,
comment|// 10  001  0010  1100  101
name|TRCDVCMR0
init|=
literal|0x8906
block|,
comment|// 10  001  0010  0000  110
name|TRCDVCMR1
init|=
literal|0x8926
block|,
comment|// 10  001  0010  0100  110
name|TRCDVCMR2
init|=
literal|0x8946
block|,
comment|// 10  001  0010  1000  110
name|TRCDVCMR3
init|=
literal|0x8966
block|,
comment|// 10  001  0010  1100  110
name|TRCDVCMR4
init|=
literal|0x8907
block|,
comment|// 10  001  0010  0000  111
name|TRCDVCMR5
init|=
literal|0x8927
block|,
comment|// 10  001  0010  0100  111
name|TRCDVCMR6
init|=
literal|0x8947
block|,
comment|// 10  001  0010  1000  111
name|TRCDVCMR7
init|=
literal|0x8967
block|,
comment|// 10  001  0010  1100  111
name|TRCCIDCVR0
init|=
literal|0x8980
block|,
comment|// 10  001  0011  0000  000
name|TRCCIDCVR1
init|=
literal|0x8990
block|,
comment|// 10  001  0011  0010  000
name|TRCCIDCVR2
init|=
literal|0x89a0
block|,
comment|// 10  001  0011  0100  000
name|TRCCIDCVR3
init|=
literal|0x89b0
block|,
comment|// 10  001  0011  0110  000
name|TRCCIDCVR4
init|=
literal|0x89c0
block|,
comment|// 10  001  0011  1000  000
name|TRCCIDCVR5
init|=
literal|0x89d0
block|,
comment|// 10  001  0011  1010  000
name|TRCCIDCVR6
init|=
literal|0x89e0
block|,
comment|// 10  001  0011  1100  000
name|TRCCIDCVR7
init|=
literal|0x89f0
block|,
comment|// 10  001  0011  1110  000
name|TRCVMIDCVR0
init|=
literal|0x8981
block|,
comment|// 10  001  0011  0000  001
name|TRCVMIDCVR1
init|=
literal|0x8991
block|,
comment|// 10  001  0011  0010  001
name|TRCVMIDCVR2
init|=
literal|0x89a1
block|,
comment|// 10  001  0011  0100  001
name|TRCVMIDCVR3
init|=
literal|0x89b1
block|,
comment|// 10  001  0011  0110  001
name|TRCVMIDCVR4
init|=
literal|0x89c1
block|,
comment|// 10  001  0011  1000  001
name|TRCVMIDCVR5
init|=
literal|0x89d1
block|,
comment|// 10  001  0011  1010  001
name|TRCVMIDCVR6
init|=
literal|0x89e1
block|,
comment|// 10  001  0011  1100  001
name|TRCVMIDCVR7
init|=
literal|0x89f1
block|,
comment|// 10  001  0011  1110  001
name|TRCCIDCCTLR0
init|=
literal|0x8982
block|,
comment|// 10  001  0011  0000  010
name|TRCCIDCCTLR1
init|=
literal|0x898a
block|,
comment|// 10  001  0011  0001  010
name|TRCVMIDCCTLR0
init|=
literal|0x8992
block|,
comment|// 10  001  0011  0010  010
name|TRCVMIDCCTLR1
init|=
literal|0x899a
block|,
comment|// 10  001  0011  0011  010
name|TRCITCTRL
init|=
literal|0x8b84
block|,
comment|// 10  001  0111  0000  100
name|TRCCLAIMSET
init|=
literal|0x8bc6
block|,
comment|// 10  001  0111  1000  110
name|TRCCLAIMCLR
init|=
literal|0x8bce
block|,
comment|// 10  001  0111  1001  110
comment|// GICv3 registers
name|ICC_BPR1_EL1
init|=
literal|0xc663
block|,
comment|// 11  000  1100  1100  011
name|ICC_BPR0_EL1
init|=
literal|0xc643
block|,
comment|// 11  000  1100  1000  011
name|ICC_PMR_EL1
init|=
literal|0xc230
block|,
comment|// 11  000  0100  0110  000
name|ICC_CTLR_EL1
init|=
literal|0xc664
block|,
comment|// 11  000  1100  1100  100
name|ICC_CTLR_EL3
init|=
literal|0xf664
block|,
comment|// 11  110  1100  1100  100
name|ICC_SRE_EL1
init|=
literal|0xc665
block|,
comment|// 11  000  1100  1100  101
name|ICC_SRE_EL2
init|=
literal|0xe64d
block|,
comment|// 11  100  1100  1001  101
name|ICC_SRE_EL3
init|=
literal|0xf665
block|,
comment|// 11  110  1100  1100  101
name|ICC_IGRPEN0_EL1
init|=
literal|0xc666
block|,
comment|// 11  000  1100  1100  110
name|ICC_IGRPEN1_EL1
init|=
literal|0xc667
block|,
comment|// 11  000  1100  1100  111
name|ICC_IGRPEN1_EL3
init|=
literal|0xf667
block|,
comment|// 11  110  1100  1100  111
name|ICC_SEIEN_EL1
init|=
literal|0xc668
block|,
comment|// 11  000  1100  1101  000
name|ICC_AP0R0_EL1
init|=
literal|0xc644
block|,
comment|// 11  000  1100  1000  100
name|ICC_AP0R1_EL1
init|=
literal|0xc645
block|,
comment|// 11  000  1100  1000  101
name|ICC_AP0R2_EL1
init|=
literal|0xc646
block|,
comment|// 11  000  1100  1000  110
name|ICC_AP0R3_EL1
init|=
literal|0xc647
block|,
comment|// 11  000  1100  1000  111
name|ICC_AP1R0_EL1
init|=
literal|0xc648
block|,
comment|// 11  000  1100  1001  000
name|ICC_AP1R1_EL1
init|=
literal|0xc649
block|,
comment|// 11  000  1100  1001  001
name|ICC_AP1R2_EL1
init|=
literal|0xc64a
block|,
comment|// 11  000  1100  1001  010
name|ICC_AP1R3_EL1
init|=
literal|0xc64b
block|,
comment|// 11  000  1100  1001  011
name|ICH_AP0R0_EL2
init|=
literal|0xe640
block|,
comment|// 11  100  1100  1000  000
name|ICH_AP0R1_EL2
init|=
literal|0xe641
block|,
comment|// 11  100  1100  1000  001
name|ICH_AP0R2_EL2
init|=
literal|0xe642
block|,
comment|// 11  100  1100  1000  010
name|ICH_AP0R3_EL2
init|=
literal|0xe643
block|,
comment|// 11  100  1100  1000  011
name|ICH_AP1R0_EL2
init|=
literal|0xe648
block|,
comment|// 11  100  1100  1001  000
name|ICH_AP1R1_EL2
init|=
literal|0xe649
block|,
comment|// 11  100  1100  1001  001
name|ICH_AP1R2_EL2
init|=
literal|0xe64a
block|,
comment|// 11  100  1100  1001  010
name|ICH_AP1R3_EL2
init|=
literal|0xe64b
block|,
comment|// 11  100  1100  1001  011
name|ICH_HCR_EL2
init|=
literal|0xe658
block|,
comment|// 11  100  1100  1011  000
name|ICH_MISR_EL2
init|=
literal|0xe65a
block|,
comment|// 11  100  1100  1011  010
name|ICH_VMCR_EL2
init|=
literal|0xe65f
block|,
comment|// 11  100  1100  1011  111
name|ICH_VSEIR_EL2
init|=
literal|0xe64c
block|,
comment|// 11  100  1100  1001  100
name|ICH_LR0_EL2
init|=
literal|0xe660
block|,
comment|// 11  100  1100  1100  000
name|ICH_LR1_EL2
init|=
literal|0xe661
block|,
comment|// 11  100  1100  1100  001
name|ICH_LR2_EL2
init|=
literal|0xe662
block|,
comment|// 11  100  1100  1100  010
name|ICH_LR3_EL2
init|=
literal|0xe663
block|,
comment|// 11  100  1100  1100  011
name|ICH_LR4_EL2
init|=
literal|0xe664
block|,
comment|// 11  100  1100  1100  100
name|ICH_LR5_EL2
init|=
literal|0xe665
block|,
comment|// 11  100  1100  1100  101
name|ICH_LR6_EL2
init|=
literal|0xe666
block|,
comment|// 11  100  1100  1100  110
name|ICH_LR7_EL2
init|=
literal|0xe667
block|,
comment|// 11  100  1100  1100  111
name|ICH_LR8_EL2
init|=
literal|0xe668
block|,
comment|// 11  100  1100  1101  000
name|ICH_LR9_EL2
init|=
literal|0xe669
block|,
comment|// 11  100  1100  1101  001
name|ICH_LR10_EL2
init|=
literal|0xe66a
block|,
comment|// 11  100  1100  1101  010
name|ICH_LR11_EL2
init|=
literal|0xe66b
block|,
comment|// 11  100  1100  1101  011
name|ICH_LR12_EL2
init|=
literal|0xe66c
block|,
comment|// 11  100  1100  1101  100
name|ICH_LR13_EL2
init|=
literal|0xe66d
block|,
comment|// 11  100  1100  1101  101
name|ICH_LR14_EL2
init|=
literal|0xe66e
block|,
comment|// 11  100  1100  1101  110
name|ICH_LR15_EL2
init|=
literal|0xe66f
comment|// 11  100  1100  1101  111
block|}
enum|;
comment|// Note that these do not inherit from NamedImmMapper. This class is
comment|// sufficiently different in its behaviour that I don't believe it's worth
comment|// burdening the common NamedImmMapper with abstractions only needed in
comment|// this one case.
struct|struct
name|SysRegMapper
block|{
specifier|static
specifier|const
name|NamedImmMapper
operator|::
name|Mapping
name|SysRegPairs
index|[]
expr_stmt|;
specifier|const
name|NamedImmMapper
operator|::
name|Mapping
operator|*
name|InstPairs
expr_stmt|;
name|size_t
name|NumInstPairs
decl_stmt|;
name|SysRegMapper
argument_list|()
block|{}
name|uint32_t
name|fromString
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
operator|&
name|Valid
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|string
name|toString
argument_list|(
argument|uint32_t Bits
argument_list|,
argument|bool&Valid
argument_list|)
specifier|const
expr_stmt|;
block|}
struct|;
name|struct
name|MSRMapper
range|:
name|SysRegMapper
block|{
specifier|static
specifier|const
name|NamedImmMapper
operator|::
name|Mapping
name|MSRPairs
index|[]
block|;
name|MSRMapper
argument_list|()
block|;   }
decl_stmt|;
name|struct
name|MRSMapper
range|:
name|SysRegMapper
block|{
specifier|static
specifier|const
name|NamedImmMapper
operator|::
name|Mapping
name|MRSPairs
index|[]
block|;
name|MRSMapper
argument_list|()
block|;   }
decl_stmt|;
name|uint32_t
name|ParseGenericRegister
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
modifier|&
name|Valid
parameter_list|)
function_decl|;
block|}
name|namespace
name|A64TLBI
block|{
enum|enum
name|TLBIValues
block|{
name|Invalid
init|=
operator|-
literal|1
block|,
comment|// Op0 Op1  CRn   CRm   Op2
name|IPAS2E1IS
init|=
literal|0x6401
block|,
comment|// 01  100  1000  0000  001
name|IPAS2LE1IS
init|=
literal|0x6405
block|,
comment|// 01  100  1000  0000  101
name|VMALLE1IS
init|=
literal|0x4418
block|,
comment|// 01  000  1000  0011  000
name|ALLE2IS
init|=
literal|0x6418
block|,
comment|// 01  100  1000  0011  000
name|ALLE3IS
init|=
literal|0x7418
block|,
comment|// 01  110  1000  0011  000
name|VAE1IS
init|=
literal|0x4419
block|,
comment|// 01  000  1000  0011  001
name|VAE2IS
init|=
literal|0x6419
block|,
comment|// 01  100  1000  0011  001
name|VAE3IS
init|=
literal|0x7419
block|,
comment|// 01  110  1000  0011  001
name|ASIDE1IS
init|=
literal|0x441a
block|,
comment|// 01  000  1000  0011  010
name|VAAE1IS
init|=
literal|0x441b
block|,
comment|// 01  000  1000  0011  011
name|ALLE1IS
init|=
literal|0x641c
block|,
comment|// 01  100  1000  0011  100
name|VALE1IS
init|=
literal|0x441d
block|,
comment|// 01  000  1000  0011  101
name|VALE2IS
init|=
literal|0x641d
block|,
comment|// 01  100  1000  0011  101
name|VALE3IS
init|=
literal|0x741d
block|,
comment|// 01  110  1000  0011  101
name|VMALLS12E1IS
init|=
literal|0x641e
block|,
comment|// 01  100  1000  0011  110
name|VAALE1IS
init|=
literal|0x441f
block|,
comment|// 01  000  1000  0011  111
name|IPAS2E1
init|=
literal|0x6421
block|,
comment|// 01  100  1000  0100  001
name|IPAS2LE1
init|=
literal|0x6425
block|,
comment|// 01  100  1000  0100  101
name|VMALLE1
init|=
literal|0x4438
block|,
comment|// 01  000  1000  0111  000
name|ALLE2
init|=
literal|0x6438
block|,
comment|// 01  100  1000  0111  000
name|ALLE3
init|=
literal|0x7438
block|,
comment|// 01  110  1000  0111  000
name|VAE1
init|=
literal|0x4439
block|,
comment|// 01  000  1000  0111  001
name|VAE2
init|=
literal|0x6439
block|,
comment|// 01  100  1000  0111  001
name|VAE3
init|=
literal|0x7439
block|,
comment|// 01  110  1000  0111  001
name|ASIDE1
init|=
literal|0x443a
block|,
comment|// 01  000  1000  0111  010
name|VAAE1
init|=
literal|0x443b
block|,
comment|// 01  000  1000  0111  011
name|ALLE1
init|=
literal|0x643c
block|,
comment|// 01  100  1000  0111  100
name|VALE1
init|=
literal|0x443d
block|,
comment|// 01  000  1000  0111  101
name|VALE2
init|=
literal|0x643d
block|,
comment|// 01  100  1000  0111  101
name|VALE3
init|=
literal|0x743d
block|,
comment|// 01  110  1000  0111  101
name|VMALLS12E1
init|=
literal|0x643e
block|,
comment|// 01  100  1000  0111  110
name|VAALE1
init|=
literal|0x443f
comment|// 01  000  1000  0111  111
block|}
enum|;
name|struct
name|TLBIMapper
range|:
name|NamedImmMapper
block|{
specifier|const
specifier|static
name|Mapping
name|TLBIPairs
index|[]
block|;
name|TLBIMapper
argument_list|()
block|;   }
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|NeedsRegister
parameter_list|(
name|TLBIValues
name|Val
parameter_list|)
block|{
switch|switch
condition|(
name|Val
condition|)
block|{
case|case
name|VMALLE1IS
case|:
case|case
name|ALLE2IS
case|:
case|case
name|ALLE3IS
case|:
case|case
name|ALLE1IS
case|:
case|case
name|VMALLS12E1IS
case|:
case|case
name|VMALLE1
case|:
case|case
name|ALLE2
case|:
case|case
name|ALLE3
case|:
case|case
name|ALLE1
case|:
case|case
name|VMALLS12E1
case|:
return|return
name|false
return|;
default|default:
return|return
name|true
return|;
block|}
block|}
block|}
name|namespace
name|AArch64II
block|{
enum|enum
name|TOF
block|{
comment|//===--------------------------------------------------------------===//
comment|// AArch64 Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|// MO_GOT - Represents a relocation referring to the GOT entry of a given
comment|// symbol. Used in adrp.
name|MO_GOT
block|,
comment|// MO_GOT_LO12 - Represents a relocation referring to the low 12 bits of the
comment|// GOT entry of a given symbol. Used in ldr only.
name|MO_GOT_LO12
block|,
comment|// MO_DTPREL_* - Represents a relocation referring to the offset from a
comment|// module's dynamic thread pointer. Used in the local-dynamic TLS access
comment|// model.
name|MO_DTPREL_G1
block|,
name|MO_DTPREL_G0_NC
block|,
comment|// MO_GOTTPREL_* - Represents a relocation referring to a GOT entry
comment|// providing the offset of a variable from the thread-pointer. Used in
comment|// initial-exec TLS model where this offset is assigned in the static thread
comment|// block and thus known by the dynamic linker.
name|MO_GOTTPREL
block|,
name|MO_GOTTPREL_LO12
block|,
comment|// MO_TLSDESC_* - Represents a relocation referring to a GOT entry providing
comment|// a TLS descriptor chosen by the dynamic linker. Used for the
comment|// general-dynamic and local-dynamic TLS access models where very littls is
comment|// known at link-time.
name|MO_TLSDESC
block|,
name|MO_TLSDESC_LO12
block|,
comment|// MO_TPREL_* - Represents a relocation referring to the offset of a
comment|// variable from the thread pointer itself. Used in the local-exec TLS
comment|// access model.
name|MO_TPREL_G1
block|,
name|MO_TPREL_G0_NC
block|,
comment|// MO_LO12 - On a symbol operand, this represents a relocation containing
comment|// lower 12 bits of the address. Used in add/sub/ldr/str.
name|MO_LO12
block|,
comment|// MO_ABS_G* - Represent the 16-bit granules of an absolute reference using
comment|// movz/movk instructions.
name|MO_ABS_G3
block|,
name|MO_ABS_G2_NC
block|,
name|MO_ABS_G1_NC
block|,
name|MO_ABS_G0_NC
block|}
enum|;
block|}
name|class
name|APFloat
decl_stmt|;
name|namespace
name|A64Imms
block|{
name|bool
name|isFPImm
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|Val
parameter_list|,
name|uint32_t
modifier|&
name|Imm8Bits
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isFPImm
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|Val
parameter_list|)
block|{
name|uint32_t
name|Imm8
decl_stmt|;
return|return
name|isFPImm
argument_list|(
name|Val
argument_list|,
name|Imm8
argument_list|)
return|;
block|}
name|bool
name|isLogicalImm
parameter_list|(
name|unsigned
name|RegWidth
parameter_list|,
name|uint64_t
name|Imm
parameter_list|,
name|uint32_t
modifier|&
name|Bits
parameter_list|)
function_decl|;
name|bool
name|isLogicalImmBits
parameter_list|(
name|unsigned
name|RegWidth
parameter_list|,
name|uint32_t
name|Bits
parameter_list|,
name|uint64_t
modifier|&
name|Imm
parameter_list|)
function_decl|;
name|bool
name|isMOVZImm
parameter_list|(
name|int
name|RegWidth
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|int
modifier|&
name|UImm16
parameter_list|,
name|int
modifier|&
name|Shift
parameter_list|)
function_decl|;
name|bool
name|isMOVNImm
parameter_list|(
name|int
name|RegWidth
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|int
modifier|&
name|UImm16
parameter_list|,
name|int
modifier|&
name|Shift
parameter_list|)
function_decl|;
comment|// We sometimes want to know whether the immediate is representable with a
comment|// MOVN but *not* with a MOVZ (because that would take priority).
name|bool
name|isOnlyMOVNImm
parameter_list|(
name|int
name|RegWidth
parameter_list|,
name|uint64_t
name|Value
parameter_list|,
name|int
modifier|&
name|UImm16
parameter_list|,
name|int
modifier|&
name|Shift
parameter_list|)
function_decl|;
name|uint64_t
name|decodeNeonModImm
parameter_list|(
name|unsigned
name|Val
parameter_list|,
name|unsigned
name|OpCmode
parameter_list|,
name|unsigned
modifier|&
name|EltBits
parameter_list|)
function_decl|;
name|bool
name|decodeNeonModShiftImm
parameter_list|(
name|unsigned
name|OpCmode
parameter_list|,
name|unsigned
modifier|&
name|ShiftImm
parameter_list|,
name|unsigned
modifier|&
name|ShiftOnesIn
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

