begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generated automatically by the program `genpeep' from the machine description file `md'.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"regs.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"real.h"
end_include

begin_decl_stmt
specifier|extern
name|rtx
name|peep_operand
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|operands
value|peep_operand
end_define

begin_function
name|rtx
name|peephole
parameter_list|(
name|ins1
parameter_list|)
name|rtx
name|ins1
decl_stmt|;
block|{
name|rtx
name|insn
decl_stmt|,
name|x
decl_stmt|,
name|pat
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|NEXT_INSN
argument_list|(
name|ins1
argument_list|)
operator|&&
name|GET_CODE
argument_list|(
name|NEXT_INSN
argument_list|(
name|ins1
argument_list|)
argument_list|)
operator|==
name|BARRIER
condition|)
return|return
literal|0
return|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|rtx
name|peep_operand
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

end_unit

