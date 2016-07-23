begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -ferror-limit 100 %s
end_comment

begin_decl_stmt
name|int
name|temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 6 {{'temp' declared here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
end_pragma

begin_comment
comment|// expected-error {{expected '(' after 'declare reduction'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|{
end_pragma

begin_comment
comment|// expected-error {{expected '(' after 'declare reduction'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
end_pragma

begin_comment
comment|// expected-error {{expected identifier or one of the following operators: '+', '-', '*', '&', '|', '^', '&&', or '||'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|#
end_pragma

begin_comment
comment|// expected-error {{expected identifier or one of the following operators: '+', '-', '*', '&', '|', '^', '&&', or '||'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|/
end_pragma

begin_comment
comment|// expected-error {{expected identifier or one of the following operators: '+', '-', '*', '&', '|', '^', '&&', or '||'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|+
end_pragma

begin_comment
comment|// expected-error {{expected ':'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|for
end_pragma

begin_comment
comment|// expected-error {{expected identifier or one of the following operators: '+', '-', '*', '&', '|', '^', '&&', or '||'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|if
name|:
end_pragma

begin_comment
comment|// expected-error {{expected identifier or one of the following operators: '+', '-', '*', '&', '|', '^', '&&', or '||'}} expected-error {{expected a type}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|oper
name|:
end_pragma

begin_comment
comment|// expected-error {{expected a type}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|oper
name|;
end_pragma

begin_comment
comment|// expected-error {{expected ':'}} expected-error {{expected a type}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|int
end_pragma

begin_comment
comment|// expected-error {{expected ':'}} expected-error {{expected expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|+
name|:
name|const
name|int
name|:
end_pragma

begin_comment
comment|// expected-error {{reduction type cannot be qualified with 'const', 'volatile' or 'restrict'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|-
name|:
name|volatile
name|int
name|:
end_pragma

begin_comment
comment|// expected-error {{reduction type cannot be qualified with 'const', 'volatile' or 'restrict'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|*
name|:
name|int
name|;
end_pragma

begin_comment
comment|// expected-error {{expected ','}} expected-error {{expected a type}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|&
name|:
name|double
name|char
name|:
end_pragma

begin_comment
comment|// expected-error {{cannot combine with previous 'double' declaration specifier}} expected-error {{expected expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|^
name|:
name|double
name|,
name|char
name|,
name|:
end_pragma

begin_comment
comment|// expected-error {{expected a type}} expected-error {{expected expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|&&
name|:
name|int
name|,
name|S
name|:
end_pragma

begin_comment
comment|// expected-error {{unknown type name 'S'}} expected-error {{expected expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|||
name|:
name|int
name|,
name|double
name|:
name|temp
name|+=
name|omp_in
name|)
end_pragma

begin_comment
comment|// expected-error 2 {{only 'omp_in' or 'omp_out' variables are allowed in combiner expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name||
name|:
name|char
name|,
name|float
name|:
name|omp_out
name|+=
name|temp
name|)
end_pragma

begin_comment
comment|// expected-error 2 {{only 'omp_in' or 'omp_out' variables are allowed in combiner expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|{
end_pragma

begin_comment
comment|// expected-error {{expected 'initializer'}} expected-warning {{extra tokens at the end of '#pragma omp declare reduction' are ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|unsigned
name|:
name|omp_out
name|+=
name|temp
name|)
name|)
end_pragma

begin_comment
comment|// expected-error {{expected 'initializer'}} expected-warning {{extra tokens at the end of '#pragma omp declare reduction' are ignored}} expected-error {{only 'omp_in' or 'omp_out' variables are allowed in combiner expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|long
name|(
name|void
name|)
name|:
name|omp_out
name|+=
name|omp_in
name|)
end_pragma

begin_comment
comment|// expected-error {{reduction type cannot be a function type}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|long
name|[
name|3
name|]
name|:
name|omp_out
name|+=
name|omp_in
name|)
end_pragma

begin_comment
comment|// expected-error {{reduction type cannot be an array type}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun23
name|:
name|long
name|,
name|int
name|,
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
end_pragma

begin_comment
comment|// expected-error {{redefinition of user-defined reduction for type 'long'}} expected-note {{previous definition is here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun222
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun1
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
end_pragma

begin_comment
comment|// expected-error {{expected '(' after 'initializer'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun2
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|{
end_pragma

begin_comment
comment|// expected-error {{expected '(' after 'initializer'}} expected-error {{expected expression}} expected-warning {{extra tokens at the end of '#pragma omp declare reduction' are ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun3
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|[
end_pragma

begin_comment
comment|// expected-error {{expected '(' after 'initializer'}} expected-error {{expected expression}} expected-warning {{extra tokens at the end of '#pragma omp declare reduction' are ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun4
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|)
end_pragma

begin_comment
comment|// expected-error {{expected expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun5
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|temp
name|)
end_pragma

begin_comment
comment|// expected-error {{only 'omp_priv' or 'omp_orig' variables are allowed in initializer expression}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun6
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|omp_orig
end_pragma

begin_comment
comment|// expected-error {{expected ')'}} expected-note {{to match this '('}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun7
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|omp_priv
name|12
name|)
end_pragma

begin_comment
comment|// expected-error {{expected ')'}} expected-note {{to match this '('}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun8
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|omp_priv
name|=
name|23
name|)
end_pragma

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun8
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|omp_priv
name|=
name|23
name|)
name|)
end_pragma

begin_comment
comment|// expected-warning {{extra tokens at the end of '#pragma omp declare reduction' are ignored}} expected-error {{redefinition of user-defined reduction for type 'long'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun9
name|:
name|long
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|omp_priv
name|=
name|)
end_pragma

begin_comment
comment|// expected-error {{expected expression}}
end_comment

begin_function
name|int
name|fun
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|red
name|:
name|int
name|:
name|omp_out
name|++
name|)
block|{
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|red
name|:
name|int
name|:
name|omp_out
name|++
name|)
comment|// expected-note {{previous definition is here}}
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|red
name|:
name|int
name|:
name|omp_out
name|++
name|)
comment|// expected-error {{redefinition of user-defined reduction for type 'int'}}
block|{
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|red
name|:
name|int
name|:
name|omp_out
name|++
name|)
block|}
block|}
return|return
name|arg
return|;
block|}
end_function

end_unit

