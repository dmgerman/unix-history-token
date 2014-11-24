begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -Wno-unused-value -Wmicrosoft -verify -fms-compatibility
end_comment

begin_enum_decl
enum_decl|enum
name|ENUM1
enum_decl|;
end_enum_decl

begin_comment
comment|// expected-warning {{forward references to 'enum' types are a Microsoft extension}}
end_comment

begin_decl_stmt
name|enum
name|ENUM1
name|var1
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|ENUM1
modifier|*
name|var2
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|ENUM2
block|{
name|ENUM2_a
init|=
operator|(
expr|enum
name|ENUM2
operator|)
literal|4
block|,
name|ENUM2_b
init|=
literal|0x9FFFFFFF
block|,
comment|// expected-warning {{enumerator value is not representable in the underlying type 'int'}}
name|ENUM2_c
init|=
literal|0x100000000
comment|// expected-warning {{enumerator value is not representable in the underlying type 'int'}}
block|}
enum|;
end_enum

begin_macro
name|__declspec
argument_list|(
argument|noreturn
argument_list|)
end_macro

begin_function
name|void
name|f6
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
comment|// expected-warning {{function 'f6' declared 'noreturn' should not return}}
block|}
end_function

begin_macro
name|__declspec
argument_list|(
argument|align(
literal|32768
argument|)
argument_list|)
end_macro

begin_struct
struct|struct
name|S1
block|{
name|int
name|a
decl_stmt|;
block|}
name|s
struct|;
end_struct

begin_comment
comment|/* expected-error {{requested alignment must be 8192 bytes or smaller}} */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|aligned
argument_list|)
name|S2
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{__declspec attribute 'aligned' is not supported}} */
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|appdomain
argument_list|)
name|S3
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-warning {{__declspec attribute 'appdomain' is not supported}} */
end_comment

begin_macro
name|__declspec
argument_list|(
argument|__noreturn__
argument_list|)
end_macro

begin_function_decl
name|void
name|f7
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* expected-warning {{__declspec attribute '__noreturn__' is not supported}} */
end_comment

end_unit

