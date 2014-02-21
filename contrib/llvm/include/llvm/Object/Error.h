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
file|"llvm/Support/system_error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
specifier|const
name|error_category
modifier|&
name|object_category
parameter_list|()
function_decl|;
struct|struct
name|object_error
block|{
enum|enum
name|Impl
block|{
name|success
init|=
literal|0
block|,
name|arch_not_found
block|,
name|invalid_file_type
block|,
name|parse_failed
block|,
name|unexpected_eof
block|}
enum|;
name|Impl
name|V
decl_stmt|;
name|object_error
argument_list|(
argument|Impl V
argument_list|)
block|:
name|V
argument_list|(
argument|V
argument_list|)
block|{}
name|operator
name|Impl
argument_list|()
specifier|const
block|{
return|return
name|V
return|;
block|}
block|}
struct|;
specifier|inline
name|error_code
name|make_error_code
parameter_list|(
name|object_error
name|e
parameter_list|)
block|{
return|return
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
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|object
operator|::
name|object_error
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|object
operator|::
name|object_error
operator|::
name|Impl
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

