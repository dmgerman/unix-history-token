begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -pedantic-errors %s 2>&1 | FileCheck %s --check-prefix=PRESUMED
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -pedantic-errors -fno-diagnostics-use-presumed-location %s 2>&1 | FileCheck %s --check-prefix=SPELLING
end_comment

begin_line
line|#
directive|line
number|100
end_line

begin_define
define|#
directive|define
name|X
parameter_list|(
name|y
parameter_list|)
value|y
end_define

begin_macro
name|X
argument_list|(
argument|int n = error
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// PRESUMED: diag-presumed.c:101:11: error: use of undeclared identifier 'error'
end_comment

begin_comment
comment|// PRESUMED: diag-presumed.c:100:14: note: expanded from
end_comment

begin_comment
comment|// SPELLING: diag-presumed.c:6:11: error: use of undeclared identifier 'error'
end_comment

begin_comment
comment|// SPELLING: diag-presumed.c:5:14: note: expanded from
end_comment

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// PRESUMED: diag-presumed.c:108:1: error: extra ';' outside of a functio
end_comment

begin_comment
comment|// SPELLING: diag-presumed.c:13:1: error: extra ';' outside of a functio
end_comment

begin_empty
empty|# 1 "thing1.cc" 1
end_empty

begin_empty
empty|# 1 "thing1.h" 1
end_empty

begin_empty
empty|# 1 "systemheader.h" 1 3
end_empty

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// No diagnostic here: we're in a system header, even if we're using spelling
end_comment

begin_comment
comment|// locations for the diagnostics..
end_comment

begin_comment
comment|// PRESUMED-NOT: extra ';'
end_comment

begin_comment
comment|// SPELLING-NOT: extra ';'
end_comment

begin_decl_stmt
name|another
name|error
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PRESUMED: included from {{.*}}diag-presumed.c:112:
end_comment

begin_comment
comment|// PRESUMED: from thing1.cc:1:
end_comment

begin_comment
comment|// PRESUMED: from thing1.h:1:
end_comment

begin_comment
comment|// PRESUMED: systemheader.h:7:1: error: unknown type name 'another'
end_comment

begin_comment
comment|// SPELLING-NOT: included from
end_comment

begin_comment
comment|// SPELLING: diag-presumed.c:26:1: error: unknown type name 'another'
end_comment

begin_empty
empty|# 1 "thing1.h" 2
end_empty

begin_empty
empty|# 1 "thing1.cc" 2
end_empty

end_unit

