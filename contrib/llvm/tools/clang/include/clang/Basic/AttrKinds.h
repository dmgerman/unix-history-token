begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- Attr.h - Enum values for C Attribute Kinds ----------*- C++ -*-===//
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
comment|/// \brief Defines the clang::attr::Kind enum.
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
name|LLVM_CLANG_BASIC_ATTRKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_ATTRKINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|attr
block|{
comment|// \brief A list of all the recognized kinds of attributes.
enum|enum
name|Kind
block|{
define|#
directive|define
name|ATTR
parameter_list|(
name|X
parameter_list|)
value|X,
define|#
directive|define
name|ATTR_RANGE
parameter_list|(
name|CLASS
parameter_list|,
name|FIRST_NAME
parameter_list|,
name|LAST_NAME
parameter_list|)
define|\
value|First##CLASS = FIRST_NAME,                    \   Last##CLASS = LAST_NAME,
include|#
directive|include
file|"clang/Basic/AttrList.inc"
block|}
enum|;
block|}
comment|// end namespace attr
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

