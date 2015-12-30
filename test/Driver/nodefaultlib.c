begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i686-pc-linux-gnu -### -nodefaultlibs %s 2>&1 | FileCheck -check-prefix=TEST1 %s
end_comment

begin_comment
comment|// TEST1-NOT: start-group
end_comment

begin_comment
comment|// TEST1-NOT: "-lgcc"
end_comment

begin_comment
comment|// TEST1-NOT: "-lc"
end_comment

begin_comment
comment|// TEST1: crtbegin
end_comment

begin_comment
comment|// TEST1: crtend
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-linux-gnu -stdlib=libc++ -nodefaultlibs -lstdc++ -### %s 2>&1 | FileCheck -check-prefix=TEST2 %s
end_comment

begin_comment
comment|// TEST2-NOT: "-lc++"
end_comment

begin_comment
comment|// TEST2: "-lstdc++"
end_comment

end_unit

