begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MAXDELIMS
value|3
end_define

begin_struct
struct|struct
name|strfile
block|{
comment|/* information table			*/
name|int
name|str_numstr
decl_stmt|;
comment|/* number of strings in the file */
name|int
name|str_longlen
decl_stmt|;
comment|/* length of longest string	*/
name|int
name|str_shortlen
decl_stmt|;
comment|/* length of shortest string	*/
name|long
name|str_delims
index|[
name|MAXDELIMS
index|]
decl_stmt|;
comment|/* delimiter markings		*/
name|int
name|str_unused
decl_stmt|;
comment|/* reserve space for later needs */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|strfile
name|STRFILE
typedef|;
end_typedef

end_unit

