begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm-pdbdump.h ----------------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_LLVMPDBDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_LLVMPDBDUMP_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|opts
block|{
extern|extern llvm::cl::opt<bool> Compilands;
extern|extern llvm::cl::opt<bool> Symbols;
extern|extern llvm::cl::opt<bool> Globals;
extern|extern llvm::cl::opt<bool> Types;
extern|extern llvm::cl::opt<bool> All;
extern|extern llvm::cl::opt<bool> ExcludeCompilerGenerated;
extern|extern llvm::cl::opt<bool> NoClassDefs;
extern|extern llvm::cl::opt<bool> NoEnumDefs;
extern|extern llvm::cl::list<std::string> ExcludeTypes;
extern|extern llvm::cl::list<std::string> ExcludeSymbols;
extern|extern llvm::cl::list<std::string> ExcludeCompilands;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

