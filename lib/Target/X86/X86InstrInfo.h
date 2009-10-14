begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86InstrInfo.h - X86 Instruction Information ------------*- C++ -*- ===//
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
comment|// This file contains the X86 implementation of the TargetInstrInfo class.
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
name|X86INSTRUCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86INSTRUCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86.h"
end_include

begin_include
include|#
directive|include
file|"X86RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|X86RegisterInfo
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
name|namespace
name|X86
block|{
comment|// X86 specific condition code. These correspond to X86_*_COND in
comment|// X86InstrInfo.td. They must be kept in synch.
enum|enum
name|CondCode
block|{
name|COND_A
init|=
literal|0
block|,
name|COND_AE
init|=
literal|1
block|,
name|COND_B
init|=
literal|2
block|,
name|COND_BE
init|=
literal|3
block|,
name|COND_E
init|=
literal|4
block|,
name|COND_G
init|=
literal|5
block|,
name|COND_GE
init|=
literal|6
block|,
name|COND_L
init|=
literal|7
block|,
name|COND_LE
init|=
literal|8
block|,
name|COND_NE
init|=
literal|9
block|,
name|COND_NO
init|=
literal|10
block|,
name|COND_NP
init|=
literal|11
block|,
name|COND_NS
init|=
literal|12
block|,
name|COND_O
init|=
literal|13
block|,
name|COND_P
init|=
literal|14
block|,
name|COND_S
init|=
literal|15
block|,
comment|// Artificial condition codes. These are used by AnalyzeBranch
comment|// to indicate a block terminated with two conditional branches to
comment|// the same location. This occurs in code using FCMP_OEQ or FCMP_UNE,
comment|// which can't be represented on x86 with a single condition. These
comment|// are never used in MachineInstrs.
name|COND_NE_OR_P
block|,
name|COND_NP_OR_E
block|,
name|COND_INVALID
block|}
enum|;
comment|// Turn condition code into conditional branch opcode.
name|unsigned
name|GetCondBranchFromCond
parameter_list|(
name|CondCode
name|CC
parameter_list|)
function_decl|;
comment|/// GetOppositeBranchCondition - Return the inverse of the specified cond,
comment|/// e.g. turning COND_E to COND_NE.
name|CondCode
name|GetOppositeBranchCondition
argument_list|(
name|X86
operator|::
name|CondCode
name|CC
argument_list|)
decl_stmt|;
block|}
comment|/// X86II - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|X86II
block|{
comment|/// Target Operand Flag enum.
enum|enum
name|TOF
block|{
comment|//===------------------------------------------------------------------===//
comment|// X86 Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|/// MO_GOT_ABSOLUTE_ADDRESS - On a symbol operand, this represents a
comment|/// relocation of:
comment|///    SYMBOL_LABEL + [. - PICBASELABEL]
name|MO_GOT_ABSOLUTE_ADDRESS
block|,
comment|/// MO_PIC_BASE_OFFSET - On a symbol operand this indicates that the
comment|/// immediate should get the value of the symbol minus the PIC base label:
comment|///    SYMBOL_LABEL - PICBASELABEL
name|MO_PIC_BASE_OFFSET
block|,
comment|/// MO_GOT - On a symbol operand this indicates that the immediate is the
comment|/// offset to the GOT entry for the symbol name from the base of the GOT.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @GOT
name|MO_GOT
block|,
comment|/// MO_GOTOFF - On a symbol operand this indicates that the immediate is
comment|/// the offset to the location of the symbol name from the base of the GOT.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @GOTOFF
name|MO_GOTOFF
block|,
comment|/// MO_GOTPCREL - On a symbol operand this indicates that the immediate is
comment|/// offset to the GOT entry for the symbol name from the current code
comment|/// location.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @GOTPCREL
name|MO_GOTPCREL
block|,
comment|/// MO_PLT - On a symbol operand this indicates that the immediate is
comment|/// offset to the PLT entry of symbol name from the current code location.
comment|///
comment|/// See the X86-64 ELF ABI supplement for more details.
comment|///    SYMBOL_LABEL @PLT
name|MO_PLT
block|,
comment|/// MO_TLSGD - On a symbol operand this indicates that the immediate is
comment|/// some TLS offset.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @TLSGD
name|MO_TLSGD
block|,
comment|/// MO_GOTTPOFF - On a symbol operand this indicates that the immediate is
comment|/// some TLS offset.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @GOTTPOFF
name|MO_GOTTPOFF
block|,
comment|/// MO_INDNTPOFF - On a symbol operand this indicates that the immediate is
comment|/// some TLS offset.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @INDNTPOFF
name|MO_INDNTPOFF
block|,
comment|/// MO_TPOFF - On a symbol operand this indicates that the immediate is
comment|/// some TLS offset.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @TPOFF
name|MO_TPOFF
block|,
comment|/// MO_NTPOFF - On a symbol operand this indicates that the immediate is
comment|/// some TLS offset.
comment|///
comment|/// See 'ELF Handling for Thread-Local Storage' for more details.
comment|///    SYMBOL_LABEL @NTPOFF
name|MO_NTPOFF
block|,
comment|/// MO_DLLIMPORT - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "__imp_FOO" symbol.  This is used for
comment|/// dllimport linkage on windows.
name|MO_DLLIMPORT
block|,
comment|/// MO_DARWIN_STUB - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "FOO$stub" symbol.  This is used for calls
comment|/// and jumps to external functions on Tiger and before.
name|MO_DARWIN_STUB
block|,
comment|/// MO_DARWIN_NONLAZY - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "FOO$non_lazy_ptr" symbol, which is a
comment|/// non-PIC-base-relative reference to a non-hidden dyld lazy pointer stub.
name|MO_DARWIN_NONLAZY
block|,
comment|/// MO_DARWIN_NONLAZY_PIC_BASE - On a symbol operand "FOO", this indicates
comment|/// that the reference is actually to "FOO$non_lazy_ptr - PICBASE", which is
comment|/// a PIC-base-relative reference to a non-hidden dyld lazy pointer stub.
name|MO_DARWIN_NONLAZY_PIC_BASE
block|,
comment|/// MO_DARWIN_HIDDEN_NONLAZY_PIC_BASE - On a symbol operand "FOO", this
comment|/// indicates that the reference is actually to "FOO$non_lazy_ptr -PICBASE",
comment|/// which is a PIC-base-relative reference to a hidden dyld lazy pointer
comment|/// stub.
name|MO_DARWIN_HIDDEN_NONLAZY_PIC_BASE
block|}
enum|;
block|}
comment|/// isGlobalStubReference - Return true if the specified TargetFlag operand is
comment|/// a reference to a stub for a global, not the global itself.
specifier|inline
specifier|static
name|bool
name|isGlobalStubReference
parameter_list|(
name|unsigned
name|char
name|TargetFlag
parameter_list|)
block|{
switch|switch
condition|(
name|TargetFlag
condition|)
block|{
case|case
name|X86II
operator|::
name|MO_DLLIMPORT
case|:
comment|// dllimport stub.
case|case
name|X86II
operator|::
name|MO_GOTPCREL
case|:
comment|// rip-relative GOT reference.
case|case
name|X86II
operator|::
name|MO_GOT
case|:
comment|// normal GOT reference.
case|case
name|X86II
operator|::
name|MO_DARWIN_NONLAZY_PIC_BASE
case|:
comment|// Normal $non_lazy_ptr ref.
case|case
name|X86II
operator|::
name|MO_DARWIN_NONLAZY
case|:
comment|// Normal $non_lazy_ptr ref.
case|case
name|X86II
operator|::
name|MO_DARWIN_HIDDEN_NONLAZY_PIC_BASE
case|:
comment|// Hidden $non_lazy_ptr ref.
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
comment|/// isGlobalRelativeToPICBase - Return true if the specified global value
comment|/// reference is relative to a 32-bit PIC base (X86ISD::GlobalBaseReg).  If this
comment|/// is true, the addressing mode has the PIC base register added in (e.g. EBX).
specifier|inline
specifier|static
name|bool
name|isGlobalRelativeToPICBase
parameter_list|(
name|unsigned
name|char
name|TargetFlag
parameter_list|)
block|{
switch|switch
condition|(
name|TargetFlag
condition|)
block|{
case|case
name|X86II
operator|::
name|MO_GOTOFF
case|:
comment|// isPICStyleGOT: local global.
case|case
name|X86II
operator|::
name|MO_GOT
case|:
comment|// isPICStyleGOT: other global.
case|case
name|X86II
operator|::
name|MO_PIC_BASE_OFFSET
case|:
comment|// Darwin local global.
case|case
name|X86II
operator|::
name|MO_DARWIN_NONLAZY_PIC_BASE
case|:
comment|// Darwin/32 external global.
case|case
name|X86II
operator|::
name|MO_DARWIN_HIDDEN_NONLAZY_PIC_BASE
case|:
comment|// Darwin/32 hidden global.
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
comment|/// X86II - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|X86II
block|{
enum|enum
block|{
comment|//===------------------------------------------------------------------===//
comment|// Instruction encodings.  These are the standard/most common forms for X86
comment|// instructions.
comment|//
comment|// PseudoFrm - This represents an instruction that is a pseudo instruction
comment|// or one that has not been implemented yet.  It is illegal to code generate
comment|// it, but tolerated for intermediate implementation stages.
name|Pseudo
init|=
literal|0
block|,
comment|/// Raw - This form is for instructions that don't have any operands, so
comment|/// they are just a fixed opcode value, like 'leave'.
name|RawFrm
init|=
literal|1
block|,
comment|/// AddRegFrm - This form is used for instructions like 'push r32' that have
comment|/// their one register operand added to their opcode.
name|AddRegFrm
init|=
literal|2
block|,
comment|/// MRMDestReg - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a destination, which in this case is a register.
comment|///
name|MRMDestReg
init|=
literal|3
block|,
comment|/// MRMDestMem - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a destination, which in this case is memory.
comment|///
name|MRMDestMem
init|=
literal|4
block|,
comment|/// MRMSrcReg - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a source, which in this case is a register.
comment|///
name|MRMSrcReg
init|=
literal|5
block|,
comment|/// MRMSrcMem - This form is used for instructions that use the Mod/RM byte
comment|/// to specify a source, which in this case is memory.
comment|///
name|MRMSrcMem
init|=
literal|6
block|,
comment|/// MRM[0-7][rm] - These forms are used to represent instructions that use
comment|/// a Mod/RM byte, and use the middle field to hold extended opcode
comment|/// information.  In the intel manual these are represented as /0, /1, ...
comment|///
comment|// First, instructions that operate on a register r/m operand...
name|MRM0r
init|=
literal|16
block|,
name|MRM1r
init|=
literal|17
block|,
name|MRM2r
init|=
literal|18
block|,
name|MRM3r
init|=
literal|19
block|,
comment|// Format /0 /1 /2 /3
name|MRM4r
init|=
literal|20
block|,
name|MRM5r
init|=
literal|21
block|,
name|MRM6r
init|=
literal|22
block|,
name|MRM7r
init|=
literal|23
block|,
comment|// Format /4 /5 /6 /7
comment|// Next, instructions that operate on a memory r/m operand...
name|MRM0m
init|=
literal|24
block|,
name|MRM1m
init|=
literal|25
block|,
name|MRM2m
init|=
literal|26
block|,
name|MRM3m
init|=
literal|27
block|,
comment|// Format /0 /1 /2 /3
name|MRM4m
init|=
literal|28
block|,
name|MRM5m
init|=
literal|29
block|,
name|MRM6m
init|=
literal|30
block|,
name|MRM7m
init|=
literal|31
block|,
comment|// Format /4 /5 /6 /7
comment|// MRMInitReg - This form is used for instructions whose source and
comment|// destinations are the same register.
name|MRMInitReg
init|=
literal|32
block|,
name|FormMask
init|=
literal|63
block|,
comment|//===------------------------------------------------------------------===//
comment|// Actual flags...
comment|// OpSize - Set if this instruction requires an operand size prefix (0x66),
comment|// which most often indicates that the instruction operates on 16 bit data
comment|// instead of 32 bit data.
name|OpSize
init|=
literal|1
operator|<<
literal|6
block|,
comment|// AsSize - Set if this instruction requires an operand size prefix (0x67),
comment|// which most often indicates that the instruction address 16 bit address
comment|// instead of 32 bit address (or 32 bit address in 64 bit mode).
name|AdSize
init|=
literal|1
operator|<<
literal|7
block|,
comment|//===------------------------------------------------------------------===//
comment|// Op0Mask - There are several prefix bytes that are used to form two byte
comment|// opcodes.  These are currently 0x0F, 0xF3, and 0xD8-0xDF.  This mask is
comment|// used to obtain the setting of this field.  If no bits in this field is
comment|// set, there is no prefix byte for obtaining a multibyte opcode.
comment|//
name|Op0Shift
init|=
literal|8
block|,
name|Op0Mask
init|=
literal|0xF
operator|<<
name|Op0Shift
block|,
comment|// TB - TwoByte - Set if this instruction has a two byte opcode, which
comment|// starts with a 0x0F byte before the real opcode.
name|TB
init|=
literal|1
operator|<<
name|Op0Shift
block|,
comment|// REP - The 0xF3 prefix byte indicating repetition of the following
comment|// instruction.
name|REP
init|=
literal|2
operator|<<
name|Op0Shift
block|,
comment|// D8-DF - These escape opcodes are used by the floating point unit.  These
comment|// values must remain sequential.
name|D8
init|=
literal|3
operator|<<
name|Op0Shift
block|,
name|D9
init|=
literal|4
operator|<<
name|Op0Shift
block|,
name|DA
init|=
literal|5
operator|<<
name|Op0Shift
block|,
name|DB
init|=
literal|6
operator|<<
name|Op0Shift
block|,
name|DC
init|=
literal|7
operator|<<
name|Op0Shift
block|,
name|DD
init|=
literal|8
operator|<<
name|Op0Shift
block|,
name|DE
init|=
literal|9
operator|<<
name|Op0Shift
block|,
name|DF
init|=
literal|10
operator|<<
name|Op0Shift
block|,
comment|// XS, XD - These prefix codes are for single and double precision scalar
comment|// floating point operations performed in the SSE registers.
name|XD
init|=
literal|11
operator|<<
name|Op0Shift
block|,
name|XS
init|=
literal|12
operator|<<
name|Op0Shift
block|,
comment|// T8, TA - Prefix after the 0x0F prefix.
name|T8
init|=
literal|13
operator|<<
name|Op0Shift
block|,
name|TA
init|=
literal|14
operator|<<
name|Op0Shift
block|,
comment|// TF - Prefix before and after 0x0F
name|TF
init|=
literal|15
operator|<<
name|Op0Shift
block|,
comment|//===------------------------------------------------------------------===//
comment|// REX_W - REX prefixes are instruction prefixes used in 64-bit mode.
comment|// They are used to specify GPRs and SSE registers, 64-bit operand size,
comment|// etc. We only cares about REX.W and REX.R bits and only the former is
comment|// statically determined.
comment|//
name|REXShift
init|=
literal|12
block|,
name|REX_W
init|=
literal|1
operator|<<
name|REXShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// This three-bit field describes the size of an immediate operand.  Zero is
comment|// unused so that we can tell if we forgot to set a value.
name|ImmShift
init|=
literal|13
block|,
name|ImmMask
init|=
literal|7
operator|<<
name|ImmShift
block|,
name|Imm8
init|=
literal|1
operator|<<
name|ImmShift
block|,
name|Imm16
init|=
literal|2
operator|<<
name|ImmShift
block|,
name|Imm32
init|=
literal|3
operator|<<
name|ImmShift
block|,
name|Imm64
init|=
literal|4
operator|<<
name|ImmShift
block|,
comment|//===------------------------------------------------------------------===//
comment|// FP Instruction Classification...  Zero is non-fp instruction.
comment|// FPTypeMask - Mask for all of the FP types...
name|FPTypeShift
init|=
literal|16
block|,
name|FPTypeMask
init|=
literal|7
operator|<<
name|FPTypeShift
block|,
comment|// NotFP - The default, set for instructions that do not use FP registers.
name|NotFP
init|=
literal|0
operator|<<
name|FPTypeShift
block|,
comment|// ZeroArgFP - 0 arg FP instruction which implicitly pushes ST(0), f.e. fld0
name|ZeroArgFP
init|=
literal|1
operator|<<
name|FPTypeShift
block|,
comment|// OneArgFP - 1 arg FP instructions which implicitly read ST(0), such as fst
name|OneArgFP
init|=
literal|2
operator|<<
name|FPTypeShift
block|,
comment|// OneArgFPRW - 1 arg FP instruction which implicitly read ST(0) and write a
comment|// result back to ST(0).  For example, fcos, fsqrt, etc.
comment|//
name|OneArgFPRW
init|=
literal|3
operator|<<
name|FPTypeShift
block|,
comment|// TwoArgFP - 2 arg FP instructions which implicitly read ST(0), and an
comment|// explicit argument, storing the result to either ST(0) or the implicit
comment|// argument.  For example: fadd, fsub, fmul, etc...
name|TwoArgFP
init|=
literal|4
operator|<<
name|FPTypeShift
block|,
comment|// CompareFP - 2 arg FP instructions which implicitly read ST(0) and an
comment|// explicit argument, but have no destination.  Example: fucom, fucomi, ...
name|CompareFP
init|=
literal|5
operator|<<
name|FPTypeShift
block|,
comment|// CondMovFP - "2 operand" floating point conditional move instructions.
name|CondMovFP
init|=
literal|6
operator|<<
name|FPTypeShift
block|,
comment|// SpecialFP - Special instruction forms.  Dispatch by opcode explicitly.
name|SpecialFP
init|=
literal|7
operator|<<
name|FPTypeShift
block|,
comment|// Lock prefix
name|LOCKShift
init|=
literal|19
block|,
name|LOCK
init|=
literal|1
operator|<<
name|LOCKShift
block|,
comment|// Segment override prefixes. Currently we just need ability to address
comment|// stuff in gs and fs segments.
name|SegOvrShift
init|=
literal|20
block|,
name|SegOvrMask
init|=
literal|3
operator|<<
name|SegOvrShift
block|,
name|FS
init|=
literal|1
operator|<<
name|SegOvrShift
block|,
name|GS
init|=
literal|2
operator|<<
name|SegOvrShift
block|,
comment|// Bits 22 -> 23 are unused
name|OpcodeShift
init|=
literal|24
block|,
name|OpcodeMask
init|=
literal|0xFF
operator|<<
name|OpcodeShift
block|}
enum|;
block|}
specifier|const
name|int
name|X86AddrNumOperands
init|=
literal|5
decl_stmt|;
specifier|inline
specifier|static
name|bool
name|isScale
parameter_list|(
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|)
block|{
return|return
name|MO
operator|.
name|isImm
argument_list|()
operator|&&
operator|(
name|MO
operator|.
name|getImm
argument_list|()
operator|==
literal|1
operator|||
name|MO
operator|.
name|getImm
argument_list|()
operator|==
literal|2
operator|||
name|MO
operator|.
name|getImm
argument_list|()
operator|==
literal|4
operator|||
name|MO
operator|.
name|getImm
argument_list|()
operator|==
literal|8
operator|)
return|;
block|}
specifier|inline
specifier|static
name|bool
name|isLeaMem
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Op
parameter_list|)
block|{
if|if
condition|(
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
argument_list|)
operator|.
name|isFI
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|Op
operator|+
literal|4
operator|<=
name|MI
operator|->
name|getNumOperands
argument_list|()
operator|&&
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
name|isScale
argument_list|(
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|1
argument_list|)
argument_list|)
operator|&&
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|2
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
operator|(
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|3
argument_list|)
operator|.
name|isImm
argument_list|()
operator|||
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|3
argument_list|)
operator|.
name|isGlobal
argument_list|()
operator|||
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|3
argument_list|)
operator|.
name|isCPI
argument_list|()
operator|||
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|3
argument_list|)
operator|.
name|isJTI
argument_list|()
operator|)
return|;
block|}
specifier|inline
specifier|static
name|bool
name|isMem
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Op
parameter_list|)
block|{
if|if
condition|(
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
argument_list|)
operator|.
name|isFI
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|Op
operator|+
literal|5
operator|<=
name|MI
operator|->
name|getNumOperands
argument_list|()
operator|&&
name|MI
operator|->
name|getOperand
argument_list|(
name|Op
operator|+
literal|4
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
name|isLeaMem
argument_list|(
name|MI
argument_list|,
name|Op
argument_list|)
return|;
block|}
name|class
name|X86InstrInfo
range|:
name|public
name|TargetInstrInfoImpl
block|{
name|X86TargetMachine
operator|&
name|TM
block|;
specifier|const
name|X86RegisterInfo
name|RI
block|;
comment|/// RegOp2MemOpTable2Addr, RegOp2MemOpTable0, RegOp2MemOpTable1,
comment|/// RegOp2MemOpTable2 - Load / store folding opcode maps.
comment|///
name|DenseMap
operator|<
name|unsigned
operator|*
block|,
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
expr|>
name|RegOp2MemOpTable2Addr
block|;
name|DenseMap
operator|<
name|unsigned
operator|*
block|,
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
expr|>
name|RegOp2MemOpTable0
block|;
name|DenseMap
operator|<
name|unsigned
operator|*
block|,
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
expr|>
name|RegOp2MemOpTable1
block|;
name|DenseMap
operator|<
name|unsigned
operator|*
block|,
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
expr|>
name|RegOp2MemOpTable2
block|;
comment|/// MemOp2RegOpTable - Load / store unfolding opcode map.
comment|///
name|DenseMap
operator|<
name|unsigned
operator|*
block|,
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
expr|>
name|MemOp2RegOpTable
block|;
name|public
operator|:
name|explicit
name|X86InstrInfo
argument_list|(
name|X86TargetMachine
operator|&
name|tm
argument_list|)
block|;
comment|/// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
comment|/// such, whenever a client has an instance of instruction info, it should
comment|/// always be able to get register info as well (through this method).
comment|///
name|virtual
specifier|const
name|X86RegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
comment|/// Return true if the instruction is a register to register move and return
comment|/// the source and dest operands and their sub-register indices by reference.
name|virtual
name|bool
name|isMoveInstr
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|unsigned&SrcReg
argument_list|,
argument|unsigned&DstReg
argument_list|,
argument|unsigned&SrcSubIdx
argument_list|,
argument|unsigned&DstSubIdx
argument_list|)
specifier|const
block|;
name|unsigned
name|isLoadFromStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|unsigned
name|isStoreToStackSlot
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int&FrameIndex
argument_list|)
specifier|const
block|;
name|bool
name|isReallyTriviallyReMaterializable
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|AliasAnalysis *AA
argument_list|)
specifier|const
block|;
name|void
name|reMaterialize
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SubIdx
argument_list|,
argument|const MachineInstr *Orig
argument_list|)
specifier|const
block|;
comment|/// convertToThreeAddress - This method must be implemented by targets that
comment|/// set the M_CONVERTIBLE_TO_3_ADDR flag.  When this flag is set, the target
comment|/// may be able to convert a two-address instruction into a true
comment|/// three-address instruction on demand.  This allows the X86 target (for
comment|/// example) to convert ADD and SHL instructions into LEA instructions if they
comment|/// would require register copies due to two-addressness.
comment|///
comment|/// This method returns a null pointer if the transformation cannot be
comment|/// performed, otherwise it returns the new instruction.
comment|///
name|virtual
name|MachineInstr
operator|*
name|convertToThreeAddress
argument_list|(
argument|MachineFunction::iterator&MFI
argument_list|,
argument|MachineBasicBlock::iterator&MBBI
argument_list|,
argument|LiveVariables *LV
argument_list|)
specifier|const
block|;
comment|/// commuteInstruction - We have a few instructions that must be hacked on to
comment|/// commute them.
comment|///
name|virtual
name|MachineInstr
operator|*
name|commuteInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|bool NewMI
argument_list|)
specifier|const
block|;
comment|// Branch analysis.
name|virtual
name|bool
name|isUnpredicatedTerminator
argument_list|(
argument|const MachineInstr* MI
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|AnalyzeBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *&TBB
argument_list|,
argument|MachineBasicBlock *&FBB
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|,
argument|bool AllowModify
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|RemoveBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|InsertBranch
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock *TBB
argument_list|,
argument|MachineBasicBlock *FBB
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|copyRegToReg
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|const TargetRegisterClass *DestRC
argument_list|,
argument|const TargetRegisterClass *SrcRC
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|storeRegToStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|storeRegToAddr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|bool isKill
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Addr
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineInstr::mmo_iterator MMOBegin
argument_list|,
argument|MachineInstr::mmo_iterator MMOEnd
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|loadRegFromStackSlot
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|int FrameIndex
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|loadRegFromAddr
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|unsigned DestReg
argument_list|,
argument|SmallVectorImpl<MachineOperand>&Addr
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|,
argument|MachineInstr::mmo_iterator MMOBegin
argument_list|,
argument|MachineInstr::mmo_iterator MMOEnd
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|spillCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|restoreCalleeSavedRegisters
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|,
argument|const std::vector<CalleeSavedInfo>&CSI
argument_list|)
specifier|const
block|;
comment|/// foldMemoryOperand - If this target supports it, fold a load or store of
comment|/// the specified stack slot into the specified machine instruction for the
comment|/// specified operand(s).  If this is possible, the target should perform the
comment|/// folding and return true, otherwise it should return false.  If it folds
comment|/// the instruction, it is likely that the MachineInstruction the iterator
comment|/// references has been changed.
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|int FrameIndex
argument_list|)
specifier|const
block|;
comment|/// foldMemoryOperand - Same as the previous version except it allows folding
comment|/// of any load and store from / to any address, not just from a specific
comment|/// stack slot.
name|virtual
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|const SmallVectorImpl<unsigned>&Ops
argument_list|,
argument|MachineInstr* LoadMI
argument_list|)
specifier|const
block|;
comment|/// canFoldMemoryOperand - Returns true if the specified load / store is
comment|/// folding is possible.
name|virtual
name|bool
name|canFoldMemoryOperand
argument_list|(
argument|const MachineInstr*
argument_list|,
argument|const SmallVectorImpl<unsigned>&
argument_list|)
specifier|const
block|;
comment|/// unfoldMemoryOperand - Separate a single instruction which folded a load or
comment|/// a store or a load and a store into two or more instruction. If this is
comment|/// possible, returns true as well as the new instructions by reference.
name|virtual
name|bool
name|unfoldMemoryOperand
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|unsigned Reg
argument_list|,
argument|bool UnfoldLoad
argument_list|,
argument|bool UnfoldStore
argument_list|,
argument|SmallVectorImpl<MachineInstr*>&NewMIs
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|unfoldMemoryOperand
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDNode*>&NewNodes
argument_list|)
specifier|const
block|;
comment|/// getOpcodeAfterMemoryUnfold - Returns the opcode of the would be new
comment|/// instruction after load / store are unfolded from an instruction of the
comment|/// specified opcode. It returns zero if the specified unfolding is not
comment|/// possible.
name|virtual
name|unsigned
name|getOpcodeAfterMemoryUnfold
argument_list|(
argument|unsigned Opc
argument_list|,
argument|bool UnfoldLoad
argument_list|,
argument|bool UnfoldStore
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|BlockHasNoFallThrough
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|ReverseBranchCondition
argument_list|(
argument|SmallVectorImpl<MachineOperand>&Cond
argument_list|)
specifier|const
block|;
comment|/// isSafeToMoveRegClassDefs - Return true if it's safe to move a machine
comment|/// instruction that defines the specified register class.
name|bool
name|isSafeToMoveRegClassDefs
argument_list|(
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
comment|// getBaseOpcodeFor - This function returns the "base" X86 opcode for the
comment|// specified machine instruction.
comment|//
name|unsigned
name|char
name|getBaseOpcodeFor
argument_list|(
argument|const TargetInstrDesc *TID
argument_list|)
specifier|const
block|{
return|return
name|TID
operator|->
name|TSFlags
operator|>>
name|X86II
operator|::
name|OpcodeShift
return|;
block|}
name|unsigned
name|char
name|getBaseOpcodeFor
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|{
return|return
name|getBaseOpcodeFor
argument_list|(
operator|&
name|get
argument_list|(
name|Opcode
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isX86_64NonExtLowByteReg
argument_list|(
argument|unsigned reg
argument_list|)
block|{
return|return
operator|(
name|reg
operator|==
name|X86
operator|::
name|SPL
operator|||
name|reg
operator|==
name|X86
operator|::
name|BPL
operator|||
name|reg
operator|==
name|X86
operator|::
name|SIL
operator|||
name|reg
operator|==
name|X86
operator|::
name|DIL
operator|)
return|;
block|}
specifier|static
name|unsigned
name|sizeOfImm
argument_list|(
specifier|const
name|TargetInstrDesc
operator|*
name|Desc
argument_list|)
block|;
specifier|static
name|bool
name|isX86_64ExtendedReg
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
block|;
specifier|static
name|unsigned
name|determineREX
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
comment|/// GetInstSize - Returns the size of the specified MachineInstr.
comment|///
name|virtual
name|unsigned
name|GetInstSizeInBytes
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|/// getGlobalBaseReg - Return a virtual register initialized with the
comment|/// the global base register value. Output instructions required to
comment|/// initialize the register in the function entry block, if necessary.
comment|///
name|unsigned
name|getGlobalBaseReg
argument_list|(
argument|MachineFunction *MF
argument_list|)
specifier|const
block|;
name|private
operator|:
name|MachineInstr
operator|*
name|foldMemoryOperandImpl
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineInstr* MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|const SmallVectorImpl<MachineOperand>&MOs
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned Alignment
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

