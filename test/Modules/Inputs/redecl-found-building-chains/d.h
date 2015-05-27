begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a.h"
end_include

begin_comment
comment|// ensure that our canonical decl is not from b
end_comment

begin_struct_decl
struct_decl|struct
name|A
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_struct_decl
struct_decl|struct
name|A
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"c.h"
end_include

begin_comment
comment|// ensure that our type for A doesn't reference the definition in b
end_comment

begin_struct_decl
struct_decl|struct
name|A
struct_decl|;
end_struct_decl

end_unit

