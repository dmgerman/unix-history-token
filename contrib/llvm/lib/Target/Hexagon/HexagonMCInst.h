begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- HexagonMCInst.h - Hexagon sub-class of MCInst ----------------------===//
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
comment|// This class extends MCInst to allow some VLIW annotation.
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
name|HEXAGONMCINST_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONMCINST_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonMCInst
range|:
name|public
name|MCInst
block|{
comment|// Packet start and end markers
name|unsigned
name|startPacket
operator|:
literal|1
block|,
name|endPacket
operator|:
literal|1
block|;
specifier|const
name|MachineInstr
operator|*
name|MachineI
block|;
name|public
operator|:
name|explicit
name|HexagonMCInst
argument_list|()
operator|:
name|MCInst
argument_list|()
block|,
name|startPacket
argument_list|(
literal|0
argument_list|)
block|,
name|endPacket
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|MachineInstr
operator|*
name|getMI
argument_list|()
specifier|const
block|{
return|return
name|MachineI
return|;
block|}
block|;
name|void
name|setMI
argument_list|(
argument|const MachineInstr *MI
argument_list|)
block|{
name|MachineI
operator|=
name|MI
block|; }
block|;
name|bool
name|isStartPacket
argument_list|()
specifier|const
block|{
return|return
operator|(
name|startPacket
operator|)
return|;
block|}
block|;
name|bool
name|isEndPacket
argument_list|()
specifier|const
block|{
return|return
operator|(
name|endPacket
operator|)
return|;
block|}
block|;
name|void
name|setStartPacket
argument_list|(
argument|bool yes
argument_list|)
block|{
name|startPacket
operator|=
name|yes
block|; }
block|;
name|void
name|setEndPacket
argument_list|(
argument|bool yes
argument_list|)
block|{
name|endPacket
operator|=
name|yes
block|; }
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

