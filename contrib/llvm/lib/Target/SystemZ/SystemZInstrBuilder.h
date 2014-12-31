begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZInstrBuilder.h - Functions to aid building insts -*- C++ -*-===//
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
comment|// This file exposes functions that may be used with BuildMI from the
end_comment

begin_comment
comment|// MachineInstrBuilder.h file to handle SystemZ'isms in a clean way.
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
name|SYSTEMZINSTRBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZINSTRBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/PseudoSourceValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Add a BDX memory reference for frame object FI to MIB.
specifier|static
specifier|inline
specifier|const
name|MachineInstrBuilder
modifier|&
name|addFrameReference
parameter_list|(
specifier|const
name|MachineInstrBuilder
modifier|&
name|MIB
parameter_list|,
name|int
name|FI
parameter_list|)
block|{
name|MachineInstr
modifier|*
name|MI
init|=
name|MIB
decl_stmt|;
name|MachineFunction
modifier|&
name|MF
init|=
operator|*
name|MI
operator|->
name|getParent
argument_list|()
operator|->
name|getParent
argument_list|()
decl_stmt|;
name|MachineFrameInfo
modifier|*
name|MFFrame
init|=
name|MF
operator|.
name|getFrameInfo
argument_list|()
decl_stmt|;
specifier|const
name|MCInstrDesc
modifier|&
name|MCID
init|=
name|MI
operator|->
name|getDesc
argument_list|()
decl_stmt|;
name|unsigned
name|Flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|MCID
operator|.
name|mayLoad
argument_list|()
condition|)
name|Flags
operator||=
name|MachineMemOperand
operator|::
name|MOLoad
expr_stmt|;
if|if
condition|(
name|MCID
operator|.
name|mayStore
argument_list|()
condition|)
name|Flags
operator||=
name|MachineMemOperand
operator|::
name|MOStore
expr_stmt|;
name|int64_t
name|Offset
init|=
literal|0
decl_stmt|;
name|MachineMemOperand
modifier|*
name|MMO
init|=
name|MF
operator|.
name|getMachineMemOperand
argument_list|(
name|MachinePointerInfo
argument_list|(
name|PseudoSourceValue
operator|::
name|getFixedStack
argument_list|(
name|FI
argument_list|)
argument_list|,
name|Offset
argument_list|)
argument_list|,
name|Flags
argument_list|,
name|MFFrame
operator|->
name|getObjectSize
argument_list|(
name|FI
argument_list|)
argument_list|,
name|MFFrame
operator|->
name|getObjectAlignment
argument_list|(
name|FI
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|MIB
operator|.
name|addFrameIndex
argument_list|(
name|FI
argument_list|)
operator|.
name|addImm
argument_list|(
name|Offset
argument_list|)
operator|.
name|addReg
argument_list|(
literal|0
argument_list|)
operator|.
name|addMemOperand
argument_list|(
name|MMO
argument_list|)
return|;
block|}
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

