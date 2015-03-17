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

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TaggedASTType.h"
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
name|ClangExpressionVariableList
decl_stmt|;
name|class
name|ValueObjectConstResult
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ClangExpressionVariable ClangExpressionVariable.h "lldb/Expression/ClangExpressionVariable.h"
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
block|{
name|public
label|:
name|ClangExpressionVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
empty_stmt|;
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
empty_stmt|;
name|ClangExpressionVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|valobj_sp
argument_list|)
expr_stmt|;
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
parameter_list|(
name|Value
modifier|&
name|value
parameter_list|,
name|ExecutionContext
modifier|*
name|exe_ctx
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ValueObjectSP
name|GetValueObject
argument_list|()
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// The following values should not live beyond parsing
comment|//----------------------------------------------------------------------
name|class
name|ParserVars
block|{
name|public
label|:
name|ParserVars
argument_list|()
operator|:
name|m_parser_type
argument_list|()
operator|,
name|m_named_decl
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_llvm_value
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_lldb_value
argument_list|()
operator|,
name|m_lldb_var
argument_list|()
operator|,
name|m_lldb_sym
argument_list|(
argument|NULL
argument_list|)
block|{         }
name|TypeFromParser
name|m_parser_type
expr_stmt|;
comment|///< The type of the variable according to the parser
specifier|const
name|clang
operator|::
name|NamedDecl
operator|*
name|m_named_decl
expr_stmt|;
comment|///< The Decl corresponding to this variable
name|llvm
operator|::
name|Value
operator|*
name|m_llvm_value
expr_stmt|;
comment|///< The IR value corresponding to this variable; usually a GlobalValue
name|lldb_private
operator|::
name|Value
name|m_lldb_value
expr_stmt|;
comment|///< The value found in LLDB for this variable
name|lldb
operator|::
name|VariableSP
name|m_lldb_var
expr_stmt|;
comment|///< The original variable for this variable
specifier|const
name|lldb_private
operator|::
name|Symbol
operator|*
name|m_lldb_sym
expr_stmt|;
comment|///< The original symbol for this variable, if it was a symbol
block|}
empty_stmt|;
name|private
label|:
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
block|{         }
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
comment|//----------------------------------------------------------------------
comment|/// Return the variable's size in bytes
comment|//----------------------------------------------------------------------
name|size_t
name|GetByteSize
parameter_list|()
function_decl|;
specifier|const
name|ConstString
modifier|&
name|GetName
parameter_list|()
function_decl|;
name|RegisterInfo
modifier|*
name|GetRegisterInfo
parameter_list|()
function_decl|;
name|void
name|SetRegisterInfo
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|)
function_decl|;
name|ClangASTType
name|GetClangType
parameter_list|()
function_decl|;
name|void
name|SetClangType
parameter_list|(
specifier|const
name|ClangASTType
modifier|&
name|clang_type
parameter_list|)
function_decl|;
name|TypeFromUser
name|GetTypeFromUser
parameter_list|()
function_decl|;
name|uint8_t
modifier|*
name|GetValueBytes
parameter_list|()
function_decl|;
name|void
name|SetName
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|ValueUpdated
parameter_list|()
function_decl|;
comment|// this function is used to copy the address-of m_live_sp into m_frozen_sp
comment|// this is necessary because the results of certain cast and pointer-arithmetic
comment|// operations (such as those described in bugzilla issues 11588 and 11618) generate
comment|// frozen objects that do not have a valid address-of, which can be troublesome when
comment|// using synthetic children providers. Transferring the address-of the live object
comment|// solves these issues and provides the expected user-level behavior
name|void
name|TransferAddress
parameter_list|(
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ValueObjectConstResult
operator|>
name|ValueObjectConstResultSP
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Members
comment|//----------------------------------------------------------------------
enum|enum
name|Flags
block|{
name|EVNone
init|=
literal|0
block|,
name|EVIsLLDBAllocated
init|=
literal|1
operator|<<
literal|0
block|,
comment|///< This variable is resident in a location specifically allocated for it by LLDB in the target process
name|EVIsProgramReference
init|=
literal|1
operator|<<
literal|1
block|,
comment|///< This variable is a reference to a (possibly invalid) area managed by the target program
name|EVNeedsAllocation
init|=
literal|1
operator|<<
literal|2
block|,
comment|///< Space for this variable has yet to be allocated in the target process
name|EVIsFreezeDried
init|=
literal|1
operator|<<
literal|3
block|,
comment|///< This variable's authoritative version is in m_frozen_sp (for example, for statically-computed results)
name|EVNeedsFreezeDry
init|=
literal|1
operator|<<
literal|4
block|,
comment|///< Copy from m_live_sp to m_frozen_sp during dematerialization
name|EVKeepInTarget
init|=
literal|1
operator|<<
literal|5
block|,
comment|///< Keep the allocation after the expression is complete rather than freeze drying its contents and freeing it
name|EVTypeIsReference
init|=
literal|1
operator|<<
literal|6
block|,
comment|///< The original type of this variable is a reference, so materialize the value rather than the location
name|EVUnknownType
init|=
literal|1
operator|<<
literal|7
block|,
comment|///< This is a symbol of unknown type, and the type must be resolved after parsing is complete
name|EVBareRegister
init|=
literal|1
operator|<<
literal|8
comment|///< This variable is a direct reference to $pc or some other entity.
block|}
enum|;
typedef|typedef
name|uint16_t
name|FlagType
typedef|;
name|FlagType
name|m_flags
decl_stmt|;
comment|// takes elements of Flags
name|lldb
operator|::
name|ValueObjectSP
name|m_frozen_sp
expr_stmt|;
name|lldb
operator|::
name|ValueObjectSP
name|m_live_sp
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ClangExpressionVariable
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ClangExpressionVariableListBase ClangExpressionVariable.h "lldb/Expression/ClangExpressionVariable.h"
comment|/// @brief A list of variable references.
comment|///
comment|/// This class stores variables internally, acting as the permanent store.
comment|//----------------------------------------------------------------------
name|class
name|ClangExpressionVariableList
block|{
name|public
label|:
comment|//----------------------------------------------------------------------
comment|/// Implementation of methods in ClangExpressionVariableListBase
comment|//----------------------------------------------------------------------
name|size_t
name|GetSize
parameter_list|()
block|{
return|return
name|m_variables
operator|.
name|size
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ClangExpressionVariableSP
name|GetVariableAtIndex
argument_list|(
argument|size_t index
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
name|var_sp
block|;
if|if
condition|(
name|index
operator|<
name|m_variables
operator|.
name|size
argument_list|()
condition|)
name|var_sp
operator|=
name|m_variables
index|[
name|index
index|]
expr_stmt|;
return|return
name|var_sp
return|;
block|}
name|size_t
name|AddVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ClangExpressionVariableSP
operator|&
name|var_sp
argument_list|)
block|{
name|m_variables
operator|.
name|push_back
argument_list|(
name|var_sp
argument_list|)
expr_stmt|;
return|return
name|m_variables
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
name|bool
name|ContainsVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ClangExpressionVariableSP
operator|&
name|var_sp
argument_list|)
block|{
specifier|const
name|size_t
name|size
init|=
name|m_variables
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|;
name|index
operator|<
name|size
condition|;
operator|++
name|index
control|)
block|{
if|if
condition|(
name|m_variables
index|[
name|index
index|]
operator|.
name|get
argument_list|()
operator|==
name|var_sp
operator|.
name|get
argument_list|()
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Finds a variable by name in the list.
comment|///
comment|/// @param[in] name
comment|///     The name of the requested variable.
comment|///
comment|/// @return
comment|///     The variable requested, or NULL if that variable is not in the list.
comment|//----------------------------------------------------------------------
name|lldb
operator|::
name|ClangExpressionVariableSP
name|GetVariable
argument_list|(
argument|const ConstString&name
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
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
name|GetVariableAtIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|var_sp
operator|->
name|GetName
argument_list|()
operator|==
name|name
condition|)
return|return
name|var_sp
return|;
block|}
name|var_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
return|return
name|var_sp
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ClangExpressionVariableSP
name|GetVariable
argument_list|(
argument|const char *name
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
name|var_sp
block|;
if|if
condition|(
name|name
operator|&&
name|name
index|[
literal|0
index|]
condition|)
block|{
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|,
name|size
init|=
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
name|GetVariableAtIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|var_name_cstr
init|=
name|var_sp
operator|->
name|GetName
argument_list|()
operator|.
name|GetCString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|var_name_cstr
operator|||
operator|!
name|name
condition|)
continue|continue;
if|if
condition|(
operator|::
name|strcmp
argument_list|(
name|var_name_cstr
argument_list|,
name|name
argument_list|)
operator|==
literal|0
condition|)
return|return
name|var_sp
return|;
block|}
name|var_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}         return
name|var_sp
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// Finds a variable by NamedDecl in the list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name
end_comment

begin_comment
comment|///     The name of the requested variable.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The variable requested, or NULL if that variable is not in the list.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
unit|lldb
operator|::
name|ClangExpressionVariableSP
name|GetVariable
argument_list|(
argument|const clang::NamedDecl *decl
argument_list|,
argument|uint64_t parser_id
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
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
name|GetVariableAtIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|ClangExpressionVariable
operator|::
name|ParserVars
operator|*
name|parser_vars
operator|=
name|var_sp
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
name|var_sp
return|;
block|}
name|var_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|var_sp
return|;
end_return

begin_comment
unit|}
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// Create a new variable in the list and return its index
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
unit|lldb
operator|::
name|ClangExpressionVariableSP
name|CreateVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
name|var_sp
argument_list|(
argument|new ClangExpressionVariable(exe_scope, byte_order, addr_byte_size)
argument_list|)
block|;
name|m_variables
operator|.
name|push_back
argument_list|(
name|var_sp
argument_list|)
block|;
return|return
name|var_sp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ClangExpressionVariableSP
name|CreateVariable
argument_list|(
argument|const lldb::ValueObjectSP&valobj_sp
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
name|var_sp
argument_list|(
argument|new ClangExpressionVariable(valobj_sp)
argument_list|)
block|;
name|m_variables
operator|.
name|push_back
argument_list|(
name|var_sp
argument_list|)
block|;
return|return
name|var_sp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ClangExpressionVariableSP
name|CreateVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const TypeFromUser& user_type
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
block|{
name|lldb
operator|::
name|ClangExpressionVariableSP
name|var_sp
argument_list|(
argument|new ClangExpressionVariable(exe_scope, byte_order, addr_byte_size)
argument_list|)
block|;
name|var_sp
operator|->
name|SetName
argument_list|(
name|name
argument_list|)
block|;
name|var_sp
operator|->
name|SetClangType
argument_list|(
name|user_type
argument_list|)
block|;
name|m_variables
operator|.
name|push_back
argument_list|(
name|var_sp
argument_list|)
block|;
return|return
name|var_sp
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|RemoveVariable
argument_list|(
name|lldb
operator|::
name|ClangExpressionVariableSP
name|var_sp
argument_list|)
block|{
for|for
control|(
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ClangExpressionVariableSP
operator|>
operator|::
name|iterator
name|vi
operator|=
name|m_variables
operator|.
name|begin
argument_list|()
operator|,
name|ve
operator|=
name|m_variables
operator|.
name|end
argument_list|()
init|;
name|vi
operator|!=
name|ve
condition|;
operator|++
name|vi
control|)
block|{
if|if
condition|(
name|vi
operator|->
name|get
argument_list|()
operator|==
name|var_sp
operator|.
name|get
argument_list|()
condition|)
block|{
name|m_variables
operator|.
name|erase
argument_list|(
name|vi
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_decl_stmt

begin_function
name|void
name|Clear
parameter_list|()
block|{
name|m_variables
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ClangExpressionVariableSP
operator|>
name|m_variables
expr_stmt|;
end_expr_stmt

begin_comment
unit|};   }
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

