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
comment|/*  * ^x - return an entry block for co-expression x from the refresh block.  * NOTE:  this code is highly dependent on stack frame layout.  */
end_comment

begin_macro
name|refresh
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|,
argument|arg0
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
decl_stmt|,
name|arg0
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
name|struct
name|descrip
modifier|*
name|dp
decl_stmt|,
modifier|*
name|dsp
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
modifier|*
name|newap
decl_stmt|;
specifier|extern
name|struct
name|b_estack
modifier|*
name|alcestk
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|INT
extern|extern interp(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_expr_stmt
name|SetBound
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|deref
argument_list|(
operator|&
name|arg1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|TYPE
argument_list|(
name|arg1
argument_list|)
operator|!=
name|T_ESTACK
condition|)
name|runerr
argument_list|(
literal|118
argument_list|,
operator|&
name|arg1
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
name|freshblk
operator|=
name|BLKLOC
argument_list|(
name|arg1
argument_list|)
operator|->
name|estack
operator|.
name|freshblk
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
name|hp
operator|=
name|BLKLOC
argument_list|(
name|ep
operator|->
name|freshblk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|na
operator|=
name|hp
operator|->
name|numargs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get value of nargs */
end_comment

begin_expr_stmt
name|nl
operator|=
name|hp
operator|->
name|numlocals
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ap
operator|=
name|hp
operator|->
name|elems
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* find arg0 of caller */
end_comment

begin_comment
comment|/* copy arguments into new stack and refresh block */
end_comment

begin_expr_stmt
name|dsp
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dp
operator|=
name|ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|--
name|dsp
operator|=
operator|*
name|dp
operator|++
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
block|{
operator|*
operator|--
name|dsp
operator|=
operator|*
name|dp
operator|++
expr_stmt|;
block|}
end_while

begin_expr_stmt
name|sp
operator|=
name|dsp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ap
operator|=
name|dp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set up original procedure frame in new stack */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|hp
operator|->
name|numargs
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
operator|(
name|hp
operator|->
name|numargs
operator|*
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*+ invent a nwords value ??-whm */
end_comment

begin_expr_stmt
name|newap
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|interp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

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

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

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
comment|/*   (save its address) */
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
name|dsp
operator|=
name|sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dp
operator|=
name|ap
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
block|{
operator|*
operator|--
name|dsp
operator|=
operator|*
name|dp
operator|++
expr_stmt|;
block|}
end_while

begin_expr_stmt
name|sp
operator|=
name|dsp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ap
operator|=
name|dp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set up dummy call to activate */
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

begin_comment
comment|/* these values are the initial register state for the coexpression */
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
literal|3
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* nwords */
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

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|hp
operator|->
name|ep
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
name|interp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc (entry point) */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
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
name|hp
operator|->
name|ep
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc (entry point) */
end_comment

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
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
comment|/* psw/reg mask with bit set to    					    restore r9, the ipc */
end_comment

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
literal|0
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|arg0
operator|.
name|type
operator|=
name|D_ESTACK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|arg0
argument_list|)
operator|=
name|ep
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ClearBound
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|} struct
name|b_iproc
name|Brefresh
init|=
block|{
name|T_PROC
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_proc
argument_list|)
block|,
name|EntryPoint
argument_list|(
name|refresh
argument_list|)
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
block|{
literal|1
block|,
literal|"^"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_comment
comment|/*  * ^x - return an entry block for co-expression x from the refresh block.  * NOTE:  this code is highly dependent on stack frame layout.  */
end_comment

begin_macro
name|refresh
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|,
argument|arg0
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
decl_stmt|,
name|arg0
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
decl_stmt|;
specifier|extern
name|struct
name|b_estack
modifier|*
name|alcestk
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|INT
extern|extern interp(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_expr_stmt
name|deref
argument_list|(
operator|&
name|arg1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|TYPE
argument_list|(
name|arg1
argument_list|)
operator|!=
name|T_ESTACK
condition|)
name|runerr
argument_list|(
literal|118
argument_list|,
operator|&
name|arg1
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
name|freshblk
operator|=
name|BLKLOC
argument_list|(
name|arg1
argument_list|)
operator|->
name|estack
operator|.
name|freshblk
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
name|hp
operator|=
name|BLKLOC
argument_list|(
name|ep
operator|->
name|freshblk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|na
operator|=
name|hp
operator|->
name|numargs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get value of nargs */
end_comment

begin_expr_stmt
name|nl
operator|=
name|hp
operator|->
name|numlocals
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ap
operator|=
name|hp
operator|->
name|elems
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* find arg0 of caller */
end_comment

begin_comment
comment|/* copy arguments into new stack and refresh block */
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
operator|*
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|ap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* copy arg0 */
end_comment

begin_while
while|while
condition|(
name|na
operator|--
operator|>
literal|0
condition|)
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
operator|++
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
name|hp
operator|->
name|numargs
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
name|file
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved file name */
end_comment

begin_comment
comment|/* copy local variables into new stack */
end_comment

begin_while
while|while
condition|(
name|nl
operator|--
operator|>
literal|0
condition|)
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
operator|++
operator|(
expr|struct
name|descrip
operator|*
operator|)
name|ap
expr_stmt|;
end_while

begin_comment
comment|/* set up dummy call to activate */
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
comment|/* these values are the initial register state for the coexpression */
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

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|interp
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc (entry point) */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|hp
operator|->
name|ep
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* return pc (entry point) */
end_comment

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
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

begin_ifdef
ifdef|#
directive|ifdef
name|INT
end_ifdef

begin_expr_stmt
operator|*
operator|--
name|sp
operator|=
name|hp
operator|->
name|ep
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* saved r2 */
end_comment

begin_endif
endif|#
directive|endif
endif|INT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CMP
end_ifdef

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

begin_endif
endif|#
directive|endif
endif|CMP
end_endif

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
name|arg0
operator|.
name|type
operator|=
name|D_ESTACK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BLKLOC
argument_list|(
name|arg0
argument_list|)
operator|=
name|ep
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|} struct
name|b_iproc
name|Brefresh
init|=
block|{
name|T_PROC
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_proc
argument_list|)
block|,
name|EntryPoint
argument_list|(
name|refresh
argument_list|)
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
block|{
literal|1
block|,
literal|"^"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

end_unit

