begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAST128_H_
end_ifndef

begin_define
define|#
directive|define
name|_CAST128_H_
end_define

begin_include
include|#
directive|include
file|<opencrypto/cast.h>
end_include

begin_define
define|#
directive|define
name|cast128_key
value|cast_key
end_define

begin_define
define|#
directive|define
name|cast128_setkey
parameter_list|(
name|key
parameter_list|,
name|rawkey
parameter_list|,
name|keybytes
parameter_list|)
define|\
value|cast_setkey((key), (rawkey), (keybytes))
end_define

begin_define
define|#
directive|define
name|cast128_encrypt
parameter_list|(
name|key
parameter_list|,
name|inblock
parameter_list|,
name|outblock
parameter_list|)
define|\
value|cast_encrypt((key), (inblock), (outblock))
end_define

begin_define
define|#
directive|define
name|cast128_decrypt
parameter_list|(
name|key
parameter_list|,
name|inblock
parameter_list|,
name|outblock
parameter_list|)
define|\
value|cast_decrypt((key), (inblock), (outblock))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAST128_H_ */
end_comment

end_unit

