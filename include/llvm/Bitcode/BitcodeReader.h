begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Bitcode/BitcodeReader.h - Bitcode reader ----*- C++ -*-===//
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
comment|// This header defines interfaces to read LLVM bitcode files/streams.
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
name|LLVM_BITCODE_BITCODEREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_BITCODEREADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitCodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|// These functions are for converting Expected/Error values to
comment|// ErrorOr/std::error_code for compatibility with legacy clients. FIXME:
comment|// Remove these functions once no longer needed by the C and libLTO APIs.
name|std
operator|::
name|error_code
name|errorToErrorCodeAndEmitErrors
argument_list|(
argument|LLVMContext&Ctx
argument_list|,
argument|Error Err
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|ErrorOr
operator|<
name|T
operator|>
name|expectedToErrorOrAndEmitErrors
argument_list|(
argument|LLVMContext&Ctx
argument_list|,
argument|Expected<T> Val
argument_list|)
block|{
if|if
condition|(
operator|!
name|Val
condition|)
return|return
name|errorToErrorCodeAndEmitErrors
argument_list|(
name|Ctx
argument_list|,
name|Val
operator|.
name|takeError
argument_list|()
argument_list|)
return|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|Val
argument_list|)
return|;
block|}
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|BitcodeFileContents
struct_decl|;
end_struct_decl

begin_comment
comment|/// Basic information extracted from a bitcode module to be used for LTO.
end_comment

