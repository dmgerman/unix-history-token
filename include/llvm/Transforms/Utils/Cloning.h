begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Cloning.h - Clone various parts of LLVM programs ---------*- C++ -*-===//
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
comment|// This file defines various functions that are used to clone chunks of LLVM
end_comment

begin_comment
comment|// code for various purposes.  This varies from copying whole modules into new
end_comment

begin_comment
comment|// modules, to cloning functions with different arguments, to inlining
end_comment

begin_comment
comment|// functions, to copying basic blocks to support loop unrolling or superblock
end_comment

begin_comment
comment|// formation, etc.
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
name|LLVM_TRANSFORMS_UTILS_CLONING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_CLONING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|LPPassManager
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|InvokeInst
decl_stmt|;
name|class
name|ReturnInst
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
name|class
name|Trace
decl_stmt|;
name|class
name|CallGraph
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|AllocaInst
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// CloneModule - Return an exact copy of the specified module
comment|///
name|Module
modifier|*
name|CloneModule
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|Module
modifier|*
name|CloneModule
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|)
decl_stmt|;
comment|/// ClonedCodeInfo - This struct can be used to capture information about code
comment|/// being cloned, while it is being cloned.
struct|struct
name|ClonedCodeInfo
block|{
comment|/// ContainsCalls - This is set to true if the cloned code contains a normal
comment|/// call instruction.
name|bool
name|ContainsCalls
decl_stmt|;
comment|/// ContainsUnwinds - This is set to true if the cloned code contains an
comment|/// unwind instruction.
name|bool
name|ContainsUnwinds
decl_stmt|;
comment|/// ContainsDynamicAllocas - This is set to true if the cloned code contains
comment|/// a 'dynamic' alloca.  Dynamic allocas are allocas that are either not in
comment|/// the entry block or they are in the entry block but are not a constant
comment|/// size.
name|bool
name|ContainsDynamicAllocas
decl_stmt|;
name|ClonedCodeInfo
argument_list|()
block|{
name|ContainsCalls
operator|=
name|false
expr_stmt|;
name|ContainsUnwinds
operator|=
name|false
expr_stmt|;
name|ContainsDynamicAllocas
operator|=
name|false
expr_stmt|;
block|}
block|}
struct|;
comment|/// CloneBasicBlock - Return a copy of the specified basic block, but without
comment|/// embedding the block into a particular function.  The block returned is an
comment|/// exact copy of the specified basic block, without any remapping having been
comment|/// performed.  Because of this, this is only suitable for applications where
comment|/// the basic block will be inserted into the same function that it was cloned
comment|/// from (loop unrolling would use this, for example).
comment|///
comment|/// Also, note that this function makes a direct copy of the basic block, and
comment|/// can thus produce illegal LLVM code.  In particular, it will copy any PHI
comment|/// nodes from the original block, even though there are no predecessors for the
comment|/// newly cloned block (thus, phi nodes will have to be updated).  Also, this
comment|/// block will branch to the old successors of the original block: these
comment|/// successors will have to have any PHI nodes updated to account for the new
comment|/// incoming edges.
comment|///
comment|/// The correlation between instructions in the source and result basic blocks
comment|/// is recorded in the ValueMap map.
comment|///
comment|/// If you have a particular suffix you'd like to use to add to any cloned
comment|/// names, specify it as the optional third parameter.
comment|///
comment|/// If you would like the basic block to be auto-inserted into the end of a
comment|/// function, you can specify it as the optional fourth parameter.
comment|///
comment|/// If you would like to collect additional information about the cloned
comment|/// function, you can specify a ClonedCodeInfo object with the optional fifth
comment|/// parameter.
comment|///
name|BasicBlock
modifier|*
name|CloneBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|,
specifier|const
name|char
operator|*
name|NameSuffix
operator|=
literal|""
argument_list|,
name|Function
operator|*
name|F
operator|=
literal|0
argument_list|,
name|ClonedCodeInfo
operator|*
name|CodeInfo
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// CloneLoop - Clone Loop. Clone dominator info for loop insiders. Populate
comment|/// ValueMap using old blocks to new blocks mapping.
name|Loop
modifier|*
name|CloneLoop
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|LPPassManager
operator|*
name|LPM
argument_list|,
name|LoopInfo
operator|*
name|LI
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|,
name|Pass
operator|*
name|P
argument_list|)
decl_stmt|;
comment|/// CloneFunction - Return a copy of the specified function, but without
comment|/// embedding the function into another module.  Also, any references specified
comment|/// in the ValueMap are changed to refer to their mapped value instead of the
comment|/// original one.  If any of the arguments to the function are in the ValueMap,
comment|/// the arguments are deleted from the resultant function.  The ValueMap is
comment|/// updated to include mappings from all of the instructions and basicblocks in
comment|/// the function from their old to new values.  The final argument captures
comment|/// information about the cloned code if non-null.
comment|///
name|Function
modifier|*
name|CloneFunction
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|,
name|ClonedCodeInfo
operator|*
name|CodeInfo
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// CloneFunction - Version of the function that doesn't need the ValueMap.
comment|///
specifier|inline
name|Function
modifier|*
name|CloneFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
name|ClonedCodeInfo
modifier|*
name|CodeInfo
init|=
literal|0
parameter_list|)
block|{
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|Value
operator|*
operator|>
name|ValueMap
expr_stmt|;
return|return
name|CloneFunction
argument_list|(
name|F
argument_list|,
name|ValueMap
argument_list|,
name|CodeInfo
argument_list|)
return|;
block|}
comment|/// Clone OldFunc into NewFunc, transforming the old arguments into references
comment|/// to ArgMap values.  Note that if NewFunc already has basic blocks, the ones
comment|/// cloned into it will be added to the end of the function.  This function
comment|/// fills in a list of return instructions, and can optionally append the
comment|/// specified suffix to all values cloned.
comment|///
name|void
name|CloneFunctionInto
argument_list|(
name|Function
operator|*
name|NewFunc
argument_list|,
specifier|const
name|Function
operator|*
name|OldFunc
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|,
name|SmallVectorImpl
operator|<
name|ReturnInst
operator|*
operator|>
operator|&
name|Returns
argument_list|,
specifier|const
name|char
operator|*
name|NameSuffix
operator|=
literal|""
argument_list|,
name|ClonedCodeInfo
operator|*
name|CodeInfo
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// CloneAndPruneFunctionInto - This works exactly like CloneFunctionInto,
comment|/// except that it does some simple constant prop and DCE on the fly.  The
comment|/// effect of this is to copy significantly less code in cases where (for
comment|/// example) a function call with constant arguments is inlined, and those
comment|/// constant arguments cause a significant amount of code in the callee to be
comment|/// dead.  Since this doesn't produce an exactly copy of the input, it can't be
comment|/// used for things like CloneFunction or CloneModule.
name|void
name|CloneAndPruneFunctionInto
argument_list|(
name|Function
operator|*
name|NewFunc
argument_list|,
specifier|const
name|Function
operator|*
name|OldFunc
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|,
name|SmallVectorImpl
operator|<
name|ReturnInst
operator|*
operator|>
operator|&
name|Returns
argument_list|,
specifier|const
name|char
operator|*
name|NameSuffix
operator|=
literal|""
argument_list|,
name|ClonedCodeInfo
operator|*
name|CodeInfo
operator|=
literal|0
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// InlineFunction - This function inlines the called function into the basic
comment|/// block of the caller.  This returns false if it is not possible to inline
comment|/// this call.  The program is still in a well defined state if this occurs
comment|/// though.
comment|///
comment|/// Note that this only does one level of inlining.  For example, if the
comment|/// instruction 'call B' is inlined, and 'B' calls 'C', then the call to 'C' now
comment|/// exists in the instruction stream.  Similiarly this will inline a recursive
comment|/// function by one level.
comment|///
comment|/// If a non-null callgraph pointer is provided, these functions update the
comment|/// CallGraph to represent the program after inlining.
comment|///
comment|/// If StaticAllocas is non-null, InlineFunction populates it with all of the
comment|/// static allocas that it inlines into the caller.
comment|///
name|bool
name|InlineFunction
argument_list|(
name|CallInst
operator|*
name|C
argument_list|,
name|CallGraph
operator|*
name|CG
operator|=
literal|0
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
operator|=
literal|0
argument_list|,
name|SmallVectorImpl
operator|<
name|AllocaInst
operator|*
operator|>
operator|*
name|StaticAllocas
operator|=
literal|0
argument_list|)
decl_stmt|;
name|bool
name|InlineFunction
argument_list|(
name|InvokeInst
operator|*
name|II
argument_list|,
name|CallGraph
operator|*
name|CG
operator|=
literal|0
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
operator|=
literal|0
argument_list|,
name|SmallVectorImpl
operator|<
name|AllocaInst
operator|*
operator|>
operator|*
name|StaticAllocas
operator|=
literal|0
argument_list|)
decl_stmt|;
name|bool
name|InlineFunction
argument_list|(
name|CallSite
name|CS
argument_list|,
name|CallGraph
operator|*
name|CG
operator|=
literal|0
argument_list|,
specifier|const
name|TargetData
operator|*
name|TD
operator|=
literal|0
argument_list|,
name|SmallVectorImpl
operator|<
name|AllocaInst
operator|*
operator|>
operator|*
name|StaticAllocas
operator|=
literal|0
argument_list|)
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

