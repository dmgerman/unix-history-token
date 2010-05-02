begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 by Peter Jeremy<peterjeremy@acm.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FENV_ACCESS
name|ON
end_pragma

begin_include
include|#
directive|include
file|<fenv.h>
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_include
include|#
directive|include
file|"milieu.h"
end_include

begin_include
include|#
directive|include
file|"systflags.h"
end_include

begin_comment
comment|/* ------------------------------------------------------------------------------- Clears the system's IEC/IEEE floating-point exception flags.  Returns the previous value of the flags. ------------------------------------------------------------------------------- */
end_comment

begin_function
name|int8
name|syst_float_flags_clear
parameter_list|(
name|void
parameter_list|)
block|{
name|fexcept_t
name|flags
decl_stmt|;
name|fegetexceptflag
argument_list|(
operator|&
name|flags
argument_list|,
name|FE_ALL_EXCEPT
argument_list|)
expr_stmt|;
name|feclearexcept
argument_list|(
name|FE_ALL_EXCEPT
argument_list|)
expr_stmt|;
return|return
operator|(
name|flags
operator|>>
literal|5
operator|)
return|;
block|}
end_function

end_unit

