begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/*  * create - return an entry block for a co-expression.  */
end_comment

begin_macro
name|create
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg1
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
modifier|*
name|ap
decl_stmt|,
modifier|*
name|sp
decl_stmt|,
modifier|*
name|tp
decl_stmt|;
specifier|register
name|struct
name|descrip
modifier|*
name|dp
decl_stmt|;
specifier|register
name|struct
name|b_estack
modifier|*
name|ep
decl_stmt|;
specifier|register
name|struct
name|b_eblock
modifier|*
name|hp
decl_stmt|;
name|int
name|na
decl_stmt|,
name|nl
decl_stmt|,
modifier|*
name|r5
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
modifier|*
name|newap
decl_stmt|;
extern|extern interp(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|struct
name|b_estack
modifier|*
name|alcestk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|b_eblock
modifier|*
name|alceblk
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|SetBound
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|QUAL
argument_list|(
name|arg1
argument_list|)
operator|||
name|TYPE
argument_list|(
name|arg1
argument_list|)
operator|!=
name|T_INTEGER
condition|)
name|syserr
argument_list|(
literal|"create: illegal entry point"
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*     * Get a new co-expression stack and initialize activator, result     *  count, and stack base.     */
end_comment

begin_expr_stmt
name|esneed
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|=
name|alcestk
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|->
name|activator
operator|=
name|nulldesc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|->
name|nresults
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|->
name|sbase
operator|=
name|sp
operator|=
operator|(
name|int
operator|*
operator|)
name|ep
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Move hardware ap of calling function into the variable ap.     */
end_comment

begin_asm
asm|asm(" addl3 8(fp),$4,r11");
end_asm

begin_comment
comment|/*     * Calculate number of arguments and number of local variables.     */
end_comment

begin_expr_stmt
name|na
operator|=
operator|*
name|ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tp
operator|=
name|ap
operator|+
literal|1
operator|+
operator|(
literal|2
operator|*
name|na
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nl
operator|=
operator|(
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|tp
operator|)
operator|->
name|value
operator|.
name|bptr
operator|->
name|proc
operator|.
name|ndynam
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Get a new co-expression heap block.  Note that the "+ 1" in     *  na + nl + 1 is for arg0, the calling procedure.     */
end_comment

begin_expr_stmt
name|hneed
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|b_eblock
argument_list|)
operator|+
operator|(
name|na
operator|+
name|nl
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|descrip
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|hp
operator|=
name|alceblk
argument_list|(
name|INTVAL
argument_list|(
name|arg1
argument_list|)
argument_list|,
name|na
argument_list|,
name|nl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|->
name|freshblk
operator|.
name|type
operator|=
name|D_EBLOCK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|ep
operator|->
name|freshblk
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|hp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*     * Copy arguments into refresh block.  dp starts at arg0 and works down.     */
end_comment

begin_expr_stmt
name|dp
operator|=
operator|(
expr|struct
name|descrip
operator|*
operator|)
operator|(
operator|(
name|int
operator|*
operator|)
operator|(
name|ap
operator|+
literal|1
operator|+
operator|(
literal|2
operator|*
name|na
operator|)
operator|)
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|i
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|hp
operator|->
name|elems
index|[
literal|0
index|]
operator|=
operator|*
name|dp
operator|--
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|j
operator|=
name|na
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|j
operator|--
operator|>
literal|0
condition|)
block|{
name|hp
operator|->
name|elems
index|[
operator|++
name|i
index|]
operator|=
operator|*
name|dp
operator|--
expr_stmt|;
block|}
end_while

begin_comment
comment|/*     * Copy arguments into new stack.  This is more painful than copying     *  into the refresh block because the arguments are copied a word     *  at a time.  tp starts at the high word of arg0 and goes down.     */
end_comment

begin_expr_stmt
name|tp
operator|=
name|ap
operator|+
literal|2
operator|+
operator|(
literal|2
operator|*
name|na
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|j
operator|=
name|na
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|j
operator|--
operator|>
literal|0
condition|)
block|{
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
block|}
end_while

begin_comment
comment|/*     * Set up original procedure frame in new stack.     */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* copy nargs */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* copy nwords (argc) */
end_comment

begin_expr_stmt
name|newap
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  and save a pointer to it. */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r5 (frame pointer) */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved ap */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* psw/reg. mask */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* condition handler */
end_comment

begin_expr_stmt
name|r5
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  and save a pointer to it */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|line
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved line number */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|file
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved file name */
end_comment

begin_comment
comment|/*     * Copy local variables into new stack.  The asm sets tp to the     *  address of the start of local region in caller's procedure frame.     */
end_comment

begin_asm
asm|asm(" addl3 12(fp),$-12,r9");
end_asm

begin_expr_stmt
name|j
operator|=
name|nl
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|j
operator|--
operator|>
literal|0
condition|)
block|{
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
operator|*
operator|--
name|sp
operator|=
operator|*
name|tp
operator|--
expr_stmt|;
block|}
end_while

begin_comment
comment|/*     * Copy local variables into the refresh block.  The asm sets dp to     *  the address of the first local.     */
end_comment

begin_asm
asm|asm(" addl3 12(fp),$-16,r8");
end_asm

begin_expr_stmt
name|j
operator|=
name|nl
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|j
operator|--
operator|>
literal|0
condition|)
name|hp
operator|->
name|elems
index|[
operator|++
name|i
index|]
operator|=
operator|*
name|dp
operator|--
expr_stmt|;
end_while

begin_comment
comment|/*     * Set up dummy call to coact.     */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|nulldesc
operator|.
name|type
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* place for result */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|INTVAL
argument_list|(
name|nulldesc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|nulldesc
operator|.
name|type
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* place for activate coexpr */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|INTVAL
argument_list|(
name|nulldesc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* nargs */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|3
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 3 longwords in nargs */
end_comment

begin_expr_stmt
name|tp
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* save pointer to start of arg 					    list in this frame */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|INTVAL
argument_list|(
name|arg1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r9 (coexpr entry point) */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|interp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|r5
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r5 */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|newap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved ap */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0x02000000
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* psw/reg mask with bit set to 					    restore r9, the ipc */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* condition handler */
end_comment

begin_expr_stmt
name|ep
operator|->
name|boundary
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   (initial boundary) */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|line
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved line number */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|file
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved file name */
end_comment

begin_expr_stmt
name|ep
operator|->
name|sp
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initial stack pointer */
end_comment

begin_expr_stmt
name|ep
operator|->
name|ap
operator|=
name|tp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initial arg. pointer */
end_comment

begin_comment
comment|/*     * Return the new co-expression.     */
end_comment

begin_expr_stmt
name|arg1
operator|.
name|type
operator|=
name|D_ESTACK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|arg1
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|ep
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ClearBound
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORT
end_ifdef

begin_expr_stmt
unit|create
operator|(
operator|)
block|{
name|syserr
argument_list|(
literal|"Attempt to create a co-expression"
argument_list|)
block|; }
endif|#
directive|endif
endif|PORT
ifdef|#
directive|ifdef
name|PDP11
comment|/*  * create - return an entry block for a co-expression  *  * NOTE:  this code is highly dependent on stack frame layout.  */
name|create
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|)
name|int
name|nargs
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg1
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
modifier|*
name|ap
decl_stmt|,
modifier|*
name|sp
decl_stmt|;
specifier|register
name|struct
name|b_estack
modifier|*
name|ep
decl_stmt|;
specifier|register
name|struct
name|b_eblock
modifier|*
name|hp
decl_stmt|;
name|int
name|na
decl_stmt|,
name|nl
decl_stmt|,
modifier|*
name|r5
decl_stmt|,
name|i
decl_stmt|;
extern|extern interp(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|struct
name|b_estack
modifier|*
name|alcestk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|b_eblock
modifier|*
name|alceblk
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|if
condition|(
name|QUAL
argument_list|(
name|arg1
argument_list|)
operator|||
name|TYPE
argument_list|(
name|arg1
argument_list|)
operator|!=
name|T_INTEGER
condition|)
name|syserr
argument_list|(
literal|"create: illegal entry point"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|esneed
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* check for room in stack space */
end_comment

begin_expr_stmt
name|ep
operator|=
name|alcestk
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* allocate expression stack */
end_comment

begin_expr_stmt
name|ep
operator|->
name|activator
operator|=
name|nulldesc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|->
name|nresults
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ep
operator|->
name|sbase
operator|=
name|sp
operator|=
operator|(
name|int
operator|*
operator|)
name|ep
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initialize new stack pointer */
end_comment

begin_expr_stmt
name|ap
operator|=
operator|(
name|int
operator|*
operator|)
operator|*
operator|(
operator|&
name|nargs
operator|-
literal|2
operator|)
operator|+
literal|2
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* find nargs of caller */
end_comment

begin_expr_stmt
name|na
operator|=
operator|*
name|ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get value of nargs */
end_comment

begin_expr_stmt
name|ap
operator|+=
literal|1
operator|+
literal|2
operator|*
name|na
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* find arg0 of caller */
end_comment

begin_expr_stmt
name|nl
operator|=
operator|(
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|ap
operator|)
operator|->
name|value
operator|.
name|bptr
operator|->
name|proc
operator|.
name|ndynam
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get # locals */
end_comment

begin_expr_stmt
name|hneed
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|b_eblock
argument_list|)
operator|+
operator|(
name|na
operator|+
name|nl
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|descrip
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|hp
operator|=
name|alceblk
argument_list|(
name|INTVAL
argument_list|(
name|arg1
argument_list|)
argument_list|,
name|na
argument_list|,
name|nl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* allocate refresh block */
end_comment

begin_expr_stmt
name|ep
operator|->
name|freshblk
operator|.
name|type
operator|=
name|D_EBLOCK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|ep
operator|->
name|freshblk
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|hp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* copy arguments into new stack and refresh block */
end_comment

begin_expr_stmt
name|i
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|hp
operator|->
name|elems
index|[
name|i
index|]
operator|=
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|sp
operator|=
operator|*
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|ap
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|na
operator|--
operator|>
literal|0
condition|)
name|hp
operator|->
name|elems
index|[
operator|++
name|i
index|]
operator|=
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|sp
operator|=
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|ap
expr_stmt|;
end_while

begin_comment
comment|/* set up original procedure frame in new stack */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|*
operator|--
name|ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* copy nargs */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r5 */
end_comment

begin_expr_stmt
name|r5
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   (save its address) */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r4 */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r3 */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r2 */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|line
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved line number */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|file
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved file name */
end_comment

begin_comment
comment|/* copy local variables into new stack */
end_comment

begin_expr_stmt
name|ap
operator|-=
literal|7
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|nl
operator|--
operator|>
literal|0
condition|)
name|hp
operator|->
name|elems
index|[
operator|++
name|i
index|]
operator|=
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|sp
operator|=
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|ap
expr_stmt|;
end_while

begin_comment
comment|/* set up dummy call to coact */
end_comment

begin_expr_stmt
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|sp
operator|=
name|nulldesc
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* place for result */
end_comment

begin_expr_stmt
operator|*
operator|--
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|sp
operator|=
name|nulldesc
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* place for activate coexpr */
end_comment

begin_comment
comment|/* these values are the initial register state for the co-expression */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* nargs */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|interp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|r5
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r5 */
end_comment

begin_expr_stmt
name|ep
operator|->
name|boundary
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   (initial boundary) */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r4 */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r3 */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|INTVAL
argument_list|(
name|arg1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r2 (coexpr entry point) */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|line
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved line number */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
operator|(
name|int
operator|)
name|file
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved file name */
end_comment

begin_expr_stmt
name|ep
operator|->
name|sp
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* initial stack pointer */
end_comment

begin_expr_stmt
name|arg1
operator|.
name|type
operator|=
name|D_ESTACK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|arg1
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|ep
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
endif|PDP11
end_endif

end_unit

