begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Bill Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)connect.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Unix Connection daemon  *   * service request structures and subroutine definitions  * for connection requests.  */
end_comment

begin_define
define|#
directive|define
name|MAXCONNECTS
value|10
end_define

begin_comment
comment|/* maximum number of simultaineous 					connects per process */
end_comment

begin_struct
struct|struct
name|connectdomain
block|{
name|short
name|cd_family
decl_stmt|;
name|short
name|cd_alen
decl_stmt|;
name|char
name|cd_address
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(s->cd_family) + sizeof (s->cd_alen) + (s->cd_alen))
end_define

begin_decl_stmt
name|int
name|externalconnect
argument_list|()
decl_stmt|,
name|externalabort
argument_list|()
decl_stmt|,
name|externalfinish
argument_list|()
decl_stmt|,
name|externaloption
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDNEWREQUEST
value|1
end_define

begin_comment
comment|/* request a new connection from client */
end_comment

begin_define
define|#
directive|define
name|CDNEWRESPONSE
value|2
end_define

begin_comment
comment|/* response from server daemon */
end_comment

begin_define
define|#
directive|define
name|CDCANCELREQUEST
value|3
end_define

begin_comment
comment|/* cancellation message from client */
end_comment

begin_define
define|#
directive|define
name|CDFINISHREQUEST
value|5
end_define

begin_comment
comment|/* finshed, pass back file descriptor to srvr */
end_comment

begin_define
define|#
directive|define
name|CDFINISHRESPONSE
value|6
end_define

begin_comment
comment|/* finish acked from server to client */
end_comment

begin_define
define|#
directive|define
name|CDOPTIONREQUEST
value|7
end_define

begin_comment
comment|/* pass option request to be performed 					on descriptor by srvr */
end_comment

begin_define
define|#
directive|define
name|CDOPTIONRESPONSE
value|8
end_define

begin_comment
comment|/* option acked from server to client */
end_comment

begin_define
define|#
directive|define
name|CDRESOFFEREQUEST
value|9
end_define

begin_comment
comment|/* other daemon offers resources of a given type 					to srvr */
end_comment

begin_define
define|#
directive|define
name|CDRESOFFERESPONSE
value|10
end_define

begin_comment
comment|/* offer acked from server to client */
end_comment

begin_define
define|#
directive|define
name|CDWITHDRNREQUEST
value|11
end_define

begin_comment
comment|/* other daemon withdraws resources frm srvr */
end_comment

begin_define
define|#
directive|define
name|CDWITHDRNRESPONSE
value|12
end_define

begin_comment
comment|/* resp to withdraw resources frm srvr */
end_comment

begin_define
define|#
directive|define
name|CDSGRANTREQUEST
value|13
end_define

begin_comment
comment|/* connect daemon demand resource frm srvr */
end_comment

begin_define
define|#
directive|define
name|CDSGRANTRESPONSE
value|14
end_define

begin_comment
comment|/* resp to demand resource frm srvr */
end_comment

begin_define
define|#
directive|define
name|ISCDREQUEST
parameter_list|(
name|s
parameter_list|)
value|(s&1)
end_define

begin_comment
comment|/* is this a request or response */
end_comment

end_unit

