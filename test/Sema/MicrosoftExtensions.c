begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-windows %s -fsyntax-only -Wno-unused-value -Wmicrosoft -verify -fms-extensions
end_comment

begin_struct
struct|struct
name|A
block|{
name|int
name|a
index|[]
decl_stmt|;
comment|/* expected-warning {{flexible array member 'a' in otherwise empty struct is a Microsoft extension}} */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|C
block|{
name|int
name|l
decl_stmt|;
union|union
block|{
name|int
name|c1
index|[]
decl_stmt|;
comment|/* expected-warning {{flexible array member 'c1' in a union is a Microsoft extension}}  */
name|char
name|c2
index|[]
decl_stmt|;
comment|/* expected-warning {{flexible array member 'c2' in a union is a Microsoft extension}} */
block|}
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|D
block|{
name|int
name|l
decl_stmt|;
name|int
name|D
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|uuid(
literal|"00000000-0000-0000-C000-000000000046"
argument|)
argument_list|)
name|IUnknown
block|{}
struct|;
end_struct

begin_comment
comment|/* expected-error {{'uuid' attribute is not supported in C}} */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|notnested
block|{
name|long
name|bad1
decl_stmt|;
name|long
name|bad2
decl_stmt|;
block|}
name|NOTNESTED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nested1
block|{
name|long
name|a
decl_stmt|;
name|struct
name|notnested
name|var1
decl_stmt|;
name|NOTNESTED
name|var2
decl_stmt|;
block|}
name|NESTED1
typedef|;
end_typedef

begin_struct
struct|struct
name|nested2
block|{
name|long
name|b
decl_stmt|;
name|NESTED1
expr_stmt|;
comment|// expected-warning {{anonymous structs are a Microsoft extension}}
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test
block|{
name|int
name|c
decl_stmt|;
struct_decl|struct
name|nested2
struct_decl|;
comment|// expected-warning {{anonymous structs are a Microsoft extension}}
block|}
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
name|struct
name|test
name|var
decl_stmt|;
name|var
operator|.
name|a
expr_stmt|;
name|var
operator|.
name|b
expr_stmt|;
name|var
operator|.
name|c
expr_stmt|;
name|var
operator|.
name|bad1
expr_stmt|;
comment|// expected-error {{no member named 'bad1' in 'struct test'}}
name|var
operator|.
name|bad2
expr_stmt|;
comment|// expected-error {{no member named 'bad2' in 'struct test'}}
block|}
end_function

begin_comment
comment|// Enumeration types with a fixed underlying type.
end_comment

begin_decl_stmt
specifier|const
name|int
name|seventeen
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|Int
typedef|;
end_typedef

begin_struct
struct|struct
name|X0
block|{
enum|enum
name|E1
enum|:
name|Int
block|{
name|SomeOtherValue
block|}
name|field
enum|;
comment|// expected-warning{{enumeration types with a fixed underlying type are a Microsoft extension}}
enum_decl|enum
name|E1
enum_decl|:
name|seventeen
enum_decl|;
block|}
struct|;
end_struct

begin_enum_decl
enum_decl|enum :
name|long
name|long
block|{
comment|// expected-warning{{enumeration types with a fixed underlying type are a Microsoft extension}}
name|SomeValue
operator|=
literal|0x100000000
block|}
enum_decl|;
end_enum_decl

begin_function
name|void
name|pointer_to_integral_type_conv
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|)
block|{
name|char
name|ch
init|=
operator|(
name|char
operator|)
name|ptr
decl_stmt|;
name|short
name|sh
init|=
operator|(
name|short
operator|)
name|ptr
decl_stmt|;
name|ch
operator|=
operator|(
name|char
operator|)
name|ptr
expr_stmt|;
name|sh
operator|=
operator|(
name|short
operator|)
name|ptr
expr_stmt|;
comment|// This is valid ISO C.
name|_Bool
name|b
init|=
operator|(
name|_Bool
operator|)
name|ptr
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|UNKNOWN
name|u
decl_stmt|;
comment|// expected-error {{unknown type name 'UNKNOWN'}}
block|}
name|AA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|AA
expr_stmt|;
comment|// expected-warning {{anonymous structs are a Microsoft extension}}
block|}
name|BB
typedef|;
end_typedef

