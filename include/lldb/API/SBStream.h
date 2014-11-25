begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBStream.h ----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBStream_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBStream_h_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBStream
block|{
name|public
label|:
name|SBStream
argument_list|()
expr_stmt|;
operator|~
name|SBStream
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
comment|// If this stream is not redirected to a file, it will maintain a local
comment|// cache for the stream data which can be accessed using this accessor.
specifier|const
name|char
modifier|*
name|GetData
parameter_list|()
function_decl|;
comment|// If this stream is not redirected to a file, it will maintain a local
comment|// cache for the stream output whose length can be accessed using this
comment|// accessor.
name|size_t
name|GetSize
parameter_list|()
function_decl|;
name|void
name|Printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|RedirectToFile
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|append
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RedirectToFileHandle
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|,
name|bool
name|transfer_fh_ownership
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RedirectToFileDescriptor
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|transfer_fh_ownership
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// If the stream is redirected to a file, forget about the file and if
end_comment

begin_comment
comment|// ownership of the file was transferred to this object, close the file.
end_comment

begin_comment
comment|// If the stream is backed by a local cache, clear this cache.
end_comment

begin_function_decl
name|void
name|Clear
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|SBAddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBBlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBBreakpoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBBreakpointLocation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBCommandReturnObject
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBCompileUnit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBData
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBDebugger
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBDeclaration
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBEvent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBFileSpec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBFileSpecList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBFrame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBFunction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBInstruction
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBInstructionList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBLineEntry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBModule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBModuleSpec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBModuleSpecList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBProcess
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBSection
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBSourceManager
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBSymbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBSymbolContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBSymbolContextList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBTarget
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBThread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBType
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBTypeEnumMember
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBTypeMember
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBValue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|SBWatchpoint
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Stream
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Stream
operator|*
name|get
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Stream
operator|&
name|ref
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SBStream
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|Stream
operator|>
name|m_opaque_ap
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_is_file
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBStream_h_
end_comment

end_unit

