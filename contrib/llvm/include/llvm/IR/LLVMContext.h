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
file|"llvm-c/Core.h"
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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
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
comment|// "invariant.load"
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
literal|0
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

