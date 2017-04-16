begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjectYAML.h ---------------------------------------------*- C++ -*-===//
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
name|LLVM_OBJECTYAML_OBJECTYAML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_OBJECTYAML_H
end_define

begin_include
include|#
directive|include
file|"llvm/ObjectYAML/COFFYAML.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ObjectYAML/ELFYAML.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ObjectYAML/MachOYAML.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ObjectYAML/WasmYAML.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|yaml
block|{
struct|struct
name|YamlObjectFile
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ELFYAML
operator|::
name|Object
operator|>
name|Elf
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|COFFYAML
operator|::
name|Object
operator|>
name|Coff
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MachOYAML
operator|::
name|Object
operator|>
name|MachO
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MachOYAML
operator|::
name|UniversalBinary
operator|>
name|FatMachO
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|WasmYAML
operator|::
name|Object
operator|>
name|Wasm
expr_stmt|;
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|YamlObjectFile
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
name|IO
operator|&
name|IO
argument_list|,
name|YamlObjectFile
operator|&
name|ObjectFile
argument_list|)
block|; }
expr_stmt|;
block|}
comment|// namespace yaml
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

