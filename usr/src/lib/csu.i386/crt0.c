begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)crt0.c	5.7 (Berkeley) 7/3/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  *	C start up routine.  *	Robert Henry, UCB, 20 Oct 81  *  *	We make the following (true) assumption:  *	1) The only register variable that we can trust is the frame pointer,  *	ebp, which points to the base of the kernel calling frame.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
init|=
operator|(
name|char
operator|*
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errno
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".long 0xc000c000");
end_asm

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|etext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|eprol
name|asm
argument_list|(
literal|"eprol"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern			start(
end_extern

begin_asm
unit|)
asm|asm("start");
end_asm

begin_extern
extern|extern			mcount(
end_extern

begin_asm
unit|)
asm|asm ("mcount");
end_asm

begin_macro
name|start
argument_list|()
end_macro

begin_block
block|{
struct|struct
name|kframe
block|{
name|int
name|kargc
decl_stmt|;
name|char
modifier|*
name|kargv
index|[
literal|1
index|]
decl_stmt|;
comment|/* size depends on kargc */
name|char
name|kargstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
name|char
name|kenvstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
block|}
struct|;
comment|/* 	 *	ALL REGISTER VARIABLES!!! 	 */
specifier|register
name|struct
name|kframe
modifier|*
name|kfp
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|targv
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
specifier|extern
name|void
name|_mcleanup
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|lint
name|kfp
operator|=
literal|0
expr_stmt|;
name|initcode
operator|=
name|initcode
operator|=
literal|0
expr_stmt|;
else|#
directive|else
else|not lint
comment|/* just above the saved frame pointer */
asm|asm ("lea 4(%%ebp), %0" : "=r" (kfp) );
endif|#
directive|endif
endif|not lint
for|for
control|(
name|argv
operator|=
name|targv
operator|=
operator|&
name|kfp
operator|->
name|kargv
index|[
literal|0
index|]
init|;
operator|*
name|targv
operator|++
condition|;
comment|/* void */
control|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|targv
operator|>=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
operator|*
name|argv
operator|)
condition|)
operator|--
name|targv
expr_stmt|;
name|environ
operator|=
name|targv
expr_stmt|;
asm|asm("eprol:");
ifdef|#
directive|ifdef
name|MCRT0
name|atexit
argument_list|(
name|_mcleanup
argument_list|)
expr_stmt|;
name|monstartup
argument_list|(
operator|&
name|eprol
argument_list|,
operator|&
name|etext
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|MCRT0
name|exit
argument_list|(
name|main
argument_list|(
name|kfp
operator|->
name|kargc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|CRT0
end_ifdef

begin_comment
comment|/*  * null mcount and moncontrol,  * just in case some routine is compiled for profiling  */
end_comment

begin_macro
name|moncontrol
argument_list|(
argument|val
argument_list|)
end_macro

begin_decl_stmt
name|int
name|val
decl_stmt|;
end_decl_stmt

begin_block
block|{  }
end_block

begin_macro
name|mcount
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_endif
endif|#
directive|endif
endif|CRT0
end_endif

end_unit

