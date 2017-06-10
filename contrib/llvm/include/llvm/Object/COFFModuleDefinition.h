begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- COFFModuleDefinition.h ---------------------------------*- C++ -*-===//
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
comment|// Windows-specific.
end_comment

begin_comment
comment|// A parser for the module-definition file (.def file).
end_comment

begin_comment
comment|// Parsed results are directly written to Config global variable.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The format of module-definition files are described in this document:
end_comment

begin_comment
comment|// https://msdn.microsoft.com/en-us/library/28d6s79h.aspx
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
name|LLVM_OBJECT_COFF_MODULE_DEFINITION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_COFF_MODULE_DEFINITION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/COFF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/COFFImportFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
struct|struct
name|COFFModuleDefinition
block|{
name|std
operator|::
name|vector
operator|<
name|COFFShortExport
operator|>
name|Exports
expr_stmt|;
name|std
operator|::
name|string
name|OutputFile
expr_stmt|;
name|uint64_t
name|ImageBase
init|=
literal|0
decl_stmt|;
name|uint64_t
name|StackReserve
init|=
literal|0
decl_stmt|;
name|uint64_t
name|StackCommit
init|=
literal|0
decl_stmt|;
name|uint64_t
name|HeapReserve
init|=
literal|0
decl_stmt|;
name|uint64_t
name|HeapCommit
init|=
literal|0
decl_stmt|;
name|uint32_t
name|MajorImageVersion
init|=
literal|0
decl_stmt|;
name|uint32_t
name|MinorImageVersion
init|=
literal|0
decl_stmt|;
name|uint32_t
name|MajorOSVersion
init|=
literal|0
decl_stmt|;
name|uint32_t
name|MinorOSVersion
init|=
literal|0
decl_stmt|;
block|}
struct|;
name|Expected
operator|<
name|COFFModuleDefinition
operator|>
name|parseCOFFModuleDefinition
argument_list|(
argument|MemoryBufferRef MB
argument_list|,
argument|COFF::MachineTypes Machine
argument_list|)
expr_stmt|;
block|}
comment|// End namespace object.
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

