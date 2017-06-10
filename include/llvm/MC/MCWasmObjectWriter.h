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
file|"llvm/BinaryFormat/Wasm.h"
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
expr_stmt|;
name|virtual
name|unsigned
name|getRelocType
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|MCValue
operator|&
name|Target
argument_list|,
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
name|bool
name|IsPCRel
argument_list|)
decl|const
init|=
literal|0
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

