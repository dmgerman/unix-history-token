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
file|"llvm/CodeGen/TargetPassConfig.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
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

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|PHINode
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
typedef|typedef
name|ValueMap
operator|<
specifier|const
name|AllocaInst
operator|*
operator|,
name|SSPLayoutKind
operator|>
name|SSPLayoutMap
expr_stmt|;
name|private
operator|:
specifier|const
name|TargetMachine
operator|*
name|TM
operator|=
name|nullptr
decl_stmt|;
comment|/// TLI - Keep a pointer of a TargetLowering to consult for determining
comment|/// target type sizes.
specifier|const
name|TargetLoweringBase
modifier|*
name|TLI
init|=
name|nullptr
decl_stmt|;
name|Triple
name|Trip
decl_stmt|;
name|Function
modifier|*
name|F
decl_stmt|;
name|Module
modifier|*
name|M
decl_stmt|;
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
comment|/// Layout - Mapping of allocations to the required SSPLayoutKind.
comment|/// StackProtector analysis will update this map when determining if an
comment|/// AllocaInst triggers a stack protector.
name|SSPLayoutMap
name|Layout
decl_stmt|;
comment|/// \brief The minimum size of buffers that will receive stack smashing
comment|/// protection when -fstack-protection is used.
name|unsigned
name|SSPBufferSize
init|=
literal|0
decl_stmt|;
comment|/// VisitedPHIs - The set of PHI nodes visited when determining
comment|/// if a variable's reference has been taken.  This set
comment|/// is maintained to ensure we don't visit the same PHI node multiple
comment|/// times.
name|SmallPtrSet
operator|<
specifier|const
name|PHINode
operator|*
operator|,
literal|16
operator|>
name|VisitedPHIs
expr_stmt|;
comment|// A prologue is generated.
name|bool
name|HasPrologue
init|=
name|false
decl_stmt|;
comment|// IR checking code is generated.
name|bool
name|HasIRCheck
init|=
name|false
decl_stmt|;
comment|/// InsertStackProtectors - Insert code into the prologue and epilogue of
comment|/// the function.
comment|///
comment|///  - The prologue code loads and stores the stack guard onto the stack.
comment|///  - The epilogue checks the value stored in the prologue against the
comment|///    original value. It calls __stack_chk_fail if they differ.
name|bool
name|InsertStackProtectors
parameter_list|()
function_decl|;
comment|/// CreateFailBB - Create a basic block to jump to when the stack protector
comment|/// check fails.
name|BasicBlock
modifier|*
name|CreateFailBB
parameter_list|()
function_decl|;
comment|/// ContainsProtectableArray - Check whether the type either is an array or
comment|/// contains an array of sufficient size so that we need stack protectors
comment|/// for it.
comment|/// \param [out] IsLarge is set to true if a protectable array is found and
comment|/// it is "large" (>= ssp-buffer-size).  In the case of a structure with
comment|/// multiple arrays, this gets set if any of them is large.
name|bool
name|ContainsProtectableArray
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|bool
operator|&
name|IsLarge
argument_list|,
name|bool
name|Strong
operator|=
name|false
argument_list|,
name|bool
name|InStruct
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check whether a stack allocation has its address taken.
name|bool
name|HasAddressTaken
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|AI
parameter_list|)
function_decl|;
comment|/// RequiresStackProtector - Check whether or not this function needs a
comment|/// stack protector based upon the stack protector level.
name|bool
name|RequiresStackProtector
parameter_list|()
function_decl|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid.
name|StackProtector
argument_list|()
operator|:
name|FunctionPass
argument_list|(
name|ID
argument_list|)
operator|,
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
block|{
name|AU
operator|.
name|addRequired
operator|<
name|TargetPassConfig
operator|>
operator|(
operator|)
block|;
name|AU
operator|.
name|addPreserved
operator|<
name|DominatorTreeWrapperPass
operator|>
operator|(
operator|)
block|;   }
name|SSPLayoutKind
name|getSSPLayout
argument_list|(
argument|const AllocaInst *AI
argument_list|)
specifier|const
expr_stmt|;
comment|// Return true if StackProtector is supposed to be handled by SelectionDAG.
name|bool
name|shouldEmitSDCheck
argument_list|(
specifier|const
name|BasicBlock
operator|&
name|BB
argument_list|)
decl|const
decl_stmt|;
name|void
name|adjustForColoring
parameter_list|(
specifier|const
name|AllocaInst
modifier|*
name|From
parameter_list|,
specifier|const
name|AllocaInst
modifier|*
name|To
parameter_list|)
function_decl|;
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|Fn
argument_list|)
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

