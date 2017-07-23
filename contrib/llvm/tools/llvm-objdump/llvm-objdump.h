begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|LLVM_TOOLS_LLVM_OBJDUMP_LLVM_OBJDUMP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_OBJDUMP_LLVM_OBJDUMP_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Archive.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|COFFObjectFile
decl_stmt|;
name|class
name|COFFImportFile
decl_stmt|;
name|class
name|MachOObjectFile
decl_stmt|;
name|class
name|ObjectFile
decl_stmt|;
name|class
name|Archive
decl_stmt|;
name|class
name|RelocationRef
decl_stmt|;
block|}
extern|extern cl::opt<std::string> TripleName;
extern|extern cl::opt<std::string> ArchName;
extern|extern cl::opt<std::string> MCPU;
extern|extern cl::list<std::string> MAttrs;
extern|extern cl::list<std::string> FilterSections;
extern|extern cl::opt<bool> Disassemble;
extern|extern cl::opt<bool> DisassembleAll;
extern|extern cl::opt<bool> NoShowRawInsn;
extern|extern cl::opt<bool> NoLeadingAddr;
extern|extern cl::opt<bool> PrivateHeaders;
extern|extern cl::opt<bool> FirstPrivateHeader;
extern|extern cl::opt<bool> ExportsTrie;
extern|extern cl::opt<bool> Rebase;
extern|extern cl::opt<bool> Bind;
extern|extern cl::opt<bool> LazyBind;
extern|extern cl::opt<bool> WeakBind;
extern|extern cl::opt<bool> RawClangAST;
extern|extern cl::opt<bool> UniversalHeaders;
extern|extern cl::opt<bool> ArchiveHeaders;
extern|extern cl::opt<bool> IndirectSymbols;
extern|extern cl::opt<bool> DataInCode;
extern|extern cl::opt<bool> LinkOptHints;
extern|extern cl::opt<bool> InfoPlist;
extern|extern cl::opt<bool> DylibsUsed;
extern|extern cl::opt<bool> DylibId;
extern|extern cl::opt<bool> ObjcMetaData;
extern|extern cl::opt<std::string> DisSymName;
extern|extern cl::opt<bool> NonVerbose;
extern|extern cl::opt<bool> Relocations;
extern|extern cl::opt<bool> SectionHeaders;
extern|extern cl::opt<bool> SectionContents;
extern|extern cl::opt<bool> SymbolTable;
extern|extern cl::opt<bool> UnwindInfo;
extern|extern cl::opt<bool> PrintImmHex;
extern|extern cl::opt<DIDumpType> DwarfDumpType;
comment|// Various helper functions.
name|void
name|error
argument_list|(
name|std
operator|::
name|error_code
name|ec
argument_list|)
decl_stmt|;
name|bool
name|RelocAddressLess
argument_list|(
name|object
operator|::
name|RelocationRef
name|a
argument_list|,
name|object
operator|::
name|RelocationRef
name|b
argument_list|)
decl_stmt|;
name|void
name|ParseInputMachO
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
function_decl|;
name|void
name|printCOFFUnwindInfo
argument_list|(
specifier|const
name|object
operator|::
name|COFFObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOUnwindInfo
argument_list|(
specifier|const
name|object
operator|::
name|MachOObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOExportsTrie
argument_list|(
specifier|const
name|object
operator|::
name|MachOObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachORebaseTable
argument_list|(
name|object
operator|::
name|MachOObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOBindTable
argument_list|(
name|object
operator|::
name|MachOObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOLazyBindTable
argument_list|(
name|object
operator|::
name|MachOObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOWeakBindTable
argument_list|(
name|object
operator|::
name|MachOObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printELFFileHeader
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printCOFFFileHeader
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printCOFFSymbolTable
argument_list|(
specifier|const
name|object
operator|::
name|COFFImportFile
operator|*
name|i
argument_list|)
decl_stmt|;
name|void
name|printCOFFSymbolTable
argument_list|(
specifier|const
name|object
operator|::
name|COFFObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOFileHeader
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printMachOLoadCommands
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printWasmFileHeader
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printExportsTrie
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printRebaseTable
argument_list|(
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printBindTable
argument_list|(
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printLazyBindTable
argument_list|(
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printWeakBindTable
argument_list|(
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|printRawClangAST
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|PrintRelocations
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|PrintSectionHeaders
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|PrintSectionContents
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|)
decl_stmt|;
name|void
name|PrintSymbolTable
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|o
argument_list|,
name|StringRef
name|ArchiveName
argument_list|,
name|StringRef
name|ArchitectureName
operator|=
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|error
parameter_list|(
name|Twine
name|Message
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_error
parameter_list|(
name|StringRef
name|File
parameter_list|,
name|Twine
name|Message
parameter_list|)
function_decl|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_error
argument_list|(
name|StringRef
name|File
argument_list|,
name|std
operator|::
name|error_code
name|EC
argument_list|)
decl_stmt|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_error
argument_list|(
name|StringRef
name|File
argument_list|,
name|llvm
operator|::
name|Error
name|E
argument_list|)
decl_stmt|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_error
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|StringRef
name|ArchiveName
argument_list|,
name|llvm
operator|::
name|Error
name|E
argument_list|,
name|StringRef
name|ArchitectureName
operator|=
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_error
argument_list|(
name|StringRef
name|ArchiveName
argument_list|,
specifier|const
name|object
operator|::
name|Archive
operator|::
name|Child
operator|&
name|C
argument_list|,
name|llvm
operator|::
name|Error
name|E
argument_list|,
name|StringRef
name|ArchitectureName
operator|=
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

