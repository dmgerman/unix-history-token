begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c --------------------------------------------------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|g_common_1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not initialized on purpose to cause it to be undefined external in .o file
end_comment

begin_decl_stmt
name|int
name|g_file_global_int
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|g_file_static_int
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|g_file_global_cstr
init|=
literal|"g_file_global_cstr"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|g_file_static_cstr
init|=
literal|"g_file_static_cstr"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_a
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|g_common_1
operator|=
name|g_file_global_int
operator|/
name|g_file_static_int
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_func_static_cstr
init|=
literal|"g_func_static_cstr"
decl_stmt|;
name|printf
argument_list|(
literal|"%s %s\n"
argument_list|,
name|g_file_global_cstr
argument_list|,
name|g_file_static_cstr
argument_list|)
expr_stmt|;
return|return
name|g_file_global_int
operator|+
name|g_a
operator|+
name|g_common_1
return|;
comment|// Set break point at this line.  //// break $source:$line; continue; var -global g_a -global g_global_int
block|}
end_function

end_unit

