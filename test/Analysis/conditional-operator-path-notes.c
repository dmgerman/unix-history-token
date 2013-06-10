begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --analyze %s -Xanalyzer -analyzer-output=text -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang --analyze %s -o %t
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_function
name|void
name|testCondOp
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|x
init|=
name|p
condition|?
name|p
else|:
name|p
decl_stmt|;
comment|// expected-note@-1 {{Assuming 'p' is null}}
comment|// expected-note@-2 {{'?' condition is false}}
comment|// expected-note@-3 {{'x' initialized to a null pointer value}}
operator|*
name|x
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'x')}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'x')}}
block|}
end_function

begin_function
name|void
name|testCondProblem
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
return|return;
comment|// expected-note@-1 {{Assuming 'p' is null}}
comment|// expected-note@-2 {{Taking false branch}}
name|int
name|x
init|=
operator|*
name|p
condition|?
literal|0
else|:
literal|1
decl_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'p')}}
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|testLHSProblem
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|x
init|=
operator|!
name|p
condition|?
operator|*
name|p
else|:
literal|1
decl_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
comment|// expected-note@-1 {{Assuming 'p' is null}}
comment|// expected-note@-2 {{'?' condition is true}}
comment|// expected-note@-3 {{Dereference of null pointer (loaded from variable 'p')}}
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|testRHSProblem
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|x
init|=
name|p
condition|?
literal|1
else|:
operator|*
name|p
decl_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
comment|// expected-note@-1 {{Assuming 'p' is null}}
comment|// expected-note@-2 {{'?' condition is false}}
comment|// expected-note@-3 {{Dereference of null pointer (loaded from variable 'p')}}
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|testBinaryCondOp
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
modifier|*
name|x
init|=
name|p
condition|?
else|:
name|p
decl_stmt|;
comment|// expected-note@-1 {{'?' condition is false}}
comment|// expected-note@-2 {{'x' initialized to a null pointer value}}
operator|*
name|x
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'x')}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'x')}}
block|}
end_function

begin_function
name|void
name|testBinaryLHSProblem
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
return|return;
comment|// expected-note@-1 {{Assuming 'p' is null}}
comment|// expected-note@-2 {{Taking false branch}}
name|int
name|x
init|=
operator|*
name|p
condition|?
else|:
literal|1
decl_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
comment|// expected-note@-1 {{Dereference of null pointer (loaded from variable 'p')}}
operator|(
name|void
operator|)
name|x
expr_stmt|;
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>6</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>extended_message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;x&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;x&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;x&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;x&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;x&apos;)</string>
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
comment|// CHECK-NEXT:<key>issue_context</key><string>testCondOp</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>5</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>15</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>19</integer>
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
comment|// CHECK-NEXT:<key>issue_context</key><string>testCondProblem</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>5</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>16</integer>
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
comment|// CHECK-NEXT:<key>col</key><integer>17</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
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
comment|// CHECK-NEXT:<key>issue_context</key><string>testLHSProblem</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>25</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>location</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>depth</key><integer>0</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>issue_context</key><string>testRHSProblem</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>33</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<dict>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<string>&apos;x&apos; initialized to a null pointer value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;x&apos; initialized to a null pointer value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>41</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>44</integer>
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
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;x&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Dereference of null pointer (loaded from variable&apos;x&apos;)</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Dereference of null pointer (loaded from variable&apos;x&apos;)</string>
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
comment|// CHECK-NEXT:<key>issue_context</key><string>testBinaryCondOp</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>4</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>49</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>53</integer>
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
comment|// CHECK-NEXT:<key>issue_context</key><string>testBinaryLHSProblem</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash</key><string>5</string>
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
comment|// CHECK-NEXT:<key>col</key><integer>11</integer>
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

