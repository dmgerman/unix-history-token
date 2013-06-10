begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MachO.h - MachO object file implementation ---------------*- C++ -*-===//
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
comment|// This file declares the MachOObjectFile class, which implement the ObjectFile
end_comment

begin_comment
comment|// interface for MachO files.
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
name|LLVM_OBJECT_MACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_MACHO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/MachOFormat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MachO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|MachOObjectFile
range|:
name|public
name|ObjectFile
block|{
name|public
operator|:
expr|struct
name|LoadCommandInfo
block|{
specifier|const
name|char
operator|*
name|Ptr
block|;
comment|// Where in memory the load command is.
name|macho
operator|::
name|LoadCommand
name|C
block|;
comment|// The command itself.
block|}
block|;
name|MachOObjectFile
argument_list|(
argument|MemoryBuffer *Object
argument_list|,
argument|bool IsLittleEndian
argument_list|,
argument|bool Is64Bits
argument_list|,
argument|error_code&ec
argument_list|)
block|;
name|virtual
name|error_code
name|getSymbolNext
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|SymbolRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolName
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|StringRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolAddress
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolFileOffset
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolAlignment
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|uint32_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolSize
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolType
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|SymbolRef::Type&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolNMTypeChar
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|char&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolFlags
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|uint32_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolSection
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|section_iterator&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSymbolValue
argument_list|(
argument|DataRefImpl Symb
argument_list|,
argument|uint64_t&Val
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSectionNext
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|SectionRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSectionName
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|StringRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSectionAddress
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSectionSize
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSectionContents
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|StringRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getSectionAlignment
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionText
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionData
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionBSS
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionRequiredForExecution
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionVirtual
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionZeroInit
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|isSectionReadOnlyData
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|bool&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|sectionContainsSymbol
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|DataRefImpl Symb
argument_list|,
argument|bool&Result
argument_list|)
specifier|const
block|;
name|virtual
name|relocation_iterator
name|getSectionRelBegin
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
block|;
name|virtual
name|relocation_iterator
name|getSectionRelEnd
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationNext
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|RelocationRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationAddress
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationOffset
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationSymbol
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|SymbolRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationType
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|uint64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationTypeName
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|SmallVectorImpl<char>&Result
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationAdditionalInfo
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|int64_t&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationValueString
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|SmallVectorImpl<char>&Result
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getRelocationHidden
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|bool&Result
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getLibraryNext
argument_list|(
argument|DataRefImpl LibData
argument_list|,
argument|LibraryRef&Res
argument_list|)
specifier|const
block|;
name|virtual
name|error_code
name|getLibraryPath
argument_list|(
argument|DataRefImpl LibData
argument_list|,
argument|StringRef&Res
argument_list|)
specifier|const
block|;
comment|// TODO: Would be useful to have an iterator based version
comment|// of the load command interface too.
name|virtual
name|symbol_iterator
name|begin_symbols
argument_list|()
specifier|const
block|;
name|virtual
name|symbol_iterator
name|end_symbols
argument_list|()
specifier|const
block|;
name|virtual
name|symbol_iterator
name|begin_dynamic_symbols
argument_list|()
specifier|const
block|;
name|virtual
name|symbol_iterator
name|end_dynamic_symbols
argument_list|()
specifier|const
block|;
name|virtual
name|section_iterator
name|begin_sections
argument_list|()
specifier|const
block|;
name|virtual
name|section_iterator
name|end_sections
argument_list|()
specifier|const
block|;
name|virtual
name|library_iterator
name|begin_libraries_needed
argument_list|()
specifier|const
block|;
name|virtual
name|library_iterator
name|end_libraries_needed
argument_list|()
specifier|const
block|;
name|virtual
name|uint8_t
name|getBytesInAddress
argument_list|()
specifier|const
block|;
name|virtual
name|StringRef
name|getFileFormatName
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getArch
argument_list|()
specifier|const
block|;
name|virtual
name|StringRef
name|getLoadName
argument_list|()
specifier|const
block|;
name|relocation_iterator
name|getSectionRelBegin
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
name|relocation_iterator
name|getSectionRelEnd
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|// In a MachO file, sections have a segment name. This is used in the .o
comment|// files. They have a single segment, but this field specifies which segment
comment|// a section should be put in in the final object.
name|StringRef
name|getSectionFinalSegmentName
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
block|;
comment|// Names are stored as 16 bytes. These returns the raw 16 bytes without
comment|// interpreting them as a C string.
name|ArrayRef
operator|<
name|char
operator|>
name|getSectionRawName
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
block|;
name|ArrayRef
operator|<
name|char
operator|>
name|getSectionRawFinalSegmentName
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
block|;
comment|// MachO specific Info about relocations.
name|bool
name|isRelocationScattered
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|unsigned
name|getPlainRelocationSymbolNum
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|bool
name|getPlainRelocationExternal
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|bool
name|getScatteredRelocationScattered
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|uint32_t
name|getScatteredRelocationValue
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|unsigned
name|getAnyRelocationAddress
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|unsigned
name|getAnyRelocationPCRel
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|unsigned
name|getAnyRelocationLength
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|unsigned
name|getAnyRelocationType
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
name|SectionRef
name|getRelocationSection
argument_list|(
argument|const macho::RelocationEntry&RE
argument_list|)
specifier|const
block|;
comment|// Walk load commands.
name|LoadCommandInfo
name|getFirstLoadCommandInfo
argument_list|()
specifier|const
block|;
name|LoadCommandInfo
name|getNextLoadCommandInfo
argument_list|(
argument|const LoadCommandInfo&L
argument_list|)
specifier|const
block|;
comment|// MachO specific structures.
name|macho
operator|::
name|Section
name|getSection
argument_list|(
argument|DataRefImpl DRI
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|Section64
name|getSection64
argument_list|(
argument|DataRefImpl DRI
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|Section
name|getSection
argument_list|(
argument|const LoadCommandInfo&L
argument_list|,
argument|unsigned Index
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|Section64
name|getSection64
argument_list|(
argument|const LoadCommandInfo&L
argument_list|,
argument|unsigned Index
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|SymbolTableEntry
name|getSymbolTableEntry
argument_list|(
argument|DataRefImpl DRI
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|Symbol64TableEntry
name|getSymbol64TableEntry
argument_list|(
argument|DataRefImpl DRI
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|LinkeditDataLoadCommand
name|getLinkeditDataLoadCommand
argument_list|(
argument|const LoadCommandInfo&L
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|SegmentLoadCommand
name|getSegmentLoadCommand
argument_list|(
argument|const LoadCommandInfo&L
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|Segment64LoadCommand
name|getSegment64LoadCommand
argument_list|(
argument|const LoadCommandInfo&L
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|LinkerOptionsLoadCommand
name|getLinkerOptionsLoadCommand
argument_list|(
argument|const LoadCommandInfo&L
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|RelocationEntry
name|getRelocation
argument_list|(
argument|DataRefImpl Rel
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|Header
name|getHeader
argument_list|()
specifier|const
block|;
name|macho
operator|::
name|Header64Ext
name|getHeader64Ext
argument_list|()
specifier|const
block|;
name|macho
operator|::
name|IndirectSymbolTableEntry
name|getIndirectSymbolTableEntry
argument_list|(
argument|const macho::DysymtabLoadCommand&DLC
argument_list|,
argument|unsigned Index
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|DataInCodeTableEntry
name|getDataInCodeTableEntry
argument_list|(
argument|uint32_t DataOffset
argument_list|,
argument|unsigned Index
argument_list|)
specifier|const
block|;
name|macho
operator|::
name|SymtabLoadCommand
name|getSymtabLoadCommand
argument_list|()
specifier|const
block|;
name|macho
operator|::
name|DysymtabLoadCommand
name|getDysymtabLoadCommand
argument_list|()
specifier|const
block|;
name|StringRef
name|getStringTableData
argument_list|()
specifier|const
block|;
name|bool
name|is64Bit
argument_list|()
specifier|const
block|;
name|void
name|ReadULEB128s
argument_list|(
argument|uint64_t Index
argument_list|,
argument|SmallVectorImpl<uint64_t>&Out
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Binary *v
argument_list|)
block|{
return|return
name|v
operator|->
name|isMachO
argument_list|()
return|;
block|}
name|private
operator|:
typedef|typedef
name|SmallVector
operator|<
specifier|const
name|char
operator|*
operator|,
literal|1
operator|>
name|SectionList
expr_stmt|;
name|SectionList
name|Sections
decl_stmt|;
specifier|const
name|char
modifier|*
name|SymtabLoadCmd
decl_stmt|;
specifier|const
name|char
modifier|*
name|DysymtabLoadCmd
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

