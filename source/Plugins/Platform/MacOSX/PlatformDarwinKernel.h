begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformDarwinKernel.h ----------------------------------*- C++ -*-===//
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
name|liblldb_PlatformDarwinKernel_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformDarwinKernel_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_comment
comment|// This Plugin uses the Mac-specific source/Host/macosx/cfcpp utilities
end_comment

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"PlatformDarwin.h"
end_include

begin_decl_stmt
name|class
name|PlatformDarwinKernel
range|:
name|public
name|PlatformDarwin
block|{
name|public
operator|:
comment|//------------------------------------------------------------
comment|// Class Functions
comment|//------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|PlatformSP
name|CreateInstance
argument_list|(
argument|bool force
argument_list|,
argument|const lldb_private::ArchSpec *arch
argument_list|)
block|;
specifier|static
name|void
name|DebuggerInitialize
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetDescriptionStatic
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// Class Methods
comment|//------------------------------------------------------------
name|PlatformDarwinKernel
argument_list|(
argument|lldb_private::LazyBool is_ios_debug_session
argument_list|)
block|;
name|virtual
operator|~
name|PlatformDarwinKernel
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// lldb_private::PluginInterface functions
comment|//------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|{
return|return
name|GetPluginNameStatic
argument_list|()
return|;
block|}
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|{
return|return
literal|1
return|;
block|}
comment|//------------------------------------------------------------
comment|// lldb_private::Platform functions
comment|//------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
name|override
block|{
return|return
name|GetDescriptionStatic
argument_list|()
return|;
block|}
name|void
name|GetStatus
argument_list|(
argument|lldb_private::Stream&strm
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
name|bool
name|GetSupportedArchitectureAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::ArchSpec&arch
argument_list|)
name|override
block|;
name|bool
name|SupportsModules
argument_list|()
name|override
block|{
return|return
name|false
return|;
block|}
name|void
name|CalculateTrapHandlerSymbolNames
argument_list|()
name|override
block|;
name|protected
operator|:
comment|// Map from kext bundle ID ("com.apple.filesystems.exfat") to FileSpec for the kext bundle on
comment|// the host ("/System/Library/Extensions/exfat.kext/Contents/Info.plist").
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|lldb_private
operator|::
name|ConstString
operator|,
name|lldb_private
operator|::
name|FileSpec
operator|>
name|BundleIDToKextMap
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|BundleIDToKextMap
operator|::
name|iterator
name|BundleIDToKextIterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
name|KernelBinaryCollection
expr_stmt|;
end_typedef

begin_comment
comment|// Array of directories that were searched for kext bundles (used only for reporting to user)
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
name|DirectoriesSearchedCollection
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DirectoriesSearchedCollection
operator|::
name|iterator
name|DirectoriesSearchedIterator
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|GetKextDirectoriesInSDK
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::FileSpec::FileType file_type
argument_list|,
argument|const lldb_private::FileSpec&file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|GetKextsInDirectory
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::FileSpec::FileType file_type
argument_list|,
argument|const lldb_private::FileSpec&file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Populate m_search_directories vector of directories
end_comment

begin_function_decl
name|void
name|CollectKextAndKernelDirectories
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Directories where we may find iOS SDKs with kext bundles in them
end_comment

begin_decl_stmt
name|void
name|GetiOSSDKDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find AppleTVOS SDKs with kext bundles in them
end_comment

begin_decl_stmt
name|void
name|GetAppleTVOSSDKDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find WatchOS SDKs with kext bundles in them
end_comment

begin_decl_stmt
name|void
name|GetWatchOSSDKDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find Mac OS X SDKs with kext bundles in them
end_comment

begin_decl_stmt
name|void
name|GetMacSDKDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find Mac OS X or iOS SDKs with kext bundles in them
end_comment

begin_decl_stmt
name|void
name|GetGenericSDKDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find iOS kext bundles
end_comment

begin_decl_stmt
name|void
name|GetiOSDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find MacOSX kext bundles
end_comment

begin_decl_stmt
name|void
name|GetMacDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find iOS or MacOSX kext bundles
end_comment

begin_decl_stmt
name|void
name|GetGenericDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories specified via the "kext-directories" setting - maybe KDK/SDKs, may be plain directories
end_comment

begin_decl_stmt
name|void
name|GetUserSpecifiedDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|GetCurrentDirectoryToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Directories where we may find kernels exclusively
end_comment

begin_decl_stmt
name|void
name|GetKernelDirectoriesToSearch
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|directories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Search through a vector of SDK FileSpecs, add any directories that may contain kexts
end_comment

begin_comment
comment|// to the vector of kext dir FileSpecs
end_comment

begin_decl_stmt
name|void
name|SearchSDKsForKextDirectories
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
name|sdk_dirs
argument_list|,
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
operator|&
name|kext_dirs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Search through all of the directories passed in, find all .kext bundles in those directories,
end_comment

begin_comment
comment|// get the CFBundleIDs out of the Info.plists and add the bundle ID and kext path to m_name_to_kext_path_map.
end_comment

begin_function_decl
name|void
name|IndexKextsInDirectories
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Search through all of the directories passed in, find all kernel binaries in those directories
end_comment

begin_comment
comment|// (look for "kernel*", "mach.*", assume those are kernels.  False positives aren't a huge problem.)
end_comment

begin_function_decl
name|void
name|IndexKernelsInDirectories
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Callback which iterates over all the files in a given directory, looking for kernel binaries
end_comment

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|GetKernelsInDirectory
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::FileSpec::FileType file_type
argument_list|,
argument|const lldb_private::FileSpec&file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|ExamineKextForMatchingUUID
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|kext_bundle_path
argument_list|,
specifier|const
name|lldb_private
operator|::
name|UUID
operator|&
name|uuid
argument_list|,
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|exe_module_sp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|BundleIDToKextMap
name|m_name_to_kext_path_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|// multimap of CFBundleID to FileSpec on local filesystem
end_comment

begin_decl_stmt
name|DirectoriesSearchedCollection
name|m_search_directories
decl_stmt|;
end_decl_stmt

begin_comment
comment|// list of directories we search for kexts/kernels
end_comment

begin_decl_stmt
name|KernelBinaryCollection
name|m_kernel_binaries
decl_stmt|;
end_decl_stmt

begin_comment
comment|// list of kernel binaries we found on local filesystem
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|LazyBool
name|m_ios_debug_session
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformDarwinKernel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
unit|};
else|#
directive|else
end_else

begin_comment
comment|// __APPLE__
end_comment

begin_comment
comment|// Since DynamicLoaderDarwinKernel is compiled in for all systems, and relies on
end_comment

begin_comment
comment|// PlatformDarwinKernel for the plug-in name, we compile just the plug-in name in
end_comment

begin_comment
comment|// here to avoid issues. We are tracking an internal bug to resolve this issue by
end_comment

begin_comment
comment|// either not compiling in DynamicLoaderDarwinKernel for non-apple builds, or to make
end_comment

begin_comment
comment|// PlatformDarwinKernel build on all systems. PlatformDarwinKernel is currently not
end_comment

begin_comment
comment|// compiled on other platforms due to the use of the Mac-specific
end_comment

begin_comment
comment|// source/Host/macosx/cfcpp utilities.
end_comment

begin_decl_stmt
name|class
name|PlatformDarwinKernel
block|{
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __APPLE__
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformDarwinKernel_h_
end_comment

end_unit

