begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/LLVMContext.h - Class for managing "global" state --*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares LLVMContext, a container of "global" state in LLVM, such
end_comment

begin_comment
comment|// as the global type and constant uniquing tables.
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
name|LLVM_IR_LLVMCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_LLVMCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Options.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContextImpl
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|SMDiagnostic
decl_stmt|;
name|class
name|DiagnosticInfo
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|DebugLoc
decl_stmt|;
comment|/// This is an important class for using LLVM in a threaded context.  It
comment|/// (opaquely) owns and manages the core "global" data of LLVM's core
comment|/// infrastructure, including the type and constant uniquing tables.
comment|/// LLVMContext itself provides no locking guarantees, so you should be careful
comment|/// to have one context per thread.
name|class
name|LLVMContext
block|{
name|public
label|:
name|LLVMContextImpl
modifier|*
specifier|const
name|pImpl
decl_stmt|;
name|LLVMContext
argument_list|()
expr_stmt|;
operator|~
name|LLVMContext
argument_list|()
expr_stmt|;
comment|// Pinned metadata names, which always have the same value.  This is a
comment|// compile-time performance optimization, not a correctness optimization.
enum|enum
block|{
name|MD_dbg
init|=
literal|0
block|,
comment|// "dbg"
name|MD_tbaa
init|=
literal|1
block|,
comment|// "tbaa"
name|MD_prof
init|=
literal|2
block|,
comment|// "prof"
name|MD_fpmath
init|=
literal|3
block|,
comment|// "fpmath"
name|MD_range
init|=
literal|4
block|,
comment|// "range"
name|MD_tbaa_struct
init|=
literal|5
block|,
comment|// "tbaa.struct"
name|MD_invariant_load
init|=
literal|6
block|,
comment|// "invariant.load"
name|MD_alias_scope
init|=
literal|7
block|,
comment|// "alias.scope"
name|MD_noalias
init|=
literal|8
block|,
comment|// "noalias",
name|MD_nontemporal
init|=
literal|9
block|,
comment|// "nontemporal"
name|MD_mem_parallel_loop_access
init|=
literal|10
block|,
comment|// "llvm.mem.parallel_loop_access"
name|MD_nonnull
init|=
literal|11
comment|// "nonnull"
block|}
enum|;
comment|/// getMDKindID - Return a unique non-zero ID for the specified metadata kind.
comment|/// This ID is uniqued across modules in the current LLVMContext.
name|unsigned
name|getMDKindID
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// getMDKindNames - Populate client supplied SmallVector with the name for
comment|/// custom metadata IDs registered in this LLVMContext.
name|void
name|getMDKindNames
argument_list|(
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|InlineAsmDiagHandlerTy
function_decl|)
parameter_list|(
specifier|const
name|SMDiagnostic
modifier|&
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|unsigned
name|LocCookie
parameter_list|)
function_decl|;
comment|/// Defines the type of a diagnostic handler.
comment|/// \see LLVMContext::setDiagnosticHandler.
comment|/// \see LLVMContext::diagnose.
typedef|typedef
name|void
function_decl|(
modifier|*
name|DiagnosticHandlerTy
function_decl|)
parameter_list|(
specifier|const
name|DiagnosticInfo
modifier|&
name|DI
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
comment|/// Defines the type of a yield callback.
comment|/// \see LLVMContext::setYieldCallback.
typedef|typedef
name|void
function_decl|(
modifier|*
name|YieldCallbackTy
function_decl|)
parameter_list|(
name|LLVMContext
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
name|OpaqueHandle
parameter_list|)
function_decl|;
comment|/// setInlineAsmDiagnosticHandler - This method sets a handler that is invoked
comment|/// when problems with inline asm are detected by the backend.  The first
comment|/// argument is a function pointer and the second is a context pointer that
comment|/// gets passed into the DiagHandler.
comment|///
comment|/// LLVMContext doesn't take ownership or interpret either of these
comment|/// pointers.
name|void
name|setInlineAsmDiagnosticHandler
parameter_list|(
name|InlineAsmDiagHandlerTy
name|DiagHandler
parameter_list|,
name|void
modifier|*
name|DiagContext
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// getInlineAsmDiagnosticHandler - Return the diagnostic handler set by
comment|/// setInlineAsmDiagnosticHandler.
name|InlineAsmDiagHandlerTy
name|getInlineAsmDiagnosticHandler
argument_list|()
specifier|const
expr_stmt|;
comment|/// getInlineAsmDiagnosticContext - Return the diagnostic context set by
comment|/// setInlineAsmDiagnosticHandler.
name|void
operator|*
name|getInlineAsmDiagnosticContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// setDiagnosticHandler - This method sets a handler that is invoked
comment|/// when the backend needs to report anything to the user.  The first
comment|/// argument is a function pointer and the second is a context pointer that
comment|/// gets passed into the DiagHandler.  The third argument should be set to
comment|/// true if the handler only expects enabled diagnostics.
comment|///
comment|/// LLVMContext doesn't take ownership or interpret either of these
comment|/// pointers.
name|void
name|setDiagnosticHandler
parameter_list|(
name|DiagnosticHandlerTy
name|DiagHandler
parameter_list|,
name|void
modifier|*
name|DiagContext
init|=
name|nullptr
parameter_list|,
name|bool
name|RespectFilters
init|=
name|false
parameter_list|)
function_decl|;
comment|/// getDiagnosticHandler - Return the diagnostic handler set by
comment|/// setDiagnosticHandler.
name|DiagnosticHandlerTy
name|getDiagnosticHandler
argument_list|()
specifier|const
expr_stmt|;
comment|/// getDiagnosticContext - Return the diagnostic context set by
comment|/// setDiagnosticContext.
name|void
operator|*
name|getDiagnosticContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Report a message to the currently installed diagnostic handler.
comment|///
comment|/// This function returns, in particular in the case of error reporting
comment|/// (DI.Severity == \a DS_Error), so the caller should leave the compilation
comment|/// process in a self-consistent state, even though the generated code
comment|/// need not be correct.
comment|///
comment|/// The diagnostic message will be implicitly prefixed with a severity keyword
comment|/// according to \p DI.getSeverity(), i.e., "error: " for \a DS_Error,
comment|/// "warning: " for \a DS_Warning, and "note: " for \a DS_Note.
name|void
name|diagnose
parameter_list|(
specifier|const
name|DiagnosticInfo
modifier|&
name|DI
parameter_list|)
function_decl|;
comment|/// \brief Registers a yield callback with the given context.
comment|///
comment|/// The yield callback function may be called by LLVM to transfer control back
comment|/// to the client that invoked the LLVM compilation. This can be used to yield
comment|/// control of the thread, or perform periodic work needed by the client.
comment|/// There is no guaranteed frequency at which callbacks must occur; in fact,
comment|/// the client is not guaranteed to ever receive this callback. It is at the
comment|/// sole discretion of LLVM to do so and only if it can guarantee that
comment|/// suspending the thread won't block any forward progress in other LLVM
comment|/// contexts in the same process.
comment|///
comment|/// At a suspend point, the state of the current LLVM context is intentionally
comment|/// undefined. No assumptions about it can or should be made. Only LLVM
comment|/// context API calls that explicitly state that they can be used during a
comment|/// yield callback are allowed to be used. Any other API calls into the
comment|/// context are not supported until the yield callback function returns
comment|/// control to LLVM. Other LLVM contexts are unaffected by this restriction.
name|void
name|setYieldCallback
parameter_list|(
name|YieldCallbackTy
name|Callback
parameter_list|,
name|void
modifier|*
name|OpaqueHandle
parameter_list|)
function_decl|;
comment|/// \brief Calls the yield callback (if applicable).
comment|///
comment|/// This transfers control of the current thread back to the client, which may
comment|/// suspend the current thread. Only call this method when LLVM doesn't hold
comment|/// any global mutex or cannot block the execution in another LLVM context.
name|void
name|yield
parameter_list|()
function_decl|;
comment|/// emitError - Emit an error message to the currently installed error handler
comment|/// with optional location information.  This function returns, so code should
comment|/// be prepared to drop the erroneous construct on the floor and "not crash".
comment|/// The generated code need not be correct.  The error message will be
comment|/// implicitly prefixed with "error: " and should not end with a ".".
name|void
name|emitError
parameter_list|(
name|unsigned
name|LocCookie
parameter_list|,
specifier|const
name|Twine
modifier|&
name|ErrorStr
parameter_list|)
function_decl|;
name|void
name|emitError
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Twine
modifier|&
name|ErrorStr
parameter_list|)
function_decl|;
name|void
name|emitError
parameter_list|(
specifier|const
name|Twine
modifier|&
name|ErrorStr
parameter_list|)
function_decl|;
comment|/// \brief Query for a debug option's value.
comment|///
comment|/// This function returns typed data populated from command line parsing.
name|template
operator|<
name|typename
name|ValT
operator|,
name|typename
name|Base
operator|,
name|ValT
argument_list|(
name|Base
operator|::
operator|*
name|Mem
argument_list|)
operator|>
name|ValT
name|getOption
argument_list|()
specifier|const
block|{
return|return
name|OptionRegistry
operator|::
name|instance
argument_list|()
operator|.
name|template
name|get
operator|<
name|ValT
operator|,
name|Base
operator|,
name|Mem
operator|>
operator|(
operator|)
return|;
block|}
name|private
label|:
name|LLVMContext
argument_list|(
argument|LLVMContext&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
name|LLVMContext
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
comment|/// addModule - Register a module as being instantiated in this context.  If
comment|/// the context is deleted, the module will be deleted as well.
name|void
name|addModule
parameter_list|(
name|Module
modifier|*
parameter_list|)
function_decl|;
comment|/// removeModule - Unregister a module from this context.
name|void
name|removeModule
parameter_list|(
name|Module
modifier|*
parameter_list|)
function_decl|;
comment|// Module needs access to the add/removeModule methods.
name|friend
name|class
name|Module
decl_stmt|;
block|}
empty_stmt|;
comment|/// getGlobalContext - Returns a global context.  This is for LLVM clients that
comment|/// only care about operating on a single thread.
specifier|extern
name|LLVMContext
modifier|&
name|getGlobalContext
parameter_list|()
function_decl|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|LLVMContext
argument_list|,
argument|LLVMContextRef
argument_list|)
comment|/* Specialized opaque context conversions.  */
specifier|inline
name|LLVMContext
modifier|*
modifier|*
name|unwrap
parameter_list|(
name|LLVMContextRef
modifier|*
name|Tys
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMContext
operator|*
operator|*
operator|>
operator|(
name|Tys
operator|)
return|;
block|}
specifier|inline
name|LLVMContextRef
modifier|*
name|wrap
parameter_list|(
specifier|const
name|LLVMContext
modifier|*
modifier|*
name|Tys
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMContextRef
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|LLVMContext
operator|*
operator|*
operator|>
operator|(
name|Tys
operator|)
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

