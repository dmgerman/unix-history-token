begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDie.h --------------------------------------------------------===//
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
name|LLVM_LIB_DEBUGINFO_DWARFDIE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_DWARFDIE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFDebugInfoEntry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWARFUnit
decl_stmt|;
name|class
name|DWARFDebugInfoEntry
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// Utility class that carries the DWARF compile/type unit and the debug info
comment|/// entry in an object.
comment|///
comment|/// When accessing information from a debug info entry we always need to DWARF
comment|/// compile/type unit in order to extract the info correctly as some information
comment|/// is relative to the compile/type unit. Prior to this class the DWARFUnit and
comment|/// the DWARFDebugInfoEntry was passed around separately and there was the
comment|/// possibility for error if the wrong DWARFUnit was used to extract a unit
comment|/// relative offset. This class helps to ensure that this doesn't happen and
comment|/// also simplifies the attribute extraction calls by not having to specify the
comment|/// DWARFUnit for each call.
name|class
name|DWARFDie
block|{
name|DWARFUnit
modifier|*
name|U
decl_stmt|;
specifier|const
name|DWARFDebugInfoEntry
modifier|*
name|Die
decl_stmt|;
name|public
label|:
name|DWARFDie
argument_list|()
operator|:
name|U
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Die
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|DWARFDie
argument_list|(
name|DWARFUnit
operator|*
name|Unit
argument_list|,
specifier|const
name|DWARFDebugInfoEntry
operator|*
name|D
argument_list|)
operator|:
name|U
argument_list|(
name|Unit
argument_list|)
operator|,
name|Die
argument_list|(
argument|D
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|U
operator|&&
name|Die
return|;
block|}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
return|;
block|}
specifier|const
name|DWARFDebugInfoEntry
operator|*
name|getDebugInfoEntry
argument_list|()
specifier|const
block|{
return|return
name|Die
return|;
block|}
name|DWARFUnit
operator|*
name|getDwarfUnit
argument_list|()
specifier|const
block|{
return|return
name|U
return|;
block|}
comment|/// Get the abbreviation declaration for this DIE.
comment|///
comment|/// \returns the abbreviation declaration or NULL for null tags.
specifier|const
name|DWARFAbbreviationDeclaration
operator|*
name|getAbbreviationDeclarationPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"must check validity prior to calling"
argument_list|)
block|;
return|return
name|Die
operator|->
name|getAbbreviationDeclarationPtr
argument_list|()
return|;
block|}
comment|/// Get the absolute offset into the debug info or types section.
comment|///
comment|/// \returns the DIE offset or -1U if invalid.
name|uint32_t
name|getOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"must check validity prior to calling"
argument_list|)
block|;
return|return
name|Die
operator|->
name|getOffset
argument_list|()
return|;
block|}
name|dwarf
operator|::
name|Tag
name|getTag
argument_list|()
specifier|const
block|{
name|auto
name|AbbrevDecl
operator|=
name|getAbbreviationDeclarationPtr
argument_list|()
block|;
if|if
condition|(
name|AbbrevDecl
condition|)
return|return
name|AbbrevDecl
operator|->
name|getTag
argument_list|()
return|;
return|return
name|dwarf
operator|::
name|DW_TAG_null
return|;
block|}
name|bool
name|hasChildren
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"must check validity prior to calling"
argument_list|)
block|;
return|return
name|Die
operator|->
name|hasChildren
argument_list|()
return|;
block|}
comment|/// Returns true for a valid DIE that terminates a sibling chain.
name|bool
name|isNULL
argument_list|()
specifier|const
block|{
return|return
name|getAbbreviationDeclarationPtr
argument_list|()
operator|==
name|nullptr
return|;
block|}
comment|/// Returns true if DIE represents a subprogram (not inlined).
name|bool
name|isSubprogramDIE
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if DIE represents a subprogram or an inlined subroutine.
name|bool
name|isSubroutineDIE
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the parent of this DIE object.
comment|///
comment|/// \returns a valid DWARFDie instance if this object has a parent or an
comment|/// invalid DWARFDie instance if it doesn't.
name|DWARFDie
name|getParent
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the sibling of this DIE object.
comment|///
comment|/// \returns a valid DWARFDie instance if this object has a sibling or an
comment|/// invalid DWARFDie instance if it doesn't.
name|DWARFDie
name|getSibling
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the first child of this DIE object.
comment|///
comment|/// \returns a valid DWARFDie instance if this object has children or an
comment|/// invalid DWARFDie instance if it doesn't.
name|DWARFDie
name|getFirstChild
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isValid
argument_list|()
operator|&&
name|Die
operator|->
name|hasChildren
argument_list|()
condition|)
return|return
name|DWARFDie
argument_list|(
name|U
argument_list|,
name|Die
operator|+
literal|1
argument_list|)
return|;
return|return
name|DWARFDie
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Dump the DIE and all of its attributes to the supplied stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OS the stream to use for output.
end_comment

