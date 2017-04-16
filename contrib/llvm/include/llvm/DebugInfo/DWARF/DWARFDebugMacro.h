begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugMacro.h ----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGMACRO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGMACRO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFDebugMacro
block|{
comment|/// A single macro entry within a macro list.
struct|struct
name|Entry
block|{
comment|/// The type of the macro entry.
name|uint32_t
name|Type
decl_stmt|;
union|union
block|{
comment|/// The source line where the macro is defined.
name|uint64_t
name|Line
decl_stmt|;
comment|/// Vendor extension constant value.
name|uint64_t
name|ExtConstant
decl_stmt|;
block|}
union|;
union|union
block|{
comment|/// The string (name, value) of the macro entry.
specifier|const
name|char
modifier|*
name|MacroStr
decl_stmt|;
comment|// An unsigned integer indicating the identity of the source file.
name|uint64_t
name|File
decl_stmt|;
comment|/// Vendor extension string.
specifier|const
name|char
modifier|*
name|ExtStr
decl_stmt|;
block|}
union|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|Entry
operator|,
literal|4
operator|>
name|MacroList
expr_stmt|;
comment|/// A list of all the macro entries in the debug_macinfo section.
name|MacroList
name|Macros
decl_stmt|;
name|public
label|:
name|DWARFDebugMacro
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Print the macro list found within the debug_macinfo section.
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Parse the debug_macinfo section accessible via the 'data' parameter.
name|void
name|parse
parameter_list|(
name|DataExtractor
name|data
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARF_DWARFDEBUGMACRO_H
end_comment

end_unit

