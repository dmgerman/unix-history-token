begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IRForTarget.h ---------------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_IRForTarget_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IRForTarget_h_
end_define

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
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StreamString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|IntegerType
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Type
decl_stmt|;
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
name|ClangExpressionDeclMap
decl_stmt|;
name|class
name|IRExecutionUnit
decl_stmt|;
name|class
name|IRMemoryMap
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class IRForTarget IRForTarget.h "lldb/Expression/IRForTarget.h"
end_comment

begin_comment
comment|/// @brief Transforms the IR for a function to run in the target
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Once an expression has been parsed and converted to IR, it can run
end_comment

begin_comment
comment|/// in two contexts: interpreted by LLDB as a DWARF location expression,
end_comment

begin_comment
comment|/// or compiled by the JIT and inserted into the target process for
end_comment

begin_comment
comment|/// execution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IRForTarget makes the second possible, by applying a series of
end_comment

begin_comment
comment|/// transformations to the IR which make it relocatable.  These
end_comment

begin_comment
comment|/// transformations are discussed in more detail next to their relevant
end_comment

begin_comment
comment|/// functions.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|IRForTarget
range|:
name|public
name|llvm
operator|::
name|ModulePass
block|{
name|public
operator|:
expr|enum
name|class
name|LookupResult
block|{
name|Success
block|,
name|Fail
block|,
name|Ignore
block|}
block|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] decl_map
comment|///     The list of externally-referenced variables for the expression,
comment|///     for use in looking up globals and allocating the argument
comment|///     struct.  See the documentation for ClangExpressionDeclMap.
comment|///
comment|/// @param[in] resolve_vars
comment|///     True if the external variable references (including persistent
comment|///     variables) should be resolved.  If not, only external functions
comment|///     are resolved.
comment|///
comment|/// @param[in] execution_policy
comment|///     Determines whether an IR interpreter can be used to statically
comment|///     evaluate the expression.
comment|///
comment|/// @param[in] const_result
comment|///     This variable is populated with the statically-computed result
comment|///     of the function, if it has no side-effects and the result can
comment|///     be computed statically.
comment|///
comment|/// @param[in] execution_unit
comment|///     The holder for raw data associated with the expression.
comment|///
comment|/// @param[in] error_stream
comment|///     If non-NULL, a stream on which errors can be printed.
comment|///
comment|/// @param[in] func_name
comment|///     The name of the function to prepare for execution in the target.
comment|//------------------------------------------------------------------
name|IRForTarget
argument_list|(
argument|lldb_private::ClangExpressionDeclMap *decl_map
argument_list|,
argument|bool resolve_vars
argument_list|,
argument|lldb_private::IRExecutionUnit&execution_unit
argument_list|,
argument|lldb_private::Stream&error_stream
argument_list|,
argument|const char *func_name =
literal|"$__lldb_expr"
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|IRForTarget
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Run this IR transformer on a single module
comment|///
comment|/// Implementation of the llvm::ModulePass::runOnModule() function.
comment|///
comment|/// @param[in] llvm_module
comment|///     The module to run on.  This module is searched for the function
comment|///     $__lldb_expr, and that function is passed to the passes one by
comment|///     one.
comment|///
comment|/// @param[in] interpreter_error
comment|///     An error.  If the expression fails to be interpreted, this error
comment|///     is set to a reason why.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|runOnModule
argument_list|(
argument|llvm::Module&llvm_module
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Interface stub
comment|///
comment|/// Implementation of the llvm::ModulePass::assignPassManager()
comment|/// function.
comment|//------------------------------------------------------------------
name|void
name|assignPassManager
argument_list|(
argument|llvm::PMStack&pass_mgr_stack
argument_list|,
argument|llvm::PassManagerType pass_mgr_type =                              llvm::PMT_ModulePassManager
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Returns PMT_ModulePassManager
comment|///
comment|/// Implementation of the llvm::ModulePass::getPotentialPassManagerType()
comment|/// function.
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|/// Ensures that the current function's linkage is set to external.
comment|/// Otherwise the JIT may not return an address for it.
comment|///
comment|/// @param[in] llvm_function
comment|///     The function whose linkage is to be fixed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|FixFunctionLinkage
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|llvm_function
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A module-level pass to replace all function pointers with their
comment|/// integer equivalents.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] llvm_module
comment|///     The module currently being processed.
comment|///
comment|/// @param[in] llvm_function
comment|///     The function currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|HasSideEffects
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|llvm_function
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A function-level pass to check whether the function has side
comment|/// effects.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Get the address of a function, and a location to put the complete
comment|/// Value of the function if one is available.
comment|///
comment|/// @param[in] function
comment|///     The function to find the location of.
comment|///
comment|/// @param[out] ptr
comment|///     The location of the function in the target.
comment|///
comment|/// @param[out] name
comment|///     The resolved name of the function (matters for intrinsics).
comment|///
comment|/// @param[out] value_ptr
comment|///     A variable to put the function's completed Value* in, or NULL
comment|///     if the Value* shouldn't be stored anywhere.
comment|///
comment|/// @return
comment|///     The pointer.
comment|//------------------------------------------------------------------
name|LookupResult
name|GetFunctionAddress
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|function
argument_list|,
name|uint64_t
operator|&
name|ptr
argument_list|,
name|lldb_private
operator|::
name|ConstString
operator|&
name|name
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|*
operator|&
name|value_ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A function-level pass to take the generated global value
comment|/// $__lldb_expr_result and make it into a persistent variable.
comment|/// Also see ASTResultSynthesizer.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Find the NamedDecl corresponding to a Value.  This interface is
comment|/// exposed for the IR interpreter.
comment|///
comment|/// @param[in] module
comment|///     The module containing metadata to search
comment|///
comment|/// @param[in] global
comment|///     The global entity to search for
comment|///
comment|/// @return
comment|///     The corresponding variable declaration
comment|//------------------------------------------------------------------
name|public
operator|:
specifier|static
name|clang
operator|::
name|NamedDecl
operator|*
name|DeclForGlobal
argument_list|(
specifier|const
name|llvm
operator|::
name|GlobalValue
operator|*
name|global_val
argument_list|,
name|llvm
operator|::
name|Module
operator|*
name|module
argument_list|)
block|;
name|private
operator|:
name|clang
operator|::
name|NamedDecl
operator|*
name|DeclForGlobal
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|global
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Set the constant result variable m_const_result to the provided
comment|/// constant, assuming it can be evaluated.  The result variable
comment|/// will be reset to NULL later if the expression has side effects.
comment|///
comment|/// @param[in] initializer
comment|///     The constant initializer for the variable.
comment|///
comment|/// @param[in] name
comment|///     The name of the result variable.
comment|///
comment|/// @param[in] type
comment|///     The Clang type of the result variable.
comment|//------------------------------------------------------------------
name|void
name|MaybeSetConstantResult
argument_list|(
argument|llvm::Constant *initializer
argument_list|,
argument|const lldb_private::ConstString&name
argument_list|,
argument|lldb_private::TypeFromParser type
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// If the IR represents a cast of a variable, set m_const_result
comment|/// to the result of the cast.  The result variable will be reset to
comment|/// NULL latger if the expression has side effects.
comment|///
comment|/// @param[in] type
comment|///     The Clang type of the result variable.
comment|//------------------------------------------------------------------
name|void
name|MaybeSetCastResult
argument_list|(
argument|lldb_private::TypeFromParser type
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] llvm_function
comment|///     The function currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|CreateResultVariable
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|llvm_function
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A module-level pass to find Objective-C constant strings and
comment|/// transform them to calls to CFStringCreateWithBytes.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Rewrite a single Objective-C constant string.
comment|///
comment|/// @param[in] NSStr
comment|///     The constant NSString to be transformed
comment|///
comment|/// @param[in] CStr
comment|///     The constant C string inside the NSString.  This will be
comment|///     passed as the bytes argument to CFStringCreateWithBytes.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewriteObjCConstString
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|NSStr
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|CStr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewriteObjCConstStrings
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// A basic block-level pass to find all Objective-C method calls and
comment|/// rewrite them to use sel_registerName instead of statically allocated
comment|/// selectors.  The reason is that the selectors are created on the
comment|/// assumption that the Objective-C runtime will scan the appropriate
comment|/// section and prepare them.  This doesn't happen when code is copied
comment|/// into the target, though, and there's no easy way to induce the
comment|/// runtime to scan them.  So instead we get our selectors from
comment|/// sel_registerName.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Replace a single selector reference
comment|///
comment|/// @param[in] selector_load
comment|///     The load of the statically-allocated selector.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewriteObjCSelector
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|selector_load
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] basic_block
comment|///     The basic block currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewriteObjCSelectors
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|basic_block
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A basic block-level pass to find all Objective-C class references that
comment|/// use the old-style Objective-C runtime and rewrite them to use
comment|/// class_getClass instead of statically allocated class references.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Replace a single old-style class reference
comment|///
comment|/// @param[in] selector_load
comment|///     The load of the statically-allocated selector.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewriteObjCClassReference
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|class_load
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] basic_block
comment|///     The basic block currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewriteObjCClassReferences
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|basic_block
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A basic block-level pass to find all newly-declared persistent
comment|/// variables and register them with the ClangExprDeclMap.  This
comment|/// allows them to be materialized and dematerialized like normal
comment|/// external variables.  Before transformation, these persistent
comment|/// variables look like normal locals, so they have an allocation.
comment|/// This pass excises these allocations and makes references look
comment|/// like external references where they will be resolved -- like all
comment|/// other external references -- by ResolveExternals().
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Handle a single allocation of a persistent variable
comment|///
comment|/// @param[in] persistent_alloc
comment|///     The allocation of the persistent variable.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RewritePersistentAlloc
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|persistent_alloc
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] basic_block
comment|///     The basic block currently being processed.
comment|//------------------------------------------------------------------
name|bool
name|RewritePersistentAllocs
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|basic_block
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A function-level pass to find all external variables and functions
comment|/// used in the IR.  Each found external variable is added to the
comment|/// struct, and each external function is resolved in place, its call
comment|/// replaced with a call to a function pointer whose value is the
comment|/// address of the function in the target process.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Write an initializer to a memory array of assumed sufficient
comment|/// size.
comment|///
comment|/// @param[in] data
comment|///     A pointer to the data to write to.
comment|///
comment|/// @param[in] initializer
comment|///     The initializer itself.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|MaterializeInitializer
argument_list|(
name|uint8_t
operator|*
name|data
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|initializer
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Move an internal variable into the static allocation section.
comment|///
comment|/// @param[in] global_variable
comment|///     The variable.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|MaterializeInternalVariable
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|global_variable
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Handle a single externally-defined variable
comment|///
comment|/// @param[in] value
comment|///     The variable.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|MaybeHandleVariable
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Handle a single externally-defined symbol
comment|///
comment|/// @param[in] symbol
comment|///     The symbol.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|HandleSymbol
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|symbol
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Handle a single externally-defined Objective-C class
comment|///
comment|/// @param[in] classlist_reference
comment|///     The reference, usually "01L_OBJC_CLASSLIST_REFERENCES_$_n"
comment|///     where n (if present) is an index.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|HandleObjCClass
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|classlist_reference
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Handle all the arguments to a function call
comment|///
comment|/// @param[in] C
comment|///     The call instruction.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|MaybeHandleCallArguments
argument_list|(
name|llvm
operator|::
name|CallInst
operator|*
name|call_inst
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Resolve variable references in calls to external functions
comment|///
comment|/// @param[in] basic_block
comment|///     The basic block currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|ResolveCalls
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|basic_block
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Remove calls to __cxa_atexit, which should never be generated by
comment|/// expressions.
comment|///
comment|/// @param[in] call_inst
comment|///     The call instruction.
comment|///
comment|/// @return
comment|///     True if the scan was successful; false if some operation
comment|///     failed
comment|//------------------------------------------------------------------
name|bool
name|RemoveCXAAtExit
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|basic_block
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] basic_block
comment|///     The function currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|ResolveExternals
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|llvm_function
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A basic block-level pass to excise guard variables from the code.
comment|/// The result for the function is passed through Clang as a static
comment|/// variable.  Static variables normally have guard variables to
comment|/// ensure that they are only initialized once.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Rewrite a load to a guard variable to return constant 0.
comment|///
comment|/// @param[in] guard_load
comment|///     The load instruction to zero out.
comment|//------------------------------------------------------------------
name|void
name|TurnGuardLoadIntoZero
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|guard_load
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] basic_block
comment|///     The basic block currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|RemoveGuards
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|basic_block
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// A function-level pass to make all external variable references
comment|/// point at the correct offsets from the void* passed into the
comment|/// function.  ClangExpressionDeclMap::DoStructLayout() must be called
comment|/// beforehand, so that the offsets are valid.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] llvm_function
comment|///     The function currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|ReplaceVariables
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|llvm_function
argument_list|)
block|;
comment|/// Flags
name|bool
name|m_resolve_vars
block|;
comment|///< True if external variable references and persistent
comment|///variable references should be resolved
name|lldb_private
operator|::
name|ConstString
name|m_func_name
block|;
comment|///< The name of the function to translate
name|lldb_private
operator|::
name|ConstString
name|m_result_name
block|;
comment|///< The name of the result variable ($0, $1, ...)
name|lldb_private
operator|::
name|TypeFromParser
name|m_result_type
block|;
comment|///< The type of the result variable.
name|llvm
operator|::
name|Module
operator|*
name|m_module
block|;
comment|///< The module being processed, or NULL if that has
comment|///not been determined yet.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|DataLayout
operator|>
name|m_target_data
block|;
comment|///< The target data for the
comment|///module being processed, or
comment|///NULL if there is no
comment|///module.
name|lldb_private
operator|::
name|ClangExpressionDeclMap
operator|*
name|m_decl_map
block|;
comment|///< The DeclMap containing the Decls
name|llvm
operator|::
name|Constant
operator|*
name|m_CFStringCreateWithBytes
block|;
comment|///< The address of the function
comment|///CFStringCreateWithBytes, cast to
comment|///the
comment|/// appropriate function pointer type
name|llvm
operator|::
name|Constant
operator|*
name|m_sel_registerName
block|;
comment|///< The address of the function
comment|///sel_registerName, cast to the
comment|///appropriate
comment|/// function pointer type
name|llvm
operator|::
name|Constant
operator|*
name|m_objc_getClass
block|;
comment|///< The address of the function
comment|///objc_getClass, cast to the
comment|///appropriate
comment|/// function pointer type
name|llvm
operator|::
name|IntegerType
operator|*
name|m_intptr_ty
block|;
comment|///< The type of an integer large enough to hold a pointer.
name|lldb_private
operator|::
name|Stream
operator|&
name|m_error_stream
block|;
comment|///< The stream on which errors should be printed
name|lldb_private
operator|::
name|IRExecutionUnit
operator|&
name|m_execution_unit
block|;
comment|///< The execution unit containing the IR being created.
name|llvm
operator|::
name|StoreInst
operator|*
name|m_result_store
block|;
comment|///< If non-NULL, the store instruction that
comment|///writes to the result variable.  If
comment|/// m_has_side_effects is true, this is NULL.
name|bool
name|m_result_is_pointer
block|;
comment|///< True if the function's result in the AST is a
comment|///pointer (see comments in
comment|/// ASTResultSynthesizer::SynthesizeBodyResult)
name|llvm
operator|::
name|GlobalVariable
operator|*
name|m_reloc_placeholder
block|;
comment|///< A placeholder that will be
comment|///replaced by a pointer to the
comment|///final
comment|/// location of the static allocation.
comment|//------------------------------------------------------------------
comment|/// UnfoldConstant operates on a constant [Old] which has just been
comment|/// replaced with a value [New].  We assume that new_value has
comment|/// been properly placed early in the function, in front of the
comment|/// first instruction in the entry basic block
comment|/// [FirstEntryInstruction].
comment|///
comment|/// UnfoldConstant reads through the uses of Old and replaces Old
comment|/// in those uses with New.  Where those uses are constants, the
comment|/// function generates new instructions to compute the result of the
comment|/// new, non-constant expression and places them before
comment|/// FirstEntryInstruction.  These instructions replace the constant
comment|/// uses, so UnfoldConstant calls itself recursively for those.
comment|///
comment|/// @param[in] llvm_function
comment|///     The function currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|class
name|FunctionValueCache
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|(
name|llvm
operator|::
name|Function
operator|*
operator|)
operator|>
name|Maker
expr_stmt|;
name|FunctionValueCache
argument_list|(
name|Maker
specifier|const
operator|&
name|maker
argument_list|)
block|;
operator|~
name|FunctionValueCache
argument_list|()
block|;
name|llvm
operator|::
name|Value
operator|*
name|GetValue
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|function
argument_list|)
block|;
name|private
operator|:
name|Maker
specifier|const
name|m_maker
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|FunctionValueMap
expr_stmt|;
name|FunctionValueMap
name|m_values
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|FunctionValueCache
name|m_entry_instruction_finder
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|UnfoldConstant
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|old_constant
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|llvm_function
argument_list|,
name|FunctionValueCache
operator|&
name|value_maker
argument_list|,
name|FunctionValueCache
operator|&
name|entry_instruction_finder
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|&
name|error_stream
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Construct a reference to m_reloc_placeholder with a given type
end_comment

begin_comment
comment|/// and offset.  This typically happens after inserting data into
end_comment

begin_comment
comment|/// m_data_allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] type
end_comment

begin_comment
comment|///     The type of the value being loaded.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] offset
end_comment

begin_comment
comment|///     The offset of the value from the base of m_data_allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The Constant for the reference, usually a ConstantExpr.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|BuildRelocation
argument_list|(
argument|llvm::Type *type
argument_list|,
argument|uint64_t offset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Commit the allocation in m_data_allocator and use its final
end_comment

begin_comment
comment|/// location to replace m_reloc_placeholder.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] module
end_comment

begin_comment
comment|///     The module that m_data_allocator resides in
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     True on success; false otherwise
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|bool
name|CompleteDataAllocation
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_IRForTarget_h_
end_comment

end_unit

