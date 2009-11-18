begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -E mode is invariant when using an implicit PCH.
end_comment

begin_comment
comment|// RUN: clang-cc -include %S/preprocess.h -E -o %t.orig %s
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -o %t %S/preprocess.h
end_comment

begin_comment
comment|// RUN: clang-cc -include-pch %t -E -o %t.from_pch %s
end_comment

begin_comment
comment|// RUN: diff %t.orig %t.from_pch
end_comment

begin_decl_stmt
name|a_typedef
name|a_value
decl_stmt|;
end_decl_stmt

end_unit

