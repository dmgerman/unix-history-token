begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source all -comments-xml-schema=%S/../../bindings/xml/comment-xml-schema.rng -target x86_64-apple-darwin10 %s> %t/out
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t/out
end_comment

begin_comment
comment|// Ensure that XML we generate is not invalid.
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=WRONG< %t/out
end_comment

begin_comment
comment|// WRONG-NOT: CommentXMLInvalid
end_comment

begin_comment
comment|// rdar://12378714
end_comment

begin_comment
comment|/**  * \brief Aaa. */
end_comment

begin_function_decl
name|int
name|global_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:<Declaration>int global_function()</Declaration>
end_comment

begin_comment
comment|/**  * \param x1 Aaa. */
end_comment

begin_function_decl
specifier|extern
name|void
name|external_function
parameter_list|(
name|int
name|x1
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:<Declaration>extern void external_function(int x1)</Declaration>
end_comment

begin_comment
comment|/**  * \brief global variable; */
end_comment

begin_decl_stmt
name|int
name|global_variable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:<Declaration>int global_variable</Declaration>
end_comment

begin_comment
comment|/**  * \brief local variable; */
end_comment

begin_decl_stmt
specifier|static
name|int
name|static_variable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:<Declaration>static int static_variable</Declaration>
end_comment

begin_comment
comment|/**  * \brief external variable */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|external_variable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:<Declaration>extern int external_variable</Declaration>
end_comment

begin_function
name|int
name|global_function
parameter_list|()
block|{
comment|/**    * \brief a local variable   */
name|int
name|local
init|=
literal|10
decl_stmt|;
return|return
name|local
return|;
block|}
end_function

begin_comment
comment|// CHECK:<Declaration>int global_function()</Declaration>
end_comment

begin_comment
comment|// CHECK:<Declaration>int local = 10</Declaration>
end_comment

begin_comment
comment|/**  * \brief initialized decl. */
end_comment

begin_decl_stmt
name|int
name|initialized_global
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:<Declaration>int initialized_global = 100</Declaration>
end_comment

begin_comment
comment|/**  * \brief typedef example */
end_comment

begin_typedef
typedef|typedef
name|int
name|INT_T
typedef|;
end_typedef

begin_comment
comment|// CHECK:<Declaration>typedef int INT_T</Declaration>
end_comment

begin_comment
comment|/**  * \brief aggregate type example */
end_comment

begin_struct
struct|struct
name|S
block|{
comment|/**  * \brief iS1; */
name|int
name|iS1
decl_stmt|;
comment|/**  * \brief dS1; */
name|double
name|dS1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK:<Declaration>struct S {}</Declaration>
end_comment

begin_comment
comment|// CHECK:<Declaration>int iS1</Declaration>
end_comment

begin_comment
comment|// CHECK:<Declaration>double dS1</Declaration>
end_comment

begin_comment
comment|/**  * \brief enum e; */
end_comment

begin_enum
enum|enum
name|e
block|{
name|One
block|,
comment|/**  * \brief Two; */
name|Two
block|,
name|Three
block|}
enum|;
end_enum

begin_comment
comment|// CHECK:<Declaration>enum e {}</Declaration>
end_comment

begin_comment
comment|// CHECK:<Declaration>Two</Declaration>
end_comment

begin_comment
comment|/**  *\brief block declaration */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|Block
function_decl|)
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:<Declaration>int (^Block)(int, int)</Declaration>
end_comment

begin_comment
comment|/**  *\brief block declaration */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|^
name|Block1
function_decl|)
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|)
block|{
end_function_decl

begin_return
return|return
name|i
operator|+
name|j
return|;
end_return

begin_comment
unit|};
comment|// CHECK:<Declaration>int (^Block1)(int, int) = ^(int i, int j) {\n}</Declaration>
end_comment

end_unit

