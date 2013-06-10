begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -verify %s
end_comment

begin_comment
comment|// rdar://12390371
end_comment

begin_comment
comment|/** @return s Test*/
end_comment

begin_function_decl
name|struct
name|s
modifier|*
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|s
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|s1
struct_decl|;
end_struct_decl

begin_comment
comment|/** @return s1 Test 1*/
end_comment

begin_function_decl
name|struct
name|s1
modifier|*
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|s2
struct_decl|;
end_struct_decl

begin_comment
comment|/** @return s2 Test 2*/
end_comment

begin_function_decl
name|struct
name|s2
modifier|*
name|f2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|s2
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return s3 Test 3 - expected warning here */
end_comment

begin_struct_decl
struct_decl|struct
name|s3
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|s3
modifier|*
name|f3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @return s4 Test 4 */
end_comment

begin_function_decl
name|struct
name|s4
modifier|*
name|f4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|s4
block|{
name|int
name|is
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return s5 Test 5  - expected warning here */
end_comment

begin_struct
struct|struct
name|s5
block|{
name|int
name|is
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|s5
modifier|*
name|f5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return s6 Test 6  - expected warning here */
end_comment

begin_decl_stmt
name|struct
name|s6
modifier|*
name|ps6
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|s6
modifier|*
name|f6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return s7 Test 7  - expected warning here */
end_comment

begin_struct_decl
struct_decl|struct
name|s7
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|s7
modifier|*
name|f7
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|s8
block|{
name|int
name|is8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** @return s8 Test 8 */
end_comment

begin_function_decl
name|struct
name|s4
modifier|*
name|f8
parameter_list|(
name|struct
name|s8
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @return e Test*/
end_comment

begin_function_decl
name|enum
name|e
modifier|*
name|g
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum_decl
enum_decl|enum
name|e
enum_decl|;
end_enum_decl

begin_enum_decl
enum_decl|enum
name|e1
enum_decl|;
end_enum_decl

begin_comment
comment|/** @return e1 Test 1*/
end_comment

begin_function_decl
name|enum
name|e1
modifier|*
name|g1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum_decl
enum_decl|enum
name|e2
enum_decl|;
end_enum_decl

begin_comment
comment|/** @return e2 Test 2*/
end_comment

begin_function_decl
name|enum
name|e2
modifier|*
name|g2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum_decl
enum_decl|enum
name|e2
enum_decl|;
end_enum_decl

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return e3 Test 3 - expected warning here */
end_comment

begin_enum_decl
enum_decl|enum
name|e3
enum_decl|;
end_enum_decl

begin_function_decl
name|enum
name|e3
modifier|*
name|g3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @return e4 Test 4 */
end_comment

begin_function_decl
name|enum
name|e4
modifier|*
name|g4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|e4
block|{
name|one
block|}
enum|;
end_enum

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return e5 Test 5  - expected warning here */
end_comment

begin_enum
enum|enum
name|e5
block|{
name|two
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|e5
modifier|*
name|g5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return e6 Test 6  - expected warning here */
end_comment

begin_decl_stmt
name|enum
name|e6
modifier|*
name|pe6
decl_stmt|;
end_decl_stmt

begin_function_decl
name|enum
name|e6
modifier|*
name|g6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning@+1 {{'@return' command used in a comment that is not attached to a function or method declaration}}
end_comment

begin_comment
comment|/** @return e7 Test 7  - expected warning here */
end_comment

begin_enum_decl
enum_decl|enum
name|e7
enum_decl|;
end_enum_decl

begin_function_decl
name|enum
name|e7
modifier|*
name|g7
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|e8
block|{
name|three
block|}
enum|;
end_enum

begin_comment
comment|/** @return e8 Test 8 */
end_comment

begin_function_decl
name|enum
name|e4
modifier|*
name|g8
parameter_list|(
name|enum
name|e8
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

end_unit

