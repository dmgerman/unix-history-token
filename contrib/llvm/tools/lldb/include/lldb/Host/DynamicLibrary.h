begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLibrary.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_DynamicLibrary_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLibrary_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Host.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DynamicLibrary
block|{
name|public
label|:
name|DynamicLibrary
argument_list|(
argument|const FileSpec& spec
argument_list|,
argument|uint32_t options = Host::eDynamicLibraryOpenOptionLazy |                                                              Host::eDynamicLibraryOpenOptionLocal |                                                              Host::eDynamicLibraryOpenOptionLimitGetSymbol
argument_list|)
empty_stmt|;
operator|~
name|DynamicLibrary
argument_list|()
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|=
name|void
operator|*
operator|>
name|T
name|GetSymbol
argument_list|(
argument|const char* name
argument_list|)
block|{
name|Error
name|err
block|;
if|if
condition|(
operator|!
name|m_handle
condition|)
return|return
operator|(
name|T
operator|)
name|NULL
return|;
name|void
operator|*
name|symbol
operator|=
name|Host
operator|::
name|DynamicLibraryGetSymbol
argument_list|(
name|m_handle
argument_list|,
name|name
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|symbol
condition|)
return|return
operator|(
name|T
operator|)
name|NULL
return|;
return|return
operator|(
name|T
operator|)
name|symbol
return|;
block|}
name|bool
name|IsValid
parameter_list|()
function_decl|;
name|private
label|:
name|lldb_private
operator|::
name|FileSpec
name|m_filespec
expr_stmt|;
name|void
modifier|*
name|m_handle
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLibrary
argument_list|)
expr_stmt|;
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
comment|// liblldb_DynamicLibrary_h_
end_comment

end_unit

