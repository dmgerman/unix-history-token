begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangExpressionVariable.h -------------------------------*- C++ -*-===//
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
name|liblldb_ClangExpressionVariable_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangExpressionVariable_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
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
file|"llvm/Support/Casting.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TaggedASTType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ValueObjectConstResult
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ClangExpressionVariable ClangExpressionVariable.h
comment|/// "lldb/Expression/ClangExpressionVariable.h"
comment|/// @brief Encapsulates one variable for the expression parser.
comment|///
comment|/// The expression parser uses variables in three different contexts:
comment|///
comment|/// First, it stores persistent variables along with the process for use
comment|/// in expressions.  These persistent variables contain their own data
comment|/// and are typed.
comment|///
comment|/// Second, in an interpreted expression, it stores the local variables
comment|/// for the expression along with the expression.  These variables
comment|/// contain their own data and are typed.
comment|///
comment|/// Third, in a JIT-compiled expression, it stores the variables that
comment|/// the expression needs to have materialized and dematerialized at each
comment|/// execution.  These do not contain their own data but are named and
comment|/// typed.
comment|///
comment|/// This class supports all of these use cases using simple type
comment|/// polymorphism, and provides necessary support methods.  Its interface
comment|/// is RTTI-neutral.
comment|//----------------------------------------------------------------------
name|class
name|ClangExpressionVariable
range|:
name|public
name|ExpressionVariable
block|{
name|public
operator|:
name|ClangExpressionVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|;
name|ClangExpressionVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|Value&value
argument_list|,
argument|const ConstString&name
argument_list|,
argument|uint16_t flags = EVNone
argument_list|)
block|;
name|ClangExpressionVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|valobj_sp
argument_list|)
block|;
name|ClangExpressionVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const TypeFromUser&user_type
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Utility functions for dealing with ExpressionVariableLists in
comment|/// Clang-specific ways
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// Finds a variable by NamedDecl in the list.
comment|///
comment|/// @param[in] name
comment|///     The name of the requested variable.
comment|///
comment|/// @return
comment|///     The variable requested, or NULL if that variable is not in the list.
comment|//----------------------------------------------------------------------
specifier|static
name|ClangExpressionVariable
operator|*
name|FindVariableInList
argument_list|(
argument|ExpressionVariableList&list
argument_list|,
argument|const clang::NamedDecl *decl
argument_list|,
argument|uint64_t parser_id
argument_list|)
block|{
name|lldb
operator|::
name|ExpressionVariableSP
name|var_sp
block|;
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|,
name|size
init|=
name|list
operator|.
name|GetSize
argument_list|()
init|;
name|index
operator|<
name|size
condition|;
operator|++
name|index
control|)
block|{
name|var_sp
operator|=
name|list
operator|.
name|GetVariableAtIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|ClangExpressionVariable
modifier|*
name|clang_var
init|=
name|llvm
operator|::
name|dyn_cast
operator|<
name|ClangExpressionVariable
operator|>
operator|(
name|var_sp
operator|.
name|get
argument_list|()
operator|)
condition|)
block|{
name|ClangExpressionVariable
operator|::
name|ParserVars
operator|*
name|parser_vars
operator|=
name|clang_var
operator|->
name|GetParserVars
argument_list|(
name|parser_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|parser_vars
operator|&&
name|parser_vars
operator|->
name|m_named_decl
operator|==
name|decl
condition|)
return|return
name|clang_var
return|;
block|}
block|}
return|return
name|nullptr
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// If the variable contains its own data, make a Value point at it.
comment|/// If \a exe_ctx in not NULL, the value will be resolved in with
comment|/// that execution context.
comment|///
comment|/// @param[in] value
comment|///     The value to point at the data.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use to resolve \a value.
comment|///
comment|/// @return
comment|///     True on success; false otherwise (in particular, if this variable
comment|///     does not contain its own data).
comment|//----------------------------------------------------------------------
name|bool
name|PointValueAtData
argument_list|(
name|Value
operator|&
name|value
argument_list|,
name|ExecutionContext
operator|*
name|exe_ctx
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// The following values should not live beyond parsing
comment|//----------------------------------------------------------------------
name|class
name|ParserVars
block|{
name|public
operator|:
name|ParserVars
argument_list|()
operator|:
name|m_parser_type
argument_list|()
block|,
name|m_named_decl
argument_list|(
name|NULL
argument_list|)
block|,
name|m_llvm_value
argument_list|(
name|NULL
argument_list|)
block|,
name|m_lldb_value
argument_list|()
block|,
name|m_lldb_var
argument_list|()
block|,
name|m_lldb_sym
argument_list|(
argument|NULL
argument_list|)
block|{}
name|TypeFromParser
name|m_parser_type
block|;
comment|///< The type of the variable according to the parser
specifier|const
name|clang
operator|::
name|NamedDecl
operator|*
name|m_named_decl
block|;
comment|///< The Decl corresponding to this variable
name|llvm
operator|::
name|Value
operator|*
name|m_llvm_value
block|;
comment|///< The IR value corresponding to this variable;
comment|///usually a GlobalValue
name|lldb_private
operator|::
name|Value
name|m_lldb_value
block|;
comment|///< The value found in LLDB for this variable
name|lldb
operator|::
name|VariableSP
name|m_lldb_var
block|;
comment|///< The original variable for this variable
specifier|const
name|lldb_private
operator|::
name|Symbol
operator|*
name|m_lldb_sym
block|;
comment|///< The original symbol for this
comment|///variable, if it was a symbol
block|}
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|ParserVars
operator|>
name|ParserVarMap
expr_stmt|;
name|ParserVarMap
name|m_parser_vars
decl_stmt|;
name|public
label|:
comment|//----------------------------------------------------------------------
comment|/// Make this variable usable by the parser by allocating space for
comment|/// parser-specific variables
comment|//----------------------------------------------------------------------
name|void
name|EnableParserVars
parameter_list|(
name|uint64_t
name|parser_id
parameter_list|)
block|{
name|m_parser_vars
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|parser_id
argument_list|,
name|ParserVars
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Deallocate parser-specific variables
comment|//----------------------------------------------------------------------
name|void
name|DisableParserVars
parameter_list|(
name|uint64_t
name|parser_id
parameter_list|)
block|{
name|m_parser_vars
operator|.
name|erase
argument_list|(
name|parser_id
argument_list|)
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Access parser-specific variables
comment|//----------------------------------------------------------------------
name|ParserVars
modifier|*
name|GetParserVars
parameter_list|(
name|uint64_t
name|parser_id
parameter_list|)
block|{
name|ParserVarMap
operator|::
name|iterator
name|i
operator|=
name|m_parser_vars
operator|.
name|find
argument_list|(
name|parser_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|m_parser_vars
operator|.
name|end
argument_list|()
condition|)
return|return
name|NULL
return|;
else|else
return|return
operator|&
name|i
operator|->
name|second
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// The following values are valid if the variable is used by JIT code
comment|//----------------------------------------------------------------------
struct|struct
name|JITVars
block|{
name|JITVars
argument_list|()
operator|:
name|m_alignment
argument_list|(
literal|0
argument_list|)
operator|,
name|m_size
argument_list|(
literal|0
argument_list|)
operator|,
name|m_offset
argument_list|(
literal|0
argument_list|)
block|{}
name|lldb
operator|::
name|offset_t
name|m_alignment
expr_stmt|;
comment|///< The required alignment of the variable, in bytes
name|size_t
name|m_size
decl_stmt|;
comment|///< The space required for the variable, in bytes
name|lldb
operator|::
name|offset_t
name|m_offset
expr_stmt|;
comment|///< The offset of the variable in the struct, in bytes
block|}
struct|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|JITVars
operator|>
name|JITVarMap
expr_stmt|;
name|JITVarMap
name|m_jit_vars
decl_stmt|;
name|public
label|:
comment|//----------------------------------------------------------------------
comment|/// Make this variable usable for materializing for the JIT by allocating
comment|/// space for JIT-specific variables
comment|//----------------------------------------------------------------------
name|void
name|EnableJITVars
parameter_list|(
name|uint64_t
name|parser_id
parameter_list|)
block|{
name|m_jit_vars
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|parser_id
argument_list|,
name|JITVars
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Deallocate JIT-specific variables
comment|//----------------------------------------------------------------------
name|void
name|DisableJITVars
parameter_list|(
name|uint64_t
name|parser_id
parameter_list|)
block|{
name|m_jit_vars
operator|.
name|erase
argument_list|(
name|parser_id
argument_list|)
expr_stmt|;
block|}
name|JITVars
modifier|*
name|GetJITVars
parameter_list|(
name|uint64_t
name|parser_id
parameter_list|)
block|{
name|JITVarMap
operator|::
name|iterator
name|i
operator|=
name|m_jit_vars
operator|.
name|find
argument_list|(
name|parser_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|m_jit_vars
operator|.
name|end
argument_list|()
condition|)
return|return
name|NULL
return|;
else|else
return|return
operator|&
name|i
operator|->
name|second
return|;
block|}
name|TypeFromUser
name|GetTypeFromUser
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// llvm casting support
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ExpressionVariable
modifier|*
name|ev
parameter_list|)
block|{
return|return
name|ev
operator|->
name|getKind
argument_list|()
operator|==
name|ExpressionVariable
operator|::
name|eKindClang
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Members
comment|//----------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ClangExpressionVariable
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ClangExpressionVariable_h_
end_comment

end_unit