begin_comment
comment|/// \param recurseDepth the depth to recurse to when dumping this DIE and its
end_comment

begin_comment
comment|/// children.
end_comment

begin_comment
comment|/// \param indent the number of characters to indent each line that is output.
end_comment

begin_decl_stmt
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|recurseDepth
argument_list|,
name|unsigned
name|indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns an optional DWARFFormValue that will have the form value if the
end_comment

begin_comment
comment|/// attribute was successfully extracted.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|DWARFFormValue
operator|>
name|getAttributeValue
argument_list|(
argument|dwarf::Attribute Attr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as a C string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \param FailValue the value to return if this DIE doesn't have this
end_comment

begin_comment
comment|/// attribute.
end_comment

begin_comment
comment|/// \returns the NULL terminated C string value owned by the DWARF section
end_comment

begin_comment
comment|/// that contains the string or FailValue if the attribute doesn't exist or
end_comment

begin_comment
comment|/// if the attribute's form isn't a form that describes an string.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getAttributeValueAsString
argument_list|(
name|dwarf
operator|::
name|Attribute
name|Attr
argument_list|,
specifier|const
name|char
operator|*
name|FailValue
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as an address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns an optional value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getAttributeValueAsAddress
argument_list|(
argument|dwarf::Attribute Attr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as a signed integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns an optional value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|int64_t
operator|>
name|getAttributeValueAsSignedConstant
argument_list|(
argument|dwarf::Attribute Attr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as an unsigned integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns an optional value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getAttributeValueAsUnsignedConstant
argument_list|(
argument|dwarf::Attribute Attr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as absolute DIE Offset.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns an optional value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getAttributeValueAsReference
argument_list|(
argument|dwarf::Attribute Attr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as absolute section offset.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns an optional value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getAttributeValueAsSectionOffset
argument_list|(
argument|dwarf::Attribute Attr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extract the specified attribute from this DIE as the referenced DIE.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Regardless of the reference type, return the correct DWARFDie instance if
end_comment

begin_comment
comment|/// the attribute exists. The returned DWARFDie object might be from another
end_comment

begin_comment
comment|/// DWARFUnit, but that is all encapsulated in the new DWARFDie object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extract an attribute value from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the attribute value in any DW_AT_specification or
end_comment

begin_comment
comment|/// DW_AT_abstract_origin referenced DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the attribute to extract.
end_comment

begin_comment
comment|/// \returns a valid DWARFDie instance if the attribute exists, or an invalid
end_comment

begin_comment
comment|/// DWARFDie object if it doesn't.
end_comment

begin_decl_stmt
name|DWARFDie
name|getAttributeValueAsReferencedDie
argument_list|(
name|dwarf
operator|::
name|Attribute
name|Attr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Extract the range base attribute from this DIE as absolute section offset.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a utility function that checks for either the DW_AT_rnglists_base
end_comment

begin_comment
comment|/// or DW_AT_GNU_ranges_base attribute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns anm optional absolute section offset value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getRangesBaseAttribute
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the DW_AT_high_pc attribute value as an address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In DWARF version 4 and later the high PC can be encoded as an offset from
end_comment

begin_comment
comment|/// the DW_AT_low_pc. This function takes care of extracting the value as an
end_comment

begin_comment
comment|/// address or offset and adds it to the low PC if needed and returns the
end_comment

begin_comment
comment|/// value as an optional in case the DIE doesn't have a DW_AT_high_pc
end_comment

begin_comment
comment|/// attribute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param LowPC the low PC that might be needed to calculate the high PC.
end_comment

begin_comment
comment|/// \returns an optional address value for the attribute.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|uint64_t
operator|>
name|getHighPC
argument_list|(
argument|uint64_t LowPC
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Retrieves DW_AT_low_pc and DW_AT_high_pc from CU.
end_comment

begin_comment
comment|/// Returns true if both attributes are present.
end_comment

begin_decl_stmt
name|bool
name|getLowAndHighPC
argument_list|(
name|uint64_t
operator|&
name|LowPC
argument_list|,
name|uint64_t
operator|&
name|HighPC
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get the address ranges for this DIE.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the hi/low PC range if both attributes are available or exrtracts the
end_comment

begin_comment
comment|/// non-contiguous address ranges from the DW_AT_ranges attribute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extracts the range information from this DIE only. This call doesn't look
end_comment

begin_comment
comment|/// for the range in any DW_AT_specification or DW_AT_abstract_origin DIEs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a address range vector that might be empty if no address range
end_comment

begin_comment
comment|/// information is available.
end_comment

begin_expr_stmt
name|DWARFAddressRangesVector
name|getAddressRanges
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get all address ranges for any DW_TAG_subprogram DIEs in this DIE or any
end_comment

begin_comment
comment|/// of its children.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get the hi/low PC range if both attributes are available or exrtracts the
end_comment

begin_comment
comment|/// non-contiguous address ranges from the DW_AT_ranges attribute for this DIE
end_comment

begin_comment
comment|/// and all children.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Ranges the addres range vector to fill in.
end_comment

begin_decl_stmt
name|void
name|collectChildrenAddressRanges
argument_list|(
name|DWARFAddressRangesVector
operator|&
name|Ranges
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|addressRangeContainsAddress
argument_list|(
specifier|const
name|uint64_t
name|Address
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If a DIE represents a subprogram (or inlined subroutine), returns its
end_comment

begin_comment
comment|/// mangled name (or short name, if mangled is missing). This name may be
end_comment

begin_comment
comment|/// fetched from specification or abstract origin for this subprogram.
end_comment

begin_comment
comment|/// Returns null if no name is found.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getSubroutineName
argument_list|(
name|DINameKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the DIE name resolving DW_AT_sepcification or DW_AT_abstract_origin
end_comment

begin_comment
comment|/// references if necessary. Returns null if no name is found.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getName
argument_list|(
name|DINameKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Retrieves values of DW_AT_call_file, DW_AT_call_line and DW_AT_call_column
end_comment

begin_comment
comment|/// from DIE (or zeroes if they are missing). This function looks for
end_comment

begin_comment
comment|/// DW_AT_call attributes in this DIE only, it will not resolve the attribute
end_comment

begin_comment
comment|/// values in any DW_AT_specification or DW_AT_abstract_origin DIEs.
end_comment

begin_comment
comment|/// \param CallFile filled in with non-zero if successful, zero if there is no
end_comment

begin_comment
comment|/// DW_AT_call_file attribute in this DIE.
end_comment

begin_comment
comment|/// \param CallLine filled in with non-zero if successful, zero if there is no
end_comment

begin_comment
comment|/// DW_AT_call_line attribute in this DIE.
end_comment

begin_comment
comment|/// \param CallColumn filled in with non-zero if successful, zero if there is
end_comment

begin_comment
comment|/// no DW_AT_call_column attribute in this DIE.
end_comment

begin_decl_stmt
name|void
name|getCallerFrame
argument_list|(
name|uint32_t
operator|&
name|CallFile
argument_list|,
name|uint32_t
operator|&
name|CallLine
argument_list|,
name|uint32_t
operator|&
name|CallColumn
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get inlined chain for a given address, rooted at the current DIE.
end_comment

begin_comment
comment|/// Returns empty chain if address is not contained in address range
end_comment

begin_comment
comment|/// of current DIE.
end_comment

begin_decl_stmt
name|void
name|getInlinedChainForAddress
argument_list|(
specifier|const
name|uint64_t
name|Address
argument_list|,
name|SmallVectorImpl
operator|<
name|DWARFDie
operator|>
operator|&
name|InlinedChain
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|iterator
operator|>
name|children
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DWARFDie
operator|&
name|LHS
operator|,
specifier|const
name|DWARFDie
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|getDebugInfoEntry
argument_list|()
operator|==
name|RHS
operator|.
name|getDebugInfoEntry
argument_list|()
operator|&&
name|LHS
operator|.
name|getDwarfUnit
argument_list|()
operator|==
name|RHS
operator|.
name|getDwarfUnit
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|DWARFDie
operator|&
name|LHS
operator|,
specifier|const
name|DWARFDie
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|class
name|DWARFDie
operator|::
name|iterator
operator|:
name|public
name|iterator_facade_base
operator|<
name|iterator
operator|,
name|std
operator|::
name|forward_iterator_tag
operator|,
specifier|const
name|DWARFDie
operator|>
block|{
name|DWARFDie
name|Die
block|;
name|void
name|skipNull
argument_list|()
block|{
if|if
condition|(
name|Die
operator|&&
name|Die
operator|.
name|isNULL
argument_list|()
condition|)
name|Die
operator|=
name|DWARFDie
argument_list|()
expr_stmt|;
block|}
name|public
operator|:
name|iterator
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|iterator
argument_list|(
argument|DWARFDie D
argument_list|)
end_macro

begin_macro
unit|:
name|Die
argument_list|(
argument|D
argument_list|)
end_macro

begin_block
block|{
comment|// If we start out with only a Null DIE then invalidate.
name|skipNull
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|Die
operator|=
name|Die
operator|.
name|getSibling
argument_list|()
block|;
comment|// Don't include the NULL die when iterating.
name|skipNull
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Die
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|DWARFDie
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Die
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|Die
operator|==
name|X
operator|.
name|Die
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// These inline functions must follow the DWARFDie::iterator definition above
end_comment

begin_comment
comment|// as they use functions from that class.
end_comment

begin_expr_stmt
specifier|inline
name|DWARFDie
operator|::
name|iterator
name|DWARFDie
operator|::
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|getFirstChild
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|DWARFDie
operator|::
name|iterator
name|DWARFDie
operator|::
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|iterator_range
operator|<
name|DWARFDie
operator|::
name|iterator
operator|>
name|DWARFDie
operator|::
name|children
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_DEBUGINFO_DWARFDIE_H
end_comment

end_unit

