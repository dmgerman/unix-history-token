begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CFSTR
parameter_list|(
name|x
parameter_list|)
value|(CFStringRef) __builtin___CFStringMakeConstantString (x)
end_define

begin_function
name|void
name|f
parameter_list|()
block|{
name|CFSTR
argument_list|(
literal|"Hello, World!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6151192
end_comment

begin_decl_stmt
name|void
modifier|*
name|G
init|=
name|CFSTR
argument_list|(
literal|"yo joe"
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

