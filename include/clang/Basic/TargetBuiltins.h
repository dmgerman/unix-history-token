begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TargetBuiltins.h - Target specific builtin IDs -------------------===//
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
name|LLVM_CLANG_BASIC_TARGET_BUILTINS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_TARGET_BUILTINS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Builtins.h"
end_include

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// ARM builtins
name|namespace
name|ARM
block|{
enum|enum
block|{
name|LastTIBuiltin
init|=
name|clang
operator|::
name|Builtin
operator|::
name|FirstTSBuiltin
operator|-
literal|1
block|,
define|#
directive|define
name|BUILTIN
parameter_list|(
name|ID
parameter_list|,
name|TYPE
parameter_list|,
name|ATTRS
parameter_list|)
value|BI##ID,
include|#
directive|include
file|"clang/Basic/BuiltinsARM.def"
name|LastTSBuiltin
block|}
enum|;
block|}
comment|/// PPC builtins
name|namespace
name|PPC
block|{
enum|enum
block|{
name|LastTIBuiltin
init|=
name|clang
operator|::
name|Builtin
operator|::
name|FirstTSBuiltin
operator|-
literal|1
block|,
define|#
directive|define
name|BUILTIN
parameter_list|(
name|ID
parameter_list|,
name|TYPE
parameter_list|,
name|ATTRS
parameter_list|)
value|BI##ID,
include|#
directive|include
file|"clang/Basic/BuiltinsPPC.def"
name|LastTSBuiltin
block|}
enum|;
block|}
comment|/// X86 builtins
name|namespace
name|X86
block|{
enum|enum
block|{
name|LastTIBuiltin
init|=
name|clang
operator|::
name|Builtin
operator|::
name|FirstTSBuiltin
operator|-
literal|1
block|,
define|#
directive|define
name|BUILTIN
parameter_list|(
name|ID
parameter_list|,
name|TYPE
parameter_list|,
name|ATTRS
parameter_list|)
value|BI##ID,
include|#
directive|include
file|"clang/Basic/BuiltinsX86.def"
name|LastTSBuiltin
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

