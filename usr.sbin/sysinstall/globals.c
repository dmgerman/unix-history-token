begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $FreeBSD$  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
name|DebugFD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where diagnostic output goes */
end_comment

begin_decl_stmt
name|Boolean
name|Fake
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Only pretend to be useful */
end_comment

begin_decl_stmt
name|Boolean
name|RunningAsInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we running as init? */
end_comment

begin_decl_stmt
name|Boolean
name|DialogActive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is libdialog initialized? */
end_comment

begin_decl_stmt
name|Boolean
name|ColorDisplay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a color display? */
end_comment

begin_decl_stmt
name|Boolean
name|OnVTY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a VTY? */
end_comment

begin_decl_stmt
name|Boolean
name|Restarting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we restarting sysinstall? */
end_comment

begin_decl_stmt
name|Boolean
name|have_volumes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Media has more than one volume. */
end_comment

begin_decl_stmt
name|Variable
modifier|*
name|VarHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The head of the variable chain */
end_comment

begin_decl_stmt
name|Device
modifier|*
name|mediaDevice
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where we're installing from */
end_comment

begin_decl_stmt
name|int
name|BootMgr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which boot manager we're using */
end_comment

begin_decl_stmt
name|int
name|StatusLine
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where to stick our status messages */
end_comment

begin_decl_stmt
name|int
name|low_volume
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lowest volume number */
end_comment

begin_decl_stmt
name|int
name|high_volume
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highest volume number */
end_comment

begin_decl_stmt
name|jmp_buf
name|BailOut
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Beam me up, scotty! The natives are pissed! */
end_comment

begin_decl_stmt
name|Chunk
modifier|*
name|HomeChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Chunk
modifier|*
name|RootChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Chunk
modifier|*
name|SwapChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Chunk
modifier|*
name|TmpChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Chunk
modifier|*
name|UsrChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Chunk
modifier|*
name|VarChunk
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_decl_stmt
name|Chunk
modifier|*
name|EfiChunk
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|DebugFD
operator|=
operator|-
literal|1
expr_stmt|;
name|ColorDisplay
operator|=
name|FALSE
expr_stmt|;
name|Fake
operator|=
name|FALSE
expr_stmt|;
name|Restarting
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
name|mediaDevice
operator|=
name|NULL
expr_stmt|;
name|RunningAsInit
operator|=
name|FALSE
expr_stmt|;
name|HomeChunk
operator|=
name|NULL
expr_stmt|;
name|RootChunk
operator|=
name|NULL
expr_stmt|;
name|SwapChunk
operator|=
name|NULL
expr_stmt|;
name|TmpChunk
operator|=
name|NULL
expr_stmt|;
name|UsrChunk
operator|=
name|NULL
expr_stmt|;
name|VarChunk
operator|=
name|NULL
expr_stmt|;
ifdef|#
directive|ifdef
name|__ia64__
name|EfiChunk
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