begin_struct
struct|struct
name|BitcodeLTOInfo
block|{
name|bool
name|IsThinLTO
decl_stmt|;
name|bool
name|HasSummary
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Represents a module in a bitcode file.
end_comment

begin_decl_stmt
name|class
name|BitcodeModule
block|{
comment|// This covers the identification (if present) and module blocks.
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Buffer
expr_stmt|;
name|StringRef
name|ModuleIdentifier
decl_stmt|;
comment|// The string table used to interpret this module.
name|StringRef
name|Strtab
decl_stmt|;
comment|// The bitstream location of the IDENTIFICATION_BLOCK.
name|uint64_t
name|IdentificationBit
decl_stmt|;
comment|// The bitstream location of this module's MODULE_BLOCK.
name|uint64_t
name|ModuleBit
decl_stmt|;
name|BitcodeModule
argument_list|(
argument|ArrayRef<uint8_t> Buffer
argument_list|,
argument|StringRef ModuleIdentifier
argument_list|,
argument|uint64_t IdentificationBit
argument_list|,
argument|uint64_t ModuleBit
argument_list|)
block|:
name|Buffer
argument_list|(
name|Buffer
argument_list|)
operator|,
name|ModuleIdentifier
argument_list|(
name|ModuleIdentifier
argument_list|)
operator|,
name|IdentificationBit
argument_list|(
name|IdentificationBit
argument_list|)
operator|,
name|ModuleBit
argument_list|(
argument|ModuleBit
argument_list|)
block|{}
comment|// Calls the ctor.
name|friend
name|Expected
operator|<
name|BitcodeFileContents
operator|>
name|getBitcodeFileContents
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|getModuleImpl
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|bool MaterializeAll
argument_list|,
argument|bool ShouldLazyLoadMetadata
argument_list|,
argument|bool IsImporting
argument_list|)
expr_stmt|;
name|public
label|:
name|StringRef
name|getBuffer
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|Buffer
operator|.
name|begin
argument_list|()
argument_list|,
name|Buffer
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
name|StringRef
name|getStrtab
argument_list|()
specifier|const
block|{
return|return
name|Strtab
return|;
block|}
name|StringRef
name|getModuleIdentifier
argument_list|()
specifier|const
block|{
return|return
name|ModuleIdentifier
return|;
block|}
comment|/// Read the bitcode module and prepare for lazy deserialization of function
comment|/// bodies. If ShouldLazyLoadMetadata is true, lazily load metadata as well.
comment|/// If IsImporting is true, this module is being parsed for ThinLTO
comment|/// importing into another module.
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|getLazyModule
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|bool ShouldLazyLoadMetadata
argument_list|,
argument|bool IsImporting
argument_list|)
expr_stmt|;
comment|/// Read the entire bitcode module and return it.
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|parseModule
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|)
expr_stmt|;
comment|/// Returns information about the module to be used for LTO: whether to
comment|/// compile with ThinLTO, and whether it has a summary.
name|Expected
operator|<
name|BitcodeLTOInfo
operator|>
name|getLTOInfo
argument_list|()
expr_stmt|;
comment|/// Parse the specified bitcode buffer, returning the module summary index.
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>>
name|getSummary
argument_list|()
expr_stmt|;
comment|/// Parse the specified bitcode buffer and merge its module summary index
comment|/// into CombinedIndex.
name|Error
name|readSummary
parameter_list|(
name|ModuleSummaryIndex
modifier|&
name|CombinedIndex
parameter_list|,
name|StringRef
name|ModulePath
parameter_list|,
name|uint64_t
name|ModuleId
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|BitcodeFileContents
block|{
name|std
operator|::
name|vector
operator|<
name|BitcodeModule
operator|>
name|Mods
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Returns the contents of a bitcode file.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|BitcodeFileContents
operator|>
name|getBitcodeFileContents
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns a list of modules in the specified bitcode buffer.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|vector
operator|<
name|BitcodeModule
operator|>>
name|getBitcodeModuleList
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Read the header of the specified bitcode buffer and prepare for lazy
end_comment

begin_comment
comment|/// deserialization of function bodies. If ShouldLazyLoadMetadata is true,
end_comment

begin_comment
comment|/// lazily load metadata as well. If IsImporting is true, this module is
end_comment

begin_comment
comment|/// being parsed for ThinLTO importing into another module.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|getLazyBitcodeModule
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|bool ShouldLazyLoadMetadata = false
argument_list|,
argument|bool IsImporting = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Like getLazyBitcodeModule, except that the module takes ownership of
end_comment

begin_comment
comment|/// the memory buffer if successful. If successful, this moves Buffer. On
end_comment

begin_comment
comment|/// error, this *does not* move Buffer. If IsImporting is true, this module is
end_comment

begin_comment
comment|/// being parsed for ThinLTO importing into another module.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|getOwningLazyBitcodeModule
argument_list|(
argument|std::unique_ptr<MemoryBuffer>&&Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|bool ShouldLazyLoadMetadata = false
argument_list|,
argument|bool IsImporting = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Read the header of the specified bitcode buffer and extract just the
end_comment

begin_comment
comment|/// triple information. If successful, this returns a string. On error, this
end_comment

begin_comment
comment|/// returns "".
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|string
operator|>
name|getBitcodeTargetTriple
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return true if \p Buffer contains a bitcode file with ObjC code (category
end_comment

begin_comment
comment|/// or class) in it.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|bool
operator|>
name|isBitcodeContainingObjCCategory
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Read the header of the specified bitcode buffer and extract just the
end_comment

begin_comment
comment|/// producer string information. If successful, this returns a string. On
end_comment

begin_comment
comment|/// error, this returns "".
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|string
operator|>
name|getBitcodeProducerString
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Read the specified bitcode file, returning the module.
end_comment

begin_expr_stmt
name|Expected
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
end_expr_stmt

begin_comment
comment|/// Returns LTO information for the specified bitcode file.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|BitcodeLTOInfo
operator|>
name|getBitcodeLTOInfo
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Parse the specified bitcode buffer, returning the module summary index.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>>
name|getModuleSummaryIndex
argument_list|(
argument|MemoryBufferRef Buffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Parse the specified bitcode buffer and merge the index into CombinedIndex.
end_comment

begin_function_decl
name|Error
name|readModuleSummaryIndex
parameter_list|(
name|MemoryBufferRef
name|Buffer
parameter_list|,
name|ModuleSummaryIndex
modifier|&
name|CombinedIndex
parameter_list|,
name|uint64_t
name|ModuleId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Parse the module summary index out of an IR file and return the module
end_comment

begin_comment
comment|/// summary index object if found, or an empty summary if not. If Path refers
end_comment

begin_comment
comment|/// to an empty file and IgnoreEmptyThinLTOIndexFile is true, then
end_comment

begin_comment
comment|/// this function will return nullptr.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>>
name|getModuleSummaryIndexForFile
argument_list|(
argument|StringRef Path
argument_list|,
argument|bool IgnoreEmptyThinLTOIndexFile = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isBitcodeWrapper - Return true if the given bytes are the magic bytes
end_comment

begin_comment
comment|/// for an LLVM IR bitcode wrapper.
end_comment

begin_comment
comment|///
end_comment

begin_function
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
end_function

begin_comment
comment|/// isRawBitcode - Return true if the given bytes are the magic bytes for
end_comment

begin_comment
comment|/// raw LLVM IR bitcode (without a wrapper).
end_comment

begin_comment
comment|///
end_comment

begin_function
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
end_function

begin_comment
comment|/// isBitcode - Return true if the given bytes are the magic bytes for
end_comment

begin_comment
comment|/// LLVM IR bitcode, either with or without a wrapper.
end_comment

begin_comment
comment|///
end_comment

begin_function
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
end_function

begin_comment
comment|/// SkipBitcodeWrapperHeader - Some systems wrap bc files with a special
end_comment

begin_comment
comment|/// header for padding or other reasons.  The format of this header is:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// struct bc_header {
end_comment

begin_comment
comment|///   uint32_t Magic;         // 0x0B17C0DE
end_comment

begin_comment
comment|///   uint32_t Version;       // Version, currently always 0.
end_comment

begin_comment
comment|///   uint32_t BitcodeOffset; // Offset to traditional bitcode file.
end_comment

begin_comment
comment|///   uint32_t BitcodeSize;   // Size of traditional bitcode file.
end_comment

begin_comment
comment|///   ... potentially other gunk ...
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function is called when we find a file with a matching magic number.
end_comment

begin_comment
comment|/// In this case, skip down to the subsection of the file that is actually a
end_comment

begin_comment
comment|/// BC file.
end_comment

begin_comment
comment|/// If 'VerifyBufferSize' is true, check that the buffer is large enough to
end_comment

begin_comment
comment|/// contain the whole bitcode file.
end_comment

begin_function
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
comment|// Must contain the offset and size field!
if|if
condition|(
name|unsigned
argument_list|(
name|BufEnd
operator|-
name|BufPtr
argument_list|)
operator|<
name|BWH_SizeField
operator|+
literal|4
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
name|BWH_OffsetField
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
name|BWH_SizeField
index|]
argument_list|)
decl_stmt|;
name|uint64_t
name|BitcodeOffsetEnd
init|=
operator|(
name|uint64_t
operator|)
name|Offset
operator|+
operator|(
name|uint64_t
operator|)
name|Size
decl_stmt|;
comment|// Verify that Offset+Size fits in the file.
if|if
condition|(
name|VerifyBufferSize
operator|&&
name|BitcodeOffsetEnd
operator|>
name|uint64_t
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
end_function

begin_expr_stmt
specifier|const
name|std
operator|::
name|error_category
operator|&
name|BitcodeErrorCategory
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|enum
name|class
name|BitcodeError
block|{
name|CorruptedBitcode
operator|=
literal|1
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_macro
unit|namespace
name|std
end_macro

begin_block
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
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

