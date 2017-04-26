begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- unittests/DebugInfo/DWARF/DwarfGenerator.h -------------*- C++ -*-===//
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
comment|// A file that can generate DWARF debug info for unit tests.
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
name|LLVM_UNITTESTS_DEBUG_INFO_DWARF_DWARFGENERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UNITTESTS_DEBUG_INFO_DWARF_DWARFGENERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DIE.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFDebugLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|DIE
decl_stmt|;
name|class
name|DIEAbbrev
decl_stmt|;
name|class
name|DwarfStringPool
decl_stmt|;
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
struct_decl|struct
name|MCDwarfLineTableParams
struct_decl|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCObjectFileInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|raw_fd_ostream
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|namespace
name|dwarfgen
block|{
name|class
name|Generator
decl_stmt|;
name|class
name|CompileUnit
decl_stmt|;
comment|/// A DWARF debug information entry class used to generate DWARF DIEs.
comment|///
comment|/// This class is used to quickly generate DWARF debug information by creating
comment|/// child DIEs or adding attributes to the current DIE. Instances of this class
comment|/// are created from the compile unit (dwarfgen::CompileUnit::getUnitDIE()) or
comment|/// by calling dwarfgen::DIE::addChild(...) and using the returned DIE object.
name|class
name|DIE
block|{
name|dwarfgen
operator|::
name|CompileUnit
operator|*
name|CU
expr_stmt|;
name|llvm
operator|::
name|DIE
operator|*
name|Die
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|Generator
decl_stmt|;
name|friend
name|class
name|CompileUnit
decl_stmt|;
name|DIE
argument_list|(
name|CompileUnit
operator|*
name|U
operator|=
name|nullptr
argument_list|,
name|llvm
operator|::
name|DIE
operator|*
name|D
operator|=
name|nullptr
argument_list|)
operator|:
name|CU
argument_list|(
name|U
argument_list|)
operator|,
name|Die
argument_list|(
argument|D
argument_list|)
block|{}
comment|/// Called with a compile/type unit relative offset prior to generating the
comment|/// DWARF debug info.
comment|///
comment|/// \param CUOffset the compile/type unit relative offset where the
comment|/// abbreviation code for this DIE will be encoded.
name|unsigned
name|computeSizeAndOffsets
argument_list|(
argument|unsigned CUOffset
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// Add an attribute value that has no value.
comment|///
comment|/// \param Attr a dwarf::Attribute enumeration value or any uint16_t that
comment|/// represents a user defined DWARF attribute.
comment|/// \param Form the dwarf::Form to use when encoding the attribute. This is
comment|/// only used with the DW_FORM_flag_present form encoding.
name|void
name|addAttribute
argument_list|(
name|uint16_t
name|Attr
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|)
decl_stmt|;
comment|/// Add an attribute value to be encoded as a DIEInteger
comment|///
comment|/// \param Attr a dwarf::Attribute enumeration value or any uint16_t that
comment|/// represents a user defined DWARF attribute.
comment|/// \param Form the dwarf::Form to use when encoding the attribute.
comment|/// \param U the unsigned integer to encode.
name|void
name|addAttribute
argument_list|(
name|uint16_t
name|Attr
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
name|uint64_t
name|U
argument_list|)
decl_stmt|;
comment|/// Add an attribute value to be encoded as a DIEString or DIEInlinedString.
comment|///
comment|/// \param Attr a dwarf::Attribute enumeration value or any uint16_t that
comment|/// represents a user defined DWARF attribute.
comment|/// \param Form the dwarf::Form to use when encoding the attribute. The form
comment|/// must be one of DW_FORM_strp or DW_FORM_string.
comment|/// \param String the string to encode.
name|void
name|addAttribute
argument_list|(
name|uint16_t
name|Attr
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
name|StringRef
name|String
argument_list|)
decl_stmt|;
comment|/// Add an attribute value to be encoded as a DIEEntry.
comment|///
comment|/// DIEEntry attributes refer to other llvm::DIE objects that have been
comment|/// created.
comment|///
comment|/// \param Attr a dwarf::Attribute enumeration value or any uint16_t that
comment|/// represents a user defined DWARF attribute.
comment|/// \param Form the dwarf::Form to use when encoding the attribute. The form
comment|/// must be one of DW_FORM_strp or DW_FORM_string.
comment|/// \param RefDie the DIE that this attriute refers to.
name|void
name|addAttribute
argument_list|(
name|uint16_t
name|Attr
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
name|dwarfgen
operator|::
name|DIE
operator|&
name|RefDie
argument_list|)
decl_stmt|;
comment|/// Add an attribute value to be encoded as a DIEBlock.
comment|///
comment|/// DIEBlock attributes refers to binary data that is stored as the
comment|/// attribute's value.
comment|///
comment|/// \param Attr a dwarf::Attribute enumeration value or any uint16_t that
comment|/// represents a user defined DWARF attribute.
comment|/// \param Form the dwarf::Form to use when encoding the attribute. The form
comment|/// must be one of DW_FORM_strp or DW_FORM_string.
comment|/// \param P a pointer to the data to store as the attribute value.
comment|/// \param S the size in bytes of the data pointed to by P .
name|void
name|addAttribute
argument_list|(
name|uint16_t
name|Attr
argument_list|,
name|dwarf
operator|::
name|Form
name|Form
argument_list|,
specifier|const
name|void
operator|*
name|P
argument_list|,
name|size_t
name|S
argument_list|)
decl_stmt|;
comment|/// Add a new child to this DIE object.
comment|///
comment|/// \param Tag the dwarf::Tag to assing to the llvm::DIE object.
comment|/// \returns the newly created DIE object that is now a child owned by this
comment|/// object.
name|dwarfgen
operator|::
name|DIE
name|addChild
argument_list|(
argument|dwarf::Tag Tag
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/// A DWARF compile unit used to generate DWARF compile/type units.
comment|///
comment|/// Instances of these classes are created by instances of the Generator
comment|/// class. All information required to generate a DWARF compile unit is
comment|/// contained inside this class.
name|class
name|CompileUnit
block|{
name|Generator
modifier|&
name|DG
decl_stmt|;
name|BasicDIEUnit
name|DU
decl_stmt|;
name|public
label|:
name|CompileUnit
argument_list|(
argument|Generator&D
argument_list|,
argument|uint16_t V
argument_list|,
argument|uint8_t A
argument_list|)
block|:
name|DG
argument_list|(
name|D
argument_list|)
operator|,
name|DU
argument_list|(
argument|V
argument_list|,
argument|A
argument_list|,
argument|dwarf::DW_TAG_compile_unit
argument_list|)
block|{}
name|DIE
name|getUnitDIE
argument_list|()
expr_stmt|;
name|Generator
modifier|&
name|getGenerator
parameter_list|()
block|{
return|return
name|DG
return|;
block|}
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|DU
operator|.
name|getDebugSectionOffset
argument_list|()
return|;
block|}
name|uint64_t
name|getLength
argument_list|()
specifier|const
block|{
return|return
name|DU
operator|.
name|getLength
argument_list|()
return|;
block|}
name|uint16_t
name|getVersion
argument_list|()
specifier|const
block|{
return|return
name|DU
operator|.
name|getDwarfVersion
argument_list|()
return|;
block|}
name|uint16_t
name|getAddressSize
argument_list|()
specifier|const
block|{
return|return
name|DU
operator|.
name|getAddressSize
argument_list|()
return|;
block|}
name|void
name|setOffset
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
block|{
name|DU
operator|.
name|setDebugSectionOffset
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
block|}
name|void
name|setLength
parameter_list|(
name|uint64_t
name|Length
parameter_list|)
block|{
name|DU
operator|.
name|setLength
argument_list|(
name|Length
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// A DWARF generator.
comment|///
comment|/// Generate DWARF for unit tests by creating any instance of this class and
comment|/// calling Generator::addCompileUnit(), and then getting the dwarfgen::DIE from
comment|/// the returned compile unit and adding attributes and children to each DIE.
name|class
name|Generator
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|MCRegisterInfo
operator|>
name|MRI
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCAsmInfo
operator|>
name|MAI
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCObjectFileInfo
operator|>
name|MOFI
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCContext
operator|>
name|MC
expr_stmt|;
name|MCAsmBackend
modifier|*
name|MAB
decl_stmt|;
comment|// Owned by MCStreamer
name|std
operator|::
name|unique_ptr
operator|<
name|MCInstrInfo
operator|>
name|MII
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCSubtargetInfo
operator|>
name|MSTI
expr_stmt|;
name|MCCodeEmitter
modifier|*
name|MCE
decl_stmt|;
comment|// Owned by MCStreamer
name|MCStreamer
modifier|*
name|MS
decl_stmt|;
comment|// Owned by AsmPrinter
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|TM
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|AsmPrinter
operator|>
name|Asm
expr_stmt|;
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DwarfStringPool
operator|>
name|StringPool
expr_stmt|;
comment|// Entries owned by Allocator.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|CompileUnit
operator|>>
name|CompileUnits
expr_stmt|;
name|DIEAbbrevSet
name|Abbreviations
decl_stmt|;
name|SmallString
operator|<
literal|4096
operator|>
name|FileBytes
expr_stmt|;
comment|/// The stream we use to generate the DWARF into as an ELF file.
name|std
operator|::
name|unique_ptr
operator|<
name|raw_svector_ostream
operator|>
name|Stream
expr_stmt|;
comment|/// The DWARF version to generate.
name|uint16_t
name|Version
decl_stmt|;
comment|/// Private constructor, call Generator::Create(...) to get a DWARF generator
comment|/// expected.
name|Generator
argument_list|()
expr_stmt|;
comment|/// Create the streamer and setup the output buffer.
name|llvm
operator|::
name|Error
name|init
argument_list|(
argument|Triple TheTriple
argument_list|,
argument|uint16_t DwarfVersion
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// Create a DWARF generator or get an appropriate error.
comment|///
comment|/// \param TheTriple the triple to use when creating any required support
comment|/// classes needed to emit the DWARF.
comment|/// \param DwarfVersion the version of DWARF to emit.
comment|///
comment|/// \returns a llvm::Expected that either contains a unique_ptr to a Generator
comment|/// or a llvm::Error.
specifier|static
name|llvm
operator|::
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Generator
operator|>>
name|create
argument_list|(
argument|Triple TheTriple
argument_list|,
argument|uint16_t DwarfVersion
argument_list|)
expr_stmt|;
operator|~
name|Generator
argument_list|()
expr_stmt|;
comment|/// Generate all DWARF sections and return a memory buffer that
comment|/// contains an ELF file that contains the DWARF.
name|StringRef
name|generate
parameter_list|()
function_decl|;
comment|/// Add a compile unit to be generated.
comment|///
comment|/// \returns a dwarfgen::CompileUnit that can be used to retrieve the compile
comment|/// unit dwarfgen::DIE that can be used to add attributes and add child DIE
comment|/// objedts to.
name|dwarfgen
operator|::
name|CompileUnit
operator|&
name|addCompileUnit
argument_list|()
expr_stmt|;
name|BumpPtrAllocator
modifier|&
name|getAllocator
parameter_list|()
block|{
return|return
name|Allocator
return|;
block|}
name|AsmPrinter
operator|*
name|getAsmPrinter
argument_list|()
specifier|const
block|{
return|return
name|Asm
operator|.
name|get
argument_list|()
return|;
block|}
name|DIEAbbrevSet
modifier|&
name|getAbbrevSet
parameter_list|()
block|{
return|return
name|Abbreviations
return|;
block|}
name|DwarfStringPool
modifier|&
name|getStringPool
parameter_list|()
block|{
return|return
operator|*
name|StringPool
return|;
block|}
comment|/// Save the generated DWARF file to disk.
comment|///
comment|/// \param Path the path to save the ELF file to.
name|bool
name|saveFile
parameter_list|(
name|StringRef
name|Path
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace dwarfgen
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_UNITTESTS_DEBUG_INFO_DWARF_DWARFGENERATOR_H
end_comment

end_unit

