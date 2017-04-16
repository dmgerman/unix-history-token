begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsOptionRecord.h - Abstraction for storing information -*- C++ -*-===//
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
comment|// MipsOptionRecord - Abstraction for storing arbitrary information in
end_comment

begin_comment
comment|// ELF files. Arbitrary information (e.g. register usage) can be stored in Mips
end_comment

begin_comment
comment|// specific ELF sections like .Mips.options. Specific records should subclass
end_comment

begin_comment
comment|// MipsOptionRecord and provide an implementation to EmitMipsOptionRecord which
end_comment

begin_comment
comment|// basically just dumps the information into an ELF section. More information
end_comment

begin_comment
comment|// about .Mips.option can be found in the SysV ABI and the 64-bit ELF Object
end_comment

begin_comment
comment|// specification.
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
name|LLVM_LIB_TARGET_MIPS_MIPSOPTIONRECORD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSOPTIONRECORD_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsELFStreamer
decl_stmt|;
name|class
name|MipsOptionRecord
block|{
name|public
label|:
name|virtual
operator|~
name|MipsOptionRecord
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|EmitMipsOptionRecord
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|class
name|MipsRegInfoRecord
range|:
name|public
name|MipsOptionRecord
block|{
name|public
operator|:
name|MipsRegInfoRecord
argument_list|(
name|MipsELFStreamer
operator|*
name|S
argument_list|,
name|MCContext
operator|&
name|Context
argument_list|)
operator|:
name|Streamer
argument_list|(
name|S
argument_list|)
block|,
name|Context
argument_list|(
argument|Context
argument_list|)
block|{
name|ri_gprmask
operator|=
literal|0
block|;
name|ri_cprmask
index|[
literal|0
index|]
operator|=
name|ri_cprmask
index|[
literal|1
index|]
operator|=
name|ri_cprmask
index|[
literal|2
index|]
operator|=
name|ri_cprmask
index|[
literal|3
index|]
operator|=
literal|0
block|;
name|ri_gp_value
operator|=
literal|0
block|;
specifier|const
name|MCRegisterInfo
operator|*
name|TRI
operator|=
name|Context
operator|.
name|getRegisterInfo
argument_list|()
block|;
name|GPR32RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|GPR32RegClassID
argument_list|)
operator|)
block|;
name|GPR64RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|GPR64RegClassID
argument_list|)
operator|)
block|;
name|FGR32RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|FGR32RegClassID
argument_list|)
operator|)
block|;
name|FGR64RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|FGR64RegClassID
argument_list|)
operator|)
block|;
name|AFGR64RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|AFGR64RegClassID
argument_list|)
operator|)
block|;
name|MSA128BRegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|MSA128BRegClassID
argument_list|)
operator|)
block|;
name|COP0RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|COP0RegClassID
argument_list|)
operator|)
block|;
name|COP2RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|COP2RegClassID
argument_list|)
operator|)
block|;
name|COP3RegClass
operator|=
operator|&
operator|(
name|TRI
operator|->
name|getRegClass
argument_list|(
name|Mips
operator|::
name|COP3RegClassID
argument_list|)
operator|)
block|;   }
operator|~
name|MipsRegInfoRecord
argument_list|()
name|override
operator|=
expr|default
block|;
name|void
name|EmitMipsOptionRecord
argument_list|()
name|override
block|;
name|void
name|SetPhysRegUsed
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const MCRegisterInfo *MCRegInfo
argument_list|)
block|;
name|private
operator|:
name|MipsELFStreamer
operator|*
name|Streamer
block|;
name|MCContext
operator|&
name|Context
block|;
specifier|const
name|MCRegisterClass
operator|*
name|GPR32RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|GPR64RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|FGR32RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|FGR64RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|AFGR64RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|MSA128BRegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|COP0RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|COP2RegClass
block|;
specifier|const
name|MCRegisterClass
operator|*
name|COP3RegClass
block|;
name|uint32_t
name|ri_gprmask
block|;
name|uint32_t
name|ri_cprmask
index|[
literal|4
index|]
block|;
name|int64_t
name|ri_gp_value
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
comment|// LLVM_LIB_TARGET_MIPS_MIPSOPTIONRECORD_H
end_comment

end_unit

