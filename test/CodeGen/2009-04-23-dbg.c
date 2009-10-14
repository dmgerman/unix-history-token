begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -g -o %t  %s -emit-llvm-bc&& llc %t -o %t.s
end_comment

begin_empty
empty|# 1 "a.c"
end_empty

begin_empty
empty|# 1 "a.c" 1
end_empty

begin_empty
empty|# 1 "<built-in>" 1
end_empty

begin_empty
empty|# 103 "<built-in>"
end_empty

begin_empty
empty|# 103 "<command line>" 1
end_empty

begin_empty
empty|# 1 "/private/tmp/a.h" 1
end_empty

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_empty
empty|# 105 "<command line>" 2
end_empty

begin_empty
empty|# 105 "<built-in>" 2
end_empty

begin_empty
empty|# 1 "a.c" 2
end_empty

begin_empty
empty|# 1 "/private/tmp/a.h" 1
end_empty

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_empty
empty|# 2 "a.c" 2
end_empty

begin_function
name|int
name|main
parameter_list|()
block|{
name|bar
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

