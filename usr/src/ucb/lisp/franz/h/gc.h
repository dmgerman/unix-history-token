begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:56:06 1983 by jkf]-  * 	gc.h			$Locker:  $  * garbage collector metering definitions  *  * $Header: /na/franz/franz/h/gc.h,v 1.1 83/01/29 14:06:15 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_struct
struct|struct
name|gchead
block|{
name|int
name|version
decl_stmt|;
comment|/* version number of this dump file */
name|int
name|lowdata
decl_stmt|;
comment|/* low address of sharable lisp data */
name|int
name|dummy
decl_stmt|,
name|dummy2
decl_stmt|,
name|dummy3
decl_stmt|;
comment|/* to be used later	*/
block|}
struct|;
end_struct

end_unit

