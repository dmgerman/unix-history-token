begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnresolvedSet.h - Unresolved sets of declarations  ------*- C++ -*-===//
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
comment|//  This file defines the WeakInfo class, which is used to store
end_comment

begin_comment
comment|//  information about the target of a #pragma weak directive.
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
name|LLVM_CLANG_SEMA_WEAK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_WEAK_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
comment|/// \brief Captures information about a \#pragma weak directive.
name|class
name|WeakInfo
block|{
name|IdentifierInfo
modifier|*
name|alias
decl_stmt|;
comment|// alias (optional)
name|SourceLocation
name|loc
decl_stmt|;
comment|// for diagnostics
name|bool
name|used
decl_stmt|;
comment|// identifier later declared?
name|public
label|:
name|WeakInfo
argument_list|()
operator|:
name|alias
argument_list|(
name|nullptr
argument_list|)
operator|,
name|loc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
operator|,
name|used
argument_list|(
argument|false
argument_list|)
block|{}
name|WeakInfo
argument_list|(
argument|IdentifierInfo *Alias
argument_list|,
argument|SourceLocation Loc
argument_list|)
operator|:
name|alias
argument_list|(
name|Alias
argument_list|)
operator|,
name|loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|used
argument_list|(
argument|false
argument_list|)
block|{}
specifier|inline
name|IdentifierInfo
operator|*
name|getAlias
argument_list|()
specifier|const
block|{
return|return
name|alias
return|;
block|}
specifier|inline
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|loc
return|;
block|}
name|void
name|setUsed
parameter_list|(
name|bool
name|Used
init|=
name|true
parameter_list|)
block|{
name|used
operator|=
name|Used
expr_stmt|;
block|}
specifier|inline
name|bool
name|getUsed
parameter_list|()
block|{
return|return
name|used
return|;
block|}
name|bool
name|operator
operator|==
operator|(
name|WeakInfo
name|RHS
operator|)
specifier|const
block|{
return|return
name|alias
operator|==
name|RHS
operator|.
name|getAlias
argument_list|()
operator|&&
name|loc
operator|==
name|RHS
operator|.
name|getLocation
argument_list|()
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|WeakInfo
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_WEAK_H
end_comment

end_unit

