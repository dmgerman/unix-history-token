begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== TaintTag.h - Path-sensitive "State" for tracking values -*- C++ -*--=//
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
comment|// Defines a set of taint tags. Several tags are used to differentiate kinds
end_comment

begin_comment
comment|// of taint.
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_TAINTTAG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_TAINTTAG_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// The type of taint, which helps to differentiate between different types of
comment|/// taint.
typedef|typedef
name|unsigned
name|TaintTagType
typedef|;
specifier|static
specifier|const
name|TaintTagType
name|TaintTagGeneric
init|=
literal|0
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