begin_expr_stmt
name|__declspec
argument_list|(
name|deprecated
argument_list|(
literal|"This is deprecated"
argument_list|)
argument_list|)
expr|enum
name|DE1
block|{
name|one
block|,
name|two
block|}
name|e1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note {{'e1' has been explicitly marked deprecated here}}
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|deprecated
argument_list|)
name|DS1
block|{
name|int
name|i
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-note {{'DS1' has been explicitly marked deprecated here}}
end_comment

begin_define
define|#
directive|define
name|MY_TEXT
value|"This is also deprecated"
end_define

begin_macro
name|__declspec
argument_list|(
argument|deprecated(MY_TEXT)
argument_list|)
end_macro

begin_function
name|void
name|Dfunc1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note {{'Dfunc1' has been explicitly marked deprecated here}}
end_comment

begin_struct
struct|struct
name|__declspec
argument_list|(
argument|deprecated(
literal|123
argument|)
argument_list|)
name|DS2
block|{}
struct|;
end_struct

begin_comment
comment|// expected-error {{'deprecated' attribute requires a string}}
end_comment

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|e1
operator|=
name|one
expr_stmt|;
comment|// expected-warning {{'e1' is deprecated: This is deprecated}}
name|struct
name|DS1
name|s
init|=
block|{
literal|0
block|}
decl_stmt|;
comment|// expected-warning {{'DS1' is deprecated}}
name|Dfunc1
argument_list|()
expr_stmt|;
comment|// expected-warning {{'Dfunc1' is deprecated: This is also deprecated}}
name|enum
name|DE1
name|no
decl_stmt|;
comment|// no warning because E1 is not deprecated
block|}
end_function

begin_decl_stmt
name|int
name|__sptr
name|wrong1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__sptr' attribute only applies to pointer arguments}}
end_comment

begin_comment
comment|// The modifier must follow the asterisk
end_comment

begin_decl_stmt
name|int
name|__sptr
modifier|*
name|wrong_psp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__sptr' attribute only applies to pointer arguments}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|__sptr
name|__uptr
name|wrong2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__sptr' and '__uptr' attributes are not compatible}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|__sptr
name|__sptr
name|wrong3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{attribute '__sptr' is already applied}}
end_comment

begin_comment
comment|// It is illegal to overload based on the type attribute.
end_comment

begin_function
name|void
name|ptr_func
parameter_list|(
name|int
modifier|*
name|__ptr32
name|i
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_function
name|void
name|ptr_func
parameter_list|(
name|int
modifier|*
name|__ptr64
name|i
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error {{redefinition of 'ptr_func'}}
end_comment

begin_comment
comment|// It is also illegal to overload based on the pointer type attribute.
end_comment

begin_function
name|void
name|ptr_func2
parameter_list|(
name|int
modifier|*
name|__sptr
name|__ptr32
name|i
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_function
name|void
name|ptr_func2
parameter_list|(
name|int
modifier|*
name|__uptr
name|__ptr32
name|i
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error {{redefinition of 'ptr_func2'}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|__sptr
name|__ptr32
name|__sptr
name|wrong4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{attribute '__sptr' is already applied}}
end_comment

begin_decl_stmt
name|__ptr32
name|int
modifier|*
name|wrong5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__ptr32' attribute only applies to pointer arguments}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|wrong6
name|__ptr32
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected ';' after top level declarator}} expected-warning {{declaration does not declare anything}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|__ptr32
name|__ptr64
name|wrong7
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__ptr32' and '__ptr64' attributes are not compatible}}
end_comment

begin_decl_stmt
name|int
modifier|*
name|__ptr32
name|__ptr32
name|wrong8
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{attribute '__ptr32' is already applied}}
end_comment

begin_macro
name|int
end_macro

begin_expr_stmt
operator|*
operator|(
name|__ptr32
name|__sptr
name|wrong9
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'__sptr' attribute only applies to pointer arguments}} // expected-error {{'__ptr32' attribute only applies to pointer arguments}}
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|T
typedef|;
end_typedef

begin_decl_stmt
name|T
name|__ptr32
name|wrong10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'__ptr32' attribute only applies to pointer arguments}}
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|my_va_list
typedef|;
end_typedef

begin_function_decl
name|void
name|__va_start
parameter_list|(
name|my_va_list
modifier|*
name|ap
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{passing argument to parameter 'ap' here}}
end_comment

begin_function_decl
name|void
name|vmyprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
name|my_va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|myprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|f
parameter_list|,
modifier|...
parameter_list|)
block|{
name|my_va_list
name|ap
decl_stmt|;
if|if
condition|(
literal|1
condition|)
block|{
name|__va_start
argument_list|(
operator|&
name|ap
argument_list|,
name|f
argument_list|)
expr_stmt|;
name|vmyprintf
argument_list|(
name|f
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|ap
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|__va_start
argument_list|(
name|ap
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer types passing 'my_va_list'}}
block|}
block|}
end_function

end_unit

