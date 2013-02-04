begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- llvm/AddressingMode.h - Addressing Mode    -------*- C++ -*-===//
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
comment|//  This file contains addressing mode data structures which are shared
end_comment

begin_comment
comment|//  between LSR and a number of places in the codegen.
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
name|LLVM_ADDRESSING_MODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADDRESSING_MODE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
comment|/// AddrMode - This represents an addressing mode of:
comment|///    BaseGV + BaseOffs + BaseReg + Scale*ScaleReg
comment|/// If BaseGV is null,  there is no BaseGV.
comment|/// If BaseOffs is zero, there is no base offset.
comment|/// If HasBaseReg is false, there is no base register.
comment|/// If Scale is zero, there is no ScaleReg.  Scale of 1 indicates a reg with
comment|/// no scale.
comment|///
struct|struct
name|AddrMode
block|{
name|GlobalValue
modifier|*
name|BaseGV
decl_stmt|;
name|int64_t
name|BaseOffs
decl_stmt|;
name|bool
name|HasBaseReg
decl_stmt|;
name|int64_t
name|Scale
decl_stmt|;
name|AddrMode
argument_list|()
operator|:
name|BaseGV
argument_list|(
literal|0
argument_list|)
operator|,
name|BaseOffs
argument_list|(
literal|0
argument_list|)
operator|,
name|HasBaseReg
argument_list|(
name|false
argument_list|)
operator|,
name|Scale
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

