begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_include
include|#
directive|include
file|"../h/gc.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/*  * sweep - sweep the stack, marking all descriptors there.  Method  *  is to start at a known point, specifically, the frame that the  *  fp points to, and then trace back along the stack looking for  *  descriptors and local variables, marking them when they are found.  *  The sp starts at the first frame, and then is moved up through  *  the stack.  Procedure, generator, and expression frames are  *  recognized when the sp is a certain distance from the fp, gfp,  *  and efp respectively.  *  * Sweeping problems can be manifested in a variety of ways due to  *  the "if it can't be identified it's a descriptor" methodology.  */
end_comment

begin_undef
undef|#
directive|undef
name|gfp
end_undef

begin_undef
undef|#
directive|undef
name|efp
end_undef

begin_undef
undef|#
directive|undef
name|fp
end_undef

begin_macro
name|sweep
argument_list|(
argument|fp
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
modifier|*
name|sp
decl_stmt|,
modifier|*
name|gfp
decl_stmt|,
modifier|*
name|efp
decl_stmt|,
modifier|*
name|ap
decl_stmt|;
name|int
modifier|*
name|getap
parameter_list|()
function_decl|;
name|int
name|nargs
decl_stmt|;
name|ap
operator|=
name|getap
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* Get pointer to 0(ap) for frame 					    on top of stack. */
name|sp
operator|=
name|fp
operator|-
name|FRAMELIMIT
expr_stmt|;
comment|/* Start sp at _file word of current 					    frame, the lowest word of it. */
name|nargs
operator|=
literal|0
expr_stmt|;
comment|/* Nargs counter is 0 initially. */
while|while
condition|(
operator|(
name|fp
operator|!=
literal|0
operator|||
name|nargs
operator|)
condition|)
block|{
comment|/* Keep going until current fp is 					    0 and no arguments are left. */
if|if
condition|(
name|sp
operator|==
name|fp
operator|-
name|FRAMELIMIT
condition|)
block|{
comment|/* The sp has reached the lower 					    boundary of a procedure frame, 					    process the frame. */
name|efp
operator|=
operator|(
name|int
operator|*
operator|)
name|ap
index|[
operator|-
literal|1
index|]
expr_stmt|;
comment|/* Get saved efp out of frame, it's 					    the first word below 0(ap). */
name|gfp
operator|=
operator|(
name|int
operator|*
operator|)
name|ap
index|[
operator|-
literal|2
index|]
expr_stmt|;
comment|/* Saved gfp is second word below 					    0(ap). */
name|sp
operator|=
name|ap
operator|+
literal|2
expr_stmt|;
comment|/* First argument descriptor is 					    second word above 0(ap), point 					    sp at it. */
name|ap
operator|=
operator|(
name|int
operator|*
operator|)
name|fp
index|[
literal|2
index|]
expr_stmt|;
comment|/* Get saved ap */
name|fp
operator|=
operator|(
name|int
operator|*
operator|)
name|fp
index|[
literal|3
index|]
expr_stmt|;
comment|/*  and fp from frame. */
name|nargs
operator|=
name|sp
index|[
operator|-
literal|1
index|]
expr_stmt|;
comment|/* Nargs is in word below first 					    argument descriptor. */
block|}
elseif|else
if|if
condition|(
name|sp
operator|==
name|gfp
operator|-
literal|3
condition|)
block|{
comment|/* The sp has reached the lower end 					    of a generator frame, process 					    the frame.*/
name|fp
operator|=
operator|(
name|int
operator|*
operator|)
name|gfp
index|[
literal|0
index|]
expr_stmt|;
comment|/* Get old fp, available as saved 					    boundary value in the frame. */
name|ap
operator|=
name|getap
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* Find 0(ap) corresponding to just- 					    restored boundary value. */
name|sp
operator|=
name|fp
operator|-
name|FRAMELIMIT
expr_stmt|;
comment|/* Set up to trigger recognition of 					    procedure frame next time around*/
block|}
elseif|else
if|if
condition|(
name|sp
operator|==
name|efp
operator|-
literal|2
condition|)
block|{
comment|/* The sp has reached the lower end 					    of a generator frame, process 					    the frame. */
name|gfp
operator|=
operator|(
name|int
operator|*
operator|)
name|efp
index|[
operator|-
literal|1
index|]
expr_stmt|;
comment|/* Restore gfp, */
name|efp
operator|=
operator|(
name|int
operator|*
operator|)
name|efp
index|[
literal|0
index|]
expr_stmt|;
comment|/*  and efp from frame. */
name|sp
operator|+=
literal|3
expr_stmt|;
comment|/* Move up past expression frame 					    marker. */
block|}
else|else
block|{
comment|/* Assume the sp is pointing at a 					    descriptor. */
name|mark
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|/* Mark it. */
name|sp
operator|+=
literal|2
expr_stmt|;
comment|/* Move past descriptor. */
if|if
condition|(
name|nargs
condition|)
comment|/* Decrement argument count if in an*/
name|nargs
operator|--
expr_stmt|;
comment|/*  argument list. */
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * getap - return ap of frame addressed by fp  */
end_comment

begin_function
name|int
modifier|*
name|getap
parameter_list|(
name|fp
parameter_list|)
specifier|register
name|int
modifier|*
name|fp
decl_stmt|;
block|{
specifier|register
name|int
name|mask
init|=
name|fp
index|[
literal|1
index|]
operator|>>
literal|15
operator|&
literal|0x1ffe
decl_stmt|;
comment|/* Get register mask out of saved 					    psw word. */
name|fp
operator|+=
literal|5
expr_stmt|;
comment|/* Point fp at where first saved 					    register (if any) is. */
while|while
condition|(
name|mask
operator|>>=
literal|1
condition|)
comment|/* Move fp up for each register  */
name|fp
operator|+=
name|mask
operator|&
literal|1
expr_stmt|;
comment|/*  saved.  When done, fp points */
return|return
name|fp
return|;
comment|/*  at word where ap would point */
block|}
end_function

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_macro
name|sweep
argument_list|()
end_macro

begin_block
block|{
name|syserr
argument_list|(
literal|"Call to sweep() in garbage collector not implemented yet"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|PORT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_comment
comment|/*  * sweep - sweep the stack, marking all descriptors there.  */
end_comment

begin_macro
name|sweep
argument_list|(
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
modifier|*
name|sp
decl_stmt|,
modifier|*
name|r5
decl_stmt|,
modifier|*
name|r4
decl_stmt|;
name|int
modifier|*
name|r3
decl_stmt|,
name|nargs
decl_stmt|;
name|r5
operator|=
name|b
expr_stmt|;
comment|/* start at last Icon/C boundary */
name|sp
operator|=
name|r5
operator|-
literal|5
expr_stmt|;
name|nargs
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|r5
operator|!=
literal|0
operator|||
name|nargs
operator|)
operator|&&
name|sp
operator|<
operator|(
name|int
operator|*
operator|)
literal|0177776
condition|)
block|{
if|if
condition|(
name|sp
operator|==
name|r5
operator|-
literal|5
condition|)
block|{
comment|/* at a procedure frame */
name|r3
operator|=
name|r5
index|[
operator|-
literal|2
index|]
expr_stmt|;
name|r4
operator|=
name|r5
index|[
operator|-
literal|1
index|]
expr_stmt|;
name|r5
operator|=
name|r5
index|[
literal|0
index|]
expr_stmt|;
name|sp
operator|+=
literal|8
expr_stmt|;
name|nargs
operator|=
name|sp
index|[
operator|-
literal|1
index|]
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sp
operator|==
name|r3
operator|-
literal|3
condition|)
block|{
comment|/* at a generator frame */
name|r5
operator|=
name|r3
index|[
literal|0
index|]
expr_stmt|;
comment|/*   go to next boundary */
name|sp
operator|=
name|r5
operator|-
literal|5
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sp
operator|==
name|r4
operator|-
literal|2
condition|)
block|{
comment|/* at an expression frame */
name|r3
operator|=
name|r4
index|[
operator|-
literal|1
index|]
expr_stmt|;
name|r4
operator|=
name|r4
index|[
literal|0
index|]
expr_stmt|;
name|sp
operator|+=
literal|3
expr_stmt|;
block|}
else|else
block|{
comment|/* must be a descriptor! */
name|mark
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|sp
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|nargs
condition|)
name|nargs
operator|--
expr_stmt|;
block|}
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

end_unit

