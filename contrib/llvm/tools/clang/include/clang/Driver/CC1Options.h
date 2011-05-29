begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CC1Options.h - Clang CC1 Options Table -----------------*- C++ -*-===//
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
name|CLANG_DRIVER_CC1OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_CC1OPTIONS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|OptTable
decl_stmt|;
name|namespace
name|cc1options
block|{
enum|enum
name|ID
block|{
name|OPT_INVALID
init|=
literal|0
block|,
comment|// This is not an option ID.
define|#
directive|define
name|OPTION
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|KIND
parameter_list|,
name|GROUP
parameter_list|,
name|ALIAS
parameter_list|,
name|FLAGS
parameter_list|,
name|PARAM
parameter_list|, \
name|HELPTEXT
parameter_list|,
name|METAVAR
parameter_list|)
value|OPT_##ID,
include|#
directive|include
file|"clang/Driver/CC1Options.inc"
name|LastOption
undef|#
directive|undef
name|OPTION
block|}
enum|;
block|}
name|OptTable
modifier|*
name|createCC1OptTable
parameter_list|()
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

