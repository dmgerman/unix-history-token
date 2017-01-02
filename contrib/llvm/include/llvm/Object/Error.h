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
file|"llvm/ADT/Twine.h"
end_include

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
name|namespace
name|object
block|{
name|class
name|Binary
decl_stmt|;
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
comment|// Error code 0 is absent. Use std::error_code() instead.
name|arch_not_found
operator|=
literal|1
operator|,
name|invalid_file_type
operator|,
name|parse_failed
operator|,
name|unexpected_eof
operator|,
name|string_table_non_null_end
operator|,
name|invalid_section_index
operator|,
name|bitcode_section_not_found
operator|,
name|invalid_symbol_index
operator|,
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
comment|/// Base class for all errors indicating malformed binary files.
comment|///
comment|/// Having a subclass for all malformed binary files allows archive-walking
comment|/// code to skip malformed files without having to understand every possible
comment|/// way that a binary file might be malformed.
comment|///
comment|/// Currently inherits from ECError for easy interoperability with
comment|/// std::error_code, but this will be removed in the future.
name|class
name|BinaryError
range|:
name|public
name|ErrorInfo
operator|<
name|BinaryError
decl_stmt|,
name|ECError
decl|>
block|{
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
name|BinaryError
argument_list|()
block|{
comment|// Default to parse_failed, can be overridden with setErrorCode.
name|setErrorCode
argument_list|(
name|make_error_code
argument_list|(
name|object_error
operator|::
name|parse_failed
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// Generic binary error.
comment|///
comment|/// For errors that don't require their own specific sub-error (most errors)
comment|/// this class can be used to describe the error via a string message.
name|class
name|GenericBinaryError
range|:
name|public
name|ErrorInfo
operator|<
name|GenericBinaryError
decl_stmt|,
name|BinaryError
decl|>
block|{
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
name|GenericBinaryError
argument_list|(
argument|Twine Msg
argument_list|)
empty_stmt|;
name|GenericBinaryError
argument_list|(
argument|Twine Msg
argument_list|,
argument|object_error ECOverride
argument_list|)
empty_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getMessage
argument_list|()
specifier|const
block|{
return|return
name|Msg
return|;
block|}
name|void
name|log
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
name|override
decl_stmt|;
name|private
label|:
name|std
operator|::
name|string
name|Msg
expr_stmt|;
block|}
empty_stmt|;
comment|/// isNotObjectErrorInvalidFileType() is used when looping through the children
comment|/// of an archive after calling getAsBinary() on the child and it returns an
comment|/// llvm::Error.  In the cases we want to loop through the children and ignore the
comment|/// non-objects in the archive this is used to test the error to see if an
comment|/// error() function needs to called on the llvm::Error.
name|Error
name|isNotObjectErrorInvalidFileType
argument_list|(
name|llvm
operator|::
name|Error
name|Err
argument_list|)
decl_stmt|;
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

