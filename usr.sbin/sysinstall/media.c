begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated to essentially a complete rewrite.  *  * $Id: media.c,v 1.2 1995/04/29 19:33:02 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Return 0 if we successfully found and set the installation type to  * be a CD.  */
end_comment

begin_function
name|int
name|mediaSetCDROM
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Return 0 if we successfully found and set the installation type to  * be a floppy  */
end_comment

begin_function
name|int
name|mediaSetFloppy
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Return 0 if we successfully found and set the installation type to  * be a DOS partition.  */
end_comment

begin_function
name|int
name|mediaSetDOS
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Return 0 if we successfully found and set the installation type to  * be a tape drive.  */
end_comment

begin_function
name|int
name|mediaSetTape
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Return 0 if we successfully found and set the installation type to  * be an ftp server  */
end_comment

begin_function
name|int
name|mediaSetFTP
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Return 0 if we successfully found and set the installation type to  * be some sort of mounted filesystem (it's also mounted at this point)  */
end_comment

begin_function
name|int
name|mediaSetFS
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

