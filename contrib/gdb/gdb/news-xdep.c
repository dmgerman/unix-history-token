begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Low level interface to ptrace, for GDB when running under Unix.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/* Bad implement execle(3). It's depend for "/bin/cc".     main()    {      printf("execle:\n");      execle(FILE, ARGS, envp);      exit(1);    }     GCC:    link a6,#0    pea LC5	; call printf    jbsr _printf    ;		; (not popd stack)    pea _envp	; call execle    clrl sp@-    pea LC4    pea LC4    pea LC4    pea LC3    pea LC6    jbsr _execle    addw #32,sp	; delayed pop !!     /bin/cc:    link.l	fp,#L23    movem.l	#L24,(sp)    pea	L26		; call printf    jbsr	_printf    addq.l	#4,sp	;<--- popd stack !!    pea	_envp		; call execle    clr.l	-(sp)    pea	L32        */
end_comment

begin_macro
name|execle
argument_list|(
argument|name
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
modifier|*
name|env
init|=
operator|&
name|args
decl_stmt|;
while|while
condition|(
operator|*
name|env
operator|++
condition|)
empty_stmt|;
name|execve
argument_list|(
name|name
argument_list|,
operator|(
name|char
operator|*
operator|*
operator|)
operator|&
name|args
argument_list|,
operator|(
name|char
operator|*
operator|*
operator|)
operator|*
name|env
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

