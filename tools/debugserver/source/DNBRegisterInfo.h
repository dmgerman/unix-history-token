begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBRegisterInfo.h ---------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 8/3/07.
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
name|__DNBRegisterInfo_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNBRegisterInfo_h__
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|struct
name|DNBRegisterValueClass
range|:
name|public
name|DNBRegisterValue
block|{
ifdef|#
directive|ifdef
name|__cplusplus
name|DNBRegisterValueClass
argument_list|(
specifier|const
name|DNBRegisterInfo
operator|*
name|regInfo
operator|=
name|NULL
argument_list|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|void
name|Dump
argument_list|(
argument|const char *pre
argument_list|,
argument|const char *post
argument_list|)
specifier|const
block|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

