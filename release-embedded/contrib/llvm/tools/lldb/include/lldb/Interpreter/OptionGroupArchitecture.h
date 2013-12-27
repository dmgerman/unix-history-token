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
file|"lldb/Interpreter/Options.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
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
name|virtual
operator|~
name|OptionGroupArchitecture
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetNumDefinitions
argument_list|()
block|;
name|virtual
specifier|const
name|OptionDefinition
operator|*
name|GetDefinitions
argument_list|()
block|;
name|virtual
name|Error
name|SetOptionValue
argument_list|(
argument|CommandInterpreter&interpreter
argument_list|,
argument|uint32_t option_idx
argument_list|,
argument|const char *option_value
argument_list|)
block|;
name|virtual
name|void
name|OptionParsingStarting
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
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
specifier|const
name|char
operator|*
name|GetArchitectureName
argument_list|()
block|{
if|if
condition|(
name|m_arch_str
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_arch_str
operator|.
name|c_str
argument_list|()
return|;
block|}
name|protected
label|:
name|std
operator|::
name|string
name|m_arch_str
expr_stmt|;
comment|// Save the arch triple in case a platform is specified after the architecture
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

