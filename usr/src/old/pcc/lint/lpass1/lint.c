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
literal|"@(#)lint.c	1.14	(Berkeley)	12/11/87"
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

begin_include
include|#
directive|include
file|"lmanifest.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_define
define|#
directive|define
name|VAL
value|0
end_define

begin_define
define|#
directive|define
name|EFF
value|1
end_define

begin_comment
comment|/* these are appropriate for the -p flag */
end_comment

begin_decl_stmt
name|int
name|SZCHAR
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SZINT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SZFLOAT
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SZDOUBLE
init|=
literal|64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SZLONG
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SZSHORT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SZPOINT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALCHAR
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALINT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALFLOAT
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALDOUBLE
init|=
literal|64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALLONG
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALSHORT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALPOINT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ALSTRUCT
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* avoid gripes about printf et al. */
end_comment

begin_decl_stmt
name|int
name|vflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tell about unused argments */
end_comment

begin_decl_stmt
name|int
name|xflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tell about unused externals */
end_comment

begin_decl_stmt
name|int
name|argflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to turn off complaints about arguments */
end_comment

begin_decl_stmt
name|int
name|libflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to generate library descriptions */
end_comment

begin_decl_stmt
name|int
name|vaflag
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* signal functions with a variable number of args */
end_comment

begin_decl_stmt
name|int
name|aflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to check precision of assignments */
end_comment

begin_decl_stmt
name|int
name|zflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no 'structure never defined' error */
end_comment

begin_decl_stmt
name|int
name|Cflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filter out certain output, for generating libraries */
end_comment

begin_decl_stmt
name|char
modifier|*
name|libname
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the library we're generating */
end_comment

begin_comment
comment|/* flags for the "outdef" function */
end_comment

begin_define
define|#
directive|define
name|USUAL
value|(-101)
end_define

begin_define
define|#
directive|define
name|DECTY
value|(-102)
end_define

begin_define
define|#
directive|define
name|NOFILE
value|(-103)
end_define

begin_define
define|#
directive|define
name|SVLINE
value|(-104)
end_define

begin_define
define|#
directive|define
name|LNAMES
value|250
end_define

begin_struct
struct|struct
name|lnm
block|{
name|short
name|lid
decl_stmt|,
name|flgs
decl_stmt|;
block|}
name|lnames
index|[
name|LNAMES
index|]
struct|,
modifier|*
name|lnp
struct|;
end_struct

begin_expr_stmt
name|contx
argument_list|(
name|p
argument_list|,
name|down
argument_list|,
name|pl
argument_list|,
name|pr
argument_list|)
specifier|register
name|NODE
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
operator|*
name|pl
operator|,
operator|*
name|pr
expr_stmt|;
end_expr_stmt

