begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIAError.h - Error extensions for PDB DIA implementation -*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_DIA_DIAERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIAERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|enum
name|class
name|dia_error_code
block|{
name|unspecified
operator|=
literal|1
operator|,
name|could_not_create_impl
operator|,
name|invalid_file_format
operator|,
name|invalid_parameter
operator|,
name|already_loaded
operator|,
name|debug_info_mismatch
operator|,
block|}
empty_stmt|;
comment|/// Base class for errors originating in DIA SDK, e.g. COM calls
name|class
name|DIAError
range|:
name|public
name|ErrorInfo
operator|<
name|DIAError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|DIAError
argument_list|(
argument|dia_error_code C
argument_list|)
block|;
name|DIAError
argument_list|(
argument|StringRef Context
argument_list|)
block|;
name|DIAError
argument_list|(
argument|dia_error_code C
argument_list|,
argument|StringRef Context
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
name|StringRef
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
name|dia_error_code
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

