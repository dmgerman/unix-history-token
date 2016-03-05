begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FunctionIndexObjectFile.h - Function index file implementation -----===//
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
comment|// This file declares the FunctionIndexObjectFile template class.
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
name|LLVM_OBJECT_FUNCTIONINDEXOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_FUNCTIONINDEXOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/SymbolicFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionInfoIndex
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
comment|/// This class is used to read just the function summary index related
comment|/// sections out of the given object (which may contain a single module's
comment|/// bitcode or be a combined index bitcode file). It builds a FunctionInfoIndex
comment|/// object.
name|class
name|FunctionIndexObjectFile
range|:
name|public
name|SymbolicFile
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionInfoIndex
operator|>
name|Index
block|;
name|public
operator|:
name|FunctionIndexObjectFile
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|std::unique_ptr<FunctionInfoIndex> I
argument_list|)
block|;
operator|~
name|FunctionIndexObjectFile
argument_list|()
name|override
block|;
comment|// TODO: Walk through FunctionMap entries for function symbols.
comment|// However, currently these interfaces are not used by any consumers.
name|void
name|moveSymbolNext
argument_list|(
argument|DataRefImpl&Symb
argument_list|)
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"not implemented"
argument_list|)
block|;   }
name|std
operator|::
name|error_code
name|printSymbolName
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"not implemented"
argument_list|)
block|;
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
name|uint32_t
name|getSymbolFlags
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"not implemented"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|basic_symbol_iterator
name|symbol_begin_impl
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"not implemented"
argument_list|)
block|;
return|return
name|basic_symbol_iterator
argument_list|(
name|BasicSymbolRef
argument_list|()
argument_list|)
return|;
block|}
name|basic_symbol_iterator
name|symbol_end_impl
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"not implemented"
argument_list|)
block|;
return|return
name|basic_symbol_iterator
argument_list|(
name|BasicSymbolRef
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|FunctionInfoIndex
operator|&
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|FunctionIndexObjectFile
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getIndex
argument_list|()
return|;
block|}
name|FunctionInfoIndex
operator|&
name|getIndex
argument_list|()
block|{
return|return
operator|*
name|Index
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionInfoIndex
operator|>
name|takeIndex
argument_list|()
block|;
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Binary *v
argument_list|)
block|{
return|return
name|v
operator|->
name|isFunctionIndex
argument_list|()
return|;
block|}
comment|/// \brief Finds and returns bitcode embedded in the given object file, or an
comment|/// error code if not found.
specifier|static
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|findBitcodeInObject
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|Obj
argument_list|)
block|;
comment|/// \brief Finds and returns bitcode in the given memory buffer (which may
comment|/// be either a bitcode file or a native object file with embedded bitcode),
comment|/// or an error code if not found.
specifier|static
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|findBitcodeInMemBuffer
argument_list|(
argument|MemoryBufferRef Object
argument_list|)
block|;
comment|/// \brief Looks for function summary in the given memory buffer,
comment|/// returns true if found, else false.
specifier|static
name|bool
name|hasFunctionSummaryInMemBuffer
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|DiagnosticHandlerFunction DiagnosticHandler
argument_list|)
block|;
comment|/// \brief Parse function index in the given memory buffer.
comment|/// Return new FunctionIndexObjectFile instance containing parsed function
comment|/// summary/index.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionIndexObjectFile
operator|>>
name|create
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|DiagnosticHandlerFunction DiagnosticHandler
argument_list|,
argument|bool IsLazy = false
argument_list|)
block|;
comment|/// \brief Parse the function summary information for function with the
comment|/// given name out of the given buffer. Parsed information is
comment|/// stored on the index object saved in this object.
name|std
operator|::
name|error_code
name|findFunctionSummaryInMemBuffer
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|DiagnosticHandlerFunction DiagnosticHandler
argument_list|,
argument|StringRef FunctionName
argument_list|)
block|; }
decl_stmt|;
block|}
comment|/// Parse the function index out of an IR file and return the function
comment|/// index object if found, or nullptr if not.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionInfoIndex
operator|>>
name|getFunctionIndexForFile
argument_list|(
argument|StringRef Path
argument_list|,
argument|DiagnosticHandlerFunction DiagnosticHandler
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

