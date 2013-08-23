begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBModuleSpec.h ------------------------------------------*- C++ -*-===//
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
name|LLDB_SBModuleSpec_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBModuleSpec_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBFileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBModuleSpec
block|{
name|public
label|:
name|SBModuleSpec
argument_list|()
expr_stmt|;
name|SBModuleSpec
argument_list|(
specifier|const
name|SBModuleSpec
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBModuleSpec
argument_list|()
expr_stmt|;
specifier|const
name|SBModuleSpec
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBModuleSpec
operator|&
name|rhs
operator|)
decl_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the module file.
comment|///
comment|/// This function returns the file for the module on the host system
comment|/// that is running LLDB. This can differ from the path on the
comment|/// platform since we might be doing remote debugging.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBFileSpec
name|GetFileSpec
argument_list|()
expr_stmt|;
name|void
name|SetFileSpec
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|fspec
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the module platform file.
comment|///
comment|/// Platform file refers to the path of the module as it is known on
comment|/// the remote system on which it is being debugged. For local
comment|/// debugging this is always the same as Module::GetFileSpec(). But
comment|/// remote debugging might mention a file '/usr/lib/liba.dylib'
comment|/// which might be locally downloaded and cached. In this case the
comment|/// platform file could be something like:
comment|/// '/tmp/lldb/platform-cache/remote.host.computer/usr/lib/liba.dylib'
comment|/// The file could also be cached in a local developer kit directory.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBFileSpec
name|GetPlatformFileSpec
argument_list|()
expr_stmt|;
name|void
name|SetPlatformFileSpec
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|fspec
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBFileSpec
name|GetSymbolFileSpec
argument_list|()
expr_stmt|;
name|void
name|SetSymbolFileSpec
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|fspec
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetObjectName
parameter_list|()
function_decl|;
name|void
name|SetObjectName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetTriple
parameter_list|()
function_decl|;
name|void
name|SetTriple
parameter_list|(
specifier|const
name|char
modifier|*
name|triple
parameter_list|)
function_decl|;
specifier|const
name|uint8_t
modifier|*
name|GetUUIDBytes
parameter_list|()
function_decl|;
name|size_t
name|GetUUIDLength
parameter_list|()
function_decl|;
name|bool
name|SetUUIDBytes
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|uuid
parameter_list|,
name|size_t
name|uuid_len
parameter_list|)
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|SBModuleSpecList
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|ModuleSpec
operator|>
name|m_opaque_ap
expr_stmt|;
block|}
empty_stmt|;
name|class
name|SBModuleSpecList
block|{
name|public
label|:
name|SBModuleSpecList
argument_list|()
expr_stmt|;
name|SBModuleSpecList
argument_list|(
specifier|const
name|SBModuleSpecList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBModuleSpecList
argument_list|()
expr_stmt|;
name|SBModuleSpecList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBModuleSpecList
operator|&
name|rhs
operator|)
decl_stmt|;
specifier|static
name|SBModuleSpecList
name|GetModuleSpecifications
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
name|void
name|Append
parameter_list|(
specifier|const
name|SBModuleSpec
modifier|&
name|spec
parameter_list|)
function_decl|;
name|void
name|Append
parameter_list|(
specifier|const
name|SBModuleSpecList
modifier|&
name|spec_list
parameter_list|)
function_decl|;
name|SBModuleSpec
name|FindFirstMatchingSpec
parameter_list|(
specifier|const
name|SBModuleSpec
modifier|&
name|match_spec
parameter_list|)
function_decl|;
name|SBModuleSpecList
name|FindMatchingSpecs
parameter_list|(
specifier|const
name|SBModuleSpec
modifier|&
name|match_spec
parameter_list|)
function_decl|;
name|size_t
name|GetSize
parameter_list|()
function_decl|;
name|SBModuleSpec
name|GetSpecAtIndex
parameter_list|(
name|size_t
name|i
parameter_list|)
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|ModuleSpecList
operator|>
name|m_opaque_ap
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBModuleSpec_h_
end_comment

end_unit

