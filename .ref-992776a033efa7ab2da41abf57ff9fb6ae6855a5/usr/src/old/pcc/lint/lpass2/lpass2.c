begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)lpass2.c	1.1	(Berkeley)	%G%"
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
file|"manifest"
end_include

begin_include
include|#
directive|include
file|"lmanifest"
end_include

begin_define
define|#
directive|define
name|USED
value|01
end_define

begin_define
define|#
directive|define
name|VUSED
value|02
end_define

begin_define
define|#
directive|define
name|EUSED
value|04
end_define

begin_define
define|#
directive|define
name|RVAL
value|010
end_define

begin_define
define|#
directive|define
name|VARARGS
value|0100
end_define

begin_define
define|#
directive|define
name|NSZ
value|2048
end_define

begin_define
define|#
directive|define
name|TYSZ
value|3500
end_define

begin_define
define|#
directive|define
name|FSZ
value|250
end_define

begin_define
define|#
directive|define
name|NTY
value|50
end_define

begin_typedef
typedef|typedef
name|struct
name|sty
name|STYPE
typedef|;
end_typedef

begin_struct
struct|struct
name|sty
block|{
name|ATYPE
name|t
decl_stmt|;
name|STYPE
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|sym
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|char
name|name
index|[
name|LCHNM
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|name
decl_stmt|;
endif|#
directive|endif
name|short
name|nargs
decl_stmt|;
name|int
name|decflag
decl_stmt|;
name|int
name|fline
decl_stmt|;
name|STYPE
name|symty
decl_stmt|;
name|int
name|fno
decl_stmt|;
name|int
name|use
decl_stmt|;
block|}
name|STAB
typedef|;
end_typedef

begin_decl_stmt
name|STAB
name|stab
index|[
name|NSZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|STAB
modifier|*
name|find
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|STYPE
name|tary
index|[
name|TYSZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|STYPE
modifier|*
name|tget
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXNAMES
end_ifndef

begin_decl_stmt
name|char
name|fnm
index|[
name|FSZ
index|]
index|[
name|LFNM
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|fnm
index|[
name|FSZ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLEXNAMES
end_ifdef

begin_function_decl
name|char
modifier|*
name|getstr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|tfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to allocate types */
end_comment

begin_decl_stmt
name|int
name|ffree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to save filenames */
end_comment

begin_decl_stmt
name|struct
name|ty
name|atyp
index|[
name|NTY
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* r is where all the input ends up */
end_comment

begin_decl_stmt
name|union
name|rec
name|r
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ddddd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cfno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file number */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* first argument is intermediate file */
comment|/* second argument is - options */
for|for
control|(
init|;
name|argc
operator|>
literal|2
operator|&&
name|argv
index|[
name|argc
operator|-
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
condition|;
operator|--
name|argc
control|)
block|{
for|for
control|(
name|p
operator|=
name|argv
index|[
name|argc
operator|-
literal|1
index|]
init|;
operator|*
name|p
condition|;
operator|++
name|p
control|)
block|{
switch|switch
condition|(
operator|*
name|p
condition|)
block|{
case|case
literal|'h'
case|:
name|hflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
name|pflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|xflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'X'
case|:
name|ddddd
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|uflag
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|argc
operator|<
literal|2
operator|||
operator|!
name|freopen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"cannot open intermediate file"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|mloop
argument_list|(
name|LDI
operator||
name|LIB
argument_list|)
expr_stmt|;
name|rewind
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
name|mloop
argument_list|(
name|LDC
operator||
name|LDX
argument_list|)
expr_stmt|;
name|rewind
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
name|mloop
argument_list|(
name|LRV
operator||
name|LUV
operator||
name|LUE
operator||
name|LUM
argument_list|)
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_macro
name|mloop
argument_list|(
argument|m
argument_list|)
end_macro

begin_block
block|{
comment|/* do the main loop */
specifier|register
name|STAB
modifier|*
name|q
decl_stmt|;
while|while
condition|(
name|lread
argument_list|(
name|m
argument_list|)
condition|)
block|{
name|q
operator|=
name|find
argument_list|()
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|decflag
condition|)
name|chkcompat
argument_list|(
name|q
argument_list|)
expr_stmt|;
else|else
name|setuse
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|lread
argument_list|(
argument|m
argument_list|)
end_macro

begin_block
block|{
comment|/* read a line into r.l */
specifier|register
name|n
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|fread
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|r
argument_list|,
sizeof|sizeof
argument_list|(
name|r
argument_list|)
argument_list|,
literal|1
argument_list|,
name|stdin
argument_list|)
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|r
operator|.
name|l
operator|.
name|decflag
operator|&
name|LFN
condition|)
block|{
comment|/* new filename */
ifdef|#
directive|ifdef
name|FLEXNAMES
name|r
operator|.
name|f
operator|.
name|fn
operator|=
name|getstr
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|setfno
argument_list|(
name|r
operator|.
name|f
operator|.
name|fn
argument_list|)
expr_stmt|;
continue|continue;
block|}
ifdef|#
directive|ifdef
name|FLEXNAMES
name|r
operator|.
name|l
operator|.
name|name
operator|=
name|getstr
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|n
operator|=
name|r
operator|.
name|l
operator|.
name|nargs
expr_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
name|n
operator|=
operator|-
name|n
expr_stmt|;
if|if
condition|(
name|n
condition|)
block|{
if|if
condition|(
name|n
operator|>=
name|NTY
condition|)
name|error
argument_list|(
literal|"more than %d args?"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|fread
argument_list|(
operator|(
name|char
operator|*
operator|)
name|atyp
argument_list|,
sizeof|sizeof
argument_list|(
name|ATYPE
argument_list|)
argument_list|,
name|n
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|r
operator|.
name|l
operator|.
name|decflag
operator|&
name|m
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
end_block

begin_macro
name|setfno
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
comment|/* look up current file names */
comment|/* first, strip backwards to the beginning or to the first / */
name|int
name|i
decl_stmt|;
comment|/* now look up s */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ffree
condition|;
operator|++
name|i
control|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|s
argument_list|,
name|fnm
index|[
name|i
index|]
argument_list|,
name|LFNM
argument_list|)
condition|)
block|{
else|#
directive|else
if|if
condition|(
name|fnm
index|[
name|i
index|]
operator|==
name|s
condition|)
block|{
endif|#
directive|endif
name|cfno
operator|=
name|i
expr_stmt|;
return|return;
block|}
block|}
comment|/* make a new entry */
if|if
condition|(
name|ffree
operator|>=
name|FSZ
condition|)
name|error
argument_list|(
literal|"more than %d files"
argument_list|,
name|FSZ
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
name|strncpy
argument_list|(
name|fnm
index|[
name|ffree
index|]
argument_list|,
name|s
argument_list|,
name|LFNM
argument_list|)
expr_stmt|;
else|#
directive|else
name|fnm
index|[
name|ffree
index|]
operator|=
name|s
expr_stmt|;
endif|#
directive|endif
name|cfno
operator|=
name|ffree
operator|++
expr_stmt|;
block|}
comment|/* VARARGS */
name|error
argument_list|(
argument|s
argument_list|,
argument|a
argument_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"pass 2 error:(file %.*s) "
argument_list|,
name|LFNM
argument_list|,
name|fnm
index|[
name|cfno
index|]
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"pass 2 error:(file %s) "
argument_list|,
name|fnm
index|[
name|cfno
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|s
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|STAB
modifier|*
name|find
parameter_list|()
block|{
comment|/* for this to work, NSZ should be a power of 2 */
specifier|register
name|h
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
for|for
control|(
name|h
operator|=
literal|0
operator|,
name|p
operator|=
name|r
operator|.
name|l
operator|.
name|name
operator|,
name|q
operator|=
name|p
operator|+
name|LCHNM
init|;
operator|*
name|p
operator|&&
name|p
operator|<
name|q
condition|;
operator|++
name|p
control|)
block|{
name|h
operator|=
operator|(
name|h
operator|<<
literal|1
operator|)
operator|+
operator|*
name|p
expr_stmt|;
if|if
condition|(
name|h
operator|>=
name|NSZ
condition|)
block|{
name|h
operator|=
operator|(
name|h
operator|+
literal|1
operator|)
operator|&
operator|(
name|NSZ
operator|-
literal|1
operator|)
expr_stmt|;
block|}
block|}
block|}
else|#
directive|else
name|h
operator|=
operator|(
operator|(
name|int
operator|)
name|r
operator|.
name|l
operator|.
name|name
operator|)
operator|%
name|NSZ
expr_stmt|;
endif|#
directive|endif
block|{
specifier|register
name|STAB
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
for|for
control|(
name|p
operator|=
name|q
operator|=
operator|&
name|stab
index|[
name|h
index|]
init|;
name|q
operator|->
name|decflag
condition|;
control|)
block|{
comment|/* this call to strncmp should be taken out... */
ifndef|#
directive|ifndef
name|FLEXNAMES
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|r
operator|.
name|l
operator|.
name|name
argument_list|,
name|q
operator|->
name|name
argument_list|,
name|LCHNM
argument_list|)
condition|)
return|return
operator|(
name|q
operator|)
return|;
else|#
directive|else
if|if
condition|(
name|r
operator|.
name|l
operator|.
name|name
operator|==
name|q
operator|->
name|name
condition|)
return|return
operator|(
name|q
operator|)
return|;
endif|#
directive|endif
if|if
condition|(
operator|++
name|q
operator|>=
operator|&
name|stab
index|[
name|NSZ
index|]
condition|)
name|q
operator|=
name|stab
expr_stmt|;
if|if
condition|(
name|q
operator|==
name|p
condition|)
name|error
argument_list|(
literal|"too many names defined"
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|FLEXNAMES
name|strncpy
argument_list|(
name|q
operator|->
name|name
argument_list|,
name|r
operator|.
name|l
operator|.
name|name
argument_list|,
name|LCHNM
argument_list|)
expr_stmt|;
else|#
directive|else
name|q
operator|->
name|name
operator|=
name|r
operator|.
name|l
operator|.
name|name
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|q
operator|)
return|;
block|}
block|}
name|STYPE
modifier|*
name|tget
parameter_list|()
block|{
if|if
condition|(
name|tfree
operator|>=
name|TYSZ
condition|)
block|{
name|error
argument_list|(
literal|"too many types needed"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|&
name|tary
index|[
name|tfree
operator|++
index|]
operator|)
return|;
block|}
name|chkcompat
argument_list|(
argument|q
argument_list|)
name|STAB
modifier|*
name|q
decl_stmt|;
block|{
comment|/* are the types, etc. in r.l and q compatible */
specifier|register
name|int
name|i
decl_stmt|;
name|STYPE
modifier|*
name|qq
decl_stmt|;
name|setuse
argument_list|(
name|q
argument_list|)
expr_stmt|;
comment|/* argument check */
if|if
condition|(
name|q
operator|->
name|decflag
operator|&
operator|(
name|LDI
operator||
name|LIB
operator||
name|LUV
operator||
name|LUE
operator|)
condition|)
block|{
if|if
condition|(
name|r
operator|.
name|l
operator|.
name|decflag
operator|&
operator|(
name|LUV
operator||
name|LIB
operator||
name|LUE
operator|)
condition|)
block|{
if|if
condition|(
name|q
operator|->
name|nargs
operator|!=
name|r
operator|.
name|l
operator|.
name|nargs
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|q
operator|->
name|use
operator|&
name|VARARGS
operator|)
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%.8s: variable # of args."
argument_list|,
name|q
operator|->
name|name
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%s: variable # of args."
argument_list|,
name|q
operator|->
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|viceversa
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|.
name|l
operator|.
name|nargs
operator|>
name|q
operator|->
name|nargs
condition|)
name|r
operator|.
name|l
operator|.
name|nargs
operator|=
name|q
operator|->
name|nargs
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|q
operator|->
name|decflag
operator|&
operator|(
name|LDI
operator||
name|LIB
operator|)
operator|)
condition|)
block|{
name|q
operator|->
name|nargs
operator|=
name|r
operator|.
name|l
operator|.
name|nargs
expr_stmt|;
name|q
operator|->
name|use
operator||=
name|VARARGS
expr_stmt|;
block|}
block|}
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|qq
operator|=
name|q
operator|->
name|symty
operator|.
name|next
init|;
name|i
operator|<
name|r
operator|.
name|l
operator|.
name|nargs
condition|;
operator|++
name|i
operator|,
name|qq
operator|=
name|qq
operator|->
name|next
control|)
block|{
if|if
condition|(
name|chktype
argument_list|(
operator|&
name|qq
operator|->
name|t
argument_list|,
operator|&
name|atyp
index|[
name|i
index|]
argument_list|)
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%.8s, arg. %d used inconsistently"
argument_list|,
else|#
directive|else
argument|printf(
literal|"%s, arg. %d used inconsistently"
argument|,
endif|#
directive|endif
argument|q->name, i+
literal|1
argument|); 					viceversa(q); 					} 				} 			} 		}  	if( (q->decflag&(LDI|LIB|LUV))&& r.l.decflag==LUV ){ 		if( chktype(&r.l.type,&q->symty.t ) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"%.8s value used inconsistently"
argument|, q->name );
else|#
directive|else
argument|printf(
literal|"%s value used inconsistently"
argument|, q->name );
endif|#
directive|endif
argument|viceversa(q); 			} 		}
comment|/* check for multiple declaration */
argument|if( (q->decflag&LDI)&& (r.l.decflag&(LDI|LIB)) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"%.8s multiply declared"
argument|, q->name );
else|#
directive|else
argument|printf(
literal|"%s multiply declared"
argument|, q->name );
endif|#
directive|endif
argument|viceversa(q); 		}
comment|/* do a bit of checking of definitions and uses... */
argument|if( (q->decflag& (LDI|LIB|LDX|LDC|LUM))&& (r.l.decflag& (LDX|LDC|LUM))&& q->symty.t.aty != r.l.type.aty ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"%.8s value declared inconsistently"
argument|, q->name );
else|#
directive|else
argument|printf(
literal|"%s value declared inconsistently"
argument|, q->name );
endif|#
directive|endif
argument|viceversa(q); 		}
comment|/* better not call functions which are declared to be structure or union returning */
argument|if( (q->decflag& (LDI|LIB|LDX|LDC))&& (r.l.decflag& LUE)&& q->symty.t.aty != r.l.type.aty ){
comment|/* only matters if the function returns union or structure */
argument|TWORD ty; 		ty = q->symty.t.aty; 		if( ISFTN(ty)&& ((ty = DECREF(ty))==STRTY || ty==UNIONTY ) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"%.8s function value type must be declared before use"
argument|, q->name );
else|#
directive|else
argument|printf(
literal|"%s function value type must be declared before use"
argument|, q->name );
endif|#
directive|endif
argument|viceversa(q); 			} 		}  	if( pflag&& q->decflag==LDX&& r.l.decflag == LUM&& !ISFTN(q->symty.t.aty) ){
comment|/* make the external declaration go away */
comment|/* in effect, it was used without being defined */
argument|} 	}  viceversa(q) STAB *q; {
comment|/* print out file comparison */
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"	%.*s(%d)  ::  %.*s(%d)\n"
argument|, 		LFNM, fnm[q->fno], q->fline, 		LFNM, fnm[cfno], r.l.fline );
else|#
directive|else
argument|printf(
literal|"	%s(%d)  ::  %s(%d)\n"
argument|, 		fnm[q->fno], q->fline, 		fnm[cfno], r.l.fline );
endif|#
directive|endif
argument|}
comment|/* messages for defintion/use */
argument|char * mess[
literal|2
argument|][
literal|2
argument|] ={
literal|""
argument_list|,
ifndef|#
directive|ifndef
name|FLEXNAMES
literal|"%.8s used( %.*s(%d) ), but not defined\n"
argument_list|,
literal|"%.8s defined( %.*s(%d) ), but never used\n"
argument_list|,
literal|"%.8s declared( %.*s(%d) ), but never used or defined\n"
else|#
directive|else
literal|"%s used( %s(%d) ), but not defined\n"
argument_list|,
literal|"%s defined( %s(%d) ), but never used\n"
argument_list|,
literal|"%s declared( %s(%d) ), but never used or defined\n"
endif|#
directive|endif
argument|};  lastone(q) STAB *q; {  	register nu
argument_list|,
argument|nd
argument_list|,
argument|uses;  	if( ddddd ) pst(q);  	nu = nd =
literal|0
argument|; 	uses = q->use;  	if( !(uses&USED)&& q->decflag != LIB ) {
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( strncmp(q->name,
literal|"main"
argument|,
literal|7
argument|) )
else|#
directive|else
argument|if (strcmp(q->name,
literal|"main"
argument|))
endif|#
directive|endif
argument|nu =
literal|1
argument|; 		}  	if( !ISFTN(q->symty.t.aty) ){ 		switch( q->decflag ){  		case LIB: 			nu = nd =
literal|0
argument|;
comment|/* don't complain about uses on libraries */
argument|break; 		case LDX: 			if( !xflag ) break; 		case LUV: 		case LUE:
comment|/* 01/04/80 */
argument|case LUV | LUE: 		case LUM: 			nd =
literal|1
argument|; 			} 		} 	if( uflag&& ( nu || nd ) ) printf( mess[nu][nd],
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|q->name, LFNM, fnm[q->fno], q->fline );
else|#
directive|else
argument|q->name
argument_list|,
argument|fnm[q->fno]
argument_list|,
argument|q->fline
argument_list|)
empty_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|uses
operator|&
operator|(
name|RVAL
operator|+
name|EUSED
operator|)
operator|)
operator|==
operator|(
name|RVAL
operator|+
name|EUSED
operator|)
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%.8s returns value which is %s ignored\n"
argument_list|,
argument|q->name
argument_list|,
else|#
directive|else
argument|printf(
literal|"%s returns value which is %s ignored\n"
argument|, q->name,
endif|#
directive|endif
argument|uses&VUSED ?
literal|"sometimes"
argument|:
literal|"always"
argument|); 		}  	if( (uses&(RVAL+VUSED)) == (VUSED)&& (q->decflag&(LDI|LIB)) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"%.8s value is used, but none returned\n"
argument|, q->name );
else|#
directive|else
argument|printf(
literal|"%s value is used, but none returned\n"
argument|, q->name );
endif|#
directive|endif
argument|} 	}  cleanup(){
comment|/* call lastone and die gracefully */
argument|STAB *q; 	for( q=stab; q<&stab[NSZ]; ++q ){ 		if( q->decflag ) lastone(q); 		} 	exit(
literal|0
argument|); 	}  setuse(q) STAB *q; {
comment|/* check new type to ensure that it is used */
argument|if( !q->decflag ){
comment|/* new one */
argument|q->decflag = r.l.decflag; 		q->symty.t = r.l.type; 		if( r.l.nargs<
literal|0
argument|){ 			q->nargs = -r.l.nargs; 			q->use = VARARGS; 			} 		else { 			q->nargs = r.l.nargs; 			q->use =
literal|0
argument|; 			} 		q->fline = r.l.fline; 		q->fno = cfno; 		if( q->nargs ){ 			int i; 			STYPE *qq; 			for( i=
literal|0
argument|,qq=&q->symty; i<q->nargs; ++i,qq=qq->next ){ 				qq->next = tget(); 				qq->next->t = atyp[i]; 				} 			} 		}  	switch( r.l.decflag ){  	case LRV: 		q->use |= RVAL; 		return; 	case LUV: 		q->use |= VUSED+USED; 		return; 	case LUE: 		q->use |= EUSED+USED; 		return;
comment|/* 01/04/80 */
argument|case LUV | LUE: 	case LUM: 		q->use |= USED; 		return;  		} 	}  chktype( pt1, pt2 ) register ATYPE *pt1
argument_list|,
argument|*pt2; { 	TWORD t;
comment|/* check the two type words to see if they are compatible */
comment|/* for the moment, enums are turned into ints, and should be checked as such */
argument|if( pt1->aty == ENUMTY ) pt1->aty =  INT; 	if( pt2->aty == ENUMTY ) pt2->aty = INT;  	if( (t=BTYPE(pt1->aty)==STRTY) || t==UNIONTY ){ 		return( pt1->aty!=pt2->aty || ( 			pt1->extra!=pt2->extra ) ); 		}  	if( pt2->extra ){
comment|/* constant passed in */
argument|if( pt1->aty == UNSIGNED&& pt2->aty == INT ) return(
literal|0
argument|); 		else if( pt1->aty == ULONG&& pt2->aty == LONG ) return(
literal|0
argument|); 		} 	else if( pt1->extra ){
comment|/* for symmetry */
argument|if( pt2->aty == UNSIGNED&& pt1->aty == INT ) return(
literal|0
argument|); 		else if( pt2->aty == ULONG&& pt1->aty == LONG ) return(
literal|0
argument|); 		}  	return( pt1->aty != pt2->aty ); 	}  struct tb { int m; char * nm }; ptb( v, tp ) struct tb *tp; {
comment|/* print a value from the table */
argument|int flag; 	flag =
literal|0
argument|; 	for( ; tp->m; ++tp ){ 		if( v&tp->m ){ 			if( flag++ ) putchar(
literal|'|'
argument|); 			printf(
literal|"%s"
argument|, tp->nm ); 			} 		} 	}  pst( q ) STAB *q; {
comment|/* give a debugging output for q */
argument|static struct tb dfs[] = { 		LDI
argument_list|,
literal|"LDI"
argument_list|,
argument|LIB
argument_list|,
literal|"LIB"
argument_list|,
argument|LDC
argument_list|,
literal|"LDC"
argument_list|,
argument|LDX
argument_list|,
literal|"LDX"
argument_list|,
argument|LRV
argument_list|,
literal|"LRV"
argument_list|,
argument|LUV
argument_list|,
literal|"LUV"
argument_list|,
argument|LUE
argument_list|,
literal|"LUE"
argument_list|,
argument|LUM
argument_list|,
literal|"LUM"
argument_list|,
literal|0
argument_list|,
literal|""
argument|};  	static struct tb us[] = { 		USED
argument_list|,
literal|"USED"
argument_list|,
argument|VUSED
argument_list|,
literal|"VUSED"
argument_list|,
argument|EUSED
argument_list|,
literal|"EUSED"
argument_list|,
argument|RVAL
argument_list|,
literal|"RVAL"
argument_list|,
argument|VARARGS
argument_list|,
literal|"VARARGS"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|};
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"%.8s ("
argument|, q->name );
else|#
directive|else
argument|printf(
literal|"%s ("
argument|, q->name );
endif|#
directive|endif
argument|ptb( q->decflag, dfs ); 	printf(
literal|"), use= "
argument|); 	ptb( q->use, us ); 	printf(
literal|", line %d, nargs=%d\n"
argument|, q->fline, q->nargs ); 	}
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|char * getstr() { 	char buf[BUFSIZ]; 	register char *cp = buf; 	register int c;  	if (feof(stdin) || ferror(stdin)) 		return(
literal|""
argument|); 	while ((c = getchar())>
literal|0
argument|) 		*cp++ = c; 	if (c<
literal|0
argument|) { 		fprintf(stderr,
literal|"pass 2 error: intermediate file format error (getstr)"
argument|); 		exit(
literal|1
argument|); 	} 	*cp++ =
literal|0
argument|; 	return (hash(buf)); }
define|#
directive|define
name|NSAVETAB
value|4096
argument|char	*savetab; int	saveleft;  char * savestr(cp) 	register char *cp; { 	register int len;  	len = strlen(cp) +
literal|1
argument|; 	if (len> saveleft) { 		saveleft = NSAVETAB; 		if (len> saveleft) 			saveleft = len; 		savetab = (char *)malloc(saveleft); 		if (savetab ==
literal|0
argument|) { 			fprintf(stderr,
literal|"pass 2 error: ran out of memory (savestr)"
argument|); 			exit(
literal|1
argument|); 		} 	} 	strncpy(savetab, cp, len); 	cp = savetab; 	savetab += len; 	saveleft -= len; 	return (cp); }
comment|/*  * The definition for the segmented hash tables.  */
define|#
directive|define
name|MAXHASH
value|20
define|#
directive|define
name|HASHINC
value|1013
argument|struct ht { 	char	**ht_low; 	char	**ht_high; 	int	ht_used; } htab[MAXHASH];  char * hash(s) 	char *s; { 	register char **h; 	register i; 	register char *cp; 	struct ht *htp; 	int sh;
comment|/* 	 * The hash function is a modular hash of 	 * the sum of the characters with the sum 	 * doubled before each successive character 	 * is added. 	 */
argument|cp = s; 	i =
literal|0
argument|; 	while (*cp) 		i = i*
literal|2
argument|+ *cp++; 	sh = (i&
literal|077777
argument|) % HASHINC; 	cp = s;
comment|/* 	 * There are as many as MAXHASH active 	 * hash tables at any given point in time. 	 * The search starts with the first table 	 * and continues through the active tables 	 * as necessary. 	 */
argument|for (htp = htab; htp<&htab[MAXHASH]; htp++) { 		if (htp->ht_low ==
literal|0
argument|) { 			register char **hp = 			    (char **) calloc(sizeof (char **), HASHINC); 			if (hp ==
literal|0
argument|) { 				fprintf(stderr,
literal|"pass 2 error: ran out of memory (hash)"
argument|); 				exit(
literal|1
argument|); 			} 			htp->ht_low = hp; 			htp->ht_high = htp->ht_low + HASHINC; 		} 		h = htp->ht_low + sh;
comment|/* 		 * quadratic rehash increment 		 * starts at 1 and incremented 		 * by two each rehash. 		 */
argument|i =
literal|1
argument|; 		do { 			if (*h ==
literal|0
argument|) { 				if (htp->ht_used> (HASHINC *
literal|3
argument|)/
literal|4
argument|) 					break; 				htp->ht_used++; 				*h = savestr(cp); 				return (*h); 			} 			if (**h == *cp&& strcmp(*h, cp) ==
literal|0
argument|) 				return (*h); 			h += i; 			i +=
literal|2
argument|; 			if (h>= htp->ht_high) 				h -= HASHINC; 		} while (i< HASHINC); 	} 	fprintf(stderr,
literal|"pass 2 error: ran out of hash tables"
argument|); 	exit(
literal|1
argument|); } char	*tstrbuf[
literal|1
argument|];
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

