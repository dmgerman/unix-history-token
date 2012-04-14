begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --analyze %s -Xclang -analyzer-ipa=inlining -o %t
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t %s
end_comment

begin_comment
comment|//<rdar://problem/10967815>
end_comment

begin_function
name|void
name|mmm
parameter_list|(
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
name|y
operator|!=
literal|0
condition|)
name|y
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|mmm
argument_list|(
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|!=
literal|0
condition|)
name|x
operator|++
expr_stmt|;
return|return
literal|5
operator|/
name|x
return|;
block|}
end_function

begin_comment
comment|// Test a bug triggering only when inlined.
end_comment

begin_function
name|void
name|has_bug
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_has_bug
parameter_list|()
block|{
name|has_bug
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

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
comment|// CHECK:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>10</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>9</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>9</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>9</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>9</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>14</integer>
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
comment|// CHECK:<string>Assuming&apos;x&apos; is equal to 0</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Assuming&apos;x&apos; is equal to 0</string>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>9</integer>
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
comment|// CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>9</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>5</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>12</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>12</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>12</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>12</integer>
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
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>14</integer>
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
comment|// CHECK:<string>Division by zero</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Division by zero</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>description</key><string>Division by zero</string>
end_comment

begin_comment
comment|// CHECK:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK:<key>type</key><string>Division by zero</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_context</key><string>foo</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>12</integer>
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
comment|// CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>23</integer>
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
comment|// CHECK:<key>line</key><integer>23</integer>
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
comment|// CHECK:<key>line</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>12</integer>
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
comment|// CHECK:<string>Calling&apos;has_bug&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;has_bug&apos;</string>
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
comment|// CHECK:<key>line</key><integer>18</integer>
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
comment|// CHECK:<string>Entered call from&apos;test_has_bug&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;test_has_bug&apos;</string>
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
comment|// CHECK:<key>line</key><integer>18</integer>
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
comment|// CHECK:<key>line</key><integer>18</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>issue_context</key><string>has_bug</string>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>19</integer>
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

