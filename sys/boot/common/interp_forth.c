begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* to pick up __FreeBSD_version */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_include
include|#
directive|include
file|"ficl.h"
end_include

begin_decl_stmt
specifier|extern
name|char
name|bootprog_rev
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #define BFORTH_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFORTH_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: " fmt "\n" , __func__ , ## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Eventually, all builtin commands throw codes must be defined  * elsewhere, possibly bootstrap.h. For now, just this code, used  * just in this file, it is getting defined.  */
end_comment

begin_define
define|#
directive|define
name|BF_PARSE
value|100
end_define

begin_comment
comment|/*  * BootForth   Interface to Ficl Forth interpreter.  */
end_comment

begin_decl_stmt
name|FICL_SYSTEM
modifier|*
name|bf_sys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FICL_VM
modifier|*
name|bf_vm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FICL_WORD
modifier|*
name|pInterp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Shim for taking commands from BF and passing them out to 'standard'  * argv/argc command functions.  */
end_comment

begin_function
specifier|static
name|void
name|bf_command
parameter_list|(
name|FICL_VM
modifier|*
name|vm
parameter_list|)
block|{
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|line
decl_stmt|,
modifier|*
name|tail
decl_stmt|,
modifier|*
name|cp
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|struct
name|bootblk_command
modifier|*
modifier|*
name|cmdp
decl_stmt|;
name|bootblk_cmd_t
modifier|*
name|cmd
decl_stmt|;
name|int
name|nstrings
decl_stmt|,
name|i
decl_stmt|;
name|int
name|argc
decl_stmt|,
name|result
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* Get the name of the current word */
name|name
operator|=
name|vm
operator|->
name|runningWord
operator|->
name|name
expr_stmt|;
comment|/* Find our command structure */
name|cmd
operator|=
name|NULL
expr_stmt|;
name|SET_FOREACH
argument_list|(
argument|cmdp
argument_list|,
argument|Xcommand_set
argument_list|)
block|{
if|if
condition|(
operator|(
operator|(
operator|*
name|cmdp
operator|)
operator|->
name|c_name
operator|!=
name|NULL
operator|)
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
operator|(
operator|*
name|cmdp
operator|)
operator|->
name|c_name
argument_list|)
condition|)
name|cmd
operator|=
operator|(
operator|*
name|cmdp
operator|)
operator|->
name|c_fn
expr_stmt|;
block|}
if|if
condition|(
name|cmd
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"callout for unknown command '%s'"
argument_list|,
name|name
argument_list|)
expr_stmt|;
comment|/* Check whether we have been compiled or are being interpreted */
if|if
condition|(
name|stackPopINT
argument_list|(
name|vm
operator|->
name|pStack
argument_list|)
condition|)
block|{
comment|/* 	 * Get parameters from stack, in the format: 	 * an un ... a2 u2 a1 u1 n -- 	 * Where n is the number of strings, a/u are pairs of 	 * address/size for strings, and they will be concatenated 	 * in LIFO order. 	 */
name|nstrings
operator|=
name|stackPopINT
argument_list|(
name|vm
operator|->
name|pStack
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|len
operator|=
literal|0
init|;
name|i
operator|<
name|nstrings
condition|;
name|i
operator|++
control|)
name|len
operator|+=
name|stackFetch
argument_list|(
name|vm
operator|->
name|pStack
argument_list|,
name|i
operator|*
literal|2
argument_list|)
operator|.
name|i
operator|+
literal|1
expr_stmt|;
name|line
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|name
argument_list|)
operator|+
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|line
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|nstrings
condition|)
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nstrings
condition|;
name|i
operator|++
control|)
block|{
name|len
operator|=
name|stackPopINT
argument_list|(
name|vm
operator|->
name|pStack
argument_list|)
expr_stmt|;
name|cp
operator|=
name|stackPopPtr
argument_list|(
name|vm
operator|->
name|pStack
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|line
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|strncat
argument_list|(
name|line
argument_list|,
name|cp
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Get remainder of invocation */
name|tail
operator|=
name|vmGetInBuf
argument_list|(
name|vm
argument_list|)
expr_stmt|;
for|for
control|(
name|cp
operator|=
name|tail
operator|,
name|len
operator|=
literal|0
init|;
name|cp
operator|!=
name|vm
operator|->
name|tib
operator|.
name|end
operator|&&
operator|*
name|cp
operator|!=
literal|0
operator|&&
operator|*
name|cp
operator|!=
literal|'\n'
condition|;
name|cp
operator|++
operator|,
name|len
operator|++
control|)
empty_stmt|;
name|line
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|name
argument_list|)
operator|+
name|len
operator|+
literal|2
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|line
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|strcat
argument_list|(
name|line
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|strncat
argument_list|(
name|line
argument_list|,
name|tail
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|vmUpdateTib
argument_list|(
name|vm
argument_list|,
name|tail
operator|+
name|len
argument_list|)
expr_stmt|;
block|}
block|}
name|DEBUG
argument_list|(
literal|"cmd '%s'"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|command_errmsg
operator|=
name|command_errbuf
expr_stmt|;
name|command_errbuf
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|parse
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|,
name|line
argument_list|)
condition|)
block|{
name|result
operator|=
call|(
name|cmd
call|)
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|argv
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|=
name|BF_PARSE
expr_stmt|;
block|}
name|free
argument_list|(
name|line
argument_list|)
expr_stmt|;
comment|/* This is going to be thrown!!! */
name|stackPushINT
argument_list|(
name|vm
operator|->
name|pStack
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Replace a word definition (a builtin command) with another  * one that:  *  *        - Throw error results instead of returning them on the stack  *        - Pass a flag indicating whether the word was compiled or is  *          being interpreted.  *  * There is one major problem with builtins that cannot be overcome  * in anyway, except by outlawing it. We want builtins to behave  * differently depending on whether they have been compiled or they  * are being interpreted. Notice that this is *not* the interpreter's  * current state. For example:  *  * : example ls ; immediate  * : problem example ;		\ "ls" gets executed while compiling  * example			\ "ls" gets executed while interpreting  *  * Notice that, though the current state is different in the two  * invocations of "example", in both cases "ls" has been  * *compiled in*, which is what we really want.  *  * The problem arises when you tick the builtin. For example:  *  * : example-1 ['] ls postpone literal ; immediate  * : example-2 example-1 execute ; immediate  * : problem example-2 ;  * example-2  *  * We have no way, when we get EXECUTEd, of knowing what our behavior  * should be. Thus, our only alternative is to "outlaw" this. See RFI  * 0007, and ANS Forth Standard's appendix D, item 6.7 for a related  * problem, concerning compile semantics.  *  * The problem is compounded by the fact that "' builtin CATCH" is valid  * and desirable. The only solution is to create an intermediary word.  * For example:  *  * : my-ls ls ;  * : example ['] my-ls catch ;  *  * So, with the below implementation, here is a summary of the behavior  * of builtins:  *  * ls -l				\ "interpret" behavior, ie,  *					\ takes parameters from TIB  * : ex-1 s" -l" 1 ls ;			\ "compile" behavior, ie,  *					\ takes parameters from the stack  * : ex-2 ['] ls catch ; immediate	\ undefined behavior  * : ex-3 ['] ls catch ;		\ undefined behavior  * ex-2 ex-3				\ "interpret" behavior,  *					\ catch works  * : ex-4 ex-2 ;			\ "compile" behavior,  *					\ catch does not work  * : ex-5 ex-3 ; immediate		\ same as ex-2  * : ex-6 ex-3 ;			\ same as ex-3  * : ex-7 ['] ex-1 catch ;		\ "compile" behavior,  *					\ catch works  * : ex-8 postpone ls ;	immediate	\ same as ex-2  * : ex-9 postpone ls ;			\ same as ex-3  *  * As the definition below is particularly tricky, and it's side effects  * must be well understood by those playing with it, I'll be heavy on  * the comments.  *  * (if you edit this definition, pay attention to trailing spaces after  *  each word -- I warned you! :-) )  */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_CONSTRUCTOR
define|\
value|": builtin: "		\   ">in @ "
comment|/* save the tib index pointer */
value|\   "' "
comment|/* get next word's xt */
value|\   "swap>in ! "
comment|/* point again to next word */
value|\   "create "
comment|/* create a new definition of the next word */
value|\   ", "
comment|/* save previous definition's xt */
value|\   "immediate "
comment|/* make the new definition an immediate word */
value|\ 			\   "does> "
comment|/* Now, the *new* definition will: */
value|\   "state @ if "
comment|/* if in compiling state: */
value|\     "1 postpone literal "
comment|/* pass 1 flag to indicate compile */
value|\     "@ compile, "
comment|/* compile in previous definition */
value|\     "postpone throw "
comment|/* throw stack-returned result */
value|\   "else "
comment|/* if in interpreting state: */
value|\     "0 swap "
comment|/* pass 0 flag to indicate interpret */
value|\     "@ execute "
comment|/* call previous definition */
value|\     "throw "
comment|/* throw stack-returned result */
value|\   "then ; "
end_define

begin_comment
comment|/*  * Initialise the Forth interpreter, create all our commands as words.  */
end_comment

begin_function
name|void
name|bf_init
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|bootblk_command
modifier|*
modifier|*
name|cmdp
decl_stmt|;
name|char
name|create_buf
index|[
literal|41
index|]
decl_stmt|;
comment|/* 31 characters-long builtins */
name|int
name|fd
decl_stmt|;
name|bf_sys
operator|=
name|ficlInitSystem
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
comment|/* Default dictionary ~4000 cells */
name|bf_vm
operator|=
name|ficlNewVM
argument_list|(
name|bf_sys
argument_list|)
expr_stmt|;
comment|/* Put all private definitions in a "builtins" vocabulary */
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
literal|"vocabulary builtins also builtins definitions"
argument_list|)
expr_stmt|;
comment|/* Builtin constructor word  */
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
name|BUILTIN_CONSTRUCTOR
argument_list|)
expr_stmt|;
comment|/* make all commands appear as Forth words */
name|SET_FOREACH
argument_list|(
argument|cmdp
argument_list|,
argument|Xcommand_set
argument_list|)
block|{
name|ficlBuild
argument_list|(
name|bf_sys
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
operator|*
name|cmdp
operator|)
operator|->
name|c_name
argument_list|,
name|bf_command
argument_list|,
name|FW_DEFAULT
argument_list|)
expr_stmt|;
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
literal|"forth definitions builtins"
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|create_buf
argument_list|,
literal|"builtin: %s"
argument_list|,
operator|(
operator|*
name|cmdp
operator|)
operator|->
name|c_name
argument_list|)
expr_stmt|;
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
name|create_buf
argument_list|)
expr_stmt|;
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
literal|"builtins definitions"
argument_list|)
expr_stmt|;
block|}
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
literal|"only forth definitions"
argument_list|)
expr_stmt|;
comment|/* Export some version numbers so that code can detect the loader/host version */
name|ficlSetEnv
argument_list|(
name|bf_sys
argument_list|,
literal|"FreeBSD_version"
argument_list|,
name|__FreeBSD_version
argument_list|)
expr_stmt|;
name|ficlSetEnv
argument_list|(
name|bf_sys
argument_list|,
literal|"loader_version"
argument_list|,
operator|(
name|bootprog_rev
index|[
literal|0
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|10
operator|+
operator|(
name|bootprog_rev
index|[
literal|2
index|]
operator|-
literal|'0'
operator|)
argument_list|)
expr_stmt|;
comment|/* try to load and run init file if present */
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
literal|"/boot/boot.4th"
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|ficlExecFD
argument_list|(
name|bf_vm
argument_list|,
name|fd
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
comment|/* Do this last, so /boot/boot.4th can change it */
name|pInterp
operator|=
name|ficlLookup
argument_list|(
name|bf_sys
argument_list|,
literal|"interpret"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Feed a line of user input to the Forth interpreter  */
end_comment

begin_function
name|int
name|bf_run
parameter_list|(
name|char
modifier|*
name|line
parameter_list|)
block|{
name|int
name|result
decl_stmt|;
name|result
operator|=
name|ficlExec
argument_list|(
name|bf_vm
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
literal|"ficlExec '%s' = %d"
argument_list|,
name|line
argument_list|,
name|result
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|result
condition|)
block|{
case|case
name|VM_OUTOFTEXT
case|:
case|case
name|VM_ABORTQ
case|:
case|case
name|VM_QUIT
case|:
case|case
name|VM_ERREXIT
case|:
break|break;
case|case
name|VM_USEREXIT
case|:
name|printf
argument_list|(
literal|"No where to leave to!\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|VM_ABORT
case|:
name|printf
argument_list|(
literal|"Aborted!\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|BF_PARSE
case|:
name|printf
argument_list|(
literal|"Parse error!\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* Hopefully, all other codes filled this buffer */
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|command_errmsg
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|result
operator|==
name|VM_USEREXIT
condition|)
name|panic
argument_list|(
literal|"interpreter exit"
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"interpret"
argument_list|,
name|bf_vm
operator|->
name|state
condition|?
literal|""
else|:
literal|"OK"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

