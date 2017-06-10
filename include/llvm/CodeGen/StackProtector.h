begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StackProtector.h - Stack Protector Insertion -------------*- C++ -*-===//
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
comment|// This pass inserts stack protectors into functions which need them. A variable
end_comment

begin_comment
comment|// with a random value in it is stored onto the stack before the local variables
end_comment

begin_comment
comment|// are allocated. Upon exiting the block, the stored value is checked. If it's
end_comment

begin_comment
comment|// changed, then there was some sort of violation and the program aborts.
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
name|LLVM_CODEGEN_STACKPROTECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_STACKPROTECTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|TargetLoweringBase
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|StackProtector
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
comment|/// SSPLayoutKind.  Stack Smashing Protection (SSP) rules require that
comment|/// vulnerable stack allocations are located close the stack protector.
expr|enum
name|SSPLayoutKind
block|{
name|SSPLK_None
block|,
comment|///< Did not trigger a stack protector.  No effect on data
comment|///< layout.
name|SSPLK_LargeArray
block|,
comment|///< Array or nested array>= SSP-buffer-size.  Closest
comment|///< to the stack protector.
name|SSPLK_SmallArray
block|,
comment|///< Array or nested array< SSP-buffer-size. 2nd closest
comment|///< to the stack protector.
name|SSPLK_AddrOf
comment|///< The address of this allocation is exposed and
comment|///< triggered protection.  3rd closest to the protector.
block|}
block|;
comment|/// A mapping of AllocaInsts to their required SSP layout.
name|using
name|SSPLayoutMap
operator|=
name|ValueMap
operator|<
specifier|const
name|AllocaInst
operator|*
block|,
name|SSPLayoutKind
operator|>
block|;
name|private
operator|:
specifier|const
name|TargetMachine
operator|*
name|TM
operator|=
name|nullptr
block|;
comment|/// TLI - Keep a pointer of a TargetLowering to consult for determining
comment|/// target type sizes.
specifier|const
name|TargetLoweringBase
operator|*
name|TLI
operator|=
name|nullptr
block|;
name|Triple
name|Trip
block|;
name|Function
operator|*
name|F
block|;
name|Module
operator|*
name|M
block|;
name|DominatorTree
operator|*
name|DT
block|;
comment|/// Layout - Mapping of allocations to the required SSPLayoutKind.
comment|/// StackProtector analysis will update this map when determining if an
comment|/// AllocaInst triggers a stack protector.
name|SSPLayoutMap
name|Layout
block|;
comment|/// \brief The minimum size of buffers that will receive stack smashing
comment|/// protection when -fstack-protection is used.
name|unsigned
name|SSPBufferSize
operator|=
literal|0
block|;
comment|/// VisitedPHIs - The set of PHI nodes visited when determining
comment|/// if a variable's reference has been taken.  This set
comment|/// is maintained to ensure we don't visit the same PHI node multiple
comment|/// times.
name|SmallPtrSet
operator|<
specifier|const
name|PHINode
operator|*
block|,
literal|16
operator|>
name|VisitedPHIs
block|;
comment|// A prologue is generated.
name|bool
name|HasPrologue
operator|=
name|false
block|;
comment|// IR checking code is generated.
name|bool
name|HasIRCheck
operator|=
name|false
block|;
comment|/// InsertStackProtectors - Insert code into the prologue and epilogue of
comment|/// the function.
comment|///
comment|///  - The prologue code loads and stores the stack guard onto the stack.
comment|///  - The epilogue checks the value stored in the prologue against the
comment|///    original value. It calls __stack_chk_fail if they differ.
name|bool
name|InsertStackProtectors
argument_list|()
block|;
comment|/// CreateFailBB - Create a basic block to jump to when the stack protector
comment|/// check fails.
name|BasicBlock
operator|*
name|CreateFailBB
argument_list|()
block|;
comment|/// ContainsProtectableArray - Check whether the type either is an array or
comment|/// contains an array of sufficient size so that we need stack protectors
comment|/// for it.
comment|/// \param [out] IsLarge is set to true if a protectable array is found and
comment|/// it is "large" (>= ssp-buffer-size).  In the case of a structure with
comment|/// multiple arrays, this gets set if any of them is large.
name|bool
name|ContainsProtectableArray
argument_list|(
argument|Type *Ty
argument_list|,
argument|bool&IsLarge
argument_list|,
argument|bool Strong = false
argument_list|,
argument|bool InStruct = false
argument_list|)
specifier|const
block|;
comment|/// \brief Check whether a stack allocation has its address taken.
name|bool
name|HasAddressTaken
argument_list|(
specifier|const
name|Instruction
operator|*
name|AI
argument_list|)
block|;
comment|/// RequiresStackProtector - Check whether or not this function needs a
comment|/// stack protector based upon the stack protector level.
name|bool
name|RequiresStackProtector
argument_list|()
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid.
name|StackProtector
argument_list|()
operator|:
name|FunctionPass
argument_list|(
name|ID
argument_list|)
block|,
name|SSPBufferSize
argument_list|(
literal|8
argument_list|)
block|{
name|initializeStackProtectorPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|SSPLayoutKind
name|getSSPLayout
argument_list|(
argument|const AllocaInst *AI
argument_list|)
specifier|const
block|;
comment|// Return true if StackProtector is supposed to be handled by SelectionDAG.
name|bool
name|shouldEmitSDCheck
argument_list|(
argument|const BasicBlock&BB
argument_list|)
specifier|const
block|;
name|void
name|adjustForColoring
argument_list|(
specifier|const
name|AllocaInst
operator|*
name|From
argument_list|,
specifier|const
name|AllocaInst
operator|*
name|To
argument_list|)
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&Fn
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_STACKPROTECTOR_H
end_comment

end_unit

