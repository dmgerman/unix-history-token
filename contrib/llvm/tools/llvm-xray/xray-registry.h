begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- xray-registry.h - Define registry mechanism for commands. ----------===//
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
comment|// Implement a simple subcommand registry.
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
name|TOOLS_LLVM_XRAY_XRAY_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|TOOLS_LLVM_XRAY_XRAY_REGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
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
name|xray
block|{
comment|// Use |CommandRegistration| as a global initialiser that registers a function
comment|// and associates it with |SC|. This requires that a command has not been
comment|// registered to a given |SC|.
comment|//
comment|// Usage:
comment|//
comment|//   // At namespace scope.
comment|//   static CommandRegistration Unused(&MySubCommand, [] { ... });
comment|//
struct|struct
name|CommandRegistration
block|{
name|CommandRegistration
argument_list|(
name|cl
operator|::
name|SubCommand
operator|*
name|SC
argument_list|,
name|std
operator|::
name|function
operator|<
name|Error
argument_list|()
operator|>
name|Command
argument_list|)
expr_stmt|;
block|}
struct|;
comment|// Requires that |SC| is not null and has an associated function to it.
name|std
operator|::
name|function
operator|<
name|Error
argument_list|()
operator|>
name|dispatch
argument_list|(
name|cl
operator|::
name|SubCommand
operator|*
name|SC
argument_list|)
expr_stmt|;
block|}
comment|// namespace xray
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TOOLS_LLVM_XRAY_XRAY_REGISTRY_H
end_comment

end_unit

