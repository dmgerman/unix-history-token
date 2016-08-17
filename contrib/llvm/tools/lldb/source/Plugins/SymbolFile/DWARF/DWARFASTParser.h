begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFASTParser.h ----------------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFASTParser_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFASTParser_h_
end_define

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerDecl.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerDeclContext.h"
end_include

begin_decl_stmt
name|class
name|DWARFDIE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFASTParser
block|{
name|public
label|:
name|virtual
operator|~
name|DWARFASTParser
argument_list|()
block|{}
name|virtual
name|lldb
operator|::
name|TypeSP
name|ParseTypeFromDWARF
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|,
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
name|bool
operator|*
name|type_is_new_ptr
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb_private
operator|::
name|Function
operator|*
name|ParseFunctionFromDWARF
argument_list|(
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|,
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|CompleteTypeFromDWARF
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|,
name|lldb_private
operator|::
name|Type
operator|*
name|type
argument_list|,
name|lldb_private
operator|::
name|CompilerType
operator|&
name|compiler_type
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|lldb_private
operator|::
name|CompilerDecl
name|GetDeclForUIDFromDWARF
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextForUIDFromDWARF
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb_private
operator|::
name|CompilerDeclContext
name|GetDeclContextContainingUIDFromDWARF
argument_list|(
specifier|const
name|DWARFDIE
operator|&
name|die
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|vector
operator|<
name|DWARFDIE
operator|>
name|GetDIEForDeclContext
argument_list|(
argument|lldb_private::CompilerDeclContext decl_context
argument_list|)
operator|=
literal|0
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
comment|// SymbolFileDWARF_DWARFASTParser_h_
end_comment

end_unit

