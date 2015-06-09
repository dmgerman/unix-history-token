begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MIRYAMLMapping.h - Describes the mapping between MIR and YAML ------===//
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
comment|// The MIR serialization library is currently a work in progress. It can't
end_comment

begin_comment
comment|// serialize machine functions at this time.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements the mapping between various MIR data structures and
end_comment

begin_comment
comment|// their corresponding YAML representation.
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
name|LLVM_LIB_CODEGEN_MIRYAMLMAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_MIRYAMLMAPPING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|MachineFunction
block|{
name|StringRef
name|Name
decl_stmt|;
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|MachineFunction
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
argument|IO&YamlIO
argument_list|,
argument|MachineFunction&MF
argument_list|)
block|{
name|YamlIO
operator|.
name|mapRequired
argument_list|(
literal|"name"
argument_list|,
name|MF
operator|.
name|Name
argument_list|)
block|;   }
block|}
expr_stmt|;
block|}
comment|// end namespace yaml
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

