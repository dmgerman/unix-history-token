begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env RC_DEBUG_OPTIONS=1 \
end_comment

begin_comment
comment|// RUN:     CC_LOG_DIAGNOSTICS=1 \
end_comment

begin_comment
comment|// RUN:     CC_LOG_DIAGNOSTICS_FILE=%t.log \
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -ccc-host-triple x86_64-apple-darwin10 -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.log
end_comment

begin_function
name|int
name|f0
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>main-file</key>
end_comment

begin_comment
comment|// CHECK:<string>{{.*}}cc-log-diagnostics.c</string>
end_comment

begin_comment
comment|// CHECK:<key>dwarf-debug-flags</key>
end_comment

begin_comment
comment|// CHECK:<string>{{.*}}clang{{.*}}-fsyntax-only{{.*}}</string>
end_comment

begin_comment
comment|// CHECK:<key>diagnostics</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>level</key>
end_comment

begin_comment
comment|// CHECK:<string>warning</string>
end_comment

begin_comment
comment|// CHECK:<key>filename</key>
end_comment

begin_comment
comment|// CHECK:<string>{{.*}}cc-log-diagnostics.c</string>
end_comment

begin_comment
comment|// CHECK:<key>line</key>
end_comment

begin_comment
comment|// CHECK:<integer>7</integer>
end_comment

begin_comment
comment|// CHECK:<key>column</key>
end_comment

begin_comment
comment|// CHECK:<integer>11</integer>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>control reaches end of non-void function</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

end_unit

