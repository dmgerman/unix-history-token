begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -fsyntax-only -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang %s -fsyntax-only -fshort-wchar -Xclang -verify -DSHORT_WCHAR
end_comment

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|defined
argument_list|(
name|SHORT_WCHAR
argument_list|)
end_if

begin_define
define|#
directive|define
name|WCHAR_T_TYPE
value|unsigned short
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__AuroraUX__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|WCHAR_T_TYPE
value|long
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Solaris or AuroraUX. */
end_comment

begin_define
define|#
directive|define
name|WCHAR_T_TYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|check_wchar_size
index|[
sizeof|sizeof
argument_list|(
operator|*
literal|L""
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|WCHAR_T_TYPE
name|t1
index|[]
init|=
literal|L"x"
decl_stmt|;
name|wchar_t
name|tab
index|[]
init|=
literal|L"x"
decl_stmt|;
name|WCHAR_T_TYPE
name|t2
index|[]
init|=
literal|"x"
decl_stmt|;
comment|// expected-error {{initializer}}
name|char
name|t3
index|[]
init|=
literal|L"x"
decl_stmt|;
comment|// expected-error {{initializer}}
block|}
end_function

end_unit

