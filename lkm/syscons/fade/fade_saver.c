begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<saver.h>
end_include

begin_macro
name|MOD_MISC
argument_list|(
literal|"fade_saver"
argument_list|)
end_macro

begin_function_decl
name|void
function_decl|(
modifier|*
name|current_saver
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|old_saver
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|fade_saver
parameter_list|(
name|int
name|blank
parameter_list|)
block|{
specifier|static
name|int
name|count
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|blank
condition|)
block|{
name|scrn_blanked
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|count
operator|<
literal|64
condition|)
block|{
name|outb
argument_list|(
name|PIXMASK
argument_list|,
literal|0xFF
argument_list|)
expr_stmt|;
comment|/* no pixelmask */
name|outb
argument_list|(
name|PALWADR
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|PALDATA
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|PALDATA
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|PALDATA
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|3
init|;
name|i
operator|<
literal|768
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|palette
index|[
name|i
index|]
operator|-
name|count
operator|>
literal|15
condition|)
name|outb
argument_list|(
name|PALDATA
argument_list|,
name|palette
index|[
name|i
index|]
operator|-
name|count
argument_list|)
expr_stmt|;
else|else
name|outb
argument_list|(
name|PALDATA
argument_list|,
literal|15
argument_list|)
expr_stmt|;
block|}
name|inb
argument_list|(
name|crtc_addr
operator|+
literal|6
argument_list|)
expr_stmt|;
comment|/* reset flip/flop */
name|outb
argument_list|(
name|ATC
argument_list|,
literal|0x20
argument_list|)
expr_stmt|;
comment|/* enable palette */
name|count
operator|++
expr_stmt|;
block|}
block|}
else|else
block|{
name|load_palette
argument_list|()
expr_stmt|;
name|count
operator|=
name|scrn_blanked
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_macro
name|saver_load
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|)
end_macro

begin_block
block|{
call|(
modifier|*
name|current_saver
call|)
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|old_saver
operator|=
name|current_saver
expr_stmt|;
name|current_saver
operator|=
name|fade_saver
expr_stmt|;
name|uprintf
argument_list|(
literal|"fade screen saver installed\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|saver_unload
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|)
end_macro

begin_block
block|{
call|(
modifier|*
name|current_saver
call|)
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|current_saver
operator|=
name|old_saver
expr_stmt|;
name|uprintf
argument_list|(
literal|"fade screen saver removed\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|saver_init
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|,
argument|int ver
argument_list|)
end_macro

begin_block
block|{
name|DISPATCH
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|saver_load
argument_list|,
name|saver_unload
argument_list|,
name|nosys
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

