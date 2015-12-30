begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Bitcode/ReaderWriter.h - Bitcode reader/writers ----*- C++ -*-===//
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
comment|// This header defines interfaces to read and write LLVM bitcode files/streams.
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
name|LLVM_BITCODE_READERWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_READERWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/FunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
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
name|BitstreamWriter
decl_stmt|;
name|class
name|DataStreamer
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Read the header of the specified bitcode buffer and prepare for lazy
comment|/// deserialization of function bodies. If ShouldLazyLoadMetadata is true,
comment|/// lazily load metadata as well. If successful, this moves Buffer. On
comment|/// error, this *does not* move Buffer.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|getLazyBitcodeModule
argument_list|(
argument|std::unique_ptr<MemoryBuffer>&&Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|bool ShouldLazyLoadMetadata = false
argument_list|)
expr_stmt|;
comment|/// Read the header of the specified stream and prepare for lazy
comment|/// deserialization and streaming of function bodies.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|getStreamedBitcodeModule
argument_list|(
argument|StringRef Name
argument_list|,
argument|std::unique_ptr<DataStreamer> Streamer
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// Read the header of the specified bitcode buffer and extract just the
comment|/// triple information. If successful, this returns a string. On error, this
comment|/// returns "".
name|std
operator|::
name|string
name|getBitcodeTargetTriple
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// Read the header of the specified bitcode buffer and extract just the
comment|/// producer string information. If successful, this returns a string. On
comment|/// error, this returns "".
name|std
operator|::
name|string
name|getBitcodeProducerString
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// Read the specified bitcode file, returning the module.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|parseBitcodeFile
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|)
expr_stmt|;
comment|/// Check if the given bitcode buffer contains a function summary block.
name|bool
name|hasFunctionSummary
parameter_list|(
name|MemoryBufferRef
name|Buffer
parameter_list|,
name|DiagnosticHandlerFunction
name|DiagnosticHandler
parameter_list|)
function_decl|;
comment|/// Parse the specified bitcode buffer, returning the function info index.
comment|/// If IsLazy is true, parse the entire function summary into
comment|/// the index. Otherwise skip the function summary section, and only create
comment|/// an index object with a map from function name to function summary offset.
comment|/// The index is used to perform lazy function summary reading later.
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionInfoIndex
operator|>>
name|getFunctionInfoIndex
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|DiagnosticHandlerFunction DiagnosticHandler
argument_list|,
argument|bool IsLazy = false
argument_list|)
expr_stmt|;
comment|/// This method supports lazy reading of function summary data from the
comment|/// combined index during function importing. When reading the combined index
comment|/// file, getFunctionInfoIndex is first invoked with IsLazy=true.
comment|/// Then this method is called for each function considered for importing,
comment|/// to parse the summary information for the given function name into
comment|/// the index.
name|std
operator|::
name|error_code
name|readFunctionSummary
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|DiagnosticHandlerFunction DiagnosticHandler
argument_list|,
argument|StringRef FunctionName
argument_list|,
argument|std::unique_ptr<FunctionInfoIndex> Index
argument_list|)
expr_stmt|;
comment|/// \brief Write the specified module to the specified raw output stream.
comment|///
comment|/// For streams where it matters, the given stream should be in "binary"
comment|/// mode.
comment|///
comment|/// If \c ShouldPreserveUseListOrder, encode the use-list order for each \a
comment|/// Value in \c M.  These will be reconstructed exactly when \a M is
comment|/// deserialized.
comment|///
comment|/// If \c EmitFunctionSummary, emit the function summary index (currently
comment|/// for use in ThinLTO optimization).
name|void
name|WriteBitcodeToFile
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|,
name|raw_ostream
modifier|&
name|Out
parameter_list|,
name|bool
name|ShouldPreserveUseListOrder
init|=
name|false
parameter_list|,
name|bool
name|EmitFunctionSummary
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Write the specified function summary index to the given raw output stream,
comment|/// where it will be written in a new bitcode block. This is used when
comment|/// writing the combined index file for ThinLTO.
name|void
name|WriteFunctionSummaryToFile
parameter_list|(
specifier|const
name|FunctionInfoIndex
modifier|&
name|Index
parameter_list|,
name|raw_ostream
modifier|&
name|Out
parameter_list|)
function_decl|;
comment|/// isBitcodeWrapper - Return true if the given bytes are the magic bytes
comment|/// for an LLVM IR bitcode wrapper.
comment|///
specifier|inline
name|bool
name|isBitcodeWrapper
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|BufPtr
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|BufEnd
parameter_list|)
block|{
comment|// See if you can find the hidden message in the magic bytes :-).
comment|// (Hint: it's a little-endian encoding.)
return|return
name|BufPtr
operator|!=
name|BufEnd
operator|&&
name|BufPtr
index|[
literal|0
index|]
operator|==
literal|0xDE
operator|&&
name|BufPtr
index|[
literal|1
index|]
operator|==
literal|0xC0
operator|&&
name|BufPtr
index|[
literal|2
index|]
operator|==
literal|0x17
operator|&&
name|BufPtr
index|[
literal|3
index|]
operator|==
literal|0x0B
return|;
block|}
comment|/// isRawBitcode - Return true if the given bytes are the magic bytes for
comment|/// raw LLVM IR bitcode (without a wrapper).
comment|///
specifier|inline
name|bool
name|isRawBitcode
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|BufPtr
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|BufEnd
parameter_list|)
block|{
comment|// These bytes sort of have a hidden message, but it's not in
comment|// little-endian this time, and it's a little redundant.
return|return
name|BufPtr
operator|!=
name|BufEnd
operator|&&
name|BufPtr
index|[
literal|0
index|]
operator|==
literal|'B'
operator|&&
name|BufPtr
index|[
literal|1
index|]
operator|==
literal|'C'
operator|&&
name|BufPtr
index|[
literal|2
index|]
operator|==
literal|0xc0
operator|&&
name|BufPtr
index|[
literal|3
index|]
operator|==
literal|0xde
return|;
block|}
comment|/// isBitcode - Return true if the given bytes are the magic bytes for
comment|/// LLVM IR bitcode, either with or without a wrapper.
comment|///
specifier|inline
name|bool
name|isBitcode
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|BufPtr
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|BufEnd
parameter_list|)
block|{
return|return
name|isBitcodeWrapper
argument_list|(
name|BufPtr
argument_list|,
name|BufEnd
argument_list|)
operator|||
name|isRawBitcode
argument_list|(
name|BufPtr
argument_list|,
name|BufEnd
argument_list|)
return|;
block|}
comment|/// SkipBitcodeWrapperHeader - Some systems wrap bc files with a special
comment|/// header for padding or other reasons.  The format of this header is:
comment|///
comment|/// struct bc_header {
comment|///   uint32_t Magic;         // 0x0B17C0DE
comment|///   uint32_t Version;       // Version, currently always 0.
comment|///   uint32_t BitcodeOffset; // Offset to traditional bitcode file.
comment|///   uint32_t BitcodeSize;   // Size of traditional bitcode file.
comment|///   ... potentially other gunk ...
comment|/// };
comment|///
comment|/// This function is called when we find a file with a matching magic number.
comment|/// In this case, skip down to the subsection of the file that is actually a
comment|/// BC file.
comment|/// If 'VerifyBufferSize' is true, check that the buffer is large enough to
comment|/// contain the whole bitcode file.
specifier|inline
name|bool
name|SkipBitcodeWrapperHeader
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
modifier|&
name|BufPtr
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
modifier|&
name|BufEnd
parameter_list|,
name|bool
name|VerifyBufferSize
parameter_list|)
block|{
enum|enum
block|{
name|KnownHeaderSize
init|=
literal|4
operator|*
literal|4
block|,
comment|// Size of header we read.
name|OffsetField
init|=
literal|2
operator|*
literal|4
block|,
comment|// Offset in bytes to Offset field.
name|SizeField
init|=
literal|3
operator|*
literal|4
comment|// Offset in bytes to Size field.
block|}
enum|;
comment|// Must contain the header!
if|if
condition|(
name|BufEnd
operator|-
name|BufPtr
operator|<
name|KnownHeaderSize
condition|)
return|return
name|true
return|;
name|unsigned
name|Offset
init|=
name|support
operator|::
name|endian
operator|::
name|read32le
argument_list|(
operator|&
name|BufPtr
index|[
name|OffsetField
index|]
argument_list|)
decl_stmt|;
name|unsigned
name|Size
init|=
name|support
operator|::
name|endian
operator|::
name|read32le
argument_list|(
operator|&
name|BufPtr
index|[
name|SizeField
index|]
argument_list|)
decl_stmt|;
comment|// Verify that Offset+Size fits in the file.
if|if
condition|(
name|VerifyBufferSize
operator|&&
name|Offset
operator|+
name|Size
operator|>
name|unsigned
argument_list|(
name|BufEnd
operator|-
name|BufPtr
argument_list|)
condition|)
return|return
name|true
return|;
name|BufPtr
operator|+=
name|Offset
expr_stmt|;
name|BufEnd
operator|=
name|BufPtr
operator|+
name|Size
expr_stmt|;
return|return
name|false
return|;
block|}
specifier|const
name|std
operator|::
name|error_category
operator|&
name|BitcodeErrorCategory
argument_list|()
expr_stmt|;
name|enum
name|class
name|BitcodeError
block|{
name|InvalidBitcodeSignature
operator|=
literal|1
operator|,
name|CorruptedBitcode
block|}
empty_stmt|;
specifier|inline
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|BitcodeError E
argument_list|)
block|{
return|return
name|std
operator|::
name|error_code
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|E
operator|)
argument_list|,
name|BitcodeErrorCategory
argument_list|()
argument_list|)
return|;
block|}
name|class
name|BitcodeDiagnosticInfo
range|:
name|public
name|DiagnosticInfo
block|{
specifier|const
name|Twine
operator|&
name|Msg
block|;
name|std
operator|::
name|error_code
name|EC
block|;
name|public
operator|:
name|BitcodeDiagnosticInfo
argument_list|(
argument|std::error_code EC
argument_list|,
argument|DiagnosticSeverity Severity
argument_list|,
argument|const Twine&Msg
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|error_code
name|getError
argument_list|()
specifier|const
block|{
return|return
name|EC
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_Bitcode
return|;
block|}
expr|}
block|;  }
comment|// End llvm namespace
name|namespace
name|std
block|{
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|llvm
operator|::
name|BitcodeError
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

