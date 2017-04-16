begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -Wno-int-to-pointer-cast -analyzer-checker=alpha.security.taint,debug.TaintTest %s -verify
end_comment

begin_include
include|#
directive|include
file|"Inputs/system-header-simulator.h"
end_include

begin_define
define|#
directive|define
name|BUFSIZE
value|10
end_define

begin_decl_stmt
name|int
name|Buffer
index|[
name|BUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|XYStruct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|char
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|taintTracking
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|n
decl_stmt|;
name|int
modifier|*
name|addr
init|=
operator|&
name|Buffer
index|[
literal|0
index|]
decl_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|n
argument_list|)
expr_stmt|;
name|addr
operator|+=
name|n
expr_stmt|;
comment|// expected-warning + {{tainted}}
operator|*
name|addr
operator|=
name|n
expr_stmt|;
comment|// expected-warning + {{tainted}}
name|double
name|tdiv
init|=
name|n
operator|/
literal|30
decl_stmt|;
comment|// expected-warning+ {{tainted}}
name|char
modifier|*
name|loc_cast
init|=
operator|(
name|char
operator|*
operator|)
name|n
decl_stmt|;
comment|// expected-warning +{{tainted}}
name|char
name|tinc
init|=
name|tdiv
operator|++
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|tincdec
init|=
operator|(
name|char
operator|)
name|tinc
operator|--
decl_stmt|;
comment|// expected-warning+{{tainted}}
comment|// Tainted ptr arithmetic/array element address.
name|int
name|tprtarithmetic1
init|=
operator|*
operator|(
name|addr
operator|+
literal|1
operator|)
decl_stmt|;
comment|// expected-warning + {{tainted}}
comment|// Dereference.
name|int
modifier|*
name|ptr
decl_stmt|;
name|scanf
argument_list|(
literal|"%p"
argument_list|,
operator|&
name|ptr
argument_list|)
expr_stmt|;
name|int
name|ptrDeref
init|=
operator|*
name|ptr
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|_ptrDeref
init|=
name|ptrDeref
operator|+
literal|13
decl_stmt|;
comment|// expected-warning + {{tainted}}
comment|// Pointer arithmetic + dereferencing.
comment|// FIXME: We fail to propagate the taint here because RegionStore does not
comment|// handle ElementRegions with symbolic indexes.
name|int
name|addrDeref
init|=
operator|*
name|addr
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|_addrDeref
init|=
name|addrDeref
decl_stmt|;
comment|// expected-warning + {{tainted}}
comment|// Tainted struct address, casts.
name|struct
name|XYStruct
modifier|*
name|xyPtr
init|=
literal|0
decl_stmt|;
name|scanf
argument_list|(
literal|"%p"
argument_list|,
operator|&
name|xyPtr
argument_list|)
expr_stmt|;
name|void
modifier|*
name|tXYStructPtr
init|=
name|xyPtr
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|struct
name|XYStruct
modifier|*
name|xyPtrCopy
init|=
name|tXYStructPtr
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|ptrtx
init|=
name|xyPtr
operator|->
name|x
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|ptrty
init|=
name|xyPtr
operator|->
name|y
decl_stmt|;
comment|// expected-warning + {{tainted}}
comment|// Taint on fields of a struct.
name|struct
name|XYStruct
name|xy
init|=
block|{
literal|2
block|,
literal|3
block|,
literal|11
block|}
decl_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|xy
operator|.
name|y
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|xy
operator|.
name|x
argument_list|)
expr_stmt|;
name|int
name|tx
init|=
name|xy
operator|.
name|x
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|ty
init|=
name|xy
operator|.
name|y
decl_stmt|;
comment|// FIXME: This should be tainted as well.
name|char
name|ntz
init|=
name|xy
operator|.
name|z
decl_stmt|;
comment|// no warning
comment|// Now, scanf scans both.
name|scanf
argument_list|(
literal|"%d %d"
argument_list|,
operator|&
name|xy
operator|.
name|y
argument_list|,
operator|&
name|xy
operator|.
name|x
argument_list|)
expr_stmt|;
name|int
name|ttx
init|=
name|xy
operator|.
name|x
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|tty
init|=
name|xy
operator|.
name|y
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_function
name|void
name|BitwiseOp
parameter_list|(
name|int
name|in
parameter_list|,
name|char
name|inn
parameter_list|)
block|{
comment|// Taint on bitwise operations, integer to integer cast.
name|int
name|m
decl_stmt|;
name|int
name|x
init|=
literal|0
decl_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
name|int
name|y
init|=
operator|(
name|in
operator|<<
operator|(
name|x
operator|<<
name|in
operator|)
operator|)
operator|*
literal|5
decl_stmt|;
comment|// expected-warning + {{tainted}}
comment|// The next line tests integer to integer cast.
name|int
name|z
init|=
name|y
operator|&
name|inn
decl_stmt|;
comment|// expected-warning + {{tainted}}
if|if
condition|(
name|y
operator|==
literal|5
condition|)
comment|// expected-warning + {{tainted}}
name|m
operator|=
name|z
operator||
name|z
expr_stmt|;
comment|// expected-warning + {{tainted}}
else|else
name|m
operator|=
name|inn
expr_stmt|;
name|int
name|mm
init|=
name|m
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_comment
comment|// Test getenv.
end_comment

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|getenvTest
parameter_list|(
name|char
modifier|*
name|home
parameter_list|)
block|{
name|home
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
if|if
condition|(
name|home
operator|!=
literal|0
condition|)
block|{
comment|// expected-warning + {{tainted}}
name|char
name|d
init|=
name|home
index|[
literal|0
index|]
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
block|}
end_function

begin_function
name|int
name|fscanfTest
parameter_list|(
name|void
parameter_list|)
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
name|s
index|[
literal|80
index|]
decl_stmt|;
name|int
name|t
decl_stmt|;
comment|// Check if stdin is treated as tainted.
name|fscanf
argument_list|(
name|stdin
argument_list|,
literal|"%s %d"
argument_list|,
name|s
argument_list|,
operator|&
name|t
argument_list|)
expr_stmt|;
comment|// Note, here, s is not tainted, but the data s points to is tainted.
name|char
modifier|*
name|ts
init|=
name|s
decl_stmt|;
name|char
name|tss
init|=
name|s
index|[
literal|0
index|]
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|tt
init|=
name|t
decl_stmt|;
comment|// expected-warning + {{tainted}}
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
literal|"test"
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|// expected-warning + {{tainted}}
return|return
literal|1
return|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s %d"
argument_list|,
name|s
argument_list|,
name|t
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
comment|// Test fscanf and fopen.
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
literal|"test"
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|// expected-warning + {{tainted}}
return|return
literal|1
return|;
name|fscanf
argument_list|(
name|fp
argument_list|,
literal|"%s%d"
argument_list|,
name|s
argument_list|,
operator|&
name|t
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s %d"
argument_list|,
name|s
argument_list|,
name|t
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Check if we propagate taint from stdin when it's used in an assignment.
end_comment

begin_function
name|void
name|stdinTest1
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|fscanf
argument_list|(
name|stdin
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
name|int
name|j
init|=
name|i
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_function
name|void
name|stdinTest2
parameter_list|(
name|FILE
modifier|*
name|pIn
parameter_list|)
block|{
name|FILE
modifier|*
name|p
init|=
name|stdin
decl_stmt|;
name|FILE
modifier|*
name|pp
init|=
name|p
decl_stmt|;
name|int
name|ii
decl_stmt|;
name|fscanf
argument_list|(
name|pp
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|ii
argument_list|)
expr_stmt|;
name|int
name|jj
init|=
name|ii
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|fscanf
argument_list|(
name|p
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|ii
argument_list|)
expr_stmt|;
name|int
name|jj2
init|=
name|ii
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|ii
operator|=
literal|3
expr_stmt|;
name|int
name|jj3
init|=
name|ii
decl_stmt|;
comment|// no warning
name|p
operator|=
name|pIn
expr_stmt|;
name|fscanf
argument_list|(
name|p
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|ii
argument_list|)
expr_stmt|;
name|int
name|jj4
init|=
name|ii
decl_stmt|;
comment|// no warning
block|}
end_function

begin_function
name|void
name|stdinTest3
parameter_list|()
block|{
name|FILE
modifier|*
modifier|*
name|ppp
init|=
operator|&
name|stdin
decl_stmt|;
name|int
name|iii
decl_stmt|;
name|fscanf
argument_list|(
operator|*
name|ppp
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|iii
argument_list|)
expr_stmt|;
name|int
name|jjj
init|=
name|iii
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_comment
comment|// Test that stdin does not get invalidated by calls.
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|stdinTest4
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|fscanf
argument_list|(
name|stdin
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
name|foo
argument_list|()
expr_stmt|;
name|int
name|j
init|=
name|i
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_function_decl
name|int
name|getw
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|getwTest
parameter_list|()
block|{
name|int
name|i
init|=
name|getw
argument_list|(
name|stdin
argument_list|)
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_typedef
typedef|typedef
name|long
name|ssize_t
typedef|;
end_typedef

begin_function_decl
name|ssize_t
name|getline
parameter_list|(
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|size_t
modifier|*
name|__restrict
parameter_list|,
name|FILE
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|getlineTest
parameter_list|(
name|void
parameter_list|)
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|line
init|=
literal|0
decl_stmt|;
name|size_t
name|len
init|=
literal|0
decl_stmt|;
name|ssize_t
name|read
decl_stmt|;
while|while
condition|(
operator|(
name|read
operator|=
name|getline
argument_list|(
operator|&
name|line
argument_list|,
operator|&
name|len
argument_list|,
name|stdin
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|line
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
block|}
name|free
argument_list|(
name|line
argument_list|)
expr_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

begin_comment
comment|// Test propagation functions - the ones that propagate taint from arguments to
end_comment

begin_comment
comment|// return value, ptr arguments.
end_comment

begin_function_decl
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|atol
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|atoll
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|atoiTest
parameter_list|()
block|{
name|char
name|s
index|[
literal|80
index|]
decl_stmt|;
name|scanf
argument_list|(
literal|"%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|int
name|d
init|=
name|atoi
argument_list|(
name|s
argument_list|)
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|td
init|=
name|d
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|long
name|l
init|=
name|atol
argument_list|(
name|s
argument_list|)
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|tl
init|=
name|l
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|long
name|long
name|ll
init|=
name|atoll
argument_list|(
name|s
argument_list|)
decl_stmt|;
comment|// expected-warning + {{tainted}}
name|int
name|tll
init|=
name|ll
decl_stmt|;
comment|// expected-warning + {{tainted}}
block|}
end_function

end_unit

