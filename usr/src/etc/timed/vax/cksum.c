begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)cksum.c	1.2 (Berkeley) 9/18/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|ADD
value|asm("adwc (r9)+,r8;");
end_define

begin_comment
comment|/* computes the checksum for ip packets for the VAX */
end_comment

begin_macro
name|in_cksum
argument_list|(
argument|addr
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|u_short
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|nleft
init|=
name|len
decl_stmt|;
comment|/* on vax, (user mode), r11 */
ifndef|#
directive|ifndef
name|lint
specifier|register
name|int
name|xxx
decl_stmt|;
comment|/* on vax, (user mode), r10 */
endif|#
directive|endif
endif|not lint
specifier|register
name|u_short
modifier|*
name|w
init|=
name|addr
decl_stmt|;
comment|/* on vax, known to be r9 */
specifier|register
name|int
name|sum
init|=
literal|0
decl_stmt|;
comment|/* on vax, known to be r8 */
if|if
condition|(
operator|(
operator|(
name|int
operator|)
name|w
operator|&
literal|0x2
operator|)
operator|&&
name|nleft
operator|>=
literal|2
condition|)
block|{
name|sum
operator|+=
operator|*
name|w
operator|++
expr_stmt|;
name|nleft
operator|-=
literal|2
expr_stmt|;
block|}
while|while
condition|(
operator|(
name|nleft
operator|-=
literal|32
operator|)
operator|>=
literal|0
condition|)
block|{
asm|asm("clrl r0");
comment|/* clears carry */
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
asm|asm("adwc $0,r8");
block|}
name|nleft
operator|+=
literal|32
expr_stmt|;
while|while
condition|(
operator|(
name|nleft
operator|-=
literal|8
operator|)
operator|>=
literal|0
condition|)
block|{
asm|asm("clrl r0");
name|ADD
expr_stmt|;
name|ADD
expr_stmt|;
asm|asm("adwc $0,r8");
block|}
name|nleft
operator|+=
literal|8
expr_stmt|;
block|{
asm|asm("ashl $-16,r8,r0; addw2 r0,r8");
asm|asm("adwc $0,r8; movzwl r8,r8");
block|}
while|while
condition|(
operator|(
name|nleft
operator|-=
literal|2
operator|)
operator|>=
literal|0
condition|)
block|{
asm|asm("movzwl (r9)+,r0; addl2 r0,r8");
block|}
if|if
condition|(
name|nleft
operator|==
operator|-
literal|1
condition|)
block|{
name|sum
operator|+=
operator|*
operator|(
name|u_char
operator|*
operator|)
name|w
expr_stmt|;
block|}
block|{
asm|asm("ashl $-16,r8,r0; addw2 r0,r8; adwc $0,r8");
asm|asm("mcoml r8,r8; movzwl r8,r8");
block|}
return|return
operator|(
name|sum
operator|)
return|;
block|}
end_block

end_unit

