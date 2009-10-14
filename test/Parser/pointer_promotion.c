begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|test
parameter_list|()
block|{
name|void
modifier|*
name|vp
decl_stmt|;
name|int
modifier|*
name|ip
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|struct
name|foo
modifier|*
name|fp
decl_stmt|;
name|struct
name|bar
modifier|*
name|bp
decl_stmt|;
name|short
name|sint
init|=
literal|7
decl_stmt|;
if|if
condition|(
name|ip
operator|<
name|cp
condition|)
block|{}
comment|// expected-warning {{comparison of distinct pointer types ('int *' and 'char *')}}
if|if
condition|(
name|cp
operator|<
name|fp
condition|)
block|{}
comment|// expected-warning {{comparison of distinct pointer types ('char *' and 'struct foo *')}}
if|if
condition|(
name|fp
operator|<
name|bp
condition|)
block|{}
comment|// expected-warning {{comparison of distinct pointer types ('struct foo *' and 'struct bar *')}}
if|if
condition|(
name|ip
operator|<
literal|7
condition|)
block|{}
comment|// expected-warning {{comparison between pointer and integer ('int *' and 'int')}}
if|if
condition|(
name|sint
operator|<
name|ip
condition|)
block|{}
comment|// expected-warning {{comparison between pointer and integer ('int' and 'int *')}}
if|if
condition|(
name|ip
operator|==
name|cp
condition|)
block|{}
comment|// expected-warning {{comparison of distinct pointer types ('int *' and 'char *')}}
block|}
end_function

end_unit

