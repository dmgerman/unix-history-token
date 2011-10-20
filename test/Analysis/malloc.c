begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core,experimental.deadcode.UnreachableCode,experimental.core.CastSize,experimental.unix.Malloc -analyzer-store=region -verify %s
end_comment

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|ownership_returns
argument_list|(
name|malloc
argument_list|)
operator|)
argument_list|)
modifier|*
name|my_malloc
argument_list|(
name|size_t
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|ownership_takes
argument_list|(
name|malloc
argument_list|,
literal|1
argument_list|)
operator|)
argument_list|)
name|my_free
argument_list|(
name|void
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|ownership_returns
argument_list|(
name|malloc
argument_list|,
literal|1
argument_list|)
operator|)
argument_list|)
modifier|*
name|my_malloc2
argument_list|(
name|size_t
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|ownership_holds
argument_list|(
name|malloc
argument_list|,
literal|1
argument_list|)
operator|)
argument_list|)
name|my_hold
argument_list|(
name|void
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Duplicate attributes are silly, but not an error.
end_comment

begin_comment
comment|// Duplicate attribute has no extra effect.
end_comment

begin_comment
comment|// If two are of different kinds, that is an error and reported as such.
end_comment

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|ownership_holds
argument_list|(
name|malloc
argument_list|,
literal|1
argument_list|)
operator|)
argument_list|)
name|__attribute
argument_list|(
operator|(
name|ownership_holds
argument_list|(
name|malloc
argument_list|,
literal|1
argument_list|)
operator|)
argument_list|)
name|__attribute
argument_list|(
operator|(
name|ownership_holds
argument_list|(
name|malloc
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
name|my_hold2
argument_list|(
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|my_malloc3
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
modifier|*
name|myglobalpointer
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|stuff
block|{
name|void
modifier|*
name|somefield
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|stuff
name|myglobalstuff
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
return|return;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_function
name|void
name|f2_realloc_0
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|realloc
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|realloc
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_function
name|void
name|f2_realloc_1
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|int
modifier|*
name|q
init|=
name|realloc
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// ownership attributes tests
end_comment

begin_function
name|void
name|naf1
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc3
argument_list|(
literal|12
argument_list|)
decl_stmt|;
return|return;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|n2af1
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc2
argument_list|(
literal|12
argument_list|)
decl_stmt|;
return|return;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_function
name|void
name|af1
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
return|return;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_function
name|void
name|af1_b
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_function
name|void
name|af1_c
parameter_list|()
block|{
name|myglobalpointer
operator|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|af1_d
parameter_list|()
block|{
name|struct
name|stuff
name|mystuff
decl_stmt|;
name|mystuff
operator|.
name|somefield
operator|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
comment|// expected-warning{{Allocated memory never released. Potential memory leak.}}
block|}
end_function

begin_comment
comment|// Test that we can pass out allocated memory via pointer-to-pointer.
end_comment

begin_function
name|void
name|af1_e
parameter_list|(
name|void
modifier|*
modifier|*
name|pp
parameter_list|)
block|{
operator|*
name|pp
operator|=
name|my_malloc
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|af1_f
parameter_list|(
name|struct
name|stuff
modifier|*
name|somestuff
parameter_list|)
block|{
name|somestuff
operator|->
name|somefield
operator|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Allocating memory for a field via multiple indirections to our arguments is OK.
end_comment

begin_function
name|void
name|af1_g
parameter_list|(
name|struct
name|stuff
modifier|*
modifier|*
name|pps
parameter_list|)
block|{
operator|*
name|pps
operator|=
name|my_malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|stuff
argument_list|)
argument_list|)
expr_stmt|;
comment|// no-warning
operator|(
operator|*
name|pps
operator|)
operator|->
name|somefield
operator|=
name|my_malloc
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|af2
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|my_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_function
name|void
name|af2b
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|my_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_function
name|void
name|af2c
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|my_hold
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_function
name|void
name|af2d
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|my_hold2
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Try to free a memory block that has been released}}
block|}
end_function

begin_comment
comment|// No leak if malloc returns null.
end_comment

begin_function
name|void
name|af2e
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
condition|)
return|return;
comment|// no-warning
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// This case would inflict a double-free elsewhere.
end_comment

begin_comment
comment|// However, this case is considered an analyzer bug since it causes false-positives.
end_comment

begin_function
name|void
name|af3
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|my_hold
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// This case would inflict a double-free elsewhere.
end_comment

begin_comment
comment|// However, this case is considered an analyzer bug since it causes false-positives.
end_comment

begin_function
name|int
modifier|*
name|af4
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|my_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
name|p
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// This case is (possibly) ok, be conservative
end_comment

begin_function
name|int
modifier|*
name|af5
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|my_malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|my_hold
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
name|p
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// This case tests that storing malloc'ed memory to a static variable which is
end_comment

begin_comment
comment|// then returned is not leaked.  In the absence of known contracts for functions
end_comment

begin_comment
comment|// or inter-procedural analysis, this is a conservative answer.
end_comment

begin_function
name|int
modifier|*
name|f3
parameter_list|()
block|{
specifier|static
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
name|p
operator|=
name|malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
return|return
name|p
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// This case tests that storing malloc'ed memory to a static global variable
end_comment

begin_comment
comment|// which is then returned is not leaked.  In the absence of known contracts for
end_comment

begin_comment
comment|// functions or inter-procedural analysis, this is a conservative answer.
end_comment

begin_decl_stmt
specifier|static
name|int
modifier|*
name|p_f4
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|f4
parameter_list|()
block|{
name|p_f4
operator|=
name|malloc
argument_list|(
literal|12
argument_list|)
expr_stmt|;
return|return
name|p_f4
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
modifier|*
name|f5
parameter_list|()
block|{
name|int
modifier|*
name|q
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
name|q
operator|=
name|realloc
argument_list|(
name|q
argument_list|,
literal|20
argument_list|)
expr_stmt|;
return|return
name|q
return|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f6
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
condition|)
return|return;
comment|// no-warning
else|else
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f6_realloc
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|12
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|p
condition|)
return|return;
comment|// no-warning
else|else
name|realloc
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|char
modifier|*
name|doit2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|pr6069
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
name|doit2
argument_list|()
decl_stmt|;
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pr6293
parameter_list|()
block|{
name|free
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f7
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|4
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|x
index|[
literal|0
index|]
operator|=
literal|'a'
expr_stmt|;
comment|// expected-warning{{Use dynamically allocated memory after it is freed.}}
block|}
end_function

begin_function
name|void
name|f7_realloc
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|4
argument_list|)
decl_stmt|;
name|realloc
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|x
index|[
literal|0
index|]
operator|=
literal|'a'
expr_stmt|;
comment|// expected-warning{{Use dynamically allocated memory after it is freed.}}
block|}
end_function

begin_function
name|void
name|PR6123
parameter_list|()
block|{
name|int
modifier|*
name|x
init|=
name|malloc
argument_list|(
literal|11
argument_list|)
decl_stmt|;
comment|// expected-warning{{Cast a region whose size is not a multiple of the destination type size.}}
block|}
end_function

begin_function
name|void
name|PR7217
parameter_list|()
block|{
name|int
modifier|*
name|buf
init|=
name|malloc
argument_list|(
literal|2
argument_list|)
decl_stmt|;
comment|// expected-warning{{Cast a region whose size is not a multiple of the destination type size.}}
name|buf
index|[
literal|1
index|]
operator|=
literal|'c'
expr_stmt|;
comment|// not crash
block|}
end_function

begin_function
name|void
name|mallocCastToVoid
parameter_list|()
block|{
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|2
argument_list|)
decl_stmt|;
specifier|const
name|void
modifier|*
name|cp
init|=
name|p
decl_stmt|;
comment|// not crash
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mallocCastToFP
parameter_list|()
block|{
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|()
init|=
name|p
function_decl|;
comment|// not crash
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// This tests that malloc() buffers are undefined by default
end_comment

begin_function
name|char
name|mallocGarbage
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
name|malloc
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|char
name|result
init|=
name|buf
index|[
literal|1
index|]
decl_stmt|;
comment|// expected-warning{{undefined}}
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|// This tests that calloc() buffers need to be freed
end_comment

begin_function
name|void
name|callocNoFree
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
name|calloc
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
decl_stmt|;
return|return;
comment|// expected-warning{{never released}}
block|}
end_function

begin_comment
comment|// These test that calloc() buffers are zeroed by default
end_comment

begin_function
name|char
name|callocZeroesGood
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
name|calloc
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|char
name|result
init|=
name|buf
index|[
literal|3
index|]
decl_stmt|;
comment|// no-warning
if|if
condition|(
name|buf
index|[
literal|1
index|]
operator|==
literal|0
condition|)
block|{
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
comment|// no-warning
block|}
end_function

begin_function
name|char
name|callocZeroesBad
parameter_list|()
block|{
name|char
modifier|*
name|buf
init|=
name|calloc
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|char
name|result
init|=
name|buf
index|[
literal|3
index|]
decl_stmt|;
comment|// no-warning
if|if
condition|(
name|buf
index|[
literal|1
index|]
operator|!=
literal|0
condition|)
block|{
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
comment|// expected-warning{{never executed}}
block|}
return|return
name|result
return|;
comment|// expected-warning{{never released}}
block|}
end_function

end_unit

