begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we can build C code.
end_comment

begin_comment
comment|// RUN: %clang_lsan %s -o %t
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_error
error|#
directive|error
literal|"This test must be built in C mode"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// FIXME: ideally this should somehow check that we don't have libstdc++
return|return
literal|0
return|;
block|}
end_function

end_unit

