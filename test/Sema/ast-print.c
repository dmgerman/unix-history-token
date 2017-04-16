begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ast-print | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -ast-print | %clang_cc1 -fsyntax-only -
end_comment

begin_typedef
typedef|typedef
name|void
name|func_typedef
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|func_typedef
name|xxx
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|func_t
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|func_t
name|a
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|blah
block|{
struct|struct
block|{
struct|struct
block|{
name|int
name|b
decl_stmt|;
block|}
struct|;
block|}
struct|;
block|}
struct|;
end_struct

begin_function
name|int
name|foo
parameter_list|(
specifier|const
name|struct
name|blah
modifier|*
name|b
parameter_list|)
block|{
comment|// CHECK: return b->b;
return|return
name|b
operator|->
name|b
return|;
block|}
end_function

begin_function
name|int
name|arr
parameter_list|(
name|int
name|a
index|[
specifier|static
literal|3
index|]
parameter_list|)
block|{
comment|// CHECK: int a[static 3]
return|return
name|a
index|[
literal|2
index|]
return|;
block|}
end_function

begin_function
name|int
name|rarr
parameter_list|(
name|int
name|a
index|[
specifier|restrict
specifier|static
literal|3
index|]
parameter_list|)
block|{
comment|// CHECK: int a[restrict static 3]
return|return
name|a
index|[
literal|2
index|]
return|;
block|}
end_function

begin_function
name|int
name|varr
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|a
index|[
specifier|static
name|n
index|]
parameter_list|)
block|{
comment|// CHECK: int a[static n]
return|return
name|a
index|[
literal|2
index|]
return|;
block|}
end_function

begin_function
name|int
name|rvarr
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|a
index|[
specifier|restrict
specifier|static
name|n
index|]
parameter_list|)
block|{
comment|// CHECK: int a[restrict static n]
return|return
name|a
index|[
literal|2
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK: typedef struct {
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|f
decl_stmt|;
block|}
name|T
name|__attribute__
typedef|((
name|__aligned__
typedef|));
end_typedef

begin_comment
comment|// CHECK: struct __attribute__((visibility("default"))) S;
end_comment

begin_decl_stmt
name|struct
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|S
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|pair_t
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: struct pair_t p = {a: 3, .b = 4};
end_comment

begin_decl_stmt
name|struct
name|pair_t
name|p
init|=
block|{
name|a
operator|:
literal|3
block|,
operator|.
name|b
operator|=
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|initializers
parameter_list|()
block|{
comment|// CHECK: int *x = ((void *)0), *y = ((void *)0);
name|int
modifier|*
name|x
init|=
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
decl_stmt|,
modifier|*
name|y
init|=
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
decl_stmt|;
struct|struct
name|Z
block|{}
struct|;
struct|struct
block|{
name|struct
name|Z
name|z
decl_stmt|;
comment|// CHECK: } z = {(struct Z){}};
block|}
name|z
init|=
block|{
operator|(
expr|struct
name|Z
operator|)
block|{}
block|}
struct|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: enum EnumWithAttributes {
end_comment

begin_enum
enum|enum
name|EnumWithAttributes
block|{
comment|// CHECK-NEXT: EnumWithAttributesFoo __attribute__((deprecated(""))),
name|EnumWithAttributesFoo
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
block|,
comment|// CHECK-NEXT: EnumWithAttributesBar __attribute__((unavailable(""))) = 50
name|EnumWithAttributesBar
name|__attribute__
argument_list|(
operator|(
name|unavailable
operator|)
argument_list|)
init|=
literal|50
comment|// CHECK-NEXT: } __attribute__((deprecated("")))
block|}
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
enum|;
end_enum

end_unit

