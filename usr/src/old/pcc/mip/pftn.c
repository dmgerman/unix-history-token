begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)pftn.c	1.28 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"pass1.h"
end_include

begin_decl_stmt
name|unsigned
name|int
name|offsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|symtab
modifier|*
name|schain
index|[
name|MAXSCOPES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sym chains for clearst */
end_comment

begin_decl_stmt
name|int
name|chaintop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* highest active entry */
end_comment

begin_struct
struct|struct
name|instk
block|{
name|int
name|in_sz
decl_stmt|;
comment|/* size of array element */
name|int
name|in_x
decl_stmt|;
comment|/* current index for structure member in structure initializations */
name|int
name|in_n
decl_stmt|;
comment|/* number of initializations seen */
name|int
name|in_s
decl_stmt|;
comment|/* sizoff */
name|int
name|in_d
decl_stmt|;
comment|/* dimoff */
name|TWORD
name|in_t
decl_stmt|;
comment|/* type */
name|int
name|in_id
decl_stmt|;
comment|/* stab index */
name|int
name|in_fl
decl_stmt|;
comment|/* flag which says if this level is controlled by {} */
name|OFFSZ
name|in_off
decl_stmt|;
comment|/* offset of the beginning of this level */
block|}
name|instack
index|[
literal|10
index|]
struct|,
modifier|*
name|pstk
struct|;
end_struct

begin_comment
comment|/* defines used for getting things off of the initialization stack */
end_comment

begin_function_decl
name|struct
name|symtab
modifier|*
name|relook
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ddebug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|symtab
modifier|*
name|mknonuniq
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|defid
argument_list|(
name|q
argument_list|,
name|class
argument_list|)
specifier|register
name|NODE
operator|*
name|q
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|class
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|symtab
modifier|*
name|p
decl_stmt|;
name|int
name|idp
decl_stmt|;
specifier|register
name|TWORD
name|type
decl_stmt|;
name|TWORD
name|stp
decl_stmt|;
specifier|register
name|int
name|scl
decl_stmt|;
name|int
name|dsym
decl_stmt|,
name|ddef
decl_stmt|;
name|int
name|slev
decl_stmt|,
name|temp
decl_stmt|;
name|int
name|changed
decl_stmt|;
if|if
condition|(
name|q
operator|==
name|NIL
condition|)
return|return;
comment|/* an error was detected */
if|if
condition|(
name|q
operator|<
name|node
operator|||
name|q
operator|>=
operator|&
name|node
index|[
name|TREESZ
index|]
condition|)
name|cerror
argument_list|(
literal|"defid call"
argument_list|)
expr_stmt|;
name|idp
operator|=
name|q
operator|->
name|tn
operator|.
name|rval
expr_stmt|;
if|if
condition|(
name|idp
operator|<
literal|0
condition|)
name|cerror
argument_list|(
literal|"tyreduce"
argument_list|)
expr_stmt|;
name|p
operator|=
operator|&
name|stab
index|[
name|idp
index|]
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"defid( %.8s (%d), "
argument_list|,
name|p
operator|->
name|sname
argument_list|,
name|idp
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"defid( %s (%d), "
argument_list|,
name|p
operator|->
name|sname
argument_list|,
name|idp
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|tprint
argument_list|(
name|q
operator|->
name|in
operator|.
name|type
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %s, (%d,%d) ), level %d\n"
argument_list|,
name|scnames
argument_list|(
name|class
argument_list|)
argument_list|,
name|q
operator|->
name|fn
operator|.
name|cdim
argument_list|,
name|q
operator|->
name|fn
operator|.
name|csiz
argument_list|,
name|blevel
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|fixtype
argument_list|(
name|q
argument_list|,
name|class
argument_list|)
expr_stmt|;
name|type
operator|=
name|q
operator|->
name|in
operator|.
name|type
expr_stmt|;
name|class
operator|=
name|fixclass
argument_list|(
name|class
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|stp
operator|=
name|p
operator|->
name|stype
expr_stmt|;
name|slev
operator|=
name|p
operator|->
name|slevel
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
condition|)
block|{
name|printf
argument_list|(
literal|"	modified to "
argument_list|)
expr_stmt|;
name|tprint
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %s\n"
argument_list|,
name|scnames
argument_list|(
name|class
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"	previous def'n: "
argument_list|)
expr_stmt|;
name|tprint
argument_list|(
name|stp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %s, (%d,%d) ), level %d\n"
argument_list|,
name|scnames
argument_list|(
name|p
operator|->
name|sclass
argument_list|)
argument_list|,
name|p
operator|->
name|dimoff
argument_list|,
name|p
operator|->
name|sizoff
argument_list|,
name|slev
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|stp
operator|==
name|FTN
operator|&&
name|p
operator|->
name|sclass
operator|==
name|SNULL
condition|)
goto|goto
name|enter
goto|;
if|if
condition|(
name|blevel
operator|==
literal|1
operator|&&
name|stp
operator|!=
name|FARG
condition|)
switch|switch
condition|(
name|class
condition|)
block|{
default|default:
ifndef|#
directive|ifndef
name|FLEXNAMES
if|if
condition|(
operator|!
operator|(
name|class
operator|&
name|FIELD
operator|)
condition|)
name|uerror
argument_list|(
literal|"declared argument %.8s is missing"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|!
operator|(
name|class
operator|&
name|FIELD
operator|)
condition|)
name|uerror
argument_list|(
literal|"declared argument %s is missing"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
endif|#
directive|endif
case|case
name|MOS
case|:
case|case
name|STNAME
case|:
case|case
name|MOU
case|:
case|case
name|UNAME
case|:
case|case
name|MOE
case|:
case|case
name|ENAME
case|:
case|case
name|TYPEDEF
case|:
empty_stmt|;
block|}
if|if
condition|(
name|stp
operator|==
name|UNDEF
operator|||
name|stp
operator|==
name|FARG
condition|)
goto|goto
name|enter
goto|;
if|if
condition|(
name|type
operator|!=
name|stp
condition|)
goto|goto
name|mismatch
goto|;
if|if
condition|(
name|blevel
operator|>
name|slev
operator|&&
operator|(
name|class
operator|==
name|AUTO
operator|||
name|class
operator|==
name|REGISTER
operator|)
condition|)
comment|/* new scope */
goto|goto
name|mismatch
goto|;
comment|/* test (and possibly adjust) dimensions */
name|dsym
operator|=
name|p
operator|->
name|dimoff
expr_stmt|;
name|ddef
operator|=
name|q
operator|->
name|fn
operator|.
name|cdim
expr_stmt|;
name|changed
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|temp
operator|=
name|type
init|;
name|temp
operator|&
name|TMASK
condition|;
name|temp
operator|=
name|DECREF
argument_list|(
name|temp
argument_list|)
control|)
block|{
if|if
condition|(
name|ISARY
argument_list|(
name|temp
argument_list|)
condition|)
block|{
if|if
condition|(
name|dimtab
index|[
name|dsym
index|]
operator|==
literal|0
condition|)
block|{
name|dimtab
index|[
name|dsym
index|]
operator|=
name|dimtab
index|[
name|ddef
index|]
expr_stmt|;
name|changed
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dimtab
index|[
name|ddef
index|]
operator|!=
literal|0
operator|&&
name|dimtab
index|[
name|dsym
index|]
operator|!=
name|dimtab
index|[
name|ddef
index|]
condition|)
block|{
goto|goto
name|mismatch
goto|;
block|}
operator|++
name|dsym
expr_stmt|;
operator|++
name|ddef
expr_stmt|;
block|}
block|}
if|if
condition|(
name|changed
condition|)
block|{
name|FIXDEF
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
comment|/* check that redeclarations are to the same structure */
if|if
condition|(
operator|(
name|temp
operator|==
name|STRTY
operator|||
name|temp
operator|==
name|UNIONTY
operator|||
name|temp
operator|==
name|ENUMTY
operator|)
operator|&&
name|p
operator|->
name|sizoff
operator|!=
name|q
operator|->
name|fn
operator|.
name|csiz
operator|&&
name|class
operator|!=
name|STNAME
operator|&&
name|class
operator|!=
name|UNAME
operator|&&
name|class
operator|!=
name|ENAME
condition|)
block|{
goto|goto
name|mismatch
goto|;
block|}
name|scl
operator|=
operator|(
name|p
operator|->
name|sclass
operator|)
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
condition|)
block|{
name|printf
argument_list|(
literal|"	previous class: %s\n"
argument_list|,
name|scnames
argument_list|(
name|scl
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|class
operator|&
name|FIELD
condition|)
block|{
comment|/* redefinition */
if|if
condition|(
operator|!
name|falloc
argument_list|(
name|p
argument_list|,
name|class
operator|&
name|FLDSIZ
argument_list|,
literal|1
argument_list|,
name|NIL
argument_list|)
condition|)
block|{
comment|/* successful allocation */
name|psave
argument_list|(
name|idp
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* blew it: resume at end of switch... */
block|}
else|else
switch|switch
condition|(
name|class
condition|)
block|{
case|case
name|EXTERN
case|:
switch|switch
condition|(
name|scl
condition|)
block|{
case|case
name|STATIC
case|:
case|case
name|USTATIC
case|:
if|if
condition|(
name|slev
operator|==
literal|0
condition|)
return|return;
break|break;
case|case
name|EXTDEF
case|:
case|case
name|EXTERN
case|:
case|case
name|FORTRAN
case|:
case|case
name|UFORTRAN
case|:
return|return;
block|}
break|break;
case|case
name|STATIC
case|:
if|if
condition|(
name|scl
operator|==
name|USTATIC
operator|||
operator|(
name|scl
operator|==
name|EXTERN
operator|&&
name|blevel
operator|==
literal|0
operator|)
condition|)
block|{
name|p
operator|->
name|sclass
operator|=
name|STATIC
expr_stmt|;
if|if
condition|(
name|ISFTN
argument_list|(
name|type
argument_list|)
condition|)
name|curftn
operator|=
name|idp
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|USTATIC
case|:
if|if
condition|(
name|scl
operator|==
name|STATIC
operator|||
name|scl
operator|==
name|USTATIC
condition|)
return|return;
break|break;
case|case
name|LABEL
case|:
if|if
condition|(
name|scl
operator|==
name|ULABEL
condition|)
block|{
name|p
operator|->
name|sclass
operator|=
name|LABEL
expr_stmt|;
name|deflab
argument_list|(
name|p
operator|->
name|offset
argument_list|)
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|TYPEDEF
case|:
if|if
condition|(
name|scl
operator|==
name|class
condition|)
return|return;
break|break;
case|case
name|UFORTRAN
case|:
if|if
condition|(
name|scl
operator|==
name|UFORTRAN
operator|||
name|scl
operator|==
name|FORTRAN
condition|)
return|return;
break|break;
case|case
name|FORTRAN
case|:
if|if
condition|(
name|scl
operator|==
name|UFORTRAN
condition|)
block|{
name|p
operator|->
name|sclass
operator|=
name|FORTRAN
expr_stmt|;
if|if
condition|(
name|ISFTN
argument_list|(
name|type
argument_list|)
condition|)
name|curftn
operator|=
name|idp
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|MOU
case|:
case|case
name|MOS
case|:
if|if
condition|(
name|scl
operator|==
name|class
condition|)
block|{
if|if
condition|(
name|oalloc
argument_list|(
name|p
argument_list|,
operator|&
name|strucoff
argument_list|)
condition|)
break|break;
if|if
condition|(
name|class
operator|==
name|MOU
condition|)
name|strucoff
operator|=
literal|0
expr_stmt|;
name|psave
argument_list|(
name|idp
argument_list|)
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|MOE
case|:
if|if
condition|(
name|scl
operator|==
name|class
condition|)
block|{
if|if
condition|(
name|p
operator|->
name|offset
operator|!=
name|strucoff
operator|++
condition|)
break|break;
name|psave
argument_list|(
name|idp
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|EXTDEF
case|:
if|if
condition|(
name|scl
operator|==
name|EXTERN
condition|)
block|{
name|p
operator|->
name|sclass
operator|=
name|EXTDEF
expr_stmt|;
if|if
condition|(
name|ISFTN
argument_list|(
name|type
argument_list|)
condition|)
name|curftn
operator|=
name|idp
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|STNAME
case|:
case|case
name|UNAME
case|:
case|case
name|ENAME
case|:
if|if
condition|(
name|scl
operator|!=
name|class
condition|)
break|break;
if|if
condition|(
name|dimtab
index|[
name|p
operator|->
name|sizoff
index|]
operator|==
literal|0
condition|)
return|return;
comment|/* previous entry just a mention */
break|break;
case|case
name|ULABEL
case|:
if|if
condition|(
name|scl
operator|==
name|LABEL
operator|||
name|scl
operator|==
name|ULABEL
condition|)
return|return;
case|case
name|PARAM
case|:
case|case
name|AUTO
case|:
case|case
name|REGISTER
case|:
empty_stmt|;
comment|/* mismatch.. */
block|}
name|mismatch
label|:
comment|/* allow nonunique structure/union member names */
if|if
condition|(
name|class
operator|==
name|MOU
operator|||
name|class
operator|==
name|MOS
operator|||
name|class
operator|&
name|FIELD
condition|)
block|{
comment|/* make a new entry */
specifier|register
name|int
modifier|*
name|memp
decl_stmt|;
name|p
operator|->
name|sflags
operator||=
name|SNONUNIQ
expr_stmt|;
comment|/* old entry is nonunique */
comment|/* determine if name has occurred in this structure/union */
if|if
condition|(
name|paramno
operator|>
literal|0
condition|)
for|for
control|(
name|memp
operator|=
operator|&
name|paramstk
index|[
name|paramno
operator|-
literal|1
index|]
init|;
comment|/* while */
operator|*
name|memp
operator|>=
literal|0
operator|&&
name|stab
index|[
operator|*
name|memp
index|]
operator|.
name|sclass
operator|!=
name|STNAME
operator|&&
name|stab
index|[
operator|*
name|memp
index|]
operator|.
name|sclass
operator|!=
name|UNAME
condition|;
comment|/* iterate */
operator|--
name|memp
control|)
block|{
name|char
modifier|*
name|cname
decl_stmt|,
modifier|*
name|oname
decl_stmt|;
if|if
condition|(
name|stab
index|[
operator|*
name|memp
index|]
operator|.
name|sflags
operator|&
name|SNONUNIQ
condition|)
block|{
name|cname
operator|=
name|p
operator|->
name|sname
expr_stmt|;
name|oname
operator|=
name|stab
index|[
operator|*
name|memp
index|]
operator|.
name|sname
expr_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
for|for
control|(
name|temp
operator|=
literal|1
init|;
name|temp
operator|<=
name|NCHNAM
condition|;
operator|++
name|temp
control|)
block|{
if|if
condition|(
operator|*
name|cname
operator|++
operator|!=
operator|*
name|oname
condition|)
goto|goto
name|diff
goto|;
if|if
condition|(
operator|!
operator|*
name|oname
operator|++
condition|)
break|break;
block|}
else|#
directive|else
if|if
condition|(
name|cname
operator|!=
name|oname
condition|)
goto|goto
name|diff
goto|;
endif|#
directive|endif
name|uerror
argument_list|(
literal|"redeclaration of: %s"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
break|break;
name|diff
label|:
continue|continue;
block|}
block|}
name|p
operator|=
name|mknonuniq
argument_list|(
operator|&
name|idp
argument_list|)
expr_stmt|;
comment|/* update p and idp to new entry */
goto|goto
name|enter
goto|;
block|}
if|if
condition|(
name|blevel
operator|>
name|slev
operator|&&
name|class
operator|!=
name|EXTERN
operator|&&
name|class
operator|!=
name|FORTRAN
operator|&&
name|class
operator|!=
name|UFORTRAN
operator|&&
operator|!
operator|(
name|class
operator|==
name|LABEL
operator|&&
name|slev
operator|>=
literal|2
operator|)
condition|)
block|{
name|q
operator|->
name|tn
operator|.
name|rval
operator|=
name|idp
operator|=
name|hide
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|p
operator|=
operator|&
name|stab
index|[
name|idp
index|]
expr_stmt|;
goto|goto
name|enter
goto|;
block|}
ifndef|#
directive|ifndef
name|FLEXNAMES
name|uerror
argument_list|(
literal|"redeclaration of %.8s"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
else|#
directive|else
name|uerror
argument_list|(
literal|"redeclaration of %s"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|class
operator|==
name|EXTDEF
operator|&&
name|ISFTN
argument_list|(
name|type
argument_list|)
condition|)
name|curftn
operator|=
name|idp
expr_stmt|;
return|return;
name|enter
label|:
comment|/* make a new entry */
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
condition|)
name|printf
argument_list|(
literal|"	new entry made\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|type
operator|==
name|UNDEF
condition|)
name|uerror
argument_list|(
literal|"void type for %s"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
name|p
operator|->
name|stype
operator|=
name|type
expr_stmt|;
name|p
operator|->
name|sclass
operator|=
name|class
expr_stmt|;
name|p
operator|->
name|slevel
operator|=
name|blevel
expr_stmt|;
name|p
operator|->
name|offset
operator|=
name|NOOFFSET
expr_stmt|;
name|p
operator|->
name|suse
operator|=
name|lineno
expr_stmt|;
if|if
condition|(
name|class
operator|==
name|STNAME
operator|||
name|class
operator|==
name|UNAME
operator|||
name|class
operator|==
name|ENAME
condition|)
block|{
name|p
operator|->
name|sizoff
operator|=
name|curdim
expr_stmt|;
name|dstash
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* size */
name|dstash
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* index to members of str or union */
name|dstash
argument_list|(
name|ALSTRUCT
argument_list|)
expr_stmt|;
comment|/* alignment */
name|dstash
argument_list|(
name|idp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|BTYPE
argument_list|(
name|type
argument_list|)
condition|)
block|{
case|case
name|STRTY
case|:
case|case
name|UNIONTY
case|:
case|case
name|ENUMTY
case|:
name|p
operator|->
name|sizoff
operator|=
name|q
operator|->
name|fn
operator|.
name|csiz
expr_stmt|;
break|break;
default|default:
name|p
operator|->
name|sizoff
operator|=
name|BTYPE
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* copy dimensions */
name|p
operator|->
name|dimoff
operator|=
name|q
operator|->
name|fn
operator|.
name|cdim
expr_stmt|;
comment|/* allocate offsets */
if|if
condition|(
name|class
operator|&
name|FIELD
condition|)
block|{
operator|(
name|void
operator|)
name|falloc
argument_list|(
name|p
argument_list|,
name|class
operator|&
name|FLDSIZ
argument_list|,
literal|0
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
comment|/* new entry */
name|psave
argument_list|(
name|idp
argument_list|)
expr_stmt|;
block|}
else|else
switch|switch
condition|(
name|class
condition|)
block|{
case|case
name|AUTO
case|:
operator|(
name|void
operator|)
name|oalloc
argument_list|(
name|p
argument_list|,
operator|&
name|autooff
argument_list|)
expr_stmt|;
break|break;
case|case
name|STATIC
case|:
case|case
name|EXTDEF
case|:
name|p
operator|->
name|offset
operator|=
name|getlab
argument_list|()
expr_stmt|;
if|if
condition|(
name|ISFTN
argument_list|(
name|type
argument_list|)
condition|)
name|curftn
operator|=
name|idp
expr_stmt|;
break|break;
case|case
name|ULABEL
case|:
case|case
name|LABEL
case|:
name|p
operator|->
name|offset
operator|=
name|getlab
argument_list|()
expr_stmt|;
name|p
operator|->
name|slevel
operator|=
literal|2
expr_stmt|;
if|if
condition|(
name|class
operator|==
name|LABEL
condition|)
block|{
operator|(
name|void
operator|)
name|locctr
argument_list|(
name|PROG
argument_list|)
expr_stmt|;
name|deflab
argument_list|(
name|p
operator|->
name|offset
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|EXTERN
case|:
case|case
name|UFORTRAN
case|:
case|case
name|FORTRAN
case|:
name|p
operator|->
name|offset
operator|=
name|getlab
argument_list|()
expr_stmt|;
name|p
operator|->
name|slevel
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|MOU
case|:
case|case
name|MOS
case|:
operator|(
name|void
operator|)
name|oalloc
argument_list|(
name|p
argument_list|,
operator|&
name|strucoff
argument_list|)
expr_stmt|;
if|if
condition|(
name|class
operator|==
name|MOU
condition|)
name|strucoff
operator|=
literal|0
expr_stmt|;
name|psave
argument_list|(
name|idp
argument_list|)
expr_stmt|;
break|break;
case|case
name|MOE
case|:
name|p
operator|->
name|offset
operator|=
name|strucoff
operator|++
expr_stmt|;
name|psave
argument_list|(
name|idp
argument_list|)
expr_stmt|;
break|break;
case|case
name|REGISTER
case|:
name|p
operator|->
name|offset
operator|=
name|regvar
operator|--
expr_stmt|;
if|if
condition|(
name|blevel
operator|==
literal|1
condition|)
name|p
operator|->
name|sflags
operator||=
name|SSET
expr_stmt|;
if|if
condition|(
name|regvar
operator|<
name|minrvar
condition|)
name|minrvar
operator|=
name|regvar
expr_stmt|;
break|break;
block|}
block|{
specifier|register
name|int
name|l
init|=
name|p
operator|->
name|slevel
decl_stmt|;
if|if
condition|(
name|l
operator|>=
name|MAXSCOPES
condition|)
name|cerror
argument_list|(
literal|"scopes nested too deep"
argument_list|)
expr_stmt|;
name|p
operator|->
name|snext
operator|=
name|schain
index|[
name|l
index|]
expr_stmt|;
name|schain
index|[
name|l
index|]
operator|=
name|p
expr_stmt|;
if|if
condition|(
name|l
operator|>=
name|chaintop
condition|)
name|chaintop
operator|=
name|l
operator|+
literal|1
expr_stmt|;
block|}
comment|/* user-supplied routine to fix up new definitions */
name|FIXDEF
argument_list|(
name|p
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
condition|)
name|printf
argument_list|(
literal|"	dimoff, sizoff, offset: %d, %d, %d\n"
argument_list|,
name|p
operator|->
name|dimoff
argument_list|,
name|p
operator|->
name|sizoff
argument_list|,
name|p
operator|->
name|offset
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|psave
argument_list|(
argument|i
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|paramno
operator|>=
name|PARAMSZ
condition|)
block|{
name|cerror
argument_list|(
literal|"parameter stack overflow"
argument_list|)
expr_stmt|;
block|}
name|paramstk
index|[
name|paramno
operator|++
index|]
operator|=
name|i
expr_stmt|;
block|}
end_block

begin_macro
name|ftnend
argument_list|()
end_macro

begin_block
block|{
comment|/* end of function */
if|if
condition|(
name|retlab
operator|!=
name|NOLAB
operator|&&
name|nerrors
operator|==
literal|0
condition|)
block|{
comment|/* inside a real function */
name|efcode
argument_list|()
expr_stmt|;
block|}
name|checkst
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|retstat
operator|=
literal|0
expr_stmt|;
name|tcheck
argument_list|()
expr_stmt|;
name|curclass
operator|=
name|SNULL
expr_stmt|;
name|brklab
operator|=
name|contlab
operator|=
name|retlab
operator|=
name|NOLAB
expr_stmt|;
name|flostat
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nerrors
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|psavbc
operator|!=
operator|&
name|asavbc
index|[
literal|0
index|]
condition|)
name|cerror
argument_list|(
literal|"bcsave error"
argument_list|)
expr_stmt|;
if|if
condition|(
name|paramno
operator|!=
literal|0
condition|)
name|cerror
argument_list|(
literal|"parameter reset error"
argument_list|)
expr_stmt|;
if|if
condition|(
name|swx
operator|!=
literal|0
condition|)
name|cerror
argument_list|(
literal|"switch error"
argument_list|)
expr_stmt|;
block|}
name|psavbc
operator|=
operator|&
name|asavbc
index|[
literal|0
index|]
expr_stmt|;
name|paramno
operator|=
literal|0
expr_stmt|;
name|autooff
operator|=
name|AUTOINIT
expr_stmt|;
name|minrvar
operator|=
name|regvar
operator|=
name|MAXRVAR
expr_stmt|;
name|reached
operator|=
literal|1
expr_stmt|;
name|swx
operator|=
literal|0
expr_stmt|;
name|swp
operator|=
name|swtab
expr_stmt|;
operator|(
name|void
operator|)
name|locctr
argument_list|(
name|DATA
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|dclargs
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|i
operator|,
name|j
expr_stmt|;
specifier|register
name|struct
name|symtab
modifier|*
name|p
decl_stmt|;
specifier|register
name|NODE
modifier|*
name|q
decl_stmt|;
name|argoff
operator|=
name|ARGINIT
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
operator|>
literal|2
condition|)
name|printf
argument_list|(
literal|"dclargs()\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|paramno
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|(
name|j
operator|=
name|paramstk
index|[
name|i
index|]
operator|)
operator|<
literal|0
condition|)
continue|continue;
name|p
operator|=
operator|&
name|stab
index|[
name|j
index|]
expr_stmt|;
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
operator|>
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"\t%s (%d) "
argument_list|,
name|p
operator|->
name|sname
argument_list|,
name|j
argument_list|)
expr_stmt|;
name|tprint
argument_list|(
name|p
operator|->
name|stype
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|p
operator|->
name|stype
operator|==
name|FARG
condition|)
block|{
name|q
operator|=
name|block
argument_list|(
name|FREE
argument_list|,
name|NIL
argument_list|,
name|NIL
argument_list|,
name|INT
argument_list|,
literal|0
argument_list|,
name|INT
argument_list|)
expr_stmt|;
name|q
operator|->
name|tn
operator|.
name|rval
operator|=
name|j
expr_stmt|;
name|defid
argument_list|(
name|q
argument_list|,
name|PARAM
argument_list|)
expr_stmt|;
block|}
name|FIXARG
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* local arg hook, eg. for sym. debugger */
name|oalloc
argument_list|(
name|p
argument_list|,
operator|&
name|argoff
argument_list|)
expr_stmt|;
comment|/* always set aside space, even for register arguments */
block|}
name|cendarg
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|locctr
argument_list|(
name|PROG
argument_list|)
expr_stmt|;
name|defalign
argument_list|(
name|ALINT
argument_list|)
expr_stmt|;
name|ftnno
operator|=
name|getlab
argument_list|()
expr_stmt|;
name|bfcode
argument_list|(
name|paramstk
argument_list|,
name|paramno
argument_list|)
expr_stmt|;
name|paramno
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_function
name|NODE
modifier|*
name|rstruct
parameter_list|(
name|idn
parameter_list|,
name|soru
parameter_list|)
block|{
comment|/* reference to a structure or union, with no definition */
specifier|register
name|struct
name|symtab
modifier|*
name|p
decl_stmt|;
specifier|register
name|NODE
modifier|*
name|q
decl_stmt|;
name|p
operator|=
operator|&
name|stab
index|[
name|idn
index|]
expr_stmt|;
switch|switch
condition|(
name|p
operator|->
name|stype
condition|)
block|{
case|case
name|UNDEF
case|:
name|def
label|:
name|q
operator|=
name|block
argument_list|(
name|FREE
argument_list|,
name|NIL
argument_list|,
name|NIL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|q
operator|->
name|tn
operator|.
name|rval
operator|=
name|idn
expr_stmt|;
name|q
operator|->
name|in
operator|.
name|type
operator|=
operator|(
name|soru
operator|&
name|INSTRUCT
operator|)
condition|?
name|STRTY
else|:
operator|(
operator|(
name|soru
operator|&
name|INUNION
operator|)
condition|?
name|UNIONTY
else|:
name|ENUMTY
operator|)
expr_stmt|;
name|defid
argument_list|(
name|q
argument_list|,
operator|(
name|soru
operator|&
name|INSTRUCT
operator|)
condition|?
name|STNAME
else|:
operator|(
operator|(
name|soru
operator|&
name|INUNION
operator|)
condition|?
name|UNAME
else|:
name|ENAME
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|STRTY
case|:
if|if
condition|(
name|soru
operator|&
name|INSTRUCT
condition|)
break|break;
goto|goto
name|def
goto|;
case|case
name|UNIONTY
case|:
if|if
condition|(
name|soru
operator|&
name|INUNION
condition|)
break|break;
goto|goto
name|def
goto|;
case|case
name|ENUMTY
case|:
if|if
condition|(
operator|!
operator|(
name|soru
operator|&
operator|(
name|INUNION
operator||
name|INSTRUCT
operator|)
operator|)
condition|)
break|break;
goto|goto
name|def
goto|;
block|}
name|stwart
operator|=
name|instruct
expr_stmt|;
return|return
operator|(
name|mkty
argument_list|(
name|p
operator|->
name|stype
argument_list|,
literal|0
argument_list|,
name|p
operator|->
name|sizoff
argument_list|)
operator|)
return|;
block|}
end_function

begin_macro
name|moedef
argument_list|(
argument|idn
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|NODE
modifier|*
name|q
decl_stmt|;
name|q
operator|=
name|block
argument_list|(
name|FREE
argument_list|,
name|NIL
argument_list|,
name|NIL
argument_list|,
name|MOETY
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|q
operator|->
name|tn
operator|.
name|rval
operator|=
name|idn
expr_stmt|;
if|if
condition|(
name|idn
operator|>=
literal|0
condition|)
name|defid
argument_list|(
name|q
argument_list|,
name|MOE
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|bstruct
argument_list|(
argument|idn
argument_list|,
argument|soru
argument_list|)
end_macro

begin_block
block|{
comment|/* begining of structure or union declaration */
specifier|register
name|NODE
modifier|*
name|q
decl_stmt|;
name|psave
argument_list|(
name|instruct
argument_list|)
expr_stmt|;
name|psave
argument_list|(
name|curclass
argument_list|)
expr_stmt|;
name|psave
argument_list|(
name|strucoff
argument_list|)
expr_stmt|;
name|strucoff
operator|=
literal|0
expr_stmt|;
name|instruct
operator|=
name|soru
expr_stmt|;
name|q
operator|=
name|block
argument_list|(
name|FREE
argument_list|,
name|NIL
argument_list|,
name|NIL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|q
operator|->
name|tn
operator|.
name|rval
operator|=
name|idn
expr_stmt|;
if|if
condition|(
name|instruct
operator|==
name|INSTRUCT
condition|)
block|{
name|curclass
operator|=
name|MOS
expr_stmt|;
name|q
operator|->
name|in
operator|.
name|type
operator|=
name|STRTY
expr_stmt|;
if|if
condition|(
name|idn
operator|>=
literal|0
condition|)
name|defid
argument_list|(
name|q
argument_list|,
name|STNAME
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|instruct
operator|==
name|INUNION
condition|)
block|{
name|curclass
operator|=
name|MOU
expr_stmt|;
name|q
operator|->
name|in
operator|.
name|type
operator|=
name|UNIONTY
expr_stmt|;
if|if
condition|(
name|idn
operator|>=
literal|0
condition|)
name|defid
argument_list|(
name|q
argument_list|,
name|UNAME
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* enum */
name|curclass
operator|=
name|MOE
expr_stmt|;
name|q
operator|->
name|in
operator|.
name|type
operator|=
name|ENUMTY
expr_stmt|;
if|if
condition|(
name|idn
operator|>=
literal|0
condition|)
name|defid
argument_list|(
name|q
argument_list|,
name|ENAME
argument_list|)
expr_stmt|;
block|}
name|psave
argument_list|(
name|idn
operator|=
name|q
operator|->
name|tn
operator|.
name|rval
argument_list|)
expr_stmt|;
comment|/* the "real" definition is where the members are seen */
if|if
condition|(
name|idn
operator|>=
literal|0
condition|)
name|stab
index|[
name|idn
index|]
operator|.
name|suse
operator|=
name|lineno
expr_stmt|;
return|return
operator|(
name|paramno
operator|-
literal|4
operator|)
return|;
block|}
end_block

begin_function
name|NODE
modifier|*
name|dclstruct
parameter_list|(
name|oparam
parameter_list|)
block|{
specifier|register
name|struct
name|symtab
modifier|*
name|p
decl_stmt|;
specifier|register
name|i
operator|,
name|al
operator|,
name|sa
operator|,
name|j
operator|,
name|sz
operator|,
name|szindex
expr_stmt|;
specifier|register
name|TWORD
name|temp
decl_stmt|;
specifier|register
name|high
operator|,
name|low
expr_stmt|;
comment|/* paramstk contains: 		paramstk[ oparam ] = previous instruct 		paramstk[ oparam+1 ] = previous class 		paramstk[ oparam+2 ] = previous strucoff 		paramstk[ oparam+3 ] = structure name  		paramstk[ oparam+4, ... ]  = member stab indices  		*/
if|if
condition|(
operator|(
name|i
operator|=
name|paramstk
index|[
name|oparam
operator|+
literal|3
index|]
operator|)
operator|<
literal|0
condition|)
block|{
name|szindex
operator|=
name|curdim
expr_stmt|;
name|dstash
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* size */
name|dstash
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* index to member names */
name|dstash
argument_list|(
name|ALSTRUCT
argument_list|)
expr_stmt|;
comment|/* alignment */
name|dstash
argument_list|(
operator|-
name|lineno
argument_list|)
expr_stmt|;
comment|/* name of structure */
block|}
else|else
block|{
name|szindex
operator|=
name|stab
index|[
name|i
index|]
operator|.
name|sizoff
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"dclstruct( %.8s ), szindex = %d\n"
argument_list|,
operator|(
name|i
operator|>=
literal|0
operator|)
condition|?
name|stab
index|[
name|i
index|]
operator|.
name|sname
else|:
literal|"??"
argument_list|,
name|szindex
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"dclstruct( %s ), szindex = %d\n"
argument_list|,
operator|(
name|i
operator|>=
literal|0
operator|)
condition|?
name|stab
index|[
name|i
index|]
operator|.
name|sname
else|:
literal|"??"
argument_list|,
name|szindex
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
name|temp
operator|=
operator|(
name|instruct
operator|&
name|INSTRUCT
operator|)
condition|?
name|STRTY
else|:
operator|(
operator|(
name|instruct
operator|&
name|INUNION
operator|)
condition|?
name|UNIONTY
else|:
name|ENUMTY
operator|)
expr_stmt|;
name|stwart
operator|=
name|instruct
operator|=
name|paramstk
index|[
name|oparam
index|]
expr_stmt|;
name|curclass
operator|=
name|paramstk
index|[
name|oparam
operator|+
literal|1
index|]
expr_stmt|;
name|dimtab
index|[
name|szindex
operator|+
literal|1
index|]
operator|=
name|curdim
expr_stmt|;
name|al
operator|=
name|ALSTRUCT
expr_stmt|;
name|high
operator|=
name|low
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
name|oparam
operator|+
literal|4
init|;
name|i
operator|<
name|paramno
condition|;
operator|++
name|i
control|)
block|{
name|dstash
argument_list|(
name|j
operator|=
name|paramstk
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|j
operator|<
literal|0
operator|||
name|j
operator|>=
name|SYMTSZ
condition|)
name|cerror
argument_list|(
literal|"gummy structure member"
argument_list|)
expr_stmt|;
name|p
operator|=
operator|&
name|stab
index|[
name|j
index|]
expr_stmt|;
if|if
condition|(
name|temp
operator|==
name|ENUMTY
condition|)
block|{
if|if
condition|(
name|p
operator|->
name|offset
operator|<
name|low
condition|)
name|low
operator|=
name|p
operator|->
name|offset
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|offset
operator|>
name|high
condition|)
name|high
operator|=
name|p
operator|->
name|offset
expr_stmt|;
name|p
operator|->
name|sizoff
operator|=
name|szindex
expr_stmt|;
continue|continue;
block|}
name|sa
operator|=
name|talign
argument_list|(
name|p
operator|->
name|stype
argument_list|,
name|p
operator|->
name|sizoff
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|sclass
operator|&
name|FIELD
condition|)
block|{
name|sz
operator|=
name|p
operator|->
name|sclass
operator|&
name|FLDSIZ
expr_stmt|;
block|}
else|else
block|{
name|sz
operator|=
name|tsize
argument_list|(
name|p
operator|->
name|stype
argument_list|,
name|p
operator|->
name|dimoff
argument_list|,
name|p
operator|->
name|sizoff
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sz
operator|==
literal|0
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|werror
argument_list|(
literal|"illegal zero sized structure member: %.8s"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
else|#
directive|else
name|werror
argument_list|(
literal|"illegal zero sized structure member: %s"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|sz
operator|>
name|strucoff
condition|)
name|strucoff
operator|=
name|sz
expr_stmt|;
comment|/* for use with unions */
name|SETOFF
argument_list|(
name|al
argument_list|,
name|sa
argument_list|)
expr_stmt|;
comment|/* set al, the alignment, to the lcm of the alignments of the members */
block|}
name|dstash
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* endmarker */
name|SETOFF
argument_list|(
name|strucoff
argument_list|,
name|al
argument_list|)
expr_stmt|;
if|if
condition|(
name|temp
operator|==
name|ENUMTY
condition|)
block|{
specifier|register
name|TWORD
name|ty
decl_stmt|;
ifdef|#
directive|ifdef
name|ENUMSIZE
name|ty
operator|=
name|ENUMSIZE
argument_list|(
name|high
argument_list|,
name|low
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
operator|(
name|char
operator|)
name|high
operator|==
name|high
operator|&&
operator|(
name|char
operator|)
name|low
operator|==
name|low
condition|)
name|ty
operator|=
name|ctype
argument_list|(
name|CHAR
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|short
operator|)
name|high
operator|==
name|high
operator|&&
operator|(
name|short
operator|)
name|low
operator|==
name|low
condition|)
name|ty
operator|=
name|ctype
argument_list|(
name|SHORT
argument_list|)
expr_stmt|;
else|else
name|ty
operator|=
name|ctype
argument_list|(
name|INT
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|strucoff
operator|=
name|tsize
argument_list|(
name|ty
argument_list|,
literal|0
argument_list|,
operator|(
name|int
operator|)
name|ty
argument_list|)
expr_stmt|;
name|dimtab
index|[
name|szindex
operator|+
literal|2
index|]
operator|=
name|al
operator|=
name|talign
argument_list|(
name|ty
argument_list|,
operator|(
name|int
operator|)
name|ty
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|strucoff
operator|==
literal|0
condition|)
name|uerror
argument_list|(
literal|"zero sized structure"
argument_list|)
expr_stmt|;
name|dimtab
index|[
name|szindex
index|]
operator|=
name|strucoff
expr_stmt|;
name|dimtab
index|[
name|szindex
operator|+
literal|2
index|]
operator|=
name|al
expr_stmt|;
name|dimtab
index|[
name|szindex
operator|+
literal|3
index|]
operator|=
name|paramstk
index|[
name|oparam
operator|+
literal|3
index|]
expr_stmt|;
comment|/* name index */
name|FIXSTRUCT
argument_list|(
name|szindex
argument_list|,
name|oparam
argument_list|)
expr_stmt|;
comment|/* local hook, eg. for sym debugger */
ifndef|#
directive|ifndef
name|BUG1
if|if
condition|(
name|ddebug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"\tdimtab[%d,%d,%d] = %d,%d,%d\n"
argument_list|,
name|szindex
argument_list|,
name|szindex
operator|+
literal|1
argument_list|,
name|szindex
operator|+
literal|2
argument_list|,
name|dimtab
index|[
name|szindex
index|]
argument_list|,
name|dimtab
index|[
name|szindex
operator|+
literal|1
index|]
argument_list|,
name|dimtab
index|[
name|szindex
operator|+
literal|2
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|dimtab
index|[
name|szindex
operator|+
literal|1
index|]
init|;
name|dimtab
index|[
name|i
index|]
operator|>=
literal|0
condition|;
operator|++
name|i
control|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"\tmember %.8s(%d)\n"
argument_list|,
name|stab
index|[
name|dimtab
index|[
name|i
index|]
index|]
operator|.
name|sname
argument_list|,
name|dimtab
index|[
name|i
index|]
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"\tmember %s(%d)\n"
argument_list|,
name|stab
index|[
name|dimtab
index|[
name|i
index|]
index|]
operator|.
name|sname
argument_list|,
name|dimtab
index|[
name|i
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
endif|#
directive|endif
name|strucoff
operator|=
name|paramstk
index|[
name|oparam
operator|+
literal|2
index|]
expr_stmt|;
name|paramno
operator|=
name|oparam
expr_stmt|;
return|return
operator|(
name|mkty
argument_list|(
name|temp
argument_list|,
literal|0
argument_list|,
name|szindex
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* VARARGS */
end_comment

begin_macro
name|yyerror
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* error printing routine in parser */
name|uerror
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|yyaccpt
argument_list|()
end_macro

begin_block
block|{
name|ftnend
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|ftnarg
argument_list|(
argument|idn
argument_list|)
end_macro

begin_block
block|{
switch|switch
condition|(
name|stab
index|[
name|idn
index|]
operator|.
name|stype
condition|)
block|{
case|case
name|UNDEF
case|:
comment|/* this parameter, entered at scan */
break|break;
case|case
name|FARG
case|:
ifndef|#
directive|ifndef
name|FLEXNAMES
name|uerror
argument_list|(
literal|"redeclaration of formal parameter, %.8s"
argument_list|,
else|#
directive|else
argument|uerror(
literal|"redeclaration of formal parameter, %s"
argument|,
endif|#
directive|endif
argument|stab[idn].sname);
comment|/* fall thru */
argument|case FTN:
comment|/* the name of this function matches parm */
comment|/* fall thru */
argument|default: 		idn = hide(&stab[idn]); 		break; 	case TNULL:
comment|/* unused entry, fill it */
argument|; 		} 	stab[idn].stype = FARG; 	stab[idn].sclass = PARAM; 	psave( idn ); 	}  talign( ty, s) register unsigned ty; register s; {
comment|/* compute the alignment of an object with type ty, sizeoff index s */
argument|register i; 	if( s<
literal|0
argument|&& ty!=INT&& ty!=CHAR&& ty!=SHORT&& ty!=UNSIGNED&& ty!=UCHAR&& ty!=USHORT
ifdef|#
directive|ifdef
name|LONGFIELDS
argument|&& ty!=LONG&& ty!=ULONG
endif|#
directive|endif
argument|){ 		return( fldal( ty ) ); 		}  	for( i=
literal|0
argument|; i<=(SZINT-BTSHIFT-
literal|1
argument|); i+=TSHIFT ){ 		switch( (ty>>i)&TMASK ){  		case FTN: 			uerror(
literal|"can't assign to function"
argument|); 			return( ALCHAR ); 		case PTR: 			return( ALPOINT ); 		case ARY: 			continue; 		case
literal|0
argument|: 			break; 			} 		}  	switch( BTYPE(ty) ){  	case UNIONTY: 	case ENUMTY: 	case STRTY: 		return( (unsigned int) dimtab[ s+
literal|2
argument|] ); 	case CHAR: 	case UCHAR: 		return( ALCHAR ); 	case FLOAT: 		return( ALFLOAT ); 	case DOUBLE: 		return( ALDOUBLE ); 	case LONG: 	case ULONG: 		return( ALLONG ); 	case SHORT: 	case USHORT: 		return( ALSHORT ); 	default: 		return( ALINT ); 		} 	}  OFFSZ tsize( ty, d, s )  TWORD ty; {
comment|/* compute the size associated with type ty, 	    dimoff d, and sizoff s */
comment|/* BETTER NOT BE CALLED WHEN t, d, and s REFER TO A BIT FIELD... */
argument|int i; 	OFFSZ mult;  	mult =
literal|1
argument|;  	for( i=
literal|0
argument|; i<=(SZINT-BTSHIFT-
literal|1
argument|); i+=TSHIFT ){ 		switch( (ty>>i)&TMASK ){  		case FTN:
comment|/* cerror( "compiler takes size of function"); */
argument|uerror(
literal|"can't take size of function"
argument|); 			return( SZCHAR ); 		case PTR: 			return( SZPOINT * mult ); 		case ARY: 			mult *= (unsigned int) dimtab[ d++ ]; 			continue; 		case
literal|0
argument|: 			break;  			} 		}  	if( dimtab[s]==
literal|0
argument|) { 		if( ty == STRTY ) 			uerror(
literal|"undefined structure"
argument|); 		else 			uerror(
literal|"unknown size"
argument|); 		return( SZINT ); 		} 	return( (unsigned int) dimtab[ s ] * mult ); 	}  inforce( n ) OFFSZ n; {
comment|/* force inoff to have the value n */
comment|/* inoff is updated to have the value n */
argument|OFFSZ wb; 	register rest;
comment|/* rest is used to do a lot of conversion to ints... */
argument|if( inoff == n ) return; 	if( inoff> n ) { 		cerror(
literal|"initialization alignment error"
argument|); 		}  	wb = inoff; 	SETOFF( wb, SZINT );
comment|/* wb now has the next higher word boundary */
argument|if( wb>= n ){
comment|/* in the same word */
argument|rest = n - inoff; 		vfdzero( rest ); 		return; 		}
comment|/* otherwise, extend inoff to be word aligned */
argument|rest = wb - inoff; 	vfdzero( rest );
comment|/* now, skip full words until near to n */
argument|rest = (n-inoff)/SZINT; 	zecode( rest );
comment|/* now, the remainder of the last word */
argument|rest = n-inoff; 	vfdzero( rest ); 	if( inoff != n ) cerror(
literal|"inoff error"
argument|);  	}  vfdalign( n ){
comment|/* make inoff have the offset the next alignment of n */
argument|OFFSZ m;  	m = inoff; 	SETOFF( m, n ); 	inforce( m ); 	}   int idebug =
literal|0
argument|;  int ibseen =
literal|0
argument|;
comment|/* the number of } constructions which have been filled */
argument|int ifull =
literal|0
argument|;
comment|/* 1 if all initializers have been seen */
argument|int iclass;
comment|/* storage class of thing being initialized */
argument|int ilocctr =
literal|0
argument|;
comment|/* location counter for current initialization */
argument|beginit(curid){
comment|/* beginning of initilization; set location ctr and set type */
argument|register struct symtab *p;
ifndef|#
directive|ifndef
name|BUG1
argument|if( idebug>=
literal|3
argument|) printf(
literal|"beginit(), curid = %d\n"
argument|, curid );
endif|#
directive|endif
argument|p =&stab[curid];  	iclass = p->sclass; 	if( curclass == EXTERN || curclass == FORTRAN ) iclass = EXTERN; 	switch( iclass ){  	case UNAME: 	case EXTERN: 		return; 	case AUTO: 	case REGISTER: 		break; 	case EXTDEF: 	case STATIC: 		ilocctr = ISARY(p->stype)?ADATA:DATA; 		if( nerrors ==
literal|0
argument|){ 			(void) locctr( ilocctr ); 			defalign( talign( p->stype, p->sizoff ) ); 			defnam( p ); 			}  		}  	inoff =
literal|0
argument|; 	ibseen =
literal|0
argument|; 	ifull =
literal|0
argument|;  	pstk =
literal|0
argument|;  	instk( curid, p->stype, p->dimoff, p->sizoff, inoff );  	}  instk( id, t, d, s, off ) OFFSZ off; TWORD t; {
comment|/* make a new entry on the parameter stack to initialize id */
argument|register struct symtab *p;  	for(;;){
ifndef|#
directive|ifndef
name|BUG1
argument|if( idebug ) printf(
literal|"instk((%d, %o,%d,%d, %d)\n"
argument|, id, t, d, s, off );
endif|#
directive|endif
comment|/* save information on the stack */
argument|if( !pstk ) pstk = instack; 		else ++pstk;  		pstk->in_fl =
literal|0
argument|;
comment|/* { flag */
argument|pstk->in_id =  id ; 		pstk->in_t =  t ; 		pstk->in_d =  d ; 		pstk->in_s =  s ; 		pstk->in_n =
literal|0
argument|;
comment|/* number seen */
argument|pstk->in_x =  t==STRTY ?dimtab[s+
literal|1
argument|] :
literal|0
argument|; 		pstk->in_off =  off;
comment|/* offset at the beginning of this element */
comment|/* if t is an array, DECREF(t) can't be a field */
comment|/* INS_sz has size of array elements, and -size for fields */
argument|if( ISARY(t) ){ 			pstk->in_sz = tsize( DECREF(t), d+
literal|1
argument|, s ); 			} 		else if( stab[id].sclass& FIELD ){ 			pstk->in_sz = - ( stab[id].sclass& FLDSIZ ); 			} 		else { 			pstk->in_sz =
literal|0
argument|; 			}  		if( (iclass==AUTO || iclass == REGISTER )&& 			(ISARY(t) || t==STRTY) ) uerror(
literal|"no automatic aggregate initialization"
argument|);
comment|/* now, if this is not a scalar, put on another element */
argument|if( ISARY(t) ){ 			t = DECREF(t); 			++d; 			continue; 			} 		else if( t == STRTY ){ 			if( dimtab[pstk->in_s] ==
literal|0
argument|){ 				uerror(
literal|"can't initialize undefined structure"
argument|); 				iclass = -
literal|1
argument|; 				return; 				} 			id = dimtab[pstk->in_x]; 			p =&stab[id]; 			if( p->sclass != MOS&& !(p->sclass&FIELD) ) cerror(
literal|"insane structure member list"
argument|); 			t = p->stype; 			d = p->dimoff; 			s = p->sizoff; 			off += p->offset; 			continue; 			} 		else return; 		} 	}  NODE * getstr(){
comment|/* decide if the string is external or an initializer, and get the contents accordingly */
argument|register l
argument_list|,
argument|temp; 	register NODE *p;  	if( (iclass==EXTDEF||iclass==STATIC)&& (pstk->in_t == CHAR || pstk->in_t == UCHAR)&& 			pstk!=instack&& ISARY( pstk[-
literal|1
argument|].in_t ) ){
comment|/* treat "abc" as { 'a', 'b', 'c', 0 } */
argument|strflg =
literal|1
argument|; 		ilbrace();
comment|/* simulate { */
argument|inforce( pstk->in_off );
comment|/* if the array is inflexible (not top level), pass in the size and 			be prepared to throw away unwanted initializers */
argument|lxstr((pstk-
literal|1
argument|)!=instack?dimtab[(pstk-
literal|1
argument|)->in_d]:
literal|0
argument|);
comment|/* get the contents */
argument|irbrace();
comment|/* simulate } */
argument|return( NIL ); 		} 	else {
comment|/* make a label, and get the contents and stash them away */
argument|if( iclass != SNULL ){
comment|/* initializing */
comment|/* fill out previous word, to permit pointer */
argument|vfdalign( ALPOINT ); 			} 		temp = locctr( blevel==
literal|0
argument|?ISTRNG:STRNG );
comment|/* set up location counter */
argument|deflab( l = getlab() ); 		strflg =
literal|0
argument|; 		lxstr(
literal|0
argument|);
comment|/* get the contents */
argument|(void) locctr( blevel==
literal|0
argument|?ilocctr:temp ); 		p = buildtree( STRING, NIL, NIL ); 		p->tn.rval = -l; 		return(p); 		} 	}  putbyte( v ){
comment|/* simulate byte v appearing in a list of integer values */
argument|register NODE *p; 	p = bcon(v); 	incode( p, SZCHAR ); 	tfree( p ); 	gotscal(); 	}  endinit(){ 	register TWORD t; 	register d
argument_list|,
argument|s
argument_list|,
argument|n
argument_list|,
argument|d1;
ifndef|#
directive|ifndef
name|BUG1
argument|if( idebug ) printf(
literal|"endinit(), inoff = %d\n"
argument|, inoff );
endif|#
directive|endif
argument|switch( iclass ){  	case EXTERN: 	case AUTO: 	case REGISTER: 	case -
literal|1
argument|: 		return; 		}  	pstk = instack;  	t = pstk->in_t; 	d = pstk->in_d; 	s = pstk->in_s; 	n = pstk->in_n;  	if( ISARY(t) ){ 		d1 = dimtab[d];  		vfdalign( pstk->in_sz );
comment|/* fill out part of the last element, if needed */
argument|n = inoff/pstk->in_sz;
comment|/* real number of initializers */
argument|if( d1>= n ){
comment|/* once again, t is an array, so no fields */
argument|inforce( tsize( t, d, s ) ); 			n = d1; 			} 		if( d1!=
literal|0
argument|&& d1!=n ) uerror(
literal|"too many initializers"
argument|); 		if( n==
literal|0
argument|) werror(
literal|"empty array declaration"
argument|); 		dimtab[d] = n; 		if( d1==
literal|0
argument|) FIXDEF(&stab[pstk->in_id]); 		}  	else if( t == STRTY || t == UNIONTY ){
comment|/* clearly not fields either */
argument|inforce( tsize( t, d, s ) ); 		} 	else if( n>
literal|1
argument|) uerror(
literal|"bad scalar initialization"
argument|);
comment|/* this will never be called with a field element... */
argument|else inforce( tsize(t,d,s) );  	paramno =
literal|0
argument|; 	vfdalign( AL_INIT ); 	inoff =
literal|0
argument|; 	iclass = SNULL;  	}  fixinit(){
comment|/* called from the grammar if we must punt during initialization */
comment|/* stolen from endinit() */
argument|pstk = instack; 	paramno =
literal|0
argument|; 	vfdalign( AL_INIT ); 	inoff =
literal|0
argument|; 	iclass = SNULL; 	}  doinit( p ) register NODE *p; {
comment|/* take care of generating a value for the initializer p */
comment|/* inoff has the current offset (last bit written) 		in the current word being generated */
argument|register sz
argument_list|,
argument|d
argument_list|,
argument|s; 	register TWORD t; 	int o;
comment|/* note: size of an individual initializer is assumed to fit into an int */
argument|if( iclass<
literal|0
argument|) goto leave; 	if( iclass == EXTERN || iclass == UNAME ){ 		uerror(
literal|"cannot initialize extern or union"
argument|); 		iclass = -
literal|1
argument|; 		goto leave; 		}  	if( iclass == AUTO || iclass == REGISTER ){
comment|/* do the initialization and get out, without regard  		    for filing out the variable with zeros, etc. */
argument|bccode(); 		idname = pstk->in_id; 		p = buildtree( ASSIGN, buildtree( NAME, NIL, NIL ), p ); 		ecomp(p); 		return; 		}  	if( p == NIL ) return;
comment|/* for throwing away strings that have been turned into lists */
argument|if( ifull ){ 		uerror(
literal|"too many initializers"
argument|); 		iclass = -
literal|1
argument|; 		goto leave; 		} 	if( ibseen ){ 		uerror(
literal|"} expected"
argument|); 		goto leave; 		}
ifndef|#
directive|ifndef
name|BUG1
argument|if( idebug>
literal|1
argument|) printf(
literal|"doinit(%o)\n"
argument|, p );
endif|#
directive|endif
argument|t = pstk->in_t;
comment|/* type required */
argument|d = pstk->in_d; 	s = pstk->in_s; 	if( pstk->in_sz<
literal|0
argument|){
comment|/* bit field */
argument|sz = -pstk->in_sz; 		} 	else { 		sz = tsize( t, d, s ); 		}  	inforce( pstk->in_off );  	p = buildtree( ASSIGN, block( NAME, NIL,NIL, t, d, s ), p );
ifdef|#
directive|ifdef
name|LINT
comment|/* force lint to treat this like an assignment */
argument|ecode(p);
endif|#
directive|endif
argument|p->in.left->in.op = FREE; 	p->in.left = p->in.right; 	p->in.right = NIL; 	p->in.left = optim( p->in.left ); 	o = p->in.left->in.op; 	if( o == UNARY AND ){ 		o = p->in.left->in.op = FREE; 		p->in.left = p->in.left->in.left; 		} 	p->in.op = INIT;  	if( sz< SZINT ){
comment|/* special case: bit fields, etc. */
argument|if( o != ICON || p->in.left->tn.rval != NONAME ) 			uerror(
literal|"illegal initialization"
argument|); 		else incode( p->in.left, sz ); 		} 	else if( o == FCON ){ 		fincode( p->in.left->fpn.fval, sz ); 		} 	else if( o == DCON ){ 		fincode( p->in.left->dpn.dval, sz ); 		} 	else { 		p = optim(p); 		if( p->in.left->in.op != ICON ) uerror(
literal|"illegal initialization"
argument|); 		else cinit( p, sz ); 		}  	gotscal();  	leave: 	tfree(p); 	}  gotscal(){ 	register t
argument_list|,
argument|ix; 	register n
argument_list|,
argument|id; 	struct symtab *p; 	OFFSZ temp;  	for( ; pstk> instack; ) {  		if( pstk->in_fl ) ++ibseen;  		--pstk; 		 		t = pstk->in_t;  		if( t == STRTY ){ 			ix = ++pstk->in_x; 			if( (id=dimtab[ix])<
literal|0
argument|) continue;
comment|/* otherwise, put next element on the stack */
argument|p =&stab[id]; 			instk( id, p->stype, p->dimoff, p->sizoff, p->offset+pstk->in_off ); 			return; 			} 		else if( ISARY(t) ){ 			n = ++pstk->in_n; 			if( n>= dimtab[pstk->in_d]&& pstk> instack ) continue;
comment|/* put the new element onto the stack */
argument|temp = pstk->in_sz; 			instk( pstk->in_id, (TWORD)DECREF(pstk->in_t), pstk->in_d+
literal|1
argument|, pstk->in_s, 				pstk->in_off+n*temp ); 			return; 			}  		} 	ifull =
literal|1
argument|; 	}  ilbrace(){
comment|/* process an initializer's left brace */
argument|register t; 	struct instk *temp;  	temp = pstk;  	for( ; pstk> instack; --pstk ){  		t = pstk->in_t; 		if( t != STRTY&& !ISARY(t) ) continue;
comment|/* not an aggregate */
argument|if( pstk->in_fl ){
comment|/* already associated with a { */
argument|if( pstk->in_n ) uerror(
literal|"illegal {"
argument|); 			continue; 			}
comment|/* we have one ... */
argument|pstk->in_fl =
literal|1
argument|; 		break; 		}
comment|/* cannot find one */
comment|/* ignore such right braces */
argument|pstk = temp; 	}  irbrace(){
comment|/* called when a '}' is seen */
ifndef|#
directive|ifndef
name|BUG1
argument|if( idebug ) printf(
literal|"irbrace(): paramno = %d on entry\n"
argument|, paramno );
endif|#
directive|endif
argument|if( ibseen ) { 		--ibseen; 		return; 		}  	for( ; pstk> instack; --pstk ){ 		if( !pstk->in_fl ) continue;
comment|/* we have one now */
argument|pstk->in_fl =
literal|0
argument|;
comment|/* cancel { */
argument|gotscal();
comment|/* take it away... */
argument|return; 		}
comment|/* these right braces match ignored left braces: throw out */
argument|ifull =
literal|1
argument|;  	}  upoff( size, alignment, poff ) register alignment
argument_list|,
argument|*poff; {
comment|/* update the offset pointed to by poff; return the 	/* offset of a value of size `size', alignment `alignment', 	/* given that off is increasing */
argument|register off;  	off = *poff; 	SETOFF( off, alignment ); 	if( (offsz-off)<  size ){ 		if( instruct!=INSTRUCT )cerror(
literal|"too many local variables"
argument|); 		else cerror(
literal|"Structure too large"
argument|); 		} 	*poff = off+size; 	return( off ); 	}  oalloc( p, poff ) register struct symtab *p; register *poff; {
comment|/* allocate p with offset *poff, and update *poff */
argument|register al
argument_list|,
argument|off
argument_list|,
argument|tsz; 	int noff;  	al = talign( p->stype, p->sizoff ); 	noff = off = *poff; 	tsz = tsize( p->stype, p->dimoff, p->sizoff );
ifdef|#
directive|ifdef
name|BACKAUTO
argument|if( p->sclass == AUTO ){ 		if( (offsz-off)< tsz ) cerror(
literal|"too many local variables"
argument|); 		noff = off + tsz; 		SETOFF( noff, al ); 		off = -noff; 		} 	else
endif|#
directive|endif
argument|if( p->sclass == PARAM&& ( tsz< SZINT ) ){ 			off = upoff( SZINT, ALINT,&noff );
ifndef|#
directive|ifndef
name|RTOLBYTES
argument|off = noff - tsz;
endif|#
directive|endif
argument|} 		else 		{ 		off = upoff( tsz, al,&noff ); 		}  	if( p->sclass != REGISTER ){
comment|/* in case we are allocating stack space for register arguments */
argument|if( p->offset == NOOFFSET ) p->offset = off; 		else if( off != p->offset ) return(
literal|1
argument|); 		}  	*poff = noff; 	return(
literal|0
argument|); 	}  falloc( p, w, new, pty )  register struct symtab *p; NODE *pty; {
comment|/* allocate a field of width w */
comment|/* new is 0 if new entry, 1 if redefinition, -1 if alignment */
argument|register al
argument_list|,
argument|sz
argument_list|,
argument|type;  	type = (new<
literal|0
argument|)? pty->in.type : p->stype;
comment|/* this must be fixed to use the current type in alignments */
argument|switch( new<
literal|0
argument|?pty->in.type:p->stype ){  	case ENUMTY: 		{ 			int s; 			s = new<
literal|0
argument|? pty->fn.csiz : p->sizoff; 			al = dimtab[s+
literal|2
argument|]; 			sz = dimtab[s]; 			break; 			}  	case CHAR: 	case UCHAR: 		al = ALCHAR; 		sz = SZCHAR; 		break;  	case SHORT: 	case USHORT: 		al = ALSHORT; 		sz = SZSHORT; 		break;  	case INT: 	case UNSIGNED: 		al = ALINT; 		sz = SZINT; 		break;
ifdef|#
directive|ifdef
name|LONGFIELDS
argument|case LONG: 	case ULONG: 		al = ALLONG; 		sz = SZLONG; 		break;
endif|#
directive|endif
argument|default: 		if( new<
literal|0
argument|) { 			uerror(
literal|"illegal field type"
argument|); 			al = ALINT; 			} 		else { 			al = fldal( p->stype ); 			sz =SZINT; 			} 		}  	if( w> sz ) { 		uerror(
literal|"field too big"
argument|); 		w = sz; 		}  	if( w ==
literal|0
argument|){
comment|/* align only */
argument|SETOFF( strucoff, al ); 		if( new>=
literal|0
argument|) uerror(
literal|"zero size field"
argument|); 		return(
literal|0
argument|); 		}  	if( strucoff%al + w> sz ) SETOFF( strucoff, al ); 	if( new<
literal|0
argument|) { 		if( (offsz-strucoff)< w ) 			cerror(
literal|"structure too large"
argument|); 		strucoff += w;
comment|/* we know it will fit */
argument|return(
literal|0
argument|); 		}
comment|/* establish the field */
argument|if( new ==
literal|1
argument|) {
comment|/* previous definition */
argument|if( p->offset != strucoff || p->sclass != (FIELD|w) ) return(
literal|1
argument|); 		} 	p->offset = strucoff; 	if( (offsz-strucoff)< w ) cerror(
literal|"structure too large"
argument|); 	strucoff += w; 	p->stype = type; 	fldty( p ); 	return(
literal|0
argument|); 	}  nidcl( p ) NODE *p; {
comment|/* handle unitialized declarations */
comment|/* assumed to be not functions */
argument|register class; 	register commflag;
comment|/* flag for labelled common declarations */
argument|commflag =
literal|0
argument|;
comment|/* compute class */
argument|if( (class=curclass) == SNULL ){ 		if( blevel>
literal|1
argument|) class = AUTO; 		else if( blevel !=
literal|0
argument||| instruct ) cerror(
literal|"nidcl error"
argument|); 		else {
comment|/* blevel = 0 */
argument|class = noinit(); 			if( class == EXTERN ) commflag =
literal|1
argument|; 			} 		}
ifdef|#
directive|ifdef
name|LCOMM
comment|/* hack so stab will come out as LCSYM rather than STSYM */
argument|if (class == STATIC) { 		extern int stabLCSYM; 		stabLCSYM =
literal|1
argument|; 	}
endif|#
directive|endif
argument|defid( p, class );
comment|/* if an array is not initialized, no empty dimension */
argument|if( class!=EXTERN&& class!=TYPEDEF&& 	    ISARY(p->in.type)&& dimtab[p->fn.cdim]==
literal|0
argument|) 		uerror(
literal|"null storage definition"
argument|);
ifndef|#
directive|ifndef
name|LCOMM
argument|if( class==EXTDEF || class==STATIC )
else|#
directive|else
argument|if (class==STATIC) { 		register struct symtab *s =&stab[p->tn.rval]; 		extern int stabLCSYM; 		int sz = tsize(s->stype, s->dimoff, s->sizoff)/SZCHAR; 		 		stabLCSYM =
literal|0
argument|; 		if (sz % sizeof (int)) 			sz += sizeof (int) - (sz % sizeof (int)); 		if (s->slevel>
literal|1
argument|) 			printf(
literal|"	.lcomm	L%d,%d\n"
argument|, s->offset, sz); 		else 			printf(
literal|"	.lcomm	%s,%d\n"
argument|, exname(s->sname), sz); 	}else if (class == EXTDEF)
endif|#
directive|endif
argument|{
comment|/* simulate initialization by 0 */
argument|beginit(p->tn.rval); 		endinit(); 		} 	if( commflag ) commdec( p->tn.rval ); 	}  TWORD types( t1, t2, t3 ) TWORD t1
argument_list|,
argument|t2
argument_list|,
argument|t3; {
comment|/* return a basic type from basic types t1, t2, and t3 */
argument|TWORD t[
literal|3
argument|]
argument_list|,
argument|noun
argument_list|,
argument|adj
argument_list|,
argument|unsg; 	register i;  	t[
literal|0
argument|] = t1; 	t[
literal|1
argument|] = t2; 	t[
literal|2
argument|] = t3;  	unsg = INT;
comment|/* INT or UNSIGNED */
argument|noun = UNDEF;
comment|/* INT, CHAR, or FLOAT */
argument|adj = INT;
comment|/* INT, LONG, or SHORT */
argument|for( i=
literal|0
argument|; i<
literal|3
argument|; ++i ){ 		switch( t[i] ){  		default: 		bad: 			uerror(
literal|"illegal type combination"
argument|); 			return( INT );  		case UNDEF: 			continue;  		case UNSIGNED: 			if( unsg != INT ) goto bad; 			unsg = UNSIGNED; 			continue;  		case LONG: 		case SHORT: 			if( adj != INT ) goto bad; 			adj = t[i]; 			continue;  		case INT: 		case CHAR: 		case FLOAT: 			if( noun != UNDEF ) goto bad; 			noun = t[i]; 			continue; 			} 		}
comment|/* now, construct final type */
argument|if( noun == UNDEF ) noun = INT; 	else if( noun == FLOAT ){ 		if( unsg != INT || adj == SHORT ) goto bad; 		return( adj==LONG ? DOUBLE : FLOAT ); 		} 	else if( noun == CHAR&& adj != INT ) goto bad;
comment|/* now, noun is INT or CHAR */
argument|if( adj != INT ) noun = adj; 	if( unsg == UNSIGNED ) return( noun + (UNSIGNED-INT) ); 	else return( noun ); 	}  NODE * tymerge( typ, idp ) NODE *typ
argument_list|,
argument|*idp; {
comment|/* merge type typ with identifier idp  */
argument|register unsigned t; 	register i; 	extern int eprint();  	if( typ->in.op != TYPE ) cerror(
literal|"tymerge: arg 1"
argument|); 	if(idp == NIL ) return( NIL );
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug>
literal|2
argument|) fwalk( idp, eprint,
literal|0
argument|);
endif|#
directive|endif
argument|idp->in.type = typ->in.type; 	idp->fn.cdim = curdim; 	tyreduce( idp ); 	idp->fn.csiz = typ->fn.csiz;  	for( t=typ->in.type, i=typ->fn.cdim; t&TMASK; t = DECREF(t) ){ 		if( ISARY(t) ) dstash( dimtab[i++] ); 		}
comment|/* now idp is a single node: fix up type */
argument|idp->in.type = ctype( idp->in.type );  	if( (t = BTYPE(idp->in.type)) != STRTY&& t != UNIONTY&& t != ENUMTY ){ 		idp->fn.csiz = t;
comment|/* in case ctype has rewritten things */
argument|}  	return( idp ); 	}  tyreduce( p ) register NODE *p; {
comment|/* build a type, and stash away dimensions, from a parse tree of the declaration */
comment|/* the type is build top down, the dimensions bottom up */
argument|register o
argument_list|,
argument|temp; 	register unsigned t;  	o = p->in.op; 	p->in.op = FREE;  	if( o == NAME ) return;  	t = INCREF( p->in.type ); 	if( o == UNARY CALL ) t += (FTN-PTR); 	else if( o == LB ){ 		t += (ARY-PTR); 		temp = p->in.right->tn.lval; 		p->in.right->in.op = FREE; 		if( temp ==
literal|0
argument|&& p->in.left->tn.op == LB ) 			uerror(
literal|"null dimension"
argument|); 		}  	p->in.left->in.type = t; 	tyreduce( p->in.left );  	if( o == LB ) dstash( temp );  	p->tn.rval = p->in.left->tn.rval; 	p->in.type = p->in.left->in.type;  	}  fixtype( p, class ) register NODE *p; { 	register unsigned t
argument_list|,
argument|type; 	register mod1
argument_list|,
argument|mod2;
comment|/* fix up the types, and check for legality */
argument|if( (type = p->in.type) == UNDEF ) return; 	if( mod2 = (type&TMASK) ){ 		t = DECREF(type); 		while( mod1=mod2, mod2 = (t&TMASK) ){ 			if( mod1 == ARY&& mod2 == FTN ){ 				uerror(
literal|"array of functions is illegal"
argument|); 				type =
literal|0
argument|; 				} 			else if( mod1 == FTN&& ( mod2 == ARY || mod2 == FTN ) ){ 				uerror(
literal|"function returns illegal type"
argument|); 				type =
literal|0
argument|; 				} 			t = DECREF(t); 			} 		}
comment|/* detect function arguments, watching out for structure declarations */
comment|/* for example, beware of f(x) struct { int a[10]; } *x; { ... } */
comment|/* the danger is that "a" will be converted to a pointer */
argument|if( class==SNULL&& blevel==
literal|1
argument|&& !(instruct&(INSTRUCT|INUNION)) ) 		class = PARAM; 	if( class == PARAM || ( class==REGISTER&& blevel==
literal|1
argument|) ){ 		if( type == FLOAT ) type = DOUBLE; 		else if( ISARY(type) ){
ifdef|#
directive|ifdef
name|LINT
argument|if( hflag&& dimtab[p->fn.cdim]!=
literal|0
argument|) 				werror(
literal|"array[%d] type changed to pointer"
argument|, 					dimtab[p->fn.cdim]);
endif|#
directive|endif
argument|++p->fn.cdim; 			type += (PTR-ARY); 			} 		else if( ISFTN(type) ){ 			werror(
literal|"a function is declared as an argument"
argument|); 			type = INCREF(type); 			}  		}  	if( instruct&& ISFTN(type) ){ 		uerror(
literal|"function illegal in structure or union"
argument|); 		type = INCREF(type); 		} 	p->in.type = type; 	}  uclass( class ) register class; {
comment|/* give undefined version of class */
argument|if( class == SNULL ) return( EXTERN ); 	else if( class == STATIC ) return( USTATIC ); 	else if( class == FORTRAN ) return( UFORTRAN ); 	else return( class ); 	}  fixclass( class, type ) TWORD type; {
comment|/* first, fix null class */
argument|if( class == SNULL ){ 		if( instruct&INSTRUCT ) class = MOS; 		else if( instruct&INUNION ) class = MOU; 		else if( blevel ==
literal|0
argument|) class = EXTDEF; 		else if( blevel ==
literal|1
argument|) class = PARAM; 		else class = AUTO;  		}
comment|/* now, do general checking */
argument|if( ISFTN( type ) ){ 		switch( class ) { 		default: 			uerror(
literal|"function has illegal storage class"
argument|); 		case AUTO: 			class = EXTERN; 		case EXTERN: 		case EXTDEF: 		case FORTRAN: 		case TYPEDEF: 		case STATIC: 		case UFORTRAN: 		case USTATIC: 			; 			} 		}  	if( class&FIELD ){ 		if( !(instruct&INSTRUCT) ) uerror(
literal|"illegal use of field"
argument|); 		return( class ); 		}  	switch( class ){  	case MOU: 		if( !(instruct&INUNION) ) uerror(
literal|"illegal class"
argument|); 		return( class );  	case MOS: 		if( !(instruct&INSTRUCT) ) uerror(
literal|"illegal class"
argument|); 		return( class );  	case MOE: 		if( instruct& (INSTRUCT|INUNION) ) uerror(
literal|"illegal class"
argument|); 		return( class );  	case REGISTER: 		if( blevel ==
literal|0
argument|) uerror(
literal|"illegal register declaration"
argument|); 		else if( regvar>= MINRVAR&& cisreg( type ) ) return( class ); 		if( blevel ==
literal|1
argument|) return( PARAM ); 		else return( AUTO );  	case AUTO: 	case LABEL: 	case ULABEL: 		if( blevel<
literal|2
argument|) uerror(
literal|"illegal class"
argument|); 		return( class );  	case PARAM: 		if( blevel !=
literal|1
argument|) uerror(
literal|"illegal class"
argument|); 		return( class );  	case UFORTRAN: 	case FORTRAN:
ifdef|#
directive|ifdef
name|NOFORTRAN
argument|NOFORTRAN;
comment|/* a condition which can regulate the FORTRAN usage */
endif|#
directive|endif
argument|if( !ISFTN(type) ) uerror(
literal|"fortran declaration must apply to function"
argument|); 		else { 			type = DECREF(type); 			if( ISFTN(type) || ISARY(type) || ISPTR(type) ) { 				uerror(
literal|"fortran function has wrong type"
argument|); 				} 			} 	case EXTERN: 	case STATIC: 	case EXTDEF: 	case TYPEDEF: 	case USTATIC: 		if( blevel ==
literal|1
argument|){ 			uerror(
literal|"illegal class"
argument|); 			return( PARAM ); 			} 	case STNAME: 	case UNAME: 	case ENAME: 		return( class );  	default: 		cerror(
literal|"illegal class: %d"
argument|, class );
comment|/* NOTREACHED */
argument|} 	}  struct symtab * mknonuniq(idindex) int *idindex; {
comment|/* locate a symbol table entry for */
comment|/* an occurrence of a nonunique structure member name */
comment|/* or field */
argument|register i; 	register struct symtab * sp; 	char *q;  	sp =& stab[ i= *idindex ];
comment|/* position search at old entry */
argument|while( sp->stype != TNULL ){
comment|/* locate unused entry */
argument|if( ++i>= SYMTSZ ){
comment|/* wrap around symbol table */
argument|i =
literal|0
argument|; 			sp = stab; 			} 		else ++sp; 		if( i == *idindex ) cerror(
literal|"Symbol table full"
argument|); 		} 	sp->sflags = SNONUNIQ | SMOS; 	q = stab[*idindex].sname;
comment|/* old entry name */
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|sp->sname = stab[*idindex].sname;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ){ 		printf(
literal|"\tnonunique entry for %s from %d to %d\n"
argument|, 			q, *idindex, i ); 		}
endif|#
directive|endif
argument|*idindex = i;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|{ 		char *p = sp->sname; 		for( i=
literal|1
argument|; i<=NCHNAM; ++i )
comment|/* copy name */
argument|if( *p++ = *q
comment|/* assign */
argument|) ++q; 		}
endif|#
directive|endif
argument|return ( sp ); 	}  lookup( name, s) char *name; {
comment|/* look up name: must agree with s w.r.t. STAG, SMOS and SHIDDEN */
argument|register char *p
argument_list|,
argument|*q; 	int i
argument_list|,
argument|ii;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|int j;
endif|#
directive|endif
argument|register struct symtab *sp;
comment|/* compute initial hash index */
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug>
literal|2
argument|){ 		printf(
literal|"lookup( %s, %d ), stwart=%d, instruct=%d\n"
argument|, name, s, stwart, instruct ); 		}
endif|#
directive|endif
argument|i =
literal|0
argument|;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|for( p=name, j=
literal|0
argument|; *p !=
literal|'\0'
argument|; ++p ){ 		i += *p; 		if( ++j>= NCHNAM ) break; 		}
else|#
directive|else
argument|i = (int)name;
endif|#
directive|endif
argument|i = i%SYMTSZ; 	sp =&stab[ii=i];  	for(;;){
comment|/* look for name */
argument|if( sp->stype == TNULL ){
comment|/* empty slot */
argument|sp->sflags = s;
comment|/* set STAG, SMOS if needed, turn off all others */
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|p = sp->sname; 			for( j=
literal|0
argument|; j<NCHNAM; ++j ) if( *p++ = *name ) ++name;
else|#
directive|else
argument|sp->sname = name;
endif|#
directive|endif
argument|sp->stype = UNDEF; 			sp->sclass = SNULL; 			return( i ); 			} 		if( (sp->sflags& (STAG|SMOS|SHIDDEN)) != s ) goto next; 		p = sp->sname; 		q = name;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|for( j=
literal|0
argument|; j<NCHNAM;++j ){ 			if( *p++ != *q ) goto next; 			if( !*q++ ) break; 			} 		return( i );
else|#
directive|else
argument|if (p == q) 			return ( i );
endif|#
directive|endif
argument|next: 		if( ++i>= SYMTSZ ){ 			i =
literal|0
argument|; 			sp = stab; 			} 		else ++sp; 		if( i == ii ) cerror(
literal|"symbol table full"
argument|); 		} 	}
ifndef|#
directive|ifndef
name|checkst
comment|/* if not debugging, make checkst a macro */
argument|checkst(lev){ 	register int s
argument_list|,
argument|i
argument_list|,
argument|j; 	register struct symtab *p
argument_list|,
argument|*q;  	for( i=
literal|0
argument|, p=stab; i<SYMTSZ; ++i, ++p ){ 		if( p->stype == TNULL ) continue; 		j = lookup( p->sname, p->sflags&(SMOS|STAG) ); 		if( j != i ){ 			q =&stab[j]; 			if( q->stype == UNDEF || 			    q->slevel<= p->slevel ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|cerror(
literal|"check error: %.8s"
argument|, q->sname );
else|#
directive|else
argument|cerror(
literal|"check error: %s"
argument|, q->sname );
endif|#
directive|endif
argument|} 			}
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|else if( p->slevel> lev ) cerror(
literal|"%.8s check at level %d"
argument|, p->sname, lev );
else|#
directive|else
argument|else if( p->slevel> lev ) cerror(
literal|"%s check at level %d"
argument|, p->sname, lev );
endif|#
directive|endif
argument|} 	}
endif|#
directive|endif
argument|struct symtab * relook(p) register struct symtab *p; {
comment|/* look up p again, and see where it lies */
argument|register struct symtab *q;
comment|/* I'm not sure that this handles towers of several hidden definitions in all cases */
argument|q =&stab[lookup( p->sname, p->sflags&(STAG|SMOS|SHIDDEN) )];
comment|/* make relook always point to either p or an empty cell */
argument|if( q->stype == UNDEF ){ 		q->stype = TNULL; 		return(q); 		} 	while( q != p ){ 		if( q->stype == TNULL ) break; 		if( ++q>=&stab[SYMTSZ] ) q=stab; 		} 	return(q); 	}  clearst( lev ) register int lev; { 	register struct symtab *p
argument_list|,
argument|*q; 	register int temp; 	struct symtab *clist =
literal|0
argument|;  	temp = lineno; 	aobeg();
comment|/* step 1: remove entries */
argument|while( chaintop-
literal|1
argument|> lev ){ 		p = schain[--chaintop]; 		schain[chaintop] =
literal|0
argument|; 		for( ; p; p = q ){ 			q = p->snext; 			if( p->stype == TNULL || p->slevel<= lev ) 				cerror(
literal|"schain botch"
argument|); 			lineno = p->suse<
literal|0
argument|? -p->suse : p->suse; 			if( p->stype==UNDEF || ( p->sclass==ULABEL&& lev<
literal|2
argument|) ){ 				lineno = temp;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|uerror(
literal|"%.8s undefined"
argument|, p->sname );
else|#
directive|else
argument|uerror(
literal|"%s undefined"
argument|, p->sname );
endif|#
directive|endif
argument|} 			else aocode(p);
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"removing %.8s"
argument|, p->sname );
else|#
directive|else
argument|printf(
literal|"removing %s"
argument|, p->sname );
endif|#
directive|endif
argument|printf(
literal|" from stab[%d], flags %o level %d\n"
argument|, 					p-stab, p->sflags, p->slevel); 				}
endif|#
directive|endif
argument|if( p->sflags& SHIDES )unhide( p ); 			p->stype = TNULL; 			p->snext = clist; 			clist = p; 			} 		}
comment|/* step 2: fix any mishashed entries */
argument|p = clist; 	while( p ){ 		register struct symtab *next
argument_list|,
argument|**t
argument_list|,
argument|*r;  		q = p; 		next = p->snext; 		for(;;){ 			if( ++q>=&stab[SYMTSZ] )q = stab; 			if( q == p || q->stype == TNULL )break; 			if( (r = relook(q)) != q ) {
comment|/* move q in schain list */
argument|t =&schain[q->slevel]; 				while( *t&& *t != q ) 					t =&(*t)->snext; 				if( *t ) 					*t = r; 				else 					cerror(
literal|"schain botch 2"
argument|); 				*r = *q; 				q->stype = TNULL; 				} 			} 		p = next; 		}  	lineno = temp; 	aoend(); 	}  hide( p ) register struct symtab *p; { 	register struct symtab *q; 	for( q=p+
literal|1
argument|; ; ++q ){ 		if( q>=&stab[SYMTSZ] ) q = stab; 		if( q == p ) cerror(
literal|"symbol table full"
argument|); 		if( q->stype == TNULL ) break; 		} 	*q = *p; 	p->sflags |= SHIDDEN; 	q->sflags = (p->sflags&(SMOS|STAG)) | SHIDES;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( hflag ) werror(
literal|"%.8s redefinition hides earlier one"
argument|, p->sname );
else|#
directive|else
argument|if( hflag ) werror(
literal|"%s redefinition hides earlier one"
argument|, p->sname );
endif|#
directive|endif
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ) printf(
literal|"	%d hidden in %d\n"
argument|, p-stab, q-stab );
endif|#
directive|endif
argument|return( idname = q-stab ); 	}  unhide( p ) register struct symtab *p; { 	register struct symtab *q; 	register s;  	s = p->sflags& (SMOS|STAG); 	q = p;  	for(;;){  		if( q == stab ) q =&stab[SYMTSZ-
literal|1
argument|]; 		else --q;  		if( q == p ) break;  		if( (q->sflags&(SMOS|STAG)) == s ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|register j; 			for( j =
literal|0
argument|; j<NCHNAM; ++j ) if( p->sname[j] != q->sname[j] ) break; 			if( j == NCHNAM ){
comment|/* found the name */
else|#
directive|else
argument|if (p->sname == q->sname) {
endif|#
directive|endif
argument|q->sflags&= ~SHIDDEN;
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ) printf(
literal|"unhide uncovered %d from %d\n"
argument|, q-stab,p-stab);
endif|#
directive|endif
argument|return; 				} 			}  		} 	cerror(
literal|"unhide fails"
argument|); 	}
end_block

end_unit

