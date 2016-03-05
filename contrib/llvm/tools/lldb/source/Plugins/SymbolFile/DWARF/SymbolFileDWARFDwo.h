begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolFileDWARFDwo.h ------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARFDwo_SymbolFileDWARFDwo_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARFDwo_SymbolFileDWARFDwo_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_decl_stmt
name|class
name|SymbolFileDWARFDwo
range|:
name|public
name|SymbolFileDWARF
block|{
name|public
operator|:
name|SymbolFileDWARFDwo
argument_list|(
argument|lldb::ObjectFileSP objfile
argument_list|,
argument|DWARFCompileUnit* dwarf_cu
argument_list|)
block|;
operator|~
name|SymbolFileDWARFDwo
argument_list|()
name|override
operator|=
expr|default
block|;
name|lldb
operator|::
name|CompUnitSP
name|ParseCompileUnit
argument_list|(
argument|DWARFCompileUnit* dwarf_cu
argument_list|,
argument|uint32_t cu_idx
argument_list|)
name|override
block|;
name|DWARFCompileUnit
operator|*
name|GetCompileUnit
argument_list|()
block|;
name|DWARFCompileUnit
operator|*
name|GetDWARFCompileUnit
argument_list|(
argument|lldb_private::CompileUnit *comp_unit
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|DWARFExpression
operator|::
name|LocationListFormat
name|GetLocationListFormat
argument_list|()
specifier|const
name|override
block|;
name|lldb_private
operator|::
name|TypeSystem
operator|*
name|GetTypeSystemForLanguage
argument_list|(
argument|lldb::LanguageType language
argument_list|)
name|override
block|;
name|protected
operator|:
name|void
name|LoadSectionData
argument_list|(
argument|lldb::SectionType sect_type
argument_list|,
argument|lldb_private::DWARFDataExtractor& data
argument_list|)
name|override
block|;
name|DIEToTypePtr
operator|&
name|GetDIEToType
argument_list|()
name|override
block|;
name|DIEToVariableSP
operator|&
name|GetDIEToVariable
argument_list|()
name|override
block|;
name|DIEToClangType
operator|&
name|GetForwardDeclDieToClangType
argument_list|()
name|override
block|;
name|ClangTypeToDIE
operator|&
name|GetForwardDeclClangTypeToDie
argument_list|()
name|override
block|;
name|UniqueDWARFASTTypeMap
operator|&
name|GetUniqueDWARFASTTypeMap
argument_list|()
name|override
block|;
name|lldb
operator|::
name|TypeSP
name|FindDefinitionTypeForDWARFDeclContext
argument_list|(
argument|const DWARFDeclContext&die_decl_ctx
argument_list|)
name|override
block|;
name|SymbolFileDWARF
operator|*
name|GetBaseSymbolFile
argument_list|()
block|;
name|lldb
operator|::
name|ObjectFileSP
name|m_obj_file_sp
block|;
name|DWARFCompileUnit
operator|*
name|m_base_dwarf_cu
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARFDwo_SymbolFileDWARFDwo_h_
end_comment

end_unit

