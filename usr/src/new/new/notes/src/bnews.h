begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bnews.h - B news article header format  */
end_comment

begin_define
define|#
directive|define
name|NUNREC
value|10
end_define

begin_comment
comment|/* article header */
end_comment

begin_struct
struct|struct
name|hbuf
block|{
name|char
name|path
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* source string	*/
name|char
name|nbuf
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* newsgroup line	*/
name|char
name|title
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* title		*/
name|char
name|ident
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* article I.D.		*/
name|char
name|replyto
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* reply address	*/
name|char
name|followid
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* artid in followup to	*/
name|char
name|subdate
index|[
name|DATELEN
index|]
decl_stmt|;
comment|/* submittal date	*/
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
comment|/* receival date	*/
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
comment|/* expiration date	*/
name|time_t
name|exptime
decl_stmt|;
comment|/* expdate in secs	*/
name|char
name|ctlmsg
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* control message	*/
name|char
name|unrec
index|[
name|NUNREC
index|]
index|[
name|WDLEN
index|]
decl_stmt|;
comment|/* unrecognized lines	*/
block|}
struct|;
end_struct

end_unit

