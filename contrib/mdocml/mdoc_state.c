begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: mdoc_state.c,v 1.8 2017/05/05 15:17:32 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2014, 2015, 2017 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"mandoc.h"
end_include

begin_include
include|#
directive|include
file|"roff.h"
end_include

begin_include
include|#
directive|include
file|"mdoc.h"
end_include

begin_include
include|#
directive|include
file|"libmandoc.h"
end_include

begin_include
include|#
directive|include
file|"libmdoc.h"
end_include

begin_define
define|#
directive|define
name|STATE_ARGS
value|struct roff_man *mdoc, struct roff_node *n
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|state_handler
function_decl|)
parameter_list|(
name|STATE_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|static
name|void
name|state_bd
parameter_list|(
name|STATE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|state_bl
parameter_list|(
name|STATE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|state_dl
parameter_list|(
name|STATE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|state_sh
parameter_list|(
name|STATE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|state_sm
parameter_list|(
name|STATE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
specifier|const
name|state_handler
name|__state_handlers
index|[
name|MDOC_MAX
operator|-
name|MDOC_Dd
index|]
init|=
block|{
name|NULL
block|,
comment|/* Dd */
name|NULL
block|,
comment|/* Dt */
name|NULL
block|,
comment|/* Os */
name|state_sh
block|,
comment|/* Sh */
name|NULL
block|,
comment|/* Ss */
name|NULL
block|,
comment|/* Pp */
name|NULL
block|,
comment|/* D1 */
name|state_dl
block|,
comment|/* Dl */
name|state_bd
block|,
comment|/* Bd */
name|NULL
block|,
comment|/* Ed */
name|state_bl
block|,
comment|/* Bl */
name|NULL
block|,
comment|/* El */
name|NULL
block|,
comment|/* It */
name|NULL
block|,
comment|/* Ad */
name|NULL
block|,
comment|/* An */
name|NULL
block|,
comment|/* Ap */
name|NULL
block|,
comment|/* Ar */
name|NULL
block|,
comment|/* Cd */
name|NULL
block|,
comment|/* Cm */
name|NULL
block|,
comment|/* Dv */
name|NULL
block|,
comment|/* Er */
name|NULL
block|,
comment|/* Ev */
name|NULL
block|,
comment|/* Ex */
name|NULL
block|,
comment|/* Fa */
name|NULL
block|,
comment|/* Fd */
name|NULL
block|,
comment|/* Fl */
name|NULL
block|,
comment|/* Fn */
name|NULL
block|,
comment|/* Ft */
name|NULL
block|,
comment|/* Ic */
name|NULL
block|,
comment|/* In */
name|NULL
block|,
comment|/* Li */
name|NULL
block|,
comment|/* Nd */
name|NULL
block|,
comment|/* Nm */
name|NULL
block|,
comment|/* Op */
name|NULL
block|,
comment|/* Ot */
name|NULL
block|,
comment|/* Pa */
name|NULL
block|,
comment|/* Rv */
name|NULL
block|,
comment|/* St */
name|NULL
block|,
comment|/* Va */
name|NULL
block|,
comment|/* Vt */
name|NULL
block|,
comment|/* Xr */
name|NULL
block|,
comment|/* %A */
name|NULL
block|,
comment|/* %B */
name|NULL
block|,
comment|/* %D */
name|NULL
block|,
comment|/* %I */
name|NULL
block|,
comment|/* %J */
name|NULL
block|,
comment|/* %N */
name|NULL
block|,
comment|/* %O */
name|NULL
block|,
comment|/* %P */
name|NULL
block|,
comment|/* %R */
name|NULL
block|,
comment|/* %T */
name|NULL
block|,
comment|/* %V */
name|NULL
block|,
comment|/* Ac */
name|NULL
block|,
comment|/* Ao */
name|NULL
block|,
comment|/* Aq */
name|NULL
block|,
comment|/* At */
name|NULL
block|,
comment|/* Bc */
name|NULL
block|,
comment|/* Bf */
name|NULL
block|,
comment|/* Bo */
name|NULL
block|,
comment|/* Bq */
name|NULL
block|,
comment|/* Bsx */
name|NULL
block|,
comment|/* Bx */
name|NULL
block|,
comment|/* Db */
name|NULL
block|,
comment|/* Dc */
name|NULL
block|,
comment|/* Do */
name|NULL
block|,
comment|/* Dq */
name|NULL
block|,
comment|/* Ec */
name|NULL
block|,
comment|/* Ef */
name|NULL
block|,
comment|/* Em */
name|NULL
block|,
comment|/* Eo */
name|NULL
block|,
comment|/* Fx */
name|NULL
block|,
comment|/* Ms */
name|NULL
block|,
comment|/* No */
name|NULL
block|,
comment|/* Ns */
name|NULL
block|,
comment|/* Nx */
name|NULL
block|,
comment|/* Ox */
name|NULL
block|,
comment|/* Pc */
name|NULL
block|,
comment|/* Pf */
name|NULL
block|,
comment|/* Po */
name|NULL
block|,
comment|/* Pq */
name|NULL
block|,
comment|/* Qc */
name|NULL
block|,
comment|/* Ql */
name|NULL
block|,
comment|/* Qo */
name|NULL
block|,
comment|/* Qq */
name|NULL
block|,
comment|/* Re */
name|NULL
block|,
comment|/* Rs */
name|NULL
block|,
comment|/* Sc */
name|NULL
block|,
comment|/* So */
name|NULL
block|,
comment|/* Sq */
name|state_sm
block|,
comment|/* Sm */
name|NULL
block|,
comment|/* Sx */
name|NULL
block|,
comment|/* Sy */
name|NULL
block|,
comment|/* Tn */
name|NULL
block|,
comment|/* Ux */
name|NULL
block|,
comment|/* Xc */
name|NULL
block|,
comment|/* Xo */
name|NULL
block|,
comment|/* Fo */
name|NULL
block|,
comment|/* Fc */
name|NULL
block|,
comment|/* Oo */
name|NULL
block|,
comment|/* Oc */
name|NULL
block|,
comment|/* Bk */
name|NULL
block|,
comment|/* Ek */
name|NULL
block|,
comment|/* Bt */
name|NULL
block|,
comment|/* Hf */
name|NULL
block|,
comment|/* Fr */
name|NULL
block|,
comment|/* Ud */
name|NULL
block|,
comment|/* Lb */
name|NULL
block|,
comment|/* Lp */
name|NULL
block|,
comment|/* Lk */
name|NULL
block|,
comment|/* Mt */
name|NULL
block|,
comment|/* Brq */
name|NULL
block|,
comment|/* Bro */
name|NULL
block|,
comment|/* Brc */
name|NULL
block|,
comment|/* %C */
name|NULL
block|,
comment|/* Es */
name|NULL
block|,
comment|/* En */
name|NULL
block|,
comment|/* Dx */
name|NULL
block|,
comment|/* %Q */
name|NULL
block|,
comment|/* %U */
name|NULL
block|,
comment|/* Ta */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|state_handler
modifier|*
specifier|const
name|state_handlers
init|=
name|__state_handlers
operator|-
name|MDOC_Dd
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|mdoc_state
parameter_list|(
name|struct
name|roff_man
modifier|*
name|mdoc
parameter_list|,
name|struct
name|roff_node
modifier|*
name|n
parameter_list|)
block|{
name|state_handler
name|handler
decl_stmt|;
if|if
condition|(
name|n
operator|->
name|tok
operator|==
name|TOKEN_NONE
operator|||
name|n
operator|->
name|tok
operator|<
name|ROFF_MAX
condition|)
return|return;
name|assert
argument_list|(
name|n
operator|->
name|tok
operator|>=
name|MDOC_Dd
operator|&&
name|n
operator|->
name|tok
operator|<
name|MDOC_MAX
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|mdoc_macros
index|[
name|n
operator|->
name|tok
index|]
operator|.
name|flags
operator|&
name|MDOC_PROLOGUE
operator|)
condition|)
name|mdoc
operator|->
name|flags
operator||=
name|MDOC_PBODY
expr_stmt|;
name|handler
operator|=
name|state_handlers
index|[
name|n
operator|->
name|tok
index|]
expr_stmt|;
if|if
condition|(
operator|*
name|handler
condition|)
call|(
modifier|*
name|handler
call|)
argument_list|(
name|mdoc
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|mdoc_state_reset
parameter_list|(
name|struct
name|roff_man
modifier|*
name|mdoc
parameter_list|)
block|{
name|roff_setreg
argument_list|(
name|mdoc
operator|->
name|roff
argument_list|,
literal|"nS"
argument_list|,
literal|0
argument_list|,
literal|'='
argument_list|)
expr_stmt|;
name|mdoc
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|state_bd
parameter_list|(
name|STATE_ARGS
parameter_list|)
block|{
name|enum
name|mdocargt
name|arg
decl_stmt|;
if|if
condition|(
name|n
operator|->
name|type
operator|!=
name|ROFFT_HEAD
operator|&&
operator|(
name|n
operator|->
name|type
operator|!=
name|ROFFT_BODY
operator|||
name|n
operator|->
name|end
operator|!=
name|ENDBODY_NOT
operator|)
condition|)
return|return;
if|if
condition|(
name|n
operator|->
name|parent
operator|->
name|args
operator|==
name|NULL
condition|)
return|return;
name|arg
operator|=
name|n
operator|->
name|parent
operator|->
name|args
operator|->
name|argv
index|[
literal|0
index|]
operator|.
name|arg
expr_stmt|;
if|if
condition|(
name|arg
operator|!=
name|MDOC_Literal
operator|&&
name|arg
operator|!=
name|MDOC_Unfilled
condition|)
return|return;
name|state_dl
argument_list|(
name|mdoc
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|state_bl
parameter_list|(
name|STATE_ARGS
parameter_list|)
block|{
if|if
condition|(
name|n
operator|->
name|type
operator|!=
name|ROFFT_HEAD
operator|||
name|n
operator|->
name|parent
operator|->
name|args
operator|==
name|NULL
condition|)
return|return;
switch|switch
condition|(
name|n
operator|->
name|parent
operator|->
name|args
operator|->
name|argv
index|[
literal|0
index|]
operator|.
name|arg
condition|)
block|{
case|case
name|MDOC_Diag
case|:
name|n
operator|->
name|norm
operator|->
name|Bl
operator|.
name|type
operator|=
name|LIST_diag
expr_stmt|;
break|break;
case|case
name|MDOC_Column
case|:
name|n
operator|->
name|norm
operator|->
name|Bl
operator|.
name|type
operator|=
name|LIST_column
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|state_dl
parameter_list|(
name|STATE_ARGS
parameter_list|)
block|{
switch|switch
condition|(
name|n
operator|->
name|type
condition|)
block|{
case|case
name|ROFFT_HEAD
case|:
name|mdoc
operator|->
name|flags
operator||=
name|MDOC_LITERAL
expr_stmt|;
break|break;
case|case
name|ROFFT_BODY
case|:
name|mdoc
operator|->
name|flags
operator|&=
operator|~
name|MDOC_LITERAL
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|state_sh
parameter_list|(
name|STATE_ARGS
parameter_list|)
block|{
name|struct
name|roff_node
modifier|*
name|nch
decl_stmt|;
name|char
modifier|*
name|secname
decl_stmt|;
if|if
condition|(
name|n
operator|->
name|type
operator|!=
name|ROFFT_HEAD
condition|)
return|return;
if|if
condition|(
operator|!
operator|(
name|n
operator|->
name|flags
operator|&
name|NODE_VALID
operator|)
condition|)
block|{
name|secname
operator|=
name|NULL
expr_stmt|;
name|deroff
argument_list|(
operator|&
name|secname
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|/* 		 * Set the section attribute for the BLOCK, HEAD, 		 * and HEAD children; the latter can only be TEXT 		 * nodes, so no recursion is needed.  For other 		 * nodes, including the .Sh BODY, this is done 		 * when allocating the node data structures, but 		 * for .Sh BLOCK and HEAD, the section is still 		 * unknown at that time. 		 */
name|n
operator|->
name|sec
operator|=
name|n
operator|->
name|parent
operator|->
name|sec
operator|=
name|secname
operator|==
name|NULL
condition|?
name|SEC_CUSTOM
else|:
name|mdoc_a2sec
argument_list|(
name|secname
argument_list|)
expr_stmt|;
for|for
control|(
name|nch
operator|=
name|n
operator|->
name|child
init|;
name|nch
operator|!=
name|NULL
condition|;
name|nch
operator|=
name|nch
operator|->
name|next
control|)
name|nch
operator|->
name|sec
operator|=
name|n
operator|->
name|sec
expr_stmt|;
name|free
argument_list|(
name|secname
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|mdoc
operator|->
name|lastsec
operator|=
name|n
operator|->
name|sec
operator|)
operator|==
name|SEC_SYNOPSIS
condition|)
block|{
name|roff_setreg
argument_list|(
name|mdoc
operator|->
name|roff
argument_list|,
literal|"nS"
argument_list|,
literal|1
argument_list|,
literal|'='
argument_list|)
expr_stmt|;
name|mdoc
operator|->
name|flags
operator||=
name|MDOC_SYNOPSIS
expr_stmt|;
block|}
else|else
block|{
name|roff_setreg
argument_list|(
name|mdoc
operator|->
name|roff
argument_list|,
literal|"nS"
argument_list|,
literal|0
argument_list|,
literal|'='
argument_list|)
expr_stmt|;
name|mdoc
operator|->
name|flags
operator|&=
operator|~
name|MDOC_SYNOPSIS
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|state_sm
parameter_list|(
name|STATE_ARGS
parameter_list|)
block|{
if|if
condition|(
name|n
operator|->
name|child
operator|==
name|NULL
condition|)
name|mdoc
operator|->
name|flags
operator|^=
name|MDOC_SMOFF
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|n
operator|->
name|child
operator|->
name|string
argument_list|,
literal|"on"
argument_list|)
condition|)
name|mdoc
operator|->
name|flags
operator|&=
operator|~
name|MDOC_SMOFF
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|n
operator|->
name|child
operator|->
name|string
argument_list|,
literal|"off"
argument_list|)
condition|)
name|mdoc
operator|->
name|flags
operator||=
name|MDOC_SMOFF
expr_stmt|;
block|}
end_function

end_unit

