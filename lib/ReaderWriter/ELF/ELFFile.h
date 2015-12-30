begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/ELFFile.h ---------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_ELF_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_FILE_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"FileCommon.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief Read a binary, find out based on the symbol table contents what kind
comment|/// of symbol it is and create corresponding atoms for it
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ELFFile
operator|:
name|public
name|SimpleFile
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Sym_Impl
operator|<
name|ELFT
operator|>
name|Elf_Sym
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Shdr_Impl
operator|<
name|ELFT
operator|>
name|Elf_Shdr
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|false
operator|>
name|Elf_Rel
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Rel_Impl
operator|<
name|ELFT
operator|,
name|true
operator|>
name|Elf_Rela
expr_stmt|;
typedef|typedef
name|typename
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
operator|::
name|Elf_Word
name|Elf_Word
expr_stmt|;
comment|// A Map is used to hold the atoms that have been divided up
comment|// after reading the section that contains Merge String attributes
struct|struct
name|MergeSectionKey
block|{
specifier|const
name|Elf_Shdr
modifier|*
name|_shdr
decl_stmt|;
name|int64_t
name|_offset
decl_stmt|;
block|}
struct|;
struct|struct
name|MergeSectionEq
block|{
name|int64_t
name|operator
argument_list|()
operator|(
specifier|const
name|MergeSectionKey
operator|&
name|k
operator|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|hash_combine
argument_list|(
call|(
name|int64_t
call|)
argument_list|(
name|k
operator|.
name|_shdr
operator|->
name|sh_name
argument_list|)
argument_list|,
operator|(
name|int64_t
operator|)
name|k
operator|.
name|_offset
argument_list|)
return|;
block|}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|MergeSectionKey
operator|&
name|lhs
operator|,
specifier|const
name|MergeSectionKey
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|(
operator|(
name|lhs
operator|.
name|_shdr
operator|->
name|sh_name
operator|==
name|rhs
operator|.
name|_shdr
operator|->
name|sh_name
operator|)
operator|&&
operator|(
name|lhs
operator|.
name|_offset
operator|==
name|rhs
operator|.
name|_offset
operator|)
operator|)
return|;
block|}
block|}
struct|;
struct|struct
name|MergeString
block|{
name|MergeString
argument_list|(
argument|int64_t offset
argument_list|,
argument|StringRef str
argument_list|,
argument|const Elf_Shdr *shdr
argument_list|,
argument|StringRef sectionName
argument_list|)
block|:
name|_offset
argument_list|(
name|offset
argument_list|)
operator|,
name|_string
argument_list|(
name|str
argument_list|)
operator|,
name|_shdr
argument_list|(
name|shdr
argument_list|)
operator|,
name|_sectionName
argument_list|(
argument|sectionName
argument_list|)
block|{}
comment|// the offset of this atom
name|int64_t
name|_offset
expr_stmt|;
comment|// The content
name|StringRef
name|_string
decl_stmt|;
comment|// Section header
specifier|const
name|Elf_Shdr
modifier|*
name|_shdr
decl_stmt|;
comment|// Section name
name|StringRef
name|_sectionName
decl_stmt|;
block|}
struct|;
comment|// This is used to find the MergeAtom given a relocation
comment|// offset
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ELFMergeAtom
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|MergeAtomsT
expr_stmt|;
comment|/// \brief find a merge atom given a offset
name|ELFMergeAtom
operator|<
name|ELFT
operator|>
operator|*
name|findMergeAtom
argument_list|(
argument|const Elf_Shdr *shdr
argument_list|,
argument|int64_t offset
argument_list|)
block|{
name|auto
name|it
operator|=
name|std
operator|::
name|find_if
argument_list|(
name|_mergeAtoms
operator|.
name|begin
argument_list|()
argument_list|,
name|_mergeAtoms
operator|.
name|end
argument_list|()
argument_list|,
index|[
operator|=
index|]
operator|(
specifier|const
name|ELFMergeAtom
operator|<
name|ELFT
operator|>
operator|*
name|a
operator|)
block|{
name|int64_t
name|off
operator|=
name|a
operator|->
name|offset
argument_list|()
block|;
return|return
name|shdr
operator|->
name|sh_name
operator|==
name|a
operator|->
name|section
argument_list|()
operator|&&
name|offset
operator|>=
name|off
operator|&&
name|offset
operator|<=
name|off
operator|+
operator|(
name|int64_t
operator|)
name|a
operator|->
name|size
argument_list|()
return|;
block|}
argument_list|)
block|;
name|assert
argument_list|(
name|it
operator|!=
name|_mergeAtoms
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|it
return|;
block|}
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|MergeSectionKey
operator|,
name|DefinedAtom
operator|*
operator|,
name|MergeSectionEq
operator|,
name|MergeSectionEq
operator|>
name|MergedSectionMapT
expr_stmt|;
typedef|typedef
name|typename
name|MergedSectionMapT
operator|::
name|iterator
name|MergedSectionMapIterT
expr_stmt|;
name|public
label|:
name|ELFFile
argument_list|(
argument|StringRef name
argument_list|,
argument|ELFLinkingContext&ctx
argument_list|)
empty_stmt|;
name|ELFFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|,
name|ELFLinkingContext
operator|&
name|ctx
argument_list|)
expr_stmt|;
specifier|static
name|std
operator|::
name|error_code
name|isCompatible
argument_list|(
argument|MemoryBufferRef mb
argument_list|,
argument|ELFLinkingContext&ctx
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|canParse
parameter_list|(
name|file_magic
name|magic
parameter_list|)
block|{
return|return
name|magic
operator|==
name|file_magic
operator|::
name|elf_relocatable
return|;
block|}
name|virtual
name|Reference
operator|::
name|KindArch
name|kindArch
argument_list|()
expr_stmt|;
comment|/// \brief Create symbols from LinkingContext.
name|std
operator|::
name|error_code
name|createAtomsFromContext
argument_list|()
expr_stmt|;
comment|/// \brief Read input sections and populate necessary data structures
comment|/// to read them later and create atoms
name|std
operator|::
name|error_code
name|createAtomizableSections
argument_list|()
expr_stmt|;
comment|/// \brief Create mergeable atoms from sections that have the merge attribute
comment|/// set
name|std
operator|::
name|error_code
name|createMergeableAtoms
argument_list|()
expr_stmt|;
comment|/// \brief Add the symbols that the sections contain. The symbols will be
comment|/// converted to atoms for
comment|/// Undefined symbols, absolute symbols
name|std
operator|::
name|error_code
name|createSymbolsFromAtomizableSections
argument_list|()
expr_stmt|;
comment|/// \brief Create individual atoms
name|std
operator|::
name|error_code
name|createAtoms
argument_list|()
expr_stmt|;
comment|// Assuming sourceSymbol has a reference to targetSym, find an atom
comment|// for targetSym. Usually it's just the atom for targetSym.
comment|// However, if an atom is in a section group, we may want to return an
comment|// undefined atom for targetSym to let the resolver to resolve the
comment|// symbol. (It's because if targetSym is in a section group A, and the
comment|// group A is not linked in because other file already provides a
comment|// section group B, we want to resolve references to B, not to A.)
name|Atom
modifier|*
name|findAtom
parameter_list|(
specifier|const
name|Elf_Sym
modifier|*
name|sourceSym
parameter_list|,
specifier|const
name|Elf_Sym
modifier|*
name|targetSym
parameter_list|)
function_decl|;
name|protected
label|:
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
name|createDefinedAtomAndAssignRelocations
argument_list|(
argument|StringRef symbolName
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|const Elf_Sym *symbol
argument_list|,
argument|const Elf_Shdr *section
argument_list|,
argument|ArrayRef<uint8_t> symContent
argument_list|,
argument|ArrayRef<uint8_t> secContent
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|doParse
argument_list|()
name|override
expr_stmt|;
comment|/// \brief Iterate over Elf_Rela relocations list and create references.
name|virtual
name|void
name|createRelocationReferences
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|content
argument_list|,
name|range
operator|<
specifier|const
name|Elf_Rela
operator|*
operator|>
name|rels
argument_list|)
decl_stmt|;
comment|/// \brief Iterate over Elf_Rel relocations list and create references.
name|virtual
name|void
name|createRelocationReferences
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|symContent
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|secContent
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|relSec
argument_list|)
decl_stmt|;
comment|/// \brief After all the Atoms and References are created, update each
comment|/// Reference's target with the Atom pointer it refers to.
name|void
name|updateReferences
parameter_list|()
function_decl|;
comment|/// \brief Update the reference if the access corresponds to a merge string
comment|/// section.
name|void
name|updateReferenceForMergeStringAccess
argument_list|(
name|ELFReference
operator|<
name|ELFT
operator|>
operator|*
name|ref
argument_list|,
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|,
specifier|const
name|Elf_Shdr
operator|*
name|shdr
argument_list|)
decl_stmt|;
comment|/// \brief Do we want to ignore the section. Ignored sections are
comment|/// not processed to create atoms
name|bool
name|isIgnoredSection
parameter_list|(
specifier|const
name|Elf_Shdr
modifier|*
name|section
parameter_list|)
function_decl|;
comment|/// \brief Is the current section be treated as a mergeable string section.
comment|/// The contents of a mergeable string section are null-terminated strings.
comment|/// If the section have mergeable strings, the linker would need to split
comment|/// the section into multiple atoms and mark them mergeByContent.
name|bool
name|isMergeableStringSection
parameter_list|(
specifier|const
name|Elf_Shdr
modifier|*
name|section
parameter_list|)
function_decl|;
comment|/// \brief Returns a new anonymous atom whose size is equal to the
comment|/// section size. That atom will be used to represent the entire
comment|/// section that have no symbols.
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
name|createSectionAtom
argument_list|(
argument|const Elf_Shdr *section
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|ArrayRef<uint8_t> contents
argument_list|)
expr_stmt|;
comment|/// Returns the symbol's content size. The nextSymbol should be null if the
comment|/// symbol is the last one in the section.
name|uint64_t
name|symbolContentSize
parameter_list|(
specifier|const
name|Elf_Shdr
modifier|*
name|section
parameter_list|,
specifier|const
name|Elf_Sym
modifier|*
name|symbol
parameter_list|,
specifier|const
name|Elf_Sym
modifier|*
name|nextSymbol
parameter_list|)
function_decl|;
name|void
name|createEdge
argument_list|(
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
name|from
argument_list|,
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
name|to
argument_list|,
name|uint32_t
name|edgeKind
argument_list|)
decl_stmt|;
comment|/// Get the section name for a section.
name|ErrorOr
operator|<
name|StringRef
operator|>
name|getSectionName
argument_list|(
argument|const Elf_Shdr *shdr
argument_list|)
specifier|const
expr_stmt|;
comment|/// Determines if the section occupy memory space.
name|bool
name|sectionOccupiesMemorySpace
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|shdr
argument_list|)
decl|const
block|{
return|return
operator|(
name|shdr
operator|->
name|sh_type
operator|!=
name|llvm
operator|::
name|ELF
operator|::
name|SHT_NOBITS
operator|)
return|;
block|}
comment|/// Return the section contents.
name|ErrorOr
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|getSectionContents
argument_list|(
argument|const Elf_Shdr *shdr
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|shdr
operator|||
operator|!
name|sectionOccupiesMemorySpace
argument_list|(
name|shdr
argument_list|)
condition|)
return|return
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
operator|)
return|;
return|return
name|_objFile
operator|->
name|getSectionContents
argument_list|(
name|shdr
argument_list|)
return|;
block|}
comment|/// Determines if the target wants to create an atom for a section that has no
comment|/// symbol references.
name|bool
name|handleSectionWithNoSymbols
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|shdr
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|Elf_Sym
operator|*
operator|>
operator|&
name|syms
argument_list|)
decl|const
block|{
return|return
name|shdr
operator|&&
operator|(
name|shdr
operator|->
name|sh_type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHT_PROGBITS
operator|||
name|shdr
operator|->
name|sh_type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHT_INIT_ARRAY
operator|||
name|shdr
operator|->
name|sh_type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHT_FINI_ARRAY
operator|||
name|shdr
operator|->
name|sh_type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHT_NOTE
operator|)
operator|&&
name|syms
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Handle creation of atoms for .gnu.linkonce sections.
name|std
operator|::
name|error_code
name|handleGnuLinkOnceSection
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|section
argument_list|,
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|vector
operator|<
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
operator|>>
operator|&
name|atomsForSection
argument_list|)
expr_stmt|;
comment|// Handle COMDAT scetions.
name|std
operator|::
name|error_code
name|handleSectionGroup
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|section
argument_list|,
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|vector
operator|<
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
operator|>>
operator|&
name|atomsForSection
argument_list|)
expr_stmt|;
comment|/// Process the Undefined symbol and create an atom for it.
name|ELFUndefinedAtom
operator|<
name|ELFT
operator|>
operator|*
name|createUndefinedAtom
argument_list|(
argument|StringRef symName
argument_list|,
argument|const Elf_Sym *sym
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|ELFUndefinedAtom
operator|<
name|ELFT
operator|>
operator|(
operator|*
name|this
operator|,
name|symName
operator|,
name|sym
operator|)
return|;
block|}
comment|/// Process the Absolute symbol and create an atom for it.
name|ELFAbsoluteAtom
operator|<
name|ELFT
operator|>
operator|*
name|createAbsoluteAtom
argument_list|(
argument|StringRef symName
argument_list|,
argument|const Elf_Sym *sym
argument_list|,
argument|int64_t value
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|ELFAbsoluteAtom
operator|<
name|ELFT
operator|>
operator|(
operator|*
name|this
operator|,
name|symName
operator|,
name|sym
operator|,
name|value
operator|)
return|;
block|}
comment|/// Returns true if the symbol is common symbol. A common symbol represents a
comment|/// tentive definition in C. It has name, size and alignment constraint, but
comment|/// actual storage has not yet been allocated. (The linker will allocate
comment|/// storage for them in the later pass after coalescing tentative symbols by
comment|/// name.)
name|virtual
name|bool
name|isCommonSymbol
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|)
decl|const
block|{
return|return
name|symbol
operator|->
name|getType
argument_list|()
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|STT_COMMON
operator|||
name|symbol
operator|->
name|st_shndx
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHN_COMMON
return|;
block|}
comment|/// Returns true if the section is a gnulinkonce section.
name|bool
name|isGnuLinkOnceSection
argument_list|(
name|StringRef
name|sectionName
argument_list|)
decl|const
block|{
return|return
name|sectionName
operator|.
name|startswith
argument_list|(
literal|".gnu.linkonce."
argument_list|)
return|;
block|}
comment|/// Returns true if the section is a COMDAT group section.
name|bool
name|isGroupSection
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|shdr
argument_list|)
decl|const
block|{
return|return
operator|(
name|shdr
operator|->
name|sh_type
operator|==
name|llvm
operator|::
name|ELF
operator|::
name|SHT_GROUP
operator|)
return|;
block|}
comment|/// Returns true if the section is a member of some group.
name|bool
name|isSectionMemberOfGroup
argument_list|(
specifier|const
name|Elf_Shdr
operator|*
name|shdr
argument_list|)
decl|const
block|{
return|return
operator|(
name|shdr
operator|->
name|sh_flags
operator|&
name|llvm
operator|::
name|ELF
operator|::
name|SHF_GROUP
operator|)
return|;
block|}
comment|/// Returns correct st_value for the symbol depending on the architecture.
comment|/// For most architectures it's just a regular st_value with no changes.
name|virtual
name|uint64_t
name|getSymbolValue
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|symbol
argument_list|)
decl|const
block|{
return|return
name|symbol
operator|->
name|st_value
return|;
block|}
comment|/// Returns initial addend
name|virtual
name|Reference
operator|::
name|Addend
name|getInitialAddend
argument_list|(
argument|ArrayRef<uint8_t> symContent
argument_list|,
argument|uint64_t symbolValue
argument_list|,
argument|const Elf_Rel& reference
argument_list|)
specifier|const
block|{
return|return
operator|*
operator|(
name|symContent
operator|.
name|data
argument_list|()
operator|+
name|reference
operator|.
name|r_offset
operator|-
name|symbolValue
operator|)
return|;
block|}
comment|/// Process the common symbol and create an atom for it.
name|virtual
name|ELFCommonAtom
operator|<
name|ELFT
operator|>
operator|*
name|createCommonAtom
argument_list|(
argument|StringRef symName
argument_list|,
argument|const Elf_Sym *sym
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|ELFCommonAtom
operator|<
name|ELFT
operator|>
operator|(
operator|*
name|this
operator|,
name|symName
operator|,
name|sym
operator|)
return|;
block|}
comment|/// Creates an atom for a given defined symbol.
name|virtual
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|*
name|createDefinedAtom
argument_list|(
argument|StringRef symName
argument_list|,
argument|StringRef sectionName
argument_list|,
argument|const Elf_Sym *sym
argument_list|,
argument|const Elf_Shdr *sectionHdr
argument_list|,
argument|ArrayRef<uint8_t> contentData
argument_list|,
argument|unsigned int referenceStart
argument_list|,
argument|unsigned int referenceEnd
argument_list|,
argument|std::vector<ELFReference<ELFT> *>&referenceList
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|ELFDefinedAtom
operator|<
name|ELFT
operator|>
operator|(
operator|*
name|this
operator|,
name|symName
operator|,
name|sectionName
operator|,
name|sym
operator|,
name|sectionHdr
operator|,
name|contentData
operator|,
name|referenceStart
operator|,
name|referenceEnd
operator|,
name|referenceList
operator|)
return|;
block|}
comment|/// Process the Merge string and create an atom for it.
name|ELFMergeAtom
operator|<
name|ELFT
operator|>
operator|*
name|createMergedString
argument_list|(
argument|StringRef sectionName
argument_list|,
argument|const Elf_Shdr *sectionHdr
argument_list|,
argument|ArrayRef<uint8_t> contentData
argument_list|,
argument|unsigned int offset
argument_list|)
block|{
name|auto
operator|*
name|mergeAtom
operator|=
name|new
argument_list|(
argument|_readerStorage
argument_list|)
name|ELFMergeAtom
operator|<
name|ELFT
operator|>
operator|(
operator|*
name|this
operator|,
name|sectionName
operator|,
name|sectionHdr
operator|,
name|contentData
operator|,
name|offset
operator|)
block|;
specifier|const
name|MergeSectionKey
name|mergedSectionKey
operator|=
block|{
name|sectionHdr
block|,
name|offset
block|}
block|;
if|if
condition|(
name|_mergedSectionMap
operator|.
name|find
argument_list|(
name|mergedSectionKey
argument_list|)
operator|==
name|_mergedSectionMap
operator|.
name|end
argument_list|()
condition|)
name|_mergedSectionMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|mergedSectionKey
argument_list|,
name|mergeAtom
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|mergeAtom
return|;
block|}
end_decl_stmt

