begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)trap.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/romvec.h>
end_include

begin_define
define|#
directive|define
name|USER
value|040
end_define

begin_comment
comment|/* user-mode flag added to type */
end_comment

begin_decl_stmt
name|char
modifier|*
name|trap_type
index|[]
init|=
block|{
literal|"Bus error"
block|,
literal|"Address error"
block|,
literal|"Illegal instruction"
block|,
literal|"Zero divide"
block|,
literal|"CHK instruction"
block|,
literal|"TRAPV instruction"
block|,
literal|"Privilege violation"
block|,
literal|"Trace trap"
block|,
literal|"MMU fault"
block|,
literal|"SSIR trap"
block|,
literal|"Format error"
block|,
literal|"68881 exception"
block|,
literal|"Coprocessor violation"
block|,
literal|"Async system trap"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TRAP_TYPES
value|(sizeof trap_type / sizeof trap_type[0])
end_define

begin_comment
comment|/*  * Called from the trap handler when a processor trap occurs.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|trap
argument_list|(
argument|type
argument_list|,
argument|code
argument_list|,
argument|v
argument_list|,
argument|frame
argument_list|)
end_macro

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|unsigned
name|v
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|frame
name|frame
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|type
condition|)
block|{
default|default:
name|dopanic
label|:
name|printf
argument_list|(
literal|"trap type %d, code = %x, v = %x\n"
argument_list|,
name|type
argument_list|,
name|code
argument_list|,
name|v
argument_list|)
expr_stmt|;
name|regdump
argument_list|(
name|frame
operator|.
name|f_regs
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|type
operator|&=
operator|~
name|USER
expr_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|type
operator|<
name|TRAP_TYPES
condition|)
name|panic
argument_list|(
name|trap_type
index|[
name|type
index|]
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"trap"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

