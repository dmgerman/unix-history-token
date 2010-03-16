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

begin_comment
comment|// RUN: echo '#define m0 ""'> %t.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.h.pch %t.h
end_comment

begin_comment
comment|// RUN: echo ''> %t.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -include-pch %t.h.pch %s 2>&1 | grep "size of file"
end_comment

begin_comment
comment|// RUN: echo '#define m0 000'> %t.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.h.pch %t.h
end_comment

begin_comment
comment|// RUN: echo ''> %t.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -include-pch %t.h.pch %s 2>&1 | grep "size of file"
end_comment

end_unit

