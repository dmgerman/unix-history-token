begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 08 Nov 1998*/
end_comment

begin_comment
comment|/*  * miscmod.c  *  * 08 Nov 1998  Rajesh Vaidheeswarran  - adapted from the lkm miscmod.c  *  * Copyright (c) 1998 Rajesh Vaidheeswarran  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Rajesh Vaidheeswarran.  * 4. The name Rajesh Vaidheeswarran may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY RAJESH VAIDHEESWARRAN ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE RAJESH VAIDHEESWARRAN BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * Copyright (c) 1993 Terrence R. Lambert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY TERRENCE R. LAMBERT ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/sysproto.h>
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|"misccall.h"
end_include

begin_comment
comment|/*  * These two entries define our system call and module information.  We  * have 0 arguments to our system call.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sysent
name|newent
init|=
block|{
literal|0
block|,
name|misccall
comment|/* # of args, function pointer*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Miscellaneous modules must have their own save areas...  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sysent
name|oldent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save area for old callslot entry*/
end_comment

begin_comment
comment|/*  * Number of syscall entries for a.out executables  */
end_comment

begin_define
define|#
directive|define
name|nsysent
value|(aout_sysvec.sv_size)
end_define

begin_comment
comment|/*  * If you have a data structure to pass ...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|misc_data
block|{
name|char
name|name
index|[
literal|20
index|]
decl_stmt|;
name|struct
name|sysent
modifier|*
name|nent
decl_stmt|;
name|struct
name|sysent
modifier|*
name|oent
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
name|misc_data_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|misc_data_t
name|misc_arg
init|=
block|{
literal|"misccall"
block|,
operator|&
name|newent
block|,
operator|&
name|oldent
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|misc_load
parameter_list|(
name|module_t
parameter_list|,
name|modeventtype_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|moduledata_t
name|misc_mod
init|=
block|{
literal|"misc_mod"
block|,
name|misc_load
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|misc_arg
comment|/* This is our real data */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This function is called each time the module is loaded or unloaded.  *  * For the system call table, we duplicate the code in the kern_lkm.c  * file for patching into the system call table.  We can tell what  * has been allocated, etc. by virtue of the fact that we know the  * criteria used by the system call loader interface.  We still  * kick out the copyright to the console here (to give an example).  */
end_comment

begin_function
specifier|static
name|int
name|misc_load
parameter_list|(
name|mod
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
name|module_t
name|mod
decl_stmt|;
name|modeventtype_t
name|cmd
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|int
name|i
decl_stmt|,
name|err
init|=
literal|0
decl_stmt|;
name|misc_data_t
modifier|*
name|args
init|=
operator|(
name|misc_data_t
operator|*
operator|)
name|arg
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|MOD_LOAD
case|:
comment|/* 	 * Search the table looking for a slot... 	 */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|nsysent
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|sysent
index|[
name|i
index|]
operator|.
name|sy_call
operator|==
operator|(
name|sy_call_t
operator|*
operator|)
name|nosys
condition|)
break|break;
comment|/* found it!*/
comment|/* out of allocable slots?*/
if|if
condition|(
name|i
operator|==
name|nsysent
condition|)
block|{
name|err
operator|=
name|ENFILE
expr_stmt|;
break|break;
block|}
comment|/* save old -- we must provide our own data area*/
name|bcopy
argument_list|(
operator|&
name|sysent
index|[
name|i
index|]
argument_list|,
name|args
operator|->
name|oent
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|sysent
argument_list|)
argument_list|)
expr_stmt|;
comment|/* replace with new*/
name|bcopy
argument_list|(
name|args
operator|->
name|nent
argument_list|,
operator|&
name|sysent
index|[
name|i
index|]
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|sysent
argument_list|)
argument_list|)
expr_stmt|;
comment|/* done!*/
name|args
operator|->
name|offset
operator|=
name|i
expr_stmt|;
comment|/* slot in sysent[]*/
comment|/* if we make it to here, print copyright on console*/
name|printf
argument_list|(
literal|"\nSample Loaded kld module (system call)\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Copyright (c) 1998\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Rajesh Vaidheeswarran\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"All rights reserved\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"System call %s loaded into slot %d\n"
argument_list|,
name|args
operator|->
name|name
argument_list|,
name|args
operator|->
name|offset
argument_list|)
expr_stmt|;
break|break;
comment|/* Success*/
case|case
name|MOD_UNLOAD
case|:
comment|/* current slot...*/
name|i
operator|=
name|args
operator|->
name|offset
expr_stmt|;
comment|/* replace current slot contents with old contents*/
name|bcopy
argument_list|(
name|args
operator|->
name|oent
argument_list|,
operator|&
name|sysent
index|[
name|i
index|]
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|sysent
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Unloaded kld module (system call)\n"
argument_list|)
expr_stmt|;
break|break;
comment|/* Success*/
default|default:
comment|/* we only understand load/unload*/
name|err
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Now declare the module to the system */
end_comment

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|misc
argument_list|,
name|misc_mod
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

