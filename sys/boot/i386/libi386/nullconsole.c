begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * nullconsole.c  *  * Copyright (c) 2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Doug Ambrisko<ambrisko@whistle.com>  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_function_decl
specifier|static
name|void
name|nullc_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|nullc_init
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|nullc_putchar
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|nullc_getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|nullc_ischar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|console
name|nullconsole
init|=
block|{
literal|"nullconsole"
block|,
literal|"null port"
block|,
literal|0
block|,
name|nullc_probe
block|,
name|nullc_init
block|,
name|nullc_putchar
block|,
name|nullc_getchar
block|,
name|nullc_ischar
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|nullc_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
block|{
name|cp
operator|->
name|c_flags
operator||=
operator|(
name|C_PRESENTIN
operator||
name|C_PRESENTOUT
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|nullc_init
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|nullc_putchar
parameter_list|(
name|int
name|c
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|int
name|nullc_getchar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|nullc_ischar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

