begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OptionParser.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_OptionParser_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_OptionParser_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_struct_decl
struct_decl|struct
name|option
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
struct|struct
name|Option
block|{
comment|// name of long option
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// one of no_argument, required_argument, and optional_argument:
comment|// whether option takes an argument
name|int
name|has_arg
decl_stmt|;
comment|// if not NULL, set *flag to val when option found
name|int
modifier|*
name|flag
decl_stmt|;
comment|// if flag not NULL, value to set *flag to; else return value
name|int
name|val
decl_stmt|;
block|}
name|Option
typedef|;
name|class
name|OptionParser
block|{
name|public
label|:
enum|enum
name|OptionArgument
block|{
name|eNoArgument
init|=
literal|0
block|,
name|eRequiredArgument
block|,
name|eOptionalArgument
block|}
enum|;
specifier|static
name|void
name|Prepare
parameter_list|()
function_decl|;
specifier|static
name|void
name|EnableError
parameter_list|(
name|bool
name|error
parameter_list|)
function_decl|;
specifier|static
name|int
name|Parse
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|optstring
parameter_list|,
specifier|const
name|Option
modifier|*
name|longopts
parameter_list|,
name|int
modifier|*
name|longindex
parameter_list|)
function_decl|;
specifier|static
name|char
modifier|*
name|GetOptionArgument
parameter_list|()
function_decl|;
specifier|static
name|int
name|GetOptionIndex
parameter_list|()
function_decl|;
specifier|static
name|int
name|GetOptionErrorCause
parameter_list|()
function_decl|;
specifier|static
name|std
operator|::
name|string
name|GetShortOptionString
argument_list|(
expr|struct
name|option
operator|*
name|long_options
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_OptionParser_h_
end_comment

end_unit

