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
name|LLVM_BITCODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_H
end_define

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
name|Module
decl_stmt|;
name|class
name|ModuleProvider
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|BitstreamWriter
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// getBitcodeModuleProvider - Read the header of the specified bitcode buffer
comment|/// and prepare for lazy deserialization of function bodies.  If successful,
comment|/// this takes ownership of 'buffer' and returns a non-null pointer.  On
comment|/// error, this returns null, *does not* take ownership of Buffer, and fills
comment|/// in *ErrMsg with an error description if ErrMsg is non-null.
name|ModuleProvider
modifier|*
name|getBitcodeModuleProvider
argument_list|(
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// ParseBitcodeFile - Read the specified bitcode file, returning the module.
comment|/// If an error occurs, this returns null and fills in *ErrMsg if it is
comment|/// non-null.  This method *never* takes ownership of Buffer.
name|Module
modifier|*
name|ParseBitcodeFile
argument_list|(
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// WriteBitcodeToFile - Write the specified module to the specified
comment|/// raw output stream.
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
parameter_list|)
function_decl|;
comment|/// WriteBitcodeToStream - Write the specified module to the specified
comment|/// raw output stream.
name|void
name|WriteBitcodeToStream
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|,
name|BitstreamWriter
modifier|&
name|Stream
parameter_list|)
function_decl|;
comment|/// createBitcodeWriterPass - Create and return a pass that writes the module
comment|/// to the specified ostream.
name|ModulePass
modifier|*
name|createBitcodeWriterPass
parameter_list|(
name|raw_ostream
modifier|&
name|Str
parameter_list|)
function_decl|;
comment|/// isBitcodeWrapper - Return true if the given bytes are the magic bytes
comment|/// for an LLVM IR bitcode wrapper.
comment|///
specifier|static
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
specifier|static
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
specifier|static
name|bool
specifier|inline
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
specifier|static
specifier|inline
name|bool
name|SkipBitcodeWrapperHeader
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|&
name|BufPtr
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|&
name|BufEnd
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
operator|(
name|BufPtr
index|[
name|OffsetField
index|]
operator||
operator|(
name|BufPtr
index|[
name|OffsetField
operator|+
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
name|BufPtr
index|[
name|OffsetField
operator|+
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|BufPtr
index|[
name|OffsetField
operator|+
literal|3
index|]
operator|<<
literal|24
operator|)
operator|)
decl_stmt|;
name|unsigned
name|Size
init|=
operator|(
name|BufPtr
index|[
name|SizeField
index|]
operator||
operator|(
name|BufPtr
index|[
name|SizeField
operator|+
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
name|BufPtr
index|[
name|SizeField
operator|+
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|BufPtr
index|[
name|SizeField
operator|+
literal|3
index|]
operator|<<
literal|24
operator|)
operator|)
decl_stmt|;
comment|// Verify that Offset+Size fits in the file.
if|if
condition|(
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
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

