begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id: globals.c,v 1.3 1995/05/08 21:39:36 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_comment
comment|/*  * Various global variables and an initialization hook to set them to  * whatever values we feel are appropriate.  */
end_comment

begin_decl_stmt
name|int
name|CpioFD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The file descriptor for our CPIO floppy */
end_comment

begin_decl_stmt
name|int
name|DebugFD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where diagnostic output goes */
end_comment

begin_decl_stmt
name|Boolean
name|OnCDROM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we running off of a CDROM? */
end_comment

begin_decl_stmt
name|Boolean
name|OnSerial
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a serial console? */
end_comment

begin_decl_stmt
name|Boolean
name|DialogActive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|ColorDisplay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|OnVTY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Variable
modifier|*
name|VarHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The head of the variable chain */
end_comment

begin_comment
comment|/*  * Yes, I know some of these are already automatically initialized as  * globals.  I simply find it clearer to set everything explicitly.  */
end_comment

begin_function
name|void
name|globalsInit
parameter_list|(
name|void
parameter_list|)
block|{
name|CpioFD
operator|=
operator|-
literal|1
expr_stmt|;
name|DebugFD
operator|=
operator|-
literal|1
expr_stmt|;
name|OnCDROM
operator|=
name|FALSE
expr_stmt|;
name|OnSerial
operator|=
name|FALSE
expr_stmt|;
name|ColorDisplay
operator|=
name|FALSE
expr_stmt|;
name|OnVTY
operator|=
name|FALSE
expr_stmt|;
name|DialogActive
operator|=
name|FALSE
expr_stmt|;
name|VarHead
operator|=
name|NULL
expr_stmt|;
name|MediaType
operator|=
name|DEVICE_TYPE_NONE
expr_stmt|;
name|MediaDevice
operator|=
name|NULL
expr_stmt|;
block|}
end_function

end_unit

