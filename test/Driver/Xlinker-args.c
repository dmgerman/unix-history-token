begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we extract --no-demangle from '-Xlinker' and '-Wl,', since that
end_comment

begin_comment
comment|// was a collect2 argument.
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### \
end_comment

begin_comment
comment|// RUN:   -Xlinker one -Xlinker --no-demangle \
end_comment

begin_comment
comment|// RUN:   -Wl,two,--no-demangle,three -Xlinker four %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: "one" "two" "three" "four"
end_comment

end_unit

