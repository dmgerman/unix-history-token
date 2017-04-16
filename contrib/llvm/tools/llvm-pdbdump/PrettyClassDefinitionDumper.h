begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PrettyClassDefinitionDumper.h ----------------------------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_PRETTYCLASSDEFINITIONDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_PRETTYCLASSDEFINITIONDUMPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBSymDumper.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBSymbolData.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBSymbolFunc.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitVector
decl_stmt|;
name|namespace
name|pdb
block|{
name|class
name|ClassLayout
decl_stmt|;
name|class
name|LinePrinter
decl_stmt|;
name|class
name|ClassDefinitionDumper
range|:
name|public
name|PDBSymDumper
block|{
name|public
operator|:
name|ClassDefinitionDumper
argument_list|(
name|LinePrinter
operator|&
name|P
argument_list|)
block|;
name|void
name|start
argument_list|(
specifier|const
name|PDBSymbolTypeUDT
operator|&
name|Class
argument_list|)
block|;
name|void
name|start
argument_list|(
specifier|const
name|ClassLayout
operator|&
name|Class
argument_list|)
block|;
name|private
operator|:
name|void
name|prettyPrintClassIntro
argument_list|(
specifier|const
name|ClassLayout
operator|&
name|Class
argument_list|)
block|;
name|void
name|prettyPrintClassOutro
argument_list|(
specifier|const
name|ClassLayout
operator|&
name|Class
argument_list|)
block|;
name|bool
name|DumpedAnything
operator|=
name|false
block|;
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

