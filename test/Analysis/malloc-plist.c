begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=unix.Malloc -analyzer-output=plist -analyzer-config path-diagnostics-alternate=false -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t %s
end_comment

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|diagnosticTest
parameter_list|(
name|int
name|in
parameter_list|)
block|{
if|if
condition|(
name|in
operator|>
literal|5
condition|)
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
operator|(
operator|*
name|p
operator|)
operator|++
expr_stmt|;
block|}
name|in
operator|++
expr_stmt|;
comment|// expected-warning {{leak}}
block|}
end_function

begin_function
name|void
name|myArrayAllocation
parameter_list|()
block|{
name|int
modifier|*
modifier|*
name|A
decl_stmt|;
name|A
operator|=
name|malloc
argument_list|(
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|int
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|A
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|// expected-warning {{leak}}
block|}
end_function

begin_function
name|void
name|reallocDiagnostics
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
name|malloc
argument_list|(
literal|100
argument_list|)
decl_stmt|;
name|char
modifier|*
name|tmp
decl_stmt|;
name|tmp
operator|=
operator|(
name|char
operator|*
operator|)
name|realloc
argument_list|(
name|buf
argument_list|,
literal|0x1000000
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|tmp
condition|)
block|{
return|return;
comment|// expected-warning {{leak}}
block|}
name|buf
operator|=
name|tmp
expr_stmt|;
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|wrapper
parameter_list|()
block|{
name|void
modifier|*
name|x
init|=
name|malloc
argument_list|(
literal|100
argument_list|)
decl_stmt|;
comment|// This is intentionally done to test diagnostic emission.
if|if
condition|(
name|x
condition|)
return|return
name|x
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|test_wrapper
parameter_list|()
block|{
name|void
modifier|*
name|buf
init|=
name|wrapper
argument_list|()
decl_stmt|;
operator|(
name|void
operator|)
name|buf
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test what happens when the same call frees and allocated memory.
end_comment

begin_comment
comment|// Also tests the stack hint for parameters, when they are passed directly or via pointer.
end_comment

begin_function
name|void
name|my_free
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|my_malloc_and_free
parameter_list|(
name|void
modifier|*
modifier|*
name|x
parameter_list|)
block|{
operator|*
name|x
operator|=
name|malloc
argument_list|(
literal|100
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|x
condition|)
name|my_free
argument_list|(
operator|*
name|x
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|void
modifier|*
name|test_double_action_call
parameter_list|()
block|{
name|void
modifier|*
name|buf
decl_stmt|;
name|my_malloc_and_free
argument_list|(
operator|&
name|buf
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|// Test stack hint for 'reallocation failed'.
end_comment

begin_function
name|char
modifier|*
name|my_realloc
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
block|{
name|char
modifier|*
name|tmp
decl_stmt|;
name|tmp
operator|=
operator|(
name|char
operator|*
operator|)
name|realloc
argument_list|(
name|buf
argument_list|,
literal|0x1000000
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|tmp
condition|)
block|{
return|return
name|tmp
return|;
block|}
return|return
name|tmp
return|;
block|}
end_function

begin_function
name|void
name|reallocIntra
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|100
argument_list|)
decl_stmt|;
name|buf
operator|=
name|my_realloc
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test stack hint when returning a result.
end_comment

begin_function
specifier|static
name|char
modifier|*
name|malloc_wrapper_ret
parameter_list|()
block|{
return|return
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|use_ret
parameter_list|()
block|{
name|char
modifier|*
name|v
decl_stmt|;
name|v
operator|=
name|malloc_wrapper_ret
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test that we refer to the last symbol used in the leak diagnostic.
end_comment

begin_function
name|void
name|LeakedSymbol
parameter_list|(
name|int
name|in
parameter_list|)
block|{
name|int
modifier|*
name|m
init|=
literal|0
decl_stmt|;
name|int
modifier|*
name|p
decl_stmt|;
name|p
operator|=
operator|(
name|int
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
operator|(
operator|*
name|p
operator|)
operator|++
expr_stmt|;
name|m
operator|=
name|p
expr_stmt|;
name|p
operator|=
literal|0
expr_stmt|;
operator|(
operator|*
name|m
operator|)
operator|++
expr_stmt|;
name|in
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// Tests that exercise running remove dead bindings at Call exit.
end_comment

begin_function
specifier|static
name|void
name|function_with_leak1
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak1
parameter_list|()
block|{
name|function_with_leak1
argument_list|()
expr_stmt|;
name|int
name|y
init|=
literal|0
decl_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|function_with_leak2
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|int
name|m
init|=
literal|0
decl_stmt|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak2
parameter_list|()
block|{
name|function_with_leak2
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|function_with_leak3
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
if|if
condition|(
name|y
condition|)
name|y
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak3
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|function_with_leak3
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|function_with_leak4
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
if|if
condition|(
name|y
condition|)
name|y
operator|++
expr_stmt|;
else|else
name|y
operator|--
expr_stmt|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak4
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|function_with_leak4
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|anotherFunction5
parameter_list|()
block|{
return|return
literal|5
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|function_with_leak5
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
return|return
name|anotherFunction5
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak5
parameter_list|()
block|{
name|function_with_leak5
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|anotherFunction6
parameter_list|(
name|int
name|m
parameter_list|)
block|{
name|m
operator|++
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|function_with_leak6
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|anotherFunction6
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak6
parameter_list|()
block|{
name|function_with_leak6
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|empty_function
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|use_empty_function
parameter_list|()
block|{
name|empty_function
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|function_with_leak7
parameter_list|()
block|{
return|return
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|12
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|use_function_with_leak7
parameter_list|()
block|{
name|function_with_leak7
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test that we do not print the name of a variable not visible from where
end_comment

begin_comment
comment|// the issue is reported.
end_comment

begin_function
name|int
modifier|*
name|my_malloc
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_function
name|void
name|testOnlyRefferToVisibleVariables
parameter_list|()
block|{
name|my_malloc
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning {{Potential leak of memory}}
end_comment

begin_struct
struct|struct
name|PointerWrapper
block|{
name|int
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
modifier|*
name|my_malloc_into_struct
parameter_list|()
block|{
name|struct
name|PointerWrapper
name|w
decl_stmt|;
name|w
operator|.
name|p
operator|=
name|malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
return|return
name|w
operator|.
name|p
return|;
block|}
end_function

begin_function
name|void
name|testMyMalloc
parameter_list|()
block|{
name|my_malloc_into_struct
argument_list|()
expr_stmt|;
comment|// expected-warning {{Potential leak of memory}}
block|}
end_function

begin_comment
comment|// CHECK:<key>diagnostics</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;in&apos; is&gt; 5</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;in&apos; is&gt; 5</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;p&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;p&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;p&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>diagnosticTest</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>2</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>30</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;A&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;A&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;A&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>myArrayAllocation</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>2</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>40</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Attempt to reallocate memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Attempt to reallocate memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;tmp&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;tmp&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Reallocation failed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Reallocation failed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>reallocDiagnostics</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>21</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;wrapper&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;wrapper&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>35</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;test_wrapper&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;test_wrapper&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>35</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>35</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>36</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;x&apos; is non-null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;x&apos; is non-null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>38</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>21</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>test_wrapper</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_malloc_and_free&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_malloc_and_free&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;test_double_action_call&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;test_double_action_call&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>54</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>17</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_free&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_free&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>2</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;my_malloc_and_free&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;my_malloc_and_free&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>2</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is released</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is released</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>17</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning; memory was released via 1st parameter</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning; memory was released via 1st parameter</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning; memory was released via 1st parameter</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning; memory was released via 1st parameter</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>62</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>62</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>62</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>62</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>62</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Use of memory after it is freed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Use of memory after it is freed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Use of memory after it is freed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Use-after-free</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>test_double_action_call</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>3</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>62</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>30</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>35</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>75</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>30</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_realloc&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_realloc&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>66</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;reallocIntra&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;reallocIntra&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>66</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>66</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>67</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>67</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>67</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>67</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>40</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Attempt to reallocate memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Attempt to reallocate memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>68</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;tmp&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;tmp&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Reallocation failed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Reallocation failed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>70</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>70</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Reallocation of 1st parameter failed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Reallocation of 1st parameter failed</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>77</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>77</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>77</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;buf&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>reallocIntra</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>77</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>85</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>85</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>26</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;malloc_wrapper_ret&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;malloc_wrapper_ret&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>81</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_ret&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_ret&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>81</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>81</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>82</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>86</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>26</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;v&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;v&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;v&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>use_ret</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>2</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>91</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>91</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>15</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>93</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>98</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>98</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>98</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;m&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;m&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;m&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>LeakedSymbol</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>3</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>98</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>106</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>106</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>106</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak1&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak1&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>102</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak1&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak1&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>102</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>102</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>31</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>104</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>104</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>104</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>function_with_leak1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>104</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>115</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>115</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>115</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak2&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak2&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>110</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak2&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak2&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>110</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>110</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>31</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>111</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>112</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>112</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>112</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>function_with_leak2</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>112</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>124</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>124</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>124</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>26</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak3&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak3&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>118</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak3&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak3&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>118</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>118</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>31</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;y&apos; is not equal to 0</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;y&apos; is not equal to 0</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>120</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>121</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>121</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>121</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>function_with_leak3</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>121</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>135</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>135</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>135</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>26</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak4&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak4&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>127</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak4&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak4&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>127</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>127</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>31</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>128</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;y&apos; is 0</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;y&apos; is 0</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>129</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>function_with_leak4</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>146</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>146</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>146</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak5&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak5&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>141</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak5&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak5&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>141</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>141</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>31</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>142</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>143</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>143</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>143</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>function_with_leak5</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>143</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>157</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>157</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>157</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak6&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak6&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>152</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak6&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak6&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>152</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>152</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>31</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>22</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>153</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>27</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>154</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>154</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>20</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>154</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential leak of memory pointed to by&apos;x&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>function_with_leak6</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>154</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak7&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;function_with_leak7&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>165</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak7&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;use_function_with_leak7&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>165</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>165</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>166</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>28</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>169</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>170</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>170</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>170</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>use_function_with_leak7</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>170</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_malloc&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_malloc&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>174</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testOnlyRefferToVisibleVariables&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testOnlyRefferToVisibleVariables&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>174</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>174</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>17</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>12</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>175</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>21</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>179</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>180</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>180</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>180</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testOnlyRefferToVisibleVariables</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>180</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>path</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_malloc_into_struct&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;my_malloc_into_struct&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>185</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testMyMalloc&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testMyMalloc&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>185</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>185</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>186</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>186</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>186</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>186</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>14</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>187</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Memory is allocated</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>ranges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>25</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returned allocated memory</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>edges</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>start</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>191</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>23</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>192</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>192</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>192</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Potential memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Memory Error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Memory leak</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testMyMalloc</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>192</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

end_unit

