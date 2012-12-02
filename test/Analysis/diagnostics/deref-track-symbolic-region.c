begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-output=plist-multi-file %s -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
modifier|*
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
modifier|*
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|inlined
parameter_list|(
name|struct
name|S
modifier|*
name|s
parameter_list|,
name|int
name|m
parameter_list|)
block|{
if|if
condition|(
name|s
operator|->
name|x
condition|)
comment|//expected-note@-1{{Taking false branch}}
comment|//expected-note@-2{{Assuming pointer value is null}}
name|m
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test
parameter_list|(
name|struct
name|S
name|syz
parameter_list|,
name|int
modifier|*
name|pp
parameter_list|)
block|{
name|int
name|m
init|=
literal|0
decl_stmt|;
name|syz
operator|.
name|x
operator|=
name|foo
argument_list|()
expr_stmt|;
name|inlined
argument_list|(
operator|&
name|syz
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|// expected-note@-1{{Calling 'inlined'}}
comment|// expected-note@-2{{Returning from 'inlined'}}
name|m
operator|+=
operator|*
name|syz
operator|.
name|x
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from field 'x')}}
comment|// expected-note@-1{{Dereference of null pointer (loaded from field 'x')}}
block|}
end_function

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>files</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>diagnostics</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>path</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|//CHECK:<key>edges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>start</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>20</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>5</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>end</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<key>ranges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Calling&apos;inlined&apos;</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Calling&apos;inlined&apos;</string>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Entered call from&apos;test&apos;</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Entered call from&apos;test&apos;</string>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|//CHECK:<key>edges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>start</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>1</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>11</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>end</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|//CHECK:<key>edges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>start</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>4</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>end</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<key>ranges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>7</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>12</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>10</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Assuming pointer value is null</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Assuming pointer value is null</string>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<key>ranges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>18</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>depth</key><integer>1</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Returning from&apos;inlined&apos;</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Returning from&apos;inlined&apos;</string>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|//CHECK:<key>edges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>start</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>22</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>9</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>end</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>control</string>
end_comment

begin_comment
comment|//CHECK:<key>edges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>start</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>3</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>end</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<key>ranges</key>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<array>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>13</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Dereference of null pointer (loaded from field&apos;x&apos;)</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Dereference of null pointer (loaded from field&apos;x&apos;)</string>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>description</key><string>Dereference of null pointer (loaded from field&apos;x&apos;)</string>
end_comment

begin_comment
comment|//CHECK:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|//CHECK:<key>type</key><string>Dereference of null pointer</string>
end_comment

begin_comment
comment|//CHECK:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|//CHECK:<key>issue_context</key><string>test</string>
end_comment

begin_comment
comment|//CHECK:<key>issue_hash</key><integer>6</integer>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>25</integer>
end_comment

begin_comment
comment|//CHECK:<key>col</key><integer>8</integer>
end_comment

begin_comment
comment|//CHECK:<key>file</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</plist>
end_comment

end_unit

