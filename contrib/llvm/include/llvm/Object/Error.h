begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Error.h - system_error extensions for Object -------------*- C++ -*-===//
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
comment|// This declares a new error_category for the Object library.
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
name|LLVM_OBJECT_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_ERROR_H
end_define

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
specifier|const
name|std
operator|::
name|error_category
operator|&
name|object_category
argument_list|()
expr_stmt|;
name|enum
name|class
name|object_error
block|{
name|success
operator|=
literal|0
operator|,
name|arch_not_found
operator|,
name|invalid_file_type
operator|,
name|parse_failed
operator|,
name|unexpected_eof
block|}
empty_stmt|;
specifier|inline
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|object_error e
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|e
operator|)
argument_list|,
name|object_category
argument_list|()
argument_list|)
return|;
block|}
block|}
comment|// end namespace object.
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|llvm
operator|::
name|object
operator|::
name|object_error
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

