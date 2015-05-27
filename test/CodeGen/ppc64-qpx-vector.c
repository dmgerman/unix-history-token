begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s -check-prefix=ALL -check-prefix=NORMAL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - -target-abi elfv1-qpx %s | FileCheck %s -check-prefix=ALL -check-prefix=QPX
end_comment

begin_typedef
typedef|typedef
name|float
name|v4sf
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|v4df
name|__attribute__
typedef|((
name|vector_size
typedef|(32)));
end_typedef

begin_struct
struct|struct
name|ssf
block|{
name|v4sf
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdf
block|{
name|v4df
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ssf2
block|{
name|v4sf
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdf2
block|{
name|v4df
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|v4sf
name|foo1
parameter_list|(
name|struct
name|ssf
name|a
parameter_list|,
name|v4sf
name|b
parameter_list|,
name|struct
name|ssf2
name|c
parameter_list|)
block|{
return|return
name|a
operator|.
name|v
operator|+
name|b
return|;
block|}
end_function

begin_comment
comment|// ALL-LABEL: define<4 x float> @foo1(<4 x float> inreg %a.coerce,<4 x float> %b, [2 x i128] %c.coerce)
end_comment

begin_comment
comment|// ALL: ret<4 x float>
end_comment

begin_function
name|v4df
name|foo2
parameter_list|(
name|struct
name|sdf
name|a
parameter_list|,
name|v4df
name|b
parameter_list|,
name|struct
name|sdf2
name|c
parameter_list|)
block|{
return|return
name|a
operator|.
name|v
operator|+
name|b
return|;
block|}
end_function

begin_comment
comment|// QPX-LABEL: define<4 x double> @foo2(<4 x double> inreg %a.coerce,<4 x double> %b, [2 x i256] %c.coerce)
end_comment

begin_comment
comment|// QPX: ret<4 x double>
end_comment

begin_comment
comment|// NORMAL-LABEL: define void @foo2(<4 x double>* noalias sret %agg.result, [2 x i128] %a.coerce,<4 x double>*, [4 x i128] %c.coerce)
end_comment

begin_comment
comment|// NORMAL: ret void
end_comment

end_unit

