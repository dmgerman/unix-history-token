begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjCARC.h - ObjCARC Scalar Transformations --------------*- C++ -*-===//
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
comment|// This header file defines prototypes for accessor functions that expose passes
end_comment

begin_comment
comment|// in the ObjCARC Scalar Transformations library.
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
name|LLVM_TRANSFORMS_OBJCARC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_OBJCARC_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Pass
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ObjCARCAPElim - ObjC ARC autorelease pool elimination.
comment|//
name|Pass
modifier|*
name|createObjCARCAPElimPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ObjCARCExpand - ObjC ARC preliminary simplifications.
comment|//
name|Pass
modifier|*
name|createObjCARCExpandPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ObjCARCContract - Late ObjC ARC cleanups.
comment|//
name|Pass
modifier|*
name|createObjCARCContractPass
parameter_list|()
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// ObjCARCOpt - ObjC ARC optimization.
comment|//
name|Pass
modifier|*
name|createObjCARCOptPass
parameter_list|()
function_decl|;
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

