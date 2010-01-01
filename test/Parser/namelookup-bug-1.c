begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|Object
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|Object
modifier|*
name|pp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Object
name|staticObject1
decl_stmt|;
end_decl_stmt

end_unit

