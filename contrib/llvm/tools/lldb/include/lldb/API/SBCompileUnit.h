begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBCompileUnit.h -----------------------------------------*- C++ -*-===//
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
name|LLDB_SBCompileUnit_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBCompileUnit_h_
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
name|SBCompileUnit
block|{
name|public
label|:
name|SBCompileUnit
argument_list|()
expr_stmt|;
name|SBCompileUnit
argument_list|(
specifier|const
name|lldb
operator|::
name|SBCompileUnit
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBCompileUnit
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBCompileUnit
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBCompileUnit
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBFileSpec
name|GetFileSpec
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetNumLineEntries
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBLineEntry
name|GetLineEntryAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
expr_stmt|;
name|uint32_t
name|FindLineEntryIndex
argument_list|(
name|uint32_t
name|start_idx
argument_list|,
name|uint32_t
name|line
argument_list|,
name|lldb
operator|::
name|SBFileSpec
operator|*
name|inline_file_spec
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|FindLineEntryIndex
argument_list|(
name|uint32_t
name|start_idx
argument_list|,
name|uint32_t
name|line
argument_list|,
name|lldb
operator|::
name|SBFileSpec
operator|*
name|inline_file_spec
argument_list|,
name|bool
name|exact
argument_list|)
decl|const
decl_stmt|;
name|SBFileSpec
name|GetSupportFileAtIndex
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|GetNumSupportFiles
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|FindSupportFileIndex
parameter_list|(
name|uint32_t
name|start_idx
parameter_list|,
specifier|const
name|SBFileSpec
modifier|&
name|sb_file
parameter_list|,
name|bool
name|full
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get all types matching \a type_mask from debug info in this
comment|/// compile unit.
comment|///
comment|/// @param[in] type_mask
comment|///    A bitfield that consists of one or more bits logically OR'ed
comment|///    together from the lldb::TypeClass enumeration. This allows
comment|///    you to request only structure types, or only class, struct
comment|///    and union types. Passing in lldb::eTypeClassAny will return
comment|///    all types found in the debug information for this compile
comment|///    unit.
comment|///
comment|/// @return
comment|///    A list of types in this compile unit that match \a type_mask
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBTypeList
name|GetTypes
argument_list|(
argument|uint32_t type_mask = lldb::eTypeClassAny
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBCompileUnit
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBCompileUnit
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
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
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBSymbolContext
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|SBCompileUnit
argument_list|(
name|lldb_private
operator|::
name|CompileUnit
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|CompileUnit
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
specifier|const
name|lldb_private
operator|::
name|CompileUnit
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|lldb_private
operator|::
name|CompileUnit
operator|*
name|get
argument_list|()
expr_stmt|;
name|void
name|reset
argument_list|(
name|lldb_private
operator|::
name|CompileUnit
operator|*
name|lldb_object_ptr
argument_list|)
decl_stmt|;
name|lldb_private
operator|::
name|CompileUnit
operator|*
name|m_opaque_ptr
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBCompileUnit_h_
end_comment

end_unit

