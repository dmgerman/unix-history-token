begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DarwinLogTypes.h ----------------------------------------*- C++ -*-===//
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
name|DarwinLogTypes_h
end_ifndef

begin_define
define|#
directive|define
name|DarwinLogTypes_h
end_define

begin_enum
enum|enum
name|FilterTarget
block|{
name|eFilterTargetInvalid
block|,
name|eFilterTargetActivity
block|,
name|eFilterTargetActivityChain
block|,
name|eFilterTargetCategory
block|,
name|eFilterTargetMessage
block|,
name|eFilterTargetSubsystem
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DarwinLogTypes_h */
end_comment

end_unit

