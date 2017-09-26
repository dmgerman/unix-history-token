begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/MachO/MachONormalizedFile.h -----------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file These data structures comprise the "normalized" view of
end_comment

begin_comment
comment|/// mach-o object files. The normalized view is an in-memory only data structure
end_comment

begin_comment
comment|/// which is always in native endianness and pointer size.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The normalized view easily converts to and from YAML using YAML I/O.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The normalized view converts to and from binary mach-o object files using
end_comment

begin_comment
comment|/// the writeBinary() and readBinary() functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The normalized view converts to and from lld::Atoms using the
end_comment

begin_comment
comment|/// normalizedToAtoms() and normalizedFromAtoms().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Overall, the conversion paths available look like:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///                 +---------------+
end_comment

begin_comment
comment|///                 | binary mach-o |
end_comment

begin_comment
comment|///                 +---------------+
end_comment

begin_comment
comment|///                        ^
end_comment

begin_comment
comment|///                        |
end_comment

begin_comment
comment|///                        v
end_comment

begin_comment
comment|///                  +------------+         +------+
end_comment

begin_comment
comment|///                  | normalized |<->   | yaml |
end_comment

begin_comment
comment|///                  +------------+         +------+
end_comment

begin_comment
comment|///                        ^
end_comment

begin_comment
comment|///                        |
end_comment

begin_comment
comment|///                        v
end_comment

begin_comment
comment|///                    +-------+
end_comment

begin_comment
comment|///                    | Atoms |
end_comment

begin_comment
comment|///                    +-------+
end_comment

begin_comment
comment|///
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_MACHO_NORMALIZE_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_NORMALIZE_FILE_H
end_define

