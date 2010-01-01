begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=x86_64-apple-darwin9
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|uint64_t
name|numer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|denom
decl_stmt|;
end_decl_stmt

begin_function
name|uint64_t
name|f
parameter_list|(
name|uint64_t
name|val
parameter_list|)
block|{
name|__uint128_t
name|tmp
decl_stmt|;
name|tmp
operator|=
name|val
expr_stmt|;
name|tmp
operator|*=
name|numer
expr_stmt|;
name|tmp
operator|/=
name|denom
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

end_unit

