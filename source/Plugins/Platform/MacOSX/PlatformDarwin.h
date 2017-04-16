begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformDarwin.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_PlatformDarwin_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformDarwin_h_
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
file|"Plugins/Platform/POSIX/PlatformPOSIX.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_decl_stmt
name|class
name|PlatformDarwin
range|:
name|public
name|PlatformPOSIX
block|{
name|public
operator|:
name|PlatformDarwin
argument_list|(
argument|bool is_host
argument_list|)
block|;
operator|~
name|PlatformDarwin
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
name|lldb_private
operator|::
name|Error
name|ResolveSymbolFile
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|const lldb_private::ModuleSpec&sym_spec
argument_list|,
argument|lldb_private::FileSpec&sym_file
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|FileSpecList
name|LocateExecutableScriptingResources
argument_list|(
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Module&module
argument_list|,
argument|lldb_private::Stream *feedback_stream
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|GetSharedModule
argument_list|(
argument|const lldb_private::ModuleSpec&module_spec
argument_list|,
argument|lldb_private::Process *process
argument_list|,
argument|lldb::ModuleSP&module_sp
argument_list|,
argument|const lldb_private::FileSpecList *module_search_paths_ptr
argument_list|,
argument|lldb::ModuleSP *old_module_sp_ptr
argument_list|,
argument|bool *did_create_ptr
argument_list|)
name|override
block|;
name|size_t
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|lldb_private::BreakpointSite *bp_site
argument_list|)
name|override
block|;
name|lldb
operator|::
name|BreakpointSP
name|SetThreadCreationBreakpoint
argument_list|(
argument|lldb_private::Target&target
argument_list|)
name|override
block|;
name|bool
name|ModuleIsExcludedForUnconstrainedSearches
argument_list|(
argument|lldb_private::Target&target
argument_list|,
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
name|bool
name|ARMGetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
block|;
name|bool
name|x86GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
block|;
name|int32_t
name|GetResumeCountForLaunchInfo
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|bool
name|GetOSVersion
argument_list|(
argument|uint32_t&major
argument_list|,
argument|uint32_t&minor
argument_list|,
argument|uint32_t&update
argument_list|,
argument|lldb_private::Process *process = nullptr
argument_list|)
name|override
block|;
name|bool
name|SupportsModules
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|lldb_private
operator|::
name|ConstString
name|GetFullNameForDylib
argument_list|(
argument|lldb_private::ConstString basename
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|FileSpec
name|LocateExecutable
argument_list|(
argument|const char *basename
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|LaunchProcess
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
specifier|static
name|std
operator|::
name|tuple
operator|<
name|uint32_t
block|,
name|uint32_t
block|,
name|uint32_t
block|,
name|llvm
operator|::
name|StringRef
operator|>
name|ParseVersionBuildDir
argument_list|(
argument|llvm::StringRef str
argument_list|)
block|;
name|protected
operator|:
name|void
name|ReadLibdispatchOffsetsAddress
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|void
name|ReadLibdispatchOffsets
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|GetSharedModuleWithLocalCache
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpecList
operator|*
name|module_search_paths_ptr
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|*
name|old_module_sp_ptr
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|)
block|;    enum
name|class
name|SDKType
block|{
name|MacOSX
operator|=
literal|0
block|,
name|iPhoneSimulator
block|,
name|iPhoneOS
block|,   }
block|;
specifier|static
name|bool
name|SDKSupportsModules
argument_list|(
argument|SDKType sdk_type
argument_list|,
argument|uint32_t major
argument_list|,
argument|uint32_t minor
argument_list|,
argument|uint32_t micro
argument_list|)
block|;
specifier|static
name|bool
name|SDKSupportsModules
argument_list|(
argument|SDKType desired_type
argument_list|,
argument|const lldb_private::FileSpec&sdk_path
argument_list|)
block|;    struct
name|SDKEnumeratorInfo
block|{
name|lldb_private
operator|::
name|FileSpec
name|found_path
block|;
name|SDKType
name|sdk_type
block|;   }
block|;
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|DirectoryEnumerator
argument_list|(
argument|void *baton
argument_list|,
argument|llvm::sys::fs::file_type file_type
argument_list|,
argument|const lldb_private::FileSpec&spec
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|FileSpec
name|FindSDKInXcodeForModules
argument_list|(
argument|SDKType sdk_type
argument_list|,
argument|const lldb_private::FileSpec&sdks_spec
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|FileSpec
name|GetSDKDirectoryForModules
argument_list|(
argument|PlatformDarwin::SDKType sdk_type
argument_list|)
block|;
name|void
name|AddClangModuleCompilationOptionsForSDKType
argument_list|(
argument|lldb_private::Target *target
argument_list|,
argument|std::vector<std::string>&options
argument_list|,
argument|SDKType sdk_type
argument_list|)
block|;
name|std
operator|::
name|string
name|m_developer_directory
block|;
specifier|const
name|char
operator|*
name|GetDeveloperDirectory
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformDarwin
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformDarwin_h_
end_comment

end_unit

