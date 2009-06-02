begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Action.h - The LLVM Compiler Driver --------------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open
end_comment

begin_comment
comment|// Source License. See LICENSE.TXT for details.
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
comment|//  Action - encapsulates a single shell command.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_ACTION_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvmc
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|StrVector
expr_stmt|;
comment|/// Action - A class that encapsulates a single shell command.
name|class
name|Action
block|{
comment|/// Command_ - The actual command (for example, 'ls').
name|std
operator|::
name|string
name|Command_
expr_stmt|;
comment|/// Args_ - Command arguments. Stdout redirection ("> file") is allowed.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args_
expr_stmt|;
comment|/// StopCompilation_ - Should we stop compilation after executing
comment|/// this action?
name|bool
name|StopCompilation_
decl_stmt|;
comment|/// OutFile_ - The output file name.
name|std
operator|::
name|string
name|OutFile_
expr_stmt|;
name|public
label|:
name|Action
argument_list|(
argument|const std::string& C
argument_list|,
argument|const StrVector& A
argument_list|,
argument|bool S
argument_list|,
argument|const std::string& O
argument_list|)
block|:
name|Command_
argument_list|(
name|C
argument_list|)
operator|,
name|Args_
argument_list|(
name|A
argument_list|)
operator|,
name|StopCompilation_
argument_list|(
name|S
argument_list|)
operator|,
name|OutFile_
argument_list|(
argument|O
argument_list|)
block|{}
comment|/// Execute - Executes the represented action.
name|int
name|Execute
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|StopCompilation
argument_list|()
specifier|const
block|{
return|return
name|StopCompilation_
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|OutFile
argument_list|()
block|{
return|return
name|OutFile_
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_ACTION_H
end_comment

end_unit

