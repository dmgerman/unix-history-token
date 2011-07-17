begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %s -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_decl_stmt
specifier|extern
name|float
name|y
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|ip
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous}}
end_comment

begin_decl_stmt
name|int
name|z2
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous}}
end_comment

begin_define
define|#
directive|define
name|MAKE_HAPPY
parameter_list|(
name|X
parameter_list|)
value|X##Happy
end_define

begin_function_decl
name|int
name|MAKE_HAPPY
parameter_list|(
name|Very
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_define
define|#
directive|define
name|A_MACRO_IN_THE_PCH
value|492
end_define

begin_define
define|#
directive|define
name|FUNCLIKE_MACRO
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|X ## Y
end_define

begin_define
define|#
directive|define
name|PASTE2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x##y
end_define

begin_define
define|#
directive|define
name|PASTE1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|PASTE2(x,y)
end_define

begin_define
define|#
directive|define
name|UNIQUE
parameter_list|(
name|x
parameter_list|)
value|PASTE1(x,__COUNTER__)
end_define

begin_function_decl
name|int
name|UNIQUE
parameter_list|(
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a0
end_comment

begin_function_decl
name|int
name|UNIQUE
parameter_list|(
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a1
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
modifier|*
name|ip2
init|=
operator|&
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
modifier|*
name|fp
init|=
operator|&
name|ip
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{incompatible pointer types}}
end_comment

begin_decl_stmt
name|double
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_decl_stmt
name|int
name|z2
init|=
literal|18
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_decl_stmt
name|double
name|VeryHappy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_decl_stmt
name|int
name|Q
init|=
name|A_MACRO_IN_THE_PCH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|R
init|=
name|FUNCLIKE_MACRO
argument_list|(
name|A_MACRO_
argument_list|,
name|IN_THE_PCH
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|UNIQUE
parameter_list|(
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a2
end_comment

begin_decl_stmt
name|int
modifier|*
name|Arr
index|[]
init|=
block|{
operator|&
name|a0
block|,
operator|&
name|a1
block|,
operator|&
name|a2
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

