begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Bitcode/BitcodeWriter.h - Bitcode writers ----*- C++ -*-===//
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
comment|// This header defines interfaces to write LLVM bitcode files/streams.
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
name|LLVM_BITCODE_BITCODEWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_BITCODEWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/StringTableBuilder.h"
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
name|Module
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|BitcodeWriter
block|{
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Buffer
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|BitstreamWriter
operator|>
name|Stream
expr_stmt|;
name|StringTableBuilder
name|StrtabBuilder
block|{
name|StringTableBuilder
operator|::
name|RAW
block|}
empty_stmt|;
name|bool
name|WroteStrtab
init|=
name|false
decl_stmt|;
name|void
name|writeBlob
parameter_list|(
name|unsigned
name|Block
parameter_list|,
name|unsigned
name|Record
parameter_list|,
name|StringRef
name|Blob
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Create a BitcodeWriter that writes to Buffer.
name|BitcodeWriter
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Buffer
argument_list|)
expr_stmt|;
operator|~
name|BitcodeWriter
argument_list|()
expr_stmt|;
comment|/// Write the bitcode file's string table. This must be called exactly once
comment|/// after all modules have been written.
name|void
name|writeStrtab
parameter_list|()
function_decl|;
comment|/// Copy the string table for another module into this bitcode file. This
comment|/// should be called after copying the module itself into the bitcode file.
name|void
name|copyStrtab
parameter_list|(
name|StringRef
name|Strtab
parameter_list|)
function_decl|;
comment|/// Write the specified module to the buffer specified at construction time.
comment|///
comment|/// If \c ShouldPreserveUseListOrder, encode the use-list order for each \a
comment|/// Value in \c M.  These will be reconstructed exactly when \a M is
comment|/// deserialized.
comment|///
comment|/// If \c Index is supplied, the bitcode will contain the summary index
comment|/// (currently for use in ThinLTO optimization).
comment|///
comment|/// \p GenerateHash enables hashing the Module and including the hash in the
comment|/// bitcode (currently for use in ThinLTO incremental build).
comment|///
comment|/// If \p ModHash is non-null, when GenerateHash is true, the resulting
comment|/// hash is written into ModHash. When GenerateHash is false, that value
comment|/// is used as the hash instead of computing from the generated bitcode.
comment|/// Can be used to produce the same module hash for a minimized bitcode
comment|/// used just for the thin link as in the regular full bitcode that will
comment|/// be used in the backend.
name|void
name|writeModule
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|,
name|bool
name|ShouldPreserveUseListOrder
init|=
name|false
parameter_list|,
specifier|const
name|ModuleSummaryIndex
modifier|*
name|Index
init|=
name|nullptr
parameter_list|,
name|bool
name|GenerateHash
init|=
name|false
parameter_list|,
name|ModuleHash
modifier|*
name|ModHash
init|=
name|nullptr
parameter_list|)
function_decl|;
name|void
name|writeIndex
argument_list|(
specifier|const
name|ModuleSummaryIndex
operator|*
name|Index
argument_list|,
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|GVSummaryMapTy
operator|>
operator|*
name|ModuleToSummariesForIndex
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Write the specified module to the specified raw output stream.
comment|///
comment|/// For streams where it matters, the given stream should be in "binary"
comment|/// mode.
comment|///
comment|/// If \c ShouldPreserveUseListOrder, encode the use-list order for each \a
comment|/// Value in \c M.  These will be reconstructed exactly when \a M is
comment|/// deserialized.
comment|///
comment|/// If \c Index is supplied, the bitcode will contain the summary index
comment|/// (currently for use in ThinLTO optimization).
comment|///
comment|/// \p GenerateHash enables hashing the Module and including the hash in the
comment|/// bitcode (currently for use in ThinLTO incremental build).
comment|///
comment|/// If \p ModHash is non-null, when GenerateHash is true, the resulting
comment|/// hash is written into ModHash. When GenerateHash is false, that value
comment|/// is used as the hash instead of computing from the generated bitcode.
comment|/// Can be used to produce the same module hash for a minimized bitcode
comment|/// used just for the thin link as in the regular full bitcode that will
comment|/// be used in the backend.
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
specifier|const
name|ModuleSummaryIndex
modifier|*
name|Index
init|=
name|nullptr
parameter_list|,
name|bool
name|GenerateHash
init|=
name|false
parameter_list|,
name|ModuleHash
modifier|*
name|ModHash
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Write the specified module summary index to the given raw output stream,
comment|/// where it will be written in a new bitcode block. This is used when
comment|/// writing the combined index file for ThinLTO. When writing a subset of the
comment|/// index for a distributed backend, provide the \p ModuleToSummariesForIndex
comment|/// map.
name|void
name|WriteIndexToFile
argument_list|(
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|raw_ostream
operator|&
name|Out
argument_list|,
specifier|const
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|GVSummaryMapTy
operator|>
operator|*
name|ModuleToSummariesForIndex
operator|=
name|nullptr
argument_list|)
decl_stmt|;
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

