begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1982 Regents of the University of California  */
end_comment

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
literal|"@(#)asparse.c 4.8 2/14/82"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_include
include|#
directive|include
file|"asscan.h"
end_include

begin_include
include|#
directive|include
file|"assyms.h"
end_include

begin_include
include|#
directive|include
file|"asexpr.h"
end_include

begin_decl_stmt
name|int
name|lgensym
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|genref
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|bitfield
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bitoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current length of literals */
end_comment

begin_comment
comment|/*  *	The following three variables are communication between various  *	modules to special case a number of things.  They are properly  *	categorized as hacks.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|lastnam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*last name seen by the lexical analyzer*/
end_comment

begin_decl_stmt
name|int
name|exprisname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*last factor in an expression was a name*/
end_comment

begin_decl_stmt
name|int
name|droppedLP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*one is analyzing an expression beginning with*/
end_comment

begin_comment
comment|/*a left parenthesis, which has already been*/
end_comment

begin_comment
comment|/*shifted. (Used to parse (<expr>)(rn)*/
end_comment

begin_decl_stmt
name|char
name|yytext
index|[
name|NCPS
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the lexical image*/
end_comment

begin_decl_stmt
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the lexical value; sloppy typing*/
end_comment

begin_decl_stmt
name|struct
name|Opcode
name|yyopcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lexical value for an opcode */
end_comment

begin_decl_stmt
name|Bignum
name|yybignum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lexical value for a big number */
end_comment

begin_comment
comment|/*  *	Expression and argument managers  */
end_comment

begin_decl_stmt
name|struct
name|exp
modifier|*
name|xp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*next free expression slot, used by expr.c*/
end_comment

begin_decl_stmt
name|struct
name|exp
name|explist
index|[
name|NEXP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*max of 20 expressions in one opcode*/
end_comment

begin_decl_stmt
name|struct
name|arg
name|arglist
index|[
name|NARG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*building up operands in instructions*/
end_comment

begin_comment
comment|/*  *	Sets to accelerate token discrimination  */
end_comment

begin_decl_stmt
name|char
name|tokensets
index|[
operator|(
name|LASTTOKEN
operator|)
operator|-
operator|(
name|FIRSTTOKEN
operator|)
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|UDotsname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*name of the assembly source*/
end_comment

begin_macro
name|yyparse
argument_list|()
end_macro

begin_block
block|{
name|reg
name|struct
name|exp
modifier|*
name|locxp
decl_stmt|;
comment|/* 		 *	loc1xp and ptrloc1xp are used in the 		 * 	expression lookahead 		 */
name|struct
name|exp
modifier|*
name|loc1xp
decl_stmt|;
comment|/*must be non register*/
name|struct
name|exp
modifier|*
modifier|*
name|ptrloc1xp
init|=
operator|&
name|loc1xp
decl_stmt|;
name|struct
name|exp
modifier|*
name|pval
decl_stmt|;
comment|/*hacking expr:expr*/
name|reg
name|struct
name|symtab
modifier|*
name|np
decl_stmt|;
name|reg
name|int
name|argcnt
decl_stmt|;
name|reg
name|inttoktype
name|val
decl_stmt|;
comment|/*what yylex gives*/
name|reg
name|inttoktype
name|auxval
decl_stmt|;
comment|/*saves val*/
name|reg
name|struct
name|arg
modifier|*
name|ap
decl_stmt|;
comment|/*first free argument*/
name|reg
name|struct
name|symtab
modifier|*
name|p
decl_stmt|;
name|reg
name|struct
name|symtab
modifier|*
name|stpt
decl_stmt|;
name|struct
name|strdesc
modifier|*
name|stringp
decl_stmt|;
comment|/*handles string lists*/
name|int
name|regno
decl_stmt|;
comment|/*handles arguments*/
name|int
modifier|*
name|ptrregno
init|=
operator|&
name|regno
decl_stmt|;
name|int
name|sawmul
decl_stmt|;
comment|/*saw * */
name|int
name|sawindex
decl_stmt|;
comment|/*saw [rn]*/
name|int
name|sawsize
decl_stmt|;
name|int
name|seg_type
decl_stmt|;
comment|/*the kind of segment: data or text*/
name|int
name|seg_number
decl_stmt|;
comment|/*the segment number*/
name|int
name|space_value
decl_stmt|;
comment|/*how much .space needs*/
name|int
name|fill_rep
decl_stmt|;
comment|/*how many reps for .fill */
name|int
name|fill_size
decl_stmt|;
comment|/*how many bytes for .fill */
name|int
name|field_width
decl_stmt|;
comment|/*how wide a field is to be*/
name|int
name|field_value
decl_stmt|;
comment|/*the value to stuff in a field*/
name|char
modifier|*
name|stabname
decl_stmt|;
comment|/*name of stab dealing with*/
name|ptrall
name|stabstart
decl_stmt|;
comment|/*where the stab starts in the buffer*/
name|int
name|reloc_how
decl_stmt|;
comment|/* how to relocate expressions */
name|int
name|toconv
decl_stmt|;
comment|/* how to convert bignums */
name|xp
operator|=
name|explist
expr_stmt|;
name|ap
operator|=
name|arglist
expr_stmt|;
name|val
operator|=
name|yylex
argument_list|()
expr_stmt|;
while|while
condition|(
name|val
operator|!=
name|PARSEEOF
condition|)
block|{
comment|/* primary loop */
while|while
condition|(
name|INTOKSET
argument_list|(
name|val
argument_list|,
name|LINSTBEGIN
argument_list|)
condition|)
block|{
if|if
condition|(
name|val
operator|==
name|INT
condition|)
block|{
name|int
name|i
init|=
operator|(
operator|(
expr|struct
name|exp
operator|*
operator|)
name|yylval
operator|)
operator|->
name|e_xvalue
decl_stmt|;
name|shift
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|COLON
condition|)
block|{
name|yyerror
argument_list|(
literal|"Local label %d is not followed by a ':' for a label definition"
argument_list|,
name|i
argument_list|)
expr_stmt|;
goto|goto
name|errorfix
goto|;
block|}
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>
literal|9
condition|)
block|{
name|yyerror
argument_list|(
literal|"Local labels are 0-9"
argument_list|)
expr_stmt|;
goto|goto
name|errorfix
goto|;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|yytext
argument_list|,
literal|"L%d\001%d"
argument_list|,
name|i
argument_list|,
name|lgensym
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|lgensym
index|[
name|i
index|]
operator|++
expr_stmt|;
name|genref
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|yylval
operator|=
operator|(
name|int
operator|)
operator|*
name|lookup
argument_list|(
name|passno
operator|==
literal|1
argument_list|)
expr_stmt|;
name|val
operator|=
name|NAME
expr_stmt|;
name|np
operator|=
operator|(
expr|struct
name|symtab
operator|*
operator|)
name|yylval
expr_stmt|;
goto|goto
name|restlab
goto|;
block|}
if|if
condition|(
name|val
operator|==
name|NL
condition|)
block|{
name|lineno
operator|++
expr_stmt|;
name|shift
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|val
operator|==
name|SEMI
condition|)
name|shift
expr_stmt|;
else|else
block|{
comment|/*its a name, so we have a label or def */
if|if
condition|(
name|val
operator|!=
name|NAME
condition|)
block|{
name|ERROR
argument_list|(
literal|"Name expected for a label"
argument_list|)
expr_stmt|;
block|}
name|np
operator|=
operator|(
expr|struct
name|symtab
operator|*
operator|)
name|yylval
expr_stmt|;
name|shiftover
argument_list|(
name|NAME
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
name|COLON
condition|)
block|{
ifdef|#
directive|ifdef
name|FLEXNAMES
name|yyerror
argument_list|(
literal|"\"%s\" is not followed by a ':' for a label definition"
argument_list|,
else|#
directive|else
else|not FLEXNAMES
argument|yyerror(
literal|"\"%.*s\" is not followed by a ':' for a label definition"
argument|, 					NCPS,
endif|#
directive|endif
endif|not FLEXNAMES
argument|np->s_name); 				goto  errorfix; 			} restlab: 			shift; 			flushfield(NBPW/
literal|4
argument|); 			if ((np->s_type&XTYPE)!=XUNDEF) { 				if(  (np->s_type&XTYPE)!=dotp->e_xtype  				   || np->s_value!=dotp->e_xvalue 				   || (  (passno==
literal|1
argument|)&&(np->s_index != dotp->e_xloc) 				      ) 				  ){
ifndef|#
directive|ifndef
name|DEBUG
argument|if (np->s_name[
literal|0
argument|] !=
literal|'L'
argument|)
endif|#
directive|endif
endif|not DEBUG
argument|{ 						if (passno ==
literal|1
argument|)
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|yyerror(
literal|"%s redefined"
argument|,
else|#
directive|else
else|not FLEXNAMES
argument|yyerror(
literal|"%.*s redefined"
argument|, 							NCPS,
endif|#
directive|endif
endif|not FLEXNAMES
argument|np->s_name); 						else
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|yyerror(
literal|"%s redefined: PHASE ERROR, 1st: %d, 2nd: %d"
argument|,
else|#
directive|else
else|not FLEXNAMES
argument|yyerror(
literal|"%.*s redefined: PHASE ERROR, 1st: %d, 2nd: %d"
argument|, 							NCPS,
endif|#
directive|endif
endif|not FLEXNAMES
argument|np->s_name, 							np->s_value, 							dotp->e_xvalue); 					} 				} 			} 			np->s_type&= ~(XTYPE|XFORW); 			np->s_type |= dotp->e_xtype; 			np->s_value = dotp->e_xvalue; 			if (passno ==
literal|1
argument|){ 				np->s_index = dotp-usedot; 				if (np->s_name[
literal|0
argument|] ==
literal|'L'
argument|){ 					nlabels++; 				} 				np->s_tag = LABELID; 			} 		}
comment|/*end of this being a label*/
argument|}
comment|/*end of to consuming all labels, NLs and SEMIS */
argument|xp = explist; 	ap = arglist;
comment|/* 	 *	process the INSTRUCTION body 	 */
argument|switch(val){      default: 	ERROR(
literal|"Unrecognized instruction or directive"
argument|);     case IABORT: 	shift; 	sawabort();
comment|/*NOTREACHED*/
argument|break;     case PARSEEOF: 	tokptr -= sizeof(bytetoktype); 	*tokptr++ = VOID; 	tokptr[
literal|1
argument|] = VOID; 	tokptr[
literal|2
argument|] = PARSEEOF; 	break;     case IFILE: 	shift; 	stringp = (struct strdesc *)yylval; 	shiftover(STRING); 	dotsname =&UDotsname[
literal|0
argument|]; 	movestr(dotsname, stringp->str, 		stringp->str_lg>=
literal|32
argument|?
literal|32
argument|:stringp->str_lg); 	dotsname[stringp->str_lg] =
literal|'\0'
argument|; 	break;     case ILINENO: 	shift;
comment|/*over the ILINENO*/
argument|expr(locxp, val); 	lineno = locxp->e_xvalue; 	break;     case ISET:
comment|/* .set<name> ,<expr> */
argument|shift; 	np = (struct symtab *)yylval; 	shiftover(NAME); 	shiftover(CM); 	expr(locxp, val); 	np->s_type&= (XXTRN|XFORW); 	np->s_type |= locxp->e_xtype&(XTYPE|XFORW); 	np->s_value = locxp->e_xvalue; 	if (passno==
literal|1
argument|) 		np->s_index = locxp->e_xloc; 	if ((locxp->e_xtype&XTYPE) == XUNDEF) 		yyerror(
literal|"Illegal set?"
argument|); 	break;     case ILSYM:
comment|/*.lsym name , expr */
argument|shift; 	np = (struct symtab *)yylval; 	shiftover(NAME); 	shiftover(CM); 	expr(locxp, val);
comment|/* 	 *	Build the unique occurance of the 	 *	symbol. 	 *	The character scanner will have 	 *	already entered it into the symbol 	 *	table, but we should remove it 	 */
argument|if (passno ==
literal|1
argument|){ 		stpt = (struct symtab *)symalloc();
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|stpt->s_name = np->s_name;
else|#
directive|else
argument|movestr(stpt->s_name, np->s_name, NCPS);
endif|#
directive|endif
argument|np->s_tag = OBSOLETE;
comment|/*invalidate original */
argument|nforgotten++; 		np = stpt; 		if ( (locxp->e_xtype& XTYPE) != XABS) 			yyerror(
literal|"Illegal second argument to lsym"
argument|); 		np->s_value = locxp->e_xvalue; 		np->s_type = XABS; 		np->s_tag = ILSYM; 	} 	break;     case IGLOBAL:
comment|/*.globl<name> */
argument|shift; 	np = (struct symtab *)yylval; 	shiftover(NAME); 	np->s_type |= XXTRN; 	break;     case IDATA:
comment|/*.data [<expr> ] */
argument|case ITEXT:
comment|/*.text [<expr> ] */
argument|seg_type = -val; 	shift; 	if (INTOKSET(val, EBEGOPS+YUKKYEXPRBEG+SAFEEXPRBEG)){ 		expr(locxp, val); 		seg_type = -seg_type;
comment|/*now, it is positive*/
argument|}  	if (seg_type<
literal|0
argument|) {
comment|/*there wasn't an associated expr*/
argument|seg_number =
literal|0
argument|; 		seg_type = -seg_type; 	} else { 		if (   ((locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument||| (seg_number = locxp->e_xvalue)>= NLOC) { 			yyerror(
literal|"illegal location counter"
argument|); 			seg_number =
literal|0
argument|; 		} 	} 	if (seg_type == IDATA) 		seg_number += NLOC; 	flushfield(NBPW/
literal|4
argument|); 	dotp =&usedot[seg_number];
ifdef|#
directive|ifdef
name|UNIX
argument|if (passno==
literal|2
argument|) {
comment|/* go salt away in pass 2*/
argument|txtfil = usefile[seg_number]; 		relfil = rusefile[seg_number]; 	}
endif|#
directive|endif
endif|UNIX
ifdef|#
directive|ifdef
name|VMS
argument|if (passno==
literal|2
argument|) { 		puchar(vms_obj_ptr,
literal|6
argument|);
comment|/*  setpl  */
argument|puchar(vms_obj_ptr,seg_number);
comment|/* psect # */
argument|plong(vms_obj_ptr,dotp->e_xvalue);
comment|/*  offset */
argument|puchar(vms_obj_ptr,
literal|80
argument|);
comment|/*  setrb  */
argument|if((vms_obj_ptr-sobuf)>
literal|400
argument|){ 			write(objfil,sobuf,vms_obj_ptr-sobuf); 			vms_obj_ptr=sobuf+
literal|1
argument|;
comment|/*flush buf*/
argument|} 	}
endif|#
directive|endif
endif|VMS
argument|break;
comment|/* 	 *	Storage filler directives: 	 * 	 *	.byte	[<exprlist>] 	 * 	 *	exprlist:  empty | exprlist outexpr 	 *	outexpr:<expr> |<expr> :<expr> 	 */
argument|case IBYTE:	curlen = NBPW/
literal|4
argument|; goto elist;    case IWORD:	curlen = NBPW/
literal|2
argument|; goto elist;    case IINT:	curlen = NBPW;   goto elist;    case ILONG:	curlen = NBPW;   goto elist;     elist: 	seg_type = val; 	shift;
comment|/* 	 *	Expression List processing 	 */
argument|if (INTOKSET(val, EBEGOPS+YUKKYEXPRBEG+SAFEEXPRBEG)){ 	    do{
comment|/* 		 *	expression list consists of a list of : 		 *<expr> 		 *<expr> :<expr>  		 *		(pack expr2 into expr1 bits 		 */
argument|expr(locxp, val);
comment|/* 		 *	now, pointing at the next token 		 */
argument|if (val == COLON){ 			shiftover(COLON); 			expr(pval, val); 			if ((locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument|yyerror(
literal|"Width not absolute"
argument|); 			field_width = locxp->e_xvalue; 			locxp = pval; 			if (bitoff + field_width> curlen) 				flushfield(curlen); 			if (field_width> curlen) 				yyerror(
literal|"Expression crosses field boundary"
argument|); 		} else { 			field_width = curlen; 			flushfield(curlen); 		}  		if ((locxp->e_xtype& XTYPE) != XABS) { 			if (bitoff) 				yyerror(
literal|"Illegal relocation in field"
argument|); 			switch(curlen){ 				case NBPW/
literal|4
argument|:	reloc_how = TYPB; break; 				case NBPW/
literal|2
argument|:	reloc_how = TYPW; break; 				case NBPW:	reloc_how = TYPL; break; 			} 			if (passno ==
literal|1
argument|){ 				dotp->e_xvalue += ty_nbyte[reloc_how]; 			} else { 				outrel(locxp, reloc_how); 			} 		} else { 			field_value = locxp->e_xvalue& ( (
literal|1L
argument|<< field_width)-
literal|1
argument|); 			bitfield |= field_value<< bitoff; 			bitoff += field_width; 		} 		xp = explist; 		if (auxval = (val == CM)) 			shift; 	    } while (auxval); 	}
comment|/* there existed an expression at all */
argument|flushfield(curlen); 	if ( ( curlen == NBPW/
literal|4
argument|)&& bitoff) 		dotp->e_xvalue ++; 	break;
comment|/*end of case IBYTE, IWORD, ILONG, IINT*/
argument|case ISPACE:
comment|/* .space<expr> */
argument|shift; 	expr(locxp, val); 	if ((locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument|yyerror(
literal|"Space size not absolute"
argument|); 	space_value = locxp->e_xvalue;   ospace: 	flushfield(NBPW/
literal|4
argument|);
ifdef|#
directive|ifdef
name|UNIX
argument|while (space_value>
literal|96
argument|){ 		outs(strbuf[
literal|2
argument|].str,
literal|96
argument|); 		space_value -=
literal|96
argument|; 	} 	outs(strbuf[
literal|2
argument|].str, space_value);
endif|#
directive|endif
endif|UNIX
ifdef|#
directive|ifdef
name|VMS
argument|dotp->e_xvalue += space_value;
comment|/*bump pc*/
argument|if (passno==
literal|2
argument|){ 	  if(*(strbuf[
literal|2
argument|].str)==
literal|0
argument|) { 		puchar(vms_obj_ptr,
literal|81
argument|);
comment|/* AUGR  */
argument|pulong(vms_obj_ptr,space_value);
comment|/* incr  */
argument|} else yyerror(
literal|"VMS, encountered non-0 .space"
argument|); 	  if ((vms_obj_ptr-sobuf)>
literal|400
argument|) { 		write(objfil,sobuf,vms_obj_ptr-sobuf); 		vms_obj_ptr=sobuf+
literal|1
argument|;
comment|/*pur buf*/
argument|} 	}
endif|#
directive|endif
endif|VMS
argument|break;
ifdef|#
directive|ifdef
name|UNIX
comment|/* 	 *	.fill rep, size, value 	 *	repeat rep times: fill size bytes with (truncated) value 	 *	size must be between 1 and 8 	 */
argument|case	IFILL: 	shift; 	expr(locxp, val); 	if ( (locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument|yyerror(
literal|"Fill repetition count not absolute"
argument|); 	fill_rep = locxp->e_xvalue; 	shiftover(CM); 	expr(locxp, val); 	if ( (locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument|yyerror(
literal|"Fill size not absolute"
argument|); 	fill_size = locxp->e_xvalue; 	if (fill_size<=
literal|0
argument||| fill_size>
literal|8
argument|) 		yyerror(
literal|"Fill count not in in 1..8"
argument|); 	shiftover(CM); 	expr(locxp, val); 	if (passno ==
literal|2
argument|&& (locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument|yyerror(
literal|"Fill value not absolute"
argument|); 	flushfield(NBPW/
literal|4
argument|); 	if (passno ==
literal|1
argument|) { 		dotp->e_xvalue += fill_rep * fill_size; 	} else { 		while(fill_rep-->
literal|0
argument|) 			bwrite((char *)&locxp->e_xvalue, fill_size, txtfil); 	} 	break;
endif|#
directive|endif
endif|UNIX
argument|case IASCII:
comment|/* .ascii [<stringlist> ] */
argument|case IASCIZ:
comment|/* .asciz [<stringlist> ] */
argument|auxval = val; 	shift;
comment|/* 	 *	Code to consume a string list 	 * 	 *	stringlist: empty | STRING | stringlist STRING 	 */
argument|while (val ==  STRING){ 		flushfield(NBPW/
literal|4
argument|); 		if (bitoff) 		  dotp->e_xvalue++; 		stringp = (struct strdesc *)yylval;
ifdef|#
directive|ifdef
name|UNIX
argument|outs(stringp->str, stringp->str_lg);
endif|#
directive|endif
endif|UNIX
ifdef|#
directive|ifdef
name|VMS
argument|{ 			reg int i; 			for (i=
literal|0
argument|; i< stringp->str_lg; i++){ 			  dotp->e_xvalue +=
literal|1
argument|; 			    if (passno==
literal|2
argument|){ 				puchar(vms_obj_ptr,-
literal|1
argument|); 			  	puchar(vms_obj_ptr,stringp->str[i]); 			  	if (vms_obj_ptr-sobuf>
literal|400
argument|) { 				  write(objfil,sobuf,vms_obj_ptr-sobuf); 				  vms_obj_ptr = sobuf +
literal|1
argument|; 			  	} 			    } 			} 		}
endif|#
directive|endif
endif|VMS
argument|shift;
comment|/*over the STRING*/
argument|if (val == CM)
comment|/*could be a split string*/
argument|shift; 	}  	if (auxval == IASCIZ){ 		flushfield(NBPW/
literal|4
argument|);
ifdef|#
directive|ifdef
name|UNIX
argument|outb(
literal|0
argument|);
endif|#
directive|endif
endif|UNIX
ifdef|#
directive|ifdef
name|VMS
argument|if (passno ==
literal|2
argument|) { 			puchar(vms_obj_ptr,-
literal|1
argument|); 			puchar(vms_obj_ptr,
literal|0
argument|); 		} 		dotp->e_xvalue +=
literal|1
argument|;
endif|#
directive|endif
endif|VMS
argument|} 	break; 	    case IORG:
comment|/* .org<expr> */
argument|shift; 	expr(locxp, val);  	if ((locxp->e_xtype& XTYPE) == XABS)
comment|/* tekmdp */
argument|orgwarn++; 	else if ((locxp->e_xtype& ~XXTRN) != dotp->e_xtype) 		yyerror(
literal|"Illegal expression to set origin"
argument|); 	space_value = locxp->e_xvalue - dotp->e_xvalue; 	if (space_value<
literal|0
argument|) 		yyerror(
literal|"Backwards 'org'"
argument|); 	goto ospace; 	break;
comment|/*  *  *	Process stabs.  Stabs are created only by the f77  *	and the C compiler with the -g flag set.  *	We only look at the stab ONCE, during pass 1, and  *	virtually remove the stab from the intermediate file  *	so it isn't seen during pass2.  This makes for some  *	hairy processing to handle labels occuring in  *	stab entries, but since most expressions in the  *	stab are integral we save lots of time in the second  *	pass by not looking at the stabs.  *	A stab that is tagged floating will be bumped during  *	the jxxx resolution phase.  A stab tagged fixed will  *	not be be bumped.  *  *	.stab:	Old fashioned stabs  *	.stabn: For stabs without names  *	.stabs:	For stabs with string names  *	.stabd: For stabs for line numbers or bracketing,  *		without a string name, without  *		a final expression.  The value of the  *		final expression is taken to be  the current  *		location counter, and is patched by the 2nd pass  *  *	.stab{<expr>,}*NCPS,<expr>,<expr>,<expr>,<expr>  *	.stabn<expr>,<expr>,<expr>,<expr>  *	.stabs   STRING,<expr>,<expr>,<expr>,<expr>  *	.stabd<expr>,<expr>,<expr> # .   */
argument|case ISTAB:
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|stabname =
literal|".stab"
argument|; 	if (passno ==
literal|2
argument|)	goto errorfix; 	stpt = (struct symtab *)yylval;
comment|/* 	 *	Make a pointer to the .stab slot. 	 *	There is a pointer in the way (stpt), and 	 *	tokptr points to the next token. 	 */
argument|stabstart = tokptr; 	(char *)stabstart -= sizeof(struct symtab *); 	(char *)stabstart -= sizeof(bytetoktype); 	shift; 	for (argcnt =
literal|0
argument|; argcnt< NCPS; argcnt++){ 		expr(locxp, val); 		stpt->s_name[argcnt] = locxp->e_xvalue; 		xp = explist; 		shiftover(CM); 	} 	goto tailstab;
else|#
directive|else
else|FLEXNAMES
argument|yyerror(
literal|".stab directive not supported in; report this compiler bug to system administrator"
argument|); 	goto errorfix;
endif|#
directive|endif
endif|FLEXNAMES
argument|tailstab: 	expr(locxp, val); 	if (! (locxp->e_xvalue& STABTYPS)){ 		yyerror(
literal|"Invalid type in %s"
argument|, stabname); 		goto errorfix; 	} 	stpt->s_ptype = locxp->e_xvalue; 	shiftover(CM); 	expr(locxp, val); 	stpt->s_other = locxp->e_xvalue; 	shiftover(CM); 	expr(locxp, val); 	stpt->s_desc = locxp->e_xvalue; 	shiftover(CM); 	exprisname =
literal|0
argument|; 	expr(locxp, val); 	p = locxp->e_xname; 	if (p == NULL) {
comment|/*absolute expr to begin with*/
argument|stpt->s_value = locxp->e_xvalue; 		stpt->s_index = dotp - usedot; 		if (exprisname){ 			switch(stpt->s_ptype){ 				case N_GSYM: 				case N_FNAME: 				case N_RSYM: 				case N_SSYM: 				case N_LSYM: 				case N_PSYM: 				case N_BCOMM: 				case N_ECOMM: 				case N_LENG: 					stpt->s_tag = STABFIXED; 					break; 				default: 					stpt->s_tag = STABFLOATING; 					break; 			} 		} else 			stpt->s_tag = STABFIXED; 	} 	else {
comment|/*really have a name*/
argument|stpt->s_dest = locxp->e_xname; 		stpt->s_index = p->s_index; 		stpt->s_type = p->s_type | STABFLAG;
comment|/* 		 *	We will assign a more accruate 		 *	guess of locxp's location when 		 *	we sort the symbol table 		 *	The final value of value is 		 *	given by stabfix() 		 */
argument|stpt->s_tag = STABFLOATING; 	}
comment|/* 	 *	tokptr now points at one token beyond 	 *	the current token stored in val and yylval, 	 *	which are the next tokens after the end of 	 *	this .stab directive.  This next token must 	 *	be either a SEMI or NL, so is of width just 	 *	one.  Therefore, to point to the next token 	 *	after the end of this stab, just back up one.. 	 */
argument|buildskip(stabstart, (bytetoktype *)tokptr - sizeof(bytetoktype)); 	break;
comment|/*end of the .stab*/
argument|case ISTABDOT:	 	stabname =
literal|".stabd"
argument|; 	stpt = (struct symtab *)yylval;
comment|/* 	 *	We clobber everything after the 	 *	.stabd and its pointer... we MUST 	 *	be able to get back to this .stabd 	 *	so that we can resolve its final value 	 */
argument|stabstart = tokptr; 	shift;
comment|/*over the ISTABDOT*/
argument|if (passno ==
literal|1
argument|){ 		expr(locxp, val); 		if (! (locxp->e_xvalue& STABTYPS)){ 			yyerror(
literal|"Invalid type in .stabd"
argument|); 			goto errorfix; 		} 		stpt->s_ptype = locxp->e_xvalue; 		shiftover(CM); 		expr(locxp, val); 		stpt->s_other = locxp->e_xvalue; 		shiftover(CM); 		expr(locxp, val); 		stpt->s_desc = locxp->e_xvalue;
comment|/* 		 * 		 *	Now, clobber everything but the 		 *	.stabd pseudo and the pointer 		 *	to its symbol table entry 		 *	tokptr points to the next token, 		 *	build the skip up to this 		 */
argument|buildskip(stabstart, (bytetoktype *)tokptr - sizeof(bytetoktype)); 	}
comment|/* 	 *	pass 1:	Assign a good guess for its position 	 *		(ensures they are sorted into right place)/ 	 *	pass 2:	Fix the actual value 	 */
argument|stpt->s_value = dotp->e_xvalue; 	stpt->s_index = dotp - usedot; 	stpt->s_tag = STABFLOATING;
comment|/*although it has no effect in pass 2*/
argument|break;     case ISTABNONE:	stabname =
literal|".stabn"
argument|; goto shortstab;     case ISTABSTR: 	stabname =
literal|".stabs"
argument|;    shortstab: 	auxval = val; 	if (passno ==
literal|2
argument|) goto errorfix; 	stpt = (struct symtab *)yylval; 	stabstart = tokptr; 	(bytetoktype *)stabstart -= sizeof(struct symtab *); 	(bytetoktype *)stabstart -= sizeof(bytetoktype); 	shift; 	if (auxval == ISTABSTR){ 		stringp = (struct strdesc *)yylval; 		shiftover(STRING);
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|auxval = stringp->str_lg> NCPS ? NCPS : stringp->str_lg;
else|#
directive|else
argument|stringp->str[stringp->str_lg] =
literal|0
argument|;
endif|#
directive|endif
argument|shiftover(CM); 	} else { 		stringp =&(strbuf[
literal|2
argument|]);
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|auxval = NCPS;
endif|#
directive|endif
argument|}
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|movestr(stpt->s_name, stringp->str, auxval);
else|#
directive|else
argument|stpt->s_name = savestr(stringp->str);
endif|#
directive|endif
argument|goto tailstab; 	break;     case ICOMM:
comment|/* .comm<name> ,<expr> */
argument|case ILCOMM:
comment|/* .lcomm<name> ,<expr> */
argument|auxval = val; 	shift; 	np = (struct symtab *)yylval; 	shiftover(NAME); 	shiftover(CM); 	expr(locxp, val);  	if ( (locxp->e_xtype& XTYPE) != XABS)
comment|/* tekmdp */
argument|yyerror(
literal|"comm size not absolute"
argument|); 	if (passno ==
literal|1
argument|&& (np->s_type&XTYPE) != XUNDEF)
ifdef|#
directive|ifdef
name|FLEXNAMES
argument|yyerror(
literal|"Redefinition of %s"
argument|,
else|#
directive|else
else|not FLEXNAMES
argument|yyerror(
literal|"Redefinition of %.*s"
argument|, 			NCPS,
endif|#
directive|endif
endif|not FLEXNAMES
argument|np->s_name); 	if (passno==
literal|1
argument|) { 		np->s_value = locxp->e_xvalue; 		if (auxval == ICOMM) 			np->s_type |= XXTRN; 		else { 			np->s_type&= ~XTYPE; 			np->s_type |= XBSS; 		} 	} 	break;     case IALIGN:
comment|/* .align<expr> */
argument|stpt = (struct symtab *)yylval; 	shift; 	expr(locxp, val); 	jalign(locxp, stpt); 	break;     case INST0:
comment|/* instructions w/o arguments*/
argument|insout(yyopcode, (struct arg *)
literal|0
argument|,
literal|0
argument|); 	shift;	 	break;     case INSTn:
comment|/* instructions with arguments*/
argument|case IJXXX:
comment|/* UNIX style jump instructions */
argument|auxval = val;
comment|/* 	 *	Code to process an argument list 	 */
argument|ap = arglist; 	xp = explist;	  	shift;
comment|/* bring in the first token for the arg list*/
argument|for (argcnt =
literal|1
argument|; argcnt<=
literal|6
argument|; argcnt++, ap++){
comment|/* 		 *	code to process an argument proper 		 */
argument|sawindex  = sawmul = sawsize =
literal|0
argument|; 	    { 		switch(val) {  		   default: 		     disp: 			if( !(INTOKSET(val, 				 EBEGOPS 				+YUKKYEXPRBEG 				+SAFEEXPRBEG)) ) { 				ERROR(
literal|"expression expected"
argument|); 			} 			expr(ap->a_xp,val); 		     overdisp: 			if ( val == LP || sawsize){ 				shiftover(LP); 				findreg(regno); 				shiftover(RP); 				ap->a_atype = ADISP; 				ap->a_areg1 = regno; 			} else { 				ap->a_atype = AEXP; 				ap->a_areg1 =
literal|0
argument|; 			} 			goto index;  		   case SIZESPEC:  		     sizespec: 			sawsize = yylval; 			shift; 			goto disp;  		   case REG: 		   case REGOP:  			findreg(regno); 			ap->a_atype = AREG; 			ap->a_areg1 = regno; 			break; 		     		   case MUL:  			sawmul =
literal|1
argument|; 			shift; 			if (val == LP) goto base; 			if (val == LITOP) goto imm; 			if (val == SIZESPEC) goto sizespec; 			if (INTOKSET(val, 				 EBEGOPS 				+YUKKYEXPRBEG 				+SAFEEXPRBEG)) goto disp; 			ERROR(
literal|"expression, '(' or '$' expected"
argument|); 			break;  		   case LP:  		     base: 			shift;
comment|/*consume the LP*/
comment|/* 			 *	hack the ambiguity of 			 *	movl (expr) (rn), ... 			 *	note that (expr) could also 			 *	be (rn) (by special hole in the 			 *	grammar), which we ensure 			 *	means register indirection, instead 			 *	of an expression with value n 			 */
argument|if (val != REG&& val != REGOP){ 				droppedLP =
literal|1
argument|; 				val = exprparse(val,&(ap->a_xp)); 				droppedLP =
literal|0
argument|; 				goto overdisp; 			} 			findreg(regno); 			shiftover(RP); 			if (val == PLUS){ 				shift; 				ap->a_atype = AINCR; 			} else 				ap->a_atype = ABASE; 			ap->a_areg1 = regno; 			goto index;  		   case LITOP:  		      imm: 			shift; 			expr(locxp, val); 			ap->a_atype = AIMM; 			ap->a_areg1 =
literal|0
argument|; 			ap->a_xp = locxp; 			goto index;  		   case MP:  			shift;
comment|/* -(reg) */
argument|findreg(regno); 			shiftover(RP); 			ap->a_atype = ADECR; 			ap->a_areg1 = regno; 	  index:
comment|/*look for [reg] */
argument|if (val == LB){ 				shift; 				findreg(regno); 				shiftover(RB); 				sawindex =
literal|1
argument|; 				ap->a_areg2 = regno; 			} 			break;  		}
comment|/*end of the switch to process an arg*/
argument|}
comment|/*end of processing an argument*/
argument|if (sawmul){
comment|/* 			 * Make a concession for *(%r) 			 * meaning *0(%r)  			 */
argument|if (ap->a_atype == ABASE) { 				ap->a_atype = ADISP; 				xp->e_xtype = XABS; 				xp->e_number = Znumber; 				xp->e_number.num_tag = TYPL; 				xp->e_xloc =
literal|0
argument|; 				ap->a_xp = xp++; 			} 			ap->a_atype |= ASTAR; 			sawmul =
literal|0
argument|; 	    } 	    if (sawindex){ 		ap->a_atype |= AINDX; 		sawindex =
literal|0
argument|; 	    } 	    ap->a_dispsize = sawsize ==
literal|0
argument|? d124 : sawsize; 		if (val != CM) break; 		shiftover(CM); 	}
comment|/*processing all the arguments*/
argument|if (argcnt>
literal|6
argument|){ 		yyerror(
literal|"More than 6 arguments"
argument|); 		goto errorfix; 	}  	insout(yyopcode, arglist, 		auxval == INSTn ? argcnt : - argcnt); 	break;     case IQUAD:		toconv = TYPQ;	goto bignumlist;    case IOCTA:		toconv = TYPO;	goto bignumlist;     case IFFLOAT:	toconv = TYPF;	goto bignumlist;    case IDFLOAT:	toconv = TYPD;	goto bignumlist;    case IGFLOAT:	toconv = TYPG;	goto bignumlist;    case IHFLOAT:	toconv = TYPH;	goto bignumlist;    bignumlist:
comment|/* 	 *	eat a list of non 32 bit numbers. 	 *	IQUAD and IOCTA can, possibly, return 	 *	INT's, if the numbers are "small". 	 * 	 *	The value of the numbers is coming back 	 *	as an expression, NOT in yybignum. 	 */
argument|shift;
comment|/* over the opener */
argument|if ((val == BIGNUM) || (val == INT)){ 		do{ 			if ((val != BIGNUM)&& (val != INT)){ 				ERROR(ty_float[toconv] 				   ?
literal|"floating number expected"
argument|:
literal|"integer number expected"
argument|); 			} 			dotp->e_xvalue += ty_nbyte[toconv]; 			if (passno ==
literal|2
argument|){ 				bignumwrite( 					((struct exp *)yylval)->e_number, 					toconv); 			} 			xp = explist; 			shift;
comment|/* over this number */
argument|if (auxval = (val == CM)) 				shift;
comment|/* over the comma */
argument|} while (auxval);
comment|/* as long as there are commas */
argument|} 	break;
comment|/* end of the case for initialized big numbers */
argument|}
comment|/*end of the switch for looking at each reserved word*/
argument|continue;     errorfix:
comment|/* 	 *	got here by either requesting to skip to the 	 *	end of this statement, or by erroring out and 	 *	wanting to apply panic mode recovery 	 */
argument|while (    (val != NL)&& (val != SEMI)&& (val != PARSEEOF) 	      ){ 		shift; 	} 	if (val == NL) 		lineno++; 	shift;      }
comment|/*end of the loop to read the entire file, line by line*/
argument|}
comment|/*end of yyparse*/
comment|/*  *	Process a register declaration of the form  *	%<expr>  *  *	Note:  *		The scanner has already processed funny registers of the form  *	%dd[+-]*, where dd is a decimal number in the range 00 to 15 (optional  *	preceding zero digit).  If there was any space between the % and  *	the digit, the scanner wouldn't have recognized it, so we  *	hack it out here.  */
argument|inttoktype funnyreg(val, regnoback)
comment|/*what the read head will sit on*/
argument|inttoktype	val;
comment|/*what the read head is sitting on*/
argument|int	*regnoback;
comment|/*call by return*/
argument|{ 	reg	struct	exp *locxp; 		struct	exp *loc1xp; 		struct	exp **ptrloc1xp =& loc1xp;  	expr(locxp, val);
comment|/*and leave the current read head with value*/
argument|if ( (passno ==
literal|2
argument|)&& 	    (   (locxp->e_xtype& XTYPE) != XABS 	     || (locxp->e_xvalue<
literal|0
argument|) 	     || (locxp->e_xvalue>=
literal|16
argument|) 	    ) 	  ){ 		yyerror(
literal|"Illegal register"
argument|); 		return(
literal|0
argument|); 	} 	*regnoback = locxp->e_xvalue; 	return(val); }
comment|/*VARARGS1*/
argument|yyerror(s, a1, a2,a3,a4,a5) 	char	*s; {
define|#
directive|define
name|sink
value|stdout
argument|if (anyerrs ==
literal|0
argument|&& anywarnings ==
literal|0
argument|&& ! silent)  		fprintf(sink,
literal|"Assembler:\n"
argument|); 	anyerrs++; 	if (silent) 		return; 	fprintf(sink,
literal|"\"%s\", line %d: "
argument|, dotsname, lineno); 	fprintf(sink, s, a1, a2,a3,a4,a5); 	fprintf(sink,
literal|"\n"
argument|);
undef|#
directive|undef
name|sink
argument|}
comment|/*VARARGS1*/
argument|yywarning(s, a1, a2,a3,a4,a5) 	char	*s; {
define|#
directive|define
name|sink
value|stdout
argument|if (anyerrs ==
literal|0
argument|&& anywarnings ==
literal|0
argument|&& ! silent)  		fprintf(sink,
literal|"Assembler:\n"
argument|); 	anywarnings++; 	if (silent) 		return; 	fprintf(sink,
literal|"\"%s\", line %d: WARNING: "
argument|, dotsname, lineno); 	fprintf(sink, s, a1, a2,a3,a4,a5); 	fprintf(sink,
literal|"\n"
argument|);
undef|#
directive|undef
name|sink
argument|}
end_block

end_unit

