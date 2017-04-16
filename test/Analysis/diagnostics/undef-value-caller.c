begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=plist -analyzer-config path-diagnostics-alternate=false -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file %t %s
end_comment

begin_include
include|#
directive|include
file|"undef-value-callee.h"
end_include

begin_comment
comment|// This code used to cause a crash since we were not adding fileID of the header to the plist diagnostic.
end_comment

begin_function
name|int
name|test_calling_unimportant_callee
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|callee
argument_list|()
expr_stmt|;
return|return
name|x
return|;
comment|// expected-warning {{Undefined or garbage value returned to caller}}
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
comment|// CHECK-NEXT:<key>line</key><integer>9</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>9</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>9</integer>
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
comment|// CHECK-NEXT:<string>&apos;x&apos; declared without an initial value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>&apos;x&apos; declared without an initial value</string>
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
comment|// CHECK-NEXT:<key>line</key><integer>9</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>9</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
end_comment

begin_comment
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
comment|// CHECK-NEXT:<key>line</key><integer>10</integer>
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
comment|// CHECK-NEXT:<string>Undefined or garbage value returned to caller</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>message</key>
end_comment

begin_comment
comment|// CHECK-NEXT:<string>Undefined or garbage value returned to caller</string>
end_comment

begin_comment
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>description</key><string>Undefined or garbage value returned to caller</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>type</key><string>Garbage return value</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>check_name</key><string>core.uninitialized.UndefReturn</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<!-- This hash is experimental and going to change! -->
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_hash_content_of_line_in_context</key><string>1ef750c5562c09a467ea54ea4b4de771</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|// CHECK-NEXT:<key>issue_context</key><string>test_calling_unimportant_callee</string>
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
comment|// CHECK-NEXT:</dict>
end_comment

begin_comment
comment|// CHECK-NEXT:</array>
end_comment

end_unit

