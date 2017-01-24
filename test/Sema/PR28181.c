begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|spinlock_t
block|{
name|int
name|lock
decl_stmt|;
block|}
name|audit_skb_queue
struct|;
end_struct

begin_function
name|void
name|fn1
parameter_list|()
block|{
name|audit_skb_queue
operator|=
operator|(
name|lock
operator|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'lock'; did you mean 'long'?}}
block|}
end_function

begin_comment
comment|// expected-error@-1 {{assigning to 'struct spinlock_t' from incompatible type '<overloaded function type>'}}
end_comment

begin_function
name|void
name|fn2
parameter_list|()
block|{
name|audit_skb_queue
operator|+
operator|(
name|lock
operator|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'lock'; did you mean 'long'?}}
block|}
end_function

begin_comment
comment|// expected-error@-1 {{reference to overloaded function could not be resolved; did you mean to call it?}}
end_comment

end_unit

