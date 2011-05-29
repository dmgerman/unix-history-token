begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BuiltinOptions.h - The LLVM Compiler Driver ------------*- C++ -*-===//
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
comment|//  Declarations of all global command-line option variables.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_BUILTIN_OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_BUILTIN_OPTIONS_H
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
name|llvmc
block|{
name|namespace
name|SaveTempsEnum
block|{
enum|enum
name|Values
block|{
name|Cwd
block|,
name|Obj
block|,
name|Unset
block|}
enum|;
block|}
extern|extern llvm::cl::list<std::string> InputFilenames;
extern|extern llvm::cl::opt<std::string> OutputFilename;
extern|extern llvm::cl::opt<std::string> TempDirname;
extern|extern llvm::cl::list<std::string> Languages;
extern|extern llvm::cl::opt<bool> DryRun;
extern|extern llvm::cl::opt<bool> Time;
extern|extern llvm::cl::opt<bool> VerboseMode;
extern|extern llvm::cl::opt<bool> CheckGraph;
extern|extern llvm::cl::opt<bool> ViewGraph;
extern|extern llvm::cl::opt<bool> WriteGraph;
extern|extern llvm::cl::opt<SaveTempsEnum::Values> SaveTemps;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvmc.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_BUILTIN_OPTIONS_H
end_comment

end_unit

