begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LLVMUserExpression.h ------------------------------------*- C++ -*-===//
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
name|liblldb_LLVMUserExpression_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_LLVMUserExpression_h
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
file|"llvm/IR/LegacyPassManager.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Expression/UserExpression.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class LLVMUserExpression LLVMUserExpression.h
comment|/// "lldb/Expression/LLVMUserExpression.h"
comment|/// @brief Encapsulates a one-time expression for use in lldb.
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  LLVMUserExpression is a virtual base
comment|/// class that encapsulates the objects needed to parse and JIT an expression.
comment|/// The actual parsing part will be provided by the specific implementations
comment|/// of LLVMUserExpression - which will be vended through the appropriate
comment|/// TypeSystem.
comment|//----------------------------------------------------------------------
name|class
name|LLVMUserExpression
range|:
name|public
name|UserExpression
block|{
name|public
operator|:
comment|// The IRPasses struct is filled in by a runtime after an expression is
comment|// compiled and can be used to to run
comment|// fixups/analysis passes as required. EarlyPasses are run on the generated
comment|// module before lldb runs its own IR
comment|// fixups and inserts instrumentation code/pointer checks. LatePasses are run
comment|// after the module has been processed by
comment|// llvm, before the module is assembled and run in the ThreadPlan.
expr|struct
name|IRPasses
block|{
name|IRPasses
argument_list|()
operator|:
name|EarlyPasses
argument_list|(
name|nullptr
argument_list|)
block|,
name|LatePasses
argument_list|(
argument|nullptr
argument_list|)
block|{}
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|llvm
operator|::
name|legacy
operator|::
name|PassManager
operator|>
name|EarlyPasses
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|llvm
operator|::
name|legacy
operator|::
name|PassManager
operator|>
name|LatePasses
block|;   }
block|;
name|LLVMUserExpression
argument_list|(
argument|ExecutionContextScope&exe_scope
argument_list|,
argument|llvm::StringRef expr
argument_list|,
argument|llvm::StringRef prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|ResultType desired_type
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
block|;
operator|~
name|LLVMUserExpression
argument_list|()
name|override
block|;
name|bool
name|FinalizeJITExecution
argument_list|(
argument|DiagnosticManager&diagnostic_manager
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::ExpressionVariableSP&result
argument_list|,
argument|lldb::addr_t function_stack_bottom = LLDB_INVALID_ADDRESS
argument_list|,
argument|lldb::addr_t function_stack_top = LLDB_INVALID_ADDRESS
argument_list|)
name|override
block|;
name|bool
name|CanInterpret
argument_list|()
name|override
block|{
return|return
name|m_can_interpret
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the string that the parser should parse.  Must be a full
comment|/// translation unit.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|Text
argument_list|()
name|override
block|{
return|return
name|m_transformed_text
operator|.
name|c_str
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ModuleSP
name|GetJITModule
argument_list|()
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|ExpressionResults
name|DoExecute
argument_list|(
argument|DiagnosticManager&diagnostic_manager
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|,
argument|lldb::UserExpressionSP&shared_ptr_to_me
argument_list|,
argument|lldb::ExpressionVariableSP&result
argument_list|)
name|override
block|;
name|virtual
name|void
name|ScanContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|err
argument_list|)
operator|=
literal|0
block|;
name|bool
name|PrepareToExecuteJITExpression
argument_list|(
name|DiagnosticManager
operator|&
name|diagnostic_manager
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|struct_address
argument_list|)
block|;
name|virtual
name|bool
name|AddArguments
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|std::vector<lldb::addr_t>&args
argument_list|,
argument|lldb::addr_t struct_address
argument_list|,
argument|DiagnosticManager&diagnostic_manager
argument_list|)
operator|=
literal|0
block|;
name|lldb
operator|::
name|addr_t
name|m_stack_frame_bottom
block|;
comment|///< The bottom of the allocated stack frame.
name|lldb
operator|::
name|addr_t
name|m_stack_frame_top
block|;
comment|///< The top of the allocated stack frame.
name|bool
name|m_allow_cxx
block|;
comment|///< True if the language allows C++.
name|bool
name|m_allow_objc
block|;
comment|///< True if the language allows Objective-C.
name|std
operator|::
name|string
name|m_transformed_text
block|;
comment|///< The text of the expression, as send to the parser
name|std
operator|::
name|shared_ptr
operator|<
name|IRExecutionUnit
operator|>
name|m_execution_unit_sp
block|;
comment|///< The execution unit the expression is stored in.
name|std
operator|::
name|unique_ptr
operator|<
name|Materializer
operator|>
name|m_materializer_ap
block|;
comment|///< The materializer to use
comment|///when running the
comment|///expression.
name|lldb
operator|::
name|ModuleWP
name|m_jit_module_wp
block|;
name|bool
name|m_enforce_valid_object
block|;
comment|///< True if the expression parser should enforce
comment|///the presence of a valid class pointer
comment|/// in order to generate the expression as a method.
name|bool
name|m_in_cplusplus_method
block|;
comment|///< True if the expression is compiled as a C++
comment|///member function (true if it was parsed
comment|/// when exe_ctx was in a C++ method).
name|bool
name|m_in_objectivec_method
block|;
comment|///< True if the expression is compiled as an
comment|///Objective-C method (true if it was parsed
comment|/// when exe_ctx was in an Objective-C method).
name|bool
name|m_in_static_method
block|;
comment|///< True if the expression is compiled as a static
comment|///(or class) method (currently true if it
comment|/// was parsed when exe_ctx was in an Objective-C class method).
name|bool
name|m_needs_object_ptr
block|;
comment|///< True if "this" or "self" must be looked up and
comment|///passed in.  False if the expression
comment|/// doesn't really use them and they can be NULL.
name|bool
name|m_const_object
block|;
comment|///< True if "this" is const.
name|Target
operator|*
name|m_target
block|;
comment|///< The target for storing persistent data like types and
comment|///variables.
name|bool
name|m_can_interpret
block|;
comment|///< True if the expression could be evaluated
comment|///statically; false otherwise.
name|lldb
operator|::
name|addr_t
name|m_materialized_address
block|;
comment|///< The address at which the arguments
comment|///to the expression have been
comment|///materialized.
name|Materializer
operator|::
name|DematerializerSP
name|m_dematerializer_sp
block|;
comment|///< The dematerializer.
block|}
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

end_unit

