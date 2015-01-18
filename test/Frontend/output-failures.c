begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -emit-llvm -o %S/doesnotexist/somename %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=OUTPUTFAIL -input-file=%t %s
end_comment

begin_comment
comment|// OUTPUTFAIL: error: unable to open output file '{{.*}}{{[/\\]}}test{{[/\\]}}Frontend{{[/\\]}}doesnotexist{{[/\\]}}somename': '{{[nN]}}o such file or directory'
end_comment

end_unit

