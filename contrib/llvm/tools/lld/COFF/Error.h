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

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
specifier|extern
name|uint64_t
name|ErrorCount
decl_stmt|;
extern|extern llvm::raw_ostream *ErrorOS;
name|void
name|log
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|message
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|warn
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|void
name|error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|fatal
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|fatal
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
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|fatal
argument_list|(
name|llvm
operator|::
name|Error
operator|&
name|Err
argument_list|,
specifier|const
name|Twine
operator|&
name|Prefix
argument_list|)
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|T
name|check
argument_list|(
argument|ErrorOr<T> V
argument_list|,
argument|const Twine&Prefix
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|V
operator|.
name|getError
argument_list|()
condition|)
name|fatal
argument_list|(
name|EC
argument_list|,
name|Prefix
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|V
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|T
name|check
argument_list|(
argument|Expected<T> E
argument_list|,
argument|const Twine&Prefix
argument_list|)
block|{
if|if
condition|(
name|llvm
operator|::
name|Error
name|Err
operator|=
name|E
operator|.
name|takeError
argument_list|()
condition|)
name|fatal
argument_list|(
name|Err
argument_list|,
name|Prefix
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|E
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|T
name|check
argument_list|(
argument|ErrorOr<T> EO
argument_list|)
block|{
if|if
condition|(
operator|!
name|EO
condition|)
name|fatal
argument_list|(
name|EO
operator|.
name|getError
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|EO
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
name|T
name|check
argument_list|(
argument|Expected<T> E
argument_list|)
block|{
if|if
condition|(
operator|!
name|E
condition|)
block|{
name|std
operator|::
name|string
name|Buf
expr_stmt|;
name|llvm
operator|::
name|raw_string_ostream
name|OS
argument_list|(
name|Buf
argument_list|)
expr_stmt|;
name|logAllUnhandledErrors
argument_list|(
name|E
operator|.
name|takeError
argument_list|()
argument_list|,
name|OS
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|OS
operator|.
name|flush
argument_list|()
expr_stmt|;
name|fatal
argument_list|(
name|Buf
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|E
argument_list|)
return|;
end_return

begin_comment
unit|}  }
comment|// namespace coff
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

