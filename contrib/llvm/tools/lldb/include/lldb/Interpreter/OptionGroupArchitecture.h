begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionGroupArchitecture.h -------------------------------*- C++ -*-===//
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
name|liblldb_OptionGroupArchitecture_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionGroupArchitecture_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Options.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//-------------------------------------------------------------------------
comment|// OptionGroupArchitecture
comment|//-------------------------------------------------------------------------
name|class
name|OptionGroupArchitecture
range|:
name|public
name|OptionGroup
block|{
name|public
operator|:
name|OptionGroupArchitecture
argument_list|()
block|;
operator|~
name|OptionGroupArchitecture
argument_list|()
name|override
block|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|OptionDefinition
operator|>
name|GetDefinitions
argument_list|()
name|override
block|;
name|Status
name|SetOptionValue
argument_list|(
argument|uint32_t option_idx
argument_list|,
argument|llvm::StringRef option_value
argument_list|,
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|void
name|OptionParsingStarting
argument_list|(
argument|ExecutionContext *execution_context
argument_list|)
name|override
block|;
name|bool
name|GetArchitecture
argument_list|(
name|Platform
operator|*
name|platform
argument_list|,
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|bool
name|ArchitectureWasSpecified
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_arch_str
operator|.
name|empty
argument_list|()
return|;
block|}
name|llvm
operator|::
name|StringRef
name|GetArchitectureName
argument_list|()
specifier|const
block|{
return|return
name|m_arch_str
return|;
block|}
name|protected
operator|:
name|std
operator|::
name|string
name|m_arch_str
block|;
comment|// Save the arch triple in case a platform is
comment|// specified after the architecture
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OptionGroupArchitecture_h_
end_comment

end_unit

