begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../hdr/defines.h"
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|fmterr
literal|2.1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fmterr
argument_list|(
name|pkt
argument_list|)
specifier|register
expr|struct
name|packet
operator|*
name|pkt
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|fclose
argument_list|(
name|pkt
operator|->
name|p_iop
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|Error
argument_list|,
literal|"format error at line %u (co4)"
argument_list|,
name|pkt
operator|->
name|p_slnno
argument_list|)
expr_stmt|;
name|fatal
argument_list|(
name|Error
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

