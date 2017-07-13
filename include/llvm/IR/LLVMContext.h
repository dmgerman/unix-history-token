begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/LLVMContext.h - Class for managing "global" state ---*- C++ -*-===//
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
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Options.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DiagnosticInfo
decl_stmt|;
enum_decl|enum
name|DiagnosticSeverity
enum_decl|:
name|char
enum_decl|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContextImpl
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|OptBisect
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
name|SMDiagnostic
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|namespace
name|yaml
block|{
name|class
name|Output
decl_stmt|;
block|}
comment|// end namespace yaml
name|namespace
name|SyncScope
block|{
typedef|typedef
name|uint8_t
name|ID
typedef|;
comment|/// Known synchronization scope IDs, which always have the same value.  All
comment|/// synchronization scope IDs that LLVM has special knowledge of are listed
comment|/// here.  Additionally, this scheme allows LLVM to efficiently check for
comment|/// specific synchronization scope ID without comparing strings.
enum|enum
block|{
comment|/// Synchronized with respect to signal handlers executing in the same thread.
name|SingleThread
init|=
literal|0
block|,
comment|/// Synchronized with respect to all concurrently executing threads.
name|System
init|=
literal|1
block|}
enum|;
block|}
comment|// end namespace SyncScope
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
name|LLVMContext
argument_list|(
name|LLVMContext
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|LLVMContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LLVMContext
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
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
block|,
comment|// "nonnull"
name|MD_dereferenceable
init|=
literal|12
block|,
comment|// "dereferenceable"
name|MD_dereferenceable_or_null
init|=
literal|13
block|,
comment|// "dereferenceable_or_null"
name|MD_make_implicit
init|=
literal|14
block|,
comment|// "make.implicit"
name|MD_unpredictable
init|=
literal|15
block|,
comment|// "unpredictable"
name|MD_invariant_group
init|=
literal|16
block|,
comment|// "invariant.group"
name|MD_align
init|=
literal|17
block|,
comment|// "align"
name|MD_loop
init|=
literal|18
block|,
comment|// "llvm.loop"
name|MD_type
init|=
literal|19
block|,
comment|// "type"
name|MD_section_prefix
init|=
literal|20
block|,
comment|// "section_prefix"
name|MD_absolute_symbol
init|=
literal|21
block|,
comment|// "absolute_symbol"
name|MD_associated
init|=
literal|22
block|,
comment|// "associated"
block|}
enum|;
comment|/// Known operand bundle tag IDs, which always have the same value.  All
comment|/// operand bundle tags that LLVM has special knowledge of are listed here.
comment|/// Additionally, this scheme allows LLVM to efficiently check for specific
comment|/// operand bundle tags without comparing strings.
enum|enum
block|{
name|OB_deopt
init|=
literal|0
block|,
comment|// "deopt"
name|OB_funclet
init|=
literal|1
block|,
comment|// "funclet"
name|OB_gc_transition
init|=
literal|2
block|,
comment|// "gc-transition"
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
comment|/// getOperandBundleTags - Populate client supplied SmallVector with the
comment|/// bundle tags registered in this LLVMContext.  The bundle tags are ordered
comment|/// by increasing bundle IDs.
comment|/// \see LLVMContext::getOperandBundleTagID
name|void
name|getOperandBundleTags
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
comment|/// getOperandBundleTagID - Maps a bundle tag to an integer ID.  Every bundle
comment|/// tag registered with an LLVMContext has an unique ID.
name|uint32_t
name|getOperandBundleTagID
argument_list|(
name|StringRef
name|Tag
argument_list|)
decl|const
decl_stmt|;
comment|/// getOrInsertSyncScopeID - Maps synchronization scope name to
comment|/// synchronization scope ID.  Every synchronization scope registered with
comment|/// LLVMContext has unique ID except pre-defined ones.
name|SyncScope
operator|::
name|ID
name|getOrInsertSyncScopeID
argument_list|(
argument|StringRef SSN
argument_list|)
expr_stmt|;
comment|/// getSyncScopeNames - Populates client supplied SmallVector with
comment|/// synchronization scope names registered with LLVMContext.  Synchronization
comment|/// scope names are ordered by increasing synchronization scope IDs.
name|void
name|getSyncScopeNames
argument_list|(
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|SSNs
argument_list|)
decl|const
decl_stmt|;
comment|/// Define the GC for a function
name|void
name|setGC
argument_list|(
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
name|std
operator|::
name|string
name|GCName
argument_list|)
decl_stmt|;
comment|/// Return the GC for a function
specifier|const
name|std
operator|::
name|string
operator|&
name|getGC
argument_list|(
specifier|const
name|Function
operator|&
name|Fn
argument_list|)
expr_stmt|;
comment|/// Remove the GC for a function
name|void
name|deleteGC
parameter_list|(
specifier|const
name|Function
modifier|&
name|Fn
parameter_list|)
function_decl|;
comment|/// Return true if the Context runtime configuration is set to discard all
comment|/// value names. When true, only GlobalValue names will be available in the
comment|/// IR.
name|bool
name|shouldDiscardValueNames
argument_list|()
specifier|const
expr_stmt|;
comment|/// Set the Context runtime configuration to discard all value name (but
comment|/// GlobalValue). Clients can use this flag to save memory and runtime,
comment|/// especially in release mode.
name|void
name|setDiscardValueNames
parameter_list|(
name|bool
name|Discard
parameter_list|)
function_decl|;
comment|/// Whether there is a string map for uniquing debug info
comment|/// identifiers across the context.  Off by default.
name|bool
name|isODRUniquingDebugTypes
argument_list|()
specifier|const
expr_stmt|;
name|void
name|enableDebugTypeODRUniquing
parameter_list|()
function_decl|;
name|void
name|disableDebugTypeODRUniquing
parameter_list|()
function_decl|;
name|using
name|InlineAsmDiagHandlerTy
init|=
name|void
argument_list|(
argument|*
argument_list|)
operator|(
specifier|const
name|SMDiagnostic
operator|&
expr|,
name|void
operator|*
name|Context
expr|,
name|unsigned
name|LocCookie
operator|)
decl_stmt|;
comment|/// Defines the type of a diagnostic handler.
comment|/// \see LLVMContext::setDiagnosticHandler.
comment|/// \see LLVMContext::diagnose.
name|using
name|DiagnosticHandlerTy
init|=
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|DiagnosticInfo
operator|&
name|DI
argument_list|,
name|void
operator|*
name|Context
argument_list|)
decl_stmt|;
comment|/// Defines the type of a yield callback.
comment|/// \see LLVMContext::setYieldCallback.
name|using
name|YieldCallbackTy
init|=
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|LLVMContext
operator|*
name|Context
argument_list|,
name|void
operator|*
name|OpaqueHandle
argument_list|)
decl_stmt|;
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
comment|/// \brief Return if a code hotness metric should be included in optimization
comment|/// diagnostics.
name|bool
name|getDiagnosticsHotnessRequested
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Set if a code hotness metric should be included in optimization
comment|/// diagnostics.
name|void
name|setDiagnosticsHotnessRequested
parameter_list|(
name|bool
name|Requested
parameter_list|)
function_decl|;
comment|/// \brief Return the minimum hotness value a diagnostic would need in order
comment|/// to be included in optimization diagnostics. If there is no minimum, this
comment|/// returns None.
name|uint64_t
name|getDiagnosticsHotnessThreshold
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Set the minimum hotness value a diagnostic needs in order to be
comment|/// included in optimization diagnostics.
name|void
name|setDiagnosticsHotnessThreshold
parameter_list|(
name|uint64_t
name|Threshold
parameter_list|)
function_decl|;
comment|/// \brief Return the YAML file used by the backend to save optimization
comment|/// diagnostics.  If null, diagnostics are not saved in a file but only
comment|/// emitted via the diagnostic handler.
name|yaml
operator|::
name|Output
operator|*
name|getDiagnosticsOutputFile
argument_list|()
expr_stmt|;
comment|/// Set the diagnostics output file used for optimization diagnostics.
comment|///
comment|/// By default or if invoked with null, diagnostics are not saved in a file
comment|/// but only emitted via the diagnostic handler.  Even if an output file is
comment|/// set, the handler is invoked for each diagnostic message.
name|void
name|setDiagnosticsOutputFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|yaml
operator|::
name|Output
operator|>
name|F
argument_list|)
decl_stmt|;
comment|/// \brief Get the prefix that should be printed in front of a diagnostic of
comment|///        the given \p Severity
specifier|static
specifier|const
name|char
modifier|*
name|getDiagnosticMessagePrefix
parameter_list|(
name|DiagnosticSeverity
name|Severity
parameter_list|)
function_decl|;
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
comment|/// \brief Access the object which manages optimization bisection for failure
comment|/// analysis.
name|OptBisect
modifier|&
name|getOptBisect
parameter_list|()
function_decl|;
name|private
label|:
comment|// Module needs access to the add/removeModule methods.
name|friend
name|class
name|Module
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
block|}
empty_stmt|;
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

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_LLVMCONTEXT_H
end_comment

end_unit

