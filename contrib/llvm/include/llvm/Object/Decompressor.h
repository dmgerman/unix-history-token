begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Decompressor.h ------------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_OBJECT_DECOMPRESSOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_DECOMPRESSOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
comment|/// @brief Decompressor helps to handle decompression of compressed sections.
name|class
name|Decompressor
block|{
name|public
label|:
comment|/// @brief Create decompressor object.
comment|/// @param Name        Section name.
comment|/// @param Data        Section content.
comment|/// @param IsLE        Flag determines if Data is in little endian form.
comment|/// @param Is64Bit     Flag determines if object is 64 bit.
specifier|static
name|Expected
operator|<
name|Decompressor
operator|>
name|create
argument_list|(
argument|StringRef Name
argument_list|,
argument|StringRef Data
argument_list|,
argument|bool IsLE
argument_list|,
argument|bool Is64Bit
argument_list|)
expr_stmt|;
comment|/// @brief Resize the buffer and uncompress section data into it.
comment|/// @param Out         Destination buffer.
name|template
operator|<
name|class
name|T
operator|>
name|Error
name|resizeAndDecompress
argument_list|(
argument|T&Out
argument_list|)
block|{
name|Out
operator|.
name|resize
argument_list|(
name|DecompressedSize
argument_list|)
block|;
return|return
name|decompress
argument_list|(
block|{
name|Out
operator|.
name|data
argument_list|()
block|,
operator|(
name|size_t
operator|)
name|DecompressedSize
block|}
argument_list|)
return|;
block|}
comment|/// @brief Uncompress section data to raw buffer provided.
comment|/// @param Buffer      Destination buffer.
name|Error
name|decompress
argument_list|(
name|MutableArrayRef
operator|<
name|char
operator|>
name|Buffer
argument_list|)
decl_stmt|;
comment|/// @brief Return memory buffer size required for decompression.
name|uint64_t
name|getDecompressedSize
parameter_list|()
block|{
return|return
name|DecompressedSize
return|;
block|}
comment|/// @brief Return true if section is compressed, including gnu-styled case.
specifier|static
name|bool
name|isCompressed
argument_list|(
specifier|const
name|object
operator|::
name|SectionRef
operator|&
name|Section
argument_list|)
decl_stmt|;
comment|/// @brief Return true if section is a ELF compressed one.
specifier|static
name|bool
name|isCompressedELFSection
parameter_list|(
name|uint64_t
name|Flags
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// @brief Return true if section name matches gnu style compressed one.
specifier|static
name|bool
name|isGnuStyle
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|private
label|:
name|Decompressor
argument_list|(
argument|StringRef Data
argument_list|)
empty_stmt|;
name|Error
name|consumeCompressedGnuHeader
parameter_list|()
function_decl|;
name|Error
name|consumeCompressedZLibHeader
parameter_list|(
name|bool
name|Is64Bit
parameter_list|,
name|bool
name|IsLittleEndian
parameter_list|)
function_decl|;
name|StringRef
name|SectionData
decl_stmt|;
name|uint64_t
name|DecompressedSize
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace object
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
comment|// LLVM_OBJECT_DECOMPRESSOR_H
end_comment

end_unit

