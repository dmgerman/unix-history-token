begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_symbolizer_internal.h -------------------------*- C++ -*-===//
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
comment|// Header for internal classes and functions to be used by implementations of
end_comment

begin_comment
comment|// symbolizers.
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
name|SANITIZER_SYMBOLIZER_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SYMBOLIZER_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_symbolizer.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// Parsing helpers, 'str' is searched for delimiter(s) and a string or uptr
comment|// is extracted. When extracting a string, a newly allocated (using
comment|// InternalAlloc) and null-terminataed buffer is returned. They return a pointer
comment|// to the next characted after the found delimiter.
specifier|const
name|char
modifier|*
name|ExtractToken
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|delims
parameter_list|,
name|char
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ExtractInt
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|delims
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ExtractUptr
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|delims
parameter_list|,
name|uptr
modifier|*
name|result
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ExtractTokenUpToDelimiter
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|delimiter
parameter_list|,
name|char
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|DemangleCXXABI
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|// SymbolizerTool is an interface that is implemented by individual "tools"
comment|// that can perform symbolication (external llvm-symbolizer, libbacktrace,
comment|// Windows DbgHelp symbolizer, etc.).
name|class
name|SymbolizerTool
block|{
name|public
label|:
comment|// The main |Symbolizer| class implements a "fallback chain" of symbolizer
comment|// tools. In a request to symbolize an address, if one tool returns false,
comment|// the next tool in the chain will be tried.
name|SymbolizerTool
modifier|*
name|next
decl_stmt|;
name|SymbolizerTool
argument_list|()
operator|:
name|next
argument_list|(
argument|nullptr
argument_list|)
block|{ }
comment|// Can't declare pure virtual functions in sanitizer runtimes:
comment|// __cxa_pure_virtual might be unavailable.
comment|// The |stack| parameter is inout. It is pre-filled with the address,
comment|// module base and module offset values and is to be used to construct
comment|// other stack frames.
name|virtual
name|bool
name|SymbolizePC
argument_list|(
argument|uptr addr
argument_list|,
argument|SymbolizedStack *stack
argument_list|)
block|{
name|UNIMPLEMENTED
argument_list|()
block|;   }
comment|// The |info| parameter is inout. It is pre-filled with the module base
comment|// and module offset values.
name|virtual
name|bool
name|SymbolizeData
argument_list|(
argument|uptr addr
argument_list|,
argument|DataInfo *info
argument_list|)
block|{
name|UNIMPLEMENTED
argument_list|()
block|;   }
name|virtual
name|void
name|Flush
argument_list|()
block|{}
comment|// Return nullptr to fallback to the default platform-specific demangler.
name|virtual
specifier|const
name|char
operator|*
name|Demangle
argument_list|(
argument|const char *name
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
block|}
empty_stmt|;
comment|// SymbolizerProcess encapsulates communication between the tool and
comment|// external symbolizer program, running in a different subprocess.
comment|// SymbolizerProcess may not be used from two threads simultaneously.
name|class
name|SymbolizerProcess
block|{
name|public
label|:
name|explicit
name|SymbolizerProcess
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|use_forkpty
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|SendCommand
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
name|protected
label|:
name|virtual
name|bool
name|ReachedEndOfOutput
argument_list|(
specifier|const
name|char
operator|*
name|buffer
argument_list|,
name|uptr
name|length
argument_list|)
decl|const
block|{
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
comment|/// The maximum number of arguments required to invoke a tool process.
enum|enum
block|{
name|kArgVMax
init|=
literal|6
block|}
enum|;
comment|/// Fill in an argv array to invoke the child process.
name|virtual
name|void
name|GetArgV
argument_list|(
specifier|const
name|char
operator|*
name|path_to_binary
argument_list|,
specifier|const
name|char
operator|*
operator|(
operator|&
name|argv
operator|)
index|[
name|kArgVMax
index|]
argument_list|)
decl|const
block|{
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
block|}
name|virtual
name|bool
name|ReadFromSymbolizer
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|uptr
name|max_length
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|Restart
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|SendCommandImpl
parameter_list|(
specifier|const
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
name|bool
name|WriteToSymbolizer
parameter_list|(
specifier|const
name|char
modifier|*
name|buffer
parameter_list|,
name|uptr
name|length
parameter_list|)
function_decl|;
name|bool
name|StartSymbolizerSubprocess
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|path_
decl_stmt|;
name|fd_t
name|input_fd_
decl_stmt|;
name|fd_t
name|output_fd_
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kBufferSize
init|=
literal|16
operator|*
literal|1024
decl_stmt|;
name|char
name|buffer_
index|[
name|kBufferSize
index|]
decl_stmt|;
specifier|static
specifier|const
name|uptr
name|kMaxTimesRestarted
init|=
literal|5
decl_stmt|;
specifier|static
specifier|const
name|int
name|kSymbolizerStartupTimeMillis
init|=
literal|10
decl_stmt|;
name|uptr
name|times_restarted_
decl_stmt|;
name|bool
name|failed_to_start_
decl_stmt|;
name|bool
name|reported_invalid_path_
decl_stmt|;
name|bool
name|use_forkpty_
decl_stmt|;
block|}
empty_stmt|;
name|class
name|LLVMSymbolizerProcess
decl_stmt|;
comment|// This tool invokes llvm-symbolizer in a subprocess. It should be as portable
comment|// as the llvm-symbolizer tool is.
name|class
name|LLVMSymbolizer
range|:
name|public
name|SymbolizerTool
block|{
name|public
operator|:
name|explicit
name|LLVMSymbolizer
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|LowLevelAllocator
operator|*
name|allocator
argument_list|)
block|;
name|bool
name|SymbolizePC
argument_list|(
argument|uptr addr
argument_list|,
argument|SymbolizedStack *stack
argument_list|)
name|override
block|;
name|bool
name|SymbolizeData
argument_list|(
argument|uptr addr
argument_list|,
argument|DataInfo *info
argument_list|)
name|override
block|;
name|private
operator|:
specifier|const
name|char
operator|*
name|SendCommand
argument_list|(
argument|bool is_data
argument_list|,
argument|const char *module_name
argument_list|,
argument|uptr module_offset
argument_list|)
block|;
name|LLVMSymbolizerProcess
operator|*
name|symbolizer_process_
block|;
specifier|static
specifier|const
name|uptr
name|kBufferSize
operator|=
literal|16
operator|*
literal|1024
block|;
name|char
name|buffer_
index|[
name|kBufferSize
index|]
block|; }
decl_stmt|;
comment|// Parses one or more two-line strings in the following format:
comment|//<function_name>
comment|//<file_name>:<line_number>[:<column_number>]
comment|// Used by LLVMSymbolizer, Addr2LinePool and InternalSymbolizer, since all of
comment|// them use the same output format.  Returns true if any useful debug
comment|// information was found.
name|void
name|ParseSymbolizePCOutput
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|SymbolizedStack
modifier|*
name|res
parameter_list|)
function_decl|;
comment|// Parses a two-line string in the following format:
comment|//<symbol_name>
comment|//<start_address><size>
comment|// Used by LLVMSymbolizer and InternalSymbolizer.
name|void
name|ParseSymbolizeDataOutput
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|DataInfo
modifier|*
name|info
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SYMBOLIZER_INTERNAL_H
end_comment

end_unit

