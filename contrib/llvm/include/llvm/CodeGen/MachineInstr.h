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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
file|"llvm/CodeGen/MachineOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ArrayRecycler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOpcodes.h"
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
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterClass
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
comment|/// This class isn't a POD type, but it must have a trivial destructor. When a
comment|/// MachineFunction is deleted, all the contained MachineInstrs are deallocated
comment|/// without having their destructor called.
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
block|,
comment|// Instruction is used as a part of
comment|// function frame setup code.
name|BundledPred
init|=
literal|1
operator|<<
literal|1
block|,
comment|// Instruction has bundled predecessors.
name|BundledSucc
init|=
literal|1
operator|<<
literal|2
comment|// Instruction has bundled successors.
block|}
enum|;
name|private
label|:
specifier|const
name|MCInstrDesc
modifier|*
name|MCID
decl_stmt|;
comment|// Instruction descriptor.
name|MachineBasicBlock
modifier|*
name|Parent
decl_stmt|;
comment|// Pointer to the owning basic block.
comment|// Operands are allocated by an ArrayRecycler.
name|MachineOperand
modifier|*
name|Operands
decl_stmt|;
comment|// Pointer to the first operand.
name|unsigned
name|NumOperands
decl_stmt|;
comment|// Number of operands on instruction.
typedef|typedef
name|ArrayRecycler
operator|<
name|MachineOperand
operator|>
operator|::
name|Capacity
name|OperandCapacity
expr_stmt|;
name|OperandCapacity
name|CapOperands
decl_stmt|;
comment|// Capacity of the Operands array.
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
name|uint8_t
name|NumMemRefs
decl_stmt|;
comment|// Information on memory references.
name|mmo_iterator
name|MemRefs
decl_stmt|;
name|DebugLoc
name|debugLoc
decl_stmt|;
comment|// Source line information.
name|MachineInstr
argument_list|(
argument|const MachineInstr&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MachineInstr
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
comment|// Use MachineFunction::DeleteMachineInstr() instead.
operator|~
name|MachineInstr
argument_list|()
name|LLVM_DELETED_FUNCTION
expr_stmt|;
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
comment|/// MachineInstr ctor - This constructor create a MachineInstr and add the
comment|/// implicit operands.  It reserves space for number of operands specified by
comment|/// MCInstrDesc.  An explicit DebugLoc is supplied.
name|MachineInstr
argument_list|(
argument|MachineFunction&
argument_list|,
argument|const MCInstrDesc&MCID
argument_list|,
argument|const DebugLoc dl
argument_list|,
argument|bool NoImp = false
argument_list|)
empty_stmt|;
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
comment|// Filter out the automatically maintained flags.
name|unsigned
name|Mask
init|=
name|BundledPred
operator||
name|BundledSucc
decl_stmt|;
name|Flags
operator|=
operator|(
name|Flags
operator|&
name|Mask
operator|)
operator||
operator|(
name|flags
operator|&
operator|~
name|Mask
operator|)
expr_stmt|;
block|}
comment|/// clearFlag - Clear a MI flag.
name|void
name|clearFlag
parameter_list|(
name|MIFlag
name|Flag
parameter_list|)
block|{
name|Flags
operator|&=
operator|~
operator|(
operator|(
name|uint8_t
operator|)
name|Flag
operator|)
expr_stmt|;
block|}
comment|/// isInsideBundle - Return true if MI is in a bundle (but not the first MI
comment|/// in a bundle).
comment|///
comment|/// A bundle looks like this before it's finalized:
comment|///   ----------------
comment|///   |      MI      |
comment|///   ----------------
comment|///          |
comment|///   ----------------
comment|///   |      MI    * |
comment|///   ----------------
comment|///          |
comment|///   ----------------
comment|///   |      MI    * |
comment|///   ----------------
comment|/// In this case, the first MI starts a bundle but is not inside a bundle, the
comment|/// next 2 MIs are considered "inside" the bundle.
comment|///
comment|/// After a bundle is finalized, it looks like this:
comment|///   ----------------
comment|///   |    Bundle    |
comment|///   ----------------
comment|///          |
comment|///   ----------------
comment|///   |      MI    * |
comment|///   ----------------
comment|///          |
comment|///   ----------------
comment|///   |      MI    * |
comment|///   ----------------
comment|///          |
comment|///   ----------------
comment|///   |      MI    * |
comment|///   ----------------
comment|/// The first instruction has the special opcode "BUNDLE". It's not "inside"
comment|/// a bundle, but the next three MIs are.
name|bool
name|isInsideBundle
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|BundledPred
argument_list|)
return|;
block|}
comment|/// isBundled - Return true if this instruction part of a bundle. This is true
comment|/// if either itself or its following instruction is marked "InsideBundle".
name|bool
name|isBundled
argument_list|()
specifier|const
block|{
return|return
name|isBundledWithPred
argument_list|()
operator|||
name|isBundledWithSucc
argument_list|()
return|;
block|}
comment|/// Return true if this instruction is part of a bundle, and it is not the
comment|/// first instruction in the bundle.
name|bool
name|isBundledWithPred
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|BundledPred
argument_list|)
return|;
block|}
comment|/// Return true if this instruction is part of a bundle, and it is not the
comment|/// last instruction in the bundle.
name|bool
name|isBundledWithSucc
argument_list|()
specifier|const
block|{
return|return
name|getFlag
argument_list|(
name|BundledSucc
argument_list|)
return|;
block|}
comment|/// Bundle this instruction with its predecessor. This can be an unbundled
comment|/// instruction, or it can be the first instruction in a bundle.
name|void
name|bundleWithPred
parameter_list|()
function_decl|;
comment|/// Bundle this instruction with its successor. This can be an unbundled
comment|/// instruction, or it can be the last instruction in a bundle.
name|void
name|bundleWithSucc
parameter_list|()
function_decl|;
comment|/// Break bundle above this instruction.
name|void
name|unbundleFromPred
parameter_list|()
function_decl|;
comment|/// Break bundle below this instruction.
name|void
name|unbundleFromSucc
parameter_list|()
function_decl|;
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
comment|/// emitError - Emit an error referring to the source location of this
comment|/// instruction. This should only be used for inline assembly that is somehow
comment|/// impossible to compile. Other errors should have been handled much
comment|/// earlier.
comment|///
comment|/// If this method returns, the caller should try to recover from the error.
comment|///
name|void
name|emitError
argument_list|(
name|StringRef
name|Msg
argument_list|)
decl|const
decl_stmt|;
comment|/// getDesc - Returns the target instruction descriptor of this
comment|/// MachineInstr.
specifier|const
name|MCInstrDesc
operator|&
name|getDesc
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MCID
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
name|MCID
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
name|NumOperands
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
name|MachineOperand
modifier|*
name|mop_iterator
typedef|;
typedef|typedef
specifier|const
name|MachineOperand
modifier|*
name|const_mop_iterator
typedef|;
name|mop_iterator
name|operands_begin
parameter_list|()
block|{
return|return
name|Operands
return|;
block|}
name|mop_iterator
name|operands_end
parameter_list|()
block|{
return|return
name|Operands
operator|+
name|NumOperands
return|;
block|}
name|const_mop_iterator
name|operands_begin
argument_list|()
specifier|const
block|{
return|return
name|Operands
return|;
block|}
name|const_mop_iterator
name|operands_end
argument_list|()
specifier|const
block|{
return|return
name|Operands
operator|+
name|NumOperands
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
name|MemRefs
operator|+
name|NumMemRefs
return|;
block|}
name|bool
name|memoperands_empty
argument_list|()
specifier|const
block|{
return|return
name|NumMemRefs
operator|==
literal|0
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
name|NumMemRefs
operator|==
literal|1
return|;
block|}
comment|/// API for querying MachineInstr properties. They are the same as MCInstrDesc
comment|/// queries but they are bundle aware.
enum|enum
name|QueryType
block|{
name|IgnoreBundle
block|,
comment|// Ignore bundles
name|AnyInBundle
block|,
comment|// Return true if any instruction in bundle has property
name|AllInBundle
comment|// Return true if all instructions in bundle have property
block|}
enum|;
comment|/// hasProperty - Return true if the instruction (or in the case of a bundle,
comment|/// the instructions inside the bundle) has the specified property.
comment|/// The first argument is the property being queried.
comment|/// The second argument indicates whether the query should look inside
comment|/// instruction bundles.
name|bool
name|hasProperty
argument_list|(
name|unsigned
name|MCFlag
argument_list|,
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
comment|// Inline the fast path for unbundled or bundle-internal instructions.
if|if
condition|(
name|Type
operator|==
name|IgnoreBundle
operator|||
operator|!
name|isBundled
argument_list|()
operator|||
name|isBundledWithPred
argument_list|()
condition|)
return|return
name|getDesc
argument_list|()
operator|.
name|getFlags
argument_list|()
operator|&
operator|(
literal|1
operator|<<
name|MCFlag
operator|)
return|;
comment|// If this is the first instruction in a bundle, take the slow path.
return|return
name|hasPropertyInBundle
argument_list|(
literal|1
operator|<<
name|MCFlag
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isVariadic - Return true if this instruction can have a variable number of
comment|/// operands.  In this case, the variable operands will be after the normal
comment|/// operands but before the implicit definitions and uses (if any are
comment|/// present).
name|bool
name|isVariadic
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Variadic
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// hasOptionalDef - Set if this instruction has an optional definition, e.g.
comment|/// ARM instructions which can set condition code if 's' bit is set.
name|bool
name|hasOptionalDef
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|HasOptionalDef
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isPseudo - Return true if this is a pseudo instruction that doesn't
comment|/// correspond to a real machine instruction.
comment|///
name|bool
name|isPseudo
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Pseudo
argument_list|,
name|Type
argument_list|)
return|;
block|}
name|bool
name|isReturn
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Return
argument_list|,
name|Type
argument_list|)
return|;
block|}
name|bool
name|isCall
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Call
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isBarrier - Returns true if the specified instruction stops control flow
comment|/// from executing the instruction immediately following it.  Examples include
comment|/// unconditional branches and return instructions.
name|bool
name|isBarrier
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Barrier
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isTerminator - Returns true if this instruction part of the terminator for
comment|/// a basic block.  Typically this is things like return and branch
comment|/// instructions.
comment|///
comment|/// Various passes use this to insert code into the bottom of a basic block,
comment|/// but before control flow occurs.
name|bool
name|isTerminator
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Terminator
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isBranch - Returns true if this is a conditional, unconditional, or
comment|/// indirect branch.  Predicates below can be used to discriminate between
comment|/// these cases, and the TargetInstrInfo::AnalyzeBranch method can be used to
comment|/// get more information.
name|bool
name|isBranch
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Branch
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isIndirectBranch - Return true if this is an indirect branch, such as a
comment|/// branch through a register.
name|bool
name|isIndirectBranch
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|IndirectBranch
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isConditionalBranch - Return true if this is a branch which may fall
comment|/// through to the next instruction or may transfer control flow to some other
comment|/// block.  The TargetInstrInfo::AnalyzeBranch method can be used to get more
comment|/// information about this branch.
name|bool
name|isConditionalBranch
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|isBranch
argument_list|(
name|Type
argument_list|)
operator|&
operator|!
name|isBarrier
argument_list|(
name|Type
argument_list|)
operator|&
operator|!
name|isIndirectBranch
argument_list|(
name|Type
argument_list|)
return|;
block|}
comment|/// isUnconditionalBranch - Return true if this is a branch which always
comment|/// transfers control flow to some other block.  The
comment|/// TargetInstrInfo::AnalyzeBranch method can be used to get more information
comment|/// about this branch.
name|bool
name|isUnconditionalBranch
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|isBranch
argument_list|(
name|Type
argument_list|)
operator|&
name|isBarrier
argument_list|(
name|Type
argument_list|)
operator|&
operator|!
name|isIndirectBranch
argument_list|(
name|Type
argument_list|)
return|;
block|}
comment|/// Return true if this instruction has a predicate operand that
comment|/// controls execution.  It may be set to 'always', or may be set to other
comment|/// values.   There are various methods in TargetInstrInfo that can be used to
comment|/// control and modify the predicate in this instruction.
name|bool
name|isPredicable
argument_list|(
name|QueryType
name|Type
operator|=
name|AllInBundle
argument_list|)
decl|const
block|{
comment|// If it's a bundle than all bundled instructions must be predicable for this
comment|// to return true.
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Predicable
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isCompare - Return true if this instruction is a comparison.
name|bool
name|isCompare
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Compare
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isMoveImmediate - Return true if this instruction is a move immediate
comment|/// (including conditional moves) instruction.
name|bool
name|isMoveImmediate
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|MoveImm
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isBitcast - Return true if this instruction is a bitcast instruction.
comment|///
name|bool
name|isBitcast
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Bitcast
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isSelect - Return true if this instruction is a select instruction.
comment|///
name|bool
name|isSelect
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Select
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isNotDuplicable - Return true if this instruction cannot be safely
comment|/// duplicated.  For example, if the instruction has a unique labels attached
comment|/// to it, duplicating it would cause multiple definition errors.
name|bool
name|isNotDuplicable
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|NotDuplicable
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// hasDelaySlot - Returns true if the specified instruction has a delay slot
comment|/// which must be filled by the code generator.
name|bool
name|hasDelaySlot
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|DelaySlot
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// canFoldAsLoad - Return true for instructions that can be folded as
comment|/// memory operands in other instructions. The most common use for this
comment|/// is instructions that are simple loads from memory that don't modify
comment|/// the loaded value in any way, but it can also be used for instructions
comment|/// that can be expressed as constant-pool loads, such as V_SETALLONES
comment|/// on x86, to allow them to be folded when it is beneficial.
comment|/// This should only be set on instructions that return a value in their
comment|/// only virtual register definition.
name|bool
name|canFoldAsLoad
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|FoldableAsLoad
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Side Effect Analysis
comment|//===--------------------------------------------------------------------===//
comment|/// mayLoad - Return true if this instruction could possibly read memory.
comment|/// Instructions with this flag set are not necessarily simple load
comment|/// instructions, they may load a value and modify it, for example.
name|bool
name|mayLoad
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
if|if
condition|(
name|isInlineAsm
argument_list|()
condition|)
block|{
name|unsigned
name|ExtraInfo
init|=
name|getOperand
argument_list|(
name|InlineAsm
operator|::
name|MIOp_ExtraInfo
argument_list|)
operator|.
name|getImm
argument_list|()
decl_stmt|;
if|if
condition|(
name|ExtraInfo
operator|&
name|InlineAsm
operator|::
name|Extra_MayLoad
condition|)
return|return
name|true
return|;
block|}
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|MayLoad
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// mayStore - Return true if this instruction could possibly modify memory.
comment|/// Instructions with this flag set are not necessarily simple store
comment|/// instructions, they may store a modified value based on their operands, or
comment|/// may not actually modify anything, for example.
name|bool
name|mayStore
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
if|if
condition|(
name|isInlineAsm
argument_list|()
condition|)
block|{
name|unsigned
name|ExtraInfo
init|=
name|getOperand
argument_list|(
name|InlineAsm
operator|::
name|MIOp_ExtraInfo
argument_list|)
operator|.
name|getImm
argument_list|()
decl_stmt|;
if|if
condition|(
name|ExtraInfo
operator|&
name|InlineAsm
operator|::
name|Extra_MayStore
condition|)
return|return
name|true
return|;
block|}
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|MayStore
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Flags that indicate whether an instruction can be modified by a method.
comment|//===--------------------------------------------------------------------===//
comment|/// isCommutable - Return true if this may be a 2- or 3-address
comment|/// instruction (of the form "X = op Y, Z, ..."), which produces the same
comment|/// result if Y and Z are exchanged.  If this flag is set, then the
comment|/// TargetInstrInfo::commuteInstruction method may be used to hack on the
comment|/// instruction.
comment|///
comment|/// Note that this flag may be set on instructions that are only commutable
comment|/// sometimes.  In these cases, the call to commuteInstruction will fail.
comment|/// Also note that some instructions require non-trivial modification to
comment|/// commute them.
name|bool
name|isCommutable
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Commutable
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isConvertibleTo3Addr - Return true if this is a 2-address instruction
comment|/// which can be changed into a 3-address instruction if needed.  Doing this
comment|/// transformation can be profitable in the register allocator, because it
comment|/// means that the instruction can use a 2-address form if possible, but
comment|/// degrade into a less efficient form if the source and dest register cannot
comment|/// be assigned to the same register.  For example, this allows the x86
comment|/// backend to turn a "shl reg, 3" instruction into an LEA instruction, which
comment|/// is the same speed as the shift but has bigger code size.
comment|///
comment|/// If this returns true, then the target must implement the
comment|/// TargetInstrInfo::convertToThreeAddress method for this instruction, which
comment|/// is allowed to fail if the transformation isn't valid for this specific
comment|/// instruction (e.g. shl reg, 4 on x86).
comment|///
name|bool
name|isConvertibleTo3Addr
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|ConvertibleTo3Addr
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// usesCustomInsertionHook - Return true if this instruction requires
comment|/// custom insertion support when the DAG scheduler is inserting it into a
comment|/// machine basic block.  If this is true for the instruction, it basically
comment|/// means that it is a pseudo instruction used at SelectionDAG time that is
comment|/// expanded out into magic code by the target when MachineInstrs are formed.
comment|///
comment|/// If this is true, the TargetLoweringInfo::InsertAtEndOfBasicBlock method
comment|/// is used to insert this into the MachineBasicBlock.
name|bool
name|usesCustomInsertionHook
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|UsesCustomInserter
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// hasPostISelHook - Return true if this instruction requires *adjustment*
comment|/// after instruction selection by calling a target hook. For example, this
comment|/// can be used to fill in ARM 's' optional operand depending on whether
comment|/// the conditional flag register is used.
name|bool
name|hasPostISelHook
argument_list|(
name|QueryType
name|Type
operator|=
name|IgnoreBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|HasPostISelHook
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isRematerializable - Returns true if this instruction is a candidate for
comment|/// remat.  This flag is deprecated, please don't use it anymore.  If this
comment|/// flag is set, the isReallyTriviallyReMaterializable() method is called to
comment|/// verify the instruction is really rematable.
name|bool
name|isRematerializable
argument_list|(
name|QueryType
name|Type
operator|=
name|AllInBundle
argument_list|)
decl|const
block|{
comment|// It's only possible to re-mat a bundle if all bundled instructions are
comment|// re-materializable.
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|Rematerializable
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// isAsCheapAsAMove - Returns true if this instruction has the same cost (or
comment|/// less) than a move instruction. This is useful during certain types of
comment|/// optimizations (e.g., remat during two-address conversion or machine licm)
comment|/// where we would like to remat or hoist the instruction, but not if it costs
comment|/// more than moving the instruction into the appropriate register. Note, we
comment|/// are not marking copies from and to the same register class with this flag.
name|bool
name|isAsCheapAsAMove
argument_list|(
name|QueryType
name|Type
operator|=
name|AllInBundle
argument_list|)
decl|const
block|{
comment|// Only returns true for a bundle if all bundled instructions are cheap.
comment|// FIXME: This probably requires a target hook.
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|CheapAsAMove
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// hasExtraSrcRegAllocReq - Returns true if this instruction source operands
comment|/// have special register allocation requirements that are not captured by the
comment|/// operand register classes. e.g. ARM::STRD's two source registers must be an
comment|/// even / odd pair, ARM::STM registers have to be in ascending order.
comment|/// Post-register allocation passes should not attempt to change allocations
comment|/// for sources of instructions with this flag.
name|bool
name|hasExtraSrcRegAllocReq
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|ExtraSrcRegAllocReq
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// hasExtraDefRegAllocReq - Returns true if this instruction def operands
comment|/// have special register allocation requirements that are not captured by the
comment|/// operand register classes. e.g. ARM::LDRD's two def registers must be an
comment|/// even / odd pair, ARM::LDM registers have to be in ascending order.
comment|/// Post-register allocation passes should not attempt to change allocations
comment|/// for definitions of instructions with this flag.
name|bool
name|hasExtraDefRegAllocReq
argument_list|(
name|QueryType
name|Type
operator|=
name|AnyInBundle
argument_list|)
decl|const
block|{
return|return
name|hasProperty
argument_list|(
name|MCID
operator|::
name|ExtraDefRegAllocReq
argument_list|,
name|Type
argument_list|)
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
comment|/// Unlink 'this' from the containing basic block, and return it without
comment|/// deleting it.
comment|///
comment|/// This function can not be used on bundled instructions, use
comment|/// removeFromBundle() to remove individual instructions from a bundle.
name|MachineInstr
modifier|*
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// Unlink this instruction from its basic block and return it without
comment|/// deleting it.
comment|///
comment|/// If the instruction is part of a bundle, the other instructions in the
comment|/// bundle remain bundled.
name|MachineInstr
modifier|*
name|removeFromBundle
parameter_list|()
function_decl|;
comment|/// Unlink 'this' from the containing basic block and delete it.
comment|///
comment|/// If this instruction is the header of a bundle, the whole bundle is erased.
comment|/// This function can not be used for instructions inside a bundle, use
comment|/// eraseFromBundle() to erase individual bundled instructions.
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// Unlink 'this' form its basic block and delete it.
comment|///
comment|/// If the instruction is part of a bundle, the other instructions in the
comment|/// bundle remain bundled.
name|void
name|eraseFromBundle
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
comment|/// A DBG_VALUE is indirect iff the first operand is a register and
comment|/// the second operand is an immediate.
name|bool
name|isIndirectDebugValue
argument_list|()
specifier|const
block|{
return|return
name|isDebugValue
argument_list|()
operator|&&
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|isReg
argument_list|()
operator|&&
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|isImm
argument_list|()
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
name|isMSInlineAsm
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
operator|&&
name|getInlineAsmDialect
argument_list|()
return|;
block|}
name|bool
name|isStackAligningInlineAsm
argument_list|()
specifier|const
expr_stmt|;
name|InlineAsm
operator|::
name|AsmDialect
name|getInlineAsmDialect
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
name|isBundle
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|TargetOpcode
operator|::
name|BUNDLE
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
name|bool
name|isFullCopy
argument_list|()
specifier|const
block|{
return|return
name|isCopy
argument_list|()
operator|&&
operator|!
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|getSubReg
argument_list|()
operator|&&
operator|!
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|.
name|getSubReg
argument_list|()
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
comment|/// isTransient - Return true if this is a transient instruction that is
comment|/// either very likely to be eliminated during register allocation (such as
comment|/// copy-like instructions), or if this instruction doesn't have an
comment|/// execution-time cost.
name|bool
name|isTransient
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getOpcode
argument_list|()
condition|)
block|{
default|default:
return|return
name|false
return|;
comment|// Copy-like instructions are usually eliminated during register allocation.
case|case
name|TargetOpcode
operator|::
name|PHI
case|:
case|case
name|TargetOpcode
operator|::
name|COPY
case|:
case|case
name|TargetOpcode
operator|::
name|INSERT_SUBREG
case|:
case|case
name|TargetOpcode
operator|::
name|SUBREG_TO_REG
case|:
case|case
name|TargetOpcode
operator|::
name|REG_SEQUENCE
case|:
comment|// Pseudo-instructions that don't produce any real output.
case|case
name|TargetOpcode
operator|::
name|IMPLICIT_DEF
case|:
case|case
name|TargetOpcode
operator|::
name|KILL
case|:
case|case
name|TargetOpcode
operator|::
name|PROLOG_LABEL
case|:
case|case
name|TargetOpcode
operator|::
name|EH_LABEL
case|:
case|case
name|TargetOpcode
operator|::
name|GC_LABEL
case|:
case|case
name|TargetOpcode
operator|::
name|DBG_VALUE
case|:
return|return
name|true
return|;
block|}
block|}
comment|/// Return the number of instructions inside the MI bundle, excluding the
comment|/// bundle header.
comment|///
comment|/// This is the number of instructions that MachineBasicBlock::iterator
comment|/// skips, 0 for unbundled instructions.
name|unsigned
name|getBundleSize
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// This may also return a register mask operand when Overlap is true.
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
comment|/// findInlineAsmFlagIdx() - Find the index of the flag word operand that
comment|/// corresponds to operand OpIdx on an inline asm instruction.  Returns -1 if
comment|/// getOperand(OpIdx) does not belong to an inline asm operand group.
comment|///
comment|/// If GroupNo is not NULL, it will receive the number of the operand group
comment|/// containing OpIdx.
comment|///
comment|/// The flag operand is an immediate that can be decoded with methods like
comment|/// InlineAsm::hasRegClassConstraint().
comment|///
name|int
name|findInlineAsmFlagIdx
argument_list|(
name|unsigned
name|OpIdx
argument_list|,
name|unsigned
operator|*
name|GroupNo
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// getRegClassConstraint - Compute the static register class constraint for
comment|/// operand OpIdx.  For normal instructions, this is derived from the
comment|/// MCInstrDesc.  For inline assembly it is derived from the flag words.
comment|///
comment|/// Returns NULL if the static register classs constraint cannot be
comment|/// determined.
comment|///
specifier|const
name|TargetRegisterClass
modifier|*
name|getRegClassConstraint
argument_list|(
name|unsigned
name|OpIdx
argument_list|,
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
decl|const
decl_stmt|;
comment|/// tieOperands - Add a tie between the register operands at DefIdx and
comment|/// UseIdx. The tie will cause the register allocator to ensure that the two
comment|/// operands are assigned the same physical register.
comment|///
comment|/// Tied operands are managed automatically for explicit operands in the
comment|/// MCInstrDesc. This method is for exceptional cases like inline asm.
name|void
name|tieOperands
parameter_list|(
name|unsigned
name|DefIdx
parameter_list|,
name|unsigned
name|UseIdx
parameter_list|)
function_decl|;
comment|/// findTiedOperandIdx - Given the index of a tied register operand, find the
comment|/// operand it is tied to. Defs are tied to uses and vice versa. Returns the
comment|/// index of the tied operand which must exist.
name|unsigned
name|findTiedOperandIdx
argument_list|(
name|unsigned
name|OpIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// isRegTiedToUseOperand - Given the index of a register def operand,
comment|/// check if the register def is tied to a source operand, due to either
comment|/// two-address elimination or inline assembly constraints. Returns the
comment|/// first tied use operand index by reference if UseOpIdx is not null.
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
block|{
specifier|const
name|MachineOperand
modifier|&
name|MO
init|=
name|getOperand
argument_list|(
name|DefOpIdx
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|MO
operator|.
name|isReg
argument_list|()
operator|||
operator|!
name|MO
operator|.
name|isDef
argument_list|()
operator|||
operator|!
name|MO
operator|.
name|isTied
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|UseOpIdx
condition|)
operator|*
name|UseOpIdx
operator|=
name|findTiedOperandIdx
argument_list|(
name|DefOpIdx
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
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
block|{
specifier|const
name|MachineOperand
modifier|&
name|MO
init|=
name|getOperand
argument_list|(
name|UseOpIdx
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|MO
operator|.
name|isReg
argument_list|()
operator|||
operator|!
name|MO
operator|.
name|isUse
argument_list|()
operator|||
operator|!
name|MO
operator|.
name|isTied
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|DefOpIdx
condition|)
operator|*
name|DefOpIdx
operator|=
name|findTiedOperandIdx
argument_list|(
name|UseOpIdx
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
comment|/// clearKillInfo - Clears kill flags on all operands.
comment|///
name|void
name|clearKillInfo
parameter_list|()
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
comment|/// clearRegisterKills - Clear all kill flags affecting Reg.  If RegInfo is
comment|/// provided, this includes super-register kills.
name|void
name|clearRegisterKills
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|RegInfo
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
name|Reg
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
name|Reg
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
comment|///
comment|/// On instructions with register mask operands, also add implicit-def
comment|/// operands for all registers in UsedRegs.
name|void
name|setPhysRegsDeadExcept
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
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
comment|/// hasOrderedMemoryRef - Return true if this instruction may have an ordered
comment|/// or volatile memory reference, or if the information describing the memory
comment|/// reference is not available. Return false if it is known to have no
comment|/// ordered or volatile memory references.
name|bool
name|hasOrderedMemoryRef
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
comment|/// For all instructions, the property is encoded in MCInstrDesc::Flags
comment|/// (see MCInstrDesc::hasUnmodeledSideEffects(). The only exception is
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
name|MachineFunction
modifier|&
name|MF
parameter_list|,
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
argument_list|,
name|bool
name|SkipOpers
operator|=
name|false
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
comment|/// Add the specified operand to the instruction.  If it is an implicit
comment|/// operand, it is added to the end of the operand list.  If it is an
comment|/// explicit operand it is added at the end of the explicit operand list
comment|/// (before the first implicit operand).
comment|///
comment|/// MF must be the machine function that was used to allocate this
comment|/// instruction.
comment|///
comment|/// MachineInstrBuilder provides a more convenient interface for creating
comment|/// instructions and adding operands.
name|void
name|addOperand
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
specifier|const
name|MachineOperand
modifier|&
name|Op
parameter_list|)
function_decl|;
comment|/// Add an operand without providing an MF reference. This only works for
comment|/// instructions that are inserted in a basic block.
comment|///
comment|/// MachineInstrBuilder and the two-argument addOperand(MF, MO) should be
comment|/// preferred.
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
name|MCInstrDesc
modifier|&
name|tid
parameter_list|)
block|{
name|MCID
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
name|NumMemRefs
operator|=
name|uint8_t
argument_list|(
name|NewMemRefsEnd
operator|-
name|NewMemRefs
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|NumMemRefs
operator|==
name|NewMemRefsEnd
operator|-
name|NewMemRefs
operator|&&
literal|"Too many memrefs"
argument_list|)
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
comment|/// untieRegOperand - Break any tie involving OpIdx.
name|void
name|untieRegOperand
parameter_list|(
name|unsigned
name|OpIdx
parameter_list|)
block|{
name|MachineOperand
modifier|&
name|MO
init|=
name|getOperand
argument_list|(
name|OpIdx
argument_list|)
decl_stmt|;
if|if
condition|(
name|MO
operator|.
name|isReg
argument_list|()
operator|&&
name|MO
operator|.
name|isTied
argument_list|()
condition|)
block|{
name|getOperand
argument_list|(
name|findTiedOperandIdx
argument_list|(
name|OpIdx
argument_list|)
argument_list|)
operator|.
name|TiedTo
operator|=
literal|0
expr_stmt|;
name|MO
operator|.
name|TiedTo
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/// addImplicitDefUseOperands - Add all implicit def and use operands to
comment|/// this instruction.
name|void
name|addImplicitDefUseOperands
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// RemoveRegOperandsFromUseLists - Unlink all of the register operands in
comment|/// this instruction from their respective use lists.  This requires that the
comment|/// operands already be on their use lists.
name|void
name|RemoveRegOperandsFromUseLists
parameter_list|(
name|MachineRegisterInfo
modifier|&
parameter_list|)
function_decl|;
comment|/// AddRegOperandsToUseLists - Add all of the register operands in
comment|/// this instruction from their respective use lists.  This requires that the
comment|/// operands not be on their use lists yet.
name|void
name|AddRegOperandsToUseLists
parameter_list|(
name|MachineRegisterInfo
modifier|&
parameter_list|)
function_decl|;
comment|/// hasPropertyInBundle - Slow path for hasProperty when we're dealing with a
comment|/// bundle.
name|bool
name|hasPropertyInBundle
argument_list|(
name|unsigned
name|Mask
argument_list|,
name|QueryType
name|Type
argument_list|)
decl|const
decl_stmt|;
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

