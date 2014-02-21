begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFLocationDescription.h ------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFLocationDescription_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFLocationDescription_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_decl_stmt
name|int
name|print_dwarf_expression
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|data
argument_list|,
name|int
name|address_size
argument_list|,
name|int
name|dwarf_ref_size
argument_list|,
name|bool
name|location_expression
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFLocationDescription_h_
end_comment

end_unit

