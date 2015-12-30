begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Error.h --------------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_COFF_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_ERROR_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|error
argument_list|(
name|std
operator|::
name|error_code
name|EC
argument_list|,
specifier|const
name|Twine
operator|&
name|Prefix
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|error
argument_list|(
argument|const ErrorOr<T>&V
argument_list|,
argument|const Twine&Prefix
argument_list|)
block|{
name|error
argument_list|(
name|V
operator|.
name|getError
argument_list|()
argument_list|,
name|Prefix
argument_list|)
block|; }
block|}
comment|// namespace coff
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

