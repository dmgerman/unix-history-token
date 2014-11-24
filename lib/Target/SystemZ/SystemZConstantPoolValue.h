begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SystemZConstantPoolValue.h - SystemZ constant-pool value -*- C++ -*-===//
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
name|SYSTEMZCONSTANTPOOLVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZCONSTANTPOOLVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineConstantPool.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|namespace
name|SystemZCP
block|{
enum|enum
name|SystemZCPModifier
block|{
name|NTPOFF
block|}
enum|;
block|}
comment|// end namespace SystemZCP
comment|/// A SystemZ-specific constant pool value.  At present, the only
comment|/// defined constant pool values are offsets of thread-local variables
comment|/// (written x@NTPOFF).
name|class
name|SystemZConstantPoolValue
range|:
name|public
name|MachineConstantPoolValue
block|{
specifier|const
name|GlobalValue
operator|*
name|GV
block|;
name|SystemZCP
operator|::
name|SystemZCPModifier
name|Modifier
block|;
name|protected
operator|:
name|SystemZConstantPoolValue
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SystemZCP::SystemZCPModifier Modifier
argument_list|)
block|;
name|public
operator|:
specifier|static
name|SystemZConstantPoolValue
operator|*
name|Create
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SystemZCP::SystemZCPModifier Modifier
argument_list|)
block|;
comment|// Override MachineConstantPoolValue.
name|unsigned
name|getRelocationInfo
argument_list|()
specifier|const
name|override
block|;
name|int
name|getExistingMachineCPValue
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
name|override
block|;
name|void
name|addSelectionDAGCSEId
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
name|override
block|;
comment|// Access SystemZ-specific fields.
specifier|const
name|GlobalValue
operator|*
name|getGlobalValue
argument_list|()
specifier|const
block|{
return|return
name|GV
return|;
block|}
name|SystemZCP
operator|::
name|SystemZCPModifier
name|getModifier
argument_list|()
specifier|const
block|{
return|return
name|Modifier
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

