begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: getarg.h,v 1.1 85/03/14 15:32:56 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Get command line argument  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Argument syntax: `-xargument' or `-x argument'  */
end_comment

begin_define
define|#
directive|define
name|GETARG
parameter_list|(
name|p
parameter_list|)
value|((p[1] != '\0') ? ++p : (--argc, *++argv))
end_define

begin_comment
comment|/*  * Argument syntax: `-xargument'  *  * #define GETARG(p) (++p)  */
end_comment

end_unit

