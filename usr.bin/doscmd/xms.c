begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** No copyright?! ** ** $Id: xms.c,v 1.3 1996/09/22 15:43:01 miff Exp $ */
end_comment

begin_include
include|#
directive|include
file|"doscmd.h"
end_include

begin_decl_stmt
name|u_long
name|xms_vector
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|int2f_43
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
switch|switch
condition|(
name|R_AL
condition|)
block|{
case|case
literal|0x00
case|:
comment|/* installation check */
name|R_AL
operator|=
literal|0x80
expr_stmt|;
break|break;
case|case
literal|0x10
case|:
comment|/* get handler address */
name|N_PUTVEC
argument_list|(
name|R_ES
argument_list|,
name|R_BX
argument_list|,
name|xms_vector
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ** XXX DANGER WILL ROBINSON! */
end_comment

begin_function
specifier|static
name|void
name|xms_entry
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
switch|switch
condition|(
name|R_AH
condition|)
block|{
case|case
literal|0x00
case|:
comment|/* get version number */
name|R_AX
operator|=
literal|0x0300
expr_stmt|;
comment|/* 3.0 */
name|R_BX
operator|=
literal|0x0001
expr_stmt|;
comment|/* internal revision 0.1 */
name|R_DX
operator|=
literal|0x0001
expr_stmt|;
comment|/* HMA exists */
break|break;
default|default:
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"XMS %02x\n"
argument_list|,
name|R_AH
argument_list|)
expr_stmt|;
name|R_AX
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_decl_stmt
specifier|static
name|u_char
name|xms_trampoline
index|[]
init|=
block|{
literal|0xeb
block|,
comment|/* JMP 5 */
literal|0x03
block|,
literal|0x90
block|,
comment|/* NOP */
literal|0x90
block|,
comment|/* NOP */
literal|0x90
block|,
comment|/* NOP */
literal|0xf4
block|,
comment|/* HLT */
literal|0xcb
block|,
comment|/* RETF */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|xms_init
parameter_list|(
name|void
parameter_list|)
block|{
name|xms_vector
operator|=
name|insert_generic_trampoline
argument_list|(
sizeof|sizeof
argument_list|(
name|xms_trampoline
argument_list|)
argument_list|,
name|xms_trampoline
argument_list|)
expr_stmt|;
name|register_callback
argument_list|(
name|xms_vector
operator|+
literal|5
argument_list|,
name|xms_entry
argument_list|,
literal|"xms"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

