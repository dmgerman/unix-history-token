begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * "From " line struct  *  * Author: Peter J. Nicklin  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_from
block|{
name|char
modifier|*
name|from
decl_stmt|;
comment|/* name of the sender */
name|char
modifier|*
name|tty
decl_stmt|;
comment|/* tty string (if any) */
name|char
modifier|*
name|date
decl_stmt|;
comment|/* date string */
name|DATE
name|bdt
decl_stmt|;
comment|/* broken down date */
name|long
name|m_seek
decl_stmt|;
comment|/* start of message */
name|long
name|m_len
decl_stmt|;
comment|/* length of message */
block|}
name|FROM
typedef|;
end_typedef

end_unit

