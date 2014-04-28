begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-private.h ------------------------------------------*- C++ -*-===//
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
name|lldb_lldb_private_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_lldb_private_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|"lldb/Host/windows/win32.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-interfaces.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-log.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|/// Initializes lldb.
comment|///
comment|/// This function should be called prior to using any lldb
comment|/// classes to ensure they have a chance to do any static
comment|/// initialization that they need to do.
comment|//------------------------------------------------------------------
name|void
name|Initialize
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Notifies any classes that lldb will be terminating soon.
comment|///
comment|/// This function will be called when the Debugger shared instance
comment|/// is being destructed and will give classes the ability to clean
comment|/// up any threads or other resources they have that they might not
comment|/// be able to clean up in their own destructors.
comment|///
comment|/// Internal classes that need this ability will need to add their
comment|/// void T::WillTerminate() method in the body of this function in
comment|/// lldb.cpp to ensure it will get called.
comment|///
comment|/// TODO: when we start having external plug-ins, we will need a way
comment|/// for plug-ins to register a WillTerminate callback.
comment|//------------------------------------------------------------------
name|void
name|WillTerminate
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Terminates lldb
comment|///
comment|/// This function optionally can be called when clients are done
comment|/// using lldb functionality to free up any static resources
comment|/// that have been allocated during initialization or during
comment|/// function calls. No lldb functions should be called after
comment|/// calling this function without again calling DCInitialize()
comment|/// again.
comment|//------------------------------------------------------------------
name|void
name|Terminate
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetVersion
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetVoteAsCString
parameter_list|(
name|Vote
name|vote
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetSectionTypeAsCString
argument_list|(
name|lldb
operator|::
name|SectionType
name|sect_type
argument_list|)
decl_stmt|;
name|bool
name|NameMatches
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|NameMatchType
name|match_type
parameter_list|,
specifier|const
name|char
modifier|*
name|match
parameter_list|)
function_decl|;
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
comment|// defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_lldb_private_h_
end_comment

end_unit

