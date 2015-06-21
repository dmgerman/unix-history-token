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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|yaml
block|{
struct|struct
name|MachineBasicBlock
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|unsigned
name|Alignment
init|=
literal|0
decl_stmt|;
name|bool
name|IsLandingPad
init|=
name|false
decl_stmt|;
name|bool
name|AddressTaken
init|=
name|false
decl_stmt|;
comment|// TODO: Serialize the successors and liveins.
comment|// TODO: Serialize machine instructions.
block|}
struct|;
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|MachineBasicBlock
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
argument|IO&YamlIO
argument_list|,
argument|MachineBasicBlock&MBB
argument_list|)
block|{
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"name"
argument_list|,
name|MBB
operator|.
name|Name
argument_list|,
name|std
operator|::
name|string
argument_list|()
argument_list|)
block|;
comment|// Don't print out an empty name.
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"alignment"
argument_list|,
name|MBB
operator|.
name|Alignment
argument_list|)
block|;
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"isLandingPad"
argument_list|,
name|MBB
operator|.
name|IsLandingPad
argument_list|)
block|;
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"addressTaken"
argument_list|,
name|MBB
operator|.
name|AddressTaken
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

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|llvm::yaml::MachineBasicBlock
argument_list|)
end_macro

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
name|unsigned
name|Alignment
init|=
literal|0
decl_stmt|;
name|bool
name|ExposesReturnsTwice
init|=
name|false
decl_stmt|;
name|bool
name|HasInlineAsm
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|>
name|BasicBlocks
expr_stmt|;
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
block|;
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"alignment"
argument_list|,
name|MF
operator|.
name|Alignment
argument_list|)
block|;
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"exposesReturnsTwice"
argument_list|,
name|MF
operator|.
name|ExposesReturnsTwice
argument_list|)
block|;
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"hasInlineAsm"
argument_list|,
name|MF
operator|.
name|HasInlineAsm
argument_list|)
block|;
name|YamlIO
operator|.
name|mapOptional
argument_list|(
literal|"body"
argument_list|,
name|MF
operator|.
name|BasicBlocks
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

