begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-ipa=inlining -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-ipa=inlining -analyzer-output=plist-multi-file %s -o - | FileCheck %s
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
comment|// expected-note@-2 + {{Assuming pointer value is null}}
comment|// expected-note@-3 + {{Taking false branch}}
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

begin_comment
comment|// CHECK:<?xml version="1.0" encoding="UTF-8"?>
end_comment

begin_comment
comment|// CHECK:<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
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
comment|// CHECK:<string>{{.*}}path-notes.c</string>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;zero&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;zero&apos;</string>
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
comment|// CHECK:<string>Entered call from&apos;testZero&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;testZero&apos;</string>
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
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Null pointer value stored to&apos;a&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Null pointer value stored to&apos;a&apos;</string>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;zero&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;zero&apos;</string>
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
comment|// CHECK:<key>line</key><integer>13</integer>
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
comment|// CHECK:<key>line</key><integer>13</integer>
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
comment|// CHECK:<key>line</key><integer>13</integer>
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
comment|// CHECK:<key>line</key><integer>13</integer>
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
comment|// CHECK:<key>line</key><integer>13</integer>
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
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
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
comment|// CHECK:<key>issue_context</key><string>testZero</string>
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
comment|// CHECK:<key>line</key><integer>13</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;check&apos;</string>
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
comment|// CHECK:<string>Entered call from&apos;testCheck&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;testCheck&apos;</string>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Assuming pointer value is null</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Assuming pointer value is null</string>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>25</integer>
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
comment|// CHECK:<key>line</key><integer>25</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;check&apos;</string>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:<key>line</key><integer>29</integer>
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
comment|// CHECK:<key>line</key><integer>32</integer>
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
comment|// CHECK:<key>line</key><integer>32</integer>
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
comment|// CHECK:<key>line</key><integer>32</integer>
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
comment|// CHECK:<key>line</key><integer>32</integer>
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
comment|// CHECK:<key>line</key><integer>32</integer>
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
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
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
comment|// CHECK:<key>issue_context</key><string>testCheck</string>
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
comment|// CHECK:<key>line</key><integer>32</integer>
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
comment|// CHECK:<key>line</key><integer>40</integer>
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
comment|// CHECK:<key>line</key><integer>40</integer>
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
comment|// CHECK:<key>line</key><integer>40</integer>
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
comment|// CHECK:<string>Variable&apos;a&apos; initialized here</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Variable&apos;a&apos; initialized here</string>
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
comment|// CHECK:<key>line</key><integer>40</integer>
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
comment|// CHECK:<key>line</key><integer>40</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;check&apos;</string>
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
comment|// CHECK:<string>Entered call from&apos;testInitCheck&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;testInitCheck&apos;</string>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>25</integer>
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
comment|// CHECK:<key>line</key><integer>25</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;check&apos;</string>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>42</integer>
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
comment|// CHECK:<key>line</key><integer>45</integer>
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
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
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
comment|// CHECK:<key>issue_context</key><string>testInitCheck</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_hash</key><integer>6</integer>
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
comment|// CHECK:<string>Value assigned to&apos;a&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Value assigned to&apos;a&apos;</string>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Calling&apos;check&apos;</string>
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
comment|// CHECK:<string>Entered call from&apos;testStoreCheck&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Entered call from&apos;testStoreCheck&apos;</string>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:<key>col</key><integer>7</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
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
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<dict>
end_comment

begin_comment
comment|// CHECK:<key>line</key><integer>19</integer>
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
comment|// CHECK:<key>line</key><integer>25</integer>
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
comment|// CHECK:<key>line</key><integer>25</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|// CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;check&apos;</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Returning from&apos;check&apos;</string>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>52</integer>
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
comment|// CHECK:<key>line</key><integer>55</integer>
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
comment|// CHECK:<key>line</key><integer>55</integer>
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
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:<key>message</key>
end_comment

begin_comment
comment|// CHECK:<string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
end_comment

begin_comment
comment|// CHECK:</dict>
end_comment

begin_comment
comment|// CHECK:</array>
end_comment

begin_comment
comment|// CHECK:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;a&apos;)</string>
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
comment|// CHECK:<key>issue_context</key><string>testStoreCheck</string>
end_comment

begin_comment
comment|// CHECK:<key>issue_hash</key><integer>6</integer>
end_comment

begin_comment
comment|// CHECK:<key>location</key>
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

