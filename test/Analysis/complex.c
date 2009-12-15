begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic -analyzer-constraints=basic -verify %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic -analyzer-constraints=range -verify %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=region -analyzer-constraints=basic -verify %s
end_comment

begin_comment
comment|// RUN: clang -cc1 -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=region -analyzer-constraints=range -verify %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_function
name|void
name|f1
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// This branch should be infeasible
comment|// because __imag__ p is 0.
if|if
condition|(
operator|!
name|p
operator|&&
name|__imag__
argument_list|(
argument|intptr_t
argument_list|)
name|p
condition|)
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
comment|// If p != 0 then this branch is feasible; otherwise it is not.
if|if
condition|(
name|__real__
argument_list|(
argument|intptr_t
argument_list|)
name|p
condition|)
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
operator|*
name|p
operator|=
literal|2
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
block|}
end_function

end_unit

