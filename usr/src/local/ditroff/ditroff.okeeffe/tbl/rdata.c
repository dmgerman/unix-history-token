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
literal|"@(#)rdata.c	1.2 (CWI) 85/10/02"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  * read data for table  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"ext.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_macro
name|gettbl
argument_list|()
end_macro

begin_block
block|{
name|int
name|icol
decl_stmt|,
name|ch
decl_stmt|;
extern|extern interr(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|chspace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|maknew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|alocv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gettext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|savsign
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|cstore
operator|=
name|cspace
operator|=
name|chspace
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|textflg
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|nlin
operator|=
name|nslin
operator|=
literal|0
init|;
name|gets1
argument_list|(
name|cstore
argument_list|)
condition|;
name|nlin
operator|++
control|)
block|{
name|stynum
index|[
name|nlin
index|]
operator|=
name|nslin
expr_stmt|;
if|if
condition|(
name|prefix
argument_list|(
literal|".TE"
argument_list|,
name|cstore
argument_list|)
condition|)
block|{
name|leftover
operator|=
literal|0
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|prefix
argument_list|(
literal|".TC"
argument_list|,
name|cstore
argument_list|)
operator|||
name|prefix
argument_list|(
literal|".T&"
argument_list|,
name|cstore
argument_list|)
condition|)
block|{
name|readspec
argument_list|()
expr_stmt|;
name|nslin
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|nlin
operator|>=
name|MAXLIN
condition|)
block|{
name|leftover
operator|=
operator|(
name|int
operator|)
name|cstore
expr_stmt|;
break|break;
block|}
name|fullbot
index|[
name|nlin
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|cstore
index|[
literal|0
index|]
operator|==
literal|'.'
operator|&&
operator|!
name|isdigit
argument_list|(
name|cstore
index|[
literal|1
index|]
argument_list|)
condition|)
block|{
name|instead
index|[
name|nlin
index|]
operator|=
name|cstore
expr_stmt|;
while|while
condition|(
operator|*
name|cstore
operator|++
condition|)
empty_stmt|;
continue|continue;
block|}
else|else
name|instead
index|[
name|nlin
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nodata
argument_list|(
name|nlin
argument_list|)
condition|)
block|{
if|if
condition|(
name|ch
operator|=
name|oneh
argument_list|(
name|nlin
argument_list|)
condition|)
name|fullbot
index|[
name|nlin
index|]
operator|=
name|ch
expr_stmt|;
ifdef|#
directive|ifdef
name|FIX
name|This
name|FIX
name|didn
literal|'t work, so commented out for the time being, 	problem temporarily solved with signal catching... dprint(".\\\" FIX nlin = %d\n", nlin); dprint(".\\\" FIXgettbl: alocv %d\n", (ncol + 2) * sizeof(table[0][0])); 			/* 			 * start of FIX? 			 * 			 * Need to allocate pointers as well, in case 			 * of vertical spanning. 			 * I hope this works 			 */ 			table[nlin] = (struct colstr *) alocv((ncol + 2) * 							sizeof(*table[0])); 			/* 			 * Does alocv clears the pointers? 			 */ 		{	int tmp; 			for( tmp = 0; tmp< ncol +2; tmp++) { 		table[nlin][tmp].col = ""; 		table[nlin][tmp].rcol = (char*)0; printf(".\\\"FIX table[%d][%d].col:<%s>\n", nlin, tmp, table[nlin][tmp].col); printf(".\\\"FIX table[%d][%d].rcol:<%s>\n", nlin, tmp, table[nlin][tmp].rcol); 			} 		} 			/* 			 * End of FIX 			 */ #endif FIX 			nlin++; 			nslin++; 			instead[nlin] = (char *) 0; 			fullbot[nlin] = 0; dprint(".\\\" gettbl continue, due to nodata\n"); 		} 		table[nlin] = (struct colstr *) alocv((ncol + 2) * 							sizeof(*table[0])); 		if(cstore[1] == 0) { 			switch(cstore[0]){  			case '
name|_
literal|':  				fullbot[nlin] = '
operator|-
literal|'; 				continue; 			case '
operator|=
literal|':  				fullbot[nlin] = '
operator|=
literal|'; 				continue; 			} 		} 		stynum[nlin] = nslin; 		nslin = min(nslin + 1, nclin - 1); 		for(icol = 0; icol< ncol; icol++){ 			table[nlin][icol].col = cstore; 			table[nlin][icol].rcol = (char*)0; 			ch = 1; 			if(strcmp(cstore, "T{") == 0) { 				/* 				 * text follows 				 */ 				table[nlin][icol].col = 						gettext(cstore, nlin, icol, 						font[stynum[nlin]][icol], 						csize[stynum[nlin]][icol]); 			} else { 				for(; (ch = *cstore) != '
operator|\
literal|0
literal|'&& ch != tab; cstore++) 					; 				*cstore++ = '
operator|\
literal|0
literal|'; 				switch(ctype(nlin, icol)){  					/* 					 * numerical or alpha, subcol 					 */ 				case '
name|n
literal|':  					table[nlin][icol].rcol = maknew(table[nlin][icol].col); 					break; 				case '
name|a
literal|':  					table[nlin][icol].rcol = table[nlin][icol].col; 					table[nlin][icol].col = ""; 					break; 				} 			} 			while(ctype(nlin, icol + 1) == '
name|s
literal|'){ 				/* 				 * spanning 				 */ 				table[nlin][++icol].col = ""; 			} 			if(ch == '
operator|\
literal|0
literal|') 				break; 		} 		while(++icol< ncol + 2){ 			table[nlin][icol].col = ""; 			table[nlin][icol].rcol = (char*)0; 		} 		while(*cstore != '
operator|\
literal|0
literal|') 			cstore++; 		if(cstore - cspace> MAXCHS) 			cstore = cspace = chspace(); 	} 	last = cstore; 	/* 	 * the next example is weird& legal tbl input. 	 * however, it generates a bus error. .TS linesize(24) tab(@); ct| c cf3 ^ | _ _ ^ | cf3 cf3 ^ | c s. 0,0@0,1@0,2 @1,1@1,2 @2,1@2,2 .TE 	 * This works: .TS linesize(24) tab(@); ct| c cf3 ^ | cf3 cf3 ^ | c s. 0,0@0,1@0,2 @1,1@1,2 @2,1@2,2 .TE 	 * So it is the vertical spanning of an empty column which 	 * cuases problems 	 */ 	savsign = signal(SIGBUS, interr); 	permute(); 	signal(SIGBUS, savsign); 	if(textflg) 		untext(); 	return; }  /*  * return 1 if no type of column specified for this line  */ nodata(il){ 	int c;  	for(c = 0; c< ncol; c++){ 		switch(ctype(il, c)){  		case '
name|c
literal|':  		case '
name|n
literal|':  		case '
name|r
literal|':  		case '
name|l
literal|':  		case '
name|s
literal|':  		case '
name|a
literal|':  			return(0); 		} 	} 	return(1); }  /*  * returns the type of heading if they are all the same for the table  * line?  */ oneh(lin){ 	int k, icol;  	k = ctype(lin, 0); 	for(icol = 1; icol< ncol; icol++){ 		if(k != ctype(lin, icol)) 			return(0); 	} 	return(k); }  #define SPAN "\\^"  permute(){ 	register int irow, jcol, is; 	char *start, *strig;  	for(jcol = 0; jcol< ncol; jcol++){ 		for(irow = 1; irow< nlin; irow++){ 			if(vspand(irow, jcol, 0)){ 				is = prev(irow); 				if(is< 0) 					error("Vertical spanning in first row not allowed"); 				start = table[is][jcol].col; 				strig = table[is][jcol].rcol; 				while(irow< nlin&& vspand(irow, jcol, 0)){ 					irow++; 				} 				table[--irow][jcol].col = start; 				table[irow][jcol].rcol = strig; 				while(is< irow){ 					table[is][jcol].col = SPAN; 					table[is][jcol].rcol = (char*)0; 					is = next(is); 				} 			} 		} 	} }  /*  * return 1 if vertical spanning is row ir, column ij, from position ifrom  */ vspand(ir, ij, ifform) { 	if(ir< 0) 		return(0); 	if(ir>= nlin) 		return(0); 	if(instead[ir]) 		return(0); 	if(ifform == 0&& ctype(ir, ij) == '
operator|^
literal|'
end_for

unit|){ 		return(1); 	} 	if(table[ir][ij].rcol != (char*)0) 		return(0); 	if(fullbot[ir]) 		return(0); 	return(vspen(table[ir][ij].col)); }  /*  * return 1 if the string is the same as SPAN  */ vspen(s) char   *s; { 	if(s == 0) 		return(0); 	if(!point(s)) 		return(0); 	return(strcmp(s, SPAN) == 0); }  static interr() { 	error("internal tbl error -- function: permute"); }
end_unit

