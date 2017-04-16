begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- WebAssemblyTargetStreamer.h - WebAssembly Target Streamer -*- C++ -*-==//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares WebAssembly-specific target streamer classes.
end_comment

begin_comment
comment|/// These are for implementing support for target-specific assembly directives.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_MCTARGETDESC_WEBASSEMBLYTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_MCTARGETDESC_WEBASSEMBLYTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
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
name|class
name|MCELFStreamer
decl_stmt|;
name|class
name|MCWasmStreamer
decl_stmt|;
comment|/// WebAssembly-specific streamer interface, to implement support
comment|/// WebAssembly-specific assembly directives.
name|class
name|WebAssemblyTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|explicit
name|WebAssemblyTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
comment|/// .param
name|virtual
name|void
name|emitParam
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|,
name|ArrayRef
operator|<
name|MVT
operator|>
name|Types
argument_list|)
operator|=
literal|0
block|;
comment|/// .result
name|virtual
name|void
name|emitResult
argument_list|(
name|MCSymbol
operator|*
name|Symbol
argument_list|,
name|ArrayRef
operator|<
name|MVT
operator|>
name|Types
argument_list|)
operator|=
literal|0
block|;
comment|/// .local
name|virtual
name|void
name|emitLocal
argument_list|(
name|ArrayRef
operator|<
name|MVT
operator|>
name|Types
argument_list|)
operator|=
literal|0
block|;
comment|/// .globalvar
name|virtual
name|void
name|emitGlobal
argument_list|(
name|ArrayRef
operator|<
name|wasm
operator|::
name|Global
operator|>
name|Globals
argument_list|)
operator|=
literal|0
block|;
comment|/// .stack_pointer
name|virtual
name|void
name|emitStackPointer
argument_list|(
argument|uint32_t Index
argument_list|)
operator|=
literal|0
block|;
comment|/// .endfunc
name|virtual
name|void
name|emitEndFunc
argument_list|()
operator|=
literal|0
block|;
comment|/// .functype
name|virtual
name|void
name|emitIndirectFunctionType
argument_list|(
argument|StringRef name
argument_list|,
argument|SmallVectorImpl<MVT>&Params
argument_list|,
argument|SmallVectorImpl<MVT>&Results
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"emitIndirectFunctionType not implemented"
argument_list|)
block|;   }
comment|/// .indidx
name|virtual
name|void
name|emitIndIdx
argument_list|(
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|)
operator|=
literal|0
block|;
comment|/// .import_global
name|virtual
name|void
name|emitGlobalImport
argument_list|(
argument|StringRef name
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
name|void
name|emitValueType
argument_list|(
argument|wasm::ValType Type
argument_list|)
block|; }
decl_stmt|;
comment|/// This part is for ascii assembly output
name|class
name|WebAssemblyTargetAsmStreamer
name|final
range|:
name|public
name|WebAssemblyTargetStreamer
block|{
name|formatted_raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|WebAssemblyTargetAsmStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|,
name|formatted_raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|emitParam
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitResult
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitLocal
argument_list|(
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitGlobal
argument_list|(
argument|ArrayRef<wasm::Global> Globals
argument_list|)
name|override
block|;
name|void
name|emitStackPointer
argument_list|(
argument|uint32_t Index
argument_list|)
name|override
block|;
name|void
name|emitEndFunc
argument_list|()
name|override
block|;
name|void
name|emitIndirectFunctionType
argument_list|(
argument|StringRef name
argument_list|,
argument|SmallVectorImpl<MVT>&Params
argument_list|,
argument|SmallVectorImpl<MVT>&Results
argument_list|)
name|override
block|;
name|void
name|emitIndIdx
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|emitGlobalImport
argument_list|(
argument|StringRef name
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// This part is for ELF object output
name|class
name|WebAssemblyTargetELFStreamer
name|final
range|:
name|public
name|WebAssemblyTargetStreamer
block|{
name|public
operator|:
name|explicit
name|WebAssemblyTargetELFStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
name|void
name|emitParam
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitResult
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitLocal
argument_list|(
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitGlobal
argument_list|(
argument|ArrayRef<wasm::Global> Globals
argument_list|)
name|override
block|;
name|void
name|emitStackPointer
argument_list|(
argument|uint32_t Index
argument_list|)
name|override
block|;
name|void
name|emitEndFunc
argument_list|()
name|override
block|;
name|void
name|emitIndirectFunctionType
argument_list|(
argument|StringRef name
argument_list|,
argument|SmallVectorImpl<MVT>&Params
argument_list|,
argument|SmallVectorImpl<MVT>&Results
argument_list|)
name|override
block|;
name|void
name|emitIndIdx
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|emitGlobalImport
argument_list|(
argument|StringRef name
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// This part is for Wasm object output
name|class
name|WebAssemblyTargetWasmStreamer
name|final
range|:
name|public
name|WebAssemblyTargetStreamer
block|{
name|public
operator|:
name|explicit
name|WebAssemblyTargetWasmStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
name|void
name|emitParam
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitResult
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitLocal
argument_list|(
argument|ArrayRef<MVT> Types
argument_list|)
name|override
block|;
name|void
name|emitGlobal
argument_list|(
argument|ArrayRef<wasm::Global> Globals
argument_list|)
name|override
block|;
name|void
name|emitStackPointer
argument_list|(
argument|uint32_t Index
argument_list|)
name|override
block|;
name|void
name|emitEndFunc
argument_list|()
name|override
block|;
name|void
name|emitIndirectFunctionType
argument_list|(
argument|StringRef name
argument_list|,
argument|SmallVectorImpl<MVT>&Params
argument_list|,
argument|SmallVectorImpl<MVT>&Results
argument_list|)
name|override
block|;
name|void
name|emitIndIdx
argument_list|(
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|emitGlobalImport
argument_list|(
argument|StringRef name
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

