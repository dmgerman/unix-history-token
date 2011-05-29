begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- GlobalSelector.h - Cross-translation-unit "token" for selectors --===//
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
comment|//  GlobalSelector is a ASTContext-independent way to refer to selectors.
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
name|LLVM_CLANG_INDEX_GLOBALSELECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_GLOBALSELECTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Selector
decl_stmt|;
name|namespace
name|idx
block|{
name|class
name|Program
decl_stmt|;
comment|/// \brief A ASTContext-independent way to refer to selectors.
name|class
name|GlobalSelector
block|{
name|void
modifier|*
name|Val
decl_stmt|;
name|explicit
name|GlobalSelector
argument_list|(
name|void
operator|*
name|val
argument_list|)
operator|:
name|Val
argument_list|(
argument|val
argument_list|)
block|{ }
name|public
operator|:
name|GlobalSelector
argument_list|()
operator|:
name|Val
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Get the ASTContext-specific selector.
name|Selector
name|getSelector
argument_list|(
argument|ASTContext&AST
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|!=
literal|0
return|;
block|}
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Get a printable name for debugging purpose.
name|std
operator|::
name|string
name|getPrintableName
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get a GlobalSelector for the ASTContext-specific selector.
specifier|static
name|GlobalSelector
name|get
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|Program
modifier|&
name|Prog
parameter_list|)
function_decl|;
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
specifier|static
name|GlobalSelector
name|getFromOpaquePtr
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
return|return
name|GlobalSelector
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|GlobalSelector
operator|&
name|LHS
operator|,
specifier|const
name|GlobalSelector
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|getAsOpaquePtr
argument_list|()
operator|==
name|RHS
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
comment|// For use in a std::map.
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|GlobalSelector
operator|&
name|LHS
operator|,
specifier|const
name|GlobalSelector
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|getAsOpaquePtr
argument_list|()
operator|<
name|RHS
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
comment|// For use in DenseMap/DenseSet.
specifier|static
name|GlobalSelector
name|getEmptyMarker
parameter_list|()
block|{
return|return
name|GlobalSelector
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
argument_list|)
return|;
block|}
specifier|static
name|GlobalSelector
name|getTombstoneMarker
parameter_list|()
block|{
return|return
name|GlobalSelector
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|-
literal|2
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// namespace idx
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Define DenseMapInfo so that GlobalSelectors can be used as keys in DenseMap
comment|/// and DenseSets.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
operator|::
name|getEmptyMarker
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
operator|::
name|getTombstoneMarker
argument_list|()
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
argument_list|)
block|;
specifier|static
specifier|inline
name|bool
name|isEqual
argument_list|(
argument|clang::idx::GlobalSelector LHS
argument_list|,
argument|clang::idx::GlobalSelector RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|idx
operator|::
name|GlobalSelector
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

