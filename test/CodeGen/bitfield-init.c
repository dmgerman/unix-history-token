begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|i
range|:
literal|1
decl_stmt|;
block|}
name|c
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|c
name|d
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR2310
end_comment

begin_struct
struct|struct
name|Token
block|{
name|unsigned
name|n
range|:
literal|31
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|sqlite3CodeSubselect
parameter_list|()
block|{
name|struct
name|Token
name|one
init|=
block|{
literal|1
block|}
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
union|union
name|T0
block|{
name|char
name|field0
range|:
literal|2
decl_stmt|;
block|}
name|T0
typedef|;
end_typedef

begin_decl_stmt
name|T0
name|T0_values
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

