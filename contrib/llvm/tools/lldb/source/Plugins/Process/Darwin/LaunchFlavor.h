begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LaunchFlavor.h ---------------------------------------- -*- C++ -*-===//
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
name|LaunchFlavor_h
end_ifndef

begin_define
define|#
directive|define
name|LaunchFlavor_h
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_darwin
block|{
name|enum
name|class
name|LaunchFlavor
block|{
name|Default
operator|=
literal|0
operator|,
name|PosixSpawn
operator|=
literal|1
operator|,
name|ForkExec
operator|=
literal|2
operator|,
ifdef|#
directive|ifdef
name|WITH_SPRINGBOARD
name|SpringBoard
operator|=
literal|3
operator|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_BKS
name|BKS
operator|=
literal|4
operator|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_FBS
name|FBS
operator|=
literal|5
endif|#
directive|endif
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespaces
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LaunchFlavor_h */
end_comment

end_unit

