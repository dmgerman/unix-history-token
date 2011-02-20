begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### \
end_comment

begin_comment
comment|// RUN:   -M -MM %s 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-sys-header-deps"' %t | count 0
end_comment

end_unit

