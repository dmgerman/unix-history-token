begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * header.h - Article header format  */
end_comment

begin_comment
comment|/*	@(#)header.h	2.21	10/7/87	*/
end_comment

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
name|LBUFLEN
index|]
decl_stmt|;
comment|/* Newsgroups:		*/
name|char
name|title
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Subject:		*/
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
name|expdate
index|[
name|DATELEN
index|]
decl_stmt|;
comment|/* Expires:		*/
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
name|summary
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Summary:		*/
name|char
name|approved
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Approved:		*/
name|char
name|nf_id
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Nf-ID:		*/
name|char
name|nf_from
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Nf-From:		*/
name|char
name|supersedes
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Supersedes:		*/
ifdef|#
directive|ifdef
name|DOXREFS
name|char
name|xref
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* Xref:		*/
endif|#
directive|endif
comment|/* DOXREFS */
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

begin_define
define|#
directive|define
name|hwrite
parameter_list|(
name|hp
parameter_list|,
name|fp
parameter_list|)
value|ihwrite(hp,fp,0)
end_define

begin_define
define|#
directive|define
name|lhwrite
parameter_list|(
name|hp
parameter_list|,
name|fp
parameter_list|)
value|ihwrite(hp,fp,1)
end_define

begin_function_decl
name|char
modifier|*
name|oident
parameter_list|()
function_decl|;
end_function_decl

end_unit

