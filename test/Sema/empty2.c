begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -pedantic
end_comment

begin_struct
struct|struct
name|emp_1
block|{
comment|// expected-warning {{empty struct is a GNU extension}}
block|}
struct|;
end_struct

begin_union
union|union
name|emp_2
block|{
comment|// expected-warning {{empty union is a GNU extension}}
block|}
union|;
end_union

begin_struct
struct|struct
name|emp_3
block|{
comment|// expected-warning {{struct without named members is a GNU extension}}
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|emp_4
block|{
comment|// expected-warning {{union without named members is a GNU extension}}
name|int
label|:
literal|0
expr_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|emp_5
block|{
comment|// expected-warning {{struct without named members is a GNU extension}}
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|emp_6
block|{
comment|// expected-warning {{union without named members is a GNU extension}}
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|nonamed_1
block|{
comment|// expected-warning {{struct without named members is a GNU extension}}
name|int
label|:
literal|4
expr_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|nonamed_2
block|{
comment|// expected-warning {{union without named members is a GNU extension}}
name|int
label|:
literal|4
expr_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|nonamed_3
block|{
comment|// expected-warning {{struct without named members is a GNU extension}}
name|int
label|:
literal|4
expr_stmt|;
name|unsigned
name|int
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|nonamed_4
block|{
comment|// expected-warning {{union without named members is a GNU extension}}
name|int
label|:
literal|4
expr_stmt|;
name|unsigned
name|int
range|:
literal|4
decl_stmt|;
block|}
union|;
end_union

end_unit

