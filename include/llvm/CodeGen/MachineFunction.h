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
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Annotation.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|ilist_node
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
block|{}
block|}
struct|;
name|class
name|MachineFunction
range|:
name|private
name|Annotation
block|{
specifier|const
name|Function
operator|*
name|Fn
block|;
specifier|const
name|TargetMachine
operator|&
name|Target
block|;
comment|// RegInfo - Information about each register in use in the function.
name|MachineRegisterInfo
operator|*
name|RegInfo
block|;
comment|// Used to keep track of target-specific per-machine function information for
comment|// the target implementation.
name|MachineFunctionInfo
operator|*
name|MFInfo
block|;
comment|// Keep track of objects allocated on the stack.
name|MachineFrameInfo
operator|*
name|FrameInfo
block|;
comment|// Keep track of constants which are spilled to memory
name|MachineConstantPool
operator|*
name|ConstantPool
block|;
comment|// Keep track of jump tables for switch instructions
name|MachineJumpTableInfo
operator|*
name|JumpTableInfo
block|;
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
block|;
comment|// Pool-allocate MachineFunction-lifetime and IR objects.
name|BumpPtrAllocator
name|Allocator
block|;
comment|// Allocation management for instructions in function.
name|Recycler
operator|<
name|MachineInstr
operator|>
name|InstructionRecycler
block|;
comment|// Allocation management for basic blocks in function.
name|Recycler
operator|<
name|MachineBasicBlock
operator|>
name|BasicBlockRecycler
block|;
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
name|public
label|:
name|MachineFunction
argument_list|(
specifier|const
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
comment|/// MachineFunctionInfo - Keep track of various per-function pieces of
comment|/// information for backends that would like to do so.
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// getBlockNumbered - MachineBasicBlocks are automatically numbered when they
end_comment

begin_comment
comment|/// are inserted into the machine function.  The block number for a machine
end_comment

begin_comment
comment|/// basic block can be found by using the MBB::getBlockNumber method, this
end_comment

begin_comment
comment|/// method provides the inverse mapping.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// getNumBlockIDs - Return the number of MBB ID's allocated.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// RenumberBlocks - This discards all of the MachineBasicBlock numbers and
end_comment

begin_comment
comment|/// recomputes them.  This guarantees that the MBB numbers are sequential,
end_comment

begin_comment
comment|/// dense, and match the ordering of the blocks within the function.  If a
end_comment

begin_comment
comment|/// specific MachineBasicBlock is specified, only that block and those after
end_comment

begin_comment
comment|/// it are renumbered.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// print - Print out the MachineFunction in a format suitable for debugging
end_comment

begin_comment
comment|/// to the specified stream.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|OS
argument_list|)
decl|const
block|{
if|if
condition|(
name|OS
condition|)
name|print
argument_list|(
operator|*
name|OS
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// viewCFG - This function is meant for use from the debugger.  You can just
end_comment

begin_comment
comment|/// say 'call F->viewCFG()' and a ghostview window should pop up from the
end_comment

begin_comment
comment|/// program, displaying the CFG of the current function with the code for each
end_comment

begin_comment
comment|/// basic block inside.  This depends on there being a 'dot' and 'gv' program
end_comment

begin_comment
comment|/// in your path.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|void
name|viewCFG
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// viewCFGOnly - This function is meant for use from the debugger.  It works
end_comment

begin_comment
comment|/// just like viewCFG, but it does not include the contents of basic blocks
end_comment

begin_comment
comment|/// into the nodes, just the label.  If you are only interested in the CFG
end_comment

begin_comment
comment|/// this can make the graph smaller.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|void
name|viewCFGOnly
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// dump - Print the current MachineFunction to cerr, useful for debugger use.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// construct - Allocate and initialize a MachineFunction for a given Function
end_comment

begin_comment
comment|/// and Target
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|static
name|MachineFunction
modifier|&
name|construct
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// destruct - Destroy the MachineFunction corresponding to a given Function
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|static
name|void
name|destruct
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// get - Return a handle to a MachineFunction corresponding to the given
end_comment

begin_comment
comment|/// Function.  This should not be called before "construct()" for a given
end_comment

begin_comment
comment|/// Function.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|static
name|MachineFunction
modifier|&
name|get
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Provide accessors for the MachineBasicBlock list...
end_comment

begin_typedef
typedef|typedef
name|BasicBlockListType
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|BasicBlockListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// addLiveIn - Add the specified physical register as a live-in value and
end_comment

begin_comment
comment|/// create a corresponding virtual register for it.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// BasicBlock accessor functions.
end_comment

begin_comment
comment|//
end_comment

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_function
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
end_function

begin_function
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
end_function

begin_function
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
end_function

begin_function
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
end_function

begin_function
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
end_function

begin_function
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
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Internal functions used to automatically number MachineBasicBlocks
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// getNextMBBNumber - Returns the next unique number to be assigned
end_comment

begin_comment
comment|/// to a MachineBasicBlock in this MachineFunction.
end_comment

begin_comment
comment|///
end_comment

begin_function
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
end_function

begin_comment
comment|/// removeFromMBBNumbering - Remove the specific machine basic block from our
end_comment

begin_comment
comment|/// tracker, this is only really to be used by the MachineBasicBlock
end_comment

begin_comment
comment|/// implementation.
end_comment

begin_function
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
end_function

begin_comment
comment|/// CreateMachineInstr - Allocate a new MachineInstr. Use this instead
end_comment

begin_comment
comment|/// of `new MachineInstr'.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// CloneMachineInstr - Create a new MachineInstr which is a copy of the
end_comment

begin_comment
comment|/// 'Orig' instruction, identical in all ways except the the instruction
end_comment

begin_comment
comment|/// has no parent, prev, or next.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// DeleteMachineInstr - Delete the given MachineInstr.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|DeleteMachineInstr
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CreateMachineBasicBlock - Allocate a new MachineBasicBlock. Use this
end_comment

begin_comment
comment|/// instead of `new MachineBasicBlock'.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// DeleteMachineBasicBlock - Delete the given MachineBasicBlock.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|DeleteMachineBasicBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Debug location.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// getOrCreateDebugLocID - Look up the DebugLocTuple index with the given
end_comment

begin_comment
comment|/// source file, line, and column. If none currently exists, create a new
end_comment

begin_comment
comment|/// DebugLocTuple, and insert it into the DebugIdMap.
end_comment

begin_function_decl
name|unsigned
name|getOrCreateDebugLocID
parameter_list|(
name|GlobalVariable
modifier|*
name|CompileUnit
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getDebugLocTuple - Get the DebugLocTuple for a given DebugLoc object.
end_comment

begin_decl_stmt
name|DebugLocTuple
name|getDebugLocTuple
argument_list|(
name|DebugLoc
name|DL
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDefaultDebugLoc - Get the default debug location for the machine
end_comment

begin_comment
comment|/// function.
end_comment

begin_expr_stmt
name|DebugLoc
name|getDefaultDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DefaultDebugLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setDefaultDebugLoc - Get the default debug location for the machine
end_comment

begin_comment
comment|/// function.
end_comment

begin_function
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
end_function

begin_comment
unit|};
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

