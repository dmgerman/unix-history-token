begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Helmut Wirth<hfwirth@ping.at>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, witout modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"doscmd.h"
end_include

begin_include
include|#
directive|include
file|"emuint.h"
end_include

begin_comment
comment|/* The central entry point for the emulator interrupt. This is used by  * different special programs to call the emulator from VM86 space.   * Look at emuint.h for definitions and a list of the currently defined  * subfunctions.  * To call emuint from VM86 space do:  *	push ax		   Save original ax value (*must be done* !)  *	mov  ah, funcnum   Emuint function number to ah  *	mov  al, subfunc   Subfunction number, optional, depending on func  *	int  0xff		  *	..  *	..  * Emuint saves the function and subfunction numbers internally, then  * pops ax off the stack and calls the function handler with the original  * value in ax.  */
end_comment

begin_function
name|void
name|emuint
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
block|{
name|u_short
name|func
decl_stmt|,
name|subfunc
decl_stmt|;
comment|/* Remove function number from stack */
name|func
operator|=
name|R_AH
expr_stmt|;
name|subfunc
operator|=
name|R_AL
expr_stmt|;
name|R_AX
operator|=
name|POP
argument_list|(
name|REGS
argument_list|)
expr_stmt|;
comment|/* Call the function handler, subfunction is ignored, if unused */
switch|switch
condition|(
name|func
condition|)
block|{
comment|/* The redirector call */
case|case
name|EMU_REDIR
case|:
name|intff
argument_list|(
name|REGS
argument_list|)
expr_stmt|;
break|break;
comment|/* EMS call, used by emsdriv.sys */
case|case
name|EMU_EMS
case|:
block|{
switch|switch
condition|(
name|subfunc
condition|)
block|{
case|case
name|EMU_EMS_CTL
case|:
name|R_AX
operator|=
operator|(
name|u_short
operator|)
name|ems_init
argument_list|()
expr_stmt|;
break|break;
case|case
name|EMU_EMS_CALL
case|:
name|ems_entry
argument_list|(
name|REGS
argument_list|)
expr_stmt|;
break|break;
default|default:
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"Undefined subfunction for EMS call\n"
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
block|}
default|default:
name|debug
argument_list|(
name|D_ALWAYS
argument_list|,
literal|"Emulator interrupt called with undefined function %02x\n"
argument_list|,
name|func
argument_list|)
expr_stmt|;
comment|/*               * XXX              * temporary backwards compatibility with instbsdi.exe              * remove after a while.              */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"***\n*** WARNING - unknown emuint function\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** Continuing; assuming instbsdi redirector.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** Please install the new redirector"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" `redir.com' as soon as possible.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** This compatibility hack is not permanent.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"***\n"
argument_list|)
expr_stmt|;
name|PUSH
argument_list|(
name|R_AX
argument_list|,
name|REGS
argument_list|)
expr_stmt|;
name|R_BX
operator|=
name|R_ES
expr_stmt|;
name|R_DX
operator|=
name|R_DI
expr_stmt|;
name|R_DI
operator|=
name|R_DS
expr_stmt|;
name|intff
argument_list|(
name|REGS
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

end_unit

