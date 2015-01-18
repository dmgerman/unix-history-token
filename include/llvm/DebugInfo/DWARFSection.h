begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFSection.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_LIB_DEBUGINFO_DWARFSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_DWARFSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARFRelocMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|DWARFSection
block|{
name|StringRef
name|Data
decl_stmt|;
name|RelocAddrMap
name|Relocs
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

