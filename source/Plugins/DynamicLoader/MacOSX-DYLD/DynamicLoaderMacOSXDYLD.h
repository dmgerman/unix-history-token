begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderMacOSXDYLD.h -------------------------------*- C++ -*-===//
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

begin_comment
comment|// This is the DynamicLoader plugin for Darwin (macOS / iPhoneOS / tvOS /
end_comment

begin_comment
comment|// watchOS)
end_comment

begin_comment
comment|// platforms earlier than 2016, where lldb would read the "dyld_all_image_infos"
end_comment

begin_comment
comment|// dyld internal structure to understand where things were loaded and the
end_comment

begin_comment
comment|// solib loaded/unloaded notification function we put a breakpoint on gives us
end_comment

begin_comment
comment|// an array of (load address, mod time, file path) tuples.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// As of late 2016, the new DynamicLoaderMacOS plugin should be used, which uses
end_comment

begin_comment
comment|// dyld SPI functions to get the same information without reading internal dyld
end_comment

begin_comment
comment|// data structures.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_DynamicLoaderMacOSXDYLD_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoaderMacOSXDYLD_h_
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
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
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
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/DynamicLoader.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/SafeMachO.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"DynamicLoaderDarwin.h"
end_include

begin_decl_stmt
name|class
name|DynamicLoaderMacOSXDYLD
range|:
name|public
name|lldb_private
operator|::
name|DynamicLoaderDarwin
block|{
name|public
operator|:
name|DynamicLoaderMacOSXDYLD
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
operator|~
name|DynamicLoaderMacOSXDYLD
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
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
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|CreateInstance
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|bool force
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Called after attaching a process.
comment|///
comment|/// Allow DynamicLoader plug-ins to execute some code after
comment|/// attaching to a process.
comment|//------------------------------------------------------------------
name|bool
name|ProcessDidExec
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|Error
name|CanLoadImage
argument_list|()
name|override
block|;
name|bool
name|GetSharedCacheInformation
argument_list|(
argument|lldb::addr_t&base_address
argument_list|,
argument|lldb_private::UUID&uuid
argument_list|,
argument|lldb_private::LazyBool&using_shared_cache
argument_list|,
argument|lldb_private::LazyBool&private_shared_cache
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|protected
operator|:
name|void
name|PutToLog
argument_list|(
argument|lldb_private::Log *log
argument_list|)
specifier|const
block|;
name|void
name|DoInitialImageFetch
argument_list|()
name|override
block|;
name|bool
name|NeedToDoInitialImageFetch
argument_list|()
name|override
block|;
name|bool
name|DidSetNotificationBreakpoint
argument_list|()
name|override
block|;
name|void
name|DoClear
argument_list|()
name|override
block|;
name|bool
name|ReadDYLDInfoFromMemoryAndSetNotificationCallback
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
specifier|static
name|bool
name|NotifyBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
name|uint32_t
name|AddrByteSize
argument_list|()
block|;
name|bool
name|ReadMachHeader
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|llvm::MachO::mach_header *header
argument_list|,
argument|lldb_private::DataExtractor *load_command_data
argument_list|)
block|;
name|uint32_t
name|ParseLoadCommands
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|ImageInfo
operator|&
name|dylib_info
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|*
name|lc_id_dylinker
argument_list|)
block|;    struct
name|DYLDAllImageInfos
block|{
name|uint32_t
name|version
block|;
name|uint32_t
name|dylib_info_count
block|;
comment|// Version>= 1
name|lldb
operator|::
name|addr_t
name|dylib_info_addr
block|;
comment|// Version>= 1
name|lldb
operator|::
name|addr_t
name|notification
block|;
comment|// Version>= 1
name|bool
name|processDetachedFromSharedRegion
block|;
comment|// Version>= 1
name|bool
name|libSystemInitialized
block|;
comment|// Version>= 2
name|lldb
operator|::
name|addr_t
name|dyldImageLoadAddress
block|;
comment|// Version>= 2
name|DYLDAllImageInfos
argument_list|()
operator|:
name|version
argument_list|(
literal|0
argument_list|)
block|,
name|dylib_info_count
argument_list|(
literal|0
argument_list|)
block|,
name|dylib_info_addr
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
block|,
name|notification
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
block|,
name|processDetachedFromSharedRegion
argument_list|(
name|false
argument_list|)
block|,
name|libSystemInitialized
argument_list|(
name|false
argument_list|)
block|,
name|dyldImageLoadAddress
argument_list|(
argument|LLDB_INVALID_ADDRESS
argument_list|)
block|{}
name|void
name|Clear
argument_list|()
block|{
name|version
operator|=
literal|0
block|;
name|dylib_info_count
operator|=
literal|0
block|;
name|dylib_info_addr
operator|=
name|LLDB_INVALID_ADDRESS
block|;
name|notification
operator|=
name|LLDB_INVALID_ADDRESS
block|;
name|processDetachedFromSharedRegion
operator|=
name|false
block|;
name|libSystemInitialized
operator|=
name|false
block|;
name|dyldImageLoadAddress
operator|=
name|LLDB_INVALID_ADDRESS
block|;     }
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|version
operator|>=
literal|1
operator|||
name|version
operator|<=
literal|6
return|;
block|}
expr|}
block|;
specifier|static
name|lldb
operator|::
name|ByteOrder
name|GetByteOrderFromMagic
argument_list|(
argument|uint32_t magic
argument_list|)
block|;
name|bool
name|SetNotificationBreakpoint
argument_list|()
name|override
block|;
name|void
name|ClearNotificationBreakpoint
argument_list|()
name|override
block|;
comment|// There is a little tricky bit where you might initially attach while dyld is
comment|// updating
comment|// the all_image_infos, and you can't read the infos, so you have to continue
comment|// and pick it
comment|// up when you hit the update breakpoint.  At that point, you need to run this
comment|// initialize
comment|// function, but when you do it that way you DON'T need to do the extra work
comment|// you would at
comment|// the breakpoint.
comment|// So this function will only do actual work if the image infos haven't been
comment|// read yet.
comment|// If it does do any work, then it will return true, and false otherwise.
comment|// That way you can
comment|// call it in the breakpoint action, and if it returns true you're done.
name|bool
name|InitializeFromAllImageInfos
argument_list|()
block|;
name|bool
name|ReadAllImageInfosStructure
argument_list|()
block|;
name|bool
name|AddModulesUsingImageInfosAddress
argument_list|(
argument|lldb::addr_t image_infos_addr
argument_list|,
argument|uint32_t image_infos_count
argument_list|)
block|;
name|bool
name|RemoveModulesUsingImageInfosAddress
argument_list|(
argument|lldb::addr_t image_infos_addr
argument_list|,
argument|uint32_t image_infos_count
argument_list|)
block|;
name|void
name|UpdateImageInfosHeaderAndLoadCommands
argument_list|(
argument|ImageInfo::collection&image_infos
argument_list|,
argument|uint32_t infos_count
argument_list|,
argument|bool update_executable
argument_list|)
block|;
name|bool
name|ReadImageInfos
argument_list|(
argument|lldb::addr_t image_infos_addr
argument_list|,
argument|uint32_t image_infos_count
argument_list|,
argument|ImageInfo::collection&image_infos
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|m_dyld_all_image_infos_addr
block|;
name|DYLDAllImageInfos
name|m_dyld_all_image_infos
block|;
name|uint32_t
name|m_dyld_all_image_infos_stop_id
block|;
name|lldb
operator|::
name|user_id_t
name|m_break_id
block|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
block|;
name|bool
name|m_process_image_addr_is_all_images_infos
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoaderMacOSXDYLD
argument_list|)
block|; }
block|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoaderMacOSXDYLD_h_
end_comment

end_unit

