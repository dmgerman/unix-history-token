begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fbounds-checking -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fbounds-checking=3 -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK2< %t %s
end_comment

begin_comment
comment|// CHECK: "-fbounds-checking=1"
end_comment

begin_comment
comment|// CHECK2: "-fbounds-checking=3"
end_comment

end_unit

