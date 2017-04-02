begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugInfoEntry.h -----------------------------------*- C++ -*-===//
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
name|LLVM_LIB_DEBUGINFO_DWARFDEBUGINFOENTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_DWARFDEBUGINFOENTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFAbbreviationDeclaration.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFDebugRangeList.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|DWARFDebugAranges
decl_stmt|;
name|class
name|DWARFCompileUnit
decl_stmt|;
name|class
name|DWARFUnit
decl_stmt|;
name|class
name|DWARFContext
decl_stmt|;
name|class
name|DWARFFormValue
decl_stmt|;
struct_decl|struct
name|DWARFDebugInfoEntryInlinedChain
struct_decl|;
comment|/// DWARFDebugInfoEntry - A DIE with only the minimum required data.
name|class
name|DWARFDebugInfoEntry
block|{
comment|/// Offset within the .debug_info of the start of this entry.
name|uint32_t
name|Offset
decl_stmt|;
comment|/// The integer depth of this DIE within the compile unit DIEs where the
comment|/// compile/type unit DIE has a depth of zero.
name|uint32_t
name|Depth
decl_stmt|;
specifier|const
name|DWARFAbbreviationDeclaration
modifier|*
name|AbbrevDecl
decl_stmt|;
name|public
label|:
name|DWARFDebugInfoEntry
argument_list|()
operator|:
name|Offset
argument_list|(
literal|0
argument_list|)
operator|,
name|Depth
argument_list|(
literal|0
argument_list|)
operator|,
name|AbbrevDecl
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Extracts a debug info entry, which is a child of a given unit,
comment|/// starting at a given offset. If DIE can't be extracted, returns false and
comment|/// doesn't change OffsetPtr.
name|bool
name|extractFast
argument_list|(
specifier|const
name|DWARFUnit
operator|&
name|U
argument_list|,
name|uint32_t
operator|*
name|OffsetPtr
argument_list|)
expr_stmt|;
comment|/// High performance extraction should use this call.
name|bool
name|extractFast
parameter_list|(
specifier|const
name|DWARFUnit
modifier|&
name|U
parameter_list|,
name|uint32_t
modifier|*
name|OffsetPtr
parameter_list|,
specifier|const
name|DataExtractor
modifier|&
name|DebugInfoData
parameter_list|,
name|uint32_t
name|UEndOffset
parameter_list|,
name|uint32_t
name|Depth
parameter_list|)
function_decl|;
name|uint32_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|uint32_t
name|getDepth
argument_list|()
specifier|const
block|{
return|return
name|Depth
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
name|AbbrevDecl
operator|?
name|AbbrevDecl
operator|->
name|getTag
argument_list|()
operator|:
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
return|return
name|AbbrevDecl
operator|&&
name|AbbrevDecl
operator|->
name|hasChildren
argument_list|()
return|;
block|}
specifier|const
name|DWARFAbbreviationDeclaration
operator|*
name|getAbbreviationDeclarationPtr
argument_list|()
specifier|const
block|{
return|return
name|AbbrevDecl
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