begin_include
include|#
directive|include
file|"DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/MachOLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/MachO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_expr_stmt
name|using
name|llvm
operator|::
name|BumpPtrAllocator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|yaml
operator|::
name|Hex64
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|yaml
operator|::
name|Hex32
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|yaml
operator|::
name|Hex16
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|yaml
operator|::
name|Hex8
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|yaml
operator|::
name|SequenceTraits
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|HeaderFileType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|BindType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|RebaseType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|NListType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|RelocationInfoType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|SectionType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|LoadCommandType
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|ExportSymbolKind
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|MachO
operator|::
name|DataRegionType
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|mach_o
block|{
name|namespace
name|normalized
block|{
comment|/// The real mach-o relocation record is 8-bytes on disk and is
comment|/// encoded in one of two different bit-field patterns.  This
comment|/// normalized form has the union of all possible fields.
struct|struct
name|Relocation
block|{
name|Relocation
argument_list|()
operator|:
name|offset
argument_list|(
literal|0
argument_list|)
operator|,
name|scattered
argument_list|(
name|false
argument_list|)
operator|,
name|type
argument_list|(
name|llvm
operator|::
name|MachO
operator|::
name|GENERIC_RELOC_VANILLA
argument_list|)
operator|,
name|length
argument_list|(
literal|0
argument_list|)
operator|,
name|pcRel
argument_list|(
name|false
argument_list|)
operator|,
name|isExtern
argument_list|(
name|false
argument_list|)
operator|,
name|value
argument_list|(
literal|0
argument_list|)
operator|,
name|symbol
argument_list|(
literal|0
argument_list|)
block|{ }
name|Hex32
name|offset
expr_stmt|;
name|bool
name|scattered
decl_stmt|;
name|RelocationInfoType
name|type
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|bool
name|pcRel
decl_stmt|;
name|bool
name|isExtern
decl_stmt|;
name|Hex32
name|value
decl_stmt|;
name|uint32_t
name|symbol
decl_stmt|;
block|}
struct|;
comment|/// A typedef so that YAML I/O can treat this vector as a sequence.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Relocation
operator|>
name|Relocations
expr_stmt|;
comment|/// A typedef so that YAML I/O can process the raw bytes in a section.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Hex8
operator|>
name|ContentBytes
expr_stmt|;
comment|/// A typedef so that YAML I/O can treat indirect symbols as a flow sequence.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|IndirectSymbols
expr_stmt|;
comment|/// A typedef so that YAML I/O can encode/decode section attributes.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint32_t
argument_list|,
argument|SectionAttr
argument_list|)
comment|/// A typedef so that YAML I/O can encode/decode section alignment.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint16_t
argument_list|,
argument|SectionAlignment
argument_list|)
comment|/// Mach-O has a 32-bit and 64-bit section record.  This normalized form
comment|/// can support either kind.
struct|struct
name|Section
block|{
name|Section
argument_list|()
operator|:
name|type
argument_list|(
name|llvm
operator|::
name|MachO
operator|::
name|S_REGULAR
argument_list|)
operator|,
name|attributes
argument_list|(
literal|0
argument_list|)
operator|,
name|alignment
argument_list|(
literal|1
argument_list|)
operator|,
name|address
argument_list|(
literal|0
argument_list|)
block|{ }
name|StringRef
name|segmentName
expr_stmt|;
name|StringRef
name|sectionName
decl_stmt|;
name|SectionType
name|type
decl_stmt|;
name|SectionAttr
name|attributes
decl_stmt|;
name|SectionAlignment
name|alignment
decl_stmt|;
name|Hex64
name|address
decl_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|content
expr_stmt|;
name|Relocations
name|relocations
decl_stmt|;
name|IndirectSymbols
name|indirectSymbols
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|)
specifier|const
block|{
name|dump
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
operator|=
name|llvm
operator|::
name|dbgs
argument_list|()
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
comment|/// A typedef so that YAML I/O can encode/decode the scope bits of an nlist.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint8_t
argument_list|,
argument|SymbolScope
argument_list|)
comment|/// A typedef so that YAML I/O can encode/decode the desc bits of an nlist.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint16_t
argument_list|,
argument|SymbolDesc
argument_list|)
comment|/// Mach-O has a 32-bit and 64-bit symbol table entry (nlist), and the symbol
comment|/// type and scope and mixed in the same n_type field.  This normalized form
comment|/// works for any pointer size and separates out the type and scope.
struct|struct
name|Symbol
block|{
name|Symbol
argument_list|()
operator|:
name|type
argument_list|(
name|llvm
operator|::
name|MachO
operator|::
name|N_UNDF
argument_list|)
operator|,
name|scope
argument_list|(
literal|0
argument_list|)
operator|,
name|sect
argument_list|(
literal|0
argument_list|)
operator|,
name|desc
argument_list|(
literal|0
argument_list|)
operator|,
name|value
argument_list|(
literal|0
argument_list|)
block|{ }
name|StringRef
name|name
expr_stmt|;
name|NListType
name|type
decl_stmt|;
name|SymbolScope
name|scope
decl_stmt|;
name|uint8_t
name|sect
decl_stmt|;
name|SymbolDesc
name|desc
decl_stmt|;
name|Hex64
name|value
decl_stmt|;
block|}
struct|;
comment|/// Check whether the given section type indicates a zero-filled section.
comment|// FIXME: Utility functions of this kind should probably be moved into
comment|//        llvm/Support.
specifier|inline
name|bool
name|isZeroFillSection
parameter_list|(
name|SectionType
name|T
parameter_list|)
block|{
return|return
operator|(
name|T
operator|==
name|llvm
operator|::
name|MachO
operator|::
name|S_ZEROFILL
operator|||
name|T
operator|==
name|llvm
operator|::
name|MachO
operator|::
name|S_THREAD_LOCAL_ZEROFILL
operator|)
return|;
block|}
comment|/// A typedef so that YAML I/O can (de/en)code the protection bits of a segment.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint32_t
argument_list|,
argument|VMProtect
argument_list|)
comment|/// A typedef to hold verions X.Y.X packed into 32-bit xxxx.yy.zz
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint32_t
argument_list|,
argument|PackedVersion
argument_list|)
comment|/// Segments are only used in normalized final linked images (not in relocatable
comment|/// object files). They specify how a range of the file is loaded.
struct|struct
name|Segment
block|{
name|StringRef
name|name
decl_stmt|;
name|Hex64
name|address
decl_stmt|;
name|Hex64
name|size
decl_stmt|;
name|VMProtect
name|init_access
decl_stmt|;
name|VMProtect
name|max_access
decl_stmt|;
block|}
struct|;
comment|/// Only used in normalized final linked images to specify on which dylibs
comment|/// it depends.
struct|struct
name|DependentDylib
block|{
name|StringRef
name|path
decl_stmt|;
name|LoadCommandType
name|kind
decl_stmt|;
name|PackedVersion
name|compatVersion
decl_stmt|;
name|PackedVersion
name|currentVersion
decl_stmt|;
block|}
struct|;
comment|/// A normalized rebasing entry.  Only used in normalized final linked images.
struct|struct
name|RebaseLocation
block|{
name|Hex32
name|segOffset
decl_stmt|;
name|uint8_t
name|segIndex
decl_stmt|;
name|RebaseType
name|kind
decl_stmt|;
block|}
struct|;
comment|/// A normalized binding entry.  Only used in normalized final linked images.
struct|struct
name|BindLocation
block|{
name|Hex32
name|segOffset
decl_stmt|;
name|uint8_t
name|segIndex
decl_stmt|;
name|BindType
name|kind
decl_stmt|;
name|bool
name|canBeNull
decl_stmt|;
name|int
name|ordinal
decl_stmt|;
name|StringRef
name|symbolName
decl_stmt|;
name|Hex64
name|addend
decl_stmt|;
block|}
struct|;
comment|/// A typedef so that YAML I/O can encode/decode export flags.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint32_t
argument_list|,
argument|ExportFlags
argument_list|)
comment|/// A normalized export entry.  Only used in normalized final linked images.
struct|struct
name|Export
block|{
name|StringRef
name|name
decl_stmt|;
name|Hex64
name|offset
decl_stmt|;
name|ExportSymbolKind
name|kind
decl_stmt|;
name|ExportFlags
name|flags
decl_stmt|;
name|Hex32
name|otherOffset
decl_stmt|;
name|StringRef
name|otherName
decl_stmt|;
block|}
struct|;
comment|/// A normalized data-in-code entry.
struct|struct
name|DataInCode
block|{
name|Hex32
name|offset
decl_stmt|;
name|Hex16
name|length
decl_stmt|;
name|DataRegionType
name|kind
decl_stmt|;
block|}
struct|;
comment|/// A typedef so that YAML I/O can encode/decode mach_header.flags.
name|LLVM_YAML_STRONG_TYPEDEF
argument_list|(
argument|uint32_t
argument_list|,
argument|FileFlags
argument_list|)
comment|///
struct|struct
name|NormalizedFile
block|{
name|MachOLinkingContext
operator|::
name|Arch
name|arch
operator|=
name|MachOLinkingContext
operator|::
name|arch_unknown
expr_stmt|;
name|HeaderFileType
name|fileType
init|=
name|llvm
operator|::
name|MachO
operator|::
name|MH_OBJECT
decl_stmt|;
name|FileFlags
name|flags
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Segment
operator|>
name|segments
expr_stmt|;
comment|// Not used in object files.
name|std
operator|::
name|vector
operator|<
name|Section
operator|>
name|sections
expr_stmt|;
comment|// Symbols sorted by kind.
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|>
name|localSymbols
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|>
name|globalSymbols
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|>
name|undefinedSymbols
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|>
name|stabsSymbols
expr_stmt|;
comment|// Maps to load commands with no LINKEDIT content (final linked images only).
name|std
operator|::
name|vector
operator|<
name|DependentDylib
operator|>
name|dependentDylibs
expr_stmt|;
name|StringRef
name|installName
decl_stmt|;
comment|// dylibs only
name|PackedVersion
name|compatVersion
init|=
literal|0
decl_stmt|;
comment|// dylibs only
name|PackedVersion
name|currentVersion
init|=
literal|0
decl_stmt|;
comment|// dylibs only
name|bool
name|hasUUID
init|=
name|false
decl_stmt|;
name|bool
name|hasMinVersionLoadCommand
init|=
name|false
decl_stmt|;
name|bool
name|generateDataInCodeLoadCommand
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|rpaths
expr_stmt|;
name|Hex64
name|entryAddress
init|=
literal|0
decl_stmt|;
name|Hex64
name|stackSize
init|=
literal|0
decl_stmt|;
name|MachOLinkingContext
operator|::
name|OS
name|os
operator|=
name|MachOLinkingContext
operator|::
name|OS
operator|::
name|unknown
expr_stmt|;
name|Hex64
name|sourceVersion
init|=
literal|0
decl_stmt|;
name|PackedVersion
name|minOSverson
init|=
literal|0
decl_stmt|;
name|PackedVersion
name|sdkVersion
init|=
literal|0
decl_stmt|;
name|LoadCommandType
name|minOSVersionKind
init|=
operator|(
name|LoadCommandType
operator|)
literal|0
decl_stmt|;
comment|// Maps to load commands with LINKEDIT content (final linked images only).
name|Hex32
name|pageSize
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|RebaseLocation
operator|>
name|rebasingInfo
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BindLocation
operator|>
name|bindingInfo
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BindLocation
operator|>
name|weakBindingInfo
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BindLocation
operator|>
name|lazyBindingInfo
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Export
operator|>
name|exportInfo
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|functionStarts
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|DataInCode
operator|>
name|dataInCode
expr_stmt|;
comment|// TODO:
comment|// code-signature
comment|// split-seg-info
comment|// function-starts
comment|// For any allocations in this struct which need to be owned by this struct.
name|BumpPtrAllocator
name|ownedAllocations
decl_stmt|;
block|}
struct|;
comment|/// Tests if a file is a non-fat mach-o object file.
name|bool
name|isThinObjectFile
argument_list|(
name|StringRef
name|path
argument_list|,
name|MachOLinkingContext
operator|::
name|Arch
operator|&
name|arch
argument_list|)
decl_stmt|;
comment|/// If the buffer is a fat file with the request arch, then this function
comment|/// returns true with 'offset' and 'size' set to location of the arch slice
comment|/// within the buffer.  Otherwise returns false;
name|bool
name|sliceFromFatFile
argument_list|(
name|MemoryBufferRef
name|mb
argument_list|,
name|MachOLinkingContext
operator|::
name|Arch
name|arch
argument_list|,
name|uint32_t
operator|&
name|offset
argument_list|,
name|uint32_t
operator|&
name|size
argument_list|)
decl_stmt|;
comment|/// Reads a mach-o file and produces an in-memory normalized view.
name|llvm
operator|::
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|NormalizedFile
operator|>>
name|readBinary
argument_list|(
argument|std::unique_ptr<MemoryBuffer>&mb
argument_list|,
argument|const MachOLinkingContext::Arch arch
argument_list|)
expr_stmt|;
comment|/// Takes in-memory normalized view and writes a mach-o object file.
name|llvm
operator|::
name|Error
name|writeBinary
argument_list|(
argument|const NormalizedFile&file
argument_list|,
argument|StringRef path
argument_list|)
expr_stmt|;
name|size_t
name|headerAndLoadCommandsSize
parameter_list|(
specifier|const
name|NormalizedFile
modifier|&
name|file
parameter_list|)
function_decl|;
comment|/// Parses a yaml encoded mach-o file to produce an in-memory normalized view.
name|llvm
operator|::
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|NormalizedFile
operator|>>
name|readYaml
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|mb
argument_list|)
expr_stmt|;
comment|/// Writes a yaml encoded mach-o files given an in-memory normalized view.
name|std
operator|::
name|error_code
name|writeYaml
argument_list|(
specifier|const
name|NormalizedFile
operator|&
name|file
argument_list|,
name|raw_ostream
operator|&
name|out
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Error
name|normalizedObjectToAtoms
argument_list|(
argument|MachOFile *file
argument_list|,
argument|const NormalizedFile&normalizedFile
argument_list|,
argument|bool copyRefs
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Error
name|normalizedDylibToAtoms
argument_list|(
argument|MachODylibFile *file
argument_list|,
argument|const NormalizedFile&normalizedFile
argument_list|,
argument|bool copyRefs
argument_list|)
expr_stmt|;
comment|/// Takes in-memory normalized dylib or object and parses it into lld::File
name|llvm
operator|::
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|lld
operator|::
name|File
operator|>>
name|normalizedToAtoms
argument_list|(
argument|const NormalizedFile&normalizedFile
argument_list|,
argument|StringRef path
argument_list|,
argument|bool copyRefs
argument_list|)
expr_stmt|;
comment|/// Takes atoms and generates a normalized macho-o view.
name|llvm
operator|::
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|NormalizedFile
operator|>>
name|normalizedFromAtoms
argument_list|(
specifier|const
name|lld
operator|::
name|File
operator|&
name|atomFile
argument_list|,
specifier|const
name|MachOLinkingContext
operator|&
name|ctxt
argument_list|)
expr_stmt|;
block|}
comment|// namespace normalized
comment|/// Class for interfacing mach-o yaml files into generic yaml parsing
name|class
name|MachOYamlIOTaggedDocumentHandler
range|:
name|public
name|YamlIOTaggedDocumentHandler
block|{
name|public
operator|:
name|MachOYamlIOTaggedDocumentHandler
argument_list|(
argument|MachOLinkingContext::Arch arch
argument_list|)
operator|:
name|_arch
argument_list|(
argument|arch
argument_list|)
block|{ }
name|bool
name|handledDocTag
argument_list|(
argument|llvm::yaml::IO&io
argument_list|,
argument|const lld::File *&file
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|MachOLinkingContext
operator|::
name|Arch
name|_arch
block|; }
decl_stmt|;
block|}
comment|// namespace mach_o
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_MACHO_NORMALIZE_FILE_H
end_comment

end_unit

