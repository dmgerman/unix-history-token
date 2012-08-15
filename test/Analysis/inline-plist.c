begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --analyze %s -Xclang -analyzer-ipa=inlining -fblocks -o %t
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

begin_function
name|void
name|triggers_bug
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

begin_comment
comment|// This function triggers a bug by calling triggers_bug().  The diagnostics
end_comment

begin_comment
comment|// should show when p is assumed to be null.
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|!
name|p
condition|)
return|return;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
name|triggers_bug
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ========================================================================== //
end_comment

begin_comment
comment|// Test inlining of blocks.
end_comment

begin_comment
comment|// ========================================================================== //
end_comment

begin_function
name|void
name|test_block__capture_null
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
lambda|^
parameter_list|()
block|{
operator|*
name|p
operator|=
literal|1
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_block_ret
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
lambda|^
parameter_list|()
block|{
name|int
modifier|*
name|q
init|=
literal|0
decl_stmt|;
return|return
name|q
return|;
block|}
argument_list|()
decl_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_block_blockvar
parameter_list|()
block|{
specifier|__block
name|int
modifier|*
name|p
decl_stmt|;
lambda|^
parameter_list|()
block|{
name|p
operator|=
literal|0
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_block_arg
parameter_list|()
block|{
name|int
modifier|*
name|p
decl_stmt|;
lambda|^
parameter_list|(
name|int
modifier|*
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|q
operator|=
literal|0
expr_stmt|;
block|}
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
operator|*
name|p
operator|=
literal|1
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>6</integer>
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
comment|// CHECK:<key>col</key><integer>6</integer>
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
comment|// CHECK:<key>issue_hash</key><integer>4</integer>
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
comment|// CHECK:<key>issue_hash</key><integer>1</integer>
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
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Assuming&apos;p&apos; is null</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Assuming&apos;p&apos; is null</string>
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
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>33</integer>
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
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>36</integer>
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
comment|// CHECK:<key>line</key><integer>36</integer>
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
comment|// CHECK:<key>line</key><integer>36</integer>
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
comment|// CHECK:<key>line</key><integer>36</integer>
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
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>37</integer>
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
comment|// CHECK:<key>line</key><integer>37</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>16</integer>
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
comment|// CHECK:<key>line</key><integer>37</integer>
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
comment|// CHECK:<key>line</key><integer>37</integer>
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
comment|// CHECK:<key>line</key><integer>37</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>19</integer>
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
comment|// CHECK:<string>Calling&apos;triggers_bug&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;triggers_bug&apos;</string>
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
comment|// CHECK:<key>line</key><integer>26</integer>
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
comment|// CHECK:<string>Entered call from&apos;bar&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;bar&apos;</string>
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
comment|// CHECK:<key>line</key><integer>26</integer>
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
comment|// CHECK:<key>line</key><integer>26</integer>
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
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>27</integer>
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
comment|// CHECK:<key>line</key><integer>27</integer>
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
comment|// CHECK:<key>line</key><integer>27</integer>
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
comment|// CHECK:<key>line</key><integer>27</integer>
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
comment|// CHECK:<key>line</key><integer>27</integer>
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
comment|// CHECK:<key>issue_context</key><string>triggers_bug</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_hash</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>27</integer>
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
comment|// CHECK:<key>line</key><integer>45</integer>
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
comment|// CHECK:<key>line</key><integer>45</integer>
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
comment|// CHECK:<key>line</key><integer>45</integer>
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
comment|// CHECK:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK:<key>line</key><integer>45</integer>
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
comment|// CHECK:<key>line</key><integer>45</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
end_comment

begin_comment
comment|// CHECK:<key>col</key><integer>18</integer>
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
comment|// CHECK:<string>Calling anonymous block</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling anonymous block</string>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;test_block__capture_null&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;test_block__capture_null&apos;</string>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>46</integer>
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
comment|// CHECK:<key>line</key><integer>50</integer>
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
comment|// CHECK:<key>line</key><integer>50</integer>
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
comment|// CHECK:<key>line</key><integer>50</integer>
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
comment|// CHECK:<key>line</key><integer>50</integer>
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
comment|// CHECK:<key>line</key><integer>50</integer>
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
comment|// CHECK:<key>line</key><integer>50</integer>
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
comment|// CHECK:<key>end</key>
end_comment

begin_comment
comment|// CHECK:<array>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>51</integer>
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
comment|// CHECK:<key>line</key><integer>51</integer>
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
comment|// CHECK:<key>line</key><integer>51</integer>
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
comment|// CHECK:<key>line</key><integer>51</integer>
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
comment|// CHECK:<key>line</key><integer>51</integer>
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
comment|// CHECK:<key>depth</key><integer>0</integer>
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
comment|// CHECK:<key>issue_context</key><string>test_block_ret</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_hash</key><integer>2</integer>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>51</integer>
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
comment|// CHECK:<key>line</key><integer>55</integer>
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
comment|// CHECK:<key>line</key><integer>55</integer>
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
comment|// CHECK:<key>line</key><integer>56</integer>
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
comment|// CHECK:<key>line</key><integer>56</integer>
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
comment|// CHECK:<key>line</key><integer>56</integer>
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
comment|// CHECK:<key>line</key><integer>56</integer>
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
comment|// CHECK:<key>line</key><integer>57</integer>
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
comment|// CHECK:<key>line</key><integer>57</integer>
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
comment|// CHECK:<key>line</key><integer>57</integer>
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
comment|// CHECK:<key>line</key><integer>57</integer>
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
comment|// CHECK:<key>line</key><integer>57</integer>
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
comment|// CHECK:<key>depth</key><integer>0</integer>
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
comment|// CHECK:<key>issue_context</key><string>test_block_blockvar</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_hash</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>57</integer>
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
comment|// CHECK:<key>line</key><integer>61</integer>
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
comment|// CHECK:<key>line</key><integer>61</integer>
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
comment|// CHECK:<key>line</key><integer>62</integer>
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
comment|// CHECK:<key>line</key><integer>62</integer>
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
comment|// CHECK:<key>line</key><integer>62</integer>
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
comment|// CHECK:<key>line</key><integer>62</integer>
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
comment|// CHECK:<key>line</key><integer>63</integer>
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
comment|// CHECK:<key>line</key><integer>63</integer>
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
comment|// CHECK:<key>line</key><integer>63</integer>
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
comment|// CHECK:<key>line</key><integer>63</integer>
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
comment|// CHECK:<key>line</key><integer>63</integer>
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
comment|// CHECK:<key>depth</key><integer>0</integer>
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
comment|// CHECK:<key>issue_context</key><string>test_block_arg</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_hash</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
end_comment

begin_comment
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>63</integer>
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

