begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Don't crash.
end_comment

begin_comment
comment|// RUN: cp %S/modified-header-crash.h %t.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DCAKE -x c-header %t.h -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: echo>> %t.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -include-pch %t -fsyntax-only
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|foo
operator|=
literal|3
expr_stmt|;
block|}
end_function

end_unit

