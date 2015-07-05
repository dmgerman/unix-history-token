begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonTargetStreamer.h - Hexagon Target Streamer ------*- C++ -*--===//
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
name|HEXAGONTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|HexagonTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
operator|:
name|MCTargetStreamer
argument_list|(
argument|S
argument_list|)
block|{}
name|virtual
name|void
name|EmitCodeAlignment
argument_list|(
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned MaxBytesToEmit =
literal|0
argument_list|)
block|{}
block|;
name|virtual
name|void
name|emitFAlign
argument_list|(
argument|unsigned Size
argument_list|,
argument|unsigned MaxBytesToEmit
argument_list|)
block|{}
block|;
name|virtual
name|void
name|EmitCommonSymbolSorted
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned AccessGranularity
argument_list|)
block|{}
block|;
name|virtual
name|void
name|EmitLocalCommonSymbolSorted
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlign
argument_list|,
argument|unsigned AccessGranularity
argument_list|)
block|{}
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

