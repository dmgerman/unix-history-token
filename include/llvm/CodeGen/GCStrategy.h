begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/GCStrategy.h - Garbage collection ----------*- C++ -*-===//
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
comment|// GCStrategy coordinates code generation algorithms and implements some itself
end_comment

begin_comment
comment|// in order to generate code compatible with a target code generator as
end_comment

begin_comment
comment|// specified in a function's 'gc' attribute. Algorithms are enabled by setting
end_comment

begin_comment
comment|// flags in a subclass's constructor, and some virtual methods can be
end_comment

begin_comment
comment|// overridden.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When requested, the GCStrategy will be populated with data about each
end_comment

begin_comment
comment|// function which uses it. Specifically:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - Safe points
end_comment

begin_comment
comment|//   Garbage collection is generally only possible at certain points in code.
end_comment

begin_comment
comment|//   GCStrategy can request that the collector insert such points:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     - At and after any call to a subroutine
end_comment

begin_comment
comment|//     - Before returning from the current function
end_comment

begin_comment
comment|//     - Before backwards branches (loops)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// - Roots
end_comment

begin_comment
comment|//   When a reference to a GC-allocated object exists on the stack, it must be
end_comment

begin_comment
comment|//   stored in an alloca registered with llvm.gcoot.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This information can used to emit the metadata tables which are required by
end_comment

begin_comment
comment|// the target garbage collector runtime.
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
name|LLVM_CODEGEN_GCSTRATEGY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GCSTRATEGY_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GCMetadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GCStrategy
decl_stmt|;
comment|/// The GC strategy registry uses all the defaults from Registry.
comment|///
typedef|typedef
name|Registry
operator|<
name|GCStrategy
operator|>
name|GCRegistry
expr_stmt|;
comment|/// GCStrategy describes a garbage collector algorithm's code generation
comment|/// requirements, and provides overridable hooks for those needs which cannot
comment|/// be abstractly described.
name|class
name|GCStrategy
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GCFunctionInfo
operator|>>
name|list_type
expr_stmt|;
typedef|typedef
name|list_type
operator|::
name|iterator
name|iterator
expr_stmt|;
name|private
label|:
name|friend
name|class
name|GCModuleInfo
decl_stmt|;
specifier|const
name|Module
modifier|*
name|M
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|list_type
name|Functions
decl_stmt|;
name|protected
label|:
name|unsigned
name|NeededSafePoints
decl_stmt|;
comment|///< Bitmask of required safe points.
name|bool
name|CustomReadBarriers
decl_stmt|;
comment|///< Default is to insert loads.
name|bool
name|CustomWriteBarriers
decl_stmt|;
comment|///< Default is to insert stores.
name|bool
name|CustomRoots
decl_stmt|;
comment|///< Default is to pass through to backend.
name|bool
name|CustomSafePoints
decl_stmt|;
comment|///< Default is to use NeededSafePoints
comment|///< to find safe points.
name|bool
name|InitRoots
decl_stmt|;
comment|///< If set, roots are nulled during lowering.
name|bool
name|UsesMetadata
decl_stmt|;
comment|///< If set, backend must emit metadata tables.
name|public
label|:
name|GCStrategy
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|GCStrategy
argument_list|()
block|{}
comment|/// getName - The name of the GC strategy, for debugging.
comment|///
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getModule - The module within which the GC strategy is operating.
comment|///
specifier|const
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
operator|*
name|M
return|;
block|}
comment|/// needsSafePoitns - True if safe points of any kind are required. By
comment|//                    default, none are recorded.
name|bool
name|needsSafePoints
argument_list|()
specifier|const
block|{
return|return
name|CustomSafePoints
operator|||
name|NeededSafePoints
operator|!=
literal|0
return|;
block|}
comment|/// needsSafePoint(Kind) - True if the given kind of safe point is
comment|//                          required. By default, none are recorded.
name|bool
name|needsSafePoint
argument_list|(
name|GC
operator|::
name|PointKind
name|Kind
argument_list|)
decl|const
block|{
return|return
operator|(
name|NeededSafePoints
operator|&
literal|1
operator|<<
name|Kind
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// customWriteBarrier - By default, write barriers are replaced with simple
comment|///                      store instructions. If true, then
comment|///                      performCustomLowering must instead lower them.
name|bool
name|customWriteBarrier
argument_list|()
specifier|const
block|{
return|return
name|CustomWriteBarriers
return|;
block|}
comment|/// customReadBarrier - By default, read barriers are replaced with simple
comment|///                     load instructions. If true, then
comment|///                     performCustomLowering must instead lower them.
name|bool
name|customReadBarrier
argument_list|()
specifier|const
block|{
return|return
name|CustomReadBarriers
return|;
block|}
comment|/// customRoots - By default, roots are left for the code generator so it
comment|///               can generate a stack map. If true, then
comment|//                performCustomLowering must delete them.
name|bool
name|customRoots
argument_list|()
specifier|const
block|{
return|return
name|CustomRoots
return|;
block|}
comment|/// customSafePoints - By default, the GC analysis will find safe
comment|///                    points according to NeededSafePoints. If true,
comment|///                    then findCustomSafePoints must create them.
name|bool
name|customSafePoints
argument_list|()
specifier|const
block|{
return|return
name|CustomSafePoints
return|;
block|}
comment|/// initializeRoots - If set, gcroot intrinsics should initialize their
comment|//                    allocas to null before the first use. This is
comment|//                    necessary for most GCs and is enabled by default.
name|bool
name|initializeRoots
argument_list|()
specifier|const
block|{
return|return
name|InitRoots
return|;
block|}
comment|/// usesMetadata - If set, appropriate metadata tables must be emitted by
comment|///                the back-end (assembler, JIT, or otherwise).
name|bool
name|usesMetadata
argument_list|()
specifier|const
block|{
return|return
name|UsesMetadata
return|;
block|}
comment|/// begin/end - Iterators for function metadata.
comment|///
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Functions
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
name|Functions
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// insertFunctionMetadata - Creates metadata for a function.
comment|///
name|GCFunctionInfo
modifier|*
name|insertFunctionInfo
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// initializeCustomLowering/performCustomLowering - If any of the actions
comment|/// are set to custom, performCustomLowering must be overriden to transform
comment|/// the corresponding actions to LLVM IR. initializeCustomLowering is
comment|/// optional to override. These are the only GCStrategy methods through
comment|/// which the LLVM IR can be modified.
name|virtual
name|bool
name|initializeCustomLowering
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|)
function_decl|;
name|virtual
name|bool
name|performCustomLowering
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|virtual
name|bool
name|findCustomSafePoints
parameter_list|(
name|GCFunctionInfo
modifier|&
name|FI
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

