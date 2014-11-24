begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file tests -Rpass diagnostics together with #line
end_comment

begin_comment
comment|// directives. We cannot map #line directives back to
end_comment

begin_comment
comment|// a SourceLocation.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -gline-tables-only -dwarf-column-info -emit-llvm-only -verify
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_comment
comment|// expected-remark@+2 {{foo inlined into bar}} expected-note@+2 {{could not determine the original source location for /bad/path/to/original.c:1230:25}}
end_comment

begin_line
line|#
directive|line
number|1230
file|"/bad/path/to/original.c"
end_line

begin_function
name|int
name|bar
parameter_list|(
name|int
name|j
parameter_list|)
block|{
return|return
name|foo
argument_list|(
name|j
argument_list|,
name|j
operator|-
literal|2
argument_list|)
return|;
block|}
end_function

end_unit

