begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Steven Wallace  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Steven Wallace.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_syscall.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_signal.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_ibcs2_errno
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sysent
name|ibcs2_sysent
index|[
name|IBCS2_SYS_MAXSYSCALL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|szsigcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sysentvec
name|ibcs2_svr3_sysvec
init|=
block|{
sizeof|sizeof
argument_list|(
name|ibcs2_sysent
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ibcs2_sysent
index|[
literal|0
index|]
argument_list|)
block|,
name|ibcs2_sysent
block|,
literal|0xFF
block|,
name|IBCS2_SIGTBLSZ
block|,
name|bsd_to_ibcs2_sig
block|,
name|ELAST
operator|+
literal|1
block|,
name|bsd_to_ibcs2_errno
block|,
literal|0
block|,
comment|/* trap-to-signal translation function */
literal|0
block|,
comment|/* fixup */
name|sendsig
block|,
name|sigcode
block|,
comment|/* use generic trampoline */
operator|&
name|szsigcode
block|,
comment|/* use generic trampoline size */
literal|0
block|,
comment|/* prepsyscall */
literal|"IBCS2 COFF"
block|,
name|NULL
block|,
comment|/* we don't have a COFF coredump function */
name|NULL
block|,
name|IBCS2_MINSIGSTKSZ
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Create an "ibcs2" module that does nothing but allow checking for  * the presence of the subsystem.  */
end_comment

begin_function
specifier|static
name|int
name|ibcs2_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|unused
parameter_list|)
block|{
name|struct
name|proc
modifier|*
name|p
init|=
name|NULL
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|MOD_UNLOAD
case|:
comment|/* if this was an ELF module we'd use elf_brand_inuse()... */
for|for
control|(
name|p
operator|=
name|allproc
operator|.
name|lh_first
init|;
name|p
operator|!=
literal|0
condition|;
name|p
operator|=
name|p
operator|->
name|p_list
operator|.
name|le_next
control|)
block|{
if|if
condition|(
name|p
operator|->
name|p_sysent
operator|==
operator|&
name|ibcs2_svr3_sysvec
condition|)
return|return
name|EBUSY
return|;
block|}
default|default:
comment|/* do not care */
block|}
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|moduledata_t
name|ibcs2_mod
init|=
block|{
literal|"ibcs2"
block|,
name|ibcs2_modevent
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|ibcs2
argument_list|,
name|ibcs2_mod
argument_list|,
name|SI_SUB_PSEUDO
argument_list|,
name|SI_ORDER_ANY
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

