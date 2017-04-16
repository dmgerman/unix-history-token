begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeViewError.h - Error extensions for CodeView ----------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_CODEVIEW_CODEVIEWERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_CODEVIEW_CODEVIEWERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|enum
name|class
name|cv_error_code
block|{
name|unspecified
operator|=
literal|1
operator|,
name|insufficient_buffer
operator|,
name|operation_unsupported
operator|,
name|corrupt_record
operator|,
name|no_records
operator|,
name|unknown_member_record
operator|,
block|}
empty_stmt|;
comment|/// Base class for errors originating when parsing raw PDB files
name|class
name|CodeViewError
range|:
name|public
name|ErrorInfo
operator|<
name|CodeViewError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|CodeViewError
argument_list|(
argument|cv_error_code C
argument_list|)
block|;
name|CodeViewError
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Context
argument_list|)
block|;
name|CodeViewError
argument_list|(
argument|cv_error_code C
argument_list|,
argument|const std::string&Context
argument_list|)
block|;
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
block|;
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
name|cv_error_code
name|Code
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

