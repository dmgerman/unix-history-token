begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 25 May 93*/
end_comment

begin_comment
comment|/*  * miscmod.c  *  * 05 Jun 93	Terry Lambert		Split mycall.c out  * 25 May 93	Terry Lambert		Original  *  * Copyright (c) 1993 Terrence R. Lambert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY TERRENCE R. LAMBERT ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
file|<sys/lkm.h>
end_include

begin_comment
comment|/* XXX this should be in a header. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|misccall
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|void
operator|*
name|uap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* save are for old callslot entry*/
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

begin_expr_stmt
name|MOD_MISC
argument_list|(
name|misc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This function is called each time the module is loaded or unloaded.  * Since we are a miscellaneous module, we have to provide whatever  * code is necessary to patch ourselves into the area we are being  * loaded to change.  *  * For the system call table, we duplicate the code in the kern_lkm.c  * file for patching into the system call table.  We can tell what  * has been allocated, etc. by virtue of the fact that we know the  * criteria used by the system call loader interface.  We still  * kick out the copyright to the console here (to give an example).  *  * The stat information is basically common to all modules, so there  * is no real issue involved with stat; we will leave it lkm_nullcmd(),  * cince we don't have to do anything about it.  */
end_comment

begin_function
specifier|static
name|int
name|misc_load
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|struct
name|lkm_misc
modifier|*
name|args
init|=
name|lkmtp
operator|->
name|private
operator|.
name|lkm_misc
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* default = success*/
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|LKM_E_LOAD
case|:
comment|/* 		 * Don't load twice! (lkmexists() is exported by kern_lkm.c) 		 */
if|if
condition|(
name|lkmexists
argument_list|(
name|lkmtp
argument_list|)
condition|)
return|return
operator|(
name|EEXIST
operator|)
return|;
comment|/* 		 * This is where we would express a slot preference if 		 * we had one; since we don't, we will simply duplicate 		 * the "auto" code and forget the other. 		 */
comment|/* 		 * Search the table looking for a slot... 		 */
for|for
control|(
name|i
operator|=
literal|0
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
name|lkmnosys
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
operator|&
name|oldent
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
operator|&
name|newent
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
name|lkm_offset
operator|=
name|i
expr_stmt|;
comment|/* slot in sysent[]*/
comment|/* if we make it to here, print copyright on console*/
name|printf
argument_list|(
literal|"\nSample Loaded miscellaneous module (system call)\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Copyright (c) 1993\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Terrence R. Lambert\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"All rights reserved\n"
argument_list|)
expr_stmt|;
break|break;
comment|/* Success*/
case|case
name|LKM_E_UNLOAD
case|:
comment|/* current slot...*/
name|i
operator|=
name|args
operator|->
name|lkm_offset
expr_stmt|;
comment|/* replace current slot contents with old contents*/
name|bcopy
argument_list|(
operator|&
name|oldent
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
comment|/*  * External entry point; should generally match name of .o file.  The  * arguments are always the same for all loaded modules.  The "load",  * "unload", and "stat" functions in "DISPATCH" will be called under  * their respective circumstances unless their value is "lkm_nullcmd".  If  * called, they are called with the same arguments (cmd is included to  * allow the use of a single function, ver is included for version  * matching between modules and the kernel loader for the modules).  *  * Since we expect to link in the kernel and add external symbols to  * the kernel symbol name space in a future version, generally all  * functions used in the implementation of a particular module should  * be static unless they are expected to be seen in other modules or  * to resolve unresolved symbols alread existing in the kernel (the  * second case is not likely to ever occur).  *  * The entry point should return 0 unless it is refusing load (in which  * case it should return an errno from errno.h).  */
end_comment

begin_function
name|int
name|misc_mod
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|,
name|ver
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|ver
decl_stmt|;
block|{
name|MOD_DISPATCH
argument_list|(
name|misc
argument_list|,
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|misc_load
argument_list|,
name|misc_load
argument_list|,
name|lkm_nullcmd
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

