begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// WebAssemblyInstPrinter.h - Print wasm MCInst to assembly syntax -*- C++ -*-//
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
comment|/// \brief This class prints an WebAssembly MCInst to wasm file syntax.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_INSTPRINTER_WEBASSEMBLYINSTPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_INSTPRINTER_WEBASSEMBLYINSTPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInstPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCOperand
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|WebAssemblyInstPrinter
range|:
name|public
name|MCInstPrinter
block|{
name|public
operator|:
name|WebAssemblyInstPrinter
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|MII
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|)
block|;
name|void
name|printRegName
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned RegNo
argument_list|)
specifier|const
name|override
block|;
name|void
name|printInst
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|StringRef Annot
argument_list|,
argument|const MCSubtargetInfo&STI
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

