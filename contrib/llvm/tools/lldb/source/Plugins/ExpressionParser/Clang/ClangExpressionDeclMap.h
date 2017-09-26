begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangExpressionDeclMap.h --------------------------------*- C++ -*-===//
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
name|liblldb_ClangExpressionDeclMap_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangExpressionDeclMap_h_
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

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"ClangASTSource.h"
end_include

begin_include
include|#
directive|include
file|"ClangExpressionVariable.h"
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
file|"lldb/Expression/Materializer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TaggedASTType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ClangExpressionDeclMap ClangExpressionDeclMap.h
comment|/// "lldb/Expression/ClangExpressionDeclMap.h"
comment|/// @brief Manages named entities that are defined in LLDB's debug information.
comment|///
comment|/// The Clang parser uses the ClangASTSource as an interface to request named
comment|/// entities from outside an expression.  The ClangASTSource reports back,
comment|/// listing
comment|/// all possible objects corresponding to a particular name.  But it in turn
comment|/// relies on ClangExpressionDeclMap, which performs several important
comment|/// functions.
comment|///
comment|/// First, it records what variables and functions were looked up and what Decls
comment|/// were returned for them.
comment|///
comment|/// Second, it constructs a struct on behalf of IRForTarget, recording which
comment|/// variables should be placed where and relaying this information back so that
comment|/// IRForTarget can generate context-independent code.
comment|///
comment|/// Third, it "materializes" this struct on behalf of the expression command,
comment|/// finding the current values of each variable and placing them into the
comment|/// struct so that it can be passed to the JITted version of the IR.
comment|///
comment|/// Fourth and finally, it "dematerializes" the struct after the JITted code has
comment|/// has executed, placing the new values back where it found the old ones.
comment|//----------------------------------------------------------------------
name|class
name|ClangExpressionDeclMap
range|:
name|public
name|ClangASTSource
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// Initializes class variables.
comment|///
comment|/// @param[in] keep_result_in_memory
comment|///     If true, inhibits the normal deallocation of the memory for
comment|///     the result persistent variable, and instead marks the variable
comment|///     as persisting.
comment|///
comment|/// @param[in] delegate
comment|///     If non-NULL, use this delegate to report result values.  This
comment|///     allows the client ClangUserExpression to report a result.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when parsing.
comment|//------------------------------------------------------------------
name|ClangExpressionDeclMap
argument_list|(
argument|bool keep_result_in_memory
argument_list|,
argument|Materializer::PersistentVariableDelegate *result_delegate
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|ClangExpressionDeclMap
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Enable the state needed for parsing and IR transformation.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when finding types for variables.
comment|///     Also used to find a "scratch" AST context to store result types.
comment|///
comment|/// @param[in] materializer
comment|///     If non-NULL, the materializer to populate with information about
comment|///     the variables to use
comment|///
comment|/// @return
comment|///     True if parsing is possible; false if it is unsafe to continue.
comment|//------------------------------------------------------------------
name|bool
name|WillParse
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|Materializer
operator|*
name|materializer
argument_list|)
block|;
name|void
name|InstallCodeGenerator
argument_list|(
name|clang
operator|::
name|ASTConsumer
operator|*
name|code_gen
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by ClangExpressionParser] For each variable that had an unknown
comment|///     type at the beginning of parsing, determine its final type now.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ResolveUnknownTypes
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Disable the state needed for parsing and IR transformation.
comment|//------------------------------------------------------------------
name|void
name|DidParse
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Add a variable to the list of persistent
comment|///     variables for the process.
comment|///
comment|/// @param[in] decl
comment|///     The Clang declaration for the persistent variable, used for
comment|///     lookup during parsing.
comment|///
comment|/// @param[in] name
comment|///     The name of the persistent variable, usually $something.
comment|///
comment|/// @param[in] type
comment|///     The type of the variable, in the Clang parser's context.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|AddPersistentVariable
argument_list|(
argument|const clang::NamedDecl *decl
argument_list|,
argument|const ConstString&name
argument_list|,
argument|TypeFromParser type
argument_list|,
argument|bool is_result
argument_list|,
argument|bool is_lvalue
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Add a variable to the struct that needs to
comment|///     be materialized each time the expression runs.
comment|///
comment|/// @param[in] decl
comment|///     The Clang declaration for the variable.
comment|///
comment|/// @param[in] name
comment|///     The name of the variable.
comment|///
comment|/// @param[in] value
comment|///     The LLVM IR value for this variable.
comment|///
comment|/// @param[in] size
comment|///     The size of the variable in bytes.
comment|///
comment|/// @param[in] alignment
comment|///     The required alignment of the variable in bytes.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|AddValueToStruct
argument_list|(
argument|const clang::NamedDecl *decl
argument_list|,
argument|const ConstString&name
argument_list|,
argument|llvm::Value *value
argument_list|,
argument|size_t size
argument_list|,
argument|lldb::offset_t alignment
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Finalize the struct, laying out the position
comment|/// of each object in it.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|DoStructLayout
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Get general information about the laid-out
comment|/// struct after DoStructLayout() has been called.
comment|///
comment|/// @param[out] num_elements
comment|///     The number of elements in the struct.
comment|///
comment|/// @param[out] size
comment|///     The size of the struct, in bytes.
comment|///
comment|/// @param[out] alignment
comment|///     The alignment of the struct, in bytes.
comment|///
comment|/// @return
comment|///     True if the information could be retrieved; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetStructInfo
argument_list|(
name|uint32_t
operator|&
name|num_elements
argument_list|,
name|size_t
operator|&
name|size
argument_list|,
name|lldb
operator|::
name|offset_t
operator|&
name|alignment
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Get specific information about one field
comment|/// of the laid-out struct after DoStructLayout() has been called.
comment|///
comment|/// @param[out] decl
comment|///     The parsed Decl for the field, as generated by ClangASTSource
comment|///     on ClangExpressionDeclMap's behalf.  In the case of the result
comment|///     value, this will have the name $__lldb_result even if the
comment|///     result value ends up having the name $1.  This is an
comment|///     implementation detail of IRForTarget.
comment|///
comment|/// @param[out] value
comment|///     The IR value for the field (usually a GlobalVariable).  In
comment|///     the case of the result value, this will have the correct
comment|///     name ($1, for instance).  This is an implementation detail
comment|///     of IRForTarget.
comment|///
comment|/// @param[out] offset
comment|///     The offset of the field from the beginning of the struct.
comment|///     As long as the struct is aligned according to its required
comment|///     alignment, this offset will align the field correctly.
comment|///
comment|/// @param[out] name
comment|///     The name of the field as used in materialization.
comment|///
comment|/// @param[in] index
comment|///     The index of the field about which information is requested.
comment|///
comment|/// @return
comment|///     True if the information could be retrieved; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetStructElement
argument_list|(
argument|const clang::NamedDecl *&decl
argument_list|,
argument|llvm::Value *&value
argument_list|,
argument|lldb::offset_t&offset
argument_list|,
argument|ConstString&name
argument_list|,
argument|uint32_t index
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Get information about a function given its
comment|/// Decl.
comment|///
comment|/// @param[in] decl
comment|///     The parsed Decl for the Function, as generated by ClangASTSource
comment|///     on ClangExpressionDeclMap's behalf.
comment|///
comment|/// @param[out] ptr
comment|///     The absolute address of the function in the target.
comment|///
comment|/// @return
comment|///     True if the information could be retrieved; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetFunctionInfo
argument_list|(
specifier|const
name|clang
operator|::
name|NamedDecl
operator|*
name|decl
argument_list|,
name|uint64_t
operator|&
name|ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRForTarget] Get the address of a symbol given nothing
comment|/// but its name.
comment|///
comment|/// @param[in] target
comment|///     The target to find the symbol in.  If not provided,
comment|///     then the current parsing context's Target.
comment|///
comment|/// @param[in] process
comment|///     The process to use.  For Objective-C symbols, the process's
comment|///     Objective-C language runtime may be queried if the process
comment|///     is non-NULL.
comment|///
comment|/// @param[in] name
comment|///     The name of the symbol.
comment|///
comment|/// @param[in] module
comment|///     The module to limit the search to. This can be NULL
comment|///
comment|/// @return
comment|///     Valid load address for the symbol
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetSymbolAddress
argument_list|(
argument|Target&target
argument_list|,
argument|Process *process
argument_list|,
argument|const ConstString&name
argument_list|,
argument|lldb::SymbolType symbol_type
argument_list|,
argument|Module *module = NULL
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetSymbolAddress
argument_list|(
argument|const ConstString&name
argument_list|,
argument|lldb::SymbolType symbol_type
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by IRInterpreter] Get basic target information.
comment|///
comment|/// @param[out] byte_order
comment|///     The byte order of the target.
comment|///
comment|/// @param[out] address_byte_size
comment|///     The size of a pointer in bytes.
comment|///
comment|/// @return
comment|///     True if the information could be determined; false
comment|///     otherwise.
comment|//------------------------------------------------------------------
block|struct
name|TargetInfo
block|{
name|lldb
operator|::
name|ByteOrder
name|byte_order
block|;
name|size_t
name|address_byte_size
block|;
name|TargetInfo
argument_list|()
operator|:
name|byte_order
argument_list|(
name|lldb
operator|::
name|eByteOrderInvalid
argument_list|)
block|,
name|address_byte_size
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|IsValid
argument_list|()
block|{
return|return
operator|(
name|byte_order
operator|!=
name|lldb
operator|::
name|eByteOrderInvalid
operator|&&
name|address_byte_size
operator|!=
literal|0
operator|)
return|;
block|}
expr|}
block|;
name|TargetInfo
name|GetTargetInfo
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// [Used by ClangASTSource] Find all entities matching a given name,
comment|/// using a NameSearchContext to make Decls for them.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext that can construct Decls for this name.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|void
name|FindExternalVisibleDecls
argument_list|(
argument|NameSearchContext&context
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Find all entities matching a given name in a given module/namespace,
comment|/// using a NameSearchContext to make Decls for them.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext that can construct Decls for this name.
comment|///
comment|/// @param[in] module
comment|///     If non-NULL, the module to query.
comment|///
comment|/// @param[in] namespace_decl
comment|///     If valid and module is non-NULL, the parent namespace.
comment|///
comment|/// @param[in] name
comment|///     The name as a plain C string.  The NameSearchContext contains
comment|///     a DeclarationName for the name so at first the name may seem
comment|///     redundant, but ClangExpressionDeclMap operates in RTTI land so
comment|///     it can't access DeclarationName.
comment|///
comment|/// @param[in] current_id
comment|///     The ID for the current FindExternalVisibleDecls invocation,
comment|///     for logging purposes.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|void
name|FindExternalVisibleDecls
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|lldb::ModuleSP module
argument_list|,
argument|CompilerDeclContext&namespace_decl
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
name|private
operator|:
name|ExpressionVariableList
name|m_found_entities
block|;
comment|///< All entities that were looked up for the parser.
name|ExpressionVariableList
name|m_struct_members
block|;
comment|///< All entities that need to be placed in the struct.
name|bool
name|m_keep_result_in_memory
block|;
comment|///< True if result persistent variables
comment|///generated by this expression should stay in
comment|///memory.
name|Materializer
operator|::
name|PersistentVariableDelegate
operator|*
name|m_result_delegate
block|;
comment|///< If non-NULL, used to report expression results to
comment|///ClangUserExpression.
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
block|{}
name|Target
operator|*
name|GetTarget
argument_list|()
block|{
if|if
condition|(
name|m_exe_ctx
operator|.
name|GetTargetPtr
argument_list|()
condition|)
return|return
name|m_exe_ctx
operator|.
name|GetTargetPtr
argument_list|()
return|;
elseif|else
if|if
condition|(
name|m_sym_ctx
operator|.
name|target_sp
condition|)
name|m_sym_ctx
operator|.
name|target_sp
operator|.
name|get
argument_list|()
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|ExecutionContext
name|m_exe_ctx
block|;
comment|///< The execution context to use when parsing.
name|SymbolContext
name|m_sym_ctx
block|;
comment|///< The symbol context to use in finding variables
comment|///and types.
name|ClangPersistentVariables
operator|*
name|m_persistent_vars
operator|=
name|nullptr
block|;
comment|///< The persistent variables for the process.
name|bool
name|m_enable_lookups
operator|=
name|false
block|;
comment|///< Set to true during parsing if we have
comment|///found the first "$__lldb" name.
name|TargetInfo
name|m_target_info
block|;
comment|///< Basic information about the target.
name|Materializer
operator|*
name|m_materializer
operator|=
name|nullptr
block|;
comment|///< If non-NULL, the materializer
comment|///to use when reporting used
comment|///variables.
name|clang
operator|::
name|ASTConsumer
operator|*
name|m_code_gen
operator|=
name|nullptr
block|;
comment|///< If non-NULL, a code generator
comment|///that receives new top-level
comment|///functions.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ParserVars
argument_list|)
block|;   }
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ParserVars
operator|>
name|m_parser_vars
block|;
comment|//----------------------------------------------------------------------
comment|/// Activate parser-specific variables
comment|//----------------------------------------------------------------------
name|void
name|EnableParserVars
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_parser_vars
operator|.
name|get
argument_list|()
condition|)
name|m_parser_vars
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|ParserVars
operator|>
operator|(
operator|)
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Deallocate parser-specific variables
comment|//----------------------------------------------------------------------
name|void
name|DisableParserVars
argument_list|()
block|{
name|m_parser_vars
operator|.
name|reset
argument_list|()
block|; }
comment|//----------------------------------------------------------------------
comment|/// The following values contain layout information for the materialized
comment|/// struct, but are not specific to a single materialization
comment|//----------------------------------------------------------------------
expr|struct
name|StructVars
block|{
name|StructVars
argument_list|()
operator|:
name|m_struct_alignment
argument_list|(
literal|0
argument_list|)
block|,
name|m_struct_size
argument_list|(
literal|0
argument_list|)
block|,
name|m_struct_laid_out
argument_list|(
name|false
argument_list|)
block|,
name|m_result_name
argument_list|()
block|,
name|m_object_pointer_type
argument_list|(
argument|NULL
argument_list|,
argument|NULL
argument_list|)
block|{}
name|lldb
operator|::
name|offset_t
name|m_struct_alignment
block|;
comment|///< The alignment of the struct in bytes.
name|size_t
name|m_struct_size
block|;
comment|///< The size of the struct in bytes.
name|bool
name|m_struct_laid_out
block|;
comment|///< True if the struct has been laid out and the
comment|///layout is valid (that is, no new fields have been
comment|///added since).
name|ConstString
name|m_result_name
block|;
comment|///< The name of the result variable ($1, for example)
name|TypeFromUser
name|m_object_pointer_type
block|;
comment|///< The type of the "this" variable, if
comment|///one exists
block|}
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|StructVars
operator|>
name|m_struct_vars
block|;
comment|//----------------------------------------------------------------------
comment|/// Activate struct variables
comment|//----------------------------------------------------------------------
name|void
name|EnableStructVars
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_struct_vars
operator|.
name|get
argument_list|()
condition|)
name|m_struct_vars
operator|.
name|reset
argument_list|(
name|new
expr|struct
name|StructVars
argument_list|)
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|/// Deallocate struct variables
comment|//----------------------------------------------------------------------
name|void
name|DisableStructVars
argument_list|()
block|{
name|m_struct_vars
operator|.
name|reset
argument_list|()
block|; }
comment|//----------------------------------------------------------------------
comment|/// Get this parser's ID for use in extracting parser- and JIT-specific
comment|/// data from persistent variables.
comment|//----------------------------------------------------------------------
name|uint64_t
name|GetParserID
argument_list|()
block|{
return|return
operator|(
name|uint64_t
operator|)
name|this
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Given a target, find a variable that matches the given name and
comment|/// type.
comment|///
comment|/// @param[in] target
comment|///     The target to use as a basis for finding the variable.
comment|///
comment|/// @param[in] module
comment|///     If non-NULL, the module to search.
comment|///
comment|/// @param[in] name
comment|///     The name as a plain C string.
comment|///
comment|/// @param[in] namespace_decl
comment|///     If non-NULL and module is non-NULL, the parent namespace.
comment|///
comment|/// @param[in] type
comment|///     The required type for the variable.  This function may be called
comment|///     during parsing, in which case we don't know its type; hence the
comment|///     default.
comment|///
comment|/// @return
comment|///     The LLDB Variable found, or NULL if none was found.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|VariableSP
name|FindGlobalVariable
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|CompilerDeclContext
operator|*
name|namespace_decl
argument_list|,
name|TypeFromUser
operator|*
name|type
operator|=
name|NULL
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get the value of a variable in a given execution context and return
comment|/// the associated Types if needed.
comment|///
comment|/// @param[in] var
comment|///     The variable to evaluate.
comment|///
comment|/// @param[out] var_location
comment|///     The variable location value to fill in
comment|///
comment|/// @param[out] found_type
comment|///     The type of the found value, as it was found in the user process.
comment|///     This is only useful when the variable is being inspected on behalf
comment|///     of the parser, hence the default.
comment|///
comment|/// @param[out] parser_type
comment|///     The type of the found value, as it was copied into the parser's
comment|///     AST context.  This is only useful when the variable is being
comment|///     inspected on behalf of the parser, hence the default.
comment|///
comment|/// @param[in] decl
comment|///     The Decl to be looked up.
comment|///
comment|/// @return
comment|///     Return true if the value was successfully filled in.
comment|//------------------------------------------------------------------
name|bool
name|GetVariableValue
argument_list|(
name|lldb
operator|::
name|VariableSP
operator|&
name|var
argument_list|,
name|lldb_private
operator|::
name|Value
operator|&
name|var_location
argument_list|,
name|TypeFromUser
operator|*
name|found_type
operator|=
name|NULL
argument_list|,
name|TypeFromParser
operator|*
name|parser_type
operator|=
name|NULL
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Use the NameSearchContext to generate a Decl for the given LLDB
comment|/// Variable, and put it in the Tuple list.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] var
comment|///     The LLDB Variable that needs a Decl.
comment|///
comment|/// @param[in] valobj
comment|///     The LLDB ValueObject for that variable.
comment|//------------------------------------------------------------------
name|void
name|AddOneVariable
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|lldb::VariableSP var
argument_list|,
argument|lldb::ValueObjectSP valobj
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Use the NameSearchContext to generate a Decl for the given
comment|/// persistent variable, and put it in the list of found entities.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] pvar
comment|///     The persistent variable that needs a Decl.
comment|///
comment|/// @param[in] current_id
comment|///     The ID of the current invocation of FindExternalVisibleDecls
comment|///     for logging purposes.
comment|//------------------------------------------------------------------
name|void
name|AddOneVariable
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|lldb::ExpressionVariableSP&pvar_sp
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Use the NameSearchContext to generate a Decl for the given LLDB
comment|/// symbol (treated as a variable), and put it in the list of found
comment|/// entities.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] var
comment|///     The LLDB Variable that needs a Decl.
comment|//------------------------------------------------------------------
name|void
name|AddOneGenericVariable
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|const Symbol&symbol
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Use the NameSearchContext to generate a Decl for the given
comment|/// function.  (Functions are not placed in the Tuple list.)  Can
comment|/// handle both fully typed functions and generic functions.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] fun
comment|///     The Function that needs to be created.  If non-NULL, this is
comment|///     a fully-typed function.
comment|///
comment|/// @param[in] sym
comment|///     The Symbol that corresponds to a function that needs to be
comment|///     created with generic type (unitptr_t foo(...)).
comment|//------------------------------------------------------------------
name|void
name|AddOneFunction
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|Function *fun
argument_list|,
argument|Symbol *sym
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Use the NameSearchContext to generate a Decl for the given
comment|/// register.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] reg_info
comment|///     The information corresponding to that register.
comment|//------------------------------------------------------------------
name|void
name|AddOneRegister
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|const RegisterInfo *reg_info
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Use the NameSearchContext to generate a Decl for the given
comment|/// type.  (Types are not placed in the Tuple list.)
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] type
comment|///     The type that needs to be created.
comment|//------------------------------------------------------------------
name|void
name|AddOneType
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|TypeFromUser&type
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Generate a Decl for "*this" and add a member function declaration
comment|/// to it for the expression, then report it.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when constructing the Decl.
comment|///
comment|/// @param[in] type
comment|///     The type for *this.
comment|//------------------------------------------------------------------
name|void
name|AddThisType
argument_list|(
argument|NameSearchContext&context
argument_list|,
argument|TypeFromUser&type
argument_list|,
argument|unsigned int current_id
argument_list|)
block|;
name|ClangASTContext
operator|*
name|GetClangASTContext
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ClangExpressionDeclMap_h_
end_comment

end_unit

