begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CompilandDumper.h - llvm-pdbdump compiland symbol dumper *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_COMPILANDDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_COMPILANDDUMPER_H
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
name|class
name|LinePrinter
decl_stmt|;
name|class
name|CompilandDumper
range|:
name|public
name|PDBSymDumper
block|{
name|public
operator|:
name|CompilandDumper
argument_list|(
name|LinePrinter
operator|&
name|P
argument_list|)
block|;
name|void
name|start
argument_list|(
argument|const PDBSymbolCompiland&Symbol
argument_list|,
argument|bool Children
argument_list|)
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolCompilandDetails&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolCompilandEnv&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolData&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolFunc&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolLabel&Symbol
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolThunk&Symbol
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
argument|const PDBSymbolUnknown&Symbol
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
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

