begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b0con.h,v 1.1 84/07/03 20:11:59 timo Exp $ */
end_comment

begin_comment
comment|/* Configuration file: some easy changes to the system                      */
end_comment

begin_comment
comment|/* VOID is used to keep lint quiet(er)                                      */
end_comment

begin_comment
comment|/* if your compiler doesn't accept (void) delete "(void)" from the next line*/
end_comment

begin_define
define|#
directive|define
name|VOID
end_define

begin_comment
comment|/* some un*xes demand that you reset stdin in some way if you get eof, and  */
end_comment

begin_comment
comment|/* want to read from it still. If yours doesn't, delete "clearerr(stdin)"   */
end_comment

begin_define
define|#
directive|define
name|CLEAR_EOF
value|clearerr(stdin)
end_define

begin_comment
comment|/* Default editor: end the string with<space>+ if it accepts a line number */
end_comment

begin_comment
comment|/* of the form +<number> before the file name when it is called		    */
end_comment

begin_comment
comment|/* eg vi +10 myunit 							    */
end_comment

begin_comment
comment|/* temporary file to save an edited file in                                 */
end_comment

begin_define
define|#
directive|define
name|SAVEFILE
value|".b_temp"
end_define

begin_comment
comment|/* 'Small' number package.  (Also used by output conversion of 'Big' pkg.)  */
end_comment

begin_define
define|#
directive|define
name|BIG
value|72057594037927935.0
end_define

begin_comment
comment|/*Largest integral real number              */
end_comment

begin_define
define|#
directive|define
name|LONG
value|9999999999999999.5
end_define

begin_comment
comment|/*Largest power of 10 less than BIG         */
end_comment

begin_define
define|#
directive|define
name|MAXNUMDIG
value|16
end_define

begin_comment
comment|/*The number of 9's in LONG                 */
end_comment

begin_define
define|#
directive|define
name|MINNUMDIG
value|6
end_define

begin_comment
comment|/*Don't change; this is here for consistency*/
end_comment

begin_comment
comment|/* Unbounded number package                                                 */
end_comment

begin_comment
comment|/* BASE must be set for your machine so that BASE*BASE can be computed      */
end_comment

begin_comment
comment|/* exactly as a double, and (BASE+BASE) and (-BASE-BASE) are computable     */
end_comment

begin_comment
comment|/* with long integers. It must equal 10**tenlogBASE.                        */
end_comment

begin_comment
comment|/* Maxreal, Maxexpo, Minexpo and Dblbits define properties of floating      */
end_comment

begin_comment
comment|/* point arithmetic on your machine                                         */
end_comment

begin_define
define|#
directive|define
name|tenlogBASE
value|8
end_define

begin_comment
comment|/*Change this and the next line together!*/
end_comment

begin_define
define|#
directive|define
name|BASE
value|100000000l
end_define

begin_define
define|#
directive|define
name|Maxreal
value|1.7E38
end_define

begin_define
define|#
directive|define
name|Maxexpo
value|127
end_define

begin_define
define|#
directive|define
name|Minexpo
value|(-128)
end_define

begin_define
define|#
directive|define
name|Dblbits
value|56
end_define

begin_comment
comment|/*Number of bits used for double precision */
end_comment

begin_comment
comment|/*Other definitions*/
end_comment

begin_typedef
typedef|typedef
name|int
name|expint
typedef|;
end_typedef

begin_comment
comment|/*The 2nd argument of frexp points to this */
end_comment

begin_comment
comment|/*(see manual page frexp(3)).              */
end_comment

begin_comment
comment|/*On some 68K systems must be short (foo!) */
end_comment

begin_define
define|#
directive|define
name|Maxgonio
value|1e16
end_define

begin_comment
comment|/*Max x for sin(x), cos(x), tan(x)         */
end_comment

begin_define
define|#
directive|define
name|Maxintlet
value|((1<<15)-1)
end_define

begin_comment
comment|/*Largest short*/
end_comment

begin_define
define|#
directive|define
name|Maxint
value|((1<<15)-1)
end_define

begin_comment
comment|/*Largest int*/
end_comment

begin_define
define|#
directive|define
name|RDBUFSIZE
value|500
end_define

begin_comment
comment|/*Buffer used for read commands*/
end_comment

begin_define
define|#
directive|define
name|TXDBUFSIZE
value|100
end_define

begin_comment
comment|/*Text displays*/
end_comment

begin_define
define|#
directive|define
name|SEED
value|getpid()
end_define

begin_comment
comment|/*Any suitable random int (eg date or time) */
end_comment

begin_comment
comment|/*to start the random number generator with */
end_comment

end_unit

