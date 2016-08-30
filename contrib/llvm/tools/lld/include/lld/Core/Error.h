begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Error.h - system_error extensions for lld ----------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|// This declares a new error_category for the lld library.
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
name|LLD_CORE_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_ERROR_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

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
name|lld
block|{
specifier|const
name|std
operator|::
name|error_category
operator|&
name|YamlReaderCategory
argument_list|()
expr_stmt|;
name|enum
name|class
name|YamlReaderError
block|{
name|unknown_keyword
operator|,
name|illegal_value
block|}
empty_stmt|;
specifier|inline
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|YamlReaderError e
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
name|YamlReaderCategory
argument_list|()
argument_list|)
return|;
block|}
comment|/// Creates an error_code object that has associated with it an arbitrary
comment|/// error messsage.  The value() of the error_code will always be non-zero
comment|/// but its value is meaningless. The messsage() will be (a copy of) the
comment|/// supplied error string.
comment|/// Note:  Once ErrorOr<> is updated to work with errors other than error_code,
comment|/// this can be updated to return some other kind of error.
name|std
operator|::
name|error_code
name|make_dynamic_error_code
argument_list|(
argument|StringRef msg
argument_list|)
expr_stmt|;
comment|/// Generic error.
comment|///
comment|/// For errors that don't require their own specific sub-error (most errors)
comment|/// this class can be used to describe the error via a string message.
name|class
name|GenericError
range|:
name|public
name|llvm
operator|::
name|ErrorInfo
operator|<
name|GenericError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|GenericError
argument_list|(
argument|Twine Msg
argument_list|)
block|;
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
argument|llvm::raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|{
return|return
name|make_dynamic_error_code
argument_list|(
name|getMessage
argument_list|()
argument_list|)
return|;
block|}
name|private
operator|:
name|std
operator|::
name|string
name|Msg
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
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
name|lld
operator|::
name|YamlReaderError
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