begin_comment
comment|/// References to the sections comprising a group, from sections
end_comment

begin_comment
comment|/// outside the group, must be made via global UNDEF symbols,
end_comment

begin_comment
comment|/// referencing global symbols defined as addresses in the group
end_comment

begin_comment
comment|/// sections. They may not reference local symbols for addresses in
end_comment

begin_comment
comment|/// the group's sections, including section symbols.
end_comment

begin_comment
comment|/// ABI Doc : https://mentorembedded.github.io/cxx-abi/abi/prop-72-comdat.html
end_comment

begin_comment
comment|/// Does the atom need to be redirected using a separate undefined atom?
end_comment

begin_decl_stmt
name|bool
name|redirectReferenceUsingUndefAtom
argument_list|(
specifier|const
name|Elf_Sym
operator|*
name|sourceSymbol
argument_list|,
specifier|const
name|Elf_Sym
operator|*
name|targetSymbol
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addReferenceToSymbol
argument_list|(
specifier|const
name|ELFReference
operator|<
name|ELFT
operator|>
operator|*
name|r
argument_list|,
specifier|const
name|Elf_Sym
operator|*
name|sym
argument_list|)
block|{
name|_referenceToSymbol
index|[
name|r
index|]
operator|=
name|sym
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|Elf_Sym
modifier|*
name|findSymbolForReference
argument_list|(
specifier|const
name|ELFReference
operator|<
name|ELFT
operator|>
operator|*
name|r
argument_list|)
decl|const
block|{
name|auto
name|elfReferenceToSymbol
init|=
name|_referenceToSymbol
operator|.
name|find
argument_list|(
name|r
argument_list|)
decl_stmt|;
if|if
condition|(
name|elfReferenceToSymbol
operator|!=
name|_referenceToSymbol
operator|.
name|end
argument_list|()
condition|)
return|return
name|elfReferenceToSymbol
operator|->
name|second
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
name|_readerStorage
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|object
operator|::
name|ELFFile
operator|<
name|ELFT
operator|>
expr|>
name|_objFile
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|Elf_Shdr
modifier|*
name|_symtab
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ArrayRef
operator|<
name|Elf_Word
operator|>
name|_shndxTable
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief _relocationAddendReferences and _relocationReferences contain the
end_comment

begin_comment
comment|/// list of relocations references.  In ELF, if a section named, ".text" has
end_comment

begin_comment
comment|/// relocations will also have a section named ".rel.text" or ".rela.text"
end_comment

begin_comment
comment|/// which will hold the entries.
end_comment

begin_expr_stmt
name|std
operator|::
name|unordered_map
operator|<
specifier|const
name|Elf_Shdr
operator|*
operator|,
name|range
operator|<
specifier|const
name|Elf_Rela
operator|*
operator|>>
name|_relocationAddendReferences
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|MergedSectionMapT
name|_mergedSectionMap
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unordered_map
operator|<
specifier|const
name|Elf_Shdr
operator|*
operator|,
specifier|const
name|Elf_Shdr
operator|*
operator|>
name|_relocationReferences
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|ELFReference
operator|<
name|ELFT
operator|>
operator|*
operator|>
name|_references
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Elf_Sym
operator|*
operator|,
name|Atom
operator|*
operator|>
name|_symbolToAtomMapping
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ELFReference
operator|<
name|ELFT
operator|>
operator|*
operator|,
specifier|const
name|Elf_Sym
operator|*
operator|>
name|_referenceToSymbol
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Group child atoms have a pair corresponding to the signature and the
end_comment

begin_comment
comment|// section header of the section that was used for generating the signature.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Elf_Sym
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
specifier|const
name|Elf_Shdr
operator|*
operator|>>
name|_groupChild
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|StringMap
operator|<
name|Atom
operator|*
operator|>
name|_undefAtomsForGroupChild
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Atoms that are created for a section that has the merge property
end_comment

begin_comment
comment|/// set
end_comment

begin_decl_stmt
name|MergeAtomsT
name|_mergeAtoms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief the section and the symbols that are contained within it to create
end_comment

begin_comment
comment|/// used to create atoms
end_comment

begin_expr_stmt
name|llvm
operator|::
name|MapVector
operator|<
specifier|const
name|Elf_Shdr
operator|*
operator|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|Elf_Sym
operator|*
operator|>>
name|_sectionSymbols
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Sections that have merge string property
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
specifier|const
name|Elf_Shdr
operator|*
operator|>
name|_mergeStringSections
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|_mb
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int64_t
name|_ordinal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief the cached options relevant while reading the ELF File
end_comment

begin_decl_stmt
name|bool
name|_doStringsMerge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Is --wrap on?
end_comment

begin_decl_stmt
name|bool
name|_useWrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The LinkingContext.
end_comment

begin_decl_stmt
name|ELFLinkingContext
modifier|&
name|_ctx
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Wrap map
end_comment

begin_expr_stmt
name|llvm
operator|::
name|StringMap
operator|<
name|UndefinedAtom
operator|*
operator|>
name|_wrapSymbolMap
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief All atoms are owned by a File. To add linker specific atoms
end_comment

begin_comment
comment|/// the atoms need to be inserted to a file called (RuntimeFile) which
end_comment

begin_comment
comment|/// are basically additional symbols required by libc and other runtime
end_comment

begin_comment
comment|/// libraries part of executing a program. This class provides support
end_comment

begin_comment
comment|/// for adding absolute symbols and undefined symbols
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|RuntimeFile
operator|:
name|public
name|ELFFile
operator|<
name|ELFT
operator|>
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|Elf_Sym_Impl
operator|<
name|ELFT
operator|>
name|Elf_Sym
expr_stmt|;
name|RuntimeFile
argument_list|(
argument|ELFLinkingContext&ctx
argument_list|,
argument|StringRef name
argument_list|)
operator|:
name|ELFFile
operator|<
name|ELFT
operator|>
operator|(
name|name
operator|,
name|ctx
operator|)
block|{}
comment|/// \brief add a global absolute atom
name|virtual
name|void
name|addAbsoluteAtom
argument_list|(
argument|StringRef symbolName
argument_list|,
argument|bool isHidden = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief add an undefined atom
end_comment

begin_function_decl
name|virtual
name|void
name|addUndefinedAtom
parameter_list|(
name|StringRef
name|symbolName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end namespace elf
end_comment

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_FILE_H
end_comment

end_unit

