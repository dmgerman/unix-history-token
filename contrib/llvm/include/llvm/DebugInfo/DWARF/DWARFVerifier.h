begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFVerifier.h ----------------------------------------------------===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFVERIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFVERIFIER_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
struct_decl|struct
name|DWARFAttribute
struct_decl|;
name|class
name|DWARFContext
decl_stmt|;
name|class
name|DWARFDie
decl_stmt|;
name|class
name|DWARFUnit
decl_stmt|;
comment|/// A class that verifies DWARF debug information given a DWARF Context.
name|class
name|DWARFVerifier
block|{
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|DWARFContext
modifier|&
name|DCtx
decl_stmt|;
comment|/// A map that tracks all references (converted absolute references) so we
comment|/// can verify each reference points to a valid DIE and not an offset that
comment|/// lies between to valid DIEs.
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|std
operator|::
name|set
operator|<
name|uint32_t
operator|>>
name|ReferenceToDIEOffsets
expr_stmt|;
name|uint32_t
name|NumDebugInfoErrors
decl_stmt|;
name|uint32_t
name|NumDebugLineErrors
decl_stmt|;
comment|/// Verifies the attribute's DWARF attribute and its value.
comment|///
comment|/// This function currently checks for:
comment|/// - DW_AT_ranges values is a valid .debug_ranges offset
comment|/// - DW_AT_stmt_list is a valid .debug_line offset
comment|///
comment|/// @param Die          The DWARF DIE that owns the attribute value
comment|/// @param AttrValue    The DWARF attribute value to check
name|void
name|verifyDebugInfoAttribute
parameter_list|(
specifier|const
name|DWARFDie
modifier|&
name|Die
parameter_list|,
name|DWARFAttribute
modifier|&
name|AttrValue
parameter_list|)
function_decl|;
comment|/// Verifies the attribute's DWARF form.
comment|///
comment|/// This function currently checks for:
comment|/// - All DW_FORM_ref values that are CU relative have valid CU offsets
comment|/// - All DW_FORM_ref_addr values have valid .debug_info offsets
comment|/// - All DW_FORM_strp values have valid .debug_str offsets
comment|///
comment|/// @param Die          The DWARF DIE that owns the attribute value
comment|/// @param AttrValue    The DWARF attribute value to check
name|void
name|verifyDebugInfoForm
parameter_list|(
specifier|const
name|DWARFDie
modifier|&
name|Die
parameter_list|,
name|DWARFAttribute
modifier|&
name|AttrValue
parameter_list|)
function_decl|;
comment|/// Verifies the all valid references that were found when iterating through
comment|/// all of the DIE attributes.
comment|///
comment|/// This function will verify that all references point to DIEs whose DIE
comment|/// offset matches. This helps to ensure if a DWARF link phase moved things
comment|/// around, that it doesn't create invalid references by failing to relocate
comment|/// CU relative and absolute references.
name|void
name|verifyDebugInfoReferences
parameter_list|()
function_decl|;
comment|/// Verify the the DW_AT_stmt_list encoding and value and ensure that no
comment|/// compile units that have the same DW_AT_stmt_list value.
name|void
name|verifyDebugLineStmtOffsets
parameter_list|()
function_decl|;
comment|/// Verify that all of the rows in the line table are valid.
comment|///
comment|/// This function currently checks for:
comment|/// - addresses within a sequence that decrease in value
comment|/// - invalid file indexes
name|void
name|verifyDebugLineRows
parameter_list|()
function_decl|;
name|public
label|:
name|DWARFVerifier
argument_list|(
name|raw_ostream
operator|&
name|S
argument_list|,
name|DWARFContext
operator|&
name|D
argument_list|)
operator|:
name|OS
argument_list|(
name|S
argument_list|)
operator|,
name|DCtx
argument_list|(
name|D
argument_list|)
operator|,
name|NumDebugInfoErrors
argument_list|(
literal|0
argument_list|)
operator|,
name|NumDebugLineErrors
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Verify the information in the .debug_info section.
comment|///
comment|/// Any errors are reported to the stream that was this object was
comment|/// constructed with.
comment|///
comment|/// @return True if the .debug_info verifies successfully, false otherwise.
name|bool
name|handleDebugInfo
argument_list|()
expr_stmt|;
comment|/// Verify the information in the .debug_line section.
comment|///
comment|/// Any errors are reported to the stream that was this object was
comment|/// constructed with.
comment|///
comment|/// @return True if the .debug_line verifies successfully, false otherwise.
name|bool
name|handleDebugLine
parameter_list|()
function_decl|;
block|}
empty_stmt|;
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
comment|// LLVM_DEBUGINFO_DWARF_DWARFCONTEXT_H
end_comment

end_unit

