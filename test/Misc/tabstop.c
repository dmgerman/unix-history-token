begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ftabstop 3 -fsyntax-only %s 2>&1 | FileCheck -check-prefix=3 -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ftabstop 4 -fsyntax-only %s 2>&1 | FileCheck -check-prefix=4 -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ftabstop 5 -fsyntax-only %s 2>&1 | FileCheck -check-prefix=5 -strict-whitespace %s
end_comment

begin_comment
comment|// tab
end_comment

begin_decl_stmt
name|void
modifier|*
name|a
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// tab tab
end_comment

begin_decl_stmt
name|void
modifier|*
name|b
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 3x space tab
end_comment

begin_decl_stmt
name|void
modifier|*
name|c
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// tab at column 10
end_comment

begin_decl_stmt
name|void
modifier|*
name|d
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|//CHECK-3: {{^   void\* a = 1;}}
end_comment

begin_comment
comment|//CHECK-3: {{^      void\* b = 1;}}
end_comment

begin_comment
comment|//CHECK-3: {{^      void\* c = 1;}}
end_comment

begin_comment
comment|//CHECK-3: {{^void\* d =   1;}}
end_comment

begin_comment
comment|//CHECK-4: {{^    void\* a = 1;}}
end_comment

begin_comment
comment|//CHECK-4: {{^        void\* b = 1;}}
end_comment

begin_comment
comment|//CHECK-4: {{^    void\* c = 1;}}
end_comment

begin_comment
comment|//CHECK-4: {{^void\* d =   1;}}
end_comment

begin_comment
comment|//CHECK-5: {{^     void\* a = 1;}}
end_comment

begin_comment
comment|//CHECK-5: {{^          void\* b = 1;}}
end_comment

begin_comment
comment|//CHECK-5: {{^     void\* c = 1;}}
end_comment

begin_comment
comment|//CHECK-5: {{^void\* d = 1;}}
end_comment

end_unit

