begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/FileFormat/MachO/ArchHandler.h ---------------------------------===//
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
name|LLD_READER_WRITER_MACHO_ARCH_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_ARCH_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"File.h"
end_include

begin_include
include|#
directive|include
file|"MachONormalizedFile.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reference.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/MachOLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|mach_o
block|{
comment|///
comment|/// The ArchHandler class handles all architecture specific aspects of
comment|/// mach-o linking.
comment|///
name|class
name|ArchHandler
block|{
name|public
label|:
name|virtual
operator|~
name|ArchHandler
argument_list|()
expr_stmt|;
comment|/// There is no public interface to subclasses of ArchHandler, so this
comment|/// is the only way to instantiate an ArchHandler.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|ArchHandler
operator|>
name|create
argument_list|(
argument|MachOLinkingContext::Arch arch
argument_list|)
expr_stmt|;
comment|/// Get (arch specific) kind strings used by Registry.
name|virtual
specifier|const
name|Registry
operator|::
name|KindStrings
operator|*
name|kindStrings
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Convert mach-o Arch to Reference::KindArch.
name|virtual
name|Reference
operator|::
name|KindArch
name|kindArch
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Used by StubPass to update References to shared library functions
comment|/// to be references to a stub.
name|virtual
name|bool
name|isCallSite
parameter_list|(
specifier|const
name|Reference
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Used by GOTPass to locate GOT References
name|virtual
name|bool
name|isGOTAccess
parameter_list|(
specifier|const
name|Reference
modifier|&
parameter_list|,
name|bool
modifier|&
name|canBypassGOT
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Used by TLVPass to locate TLV References.
name|virtual
name|bool
name|isTLVAccess
argument_list|(
specifier|const
name|Reference
operator|&
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Used by the TLVPass to update TLV References.
name|virtual
name|void
name|updateReferenceToTLV
parameter_list|(
specifier|const
name|Reference
modifier|*
parameter_list|)
block|{}
comment|/// Used by ShimPass to insert shims in branches that switch mode.
name|virtual
name|bool
name|isNonCallBranch
parameter_list|(
specifier|const
name|Reference
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Used by GOTPass to update GOT References
name|virtual
name|void
name|updateReferenceToGOT
parameter_list|(
specifier|const
name|Reference
modifier|*
parameter_list|,
name|bool
name|targetIsNowGOT
parameter_list|)
block|{}
comment|/// Does this architecture make use of __unwind_info sections for exception
comment|/// handling? If so, it will need a separate pass to create them.
name|virtual
name|bool
name|needsCompactUnwind
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Returns the kind of reference to use to synthesize a 32-bit image-offset
comment|/// value, used in the __unwind_info section.
name|virtual
name|Reference
operator|::
name|KindValue
name|imageOffsetKind
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Returns the kind of reference to use to synthesize a 32-bit image-offset
comment|/// indirect value. Used for personality functions in the __unwind_info
comment|/// section.
name|virtual
name|Reference
operator|::
name|KindValue
name|imageOffsetKindIndirect
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Architecture specific compact unwind type that signals __eh_frame should
comment|/// actually be used.
name|virtual
name|uint32_t
name|dwarfCompactUnwindType
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Reference from an __eh_frame CIE atom to its personality function it's
comment|/// describing. Usually pointer-sized and PC-relative, but differs in whether
comment|/// it needs to be in relocatable objects.
name|virtual
name|Reference
operator|::
name|KindValue
name|unwindRefToPersonalityFunctionKind
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Reference from an __eh_frame FDE to the CIE it's based on.
name|virtual
name|Reference
operator|::
name|KindValue
name|unwindRefToCIEKind
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Reference from an __eh_frame FDE atom to the function it's
comment|/// describing. Usually pointer-sized and PC-relative, but differs in whether
comment|/// it needs to be in relocatable objects.
name|virtual
name|Reference
operator|::
name|KindValue
name|unwindRefToFunctionKind
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Reference from an __unwind_info entry of dwarfCompactUnwindType to the
comment|/// required __eh_frame entry. On current architectures, the low 24 bits
comment|/// represent the offset of the function's FDE entry from the start of
comment|/// __eh_frame.
name|virtual
name|Reference
operator|::
name|KindValue
name|unwindRefToEhFrameKind
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Returns a pointer sized reference kind.  On 64-bit targets this will
comment|/// likely be something like pointer64, and pointer32 on 32-bit targets.
name|virtual
name|Reference
operator|::
name|KindValue
name|pointerKind
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|Atom
modifier|*
name|fdeTargetFunction
parameter_list|(
specifier|const
name|DefinedAtom
modifier|*
name|fde
parameter_list|)
function_decl|;
comment|/// Used by normalizedFromAtoms() to know where to generated rebasing and
comment|/// binding info in final executables.
name|virtual
name|bool
name|isPointer
parameter_list|(
specifier|const
name|Reference
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Used by normalizedFromAtoms() to know where to generated lazy binding
comment|/// info in final executables.
name|virtual
name|bool
name|isLazyPointer
parameter_list|(
specifier|const
name|Reference
modifier|&
parameter_list|)
function_decl|;
comment|/// Returns true if the specified relocation is paired to the next relocation.
name|virtual
name|bool
name|isPairedReloc
argument_list|(
specifier|const
name|normalized
operator|::
name|Relocation
operator|&
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Prototype for a helper function.  Given a sectionIndex and address,
comment|/// finds the atom and offset with that atom of that address.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|llvm
operator|::
name|Error
argument_list|(
argument|uint32_t sectionIndex
argument_list|,
argument|uint64_t addr
argument_list|,
argument|const lld::Atom **
argument_list|,
argument|Reference::Addend *
argument_list|)
operator|>
name|FindAtomBySectionAndAddress
expr_stmt|;
comment|/// Prototype for a helper function.  Given a symbolIndex, finds the atom
comment|/// representing that symbol.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|llvm
operator|::
name|Error
argument_list|(
argument|uint32_t symbolIndex
argument_list|,
argument|const lld::Atom **
argument_list|)
operator|>
name|FindAtomBySymbolIndex
expr_stmt|;
comment|/// Analyzes a relocation from a .o file and returns the info
comment|/// (kind, target, addend) needed to instantiate a Reference.
comment|/// Two helper functions are passed as parameters to find the target atom
comment|/// given a symbol index or address.
name|virtual
name|llvm
operator|::
name|Error
name|getReferenceInfo
argument_list|(
argument|const normalized::Relocation&reloc
argument_list|,
argument|const DefinedAtom *inAtom
argument_list|,
argument|uint32_t offsetInAtom
argument_list|,
argument|uint64_t fixupAddress
argument_list|,
argument|bool isBigEndian
argument_list|,
argument|FindAtomBySectionAndAddress atomFromAddress
argument_list|,
argument|FindAtomBySymbolIndex atomFromSymbolIndex
argument_list|,
argument|Reference::KindValue *kind
argument_list|,
argument|const lld::Atom **target
argument_list|,
argument|Reference::Addend *addend
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Analyzes a pair of relocations from a .o file and returns the info
comment|/// (kind, target, addend) needed to instantiate a Reference.
comment|/// Two helper functions are passed as parameters to find the target atom
comment|/// given a symbol index or address.
name|virtual
name|llvm
operator|::
name|Error
name|getPairReferenceInfo
argument_list|(
argument|const normalized::Relocation&reloc1
argument_list|,
argument|const normalized::Relocation&reloc2
argument_list|,
argument|const DefinedAtom *inAtom
argument_list|,
argument|uint32_t offsetInAtom
argument_list|,
argument|uint64_t fixupAddress
argument_list|,
argument|bool isBig
argument_list|,
argument|bool scatterable
argument_list|,
argument|FindAtomBySectionAndAddress atomFromAddress
argument_list|,
argument|FindAtomBySymbolIndex atomFromSymbolIndex
argument_list|,
argument|Reference::KindValue *kind
argument_list|,
argument|const lld::Atom **target
argument_list|,
argument|Reference::Addend *addend
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Prototype for a helper function.  Given an atom, finds the symbol table
comment|/// index for it in the output file.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|uint32_t
argument_list|(
specifier|const
name|Atom
operator|&
name|atom
argument_list|)
operator|>
name|FindSymbolIndexForAtom
expr_stmt|;
comment|/// Prototype for a helper function.  Given an atom, finds the index
comment|/// of the section that will contain the atom.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|uint32_t
argument_list|(
specifier|const
name|Atom
operator|&
name|atom
argument_list|)
operator|>
name|FindSectionIndexForAtom
expr_stmt|;
comment|/// Prototype for a helper function.  Given an atom, finds the address
comment|/// assigned to it in the output file.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|uint64_t
argument_list|(
specifier|const
name|Atom
operator|&
name|atom
argument_list|)
operator|>
name|FindAddressForAtom
expr_stmt|;
comment|/// Some architectures require local symbols on anonymous atoms.
name|virtual
name|bool
name|needsLocalSymbolInRelocatableFile
parameter_list|(
specifier|const
name|DefinedAtom
modifier|*
name|atom
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Copy raw content then apply all fixup References on an Atom.
name|virtual
name|void
name|generateAtomContent
argument_list|(
specifier|const
name|DefinedAtom
operator|&
name|atom
argument_list|,
name|bool
name|relocatable
argument_list|,
name|FindAddressForAtom
name|findAddress
argument_list|,
name|FindAddressForAtom
name|findSectionAddress
argument_list|,
name|uint64_t
name|imageBaseAddress
argument_list|,
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|atomContentBuffer
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Used in -r mode to convert a Reference to a mach-o relocation.
name|virtual
name|void
name|appendSectionRelocations
argument_list|(
specifier|const
name|DefinedAtom
operator|&
name|atom
argument_list|,
name|uint64_t
name|atomSectionOffset
argument_list|,
specifier|const
name|Reference
operator|&
name|ref
argument_list|,
name|FindSymbolIndexForAtom
argument_list|,
name|FindSectionIndexForAtom
argument_list|,
name|FindAddressForAtom
argument_list|,
name|normalized
operator|::
name|Relocations
operator|&
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Add arch-specific References.
name|virtual
name|void
name|addAdditionalReferences
parameter_list|(
name|MachODefinedAtom
modifier|&
name|atom
parameter_list|)
block|{ }
comment|// Add Reference for data-in-code marker.
name|virtual
name|void
name|addDataInCodeReference
parameter_list|(
name|MachODefinedAtom
modifier|&
name|atom
parameter_list|,
name|uint32_t
name|atomOff
parameter_list|,
name|uint16_t
name|length
parameter_list|,
name|uint16_t
name|kind
parameter_list|)
block|{ }
comment|/// Returns true if the specificed Reference value marks the start or end
comment|/// of a data-in-code range in an atom.
name|virtual
name|bool
name|isDataInCodeTransition
argument_list|(
name|Reference
operator|::
name|KindValue
name|refKind
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Returns the Reference value for a Reference that marks that start of
comment|/// a data-in-code range.
name|virtual
name|Reference
operator|::
name|KindValue
name|dataInCodeTransitionStart
argument_list|(
argument|const MachODefinedAtom&atom
argument_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// Returns the Reference value for a Reference that marks that end of
comment|/// a data-in-code range.
name|virtual
name|Reference
operator|::
name|KindValue
name|dataInCodeTransitionEnd
argument_list|(
argument|const MachODefinedAtom&atom
argument_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// Only relevant for 32-bit arm archs.
name|virtual
name|bool
name|isThumbFunction
parameter_list|(
specifier|const
name|DefinedAtom
modifier|&
name|atom
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Only relevant for 32-bit arm archs.
name|virtual
specifier|const
name|DefinedAtom
modifier|*
name|createShim
parameter_list|(
name|MachOFile
modifier|&
name|file
parameter_list|,
name|bool
name|thumbToArm
parameter_list|,
specifier|const
name|DefinedAtom
modifier|&
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"shims only support on arm"
argument_list|)
expr_stmt|;
block|}
comment|/// Does a given unwind-cfi atom represent a CIE (as opposed to an FDE).
specifier|static
name|bool
name|isDwarfCIE
parameter_list|(
name|bool
name|isBig
parameter_list|,
specifier|const
name|DefinedAtom
modifier|*
name|atom
parameter_list|)
function_decl|;
struct|struct
name|ReferenceInfo
block|{
name|Reference
operator|::
name|KindArch
name|arch
expr_stmt|;
name|uint16_t
name|kind
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|int32_t
name|addend
decl_stmt|;
block|}
struct|;
struct|struct
name|OptionalRefInfo
block|{
name|bool
name|used
decl_stmt|;
name|uint16_t
name|kind
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|int32_t
name|addend
decl_stmt|;
block|}
struct|;
comment|/// Table of architecture specific information for creating stubs.
struct|struct
name|StubInfo
block|{
specifier|const
name|char
modifier|*
name|binderSymbolName
decl_stmt|;
name|ReferenceInfo
name|lazyPointerReferenceToHelper
decl_stmt|;
name|ReferenceInfo
name|lazyPointerReferenceToFinal
decl_stmt|;
name|ReferenceInfo
name|nonLazyPointerReferenceToBinder
decl_stmt|;
name|uint8_t
name|codeAlignment
decl_stmt|;
name|uint32_t
name|stubSize
decl_stmt|;
name|uint8_t
name|stubBytes
index|[
literal|16
index|]
decl_stmt|;
name|ReferenceInfo
name|stubReferenceToLP
decl_stmt|;
name|OptionalRefInfo
name|optStubReferenceToLP
decl_stmt|;
name|uint32_t
name|stubHelperSize
decl_stmt|;
name|uint8_t
name|stubHelperBytes
index|[
literal|16
index|]
decl_stmt|;
name|ReferenceInfo
name|stubHelperReferenceToImm
decl_stmt|;
name|ReferenceInfo
name|stubHelperReferenceToHelperCommon
decl_stmt|;
name|DefinedAtom
operator|::
name|ContentType
name|stubHelperImageCacheContentType
expr_stmt|;
name|uint32_t
name|stubHelperCommonSize
decl_stmt|;
name|uint8_t
name|stubHelperCommonAlignment
decl_stmt|;
name|uint8_t
name|stubHelperCommonBytes
index|[
literal|36
index|]
decl_stmt|;
name|ReferenceInfo
name|stubHelperCommonReferenceToCache
decl_stmt|;
name|OptionalRefInfo
name|optStubHelperCommonReferenceToCache
decl_stmt|;
name|ReferenceInfo
name|stubHelperCommonReferenceToBinder
decl_stmt|;
name|OptionalRefInfo
name|optStubHelperCommonReferenceToBinder
decl_stmt|;
block|}
struct|;
name|virtual
specifier|const
name|StubInfo
modifier|&
name|stubInfo
parameter_list|()
init|=
literal|0
function_decl|;
name|protected
label|:
name|ArchHandler
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|mach_o
operator|::
name|ArchHandler
operator|>
name|create_x86_64
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|mach_o
operator|::
name|ArchHandler
operator|>
name|create_x86
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|mach_o
operator|::
name|ArchHandler
operator|>
name|create_arm
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|mach_o
operator|::
name|ArchHandler
operator|>
name|create_arm64
argument_list|()
expr_stmt|;
comment|// Handy way to pack mach-o r_type and other bit fields into one 16-bit value.
typedef|typedef
name|uint16_t
name|RelocPattern
typedef|;
enum|enum
block|{
name|rScattered
init|=
literal|0x8000
block|,
name|rPcRel
init|=
literal|0x4000
block|,
name|rExtern
init|=
literal|0x2000
block|,
name|rLength1
init|=
literal|0x0000
block|,
name|rLength2
init|=
literal|0x0100
block|,
name|rLength4
init|=
literal|0x0200
block|,
name|rLength8
init|=
literal|0x0300
block|,
name|rLenArmLo
init|=
name|rLength1
block|,
name|rLenArmHi
init|=
name|rLength2
block|,
name|rLenThmbLo
init|=
name|rLength4
block|,
name|rLenThmbHi
init|=
name|rLength8
block|}
enum|;
comment|/// Extract RelocPattern from normalized mach-o relocation.
specifier|static
name|RelocPattern
name|relocPattern
argument_list|(
specifier|const
name|normalized
operator|::
name|Relocation
operator|&
name|reloc
argument_list|)
decl_stmt|;
comment|/// Create normalized Relocation initialized from pattern.
specifier|static
name|normalized
operator|::
name|Relocation
name|relocFromPattern
argument_list|(
argument|RelocPattern pattern
argument_list|)
expr_stmt|;
comment|/// One liner to add a relocation.
specifier|static
name|void
name|appendReloc
argument_list|(
name|normalized
operator|::
name|Relocations
operator|&
name|relocs
argument_list|,
name|uint32_t
name|offset
argument_list|,
name|uint32_t
name|symbol
argument_list|,
name|uint32_t
name|value
argument_list|,
name|RelocPattern
name|pattern
argument_list|)
decl_stmt|;
specifier|static
name|int16_t
name|readS16
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|addr
parameter_list|,
name|bool
name|isBig
parameter_list|)
function_decl|;
specifier|static
name|int32_t
name|readS32
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|addr
parameter_list|,
name|bool
name|isBig
parameter_list|)
function_decl|;
specifier|static
name|uint32_t
name|readU32
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|addr
parameter_list|,
name|bool
name|isBig
parameter_list|)
function_decl|;
specifier|static
name|int64_t
name|readS64
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|addr
parameter_list|,
name|bool
name|isBig
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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
comment|// LLD_READER_WRITER_MACHO_ARCH_HANDLER_H
end_comment

end_unit

