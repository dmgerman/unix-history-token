begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Awriteable.c	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoealign/align.h"
end_include

begin_function
name|long
name|writeable
parameter_list|(
name|infop
parameter_list|,
name|address
parameter_list|,
name|length
parameter_list|)
name|process_info
modifier|*
name|infop
decl_stmt|;
name|long
name|address
decl_stmt|,
name|length
decl_stmt|;
comment|/*  *   Return TRUE (= -1) if the specified bytes can be written without an access  * control violation (limit and/or protection). Page faults are OK.  *   If problems, return the code that would be pushed by HW on the  * stack (see the architecture manual).  *   Assumption is that in most cases, access is OK, so a quick 'probew'  * will be enough. If not, we have to work harder to determine the exact  * cause and return the right code, without getting the fault here in  * the kernel !!.  *  * The address is assumed to be write for the user.!  */
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* Has to be first reg ! */
specifier|register
name|long
name|Register_11
decl_stmt|;
specifier|register
name|long
name|Register_10
decl_stmt|;
specifier|register
name|long
name|Register_9
decl_stmt|;
specifier|register
name|long
name|Register_8
decl_stmt|;
specifier|register
name|long
name|subspace
decl_stmt|;
specifier|register
name|long
name|last_page
decl_stmt|;
name|Register_12
operator|=
name|address
expr_stmt|;
name|Register_11
operator|=
name|length
operator|-
literal|1
expr_stmt|;
asm|asm ("		probew	$1,(r12),$1	");
comment|/* Yeach ... */
asm|asm ("		beql	no_access	");
asm|asm ("		addl2	r11,r12		");
comment|/* last byte */
asm|asm ("		probew	$1,(r12),$1	");
asm|asm ("		beql	no_access	");
asm|asm ("		movl	$-1,r0		");
comment|/* TRUE */
asm|asm ("		ret#1			");
asm|asm ("no_access:			");
comment|/*  * Now the hard work. Have to check length violation first.  * If any byte (first or last) causes a length violation, report it as such.  */
asm|asm ("	mfpr	$3,r8	");
comment|/* Get length registers. P0LR */
asm|asm ("	mfpr	$5,r9	");
comment|/* P1LR */
asm|asm ("	mfpr	$7,r10	");
comment|/* P2LR */
asm|asm ("	mfpr	$1,r11	");
comment|/* SLR */
name|subspace
operator|=
operator|(
name|address
operator|>>
literal|30
operator|)
operator|&
literal|3
expr_stmt|;
name|Register_12
operator|=
operator|(
name|address
operator|>>
literal|10
operator|)
operator|&
literal|0xfffff
expr_stmt|;
comment|/* 1'st byte page # */
name|last_page
operator|=
operator|(
operator|(
name|address
operator|+
name|length
operator|-
literal|1
operator|)
operator|>>
literal|10
operator|)
operator|&
literal|0xfffff
expr_stmt|;
switch|switch
condition|(
name|subspace
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
operator|(
name|Register_12
operator|>=
name|Register_8
operator|)
operator|||
operator|(
name|last_page
operator|>=
name|Register_8
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
case|case
literal|1
case|:
if|if
condition|(
operator|(
name|Register_12
operator|>=
name|Register_9
operator|)
operator|||
operator|(
name|last_page
operator|>=
name|Register_9
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
case|case
literal|2
case|:
if|if
condition|(
operator|(
name|Register_12
operator|<
name|Register_10
operator|)
operator|||
operator|(
name|last_page
operator|<
name|Register_10
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
case|case
literal|3
case|:
if|if
condition|(
operator|(
name|Register_12
operator|>=
name|Register_11
operator|)
operator|||
operator|(
name|last_page
operator|>=
name|Register_11
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
break|break;
block|}
comment|/*  * OK, it's not a length violation. Must have been an access problem  * (no write by user).  *  * NOTE : I definitely ignore the case of 'no PTE access' since I  *	assume that's not the case for user mode. Besides, the poor  *	guy will just get an access violation that will most probably  *	send him into hyperspace anyway, so no need to be too acurate here.  */
return|return
operator|(
literal|4
operator|)
return|;
block|}
end_function

end_unit

