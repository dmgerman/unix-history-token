begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- HexagonMachineFunctionInfo.h - Hexagon machine function info -*- C++ -*-=//
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Hexagon
block|{
specifier|const
name|unsigned
name|int
name|StartPacket
init|=
literal|0x1
decl_stmt|;
specifier|const
name|unsigned
name|int
name|EndPacket
init|=
literal|0x2
decl_stmt|;
block|}
comment|// end namespace Hexagon
comment|/// Hexagon target-specific information for each MachineFunction.
name|class
name|HexagonMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
comment|// SRetReturnReg - Some subtargets require that sret lowering includes
comment|// returning the value of the returned struct in a register. This field
comment|// holds the virtual register into which the sret argument is passed.
name|unsigned
name|SRetReturnReg
operator|=
literal|0
block|;
name|unsigned
name|StackAlignBaseVReg
operator|=
literal|0
block|;
comment|// Aligned-stack base register (virtual)
name|unsigned
name|StackAlignBasePhysReg
operator|=
literal|0
block|;
comment|//                             (physical)
name|int
name|VarArgsFrameIndex
block|;
name|bool
name|HasClobberLR
operator|=
name|false
block|;
name|bool
name|HasEHReturn
operator|=
name|false
block|;
name|std
operator|::
name|map
operator|<
specifier|const
name|MachineInstr
operator|*
block|,
name|unsigned
operator|>
name|PacketInfo
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|HexagonMachineFunctionInfo
argument_list|()
operator|=
expr|default
block|;
name|HexagonMachineFunctionInfo
argument_list|(
argument|MachineFunction&MF
argument_list|)
block|{}
name|unsigned
name|getSRetReturnReg
argument_list|()
specifier|const
block|{
return|return
name|SRetReturnReg
return|;
block|}
name|void
name|setSRetReturnReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|SRetReturnReg
operator|=
name|Reg
block|; }
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int v
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|v
block|; }
name|int
name|getVarArgsFrameIndex
argument_list|()
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setStartPacket
argument_list|(
argument|MachineInstr* MI
argument_list|)
block|{
name|PacketInfo
index|[
name|MI
index|]
operator||=
name|Hexagon
operator|::
name|StartPacket
block|;   }
name|void
name|setEndPacket
argument_list|(
argument|MachineInstr* MI
argument_list|)
block|{
name|PacketInfo
index|[
name|MI
index|]
operator||=
name|Hexagon
operator|::
name|EndPacket
block|;   }
name|bool
name|isStartPacket
argument_list|(
argument|const MachineInstr* MI
argument_list|)
specifier|const
block|{
return|return
operator|(
name|PacketInfo
operator|.
name|count
argument_list|(
name|MI
argument_list|)
operator|&&
operator|(
name|PacketInfo
operator|.
name|find
argument_list|(
name|MI
argument_list|)
operator|->
name|second
operator|&
name|Hexagon
operator|::
name|StartPacket
operator|)
operator|)
return|;
block|}
name|bool
name|isEndPacket
argument_list|(
argument|const MachineInstr* MI
argument_list|)
specifier|const
block|{
return|return
operator|(
name|PacketInfo
operator|.
name|count
argument_list|(
name|MI
argument_list|)
operator|&&
operator|(
name|PacketInfo
operator|.
name|find
argument_list|(
name|MI
argument_list|)
operator|->
name|second
operator|&
name|Hexagon
operator|::
name|EndPacket
operator|)
operator|)
return|;
block|}
name|void
name|setHasClobberLR
argument_list|(
argument|bool v
argument_list|)
block|{
name|HasClobberLR
operator|=
name|v
block|;  }
name|bool
name|hasClobberLR
argument_list|()
specifier|const
block|{
return|return
name|HasClobberLR
return|;
block|}
name|bool
name|hasEHReturn
argument_list|()
specifier|const
block|{
return|return
name|HasEHReturn
return|;
block|}
block|;
name|void
name|setHasEHReturn
argument_list|(
argument|bool H = true
argument_list|)
block|{
name|HasEHReturn
operator|=
name|H
block|; }
block|;
name|void
name|setStackAlignBaseVReg
argument_list|(
argument|unsigned R
argument_list|)
block|{
name|StackAlignBaseVReg
operator|=
name|R
block|; }
name|unsigned
name|getStackAlignBaseVReg
argument_list|()
specifier|const
block|{
return|return
name|StackAlignBaseVReg
return|;
block|}
name|void
name|setStackAlignBasePhysReg
argument_list|(
argument|unsigned R
argument_list|)
block|{
name|StackAlignBasePhysReg
operator|=
name|R
block|; }
name|unsigned
name|getStackAlignBasePhysReg
argument_list|()
specifier|const
block|{
return|return
name|StackAlignBasePhysReg
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_HEXAGON_HEXAGONMACHINEFUNCTIONINFO_H
end_comment

end_unit

