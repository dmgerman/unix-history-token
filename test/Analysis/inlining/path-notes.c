begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=text -analyzer-config suppress-null-return-paths=false -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=plist-multi-file -analyzer-config suppress-null-return-paths=false -analyzer-config path-diagnostics-alternate=false %s -o %t.plist
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
name|testCheck
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
condition|)
block|{
comment|// expected-note@-1 + {{Assuming 'a' is null}}
comment|// expected-note@-2 + {{Taking false branch}}
empty_stmt|;
block|}
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
comment|// expected-note@-1 {{'a' initialized here}}
if|if
condition|(
name|a
condition|)
block|{
comment|// expected-note@-1 + {{Assuming 'a' is null}}
comment|// expected-note@-2 + {{Taking false branch}}
empty_stmt|;
block|}
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
if|if
condition|(
name|a
condition|)
block|{
comment|// expected-note@-1 + {{Assuming 'a' is null}}
comment|// expected-note@-2 + {{Taking false branch}}
empty_stmt|;
block|}
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
comment|// expected-note@-1 + {{'p' initialized to a null pointer value}}
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
comment|// expected-note@-3 {{'a' initialized to a null pointer value}}
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

begin_struct
struct|struct
name|X
block|{
name|char
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|setFieldToNull
parameter_list|(
name|struct
name|X
modifier|*
name|x
parameter_list|)
block|{
name|x
operator|->
name|p
operator|=
literal|0
expr_stmt|;
comment|// expected-note {{Null pointer value stored to field 'p'}}
block|}
end_function

begin_function
name|int
name|testSetFieldToNull
parameter_list|(
name|struct
name|X
modifier|*
name|x
parameter_list|)
block|{
name|setFieldToNull
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-note {{Calling 'setFieldToNull'}}
comment|// expected-note@-1{{Returning from 'setFieldToNull'}}
return|return
operator|*
name|x
operator|->
name|p
return|;
comment|// expected-warning@-1 {{Dereference of null pointer (loaded from field 'p')}}
comment|// expected-note@-2 {{Dereference of null pointer (loaded from field 'p')}}
block|}
end_function

begin_struct
struct|struct
name|Outer
block|{
struct|struct
name|Inner
block|{
name|int
modifier|*
name|p
decl_stmt|;
block|}
name|inner
struct|;
block|}
struct|;
end_struct

begin_function
name|void
name|test
parameter_list|(
name|struct
name|Outer
modifier|*
name|wrapperPtr
parameter_list|)
block|{
name|wrapperPtr
operator|->
name|inner
operator|.
name|p
operator|=
literal|0
expr_stmt|;
comment|// expected-note {{Null pointer value stored to field 'p'}}
operator|*
name|wrapperPtr
operator|->
name|inner
operator|.
name|p
operator|=
literal|1
expr_stmt|;
comment|//expected-warning {{Dereference of null pointer (loaded from field 'p')}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from field 'p')}}
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|int
modifier|*
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
operator|*
name|p
condition|)
return|return;
comment|// expected-note {{Taking false branch}}
comment|// expected-note@-1 {{Assuming pointer value is null}}
operator|*
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// expected-warning {{Dereference of null pointer}}
comment|// expected-note@-1 {{Dereference of null pointer}}
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>14</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>52499a849b132453be19ec9167d8c021</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>4</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
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
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;a&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;a&apos; is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>cb893891b6a08ee4b7dc3d0c11df856e</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testCheck</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>6</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>24</integer>
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
comment|// CHECK-NEXT:<string>&apos;a&apos; initialized here</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;a&apos; initialized here</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;a&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;a&apos; is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>34</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>ec20b5e53a72c82d442b3ca04c81e138</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testInitCheck</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>8</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>39</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;a&apos; is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming&apos;a&apos; is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>46</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>51</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>1ae8e7c84d15f307abc1df9f5612078b</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testStoreCheck</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>8</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>d03346854b8f45b55cbd5efe29bf2c8e</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testReturnZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>65</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>5a72f98932a4061a833287a12b28ba8b</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testReturnZero2</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>72</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<string>&apos;a&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;a&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>79</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>83</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>6d3745ba4b32e1858de16c61fecf8ed4</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testInitZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>5</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>88</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>92</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>2d25b170621486480ca76aaba4c7a0c0</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testStoreZero</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>5</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>56</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;p&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>57</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>60</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>103</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>96</integer>
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
comment|// CHECK-NEXT:<key>end</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<array>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>567151df0ae29b0f0e1a412114d544dc</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>usePointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>97</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<string>Calling&apos;setFieldToNull&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Calling&apos;setFieldToNull&apos;</string>
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
comment|// CHECK-NEXT:<string>Entered call from&apos;testSetFieldToNull&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Entered call from&apos;testSetFieldToNull&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>112</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>112</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>113</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>2</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>113</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>2</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>113</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>2</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>113</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>col</key><integer>2</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>113</integer>
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
comment|// CHECK-NEXT:<string>Null pointer value stored to field&apos;p&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Null pointer value stored to field&apos;p&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<string>Returning from&apos;setFieldToNull&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Returning from&apos;setFieldToNull&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>117</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>119</integer>
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
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from field&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from field&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from field&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>7849ab11af99aee1e3603a24ae95cdfd</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>testSetFieldToNull</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>3</string>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>131</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>131</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>131</integer>
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
comment|// CHECK-NEXT:<string>Null pointer value stored to field&apos;p&apos;</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Null pointer value stored to field&apos;p&apos;</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>131</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>131</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>132</integer>
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
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from field&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from field&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from field&apos;p&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>3ccb5e7e2cc82aba5c28a1cc873c83a1</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>test</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>2</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>24</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<string>Assuming pointer value is null</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Assuming pointer value is null</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>137</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:<key>check_name</key><string>core.NullDereference</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>19292468c6c6f83fbbdb2ff072bb2ae8</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>test4</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_function_offset</key><string>3</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>139</integer>
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
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

end_unit

