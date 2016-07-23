begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Error.h - system_error extensions for obj2yaml -----------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_OBJ2YAML_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_OBJ2YAML_ERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|const
name|std
operator|::
name|error_category
operator|&
name|obj2yaml_category
argument_list|()
expr_stmt|;
name|enum
name|class
name|obj2yaml_error
block|{
name|success
operator|=
literal|0
operator|,
name|file_not_found
operator|,
name|unrecognized_file_format
operator|,
name|unsupported_obj_file_format
operator|,
name|not_implemented
block|}
empty_stmt|;
specifier|inline
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|obj2yaml_error e
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
name|obj2yaml_category
argument_list|()
argument_list|)
return|;
block|}
name|class
name|Obj2YamlError
range|:
name|public
name|ErrorInfo
operator|<
name|Obj2YamlError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|Obj2YamlError
argument_list|(
argument|obj2yaml_error C
argument_list|)
operator|:
name|Code
argument_list|(
argument|C
argument_list|)
block|{}
name|Obj2YamlError
argument_list|(
argument|std::string ErrMsg
argument_list|)
operator|:
name|ErrMsg
argument_list|(
argument|std::move(ErrMsg)
argument_list|)
block|{}
name|Obj2YamlError
argument_list|(
argument|obj2yaml_error C
argument_list|,
argument|std::string ErrMsg
argument_list|)
operator|:
name|ErrMsg
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|ErrMsg
argument_list|)
argument_list|)
block|,
name|Code
argument_list|(
argument|C
argument_list|)
block|{}
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getErrorMessage
argument_list|()
specifier|const
block|{
return|return
name|ErrMsg
return|;
block|}
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|ErrMsg
block|;
name|obj2yaml_error
name|Code
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
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
name|obj2yaml_error
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

