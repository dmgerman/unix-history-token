begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)configdefs.h	5.2 (Berkeley) 2/18/88  */
end_comment

begin_comment
comment|/*  * This file contains the definitions of data structures used in  * configuring the network behavior of Mail when replying.  */
end_comment

begin_comment
comment|/*  * The following constants are used when you are running 4.1a bsd or  * later on a local network.  Under control of the #define flag  * GETHOST, the host name is determined dynamically using the  * gethostname() system call.  The name thus found is inserted  * into the host table slot whose name was originally EMPTY.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY
value|"** empty **"
end_define

begin_define
define|#
directive|define
name|EMPTYID
value|'E'
end_define

begin_comment
comment|/*  * The following data structure is the host table.  You must have  * an entry here for your own machine, plus any special stuff you  * expect the mailer to know about.  If you have #define'd GETHOST  * in v7.local.h, you needn't add your machine to the host table.  * Not all hosts need be here, however:  * Mail can dope out stuff about hosts on the fly by looking  * at addresses.  The machines needed here are:  *	1) The local machine  *	2) Any machines on the path to a network gateway  *	3) Any machines with nicknames that you want to have considered  *	   the same.  * The machine id letters can be anything you like and are not seen  * externally.  Be sure not to use characters with the 0200 bit set --  * these have special meanings.  */
end_comment

begin_struct
struct|struct
name|netmach
block|{
name|char
modifier|*
name|nt_machine
decl_stmt|;
name|char
name|nt_mid
decl_stmt|;
name|short
name|nt_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Network type codes.  Basically, there is one for each different  * network, if the network can be discerned by the separator character,  * such as @ for the arpa net.  The purpose of these codes is to  * coalesce cases where more than one character means the same thing,  * such as % and @ for the arpanet.  Also, the host table uses a  * bit map of these codes to show what it is connected to.  * BN -- connected to Bell Net.  * AN -- connected to ARPA net, SN -- connected to Schmidt net.  */
end_comment

begin_define
define|#
directive|define
name|AN
value|1
end_define

begin_comment
comment|/* Connected to ARPA net */
end_comment

begin_define
define|#
directive|define
name|BN
value|2
end_define

begin_comment
comment|/* Connected to BTL net */
end_comment

begin_define
define|#
directive|define
name|SN
value|4
end_define

begin_comment
comment|/* Connected to Schmidt net */
end_comment

begin_comment
comment|/*  * Data structure for table mapping network characters to network types.  */
end_comment

begin_struct
struct|struct
name|ntypetab
block|{
name|char
name|nt_char
decl_stmt|;
comment|/* Actual character separator */
name|int
name|nt_bcode
decl_stmt|;
comment|/* Type bit code */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Codes for the "kind" of a network.  IMPLICIT means that if there are  * physically several machines on the path, one does not list them in the  * address.  The arpa net is like this.  EXPLICIT means you list them,  * as in UUCP.  * By the way, this distinction means we lose if anyone actually uses the  * arpa net subhost convention: name@subhost@arpahost  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT
value|1
end_define

begin_define
define|#
directive|define
name|EXPLICIT
value|2
end_define

begin_comment
comment|/*  * Table for mapping a network code to its type -- IMPLICIT routing or  * IMPLICIT routing.  */
end_comment

begin_struct
struct|struct
name|nkindtab
block|{
name|int
name|nk_type
decl_stmt|;
comment|/* Its bit code */
name|int
name|nk_kind
decl_stmt|;
comment|/* Whether explicit or implicit */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following table gives the order of preference of the various  * networks.  Thus, if we have a choice of how to get somewhere, we  * take the preferred route.  */
end_comment

begin_struct
struct|struct
name|netorder
block|{
name|short
name|no_stat
decl_stmt|;
name|char
name|no_char
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * External declarations for above defined tables.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIGFILE
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|netmach
name|netmach
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ntypetab
name|ntypetab
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nkindtab
name|nkindtab
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netorder
name|netorder
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|metanet
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

