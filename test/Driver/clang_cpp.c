begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that -include isn't included twice with -save-temps.
end_comment

begin_comment
comment|// RUN: %clang -S -o - %s -include %t.h -save-temps -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-include' %t.log | count 1
end_comment

end_unit

