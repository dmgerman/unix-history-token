begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	getq.h	4.3	83/02/10	*/
end_comment

begin_include
include|#
directive|include
file|<dir.h>
end_include

begin_comment
comment|/*  * Structure used for building a sorted list of control files.  */
end_comment

begin_struct
struct|struct
name|queue
block|{
name|time_t
name|q_time
decl_stmt|;
comment|/* modification time */
name|char
name|q_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* control file name */
block|}
struct|;
end_struct

end_unit

