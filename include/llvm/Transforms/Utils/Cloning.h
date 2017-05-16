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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AssumptionCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/ValueMapper.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|class
name|AllocaInst
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|BlockFrequencyInfo
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|CallGraph
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
name|InvokeInst
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ProfileSummaryInfo
decl_stmt|;
name|class
name|ReturnInst
decl_stmt|;
comment|/// Return an exact copy of the specified module
comment|///
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|CloneModule
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|CloneModule
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|,
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|)
expr_stmt|;
comment|/// Return a copy of the specified module. The ShouldCloneDefinition function
comment|/// controls whether a specific GlobalValue's definition is cloned. If the
comment|/// function returns false, the module copy will contain an external reference
comment|/// in place of the global definition.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|CloneModule
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|,
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|,
name|function_ref
operator|<
name|bool
argument_list|(
specifier|const
name|GlobalValue
operator|*
argument_list|)
operator|>
name|ShouldCloneDefinition
argument_list|)
expr_stmt|;
comment|/// ClonedCodeInfo - This struct can be used to capture information about code
comment|/// being cloned, while it is being cloned.
struct|struct
name|ClonedCodeInfo
block|{
comment|/// ContainsCalls - This is set to true if the cloned code contains a normal
comment|/// call instruction.
name|bool
name|ContainsCalls
init|=
name|false
decl_stmt|;
comment|/// ContainsDynamicAllocas - This is set to true if the cloned code contains
comment|/// a 'dynamic' alloca.  Dynamic allocas are allocas that are either not in
comment|/// the entry block or they are in the entry block but are not a constant
comment|/// size.
name|bool
name|ContainsDynamicAllocas
init|=
name|false
decl_stmt|;
comment|/// All cloned call sites that have operand bundles attached are appended to
comment|/// this vector.  This vector may contain nulls or undefs if some of the
comment|/// originally inserted callsites were DCE'ed after they were cloned.
name|std
operator|::
name|vector
operator|<
name|WeakTrackingVH
operator|>
name|OperandBundleCallSites
expr_stmt|;
name|ClonedCodeInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
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
comment|/// is recorded in the VMap map.
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
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VMap
parameter_list|,
specifier|const
name|Twine
modifier|&
name|NameSuffix
init|=
literal|""
parameter_list|,
name|Function
modifier|*
name|F
init|=
name|nullptr
parameter_list|,
name|ClonedCodeInfo
modifier|*
name|CodeInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// CloneFunction - Return a copy of the specified function and add it to that
comment|/// function's module.  Also, any references specified in the VMap are changed
comment|/// to refer to their mapped value instead of the original one.  If any of the
comment|/// arguments to the function are in the VMap, the arguments are deleted from
comment|/// the resultant function.  The VMap is updated to include mappings from all of
comment|/// the instructions and basicblocks in the function from their old to new
comment|/// values.  The final argument captures information about the cloned code if
comment|/// non-null.
comment|///
comment|/// VMap contains no non-identity GlobalValue mappings and debug info metadata
comment|/// will not be cloned.
comment|///
name|Function
modifier|*
name|CloneFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|VMap
parameter_list|,
name|ClonedCodeInfo
modifier|*
name|CodeInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Clone OldFunc into NewFunc, transforming the old arguments into references
comment|/// to VMap values.  Note that if NewFunc already has basic blocks, the ones
comment|/// cloned into it will be added to the end of the function.  This function
comment|/// fills in a list of return instructions, and can optionally remap types
comment|/// and/or append the specified suffix to all values cloned.
comment|///
comment|/// If ModuleLevelChanges is false, VMap contains no non-identity GlobalValue
comment|/// mappings.
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
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|,
name|bool
name|ModuleLevelChanges
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
name|nullptr
argument_list|,
name|ValueMapTypeRemapper
operator|*
name|TypeMapper
operator|=
name|nullptr
argument_list|,
name|ValueMaterializer
operator|*
name|Materializer
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|void
name|CloneAndPruneIntoFromInst
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
specifier|const
name|Instruction
operator|*
name|StartingInst
argument_list|,
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|,
name|bool
name|ModuleLevelChanges
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
name|nullptr
argument_list|)
decl_stmt|;
comment|/// CloneAndPruneFunctionInto - This works exactly like CloneFunctionInto,
comment|/// except that it does some simple constant prop and DCE on the fly.  The
comment|/// effect of this is to copy significantly less code in cases where (for
comment|/// example) a function call with constant arguments is inlined, and those
comment|/// constant arguments cause a significant amount of code in the callee to be
comment|/// dead.  Since this doesn't produce an exactly copy of the input, it can't be
comment|/// used for things like CloneFunction or CloneModule.
comment|///
comment|/// If ModuleLevelChanges is false, VMap contains no non-identity GlobalValue
comment|/// mappings.
comment|///
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
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|,
name|bool
name|ModuleLevelChanges
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
name|nullptr
argument_list|,
name|Instruction
operator|*
name|TheCall
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// InlineFunctionInfo - This class captures the data input to the
comment|/// InlineFunction call, and records the auxiliary results produced by it.
name|class
name|InlineFunctionInfo
block|{
name|public
label|:
name|explicit
name|InlineFunctionInfo
argument_list|(
name|CallGraph
operator|*
name|cg
operator|=
name|nullptr
argument_list|,
name|std
operator|::
name|function
operator|<
name|AssumptionCache
operator|&
operator|(
name|Function
operator|&
operator|)
operator|>
operator|*
name|GetAssumptionCache
operator|=
name|nullptr
argument_list|,
name|ProfileSummaryInfo
operator|*
name|PSI
operator|=
name|nullptr
argument_list|,
name|BlockFrequencyInfo
operator|*
name|CallerBFI
operator|=
name|nullptr
argument_list|,
name|BlockFrequencyInfo
operator|*
name|CalleeBFI
operator|=
name|nullptr
argument_list|)
range|:
name|CG
argument_list|(
name|cg
argument_list|)
decl_stmt|,
name|GetAssumptionCache
argument_list|(
name|GetAssumptionCache
argument_list|)
decl_stmt|,
name|PSI
argument_list|(
name|PSI
argument_list|)
decl_stmt|,
name|CallerBFI
argument_list|(
name|CallerBFI
argument_list|)
decl_stmt|,
name|CalleeBFI
argument_list|(
name|CalleeBFI
argument_list|)
block|{}
comment|/// CG - If non-null, InlineFunction will update the callgraph to reflect the
comment|/// changes it makes.
name|CallGraph
modifier|*
name|CG
decl_stmt|;
name|std
operator|::
name|function
operator|<
name|AssumptionCache
operator|&
operator|(
name|Function
operator|&
operator|)
operator|>
operator|*
name|GetAssumptionCache
expr_stmt|;
name|ProfileSummaryInfo
modifier|*
name|PSI
decl_stmt|;
name|BlockFrequencyInfo
modifier|*
name|CallerBFI
decl_stmt|,
modifier|*
name|CalleeBFI
decl_stmt|;
comment|/// StaticAllocas - InlineFunction fills this in with all static allocas that
comment|/// get copied into the caller.
name|SmallVector
operator|<
name|AllocaInst
operator|*
operator|,
literal|4
operator|>
name|StaticAllocas
expr_stmt|;
comment|/// InlinedCalls - InlineFunction fills this in with callsites that were
comment|/// inlined from the callee.  This is only filled in if CG is non-null.
name|SmallVector
operator|<
name|WeakTrackingVH
operator|,
literal|8
operator|>
name|InlinedCalls
expr_stmt|;
comment|/// All of the new call sites inlined into the caller.
comment|///
comment|/// 'InlineFunction' fills this in by scanning the inlined instructions, and
comment|/// only if CG is null. If CG is non-null, instead the value handle
comment|/// `InlinedCalls` above is used.
name|SmallVector
operator|<
name|CallSite
operator|,
literal|8
operator|>
name|InlinedCallSites
expr_stmt|;
name|void
name|reset
parameter_list|()
block|{
name|StaticAllocas
operator|.
name|clear
argument_list|()
expr_stmt|;
name|InlinedCalls
operator|.
name|clear
argument_list|()
expr_stmt|;
name|InlinedCallSites
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// InlineFunction - This function inlines the called function into the basic
comment|/// block of the caller.  This returns false if it is not possible to inline
comment|/// this call.  The program is still in a well defined state if this occurs
comment|/// though.
comment|///
comment|/// Note that this only does one level of inlining.  For example, if the
comment|/// instruction 'call B' is inlined, and 'B' calls 'C', then the call to 'C' now
comment|/// exists in the instruction stream.  Similarly this will inline a recursive
comment|/// function by one level.
comment|///
comment|/// Note that while this routine is allowed to cleanup and optimize the
comment|/// *inlined* code to minimize the actual inserted code, it must not delete
comment|/// code in the caller as users of this routine may have pointers to
comment|/// instructions in the caller that need to remain stable.
name|bool
name|InlineFunction
parameter_list|(
name|CallInst
modifier|*
name|C
parameter_list|,
name|InlineFunctionInfo
modifier|&
name|IFI
parameter_list|,
name|AAResults
modifier|*
name|CalleeAAR
init|=
name|nullptr
parameter_list|,
name|bool
name|InsertLifetime
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|InlineFunction
parameter_list|(
name|InvokeInst
modifier|*
name|II
parameter_list|,
name|InlineFunctionInfo
modifier|&
name|IFI
parameter_list|,
name|AAResults
modifier|*
name|CalleeAAR
init|=
name|nullptr
parameter_list|,
name|bool
name|InsertLifetime
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|InlineFunction
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|InlineFunctionInfo
modifier|&
name|IFI
parameter_list|,
name|AAResults
modifier|*
name|CalleeAAR
init|=
name|nullptr
parameter_list|,
name|bool
name|InsertLifetime
init|=
name|true
parameter_list|)
function_decl|;
comment|/// \brief Clones a loop \p OrigLoop.  Returns the loop and the blocks in \p
comment|/// Blocks.
comment|///
comment|/// Updates LoopInfo and DominatorTree assuming the loop is dominated by block
comment|/// \p LoopDomBB.  Insert the new blocks before block specified in \p Before.
comment|/// Note: Only innermost loops are supported.
name|Loop
modifier|*
name|cloneLoopWithPreheader
argument_list|(
name|BasicBlock
operator|*
name|Before
argument_list|,
name|BasicBlock
operator|*
name|LoopDomBB
argument_list|,
name|Loop
operator|*
name|OrigLoop
argument_list|,
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|,
specifier|const
name|Twine
operator|&
name|NameSuffix
argument_list|,
name|LoopInfo
operator|*
name|LI
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|Blocks
argument_list|)
decl_stmt|;
comment|/// \brief Remaps instructions in \p Blocks using the mapping in \p VMap.
name|void
name|remapInstructionsInBlocks
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|Blocks
argument_list|,
name|ValueToValueMapTy
operator|&
name|VMap
argument_list|)
decl_stmt|;
comment|/// Split edge between BB and PredBB and duplicate all non-Phi instructions
comment|/// from BB between its beginning and the StopAt instruction into the split
comment|/// block. Phi nodes are not duplicated, but their uses are handled correctly:
comment|/// we replace them with the uses of corresponding Phi inputs. ValueMapping
comment|/// is used to map the original instructions from BB to their newly-created
comment|/// copies. Returns the split block.
name|BasicBlock
modifier|*
name|DuplicateInstructionsInSplitBetween
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|BasicBlock
modifier|*
name|PredBB
parameter_list|,
name|Instruction
modifier|*
name|StopAt
parameter_list|,
name|ValueToValueMapTy
modifier|&
name|ValueMapping
parameter_list|)
function_decl|;
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
comment|// LLVM_TRANSFORMS_UTILS_CLONING_H
end_comment

end_unit

