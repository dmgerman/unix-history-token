begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugMacro.h ----------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugMacro_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugMacro_h_
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/dwarf.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/DebugMacros.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DWARFDataExtractor
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_decl_stmt
name|class
name|SymbolFileDWARF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFDebugMacroHeader
block|{
name|public
label|:
enum|enum
name|HeaderFlagMask
block|{
name|OFFSET_SIZE_MASK
init|=
literal|0x1
block|,
name|DEBUG_LINE_OFFSET_MASK
init|=
literal|0x2
block|,
name|OPCODE_OPERANDS_TABLE_MASK
init|=
literal|0x4
block|}
enum|;
specifier|static
name|DWARFDebugMacroHeader
name|ParseHeader
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_macro_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
name|bool
name|OffsetIs64Bit
argument_list|()
specifier|const
block|{
return|return
name|m_offset_is_64_bit
return|;
block|}
name|private
label|:
specifier|static
name|void
name|SkipOperandTable
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_macro_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset
argument_list|)
decl_stmt|;
name|uint16_t
name|m_version
decl_stmt|;
name|bool
name|m_offset_is_64_bit
decl_stmt|;
name|uint64_t
name|m_debug_line_offset
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|DWARFDebugMacroEntry
block|{
name|public
label|:
specifier|static
name|void
name|ReadMacroEntries
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_macro_data
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_str_data
argument_list|,
specifier|const
name|bool
name|offset_is_64_bit
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|sect_offset
argument_list|,
name|SymbolFileDWARF
operator|*
name|sym_file_dwarf
argument_list|,
name|lldb_private
operator|::
name|DebugMacrosSP
operator|&
name|debug_macros_sp
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFDebugMacro_h_
end_comment

end_unit

