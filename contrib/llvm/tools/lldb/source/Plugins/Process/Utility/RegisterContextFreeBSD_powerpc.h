begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextFreeBSD_powerpc.h -------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextFreeBSD_powerpc_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextFreeBSD_powerpc_H_
end_define

begin_include
include|#
directive|include
file|"RegisterContextPOSIX.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextFreeBSD_powerpc
range|:
name|public
name|lldb_private
operator|::
name|RegisterInfoInterface
block|{
name|public
operator|:
name|RegisterContextFreeBSD_powerpc
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextFreeBSD_powerpc
argument_list|()
block|;
name|size_t
name|GetGPRSize
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextFreeBSD_powerpc32
range|:
name|public
name|RegisterContextFreeBSD_powerpc
block|{
name|public
operator|:
name|RegisterContextFreeBSD_powerpc32
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextFreeBSD_powerpc32
argument_list|()
block|;
name|size_t
name|GetGPRSize
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextFreeBSD_powerpc64
range|:
name|public
name|RegisterContextFreeBSD_powerpc
block|{
name|public
operator|:
name|RegisterContextFreeBSD_powerpc64
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextFreeBSD_powerpc64
argument_list|()
block|;
name|size_t
name|GetGPRSize
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

