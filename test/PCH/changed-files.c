begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|const
name|char
modifier|*
name|s0
init|=
name|m0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s1
init|=
name|m1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|s2
init|=
name|m0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: This test fails inexplicably on Windows in a manner that makes it
end_comment

begin_comment
comment|// look like standard error isn't getting flushed properly.
end_comment

begin_comment
comment|// RUN: true
end_comment

begin_comment
comment|// RUNx: echo '#define m0 ""'> %t.h
end_comment

begin_comment
comment|// RUNx: %clang_cc1 -emit-pch -o %t.h.pch %t.h
end_comment

begin_comment
comment|// RUNx: echo ''> %t.h
end_comment

begin_comment
comment|// RUNx: not %clang_cc1 -include-pch %t.h.pch %s 2> %t.stderr
end_comment

begin_comment
comment|// RUNx: grep "modified" %t.stderr
end_comment

begin_comment
comment|// RUNx: echo '#define m0 000'> %t.h
end_comment

begin_comment
comment|// RUNx: %clang_cc1 -emit-pch -o %t.h.pch %t.h
end_comment

begin_comment
comment|// RUNx: echo ''> %t.h
end_comment

begin_comment
comment|// RUNx: not %clang_cc1 -include-pch %t.h.pch %s 2> %t.stderr
end_comment

begin_comment
comment|// RUNx: grep "modified" %t.stderr
end_comment

begin_comment
comment|// RUNx: echo '#define m0 000'> %t.h
end_comment

begin_comment
comment|// RUNx: echo "#define m1 'abcd'">> %t.h
end_comment

begin_comment
comment|// RUNx: %clang_cc1 -emit-pch -o %t.h.pch %t.h
end_comment

begin_comment
comment|// RUNx: echo ''> %t.h
end_comment

begin_comment
comment|// RUNx: not %clang_cc1 -include-pch %t.h.pch %s 2> %t.stderr
end_comment

begin_comment
comment|// RUNx: grep "modified" %t.stderr
end_comment

end_unit

