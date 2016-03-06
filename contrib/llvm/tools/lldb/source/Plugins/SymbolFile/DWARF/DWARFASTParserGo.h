begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFASTParserGo.h --------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFASTParserGo_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFASTParserGo_h_
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

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/GoASTContext.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_include
include|#
directive|include
file|"DWARFASTParser.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDIE.h"
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
name|DWARFASTParserGo
range|:
name|public
name|DWARFASTParser
block|{
name|public
operator|:
name|DWARFASTParserGo
argument_list|(
name|lldb_private
operator|::
name|GoASTContext
operator|&
name|ast
argument_list|)
block|;
operator|~
name|DWARFASTParserGo
argument_list|()
name|override
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
argument|lldb_private::CompilerType&go_type
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextForUIDFromDWARF
argument_list|(
argument|const DWARFDIE&die
argument_list|)
name|override
block|{
return|return
name|lldb_private
operator|::
name|CompilerDeclContext
argument_list|()
return|;
block|}
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextContainingUIDFromDWARF
argument_list|(
argument|const DWARFDIE&die
argument_list|)
name|override
block|{
return|return
name|lldb_private
operator|::
name|CompilerDeclContext
argument_list|()
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
name|std
operator|::
name|vector
operator|<
name|DWARFDIE
operator|>
operator|(
operator|)
return|;
block|}
name|private
operator|:
name|size_t
name|ParseChildParameters
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|parent_die
argument_list|,
name|bool
operator|&
name|is_variadic
argument_list|,
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|CompilerType
operator|>
operator|&
name|function_param_types
argument_list|)
block|;
name|void
name|ParseChildArrayInfo
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|parent_die
argument_list|,
name|int64_t
operator|&
name|first_index
argument_list|,
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
operator|&
name|element_orders
argument_list|,
name|uint32_t
operator|&
name|byte_stride
argument_list|,
name|uint32_t
operator|&
name|bit_stride
argument_list|)
block|;
name|size_t
name|ParseChildMembers
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|,
name|lldb_private
operator|::
name|CompilerType
operator|&
name|class_compiler_type
argument_list|)
block|;
name|lldb_private
operator|::
name|GoASTContext
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
comment|// SymbolFileDWARF_DWARFASTParserGo_h_
end_comment

end_unit

