begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
literal|"@(#)gen_subs.c	8.1 (Berkeley) 5/31/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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
file|"pax.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * a collection of general purpose subroutines used by pax  */
end_comment

begin_comment
comment|/*  * constants used by ls_list() when printing out archive members  */
end_comment

begin_define
define|#
directive|define
name|MODELEN
value|20
end_define

begin_define
define|#
directive|define
name|DATELEN
value|64
end_define

begin_define
define|#
directive|define
name|SIXMONTHS
value|((365 / 2) * 86400)
end_define

begin_define
define|#
directive|define
name|CURFRMT
value|"%b %e %H:%M"
end_define

begin_define
define|#
directive|define
name|OLDFRMT
value|"%b %e  %Y"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|UT_NAMESIZE
end_ifndef

begin_define
define|#
directive|define
name|UT_NAMESIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UT_GRPSIZE
value|6
end_define

begin_comment
comment|/*  * ls_list()  *	list the members of an archive in ls format  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|void
name|ls_list
argument_list|(
specifier|register
name|ARCHD
operator|*
name|arcn
argument_list|,
name|time_t
name|now
argument_list|)
else|#
directive|else
name|void
name|ls_list
argument_list|(
name|arcn
argument_list|,
name|now
argument_list|)
decl|register
name|ARCHD
modifier|*
name|arcn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
specifier|register
name|struct
name|stat
modifier|*
name|sbp
decl_stmt|;
name|char
name|f_mode
index|[
name|MODELEN
index|]
decl_stmt|;
name|char
name|f_date
index|[
name|DATELEN
index|]
decl_stmt|;
name|char
modifier|*
name|timefrmt
decl_stmt|;
comment|/* 	 * if not verbose, just print the file name 	 */
if|if
condition|(
operator|!
name|vflag
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|arcn
operator|->
name|name
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * user wants long mode 	 */
name|sbp
operator|=
operator|&
operator|(
name|arcn
operator|->
name|sb
operator|)
expr_stmt|;
name|strmode
argument_list|(
name|sbp
operator|->
name|st_mode
argument_list|,
name|f_mode
argument_list|)
expr_stmt|;
if|if
condition|(
name|ltmfrmt
operator|==
name|NULL
condition|)
block|{
comment|/* 		 * no locale specified format. time format based on age 		 * compared to the time pax was started. 		 */
if|if
condition|(
operator|(
name|sbp
operator|->
name|st_mtime
operator|+
name|SIXMONTHS
operator|)
operator|<=
name|now
condition|)
name|timefrmt
operator|=
name|OLDFRMT
expr_stmt|;
else|else
name|timefrmt
operator|=
name|CURFRMT
expr_stmt|;
block|}
else|else
name|timefrmt
operator|=
name|ltmfrmt
expr_stmt|;
comment|/* 	 * print file mode, link count, uid, gid and time 	 */
if|if
condition|(
name|strftime
argument_list|(
name|f_date
argument_list|,
name|DATELEN
argument_list|,
name|timefrmt
argument_list|,
name|localtime
argument_list|(
operator|&
operator|(
name|sbp
operator|->
name|st_mtime
operator|)
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
name|f_date
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s%2u %-*s %-*s "
argument_list|,
name|f_mode
argument_list|,
name|sbp
operator|->
name|st_nlink
argument_list|,
name|UT_NAMESIZE
argument_list|,
name|name_uid
argument_list|(
name|sbp
operator|->
name|st_uid
argument_list|,
literal|1
argument_list|)
argument_list|,
name|UT_GRPSIZE
argument_list|,
name|name_gid
argument_list|(
name|sbp
operator|->
name|st_gid
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * print device id's for devices, or sizes for other nodes 	 */
if|if
condition|(
operator|(
name|arcn
operator|->
name|type
operator|==
name|PAX_CHR
operator|)
operator|||
operator|(
name|arcn
operator|->
name|type
operator|==
name|PAX_BLK
operator|)
condition|)
ifdef|#
directive|ifdef
name|NET2_STAT
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%4u,%4u "
argument_list|,
argument|MAJOR(sbp->st_rdev)
argument_list|,
else|#
directive|else
argument|(void)printf(
literal|"%4lu,%4lu "
argument|, (unsigned long)MAJOR(sbp->st_rdev),
endif|#
directive|endif
argument|MINOR(sbp->st_rdev)); 	else {
ifdef|#
directive|ifdef
name|NET2_STAT
argument|(void)printf(
literal|"%9lu "
argument|, sbp->st_size);
else|#
directive|else
argument|(void)printf(
literal|"%9qu "
argument|, sbp->st_size);
endif|#
directive|endif
argument|}
comment|/* 	 * print name and link info for hard and soft links 	 */
argument|(void)printf(
literal|"%s %s"
argument|, f_date, arcn->name); 	if ((arcn->type == PAX_HLK) || (arcn->type == PAX_HRG)) 		(void)printf(
literal|" == %s\n"
argument|, arcn->ln_name); 	else if (arcn->type == PAX_SLK) 		(void)printf(
literal|" => %s\n"
argument|, arcn->ln_name); 	else 		(void)putchar(
literal|'\n'
argument|); 	(void)fflush(stdout); 	return; }
comment|/*  * tty_ls()  * 	print a short summary of file to tty.  */
if|#
directive|if
name|__STDC__
argument|void ls_tty(register ARCHD *arcn)
else|#
directive|else
argument|void ls_tty(arcn) 	register ARCHD *arcn;
endif|#
directive|endif
argument|{ 	char f_date[DATELEN]; 	char f_mode[MODELEN]; 	char *timefrmt;  	if (ltmfrmt == NULL) {
comment|/* 		 * no locale specified format 		 */
argument|if ((arcn->sb.st_mtime + SIXMONTHS)<= time((time_t *)NULL)) 			timefrmt = OLDFRMT; 		else 			timefrmt = CURFRMT; 	} else 		timefrmt = ltmfrmt;
comment|/* 	 * convert time to string, and print 	 */
argument|if (strftime(f_date, DATELEN, timefrmt, 	    localtime(&(arcn->sb.st_mtime))) ==
literal|0
argument|) 		f_date[
literal|0
argument|] =
literal|'\0'
argument|; 	strmode(arcn->sb.st_mode, f_mode); 	tty_prnt(
literal|"%s%s %s\n"
argument|, f_mode, f_date, arcn->name); 	return; }
comment|/*  * zf_strncpy()  *	copy src to dest up to len chars (stopping at first '\0'), when src is  *	shorter than len, pads to len with '\0'. big performance win (and  *	a lot easier to code) over strncpy(), then a strlen() then a  *	bzero(). (or doing the bzero() first).  */
if|#
directive|if
name|__STDC__
argument|void zf_strncpy(register char *dest, register char *src, int len)
else|#
directive|else
argument|void zf_strncpy(dest, src, len) 	register char *dest; 	register char *src; 	int len;
endif|#
directive|endif
argument|{ 	register char *stop;  	stop = dest + len; 	while ((dest< stop)&& (*src !=
literal|'\0'
argument|)) 		*dest++ = *src++; 	while (dest< stop) 		*dest++ =
literal|'\0'
argument|; 	return; }
comment|/*  * l_strncpy()  *	copy src to dest up to len chars (stopping at first '\0')  * Return:  *	number of chars copied. (Note this is a real performance win over  *	doing a strncpy() then a strlen()  */
if|#
directive|if
name|__STDC__
argument|int l_strncpy(register char *dest, register char *src, int len)
else|#
directive|else
argument|int l_strncpy(dest, src, len) 	register char *dest; 	register char *src; 	int len;
endif|#
directive|endif
argument|{ 	register char *stop; 	register char *start;  	stop = dest + len; 	start = dest; 	while ((dest< stop)&& (*src !=
literal|'\0'
argument|)) 		*dest++ = *src++; 	if (dest< stop) 		*dest =
literal|'\0'
argument|; 	return(dest - start); }
comment|/*  * asc_ul()  *	convert hex/octal character string into a u_long. We do not have to  *	check for overflow! (the headers in all supported formats are not large  *	enough to create an overflow).  *	NOTE: strings passed to us are NOT TERMINATED.  * Return:  *	unsigned long value  */
if|#
directive|if
name|__STDC__
argument|u_long asc_ul(register char *str, int len, register int base)
else|#
directive|else
argument|u_long asc_ul(str, len, base) 	register char *str; 	int len; 	register int base;
endif|#
directive|endif
argument|{ 	register char *stop; 	u_long tval =
literal|0
argument|;  	stop = str + len;
comment|/* 	 * skip over leading blanks and zeros 	 */
argument|while ((str< stop)&& ((*str ==
literal|' '
argument|) || (*str ==
literal|'0'
argument|))) 		++str;
comment|/* 	 * for each valid digit, shift running value (tval) over to next digit 	 * and add next digit 	 */
argument|if (base == HEX) { 		while (str< stop) { 			if ((*str>=
literal|'0'
argument|)&& (*str<=
literal|'9'
argument|)) 				tval = (tval<<
literal|4
argument|) + (*str++ -
literal|'0'
argument|); 			else if ((*str>=
literal|'A'
argument|)&& (*str<=
literal|'F'
argument|)) 				tval = (tval<<
literal|4
argument|) +
literal|10
argument|+ (*str++ -
literal|'A'
argument|); 			else if ((*str>=
literal|'a'
argument|)&& (*str<=
literal|'f'
argument|)) 				tval = (tval<<
literal|4
argument|) +
literal|10
argument|+ (*str++ -
literal|'a'
argument|); 			else 				break; 		} 	} else {  		while ((str< stop)&& (*str>=
literal|'0'
argument|)&& (*str<=
literal|'7'
argument|)) 			tval = (tval<<
literal|3
argument|) + (*str++ -
literal|'0'
argument|); 	} 	return(tval); }
comment|/*  * ul_asc()  *	convert an unsigned long into an hex/oct ascii string. pads with LEADING  *	ascii 0's to fill string completely  *	NOTE: the string created is NOT TERMINATED.  */
if|#
directive|if
name|__STDC__
argument|int ul_asc(u_long val, register char *str, register int len, register int base)
else|#
directive|else
argument|int ul_asc(val, str, len, base) 	u_long val; 	register char *str; 	register int len; 	register int base;
endif|#
directive|endif
argument|{ 	register char *pt; 	u_long digit;
comment|/* 	 * WARNING str is not '\0' terminated by this routine 	 */
argument|pt = str + len -
literal|1
argument|;
comment|/* 	 * do a tailwise conversion (start at right most end of string to place 	 * least significant digit). Keep shifting until conversion value goes 	 * to zero (all digits were converted) 	 */
argument|if (base == HEX) { 		while (pt>= str) { 			if ((digit = (val&
literal|0xf
argument|))<
literal|10
argument|) 				*pt-- =
literal|'0'
argument|+ (char)digit; 			else 				*pt-- =
literal|'a'
argument|+ (char)(digit -
literal|10
argument|); 			if ((val = (val>>
literal|4
argument|)) == (u_long)
literal|0
argument|) 				break; 		} 	} else { 		while (pt>= str) { 			*pt-- =
literal|'0'
argument|+ (char)(val&
literal|0x7
argument|); 			if ((val = (val>>
literal|3
argument|)) == (u_long)
literal|0
argument|) 				break; 		} 	}
comment|/* 	 * pad with leading ascii ZEROS. We return -1 if we ran out of space. 	 */
argument|while (pt>= str) 		*pt-- =
literal|'0'
argument|; 	if (val != (u_long)
literal|0
argument|) 		return(-
literal|1
argument|); 	return(
literal|0
argument|); }
ifndef|#
directive|ifndef
name|NET2_STAT
comment|/*  * asc_uqd()  *	convert hex/octal character string into a u_quad_t. We do not have to  *	check for overflow! (the headers in all supported formats are not large  *	enough to create an overflow).  *	NOTE: strings passed to us are NOT TERMINATED.  * Return:  *	u_quad_t value  */
if|#
directive|if
name|__STDC__
argument|u_quad_t asc_uqd(register char *str, int len, register int base)
else|#
directive|else
argument|u_quad_t asc_uqd(str, len, base) 	register char *str; 	int len; 	register int base;
endif|#
directive|endif
argument|{ 	register char *stop; 	u_quad_t tval =
literal|0
argument|;  	stop = str + len;
comment|/* 	 * skip over leading blanks and zeros 	 */
argument|while ((str< stop)&& ((*str ==
literal|' '
argument|) || (*str ==
literal|'0'
argument|))) 		++str;
comment|/* 	 * for each valid digit, shift running value (tval) over to next digit 	 * and add next digit 	 */
argument|if (base == HEX) { 		while (str< stop) { 			if ((*str>=
literal|'0'
argument|)&& (*str<=
literal|'9'
argument|)) 				tval = (tval<<
literal|4
argument|) + (*str++ -
literal|'0'
argument|); 			else if ((*str>=
literal|'A'
argument|)&& (*str<=
literal|'F'
argument|)) 				tval = (tval<<
literal|4
argument|) +
literal|10
argument|+ (*str++ -
literal|'A'
argument|); 			else if ((*str>=
literal|'a'
argument|)&& (*str<=
literal|'f'
argument|)) 				tval = (tval<<
literal|4
argument|) +
literal|10
argument|+ (*str++ -
literal|'a'
argument|); 			else 				break; 		} 	} else {  		while ((str< stop)&& (*str>=
literal|'0'
argument|)&& (*str<=
literal|'7'
argument|)) 			tval = (tval<<
literal|3
argument|) + (*str++ -
literal|'0'
argument|); 	} 	return(tval); }
comment|/*  * uqd_asc()  *	convert an u_quad_t into a hex/oct ascii string. pads with LEADING  *	ascii 0's to fill string completely  *	NOTE: the string created is NOT TERMINATED.  */
if|#
directive|if
name|__STDC__
argument|int uqd_asc(u_quad_t val, register char *str, register int len, register int base)
else|#
directive|else
argument|int uqd_asc(val, str, len, base) 	u_quad_t val; 	register char *str; 	register int len; 	register int base;
endif|#
directive|endif
argument|{ 	register char *pt; 	u_quad_t digit;
comment|/* 	 * WARNING str is not '\0' terminated by this routine 	 */
argument|pt = str + len -
literal|1
argument|;
comment|/* 	 * do a tailwise conversion (start at right most end of string to place 	 * least significant digit). Keep shifting until conversion value goes 	 * to zero (all digits were converted) 	 */
argument|if (base == HEX) { 		while (pt>= str) { 			if ((digit = (val&
literal|0xf
argument|))<
literal|10
argument|) 				*pt-- =
literal|'0'
argument|+ (char)digit; 			else 				*pt-- =
literal|'a'
argument|+ (char)(digit -
literal|10
argument|); 			if ((val = (val>>
literal|4
argument|)) == (u_quad_t)
literal|0
argument|) 				break; 		} 	} else { 		while (pt>= str) { 			*pt-- =
literal|'0'
argument|+ (char)(val&
literal|0x7
argument|); 			if ((val = (val>>
literal|3
argument|)) == (u_quad_t)
literal|0
argument|) 				break; 		} 	}
comment|/* 	 * pad with leading ascii ZEROS. We return -1 if we ran out of space. 	 */
argument|while (pt>= str) 		*pt-- =
literal|'0'
argument|; 	if (val != (u_quad_t)
literal|0
argument|) 		return(-
literal|1
argument|); 	return(
literal|0
argument|); }
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

