begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFTypeUnit.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFTYPEUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFTYPEUNIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFUnit.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFUnitIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWARFContext
decl_stmt|;
name|class
name|DWARFDebugAbbrev
decl_stmt|;
struct_decl|struct
name|DWARFSection
struct_decl|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFTypeUnit
range|:
name|public
name|DWARFUnit
block|{
name|private
operator|:
name|uint64_t
name|TypeHash
block|;
name|uint32_t
name|TypeOffset
block|;
name|public
operator|:
name|DWARFTypeUnit
argument_list|(
argument|DWARFContext&Context
argument_list|,
argument|const DWARFSection&Section
argument_list|,
argument|const DWARFDebugAbbrev *DA
argument_list|,
argument|const DWARFSection *RS
argument_list|,
argument|StringRef SS
argument_list|,
argument|StringRef SOS
argument_list|,
argument|StringRef AOS
argument_list|,
argument|StringRef LS
argument_list|,
argument|bool LE
argument_list|,
argument|bool IsDWO
argument_list|,
argument|const DWARFUnitSectionBase&UnitSection
argument_list|,
argument|const DWARFUnitIndex::Entry *Entry
argument_list|)
operator|:
name|DWARFUnit
argument_list|(
argument|Context
argument_list|,
argument|Section
argument_list|,
argument|DA
argument_list|,
argument|RS
argument_list|,
argument|SS
argument_list|,
argument|SOS
argument_list|,
argument|AOS
argument_list|,
argument|LS
argument_list|,
argument|LE
argument_list|,
argument|IsDWO
argument_list|,
argument|UnitSection
argument_list|,
argument|Entry
argument_list|)
block|{}
name|uint32_t
name|getHeaderSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|DWARFUnit
operator|::
name|getHeaderSize
argument_list|()
operator|+
literal|12
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool Brief = false
argument_list|)
block|;
specifier|static
specifier|const
name|DWARFSectionKind
name|Section
operator|=
name|DW_SECT_TYPES
block|;
name|protected
operator|:
name|bool
name|extractImpl
argument_list|(
argument|DataExtractor debug_info
argument_list|,
argument|uint32_t *offset_ptr
argument_list|)
name|override
block|; }
decl_stmt|;
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
comment|// LLVM_DEBUGINFO_DWARF_DWARFTYPEUNIT_H
end_comment

end_unit

