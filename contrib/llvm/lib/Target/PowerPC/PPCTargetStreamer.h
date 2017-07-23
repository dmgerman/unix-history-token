begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PPCTargetStreamer.h - PPC Target Streamer ----------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_POWERPC_PPCTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

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
name|MCExpr
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSymbolELF
decl_stmt|;
name|class
name|PPCTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|PPCTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
operator|~
name|PPCTargetStreamer
argument_list|()
name|override
block|;
name|virtual
name|void
name|emitTCEntry
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|S
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitMachine
argument_list|(
argument|StringRef CPU
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitAbiVersion
argument_list|(
argument|int AbiVersion
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|emitLocalEntry
argument_list|(
name|MCSymbolELF
operator|*
name|S
argument_list|,
specifier|const
name|MCExpr
operator|*
name|LocalOffset
argument_list|)
operator|=
literal|0
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

begin_comment
comment|// LLVM_LIB_TARGET_POWERPC_PPCTARGETSTREAMER_H
end_comment

end_unit

