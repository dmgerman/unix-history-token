begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====-- PTXSubtarget.h - Define Subtarget for the PTX ---------*- C++ -*--===//
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
comment|// This file declares the PTX specific subclass of TargetSubtarget.
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
name|PTX_SUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_SUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PTXSubtarget
range|:
name|public
name|TargetSubtarget
block|{
name|private
operator|:
name|bool
name|is_sm20
block|;
name|public
operator|:
name|PTXSubtarget
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|)
block|;
name|std
operator|::
name|string
name|ParseSubtargetFeatures
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CPU
argument_list|)
block|;   }
decl_stmt|;
comment|// class PTXSubtarget
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_SUBTARGET_H
end_comment

end_unit

