begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- HexagonMCShuffler.h ---------------------------------------------------=//
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
comment|// This declares the shuffling of insns inside a bundle according to the
end_comment

begin_comment
comment|// packet formation rules of the Hexagon ISA.
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
name|HEXAGONMCSHUFFLER_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONMCSHUFFLER_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonShuffler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
comment|// Insn bundle shuffler.
name|class
name|HexagonMCShuffler
range|:
name|public
name|HexagonShuffler
block|{
name|bool
name|immext_present
block|;
name|bool
name|duplex_present
block|;
name|public
operator|:
name|HexagonMCShuffler
argument_list|(
name|MCInstrInfo
specifier|const
operator|&
name|MCII
argument_list|,
name|MCSubtargetInfo
specifier|const
operator|&
name|STI
argument_list|,
name|MCInst
operator|&
name|MCB
argument_list|)
operator|:
name|HexagonShuffler
argument_list|(
argument|MCII
argument_list|,
argument|STI
argument_list|)
block|{
name|init
argument_list|(
name|MCB
argument_list|)
block|;   }
block|;
name|HexagonMCShuffler
argument_list|(
argument|MCInstrInfo const&MCII
argument_list|,
argument|MCSubtargetInfo const&STI
argument_list|,
argument|MCInst&MCB
argument_list|,
argument|const MCInst *AddMI
argument_list|,
argument|bool bInsertAtFront = false
argument_list|)
operator|:
name|HexagonShuffler
argument_list|(
argument|MCII
argument_list|,
argument|STI
argument_list|)
block|{
name|init
argument_list|(
name|MCB
argument_list|,
name|AddMI
argument_list|,
name|bInsertAtFront
argument_list|)
block|;   }
block|;
comment|// Copy reordered bundle to another.
name|void
name|copyTo
argument_list|(
name|MCInst
operator|&
name|MCB
argument_list|)
block|;
comment|// Reorder and copy result to another.
name|bool
name|reshuffleTo
argument_list|(
name|MCInst
operator|&
name|MCB
argument_list|)
block|;
name|bool
name|immextPresent
argument_list|()
specifier|const
block|{
return|return
name|immext_present
return|;
block|}
block|;
name|bool
name|duplexPresent
argument_list|()
specifier|const
block|{
return|return
name|duplex_present
return|;
block|}
block|;
name|private
operator|:
name|void
name|init
argument_list|(
name|MCInst
operator|&
name|MCB
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|MCInst&MCB
argument_list|,
argument|const MCInst *AddMI
argument_list|,
argument|bool bInsertAtFront = false
argument_list|)
block|; }
decl_stmt|;
comment|// Invocation of the shuffler.
name|bool
name|HexagonMCShuffle
parameter_list|(
name|MCInstrInfo
specifier|const
modifier|&
name|MCII
parameter_list|,
name|MCSubtargetInfo
specifier|const
modifier|&
name|STI
parameter_list|,
name|MCInst
modifier|&
parameter_list|)
function_decl|;
name|bool
name|HexagonMCShuffle
parameter_list|(
name|MCInstrInfo
specifier|const
modifier|&
name|MCII
parameter_list|,
name|MCSubtargetInfo
specifier|const
modifier|&
name|STI
parameter_list|,
name|MCInst
modifier|&
parameter_list|,
specifier|const
name|MCInst
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|unsigned
name|HexagonMCShuffle
argument_list|(
name|MCInstrInfo
specifier|const
operator|&
name|MCII
argument_list|,
name|MCSubtargetInfo
specifier|const
operator|&
name|STI
argument_list|,
name|MCContext
operator|&
name|Context
argument_list|,
name|MCInst
operator|&
argument_list|,
name|SmallVector
operator|<
name|DuplexCandidate
argument_list|,
literal|8
operator|>
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// HEXAGONMCSHUFFLER_H
end_comment

end_unit

