begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test transparent PTH support.
end_comment

begin_comment
comment|// RUN: clang -ccc-pch-is-pth -x c-header %s -o %t.h.pth -### 2> %t.log&&
end_comment

begin_comment
comment|// RUN: grep '".*/clang-cc" .* "-o" ".*\.h\.pth" "-x" "c-header" ".*pth\.c"' %t.log&&
end_comment

begin_comment
comment|// RUN: touch %t.h.pth&&
end_comment

begin_comment
comment|// RUN: clang -ccc-pch-is-pth -E -include %t.h %s -### 2> %t.log&&
end_comment

begin_comment
comment|// RUN: grep '".*/clang-cc" .*"-include-pth" ".*\.h\.pth" .*"-x" "c" ".*pth\.c"' %t.log
end_comment

end_unit

