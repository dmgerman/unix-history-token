begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* file: myfrexp.c ** functions: myfrexp() ** origins: 68k.c ** comments: this looks like a lame way out to me but *I* certainly don't ** want to write a version of this routine for any processor. */
end_comment

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_macro
name|myfrexp
argument_list|()
end_macro

begin_block
block|{
name|error
argument_list|(
literal|"myfrexp called"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ** Comment from bigmath.c: ** **	myfrexp (value, exp, hi, lo) **		double value; **		int *exp, *hi, *lo; ** **	myfrexp returns three values, exp, hi, lo, **	Such that value = 2**exp*tmp, where tmp = (hi*2**-23+lo*2**-53) **	is uniquely determined subect to .5< abs(tmp)<= 1.0 ** */
end_comment

end_unit