begin_block
block|{
operator|*
name|pl
operator|=
operator|*
name|pr
operator|=
name|VAL
expr_stmt|;
switch|switch
condition|(
name|p
operator|->
name|in
operator|.
name|op
condition|)
block|{
case|case
name|ANDAND
case|:
case|case
name|OROR
case|:
case|case
name|QUEST
case|:
operator|*
name|pr
operator|=
name|down
expr_stmt|;
break|break;
case|case
name|SCONV
case|:
case|case
name|PCONV
case|:
case|case
name|COLON
case|:
operator|*
name|pr
operator|=
operator|*
name|pl
operator|=
name|down
expr_stmt|;
break|break;
case|case
name|COMOP
case|:
operator|*
name|pl
operator|=
name|EFF
expr_stmt|;
operator|*
name|pr
operator|=
name|down
expr_stmt|;
case|case
name|FORCE
case|:
case|case
name|INIT
case|:
case|case
name|UNARY
name|CALL
case|:
case|case
name|STCALL
case|:
case|case
name|UNARY
name|STCALL
case|:
case|case
name|CALL
case|:
case|case
name|UNARY
name|FORTCALL
case|:
case|case
name|FORTCALL
case|:
case|case
name|CBRANCH
case|:
break|break;
default|default:
if|if
condition|(
name|asgop
argument_list|(
name|p
operator|->
name|in
operator|.
name|op
argument_list|)
condition|)
break|break;
if|if
condition|(
name|p
operator|->
name|in
operator|.
name|op
operator|==
name|UNARY
name|MUL
operator|&&
operator|(
name|p
operator|->
name|in
operator|.
name|type
operator|==
name|STRTY
operator|||
name|p
operator|->
name|in
operator|.
name|type
operator|==
name|UNIONTY
operator|||
name|p
operator|->
name|in
operator|.
name|type
operator|==
name|UNDEF
operator|)
condition|)
block|{
comment|/* struct x f( );  main( ) {  (void) f( ); } 		 * the the cast call appears as U* UNDEF 		 */
break|break;
comment|/* the compiler does this... */
block|}
if|if
condition|(
name|down
operator|==
name|EFF
operator|&&
name|hflag
condition|)
name|werror
argument_list|(
literal|"null effect"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|ecode
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|NODE
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* compile code for p */
name|fwalk
argument_list|(
name|p
argument_list|,
name|contx
argument_list|,
name|EFF
argument_list|)
expr_stmt|;
name|lnp
operator|=
name|lnames
expr_stmt|;
name|lprt
argument_list|(
name|p
argument_list|,
name|EFF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|strforget
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|ejobcode
argument_list|(
argument|flag
argument_list|)
end_macro

begin_block
block|{
comment|/* called after processing each job */
comment|/* flag is nonzero if errors were detected */
specifier|register
name|k
expr_stmt|;
specifier|register
name|struct
name|symtab
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|stab
init|;
name|p
operator|<
operator|&
name|stab
index|[
name|SYMTSZ
index|]
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
name|p
operator|->
name|stype
operator|!=
name|TNULL
condition|)
block|{
if|if
condition|(
name|p
operator|->
name|stype
operator|==
name|STRTY
operator|||
name|p
operator|->
name|stype
operator|==
name|UNIONTY
condition|)
block|{
if|if
condition|(
operator|!
name|zflag
operator|&&
name|dimtab
index|[
name|p
operator|->
name|sizoff
operator|+
literal|1
index|]
operator|<
literal|0
condition|)
block|{
comment|/* never defined */
ifndef|#
directive|ifndef
name|FLEXNAMES
if|if
condition|(
name|hflag
condition|)
name|werror
argument_list|(
literal|"struct/union %.8s never defined"
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
name|hflag
condition|)
name|werror
argument_list|(
literal|"struct/union %s never defined"
argument_list|,
name|p
operator|->
name|sname
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
switch|switch
condition|(
name|p
operator|->
name|sclass
condition|)
block|{
case|case
name|STATIC
case|:
if|if
condition|(
name|p
operator|->
name|suse
operator|>
literal|0
condition|)
block|{
name|k
operator|=
name|lineno
expr_stmt|;
name|lineno
operator|=
name|p
operator|->
name|suse
expr_stmt|;
ifndef|#
directive|ifndef
name|FLEXNAMES
name|uerror
argument_list|(
literal|"static variable %.8s unused"
argument_list|,
else|#
directive|else
argument|uerror(
literal|"static variable %s unused"
argument|,
endif|#
directive|endif
argument|p->sname ); 					lineno = k; 					break; 					}
comment|/* no statics in libraries */
argument|if( Cflag ) break;  			case EXTERN: 			case USTATIC:
comment|/* with the xflag, worry about externs not used */
comment|/* the filename may be wrong here... */
argument|if( xflag&& p->suse>=
literal|0
argument|&& !libflag ){ 					outdef( p, LDX, NOFILE ); 					} 			 			case EXTDEF: 				if( p->suse<
literal|0
argument|){
comment|/* used */
argument|outdef( p, LUM, SVLINE ); 					} 				break; 				} 			 			}  		} 	exit(
literal|0
argument|); 	}  astype( t, i ) ATYPE *t; { 	TWORD tt; 	int j
argument_list|,
argument|k=
literal|0
argument_list|,
argument|l=
literal|0
argument|;  	if( (tt=BTYPE(t->aty))==STRTY || tt==UNIONTY ){ 		if( i<
literal|0
argument||| i>= DIMTABSZ-
literal|3
argument|){ 			werror(
literal|"lint's little mind is blown"
argument|); 			} 		else { 			j = dimtab[i+
literal|3
argument|]; 			if( j<
literal|0
argument||| j>SYMTSZ ){ 				k = dimtab[i]; 				l = X_NONAME | stab[j].suse; 				} 			else { 				if( stab[j].suse<=
literal|0
argument|) {
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"no line number for %.8s"
argument|,
else|#
directive|else
argument|werror(
literal|"no line number for %s"
argument|,
endif|#
directive|endif
argument|stab[j].sname ); 					} 				else { 					k = dimtab[i];
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|l = hashstr(stab[j].sname);
else|#
directive|else
argument|l = hashstr(stab[j].sname, LCHNM);
endif|#
directive|endif
argument|} 				} 			} 		 		t->extra = k; 		t->extra1 = l; 		return(
literal|1
argument|); 		} 	else return(
literal|0
argument|); 	}  bfcode( a, n ) int a[]; {
comment|/* code for the beginning of a function; a is an array of 		indices in stab for the arguments; n is the number */
comment|/* this must also set retlab */
argument|register i; 	register struct symtab *cfp; 	static ATYPE t;  	strforget(); 	retlab =
literal|1
argument|;  	cfp =&stab[curftn];
comment|/* if creating library, don't do static functions */
argument|if( Cflag&& cfp->sclass == STATIC ) return;
comment|/* if variable number of arguments, only print the ones which will be checked */
argument|if( vaflag>=
literal|0
argument|){ 		if( n< vaflag ) werror(
literal|"declare the VARARGS arguments you want checked!"
argument|); 		else n = vaflag; 		} 	fsave( ftitle ); 	if( cfp->sclass == STATIC ) outdef( cfp, LST, vaflag>=
literal|0
argument|?~n:n ); 	else outdef( cfp, libflag?LIB:LDI, vaflag>=
literal|0
argument|?~n:n ); 	vaflag = -
literal|1
argument|;
comment|/* output the arguments */
argument|if( n ){ 		for( i=
literal|0
argument|; i<n; ++i ) { 			t.aty = stab[a[i]].stype; 			t.extra =
literal|0
argument|; 			t.extra1 =
literal|0
argument|; 			if( !astype(&t, stab[a[i]].sizoff ) ) { 				switch( t.aty ){  				case ULONG: 					break;  				case CHAR: 				case SHORT: 					t.aty = INT; 					break;  				case UCHAR: 				case USHORT: 				case UNSIGNED: 					t.aty = UNSIGNED; 					break;  					} 				} 			fwrite( (char *)&t, sizeof(ATYPE),
literal|1
argument|, stdout ); 			} 		} 	}  ctargs( p ) NODE *p; {
comment|/* count arguments; p points to at least one */
comment|/* the arguemnts are a tower of commas to the left */
argument|register c; 	c =
literal|1
argument|;
comment|/* count the rhs */
argument|while( p->in.op == CM ){ 		++c; 		p = p->in.left; 		} 	return( c ); 	}  lpta( p ) NODE *p; { 	static ATYPE t;  	if( p->in.op == CM ){ 		lpta( p->in.left ); 		p = p->in.right; 		}  	t.aty = p->in.type; 	t.extra = (p->in.op==ICON); 	t.extra1 =
literal|0
argument|;  	if( !astype(&t, p->fn.csiz ) ) { 		switch( t.aty ){  			case CHAR: 			case SHORT: 				t.aty = INT; 			case LONG: 			case ULONG: 			case INT: 			case UNSIGNED: 				break;  			case UCHAR: 			case USHORT: 				t.aty = UNSIGNED; 				break;  			case FLOAT: 				t.aty = DOUBLE; 				t.extra =
literal|0
argument|; 				break;  			default: 				t.extra =
literal|0
argument|; 				break; 			} 		} 	fwrite( (char *)&t, sizeof(ATYPE),
literal|1
argument|, stdout ); 	}
define|#
directive|define
name|VALSET
value|1
define|#
directive|define
name|VALUSED
value|2
define|#
directive|define
name|VALASGOP
value|4
define|#
directive|define
name|VALADDR
value|8
argument|lprt( p, down, uses ) register NODE *p; { 	register struct symtab *q; 	register id; 	register acount; 	register down1, down2; 	register use1, use2; 	register struct lnm *np1, *np2;
comment|/* first, set variables which are set... */
argument|use1 = use2 = VALUSED; 	if( p->in.op == ASSIGN ) use1 = VALSET; 	else if( p->in.op == UNARY AND ) use1 = VALADDR; 	else if( asgop( p->in.op ) ){
comment|/* =ops */
argument|use1 = VALUSED|VALSET; 		if( down == EFF ) use1 |= VALASGOP; 		}
comment|/* print the lines for lint */
argument|down2 = down1 = VAL; 	acount =
literal|0
argument|;  	switch( p->in.op ){  	case EQ: 	case NE: 	case GT: 	case GE: 	case LT: 	case LE: 		if( p->in.left->in.type == CHAR&& p->in.right->in.op==ICON&& p->in.right->tn.lval<
literal|0
argument|){ 			werror(
literal|"nonportable character comparison"
argument|); 			} 		if( (p->in.op==EQ || p->in.op==NE )&& ISUNSIGNED(p->in.left->in.type)&& p->in.right->in.op == ICON ){ 			if( p->in.right->tn.lval<
literal|0
argument|&& p->in.right->tn.rval == NONAME&& !ISUNSIGNED(p->in.right->in.type) ){ 				werror(
literal|"comparison of unsigned with negative constant"
argument|); 				} 			} 		break;  	case UGE: 	case ULT: 		if( p->in.right->in.op == ICON&& p->in.right->tn.lval ==
literal|0
argument|&& p->in.right->tn.rval == NONAME ){ 			werror(
literal|"unsigned comparison with 0?"
argument|); 			break; 			} 	case UGT: 	case ULE: 		if( p->in.right->in.op == ICON&& p->in.right->tn.lval<=
literal|0
argument|&& !ISUNSIGNED(p->in.right->in.type)&& p->in.right->tn.rval == NONAME ){ 			werror(
literal|"degenerate unsigned comparison"
argument|); 			} 		break;  	case COMOP: 		down1 = EFF;  	case ANDAND: 	case OROR: 	case QUEST: 		down2 = down;
comment|/* go recursively left, then right  */
argument|np1 = lnp; 		lprt( p->in.left, down1, use1 ); 		np2 = lnp; 		lprt( p->in.right, down2, use2 ); 		lmerge( np1, np2,
literal|0
argument|); 		return;  	case SCONV: 	case PCONV: 	case COLON: 		down1 = down2 = down; 		break;  	case CALL: 	case STCALL: 	case FORTCALL: 		acount = ctargs( p->in.right ); 	case UNARY CALL: 	case UNARY STCALL: 	case UNARY FORTCALL: 		if( p->in.left->in.op == ICON&& (id=p->in.left->tn.rval) != NONAME ){
comment|/* used to be&name */
argument|struct symtab *sp =&stab[id]; 			int lty;  			fsave( ftitle ); 			if (!nflag) 				doform(p, sp, acount);
comment|/* 			 * if we're generating a library -C then 			 * we don't want to output references to functions 			 */
argument|if( Cflag ) break;
comment|/*  if a function used in an effects context is 			 *  cast to type  void  then consider its value 			 *  to have been disposed of properly 			 *  thus a call of type  undef  in an effects 			 *  context is construed to be used in a value 			 *  context 			 */
argument|if ((down == EFF)&& (p->in.type != UNDEF)) { 				lty = LUE; 			} else if (down == EFF) { 				lty = LUV | LUE; 			} else { 				lty = LUV; 			} 			outdef( sp, lty, acount ); 			if( acount ) { 				lpta( p->in.right ); 				} 			} 		break;  	case ICON:
comment|/* look for&name case */
argument|if( (id = p->tn.rval)>=
literal|0
argument|&& id != NONAME ){ 			q =&stab[id]; 			q->sflags |= (SREF|SSET); 			q->suse = -lineno; 			} 		return;  	case NAME: 		if( (id = p->tn.rval)>=
literal|0
argument|&& id != NONAME ){ 			q =&stab[id]; 			if( (uses&VALUSED)&& !(q->sflags&SSET) ){ 				if( q->sclass == AUTO || q->sclass == REGISTER ){ 					if( !ISARY(q->stype )&& !ISFTN(q->stype)&& q->stype!=STRTY&& q->stype!=UNIONTY ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"%.8s may be used before set"
argument|, q->sname );
else|#
directive|else
argument|werror(
literal|"%s may be used before set"
argument|, q->sname );
endif|#
directive|endif
argument|q->sflags |= SSET; 						} 					} 				} 			if( uses& VALASGOP ) break;
comment|/* not a real use */
argument|if( uses& VALSET ) q->sflags |= SSET; 			if( uses& VALUSED ) q->sflags |= SREF; 			if( uses& VALADDR ) q->sflags |= (SREF|SSET); 			if( p->tn.lval ==
literal|0
argument|){ 				lnp->lid = id; 				lnp->flgs = (uses&VALADDR)?
literal|0
argument|:((uses&VALSET)?VALSET:VALUSED); 				if( ++lnp>=&lnames[LNAMES] ) --lnp; 				} 			} 		return;  		}
comment|/* recurse, going down the right side first if we can */
argument|switch( optype(p->in.op) ){  	case BITYPE: 		np1 = lnp; 		lprt( p->in.right, down2, use2 ); 	case UTYPE: 		np2 = lnp; 		lprt( p->in.left, down1, use1 ); 		}  	if( optype(p->in.op) == BITYPE ){ 		if( p->in.op == ASSIGN&& p->in.left->in.op == NAME ){
comment|/* special case for a =  .. a .. */
argument|lmerge( np1, np2,
literal|0
argument|); 			} 		else lmerge( np1, np2, p->in.op != COLON );
comment|/* look for assignments to fields, and complain */
argument|if( p->in.op == ASSIGN&& p->in.left->in.op == FLD&& p->in.right->in.op == ICON ) fldcon( p ); 		}  	}  lmerge( np1, np2, flag ) struct lnm *np1, *np2; {
comment|/* np1 and np2 point to lists of lnm members, for the two sides 	 * of a binary operator 	 * flag is 1 if commutation is possible, 0 otherwise 	 * lmerge returns a merged list, starting at np1, resetting lnp 	 * it also complains, if appropriate, about side effects 	 */
argument|register struct lnm *npx, *npy;  	for( npx = np2; npx< lnp; ++npx ){
comment|/* is it already there? */
argument|for( npy = np1; npy< np2; ++npy ){ 			if( npx->lid == npy->lid ){
comment|/* yes */
argument|if( npx->flgs ==
literal|0
argument||| npx->flgs == (VALSET|VALUSED) ) 					;
comment|/* do nothing */
argument|else if( (npx->flgs|npy->flgs)== (VALSET|VALUSED) || 					(npx->flgs&npy->flgs&VALSET) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( flag ) werror(
literal|"%.8s evaluation order undefined"
argument|, stab[npy->lid].sname );
else|#
directive|else
argument|if( flag ) werror(
literal|"%s evaluation order undefined"
argument|, stab[npy->lid].sname );
endif|#
directive|endif
argument|} 				if( npy->flgs ==
literal|0
argument|) npx->flgs =
literal|0
argument|; 				else npy->flgs |= npx->flgs; 				goto foundit; 				} 			}
comment|/* not there: update entry */
argument|np2->lid = npx->lid; 		np2->flgs = npx->flgs; 		++np2;  		foundit: ; 		}
comment|/* all finished: merged list is at np1 */
argument|lnp = np2; 	}  efcode(){
comment|/* code for the end of a function */
argument|register struct symtab *cfp;  	cfp =&stab[curftn]; 	if( retstat& RETVAL&& !(Cflag&& cfp->sclass==STATIC) ) 		outdef( cfp, LRV, DECTY ); 	if( !vflag ){ 		vflag = argflag; 		argflag =
literal|0
argument|; 		} 	if( retstat == RETVAL+NRETVAL )
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"function %.8s has return(e); and return;"
argument|, cfp->sname);
else|#
directive|else
argument|werror(
literal|"function %s has return(e); and return;"
argument|, cfp->sname);
endif|#
directive|endif
argument|}  aocode(p) struct symtab *p; {
comment|/* called when automatic p removed from stab */
argument|register struct symtab *cfs; 	cfs =&stab[curftn]; 	if(p->suse>
literal|0
argument|&& !(p->sflags&(SMOS|STAG)) ){ 		if( p->sclass == PARAM ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( vflag ) werror(
literal|"argument %.8s unused in function %.8s"
argument|,
else|#
directive|else
argument|if( vflag ) werror(
literal|"argument %s unused in function %s"
argument|,
endif|#
directive|endif
argument|p->sname, 				cfs->sname ); 			} 		else {
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( p->sclass != TYPEDEF ) werror(
literal|"%.8s unused in function %.8s"
argument|,
else|#
directive|else
argument|if( p->sclass != TYPEDEF ) werror(
literal|"%s unused in function %s"
argument|,
endif|#
directive|endif
argument|p->sname, cfs->sname ); 			} 		}  	if( p->suse<
literal|0
argument|&& (p->sflags& (SSET|SREF|SMOS)) == SSET&& 		!ISARY(p->stype)&& !ISFTN(p->stype) ){
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"%.8s set but not used in function %.8s"
argument|, p->sname, cfs->sname );
else|#
directive|else
argument|werror(
literal|"%s set but not used in function %s"
argument|, p->sname, cfs->sname );
endif|#
directive|endif
argument|}  	if( p->stype == STRTY || p->stype == UNIONTY || p->stype == ENUMTY ){ 		if( !zflag&& dimtab[p->sizoff+
literal|1
argument|]<
literal|0
argument|)
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|werror(
literal|"structure %.8s never defined"
argument|, p->sname );
else|#
directive|else
argument|werror(
literal|"structure %s never defined"
argument|, p->sname );
endif|#
directive|endif
argument|}  	}  defnam( p ) register struct symtab *p; {
comment|/* define the current location as the name p->sname */
argument|if( p->sclass == STATIC&& (p->slevel>
literal|1
argument||| Cflag) ) return;  	if( !ISFTN( p->stype ) ) 		if( p->sclass == STATIC ) outdef( p, LST, USUAL ); 		else outdef( p, libflag?LIB:LDI, USUAL ); 	}  zecode( n ){
comment|/* n integer words of zeros */
argument|OFFSZ temp; 	temp = n; 	inoff += temp*SZINT; 	; 	}  andable( p ) NODE *p; {
comment|/* p is a NAME node; can it accept& ? */
argument|register r;  	if( p->in.op != NAME ) cerror(
literal|"andable error"
argument|);  	if( (r = p->tn.rval)<
literal|0
argument|) return(
literal|1
argument|);
comment|/* labels are andable */
argument|if( stab[r].sclass == AUTO || stab[r].sclass == PARAM ) return(
literal|0
argument|);
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( stab[r].sclass == REGISTER ) uerror(
literal|"can't take& of %.8s"
argument|, stab[r].sname );
else|#
directive|else
argument|if( stab[r].sclass == REGISTER ) uerror(
literal|"can't take& of %s"
argument|, stab[r].sname );
endif|#
directive|endif
argument|return(
literal|1
argument|); 	}  NODE * clocal(p) NODE *p; {
comment|/* this is called to do local transformations on 	   an expression tree preparitory to its being 	   written out in intermediate code. 	*/
comment|/* the major essential job is rewriting the 	   automatic variables and arguments in terms of 	   REG and OREG nodes */
comment|/* conversion ops which are not necessary are also clobbered here */
comment|/* in addition, any special features (such as rewriting 	   exclusive or) are easily handled here as well */
argument|register o; 	register unsigned t, tl; 	int s;  	switch( o = p->in.op ){ 	case NAME: 		{ 			extern int	didstr, subscr; 			extern NODE *	strnodes[];  			if (didstr) { 				didstr =
literal|0
argument|; 				strnodes[subscr] = p; 			} 		} 		break;  	case SCONV: 	case PCONV: 		if( p->in.left->in.type==ENUMTY ){ 			p->in.left = pconvert( p->in.left ); 			}
comment|/* assume conversion takes place; type is inherited */
argument|t = p->in.type; 		tl = p->in.left->in.type; 		if( aflag&& (tl==LONG||tl==ULONG)&& (t!=LONG&&t!=ULONG&&t!=UNDEF) ){ 			werror(
literal|"long assignment may lose accuracy"
argument|); 			} 		if( aflag>=
literal|2
argument|&& (tl!=LONG&&tl!=ULONG)&& (t==LONG||t==ULONG)&& p->in.left->in.op != ICON ){ 			werror(
literal|"assignment to long may sign-extend incorrectly"
argument|); 			} 		if( ISPTR(tl)&& ISPTR(t) ){ 			tl = DECREF(tl); 			t = DECREF(t); 			switch( ISFTN(t) + ISFTN(tl) ){  			case
literal|0
argument|:
comment|/* neither is a function pointer */
argument|if( talign(t,p->fn.csiz)> talign(tl,p->in.left->fn.csiz) ){ 					if( hflag||pflag ) werror(
literal|"possible pointer alignment problem"
argument|); 					} 				break;  			case
literal|1
argument|: 				werror(
literal|"questionable conversion of function pointer"
argument|);  			case
literal|2
argument|: 				; 				} 			} 		p->in.left->in.type = p->in.type; 		p->in.left->fn.cdim = p->fn.cdim; 		p->in.left->fn.csiz = p->fn.csiz; 		p->in.op = FREE; 		return( p->in.left );  	case PVCONV: 	case PMCONV: 		if( p->in.right->in.op != ICON ) cerror(
literal|"bad conversion"
argument|); 		p->in.op = FREE; 		return( buildtree( o==PMCONV?MUL:DIV, p->in.left, p->in.right ) );  	case RS: 	case LS: 	case ASG RS: 	case ASG LS: 		if( p->in.right->in.op != ICON ) 			break; 		s = p->in.right->tn.lval; 		if( s<
literal|0
argument|) 			werror(
literal|"negative shift"
argument|); 		else 		if( s>= dimtab[ p->fn.csiz ] ) 			werror(
literal|"shift greater than size of object"
argument|); 		break;  		}  	return(p); 	}  NODE * offcon( off, t, d, s ) OFFSZ off; TWORD t;{
comment|/* make a structure offset node */
argument|register NODE *p; 	p = bcon(
literal|0
argument|); 	p->tn.lval = off/SZCHAR; 	return(p); 	}  noinit(){
comment|/* storage class for such as "int a;" */
argument|return( pflag ? EXTDEF : EXTERN ); 	}   cinit( p, sz ) NODE *p; {
comment|/* initialize p into size sz */
argument|register int id;  	inoff += sz; 	if( p->in.op == INIT ){ 		if( p->in.left->in.op == ICON ) return; 		if( p->in.left->in.op == NAME&& p->in.left->in.type == MOE ) return; 		} 	uerror(
literal|"illegal initialization"
argument|); 	}  char * exname( p ) char *p; {
comment|/* make a name look like an external name in the local machine */
argument|static char aa[
literal|8
argument|]; 	register int i;  	if( !pflag ) return(p); 	for( i=
literal|0
argument|; i<
literal|6
argument|; ++i ){ 		if( isupper(*p ) ) aa[i] = tolower( *p ); 		else aa[i] = *p; 		if( *p ) ++p; 		} 	aa[
literal|6
argument|] =
literal|'\0'
argument|; 	return( aa ); 	}  char * strip(s) char *s; {
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|static char x[LFNM+
literal|1
argument|];
else|#
directive|else
argument|static char x[BUFSIZ];
endif|#
directive|endif
argument|register char *p; 	static	int	stripping =
literal|0
argument|;  	if (stripping) 		return(s); 	stripping++; 	for( p=x; *s; ++s ){ 		if( *s !=
literal|'"'
argument|){
ifndef|#
directive|ifndef
name|FLEXNAMES
comment|/* PATCHED by ROBERT HENRY on 8Jul80 to fix 14 character file name bug */
argument|if( p>=&x[LFNM] )
else|#
directive|else
argument|if( p>=&x[BUFSIZ] )
endif|#
directive|endif
argument|cerror(
literal|"filename too long"
argument|); 			*p++ = *s; 		} 	} 	stripping =
literal|0
argument|; 	*p =
literal|'\0'
argument|;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|return( x );
else|#
directive|else
argument|return( hash(x) );
endif|#
directive|endif
argument|}  fsave( s ) char *s; { 	static union rec fsname; 	s = strip( s );
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|if( strncmp( s, fsname.f.fn, LFNM ) )
else|#
directive|else
argument|if (fsname.f.fn == NULL || strcmp(s, fsname.f.fn))
endif|#
directive|endif
argument|{
comment|/* new one */
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|strncpy( fsname.f.fn, s, LFNM );
else|#
directive|else
argument|fsname.f.fn = s;
endif|#
directive|endif
argument|fsname.f.decflag = LFN; 		fwrite( (char *)&fsname, sizeof(fsname),
literal|1
argument|, stdout );
ifdef|#
directive|ifdef
name|FLEXNAMES
comment|/* if generating a library, prefix with the library name */
comment|/* only do this for flexnames */
argument|if( libname ){ 			fwrite( libname, strlen(libname),
literal|1
argument|, stdout ); 			putchar(
literal|':'
argument|); 			} 		fwrite( fsname.f.fn, strlen(fsname.f.fn)+
literal|1
argument|,
literal|1
argument|, stdout );
endif|#
directive|endif
argument|} 	}  where(f){
comment|/* print true location of error */
argument|if( f ==
literal|'u'
argument|&& nerrors>
literal|1
argument|) 		--nerrors;
comment|/* don't get "too many errors" */
argument|fprintf( stderr,
literal|"%s(%d): "
argument|, strip(ftitle), lineno); 	}
comment|/* a number of dummy routines, unneeded by lint */
argument|branch(n){;} defalign(n){;} deflab(n){;}  extern char *	strchr();
define|#
directive|define
name|SBUFSIZE
value|16
define|#
directive|define
name|SCLICK
value|80
ifndef|#
directive|ifndef
name|size_t
define|#
directive|define
name|size_t
value|unsigned
endif|#
directive|endif
comment|/* !size_t */
argument|static char *	strings[SBUFSIZE]; static NODE *	strnodes[SBUFSIZE]; static int	didstr; static int	subscr; static int	strapped;  bycode(t, i) { 	extern char *	calloc(); 	extern char *	realloc();  	if (nflag || strapped) 		return; 	if (i ==
literal|0
argument|) 		if (subscr< (SBUFSIZE -
literal|1
argument|)) 			++subscr; 	if (subscr>= SBUFSIZE) 		return; 	didstr =
literal|1
argument|; 	if ((i % SCLICK) ==
literal|0
argument|) { 		strings[subscr] = (strings[subscr] == NULL) ? 			calloc((size_t) (SCLICK +
literal|1
argument|),
literal|1
argument|) : 			realloc(strings[subscr], (size_t) (i + SCLICK +
literal|1
argument|)); 		if (strings[subscr] == NULL) { 			strapped =
literal|1
argument|; 			return; 		} 	} 	strings[subscr][i] = t; }  strforget() { 	didstr = subscr =
literal|0
argument|; }  static char * typestr(t) { 	switch (t) { 		case CHAR:		return
literal|"char"
argument|; 		case UCHAR:		return
literal|"unsigned char"
argument|; 		case SHORT:		return
literal|"short"
argument|; 		case USHORT:		return
literal|"unsigned short"
argument|; 		case INT:		return
literal|"int"
argument|; 		case UNSIGNED:		return
literal|"unsigned"
argument|; 		case ENUMTY:		return
literal|"enum"
argument|; 		case LONG:		return
literal|"long"
argument|; 		case ULONG:		return
literal|"unsigned long"
argument|; 		case FLOAT:		return
literal|"float"
argument|; 		case DOUBLE:		return
literal|"double"
argument|; 		case STRTY:		return
literal|"struct"
argument|; 		case UNIONTY:		return
literal|"union"
argument|; 		case PTR|CHAR:		return
literal|"char *"
argument|; 		case PTR|UCHAR:		return
literal|"unsigned char *"
argument|; 		case PTR|SHORT:		return
literal|"short *"
argument|; 		case PTR|USHORT:	return
literal|"unsigned short *"
argument|; 		case PTR|INT:		return
literal|"int *"
argument|; 		case PTR|UNSIGNED:	return
literal|"unsigned *"
argument|; 		case PTR|ENUMTY:	return
literal|"enum *"
argument|; 		case PTR|LONG:		return
literal|"long *"
argument|; 		case PTR|ULONG:		return
literal|"unsigned long *"
argument|; 		case PTR|FLOAT:		return
literal|"float *"
argument|; 		case PTR|DOUBLE:	return
literal|"double *"
argument|; 		case PTR|STRTY:		return
literal|"struct *"
argument|; 		case PTR|UNIONTY:	return
literal|"union *"
argument|; 		default:		return ISPTR(t) ?
literal|"pointer"
argument|:
literal|"non-scalar"
argument|; 	} }  NODE * ntharg(p, n, acount) NODE *		p; register int	n; register int	acount; { 	if (n> acount) 		return NULL; 	p = p->in.right; 	while (n != acount) { 		p = p->in.left; 		--acount; 	} 	return (n ==
literal|1
argument|) ? p : p->in.right; }  struct entry {
comment|/* If argument to print/scan is of type... */
argument|int	argtype;
comment|/* ...and this length character is used... */
argument|char	lchar;
comment|/* ...and one of these is control char... */
argument|char *	cchars;
comment|/* ...then use this format with werror... */
argument|char *	werror;
comment|/* ...(where NULL means it's hunky dory)... */
argument|};
comment|/* ** Portable printf. ** H&S says "%o" takes an unsigned argument; ** X3J11 says "%o" takes an int argument; ** we'll allow either here. */
argument|static struct entry pprintf[] = { 	CHAR,
literal|'\0'
argument|,
literal|"c"
argument|,		NULL,
comment|/* this is deliberate */
argument|INT,
literal|'\0'
argument|,
literal|"cdoxX"
argument|,	NULL, 	UNSIGNED,
literal|'\0'
argument|,
literal|"uoxX"
argument|,		NULL, 	CHAR,
literal|'\0'
argument|,
literal|"cdoxX"
argument|,	NULL, 	UCHAR,
literal|'\0'
argument|,
literal|"udoxX"
argument|,	NULL,
comment|/* yes, d is okay */
argument|SHORT,
literal|'\0'
argument|,
literal|"cdoxX"
argument|,	NULL, 	USHORT,
literal|'\0'
argument|,
literal|"uoxX"
argument|,		NULL, 	ENUMTY,
literal|'\0'
argument|,
literal|"duoxX"
argument|,	NULL, 	LONG,
literal|'l'
argument|,
literal|"doxX"
argument|,		NULL, 	ULONG,
literal|'l'
argument|,
literal|"uoxX"
argument|,		NULL, 	FLOAT,
literal|'\0'
argument|,
literal|"eEfgG"
argument|,	NULL, 	DOUBLE,
literal|'\0'
argument|,
literal|"eEfgG"
argument|,	NULL, 	PTR|CHAR,
literal|'\0'
argument|,
literal|"s"
argument|,		NULL, 	UNDEF,
literal|'\0'
argument|,
literal|""
argument|,		NULL };
comment|/* ** Berkeley printf. ** It allows %D, %O, and %U, which we deprecate. ** Since **	sizeof (char *) == sizeof (int)&& **	sizeof (int) == sizeof (long)&& **	sizeof (char *) == sizeof (int *) ** you can be lax--and we tolerate *some* laxness.  ** g/lax/p to find lax table entries and code. */
argument|static char	uppercase[] =
literal|"deprecated upper-case control character (%c)"
argument|;
define|#
directive|define
name|lax
value|NULL
argument|static struct entry bprintf[] = { 	CHAR,
literal|'\0'
argument|,
literal|"c"
argument|,		NULL,
comment|/* this is deliberate */
argument|INT,
literal|'\0'
argument|,
literal|"cdoxX"
argument|,	NULL, 	INT,
literal|'\0'
argument|,
literal|"DO"
argument|,		uppercase, 	UNSIGNED,
literal|'\0'
argument|,
literal|"uoxX"
argument|,		NULL, 	UNSIGNED,
literal|'\0'
argument|,
literal|"UO"
argument|,		uppercase, 	CHAR,
literal|'\0'
argument|,
literal|"cdoxX"
argument|,	NULL, 	CHAR,
literal|'\0'
argument|,
literal|"DO"
argument|,		uppercase, 	UCHAR,
literal|'\0'
argument|,
literal|"duoxX"
argument|,	NULL,
comment|/* yes, d is okay */
argument|UCHAR,
literal|'\0'
argument|,
literal|"DUO"
argument|,		uppercase, 	SHORT,
literal|'\0'
argument|,
literal|"cdoxX"
argument|,	NULL, 	SHORT,
literal|'\0'
argument|,
literal|"DO"
argument|,		uppercase, 	USHORT,
literal|'\0'
argument|,
literal|"duoxX"
argument|,	NULL,
comment|/* d okay on BSD */
argument|USHORT,
literal|'\0'
argument|,
literal|"DUO"
argument|,		uppercase, 	ENUMTY,
literal|'\0'
argument|,
literal|"duoxX"
argument|,	NULL, 	ENUMTY,
literal|'\0'
argument|,
literal|"DUO"
argument|,		uppercase, 	LONG,
literal|'\0'
argument|,
literal|"doxX"
argument|,		lax, 	LONG,
literal|'\0'
argument|,
literal|"DO"
argument|,		uppercase, 	LONG,
literal|'l'
argument|,
literal|"doxX"
argument|,		NULL, 	INT,
literal|'l'
argument|,
literal|"doxX"
argument|,		lax, 	ULONG,
literal|'\0'
argument|,
literal|"uoxX"
argument|,		lax, 	ULONG,
literal|'\0'
argument|,
literal|"UO"
argument|,		uppercase, 	ULONG,
literal|'l'
argument|,
literal|"uoxX"
argument|,		NULL, 	UNSIGNED,
literal|'l'
argument|,
literal|"uoxX"
argument|,		lax, 	FLOAT,
literal|'\0'
argument|,
literal|"eEfgG"
argument|,	NULL, 	DOUBLE,
literal|'\0'
argument|,
literal|"eEfgG"
argument|,	NULL, 	PTR|CHAR,
literal|'\0'
argument|,
literal|"s"
argument|,		NULL, 	UNDEF,
literal|'\0'
argument|,	NULL,		NULL, };
comment|/* ** Portable scanf.  'l' and 'h' are universally ignored preceding 'c' and 's', ** and 'h' is universally ignored preceding 'e' and 'f', ** but you won't find such cruft here. */
argument|static struct entry pscanf[] = { 	INT,
literal|'\0'
argument|,
literal|"dox"
argument|,	NULL, 	UNSIGNED,
literal|'\0'
argument|,
literal|"uox"
argument|,	NULL, 	CHAR,
literal|'\0'
argument|,
literal|"cs["
argument|,	NULL, 	SHORT,
literal|'h'
argument|,
literal|"dox"
argument|,	NULL, 	USHORT,
literal|'h'
argument|,
literal|"uox"
argument|,	NULL, 	LONG,
literal|'l'
argument|,
literal|"dox"
argument|,	NULL, 	ULONG,
literal|'l'
argument|,
literal|"uox"
argument|,	NULL, 	FLOAT,
literal|'\0'
argument|,
literal|"ef"
argument|,	NULL,
comment|/* BSD doesn't handle g */
argument|DOUBLE,
literal|'l'
argument|,
literal|"ef"
argument|,	NULL, 	UNDEF,
literal|'\0'
argument|,	NULL,	NULL, };
comment|/* ** Berkeley scanf.  An upper case letter equals an l plus the lower case char, ** but this is deprecated. ** Even though sizeof (int) == sizeof (long), we'll be picky here. */
argument|static struct entry bscanf[] = { 	INT,
literal|'\0'
argument|,
literal|"dox"
argument|,	NULL, 	UNSIGNED,
literal|'\0'
argument|,
literal|"uox"
argument|,	NULL, 	CHAR,
literal|'\0'
argument|,
literal|"cs["
argument|,	NULL, 	SHORT,
literal|'h'
argument|,
literal|"dox"
argument|,	NULL, 	USHORT,
literal|'h'
argument|,
literal|"uox"
argument|,	NULL, 	LONG,
literal|'\0'
argument|,
literal|"dox"
argument|,	lax, 	LONG,
literal|'\0'
argument|,
literal|"DOX"
argument|,	uppercase, 	LONG,
literal|'l'
argument|,
literal|"dox"
argument|,	NULL, 	ULONG,
literal|'\0'
argument|,
literal|"uox"
argument|,	lax, 	ULONG,
literal|'\0'
argument|,
literal|"UOX"
argument|,	uppercase, 	ULONG,
literal|'l'
argument|,
literal|"uox"
argument|,	NULL, 	FLOAT,
literal|'\0'
argument|,
literal|"ef"
argument|,	NULL, 	DOUBLE,
literal|'\0'
argument|,
literal|"EF"
argument|,	uppercase, 	DOUBLE,
literal|'l'
argument|,
literal|"ef"
argument|,	NULL, 	UNDEF,
literal|'\0'
argument|,	NULL,	NULL, };  static struct item { 	char *		name;
comment|/* such as "printf" */
argument|int		isscan;
comment|/* scanf/printf */
argument|int		fmtarg;
comment|/* number of format argument */
argument|struct entry *	ptable;
comment|/* portable checking table */
argument|struct entry *	btable;
comment|/* berkeley checking table */
argument|} items[] = {
literal|"printf"
argument|,
literal|0
argument|,
literal|1
argument|,	pprintf,	bprintf,
literal|"fprintf"
argument|,
literal|0
argument|,
literal|2
argument|,	pprintf,	bprintf,
literal|"sprintf"
argument|,
literal|0
argument|,
literal|2
argument|,	pprintf,	bprintf,
literal|"scanf"
argument|,
literal|1
argument|,
literal|1
argument|,	pscanf,		bscanf,
literal|"fscanf"
argument|,
literal|1
argument|,
literal|2
argument|,	pscanf,		bscanf,
literal|"sscanf"
argument|,
literal|1
argument|,
literal|2
argument|,	pscanf,		bscanf, 	NULL,		-
literal|1
argument|,	-
literal|1
argument|,	NULL,		NULL };  static char	pwf[]	=
literal|"possible wild format"
argument|; static char	pfacm[]	=
literal|"possible format/argument count mismatch"
argument|;  static struct entry * findlc(ep, lchar, cchar) register struct entry *	ep; register int		lchar; register int		cchar; { 	for ( ; ep->argtype != UNDEF; ++ep) 		if (ep->lchar == lchar&& strchr(ep->cchars, cchar) !=
literal|0
argument|) 			return ep; 	return NULL; }  static char * subform(p, sp, acount) register NODE *			p; register struct symtab *	sp; { 	register int		i, j, isscan; 	register NODE *		tp; 	register char *		cp; 	register struct entry *	basep; 	register struct entry *	ep; 	register struct item *	ip; 	register int		lchar; 	register int		cchar; 	register int		t; 	register int		suppressed; 	static char		errbuf[
literal|132
argument|];  	if (nflag || strapped) 		return NULL; 	cp = sp->sname; 	for (ip = items; ; ++ip) 		if (ip->name == NULL) 			return NULL;
comment|/* not a print/scan function */
argument|else if (strcmp(ip->name, sp->sname) ==
literal|0
argument|) 			break; 	isscan = ip->isscan; 	i = ip->fmtarg; 	if (i> acount) 		return NULL;
comment|/* handled in pass 2 */
argument|tp = ntharg(p, i, acount); 	if (tp->in.type != (PTR|CHAR)) 		return NULL;
comment|/* handled in pass 2 */
argument|if (tp->in.op != ICON || tp->tn.lval !=
literal|0
argument|) 		return NULL;
comment|/* can't check it */
argument|for (j =
literal|1
argument|; j<= subscr; ++j) 		if (tp == strnodes[j]) 			break; 	if (j> subscr) 		return NULL;
comment|/* oh well. . . */
argument|cp = strings[j];
comment|/* 	** cp now points to format string. 	*/
comment|/* 	** For now, ALWAYS use "portable" table, rather than doing this: 	**	basep = pflag ? ip->ptable : ip->btable; 	*/
argument|basep = ip->ptable; 	for ( ; ; ) { 		if (*cp ==
literal|'\0'
argument|) 			return (i == acount) ? NULL : pfacm; 		if (*cp++ !=
literal|'%'
argument|) 			continue; 		if (*cp ==
literal|'\0'
argument|) 			return
literal|"wild trailing %% in format"
argument|; 		if (*cp ==
literal|'%'
argument|) { 			++cp; 			continue; 		} 		if (isscan) { 			suppressed = *cp ==
literal|'*'
argument|; 			if (suppressed) 				++cp; 			while (isdigit(*cp)) 				++cp; 			if (!suppressed&& ++i<= acount) { 				t = ntharg(p, i, acount)->in.type; 				if (!ISPTR(t)) { (void) sprintf(errbuf,
literal|"%s argument is type (%s) rather than pointer (arg %d)"
argument|, 	ip->name, typestr(t), i); 					return errbuf; 				} 				t = DECREF(t); 			} 		} else { 			int	nspace, ndash, nplus, nhash;  			suppressed =
literal|0
argument|; 			nspace = ndash = nplus = nhash =
literal|0
argument|; 			for ( ; ; ) { 				if (*cp ==
literal|' '
argument|) 					++nspace; 				else if (*cp ==
literal|'+'
argument|) 					++nplus; 				else if (*cp ==
literal|'-'
argument|) 					++ndash; 				else if (*cp ==
literal|'#'
argument|) 					++nhash; 				else	break; 				++cp; 			} 			if (nspace>
literal|1
argument||| ndash>
literal|1
argument||| nplus>
literal|1
argument||| nhash>
literal|1
argument|) 				return
literal|"wild repeated flag character in format"
argument|; 			if (*cp ==
literal|'*'
argument|) { 				++cp; 				if (++i> acount) 					break; 				t = ntharg(p, i, acount)->in.type;
comment|/* 				** Width other than INT or UNSIGNED is suspect. 				*/
argument|if (t != INT&& t != UNSIGNED) { (void) sprintf(errbuf,
literal|"field width argument is type (%s) rather than (int) (arg %d)"
argument|, 	typestr(t), i); 					return errbuf; 				} 			} else while (isdigit(*cp)) 				++cp; 			if (*cp ==
literal|'.'
argument|) { 				++cp; 				if (*cp ==
literal|'*'
argument|) { 					++cp; 					if (++i> acount) 						return pfacm; 					t = ntharg(p, i, acount)->in.type; 					if (t != INT&& t != UNSIGNED) { (void) sprintf(errbuf,
literal|"precision argument is type (%s) rather than (int) (arg %d)"
argument|, 	typestr(t), i); 						return errbuf; 					} 				} else while (isdigit(*cp)) 					++cp; 			} 			if (++i<= acount) 				t = ntharg(p, i, acount)->in.type; 		} 		if (*cp ==
literal|'h'
argument||| *cp ==
literal|'l'
argument|) 			lchar = *cp++; 		else	lchar =
literal|'\0'
argument|; 		if ((cchar = *cp++) ==
literal|'\0'
argument|) 			return pwf; 		if (i> acount) 			return (findlc(basep, lchar, cchar) == NULL) ? 				pwf : pfacm; 		if (!isscan&& !pflag&& ISPTR(t)&& 			strchr(
literal|"douxX"
argument|, cchar) !=
literal|0
argument|) 				continue;
comment|/* lax--printf("%d", (int *)) */
argument|if (suppressed) { 			if (findlc(basep, lchar, cchar) == NULL) 				return pwf; 		} else for (ep = basep; ; ++ep) { 			if (ep->argtype == UNDEF) {
comment|/* end of table */
argument|ep = findlc(basep, lchar, cchar); 				if (ep == NULL) 					return pwf; (void) sprintf(errbuf,
literal|"%s: (%s) format, (%s) arg (arg %d)"
argument|, 					ip->name, 					typestr(ep->argtype), 					typestr(isscan ? (t | PTR) : t), i); 				return errbuf; 			} 			if (ep->argtype == t&& ep->lchar == lchar&& 				strchr(ep->cchars, cchar) !=
literal|0
argument|) 					if (ep->werror ==
literal|0
argument|) 						break; 					else { 						werror(ep->werror, cchar); 						return NULL; 					} 		} 		if (cchar !=
literal|'['
argument|) 			continue; 		do { 			if (*cp ==
literal|'\0'
argument|) 				return
literal|"possible unmatched '[' in format"
argument|; 		} while (*cp++ !=
literal|']'
argument|); 	}
comment|/*NOTREACHED*/
argument|}  doform(p, sp, acount) NODE *		p; struct symtab *	sp; { 	char *	cp;  	if ((cp = subform(p, sp, acount)) != NULL) 		werror(cp); }  cisreg(t) TWORD t; {return(
literal|1
argument|);}
comment|/* everyting is a register variable! */
argument|fldty(p) struct symtab *p; { 	;
comment|/* all types are OK here... */
argument|}  fldal(t) unsigned t; {
comment|/* field alignment... */
argument|if( t == ENUMTY ) return( ALCHAR );
comment|/* this should be thought through better... */
argument|if( ISPTR(t) ){
comment|/* really for the benefit of honeywell (and someday IBM) */
argument|if( pflag ) uerror(
literal|"nonportable field type"
argument|); 		} 	else uerror(
literal|"illegal field type"
argument|); 	return(ALINT); 	}  main(argc, argv) 	int	argc; 	char	**argv; { 	extern char	*optarg; 	extern int	optind; 	int	ch;  	while ((ch = getopt(argc,argv,
literal|"C:D:I:U:LX:Pabchnpuvxz"
argument|)) != EOF) 		switch((char)ch) { 			case
literal|'C'
argument|: 				Cflag =
literal|1
argument|; 				libname = optarg; 				continue; 			case
literal|'D'
argument|:
comment|/* #define */
argument|case
literal|'I'
argument|:
comment|/* include path */
argument|case
literal|'U'
argument|:
comment|/* #undef */
argument|case
literal|'X'
argument|:
comment|/* debugging, done in first pass */
argument|case
literal|'P'
argument|:
comment|/* debugging, done in second pass */
argument|break; 			case
literal|'L'
argument|: 				libflag =
literal|1
argument|;
comment|/*FALLTHROUGH*/
argument|case
literal|'v'
argument|:
comment|/* unused arguments in functions */
argument|vflag =
literal|0
argument|; 				break; 			case
literal|'a'
argument|:
comment|/* long to int assignment */
argument|++aflag; 				break; 			case
literal|'b'
argument|:
comment|/* unreached break statements */
argument|brkflag =
literal|1
argument|; 				break; 			case
literal|'c'
argument|:
comment|/* questionable casts */
argument|cflag =
literal|1
argument|; 				break; 			case
literal|'h'
argument|:
comment|/* heuristics */
argument|hflag =
literal|1
argument|; 				break; 			case
literal|'n'
argument|:
comment|/* standard library check */
argument|nflag =
literal|1
argument|; 				break; 			case
literal|'p'
argument|:
comment|/* IBM& GCOS portability */
argument|pflag =
literal|1
argument|; 				break; 			case
literal|'u'
argument|:
comment|/* 2nd pass: undefined or unused */
argument|break; 			case
literal|'x'
argument|:
comment|/* unused externs */
argument|xflag =
literal|1
argument|; 				break; 			case
literal|'z'
argument|:
comment|/* use of undefined structures */
argument|zflag =
literal|1
argument|; 				break; 			case
literal|'?'
argument|: 			default: 				fputs(
literal|"usage: lint [-C lib] [-D def] [-I include] [-U undef] [-Labchnpuvx] file ...\n"
argument|,stderr); 				exit(
literal|1
argument|); 		}  	if (!pflag) {
comment|/* set sizes to sizes of target machine */
ifdef|#
directive|ifdef
name|gcos
argument|SZCHAR = ALCHAR =
literal|9
argument|;
else|#
directive|else
argument|SZCHAR = ALCHAR =
literal|8
argument|;
endif|#
directive|endif
argument|SZINT = ALINT = sizeof(int)*SZCHAR; 		SZFLOAT = ALFLOAT = sizeof(float)*SZCHAR; 		SZDOUBLE = ALDOUBLE = sizeof(double)*SZCHAR; 		SZLONG = ALLONG = sizeof(long)*SZCHAR; 		SZSHORT = ALSHORT = sizeof(short)*SZCHAR; 		SZPOINT = ALPOINT = sizeof(int *)*SZCHAR; 		ALSTRUCT = ALINT;
comment|/* now, fix some things up for various machines (I wish we had "alignof") */
ifdef|#
directive|ifdef
name|pdp11
argument|ALLONG = ALDOUBLE = ALFLOAT = ALINT;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ibm
argument|ALSTRUCT = ALCHAR;
endif|#
directive|endif
argument|} 	return(mainp1(argc,argv)); }  ctype( type ) unsigned type; {
comment|/* are there any funny types? */
argument|return( type ); 	}  commdec( i ){
comment|/* put out a common declaration */
argument|if( stab[i].sclass == STATIC ) outdef(&stab[i], LST, USUAL ); 	else outdef(&stab[i], libflag?LIB:LDC, USUAL ); 	}  isitfloat ( s ) char *s; {
comment|/* s is a character string; 	   if floating point is implemented, set dcon to the value of s */
comment|/* lint version 	*/
argument|dcon = atof( s ); 	return( DCON ); 	}  fldcon( p ) register NODE *p; {
comment|/* p is an assignment of a constant to a field */
comment|/* check to see if the assignment is going to overflow, or otherwise cause trouble */
argument|register s; 	CONSZ v;  	if( !hflag& !pflag ) return;  	s = UPKFSZ(p->in.left->tn.rval); 	v = p->in.right->tn.lval;  	switch( p->in.left->in.type ){  	case CHAR: 	case INT: 	case SHORT: 	case LONG: 	case ENUMTY: 		if( v>=
literal|0
argument|&& (v>>(s-
literal|1
argument|))==
literal|0
argument|) return; 		werror(
literal|"precision lost in assignment to (possibly sign-extended) field"
argument|); 	default: 		return;  	case UNSIGNED: 	case UCHAR: 	case USHORT: 	case ULONG: 		if( v<
literal|0
argument||| (v>>s)!=
literal|0
argument|) werror(
literal|"precision lost in field assignment"
argument|); 		 		return; 		}  	}  outdef( p, lty, mode ) struct symtab *p; {
comment|/* output a definition for the second pass */
comment|/* if mode is> USUAL, it is the number of args */
argument|char *fname; 	TWORD t; 	int line; 	static union rec rc;  	if( mode == NOFILE ){ 		fname =
literal|"???"
argument|; 		line = p->suse; 		} 	else if( mode == SVLINE ){ 		fname = ftitle; 		line = -p->suse; 		} 	else { 		fname = ftitle; 		line = lineno; 		} 	fsave( fname );
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|strncpy( rc.l.name, exname(p->sname), LCHNM );
endif|#
directive|endif
argument|rc.l.decflag = lty; 	t = p->stype; 	if( mode == DECTY ) t = DECREF(t); 	rc.l.type.aty = t; 	rc.l.type.extra =
literal|0
argument|; 	rc.l.type.extra1 =
literal|0
argument|; 	astype(&rc.l.type, p->sizoff ); 	rc.l.nargs = (mode>USUAL) ? mode :
literal|0
argument|; 	rc.l.fline = line; 	fwrite( (char *)&rc, sizeof(rc),
literal|1
argument|, stdout );
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|rc.l.name = exname(p->sname); 	fwrite( rc.l.name, strlen(rc.l.name)+
literal|1
argument|,
literal|1
argument|, stdout );
endif|#
directive|endif
argument|} int proflg; int gdebug;
end_block

end_unit

