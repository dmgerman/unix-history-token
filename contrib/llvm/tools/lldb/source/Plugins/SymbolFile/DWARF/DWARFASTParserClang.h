begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFASTParserClang.h -----------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFASTParserClang_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFASTParserClang_h_
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
file|"clang/AST/CharUnits.h"
end_include

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
file|"DWARFASTParser.h"
end_include

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTImporter.h"
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
name|DWARFASTParserClang
range|:
name|public
name|DWARFASTParser
block|{
name|public
operator|:
name|DWARFASTParserClang
argument_list|(
name|lldb_private
operator|::
name|ClangASTContext
operator|&
name|ast
argument_list|)
block|;
operator|~
name|DWARFASTParserClang
argument_list|()
name|override
block|;
comment|// DWARFASTParser interface.
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
block|;
name|lldb_private
operator|::
name|CompilerDecl
name|GetDeclForUIDFromDWARF
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
block|;
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
name|lldb_private
operator|::
name|ClangASTImporter
operator|&
name|GetClangASTImporter
argument_list|()
block|;
name|protected
operator|:
name|class
name|DelayedAddObjCClassProperty
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DelayedAddObjCClassProperty
operator|>
name|DelayedPropertyList
expr_stmt|;
name|clang
operator|::
name|DeclContext
operator|*
name|GetDeclContextForBlock
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|clang
operator|::
name|BlockDecl
operator|*
name|ResolveBlockDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clang
operator|::
name|NamespaceDecl
operator|*
name|ResolveNamespaceDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|ParseTemplateDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|,
name|lldb_private
operator|::
name|ClangASTContext
operator|::
name|TemplateParameterInfos
operator|&
name|template_param_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ParseTemplateParameterInfos
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|parent_die
argument_list|,
name|lldb_private
operator|::
name|ClangASTContext
operator|::
name|TemplateParameterInfos
operator|&
name|template_param_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
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
argument_list|,
specifier|const
name|lldb
operator|::
name|LanguageType
name|class_language
argument_list|,
name|std
operator|::
name|vector
operator|<
name|clang
operator|::
name|CXXBaseSpecifier
operator|*
operator|>
operator|&
name|base_classes
argument_list|,
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|&
name|member_accessibilities
argument_list|,
name|DWARFDIECollection
operator|&
name|member_function_dies
argument_list|,
name|DelayedPropertyList
operator|&
name|delayed_properties
argument_list|,
name|lldb
operator|::
name|AccessType
operator|&
name|default_accessibility
argument_list|,
name|bool
operator|&
name|is_a_class
argument_list|,
name|lldb_private
operator|::
name|ClangASTImporter
operator|::
name|LayoutInfo
operator|&
name|layout_info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|clang
operator|::
name|DeclContext
operator|*
name|containing_decl_ctx
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|parent_die
argument_list|,
name|bool
name|skip_artificial
argument_list|,
name|bool
operator|&
name|is_static
argument_list|,
name|bool
operator|&
name|is_variadic
argument_list|,
name|bool
operator|&
name|has_template_params
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
name|function_args
argument_list|,
name|std
operator|::
name|vector
operator|<
name|clang
operator|::
name|ParmVarDecl
operator|*
operator|>
operator|&
name|function_param_decls
argument_list|,
name|unsigned
operator|&
name|type_quals
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|ParseChildEnumerators
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
name|lldb_private
operator|::
name|CompilerType
operator|&
name|compiler_type
argument_list|,
name|bool
name|is_signed
argument_list|,
name|uint32_t
name|enumerator_byte_size
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|parent_die
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Type
operator|*
name|GetTypeForDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clang
operator|::
name|Decl
operator|*
name|GetClangDeclForDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clang
operator|::
name|DeclContext
operator|*
name|GetClangDeclContextForDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clang
operator|::
name|DeclContext
operator|*
name|GetClangDeclContextContainingDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|,
name|DWARFDIE
operator|*
name|decl_ctx_die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|CopyUniqueClassMethodTypes
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|src_class_die
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|dst_class_die
argument_list|,
name|lldb_private
operator|::
name|Type
operator|*
name|class_type
argument_list|,
name|DWARFDIECollection
operator|&
name|failures
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|clang
operator|::
name|DeclContext
operator|*
name|GetCachedClangDeclContextForDIE
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|LinkDeclContextToDIE
argument_list|(
name|clang
operator|::
name|DeclContext
operator|*
name|decl_ctx
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|LinkDeclToDIE
argument_list|(
name|clang
operator|::
name|Decl
operator|*
name|decl
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeSP
name|ParseTypeFromDWO
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|,
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Return true if this type is a declaration to a type in an external
end_comment

begin_comment
comment|// module.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|GetModuleForType
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|DWARFDebugInfoEntry
operator|*
operator|,
literal|4
operator|>
name|DIEPointerSet
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DWARFDebugInfoEntry
operator|*
operator|,
name|clang
operator|::
name|DeclContext
operator|*
operator|>
name|DIEToDeclContextMap
expr_stmt|;
end_typedef

begin_comment
comment|// typedef llvm::DenseMap<const clang::DeclContext *, DIEPointerSet>
end_comment

begin_comment
comment|// DeclContextToDIEMap;
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|multimap
operator|<
specifier|const
name|clang
operator|::
name|DeclContext
operator|*
operator|,
specifier|const
name|DWARFDIE
operator|>
name|DeclContextToDIEMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DWARFDebugInfoEntry
operator|*
operator|,
name|clang
operator|::
name|Decl
operator|*
operator|>
name|DIEToDeclMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|clang
operator|::
name|Decl
operator|*
operator|,
name|DIEPointerSet
operator|>
name|DeclToDIEMap
expr_stmt|;
end_typedef

begin_expr_stmt
name|lldb_private
operator|::
name|ClangASTContext
operator|&
name|m_ast
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|DIEToDeclMap
name|m_die_to_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeclToDIEMap
name|m_decl_to_die
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DIEToDeclContextMap
name|m_die_to_decl_ctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeclContextToDIEMap
name|m_decl_ctx_to_die
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|ClangASTImporter
operator|>
name|m_clang_ast_importer_ap
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFASTParserClang_h_
end_comment

end_unit

