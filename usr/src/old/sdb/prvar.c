begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)prvar.c 4.3 8/17/82"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"head.h"
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<stab.h>
end_include

begin_include
include|#
directive|include
file|"cdefs.h"
end_include

begin_decl_stmt
name|struct
name|user
name|u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BKPTR
name|bkpthead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|errflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   *  outvar():  * Prints named variable, recursing once for each structure member or  *  subscript.  * proc:var: variable name  * fmt: print format  * metaflag: set iff var contains metacharacters * or ?  * addr: partial address of variable, initally 0  * class: type class of variable  * subflag: number of levels of subscript indirection  * prnamep: pointer to end of partially formed print name of variable  * comblk: name of common block containing variable, if any  * prvar: as in findvar  *  * Here and elsewhere we assume that -1 is an invalid address, and  *	its is used to indicate error.  */
end_comment

begin_macro
name|outvar
argument_list|(
argument|proc
argument_list|,
argument|var
argument_list|,
argument|fmt
argument_list|,
argument|metaflag
argument_list|,
argument|addr
argument_list|,
argument|class
argument_list|,
argument|subflag
argument_list|,
argument|prnamep
argument_list|,
argument|comblk
argument_list|,
argument|prvar
argument_list|)
end_macro

begin_decl_stmt
name|ADDR
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|proc
decl_stmt|,
modifier|*
name|var
decl_stmt|,
modifier|*
name|fmt
decl_stmt|,
modifier|*
name|prnamep
decl_stmt|,
modifier|*
name|comblk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|class
decl_stmt|;
end_decl_stmt

