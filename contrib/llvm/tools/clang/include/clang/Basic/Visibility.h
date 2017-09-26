begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Visibility.h - Visibility enumeration and utilities ----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::Visibility enumeration and various utility
end_comment

begin_comment
comment|/// functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_VISIBILITY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_VISIBILITY_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Linkage.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Describes the different kinds of visibility that a declaration
comment|/// may have.
comment|///
comment|/// Visibility determines how a declaration interacts with the dynamic
comment|/// linker.  It may also affect whether the symbol can be found by runtime
comment|/// symbol lookup APIs.
comment|///
comment|/// Visibility is not described in any language standard and
comment|/// (nonetheless) sometimes has odd behavior.  Not all platforms
comment|/// support all visibility kinds.
enum|enum
name|Visibility
block|{
comment|/// Objects with "hidden" visibility are not seen by the dynamic
comment|/// linker.
name|HiddenVisibility
block|,
comment|/// Objects with "protected" visibility are seen by the dynamic
comment|/// linker but always dynamically resolve to an object within this
comment|/// shared object.
name|ProtectedVisibility
block|,
comment|/// Objects with "default" visibility are seen by the dynamic linker
comment|/// and act like normal objects.
name|DefaultVisibility
block|}
enum|;
specifier|inline
name|Visibility
name|minVisibility
parameter_list|(
name|Visibility
name|L
parameter_list|,
name|Visibility
name|R
parameter_list|)
block|{
return|return
name|L
operator|<
name|R
condition|?
name|L
else|:
name|R
return|;
block|}
name|class
name|LinkageInfo
block|{
name|uint8_t
name|linkage_
range|:
literal|3
decl_stmt|;
name|uint8_t
name|visibility_
range|:
literal|2
decl_stmt|;
name|uint8_t
name|explicit_
range|:
literal|1
decl_stmt|;
name|void
name|setVisibility
parameter_list|(
name|Visibility
name|V
parameter_list|,
name|bool
name|E
parameter_list|)
block|{
name|visibility_
operator|=
name|V
expr_stmt|;
name|explicit_
operator|=
name|E
expr_stmt|;
block|}
name|public
label|:
name|LinkageInfo
argument_list|()
operator|:
name|linkage_
argument_list|(
name|ExternalLinkage
argument_list|)
operator|,
name|visibility_
argument_list|(
name|DefaultVisibility
argument_list|)
operator|,
name|explicit_
argument_list|(
argument|false
argument_list|)
block|{}
name|LinkageInfo
argument_list|(
argument|Linkage L
argument_list|,
argument|Visibility V
argument_list|,
argument|bool E
argument_list|)
operator|:
name|linkage_
argument_list|(
name|L
argument_list|)
operator|,
name|visibility_
argument_list|(
name|V
argument_list|)
operator|,
name|explicit_
argument_list|(
argument|E
argument_list|)
block|{
name|assert
argument_list|(
name|getLinkage
argument_list|()
operator|==
name|L
operator|&&
name|getVisibility
argument_list|()
operator|==
name|V
operator|&&
name|isVisibilityExplicit
argument_list|()
operator|==
name|E
operator|&&
literal|"Enum truncated!"
argument_list|)
block|;   }
specifier|static
name|LinkageInfo
name|external
argument_list|()
block|{
return|return
name|LinkageInfo
argument_list|()
return|;
block|}
specifier|static
name|LinkageInfo
name|internal
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|InternalLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|LinkageInfo
name|uniqueExternal
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|UniqueExternalLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|LinkageInfo
name|none
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|NoLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|LinkageInfo
name|visible_none
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|VisibleNoLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
name|Linkage
name|getLinkage
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Linkage
operator|)
name|linkage_
return|;
block|}
name|Visibility
name|getVisibility
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Visibility
operator|)
name|visibility_
return|;
block|}
name|bool
name|isVisibilityExplicit
argument_list|()
specifier|const
block|{
return|return
name|explicit_
return|;
block|}
name|void
name|setLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
name|linkage_
operator|=
name|L
expr_stmt|;
block|}
name|void
name|mergeLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
name|setLinkage
argument_list|(
name|minLinkage
argument_list|(
name|getLinkage
argument_list|()
argument_list|,
name|L
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeLinkage
parameter_list|(
name|LinkageInfo
name|other
parameter_list|)
block|{
name|mergeLinkage
argument_list|(
name|other
operator|.
name|getLinkage
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeExternalVisibility
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
name|Linkage
name|ThisL
init|=
name|getLinkage
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|isExternallyVisible
argument_list|(
name|L
argument_list|)
condition|)
block|{
if|if
condition|(
name|ThisL
operator|==
name|VisibleNoLinkage
condition|)
name|ThisL
operator|=
name|NoLinkage
expr_stmt|;
elseif|else
if|if
condition|(
name|ThisL
operator|==
name|ExternalLinkage
condition|)
name|ThisL
operator|=
name|UniqueExternalLinkage
expr_stmt|;
block|}
name|setLinkage
argument_list|(
name|ThisL
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeExternalVisibility
parameter_list|(
name|LinkageInfo
name|Other
parameter_list|)
block|{
name|mergeExternalVisibility
argument_list|(
name|Other
operator|.
name|getLinkage
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// Merge in the visibility 'newVis'.
name|void
name|mergeVisibility
parameter_list|(
name|Visibility
name|newVis
parameter_list|,
name|bool
name|newExplicit
parameter_list|)
block|{
name|Visibility
name|oldVis
init|=
name|getVisibility
argument_list|()
decl_stmt|;
comment|// Never increase visibility.
if|if
condition|(
name|oldVis
operator|<
name|newVis
condition|)
return|return;
comment|// If the new visibility is the same as the old and the new
comment|// visibility isn't explicit, we have nothing to add.
if|if
condition|(
name|oldVis
operator|==
name|newVis
operator|&&
operator|!
name|newExplicit
condition|)
return|return;
comment|// Otherwise, we're either decreasing visibility or making our
comment|// existing visibility explicit.
name|setVisibility
argument_list|(
name|newVis
argument_list|,
name|newExplicit
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeVisibility
parameter_list|(
name|LinkageInfo
name|other
parameter_list|)
block|{
name|mergeVisibility
argument_list|(
name|other
operator|.
name|getVisibility
argument_list|()
argument_list|,
name|other
operator|.
name|isVisibilityExplicit
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// Merge both linkage and visibility.
name|void
name|merge
parameter_list|(
name|LinkageInfo
name|other
parameter_list|)
block|{
name|mergeLinkage
argument_list|(
name|other
argument_list|)
expr_stmt|;
name|mergeVisibility
argument_list|(
name|other
argument_list|)
expr_stmt|;
block|}
comment|/// Merge linkage and conditionally merge visibility.
name|void
name|mergeMaybeWithVisibility
parameter_list|(
name|LinkageInfo
name|other
parameter_list|,
name|bool
name|withVis
parameter_list|)
block|{
name|mergeLinkage
argument_list|(
name|other
argument_list|)
expr_stmt|;
if|if
condition|(
name|withVis
condition|)
name|mergeVisibility
argument_list|(
name|other
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_VISIBILITY_H
end_comment

end_unit

