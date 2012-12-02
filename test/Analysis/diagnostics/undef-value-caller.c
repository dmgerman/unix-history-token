begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-output=plist -o %t %s
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
comment|//CHECK:<key>kind</key><string>event</string>
end_comment

begin_comment
comment|//CHECK:<key>location</key>
end_comment

begin_comment
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>9</integer>
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
comment|//CHECK:<key>line</key><integer>9</integer>
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
comment|//CHECK:<key>line</key><integer>9</integer>
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
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Variable&apos;x&apos; declared without an initial value</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Variable&apos;x&apos; declared without an initial value</string>
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
comment|//CHECK:<key>line</key><integer>9</integer>
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
comment|//CHECK:<key>line</key><integer>9</integer>
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
comment|//CHECK:<key>line</key><integer>10</integer>
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
comment|//CHECK:<key>line</key><integer>10</integer>
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
comment|//CHECK:<key>line</key><integer>10</integer>
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
comment|//CHECK:<key>line</key><integer>10</integer>
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
comment|//CHECK:<key>end</key>
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
comment|//CHECK:<key>line</key><integer>11</integer>
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
comment|//CHECK:<key>line</key><integer>11</integer>
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
comment|//CHECK:<key>line</key><integer>11</integer>
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
comment|//CHECK:<dict>
end_comment

begin_comment
comment|//CHECK:<key>line</key><integer>11</integer>
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
comment|//CHECK:<key>depth</key><integer>0</integer>
end_comment

begin_comment
comment|//CHECK:<key>extended_message</key>
end_comment

begin_comment
comment|//CHECK:<string>Undefined or garbage value returned to caller</string>
end_comment

begin_comment
comment|//CHECK:<key>message</key>
end_comment

begin_comment
comment|//CHECK:<string>Undefined or garbage value returned to caller</string>
end_comment

begin_comment
comment|//CHECK:</dict>
end_comment

begin_comment
comment|//CHECK:</array>
end_comment

begin_comment
comment|//CHECK:<key>description</key><string>Undefined or garbage value returned to caller</string>
end_comment

begin_comment
comment|//CHECK:<key>category</key><string>Logic error</string>
end_comment

begin_comment
comment|//CHECK:<key>type</key><string>Garbage return value</string>
end_comment

begin_comment
comment|//CHECK:<key>issue_context_kind</key><string>function</string>
end_comment

begin_comment
comment|//CHECK:<key>issue_context</key><string>test_calling_unimportant_callee</string>
end_comment

begin_comment
comment|//CHECK:<key>issue_hash</key><integer>3</integer>
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
comment|//CHECK:<key>col</key><integer>3</integer>
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

