begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostInfoBase.h ------------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostInfoBase_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostInfoBase_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FileSpec
decl_stmt|;
name|class
name|HostInfoBase
block|{
name|private
label|:
comment|// Static class, unconstructable.
name|HostInfoBase
argument_list|()
block|{}
operator|~
name|HostInfoBase
argument_list|()
block|{}
name|public
operator|:
specifier|static
name|void
name|Initialize
argument_list|()
expr_stmt|;
specifier|static
name|void
name|Terminate
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the host target triple as a const string.
comment|///
comment|/// @return
comment|///     A const string object containing the host target triple.
comment|//------------------------------------------------------------------
specifier|static
name|llvm
operator|::
name|StringRef
name|GetTargetTriple
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the host architecture.
comment|///
comment|/// @return
comment|///     A const architecture object that represents the host
comment|///     architecture.
comment|//------------------------------------------------------------------
enum|enum
name|ArchitectureKind
block|{
name|eArchKindDefault
block|,
comment|// The overall default architecture that applications will
comment|// run on this host
name|eArchKind32
block|,
comment|// If this host supports 32 bit programs, return the default 32
comment|// bit arch
name|eArchKind64
comment|// If this host supports 64 bit programs, return the default 64
comment|// bit arch
block|}
enum|;
specifier|static
specifier|const
name|ArchSpec
modifier|&
name|GetArchitecture
parameter_list|(
name|ArchitectureKind
name|arch_kind
init|=
name|eArchKindDefault
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find a resource files that are related to LLDB.
comment|///
comment|/// Operating systems have different ways of storing shared
comment|/// libraries and related resources. This function abstracts the
comment|/// access to these paths.
comment|///
comment|/// @param[in] path_type
comment|///     The type of LLDB resource path you are looking for. If the
comment|///     enumeration ends with "Dir", then only the \a file_spec's
comment|///     directory member gets filled in.
comment|///
comment|/// @param[in] file_spec
comment|///     A file spec that gets filled in with the appropriate path.
comment|///
comment|/// @return
comment|///     \b true if \a resource_path was resolved, \a false otherwise.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|GetLLDBPath
argument_list|(
name|lldb
operator|::
name|PathType
name|type
argument_list|,
name|FileSpec
operator|&
name|file_spec
argument_list|)
decl_stmt|;
name|protected
label|:
specifier|static
name|bool
name|ComputeSharedLibraryDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeSupportExeDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeProcessTempFileDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeGlobalTempFileDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeTempFileBaseDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeHeaderDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeSystemPluginsDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeClangDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ComputeUserPluginsDirectory
parameter_list|(
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
function_decl|;
specifier|static
name|void
name|ComputeHostArchitectureSupport
parameter_list|(
name|ArchSpec
modifier|&
name|arch_32
parameter_list|,
name|ArchSpec
modifier|&
name|arch_64
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

