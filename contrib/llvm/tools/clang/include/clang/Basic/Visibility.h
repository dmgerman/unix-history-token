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
comment|//
end_comment

begin_comment
comment|// This file defines the Visibility enumeration and various utility
end_comment

begin_comment
comment|// functions.
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
name|LLVM_CLANG_BASIC_VISIBILITY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_VISIBILITY_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \link Describes the different kinds of visibility that a
comment|/// declaration may have.  Visibility determines how a declaration
comment|/// interacts with the dynamic linker.  It may also affect whether the
comment|/// symbol can be found by runtime symbol lookup APIs.
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

