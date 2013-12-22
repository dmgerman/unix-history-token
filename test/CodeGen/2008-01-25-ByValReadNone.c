begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// It could hit in @llvm.memcpy with "-triple x86_64-(mingw32|win32)".
end_comment

begin_comment
comment|// CHECK-NOT: readonly
end_comment

begin_comment
comment|// CHECK-NOT: readnone
end_comment

begin_comment
comment|// The struct being passed byval means that we cannot mark the
end_comment

begin_comment
comment|// function readnone.  Readnone would allow stores to the arg to
end_comment

begin_comment
comment|// be deleted in the caller.  We also don't allow readonly since
end_comment

begin_comment
comment|// the callee might write to the byval parameter.  The inliner
end_comment

begin_comment
comment|// would have to assume the worse and introduce an explicit
end_comment

begin_comment
comment|// temporary when inlining such a function, which is costly for
end_comment

begin_comment
comment|// the common case in which the byval argument is not written.
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|A
index|[
literal|1000
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
name|f
argument_list|(
expr|struct
name|S
name|x
argument_list|)
block|{
name|x
operator|.
name|A
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|x
operator|.
name|A
index|[
literal|0
index|]
return|;
block|}
end_decl_stmt

begin_function_decl
name|int
name|g
parameter_list|(
name|struct
name|S
name|x
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(pure
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|h
parameter_list|(
name|struct
name|S
name|x
parameter_list|)
block|{
return|return
name|g
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

