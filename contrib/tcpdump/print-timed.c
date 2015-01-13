begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Ben Smithurst<ben@scientia.demon.co.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_comment
comment|/*  * Time Synchronization Protocol  */
end_comment

begin_struct
struct|struct
name|tsp_timeval
block|{
name|uint32_t
name|tv_sec
decl_stmt|;
name|uint32_t
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tsp
block|{
name|uint8_t
name|tsp_type
decl_stmt|;
name|uint8_t
name|tsp_vers
decl_stmt|;
name|uint16_t
name|tsp_seq
decl_stmt|;
union|union
block|{
name|struct
name|tsp_timeval
name|tspu_time
decl_stmt|;
name|int8_t
name|tspu_hopcnt
decl_stmt|;
block|}
name|tsp_u
union|;
name|int8_t
name|tsp_name
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tsp_time
value|tsp_u.tspu_time
end_define

begin_define
define|#
directive|define
name|tsp_hopcnt
value|tsp_u.tspu_hopcnt
end_define

begin_comment
comment|/*  * Command types.  */
end_comment

begin_define
define|#
directive|define
name|TSP_ANY
value|0
end_define

begin_comment
comment|/* match any types */
end_comment

begin_define
define|#
directive|define
name|TSP_ADJTIME
value|1
end_define

begin_comment
comment|/* send adjtime */
end_comment

begin_define
define|#
directive|define
name|TSP_ACK
value|2
end_define

begin_comment
comment|/* generic acknowledgement */
end_comment

begin_define
define|#
directive|define
name|TSP_MASTERREQ
value|3
end_define

begin_comment
comment|/* ask for master's name */
end_comment

begin_define
define|#
directive|define
name|TSP_MASTERACK
value|4
end_define

begin_comment
comment|/* acknowledge master request */
end_comment

begin_define
define|#
directive|define
name|TSP_SETTIME
value|5
end_define

begin_comment
comment|/* send network time */
end_comment

begin_define
define|#
directive|define
name|TSP_MASTERUP
value|6
end_define

begin_comment
comment|/* inform slaves that master is up */
end_comment

begin_define
define|#
directive|define
name|TSP_SLAVEUP
value|7
end_define

begin_comment
comment|/* slave is up but not polled */
end_comment

begin_define
define|#
directive|define
name|TSP_ELECTION
value|8
end_define

begin_comment
comment|/* advance candidature for master */
end_comment

begin_define
define|#
directive|define
name|TSP_ACCEPT
value|9
end_define

begin_comment
comment|/* support candidature of master */
end_comment

begin_define
define|#
directive|define
name|TSP_REFUSE
value|10
end_define

begin_comment
comment|/* reject candidature of master */
end_comment

begin_define
define|#
directive|define
name|TSP_CONFLICT
value|11
end_define

begin_comment
comment|/* two or more masters present */
end_comment

begin_define
define|#
directive|define
name|TSP_RESOLVE
value|12
end_define

begin_comment
comment|/* masters' conflict resolution */
end_comment

begin_define
define|#
directive|define
name|TSP_QUIT
value|13
end_define

begin_comment
comment|/* reject candidature if master is up */
end_comment

begin_define
define|#
directive|define
name|TSP_DATE
value|14
end_define

begin_comment
comment|/* reset the time (date command) */
end_comment

begin_define
define|#
directive|define
name|TSP_DATEREQ
value|15
end_define

begin_comment
comment|/* remote request to reset the time */
end_comment

begin_define
define|#
directive|define
name|TSP_DATEACK
value|16
end_define

begin_comment
comment|/* acknowledge time setting  */
end_comment

begin_define
define|#
directive|define
name|TSP_TRACEON
value|17
end_define

begin_comment
comment|/* turn tracing on */
end_comment

begin_define
define|#
directive|define
name|TSP_TRACEOFF
value|18
end_define

begin_comment
comment|/* turn tracing off */
end_comment

begin_define
define|#
directive|define
name|TSP_MSITE
value|19
end_define

begin_comment
comment|/* find out master's site */
end_comment

begin_define
define|#
directive|define
name|TSP_MSITEREQ
value|20
end_define

begin_comment
comment|/* remote master's site request */
end_comment

begin_define
define|#
directive|define
name|TSP_TEST
value|21
end_define

begin_comment
comment|/* for testing election algo */
end_comment

begin_define
define|#
directive|define
name|TSP_SETDATE
value|22
end_define

begin_comment
comment|/* New from date command */
end_comment

begin_define
define|#
directive|define
name|TSP_SETDATEREQ
value|23
end_define

begin_comment
comment|/* New remote for above */
end_comment

begin_define
define|#
directive|define
name|TSP_LOOP
value|24
end_define

begin_comment
comment|/* loop detection packet */
end_comment

begin_define
define|#
directive|define
name|TSPTYPENUMBER
value|25
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
name|tstr
index|[]
init|=
literal|"[|timed]"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|tsptype
index|[
name|TSPTYPENUMBER
index|]
init|=
block|{
literal|"ANY"
block|,
literal|"ADJTIME"
block|,
literal|"ACK"
block|,
literal|"MASTERREQ"
block|,
literal|"MASTERACK"
block|,
literal|"SETTIME"
block|,
literal|"MASTERUP"
block|,
literal|"SLAVEUP"
block|,
literal|"ELECTION"
block|,
literal|"ACCEPT"
block|,
literal|"REFUSE"
block|,
literal|"CONFLICT"
block|,
literal|"RESOLVE"
block|,
literal|"QUIT"
block|,
literal|"DATE"
block|,
literal|"DATEREQ"
block|,
literal|"DATEACK"
block|,
literal|"TRACEON"
block|,
literal|"TRACEOFF"
block|,
literal|"MSITE"
block|,
literal|"MSITEREQ"
block|,
literal|"TEST"
block|,
literal|"SETDATE"
block|,
literal|"SETDATEREQ"
block|,
literal|"LOOP"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|timed_print
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
parameter_list|)
block|{
name|struct
name|tsp
modifier|*
name|tsp
init|=
operator|(
expr|struct
name|tsp
operator|*
operator|)
name|bp
decl_stmt|;
name|long
name|sec
decl_stmt|,
name|usec
decl_stmt|;
name|ND_TCHECK
argument_list|(
name|tsp
operator|->
name|tsp_type
argument_list|)
expr_stmt|;
if|if
condition|(
name|tsp
operator|->
name|tsp_type
operator|<
name|TSPTYPENUMBER
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"TSP_%s"
operator|,
name|tsptype
index|[
name|tsp
operator|->
name|tsp_type
index|]
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"(tsp_type %#x)"
operator|,
name|tsp
operator|->
name|tsp_type
operator|)
argument_list|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|tsp
operator|->
name|tsp_vers
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" vers %u"
operator|,
name|tsp
operator|->
name|tsp_vers
operator|)
argument_list|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|tsp
operator|->
name|tsp_seq
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" seq %u"
operator|,
name|tsp
operator|->
name|tsp_seq
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|tsp
operator|->
name|tsp_type
condition|)
block|{
case|case
name|TSP_LOOP
case|:
name|ND_TCHECK
argument_list|(
name|tsp
operator|->
name|tsp_hopcnt
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" hopcnt %u"
operator|,
name|tsp
operator|->
name|tsp_hopcnt
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TSP_SETTIME
case|:
case|case
name|TSP_ADJTIME
case|:
case|case
name|TSP_SETDATE
case|:
case|case
name|TSP_SETDATEREQ
case|:
name|ND_TCHECK
argument_list|(
name|tsp
operator|->
name|tsp_time
argument_list|)
expr_stmt|;
name|sec
operator|=
name|EXTRACT_32BITS
argument_list|(
operator|&
name|tsp
operator|->
name|tsp_time
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
name|usec
operator|=
name|EXTRACT_32BITS
argument_list|(
operator|&
name|tsp
operator|->
name|tsp_time
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
comment|/* XXX The comparison below is always false? */
if|if
condition|(
name|usec
operator|<
literal|0
condition|)
comment|/* corrupt, skip the rest of the packet */
return|return;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" time "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sec
operator|<
literal|0
operator|&&
name|usec
operator|!=
literal|0
condition|)
block|{
name|sec
operator|++
expr_stmt|;
if|if
condition|(
name|sec
operator|==
literal|0
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"-"
operator|)
argument_list|)
expr_stmt|;
name|usec
operator|=
literal|1000000
operator|-
name|usec
expr_stmt|;
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%ld.%06ld"
operator|,
name|sec
operator|,
name|usec
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|ND_TCHECK
argument_list|(
name|tsp
operator|->
name|tsp_name
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" name "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|fn_print
argument_list|(
name|ndo
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|tsp
operator|->
name|tsp_name
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|tsp
operator|->
name|tsp_name
operator|+
sizeof|sizeof
argument_list|(
name|tsp
operator|->
name|tsp_name
argument_list|)
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" %s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

