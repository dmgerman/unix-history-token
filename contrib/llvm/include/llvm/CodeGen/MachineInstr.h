begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineInstr.h - MachineInstr class --------*- C++ -*-===//
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
comment|// This file contains the declaration of the MachineInstr class, which is the
end_comment

begin_comment
comment|// basic representation for all target dependent machine instructions used by
end_comment

begin_comment
comment|// the back end.
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
name|LLVM_CODEGEN_MACHINEINSTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEINSTR_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|TargetInstrDesc
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineMemOperand
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// MachineInstr - Representation of each machine instruction.
comment|///
name|class
name|MachineInstr
range|:
name|public
name|ilist_node
operator|<
name|MachineInstr
operator|>
block|{
name|public
operator|:
typedef|typedef
name|MachineMemOperand
modifier|*
modifier|*
name|mmo_iterator
typedef|;
comment|/// Flags to specify different kinds of comments to output in
comment|/// assembly code.  These flags carry semantic information not
comment|/// otherwise easily derivable from the IR text.
comment|///
block|enum
name|CommentFlag
block|{
name|ReloadReuse
operator|=
literal|0x1
block|}
decl_stmt|;
enum|enum
name|MIFlag
block|{
name|NoFlags
init|=
literal|0
block|,
name|FrameSetup
init|=
literal|1
operator|<<
literal|0
comment|// Instruction is used as a part of
comment|// function frame setup code.
block|}
enum|;
name|private
label|:
specifier|const
name|TargetInstrDesc
modifier|*
name|TID
decl_stmt|;
comment|// Instruction descriptor.
name|uint16_t
name|NumImplicitOps
decl_stmt|;
comment|// Number of implicit operands (which
comment|// are determined at construction time).
name|uint8_t
name|Flags
decl_stmt|;
comment|// Various bits of additional
comment|// information about machine
comment|// instruction.
name|uint8_t
name|AsmPrinterFlags
decl_stmt|;
comment|// Various bits of information used by
comment|// the AsmPrinter to emit helpful
comment|// comments.  This is *not* semantic
comment|// information.  Do not use this for
comment|// anything other than to convey comment
comment|// information to AsmPrinter.
name|std
operator|::
name|vector
operator|<
name|MachineOperand
operator|>
name|Operands
expr_stmt|;
comment|// the operands
name|mmo_iterator
name|MemRefs
decl_stmt|;
comment|// information on memory references
name|mmo_iterator
name|MemRefsEnd
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|Parent
decl_stmt|;
comment|// Pointer to the owning basic block.
name|DebugLoc
name|debugLoc
decl_stmt|;
comment|// Source line information.
comment|// OperandComplete - Return true if it's illegal to add a new operand
name|bool
name|OperandsComplete
parameter_list|()
function_decl|const;
name|MachineInstr
argument_list|(
specifier|const
name|MachineInstr
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MachineInstr
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
comment|// Intrusive list support
name|friend
block|struct
name|ilist_traits
operator|<
name|MachineInstr
operator|>
expr_stmt|;
name|friend
block|struct
name|ilist_traits
operator|<
name|MachineBasicBlock
operator|>
expr_stmt|;
name|void
name|setParent
parameter_list|(
name|MachineBasicBlock
modifier|*
name|P
parameter_list|)
block|{
name|Parent
operator|=
name|P
expr_stmt|;
block|}
comment|/// MachineInstr ctor - This constructor creates a copy of the given
comment|/// MachineInstr in the given MachineFunction.
name|MachineInstr
argument_list|(
name|MachineFunction
operator|&
argument_list|,
specifier|const
name|MachineInstr
operator|&
argument_list|)
expr_stmt|;
comment|/// MachineInstr ctor - This constructor creates a dummy MachineInstr with
comment|/// TID NULL and no operands.
name|MachineInstr
argument_list|()
expr_stmt|;
comment|// The next two constructors have DebugLoc and non-DebugLoc versions;
comment|// over time, the non-DebugLoc versions should be phased out and eventually
comment|// removed.
comment|/// MachineInstr ctor - This constructor creates a MachineInstr and adds the
comment|/// implicit operands.  It reserves space for the number of operands specified
comment|/// by the TargetInstrDesc.  The version with a DebugLoc should be preferred.
name|explicit
name|MachineInstr
parameter_list|(
specifier|const
name|TargetInstrDesc
modifier|&
name|TID
parameter_list|,
name|bool
name|NoImp
init|=
name|false
parameter_list|)
function_decl|;
comment|/// MachineInstr ctor - Work exactly the same as the ctor above, except that
comment|/// the MachineInstr is created and added to the end of the specified basic
comment|/// block.  The version with a DebugLoc should be preferred.
name|MachineInstr
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
specifier|const
name|TargetInstrDesc
operator|&
name|TID
argument_list|)
expr_stmt|;
comment|/// MachineInstr ctor - This constructor create a MachineInstr and add the
comment|/// implicit operands.  It reserves space for number of operands specified by
comment|/// TargetInstrDesc.  An explicit DebugLoc is supplied.
name|explicit
name|MachineInstr
parameter_list|(
specifier|const
name|TargetInstrDesc
modifier|&
name|TID
parameter_list|,
specifier|const
name|DebugLoc
name|dl
parameter_list|,
name|bool
name|NoImp
init|=
name|false
parameter_list|)
function_decl|;
comment|/// MachineInstr ctor - Work exactly the same as the ctor above, except that
comment|/// the MachineInstr is created and added to the end of the specified basic
comment|/// block.
name|MachineInstr
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|const DebugLoc dl
argument_list|,
argument|const TargetInstrDesc&TID
argument_list|)
empty_stmt|;
operator|~
name|MachineInstr
argument_list|()
expr_stmt|;
comment|// MachineInstrs are pool-allocated and owned by MachineFunction.
name|friend
name|class
name|MachineFunction
decl_stmt|;
name|public
label|:
specifier|const
name|MachineBasicBlock
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
name|MachineBasicBlock
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// getAsmPrinterFlags - Return the asm printer flags bitvector.
comment|///
name|uint8_t
name|getAsmPrinterFlags
argument_list|()
specifier|const
block|{
return|return
name|AsmPrinterFlags
return|;
block|}
comment|/// clearAsmPrinterFlags - clear the AsmPrinter bitvector
comment|///
name|void
name|clearAsmPrinterFlags
parameter_list|()
block|{
name|AsmPrinterFlags
operator|=
literal|0
expr_stmt|;
block|}
comment|/// getAsmPrinterFlag - Return whether an AsmPrinter flag is set.
comment|///
name|bool
name|getAsmPrinterFlag
argument_list|(
name|CommentFlag
name|Flag
argument_list|)
decl|const
block|{
return|return
name|AsmPrinterFlags
operator|&
name|Flag
return|;
block|}
comment|/// setAsmPrinterFlag - Set a flag for the AsmPrinter.
comment|///
name|void
name|setAsmPrinterFlag
parameter_list|(
name|CommentFlag
name|Flag
parameter_list|)
block|{
name|AsmPrinterFlags
operator||=
operator|(
name|uint8_t
operator|)
name|Flag
expr_stmt|;
block|}
comment|/// getFlags - Return the MI flags bitvector.
name|uint8_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// getFlag - Return whether an MI flag is set.
name|bool
name|getFlag
argument_list|(
name|MIFlag
name|Flag
argument_list|)
decl|const
block|{
return|return
name|Flags
operator|&
name|Flag
return|;
block|}
comment|/// setFlag - Set a MI flag.
name|void
name|setFlag
parameter_list|(
name|MIFlag
name|Flag
parameter_list|)
block|{
name|Flags
operator||=
operator|(
name|uint8_t
operator|)
name|Flag
expr_stmt|;
block|}
name|void
name|setFlags
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
name|Flags
operator|=
name|flags
expr_stmt|;
block|}
comment|/// clearAsmPrinterFlag - clear specific AsmPrinter flags
comment|///
name|void
name|clearAsmPrinterFlag
parameter_list|(
name|CommentFlag
name|Flag
parameter_list|)
block|{
name|AsmPrinterFlags
operator|&=
operator|~
name|Flag
expr_stmt|;
block|}
comment|/// getDebugLoc - Returns the debug location id of this MachineInstr.
comment|///
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|debugLoc
return|;
block|}
comment|/// getDesc - Returns the target instruction descriptor of this
comment|/// MachineInstr.
specifier|const
name|TargetInstrDesc
operator|&
name|getDesc
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TID
return|;
block|}
comment|/// getOpcode - Returns the opcode of this MachineInstr.
comment|///
name|int
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|TID
operator|->
name|Opcode
return|;
block|}
comment|/// Access to explicit operands of the instruction.
comment|///
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Operands
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|MachineOperand
modifier|&
name|getOperand
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"getOperand() out of range!"
argument_list|)
expr_stmt|;
return|return
name|Operands
index|[
name|i
index|]
return|;
block|}
name|MachineOperand
modifier|&
name|getOperand
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"getOperand() out of range!"
argument_list|)
expr_stmt|;
return|return
name|Operands
index|[
name|i
index|]
return|;
block|}
comment|/// getNumExplicitOperands - Returns the number of non-implicit operands.
comment|///
name|unsigned
name|getNumExplicitOperands
argument_list|()
specifier|const
expr_stmt|;
comment|/// iterator/begin/end - Iterate over all operands of a machine instruction.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineOperand
operator|>
operator|::
name|iterator
name|mop_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MachineOperand
operator|>
operator|::
name|const_iterator
name|const_mop_iterator
expr_stmt|;
name|mop_iterator
name|operands_begin
parameter_list|()
block|{
return|return
name|Operands
operator|.
name|begin
argument_list|()
return|;
block|}
name|mop_iterator
name|operands_end
parameter_list|()
block|{
return|return
name|Operands
operator|.
name|end
argument_list|()
return|;
block|}
name|const_mop_iterator
name|operands_begin
argument_list|()
specifier|const
block|{
return|return
name|Operands
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_mop_iterator
name|operands_end
argument_list|()
specifier|const
block|{
return|return
name|Operands
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Access to memory operands of the instruction
name|mmo_iterator
name|memoperands_begin
argument_list|()
specifier|const
block|{
return|return
name|MemRefs
return|;
block|}
name|mmo_iterator
name|memoperands_end
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
return|;
block|}
name|bool
name|memoperands_empty
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
operator|==
name|MemRefs
return|;
block|}
comment|/// hasOneMemOperand - Return true if this instruction has exactly one
comment|/// MachineMemOperand.
name|bool
name|hasOneMemOperand
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
operator|-
name|MemRefs
operator|==
literal|1
return|;
block|}
enum|enum
name|MICheckType
block|{
name|CheckDefs
block|,
comment|// Check all operands for equality
name|CheckKillDead
block|,
comment|// Check all operands including kill / dead markers
name|IgnoreDefs
block|,
comment|// Ignore all definitions
name|IgnoreVRegDefs
comment|// Ignore virtual register definitions
block|}
enum|;
comment|/// isIdenticalTo - Return true if this instruction is identical to (same
comment|/// opcode and same operands as) the specified instruction.
name|bool
name|isIdenticalTo
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|Other
argument_list|,
name|MICheckType
name|Check
operator|=
name|CheckDefs
argument_list|)
decl|const
decl_stmt|;
comment|/// removeFromParent - This method unlinks 'this' from the containing basic
comment|/// block, and returns it, but does not delete it.
name|MachineInstr
modifier|*
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing basic
comment|/// block and deletes it.
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// isLabel - Returns true if the MachineInstr represents a label.
comment|///
name|bool
name|isLabel
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|PROLOG_LABEL
operator|||
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|EH_LABEL
operator|||
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|GC_LABEL
return|;
block|}
name|bool
name|isPrologLabel
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|PROLOG_LABEL
return|;
block|}
name|bool
name|isEHLabel
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|EH_LABEL
return|;
block|}
name|bool
name|isGCLabel
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|GC_LABEL
return|;
block|}
name|bool
name|isDebugValue
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|DBG_VALUE
return|;
block|}
name|bool
name|isPHI
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|PHI
return|;
block|}
name|bool
name|isKill
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|KILL
return|;
block|}
name|bool
name|isImplicitDef
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|IMPLICIT_DEF
return|;
block|}
name|bool
name|isInlineAsm
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|INLINEASM
return|;
block|}
name|bool
name|isStackAligningInlineAsm
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isInsertSubreg
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|INSERT_SUBREG
return|;
block|}
name|bool
name|isSubregToReg
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|SUBREG_TO_REG
return|;
block|}
name|bool
name|isRegSequence
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|REG_SEQUENCE
return|;
block|}
name|bool
name|isCopy
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|COPY
return|;
block|}
comment|/// isCopyLike - Return true if the instruction behaves like a copy.
comment|/// This does not include native copy instructions.
name|bool
name|isCopyLike
argument_list|()
specifier|const
block|{
return|return
name|isCopy
argument_list|()
operator|||
name|isSubregToReg
argument_list|()
return|;
block|}
comment|/// isIdentityCopy - Return true is the instruction is an identity copy.
name|bool
name|isIdentityCopy
argument_list|()
specifier|const
block|{
return|return
name|isCopy
argument_list|()
operator|&&
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getReg
argument_list|()
operator|==
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|getReg
argument_list|()
operator|&&
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getSubReg
argument_list|()
operator|==
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|getSubReg
argument_list|()
return|;
block|}
comment|/// readsRegister - Return true if the MachineInstr reads the specified
comment|/// register. If TargetRegisterInfo is passed, then it also checks if there
comment|/// is a read of a super-register.
comment|/// This does not count partial redefines of virtual registers as reads:
comment|///   %reg1024:6 = OP.
name|bool
name|readsRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterUseOperandIdx
argument_list|(
name|Reg
argument_list|,
name|false
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// readsVirtualRegister - Return true if the MachineInstr reads the specified
comment|/// virtual register. Take into account that a partial define is a
comment|/// read-modify-write operation.
name|bool
name|readsVirtualRegister
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|readsWritesVirtualRegister
argument_list|(
name|Reg
argument_list|)
operator|.
name|first
return|;
block|}
comment|/// readsWritesVirtualRegister - Return a pair of bools (reads, writes)
comment|/// indicating if this instruction reads or writes Reg. This also considers
comment|/// partial defines.
comment|/// If Ops is not null, all operand indices for Reg are added.
name|std
operator|::
name|pair
operator|<
name|bool
operator|,
name|bool
operator|>
name|readsWritesVirtualRegister
argument_list|(
argument|unsigned Reg
argument_list|,
argument|SmallVectorImpl<unsigned> *Ops =
literal|0
argument_list|)
specifier|const
expr_stmt|;
comment|/// killsRegister - Return true if the MachineInstr kills the specified
comment|/// register. If TargetRegisterInfo is passed, then it also checks if there is
comment|/// a kill of a super-register.
name|bool
name|killsRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterUseOperandIdx
argument_list|(
name|Reg
argument_list|,
name|true
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// definesRegister - Return true if the MachineInstr fully defines the
comment|/// specified register. If TargetRegisterInfo is passed, then it also checks
comment|/// if there is a def of a super-register.
comment|/// NOTE: It's ignoring subreg indices on virtual registers.
name|bool
name|definesRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// modifiesRegister - Return true if the MachineInstr modifies (fully define
comment|/// or partially define) the specified register.
comment|/// NOTE: It's ignoring subreg indices on virtual registers.
name|bool
name|modifiesRegister
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
block|{
return|return
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|false
argument_list|,
name|true
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// registerDefIsDead - Returns true if the register is dead in this machine
comment|/// instruction. If TargetRegisterInfo is passed, then it also checks
comment|/// if there is a dead def of a super-register.
name|bool
name|registerDefIsDead
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
block|{
return|return
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|true
argument_list|,
name|false
argument_list|,
name|TRI
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// findRegisterUseOperandIdx() - Returns the operand index that is a use of
comment|/// the specific register or -1 if it is not found. It further tightens
comment|/// the search criteria to a use that kills the register if isKill is true.
name|int
name|findRegisterUseOperandIdx
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|bool
name|isKill
operator|=
name|false
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|/// findRegisterUseOperand - Wrapper for findRegisterUseOperandIdx, it returns
comment|/// a pointer to the MachineOperand rather than an index.
name|MachineOperand
modifier|*
name|findRegisterUseOperand
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isKill
init|=
name|false
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|NULL
parameter_list|)
block|{
name|int
name|Idx
init|=
name|findRegisterUseOperandIdx
argument_list|(
name|Reg
argument_list|,
name|isKill
argument_list|,
name|TRI
argument_list|)
decl_stmt|;
return|return
operator|(
name|Idx
operator|==
operator|-
literal|1
operator|)
condition|?
name|NULL
else|:
operator|&
name|getOperand
argument_list|(
name|Idx
argument_list|)
return|;
block|}
comment|/// findRegisterDefOperandIdx() - Returns the operand index that is a def of
comment|/// the specified register or -1 if it is not found. If isDead is true, defs
comment|/// that are not dead are skipped. If Overlap is true, then it also looks for
comment|/// defs that merely overlap the specified register. If TargetRegisterInfo is
comment|/// non-null, then it also checks if there is a def of a super-register.
name|int
name|findRegisterDefOperandIdx
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|bool
name|isDead
operator|=
name|false
argument_list|,
name|bool
name|Overlap
operator|=
name|false
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|/// findRegisterDefOperand - Wrapper for findRegisterDefOperandIdx, it returns
comment|/// a pointer to the MachineOperand rather than an index.
name|MachineOperand
modifier|*
name|findRegisterDefOperand
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|bool
name|isDead
init|=
name|false
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|NULL
parameter_list|)
block|{
name|int
name|Idx
init|=
name|findRegisterDefOperandIdx
argument_list|(
name|Reg
argument_list|,
name|isDead
argument_list|,
name|false
argument_list|,
name|TRI
argument_list|)
decl_stmt|;
return|return
operator|(
name|Idx
operator|==
operator|-
literal|1
operator|)
condition|?
name|NULL
else|:
operator|&
name|getOperand
argument_list|(
name|Idx
argument_list|)
return|;
block|}
comment|/// findFirstPredOperandIdx() - Find the index of the first operand in the
comment|/// operand list that is used to represent the predicate. It returns -1 if
comment|/// none is found.
name|int
name|findFirstPredOperandIdx
argument_list|()
specifier|const
expr_stmt|;
comment|/// isRegTiedToUseOperand - Given the index of a register def operand,
comment|/// check if the register def is tied to a source operand, due to either
comment|/// two-address elimination or inline assembly constraints. Returns the
comment|/// first tied use operand index by reference is UseOpIdx is not null.
name|bool
name|isRegTiedToUseOperand
argument_list|(
name|unsigned
name|DefOpIdx
argument_list|,
name|unsigned
operator|*
name|UseOpIdx
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// isRegTiedToDefOperand - Return true if the use operand of the specified
comment|/// index is tied to an def operand. It also returns the def operand index by
comment|/// reference if DefOpIdx is not null.
name|bool
name|isRegTiedToDefOperand
argument_list|(
name|unsigned
name|UseOpIdx
argument_list|,
name|unsigned
operator|*
name|DefOpIdx
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// clearKillInfo - Clears kill flags on all operands.
comment|///
name|void
name|clearKillInfo
parameter_list|()
function_decl|;
comment|/// copyKillDeadInfo - Copies kill / dead operand properties from MI.
comment|///
name|void
name|copyKillDeadInfo
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// copyPredicates - Copies predicate operand(s) from MI.
name|void
name|copyPredicates
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// substituteRegister - Replace all occurrences of FromReg with ToReg:SubIdx,
comment|/// properly composing subreg indices where necessary.
name|void
name|substituteRegister
parameter_list|(
name|unsigned
name|FromReg
parameter_list|,
name|unsigned
name|ToReg
parameter_list|,
name|unsigned
name|SubIdx
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|&
name|RegInfo
parameter_list|)
function_decl|;
comment|/// addRegisterKilled - We have determined MI kills a register. Look for the
comment|/// operand that uses it and mark it as IsKill. If AddIfNotFound is true,
comment|/// add a implicit operand if it's not found. Returns true if the operand
comment|/// exists / is added.
name|bool
name|addRegisterKilled
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|RegInfo
parameter_list|,
name|bool
name|AddIfNotFound
init|=
name|false
parameter_list|)
function_decl|;
comment|/// addRegisterDead - We have determined MI defined a register without a use.
comment|/// Look for the operand that defines it and mark it as IsDead. If
comment|/// AddIfNotFound is true, add a implicit operand if it's not found. Returns
comment|/// true if the operand exists / is added.
name|bool
name|addRegisterDead
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|RegInfo
parameter_list|,
name|bool
name|AddIfNotFound
init|=
name|false
parameter_list|)
function_decl|;
comment|/// addRegisterDefined - We have determined MI defines a register. Make sure
comment|/// there is an operand defining Reg.
name|void
name|addRegisterDefined
parameter_list|(
name|unsigned
name|IncomingReg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|RegInfo
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// setPhysRegsDeadExcept - Mark every physreg used by this instruction as
comment|/// dead except those in the UsedRegs list.
name|void
name|setPhysRegsDeadExcept
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|UsedRegs
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl_stmt|;
comment|/// isSafeToMove - Return true if it is safe to move this instruction. If
comment|/// SawStore is set to true, it means that there is a store (or call) between
comment|/// the instruction's location and its intended destination.
name|bool
name|isSafeToMove
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|,
name|bool
operator|&
name|SawStore
argument_list|)
decl|const
decl_stmt|;
comment|/// isSafeToReMat - Return true if it's safe to rematerialize the specified
comment|/// instruction which defined the specified register instead of copying it.
name|bool
name|isSafeToReMat
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|,
name|unsigned
name|DstReg
argument_list|)
decl|const
decl_stmt|;
comment|/// hasVolatileMemoryRef - Return true if this instruction may have a
comment|/// volatile memory reference, or if the information describing the
comment|/// memory reference is not available. Return false if it is known to
comment|/// have no volatile memory references.
name|bool
name|hasVolatileMemoryRef
argument_list|()
specifier|const
expr_stmt|;
comment|/// isInvariantLoad - Return true if this instruction is loading from a
comment|/// location whose value is invariant across the function.  For example,
comment|/// loading a value from the constant pool or from the argument area of
comment|/// a function if it does not change.  This should only return true of *all*
comment|/// loads the instruction does are invariant (if it does multiple loads).
name|bool
name|isInvariantLoad
argument_list|(
name|AliasAnalysis
operator|*
name|AA
argument_list|)
decl|const
decl_stmt|;
comment|/// isConstantValuePHI - If the specified instruction is a PHI that always
comment|/// merges together the same virtual register, return the register, otherwise
comment|/// return 0.
name|unsigned
name|isConstantValuePHI
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasUnmodeledSideEffects - Return true if this instruction has side
comment|/// effects that are not modeled by mayLoad / mayStore, etc.
comment|/// For all instructions, the property is encoded in TargetInstrDesc::Flags
comment|/// (see TargetInstrDesc::hasUnmodeledSideEffects(). The only exception is
comment|/// INLINEASM instruction, in which case the side effect property is encoded
comment|/// in one of its operands (see InlineAsm::Extra_HasSideEffect).
comment|///
name|bool
name|hasUnmodeledSideEffects
argument_list|()
specifier|const
expr_stmt|;
comment|/// allDefsAreDead - Return true if all the defs of this instruction are dead.
comment|///
name|bool
name|allDefsAreDead
argument_list|()
specifier|const
expr_stmt|;
comment|/// copyImplicitOps - Copy implicit register operands from specified
comment|/// instruction to this instruction.
name|void
name|copyImplicitOps
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|//
comment|// Debugging support
comment|//
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|TargetMachine
operator|*
name|TM
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Accessors used to build up machine instructions.
comment|/// addOperand - Add the specified operand to the instruction.  If it is an
comment|/// implicit operand, it is added to the end of the operand list.  If it is
comment|/// an explicit operand it is added at the end of the explicit operand list
comment|/// (before the first implicit operand).
name|void
name|addOperand
parameter_list|(
specifier|const
name|MachineOperand
modifier|&
name|Op
parameter_list|)
function_decl|;
comment|/// setDesc - Replace the instruction descriptor (thus opcode) of
comment|/// the current instruction with a new one.
comment|///
name|void
name|setDesc
parameter_list|(
specifier|const
name|TargetInstrDesc
modifier|&
name|tid
parameter_list|)
block|{
name|TID
operator|=
operator|&
name|tid
expr_stmt|;
block|}
comment|/// setDebugLoc - Replace current source information with new such.
comment|/// Avoid using this, the constructor argument is preferable.
comment|///
name|void
name|setDebugLoc
parameter_list|(
specifier|const
name|DebugLoc
name|dl
parameter_list|)
block|{
name|debugLoc
operator|=
name|dl
expr_stmt|;
block|}
comment|/// RemoveOperand - Erase an operand  from an instruction, leaving it with one
comment|/// fewer operand than it started with.
comment|///
name|void
name|RemoveOperand
parameter_list|(
name|unsigned
name|i
parameter_list|)
function_decl|;
comment|/// addMemOperand - Add a MachineMemOperand to the machine instruction.
comment|/// This function should be used only occasionally. The setMemRefs function
comment|/// is the primary method for setting up a MachineInstr's MemRefs list.
name|void
name|addMemOperand
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|MachineMemOperand
modifier|*
name|MO
parameter_list|)
function_decl|;
comment|/// setMemRefs - Assign this MachineInstr's memory reference descriptor
comment|/// list. This does not transfer ownership.
name|void
name|setMemRefs
parameter_list|(
name|mmo_iterator
name|NewMemRefs
parameter_list|,
name|mmo_iterator
name|NewMemRefsEnd
parameter_list|)
block|{
name|MemRefs
operator|=
name|NewMemRefs
expr_stmt|;
name|MemRefsEnd
operator|=
name|NewMemRefsEnd
expr_stmt|;
block|}
name|private
label|:
comment|/// getRegInfo - If this instruction is embedded into a MachineFunction,
comment|/// return the MachineRegisterInfo object for the current function, otherwise
comment|/// return null.
name|MachineRegisterInfo
modifier|*
name|getRegInfo
parameter_list|()
function_decl|;
comment|/// addImplicitDefUseOperands - Add all implicit def and use operands to
comment|/// this instruction.
name|void
name|addImplicitDefUseOperands
parameter_list|()
function_decl|;
comment|/// RemoveRegOperandsFromUseLists - Unlink all of the register operands in
comment|/// this instruction from their respective use lists.  This requires that the
comment|/// operands already be on their use lists.
name|void
name|RemoveRegOperandsFromUseLists
parameter_list|()
function_decl|;
comment|/// AddRegOperandsToUseLists - Add all of the register operands in
comment|/// this instruction from their respective use lists.  This requires that the
comment|/// operands not be on their use lists yet.
name|void
name|AddRegOperandsToUseLists
parameter_list|(
name|MachineRegisterInfo
modifier|&
name|RegInfo
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MachineInstrExpressionTrait - Special DenseMapInfo traits to compare
end_comment

begin_comment
comment|/// MachineInstr* by *value* of the instruction rather than by pointer value.
end_comment

begin_comment
comment|/// The hashing and equality testing functions ignore definitions so this is
end_comment

begin_comment
comment|/// useful for CSE, etc.
end_comment

begin_decl_stmt
name|struct
name|MachineInstrExpressionTrait
range|:
name|DenseMapInfo
operator|<
name|MachineInstr
operator|*
operator|>
block|{
specifier|static
specifier|inline
name|MachineInstr
operator|*
name|getEmptyKey
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
specifier|inline
name|MachineInstr
operator|*
name|getTombstoneKey
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|MachineInstr
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
specifier|const
name|MachineInstr
operator|*
specifier|const
operator|&
name|MI
argument_list|)
block|;
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const MachineInstr* const&LHS
argument_list|,
argument|const MachineInstr* const&RHS
argument_list|)
block|{
if|if
condition|(
name|RHS
operator|==
name|getEmptyKey
argument_list|()
operator|||
name|RHS
operator|==
name|getTombstoneKey
argument_list|()
operator|||
name|LHS
operator|==
name|getEmptyKey
argument_list|()
operator|||
name|LHS
operator|==
name|getTombstoneKey
argument_list|()
condition|)
return|return
name|LHS
operator|==
name|RHS
return|;
return|return
name|LHS
operator|->
name|isIdenticalTo
argument_list|(
name|RHS
argument_list|,
name|MachineInstr
operator|::
name|IgnoreVRegDefs
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Debugging Support
end_comment

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineInstr
operator|&
name|MI
operator|)
block|{
name|MI
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

