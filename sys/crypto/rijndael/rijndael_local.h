begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rijndael_local.h,v 1.3 2000/10/02 17:14:27 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/* the file should not be used from outside */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
name|BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|word8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|word16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|word32
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXKC
value|RIJNDAEL_MAXKC
end_define

begin_define
define|#
directive|define
name|MAXROUNDS
value|RIJNDAEL_MAXROUNDS
end_define

end_unit

