begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====- PIC16MachineFuctionInfo.h - PIC16 machine function info -*- C++ -*-===//
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
comment|// This file declares PIC16-specific per-machine-function information.
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
name|PIC16MACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16MACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PIC16MachineFunctionInfo - This class is derived from MachineFunction
comment|/// private PIC16 target-specific information for each MachineFunction.
name|class
name|PIC16MachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
comment|// The frameindexes generated for spill/reload are stack based.
comment|// This maps maintain zero based indexes for these FIs.
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|FiTmpOffsetMap
block|;
name|unsigned
name|TmpSize
block|;
comment|// These are the frames for return value and argument passing
comment|// These FrameIndices will be expanded to foo.frame external symbol
comment|// and all others will be expanded to foo.tmp external symbol.
name|unsigned
name|ReservedFrameCount
block|;
name|public
operator|:
name|PIC16MachineFunctionInfo
argument_list|()
operator|:
name|TmpSize
argument_list|(
literal|0
argument_list|)
block|,
name|ReservedFrameCount
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|PIC16MachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|TmpSize
argument_list|(
literal|0
argument_list|)
block|,
name|ReservedFrameCount
argument_list|(
literal|0
argument_list|)
block|{}
name|std
operator|::
name|map
operator|<
name|unsigned
block|,
name|unsigned
operator|>
operator|&
name|getFiTmpOffsetMap
argument_list|()
block|{
return|return
name|FiTmpOffsetMap
return|;
block|}
name|unsigned
name|getTmpSize
argument_list|()
specifier|const
block|{
return|return
name|TmpSize
return|;
block|}
name|void
name|setTmpSize
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|TmpSize
operator|=
name|Size
block|; }
name|unsigned
name|getReservedFrameCount
argument_list|()
specifier|const
block|{
return|return
name|ReservedFrameCount
return|;
block|}
name|void
name|setReservedFrameCount
argument_list|(
argument|unsigned Count
argument_list|)
block|{
name|ReservedFrameCount
operator|=
name|Count
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

