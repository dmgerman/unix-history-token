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
file|"lldb/Utility/ConstString.h"
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
comment|// This Plugin uses the Mac-specific
end_comment

begin_comment
comment|// source/Host/macosx/cfcpp utilities
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
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
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
name|Status
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
comment|// Map from kext bundle ID ("com.apple.filesystems.exfat") to FileSpec for the
comment|// kext bundle on
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
comment|// Array of directories that were searched for kext bundles (used only for
end_comment

begin_comment
comment|// reporting to user)
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

begin_comment
comment|// Populate m_search_directories and m_search_directories_no_recursing vectors
end_comment

begin_comment
comment|// of directories
end_comment

begin_function_decl
name|void
name|CollectKextAndKernelDirectories
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetUserSpecifiedDirectoriesToSearch
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|void
name|AddRootSubdirsToSearchPaths
argument_list|(
name|PlatformDarwinKernel
operator|*
name|thisp
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|dir
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddSDKSubdirsToSearchPaths
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|dir
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|FindKDKandSDKDirectoriesInDirectory
argument_list|(
argument|void *baton
argument_list|,
argument|llvm::sys::fs::file_type ft
argument_list|,
argument|const lldb_private::FileSpec&file_spec
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|SearchForKextsAndKernelsRecursively
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|FileSpec
operator|::
name|EnumerateDirectoryResult
name|GetKernelsAndKextsInDirectoryWithRecursion
argument_list|(
argument|void *baton
argument_list|,
argument|llvm::sys::fs::file_type ft
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
name|GetKernelsAndKextsInDirectoryNoRecursion
argument_list|(
argument|void *baton
argument_list|,
argument|llvm::sys::fs::file_type ft
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
name|GetKernelsAndKextsInDirectoryHelper
argument_list|(
argument|void *baton
argument_list|,
argument|llvm::sys::fs::file_type ft
argument_list|,
argument|const lldb_private::FileSpec&file_spec
argument_list|,
argument|bool recurse
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|void
name|AddKextToMap
argument_list|(
name|PlatformDarwinKernel
operator|*
name|thisp
argument_list|,
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns true if there is a .dSYM bundle next to the kext, or next to the
end_comment

begin_comment
comment|// binary inside the kext.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|KextHasdSYMSibling
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|kext_bundle_filepath
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns true if there is a .dSYM bundle next to the kernel
end_comment

begin_decl_stmt
specifier|static
name|bool
name|KernelHasdSYMSibling
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|kext_bundle_filepath
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Status
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

begin_comment
comment|// Most of the ivars are assembled under FileSpec::EnumerateDirectory calls
end_comment

begin_comment
comment|// where the
end_comment

begin_comment
comment|// function being called for each file/directory must be static.  We'll pass a
end_comment

begin_comment
comment|// this pointer
end_comment

begin_comment
comment|// as a baton and access the ivars directly.  Toss-up whether this should just
end_comment

begin_comment
comment|// be a struct
end_comment

begin_comment
comment|// at this point.
end_comment

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|BundleIDToKextMap
name|m_name_to_kext_path_map_with_dsyms
decl_stmt|;
end_decl_stmt

begin_comment
comment|// multimap of
end_comment

begin_comment
comment|// CFBundleID to
end_comment

begin_comment
comment|// FileSpec on local
end_comment

begin_comment
comment|// filesystem, kexts
end_comment

begin_comment
comment|// with dSYMs next to
end_comment

begin_comment
comment|// them
end_comment

begin_decl_stmt
name|BundleIDToKextMap
name|m_name_to_kext_path_map_without_dsyms
decl_stmt|;
end_decl_stmt

begin_comment
comment|// multimap of
end_comment

begin_comment
comment|// CFBundleID to
end_comment

begin_comment
comment|// FileSpec on local
end_comment

begin_comment
comment|// filesystem, kexts
end_comment

begin_comment
comment|// without dSYMs next
end_comment

begin_comment
comment|// to them
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
name|DirectoriesSearchedCollection
name|m_search_directories_no_recursing
decl_stmt|;
end_decl_stmt

begin_comment
comment|// list of directories we search for
end_comment

begin_comment
comment|// kexts/kernels, no recursion
end_comment

begin_decl_stmt
name|KernelBinaryCollection
name|m_kernel_binaries_with_dsyms
decl_stmt|;
end_decl_stmt

begin_comment
comment|// list of kernel
end_comment

begin_comment
comment|// binaries we found on
end_comment

begin_comment
comment|// local filesystem,
end_comment

begin_comment
comment|// without dSYMs next to
end_comment

begin_comment
comment|// them
end_comment

begin_decl_stmt
name|KernelBinaryCollection
name|m_kernel_binaries_without_dsyms
decl_stmt|;
end_decl_stmt

begin_comment
comment|// list of kernel
end_comment

begin_comment
comment|// binaries we found
end_comment

begin_comment
comment|// on local
end_comment

begin_comment
comment|// filesystem, with
end_comment

begin_comment
comment|// dSYMs next to them
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
comment|// PlatformDarwinKernel for the plug-in name, we compile just the plug-in name
end_comment

begin_comment
comment|// in
end_comment

begin_comment
comment|// here to avoid issues. We are tracking an internal bug to resolve this issue
end_comment

begin_comment
comment|// by
end_comment

begin_comment
comment|// either not compiling in DynamicLoaderDarwinKernel for non-apple builds, or to
end_comment

begin_comment
comment|// make
end_comment

begin_comment
comment|// PlatformDarwinKernel build on all systems. PlatformDarwinKernel is currently
end_comment

begin_comment
comment|// not
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

