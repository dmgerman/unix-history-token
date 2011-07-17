begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s -c -o tmp.o -triple i686-pc-linux-gnu -integrated-as -Wa,--noexecstack 2>&1 | grep "mnoexecstack"
end_comment

end_unit

