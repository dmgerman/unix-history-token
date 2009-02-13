begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for the CHU line discipline v2.0  */
end_comment

begin_comment
comment|/*  * The CHU time code consists of 10 BCD digits and is repeated  * twice for a total of 10 characters.  A time is taken after  * the arrival of each character.  The following structure is  * used to return this stuff.  */
end_comment

begin_define
define|#
directive|define
name|NCHUCHARS
value|(10)
end_define

begin_struct
struct|struct
name|chucode
block|{
name|u_char
name|codechars
index|[
name|NCHUCHARS
index|]
decl_stmt|;
comment|/* code characters */
name|u_char
name|ncodechars
decl_stmt|;
comment|/* number of code characters */
name|u_char
name|chutype
decl_stmt|;
comment|/* packet type */
name|struct
name|timeval
name|codetimes
index|[
name|NCHUCHARS
index|]
decl_stmt|;
comment|/* arrival times */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHU_TIME
value|0
end_define

begin_comment
comment|/* second half is equal to first half */
end_comment

begin_define
define|#
directive|define
name|CHU_YEAR
value|1
end_define

begin_comment
comment|/* second half is one's complement */
end_comment

end_unit

