begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleSymbolTable.h - symbol table for in-memory IR ------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This class represents a symbol table built from in-memory IR. It provides
end_comment

begin_comment
comment|// access to GlobalValues and should only be used if such access is required
end_comment

begin_comment
comment|// (e.g. in the LTO implementation).
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
name|LLVM_OBJECT_MODULESYMBOLTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_MODULESYMBOLTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Mangler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/SymbolicFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|ModuleSymbolTable
block|{
name|public
label|:
name|using
name|AsmSymbol
init|=
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
decl_stmt|,
name|uint32_t
decl|>
decl_stmt|;
name|using
name|Symbol
init|=
name|PointerUnion
operator|<
name|GlobalValue
operator|*
decl_stmt|,
name|AsmSymbol
modifier|*
decl|>
decl_stmt|;
name|private
label|:
name|Module
modifier|*
name|FirstMod
init|=
name|nullptr
decl_stmt|;
name|SpecificBumpPtrAllocator
operator|<
name|AsmSymbol
operator|>
name|AsmSymbols
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|>
name|SymTab
expr_stmt|;
name|Mangler
name|Mang
decl_stmt|;
name|public
label|:
name|ArrayRef
operator|<
name|Symbol
operator|>
name|symbols
argument_list|()
specifier|const
block|{
return|return
name|SymTab
return|;
block|}
name|void
name|addModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|void
name|printSymbolName
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|Symbol
name|S
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|getSymbolFlags
argument_list|(
name|Symbol
name|S
argument_list|)
decl|const
decl_stmt|;
comment|/// Parse inline ASM and collect the symbols that are defined or referenced in
comment|/// the current module.
comment|///
comment|/// For each found symbol, call \p AsmSymbol with the name of the symbol found
comment|/// and the associated flags.
specifier|static
name|void
name|CollectAsmSymbols
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|StringRef
argument_list|,
name|object
operator|::
name|BasicSymbolRef
operator|::
name|Flags
argument_list|)
operator|>
name|AsmSymbol
argument_list|)
decl_stmt|;
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
comment|// LLVM_OBJECT_MODULESYMBOLTABLE_H
end_comment

end_unit

