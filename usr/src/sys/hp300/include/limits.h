begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)limits.h	8.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_comment
comment|/* number of bits in a char */
end_comment

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|6
end_define

begin_comment
comment|/* Allow 31 bit UTF2 */
end_comment

begin_define
define|#
directive|define
name|CLK_TCK
value|60
end_define

begin_comment
comment|/* ticks per second */
end_comment

begin_comment
comment|/*  * According to ANSI (section 2.2.4.2), the values below must be usable by  * #if preprocessing directives.  Additionally, the expression must have the  * same type as would an expression that is an object of the corresponding  * type converted according to the integral promotions.  The subtraction for  * INT_MIN and LONG_MIN is so the value is not unsigned; 2147483648 is an  * unsigned int for 32-bit two's complement ANSI compilers (section 3.1.3.2).  * These numbers work for pcc as well.  The UINT_MAX and ULONG_MAX values  * are written as hex so that GCC will be quiet about large integer constants.  */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MAX
value|127
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-128)
end_define

begin_comment
comment|/* max value for a signed char */
end_comment

begin_define
define|#
directive|define
name|UCHAR_MAX
value|255
end_define

begin_comment
comment|/* max value for an unsigned char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MAX
value|127
end_define

begin_comment
comment|/* max value for a char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MIN
value|(-128)
end_define

begin_comment
comment|/* min value for a char */
end_comment

begin_define
define|#
directive|define
name|USHRT_MAX
value|65535
end_define

begin_comment
comment|/* max value for an unsigned short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MAX
value|32767
end_define

begin_comment
comment|/* max value for a short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MIN
value|(-32768)
end_define

begin_comment
comment|/* min value for a short */
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|0xffffffff
end_define

begin_comment
comment|/* max value for an unsigned int */
end_comment

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_comment
comment|/* max value for an int */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|(-2147483647-1)
end_define

begin_comment
comment|/* min value for an int */
end_comment

begin_define
define|#
directive|define
name|ULONG_MAX
value|0xffffffff
end_define

begin_comment
comment|/* max value for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|2147483647
end_define

begin_comment
comment|/* max value for a long */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
value|(-2147483647-1)
end_define

begin_comment
comment|/* min value for a long */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SSIZE_MAX
value|INT_MAX
end_define

begin_comment
comment|/* max value for a ssize_t */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|UINT_MAX
end_define

begin_comment
comment|/* max value for a size_t */
end_comment

begin_comment
comment|/* GCC requires that quad constants be written as expressions. */
end_comment

begin_define
define|#
directive|define
name|UQUAD_MAX
value|((u_quad_t)0-1)
end_define

begin_comment
comment|/* max value for a uquad_t */
end_comment

begin_comment
comment|/* max value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|((quad_t)(UQUAD_MAX>> 1))
end_define

begin_define
define|#
directive|define
name|QUAD_MIN
value|(-QUAD_MAX-1)
end_define

begin_comment
comment|/* min value for a quad_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

end_unit