begin_block
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
decl_stmt|,
modifier|*
name|oldpr
decl_stmt|;
specifier|register
name|int
name|match
decl_stmt|;
name|long
name|soffset
decl_stmt|,
name|goffset
decl_stmt|;
specifier|register
name|ADDR
name|newaddr
init|=
operator|-
literal|1
decl_stmt|,
name|arrowaddr
decl_stmt|;
specifier|register
enum|enum
block|{
name|INIT
block|,
name|ARROW
block|,
name|DOT
block|}
name|typeflag
enum|;
switch|switch
condition|(
name|var
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'\0'
case|:
if|if
condition|(
name|prvar
operator|==
literal|0
condition|)
return|return
operator|(
name|addr
operator|)
return|;
if|if
condition|(
name|metaflag
condition|)
block|{
if|if
condition|(
name|comblk
index|[
literal|0
index|]
operator|&&
operator|!
operator|(
name|eqstr
argument_list|(
name|comblk
argument_list|,
literal|"*"
argument_list|)
operator|)
condition|)
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%.8s:%.8s"
argument_list|,
name|comblk
argument_list|,
name|prname
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%s:%s"
argument_list|,
name|comblk
argument_list|,
name|prname
argument_list|)
expr_stmt|;
endif|#
directive|endif
elseif|else
if|if
condition|(
name|proc
index|[
literal|0
index|]
condition|)
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%.8s:%.8s"
argument_list|,
name|proc
argument_list|,
name|prname
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%s:%s"
argument_list|,
name|proc
argument_list|,
name|prname
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|else
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|prname
argument_list|)
expr_stmt|;
block|}
name|printit
argument_list|(
name|metaflag
argument_list|,
name|prvar
argument_list|,
name|addr
argument_list|,
name|fmt
argument_list|,
name|class
argument_list|,
name|sl_type
argument_list|,
name|sl_size
argument_list|,
name|subflag
argument_list|,
name|DSP
argument_list|)
expr_stmt|;
return|return
operator|(
name|addr
operator|)
return|;
case|case
literal|'['
case|:
operator|*
name|prnamep
operator|++
operator|=
operator|*
name|var
operator|++
expr_stmt|;
name|p
operator|=
name|var
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
operator|*
name|prnamep
operator|++
operator|=
operator|*
name|var
expr_stmt|;
if|if
condition|(
operator|*
name|var
operator|==
literal|'\0'
operator|||
operator|*
name|var
operator|==
literal|']'
condition|)
break|break;
name|var
operator|++
expr_stmt|;
block|}
name|newaddr
operator|=
name|getindir
argument_list|(
name|class
argument_list|,
name|addr
argument_list|,
name|sl_type
argument_list|)
expr_stmt|;
name|newaddr
operator|+=
name|typetosize
argument_list|(
name|sl_type
argument_list|,
name|sl_size
argument_list|)
operator|*
name|readint
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|outvar
argument_list|(
name|proc
argument_list|,
name|var
operator|+
literal|1
argument_list|,
name|fmt
argument_list|,
name|metaflag
argument_list|,
name|newaddr
argument_list|,
name|N_GSYM
argument_list|,
name|subflag
operator|+
literal|1
argument_list|,
name|prnamep
argument_list|,
name|comblk
argument_list|,
name|prvar
argument_list|)
operator|)
return|;
case|case
literal|'-'
case|:
case|case
literal|'>'
case|:
name|typeflag
operator|=
name|ARROW
expr_stmt|;
while|while
condition|(
name|eqany
argument_list|(
operator|*
name|var
argument_list|,
literal|"->"
argument_list|)
condition|)
operator|*
name|prnamep
operator|++
operator|=
operator|*
name|var
operator|++
expr_stmt|;
name|subflag
operator|++
expr_stmt|;
name|arrowaddr
operator|=
name|getindir
argument_list|(
name|class
argument_list|,
name|addr
argument_list|,
name|sl_type
argument_list|)
expr_stmt|;
if|if
condition|(
name|errflg
condition|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|errflg
argument_list|)
expr_stmt|;
name|errflg
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|class
operator|=
name|N_GSYM
expr_stmt|;
if|if
condition|(
name|var
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|p
operator|=
name|var
expr_stmt|;
name|newaddr
operator|=
name|arrowaddr
expr_stmt|;
goto|goto
name|recurse
goto|;
block|}
break|break;
case|case
literal|'.'
case|:
name|typeflag
operator|=
name|DOT
expr_stmt|;
if|if
condition|(
name|class
operator|==
name|N_RSYM
condition|)
block|{
name|error
argument_list|(
literal|"Not with a register variable"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
operator|*
name|prnamep
operator|++
operator|=
operator|*
name|var
operator|++
expr_stmt|;
name|subflag
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|typeflag
operator|=
name|INIT
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|typeflag
operator|==
name|INIT
condition|)
block|{
name|soffset
operator|=
name|proc
index|[
literal|0
index|]
condition|?
name|adrtostoffset
argument_list|(
name|callpc
operator|-
literal|1
argument_list|)
else|:
operator|-
literal|1
expr_stmt|;
name|goffset
operator|=
name|proc
index|[
literal|0
index|]
condition|?
operator|-
literal|1
else|:
name|findfile
argument_list|(
name|curfile
argument_list|)
operator|->
name|stf_offset
expr_stmt|;
block|}
else|else
block|{
name|soffset
operator|=
name|proc
index|[
literal|0
index|]
condition|?
name|adrtostoffset
argument_list|(
name|callpc
operator|-
literal|1
argument_list|)
else|:
operator|-
literal|1
expr_stmt|;
name|goffset
operator|=
name|findfile
argument_list|(
name|curfile
argument_list|)
operator|->
name|stf_offset
expr_stmt|;
block|}
name|p
operator|=
name|var
expr_stmt|;
name|oldpr
operator|=
name|prnamep
expr_stmt|;
while|while
condition|(
operator|!
name|eqany
argument_list|(
operator|*
name|p
argument_list|,
literal|"->.["
argument_list|)
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
operator|*
name|prnamep
operator|++
operator|=
operator|*
name|p
operator|++
expr_stmt|;
operator|*
name|prnamep
operator|=
literal|'\0'
expr_stmt|;
name|match
operator|=
literal|0
expr_stmt|;
name|slookinit
argument_list|()
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|soffset
operator|!=
operator|-
literal|1
condition|)
if|if
condition|(
operator|(
name|soffset
operator|=
name|slooknext
argument_list|(
name|var
argument_list|,
name|soffset
argument_list|,
name|typeflag
operator|!=
name|INIT
argument_list|,
name|comblk
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
goto|goto
name|found
goto|;
if|if
condition|(
name|goffset
operator|!=
operator|-
literal|1
condition|)
if|if
condition|(
operator|(
name|goffset
operator|=
name|globallookup
argument_list|(
name|var
argument_list|,
name|goffset
argument_list|,
name|typeflag
operator|!=
name|INIT
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
goto|goto
name|found
goto|;
return|return
operator|(
name|newaddr
operator|)
return|;
name|found
label|:
name|r
operator|=
name|sl_name
expr_stmt|;
name|q
operator|=
name|oldpr
expr_stmt|;
while|while
condition|(
operator|*
name|r
condition|)
operator|*
name|q
operator|++
operator|=
operator|*
name|r
operator|++
expr_stmt|;
operator|*
name|q
operator|=
literal|'\0'
expr_stmt|;
switch|switch
condition|(
name|typeflag
condition|)
block|{
case|case
name|INIT
case|:
name|class
operator|=
name|sl_class
operator|&
name|STABMASK
expr_stmt|;
if|if
condition|(
operator|!
name|varclass
argument_list|(
name|class
argument_list|)
operator|||
name|class
operator|==
name|N_SSYM
condition|)
goto|goto
name|l
goto|;
name|newaddr
operator|=
operator|(
name|class
operator|==
name|N_LSYM
operator|)
condition|?
operator|-
name|sl_addr
else|:
name|sl_addr
expr_stmt|;
name|newaddr
operator|=
name|formaddr
argument_list|(
name|class
argument_list|,
name|newaddr
argument_list|)
expr_stmt|;
break|break;
case|case
name|ARROW
case|:
name|class
operator|=
name|sl_class
operator|&
name|STABMASK
expr_stmt|;
if|if
condition|(
operator|!
name|varclass
argument_list|(
name|class
argument_list|)
operator|||
name|class
operator|!=
name|N_SSYM
condition|)
goto|goto
name|l
goto|;
name|newaddr
operator|=
name|arrowaddr
operator|+
name|sl_addr
expr_stmt|;
break|break;
case|case
name|DOT
case|:
name|class
operator|=
name|sl_class
operator|&
name|STABMASK
expr_stmt|;
if|if
condition|(
operator|!
name|varclass
argument_list|(
name|class
argument_list|)
operator|||
name|class
operator|!=
name|N_SSYM
condition|)
goto|goto
name|l
goto|;
name|newaddr
operator|=
name|addr
operator|+
name|sl_addr
expr_stmt|;
break|break;
block|}
name|recurse
label|:
name|newaddr
operator|=
name|outvar
argument_list|(
name|proc
argument_list|,
name|p
argument_list|,
name|fmt
argument_list|,
name|metaflag
argument_list|,
name|newaddr
argument_list|,
name|class
argument_list|,
name|subflag
argument_list|,
name|prnamep
argument_list|,
name|comblk
argument_list|,
name|prvar
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|metaflag
condition|)
return|return
operator|(
name|newaddr
operator|)
return|;
name|l
label|:
empty_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* Output external variables.  Arguments as in outvar() */
end_comment

begin_macro
name|extoutvar
argument_list|(
argument|var
argument_list|,
argument|fmt
argument_list|,
argument|metaflag
argument_list|,
argument|prvar
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|var
decl_stmt|,
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|offset
decl_stmt|;
name|ADDR
name|addr
init|=
operator|-
literal|1
decl_stmt|;
name|offset
operator|=
name|extstart
expr_stmt|;
name|sl_addr
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|offset
operator|=
name|extlookup
argument_list|(
name|var
argument_list|,
name|offset
argument_list|)
expr_stmt|;
name|addr
operator|=
name|sl_addr
expr_stmt|;
if|if
condition|(
name|offset
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|addr
operator|)
return|;
if|if
condition|(
name|metaflag
condition|)
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%.7s"
argument_list|,
name|sl_name
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|sl_name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printit
argument_list|(
name|metaflag
argument_list|,
name|prvar
argument_list|,
name|addr
argument_list|,
name|fmt
index|[
literal|0
index|]
condition|?
name|fmt
else|:
literal|"d"
argument_list|,
name|N_GSYM
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|DSP
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|metaflag
condition|)
return|return
operator|(
name|addr
operator|)
return|;
block|}
block|}
end_block

begin_macro
name|prdebug
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|proct
modifier|*
name|procp
decl_stmt|;
specifier|register
name|struct
name|filet
modifier|*
name|filep
decl_stmt|;
name|printf
argument_list|(
literal|"dot=%d\n"
argument_list|,
name|dot
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"extstart = %d\n"
argument_list|,
name|extstart
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"firstdata = %d\n"
argument_list|,
name|firstdata
argument_list|)
expr_stmt|;
for|for
control|(
name|filep
operator|=
name|files
init|;
name|filep
operator|->
name|sfilename
index|[
literal|0
index|]
condition|;
name|filep
operator|++
control|)
name|printf
argument_list|(
literal|"%s offs %d @ %d flag %d addr 0x%x\n"
argument_list|,
name|filep
operator|->
name|sfilename
argument_list|,
name|filep
operator|->
name|stf_offset
argument_list|,
name|filep
argument_list|,
name|filep
operator|->
name|lineflag
argument_list|,
name|filep
operator|->
name|faddr
argument_list|)
expr_stmt|;
for|for
control|(
name|procp
operator|=
name|procs
init|;
name|procp
operator|->
name|pname
index|[
literal|0
index|]
condition|;
name|procp
operator|++
control|)
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|printf
argument_list|(
literal|"%s addr 0x%x; offs %d; sfptr %d; line %d"
argument_list|,
else|#
directive|else
argument|printf(
literal|"%8.8s addr 0x%x; offs %d; sfptr %d; line %d"
argument|,
endif|#
directive|endif
argument|procp->pname, procp->paddr, procp->st_offset, 			procp->sfptr, procp->lineno); 		if (procp->entrypt) printf(
literal|" entrypoint"
argument|); 		printf(
literal|"\n"
argument|); 	} }
comment|/*  * display addr in data space using format desc or class s  *  type == 1 => use addr for value to print  */
argument|dispf(addr, desc, class, type, size, subflag, space) u_char class; char *desc; short type; ADDR addr; { 	dispx(addr, desc, class, type, size, subflag, DSP); 	printf(
literal|"\n"
argument|); }
comment|/* display addr in instruction space using format desc or class s */
comment|/*  returns -1 if bad address */
argument|dispi(addr, desc, class, type, size, subflag, space) u_char class; char *desc; short type; ADDR addr; { 	register i; 	i = dispx(addr, desc, class, type, size, subflag, ISP); 	printf(
literal|"\n"
argument|); 	return(i); }  char	pd[
literal|3
argument|]; dispx(addr, desc, class, type, size, subflag, space) u_char class; char *desc; short type; ADDR addr; { 	int i
argument_list|,
argument|sflag; 	char *p; 	char dlen
argument_list|,
argument|dfmt; 	long value; 	union { 		char c[WORDSIZE];  		int w; 		float f; 	} word; 	union { 		struct{ 			int w1
argument_list|,
argument|w2; 		} ww; 		double d; 	} dbl;  	class&= STABMASK; 	if (desc[
literal|0
argument|]  ==
literal|'\0'
argument|) desc = typetodesc(type, subflag); 	cpstr(odesc, desc); 	otype = type; 	oclass = class; 	oaddr = addr; 	oincr =
literal|0
argument|; 	if (debug) printf(
literal|"dispx(addr=%d,desc=%s,class=%d,type=%d,size=%d,subflg=%d,space=%d)\n"
argument|, 		addr, desc, class, type, size, subflag, space); 	pd[
literal|0
argument|] =
literal|'%'
argument|; 	pd[
literal|1
argument|] = dfmt =
literal|'d'
argument|; 	dlen =
literal|'\0'
argument|; 	for (p = desc; *p; p++) { 		if (*p>=
literal|'0'
argument|&& *p<
literal|'9'
argument|) { 			size = readint(&p); 			p--; 		} else switch (*p) { 			case
literal|'l'
argument|: 			case
literal|'h'
argument|: 			case
literal|'b'
argument|: 				dlen = *p; 				break;  			case
literal|'a'
argument|: 			case
literal|'c'
argument|: 			case
literal|'d'
argument|: 			case
literal|'f'
argument|: 			case
literal|'g'
argument|: 			case
literal|'i'
argument|: 			case
literal|'I'
argument|: 			case
literal|'o'
argument|: 			case
literal|'p'
argument|: 			case
literal|'s'
argument|: 			case
literal|'u'
argument|: 			case
literal|'x'
argument|: 				pd[
literal|1
argument|] = dfmt = *p; 				break;  			default: 				printf(
literal|"Illegal descriptor: %c\n"
argument|, *p); 				return(
literal|1
argument|); 		} 	}  	if (type == -
literal|1
argument|) 		value = addr; 	else if (class == N_RSYM&& addr<
literal|16
argument|) {
comment|/* MACHINE DEPENDENT */
argument|if ((addr>
literal|0
argument|&& addr<
literal|6
argument|) || addr>
literal|11
argument|) { 			printf(
literal|"Bad register var %d\n"
argument|, addr); 			return(-
literal|1
argument|); 		} 		value = *(ADDR *)(((ADDR)&u) + R0 + (WORDSIZE)*addr); 	} 	else { 		value = getval(addr, dfmt ==
literal|'g'
argument|?
literal|'d'
argument|: dfmt, space); 	}  	if (errflg) { 		printf(
literal|"%s"
argument|, errflg); 		errflg =
literal|0
argument|; 		return(-
literal|1
argument|); 	}  	switch (dfmt) { 	default: 		switch (dfmt) { 		case
literal|'u'
argument|: 		case
literal|'x'
argument|: 		case
literal|'o'
argument|: 			switch (dlen) { 			case
literal|'h'
argument|: 				value = (unsigned short) value; 				oincr =
literal|2
argument|; 				break; 			case
literal|'b'
argument|: 				value = (unsigned char) value; 				oincr =
literal|1
argument|; 				break; 			case
literal|'l'
argument|: 				value = (unsigned long) value; 				oincr =
literal|4
argument|; 				break; 			default: 				oincr = WORDSIZE; 				break; 			} 			break;  		default: 			switch (dlen) { 			case
literal|'h'
argument|: 				value = (short) value; 				oincr =
literal|2
argument|; 				break; 			case
literal|'b'
argument|: 				value = (char) value; 				oincr =
literal|1
argument|; 				break; 			case
literal|'l'
argument|: 				value = (long) value; 				oincr =
literal|4
argument|; 				break; 			default: 				oincr = WORDSIZE; 				break; 			} 		} 		if (dfmt ==
literal|'x'
argument|&& (value>
literal|9
argument||| value<
literal|0
argument|)) 			printf(
literal|"0x"
argument|); 		else if (dfmt ==
literal|'o'
argument|&& (value>
literal|7
argument||| value<
literal|0
argument|)) 			printf(
literal|"0"
argument|); 		printf(pd, value); 		return(
literal|1
argument|); 		 	case
literal|'f'
argument|: 		pd[
literal|1
argument|] =
literal|'g'
argument|; 		word.w = value; 		printf(pd, word.f); 		return(
literal|1
argument|);  	case
literal|'g'
argument|: 		dbl.ww.w1 = value; 		dbl.ww.w2 = (class == N_RSYM) ? 			*(ADDR *)(((ADDR)&u)+R0+(WORDSIZE)*(addr+
literal|1
argument|)) : 			getval(addr+WORDSIZE,
literal|'d'
argument|, space); 		printf(
literal|"%.13g"
argument|, dbl.d); 		return(
literal|1
argument|);  	case
literal|'p'
argument|: 		printf(
literal|"%s:%d"
argument|, adrtoprocp(value)->pname, 			adrtolineno(value)); 		return(
literal|1
argument|);  	case
literal|'s'
argument|: 		addr = getindir(class, addr, type); 		goto aa; 			 	case
literal|'c'
argument|: 		if (size<=
literal|1
argument|) { 			oincr =
literal|1
argument|; 			printchar(value); 			return(
literal|1
argument|); 		} else  			goto aa;  	case
literal|'a'
argument|: 	aa:	sflag = size ==
literal|0
argument|; 		if (sflag) 			size =
literal|128
argument|;
comment|/* maximum length for s and a */
argument|else 			oincr = size; 		for (;;) { 			word.w = getval(addr,
literal|'d'
argument|, space); 			for (i=
literal|0
argument|; i<WORDSIZE; i++) { 				if (sflag&& word.c[i] ==
literal|0
argument|)  					return(
literal|1
argument|); 				if (size-- ==
literal|0
argument|) 					return(
literal|1
argument|); 				printchar(word.c[i]); 			} 			addr += WORDSIZE; 		} 		break;  	case
literal|'i'
argument|: 	case
literal|'I'
argument|: 		value = chkget(dot, space); 		if (errflg) { 			printf(
literal|"%s"
argument|, errflg); 			errflg =
literal|0
argument|; 			return(-
literal|1
argument|); 		} 		printins(dfmt, space, value); 		break;  	} 	return(
literal|1
argument|); }
comment|/* print variable as in prvar */
argument|printit(metaflag, prvar, addr, desc, class, type, size, subflag, space)  u_char class; char *desc; short type; ADDR addr; { 	if (prvar ==
literal|0
argument|) 		return; 	if (metaflag) { 		if (prvar ==
literal|1
argument|) 			printf(
literal|"/ "
argument|); 		else 			printf(
literal|"= "
argument|); 	} 	if (prvar ==
literal|1
argument|) 		dispf(addr, desc, class, type, size, 			subflag, space); 	else 		dispf(addr, desc,
literal|0
argument|, -
literal|1
argument|,
literal|0
argument|,
literal|0
argument|, DSP); }  printchar(c) { 	if ((c&
literal|0177
argument|)<
literal|' '
argument|)  		printf(
literal|"^%c"
argument|, c + (
literal|'A'
argument|-
literal|1
argument|)); 	else if ((c&
literal|0177
argument|) ==
literal|0177
argument|) 		printf(
literal|"^?"
argument|); 	else 		printf(
literal|"%c"
argument|, c); }  INT fcor; printmap(s,amap) STRING	s; MAP *amap; { 	int file; 	file=amap->ufd; 	printf(
literal|"%s\t`%s'\n"
argument|,s,(file<
literal|0
argument|?
literal|"-"
argument|: (file==fcor ? corfil : symfil))); 	printf(
literal|"b1 = 0x%-16x"
argument|,amap->b1); 	printf(
literal|"e1 = 0x%-16x"
argument|,amap->e1); 	printf(
literal|"f1 = 0x%-x"
argument|,amap->f1); 	printf(
literal|"\nb2 = 0x%-16x"
argument|,amap->b2); 	printf(
literal|"e2 = 0x%-16x"
argument|,amap->e2); 	printf(
literal|"f2 = 0x%-x"
argument|,amap->f2); 	printf(
literal|"\n"
argument|); }
define|#
directive|define
name|NUMREGS
value|24
comment|/* number of hardware registers */
argument|REGLIST reglist[];  printregs() { 	REG REGPTR	p;  	for (p=reglist; p<&reglist[NUMREGS/
literal|2
argument|]; p++) { 		printf(
literal|"%4.4s/  "
argument|, p->rname); 		prhex12(*(ADDR *)(((ADDR)&u)+p->roffs)); 		printf(
literal|"      %4.4s/  "
argument|,(p+NUMREGS/
literal|2
argument|)->rname); 		prhex(*(ADDR *)(((ADDR)&u)+(p+NUMREGS/
literal|2
argument|)->roffs)); 		printf(
literal|"\n"
argument|); 	} 	printpc(); }  printpc() { 	dot= *(ADDR *)(((ADDR)&u)+PC); 	prisploc(); 	printins(
literal|'i'
argument|,ISP,chkget(dot,ISP)); 	printf(
literal|"\n"
argument|); }
comment|/* print register */
argument|REGLIST reglist[]; regout(name, prvar, fmt)  char *name
argument_list|,
argument|*fmt; { 	REG REGPTR p; 	for (p=reglist; p<&reglist[
literal|24
argument|]; p++) { 		if (eqstr(name, p->rname)) { 			printit(
literal|0
argument|, prvar, *(ADDR *)(((ADDR)&u)+p->roffs), 				fmt[
literal|0
argument|] ? fmt :
literal|"d"
argument|, N_GSYM, -
literal|1
argument|,
literal|0
argument|,
literal|0
argument|, DSP); 			return(p->roffs); 		} 	} 	error(
literal|"Unknown register variable"
argument|); 	return(-
literal|1
argument|); }
comment|/* Print symbolic location of dot */
argument|prisploc() { 	struct proct *procp; 	int lineno;  	printf(
literal|"0x%x"
argument|, dot); 	procp = adrtoprocp(dot); 	if (procp != badproc) { 		printf(
literal|" ("
argument|); 		prlnoff(procp, dot); 		printf(
literal|"):  \t"
argument|); 	} else 		printf(
literal|":  \t"
argument|); }
end_block

end_unit

