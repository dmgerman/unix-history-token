begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/include/ieee754io.h,v 4.0 1998/04/10 19:50:40 kardel RELEASE_19990228_A  *  * $Created: Sun Jul 13 12:22:11 1997 $  *  * Copyright (C) 1997 by Frank Kardel  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE754IO_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE754IO_H
end_define

begin_define
define|#
directive|define
name|IEEE_SINGLE
value|1
end_define

begin_define
define|#
directive|define
name|IEEE_DOUBLE
value|2
end_define

begin_define
define|#
directive|define
name|IEEE_MSB
value|1
end_define

begin_define
define|#
directive|define
name|IEEE_LSB
value|2
end_define

begin_define
define|#
directive|define
name|IEEE_OK
value|0
end_define

begin_comment
comment|/* conversion ok */
end_comment

begin_define
define|#
directive|define
name|IEEE_BADCALL
value|1
end_define

begin_comment
comment|/* bad call parameters */
end_comment

begin_define
define|#
directive|define
name|IEEE_NAN
value|2
end_define

begin_comment
comment|/* found an NaN */
end_comment

begin_define
define|#
directive|define
name|IEEE_POSINFINITY
value|3
end_define

begin_comment
comment|/* positive infinity */
end_comment

begin_define
define|#
directive|define
name|IEEE_NEGINFINITY
value|4
end_define

begin_comment
comment|/* negative infinity */
end_comment

begin_define
define|#
directive|define
name|IEEE_POSOVERFLOW
value|5
end_define

begin_comment
comment|/* positive overflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_NEGOVERFLOW
value|6
end_define

begin_comment
comment|/* negative overflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_OFFSETS
value|8
end_define

begin_comment
comment|/* number of byte positions */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|offsets_t
index|[
name|IEEE_OFFSETS
index|]
typedef|;
end_typedef

begin_decl_stmt
name|int
name|fetch_ieee754
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
name|bufp
operator|,
name|int
name|size
operator|,
name|l_fp
operator|*
name|lfpp
operator|,
name|offsets_t
name|offsets
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|put_ieee754
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
name|bufpp
operator|,
name|int
name|size
operator|,
name|l_fp
operator|*
name|lfpp
operator|,
name|offsets_t
name|offsets
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ieee754io.h,v  * Revision 4.0  1998/04/10 19:50:40  kardel  * Start 4.0 release version numbering  *  * Revision 1.1  1998/04/10 19:27:33  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  * Revision 1.1  1997/10/06 20:55:37  kardel  * new parse structure  *  */
end_comment

end_unit

