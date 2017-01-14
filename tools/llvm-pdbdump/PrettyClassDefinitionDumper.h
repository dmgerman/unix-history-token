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
name|namespace
name|pdb
block|{
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
name|Exe
argument_list|)
block|;
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeBaseClass&Symbol
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
argument|const PDBSymbolTypeEnum&Symbol
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
name|void
name|dump
argument_list|(
argument|const PDBSymbolTypeVTable&Symbol
argument_list|)
name|override
block|;
name|private
operator|:
name|LinePrinter
operator|&
name|Printer
block|;    struct
name|SymbolGroup
block|{
name|SymbolGroup
argument_list|()
block|{}
name|SymbolGroup
argument_list|(
argument|SymbolGroup&&Other
argument_list|)
block|{
name|Functions
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|Functions
argument_list|)
block|;
name|Data
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|Data
argument_list|)
block|;
name|Unknown
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
operator|.
name|Unknown
argument_list|)
block|;     }
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbolFunc
operator|>>
name|Functions
block|;
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbolData
operator|>>
name|Data
block|;
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PDBSymbol
operator|>>
name|Unknown
block|;
name|SymbolGroup
argument_list|(
specifier|const
name|SymbolGroup
operator|&
name|other
argument_list|)
operator|=
name|delete
block|;
name|SymbolGroup
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SymbolGroup
operator|&
name|other
operator|)
operator|=
name|delete
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|int
operator|,
name|SymbolGroup
operator|>
name|SymbolGroupByAccess
expr_stmt|;
name|int
name|dumpAccessGroup
argument_list|(
argument|PDB_MemberAccess Access
argument_list|,
argument|const SymbolGroup&Group
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

