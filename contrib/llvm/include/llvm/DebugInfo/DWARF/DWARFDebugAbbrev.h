begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugAbbrev.h --------------------------------------*- C++ -*-===//
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
name|LLVM_LIB_DEBUGINFO_DWARFDEBUGABBREV_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_DWARFDEBUGABBREV_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFAbbreviationDeclaration.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
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
name|DWARFAbbreviationDeclarationSet
block|{
name|uint32_t
name|Offset
decl_stmt|;
comment|/// Code of the first abbreviation, if all abbreviations in the set have
comment|/// consecutive codes. UINT32_MAX otherwise.
name|uint32_t
name|FirstAbbrCode
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|DWARFAbbreviationDeclaration
operator|>
name|Decls
expr_stmt|;
name|public
label|:
name|DWARFAbbreviationDeclarationSet
argument_list|()
expr_stmt|;
name|uint32_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
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
specifier|const
name|DWARFAbbreviationDeclaration
modifier|*
name|getAbbreviationDeclaration
argument_list|(
name|uint32_t
name|AbbrCode
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|clear
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|class
name|DWARFDebugAbbrev
block|{
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|DWARFAbbreviationDeclarationSet
operator|>
name|DWARFAbbreviationDeclarationSetMap
expr_stmt|;
name|DWARFAbbreviationDeclarationSetMap
name|AbbrDeclSets
decl_stmt|;
name|mutable
name|DWARFAbbreviationDeclarationSetMap
operator|::
name|const_iterator
name|PrevAbbrOffsetPos
expr_stmt|;
name|public
label|:
name|DWARFDebugAbbrev
argument_list|()
expr_stmt|;
specifier|const
name|DWARFAbbreviationDeclarationSet
modifier|*
name|getAbbreviationDeclarationSet
argument_list|(
name|uint64_t
name|CUAbbrOffset
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|extract
parameter_list|(
name|DataExtractor
name|Data
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|clear
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

