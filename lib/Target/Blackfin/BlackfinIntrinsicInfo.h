begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BlackfinIntrinsicInfo.h - Blackfin Intrinsic Information -*- C++ -*-===//
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
comment|// This file contains the Blackfin implementation of TargetIntrinsicInfo.
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
name|BLACKFININTRINSICS_H
end_ifndef

begin_define
define|#
directive|define
name|BLACKFININTRINSICS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetIntrinsicInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlackfinIntrinsicInfo
range|:
name|public
name|TargetIntrinsicInfo
block|{
name|public
operator|:
specifier|const
name|char
operator|*
name|getName
argument_list|(
argument|unsigned IntrID
argument_list|)
specifier|const
block|;
name|unsigned
name|lookupName
argument_list|(
argument|const char *Name
argument_list|,
argument|unsigned Len
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

