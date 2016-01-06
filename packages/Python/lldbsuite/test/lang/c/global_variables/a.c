begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- a.c -----------------------------------------------------*- C++ -*-===//
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

begin_decl_stmt
name|int
name|g_a
init|=
literal|123
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Point
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Point
name|g_marked_spot
init|=
block|{
literal|20
block|,
literal|21
block|}
decl_stmt|;
end_decl_stmt

end_unit

