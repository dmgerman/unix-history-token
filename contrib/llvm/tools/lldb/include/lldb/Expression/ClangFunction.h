begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangFunction.h -----------------------------------------*- C++ -*-===//
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
name|lldb_ClangFunction_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_ClangFunction_h_
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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<list>
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
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ValueObjectList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ASTStructExtractor
decl_stmt|;
name|class
name|ClangExpressionParser
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ClangFunction ClangFunction.h "lldb/Expression/ClangFunction.h"
comment|/// @brief Encapsulates a function that can be called.
comment|///
comment|/// A given ClangFunction object can handle a single function signature.
comment|/// Once constructed, it can set up any number of concurrent calls to
comment|/// functions with that signature.
comment|///
comment|/// It performs the call by synthesizing a structure that contains the pointer
comment|/// to the function and the arguments that should be passed to that function,
comment|/// and producing a special-purpose JIT-compiled function that accepts a void*
comment|/// pointing to this struct as its only argument and calls the function in the
comment|/// struct with the written arguments.  This method lets Clang handle the
comment|/// vagaries of function calling conventions.
comment|///
comment|/// The simplest use of the ClangFunction is to construct it with a
comment|/// function representative of the signature you want to use, then call
comment|/// ExecuteFunction(ExecutionContext&, Stream&, Value&).
comment|///
comment|/// If you need to reuse the arguments for several calls, you can call
comment|/// InsertFunction() followed by WriteFunctionArguments(), which will return
comment|/// the location of the args struct for the wrapper function in args_addr_ref.
comment|///
comment|/// If you need to call the function on the thread plan stack, you can also
comment|/// call InsertFunction() followed by GetThreadPlanToCallFunction().
comment|///
comment|/// Any of the methods that take arg_addr_ptr or arg_addr_ref can be passed
comment|/// a pointer set to LLDB_INVALID_ADDRESS and new structure will be allocated
comment|/// and its address returned in that variable.
comment|///
comment|/// Any of the methods that take arg_addr_ptr can be passed NULL, and the
comment|/// argument space will be managed for you.
comment|//----------------------------------------------------------------------
name|class
name|ClangFunction
range|:
name|public
name|ClangExpression
block|{
name|friend
name|class
name|ASTStructExtractor
block|;
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] exe_scope
comment|///     An execution context scope that gets us at least a target and
comment|///     process.
comment|///
comment|/// @param[in] function_ptr
comment|///     The default function to be called.  Can be overridden using
comment|///     WriteFunctionArguments().
comment|///
comment|/// @param[in] ast_context
comment|///     The AST context to evaluate argument types in.
comment|///
comment|/// @param[in] arg_value_list
comment|///     The default values to use when calling this function.  Can
comment|///     be overridden using WriteFunctionArguments().
comment|//------------------------------------------------------------------
name|ClangFunction
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|,
name|Function
operator|&
name|function_ptr
argument_list|,
name|ClangASTContext
operator|*
name|ast_context
argument_list|,
specifier|const
name|ValueList
operator|&
name|arg_value_list
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] exe_scope
comment|///     An execution context scope that gets us at least a target and
comment|///     process.
comment|///
comment|/// @param[in] ast_context
comment|///     The AST context to evaluate argument types in.
comment|///
comment|/// @param[in] return_qualtype
comment|///     An opaque Clang QualType for the function result.  Should be
comment|///     defined in ast_context.
comment|///
comment|/// @param[in] function_address
comment|///     The address of the function to call.
comment|///
comment|/// @param[in] arg_value_list
comment|///     The default values to use when calling this function.  Can
comment|///     be overridden using WriteFunctionArguments().
comment|//------------------------------------------------------------------
name|ClangFunction
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|,
specifier|const
name|ClangASTType
operator|&
name|return_type
argument_list|,
specifier|const
name|Address
operator|&
name|function_address
argument_list|,
specifier|const
name|ValueList
operator|&
name|arg_value_list
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|ClangFunction
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Compile the wrapper function
comment|///
comment|/// @param[in] errors
comment|///     The stream to print parser errors to.
comment|///
comment|/// @return
comment|///     The number of errors.
comment|//------------------------------------------------------------------
name|unsigned
name|CompileFunction
argument_list|(
name|Stream
operator|&
name|errors
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Insert the default function wrapper and its default argument struct
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to insert the function and its arguments
comment|///     into.
comment|///
comment|/// @param[in,out] args_addr_ref
comment|///     The address of the structure to write the arguments into.  May
comment|///     be LLDB_INVALID_ADDRESS; if it is, a new structure is allocated
comment|///     and args_addr_ref is pointed to it.
comment|///
comment|/// @param[in] errors
comment|///     The stream to write errors to.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|InsertFunction
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|args_addr_ref
argument_list|,
name|Stream
operator|&
name|errors
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Insert the default function wrapper (using the JIT)
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to insert the function and its arguments
comment|///     into.
comment|///
comment|/// @param[in] errors
comment|///     The stream to write errors to.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|WriteFunctionWrapper
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|Stream
operator|&
name|errors
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Insert the default function argument struct
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to insert the function and its arguments
comment|///     into.
comment|///
comment|/// @param[in,out] args_addr_ref
comment|///     The address of the structure to write the arguments into.  May
comment|///     be LLDB_INVALID_ADDRESS; if it is, a new structure is allocated
comment|///     and args_addr_ref is pointed to it.
comment|///
comment|/// @param[in] errors
comment|///     The stream to write errors to.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|WriteFunctionArguments
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|args_addr_ref
argument_list|,
name|Stream
operator|&
name|errors
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Insert an argument struct with a non-default function address and
comment|/// non-default argument values
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to insert the function and its arguments
comment|///     into.
comment|///
comment|/// @param[in,out] args_addr_ref
comment|///     The address of the structure to write the arguments into.  May
comment|///     be LLDB_INVALID_ADDRESS; if it is, a new structure is allocated
comment|///     and args_addr_ref is pointed to it.
comment|///
comment|/// @param[in] function_address
comment|///     The address of the function to call.
comment|///
comment|/// @param[in] arg_values
comment|///     The values of the function's arguments.
comment|///
comment|/// @param[in] errors
comment|///     The stream to write errors to.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|WriteFunctionArguments
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::addr_t&args_addr_ref
argument_list|,
argument|Address function_address
argument_list|,
argument|ValueList&arg_values
argument_list|,
argument|Stream&errors
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Run the function this ClangFunction was created with.
comment|///
comment|/// This is the full version.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The thread& process in which this function will run.
comment|///
comment|/// @param[in] args_addr_ptr
comment|///     If NULL, the function will take care of allocating& deallocating the wrapper
comment|///     args structure.  Otherwise, if set to LLDB_INVALID_ADDRESS, a new structure
comment|///     will be allocated, filled and the address returned to you.  You are responsible
comment|///     for deallocating it.  And if passed in with a value other than LLDB_INVALID_ADDRESS,
comment|///     this should point to an already allocated structure with the values already written.
comment|///
comment|/// @param[in] errors
comment|///     Errors will be written here if there are any.
comment|///
comment|/// @param[in] options
comment|///     The options for this expression execution.
comment|///
comment|/// @param[out] results
comment|///     The result value will be put here after running the function.
comment|///
comment|/// @return
comment|///     Returns one of the ExecutionResults enum indicating function call status.
comment|//------------------------------------------------------------------
name|ExecutionResults
name|ExecuteFunction
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|*
name|args_addr_ptr
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
name|Stream
operator|&
name|errors
argument_list|,
name|Value
operator|&
name|results
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get a thread plan to run the function this ClangFunction was created with.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to insert the function and its arguments
comment|///     into.
comment|///
comment|/// @param[in] func_addr
comment|///     The address of the function in the target process.
comment|///
comment|/// @param[in] args_addr
comment|///     The address of the argument struct.
comment|///
comment|/// @param[in] errors
comment|///     The stream to write errors to.
comment|///
comment|/// @param[in] stop_others
comment|///     True if other threads should pause during execution.
comment|///
comment|/// @param[in] unwind_on_error
comment|///     True if the thread plan may simply be discarded if an error occurs.
comment|///
comment|/// @return
comment|///     A ThreadPlan for executing the function.
comment|//------------------------------------------------------------------
name|ThreadPlan
operator|*
name|GetThreadPlanToCallFunction
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::addr_t args_addr
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|,
argument|Stream&errors
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get the result of the function from its struct
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to retrieve the result from.
comment|///
comment|/// @param[in] args_addr
comment|///     The address of the argument struct.
comment|///
comment|/// @param[out] ret_value
comment|///     The value returned by the function.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|FetchFunctionResults
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::addr_t args_addr
argument_list|,
argument|Value&ret_value
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Deallocate the arguments structure
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to insert the function and its arguments
comment|///     into.
comment|///
comment|/// @param[in] args_addr
comment|///     The address of the argument struct.
comment|//------------------------------------------------------------------
name|void
name|DeallocateFunctionResults
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::addr_t args_addr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Interface for ClangExpression
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Return the string that the parser should parse.  Must be a full
comment|/// translation unit.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|Text
argument_list|()
block|{
return|return
name|m_wrapper_function_text
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the function name that should be used for executing the
comment|/// expression.  Text() should contain the definition of this
comment|/// function.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|FunctionName
argument_list|()
block|{
return|return
name|m_wrapper_function_name
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when resolving external
comment|/// values.  May be NULL if everything should be self-contained.
comment|//------------------------------------------------------------------
name|ClangExpressionDeclMap
operator|*
name|DeclMap
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when registering
comment|/// local variables.  May be NULL if the Expression doesn't care.
comment|//------------------------------------------------------------------
name|ClangExpressionVariableList
operator|*
name|LocalVariables
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should allow to access ASTs.
comment|/// May be NULL if the ASTs do not need to be transformed.
comment|///
comment|/// @param[in] passthrough
comment|///     The ASTConsumer that the returned transformer should send
comment|///     the ASTs to after transformation.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|ASTConsumer
operator|*
name|ASTTransformer
argument_list|(
name|clang
operator|::
name|ASTConsumer
operator|*
name|passthrough
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Return true if validation code should be inserted into the
comment|/// expression.
comment|//------------------------------------------------------------------
name|bool
name|NeedsValidation
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if external variables in the expression should be
comment|/// resolved.
comment|//------------------------------------------------------------------
name|bool
name|NeedsVariableResolution
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|ValueList
name|GetArgumentValues
argument_list|()
specifier|const
block|{
return|return
name|m_arg_values
return|;
block|}
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For ClangFunction only
comment|//------------------------------------------------------------------
name|std
operator|::
name|unique_ptr
operator|<
name|ClangExpressionParser
operator|>
name|m_parser
block|;
comment|///< The parser responsible for compiling the function.
name|std
operator|::
name|unique_ptr
operator|<
name|IRExecutionUnit
operator|>
name|m_execution_unit_ap
block|;
name|Function
operator|*
name|m_function_ptr
block|;
comment|///< The function we're going to call.  May be NULL if we don't have debug info for the function.
name|Address
name|m_function_addr
block|;
comment|///< If we don't have the FunctionSP, we at least need the address& return type.
name|ClangASTType
name|m_function_return_type
block|;
comment|///< The opaque clang qual type for the function return type.
name|std
operator|::
name|string
name|m_wrapper_function_name
block|;
comment|///< The name of the wrapper function.
name|std
operator|::
name|string
name|m_wrapper_function_text
block|;
comment|///< The contents of the wrapper function.
name|std
operator|::
name|string
name|m_wrapper_struct_name
block|;
comment|///< The name of the struct that contains the target function address, arguments, and result.
name|std
operator|::
name|list
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_wrapper_args_addrs
block|;
comment|///< The addresses of the arguments to the wrapper function.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTStructExtractor
operator|>
name|m_struct_extractor
block|;
comment|///< The class that generates the argument struct below.
name|bool
name|m_struct_valid
block|;
comment|///< True if the ASTStructExtractor has populated the variables below.
comment|//------------------------------------------------------------------
comment|/// These values are populated by the ASTStructExtractor
name|size_t
name|m_struct_size
block|;
comment|///< The size of the argument struct, in bytes.
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
name|m_member_offsets
block|;
comment|///< The offset of each member in the struct, in bytes.
name|uint64_t
name|m_return_size
block|;
comment|///< The size of the result variable, in bytes.
name|uint64_t
name|m_return_offset
block|;
comment|///< The offset of the result variable in the struct, in bytes.
comment|//------------------------------------------------------------------
name|ValueList
name|m_arg_values
block|;
comment|///< The default values of the arguments.
name|bool
name|m_compiled
block|;
comment|///< True if the wrapper function has already been parsed.
name|bool
name|m_JITted
block|;
comment|///< True if the wrapper function has already been JIT-compiled.
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_ClangFunction_h_
end_comment

end_unit

