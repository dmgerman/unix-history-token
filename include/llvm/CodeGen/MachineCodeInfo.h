begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachineCodeInfo.h - Class used to report JIT info -------*- C++ -*-===//
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
comment|// This file defines MachineCodeInfo, a class used by the JIT ExecutionEngine
end_comment

begin_comment
comment|// to report information about the generated machine code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See JIT::runJITOnFunction for usage.
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
name|EE_MACHINE_CODE_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|EE_MACHINE_CODE_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineCodeInfo
block|{
name|private
label|:
name|size_t
name|Size
decl_stmt|;
comment|// Number of bytes in memory used
name|void
modifier|*
name|Address
decl_stmt|;
comment|// The address of the function in memory
name|public
label|:
name|MachineCodeInfo
argument_list|()
operator|:
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|Address
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setSize
argument_list|(
argument|size_t s
argument_list|)
block|{
name|Size
operator|=
name|s
block|;   }
name|void
name|setAddress
argument_list|(
argument|void *a
argument_list|)
block|{
name|Address
operator|=
name|a
block|;   }
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|void
operator|*
name|address
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

