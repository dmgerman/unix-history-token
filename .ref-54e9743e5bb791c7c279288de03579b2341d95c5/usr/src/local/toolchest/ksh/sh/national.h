begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)national.h	1.1 */
end_comment

begin_comment
comment|/*  *  national.h -  definitions for international character sets  *  *   David Korn  *   AT&T Bell Laboratories  *   Room 5D-112  *   Murray Hill, N. J. 07974  *   Tel. x7975  *  */
end_comment

begin_comment
comment|/*  * This data must be defined for each country in defs.c  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HIGHBIT
end_ifndef

begin_define
define|#
directive|define
name|HIGHBIT
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HIGHBIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESS_MAXCHAR
end_ifndef

begin_comment
comment|/* allow multiple includes */
end_comment

begin_comment
comment|/*  *  This section may change from country to country  */
end_comment

begin_define
define|#
directive|define
name|ESS_MAXCHAR
value|2
end_define

begin_comment
comment|/* Maximum number of non-escape bytes 				   for any and all character sets */
end_comment

begin_define
define|#
directive|define
name|CCS1_IN_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|CCS1_OUT_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|CCS2_IN_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|CCS2_OUT_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|CCS3_IN_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|CCS3_OUT_SIZE
value|2
end_define

begin_comment
comment|/*  * This part is generic  */
end_comment

begin_define
define|#
directive|define
name|MARKER
value|0x100
end_define

begin_comment
comment|/* Must be invalid character */
end_comment

begin_define
define|#
directive|define
name|ESS2
value|0x8e
end_define

begin_comment
comment|/* Escape to char set 2 */
end_comment

begin_define
define|#
directive|define
name|ESS3
value|0x8f
end_define

begin_comment
comment|/* Escape to char set 3 */
end_comment

begin_define
define|#
directive|define
name|ESS_SETMASK
value|(3<<(7*ESS_MAXCHAR))
end_define

begin_comment
comment|/* character set bits */
end_comment

begin_define
define|#
directive|define
name|echarset
parameter_list|(
name|c
parameter_list|)
value|((c)==ESS3?3:((c)==ESS2)?2:((c)>>7)&1)
end_define

begin_define
define|#
directive|define
name|icharset
parameter_list|(
name|i
parameter_list|)
value|((i)>>(7*ESS_MAXCHAR)&3)
end_define

begin_define
define|#
directive|define
name|in_csize
parameter_list|(
name|s
parameter_list|)
value|int_charsize[s]
end_define

begin_define
define|#
directive|define
name|out_csize
parameter_list|(
name|s
parameter_list|)
value|int_charsize[s+4]
end_define

begin_decl_stmt
specifier|extern
name|char
name|int_charsize
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ESS_MAXCHAR */
end_comment

end_unit

