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
name|namespace
name|pretty
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
extern|extern llvm::cl::list<std::string> IncludeTypes;
extern|extern llvm::cl::list<std::string> IncludeSymbols;
extern|extern llvm::cl::list<std::string> IncludeCompilands;
block|}
name|namespace
name|raw
block|{
extern|extern llvm::cl::opt<bool> DumpHeaders;
extern|extern llvm::cl::opt<bool> DumpStreamBlocks;
extern|extern llvm::cl::opt<bool> DumpStreamSummary;
extern|extern llvm::cl::opt<bool> DumpTpiHash;
extern|extern llvm::cl::opt<bool> DumpTpiRecordBytes;
extern|extern llvm::cl::opt<bool> DumpTpiRecords;
extern|extern llvm::cl::opt<bool> DumpIpiRecords;
extern|extern llvm::cl::opt<bool> DumpIpiRecordBytes;
extern|extern llvm::cl::opt<std::string> DumpStreamDataIdx;
extern|extern llvm::cl::opt<std::string> DumpStreamDataName;
extern|extern llvm::cl::opt<bool> DumpModules;
extern|extern llvm::cl::opt<bool> DumpModuleFiles;
extern|extern llvm::cl::opt<bool> DumpModuleSyms;
extern|extern llvm::cl::opt<bool> DumpPublics;
extern|extern llvm::cl::opt<bool> DumpSectionContribs;
extern|extern llvm::cl::opt<bool> DumpLineInfo;
extern|extern llvm::cl::opt<bool> DumpSectionMap;
extern|extern llvm::cl::opt<bool> DumpSymRecordBytes;
extern|extern llvm::cl::opt<bool> DumpSectionHeaders;
extern|extern llvm::cl::opt<bool> DumpFpo;
block|}
name|namespace
name|pdb2yaml
block|{
extern|extern llvm::cl::opt<bool> NoFileHeaders;
extern|extern llvm::cl::opt<bool> StreamMetadata;
extern|extern llvm::cl::opt<bool> StreamDirectory;
extern|extern llvm::cl::opt<bool> PdbStream;
extern|extern llvm::cl::opt<bool> DbiStream;
extern|extern llvm::cl::list<std::string> InputFilename;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

