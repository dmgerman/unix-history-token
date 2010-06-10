begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Handlers.h - Interfaces for receiving information ------*- C++ -*-===//
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
comment|//  Abstract interfaces for receiving information.
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
name|LLVM_CLANG_INDEX_HANDLERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_HANDLERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|idx
block|{
name|class
name|Entity
decl_stmt|;
name|class
name|TranslationUnit
decl_stmt|;
name|class
name|TULocation
decl_stmt|;
comment|/// \brief Abstract interface for receiving Entities.
name|class
name|EntityHandler
block|{
name|public
label|:
typedef|typedef
name|Entity
name|receiving_type
typedef|;
name|virtual
operator|~
name|EntityHandler
argument_list|()
expr_stmt|;
name|virtual
name|void
name|Handle
parameter_list|(
name|Entity
name|Ent
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Abstract interface for receiving TranslationUnits.
name|class
name|TranslationUnitHandler
block|{
name|public
label|:
typedef|typedef
name|TranslationUnit
modifier|*
name|receiving_type
typedef|;
name|virtual
operator|~
name|TranslationUnitHandler
argument_list|()
expr_stmt|;
name|virtual
name|void
name|Handle
parameter_list|(
name|TranslationUnit
modifier|*
name|TU
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Abstract interface for receiving TULocations.
name|class
name|TULocationHandler
block|{
name|public
label|:
typedef|typedef
name|TULocation
name|receiving_type
typedef|;
name|virtual
operator|~
name|TULocationHandler
argument_list|()
expr_stmt|;
name|virtual
name|void
name|Handle
parameter_list|(
name|TULocation
name|TULoc
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Helper for the Handler classes. Stores the objects into a vector.
comment|/// example:
comment|/// @code
comment|/// Storing<TranslationUnitHandler> TURes;
comment|/// IndexProvider.GetTranslationUnitsFor(Entity, TURes);
comment|/// for (Storing<TranslationUnitHandler>::iterator
comment|///   I = TURes.begin(), E = TURes.end(); I != E; ++I) { ....
comment|/// @endcode
name|template
operator|<
name|typename
name|handler_type
operator|>
name|class
name|Storing
operator|:
name|public
name|handler_type
block|{
typedef|typedef
name|typename
name|handler_type
operator|::
name|receiving_type
name|receiving_type
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|receiving_type
operator|,
literal|8
operator|>
name|StoreTy
expr_stmt|;
name|StoreTy
name|Store
decl_stmt|;
name|public
label|:
name|virtual
name|void
name|Handle
parameter_list|(
name|receiving_type
name|Obj
parameter_list|)
block|{
name|Store
operator|.
name|push_back
argument_list|(
name|Obj
argument_list|)
expr_stmt|;
block|}
typedef|typedef
name|typename
name|StoreTy
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Store
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Store
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace idx
end_comment

begin_comment
unit|}
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

