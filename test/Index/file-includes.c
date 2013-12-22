begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"targeted-top.h"
end_include

begin_include
include|#
directive|include
file|"targeted-preamble.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|LocalVar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|LocalVar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %S/targeted-top.h -Xclang -detailed-preprocessing-record
end_comment

begin_comment
comment|// RUN: c-index-test -file-includes-in=%s %s | FileCheck %s -check-prefix=LOCAL
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -file-includes-in=%s %s | FileCheck %s -check-prefix=LOCAL
end_comment

begin_comment
comment|// RUN: c-index-test -file-includes-in=%s %s -include %t.h | FileCheck %s -check-prefix=LOCAL
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -file-includes-in=%s %s -include %t.h | FileCheck %s -check-prefix=LOCAL
end_comment

begin_comment
comment|// LOCAL: inclusion directive=targeted-top.h ({{.*[/\\]}}test{{[/\\]}}Index{{[/\\]}}targeted-top.h) {{.*}}=[2:1 - 2:2]
end_comment

begin_comment
comment|// LOCAL: inclusion directive=targeted-preamble.h ({{.*[/\\]}}test{{[/\\]}}Index{{[/\\]}}targeted-preamble.h) =[3:1 - 3:2]
end_comment

begin_comment
comment|// RUN: c-index-test -file-includes-in=%S/targeted-top.h %s | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -file-includes-in=%S/targeted-top.h %s | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// RUN: c-index-test -file-includes-in=%S/targeted-top.h %s -include %t.h | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -file-includes-in=%S/targeted-top.h %s -include %t.h | FileCheck %s -check-prefix=TOP
end_comment

begin_comment
comment|// TOP: inclusion directive=targeted-nested1.h ({{.*[/\\]}}test{{[/\\]}}Index{{[/\\]}}targeted-nested1.h) =[5:1 - 5:2]
end_comment

begin_comment
comment|// TOP: inclusion directive=targeted-fields.h ({{.*[/\\]}}test{{[/\\]}}Index{{[/\\]}}targeted-fields.h) =[16:1 - 16:2]
end_comment

begin_comment
comment|// rdar://13803893
end_comment

begin_comment
comment|// RUN: c-index-test -file-includes-in=%S/Inputs/empty.h %S/Inputs/empty.h
end_comment

end_unit

