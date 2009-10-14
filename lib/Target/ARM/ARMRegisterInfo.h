begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMRegisterInfo.h - ARM Register Information Impl --------*- C++ -*-===//
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
comment|// This file contains the ARM implementation of the TargetRegisterInfo class.
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
name|ARMREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|"ARM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMBaseRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMSubtarget
decl_stmt|;
name|class
name|ARMBaseInstrInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|namespace
name|ARM
block|{
comment|/// SubregIndex - The index of various subregister classes. Note that
comment|/// these indices must be kept in sync with the class indices in the
comment|/// ARMRegisterInfo.td file.
enum|enum
name|SubregIndex
block|{
name|SSUBREG_0
init|=
literal|1
block|,
name|SSUBREG_1
init|=
literal|2
block|,
name|SSUBREG_2
init|=
literal|3
block|,
name|SSUBREG_3
init|=
literal|4
block|,
name|DSUBREG_0
init|=
literal|5
block|,
name|DSUBREG_1
init|=
literal|6
block|}
enum|;
block|}
name|struct
name|ARMRegisterInfo
range|:
name|public
name|ARMBaseRegisterInfo
block|{
name|public
operator|:
name|ARMRegisterInfo
argument_list|(
specifier|const
name|ARMBaseInstrInfo
operator|&
name|tii
argument_list|,
specifier|const
name|ARMSubtarget
operator|&
name|STI
argument_list|)
block|; }
decl_stmt|;
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

