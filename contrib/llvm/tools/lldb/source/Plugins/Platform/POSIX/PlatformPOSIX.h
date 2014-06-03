begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformPOSIX.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformPOSIX_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformPOSIX_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

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
file|"lldb/Target/Platform.h"
end_include

begin_decl_stmt
name|class
name|PlatformPOSIX
range|:
name|public
name|lldb_private
operator|::
name|Platform
block|{
name|public
operator|:
name|PlatformPOSIX
argument_list|(
argument|bool is_host
argument_list|)
block|;
name|virtual
operator|~
name|PlatformPOSIX
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|OptionGroupOptions
operator|*
name|GetConnectionOptions
argument_list|(
name|lldb_private
operator|::
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|PutFile
argument_list|(
argument|const lldb_private::FileSpec& source
argument_list|,
argument|const lldb_private::FileSpec& destination
argument_list|,
argument|uint32_t uid = UINT32_MAX
argument_list|,
argument|uint32_t gid = UINT32_MAX
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const lldb_private::FileSpec& file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|uint64_t
name|ReadFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|void *dst
argument_list|,
argument|uint64_t dst_len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|uint64_t
name|WriteFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|const void* src
argument_list|,
argument|uint64_t src_len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|CreateSymlink
argument_list|(
specifier|const
name|char
operator|*
name|src
argument_list|,
specifier|const
name|char
operator|*
name|dst
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetFile
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|source
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|destination
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetRemoteWorkingDirectory
argument_list|()
block|;
name|virtual
name|bool
name|SetRemoteWorkingDirectory
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|path
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be NULL
argument|const char *working_dir
argument_list|,
comment|// Pass NULL to use the current working directory
argument|int *status_ptr
argument_list|,
comment|// Pass NULL if you don't want the process exit status
argument|int *signo_ptr
argument_list|,
comment|// Pass NULL if you don't want the signal that caused the process to exit
argument|std::string *command_output
argument_list|,
comment|// Pass NULL if you don't want the command output
argument|uint32_t timeout_sec
argument_list|)
block|;
comment|// Timeout in seconds to wait for shell program to finish
name|virtual
name|lldb_private
operator|::
name|Error
name|MakeDirectory
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t mode
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetFilePermissions
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|uint32_t
operator|&
name|file_permissions
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|SetFilePermissions
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t file_permissions
argument_list|)
block|;
name|virtual
name|bool
name|GetFileExists
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|Unlink
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
name|virtual
name|std
operator|::
name|string
name|GetPlatformSpecificConnectionInformation
argument_list|()
block|;
name|virtual
name|bool
name|CalculateMD5
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|uint64_t
operator|&
name|low
argument_list|,
name|uint64_t
operator|&
name|high
argument_list|)
block|;
name|virtual
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|OptionGroupOptions
operator|>
name|m_options
block|;
name|lldb
operator|::
name|PlatformSP
name|m_remote_platform_sp
block|;
comment|// Allow multiple ways to connect to a remote POSIX-compliant OS
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformPOSIX
argument_list|)
block|;      }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformPOSIX_h_
end_comment

end_unit

