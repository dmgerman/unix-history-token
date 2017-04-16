begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCWasmObjectWriter.h - Wasm Object Writer -------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCWASMOBJECTWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCWASMOBJECTWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSectionWasm
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSymbolWasm
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
comment|// Information about a single relocation.
struct|struct
name|WasmRelocationEntry
block|{
name|uint64_t
name|Offset
decl_stmt|;
comment|// Where is the relocation.
specifier|const
name|MCSymbolWasm
modifier|*
name|Symbol
decl_stmt|;
comment|// The symbol to relocate with.
name|uint64_t
name|Addend
decl_stmt|;
comment|// A value to add to the symbol.
name|unsigned
name|Type
decl_stmt|;
comment|// The type of the relocation.
name|MCSectionWasm
modifier|*
name|FixupSection
decl_stmt|;
comment|// The section the relocation is targeting.
name|WasmRelocationEntry
argument_list|(
argument|uint64_t Offset
argument_list|,
argument|const MCSymbolWasm *Symbol
argument_list|,
argument|uint64_t Addend
argument_list|,
argument|unsigned Type
argument_list|,
argument|MCSectionWasm *FixupSection
argument_list|)
block|:
name|Offset
argument_list|(
name|Offset
argument_list|)
operator|,
name|Symbol
argument_list|(
name|Symbol
argument_list|)
operator|,
name|Addend
argument_list|(
name|Addend
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|FixupSection
argument_list|(
argument|FixupSection
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&Out
argument_list|)
specifier|const
block|{
name|Out
operator|<<
literal|"Off="
operator|<<
name|Offset
operator|<<
literal|", Sym="
operator|<<
name|Symbol
operator|<<
literal|", Addend="
operator|<<
name|Addend
operator|<<
literal|", Type="
operator|<<
name|Type
operator|<<
literal|", FixupSection="
operator|<<
name|FixupSection
block|;   }
name|void
name|dump
argument_list|()
specifier|const
block|{
name|print
argument_list|(
name|errs
argument_list|()
argument_list|)
block|; }
block|}
struct|;
name|class
name|MCWasmObjectTargetWriter
block|{
specifier|const
name|unsigned
name|Is64Bit
range|:
literal|1
decl_stmt|;
name|protected
label|:
name|explicit
name|MCWasmObjectTargetWriter
parameter_list|(
name|bool
name|Is64Bit_
parameter_list|)
function_decl|;
name|public
label|:
name|virtual
operator|~
name|MCWasmObjectTargetWriter
argument_list|()
block|{}
name|virtual
name|unsigned
name|getRelocType
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|const MCValue&Target
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|bool IsPCRel
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|needsRelocateWithSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Sym
argument_list|,
name|unsigned
name|Type
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|sortRelocs
argument_list|(
specifier|const
name|MCAssembler
operator|&
name|Asm
argument_list|,
name|std
operator|::
name|vector
operator|<
name|WasmRelocationEntry
operator|>
operator|&
name|Relocs
argument_list|)
decl_stmt|;
comment|/// \name Accessors
comment|/// @{
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Construct a new Wasm writer instance.
comment|///
comment|/// \param MOTW - The target specific Wasm writer subclass.
comment|/// \param OS - The stream to write to.
comment|/// \returns The constructed object writer.
name|MCObjectWriter
modifier|*
name|createWasmObjectWriter
parameter_list|(
name|MCWasmObjectTargetWriter
modifier|*
name|MOTW
parameter_list|,
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|)
function_decl|;
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

