begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFASTParserOCaml.h -----------------------------------*- C++ -*-===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SymbolFileDWARF_DWARFASTParserOCaml_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFASTParserOCaml_h_
end_define

begin_include
include|#
directive|include
file|"DWARFASTParser.h"
end_include

begin_include
include|#
directive|include
file|"DWARFCompileUnit.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDIE.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/OCamlASTContext.h"
end_include

begin_decl_stmt
name|class
name|DWARFDebugInfoEntry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFDIECollection
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFASTParserOCaml
range|:
name|public
name|DWARFASTParser
block|{
name|public
operator|:
name|DWARFASTParserOCaml
argument_list|(
name|lldb_private
operator|::
name|OCamlASTContext
operator|&
name|ast
argument_list|)
block|;
name|virtual
operator|~
name|DWARFASTParserOCaml
argument_list|()
block|;
name|lldb
operator|::
name|TypeSP
name|ParseBaseTypeFromDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
block|;
name|lldb
operator|::
name|TypeSP
name|ParseTypeFromDWARF
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|const DWARFDIE&die
argument_list|,
argument|lldb_private::Log *log
argument_list|,
argument|bool *type_is_new_ptr
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Function
operator|*
name|ParseFunctionFromDWARF
argument_list|(
argument|const lldb_private::SymbolContext&sc
argument_list|,
argument|const DWARFDIE&die
argument_list|)
name|override
block|;
name|bool
name|CompleteTypeFromDWARF
argument_list|(
argument|const DWARFDIE&die
argument_list|,
argument|lldb_private::Type *type
argument_list|,
argument|lldb_private::CompilerType&compiler_type
argument_list|)
name|override
block|{
return|return
name|false
return|;
block|}
name|lldb_private
operator|::
name|CompilerDecl
name|GetDeclForUIDFromDWARF
argument_list|(
argument|const DWARFDIE&die
argument_list|)
name|override
block|{
return|return
name|lldb_private
operator|::
name|CompilerDecl
argument_list|()
return|;
block|}
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextForUIDFromDWARF
argument_list|(
argument|const DWARFDIE&die
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextContainingUIDFromDWARF
argument_list|(
argument|const DWARFDIE&die
argument_list|)
name|override
block|;
name|std
operator|::
name|vector
operator|<
name|DWARFDIE
operator|>
name|GetDIEForDeclContext
argument_list|(
argument|lldb_private::CompilerDeclContext decl_context
argument_list|)
name|override
block|{
return|return
block|{}
return|;
block|}
name|protected
operator|:
name|lldb_private
operator|::
name|OCamlASTContext
operator|&
name|m_ast
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFASTParserOCaml_h_
end_comment

end_unit

