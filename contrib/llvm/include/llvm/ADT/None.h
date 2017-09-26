begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- None.h - Simple null value for implicit construction ------*- C++ -*-=//
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
comment|//  This file provides None, an enumerator for use in implicit constructors
end_comment

begin_comment
comment|//  of various (usually templated) types to make such construction more
end_comment

begin_comment
comment|//  terse.
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
name|LLVM_ADT_NONE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_NONE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief A simple null object to allow implicit construction of Optional<T>
comment|/// and similar types without having to spell out the specialization's name.
comment|// (constant value 1 in an attempt to workaround MSVC build issue... )
name|enum
name|class
name|NoneType
block|{
name|None
operator|=
literal|1
block|}
empty_stmt|;
specifier|const
name|NoneType
name|None
init|=
name|NoneType
operator|::
name|None
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

