begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CPlusPlusLanguage.h -------------------------------------*- C++ -*-===//
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
name|liblldb_CPlusPlusLanguage_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CPlusPlusLanguage_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/Language.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CPlusPlusLanguage
range|:
name|public
name|Language
block|{
name|public
operator|:
name|class
name|MethodName
block|{
name|public
operator|:
name|MethodName
argument_list|()
operator|:
name|m_full
argument_list|()
block|,
name|m_basename
argument_list|()
block|,
name|m_context
argument_list|()
block|,
name|m_arguments
argument_list|()
block|,
name|m_qualifiers
argument_list|()
block|,
name|m_parsed
argument_list|(
name|false
argument_list|)
block|,
name|m_parse_error
argument_list|(
argument|false
argument_list|)
block|{}
name|MethodName
argument_list|(
specifier|const
name|ConstString
operator|&
name|s
argument_list|)
operator|:
name|m_full
argument_list|(
name|s
argument_list|)
block|,
name|m_basename
argument_list|()
block|,
name|m_context
argument_list|()
block|,
name|m_arguments
argument_list|()
block|,
name|m_qualifiers
argument_list|()
block|,
name|m_parsed
argument_list|(
name|false
argument_list|)
block|,
name|m_parse_error
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|Clear
argument_list|()
block|;
name|bool
name|IsValid
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_parsed
condition|)
name|Parse
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_parse_error
condition|)
return|return
name|false
return|;
return|return
operator|(
name|bool
operator|)
name|m_full
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetFullName
argument_list|()
specifier|const
block|{
return|return
name|m_full
return|;
block|}
name|std
operator|::
name|string
name|GetScopeQualifiedName
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetBasename
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetContext
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetArguments
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetQualifiers
argument_list|()
expr_stmt|;
name|protected
label|:
name|void
name|Parse
parameter_list|()
function_decl|;
name|bool
name|TrySimplifiedParse
parameter_list|()
function_decl|;
name|ConstString
name|m_full
decl_stmt|;
comment|// Full name:
comment|// "lldb::SBTarget::GetBreakpointAtIndex(unsigned int)
comment|// const"
name|llvm
operator|::
name|StringRef
name|m_basename
expr_stmt|;
comment|// Basename:     "GetBreakpointAtIndex"
name|llvm
operator|::
name|StringRef
name|m_context
expr_stmt|;
comment|// Decl context: "lldb::SBTarget"
name|llvm
operator|::
name|StringRef
name|m_arguments
expr_stmt|;
comment|// Arguments:    "(unsigned int)"
name|llvm
operator|::
name|StringRef
name|m_qualifiers
expr_stmt|;
comment|// Qualifiers:   "const"
name|bool
name|m_parsed
decl_stmt|;
name|bool
name|m_parse_error
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|CPlusPlusLanguage
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|CPlusPlusLanguage
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|LanguageType
name|GetLanguageType
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eLanguageTypeC_plus_plus
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|TypeScavenger
operator|>
name|GetTypeScavenger
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|TypeCategoryImplSP
name|GetFormatters
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HardcodedFormatters
operator|::
name|HardcodedSummaryFinder
name|GetHardcodedSummaries
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HardcodedFormatters
operator|::
name|HardcodedSyntheticFinder
name|GetHardcodedSynthetics
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Static Functions
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|void
name|Initialize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|Terminate
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|Language
operator|*
name|CreateInstance
argument_list|(
argument|lldb::LanguageType language
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|bool
name|IsCPPMangledName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Extract C++ context and identifier from a string using heuristic matching
end_comment

begin_comment
comment|// (as opposed to
end_comment

begin_comment
comment|// CPlusPlusLanguage::MethodName which has to have a fully qualified C++ name
end_comment

begin_comment
comment|// with parens and arguments.
end_comment

begin_comment
comment|// If the name is a lone C identifier (e.g. C) or a qualified C identifier
end_comment

begin_comment
comment|// (e.g. A::B::C) it will return true,
end_comment

begin_comment
comment|// and identifier will be the identifier (C and C respectively) and the
end_comment

begin_comment
comment|// context will be "" and "A::B" respectively.
end_comment

begin_comment
comment|// If the name fails the heuristic matching for a qualified or unqualified
end_comment

begin_comment
comment|// C/C++ identifier, then it will return false
end_comment

begin_comment
comment|// and identifier and context will be unchanged.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|ExtractContextAndIdentifier
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|llvm
operator|::
name|StringRef
operator|&
name|context
argument_list|,
name|llvm
operator|::
name|StringRef
operator|&
name|identifier
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Given a mangled function name, calculates some alternative manglings since
end_comment

begin_comment
comment|// the compiler mangling may not line up with the symbol we are expecting
end_comment

begin_decl_stmt
specifier|static
name|uint32_t
name|FindAlternateFunctionManglings
argument_list|(
specifier|const
name|ConstString
name|mangled
argument_list|,
name|std
operator|::
name|set
operator|<
name|ConstString
operator|>
operator|&
name|candidates
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// PluginInterface protocol
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|ConstString
name|GetPluginName
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CPlusPlusLanguage_h_
end_comment

end_unit

