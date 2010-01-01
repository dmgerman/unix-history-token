begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-html -o -
end_comment

begin_comment
comment|// rdar://6562329
end_comment

begin_line
line|#
directive|line
number|42
file|"foo.c"
end_line

begin_comment
comment|// PR3635
end_comment

begin_define
define|#
directive|define
name|F
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|fmt, ## __VA_ARGS__
end_define

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
return|return
name|F
argument_list|(
name|argc
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// PR3798
end_comment

begin_define
define|#
directive|define
name|FOR_ALL_FILES
parameter_list|(
name|f
parameter_list|,
name|i
parameter_list|)
value|i
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|FOR_ALL_FILES(f) { }
endif|#
directive|endif
end_endif

end_unit

