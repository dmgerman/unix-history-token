begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== DynamicTypeMap.h - Dynamic type map ----------------------- -*- C++ -*--=//
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
comment|//  This file provides APIs for tracking dynamic type information.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_DYNAMICTYPEMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_DYNAMICTYPEMAP_H
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
file|"llvm/ADT/ImmutableMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// The GDM component containing the dynamic type info. This is a map from a
comment|/// symbol to its most likely type.
struct|struct
name|DynamicTypeMap
block|{}
struct|;
typedef|typedef
name|llvm
operator|::
name|ImmutableMap
operator|<
specifier|const
name|MemRegion
operator|*
operator|,
name|DynamicTypeInfo
operator|>
name|DynamicTypeMapImpl
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|ProgramStateTrait
operator|<
name|DynamicTypeMap
operator|>
operator|:
name|public
name|ProgramStatePartialTrait
operator|<
name|DynamicTypeMapImpl
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
comment|/// \brief Get dynamic type information for a region.
name|DynamicTypeInfo
name|getDynamicTypeInfo
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|const MemRegion *Reg
argument_list|)
block|;
comment|/// \brief Set dynamic type information of the region; return the new state.
name|ProgramStateRef
name|setDynamicTypeInfo
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|const MemRegion *Reg
argument_list|,
argument|DynamicTypeInfo NewTy
argument_list|)
block|;
comment|/// \brief Set dynamic type information of the region; return the new state.
specifier|inline
name|ProgramStateRef
name|setDynamicTypeInfo
argument_list|(
argument|ProgramStateRef State
argument_list|,
argument|const MemRegion *Reg
argument_list|,
argument|QualType NewTy
argument_list|,
argument|bool CanBeSubClassed = true
argument_list|)
block|{
return|return
name|setDynamicTypeInfo
argument_list|(
name|State
argument_list|,
name|Reg
argument_list|,
name|DynamicTypeInfo
argument_list|(
name|NewTy
argument_list|,
name|CanBeSubClassed
argument_list|)
argument_list|)
return|;
block|}
expr|}
comment|// ento
expr|}
end_decl_stmt

begin_comment
comment|// clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_DYNAMICTYPEMAP_H
end_comment

end_unit

