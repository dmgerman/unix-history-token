begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LLVM.h - Import various common LLVM datatypes ----------*- C++ -*-===//
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
comment|// This file forward declares and imports various common LLVM datatypes that
end_comment

begin_comment
comment|// clang wants to use unqualified.
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
name|CLANG_BASIC_LLVM_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_BASIC_LLVM_H
end_define

begin_comment
comment|// This should be the only #include, force #includes of all the others on
end_comment

begin_comment
comment|// clients.
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// ADT's.
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|N
operator|>
name|class
name|SmallVector
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|// TODO: DenseMap, ...
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
comment|// Casting operators.
name|using
name|llvm
operator|::
name|isa
expr_stmt|;
name|using
name|llvm
operator|::
name|cast
expr_stmt|;
name|using
name|llvm
operator|::
name|dyn_cast
expr_stmt|;
name|using
name|llvm
operator|::
name|dyn_cast_or_null
expr_stmt|;
name|using
name|llvm
operator|::
name|cast_or_null
expr_stmt|;
comment|// ADT's.
name|using
name|llvm
operator|::
name|StringRef
expr_stmt|;
name|using
name|llvm
operator|::
name|Twine
expr_stmt|;
name|using
name|llvm
operator|::
name|ArrayRef
expr_stmt|;
name|using
name|llvm
operator|::
name|SmallVector
expr_stmt|;
name|using
name|llvm
operator|::
name|SmallVectorImpl
expr_stmt|;
name|using
name|llvm
operator|::
name|raw_ostream
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

