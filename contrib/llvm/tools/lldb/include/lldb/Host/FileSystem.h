begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FileSystem.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_Host_FileSystem_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_FileSystem_h
end_define

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
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FileSystem
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|DEV_NULL
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|PATH_CONVERSION_ERROR
decl_stmt|;
specifier|static
name|Status
name|Symlink
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|src
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|dst
parameter_list|)
function_decl|;
specifier|static
name|Status
name|Readlink
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|src
parameter_list|,
name|FileSpec
modifier|&
name|dst
parameter_list|)
function_decl|;
specifier|static
name|Status
name|ResolveSymbolicLink
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|src
parameter_list|,
name|FileSpec
modifier|&
name|dst
parameter_list|)
function_decl|;
comment|/// Wraps ::fopen in a platform-independent way. Once opened, FILEs can be
comment|/// manipulated and closed with the normal ::fread, ::fclose, etc. functions.
specifier|static
name|FILE
modifier|*
name|Fopen
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
specifier|static
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|GetModificationTime
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

