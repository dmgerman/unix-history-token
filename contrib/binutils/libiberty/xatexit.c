begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_comment
comment|/* Adapted from newlib/libc/stdlib/{,at}exit.[ch].    If you use xatexit, you must call xexit instead of exit.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For systems with larger pointers than ints, this must be declared.  */
end_comment

begin_decl_stmt
name|PTR
name|malloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|xatexit_cleanup
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to function run by xexit.  */
end_comment

begin_extern
extern|extern void (*_xexit_cleanup
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XATEXIT_SIZE
value|32
end_define

begin_struct
struct|struct
name|xatexit
block|{
name|struct
name|xatexit
modifier|*
name|next
decl_stmt|;
comment|/* next in list */
name|int
name|ind
decl_stmt|;
comment|/* next index in this table */
name|void
argument_list|(
argument|*fns[XATEXIT_SIZE]
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* the table itself */
block|}
struct|;
end_struct

begin_comment
comment|/* Allocate one struct statically to guarantee that we can register    at least a few handlers.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|xatexit
name|xatexit_first
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Points to head of LIFO stack.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|xatexit
modifier|*
name|xatexit_head
init|=
operator|&
name|xatexit_first
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register function FN to be run by xexit.    Return 0 if successful, -1 if not.  */
end_comment

begin_function_decl
name|int
name|xatexit
parameter_list|(
name|fn
parameter_list|)
function_decl|void
parameter_list|(
function_decl|*fn
end_function_decl

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|struct
name|xatexit
modifier|*
name|p
decl_stmt|;
comment|/* Tell xexit to call xatexit_cleanup.  */
if|if
condition|(
operator|!
name|_xexit_cleanup
condition|)
name|_xexit_cleanup
operator|=
name|xatexit_cleanup
expr_stmt|;
name|p
operator|=
name|xatexit_head
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|ind
operator|>=
name|XATEXIT_SIZE
condition|)
block|{
if|if
condition|(
operator|(
name|p
operator|=
operator|(
expr|struct
name|xatexit
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
expr|*
name|p
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
name|p
operator|->
name|ind
operator|=
literal|0
expr_stmt|;
name|p
operator|->
name|next
operator|=
name|xatexit_head
expr_stmt|;
name|xatexit_head
operator|=
name|p
expr_stmt|;
block|}
name|p
operator|->
name|fns
index|[
name|p
operator|->
name|ind
operator|++
index|]
operator|=
name|fn
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/* Call any cleanup functions.  */
end_comment

begin_function
specifier|static
name|void
name|xatexit_cleanup
parameter_list|()
block|{
specifier|register
name|struct
name|xatexit
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
for|for
control|(
name|p
operator|=
name|xatexit_head
init|;
name|p
condition|;
name|p
operator|=
name|p
operator|->
name|next
control|)
for|for
control|(
name|n
operator|=
name|p
operator|->
name|ind
init|;
operator|--
name|n
operator|>=
literal|0
condition|;
control|)
call|(
modifier|*
name|p
operator|->
name|fns
index|[
name|n
index|]
call|)
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

