begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 %s -verify
end_comment

begin_typedef
typedef|typedef
name|int
name|type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|type
name|type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|type
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|(
name|int
name|N
parameter_list|)
block|{
typedef|typedef
name|int
name|type2
typedef|;
typedef|typedef
name|type
name|type2
typedef|;
typedef|typedef
name|int
name|type2
typedef|;
typedef|typedef
name|int
name|vla
index|[
name|N
index|]
typedef|;
comment|// expected-note{{previous definition is here}}
typedef|typedef
name|int
name|vla
index|[
name|N
index|]
typedef|;
comment|// expected-error{{redefinition of typedef for variably-modified type 'int [N]'}}
typedef|typedef
name|int
name|vla2
index|[
name|N
index|]
typedef|;
typedef|typedef
name|vla2
name|vla3
typedef|;
comment|// expected-note{{previous definition is here}}
typedef|typedef
name|vla2
name|vla3
typedef|;
comment|// expected-error{{redefinition of typedef for variably-modified type 'vla2' (aka 'int [N]')}}
block|}
end_function

end_unit

