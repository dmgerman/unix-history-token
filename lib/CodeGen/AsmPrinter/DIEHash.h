begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DIEHash.h - Dwarf Hashing Framework -------*- C++ -*--===//
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
comment|// This file contains support for DWARF4 hashing of DIEs.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DIEHASH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DIEHASH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DIE.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MD5.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|CompileUnit
decl_stmt|;
comment|/// \brief An object containing the capability of hashing and adding hash
comment|/// attributes onto a DIE.
name|class
name|DIEHash
block|{
comment|// Collection of all attributes used in hashing a particular DIE.
struct|struct
name|DIEAttrs
block|{
name|DIEValue
name|DW_AT_name
decl_stmt|;
name|DIEValue
name|DW_AT_accessibility
decl_stmt|;
name|DIEValue
name|DW_AT_address_class
decl_stmt|;
name|DIEValue
name|DW_AT_allocated
decl_stmt|;
name|DIEValue
name|DW_AT_artificial
decl_stmt|;
name|DIEValue
name|DW_AT_associated
decl_stmt|;
name|DIEValue
name|DW_AT_binary_scale
decl_stmt|;
name|DIEValue
name|DW_AT_bit_offset
decl_stmt|;
name|DIEValue
name|DW_AT_bit_size
decl_stmt|;
name|DIEValue
name|DW_AT_bit_stride
decl_stmt|;
name|DIEValue
name|DW_AT_byte_size
decl_stmt|;
name|DIEValue
name|DW_AT_byte_stride
decl_stmt|;
name|DIEValue
name|DW_AT_const_expr
decl_stmt|;
name|DIEValue
name|DW_AT_const_value
decl_stmt|;
name|DIEValue
name|DW_AT_containing_type
decl_stmt|;
name|DIEValue
name|DW_AT_count
decl_stmt|;
name|DIEValue
name|DW_AT_data_bit_offset
decl_stmt|;
name|DIEValue
name|DW_AT_data_location
decl_stmt|;
name|DIEValue
name|DW_AT_data_member_location
decl_stmt|;
name|DIEValue
name|DW_AT_decimal_scale
decl_stmt|;
name|DIEValue
name|DW_AT_decimal_sign
decl_stmt|;
name|DIEValue
name|DW_AT_default_value
decl_stmt|;
name|DIEValue
name|DW_AT_digit_count
decl_stmt|;
name|DIEValue
name|DW_AT_discr
decl_stmt|;
name|DIEValue
name|DW_AT_discr_list
decl_stmt|;
name|DIEValue
name|DW_AT_discr_value
decl_stmt|;
name|DIEValue
name|DW_AT_encoding
decl_stmt|;
name|DIEValue
name|DW_AT_enum_class
decl_stmt|;
name|DIEValue
name|DW_AT_endianity
decl_stmt|;
name|DIEValue
name|DW_AT_explicit
decl_stmt|;
name|DIEValue
name|DW_AT_is_optional
decl_stmt|;
name|DIEValue
name|DW_AT_location
decl_stmt|;
name|DIEValue
name|DW_AT_lower_bound
decl_stmt|;
name|DIEValue
name|DW_AT_mutable
decl_stmt|;
name|DIEValue
name|DW_AT_ordering
decl_stmt|;
name|DIEValue
name|DW_AT_picture_string
decl_stmt|;
name|DIEValue
name|DW_AT_prototyped
decl_stmt|;
name|DIEValue
name|DW_AT_small
decl_stmt|;
name|DIEValue
name|DW_AT_segment
decl_stmt|;
name|DIEValue
name|DW_AT_string_length
decl_stmt|;
name|DIEValue
name|DW_AT_threads_scaled
decl_stmt|;
name|DIEValue
name|DW_AT_upper_bound
decl_stmt|;
name|DIEValue
name|DW_AT_use_location
decl_stmt|;
name|DIEValue
name|DW_AT_use_UTF8
decl_stmt|;
name|DIEValue
name|DW_AT_variable_parameter
decl_stmt|;
name|DIEValue
name|DW_AT_virtuality
decl_stmt|;
name|DIEValue
name|DW_AT_visibility
decl_stmt|;
name|DIEValue
name|DW_AT_vtable_elem_location
decl_stmt|;
name|DIEValue
name|DW_AT_type
decl_stmt|;
comment|// Insert any additional ones here...
block|}
struct|;
name|public
label|:
name|DIEHash
argument_list|(
name|AsmPrinter
operator|*
name|A
operator|=
name|nullptr
argument_list|)
operator|:
name|AP
argument_list|(
argument|A
argument_list|)
block|{}
comment|/// \brief Computes the ODR signature.
name|uint64_t
name|computeDIEODRSignature
argument_list|(
specifier|const
name|DIE
operator|&
name|Die
argument_list|)
expr_stmt|;
comment|/// \brief Computes the CU signature.
name|uint64_t
name|computeCUSignature
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
comment|/// \brief Computes the type signature.
name|uint64_t
name|computeTypeSignature
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
comment|// Helper routines to process parts of a DIE.
name|private
label|:
comment|/// \brief Adds the parent context of \param Die to the hash.
name|void
name|addParentContext
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
comment|/// \brief Adds the attributes of \param Die to the hash.
name|void
name|addAttributes
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
comment|/// \brief Computes the full DWARF4 7.27 hash of the DIE.
name|void
name|computeHash
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|)
function_decl|;
comment|// Routines that add DIEValues to the hash.
name|public
label|:
comment|/// \brief Adds \param Value to the hash.
name|void
name|update
parameter_list|(
name|uint8_t
name|Value
parameter_list|)
block|{
name|Hash
operator|.
name|update
argument_list|(
name|Value
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Encodes and adds \param Value to the hash as a ULEB128.
name|void
name|addULEB128
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// \brief Encodes and adds \param Value to the hash as a SLEB128.
name|void
name|addSLEB128
parameter_list|(
name|int64_t
name|Value
parameter_list|)
function_decl|;
name|private
label|:
comment|/// \brief Adds \param Str to the hash and includes a NULL byte.
name|void
name|addString
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// \brief Collects the attributes of DIE \param Die into the \param Attrs
comment|/// structure.
name|void
name|collectAttributes
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|,
name|DIEAttrs
modifier|&
name|Attrs
parameter_list|)
function_decl|;
comment|/// \brief Hashes the attributes in \param Attrs in order.
name|void
name|hashAttributes
argument_list|(
specifier|const
name|DIEAttrs
operator|&
name|Attrs
argument_list|,
name|dwarf
operator|::
name|Tag
name|Tag
argument_list|)
decl_stmt|;
comment|/// \brief Hashes the data in a block like DIEValue, e.g. DW_FORM_block or
comment|/// DW_FORM_exprloc.
name|void
name|hashBlockData
argument_list|(
specifier|const
name|DIE
operator|::
name|value_range
operator|&
name|Values
argument_list|)
decl_stmt|;
comment|/// \brief Hashes the contents pointed to in the .debug_loc section.
name|void
name|hashLocList
parameter_list|(
specifier|const
name|DIELocList
modifier|&
name|LocList
parameter_list|)
function_decl|;
comment|/// \brief Hashes an individual attribute.
name|void
name|hashAttribute
argument_list|(
name|DIEValue
name|Value
argument_list|,
name|dwarf
operator|::
name|Tag
name|Tag
argument_list|)
decl_stmt|;
comment|/// \brief Hashes an attribute that refers to another DIE.
name|void
name|hashDIEEntry
argument_list|(
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|dwarf
operator|::
name|Tag
name|Tag
argument_list|,
specifier|const
name|DIE
operator|&
name|Entry
argument_list|)
decl_stmt|;
comment|/// \brief Hashes a reference to a named type in such a way that is
comment|/// independent of whether that type is described by a declaration or a
comment|/// definition.
name|void
name|hashShallowTypeReference
argument_list|(
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
specifier|const
name|DIE
operator|&
name|Entry
argument_list|,
name|StringRef
name|Name
argument_list|)
decl_stmt|;
comment|/// \brief Hashes a reference to a previously referenced type DIE.
name|void
name|hashRepeatedTypeReference
argument_list|(
name|dwarf
operator|::
name|Attribute
name|Attribute
argument_list|,
name|unsigned
name|DieNumber
argument_list|)
decl_stmt|;
name|void
name|hashNestedType
parameter_list|(
specifier|const
name|DIE
modifier|&
name|Die
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|private
label|:
name|MD5
name|Hash
decl_stmt|;
name|AsmPrinter
modifier|*
name|AP
decl_stmt|;
name|DenseMap
operator|<
specifier|const
name|DIE
operator|*
operator|,
name|unsigned
operator|>
name|Numbering
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

