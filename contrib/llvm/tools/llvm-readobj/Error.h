begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Error.h - system_error extensions for llvm-readobj -------*- C++ -*-===//
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
comment|// This declares a new error_category for the llvm-readobj tool.
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
name|LLVM_READOBJ_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_READOBJ_ERROR_H
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
specifier|const
name|error_category
modifier|&
name|readobj_category
parameter_list|()
function_decl|;
struct|struct
name|readobj_error
block|{
enum|enum
name|_
block|{
name|success
init|=
literal|0
block|,
name|file_not_found
block|,
name|unsupported_file_format
block|,
name|unrecognized_file_format
block|,
name|unsupported_obj_file_format
block|,
name|unknown_symbol
block|}
enum|;
name|_
name|v_
decl_stmt|;
name|readobj_error
argument_list|(
argument|_ v
argument_list|)
block|:
name|v_
argument_list|(
argument|v
argument_list|)
block|{}
name|explicit
name|readobj_error
argument_list|(
argument|int v
argument_list|)
block|:
name|v_
argument_list|(
argument|_(v)
argument_list|)
block|{}
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|v_
return|;
block|}
block|}
struct|;
specifier|inline
name|error_code
name|make_error_code
parameter_list|(
name|readobj_error
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
name|readobj_category
argument_list|()
argument_list|)
return|;
block|}
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|readobj_error
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
name|readobj_error
operator|::
name|_
operator|>
operator|:
name|true_type
block|{ }
expr_stmt|;
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

