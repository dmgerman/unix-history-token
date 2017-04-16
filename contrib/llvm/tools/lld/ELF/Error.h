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

begin_comment
comment|//
end_comment

begin_comment
comment|// In LLD, we have three levels of errors: fatal, error or warn.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Fatal makes the program exit immediately with an error message.
end_comment

begin_comment
comment|// You shouldn't use it except for reporting a corrupted input file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Error prints out an error message and increment a global variable
end_comment

begin_comment
comment|// ErrorCount to record the fact that we met an error condition. It does
end_comment

begin_comment
comment|// not exit, so it is safe for a lld-as-a-library use case. It is generally
end_comment

begin_comment
comment|// useful because it can report more than one error in a single run.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Warn doesn't do anything but printing out a given message.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It is not recommended to use llvm::outs() or llvm::errs() directly
end_comment

begin_comment
comment|// in LLD because they are not thread-safe. The functions declared in
end_comment

begin_comment
comment|// this file are mutually excluded, so you want to use them instead.
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
name|LLD_ELF_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_ERROR_H
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
name|elf
block|{
specifier|extern
name|uint64_t
name|ErrorCount
decl_stmt|;
extern|extern llvm::raw_ostream *ErrorOS;
extern|extern llvm::StringRef Argv0;
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
name|exitLld
parameter_list|(
name|int
name|Val
parameter_list|)
function_decl|;
comment|// check() functions are convenient functions to strip errors
comment|// from error-or-value objects.
name|template
operator|<
name|class
name|T
operator|>
name|T
name|check
argument_list|(
argument|ErrorOr<T> E
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|E
operator|.
name|getError
argument_list|()
condition|)
name|fatal
argument_list|(
name|EC
operator|.
name|message
argument_list|()
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
name|template
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
name|fatal
argument_list|(
name|llvm
operator|::
name|toString
argument_list|(
name|E
operator|.
name|takeError
argument_list|()
argument_list|)
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
argument|ErrorOr<T> E
argument_list|,
argument|const Twine&Prefix
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|E
operator|.
name|getError
argument_list|()
condition|)
name|fatal
argument_list|(
name|Prefix
operator|+
literal|": "
operator|+
name|EC
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
name|E
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
argument_list|,
argument|const Twine&Prefix
argument_list|)
block|{
if|if
condition|(
operator|!
name|E
condition|)
name|fatal
argument_list|(
name|Prefix
operator|+
literal|": "
operator|+
name|toString
argument_list|(
name|E
operator|.
name|takeError
argument_list|()
argument_list|)
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
name|E
argument_list|)
return|;
end_return

begin_comment
unit|}  }
comment|// namespace elf
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

