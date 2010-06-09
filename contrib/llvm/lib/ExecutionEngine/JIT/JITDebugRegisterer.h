begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JITDebugRegisterer.h - Register debug symbols for JIT -------------===//
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
comment|// This file defines a JITDebugRegisterer object that is used by the JIT to
end_comment

begin_comment
comment|// register debug info with debuggers like GDB.
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
name|LLVM_EXECUTION_ENGINE_JIT_DEBUGREGISTERER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTION_ENGINE_JIT_DEBUGREGISTERER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// This must be kept in sync with gdb/gdb/jit.h .
end_comment

begin_extern
extern|extern
literal|"C"
block|{
typedef|typedef
enum|enum
block|{
name|JIT_NOACTION
init|=
literal|0
block|,
name|JIT_REGISTER_FN
block|,
name|JIT_UNREGISTER_FN
block|}
name|jit_actions_t
typedef|;
struct|struct
name|jit_code_entry
block|{
name|struct
name|jit_code_entry
modifier|*
name|next_entry
decl_stmt|;
name|struct
name|jit_code_entry
modifier|*
name|prev_entry
decl_stmt|;
specifier|const
name|char
modifier|*
name|symfile_addr
decl_stmt|;
name|uint64_t
name|symfile_size
decl_stmt|;
block|}
struct|;
struct|struct
name|jit_descriptor
block|{
name|uint32_t
name|version
decl_stmt|;
comment|// This should be jit_actions_t, but we want to be specific about the
comment|// bit-width.
name|uint32_t
name|action_flag
decl_stmt|;
name|struct
name|jit_code_entry
modifier|*
name|relevant_entry
decl_stmt|;
name|struct
name|jit_code_entry
modifier|*
name|first_entry
decl_stmt|;
block|}
struct|;
block|}
end_extern

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ELFSection
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// This class encapsulates information we want to send to the debugger.
comment|///
struct|struct
name|DebugInfo
block|{
name|uint8_t
modifier|*
name|FnStart
decl_stmt|;
name|uint8_t
modifier|*
name|FnEnd
decl_stmt|;
name|uint8_t
modifier|*
name|EhStart
decl_stmt|;
name|uint8_t
modifier|*
name|EhEnd
decl_stmt|;
name|DebugInfo
argument_list|()
operator|:
name|FnStart
argument_list|(
literal|0
argument_list|)
operator|,
name|FnEnd
argument_list|(
literal|0
argument_list|)
operator|,
name|EhStart
argument_list|(
literal|0
argument_list|)
operator|,
name|EhEnd
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|jit_code_entry
operator|*
operator|>
expr|>
name|RegisteredFunctionsMap
expr_stmt|;
comment|/// This class registers debug info for JITed code with an attached debugger.
comment|/// Without proper debug info, GDB can't do things like source level debugging
comment|/// or even produce a proper stack trace on linux-x86_64.  To use this class,
comment|/// whenever a function is JITed, create a DebugInfo struct and pass it to the
comment|/// RegisterFunction method.  The method will then do whatever is necessary to
comment|/// inform the debugger about the JITed function.
name|class
name|JITDebugRegisterer
block|{
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|/// FnMap - A map of functions that have been registered to the associated
comment|/// temporary files.  Used for cleanup.
name|RegisteredFunctionsMap
name|FnMap
decl_stmt|;
comment|/// MakeELF - Builds the ELF file in memory and returns a std::string that
comment|/// contains the ELF.
name|std
operator|::
name|string
name|MakeELF
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|DebugInfo
operator|&
name|I
argument_list|)
expr_stmt|;
name|public
label|:
name|JITDebugRegisterer
argument_list|(
name|TargetMachine
operator|&
name|tm
argument_list|)
expr_stmt|;
comment|/// ~JITDebugRegisterer - Unregisters all code and frees symbol files.
comment|///
operator|~
name|JITDebugRegisterer
argument_list|()
expr_stmt|;
comment|/// RegisterFunction - Register debug info for the given function with an
comment|/// attached debugger.  Clients must call UnregisterFunction on all
comment|/// registered functions before deleting them to free the associated symbol
comment|/// file and unregister it from the debugger.
name|void
name|RegisterFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
name|DebugInfo
modifier|&
name|I
parameter_list|)
function_decl|;
comment|/// UnregisterFunction - Unregister the debug info for the given function
comment|/// from the debugger and free associated memory.
name|void
name|UnregisterFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|private
label|:
comment|/// UnregisterFunctionInternal - Unregister the debug info for the given
comment|/// function from the debugger and delete any temporary files.  The private
comment|/// version of this method does not remove the function from FnMap so that it
comment|/// can be called while iterating over FnMap.
name|void
name|UnregisterFunctionInternal
argument_list|(
name|RegisteredFunctionsMap
operator|::
name|iterator
name|I
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_EXECUTION_ENGINE_JIT_DEBUGREGISTERER_H
end_comment

end_unit

