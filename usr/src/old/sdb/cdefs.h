begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "@(#)cdefs.h 4.2 8/17/82" */
end_comment

begin_comment
comment|/* type modifiers */
end_comment

begin_define
define|#
directive|define
name|PTR
value|020
end_define

begin_define
define|#
directive|define
name|FTN
value|040
end_define

begin_define
define|#
directive|define
name|ARY
value|060
end_define

begin_comment
comment|/* type packing constants */
end_comment

begin_define
define|#
directive|define
name|TMASK
value|060
end_define

begin_define
define|#
directive|define
name|TMASK1
value|0300
end_define

begin_define
define|#
directive|define
name|TMASK2
value|0360
end_define

begin_define
define|#
directive|define
name|BTMASK
value|017
end_define

begin_define
define|#
directive|define
name|BTSHIFT
value|4
end_define

begin_define
define|#
directive|define
name|TSHIFT
value|2
end_define

begin_comment
comment|/*	macros	*/
end_comment

begin_define
define|#
directive|define
name|BTYPE
parameter_list|(
name|x
parameter_list|)
value|(x&BTMASK)
end_define

begin_comment
comment|/* basic type of x */
end_comment

begin_define
define|#
directive|define
name|ISUNSIGNED
parameter_list|(
name|x
parameter_list|)
value|((x)<=ULONG&&(x)>=UCHAR)
end_define

begin_define
define|#
directive|define
name|UNSIGNABLE
parameter_list|(
name|x
parameter_list|)
value|((x)<=LONG&&(x)>=CHAR)
end_define

begin_define
define|#
directive|define
name|ENUNSIGN
parameter_list|(
name|x
parameter_list|)
value|((x)+(UNSIGNED-INT))
end_define

begin_define
define|#
directive|define
name|DEUNSIGN
parameter_list|(
name|x
parameter_list|)
value|((x)+(INT-UNSIGNED))
end_define

begin_define
define|#
directive|define
name|ISPTR
parameter_list|(
name|x
parameter_list|)
value|((x&TMASK)==PTR)
end_define

begin_define
define|#
directive|define
name|ISFTN
parameter_list|(
name|x
parameter_list|)
value|((x&TMASK)==FTN)
end_define

begin_comment
comment|/* is x a function type */
end_comment

begin_define
define|#
directive|define
name|ISARY
parameter_list|(
name|x
parameter_list|)
value|((x&TMASK)==ARY)
end_define

begin_comment
comment|/* is x an array type */
end_comment

begin_define
define|#
directive|define
name|INCREF
parameter_list|(
name|x
parameter_list|)
value|(((x&~BTMASK)<<TSHIFT)|PTR|(x&BTMASK))
end_define

begin_define
define|#
directive|define
name|DECREF
parameter_list|(
name|x
parameter_list|)
value|(((x>>TSHIFT)&~BTMASK&0x3fff)|(x&BTMASK))
end_define

begin_comment
comment|/* pack and unpack field descriptors (size and offset) */
end_comment

begin_define
define|#
directive|define
name|PKFIELD
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|)
value|((o<<6)|s)
end_define

begin_define
define|#
directive|define
name|UPKFSZ
parameter_list|(
name|v
parameter_list|)
value|(v&077)
end_define

begin_define
define|#
directive|define
name|UPKFOFF
parameter_list|(
name|v
parameter_list|)
value|(v>>6)
end_define

end_unit

