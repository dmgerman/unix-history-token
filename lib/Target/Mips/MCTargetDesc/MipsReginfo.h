begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MipsReginfo.h - MipsReginfo -----------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                    The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENCE.TXT for details.
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
name|MIPSREGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSREGINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
decl_stmt|;
name|class
name|TargetLoweringObjectFile
decl_stmt|;
name|class
name|MipsSubtarget
decl_stmt|;
name|class
name|MipsReginfo
block|{
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|MipsReginfo
argument_list|()
block|{}
name|void
name|emitMipsReginfoSectionCG
argument_list|(
name|MCStreamer
operator|&
name|OS
argument_list|,
specifier|const
name|TargetLoweringObjectFile
operator|&
name|TLOF
argument_list|,
specifier|const
name|MipsSubtarget
operator|&
name|MST
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

