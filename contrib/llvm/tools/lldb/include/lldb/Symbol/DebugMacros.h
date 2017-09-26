begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DebugMacros.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_DebugMacros_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DebugMacros_h_
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
file|<memory>
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
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CompileUnit
decl_stmt|;
name|class
name|DebugMacros
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|DebugMacros
operator|>
name|DebugMacrosSP
expr_stmt|;
name|class
name|DebugMacroEntry
block|{
name|public
label|:
enum|enum
name|EntryType
block|{
name|INVALID
block|,
name|DEFINE
block|,
name|UNDEF
block|,
name|START_FILE
block|,
name|END_FILE
block|,
name|INDIRECT
block|}
enum|;
name|public
label|:
specifier|static
name|DebugMacroEntry
name|CreateDefineEntry
parameter_list|(
name|uint32_t
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
specifier|static
name|DebugMacroEntry
name|CreateUndefEntry
parameter_list|(
name|uint32_t
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
specifier|static
name|DebugMacroEntry
name|CreateStartFileEntry
parameter_list|(
name|uint32_t
name|line
parameter_list|,
name|uint32_t
name|debug_line_file_idx
parameter_list|)
function_decl|;
specifier|static
name|DebugMacroEntry
name|CreateEndFileEntry
parameter_list|()
function_decl|;
specifier|static
name|DebugMacroEntry
name|CreateIndirectEntry
parameter_list|(
specifier|const
name|DebugMacrosSP
modifier|&
name|debug_macros_sp
parameter_list|)
function_decl|;
name|DebugMacroEntry
argument_list|()
operator|:
name|m_type
argument_list|(
argument|INVALID
argument_list|)
block|{}
operator|~
name|DebugMacroEntry
argument_list|()
operator|=
expr|default
expr_stmt|;
name|EntryType
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|uint64_t
name|GetLineNumber
argument_list|()
specifier|const
block|{
return|return
name|m_line
return|;
block|}
name|ConstString
name|GetMacroString
argument_list|()
specifier|const
block|{
return|return
name|m_str
return|;
block|}
specifier|const
name|FileSpec
modifier|&
name|GetFileSpec
argument_list|(
name|CompileUnit
operator|*
name|comp_unit
argument_list|)
decl|const
decl_stmt|;
name|DebugMacros
operator|*
name|GetIndirectDebugMacros
argument_list|()
specifier|const
block|{
return|return
name|m_debug_macros_sp
operator|.
name|get
argument_list|()
return|;
block|}
name|private
label|:
name|DebugMacroEntry
argument_list|(
argument|EntryType type
argument_list|,
argument|uint32_t line
argument_list|,
argument|uint32_t debug_line_file_idx
argument_list|,
argument|const char *str
argument_list|)
empty_stmt|;
name|DebugMacroEntry
argument_list|(
argument|EntryType type
argument_list|,
argument|const DebugMacrosSP&debug_macros_sp
argument_list|)
empty_stmt|;
name|EntryType
name|m_type
range|:
literal|3
decl_stmt|;
name|uint32_t
name|m_line
range|:
literal|29
decl_stmt|;
name|uint32_t
name|m_debug_line_file_idx
decl_stmt|;
name|ConstString
name|m_str
decl_stmt|;
name|DebugMacrosSP
name|m_debug_macros_sp
decl_stmt|;
block|}
empty_stmt|;
name|class
name|DebugMacros
block|{
name|public
label|:
name|DebugMacros
argument_list|()
operator|=
expr|default
expr_stmt|;
operator|~
name|DebugMacros
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|AddMacroEntry
parameter_list|(
specifier|const
name|DebugMacroEntry
modifier|&
name|entry
parameter_list|)
block|{
name|m_macro_entries
operator|.
name|push_back
argument_list|(
name|entry
argument_list|)
expr_stmt|;
block|}
name|size_t
name|GetNumMacroEntries
argument_list|()
specifier|const
block|{
return|return
name|m_macro_entries
operator|.
name|size
argument_list|()
return|;
block|}
name|DebugMacroEntry
name|GetMacroEntryAtIndex
argument_list|(
specifier|const
name|size_t
name|index
argument_list|)
decl|const
block|{
if|if
condition|(
name|index
operator|<
name|m_macro_entries
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_macro_entries
index|[
name|index
index|]
return|;
else|else
return|return
name|DebugMacroEntry
argument_list|()
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DebugMacros
argument_list|)
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|DebugMacroEntry
operator|>
name|m_macro_entries
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
comment|// liblldb_DebugMacros_h_
end_comment

end_unit

