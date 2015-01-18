begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm-vtabledump.h ---------------------------------------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVM_VTABLEDUMP_LLVM_VTABLEDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_VTABLEDUMP_LLVM_VTABLEDUMP_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|opts
block|{
extern|extern llvm::cl::list<std::string> InputFilenames;
block|}
end_decl_stmt

begin_comment
comment|// namespace opts
end_comment

begin_define
define|#
directive|define
name|LLVM_VTABLEDUMP_ENUM_ENT
parameter_list|(
name|ns
parameter_list|,
name|enum
define|)                                     \   { #enum, ns::enum }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

