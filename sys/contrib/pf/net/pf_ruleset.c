begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pf_ruleset.c,v 1.2 2008/12/18 15:31:37 dhill Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * Copyright (c) 2002,2003 Henning Brauer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/pfvar.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|DPFPRINTF
parameter_list|(
name|format
parameter_list|,
name|x
modifier|...
parameter_list|)
define|\
value|if (V_pf_status.debug>= PF_DEBUG_NOISY)	\ 		printf(format , ##x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPFPRINTF
parameter_list|(
name|format
parameter_list|,
name|x
modifier|...
parameter_list|)
define|\
value|if (pf_status.debug>= PF_DEBUG_NOISY)		\ 		printf(format , ##x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|rs_malloc
parameter_list|(
name|x
parameter_list|)
value|malloc(x, M_TEMP, M_NOWAIT|M_ZERO)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rs_malloc
parameter_list|(
name|x
parameter_list|)
value|malloc(x, M_TEMP, M_WAITOK|M_CANFAIL|M_ZERO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rs_free
parameter_list|(
name|x
parameter_list|)
value|free(x, M_TEMP)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Userland equivalents so we can lend code to pfctl et al. */
end_comment

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_define
define|#
directive|define
name|rs_malloc
parameter_list|(
name|x
parameter_list|)
value|calloc(1, x)
end_define

begin_define
define|#
directive|define
name|rs_free
parameter_list|(
name|x
parameter_list|)
value|free(x)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PFDEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/stdarg.h>
end_include

begin_define
define|#
directive|define
name|DPFPRINTF
parameter_list|(
name|format
parameter_list|,
name|x
modifier|...
parameter_list|)
value|fprintf(stderr, format , ##x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPFPRINTF
parameter_list|(
name|format
parameter_list|,
name|x
modifier|...
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PFDEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|V_pf_anchors
end_undef

begin_define
define|#
directive|define
name|V_pf_anchors
value|pf_anchors
end_define

begin_undef
undef|#
directive|undef
name|pf_main_ruleset
end_undef

begin_define
define|#
directive|define
name|pf_main_ruleset
value|pf_main_anchor.ruleset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_expr_stmt
name|VNET_DEFINE
argument_list|(
expr|struct
name|pf_anchor_global
argument_list|,
name|pf_anchors
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DEFINE
argument_list|(
expr|struct
name|pf_anchor
argument_list|,
name|pf_main_anchor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|pf_anchor_global
name|pf_anchors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pf_anchor
name|pf_main_anchor
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|__inline
name|int
name|pf_anchor_compare
parameter_list|(
name|struct
name|pf_anchor
modifier|*
parameter_list|,
name|struct
name|pf_anchor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_anchor_global
argument_list|,
name|pf_anchor
argument_list|,
name|entry_global
argument_list|,
name|pf_anchor_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_GENERATE
argument_list|(
name|pf_anchor_node
argument_list|,
name|pf_anchor
argument_list|,
name|entry_node
argument_list|,
name|pf_anchor_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|__inline
name|int
name|pf_anchor_compare
parameter_list|(
name|struct
name|pf_anchor
modifier|*
name|a
parameter_list|,
name|struct
name|pf_anchor
modifier|*
name|b
parameter_list|)
block|{
name|int
name|c
init|=
name|strcmp
argument_list|(
name|a
operator|->
name|path
argument_list|,
name|b
operator|->
name|path
argument_list|)
decl_stmt|;
return|return
operator|(
name|c
condition|?
operator|(
name|c
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|pf_get_ruleset_number
parameter_list|(
name|u_int8_t
name|action
parameter_list|)
block|{
switch|switch
condition|(
name|action
condition|)
block|{
case|case
name|PF_SCRUB
case|:
case|case
name|PF_NOSCRUB
case|:
return|return
operator|(
name|PF_RULESET_SCRUB
operator|)
return|;
break|break;
case|case
name|PF_PASS
case|:
case|case
name|PF_DROP
case|:
return|return
operator|(
name|PF_RULESET_FILTER
operator|)
return|;
break|break;
case|case
name|PF_NAT
case|:
case|case
name|PF_NONAT
case|:
return|return
operator|(
name|PF_RULESET_NAT
operator|)
return|;
break|break;
case|case
name|PF_BINAT
case|:
case|case
name|PF_NOBINAT
case|:
return|return
operator|(
name|PF_RULESET_BINAT
operator|)
return|;
break|break;
case|case
name|PF_RDR
case|:
case|case
name|PF_NORDR
case|:
return|return
operator|(
name|PF_RULESET_RDR
operator|)
return|;
break|break;
default|default:
return|return
operator|(
name|PF_RULESET_MAX
operator|)
return|;
break|break;
block|}
block|}
end_function

begin_function
name|void
name|pf_init_ruleset
parameter_list|(
name|struct
name|pf_ruleset
modifier|*
name|ruleset
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|memset
argument_list|(
name|ruleset
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pf_ruleset
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|PF_RULESET_MAX
condition|;
name|i
operator|++
control|)
block|{
name|TAILQ_INIT
argument_list|(
operator|&
name|ruleset
operator|->
name|rules
index|[
name|i
index|]
operator|.
name|queues
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|ruleset
operator|->
name|rules
index|[
name|i
index|]
operator|.
name|queues
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ruleset
operator|->
name|rules
index|[
name|i
index|]
operator|.
name|active
operator|.
name|ptr
operator|=
operator|&
name|ruleset
operator|->
name|rules
index|[
name|i
index|]
operator|.
name|queues
index|[
literal|0
index|]
expr_stmt|;
name|ruleset
operator|->
name|rules
index|[
name|i
index|]
operator|.
name|inactive
operator|.
name|ptr
operator|=
operator|&
name|ruleset
operator|->
name|rules
index|[
name|i
index|]
operator|.
name|queues
index|[
literal|1
index|]
expr_stmt|;
block|}
block|}
end_function

begin_function
name|struct
name|pf_anchor
modifier|*
name|pf_find_anchor
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|struct
name|pf_anchor
modifier|*
name|key
decl_stmt|,
modifier|*
name|found
decl_stmt|;
name|key
operator|=
operator|(
expr|struct
name|pf_anchor
operator|*
operator|)
name|rs_malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|key
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|strlcpy
argument_list|(
name|key
operator|->
name|path
argument_list|,
name|path
argument_list|,
sizeof|sizeof
argument_list|(
name|key
operator|->
name|path
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|found
operator|=
name|RB_FIND
argument_list|(
name|pf_anchor_global
argument_list|,
operator|&
name|V_pf_anchors
argument_list|,
name|key
argument_list|)
expr_stmt|;
else|#
directive|else
name|found
operator|=
name|RB_FIND
argument_list|(
name|pf_anchor_global
argument_list|,
operator|&
name|pf_anchors
argument_list|,
name|key
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rs_free
argument_list|(
name|key
argument_list|)
expr_stmt|;
return|return
operator|(
name|found
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|pf_ruleset
modifier|*
name|pf_find_ruleset
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|struct
name|pf_anchor
modifier|*
name|anchor
decl_stmt|;
while|while
condition|(
operator|*
name|path
operator|==
literal|'/'
condition|)
name|path
operator|++
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|path
condition|)
return|return
operator|(
operator|&
name|pf_main_ruleset
operator|)
return|;
name|anchor
operator|=
name|pf_find_anchor
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
name|anchor
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
else|else
return|return
operator|(
operator|&
name|anchor
operator|->
name|ruleset
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|pf_ruleset
modifier|*
name|pf_find_or_create_ruleset
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|,
modifier|*
name|r
decl_stmt|;
name|struct
name|pf_ruleset
modifier|*
name|ruleset
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|pf_anchor
modifier|*
name|anchor
init|=
name|NULL
decl_stmt|,
modifier|*
name|dup
decl_stmt|,
modifier|*
name|parent
init|=
name|NULL
decl_stmt|;
else|#
directive|else
name|struct
name|pf_anchor
modifier|*
name|anchor
decl_stmt|,
modifier|*
name|dup
decl_stmt|,
modifier|*
name|parent
init|=
name|NULL
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|path
index|[
literal|0
index|]
operator|==
literal|0
condition|)
return|return
operator|(
operator|&
name|pf_main_ruleset
operator|)
return|;
while|while
condition|(
operator|*
name|path
operator|==
literal|'/'
condition|)
name|path
operator|++
expr_stmt|;
name|ruleset
operator|=
name|pf_find_ruleset
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
name|ruleset
operator|!=
name|NULL
condition|)
return|return
operator|(
name|ruleset
operator|)
return|;
name|p
operator|=
operator|(
name|char
operator|*
operator|)
name|rs_malloc
argument_list|(
name|MAXPATHLEN
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|strlcpy
argument_list|(
name|p
argument_list|,
name|path
argument_list|,
name|MAXPATHLEN
argument_list|)
expr_stmt|;
while|while
condition|(
name|parent
operator|==
name|NULL
operator|&&
operator|(
name|q
operator|=
name|strrchr
argument_list|(
name|p
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|*
name|q
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|ruleset
operator|=
name|pf_find_ruleset
argument_list|(
name|p
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|parent
operator|=
name|ruleset
operator|->
name|anchor
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|q
operator|==
name|NULL
condition|)
name|q
operator|=
name|p
expr_stmt|;
else|else
name|q
operator|++
expr_stmt|;
name|strlcpy
argument_list|(
name|p
argument_list|,
name|path
argument_list|,
name|MAXPATHLEN
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|q
condition|)
block|{
name|rs_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
while|while
condition|(
operator|(
name|r
operator|=
name|strchr
argument_list|(
name|q
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
operator|||
operator|*
name|q
condition|)
block|{
if|if
condition|(
name|r
operator|!=
name|NULL
condition|)
operator|*
name|r
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|q
operator|||
name|strlen
argument_list|(
name|q
argument_list|)
operator|>=
name|PF_ANCHOR_NAME_SIZE
operator|||
operator|(
name|parent
operator|!=
name|NULL
operator|&&
name|strlen
argument_list|(
name|parent
operator|->
name|path
argument_list|)
operator|>=
name|MAXPATHLEN
operator|-
name|PF_ANCHOR_NAME_SIZE
operator|-
literal|1
operator|)
condition|)
block|{
name|rs_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|anchor
operator|=
operator|(
expr|struct
name|pf_anchor
operator|*
operator|)
name|rs_malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|anchor
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|anchor
operator|==
name|NULL
condition|)
block|{
name|rs_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|RB_INIT
argument_list|(
operator|&
name|anchor
operator|->
name|children
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|anchor
operator|->
name|name
argument_list|,
name|q
argument_list|,
sizeof|sizeof
argument_list|(
name|anchor
operator|->
name|name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|parent
operator|!=
name|NULL
condition|)
block|{
name|strlcpy
argument_list|(
name|anchor
operator|->
name|path
argument_list|,
name|parent
operator|->
name|path
argument_list|,
sizeof|sizeof
argument_list|(
name|anchor
operator|->
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|strlcat
argument_list|(
name|anchor
operator|->
name|path
argument_list|,
literal|"/"
argument_list|,
sizeof|sizeof
argument_list|(
name|anchor
operator|->
name|path
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|strlcat
argument_list|(
name|anchor
operator|->
name|path
argument_list|,
name|anchor
operator|->
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|anchor
operator|->
name|path
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
if|if
condition|(
operator|(
name|dup
operator|=
name|RB_INSERT
argument_list|(
name|pf_anchor_global
argument_list|,
operator|&
name|V_pf_anchors
argument_list|,
name|anchor
argument_list|)
operator|)
operator|!=
else|#
directive|else
if|if
condition|(
operator|(
name|dup
operator|=
name|RB_INSERT
argument_list|(
name|pf_anchor_global
argument_list|,
operator|&
name|pf_anchors
argument_list|,
name|anchor
argument_list|)
operator|)
operator|!=
endif|#
directive|endif
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"pf_find_or_create_ruleset: RB_INSERT1 "
literal|"'%s' '%s' collides with '%s' '%s'\n"
argument_list|,
name|anchor
operator|->
name|path
argument_list|,
name|anchor
operator|->
name|name
argument_list|,
name|dup
operator|->
name|path
argument_list|,
name|dup
operator|->
name|name
argument_list|)
expr_stmt|;
name|rs_free
argument_list|(
name|anchor
argument_list|)
expr_stmt|;
name|rs_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|parent
operator|!=
name|NULL
condition|)
block|{
name|anchor
operator|->
name|parent
operator|=
name|parent
expr_stmt|;
if|if
condition|(
operator|(
name|dup
operator|=
name|RB_INSERT
argument_list|(
name|pf_anchor_node
argument_list|,
operator|&
name|parent
operator|->
name|children
argument_list|,
name|anchor
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"pf_find_or_create_ruleset: "
literal|"RB_INSERT2 '%s' '%s' collides with "
literal|"'%s' '%s'\n"
argument_list|,
name|anchor
operator|->
name|path
argument_list|,
name|anchor
operator|->
name|name
argument_list|,
name|dup
operator|->
name|path
argument_list|,
name|dup
operator|->
name|name
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|RB_REMOVE
argument_list|(
argument|pf_anchor_global
argument_list|,
argument|&V_pf_anchors
argument_list|,
else|#
directive|else
argument|RB_REMOVE(pf_anchor_global,&pf_anchors,
endif|#
directive|endif
argument|anchor); 				rs_free(anchor); 				rs_free(p); 				return (NULL); 			} 		} 		pf_init_ruleset(&anchor->ruleset); 		anchor->ruleset.anchor = anchor; 		parent = anchor; 		if (r != NULL) 			q = r +
literal|1
argument|; 		else 			*q =
literal|0
argument|; 	} 	rs_free(p); 	return (&anchor->ruleset); }  void pf_remove_if_empty_ruleset(struct pf_ruleset *ruleset) { 	struct pf_anchor	*parent; 	int			 i;  	while (ruleset != NULL) { 		if (ruleset ==&pf_main_ruleset || ruleset->anchor == NULL || 		    !RB_EMPTY(&ruleset->anchor->children) || 		    ruleset->anchor->refcnt>
literal|0
argument||| ruleset->tables>
literal|0
argument||| 		    ruleset->topen) 			return; 		for (i =
literal|0
argument|; i< PF_RULESET_MAX; ++i) 			if (!TAILQ_EMPTY(ruleset->rules[i].active.ptr) || 			    !TAILQ_EMPTY(ruleset->rules[i].inactive.ptr) || 			    ruleset->rules[i].inactive.open) 				return;
ifdef|#
directive|ifdef
name|__FreeBSD__
argument|RB_REMOVE(pf_anchor_global,&V_pf_anchors, ruleset->anchor);
else|#
directive|else
argument|RB_REMOVE(pf_anchor_global,&pf_anchors, ruleset->anchor);
endif|#
directive|endif
argument|if ((parent = ruleset->anchor->parent) != NULL) 			RB_REMOVE(pf_anchor_node,&parent->children, 			    ruleset->anchor); 		rs_free(ruleset->anchor); 		if (parent == NULL) 			return; 		ruleset =&parent->ruleset; 	} }  int pf_anchor_setup(struct pf_rule *r, const struct pf_ruleset *s,     const char *name) { 	char			*p
argument_list|,
argument|*path; 	struct pf_ruleset	*ruleset;  	r->anchor = NULL; 	r->anchor_relative =
literal|0
argument|; 	r->anchor_wildcard =
literal|0
argument|; 	if (!name[
literal|0
argument|]) 		return (
literal|0
argument|); 	path = (char *)rs_malloc(MAXPATHLEN); 	if (path == NULL) 		return (
literal|1
argument|); 	if (name[
literal|0
argument|] ==
literal|'/'
argument|) 		strlcpy(path, name +
literal|1
argument|, MAXPATHLEN); 	else {
comment|/* relative path */
argument|r->anchor_relative =
literal|1
argument|; 		if (s->anchor == NULL || !s->anchor->path[
literal|0
argument|]) 			path[
literal|0
argument|] =
literal|0
argument|; 		else 			strlcpy(path, s->anchor->path, MAXPATHLEN); 		while (name[
literal|0
argument|] ==
literal|'.'
argument|&& name[
literal|1
argument|] ==
literal|'.'
argument|&& name[
literal|2
argument|] ==
literal|'/'
argument|) { 			if (!path[
literal|0
argument|]) { 				printf(
literal|"pf_anchor_setup: .. beyond root\n"
argument|); 				rs_free(path); 				return (
literal|1
argument|); 			} 			if ((p = strrchr(path,
literal|'/'
argument|)) != NULL) 				*p =
literal|0
argument|; 			else 				path[
literal|0
argument|] =
literal|0
argument|; 			r->anchor_relative++; 			name +=
literal|3
argument|; 		} 		if (path[
literal|0
argument|]) 			strlcat(path,
literal|"/"
argument|, MAXPATHLEN); 		strlcat(path, name, MAXPATHLEN); 	} 	if ((p = strrchr(path,
literal|'/'
argument|)) != NULL&& !strcmp(p,
literal|"/*"
argument|)) { 		r->anchor_wildcard =
literal|1
argument|; 		*p =
literal|0
argument|; 	} 	ruleset = pf_find_or_create_ruleset(path); 	rs_free(path); 	if (ruleset == NULL || ruleset->anchor == NULL) { 		printf(
literal|"pf_anchor_setup: ruleset\n"
argument|); 		return (
literal|1
argument|); 	} 	r->anchor = ruleset->anchor; 	r->anchor->refcnt++; 	return (
literal|0
argument|); }  int pf_anchor_copyout(const struct pf_ruleset *rs, const struct pf_rule *r,     struct pfioc_rule *pr) { 	pr->anchor_call[
literal|0
argument|] =
literal|0
argument|; 	if (r->anchor == NULL) 		return (
literal|0
argument|); 	if (!r->anchor_relative) { 		strlcpy(pr->anchor_call,
literal|"/"
argument|, sizeof(pr->anchor_call)); 		strlcat(pr->anchor_call, r->anchor->path, 		    sizeof(pr->anchor_call)); 	} else { 		char	*a
argument_list|,
argument|*p; 		int	 i;  		a = (char *)rs_malloc(MAXPATHLEN); 		if (a == NULL) 			return (
literal|1
argument|); 		if (rs->anchor == NULL) 			a[
literal|0
argument|] =
literal|0
argument|; 		else 			strlcpy(a, rs->anchor->path, MAXPATHLEN); 		for (i =
literal|1
argument|; i< r->anchor_relative; ++i) { 			if ((p = strrchr(a,
literal|'/'
argument|)) == NULL) 				p = a; 			*p =
literal|0
argument|; 			strlcat(pr->anchor_call,
literal|"../"
argument|, 			    sizeof(pr->anchor_call)); 		} 		if (strncmp(a, r->anchor->path, strlen(a))) { 			printf(
literal|"pf_anchor_copyout: '%s' '%s'\n"
argument|, a, 			    r->anchor->path); 			rs_free(a); 			return (
literal|1
argument|); 		} 		if (strlen(r->anchor->path)> strlen(a)) 			strlcat(pr->anchor_call, r->anchor->path + (a[
literal|0
argument|] ? 			    strlen(a) +
literal|1
argument|:
literal|0
argument|), sizeof(pr->anchor_call)); 		rs_free(a); 	} 	if (r->anchor_wildcard) 		strlcat(pr->anchor_call, pr->anchor_call[
literal|0
argument|] ?
literal|"/*"
argument|:
literal|"*"
argument|, 		    sizeof(pr->anchor_call)); 	return (
literal|0
argument|); }  void pf_anchor_remove(struct pf_rule *r) { 	if (r->anchor == NULL) 		return; 	if (r->anchor->refcnt<=
literal|0
argument|) { 		printf(
literal|"pf_anchor_remove: broken refcount\n"
argument|); 		r->anchor = NULL; 		return; 	} 	if (!--r->anchor->refcnt) 		pf_remove_if_empty_ruleset(&r->anchor->ruleset); 	r->anchor = NULL; }
end_function

end_unit

