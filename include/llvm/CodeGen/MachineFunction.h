begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineFunction.h --------------------------*- C++ -*-===//
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
comment|// Collect native machine code for a function.  This class contains a list of
end_comment

begin_comment
comment|// MachineBasicBlock instances that make up the current compiled function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class also contains pointers to various classes which hold
end_comment

begin_comment
comment|// target-specific information about the generated code.
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
name|LLVM_CODEGEN_MACHINEFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEFUNCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ArrayRecycler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Recycler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GCModuleInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|PseudoSourceValueManager
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetSubtargetInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
struct_decl|struct
name|MachinePointerInfo
struct_decl|;
struct_decl|struct
name|WinEHFuncInfo
struct_decl|;
name|template
operator|<
operator|>
expr|struct
name|ilist_traits
operator|<
name|MachineBasicBlock
operator|>
operator|:
name|public
name|ilist_default_traits
operator|<
name|MachineBasicBlock
operator|>
block|{
name|mutable
name|ilist_half_node
operator|<
name|MachineBasicBlock
operator|>
name|Sentinel
block|;
name|public
operator|:
comment|// FIXME: This downcast is UB. See llvm.org/PR26753.
name|LLVM_NO_SANITIZE
argument_list|(
literal|"object-size"
argument_list|)
name|MachineBasicBlock
operator|*
name|createSentinel
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|(
operator|&
name|Sentinel
operator|)
return|;
block|}
name|void
name|destroySentinel
argument_list|(
argument|MachineBasicBlock *
argument_list|)
specifier|const
block|{}
name|MachineBasicBlock
operator|*
name|provideInitialHead
argument_list|()
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
name|MachineBasicBlock
operator|*
name|ensureHead
argument_list|(
argument|MachineBasicBlock*
argument_list|)
specifier|const
block|{
return|return
name|createSentinel
argument_list|()
return|;
block|}
specifier|static
name|void
name|noteHead
argument_list|(
argument|MachineBasicBlock*
argument_list|,
argument|MachineBasicBlock*
argument_list|)
block|{}
name|void
name|addNodeToList
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
name|void
name|removeNodeFromList
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
name|void
name|deleteNode
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
name|private
operator|:
name|void
name|createNode
argument_list|(
specifier|const
name|MachineBasicBlock
operator|&
argument_list|)
block|; }
expr_stmt|;
comment|/// MachineFunctionInfo - This class can be derived from and used by targets to
comment|/// hold private target-specific information for each MachineFunction.  Objects
comment|/// of type are accessed/created with MF::getInfo and destroyed when the
comment|/// MachineFunction is destroyed.
struct|struct
name|MachineFunctionInfo
block|{
name|virtual
operator|~
name|MachineFunctionInfo
argument_list|()
expr_stmt|;
comment|/// \brief Factory function: default behavior is to call new using the
comment|/// supplied allocator.
comment|///
comment|/// This function can be overridden in a derive class.
name|template
operator|<
name|typename
name|Ty
operator|>
specifier|static
name|Ty
operator|*
name|create
argument_list|(
argument|BumpPtrAllocator&Allocator
argument_list|,
argument|MachineFunction&MF
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|Allocator.Allocate<Ty>()
argument_list|)
name|Ty
argument_list|(
name|MF
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// Properties which a MachineFunction may have at a given point in time.
comment|/// Each of these has checking code in the MachineVerifier, and passes can
comment|/// require that a property be set.
name|class
name|MachineFunctionProperties
block|{
comment|// TODO: Add MachineVerifier checks for AllVRegsAllocated
comment|// TODO: Add a way to print the properties and make more useful error messages
comment|// Possible TODO: Allow targets to extend this (perhaps by allowing the
comment|// constructor to specify the size of the bit vector)
comment|// Possible TODO: Allow requiring the negative (e.g. VRegsAllocated could be
comment|// stated as the negative of "has vregs"
name|public
label|:
comment|// The properties are stated in "positive" form; i.e. a pass could require
comment|// that the property hold, but not that it does not hold.
comment|// Property descriptions:
comment|// IsSSA: True when the machine function is in SSA form and virtual registers
comment|//  have a single def.
comment|// TracksLiveness: True when tracking register liveness accurately.
comment|//  While this property is set, register liveness information in basic block
comment|//  live-in lists and machine instruction operands (e.g. kill flags, implicit
comment|//  defs) is accurate. This means it can be used to change the code in ways
comment|//  that affect the values in registers, for example by the register
comment|//  scavenger.
comment|//  When this property is clear, liveness is no longer reliable.
comment|// AllVRegsAllocated: All virtual registers have been allocated; i.e. all
comment|//  register operands are physical registers.
name|enum
name|class
name|Property
range|:
name|unsigned
block|{
name|IsSSA
block|,
name|TracksLiveness
block|,
name|AllVRegsAllocated
block|,
name|LastProperty
block|,   }
decl_stmt|;
name|bool
name|hasProperty
argument_list|(
name|Property
name|P
argument_list|)
decl|const
block|{
return|return
name|Properties
index|[
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|P
operator|)
index|]
return|;
block|}
name|MachineFunctionProperties
modifier|&
name|set
parameter_list|(
name|Property
name|P
parameter_list|)
block|{
name|Properties
operator|.
name|set
argument_list|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|P
operator|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|MachineFunctionProperties
modifier|&
name|clear
parameter_list|(
name|Property
name|P
parameter_list|)
block|{
name|Properties
operator|.
name|reset
argument_list|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|P
operator|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|MachineFunctionProperties
modifier|&
name|set
parameter_list|(
specifier|const
name|MachineFunctionProperties
modifier|&
name|MFP
parameter_list|)
block|{
name|Properties
operator||=
name|MFP
operator|.
name|Properties
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|MachineFunctionProperties
modifier|&
name|clear
parameter_list|(
specifier|const
name|MachineFunctionProperties
modifier|&
name|MFP
parameter_list|)
block|{
name|Properties
operator|.
name|reset
argument_list|(
name|MFP
operator|.
name|Properties
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|// Returns true if all properties set in V (i.e. required by a pass) are set
comment|// in this.
name|bool
name|verifyRequiredProperties
argument_list|(
specifier|const
name|MachineFunctionProperties
operator|&
name|V
argument_list|)
decl|const
block|{
return|return
operator|!
name|V
operator|.
name|Properties
operator|.
name|test
argument_list|(
name|Properties
argument_list|)
return|;
block|}
comment|// Print the MachineFunctionProperties in human-readable form. If OnlySet is
comment|// true, only print the properties that are set.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|ROS
argument_list|,
name|bool
name|OnlySet
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|BitVector
name|Properties
init|=
name|BitVector
argument_list|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|Property
operator|::
name|LastProperty
operator|)
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
name|class
name|MachineFunction
block|{
specifier|const
name|Function
modifier|*
name|Fn
decl_stmt|;
specifier|const
name|TargetMachine
modifier|&
name|Target
decl_stmt|;
specifier|const
name|TargetSubtargetInfo
modifier|*
name|STI
decl_stmt|;
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|MachineModuleInfo
modifier|&
name|MMI
decl_stmt|;
comment|// RegInfo - Information about each register in use in the function.
name|MachineRegisterInfo
modifier|*
name|RegInfo
decl_stmt|;
comment|// Used to keep track of target-specific per-machine function information for
comment|// the target implementation.
name|MachineFunctionInfo
modifier|*
name|MFInfo
decl_stmt|;
comment|// Keep track of objects allocated on the stack.
name|MachineFrameInfo
modifier|*
name|FrameInfo
decl_stmt|;
comment|// Keep track of constants which are spilled to memory
name|MachineConstantPool
modifier|*
name|ConstantPool
decl_stmt|;
comment|// Keep track of jump tables for switch instructions
name|MachineJumpTableInfo
modifier|*
name|JumpTableInfo
decl_stmt|;
comment|// Keeps track of Windows exception handling related data. This will be null
comment|// for functions that aren't using a funclet-based EH personality.
name|WinEHFuncInfo
modifier|*
name|WinEHInfo
init|=
name|nullptr
decl_stmt|;
comment|// Function-level unique numbering for MachineBasicBlocks.  When a
comment|// MachineBasicBlock is inserted into a MachineFunction is it automatically
comment|// numbered and this vector keeps track of the mapping from ID's to MBB's.
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
name|MBBNumbering
expr_stmt|;
comment|// Pool-allocate MachineFunction-lifetime and IR objects.
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
comment|// Allocation management for instructions in function.
name|Recycler
operator|<
name|MachineInstr
operator|>
name|InstructionRecycler
expr_stmt|;
comment|// Allocation management for operand arrays on instructions.
name|ArrayRecycler
operator|<
name|MachineOperand
operator|>
name|OperandRecycler
expr_stmt|;
comment|// Allocation management for basic blocks in function.
name|Recycler
operator|<
name|MachineBasicBlock
operator|>
name|BasicBlockRecycler
expr_stmt|;
comment|// List of machine basic blocks in function
typedef|typedef
name|ilist
operator|<
name|MachineBasicBlock
operator|>
name|BasicBlockListType
expr_stmt|;
name|BasicBlockListType
name|BasicBlocks
decl_stmt|;
comment|/// FunctionNumber - This provides a unique ID for each function emitted in
comment|/// this translation unit.
comment|///
name|unsigned
name|FunctionNumber
decl_stmt|;
comment|/// Alignment - The alignment of the function.
name|unsigned
name|Alignment
decl_stmt|;
comment|/// ExposesReturnsTwice - True if the function calls setjmp or related
comment|/// functions with attribute "returns twice", but doesn't have
comment|/// the attribute itself.
comment|/// This is used to limit optimizations which cannot reason
comment|/// about the control flow of such functions.
name|bool
name|ExposesReturnsTwice
init|=
name|false
decl_stmt|;
comment|/// True if the function includes any inline assembly.
name|bool
name|HasInlineAsm
init|=
name|false
decl_stmt|;
comment|/// Current high-level properties of the IR of the function (e.g. is in SSA
comment|/// form or whether registers have been allocated)
name|MachineFunctionProperties
name|Properties
decl_stmt|;
comment|// Allocation management for pseudo source values.
name|std
operator|::
name|unique_ptr
operator|<
name|PseudoSourceValueManager
operator|>
name|PSVManager
expr_stmt|;
name|MachineFunction
argument_list|(
specifier|const
name|MachineFunction
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MachineFunction
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|MachineFunction
argument_list|(
argument|const Function *Fn
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|unsigned FunctionNum
argument_list|,
argument|MachineModuleInfo&MMI
argument_list|)
empty_stmt|;
operator|~
name|MachineFunction
argument_list|()
expr_stmt|;
name|MachineModuleInfo
operator|&
name|getMMI
argument_list|()
specifier|const
block|{
return|return
name|MMI
return|;
block|}
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Ctx
return|;
block|}
name|PseudoSourceValueManager
operator|&
name|getPSVManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PSVManager
return|;
block|}
comment|/// Return the DataLayout attached to the Module associated to this MF.
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
expr_stmt|;
comment|/// getFunction - Return the LLVM function that this machine code represents
comment|///
specifier|const
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|Fn
return|;
block|}
comment|/// getName - Return the name of the corresponding LLVM function.
comment|///
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getFunctionNumber - Return a unique ID for the current function.
comment|///
name|unsigned
name|getFunctionNumber
argument_list|()
specifier|const
block|{
return|return
name|FunctionNumber
return|;
block|}
comment|/// getTarget - Return the target machine this machine code is compiled with
comment|///
specifier|const
name|TargetMachine
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|Target
return|;
block|}
comment|/// getSubtarget - Return the subtarget for which this machine code is being
comment|/// compiled.
specifier|const
name|TargetSubtargetInfo
operator|&
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
operator|*
name|STI
return|;
block|}
name|void
name|setSubtarget
parameter_list|(
specifier|const
name|TargetSubtargetInfo
modifier|*
name|ST
parameter_list|)
block|{
name|STI
operator|=
name|ST
expr_stmt|;
block|}
comment|/// getSubtarget - This method returns a pointer to the specified type of
comment|/// TargetSubtargetInfo.  In debug builds, it verifies that the object being
comment|/// returned is of the correct type.
name|template
operator|<
name|typename
name|STC
operator|>
specifier|const
name|STC
operator|&
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
specifier|const
name|STC
operator|*
operator|>
operator|(
name|STI
operator|)
return|;
block|}
comment|/// getRegInfo - Return information about the registers currently in use.
comment|///
name|MachineRegisterInfo
modifier|&
name|getRegInfo
parameter_list|()
block|{
return|return
operator|*
name|RegInfo
return|;
block|}
specifier|const
name|MachineRegisterInfo
operator|&
name|getRegInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|RegInfo
return|;
block|}
comment|/// getFrameInfo - Return the frame info object for the current function.
comment|/// This object contains information about objects allocated on the stack
comment|/// frame of the current function in an abstract way.
comment|///
name|MachineFrameInfo
modifier|*
name|getFrameInfo
parameter_list|()
block|{
return|return
name|FrameInfo
return|;
block|}
specifier|const
name|MachineFrameInfo
operator|*
name|getFrameInfo
argument_list|()
specifier|const
block|{
return|return
name|FrameInfo
return|;
block|}
comment|/// getJumpTableInfo - Return the jump table info object for the current
comment|/// function.  This object contains information about jump tables in the
comment|/// current function.  If the current function has no jump tables, this will
comment|/// return null.
specifier|const
name|MachineJumpTableInfo
operator|*
name|getJumpTableInfo
argument_list|()
specifier|const
block|{
return|return
name|JumpTableInfo
return|;
block|}
name|MachineJumpTableInfo
modifier|*
name|getJumpTableInfo
parameter_list|()
block|{
return|return
name|JumpTableInfo
return|;
block|}
comment|/// getOrCreateJumpTableInfo - Get the JumpTableInfo for this function, if it
comment|/// does already exist, allocate one.
name|MachineJumpTableInfo
modifier|*
name|getOrCreateJumpTableInfo
parameter_list|(
name|unsigned
name|JTEntryKind
parameter_list|)
function_decl|;
comment|/// getConstantPool - Return the constant pool object for the current
comment|/// function.
comment|///
name|MachineConstantPool
modifier|*
name|getConstantPool
parameter_list|()
block|{
return|return
name|ConstantPool
return|;
block|}
specifier|const
name|MachineConstantPool
operator|*
name|getConstantPool
argument_list|()
specifier|const
block|{
return|return
name|ConstantPool
return|;
block|}
comment|/// getWinEHFuncInfo - Return information about how the current function uses
comment|/// Windows exception handling. Returns null for functions that don't use
comment|/// funclets for exception handling.
specifier|const
name|WinEHFuncInfo
operator|*
name|getWinEHFuncInfo
argument_list|()
specifier|const
block|{
return|return
name|WinEHInfo
return|;
block|}
name|WinEHFuncInfo
modifier|*
name|getWinEHFuncInfo
parameter_list|()
block|{
return|return
name|WinEHInfo
return|;
block|}
comment|/// getAlignment - Return the alignment (log2, not bytes) of the function.
comment|///
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
comment|/// setAlignment - Set the alignment (log2, not bytes) of the function.
comment|///
name|void
name|setAlignment
parameter_list|(
name|unsigned
name|A
parameter_list|)
block|{
name|Alignment
operator|=
name|A
expr_stmt|;
block|}
comment|/// ensureAlignment - Make sure the function is at least 1<< A bytes aligned.
name|void
name|ensureAlignment
parameter_list|(
name|unsigned
name|A
parameter_list|)
block|{
if|if
condition|(
name|Alignment
operator|<
name|A
condition|)
name|Alignment
operator|=
name|A
expr_stmt|;
block|}
comment|/// exposesReturnsTwice - Returns true if the function calls setjmp or
comment|/// any other similar functions with attribute "returns twice" without
comment|/// having the attribute itself.
name|bool
name|exposesReturnsTwice
argument_list|()
specifier|const
block|{
return|return
name|ExposesReturnsTwice
return|;
block|}
comment|/// setCallsSetJmp - Set a flag that indicates if there's a call to
comment|/// a "returns twice" function.
name|void
name|setExposesReturnsTwice
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|ExposesReturnsTwice
operator|=
name|B
expr_stmt|;
block|}
comment|/// Returns true if the function contains any inline assembly.
name|bool
name|hasInlineAsm
argument_list|()
specifier|const
block|{
return|return
name|HasInlineAsm
return|;
block|}
comment|/// Set a flag that indicates that the function contains inline assembly.
name|void
name|setHasInlineAsm
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|HasInlineAsm
operator|=
name|B
expr_stmt|;
block|}
comment|/// Get the function properties
specifier|const
name|MachineFunctionProperties
operator|&
name|getProperties
argument_list|()
specifier|const
block|{
return|return
name|Properties
return|;
block|}
name|MachineFunctionProperties
modifier|&
name|getProperties
parameter_list|()
block|{
return|return
name|Properties
return|;
block|}
comment|/// getInfo - Keep track of various per-function pieces of information for
comment|/// backends that would like to do so.
comment|///
name|template
operator|<
name|typename
name|Ty
operator|>
name|Ty
operator|*
name|getInfo
argument_list|()
block|{
if|if
condition|(
operator|!
name|MFInfo
condition|)
name|MFInfo
operator|=
name|Ty
operator|::
name|template
name|create
operator|<
name|Ty
operator|>
operator|(
name|Allocator
operator|,
operator|*
name|this
operator|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|Ty
operator|*
operator|>
operator|(
name|MFInfo
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|Ty
operator|>
specifier|const
name|Ty
operator|*
name|getInfo
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MachineFunction
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getInfo
operator|<
name|Ty
operator|>
operator|(
operator|)
return|;
block|}
comment|/// getBlockNumbered - MachineBasicBlocks are automatically numbered when they
comment|/// are inserted into the machine function.  The block number for a machine
comment|/// basic block can be found by using the MBB::getBlockNumber method, this
comment|/// method provides the inverse mapping.
comment|///
name|MachineBasicBlock
modifier|*
name|getBlockNumbered
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|<
name|MBBNumbering
operator|.
name|size
argument_list|()
operator|&&
literal|"Illegal block number"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|MBBNumbering
index|[
name|N
index|]
operator|&&
literal|"Block was removed from the machine function!"
argument_list|)
expr_stmt|;
return|return
name|MBBNumbering
index|[
name|N
index|]
return|;
block|}
comment|/// Should we be emitting segmented stack stuff for the function
name|bool
name|shouldSplitStack
argument_list|()
specifier|const
expr_stmt|;
comment|/// getNumBlockIDs - Return the number of MBB ID's allocated.
comment|///
name|unsigned
name|getNumBlockIDs
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|MBBNumbering
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// RenumberBlocks - This discards all of the MachineBasicBlock numbers and
comment|/// recomputes them.  This guarantees that the MBB numbers are sequential,
comment|/// dense, and match the ordering of the blocks within the function.  If a
comment|/// specific MachineBasicBlock is specified, only that block and those after
comment|/// it are renumbered.
name|void
name|RenumberBlocks
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBBFrom
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// print - Print out the MachineFunction in a format suitable for debugging
comment|/// to the specified stream.
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SlotIndexes
operator|*
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// viewCFG - This function is meant for use from the debugger.  You can just
comment|/// say 'call F->viewCFG()' and a ghostview window should pop up from the
comment|/// program, displaying the CFG of the current function with the code for each
comment|/// basic block inside.  This depends on there being a 'dot' and 'gv' program
comment|/// in your path.
comment|///
name|void
name|viewCFG
argument_list|()
specifier|const
expr_stmt|;
comment|/// viewCFGOnly - This function is meant for use from the debugger.  It works
comment|/// just like viewCFG, but it does not include the contents of basic blocks
comment|/// into the nodes, just the label.  If you are only interested in the CFG
comment|/// this can make the graph smaller.
comment|///
name|void
name|viewCFGOnly
argument_list|()
specifier|const
expr_stmt|;
comment|/// dump - Print the current MachineFunction to cerr, useful for debugger use.
comment|///
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Run the current MachineFunction through the machine code verifier, useful
comment|/// for debugger use.
comment|/// \returns true if no problems were found.
name|bool
name|verify
argument_list|(
name|Pass
operator|*
name|p
operator|=
name|nullptr
argument_list|,
specifier|const
name|char
operator|*
name|Banner
operator|=
name|nullptr
argument_list|,
name|bool
name|AbortOnError
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|// Provide accessors for the MachineBasicBlock list...
typedef|typedef
name|BasicBlockListType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|BasicBlockListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
comment|/// Support for MachineBasicBlock::getNextNode().
specifier|static
name|BasicBlockListType
name|MachineFunction
operator|::
operator|*
name|getSublistAccess
argument_list|(
argument|MachineBasicBlock *
argument_list|)
block|{
return|return
operator|&
name|MachineFunction
operator|::
name|BasicBlocks
return|;
block|}
comment|/// addLiveIn - Add the specified physical register as a live-in value and
comment|/// create a corresponding virtual register for it.
name|unsigned
name|addLiveIn
parameter_list|(
name|unsigned
name|PReg
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// BasicBlock accessor functions.
comment|//
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|end
argument_list|()
return|;
block|}
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|rend
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|rend
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|BasicBlocks
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|MachineBasicBlock
operator|&
name|front
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|front
argument_list|()
return|;
block|}
name|MachineBasicBlock
modifier|&
name|front
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|front
argument_list|()
return|;
block|}
specifier|const
name|MachineBasicBlock
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|back
argument_list|()
return|;
block|}
name|MachineBasicBlock
modifier|&
name|back
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|back
argument_list|()
return|;
block|}
name|void
name|push_back
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|push_back
argument_list|(
name|MBB
argument_list|)
expr_stmt|;
block|}
name|void
name|push_front
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|push_front
argument_list|(
name|MBB
argument_list|)
expr_stmt|;
block|}
name|void
name|insert
parameter_list|(
name|iterator
name|MBBI
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|insert
argument_list|(
name|MBBI
argument_list|,
name|MBB
argument_list|)
expr_stmt|;
block|}
name|void
name|splice
parameter_list|(
name|iterator
name|InsertPt
parameter_list|,
name|iterator
name|MBBI
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|splice
argument_list|(
name|InsertPt
argument_list|,
name|BasicBlocks
argument_list|,
name|MBBI
argument_list|)
expr_stmt|;
block|}
name|void
name|splice
parameter_list|(
name|iterator
name|InsertPt
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|splice
argument_list|(
name|InsertPt
argument_list|,
name|BasicBlocks
argument_list|,
name|MBB
argument_list|)
expr_stmt|;
block|}
name|void
name|splice
parameter_list|(
name|iterator
name|InsertPt
parameter_list|,
name|iterator
name|MBBI
parameter_list|,
name|iterator
name|MBBE
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|splice
argument_list|(
name|InsertPt
argument_list|,
name|BasicBlocks
argument_list|,
name|MBBI
argument_list|,
name|MBBE
argument_list|)
expr_stmt|;
block|}
name|void
name|remove
parameter_list|(
name|iterator
name|MBBI
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|remove
argument_list|(
name|MBBI
argument_list|)
expr_stmt|;
block|}
name|void
name|remove
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBBI
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|remove
argument_list|(
name|MBBI
argument_list|)
expr_stmt|;
block|}
name|void
name|erase
parameter_list|(
name|iterator
name|MBBI
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|erase
argument_list|(
name|MBBI
argument_list|)
expr_stmt|;
block|}
name|void
name|erase
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBBI
parameter_list|)
block|{
name|BasicBlocks
operator|.
name|erase
argument_list|(
name|MBBI
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|Comp
operator|>
name|void
name|sort
argument_list|(
argument|Comp comp
argument_list|)
block|{
name|BasicBlocks
operator|.
name|sort
argument_list|(
name|comp
argument_list|)
block|;   }
comment|//===--------------------------------------------------------------------===//
comment|// Internal functions used to automatically number MachineBasicBlocks
comment|//
comment|/// \brief Adds the MBB to the internal numbering. Returns the unique number
comment|/// assigned to the MBB.
comment|///
name|unsigned
name|addToMBBNumbering
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
block|{
name|MBBNumbering
operator|.
name|push_back
argument_list|(
name|MBB
argument_list|)
block|;
return|return
operator|(
name|unsigned
operator|)
name|MBBNumbering
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// removeFromMBBNumbering - Remove the specific machine basic block from our
comment|/// tracker, this is only really to be used by the MachineBasicBlock
comment|/// implementation.
name|void
name|removeFromMBBNumbering
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|<
name|MBBNumbering
operator|.
name|size
argument_list|()
operator|&&
literal|"Illegal basic block #"
argument_list|)
expr_stmt|;
name|MBBNumbering
index|[
name|N
index|]
operator|=
name|nullptr
expr_stmt|;
block|}
comment|/// CreateMachineInstr - Allocate a new MachineInstr. Use this instead
comment|/// of `new MachineInstr'.
comment|///
name|MachineInstr
modifier|*
name|CreateMachineInstr
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|&
name|MCID
parameter_list|,
specifier|const
name|DebugLoc
modifier|&
name|DL
parameter_list|,
name|bool
name|NoImp
init|=
name|false
parameter_list|)
function_decl|;
comment|/// CloneMachineInstr - Create a new MachineInstr which is a copy of the
comment|/// 'Orig' instruction, identical in all ways except the instruction
comment|/// has no parent, prev, or next.
comment|///
comment|/// See also TargetInstrInfo::duplicate() for target-specific fixes to cloned
comment|/// instructions.
name|MachineInstr
modifier|*
name|CloneMachineInstr
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|Orig
parameter_list|)
function_decl|;
comment|/// DeleteMachineInstr - Delete the given MachineInstr.
comment|///
name|void
name|DeleteMachineInstr
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// CreateMachineBasicBlock - Allocate a new MachineBasicBlock. Use this
comment|/// instead of `new MachineBasicBlock'.
comment|///
name|MachineBasicBlock
modifier|*
name|CreateMachineBasicBlock
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|bb
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// DeleteMachineBasicBlock - Delete the given MachineBasicBlock.
comment|///
name|void
name|DeleteMachineBasicBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
comment|/// getMachineMemOperand - Allocate a new MachineMemOperand.
comment|/// MachineMemOperands are owned by the MachineFunction and need not be
comment|/// explicitly deallocated.
name|MachineMemOperand
modifier|*
name|getMachineMemOperand
argument_list|(
name|MachinePointerInfo
name|PtrInfo
argument_list|,
name|MachineMemOperand
operator|::
name|Flags
name|f
argument_list|,
name|uint64_t
name|s
argument_list|,
name|unsigned
name|base_alignment
argument_list|,
specifier|const
name|AAMDNodes
operator|&
name|AAInfo
operator|=
name|AAMDNodes
argument_list|()
argument_list|,
specifier|const
name|MDNode
operator|*
name|Ranges
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// getMachineMemOperand - Allocate a new MachineMemOperand by copying
comment|/// an existing one, adjusting by an offset and using the given size.
comment|/// MachineMemOperands are owned by the MachineFunction and need not be
comment|/// explicitly deallocated.
name|MachineMemOperand
modifier|*
name|getMachineMemOperand
parameter_list|(
specifier|const
name|MachineMemOperand
modifier|*
name|MMO
parameter_list|,
name|int64_t
name|Offset
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
function_decl|;
typedef|typedef
name|ArrayRecycler
operator|<
name|MachineOperand
operator|>
operator|::
name|Capacity
name|OperandCapacity
expr_stmt|;
comment|/// Allocate an array of MachineOperands. This is only intended for use by
comment|/// internal MachineInstr functions.
name|MachineOperand
modifier|*
name|allocateOperandArray
parameter_list|(
name|OperandCapacity
name|Cap
parameter_list|)
block|{
return|return
name|OperandRecycler
operator|.
name|allocate
argument_list|(
name|Cap
argument_list|,
name|Allocator
argument_list|)
return|;
block|}
comment|/// Dellocate an array of MachineOperands and recycle the memory. This is
comment|/// only intended for use by internal MachineInstr functions.
comment|/// Cap must be the same capacity that was used to allocate the array.
name|void
name|deallocateOperandArray
parameter_list|(
name|OperandCapacity
name|Cap
parameter_list|,
name|MachineOperand
modifier|*
name|Array
parameter_list|)
block|{
name|OperandRecycler
operator|.
name|deallocate
argument_list|(
name|Cap
argument_list|,
name|Array
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Allocate and initialize a register mask with @p NumRegister bits.
name|uint32_t
modifier|*
name|allocateRegisterMask
parameter_list|(
name|unsigned
name|NumRegister
parameter_list|)
block|{
name|unsigned
name|Size
init|=
operator|(
name|NumRegister
operator|+
literal|31
operator|)
operator|/
literal|32
decl_stmt|;
name|uint32_t
modifier|*
name|Mask
init|=
name|Allocator
operator|.
name|Allocate
operator|<
name|uint32_t
operator|>
operator|(
name|Size
operator|)
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|Size
condition|;
operator|++
name|i
control|)
name|Mask
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|Mask
return|;
block|}
comment|/// allocateMemRefsArray - Allocate an array to hold MachineMemOperand
comment|/// pointers.  This array is owned by the MachineFunction.
name|MachineInstr
operator|::
name|mmo_iterator
name|allocateMemRefsArray
argument_list|(
argument|unsigned long Num
argument_list|)
expr_stmt|;
comment|/// extractLoadMemRefs - Allocate an array and populate it with just the
comment|/// load information from the given MachineMemOperand sequence.
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|::
name|mmo_iterator
operator|,
name|MachineInstr
operator|::
name|mmo_iterator
operator|>
name|extractLoadMemRefs
argument_list|(
argument|MachineInstr::mmo_iterator Begin
argument_list|,
argument|MachineInstr::mmo_iterator End
argument_list|)
expr_stmt|;
comment|/// extractStoreMemRefs - Allocate an array and populate it with just the
comment|/// store information from the given MachineMemOperand sequence.
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|::
name|mmo_iterator
operator|,
name|MachineInstr
operator|::
name|mmo_iterator
operator|>
name|extractStoreMemRefs
argument_list|(
argument|MachineInstr::mmo_iterator Begin
argument_list|,
argument|MachineInstr::mmo_iterator End
argument_list|)
expr_stmt|;
comment|/// Allocate a string and populate it with the given external symbol name.
specifier|const
name|char
modifier|*
name|createExternalSymbolName
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Label Manipulation.
comment|//
comment|/// getJTISymbol - Return the MCSymbol for the specified non-empty jump table.
comment|/// If isLinkerPrivate is specified, an 'l' label is returned, otherwise a
comment|/// normal 'L' label is returned.
name|MCSymbol
modifier|*
name|getJTISymbol
argument_list|(
name|unsigned
name|JTI
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|,
name|bool
name|isLinkerPrivate
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// getPICBaseSymbol - Return a function-local symbol to represent the PIC
comment|/// base.
name|MCSymbol
operator|*
name|getPICBaseSymbol
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// GraphTraits specializations for function basic block graphs (CFGs)
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Provide specializations of GraphTraits to be able to treat a
end_comment

begin_comment
comment|// machine function as a graph of machine basic blocks... these are
end_comment

begin_comment
comment|// the same as the machine basic block iterators, except that the root
end_comment

begin_comment
comment|// node is implicitly the first node of the function.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|MachineFunction
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
name|MachineBasicBlock
operator|*
operator|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|MachineFunction *F
argument_list|)
block|{
return|return
operator|&
name|F
operator|->
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|MachineFunction
operator|::
name|iterator
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
name|MachineFunction
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
name|MachineFunction
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|size
parameter_list|(
name|MachineFunction
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|size
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|MachineFunction
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|const MachineFunction *F
argument_list|)
block|{
return|return
operator|&
name|F
operator|->
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
end_comment

begin_typedef
typedef|typedef
name|MachineFunction
operator|::
name|const_iterator
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|size
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|size
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|// Provide specializations of GraphTraits to be able to treat a function as a
end_comment

begin_comment
comment|// graph of basic blocks... and to walk it in inverse order.  Inverse order for
end_comment

begin_comment
comment|// a function is considered to be when traversing the predecessor edges of a BB
end_comment

begin_comment
comment|// instead of the successor edges.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
name|MachineFunction
operator|*
operator|>
expr|>
operator|:
name|public
name|GraphTraits
operator|<
name|Inverse
operator|<
name|MachineBasicBlock
operator|*
operator|>
expr|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|Inverse<MachineFunction*> G
argument_list|)
block|{
return|return
operator|&
name|G
operator|.
name|Graph
operator|->
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|MachineFunction
operator|*
operator|>
expr|>
operator|:
name|public
name|GraphTraits
operator|<
name|Inverse
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|>
expr|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|Inverse<const MachineFunction *> G
argument_list|)
block|{
return|return
operator|&
name|G
operator|.
name|Graph
operator|->
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

