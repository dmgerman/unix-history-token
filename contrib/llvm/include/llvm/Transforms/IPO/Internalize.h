begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====- Internalize.h - Internalization API ---------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// This pass loops over all of the functions and variables in the input module.
end_comment

begin_comment
comment|// If the function or variable does not need to be preserved according to the
end_comment

begin_comment
comment|// client supplied callback, it is marked as internal.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This transformation would not be legal in a regular compilation, but it gets
end_comment

begin_comment
comment|// extra information from the linker about what is safe.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example: Internalizing a function with external linkage. Only if we are
end_comment

begin_comment
comment|// told it is only used from within this module, it is safe to do it.
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
name|LLVM_TRANSFORMS_IPO_INTERNALIZE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_INTERNALIZE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|CallGraph
decl_stmt|;
comment|/// A pass that internalizes all functions and variables other than those that
comment|/// must be preserved according to \c MustPreserveGV.
name|class
name|InternalizePass
range|:
name|public
name|PassInfoMixin
operator|<
name|InternalizePass
operator|>
block|{
comment|/// Client supplied callback to control wheter a symbol must be preserved.
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|GlobalValue
operator|&
argument_list|)
operator|>
name|MustPreserveGV
block|;
comment|/// Set of symbols private to the compiler that this pass should not touch.
name|StringSet
operator|<
operator|>
name|AlwaysPreserved
block|;
comment|/// Return false if we're allowed to internalize this GV.
name|bool
name|shouldPreserveGV
argument_list|(
specifier|const
name|GlobalValue
operator|&
name|GV
argument_list|)
block|;
comment|/// Internalize GV if it is possible to do so, i.e. it is not externally
comment|/// visible and is not a member of an externally visible comdat.
name|bool
name|maybeInternalize
argument_list|(
name|GlobalValue
operator|&
name|GV
argument_list|,
specifier|const
name|std
operator|::
name|set
operator|<
specifier|const
name|Comdat
operator|*
operator|>
operator|&
name|ExternalComdats
argument_list|)
block|;
comment|/// If GV is part of a comdat and is externally visible, keep track of its
comment|/// comdat so that we don't internalize any of its members.
name|void
name|checkComdatVisibility
argument_list|(
name|GlobalValue
operator|&
name|GV
argument_list|,
name|std
operator|::
name|set
operator|<
specifier|const
name|Comdat
operator|*
operator|>
operator|&
name|ExternalComdats
argument_list|)
block|;
name|public
operator|:
name|InternalizePass
argument_list|()
block|;
name|InternalizePass
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|GlobalValue
operator|&
argument_list|)
operator|>
name|MustPreserveGV
argument_list|)
operator|:
name|MustPreserveGV
argument_list|(
argument|std::move(MustPreserveGV)
argument_list|)
block|{}
comment|/// Run the internalizer on \p TheModule, returns true if any changes was
comment|/// made.
comment|///
comment|/// If the CallGraph \p CG is supplied, it will be updated when
comment|/// internalizing a function (by removing any edge from the "external node")
name|bool
name|internalizeModule
argument_list|(
name|Module
operator|&
name|TheModule
argument_list|,
name|CallGraph
operator|*
name|CG
operator|=
name|nullptr
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
comment|/// Helper function to internalize functions and variables in a Module.
specifier|inline
name|bool
name|internalizeModule
argument_list|(
name|Module
operator|&
name|TheModule
argument_list|,
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|GlobalValue
operator|&
argument_list|)
operator|>
name|MustPreserveGV
argument_list|,
name|CallGraph
operator|*
name|CG
operator|=
name|nullptr
argument_list|)
block|{
return|return
name|InternalizePass
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|MustPreserveGV
argument_list|)
argument_list|)
operator|.
name|internalizeModule
argument_list|(
name|TheModule
argument_list|,
name|CG
argument_list|)
return|;
block|}
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
comment|// LLVM_TRANSFORMS_IPO_INTERNALIZE_H
end_comment

end_unit

