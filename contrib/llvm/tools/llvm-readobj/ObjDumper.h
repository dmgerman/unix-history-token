begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjDumper.h ---------------------------------------------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVM_READOBJ_OBJDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_READOBJ_OBJDUMPER_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|COFFImportFile
decl_stmt|;
name|class
name|ObjectFile
decl_stmt|;
block|}
name|namespace
name|codeview
block|{
name|class
name|TypeTableBuilder
decl_stmt|;
block|}
name|class
name|ScopedPrinter
decl_stmt|;
name|class
name|ObjDumper
block|{
name|public
label|:
name|ObjDumper
argument_list|(
name|ScopedPrinter
operator|&
name|Writer
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|ObjDumper
argument_list|()
expr_stmt|;
name|virtual
name|void
name|printFileHeaders
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printSections
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printRelocations
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printSymbols
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printDynamicSymbols
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printUnwindInfo
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Only implemented for ELF at this time.
name|virtual
name|void
name|printDynamicRelocations
parameter_list|()
block|{ }
name|virtual
name|void
name|printDynamicTable
parameter_list|()
block|{ }
name|virtual
name|void
name|printNeededLibraries
parameter_list|()
block|{ }
name|virtual
name|void
name|printProgramHeaders
parameter_list|()
block|{ }
name|virtual
name|void
name|printHashTable
parameter_list|()
block|{ }
name|virtual
name|void
name|printGnuHashTable
parameter_list|()
block|{ }
name|virtual
name|void
name|printLoadName
parameter_list|()
block|{}
name|virtual
name|void
name|printVersionInfo
parameter_list|()
block|{}
name|virtual
name|void
name|printGroupSections
parameter_list|()
block|{}
name|virtual
name|void
name|printHashHistogram
parameter_list|()
block|{}
name|virtual
name|void
name|printNotes
parameter_list|()
block|{}
comment|// Only implemented for ARM ELF at this time.
name|virtual
name|void
name|printAttributes
parameter_list|()
block|{ }
comment|// Only implemented for MIPS ELF at this time.
name|virtual
name|void
name|printMipsPLTGOT
parameter_list|()
block|{ }
name|virtual
name|void
name|printMipsABIFlags
parameter_list|()
block|{ }
name|virtual
name|void
name|printMipsReginfo
parameter_list|()
block|{ }
name|virtual
name|void
name|printMipsOptions
parameter_list|()
block|{ }
comment|// Only implemented for AMDGPU ELF at this time.
name|virtual
name|void
name|printAMDGPUCodeObjectMetadata
parameter_list|()
block|{}
comment|// Only implemented for PE/COFF.
name|virtual
name|void
name|printCOFFImports
parameter_list|()
block|{ }
name|virtual
name|void
name|printCOFFExports
parameter_list|()
block|{ }
name|virtual
name|void
name|printCOFFDirectives
parameter_list|()
block|{ }
name|virtual
name|void
name|printCOFFBaseReloc
parameter_list|()
block|{ }
name|virtual
name|void
name|printCOFFDebugDirectory
parameter_list|()
block|{ }
name|virtual
name|void
name|printCOFFResources
parameter_list|()
block|{}
name|virtual
name|void
name|printCOFFLoadConfig
parameter_list|()
block|{ }
name|virtual
name|void
name|printCodeViewDebugInfo
parameter_list|()
block|{ }
name|virtual
name|void
name|mergeCodeViewTypes
argument_list|(
name|llvm
operator|::
name|codeview
operator|::
name|TypeTableBuilder
operator|&
name|CVIDs
argument_list|,
name|llvm
operator|::
name|codeview
operator|::
name|TypeTableBuilder
operator|&
name|CVTypes
argument_list|)
block|{}
comment|// Only implemented for MachO.
name|virtual
name|void
name|printMachODataInCode
parameter_list|()
block|{ }
name|virtual
name|void
name|printMachOVersionMin
parameter_list|()
block|{ }
name|virtual
name|void
name|printMachODysymtab
parameter_list|()
block|{ }
name|virtual
name|void
name|printMachOSegment
parameter_list|()
block|{ }
name|virtual
name|void
name|printMachOIndirectSymbols
parameter_list|()
block|{ }
name|virtual
name|void
name|printMachOLinkerOptions
parameter_list|()
block|{ }
name|virtual
name|void
name|printStackMap
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|ScopedPrinter
modifier|&
name|W
decl_stmt|;
block|}
empty_stmt|;
name|std
operator|::
name|error_code
name|createCOFFDumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|ScopedPrinter
operator|&
name|Writer
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|createELFDumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|ScopedPrinter
operator|&
name|Writer
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|createMachODumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|ScopedPrinter
operator|&
name|Writer
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|createWasmDumper
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
name|Obj
argument_list|,
name|ScopedPrinter
operator|&
name|Writer
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ObjDumper
operator|>
operator|&
name|Result
argument_list|)
expr_stmt|;
name|void
name|dumpCOFFImportFile
argument_list|(
specifier|const
name|object
operator|::
name|COFFImportFile
operator|*
name|File
argument_list|)
decl_stmt|;
name|void
name|dumpCodeViewMergedTypes
argument_list|(
name|ScopedPrinter
operator|&
name|Writer
argument_list|,
name|llvm
operator|::
name|codeview
operator|::
name|TypeTableBuilder
operator|&
name|IDTable
argument_list|,
name|llvm
operator|::
name|codeview
operator|::
name|TypeTableBuilder
operator|&
name|TypeTable
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

