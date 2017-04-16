begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Options.h - Option info& table ------------------------*- C++ -*-===//
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
name|LLVM_CLANG_DRIVER_OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_OPTIONS_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|opt
block|{
name|class
name|OptTable
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|namespace
name|options
block|{
comment|/// Flags specifically for clang options.  Must not overlap with
comment|/// llvm::opt::DriverFlag.
enum|enum
name|ClangFlags
block|{
name|DriverOption
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|LinkerInput
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|NoArgumentUnused
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|Unsupported
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|CoreOption
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|CLOption
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|CC1Option
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|CC1AsOption
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|NoDriverOption
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|Ignored
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|}
enum|;
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
name|PREFIX
parameter_list|,
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
name|ALIASARGS
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
file|"clang/Driver/Options.inc"
name|LastOption
undef|#
directive|undef
name|OPTION
block|}
enum|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|opt
operator|::
name|OptTable
operator|>
name|createDriverOptTable
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

