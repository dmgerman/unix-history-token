begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Format and print trivial file transfer protocol packets.  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

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
file|<tcpdump-stdinc.h>
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
file|"extract.h"
end_include

begin_comment
comment|/*  * Trivial File Transfer Protocol (IEN-133)  */
end_comment

begin_comment
comment|/*  * Packet types.  */
end_comment

begin_define
define|#
directive|define
name|RRQ
value|01
end_define

begin_comment
comment|/* read request */
end_comment

begin_define
define|#
directive|define
name|WRQ
value|02
end_define

begin_comment
comment|/* write request */
end_comment

begin_define
define|#
directive|define
name|DATA
value|03
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|ACK
value|04
end_define

begin_comment
comment|/* acknowledgement */
end_comment

begin_define
define|#
directive|define
name|TFTP_ERROR
value|05
end_define

begin_comment
comment|/* error code */
end_comment

begin_define
define|#
directive|define
name|OACK
value|06
end_define

begin_comment
comment|/* option acknowledgement */
end_comment

begin_struct
struct|struct
name|tftphdr
block|{
name|unsigned
name|short
name|th_opcode
decl_stmt|;
comment|/* packet type */
union|union
block|{
name|unsigned
name|short
name|tu_block
decl_stmt|;
comment|/* block # */
name|unsigned
name|short
name|tu_code
decl_stmt|;
comment|/* error code */
name|char
name|tu_stuff
index|[
literal|1
index|]
decl_stmt|;
comment|/* request packet stuff */
block|}
name|th_u
union|;
name|char
name|th_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* data or error string */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|th_block
value|th_u.tu_block
end_define

begin_define
define|#
directive|define
name|th_code
value|th_u.tu_code
end_define

begin_define
define|#
directive|define
name|th_stuff
value|th_u.tu_stuff
end_define

begin_define
define|#
directive|define
name|th_msg
value|th_data
end_define

begin_comment
comment|/*  * Error codes.  */
end_comment

begin_define
define|#
directive|define
name|EUNDEF
value|0
end_define

begin_comment
comment|/* not defined */
end_comment

begin_define
define|#
directive|define
name|ENOTFOUND
value|1
end_define

begin_comment
comment|/* file not found */
end_comment

begin_define
define|#
directive|define
name|EACCESS
value|2
end_define

begin_comment
comment|/* access violation */
end_comment

begin_define
define|#
directive|define
name|ENOSPACE
value|3
end_define

begin_comment
comment|/* disk full or allocation exceeded */
end_comment

begin_define
define|#
directive|define
name|EBADOP
value|4
end_define

begin_comment
comment|/* illegal TFTP operation */
end_comment

begin_define
define|#
directive|define
name|EBADID
value|5
end_define

begin_comment
comment|/* unknown transfer ID */
end_comment

begin_define
define|#
directive|define
name|EEXISTS
value|6
end_define

begin_comment
comment|/* file already exists */
end_comment

begin_define
define|#
directive|define
name|ENOUSER
value|7
end_define

begin_comment
comment|/* no such user */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
name|tstr
index|[]
init|=
literal|" [|tftp]"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* op code to string mapping */
end_comment

begin_decl_stmt
specifier|static
specifier|const
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
name|TFTP_ERROR
block|,
literal|"ERROR"
block|}
block|,
comment|/* error code */
block|{
name|OACK
block|,
literal|"OACK"
block|}
block|,
comment|/* option acknowledgement */
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
specifier|const
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
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" %d"
operator|,
name|length
operator|)
argument_list|)
expr_stmt|;
comment|/* Print tftp request type */
name|ND_TCHECK
argument_list|(
name|tp
operator|->
name|th_opcode
argument_list|)
expr_stmt|;
name|opcode
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" %s"
operator|,
name|cp
operator|)
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
case|case
name|OACK
case|:
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" "
operator|)
argument_list|)
expr_stmt|;
comment|/* Print filename or first option */
if|if
condition|(
name|opcode
operator|!=
name|OACK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"\""
operator|)
argument_list|)
expr_stmt|;
name|i
operator|=
name|fn_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|ndo
operator|->
name|ndo_snapend
argument_list|)
expr_stmt|;
if|if
condition|(
name|opcode
operator|!=
name|OACK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"\""
operator|)
argument_list|)
expr_stmt|;
comment|/* Print the mode (RRQ and WRQ only) and any options */
while|while
condition|(
operator|(
name|p
operator|=
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|strchr
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|p
argument_list|,
literal|'\0'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|length
operator|<=
call|(
name|u_int
call|)
argument_list|(
name|p
operator|-
operator|(
specifier|const
name|u_char
operator|*
operator|)
operator|&
name|tp
operator|->
name|th_block
argument_list|)
condition|)
break|break;
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|'\0'
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" "
operator|)
argument_list|)
expr_stmt|;
name|fn_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|ndo
operator|->
name|ndo_snapend
argument_list|)
expr_stmt|;
block|}
block|}
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
name|ND_TCHECK
argument_list|(
name|tp
operator|->
name|th_block
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" block %d"
operator|,
name|EXTRACT_16BITS
argument_list|(
operator|&
name|tp
operator|->
name|th_block
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TFTP_ERROR
case|:
comment|/* Print error code string */
name|ND_TCHECK
argument_list|(
name|tp
operator|->
name|th_code
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" %s \""
operator|,
name|tok2str
argument_list|(
name|err2str
argument_list|,
literal|"tftp-err-#%d \""
argument_list|,
name|EXTRACT_16BITS
argument_list|(
operator|&
name|tp
operator|->
name|th_code
argument_list|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
comment|/* Print error message string */
name|i
operator|=
name|fn_print
argument_list|(
name|ndo
argument_list|,
operator|(
specifier|const
name|u_char
operator|*
operator|)
name|tp
operator|->
name|th_data
argument_list|,
name|ndo
operator|->
name|ndo_snapend
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"\""
operator|)
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
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"(unknown #%d)"
operator|,
name|opcode
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

