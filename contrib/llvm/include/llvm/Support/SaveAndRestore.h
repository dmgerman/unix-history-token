begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SaveAndRestore.h - Utility  -------------------------------*- C++ -*-=//
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
comment|/// This file provides utility classes that use RAII to save and restore
end_comment

begin_comment
comment|/// values.
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
name|LLVM_SUPPORT_SAVEANDRESTORE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SAVEANDRESTORE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A utility class that uses RAII to save and restore the value of a variable.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SaveAndRestore
block|{
name|SaveAndRestore
argument_list|(
name|T
operator|&
name|X
argument_list|)
operator|:
name|X
argument_list|(
name|X
argument_list|)
block|,
name|OldValue
argument_list|(
argument|X
argument_list|)
block|{}
name|SaveAndRestore
argument_list|(
name|T
operator|&
name|X
argument_list|,
specifier|const
name|T
operator|&
name|NewValue
argument_list|)
operator|:
name|X
argument_list|(
name|X
argument_list|)
block|,
name|OldValue
argument_list|(
argument|X
argument_list|)
block|{
name|X
operator|=
name|NewValue
block|;   }
operator|~
name|SaveAndRestore
argument_list|()
block|{
name|X
operator|=
name|OldValue
block|; }
name|T
name|get
argument_list|()
block|{
return|return
name|OldValue
return|;
block|}
name|private
operator|:
name|T
operator|&
name|X
block|;
name|T
name|OldValue
block|; }
expr_stmt|;
comment|/// Similar to \c SaveAndRestore.  Operates only on bools; the old value of a
comment|/// variable is saved, and during the dstor the old value is or'ed with the new
comment|/// value.
struct|struct
name|SaveOr
block|{
name|SaveOr
argument_list|(
name|bool
operator|&
name|X
argument_list|)
operator|:
name|X
argument_list|(
name|X
argument_list|)
operator|,
name|OldValue
argument_list|(
argument|X
argument_list|)
block|{
name|X
operator|=
name|false
block|; }
operator|~
name|SaveOr
argument_list|()
block|{
name|X
operator||=
name|OldValue
block|; }
name|private
operator|:
name|bool
operator|&
name|X
expr_stmt|;
specifier|const
name|bool
name|OldValue
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

