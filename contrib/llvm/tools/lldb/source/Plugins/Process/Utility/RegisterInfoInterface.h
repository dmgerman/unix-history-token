begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterInfoInterface.h --------------------------------*- C++ -*-===//
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
name|lldb_RegisterInfoInterface_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_RegisterInfoInterface_h
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|///------------------------------------------------------------------------------
comment|/// @class RegisterInfoInterface
comment|///
comment|/// @brief RegisterInfo interface to patch RegisterInfo structure for archs.
comment|///------------------------------------------------------------------------------
name|class
name|RegisterInfoInterface
block|{
name|public
label|:
name|RegisterInfoInterface
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
operator|:
name|m_target_arch
argument_list|(
argument|target_arch
argument_list|)
block|{}
name|virtual
operator|~
name|RegisterInfoInterface
argument_list|()
block|{}
name|virtual
name|size_t
name|GetGPRSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the number of registers including the user registers and the
comment|// lldb internal registers also
name|virtual
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the number of the user registers (excluding the registers
comment|// kept for lldb internal use only). Subclasses should override it if
comment|// they belongs to an architecture with lldb internal registers.
name|virtual
name|uint32_t
name|GetUserRegisterCount
argument_list|()
specifier|const
block|{
return|return
name|GetRegisterCount
argument_list|()
return|;
block|}
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|GetTargetArchitecture
argument_list|()
specifier|const
block|{
return|return
name|m_target_arch
return|;
block|}
name|public
label|:
comment|// FIXME make private.
name|lldb_private
operator|::
name|ArchSpec
name|m_target_arch
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

