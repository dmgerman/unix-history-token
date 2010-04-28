begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===============================================================================  This C source file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"milieu.h"
end_include

begin_include
include|#
directive|include
file|"random.h"
end_include

begin_function
name|uint8
name|randomUint8
parameter_list|(
name|void
parameter_list|)
block|{
return|return
call|(
name|bits8
call|)
argument_list|(
name|random
argument_list|()
operator|>>
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16
name|randomUint16
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|random
argument_list|()
operator|&
literal|0x0000ffff
operator|)
return|;
block|}
end_function

begin_function
name|uint32
name|randomUint32
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|uint32
operator|)
name|random
argument_list|()
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
name|uint32
operator|)
name|random
argument_list|()
operator|&
literal|0x0000ffff
operator|)
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_function
name|uint64
name|randomUint64
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|uint64
operator|)
name|randomUint32
argument_list|()
operator|)
operator|<<
literal|32
operator|)
operator||
name|randomUint32
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

