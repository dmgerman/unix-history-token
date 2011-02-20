begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"annotate-tokens-include.h"
end_include

begin_comment
comment|// RUN: c-index-test -test-annotate-tokens=%s:1:1:2:1 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Punctuation: "#" [1:1 - 1:2] inclusion directive=annotate-tokens-include.h
end_comment

begin_comment
comment|// CHECK: Identifier: "include" [1:2 - 1:9] inclusion directive=annotate-tokens-include.h
end_comment

begin_comment
comment|// CHECK: Literal: ""annotate-tokens-include.h"" [1:10 - 1:37] inclusion directive=annotate-tokens-include.h
end_comment

end_unit

