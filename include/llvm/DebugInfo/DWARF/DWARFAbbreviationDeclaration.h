begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFAbbreviationDeclaration.h --------------------------*- C++ -*-===//
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
name|LLVM_LIB_DEBUGINFO_DWARFABBREVIATIONDECLARATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_DWARFABBREVIATIONDECLARATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Dwarf.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWARFUnit
decl_stmt|;
name|class
name|DWARFFormValue
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFAbbreviationDeclaration
block|{
name|public
label|:
struct|struct
name|AttributeSpec
block|{
name|AttributeSpec
argument_list|(
argument|dwarf::Attribute A
argument_list|,
argument|dwarf::Form F
argument_list|,
argument|Optional<uint8_t> S
argument_list|)
block|:
name|Attr
argument_list|(
name|A
argument_list|)
operator|,
name|Form
argument_list|(
name|F
argument_list|)
operator|,
name|ByteSize
argument_list|(
argument|S
argument_list|)
block|{}
name|dwarf
operator|::
name|Attribute
name|Attr
expr_stmt|;
name|dwarf
operator|::
name|Form
name|Form
expr_stmt|;
comment|/// If ByteSize has a value, then it contains the fixed size in bytes for
comment|/// the Form in this object. If ByteSize doesn't have a value, then the
comment|/// byte size of Form either varies according to the DWARFUnit that it is
comment|/// contained in or the value size varies and must be decoded from the
comment|/// debug information in order to determine its size.
name|Optional
operator|<
name|uint8_t
operator|>
name|ByteSize
expr_stmt|;
comment|/// Get the fixed byte size of this Form if possible. This function might
comment|/// use the DWARFUnit to calculate the size of the Form, like for
comment|/// DW_AT_address and DW_AT_ref_addr, so this isn't just an accessor for
comment|/// the ByteSize member.
name|Optional
operator|<
name|uint8_t
operator|>
name|getByteSize
argument_list|(
argument|const DWARFUnit&U
argument_list|)
specifier|const
expr_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|AttributeSpec
operator|,
literal|8
operator|>
name|AttributeSpecVector
expr_stmt|;
name|DWARFAbbreviationDeclaration
argument_list|()
expr_stmt|;
name|uint32_t
name|getCode
argument_list|()
specifier|const
block|{
return|return
name|Code
return|;
block|}
name|dwarf
operator|::
name|Tag
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|Tag
return|;
block|}
name|bool
name|hasChildren
argument_list|()
specifier|const
block|{
return|return
name|HasChildren
return|;
block|}
typedef|typedef
name|iterator_range
operator|<
name|AttributeSpecVector
operator|::
name|const_iterator
operator|>
name|attr_iterator_range
expr_stmt|;
name|attr_iterator_range
name|attributes
argument_list|()
specifier|const
block|{
return|return
name|attr_iterator_range
argument_list|(
name|AttributeSpecs
operator|.
name|begin
argument_list|()
argument_list|,
name|AttributeSpecs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|dwarf
operator|::
name|Form
name|getFormByIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
block|{
if|if
condition|(
name|idx
operator|<
name|AttributeSpecs
operator|.
name|size
argument_list|()
condition|)
return|return
name|AttributeSpecs
index|[
name|idx
index|]
operator|.
name|Form
return|;
return|return
name|dwarf
operator|::
name|Form
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Get the index of the specified attribute.
comment|///
comment|/// Searches the this abbreviation declaration for the index of the specified
comment|/// attribute.
comment|///
comment|/// \param attr DWARF attribute to search for.
comment|/// \returns Optional index of the attribute if found, None otherwise.
name|Optional
operator|<
name|uint32_t
operator|>
name|findAttributeIndex
argument_list|(
argument|dwarf::Attribute attr
argument_list|)
specifier|const
expr_stmt|;
comment|/// Extract a DWARF form value from a DIE specified by DIE offset.
comment|///
comment|/// Extract an attribute value for a DWARFUnit given the DIE offset and the
comment|/// attribute.
comment|///
comment|/// \param DIEOffset the DIE offset that points to the ULEB128 abbreviation
comment|/// code in the .debug_info data.
comment|/// \param Attr DWARF attribute to search for.
comment|/// \param U the DWARFUnit the contains the DIE.
comment|/// \returns Optional DWARF form value if the attribute was extracted.
name|Optional
operator|<
name|DWARFFormValue
operator|>
name|getAttributeValue
argument_list|(
argument|const uint32_t DIEOffset
argument_list|,
argument|const dwarf::Attribute Attr
argument_list|,
argument|const DWARFUnit&U
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|extract
parameter_list|(
name|DataExtractor
name|Data
parameter_list|,
name|uint32_t
modifier|*
name|OffsetPtr
parameter_list|)
function_decl|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|// Return an optional byte size of all attribute data in this abbreviation
comment|// if a constant byte size can be calculated given a DWARFUnit. This allows
comment|// DWARF parsing to be faster as many DWARF DIEs have a fixed byte size.
name|Optional
operator|<
name|size_t
operator|>
name|getFixedAttributesByteSize
argument_list|(
argument|const DWARFUnit&U
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// A helper structure that can quickly determine the size in bytes of an
comment|/// abbreviation declaration.
struct|struct
name|FixedSizeInfo
block|{
comment|/// The fixed byte size for fixed size forms.
name|uint16_t
name|NumBytes
decl_stmt|;
comment|/// Number of DW_FORM_address forms in this abbrevation declaration.
name|uint8_t
name|NumAddrs
decl_stmt|;
comment|/// Number of DW_FORM_ref_addr forms in this abbrevation declaration.
name|uint8_t
name|NumRefAddrs
decl_stmt|;
comment|/// Number of 4 byte in DWARF32 and 8 byte in DWARF64 forms.
name|uint8_t
name|NumDwarfOffsets
decl_stmt|;
comment|/// Constructor
name|FixedSizeInfo
argument_list|()
operator|:
name|NumBytes
argument_list|(
literal|0
argument_list|)
operator|,
name|NumAddrs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumRefAddrs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumDwarfOffsets
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Calculate the fixed size in bytes given a DWARFUnit.
comment|///
comment|/// \param U the DWARFUnit to use when determing the byte size.
comment|/// \returns the size in bytes for all attribute data in this abbreviation.
comment|/// The returned size does not include bytes for the  ULEB128 abbreviation
comment|/// code
name|size_t
name|getByteSize
argument_list|(
argument|const DWARFUnit&U
argument_list|)
specifier|const
expr_stmt|;
block|}
struct|;
name|uint32_t
name|Code
decl_stmt|;
name|dwarf
operator|::
name|Tag
name|Tag
expr_stmt|;
name|uint8_t
name|CodeByteSize
decl_stmt|;
name|bool
name|HasChildren
decl_stmt|;
name|AttributeSpecVector
name|AttributeSpecs
decl_stmt|;
comment|/// If this abbreviation has a fixed byte size then FixedAttributeSize member
comment|/// variable below will have a value.
name|Optional
operator|<
name|FixedSizeInfo
operator|>
name|FixedAttributeSize
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

