begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfStringPool.h - Dwarf Debug Framework -*- C++ -*--===//
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFSTRINGPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFSTRINGPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DwarfStringPoolEntry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|// Collection of strings for this unit and assorted symbols.
comment|// A String->Symbol mapping of strings used by indirect
comment|// references.
name|class
name|DwarfStringPool
block|{
typedef|typedef
name|DwarfStringPoolEntry
name|EntryTy
typedef|;
name|StringMap
operator|<
name|EntryTy
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|Pool
expr_stmt|;
name|StringRef
name|Prefix
decl_stmt|;
name|unsigned
name|NumBytes
init|=
literal|0
decl_stmt|;
name|bool
name|ShouldCreateSymbols
decl_stmt|;
name|public
label|:
typedef|typedef
name|DwarfStringPoolEntryRef
name|EntryRef
typedef|;
name|DwarfStringPool
argument_list|(
argument|BumpPtrAllocator&A
argument_list|,
argument|AsmPrinter&Asm
argument_list|,
argument|StringRef Prefix
argument_list|)
empty_stmt|;
name|void
name|emit
parameter_list|(
name|AsmPrinter
modifier|&
name|Asm
parameter_list|,
name|MCSection
modifier|*
name|StrSection
parameter_list|,
name|MCSection
modifier|*
name|OffsetSection
init|=
name|nullptr
parameter_list|)
function_decl|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Pool
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Get a reference to an entry in the string pool.
name|EntryRef
name|getEntry
parameter_list|(
name|AsmPrinter
modifier|&
name|Asm
parameter_list|,
name|StringRef
name|Str
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

