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
literal|"@(#)pftn.c	1.15 (Berkeley) 5/1/87"
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
ifdef|#
directive|ifdef
name|LINT
if|if
condition|(
name|pflag
condition|)
block|{
specifier|register
name|int
name|i
decl_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
operator|++
name|i
control|)
else|#
directive|else
comment|/* FLEXNAMES */
for|for
control|(
name|i
operator|=
literal|0
init|;
condition|;
operator|++
name|i
control|)
endif|#
directive|endif
comment|/* FLEXNAMES */
if|if
condition|(
name|p
operator|->
name|sname
index|[
name|i
index|]
operator|==
literal|'\0'
condition|)
break|break;
elseif|else
if|if
condition|(
name|p
operator|->
name|sname
index|[
name|i
index|]
operator|==
literal|'$'
condition|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|werror
argument_list|(
literal|"nonportable identifier (uses $): %.8s"
argument_list|,
else|#
directive|else
comment|/* FLEXNAMES */
argument|werror(
literal|"nonportable identifier (uses $): %s"
argument|,
endif|#
directive|endif
comment|/* FLEXNAMES */
argument|p->sname); 				break; 			} 	}
endif|#
directive|endif
comment|/* LINT */
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"defid( %.8s (%d), "
argument|, p->sname, idp );
else|#
directive|else
argument|printf(
literal|"defid( %s (%d), "
argument|, p->sname, idp );
endif|#
directive|endif
argument|tprint( q->in.type ); 		printf(
literal|", %s, (%d,%d) ), level %d\n"
argument|, scnames(class), q->fn.cdim, q->fn.csiz, blevel ); 		}
endif|#
directive|endif
argument|fixtype( q, class );  	type = q->in.type; 	class = fixclass( class, type );  	stp = p->stype; 	slev = p->slevel;
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ){ 		printf(
literal|"	modified to "
argument|); 		tprint( type ); 		printf(
literal|", %s\n"
argument|, scnames(class) ); 		printf(
literal|"	previous def'n: "
argument|); 		tprint( stp ); 		printf(
literal|", %s, (%d,%d) ), level %d\n"
argument|, scnames(p->sclass), p->dimoff, p->sizoff, slev ); 		}
endif|#
directive|endif
argument|if( stp == FTN&& p->sclass == SNULL )goto enter;
comment|/* name encountered as function, not yet defined */
argument|if( stp == UNDEF|| stp == FARG ){ 		if( blevel==
literal|1
argument|&& stp!=FARG ) switch( class ){  		default:
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if(!(class&FIELD)) uerror(
literal|"declared argument %.8s is missing"
argument|, p->sname );
else|#
directive|else
argument|if(!(class&FIELD)) uerror(
literal|"declared argument %s is missing"
argument|, p->sname );
endif|#
directive|endif
argument|case MOS: 		case STNAME: 		case MOU: 		case UNAME: 		case MOE: 		case ENAME: 		case TYPEDEF: 			; 			} 		goto enter; 		}  	if( type != stp ) goto mismatch;
comment|/* test (and possibly adjust) dimensions */
argument|dsym = p->dimoff; 	ddef = q->fn.cdim; 	changed =
literal|0
argument|; 	for( temp=type; temp&TMASK; temp = DECREF(temp) ){ 		if( ISARY(temp) ){ 			if (dimtab[dsym] ==
literal|0
argument|) { 				dimtab[dsym] = dimtab[ddef]; 				changed =
literal|1
argument|; 				} 			else if (dimtab[ddef]!=
literal|0
argument|&&dimtab[dsym]!=dimtab[ddef]) { 				goto mismatch; 				} 			++dsym; 			++ddef; 			} 		}  	if (changed) { 		FIXDEF(p); 		}
comment|/* check that redeclarations are to the same structure */
argument|if( (temp==STRTY||temp==UNIONTY||temp==ENUMTY)&& p->sizoff != q->fn.csiz&& class!=STNAME&& class!=UNAME&& class!=ENAME ){ 		goto mismatch; 		}  	scl = ( p->sclass );
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ){ 		printf(
literal|"	previous class: %s\n"
argument|, scnames(scl) ); 		}
endif|#
directive|endif
argument|if( class&FIELD ){
comment|/* redefinition */
argument|if( !falloc( p, class&FLDSIZ,
literal|1
argument|, NIL ) ) {
comment|/* successful allocation */
argument|psave( idp ); 			return; 			}
comment|/* blew it: resume at end of switch... */
argument|}  	else switch( class ){  	case EXTERN: 		switch( scl ){ 		case STATIC: 		case USTATIC: 			if( slev==
literal|0
argument|) return; 			break; 		case EXTDEF: 		case EXTERN: 		case FORTRAN: 		case UFORTRAN: 			return; 			} 		break;  	case STATIC: 		if( scl==USTATIC || (scl==EXTERN&& blevel==
literal|0
argument|) ){ 			p->sclass = STATIC; 			if( ISFTN(type) ) curftn = idp; 			return; 			} 		break;  	case USTATIC: 		if( scl==STATIC || scl==USTATIC ) return; 		break;  	case LABEL: 		if( scl == ULABEL ){ 			p->sclass = LABEL; 			deflab( p->offset ); 			return; 			} 		break;  	case TYPEDEF: 		if( scl == class ) return; 		break;  	case UFORTRAN: 		if( scl == UFORTRAN || scl == FORTRAN ) return; 		break;  	case FORTRAN: 		if( scl == UFORTRAN ){ 			p->sclass = FORTRAN; 			if( ISFTN(type) ) curftn = idp; 			return; 			} 		break;  	case MOU: 	case MOS: 		if( scl == class ) { 			if( oalloc( p,&strucoff ) ) break; 			if( class == MOU ) strucoff =
literal|0
argument|; 			psave( idp ); 			return; 			} 		break;  	case MOE: 		if( scl == class ){ 			if( p->offset!= strucoff++ ) break; 			psave( idp ); 			} 		break;  	case EXTDEF: 		if( scl == EXTERN ) { 			p->sclass = EXTDEF; 			if( ISFTN(type) ) curftn = idp; 			return; 			} 		break;  	case STNAME: 	case UNAME: 	case ENAME: 		if( scl != class ) break; 		if( dimtab[p->sizoff] ==
literal|0
argument|) return;
comment|/* previous entry just a mention */
argument|break;  	case ULABEL: 		if( scl == LABEL || scl == ULABEL ) return; 	case PARAM: 	case AUTO: 	case REGISTER: 		;
comment|/* mismatch.. */
argument|}  	mismatch:
comment|/* allow nonunique structure/union member names */
argument|if( class==MOU || class==MOS || class& FIELD ){
comment|/* make a new entry */
argument|register int *memp; 		p->sflags |= SNONUNIQ;
comment|/* old entry is nonunique */
comment|/* determine if name has occurred in this structure/union */
argument|if (paramno>
literal|0
argument|) for( memp =&paramstk[paramno-
literal|1
argument|];
comment|/* while */
argument|*memp>=
literal|0
argument|&& stab[*memp].sclass != STNAME&& stab[*memp].sclass != UNAME;
comment|/* iterate */
argument|--memp){ char *cname
argument_list|,
argument|*oname; 			if( stab[*memp].sflags& SNONUNIQ ){int k; 				cname=p->sname; 				oname=stab[*memp].sname;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|for(k=
literal|1
argument|; k<=NCHNAM; ++k){ 					if(*cname++ != *oname)goto diff; 					if(!*oname++)break; 					}
else|#
directive|else
argument|if (cname != oname) goto diff;
endif|#
directive|endif
argument|uerror(
literal|"redeclaration of: %s"
argument|,p->sname); 				break; 				diff: continue; 				} 			} 		p = mknonuniq(&idp );
comment|/* update p and idp to new entry */
argument|goto enter; 		} 	if( blevel> slev&& class != EXTERN&& class != FORTRAN&& 		class != UFORTRAN&& !( class == LABEL&& slev>=
literal|2
argument|) ){ 		q->tn.rval = idp = hide( p ); 		p =&stab[idp]; 		goto enter; 		}
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|uerror(
literal|"redeclaration of %.8s"
argument|, p->sname );
else|#
directive|else
argument|uerror(
literal|"redeclaration of %s"
argument|, p->sname );
endif|#
directive|endif
argument|if( class==EXTDEF&& ISFTN(type) ) curftn = idp; 	return;  	enter:
comment|/* make a new entry */
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ) printf(
literal|"	new entry made\n"
argument|);
endif|#
directive|endif
argument|if( type == UNDEF ) uerror(
literal|"void type for %s"
argument|,p->sname); 	p->stype = type; 	p->sclass = class; 	p->slevel = blevel; 	p->offset = NOOFFSET; 	p->suse = lineno; 	if( class == STNAME || class == UNAME || class == ENAME ) { 		p->sizoff = curdim; 		dstash(
literal|0
argument|);
comment|/* size */
argument|dstash( -
literal|1
argument|);
comment|/* index to members of str or union */
argument|dstash( ALSTRUCT );
comment|/* alignment */
argument|dstash( idp ); 		} 	else { 		switch( BTYPE(type) ){ 		case STRTY: 		case UNIONTY: 		case ENUMTY: 			p->sizoff = q->fn.csiz; 			break; 		default: 			p->sizoff = BTYPE(type); 			} 		}
comment|/* copy dimensions */
argument|p->dimoff = q->fn.cdim;
comment|/* allocate offsets */
argument|if( class&FIELD ){ 		falloc( p, class&FLDSIZ,
literal|0
argument|, NIL );
comment|/* new entry */
argument|psave( idp ); 		} 	else switch( class ){  	case AUTO: 		oalloc( p,&autooff ); 		break; 	case STATIC: 	case EXTDEF: 		p->offset = getlab(); 		if( ISFTN(type) ) curftn = idp; 		break; 	case ULABEL: 	case LABEL: 		p->offset = getlab(); 		p->slevel =
literal|2
argument|; 		if( class == LABEL ){ 			locctr( PROG ); 			deflab( p->offset ); 			} 		break;  	case EXTERN: 	case UFORTRAN: 	case FORTRAN: 		p->offset = getlab(); 		p->slevel =
literal|0
argument|; 		break; 	case MOU: 	case MOS: 		oalloc( p,&strucoff ); 		if( class == MOU ) strucoff =
literal|0
argument|; 		psave( idp ); 		break;  	case MOE: 		p->offset = strucoff++; 		psave( idp ); 		break; 	case REGISTER: 		p->offset = regvar--; 		if( blevel ==
literal|1
argument|) p->sflags |= SSET; 		if( regvar< minrvar ) minrvar = regvar; 		break; 		}  	{ 		register int l = p->slevel;  		if( l>= MAXSCOPES ) 			cerror(
literal|"scopes nested too deep"
argument|);  		p->snext = schain[l]; 		schain[l] = p; 		if( l>= chaintop ) 			chaintop = l +
literal|1
argument|; 		}
comment|/* user-supplied routine to fix up new definitions */
argument|FIXDEF(p);
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ) printf(
literal|"	dimoff, sizoff, offset: %d, %d, %d\n"
argument|, p->dimoff, p->sizoff, p->offset );
endif|#
directive|endif
argument|}  psave( i ){ 	if( paramno>= PARAMSZ ){ 		cerror(
literal|"parameter stack overflow"
argument|); 		} 	paramstk[ paramno++ ] = i; 	}  ftnend(){
comment|/* end of function */
argument|if( retlab != NOLAB ){
comment|/* inside a real function */
argument|efcode(); 		} 	checkst(
literal|0
argument|); 	retstat =
literal|0
argument|; 	tcheck(); 	curclass = SNULL; 	brklab = contlab = retlab = NOLAB; 	flostat =
literal|0
argument|; 	if( nerrors ==
literal|0
argument|){ 		if( psavbc !=& asavbc[
literal|0
argument|] ) cerror(
literal|"bcsave error"
argument|); 		if( paramno !=
literal|0
argument|) cerror(
literal|"parameter reset error"
argument|); 		if( swx !=
literal|0
argument|) cerror(
literal|"switch error"
argument|); 		} 	psavbc =&asavbc[
literal|0
argument|]; 	paramno =
literal|0
argument|; 	autooff = AUTOINIT; 	minrvar = regvar = MAXRVAR; 	reached =
literal|1
argument|; 	swx =
literal|0
argument|; 	swp = swtab; 	locctr(DATA); 	}  dclargs(){ 	register i
argument_list|,
argument|j; 	register struct symtab *p; 	register NODE *q; 	argoff = ARGINIT;
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug>
literal|2
argument|) printf(
literal|"dclargs()\n"
argument|);
endif|#
directive|endif
argument|for( i=
literal|0
argument|; i<paramno; ++i ){ 		if( (j = paramstk[i])<
literal|0
argument|) continue; 		p =&stab[j];
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug>
literal|2
argument|){ 			printf(
literal|"\t%s (%d) "
argument|,p->sname, j); 			tprint(p->stype); 			printf(
literal|"\n"
argument|); 			}
endif|#
directive|endif
argument|if( p->stype == FARG ) { 			q = block(FREE,NIL,NIL,INT,
literal|0
argument|,INT); 			q->tn.rval = j; 			defid( q, PARAM ); 			} 		FIXARG(p);
comment|/* local arg hook, eg. for sym. debugger */
argument|oalloc( p,&argoff );
comment|/* always set aside space, even for register arguments */
argument|} 	cendarg(); 	locctr(PROG); 	defalign(ALINT); 	ftnno = getlab(); 	bfcode( paramstk, paramno ); 	paramno =
literal|0
argument|; 	}  NODE * rstruct( idn, soru ){
comment|/* reference to a structure or union, with no definition */
argument|register struct symtab *p; 	register NODE *q; 	p =&stab[idn]; 	switch( p->stype ){  	case UNDEF: 	def: 		q = block( FREE, NIL, NIL,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|); 		q->tn.rval = idn; 		q->in.type = (soru&INSTRUCT) ? STRTY : ( (soru&INUNION) ? UNIONTY : ENUMTY ); 		defid( q, (soru&INSTRUCT) ? STNAME : ( (soru&INUNION) ? UNAME : ENAME ) ); 		break;  	case STRTY: 		if( soru& INSTRUCT ) break; 		goto def;  	case UNIONTY: 		if( soru& INUNION ) break; 		goto def;  	case ENUMTY: 		if( !(soru&(INUNION|INSTRUCT)) ) break; 		goto def;  		} 	stwart = instruct; 	return( mkty( p->stype,
literal|0
argument|, p->sizoff ) ); 	}  moedef( idn ){ 	register NODE *q;  	q = block( FREE, NIL, NIL, MOETY,
literal|0
argument|,
literal|0
argument|); 	q->tn.rval = idn; 	if( idn>=
literal|0
argument|) defid( q, MOE ); 	}  bstruct( idn, soru ){
comment|/* begining of structure or union declaration */
argument|register NODE *q;  	psave( instruct ); 	psave( curclass ); 	psave( strucoff ); 	strucoff =
literal|0
argument|; 	instruct = soru; 	q = block( FREE, NIL, NIL,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|); 	q->tn.rval = idn; 	if( instruct==INSTRUCT ){ 		curclass = MOS; 		q->in.type = STRTY; 		if( idn>=
literal|0
argument|) defid( q, STNAME ); 		} 	else if( instruct == INUNION ) { 		curclass = MOU; 		q->in.type = UNIONTY; 		if( idn>=
literal|0
argument|) defid( q, UNAME ); 		} 	else {
comment|/* enum */
argument|curclass = MOE; 		q->in.type = ENUMTY; 		if( idn>=
literal|0
argument|) defid( q, ENAME ); 		} 	psave( idn = q->tn.rval );
comment|/* the "real" definition is where the members are seen */
argument|if ( idn>=
literal|0
argument|) stab[idn].suse = lineno; 	return( paramno-
literal|4
argument|); 	}  NODE * dclstruct( oparam ){ 	register struct symtab *p; 	register i
argument_list|,
argument|al
argument_list|,
argument|sa
argument_list|,
argument|j
argument_list|,
argument|sz
argument_list|,
argument|szindex; 	register TWORD temp; 	register high
argument_list|,
argument|low;
comment|/* paramstack contains: 		paramstack[ oparam ] = previous instruct 		paramstack[ oparam+1 ] = previous class 		paramstk[ oparam+2 ] = previous strucoff 		paramstk[ oparam+3 ] = structure name  		paramstk[ oparam+4, ... ]  = member stab indices  		*/
argument|if( (i=paramstk[oparam+
literal|3
argument|])<
literal|0
argument|){ 		szindex = curdim; 		dstash(
literal|0
argument|);
comment|/* size */
argument|dstash( -
literal|1
argument|);
comment|/* index to member names */
argument|dstash( ALSTRUCT );
comment|/* alignment */
argument|dstash( -lineno );
comment|/* name of structure */
argument|} 	else { 		szindex = stab[i].sizoff; 		}
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"dclstruct( %.8s ), szindex = %d\n"
argument|, (i>=
literal|0
argument|)? stab[i].sname :
literal|"??"
argument|, szindex );
else|#
directive|else
argument|printf(
literal|"dclstruct( %s ), szindex = %d\n"
argument|, (i>=
literal|0
argument|)? stab[i].sname :
literal|"??"
argument|, szindex );
endif|#
directive|endif
argument|}
endif|#
directive|endif
argument|temp = (instruct&INSTRUCT)?STRTY:((instruct&INUNION)?UNIONTY:ENUMTY); 	stwart = instruct = paramstk[ oparam ]; 	curclass = paramstk[ oparam+
literal|1
argument|]; 	dimtab[ szindex+
literal|1
argument|] = curdim; 	al = ALSTRUCT;  	high = low =
literal|0
argument|;  	for( i = oparam+
literal|4
argument|;  i< paramno; ++i ){ 		dstash( j=paramstk[i] ); 		if( j<
literal|0
argument||| j>= SYMTSZ ) cerror(
literal|"gummy structure member"
argument|); 		p =&stab[j]; 		if( temp == ENUMTY ){ 			if( p->offset< low ) low = p->offset; 			if( p->offset> high ) high = p->offset; 			p->sizoff = szindex; 			continue; 			} 		sa = talign( p->stype, p->sizoff ); 		if( p->sclass& FIELD ){ 			sz = p->sclass&FLDSIZ; 			} 		else { 			sz = tsize( p->stype, p->dimoff, p->sizoff ); 			} 		if( sz ==
literal|0
argument|){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"illegal zero sized structure member: %.8s"
argument|, p->sname );
else|#
directive|else
argument|werror(
literal|"illegal zero sized structure member: %s"
argument|, p->sname );
endif|#
directive|endif
argument|} 		if( sz> strucoff ) strucoff = sz;
comment|/* for use with unions */
argument|SETOFF( al, sa );
comment|/* set al, the alignment, to the lcm of the alignments of the members */
argument|} 	dstash( -
literal|1
argument|);
comment|/* endmarker */
argument|SETOFF( strucoff, al );  	if( temp == ENUMTY ){ 		register TWORD ty;
ifdef|#
directive|ifdef
name|ENUMSIZE
argument|ty = ENUMSIZE(high,low);
else|#
directive|else
argument|if( (char)high == high&& (char)low == low ) ty = ctype( CHAR ); 		else if( (short)high == high&& (short)low == low ) ty = ctype( SHORT ); 		else ty = ctype(INT);
endif|#
directive|endif
argument|strucoff = tsize( ty,
literal|0
argument|, (int)ty ); 		dimtab[ szindex+
literal|2
argument|] = al = talign( ty, (int)ty ); 		}  	if( strucoff ==
literal|0
argument|) uerror(
literal|"zero sized structure"
argument|); 	dimtab[ szindex ] = strucoff; 	dimtab[ szindex+
literal|2
argument|] = al; 	dimtab[ szindex+
literal|3
argument|] = paramstk[ oparam+
literal|3
argument|];
comment|/* name index */
argument|FIXSTRUCT( szindex, oparam );
comment|/* local hook, eg. for sym debugger */
ifndef|#
directive|ifndef
name|BUG1
argument|if( ddebug>
literal|1
argument|){ 		printf(
literal|"\tdimtab[%d,%d,%d] = %d,%d,%d\n"
argument|, szindex,szindex+
literal|1
argument|,szindex+
literal|2
argument|, 				dimtab[szindex],dimtab[szindex+
literal|1
argument|],dimtab[szindex+
literal|2
argument|] ); 		for( i = dimtab[szindex+
literal|1
argument|]; dimtab[i]>=
literal|0
argument|; ++i ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|printf(
literal|"\tmember %.8s(%d)\n"
argument|, stab[dimtab[i]].sname, dimtab[i] );
else|#
directive|else
argument|printf(
literal|"\tmember %s(%d)\n"
argument|, stab[dimtab[i]].sname, dimtab[i] );
endif|#
directive|endif
argument|} 		}
endif|#
directive|endif
argument|strucoff = paramstk[ oparam+
literal|2
argument|]; 	paramno = oparam;  	return( mkty( temp,
literal|0
argument|, szindex ) ); 	}
comment|/* VARARGS */
argument|yyerror( s ) char *s; {
comment|/* error printing routine in parser */
argument|uerror( s );  	}  yyaccpt(){ 	ftnend(); 	}  ftnarg( idn ) { 	switch( stab[idn].stype ){  	case UNDEF:
comment|/* this parameter, entered at scan */
argument|break; 	case FARG:
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|uerror(
literal|"redeclaration of formal parameter, %.8s"
argument|,
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
argument|); i+=TSHIFT ){ 		switch( (ty>>i)&TMASK ){  		case FTN: 			cerror(
literal|"compiler takes alignment of function"
argument|); 		case PTR: 			return( ALPOINT ); 		case ARY: 			continue; 		case
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
argument|); i+=TSHIFT ){ 		switch( (ty>>i)&TMASK ){  		case FTN: 			cerror(
literal|"compiler takes size of function"
argument|); 		case PTR: 			return( SZPOINT * mult ); 		case ARY: 			mult *= (unsigned int) dimtab[ d++ ]; 			continue; 		case
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
argument|p =&stab[curid];  	iclass = p->sclass; 	if( curclass == EXTERN || curclass == FORTRAN ) iclass = EXTERN; 	switch( iclass ){  	case UNAME: 	case EXTERN: 		return; 	case AUTO: 	case REGISTER: 		break; 	case EXTDEF: 	case STATIC: 		ilocctr = ISARY(p->stype)?ADATA:DATA; 		locctr( ilocctr ); 		defalign( talign( p->stype, p->sizoff ) ); 		defnam( p );  		}  	inoff =
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
argument|register l, temp; 	register NODE *p;  	if( (iclass==EXTDEF||iclass==STATIC)&& (pstk->in_t == CHAR || pstk->in_t == UCHAR)&& 			pstk!=instack&& ISARY( pstk[-
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
argument|locctr( blevel==
literal|0
argument|?ilocctr:temp ); 		p = buildtree( STRING, NIL, NIL ); 		p->tn.rval = -l; 		return(p); 		} 	}  putbyte( v ){
comment|/* simulate byte v appearing in a list of integer values */
argument|register NODE *p; 	p = bcon(v); 	incode( p, SZCHAR ); 	tfree( p ); 	gotscal(); 	}  endinit(){ 	register TWORD t; 	register d, s, n, d1;
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
argument|; 	iclass = SNULL;  	}  doinit( p ) register NODE *p; {
comment|/* take care of generating a value for the initializer p */
comment|/* inoff has the current offset (last bit written) 		in the current word being generated */
argument|register sz, d, s; 	register TWORD t; 	int o;
comment|/* note: size of an individual initializer is assumed to fit into an int */
argument|if( iclass<
literal|0
argument||| pstk ==
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
argument|ecode(p);
endif|#
directive|endif
argument|p->in.left->in.op = FREE; 	p->in.left = p->in.right; 	p->in.right = NIL; 	p->in.left = optim( p->in.left ); 	o = p->in.left->in.op; 	if( o == UNARY AND ){ 		o = p->in.left->in.op = FREE; 		p->in.left = p->in.left->in.left; 		} 	p->in.op = INIT;  	if( sz< SZINT ){
comment|/* special case: bit fields, etc. */
argument|if( o != ICON ) uerror(
literal|"illegal initialization"
argument|); 		else incode( p->in.left, sz ); 		} 	else if( o == FCON ){ 		fincode( p->in.left->fpn.fval, sz ); 		} 	else if( o == DCON ){ 		fincode( p->in.left->dpn.dval, sz ); 		} 	else { 		p = optim(p); 		if( p->in.left->in.op != ICON ) uerror(
literal|"illegal initialization"
argument|); 		else cinit( p, sz ); 		}  	gotscal();  	leave: 	tfree(p); 	}  gotscal(){ 	register t, ix; 	register n, id; 	struct symtab *p; 	OFFSZ temp;  	for( ; pstk> instack; ) {  		if( pstk->in_fl ) ++ibseen;  		--pstk; 		 		t = pstk->in_t;  		if( t == STRTY ){ 			ix = ++pstk->in_x; 			if( (id=dimtab[ix])<
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
argument|;  	}  upoff( size, alignment, poff ) register alignment, *poff; {
comment|/* update the offset pointed to by poff; return the 	/* offset of a value of size `size', alignment `alignment', 	/* given that off is increasing */
argument|register off;  	off = *poff; 	SETOFF( off, alignment ); 	if( (offsz-off)<  size ){ 		if( instruct!=INSTRUCT )cerror(
literal|"too many local variables"
argument|); 		else cerror(
literal|"Structure too large"
argument|); 		} 	*poff = off+size; 	return( off ); 	}  oalloc( p, poff ) register struct symtab *p; register *poff; {
comment|/* allocate p with offset *poff, and update *poff */
argument|register al, off, tsz; 	int noff;  	al = talign( p->stype, p->sizoff ); 	noff = off = *poff; 	tsz = tsize( p->stype, p->dimoff, p->sizoff );
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
argument|register al,sz,type;  	type = (new<
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
comment|/* hack so stab will come at as LCSYM rather than STSYM */
argument|if (class == STATIC) { 		extern int stabLCSYM; 		stabLCSYM =
literal|1
argument|; 	}
endif|#
directive|endif
argument|defid( p, class );
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
argument|beginit(p->tn.rval); 		endinit(); 		} 	if( commflag ) commdec( p->tn.rval ); 	}  TWORD types( t1, t2, t3 ) TWORD t1, t2, t3; {
comment|/* return a basic type from basic types t1, t2, and t3 */
argument|TWORD t[
literal|3
argument|], noun, adj, unsg; 	register i;  	t[
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
argument|if( adj != INT ) noun = adj; 	if( unsg == UNSIGNED ) return( noun + (UNSIGNED-INT) ); 	else return( noun ); 	}  NODE * tymerge( typ, idp ) NODE *typ, *idp; {
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
argument|register o, temp; 	register unsigned t;  	o = p->in.op; 	p->in.op = FREE;  	if( o == NAME ) return;  	t = INCREF( p->in.type ); 	if( o == UNARY CALL ) t += (FTN-PTR); 	else if( o == LB ){ 		t += (ARY-PTR); 		temp = p->in.right->tn.lval; 		p->in.right->in.op = FREE; 		if( ( temp ==
literal|0
argument|)& ( p->in.left->tn.op == LB ) ) 			uerror(
literal|"Null dimension"
argument|); 		}  	p->in.left->in.type = t; 	tyreduce( p->in.left );  	if( o == LB ) dstash( temp );  	p->tn.rval = p->in.left->tn.rval; 	p->in.type = p->in.left->in.type;  	}  fixtype( p, class ) register NODE *p; { 	register unsigned t, type; 	register mod1, mod2;
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
comment|/* for example, beware of f(x) struct [ int a[10]; } *x; { ... } */
comment|/* the danger is that "a" will be converted to a pointer */
argument|if( class==SNULL&& blevel==
literal|1
argument|&& !(instruct&(INSTRUCT|INUNION)) ) class = PARAM; 	if( class == PARAM || ( class==REGISTER&& blevel==
literal|1
argument|) ){ 		if( type == FLOAT ) type = DOUBLE; 		else if( ISARY(type) ){ 			++p->fn.cdim; 			type += (PTR-ARY); 			} 		else if( ISFTN(type) ){ 			werror(
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
argument|register i; 	register struct symtab * sp; 	char *p,*q;  	sp =& stab[ i= *idindex ];
comment|/* position search at old entry */
argument|while( sp->stype != TNULL ){
comment|/* locate unused entry */
argument|if( ++i>= SYMTSZ ){
comment|/* wrap around symbol table */
argument|i =
literal|0
argument|; 			sp = stab; 			} 		else ++sp; 		if( i == *idindex ) cerror(
literal|"Symbol table full"
argument|); 		} 	sp->sflags = SNONUNIQ | SMOS; 	p = sp->sname; 	q = stab[*idindex].sname;
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
argument|for( i=
literal|1
argument|; i<=NCHNAM; ++i ){
comment|/* copy name */
argument|if( *p++ = *q
comment|/* assign */
argument|) ++q; 		}
endif|#
directive|endif
argument|return ( sp ); 	}  lookup( name, s) char *name; {
comment|/* look up name: must agree with s w.r.t. STAG, SMOS and SHIDDEN */
argument|register char *p, *q; 	int i, j, ii; 	register struct symtab *sp;
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
argument|checkst(lev){ 	register int s, i, j; 	register struct symtab *p, *q;  	for( i=
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
argument|if( q->stype == UNDEF ){ 		q->stype = TNULL; 		return(q); 		} 	while( q != p ){ 		if( q->stype == TNULL ) break; 		if( ++q>=&stab[SYMTSZ] ) q=stab; 		} 	return(q); 	}  clearst( lev ) register int lev; { 	register struct symtab *p, *q; 	register int temp; 	struct symtab *clist =
literal|0
argument|;  	temp = lineno; 	aobeg();
comment|/* step 1: remove entries */
argument|while( chaintop-
literal|1
argument|> lev ){ 		register int type;  		p = schain[--chaintop]; 		schain[chaintop] =
literal|0
argument|; 		for( ; p; p = q ){ 			q = p->snext; 			type = p->stype; 			if( p->stype == TNULL || p->slevel<= lev ) 				cerror(
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
argument|p = clist; 	while( p ){ 		register struct symtab *r, *next;  		q = p; 		next = p->snext; 		for(;;){ 			if( ++q>=&stab[SYMTSZ] )q = stab; 			if( q == p || q->stype == TNULL )break; 			if( (r = relook(q)) != q ) { 				*r = *q; 				q->stype = TNULL; 				} 			} 		p = next; 		}  	lineno = temp; 	aoend(); 	}  hide( p ) register struct symtab *p; { 	register struct symtab *q; 	for( q=p+
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
argument|return( idname = q-stab ); 	}  unhide( p ) register struct symtab *p; { 	register struct symtab *q; 	register s, j;  	s = p->sflags& (SMOS|STAG); 	q = p;  	for(;;){  		if( q == stab ) q =&stab[SYMTSZ-
literal|1
argument|]; 		else --q;  		if( q == p ) break;  		if( (q->sflags&(SMOS|STAG)) == s ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|for( j =
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

