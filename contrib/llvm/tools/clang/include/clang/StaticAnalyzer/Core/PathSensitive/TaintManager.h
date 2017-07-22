begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== TaintManager.h - Managing taint --------------------------- -*- C++ -*--=//
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
comment|//  This file provides APIs for adding, removing, querying symbol taint.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_TAINTMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_TAINTMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/PathDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramState.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramStateTrait.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/TaintTag.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ImmutableMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// The GDM component containing the tainted root symbols. We lazily infer the
comment|/// taint of the dependent symbols. Currently, this is a map from a symbol to
comment|/// tag kind. TODO: Should support multiple tag kinds.
comment|// FIXME: This does not use the nice trait macros because it must be accessible
comment|// from multiple translation units.
struct|struct
name|TaintMap
block|{}
struct|;
typedef|typedef
name|llvm
operator|::
name|ImmutableMap
operator|<
name|SymbolRef
operator|,
name|TaintTagType
operator|>
name|TaintMapImpl
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ProgramStateTrait
operator|<
name|TaintMap
operator|>
operator|:
name|public
name|ProgramStatePartialTrait
operator|<
name|TaintMapImpl
operator|>
block|{
specifier|static
name|void
operator|*
name|GDMIndex
argument_list|()
block|{
specifier|static
name|int
name|index
operator|=
literal|0
block|;
return|return
operator|&
name|index
return|;
block|}
expr|}
block|;
comment|/// The GDM component mapping derived symbols' parent symbols to their
comment|/// underlying regions. This is used to efficiently check whether a symbol is
comment|/// tainted when it represents a sub-region of a tainted symbol.
block|struct
name|DerivedSymTaint
block|{}
block|;
typedef|typedef
name|llvm
operator|::
name|ImmutableMap
operator|<
name|SymbolRef
operator|,
name|TaintedSubRegions
operator|>
name|DerivedSymTaintImpl
expr_stmt|;
name|template
operator|<
operator|>
block|struct
name|ProgramStateTrait
operator|<
name|DerivedSymTaint
operator|>
operator|:
name|public
name|ProgramStatePartialTrait
operator|<
name|DerivedSymTaintImpl
operator|>
block|{
specifier|static
name|void
operator|*
name|GDMIndex
argument_list|()
block|{
specifier|static
name|int
name|index
block|;
return|return
operator|&
name|index
return|;
block|}
expr|}
block|;
name|class
name|TaintManager
block|{
name|TaintManager
argument_list|()
block|{}
block|}
block|;  }
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

