begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-output=text -analyzer-config suppress-null-return-paths=false -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-output=plist-multi-file -analyzer-config suppress-null-return-paths=false %s -o %t.plist
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t.plist %s
end_comment

begin_function
name|void
name|zero
parameter_list|(
name|int
modifier|*
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
literal|0
expr_stmt|;
comment|// expected-note@-1 {{Null pointer value stored to 'a'}}
block|}
end_function

begin_function
name|void
name|testZero
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|zero
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
comment|// expected-note@-1 {{Calling 'zero'}}
comment|// expected-note@-2 {{Returning from 'zero'}}
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'a')}}
block|}
end_function

begin_function
name|void
name|check
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|p
condition|)
block|{
comment|// expected-note@-1 + {{Assuming 'p' is null}}
comment|// expected-note@-2 + {{Taking false branch}}
return|return;
block|}
return|return;
block|}
end_function

begin_function
name|void
name|testCheck
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|check
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-note@-1 {{Calling 'check'}}
comment|// expected-note@-2 {{Returning from 'check'}}
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'a')}}
block|}
end_function

begin_function_decl
name|int
modifier|*
name|getPointer
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|testInitCheck
parameter_list|()
block|{
name|int
modifier|*
name|a
init|=
name|getPointer
argument_list|()
decl_stmt|;
comment|// expected-note@-1 {{Variable 'a' initialized here}}
name|check
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-note@-1 {{Calling 'check'}}
comment|// expected-note@-2 {{Returning from 'check'}}
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'a')}}
block|}
end_function

begin_function
name|void
name|testStoreCheck
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|getPointer
argument_list|()
expr_stmt|;
comment|// expected-note@-1 {{Value assigned to 'a'}}
name|check
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-note@-1 {{Calling 'check'}}
comment|// expected-note@-2 {{Returning from 'check'}}
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'a')}}
block|}
end_function

begin_function
name|int
modifier|*
name|getZero
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
comment|// expected-note@-1 + {{Variable 'p' initialized to a null pointer value}}
comment|// ^ This note checks that we add a second visitor for the return value.
return|return
name|p
return|;
comment|// expected-note@-1 + {{Returning null pointer (loaded from 'p')}}
block|}
end_function

begin_function
name|void
name|testReturnZero
parameter_list|()
block|{
operator|*
name|getZero
argument_list|()
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Calling 'getZero'}}
comment|// expected-note@-2 {{Returning from 'getZero'}}
comment|// expected-note@-3 {{Dereference of null pointer}}
block|}
end_function

begin_function
name|int
name|testReturnZero2
parameter_list|()
block|{
return|return
operator|*
name|getZero
argument_list|()
return|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Calling 'getZero'}}
comment|// expected-note@-2 {{Returning from 'getZero'}}
comment|// expected-note@-3 {{Dereference of null pointer}}
block|}
end_function

begin_function
name|void
name|testInitZero
parameter_list|()
block|{
name|int
modifier|*
name|a
init|=
name|getZero
argument_list|()
decl_stmt|;
comment|// expected-note@-1 {{Calling 'getZero'}}
comment|// expected-note@-2 {{Returning from 'getZero'}}
comment|// expected-note@-3 {{Variable 'a' initialized to a null pointer value}}
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'a')}}
block|}
end_function

begin_function
name|void
name|testStoreZero
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|getZero
argument_list|()
expr_stmt|;
comment|// expected-note@-1 {{Calling 'getZero'}}
comment|// expected-note@-2 {{Returning from 'getZero'}}
comment|// expected-note@-3 {{Null pointer value stored to 'a'}}
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'a')}}
block|}
end_function

begin_function
name|void
name|usePointer
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer}}
block|}
end_function

begin_function
name|void
name|testUseOfNullPointer
parameter_list|()
block|{
comment|// Test the case where an argument expression is itself a call.
name|usePointer
argument_list|(
name|getZero
argument_list|()
argument_list|)
expr_stmt|;
comment|// expected-note@-1 {{Calling 'getZero'}}
comment|// expected-note@-2 {{Returning from 'getZero'}}
comment|// expected-note@-3 {{Passing null pointer value via 1st parameter 'p'}}
comment|// expected-note@-4 {{Calling 'usePointer'}}
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
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;zero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;zero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>5</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>5</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>5</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Null pointer value stored to&apos;a&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Null pointer value stored to&apos;a&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>11</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;zero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;zero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;check&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testCheck&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testCheck&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<string>Assuming&apos;p&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;p&apos; is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;check&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>29</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>32</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>32</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>32</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>32</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>32</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testCheck</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>4</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>32</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>40</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>40</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>40</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;a&apos; initialized here</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;a&apos; initialized here</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>40</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>40</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;check&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testInitCheck&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testInitCheck&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<string>Assuming&apos;p&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;p&apos; is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;check&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>42</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>45</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>45</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>45</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>45</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>45</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testInitCheck</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>45</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Value assigned to&apos;a&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Value assigned to&apos;a&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>50</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;check&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testStoreCheck&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testStoreCheck&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<string>Assuming&apos;p&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;p&apos; is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>20</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;check&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>52</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testStoreCheck</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>55</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testReturnZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testReturnZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>4</integer>
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
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>69</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>16</integer>
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
comment|// CHECK-NEXT:<string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testReturnZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>1</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
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
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testReturnZero2&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testReturnZero2&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>19</integer>
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
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>76</integer>
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
comment|// CHECK-NEXT:<string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testReturnZero2</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>1</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testInitZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testInitZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;a&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;a&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>87</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testInitZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>5</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>3</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testStoreZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testStoreZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Null pointer value stored to&apos;a&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Null pointer value stored to&apos;a&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testStoreZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>5</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testUseOfNullPointer&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testUseOfNullPointer&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>61</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Variable&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>64</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning null pointer (loaded from&apos;p&apos;)</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;getZero&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Passing null pointer value via 1st parameter&apos;p&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Passing null pointer value via 1st parameter&apos;p&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>107</integer>
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
comment|// CHECK-NEXT:<string>Calling&apos;usePointer&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;usePointer&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>100</integer>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testUseOfNullPointer&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testUseOfNullPointer&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>100</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>100</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>101</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>101</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>101</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>101</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>101</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>usePointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>101</integer>
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
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

end_unit

