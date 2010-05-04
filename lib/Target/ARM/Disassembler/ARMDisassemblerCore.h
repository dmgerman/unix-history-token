begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMDisassemblerCore.h - ARM disassembler helpers ---------*- C++ -*-===//
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
comment|// This file is part of the ARM Disassembler.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The first part defines the enumeration type of ARM instruction format, which
end_comment

begin_comment
comment|// specifies the encoding used by the instruction, as well as a helper function
end_comment

begin_comment
comment|// to convert the enums to printable char strings.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It also contains code to represent the concepts of Builder and DisassembleFP
end_comment

begin_comment
comment|// to solve the problem of disassembling an ARM instr.
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
name|ARMDISASSEMBLERCORE_H
end_ifndef

begin_define
define|#
directive|define
name|ARMDISASSEMBLERCORE_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMDisassembler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMUtils
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|OpcodeName
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/////////////////////////////////////////////////////
comment|//                                                 //
comment|//  Enums and Utilities for ARM Instruction Format //
comment|//                                                 //
comment|/////////////////////////////////////////////////////
define|#
directive|define
name|ARM_FORMATS
define|\
value|ENTRY(ARM_FORMAT_PSEUDO,         0) \   ENTRY(ARM_FORMAT_MULFRM,         1) \   ENTRY(ARM_FORMAT_BRFRM,          2) \   ENTRY(ARM_FORMAT_BRMISCFRM,      3) \   ENTRY(ARM_FORMAT_DPFRM,          4) \   ENTRY(ARM_FORMAT_DPSOREGFRM,     5) \   ENTRY(ARM_FORMAT_LDFRM,          6) \   ENTRY(ARM_FORMAT_STFRM,          7) \   ENTRY(ARM_FORMAT_LDMISCFRM,      8) \   ENTRY(ARM_FORMAT_STMISCFRM,      9) \   ENTRY(ARM_FORMAT_LDSTMULFRM,    10) \   ENTRY(ARM_FORMAT_LDSTEXFRM,     11) \   ENTRY(ARM_FORMAT_ARITHMISCFRM,  12) \   ENTRY(ARM_FORMAT_EXTFRM,        13) \   ENTRY(ARM_FORMAT_VFPUNARYFRM,   14) \   ENTRY(ARM_FORMAT_VFPBINARYFRM,  15) \   ENTRY(ARM_FORMAT_VFPCONV1FRM,   16) \   ENTRY(ARM_FORMAT_VFPCONV2FRM,   17) \   ENTRY(ARM_FORMAT_VFPCONV3FRM,   18) \   ENTRY(ARM_FORMAT_VFPCONV4FRM,   19) \   ENTRY(ARM_FORMAT_VFPCONV5FRM,   20) \   ENTRY(ARM_FORMAT_VFPLDSTFRM,    21) \   ENTRY(ARM_FORMAT_VFPLDSTMULFRM, 22) \   ENTRY(ARM_FORMAT_VFPMISCFRM,    23) \   ENTRY(ARM_FORMAT_THUMBFRM,      24) \   ENTRY(ARM_FORMAT_NEONFRM,       25) \   ENTRY(ARM_FORMAT_NEONGETLNFRM,  26) \   ENTRY(ARM_FORMAT_NEONSETLNFRM,  27) \   ENTRY(ARM_FORMAT_NEONDUPFRM,    28) \   ENTRY(ARM_FORMAT_MISCFRM,       29) \   ENTRY(ARM_FORMAT_THUMBMISCFRM,  30) \   ENTRY(ARM_FORMAT_NLdSt,         31) \   ENTRY(ARM_FORMAT_N1RegModImm,   32) \   ENTRY(ARM_FORMAT_N2Reg,         33) \   ENTRY(ARM_FORMAT_NVCVT,         34) \   ENTRY(ARM_FORMAT_NVecDupLn,     35) \   ENTRY(ARM_FORMAT_N2RegVecShL,   36) \   ENTRY(ARM_FORMAT_N2RegVecShR,   37) \   ENTRY(ARM_FORMAT_N3Reg,         38) \   ENTRY(ARM_FORMAT_N3RegVecSh,    39) \   ENTRY(ARM_FORMAT_NVecExtract,   40) \   ENTRY(ARM_FORMAT_NVecMulScalar, 41) \   ENTRY(ARM_FORMAT_NVTBL,         42)
comment|// ARM instruction format specifies the encoding used by the instruction.
define|#
directive|define
name|ENTRY
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|n = v,
typedef|typedef
enum|enum
block|{
name|ARM_FORMATS
name|ARM_FORMAT_NA
block|}
name|ARMFormat
typedef|;
undef|#
directive|undef
name|ENTRY
comment|// Converts enum to const char*.
specifier|static
specifier|const
specifier|inline
name|char
modifier|*
name|stringForARMFormat
parameter_list|(
name|ARMFormat
name|form
parameter_list|)
block|{
define|#
directive|define
name|ENTRY
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|case n: return #n;
switch|switch
condition|(
name|form
condition|)
block|{
name|ARM_FORMATS
case|case
name|ARM_FORMAT_NA
case|:
default|default:
return|return
literal|""
return|;
block|}
undef|#
directive|undef
name|ENTRY
block|}
comment|/// Expands on the enum definitions from ARMBaseInstrInfo.h.
comment|/// They are being used by the disassembler implementation.
name|namespace
name|ARMII
block|{
enum|enum
block|{
name|NEONRegMask
init|=
literal|15
block|,
name|GPRRegMask
init|=
literal|15
block|,
name|NEON_RegRdShift
init|=
literal|12
block|,
name|NEON_D_BitShift
init|=
literal|22
block|,
name|NEON_RegRnShift
init|=
literal|16
block|,
name|NEON_N_BitShift
init|=
literal|7
block|,
name|NEON_RegRmShift
init|=
literal|0
block|,
name|NEON_M_BitShift
init|=
literal|5
block|}
enum|;
block|}
comment|/// Utility function for extracting [From, To] bits from a uint32_t.
specifier|static
specifier|inline
name|unsigned
name|slice
parameter_list|(
name|uint32_t
name|Bits
parameter_list|,
name|unsigned
name|From
parameter_list|,
name|unsigned
name|To
parameter_list|)
block|{
name|assert
argument_list|(
name|From
operator|<
literal|32
operator|&&
name|To
operator|<
literal|32
operator|&&
name|From
operator|>=
name|To
argument_list|)
expr_stmt|;
return|return
operator|(
name|Bits
operator|>>
name|To
operator|)
operator|&
operator|(
operator|(
literal|1
operator|<<
operator|(
name|From
operator|-
name|To
operator|+
literal|1
operator|)
operator|)
operator|-
literal|1
operator|)
return|;
block|}
comment|/// Utility function for setting [From, To] bits to Val for a uint32_t.
specifier|static
specifier|inline
name|void
name|setSlice
parameter_list|(
name|uint32_t
modifier|&
name|Bits
parameter_list|,
name|unsigned
name|From
parameter_list|,
name|unsigned
name|To
parameter_list|,
name|uint32_t
name|Val
parameter_list|)
block|{
name|assert
argument_list|(
name|From
operator|<
literal|32
operator|&&
name|To
operator|<
literal|32
operator|&&
name|From
operator|>=
name|To
argument_list|)
expr_stmt|;
name|uint32_t
name|Mask
init|=
operator|(
operator|(
literal|1
operator|<<
operator|(
name|From
operator|-
name|To
operator|+
literal|1
operator|)
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
name|Bits
operator|&=
operator|~
operator|(
name|Mask
operator|<<
name|To
operator|)
expr_stmt|;
name|Bits
operator||=
operator|(
name|Val
operator|&
name|Mask
operator|)
operator|<<
name|To
expr_stmt|;
block|}
comment|/// Various utilities for checking the target specific flags.
comment|/// A unary data processing instruction doesn't have an Rn operand.
specifier|static
specifier|inline
name|bool
name|isUnaryDP
parameter_list|(
name|unsigned
name|TSFlags
parameter_list|)
block|{
return|return
operator|(
name|TSFlags
operator|&
name|ARMII
operator|::
name|UnaryDP
operator|)
return|;
block|}
comment|/// This four-bit field describes the addressing mode used.
comment|/// See also ARMBaseInstrInfo.h.
specifier|static
specifier|inline
name|unsigned
name|getAddrMode
parameter_list|(
name|unsigned
name|TSFlags
parameter_list|)
block|{
return|return
operator|(
name|TSFlags
operator|&
name|ARMII
operator|::
name|AddrModeMask
operator|)
return|;
block|}
comment|/// {IndexModePre, IndexModePost}
comment|/// Only valid for load and store ops.
comment|/// See also ARMBaseInstrInfo.h.
specifier|static
specifier|inline
name|unsigned
name|getIndexMode
parameter_list|(
name|unsigned
name|TSFlags
parameter_list|)
block|{
return|return
operator|(
name|TSFlags
operator|&
name|ARMII
operator|::
name|IndexModeMask
operator|)
operator|>>
name|ARMII
operator|::
name|IndexModeShift
return|;
block|}
comment|/// Pre-/post-indexed operations define an extra $base_wb in the OutOperandList.
specifier|static
specifier|inline
name|bool
name|isPrePostLdSt
parameter_list|(
name|unsigned
name|TSFlags
parameter_list|)
block|{
return|return
operator|(
name|TSFlags
operator|&
name|ARMII
operator|::
name|IndexModeMask
operator|)
operator|!=
literal|0
return|;
block|}
comment|// Forward declaration.
name|class
name|ARMBasicMCBuilder
decl_stmt|;
comment|// Builder Object is mostly ignored except in some Thumb disassemble functions.
typedef|typedef
name|ARMBasicMCBuilder
modifier|*
name|BO
typedef|;
comment|/// DisassembleFP - DisassembleFP points to a function that disassembles an insn
comment|/// and builds the MCOperand list upon disassembly.  It returns false on failure
comment|/// or true on success.  The number of operands added is updated upon success.
typedef|typedef
name|bool
function_decl|(
modifier|*
name|DisassembleFP
function_decl|)
parameter_list|(
name|MCInst
modifier|&
name|MI
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|uint32_t
name|insn
parameter_list|,
name|unsigned
name|short
name|NumOps
parameter_list|,
name|unsigned
modifier|&
name|NumOpsAdded
parameter_list|,
name|BO
name|Builder
parameter_list|)
function_decl|;
comment|/// CreateMCBuilder - Return an ARMBasicMCBuilder that can build up the MC
comment|/// infrastructure of an MCInst given the Opcode and Format of the instr.
comment|/// Return NULL if it fails to create/return a proper builder.  API clients
comment|/// are responsible for freeing up of the allocated memory.  Cacheing can be
comment|/// performed by the API clients to improve performance.
specifier|extern
name|ARMBasicMCBuilder
modifier|*
name|CreateMCBuilder
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|ARMFormat
name|Format
parameter_list|)
function_decl|;
comment|/// ARMBasicMCBuilder - ARMBasicMCBuilder represents an ARM MCInst builder that
comment|/// knows how to build up the MCOperand list.
name|class
name|ARMBasicMCBuilder
block|{
name|friend
name|ARMBasicMCBuilder
modifier|*
name|CreateMCBuilder
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|ARMFormat
name|Format
parameter_list|)
function_decl|;
name|unsigned
name|Opcode
decl_stmt|;
name|ARMFormat
name|Format
decl_stmt|;
name|unsigned
name|short
name|NumOps
decl_stmt|;
name|DisassembleFP
name|Disasm
decl_stmt|;
name|Session
modifier|*
name|SP
decl_stmt|;
name|int
name|Err
decl_stmt|;
comment|// !=0 if the builder encounters some error condition during build.
name|private
label|:
comment|/// Opcode, Format, and NumOperands make up an ARM Basic MCBuilder.
name|ARMBasicMCBuilder
argument_list|(
argument|unsigned opc
argument_list|,
argument|ARMFormat format
argument_list|,
argument|unsigned short num
argument_list|)
empty_stmt|;
name|public
label|:
name|ARMBasicMCBuilder
argument_list|(
name|ARMBasicMCBuilder
operator|&
name|B
argument_list|)
operator|:
name|Opcode
argument_list|(
name|B
operator|.
name|Opcode
argument_list|)
operator|,
name|Format
argument_list|(
name|B
operator|.
name|Format
argument_list|)
operator|,
name|NumOps
argument_list|(
name|B
operator|.
name|NumOps
argument_list|)
operator|,
name|Disasm
argument_list|(
name|B
operator|.
name|Disasm
argument_list|)
operator|,
name|SP
argument_list|(
argument|B.SP
argument_list|)
block|{
name|Err
operator|=
literal|0
block|;   }
name|virtual
operator|~
name|ARMBasicMCBuilder
argument_list|()
block|{}
name|void
name|SetSession
argument_list|(
argument|Session *sp
argument_list|)
block|{
name|SP
operator|=
name|sp
block|;   }
name|void
name|SetErr
argument_list|(
argument|int ErrCode
argument_list|)
block|{
name|Err
operator|=
name|ErrCode
block|;   }
comment|/// DoPredicateOperands - DoPredicateOperands process the predicate operands
comment|/// of some Thumb instructions which come before the reglist operands.  It
comment|/// returns true if the two predicate operands have been processed.
name|bool
name|DoPredicateOperands
argument_list|(
argument|MCInst& MI
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|uint32_t insn
argument_list|,
argument|unsigned short NumOpsRemaning
argument_list|)
expr_stmt|;
comment|/// TryPredicateAndSBitModifier - TryPredicateAndSBitModifier tries to process
comment|/// the possible Predicate and SBitModifier, to build the remaining MCOperand
comment|/// constituents.
name|bool
name|TryPredicateAndSBitModifier
parameter_list|(
name|MCInst
modifier|&
name|MI
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|uint32_t
name|insn
parameter_list|,
name|unsigned
name|short
name|NumOpsRemaning
parameter_list|)
function_decl|;
comment|/// InITBlock - InITBlock returns true if we are inside an IT block.
name|bool
name|InITBlock
parameter_list|()
block|{
if|if
condition|(
name|SP
condition|)
return|return
name|SP
operator|->
name|ITCounter
operator|>
literal|0
return|;
return|return
name|false
return|;
block|}
comment|/// Build - Build delegates to BuildIt to perform the heavy liftling.  After
comment|/// that, it invokes RunBuildAfterHook where some housekeepings can be done.
name|virtual
name|bool
name|Build
parameter_list|(
name|MCInst
modifier|&
name|MI
parameter_list|,
name|uint32_t
name|insn
parameter_list|)
block|{
name|bool
name|Status
init|=
name|BuildIt
argument_list|(
name|MI
argument_list|,
name|insn
argument_list|)
decl_stmt|;
return|return
name|RunBuildAfterHook
argument_list|(
name|Status
argument_list|,
name|MI
argument_list|,
name|insn
argument_list|)
return|;
block|}
comment|/// BuildIt - BuildIt performs the build step for this ARM Basic MC Builder.
comment|/// The general idea is to set the Opcode for the MCInst, followed by adding
comment|/// the appropriate MCOperands to the MCInst.  ARM Basic MC Builder delegates
comment|/// to the Format-specific disassemble function for disassembly, followed by
comment|/// TryPredicateAndSBitModifier() for PredicateOperand and OptionalDefOperand
comment|/// which follow the Dst/Src Operands.
name|virtual
name|bool
name|BuildIt
parameter_list|(
name|MCInst
modifier|&
name|MI
parameter_list|,
name|uint32_t
name|insn
parameter_list|)
function_decl|;
comment|/// RunBuildAfterHook - RunBuildAfterHook performs operations deemed necessary
comment|/// after BuildIt is finished.
name|virtual
name|bool
name|RunBuildAfterHook
parameter_list|(
name|bool
name|Status
parameter_list|,
name|MCInst
modifier|&
name|MI
parameter_list|,
name|uint32_t
name|insn
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Get condition of the current IT instruction.
name|unsigned
name|GetITCond
parameter_list|()
block|{
name|assert
argument_list|(
name|SP
argument_list|)
expr_stmt|;
return|return
name|slice
argument_list|(
name|SP
operator|->
name|ITState
argument_list|,
literal|7
argument_list|,
literal|4
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

