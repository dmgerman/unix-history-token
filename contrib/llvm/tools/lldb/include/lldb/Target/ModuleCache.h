begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModuleCache.h -------------------------------------------*- C++ -*-===//
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
name|LLDB_TARGET_MODULECACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_TARGET_MODULECACHE_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/File.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Module
decl_stmt|;
name|class
name|UUID
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ModuleCache ModuleCache.h "lldb/Target/ModuleCache.h"
comment|/// @brief A module cache class.
comment|///
comment|/// Caches locally modules that are downloaded from remote targets.
comment|/// Each cached module maintains 2 views:
comment|///  - UUID view:
comment|///  /${CACHE_ROOT}/${PLATFORM_NAME}/.cache/${UUID}/${MODULE_FILENAME}
comment|///  - Sysroot view:
comment|///  /${CACHE_ROOT}/${PLATFORM_NAME}/${HOSTNAME}/${MODULE_FULL_FILEPATH}
comment|///
comment|/// UUID views stores a real module file, whereas Sysroot view holds a symbolic
comment|/// link to UUID-view file.
comment|///
comment|/// Example:
comment|/// UUID view   :
comment|/// /tmp/lldb/remote-linux/.cache/30C94DC6-6A1F-E951-80C3-D68D2B89E576-D5AE213C/libc.so.6
comment|/// Sysroot view: /tmp/lldb/remote-linux/ubuntu/lib/x86_64-linux-gnu/libc.so.6
comment|//----------------------------------------------------------------------
name|class
name|ModuleCache
block|{
name|public
label|:
name|using
name|ModuleDownloader
init|=
name|std
operator|::
name|function
operator|<
name|Status
argument_list|(
specifier|const
name|ModuleSpec
operator|&
argument_list|,
specifier|const
name|FileSpec
operator|&
argument_list|)
operator|>
decl_stmt|;
name|using
name|SymfileDownloader
init|=
name|std
operator|::
name|function
operator|<
name|Status
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
argument_list|,
specifier|const
name|FileSpec
operator|&
argument_list|)
operator|>
decl_stmt|;
name|Status
name|GetAndPut
argument_list|(
specifier|const
name|FileSpec
operator|&
name|root_dir_spec
argument_list|,
specifier|const
name|char
operator|*
name|hostname
argument_list|,
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
specifier|const
name|ModuleDownloader
operator|&
name|module_downloader
argument_list|,
specifier|const
name|SymfileDownloader
operator|&
name|symfile_downloader
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|cached_module_sp
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|)
decl_stmt|;
name|private
label|:
name|Status
name|Put
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|root_dir_spec
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
specifier|const
name|ModuleSpec
modifier|&
name|module_spec
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|tmp_file
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|target_file
parameter_list|)
function_decl|;
name|Status
name|Get
argument_list|(
specifier|const
name|FileSpec
operator|&
name|root_dir_spec
argument_list|,
specifier|const
name|char
operator|*
name|hostname
argument_list|,
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|cached_module_sp
argument_list|,
name|bool
operator|*
name|did_create_ptr
argument_list|)
decl_stmt|;
name|std
operator|::
name|unordered_map
operator|<
name|std
operator|::
name|string
operator|,
name|lldb
operator|::
name|ModuleWP
operator|>
name|m_loaded_modules
expr_stmt|;
block|}
empty_stmt|;
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
comment|// utility_ModuleCache_h_
end_comment

end_unit

