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
comment|//
end_comment

begin_comment
comment|//  This file provides utility classes that uses RAII to save and restore
end_comment

begin_comment
comment|//  values.
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
name|LLVM_CLANG_ANALYSIS_SAVERESTORE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_SAVERESTORE
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|// SaveAndRestore - A utility class that uses RAII to save and restore
comment|//  the value of a variable.
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
name|x
argument_list|)
operator|:
name|X
argument_list|(
name|x
argument_list|)
block|,
name|old_value
argument_list|(
argument|x
argument_list|)
block|{}
operator|~
name|SaveAndRestore
argument_list|()
block|{
name|X
operator|=
name|old_value
block|; }
name|T
name|get
argument_list|()
block|{
return|return
name|old_value
return|;
block|}
name|private
operator|:
name|T
operator|&
name|X
block|;
name|T
name|old_value
block|; }
expr_stmt|;
comment|// SaveOr - Similar to SaveAndRestore.  Operates only on bools; the old
comment|//  value of a variable is saved, and during the dstor the old value is
comment|//  or'ed with the new value.
struct|struct
name|SaveOr
block|{
name|SaveOr
argument_list|(
name|bool
operator|&
name|x
argument_list|)
operator|:
name|X
argument_list|(
name|x
argument_list|)
operator|,
name|old_value
argument_list|(
argument|x
argument_list|)
block|{
name|x
operator|=
name|false
block|; }
operator|~
name|SaveOr
argument_list|()
block|{
name|X
operator||=
name|old_value
block|; }
name|private
operator|:
name|bool
operator|&
name|X
expr_stmt|;
specifier|const
name|bool
name|old_value
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

