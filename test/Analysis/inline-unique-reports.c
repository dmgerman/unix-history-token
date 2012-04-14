begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --analyze %s -Xclang -analyzer-ipa=inlining -o %t> /dev/null 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t %s
end_comment

begin_expr_stmt
specifier|static
specifier|inline
name|bug
argument_list|(
argument|int *p
argument_list|)
block|{
operator|*
name|p
operator|=
literal|0xDEADBEEF
block|; }
name|void
name|test_bug_1
argument_list|()
block|{
name|int
operator|*
name|p
operator|=
literal|0
block|;
name|bug
argument_list|(
name|p
argument_list|)
block|; }
name|void
name|test_bug_2
argument_list|()
block|{
name|int
operator|*
name|p
operator|=
literal|0
block|;
name|bug
argument_list|(
name|p
argument_list|)
block|; }
end_expr_stmt

begin_comment
comment|// CHECK:<?xml version="1.0" encoding="UTF-8"?>
end_comment

begin_comment
comment|// CHECK:<plist version="1.0">
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>files</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:</array>
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
comment|// CHECK:<key>path</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK:<key>edges</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>start</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
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

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;bug&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;bug&apos;</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;test_bug_1&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;test_bug_1&apos;</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK:<key>edges</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>start</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
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

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_context</key><string>bug</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:</dict>
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

begin_comment
comment|// CHECK:</plist>
end_comment

end_unit

