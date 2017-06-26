begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm-pdbutil.h ----------------------------------------- *- C++ --*-===//
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
file|"llvm/ADT/Optional.h"
end_include

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

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|PDBSymbolData
decl_stmt|;
name|class
name|PDBSymbolFunc
decl_stmt|;
name|uint32_t
name|getTypeLength
parameter_list|(
specifier|const
name|PDBSymbolData
modifier|&
name|Symbol
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|opts
block|{
name|enum
name|class
name|DumpLevel
block|{
name|None
operator|,
name|Basic
operator|,
name|Verbose
block|}
empty_stmt|;
name|enum
name|class
name|ModuleSubsection
block|{
name|Unknown
operator|,
name|Lines
operator|,
name|FileChecksums
operator|,
name|InlineeLines
operator|,
name|CrossScopeImports
operator|,
name|CrossScopeExports
operator|,
name|StringTable
operator|,
name|Symbols
operator|,
name|FrameData
operator|,
name|CoffSymbolRVAs
operator|,
name|All
block|}
empty_stmt|;
name|namespace
name|pretty
block|{
name|enum
name|class
name|ClassDefinitionFormat
block|{
name|None
operator|,
name|Layout
operator|,
name|All
block|}
empty_stmt|;
name|enum
name|class
name|ClassSortMode
block|{
name|None
operator|,
name|Name
operator|,
name|Size
operator|,
name|Padding
operator|,
name|PaddingPct
operator|,
name|PaddingImmediate
operator|,
name|PaddingPctImmediate
block|}
empty_stmt|;
name|enum
name|class
name|SymbolSortMode
block|{
name|None
operator|,
name|Name
operator|,
name|Size
block|}
empty_stmt|;
name|enum
name|class
name|SymLevel
block|{
name|Functions
operator|,
name|Data
operator|,
name|Thunks
operator|,
name|All
block|}
empty_stmt|;
name|bool
name|shouldDumpSymLevel
parameter_list|(
name|SymLevel
name|Level
parameter_list|)
function_decl|;
name|bool
name|compareFunctionSymbols
argument_list|(
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|pdb
operator|::
name|PDBSymbolFunc
operator|>
operator|&
name|F1
argument_list|,
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|pdb
operator|::
name|PDBSymbolFunc
operator|>
operator|&
name|F2
argument_list|)
decl_stmt|;
name|bool
name|compareDataSymbols
argument_list|(
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|pdb
operator|::
name|PDBSymbolData
operator|>
operator|&
name|F1
argument_list|,
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|pdb
operator|::
name|PDBSymbolData
operator|>
operator|&
name|F2
argument_list|)
decl_stmt|;
extern|extern llvm::cl::opt<bool> Compilands;
extern|extern llvm::cl::opt<bool> Symbols;
extern|extern llvm::cl::opt<bool> Globals;
extern|extern llvm::cl::opt<bool> Classes;
extern|extern llvm::cl::opt<bool> Enums;
extern|extern llvm::cl::opt<bool> Typedefs;
extern|extern llvm::cl::opt<bool> All;
extern|extern llvm::cl::opt<bool> ExcludeCompilerGenerated;
extern|extern llvm::cl::opt<bool> NoEnumDefs;
extern|extern llvm::cl::list<std::string> ExcludeTypes;
extern|extern llvm::cl::list<std::string> ExcludeSymbols;
extern|extern llvm::cl::list<std::string> ExcludeCompilands;
extern|extern llvm::cl::list<std::string> IncludeTypes;
extern|extern llvm::cl::list<std::string> IncludeSymbols;
extern|extern llvm::cl::list<std::string> IncludeCompilands;
extern|extern llvm::cl::opt<SymbolSortMode> SymbolOrder;
extern|extern llvm::cl::opt<ClassSortMode> ClassOrder;
extern|extern llvm::cl::opt<uint32_t> SizeThreshold;
extern|extern llvm::cl::opt<uint32_t> PaddingThreshold;
extern|extern llvm::cl::opt<uint32_t> ImmediatePaddingThreshold;
extern|extern llvm::cl::opt<ClassDefinitionFormat> ClassFormat;
extern|extern llvm::cl::opt<uint32_t> ClassRecursionDepth;
block|}
name|namespace
name|bytes
block|{
struct|struct
name|NumberRange
block|{
name|uint64_t
name|Min
decl_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|uint64_t
operator|>
name|Max
expr_stmt|;
block|}
struct|;
extern|extern llvm::Optional<NumberRange> DumpBlockRange;
extern|extern llvm::Optional<NumberRange> DumpByteRange;
extern|extern llvm::cl::list<std::string> DumpStreamData;
extern|extern llvm::cl::opt<bool> NameMap;
extern|extern llvm::cl::opt<bool> SectionContributions;
extern|extern llvm::cl::opt<bool> SectionMap;
extern|extern llvm::cl::opt<bool> ModuleInfos;
extern|extern llvm::cl::opt<bool> FileInfo;
extern|extern llvm::cl::opt<bool> TypeServerMap;
extern|extern llvm::cl::opt<bool> ECData;
extern|extern llvm::cl::list<uint32_t> TypeIndex;
extern|extern llvm::cl::list<uint32_t> IdIndex;
extern|extern llvm::cl::opt<uint32_t> ModuleIndex;
extern|extern llvm::cl::opt<bool> ModuleSyms;
extern|extern llvm::cl::opt<bool> ModuleC11;
extern|extern llvm::cl::opt<bool> ModuleC13;
extern|extern llvm::cl::opt<bool> SplitChunks;
block|}
comment|// namespace bytes
name|namespace
name|dump
block|{
extern|extern llvm::cl::opt<bool> DumpSummary;
extern|extern llvm::cl::opt<bool> DumpStreams;
extern|extern llvm::cl::opt<bool> DumpStreamBlocks;
extern|extern llvm::cl::opt<bool> DumpLines;
extern|extern llvm::cl::opt<bool> DumpInlineeLines;
extern|extern llvm::cl::opt<bool> DumpXmi;
extern|extern llvm::cl::opt<bool> DumpXme;
extern|extern llvm::cl::opt<bool> DumpStringTable;
extern|extern llvm::cl::opt<bool> DumpTypes;
extern|extern llvm::cl::opt<bool> DumpTypeData;
extern|extern llvm::cl::opt<bool> DumpTypeExtras;
extern|extern llvm::cl::list<uint32_t> DumpTypeIndex;
extern|extern llvm::cl::opt<bool> DumpIds;
extern|extern llvm::cl::opt<bool> DumpIdData;
extern|extern llvm::cl::opt<bool> DumpIdExtras;
extern|extern llvm::cl::list<uint32_t> DumpIdIndex;
extern|extern llvm::cl::opt<bool> DumpSymbols;
extern|extern llvm::cl::opt<bool> DumpSymRecordBytes;
extern|extern llvm::cl::opt<bool> DumpPublics;
extern|extern llvm::cl::opt<bool> DumpSectionContribs;
extern|extern llvm::cl::opt<bool> DumpSectionMap;
extern|extern llvm::cl::opt<bool> DumpModules;
extern|extern llvm::cl::opt<bool> DumpModuleFiles;
extern|extern llvm::cl::opt<bool> RawAll;
block|}
name|namespace
name|pdb2yaml
block|{
extern|extern llvm::cl::opt<bool> All;
extern|extern llvm::cl::opt<bool> NoFileHeaders;
extern|extern llvm::cl::opt<bool> Minimal;
extern|extern llvm::cl::opt<bool> StreamMetadata;
extern|extern llvm::cl::opt<bool> StreamDirectory;
extern|extern llvm::cl::opt<bool> StringTable;
extern|extern llvm::cl::opt<bool> PdbStream;
extern|extern llvm::cl::opt<bool> DbiStream;
extern|extern llvm::cl::opt<bool> TpiStream;
extern|extern llvm::cl::opt<bool> IpiStream;
extern|extern llvm::cl::list<std::string> InputFilename;
extern|extern llvm::cl::opt<bool> DumpModules;
extern|extern llvm::cl::opt<bool> DumpModuleFiles;
extern|extern llvm::cl::list<ModuleSubsection> DumpModuleSubsections;
extern|extern llvm::cl::opt<bool> DumpModuleSyms;
block|}
comment|// namespace pdb2yaml
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

