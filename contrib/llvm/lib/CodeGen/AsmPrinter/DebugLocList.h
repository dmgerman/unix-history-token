begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- lib/CodeGen/DebugLocList.h - DWARF debug_loc list ------*- C++ -*-===//
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
name|CODEGEN_ASMPRINTER_DEBUGLOCLIST_H__
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DEBUGLOCLIST_H__
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"DebugLocEntry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|DebugLocList
block|{
name|MCSymbol
modifier|*
name|Label
decl_stmt|;
name|SmallVector
operator|<
name|DebugLocEntry
operator|,
literal|4
operator|>
name|List
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

