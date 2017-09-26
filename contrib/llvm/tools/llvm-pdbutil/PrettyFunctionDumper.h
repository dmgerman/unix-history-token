begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PrettyFunctionDumper.h --------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_PRETTYFUNCTIONDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_PRETTYFUNCTIONDUMPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBSymDumper.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|LinePrinter
decl_stmt|;
name|class
name|FunctionDumper
range|:
name|public
name|PDBSymDumper
block|{
name|public
operator|:
name|FunctionDumper
argument_list|(
name|LinePrinter
operator|&
name|P
argument_list|)
block|;    enum
name|class
name|PointerType
block|{
name|None
block|,
name|Pointer
block|,
name|Reference
block|}
block|;
name|void
name|start
argument_list|(
argument|const PDBSymbolTypeFunctionSig&Symbol
argument_list|,
argument|const char *Name
argument_list|,
argument|PointerType Pointer
argument_list|)
block|;
name|void
name|start
argument_list|(
argument|const PDBSymbolFunc&Symbol
argument_list|,
argument|PointerType Pointer
argument_list|)
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeArray&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeBuiltin&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeEnum&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeFunctionArg&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypePointer&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeTypedef&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeUDT&Symbol
argument_list|)
name|override
block|;
name|private
operator|:
name|LinePrinter
operator|&
name|Printer
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

