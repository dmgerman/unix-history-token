begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangFunctionCaller.h -----------------------------------*- C++ -*-===//
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
name|liblldb_ClangFunctionCaller_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangFunctionCaller_h_
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
file|"ClangExpressionHelper.h"
end_include

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
file|"lldb/Expression/FunctionCaller.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
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
comment|/// @class ClangFunctionCaller ClangFunctionCaller.h "lldb/Expression/ClangFunctionCaller.h"
comment|/// @brief Encapsulates a function that can be called.
comment|///
comment|/// A given ClangFunctionCaller object can handle a single function signature.
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
comment|/// The simplest use of the ClangFunctionCaller is to construct it with a
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
name|ClangFunctionCaller
range|:
name|public
name|FunctionCaller
block|{
name|friend
name|class
name|ASTStructExtractor
block|;
name|class
name|ClangFunctionCallerHelper
operator|:
name|public
name|ClangExpressionHelper
block|{
name|public
operator|:
name|ClangFunctionCallerHelper
argument_list|(
name|ClangFunctionCaller
operator|&
name|owner
argument_list|)
operator|:
name|m_owner
argument_list|(
argument|owner
argument_list|)
block|{         }
operator|~
name|ClangFunctionCallerHelper
argument_list|()
name|override
operator|=
expr|default
block|;
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when resolving external
comment|/// values.  May be NULL if everything should be self-contained.
comment|//------------------------------------------------------------------
name|ClangExpressionDeclMap
operator|*
name|DeclMap
argument_list|()
name|override
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
argument|clang::ASTConsumer *passthrough
argument_list|)
name|override
block|;
name|private
operator|:
name|ClangFunctionCaller
operator|&
name|m_owner
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTStructExtractor
operator|>
name|m_struct_extractor
block|;
comment|///< The class that generates the argument struct layout.
block|}
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
name|ClangFunctionCaller
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|,
specifier|const
name|CompilerType
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
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
operator|~
name|ClangFunctionCaller
argument_list|()
name|override
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
argument|Stream&errors
argument_list|)
name|override
block|;
name|ExpressionTypeSystemHelper
operator|*
name|GetTypeSystemHelper
argument_list|()
name|override
block|{
return|return
operator|&
name|m_type_system_helper
return|;
block|}
name|protected
operator|:
specifier|const
name|char
operator|*
name|GetWrapperStructName
argument_list|()
block|{
return|return
name|m_wrapper_struct_name
operator|.
name|c_str
argument_list|()
return|;
block|}
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For ClangFunctionCaller only
comment|//------------------------------------------------------------------
comment|// Note: the parser needs to be destructed before the execution unit, so
comment|// declare the execution unit first.
name|ClangFunctionCallerHelper
name|m_type_system_helper
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
comment|// liblldb_ClangFunctionCaller_h_
end_comment

end_unit

