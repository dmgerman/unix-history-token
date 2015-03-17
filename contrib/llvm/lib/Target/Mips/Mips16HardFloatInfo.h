begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- Mips16HardFloatInfo.h for Mips16 Hard Float              --------===//
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
comment|// This file defines some data structures relevant to the implementation of
end_comment

begin_comment
comment|// Mips16 hard float.
end_comment

begin_comment
comment|//
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
name|LLVM_LIB_TARGET_MIPS_MIPS16HARDFLOATINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPS16HARDFLOATINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Mips16HardFloatInfo
block|{
comment|// Return types that matter for hard float are:
comment|// float, double, complex float, and complex double
comment|//
enum|enum
name|FPReturnVariant
block|{
name|FRet
block|,
name|DRet
block|,
name|CFRet
block|,
name|CDRet
block|,
name|NoFPRet
block|}
enum|;
comment|//
comment|// Parameter type that matter are float, (float, float), (float, double),
comment|// double, (double, double), (double, float)
comment|//
enum|enum
name|FPParamVariant
block|{
name|FSig
block|,
name|FFSig
block|,
name|FDSig
block|,
name|DSig
block|,
name|DDSig
block|,
name|DFSig
block|,
name|NoSig
block|}
enum|;
struct|struct
name|FuncSignature
block|{
name|FPParamVariant
name|ParamSig
decl_stmt|;
name|FPReturnVariant
name|RetSig
decl_stmt|;
block|}
struct|;
struct|struct
name|FuncNameSignature
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
name|FuncSignature
name|Signature
decl_stmt|;
block|}
struct|;
specifier|extern
specifier|const
name|FuncNameSignature
name|PredefinedFuncs
index|[]
decl_stmt|;
specifier|extern
name|FuncSignature
specifier|const
modifier|*
name|findFuncSignature
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

