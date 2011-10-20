begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_comment
comment|// Aggregates of size zero should be dropped from argument list.
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|Tlong
typedef|;
end_typedef

begin_struct
struct|struct
name|S2411
block|{
name|__attribute__
argument_list|(
argument|(aligned)
argument_list|)
name|Tlong
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|S2411
name|a2411
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|checkx2411
parameter_list|(
name|struct
name|S2411
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test2411
parameter_list|(
name|void
parameter_list|)
block|{
name|checkx2411
argument_list|(
name|a2411
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Proper handling of zero sized fields during type conversion.
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|Tal2ullong
name|__attribute__
typedef|((
name|aligned
typedef|(2)));
end_typedef

begin_struct
struct|struct
name|S2525
block|{
name|Tal2ullong
label|:
literal|0
expr_stmt|;
struct|struct
block|{  }
name|e
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|S2525
name|s2525
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|signed
name|char
name|f
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
struct|struct
block|{}
name|h
struct|;
name|char
modifier|*
name|i
index|[
literal|5
index|]
decl_stmt|;
block|}
name|data
struct|;
end_struct

begin_comment
comment|// Taking address of a zero sized field.
end_comment

begin_struct
struct|struct
name|Z
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|int
name|i
decl_stmt|;
name|struct
name|Z
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
modifier|*
name|f
parameter_list|(
name|struct
name|Y
modifier|*
name|y
parameter_list|)
block|{
return|return
operator|&
name|y
operator|->
name|z
return|;
block|}
end_function

end_unit

