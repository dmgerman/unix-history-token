begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wno-unused-value %s 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// REQUIRES: asserts
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
literal|"§Ã"
expr_stmt|;
comment|// ø
comment|// CHECK: {{^  "<A7><C3>"; //<F8>}}
comment|// CHECK: {{^   \^~~~~~~}}
comment|/* þ« */
specifier|const
name|char
modifier|*
name|d
init|=
literal|"¥"
decl_stmt|;
comment|// CHECK: {{^  /\*<FE><AB> \*/ const char \*d = "<A5>";}}
comment|// CHECK: {{^                                  \^~~~}}
literal|"xxé¿¿¿d"
expr_stmt|;
comment|// CHECK: {{^  "xx<U\+9FFF><BF>d";}}
comment|// CHECK: {{^             \^~~~}}
literal|"xxé¿bcd"
expr_stmt|;
comment|// CHECK: {{^  "xx<E9><BF>bcd";}}
comment|// CHECK: {{^     \^~~~~~~~}}
literal|"xxéabcd"
expr_stmt|;
comment|// CHECK: {{^  "xx<E9>abcd";}}
comment|// CHECK: {{^     \^~~~}}
literal|"xxé¿é¿d"
expr_stmt|;
comment|// CHECK: {{^  "xx<E9><BF><E9><BF>d";}}
comment|// CHECK: {{^     \^~~~~~~~~~~~~~~}}
literal|"xxé¿xxxxxxxxxxxxxxxxxxxxxé¿xx"
expr_stmt|;
comment|// CHECK: {{^  "xx<E9><BF>xxxxxxxxxxxxxxxxxxxxx<E9><BF>xx";}}
comment|// CHECK: {{^     \^~~~~~~~                     ~~~~~~~~}}
literal|"?kÍ
literal|S¥ÇØg7,	2,D
literal|íu*É,pûäÚ&(K§:Ñ'1áÎjO
literal|Å°<:"
expr_stmt|;
literal|"xé¿xé¿xé¿xé¿xé¿xé¿xé¿xé¿xé¿xé¿xé¿xé¿x"
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NOT:Assertion
end_comment

end_unit

