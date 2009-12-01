begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -### -S -msoft-float %s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-no-implicit-float"' %t.log
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -### -S -msoft-float -mno-soft-float %s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-no-implicit-float"' %t.log | count 0
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -### -S -mno-soft-float %s -msoft-float 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-no-implicit-float"' %t.log
end_comment

end_unit

