begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)PCSTART.c	1.10 (Berkeley) 5/29/90"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"libpc.h"
end_include

begin_comment
comment|/*  * program variables  */
end_comment

begin_decl_stmt
name|struct
name|display
name|_disply
index|[
name|MAXLVL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|_stlim
init|=
literal|500000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|_stcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|_seed
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|_minptr
init|=
operator|(
name|char
operator|*
operator|)
literal|0x7fffffff
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|_minptr
init|=
operator|(
name|char
operator|*
operator|)
literal|0xffff
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_decl_stmt
name|char
modifier|*
name|_maxptr
init|=
operator|(
name|char
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * file record variables  */
end_comment

begin_decl_stmt
name|long
name|_filefre
init|=
name|PREDEF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iorechd
name|_fchain
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* only use fchain field */
name|INPUT
comment|/* fchain  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iorec
modifier|*
name|_actfile
index|[
name|MAXFILES
index|]
init|=
block|{
name|INPUT
block|,
name|OUTPUT
block|,
name|ERR
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * standard files  */
end_comment

begin_decl_stmt
name|char
name|_inwin
decl_stmt|,
name|_outwin
decl_stmt|,
name|_errwin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iorechd
name|input
init|=
block|{
operator|&
name|_inwin
block|,
comment|/* fileptr */
literal|0
block|,
comment|/* lcount  */
literal|0x7fffffff
block|,
comment|/* llimit  */
name|stdin
block|,
comment|/* fbuf    */
name|OUTPUT
block|,
comment|/* fchain  */
name|STDLVL
block|,
comment|/* flev    */
literal|"standard input"
block|,
comment|/* pfname  */
name|FTEXT
operator||
name|FREAD
operator||
name|SYNC
operator||
name|EOLN
block|,
comment|/* funit   */
literal|0
block|,
comment|/* fblk    */
literal|1
comment|/* fsize   */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iorechd
name|output
init|=
block|{
operator|&
name|_outwin
block|,
comment|/* fileptr */
literal|0
block|,
comment|/* lcount  */
literal|0x7fffffff
block|,
comment|/* llimit  */
name|stdout
block|,
comment|/* fbuf    */
name|ERR
block|,
comment|/* fchain  */
name|STDLVL
block|,
comment|/* flev    */
literal|"standard output"
block|,
comment|/* pfname  */
name|FTEXT
operator||
name|FWRITE
operator||
name|EOFF
block|,
comment|/* funit   */
literal|1
block|,
comment|/* fblk    */
literal|1
comment|/* fsize   */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iorechd
name|_err
init|=
block|{
operator|&
name|_errwin
block|,
comment|/* fileptr */
literal|0
block|,
comment|/* lcount  */
literal|0x7fffffff
block|,
comment|/* llimit  */
name|stderr
block|,
comment|/* fbuf    */
name|FILNIL
block|,
comment|/* fchain  */
name|STDLVL
block|,
comment|/* flev    */
literal|"Message file"
block|,
comment|/* pfname  */
name|FTEXT
operator||
name|FWRITE
operator||
name|EOFF
block|,
comment|/* funit   */
literal|2
block|,
comment|/* fblk    */
literal|1
comment|/* fsize   */
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|PCSTART
argument_list|(
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * necessary only on systems which do not initialize 	 * memory to zero 	 */
name|struct
name|iorec
modifier|*
modifier|*
name|ip
decl_stmt|;
comment|/* 	 * if running with runtime tests enabled, give more 	 * coherent error messages for FPEs 	 */
if|if
condition|(
name|mode
condition|)
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|EXCEPT
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|ip
operator|=
operator|&
name|_actfile
index|[
literal|3
index|]
init|;
name|ip
operator|<
operator|&
name|_actfile
index|[
name|MAXFILES
index|]
condition|;
operator|*
name|ip
operator|++
operator|=
name|FILNIL
control|)
empty_stmt|;
block|}
end_block

end_unit

