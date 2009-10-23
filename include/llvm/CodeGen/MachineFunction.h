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
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Recycler.h"
end_include

begin_include
include|#
directive|include
file|<map>
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
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
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
block|}
struct|;
name|class
name|MachineFunction
block|{
name|Function
modifier|*
name|Fn
decl_stmt|;
specifier|const
name|TargetMachine
modifier|&
name|Target
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
comment|// Default debug location. Used to print out the debug label at the beginning
comment|// of a function.
name|DebugLoc
name|DefaultDebugLoc
decl_stmt|;
comment|// Tracks debug locations.
name|DebugLocTracker
name|DebugLocInfo
decl_stmt|;
comment|// The alignment of the function.
name|unsigned
name|Alignment
decl_stmt|;
name|public
label|:
name|MachineFunction
argument_list|(
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
expr_stmt|;
operator|~
name|MachineFunction
argument_list|()
expr_stmt|;
comment|/// getFunction - Return the LLVM function that this machine code represents
comment|///
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
comment|/// function.  This object contains information about jump tables for switch
comment|/// instructions in the current function.
comment|///
name|MachineJumpTableInfo
modifier|*
name|getJumpTableInfo
parameter_list|()
block|{
return|return
name|JumpTableInfo
return|;
block|}
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
block|{
comment|// This should be just `new (Allocator.Allocate<Ty>()) Ty(*this)', but
comment|// that apparently breaks GCC 3.3.
name|Ty
modifier|*
name|Loc
init|=
name|static_cast
operator|<
name|Ty
operator|*
operator|>
operator|(
name|Allocator
operator|.
name|Allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|Ty
argument_list|)
argument_list|,
name|AlignOf
operator|<
name|Ty
operator|>
operator|::
name|Alignment
argument_list|)
operator|)
decl_stmt|;
name|MFInfo
operator|=
name|new
argument_list|(
argument|Loc
argument_list|)
name|Ty
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
block|}
name|assert
argument_list|(
operator|(
name|void
operator|*
operator|)
name|dynamic_cast
operator|<
name|Ty
operator|*
operator|>
operator|(
name|MFInfo
operator|)
operator|==
operator|(
name|void
operator|*
operator|)
name|MFInfo
operator|&&
literal|"Invalid concrete type or multiple inheritence for getInfo"
argument_list|)
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
literal|0
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
comment|//===--------------------------------------------------------------------===//
comment|// Internal functions used to automatically number MachineBasicBlocks
comment|//
comment|/// getNextMBBNumber - Returns the next unique number to be assigned
comment|/// to a MachineBasicBlock in this MachineFunction.
comment|///
name|unsigned
name|addToMBBNumbering
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
name|MBBNumbering
operator|.
name|push_back
argument_list|(
name|MBB
argument_list|)
expr_stmt|;
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
literal|0
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
name|TargetInstrDesc
modifier|&
name|TID
parameter_list|,
name|DebugLoc
name|DL
parameter_list|,
name|bool
name|NoImp
init|=
name|false
parameter_list|)
function_decl|;
comment|/// CloneMachineInstr - Create a new MachineInstr which is a copy of the
comment|/// 'Orig' instruction, identical in all ways except the the instruction
comment|/// has no parent, prev, or next.
comment|///
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
literal|0
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
parameter_list|(
specifier|const
name|Value
modifier|*
name|v
parameter_list|,
name|unsigned
name|f
parameter_list|,
name|int64_t
name|o
parameter_list|,
name|uint64_t
name|s
parameter_list|,
name|unsigned
name|base_alignment
parameter_list|)
function_decl|;
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
comment|//===--------------------------------------------------------------------===//
comment|// Debug location.
comment|//
comment|/// getDebugLocTuple - Get the DebugLocTuple for a given DebugLoc object.
name|DebugLocTuple
name|getDebugLocTuple
argument_list|(
name|DebugLoc
name|DL
argument_list|)
decl|const
decl_stmt|;
comment|/// getDefaultDebugLoc - Get the default debug location for the machine
comment|/// function.
name|DebugLoc
name|getDefaultDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DefaultDebugLoc
return|;
block|}
comment|/// setDefaultDebugLoc - Get the default debug location for the machine
comment|/// function.
name|void
name|setDefaultDebugLoc
parameter_list|(
name|DebugLoc
name|DL
parameter_list|)
block|{
name|DefaultDebugLoc
operator|=
name|DL
expr_stmt|;
block|}
comment|/// getDebugLocInfo - Get the debug info location tracker.
name|DebugLocTracker
modifier|&
name|getDebugLocInfo
parameter_list|()
block|{
return|return
name|DebugLocInfo
return|;
block|}
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

