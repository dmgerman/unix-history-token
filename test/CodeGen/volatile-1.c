begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wno-unused-value -emit-llvm< %s -o %t
end_comment

begin_comment
comment|// RUN: grep volatile %t | count 145
end_comment

begin_comment
comment|// RUN: grep memcpy %t | count 4
end_comment

begin_decl_stmt
specifier|volatile
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|ar
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
specifier|_Complex
name|int
name|ci
decl_stmt|;
end_decl_stmt

begin_struct
specifier|volatile
struct|struct
name|S
block|{
ifdef|#
directive|ifdef
name|__cplusplus
name|void
name|operator
init|=
operator|(
specifier|volatile
expr|struct
name|S
operator|&
name|o
operator|)
specifier|volatile
decl_stmt|;
endif|#
directive|endif
name|int
name|i
decl_stmt|;
block|}
name|a
struct|,
name|b
struct|;
end_struct

begin_comment
comment|//void operator =(volatile struct S&o1, volatile struct S&o2) volatile;
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// A use.
name|i
expr_stmt|;
comment|// A use of the real part
call|(
name|float
call|)
argument_list|(
name|ci
argument_list|)
expr_stmt|;
comment|// A use.
operator|(
name|void
operator|)
name|ci
expr_stmt|;
comment|// A use.
operator|(
name|void
operator|)
name|a
expr_stmt|;
comment|// Not a use.
call|(
name|void
call|)
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
comment|// Not a use.
call|(
name|void
call|)
argument_list|(
name|i
operator|=
name|j
argument_list|)
expr_stmt|;
name|ci
operator|+=
name|ci
expr_stmt|;
operator|(
name|ci
operator|+=
name|ci
operator|)
operator|+
name|ci
expr_stmt|;
asm|asm("nop");
operator|(
name|i
operator|+=
name|j
operator|)
operator|+
name|k
expr_stmt|;
asm|asm("nop");
comment|// A use
operator|(
name|i
operator|+=
name|j
operator|)
operator|+
literal|1
expr_stmt|;
asm|asm("nop");
name|ci
operator|+
name|ci
expr_stmt|;
comment|// A use.
name|__real
name|i
decl_stmt|;
comment|// A use.
operator|+
name|ci
expr_stmt|;
asm|asm("nop");
comment|// Not a use.
call|(
name|void
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
call|(
name|float
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// A use.
operator|(
name|void
operator|)
name|i
expr_stmt|;
name|i
operator|=
name|i
expr_stmt|;
name|i
operator|=
name|i
operator|=
name|i
expr_stmt|;
ifndef|#
directive|ifndef
name|__cplusplus
comment|// Not a use.
operator|(
name|void
operator|)
name|__builtin_choose_expr
argument_list|(
literal|0
argument_list|,
name|i
operator|=
name|i
argument_list|,
name|j
operator|=
name|j
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// A use.
name|k
condition|?
operator|(
name|i
operator|=
name|i
operator|)
else|:
operator|(
name|j
operator|=
name|j
operator|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|i
argument_list|,
operator|(
name|i
operator|=
name|i
operator|)
argument_list|)
expr_stmt|;
name|i
operator|=
name|i
operator|,
name|i
expr_stmt|;
operator|(
name|i
operator|=
name|j
operator|,
name|k
operator|=
name|j
operator|)
expr_stmt|;
operator|(
name|i
operator|=
name|j
operator|,
name|k
operator|)
expr_stmt|;
operator|(
name|i
operator|,
name|j
operator|)
expr_stmt|;
name|i
operator|=
name|c
operator|=
name|k
expr_stmt|;
name|i
operator|+=
name|k
expr_stmt|;
comment|// A use of both.
name|ci
expr_stmt|;
ifndef|#
directive|ifndef
name|__cplusplus
comment|// A use of _real.
operator|(
name|int
operator|)
name|ci
expr_stmt|;
comment|// A use of both.
operator|(
name|_Bool
operator|)
name|ci
expr_stmt|;
endif|#
directive|endif
name|ci
operator|=
name|ci
expr_stmt|;
name|ci
operator|=
name|ci
operator|=
name|ci
expr_stmt|;
name|__imag
name|ci
init|=
name|__imag
name|ci
operator|=
name|__imag
name|ci
decl_stmt|;
comment|// Not a use.
name|__real
argument_list|(
name|i
operator|=
name|j
argument_list|)
expr_stmt|;
comment|// Not a use.
name|__imag
name|i
decl_stmt|;
comment|// ============================================================
comment|// FIXME: Test cases we get wrong.
comment|// A use.  We load all of a into a copy of a, then load i.  gcc forgets to do
comment|// the assignment.
comment|// (a = a).i;
comment|// ============================================================
comment|// Test cases where we intentionally differ from gcc, due to suspected bugs in
comment|// gcc.
comment|// Not a use.  gcc forgets to do the assignment.
operator|(
operator|(
name|a
operator|=
name|a
operator|)
operator|,
name|a
operator|)
expr_stmt|;
comment|// Not a use.  gcc gets this wrong, it doesn't emit the copy!
comment|// (void)(a=a);
comment|// Not a use.  gcc got this wrong in 4.2 and omitted the side effects
comment|// entirely, but it is fixed in 4.4.0.
name|__imag
argument_list|(
name|i
operator|=
name|j
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|__cplusplus
comment|// A use of the real part
call|(
name|float
call|)
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
comment|// Not a use, bug?  gcc treats this as not a use, that's probably a bug due to
comment|// tree folding ignoring volatile.
call|(
name|int
call|)
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// A use.
call|(
name|float
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// A use.  gcc treats this as not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
call|(
name|int
call|)
argument_list|(
name|i
operator|=
name|i
argument_list|)
expr_stmt|;
comment|// A use.
operator|-
operator|(
name|i
operator|=
name|j
operator|)
expr_stmt|;
comment|// A use.  gcc treats this a not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
operator|+
operator|(
name|i
operator|=
name|k
operator|)
expr_stmt|;
comment|// A use. gcc treats this a not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
name|__real
argument_list|(
name|ci
operator|=
name|ci
argument_list|)
expr_stmt|;
comment|// A use.
name|i
operator|+
literal|0
expr_stmt|;
comment|// A use.
operator|(
name|i
operator|=
name|j
operator|)
operator|+
name|i
expr_stmt|;
comment|// A use.  gcc treats this as not a use, that's probably a bug due to tree
comment|// folding ignoring volatile.
operator|(
name|i
operator|=
name|j
operator|)
operator|+
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
operator|(
name|i
operator|,
name|j
operator|)
operator|=
name|k
expr_stmt|;
operator|(
name|j
operator|=
name|k
operator|,
name|i
operator|)
operator|=
name|i
expr_stmt|;
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|s
struct|,
name|s1
struct|;
name|printf
argument_list|(
literal|"s is at %p\n"
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"s is at %p\n"
argument_list|,
operator|&
operator|(
name|s
operator|=
name|s1
operator|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"s.x is at %p\n"
argument_list|,
operator|&
operator|(
operator|(
name|s
operator|=
name|s1
operator|)
operator|.
name|x
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

