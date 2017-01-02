begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFFormValue.h ----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFFORMVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFFORMVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|DWARFUnit
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFFormValue
block|{
name|public
label|:
enum|enum
name|FormClass
block|{
name|FC_Unknown
block|,
name|FC_Address
block|,
name|FC_Block
block|,
name|FC_Constant
block|,
name|FC_String
block|,
name|FC_Flag
block|,
name|FC_Reference
block|,
name|FC_Indirect
block|,
name|FC_SectionOffset
block|,
name|FC_Exprloc
block|}
enum|;
name|private
label|:
struct|struct
name|ValueType
block|{
name|ValueType
argument_list|()
operator|:
name|data
argument_list|(
argument|nullptr
argument_list|)
block|{
name|uval
operator|=
literal|0
block|;     }
expr|union
block|{
name|uint64_t
name|uval
block|;
name|int64_t
name|sval
block|;
specifier|const
name|char
operator|*
name|cstr
block|;     }
expr_stmt|;
specifier|const
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
name|dwarf
operator|::
name|Form
name|Form
expr_stmt|;
comment|// Form for this value.
name|ValueType
name|Value
decl_stmt|;
comment|// Contains all data for the form.
specifier|const
name|DWARFUnit
modifier|*
name|U
decl_stmt|;
comment|// Remember the DWARFUnit at extract time.
name|public
label|:
name|DWARFFormValue
argument_list|(
argument|dwarf::Form F = dwarf::Form(
literal|0
argument|)
argument_list|)
block|:
name|Form
argument_list|(
name|F
argument_list|)
operator|,
name|U
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|dwarf
operator|::
name|Form
name|getForm
argument_list|()
specifier|const
block|{
return|return
name|Form
return|;
block|}
name|void
name|setForm
argument_list|(
name|dwarf
operator|::
name|Form
name|F
argument_list|)
block|{
name|Form
operator|=
name|F
expr_stmt|;
block|}
name|bool
name|isFormClass
argument_list|(
name|FormClass
name|FC
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|DWARFUnit
operator|*
name|getUnit
argument_list|()
specifier|const
block|{
return|return
name|U
return|;
block|}
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief extracts a value in data at offset *offset_ptr.
comment|///
comment|/// The passed DWARFUnit is allowed to be nullptr, in which
comment|/// case no relocation processing will be performed and some
comment|/// kind of forms that depend on Unit information are disallowed.
comment|/// \returns whether the extraction succeeded.
name|bool
name|extractValue
parameter_list|(
specifier|const
name|DataExtractor
modifier|&
name|Data
parameter_list|,
name|uint32_t
modifier|*
name|OffsetPtr
parameter_list|,
specifier|const
name|DWARFUnit
modifier|*
name|U
parameter_list|)
function_decl|;
name|bool
name|isInlinedCStr
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|data
operator|!=
name|nullptr
operator|&&
name|Value
operator|.
name|data
operator|==
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|Value
operator|.
name|cstr
return|;
block|}
comment|/// getAsFoo functions below return the extracted value as Foo if only
comment|/// DWARFFormValue has form class is suitable for representing Foo.
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsReference
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsUnsignedConstant
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|int64_t
operator|>
name|getAsSignedConstant
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
specifier|const
name|char
operator|*
operator|>
name|getAsCString
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsAddress
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsSectionOffset
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|getAsBlock
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsCStringOffset
argument_list|()
specifier|const
expr_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getAsReferenceUVal
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the fixed byte size for a given form.
comment|///
comment|/// If the form always has a fixed valid byte size that doesn't depend on a
comment|/// DWARFUnit, then an Optional with a value will be returned. If the form
comment|/// can vary in size depending on the DWARFUnit (DWARF version, address byte
comment|/// size, or DWARF 32/64) and the DWARFUnit is valid, then an Optional with a
comment|/// valid value is returned. If the form is always encoded using a variable
comment|/// length storage format (ULEB or SLEB numbers or blocks) or the size
comment|/// depends on a DWARFUnit and the DWARFUnit is NULL, then None will be
comment|/// returned.
comment|/// \param Form The DWARF form to get the fixed byte size for
comment|/// \param U The DWARFUnit that can be used to help determine the byte size.
comment|///
comment|/// \returns Optional<uint8_t> value with the fixed byte size or None if
comment|/// \p Form doesn't have a fixed byte size or a DWARFUnit wasn't supplied
comment|/// and was needed to calculate the byte size.
specifier|static
name|Optional
operator|<
name|uint8_t
operator|>
name|getFixedByteSize
argument_list|(
argument|dwarf::Form Form
argument_list|,
argument|const DWARFUnit *U = nullptr
argument_list|)
expr_stmt|;
comment|/// Get the fixed byte size for a given form.
comment|///
comment|/// If the form has a fixed byte size given a valid DWARF version and address
comment|/// byte size, then an Optional with a valid value is returned. If the form
comment|/// is always encoded using a variable length storage format (ULEB or SLEB
comment|/// numbers or blocks) then None will be returned.
comment|///
comment|/// \param Form DWARF form to get the fixed byte size for
comment|/// \param Version DWARF version number.
comment|/// \param AddrSize size of an address in bytes.
comment|/// \param Format enum value from llvm::dwarf::DwarfFormat.
comment|/// \returns Optional<uint8_t> value with the fixed byte size or None if
comment|/// \p Form doesn't have a fixed byte size.
specifier|static
name|Optional
operator|<
name|uint8_t
operator|>
name|getFixedByteSize
argument_list|(
argument|dwarf::Form Form
argument_list|,
argument|uint16_t Version
argument_list|,
argument|uint8_t AddrSize
argument_list|,
argument|llvm::dwarf::DwarfFormat Format
argument_list|)
expr_stmt|;
comment|/// Skip a form in \p debug_info_data at offset specified by \p offset_ptr.
comment|///
comment|/// Skips the bytes for this form in the debug info and updates the offset.
comment|///
comment|/// \param debug_info_data the .debug_info data to use to skip the value.
comment|/// \param offset_ptr a reference to the offset that will be updated.
comment|/// \param U the DWARFUnit to use when skipping the form in case the form
comment|/// size differs according to data in the DWARFUnit.
comment|/// \returns true on success, false if the form was not skipped.
name|bool
name|skipValue
argument_list|(
name|DataExtractor
name|debug_info_data
argument_list|,
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
specifier|const
name|DWARFUnit
operator|*
name|U
argument_list|)
decl|const
decl_stmt|;
comment|/// Skip a form in \p debug_info_data at offset specified by \p offset_ptr.
comment|///
comment|/// Skips the bytes for this form in the debug info and updates the offset.
comment|///
comment|/// \param form the DW_FORM enumeration that indicates the form to skip.
comment|/// \param debug_info_data the .debug_info data to use to skip the value.
comment|/// \param offset_ptr a reference to the offset that will be updated.
comment|/// \param U the DWARFUnit to use when skipping the form in case the form
comment|/// size differs according to data in the DWARFUnit.
comment|/// \returns true on success, false if the form was not skipped.
specifier|static
name|bool
name|skipValue
argument_list|(
name|dwarf
operator|::
name|Form
name|form
argument_list|,
name|DataExtractor
name|debug_info_data
argument_list|,
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
specifier|const
name|DWARFUnit
operator|*
name|U
argument_list|)
decl_stmt|;
comment|/// Skip a form in \p debug_info_data at offset specified by \p offset_ptr.
comment|///
comment|/// Skips the bytes for this form in the debug info and updates the offset.
comment|///
comment|/// \param form the DW_FORM enumeration that indicates the form to skip.
comment|/// \param debug_info_data the .debug_info data to use to skip the value.
comment|/// \param offset_ptr a reference to the offset that will be updated.
comment|/// \param Version DWARF version number.
comment|/// \param AddrSize size of an address in bytes.
comment|/// \param Format enum value from llvm::dwarf::DwarfFormat.
comment|/// \returns true on success, false if the form was not skipped.
specifier|static
name|bool
name|skipValue
argument_list|(
name|dwarf
operator|::
name|Form
name|form
argument_list|,
name|DataExtractor
name|debug_info_data
argument_list|,
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint16_t
name|Version
argument_list|,
name|uint8_t
name|AddrSize
argument_list|,
name|llvm
operator|::
name|dwarf
operator|::
name|DwarfFormat
name|Format
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|dumpString
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

