begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * header.h - Article header format  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Header
init|=
literal|"@(#)header.h	2.11	4/24/83"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUNREC
value|50
end_define

begin_comment
comment|/* article header */
end_comment

begin_struct
struct|struct
name|hbuf
block|{
name|char
name|from
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* From:		*/
name|char
name|path
index|[
name|PATHLEN
index|]
decl_stmt|;
comment|/* Path:		*/
name|char
name|nbuf
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Newsgroups:		*/
name|char
name|snbuf
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Squashed nbuf.	*/
name|char
name|title
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Subject:		*/
name|char
name|oident
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Article-I.D.:	*/
name|char
name|ident
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Message-ID:		*/
name|char
name|replyto
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Reply-To:		*/
name|char
name|followid
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* References:		*/
name|char
name|subdate
index|[
name|DATELEN
index|]
decl_stmt|;
comment|/* Date: (submission)	*/
name|time_t
name|subtime
decl_stmt|;
comment|/* subdate in secs	*/
name|char
name|recdate
index|[
name|DATELEN
index|]
decl_stmt|;
comment|/* Date-Received:	*/
name|time_t
name|rectime
decl_stmt|;
comment|/* recdate in secs	*/
name|char
name|expdate
index|[
name|DATELEN
index|]
decl_stmt|;
comment|/* Expires:		*/
name|time_t
name|exptime
decl_stmt|;
comment|/* expdate in secs	*/
name|char
name|ctlmsg
index|[
name|PATHLEN
index|]
decl_stmt|;
comment|/* Control:		*/
name|char
name|sender
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Sender:		*/
name|char
name|followto
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Followup-to:		*/
name|char
name|postversion
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Post-Version:	*/
name|char
name|relayversion
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Relay-Version:	*/
name|char
name|distribution
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Distribution:	*/
name|char
name|organization
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Organization:	*/
name|char
name|numlines
index|[
literal|8
index|]
decl_stmt|;
comment|/* Lines:		*/
name|int
name|intnumlines
decl_stmt|;
comment|/* Integer version	*/
name|char
name|keywords
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Keywords:		*/
name|char
name|approved
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Approved:		*/
name|char
modifier|*
name|unrec
index|[
name|NUNREC
index|]
decl_stmt|;
comment|/* unrecognized lines	*/
block|}
struct|;
end_struct

end_unit

