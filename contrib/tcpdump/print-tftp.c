begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Format and print trivial file transfer protocol packets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-tftp.c,v 1.31 1999/11/21 09:37:03 fenner Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SEGSIZE
end_ifdef

begin_undef
undef|#
directive|undef
name|SEGSIZE
end_undef

begin_comment
comment|/* SINIX sucks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<arpa/tftp.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_comment
comment|/* op code to string mapping */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|tok
name|op2str
index|[]
init|=
block|{
block|{
name|RRQ
block|,
literal|"RRQ"
block|}
block|,
comment|/* read request */
block|{
name|WRQ
block|,
literal|"WRQ"
block|}
block|,
comment|/* write request */
block|{
name|DATA
block|,
literal|"DATA"
block|}
block|,
comment|/* data packet */
block|{
name|ACK
block|,
literal|"ACK"
block|}
block|,
comment|/* acknowledgement */
block|{
name|ERROR
block|,
literal|"ERROR"
block|}
block|,
comment|/* error code */
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error code to string mapping */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|tok
name|err2str
index|[]
init|=
block|{
block|{
name|EUNDEF
block|,
literal|"EUNDEF"
block|}
block|,
comment|/* not defined */
block|{
name|ENOTFOUND
block|,
literal|"ENOTFOUND"
block|}
block|,
comment|/* file not found */
block|{
name|EACCESS
block|,
literal|"EACCESS"
block|}
block|,
comment|/* access violation */
block|{
name|ENOSPACE
block|,
literal|"ENOSPACE"
block|}
block|,
comment|/* disk full or allocation exceeded */
block|{
name|EBADOP
block|,
literal|"EBADOP"
block|}
block|,
comment|/* illegal TFTP operation */
block|{
name|EBADID
block|,
literal|"EBADID"
block|}
block|,
comment|/* unknown transfer ID */
block|{
name|EEXISTS
block|,
literal|"EEXISTS"
block|}
block|,
comment|/* file already exists */
block|{
name|ENOUSER
block|,
literal|"ENOUSER"
block|}
block|,
comment|/* no such user */
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Print trivial file transfer program requests  */
end_comment

begin_function
name|void
name|tftp_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
specifier|register
specifier|const
name|struct
name|tftphdr
modifier|*
name|tp
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|cp
decl_stmt|;
specifier|register
specifier|const
name|u_char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|opcode
decl_stmt|,
name|i
decl_stmt|;
specifier|static
name|char
name|tstr
index|[]
init|=
literal|" [|tftp]"
decl_stmt|;
name|tp
operator|=
operator|(
specifier|const
expr|struct
name|tftphdr
operator|*
operator|)
name|bp
expr_stmt|;
comment|/* Print length */
name|printf
argument_list|(
literal|" %d"
argument_list|,
name|length
argument_list|)
expr_stmt|;
comment|/* Print tftp request type */
name|TCHECK
argument_list|(
name|tp
operator|->
name|th_opcode
argument_list|)
expr_stmt|;
name|opcode
operator|=
name|ntohs
argument_list|(
name|tp
operator|->
name|th_opcode
argument_list|)
expr_stmt|;
name|cp
operator|=
name|tok2str
argument_list|(
name|op2str
argument_list|,
literal|"tftp-#%d"
argument_list|,
name|opcode
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
comment|/* Bail if bogus opcode */
if|if
condition|(
operator|*
name|cp
operator|==
literal|'t'
condition|)
return|return;
switch|switch
condition|(
name|opcode
condition|)
block|{
case|case
name|RRQ
case|:
case|case
name|WRQ
case|:
comment|/* 		 * XXX Not all arpa/tftp.h's specify th_stuff as any 		 * array; use address of th_block instead 		 */
ifdef|#
directive|ifdef
name|notdef
name|p
operator|=
operator|(
name|u_char
operator|*
operator|)
name|tp
operator|->
name|th_stuff
expr_stmt|;
else|#
directive|else
name|p
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tp
operator|->
name|th_block
expr_stmt|;
endif|#
directive|endif
name|fputs
argument_list|(
literal|" \""
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|i
operator|=
name|fn_print
argument_list|(
name|p
argument_list|,
name|snapend
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
condition|)
goto|goto
name|trunc
goto|;
break|break;
case|case
name|ACK
case|:
case|case
name|DATA
case|:
name|TCHECK
argument_list|(
name|tp
operator|->
name|th_block
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" block %d"
argument_list|,
name|ntohs
argument_list|(
name|tp
operator|->
name|th_block
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ERROR
case|:
comment|/* Print error code string */
name|TCHECK
argument_list|(
name|tp
operator|->
name|th_code
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %s "
argument_list|,
name|tok2str
argument_list|(
name|err2str
argument_list|,
literal|"tftp-err-#%d \""
argument_list|,
name|ntohs
argument_list|(
name|tp
operator|->
name|th_code
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Print error message string */
name|i
operator|=
name|fn_print
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|tp
operator|->
name|th_data
argument_list|,
name|snapend
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
condition|)
goto|goto
name|trunc
goto|;
break|break;
default|default:
comment|/* We shouldn't get here */
name|printf
argument_list|(
literal|"(unknown #%d)"
argument_list|,
name|opcode
argument_list|)
expr_stmt|;
break|break;
block|}
return|return;
name|trunc
label|:
name|fputs
argument_list|(
name|tstr
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

