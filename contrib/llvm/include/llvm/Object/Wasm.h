begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- WasmObjectFile.h - Wasm object file implementation -------*- C++ -*-===//
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
comment|// This file declares the WasmObjectFile class, which implements the ObjectFile
end_comment

begin_comment
comment|// interface for Wasm files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See: https://github.com/WebAssembly/design/blob/master/BinaryEncoding.md
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
name|LLVM_OBJECT_WASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_WASM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Wasm.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|WasmObjectFile
range|:
name|public
name|ObjectFile
block|{
name|public
operator|:
name|WasmObjectFile
argument_list|(
argument|MemoryBufferRef Object
argument_list|,
argument|Error&Err
argument_list|)
block|;
specifier|const
name|wasm
operator|::
name|WasmObjectHeader
operator|&
name|getHeader
argument_list|()
specifier|const
block|;
specifier|const
name|wasm
operator|::
name|WasmSection
operator|*
name|getWasmSection
argument_list|(
argument|const SectionRef&Section
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Binary *v
argument_list|)
block|{
return|return
name|v
operator|->
name|isWasm
argument_list|()
return|;
block|}
name|protected
operator|:
name|void
name|moveSymbolNext
argument_list|(
argument|DataRefImpl&Symb
argument_list|)
specifier|const
name|override
block|;
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
block|;
name|uint32_t
name|getSymbolFlags
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|basic_symbol_iterator
name|symbol_begin
argument_list|()
specifier|const
name|override
block|;
name|basic_symbol_iterator
name|symbol_end
argument_list|()
specifier|const
name|override
block|;
name|Expected
operator|<
name|StringRef
operator|>
name|getSymbolName
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|Expected
operator|<
name|uint64_t
operator|>
name|getSymbolAddress
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getSymbolValueImpl
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|getSymbolAlignment
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getCommonSymbolSizeImpl
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|Expected
operator|<
name|SymbolRef
operator|::
name|Type
operator|>
name|getSymbolType
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
name|Expected
operator|<
name|section_iterator
operator|>
name|getSymbolSection
argument_list|(
argument|DataRefImpl Symb
argument_list|)
specifier|const
name|override
block|;
comment|// Overrides from SectionRef.
name|void
name|moveSectionNext
argument_list|(
argument|DataRefImpl&Sec
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|error_code
name|getSectionName
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|StringRef&Res
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getSectionAddress
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getSectionSize
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|error_code
name|getSectionContents
argument_list|(
argument|DataRefImpl Sec
argument_list|,
argument|StringRef&Res
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getSectionAlignment
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSectionCompressed
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSectionText
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSectionData
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSectionBSS
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSectionVirtual
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isSectionBitcode
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|relocation_iterator
name|section_rel_begin
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|relocation_iterator
name|section_rel_end
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
name|section_iterator
name|getRelocatedSection
argument_list|(
argument|DataRefImpl Sec
argument_list|)
specifier|const
name|override
block|;
comment|// Overrides from RelocationRef.
name|void
name|moveRelocationNext
argument_list|(
argument|DataRefImpl&Rel
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getRelocationOffset
argument_list|(
argument|DataRefImpl Rel
argument_list|)
specifier|const
name|override
block|;
name|symbol_iterator
name|getRelocationSymbol
argument_list|(
argument|DataRefImpl Rel
argument_list|)
specifier|const
name|override
block|;
name|uint64_t
name|getRelocationType
argument_list|(
argument|DataRefImpl Rel
argument_list|)
specifier|const
name|override
block|;
name|void
name|getRelocationTypeName
argument_list|(
argument|DataRefImpl Rel
argument_list|,
argument|SmallVectorImpl<char>&Result
argument_list|)
specifier|const
name|override
block|;
name|section_iterator
name|section_begin
argument_list|()
specifier|const
name|override
block|;
name|section_iterator
name|section_end
argument_list|()
specifier|const
name|override
block|;
name|uint8_t
name|getBytesInAddress
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|getFileFormatName
argument_list|()
specifier|const
name|override
block|;
name|unsigned
name|getArch
argument_list|()
specifier|const
name|override
block|;
name|SubtargetFeatures
name|getFeatures
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isRelocatableObject
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|uint8_t
operator|*
name|getPtr
argument_list|(
argument|size_t Offset
argument_list|)
specifier|const
block|;
name|Error
name|parseUserSection
argument_list|(
argument|wasm::WasmSection&Sec
argument_list|,
argument|const uint8_t *Ptr
argument_list|,
argument|size_t Length
argument_list|)
block|;
name|wasm
operator|::
name|WasmObjectHeader
name|Header
block|;
name|std
operator|::
name|vector
operator|<
name|wasm
operator|::
name|WasmSection
operator|>
name|Sections
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

